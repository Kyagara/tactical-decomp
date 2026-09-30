#!/usr/bin/env python3
"""Import decomp ground truth (splat yamls + symbol maps) into recomp inputs.

Reads (repo root relative):
  config/boot.yaml                  exe segment map (vram/file offsets, gp)
  config/symbol_addrs.txt           decomp-verified exe func/data addrs
  config/applied_names.txt          Names (reference-only)
  config/psyq_matches.csv           PSYQ lib/member per func (1.0 hits)
  config/hard_tails.txt             never-C thunks / stalemates
  recomp/seeds/ghidra_funcs.txt     current probe JAL seeds

Writes (recomp/ relative, no staging/committing done here):
  seeds/ghidra_funcs.txt  merged probe + decomp-verified exe funcs
  symbols.toml            func map with real names (emit=false always)
  game.toml               adds overlay_region_floor + decomp reference comments

Stdlib only. Deterministic output (sorted). Idempotent.
Usage from repo root:
  tools/.venv/bin/python recomp/tools/import_decomp.py
  tools/.venv/bin/python recomp/tools/import_decomp.py --check
"""
from __future__ import annotations

import argparse
import csv
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
RECOMP = ROOT / "recomp"
CONFIG = ROOT / "config"

SYM_RE = re.compile(r"(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;")
CIDENT_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*\Z")
SEED_RE = re.compile(r"^(0x[0-9A-Fa-f]+)\b")


def parse_sym_addrs(path: Path) -> list[tuple[str, int]]:
    out: list[tuple[str, int]] = []
    if not path.is_file():
        return out
    for line in path.read_text(errors="replace").splitlines():
        m = SYM_RE.search(line)
        if m:
            out.append((m.group(1), int(m.group(2), 16)))
    return out


def parse_seeds(path: Path) -> list[int]:
    out: list[int] = []
    if not path.is_file():
        return out
    for line in path.read_text(errors="replace").splitlines():
        s = line.strip()
        if not s or s.startswith("#"):
            continue
        m = SEED_RE.match(s)
        if m:
            out.append(int(m.group(1), 16))
    return out


def parse_hard_tails(path: Path) -> dict[int, str]:
    """func name -> reason. Names are func_800XXXXX; resolve via addr suffix."""
    out: dict[int, str] = {}
    if not path.is_file():
        return out
    for line in path.read_text(errors="replace").splitlines():
        s = line.strip()
        if not s or s.startswith("#"):
            continue
        m = re.match(r"(func_[0-9A-Fa-f]+)\s*//\s*(.*)", s)
        if m:
            try:
                addr = int(m.group(1)[5:], 16)
            except ValueError:
                continue
            out[addr] = m.group(2).strip()
    return out


def parse_psyq(path: Path) -> dict[int, tuple[str, str, str]]:
    """addr -> (symbol, lib, member) for hit>=1.0 rows with C-valid symbols."""
    out: dict[int, tuple[str, str, str]] = {}
    if not path.is_file():
        return out
    with open(path, newline="", encoding="utf-8", errors="replace") as fh:
        for row in csv.DictReader(fh):
            try:
                hit = float(row.get("hit", "0") or 0)
            except ValueError:
                continue
            if hit < 1.0:
                continue
            sym = (row.get("symbol") or "").strip()
            if not CIDENT_RE.match(sym) or sym.startswith("@"):
                continue
            try:
                addr = int(row["vram"], 16)
            except (ValueError, KeyError):
                continue
            # First 1.0 hit wins (csv is lib-precedence ordered).
            out.setdefault(addr, (sym, row.get("lib", ""), row.get("member", "")))
    return out


def sanitize(name: str) -> str | None:
    return name if CIDENT_RE.match(name) else None


def exe_code_ranges() -> list[tuple[int, int, str]]:
    """(lo, hi, note) executable ranges from boot.yaml code segments."""
    # Frozen from config/boot.yaml (kept literal to stay stdlib-only).
    return [
        (0x80010000, 0x80021F44, "main/main_2"),
        (0x80022114, 0x80028AE8, "main_3"),
        (0x80040934, 0x8004593C, "main_4"),
        (0x80059854, 0x80064410, "main_5"),
    ]


def in_exe_code(addr: int) -> bool:
    return any(lo <= addr < hi for lo, hi, _ in exe_code_ranges())




def build_symbols() -> tuple[list[dict], set[int], dict[str, int]]:
    sym_rows = parse_sym_addrs(CONFIG / "symbol_addrs.txt")
    applied = parse_sym_addrs(CONFIG / "applied_names.txt")
    applied_by_addr = {a: n for n, a in applied}
    psyq = parse_psyq(CONFIG / "psyq_matches.csv")
    hard = parse_hard_tails(CONFIG / "hard_tails.txt")
    seeds = parse_seeds(RECOMP / "seeds" / "ghidra_funcs.txt")

    sym_func_addrs = {a for n, a in sym_rows if not n.startswith("D_")}
    sym_func_name_by_addr = {a: n for n, a in sym_rows if not n.startswith("D_")}
    psyq_addrs = set(psyq)
    seed_set = set(seeds)

    # Every exe-code addr we can name: decomp funcs + applied/psyq funcs
    # + probe seeds (guessed fallback). Blob addrs never enter here.
    candidates: set[int] = set()
    for a in sym_func_addrs:
        if in_exe_code(a):
            candidates.add(a)
    for a in applied_by_addr:
        if in_exe_code(a) and (a in sym_func_addrs or a in seed_set or a in psyq_addrs):
            candidates.add(a)
    for a in psyq_addrs:
        if in_exe_code(a):
            candidates.add(a)
    for a in seed_set:
        if in_exe_code(a):
            candidates.add(a)

    used_names: dict[str, int] = {}
    funcs: list[dict] = []
    for addr in sorted(candidates):
        pick: str | None = None
        sources: list[str] = []
        # NB: D_* labels (split_merged rodata stubs like D_80010BA8) must never
        # become func names; func names come only from func-like decomp rows.
        decomp_name = sym_func_name_by_addr.get(addr)
        if decomp_name and not decomp_name.startswith("func_") and sanitize(decomp_name):
            pick = decomp_name
            sources.append("decomp:symbol_addrs")
        if addr in psyq and sanitize(psyq[addr][0]):
            if pick is None:
                pick, lib, mem = psyq[addr][0], psyq[addr][1], psyq[addr][2]
            sources.append(f"psyq:{psyq[addr][1]}/{psyq[addr][2]}")
        app = applied_by_addr.get(addr)
        if app and sanitize(app):
            if pick is None:
                pick = app
            sources.append("config:applied_names")
        if pick is None:
            if decomp_name and sanitize(decomp_name):
                pick = decomp_name
                sources.append("decomp:symbol_addrs(func_xxx)")
            else:
                pick = f"Func_{addr:08X}"
                sources.append("probe:jal-seed")
        assert pick is not None
        # Unique C names (SpuRead/SpuWrite/Stframe_no repeat in PSYQ).
        base_name = pick
        if pick in used_names and used_names[pick] != addr:
            pick = f"{base_name}_{addr:08X}"
        used_names.setdefault(pick, addr)

        status = "confirmed" if addr in sym_func_addrs or addr in psyq_addrs or addr in applied_by_addr else "guessed"
        note_bits = list(dict.fromkeys(sources))
        if addr in hard:
            note_bits.append(f"hard-tail: {hard[addr][:100]}")
        if addr == 0x80010A30:
            note_bits.insert(0, "SYSTEM.CNF / EXE entry PC")
        funcs.append({
            "pc": addr,
            "name": pick,
            "emit": False,
            "status": status,
            "note": "; ".join(note_bits)[:220],
        })
    return funcs, sym_func_addrs, used_names


def render_symbols_toml(funcs: list[dict]) -> str:
    lines = [
        "# Final Fantasy Tactics - progressive symbol map (partial decomp)",
        "# Generated by recomp/tools/import_decomp.py from:",
        "#   config/boot.yaml + config/symbol_addrs.txt (decomp-verified)",
        "#   config/applied_names.txt + config/psyq_matches.csv (PSYQ 1.0)",
        "#   config/hard_tails.txt (never-emit thunks) + probe JAL seeds.",
        "# Discover → label here → manipulate via PSX_FN_* (tools/sync_symbols.py).",
        "# Gate emit=true only when the entry is safe to own for host hooks.",
        "# Blob (overlay) funcs live in config/blobs/*.symbols.txt, NOT here.",
        "# See psxrecomp/docs/SYMBOLS.md. Do not hand-edit; re-run the importer.",
        "",
    ]
    for f in funcs:
        lines.append("[[func]]")
        lines.append(f"pc = 0x{f['pc']:08X}")
        lines.append(f"name = \"{f['name']}\"")
        lines.append(f"emit = {'true' if f['emit'] else 'false'}")
        lines.append(f"status = \"{f['status']}\"")
        note = f["note"].replace("\\", "\\\\").replace('"', "'")
        lines.append(f"note = \"{note}\"")
        lines.append("")
    return "\n".join(lines)


def render_seeds(funcs: list[dict], old_seeds: list[int]) -> str:
    addrs = sorted({f["pc"] for f in funcs} | {a for a in old_seeds if in_exe_code(a)})
    by_addr = {f["pc"]: f for f in funcs}
    lines = [
        "# Auto-scanned JAL targets (+ entry) from SCUS_942.21",
        "# entry=0x80010a30 load=0x80010000 text_size=0x56800",
        "# Merged by recomp/tools/import_decomp.py: probe seeds + decomp-verified",
        "# config/symbol_addrs.txt funcs (exe code ranges only). Blob/overlay",
        "# funcs are NOT here (see config/blobs/*.symbols.txt). First token is the seed.",
        "# Trailing label is provenance for psxrecomp-analyze / reviewers.",
    ]
    for a in addrs:
        f = by_addr.get(a)
        label = f["name"] if f else f"Func_{a:08X}"
        lines.append(f"0x{a:08X}  # {label}")
    lines.append("")
    return "\n".join(lines)


GAME_TOML_MARK = "# --- decomp reference (import_decomp.py) ---"


def patch_game_toml() -> str:
    p = RECOMP / "game.toml"
    text = p.read_text(encoding="utf-8")
    # Ensure overlay floor for 0x80060000-arena blobs (inside boot text range).
    if "overlay_region_floor" not in text:
        text = text.replace(
            "[runtime]\nwindow_title = \"tactical-recomp\"\nmemcard_dir = \"saves\"\noverlay_cache = true",
            "[runtime]\nwindow_title = \"tactical-recomp\"\nmemcard_dir = \"saves\"\noverlay_cache = true\noverlay_region_floor = \"0x80060000\"",
        )
    block = """%s
# Decomp ground truth (config/boot.yaml + config/symbol_addrs.txt):
#   exe load 0x80010000, gp 0x800329BC, text_size 0x56800 (entry 0x80010A30).
#   code ranges: main/main_2 0x80010000-0x80021F44, main_3 0x80022114-0x80028AE8,
#   main_4 0x80040934-0x8004593C, main_5 0x80059854-0x80064410.
#   trampolines/data islands are data, not funcs (link_section .text excepted).
#   overlay_region_floor 0x80060000 keeps OPEN/BATTLE/EVENT arena blobs
#   (inside boot text end 0x80066800) overlay-eligible; EFFECT 0x801C2500+
#   is above text end. Blob bases/load map: config/blobs/*.yaml.
""" % GAME_TOML_MARK
    # Migrate the pre-AOT-removal wording that pointed at aot/overlays.json.
    text = text.replace(
        "#   is above text end. Blob bases/load map: see aot/overlays.json\n"
        "#   (from config/blobs/*.yaml). Regenerate with import_decomp.py.\n",
        "#   is above text end. Blob bases/load map: config/blobs/*.yaml.\n",
    )
    if GAME_TOML_MARK not in text:
        if not text.endswith("\n"):
            text += "\n"
        text += "\n" + block
    return text


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()

    funcs, _, _ = build_symbols()
    old_seeds = parse_seeds(RECOMP / "seeds" / "ghidra_funcs.txt")
    seeds_text = render_seeds(funcs, old_seeds)
    symbols_text = render_symbols_toml(funcs)
    game_text = patch_game_toml()

    targets = {
        RECOMP / "seeds" / "ghidra_funcs.txt": seeds_text,
        RECOMP / "symbols.toml": symbols_text,
        RECOMP / "game.toml": game_text,
    }
    if args.check:
        rc = 0
        for path, want in targets.items():
            if not path.is_file() or path.read_text(encoding="utf-8") != want:
                print(f"out of date: {path.relative_to(ROOT)}", file=sys.stderr)
                rc = 1
        if rc == 0:
            print(f"ok: {len(funcs)} funcs")
        return rc
    for path, want in targets.items():
        path.write_text(want, encoding="utf-8")
        print(f"wrote {path.relative_to(ROOT)}")
    print(f"funcs={len(funcs)} seeds={len(parse_seeds(RECOMP / 'seeds' / 'ghidra_funcs.txt'))}")
    print("next: python3 recomp/tools/sync_symbols.py  (regenerates psx_symbols.h)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
