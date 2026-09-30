#!/usr/bin/env python3
"""Shared symbol/stub helpers for the naming and decomp tooling.

Single source of truth for three things every tool used to re-derive:

  * function vram: derived from the symbol name itself (hex after ``_``,
    e.g. ``func_800XXXXX`` or ``D_800XXXXX`` -> ``int(hex,16)``).  A legacy
    ``/* func_800XXXXX */`` comment one line above the definition is still
    recognised as a fallback but is no longer required and has been removed
    from src/.  Applied-names definitions (``GetWD``, ``Startup``, ...)
    resolve via the link map (``src_applied_name_addrs``).
  * stub scanning: one instruction-count method (size from the
    ``nonmatching <func>, 0x<size>`` header, not line counting).
  * stub health classification (merged / rodata / PSYQ / tail), shared by
    pick_function --clean and workflow.py decompile's warnings.

Consumers: tools/scripts/{pick_function,progress,m2ctx}.py.
"""
from __future__ import annotations

import re
from pathlib import Path

try:
    import target as _target_mod  # sibling: tools/scripts/target.py
except ImportError:
    _target_mod = None

ROOT = Path(__file__).resolve().parent.parent.parent
ASM_NM = ROOT / "rom" / "extracted" / "asm" / "nonmatchings"
SRC = ROOT / "src"
MAP = ROOT / "rom" / "extracted" / "baserom" / "SCUS_942.21.map"
SYM_FILE = ROOT / "config" / "symbol_addrs.txt"
CSV_FILE = ROOT / "config" / "psyq_matches.csv"

SEGMENTS = ("main", "main_2", "main_3", "main_4", "main_5")


def _resolve_target(target):
    """Normalize None / blob-name / Target to a Target (or None)."""
    if target is None or _target_mod is None:
        return None
    if isinstance(target, str):
        return _target_mod.get_target(target or None)
    return target


def vram_from_name(name: str) -> int | None:
    """VRAM from a `PREFIX_800XXXXX` name (func_/D_/<blob>_), or None.

    One rule for every prefix: hex after the last ``_`` must be 8 digits
    in PSX RAM (``0x80000000-0x801FFFFF``).  Applied names (``GetWD``)
    carry no address and return None.
    """
    if name and "_" in name:
        hexpart = name.rsplit("_", 1)[1]
        if len(hexpart) == 8:
            try:
                vram = int(hexpart, 16)
            except ValueError:
                return None
            if 0x80000000 <= vram <= 0x801FFFFF:
                return vram
    return None


def _unit_c_files(src_root: Path, target) -> list[Path]:
    """C unit files for a target (exe units by default, blob units scoped)."""
    t = _resolve_target(target)
    if t is None:
        if _target_mod is not None:
            units = _target_mod.get_target(None).src_units
            paths = [src_root / f"{u}.c" for u in units]
            found = [p for p in paths if p.is_file()]
            if found:
                return sorted(found)
        return sorted(src_root.glob("*.c"))
    files: list[Path] = []
    for u in t.src_units:
        p = t.unit_src(u)
        if p.is_file() and p not in files:
            files.append(p)
    return sorted(files)

# legacy address comment (one line above the def, optional).  Kept for
# backwards-compatibility; the name fallback below is now the primary path.
ADDR_COMMENT_RE = re.compile(r"^\s*/\*\s*((?:func|D)_[0-9A-Fa-f]{8})\s*\*/")

# a real C definition: return type (optional), name, parens, `{`.  The name
# must not be a statement keyword.  Lines ending `;` (externs, prototypes,
# INCLUDE_ASM tokens) never match because `{` is required.
_DEF_RE = re.compile(
    r"^(?P<ret>[A-Za-z_][\w ]*?\s+(?:\*\s*)?)?"
    r"(?P<name>(?!(?:if|for|while|switch|do|return|goto|sizeof|typeof|"
    r"typedef|static|extern|void)\b)[A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*\)\s*\{"
)

_MAP_RE = re.compile(
    r"\s*0x([0-9A-Fa-f]{16})[ \t]+([A-Za-z_.$][A-Za-z0-9_.$]*)(?:\s|=|$)")

# COP2 transfer/memory ops + GTE macro ops.  Stubs containing these are
# Sony LIBGTE handwritten asm (SquareRoot*, matrix/vector kernels, ...),
# never decompiled to C89 -- m2c has no COP2 support and the originals are
# hand-scheduled SDK code (see the "Permanent asm" tier in
# config/hard_tails.txt).  Shared by progress.py (exclusion counts) and
# pick_function.py (difficulty doubling); keep the two in sync by importing
# this instead of re-declaring.
COP2_RE = re.compile(r"\b(cop2|cfc2|ctc2|mfc2|mtc2|lwc2|swc2)\b", re.I)
GTE_RE = re.compile(
    r"\b(sqr|mvmva|gpf|gpl|avsz[34]|rtps|rtpt|nclip|dpcs|dpct|dpcl|intpl|"
    r"lzcs)\b", re.I)


def is_cop2_text(text: str) -> bool:
    """True when stub text contains COP2/GTE instructions (lib code)."""
    return bool(COP2_RE.search(text) or GTE_RE.search(text))


def cop2_stubs(stubs: dict | None = None, target=None) -> dict[str, dict]:
    """{name: info} for live stubs containing COP2/GTE instructions.

    Sony LIBGTE handwritten asm (SquareRoot*, matrix/vector kernels,
    ...), never decompiled to C89 -- same standing as PSYQ stubs.
    PSYQ-tagged stubs are excluded here so the two buckets never
    double-count (a PSYQ stub with COP2 ops counts under PSYQ).
    """
    out = {}
    for name, info in (stubs or stub_scan(target=target)).items():
        if not name.startswith("func_"):
            continue
        if is_psyq_stub(name, info.get("vram")):
            continue
        try:
            text = info["file"].read_text(errors="replace")
        except OSError:
            continue
        if is_cop2_text(text):
            out[name] = info
    return out


def def_name(line: str) -> str | None:
    """The function name of a C definition line, or None."""
    m = _DEF_RE.match(line)
    return m.group("name") if m else None


def is_definition(line: str) -> bool:
    return _DEF_RE.match(line) is not None


# K&R (old-style) definition header: `ret name(params)` with neither `{`
# nor `;` on the line; 1+ parameter-declaration lines follow, then a lone
# `{`.  m2c emits K&R when call sites disagree on arity (main_4
# func_800437D8/80044600/800447BC are all called with 0 args, so ANSI
# prototypes would not compile); the single-line _DEF_RE above can never
# match those, and progress undercounted them.  Keep the matcher strict
# (ends with `)`, decl lines are `type ident;`) so Allman `if (...)`
# blocks and multi-line calls never count.
_KR_HDR_RE = re.compile(
    r"^(?P<ret>[A-Za-z_][\w ]*?\s+(?:\*\s*)?)?"
    r"(?P<name>(?!(?:if|for|while|switch|do|return|goto|sizeof|typeof|"
    r"typedef|static|extern|void)\b)[A-Za-z_][A-Za-z0-9_]*)\s*\([^;{}]*\)\s*$"
)

_KR_DECL_RE = re.compile(
    r"^\s*(register\s+)?[A-Za-z_][\w\s\*]*[A-Za-z0-9_\]]"
    r"(\s*,\s*[A-Za-z_][A-Za-z0-9_\]]*)*\s*;\s*$"
)


def kr_def_name(lines: list[str], i: int) -> str | None:
    """Name of a K&R definition headed at lines[i], or None."""
    if not (0 <= i < len(lines)):
        return None
    m = _KR_HDR_RE.match(lines[i])
    if not m or _DEF_RE.match(lines[i]):
        return None
    name = m.group("name")
    seen_decl = False
    for j in range(i + 1, min(i + 9, len(lines))):
        s = lines[j].strip()
        if not s:
            continue
        if s == "{":
            return name if seen_decl else None
        if _KR_DECL_RE.match(lines[j]):
            seen_decl = True
            continue
        return None
    return None


def src_func_addrs(src: Path | None = None, target=None) -> dict[int, dict]:
    """{vram: {c_name, path, line}} for every C definition in a target's units.

    The address is derived from the function name itself (``func_800XXXXX``,
    ``D_800XXXXX`` or ``<blob>_800XXXXX`` -> hex after ``_``).  A legacy
    ``/* func_800XXXXX */`` comment directly above the definition is still
    honoured as a fallback.  ``target`` scopes the scan: None scans the exe
    units, a blob name / Target scans that blob's units only.
    """
    out = {}
    for path in _unit_c_files(src or SRC, target):
        lines = path.read_text(errors="replace").splitlines()
        for i, ln in enumerate(lines):
            name = def_name(ln)
            if name is None:
                name = kr_def_name(lines, i)
                if name is None:
                    continue
            vram = None
            if i > 0:
                cm = ADDR_COMMENT_RE.match(lines[i - 1])
                if cm:
                    vram = int(cm.group(1).split("_")[1], 16)
            if vram is None:
                vram = vram_from_name(name) if name else None
            if vram is not None:
                out.setdefault(vram, {"c_name": name, "path": path,
                                      "line": i})
    return out


def vram_from_map(name: str, map_path: Path | None = None) -> int | None:
    """Look up a C function's vram in the GNU linker map (renamed defs)."""
    p = map_path or MAP
    if not p.is_file():
        return None
    for ln in p.read_text(errors="replace").splitlines():
        m = _MAP_RE.match(ln)
        if m and m.group(2).split(".")[0] == name:
            return int(m.group(1), 16)
    return None


def src_applied_name_addrs(src: Path | None = None,
                           map_path: Path | None = None,
                           target=None,
                           ) -> dict[int, dict]:
    """{vram: {c_name, path, line}} for applied-names C definitions.

    Companion to src_func_addrs() for definitions whose names carry no
    address (GetWD, Startup, ClearOTag, ...): vram is resolved from
    the link map instead of the name.  Names already covered by
    src_func_addrs() (``func_*``/``D_*``/``*_800XXXXXX``) are skipped, as
    are definitions with no map entry (e.g. without a built map).
    ``target`` scopes both the unit scan and the default map file.
    """
    t = _resolve_target(target)
    if map_path is None and t is not None:
        map_path = t.map
    known = {info["c_name"] for info in src_func_addrs(src, target).values()}
    out = {}
    for path in _unit_c_files(src or SRC, target):
        lines = path.read_text(errors="replace").splitlines()
        for i, ln in enumerate(lines):
            name = def_name(ln)
            if name is None:
                name = kr_def_name(lines, i)
                if name is None:
                    continue
            if name in known:
                continue
            vram = vram_from_map(name, map_path)
            if vram is None:
                continue
            if not (0x80000000 <= vram <= 0x801FFFFF):
                continue
            out.setdefault(vram, {"c_name": name, "path": path,
                                  "line": i})
    return out


def vram_from_symbol_addrs(name: str) -> int | None:
    """Look up `Name = 0xADDR;` in config/symbol_addrs.txt."""
    if not SYM_FILE.is_file():
        return None
    for ln in SYM_FILE.read_text().splitlines():
        m = re.match(rf"^{re.escape(name)} = 0x([0-9A-F]+);", ln)
        if m:
            return int(m.group(1), 16)
    return None


def stub_scan(nm: Path | None = None, fragments: bool = False,
              target=None) -> dict[str, dict]:
    """{name: {file, segment, vram, size, instrs}} for every function stub.

    Indexes every .s in the nonmatchings dirs that carries a `nonmatching`
    function header (func_*, <blob>_*, PSYQ/wiki-named stubs, .L fragments when
    fragments=True, and rodata/data pieces when data=True).  instrs =
    size // 4 from the nonmatching header (one method).  ``target`` scopes
    the scan to one target's stub dirs (exe by default).
    """
    out = {}
    t = _resolve_target(target)
    segs = t.segments if t is not None else SEGMENTS
    base = nm or (t.asm_nm if t is not None else ASM_NM)
    for seg in segs:
        d = base / seg
        if not d.is_dir():
            continue
        for f in sorted(p for p in d.iterdir() if p.suffix == ".s"):
            name = f.stem
            if name.startswith("pad_"):
                continue  # alignment-nop carriers (split_merged pad_* stubs)
            if name.startswith(".") and not (fragments
                                             and name.startswith(".L")):
                continue
            text = f.read_text(errors="replace")
            # header size: prefer the file's own header (stubs can carry
            # jumptable/rodata pieces with their own nonmatching headers
            # above the function), else the first sized nonmatching line
            # (relabelled stubs keep a PSYQ/wiki name in the header).
            m = re.search(rf"nonmatching {re.escape(name)}, 0x([0-9A-Fa-f]+)",
                          text)
            if not m:
                m = re.search(r"nonmatching [A-Za-z_.$][\w.$]*, "
                              r"0x([0-9A-Fa-f]+)", text)
            if not m:
                continue
            # the file name is the reliable vram source (fragments are named
            # by address); PSYQ/wiki-named stubs fall back to the first
            # instruction-comment vram in the file.
            vram = vram_from_name(name)
            if vram is None:
                if name.startswith(".L"):
                    vram = int(name[2:], 16)
                else:
                    mvr = re.search(r"/\*\s*[0-9A-Fa-f]{4,8}\s+"
                                    r"(800[0-9A-Fa-f]{5})\s+", text)
                    vram = int(mvr.group(1), 16) if mvr else 0
            if m.group(1):
                size = int(m.group(1), 16)
                instrs = size // 4
            else:
                # header without a size (trampoline/data stubs): count the
                # instruction-comment lines instead
                size = None
                instrs = sum(
                    1 for ln in text.splitlines()
                    if re.match(r"^\s*/\* [0-9A-Fa-f]{1,8} 800[0-9A-Fa-f]{5} ",
                                ln))
            out[name] = {"file": f, "segment": seg, "vram": vram,
                         "size": size, "instrs": instrs}
    return out


def find_stub(sym: str, nm: Path | None = None, target=None) -> Path | None:
    """Locate a stub file by name in any segment (target-scoped)."""
    t = _resolve_target(target)
    for name, info in stub_scan(nm or (t.asm_nm if t is not None else None),
                                fragments=True,
                                target=target).items():
        if name == sym:
            return info["file"]
    return None


def prune_stale_stubs(src: Path | None = None, nm: Path | None = None,
                      target=None) \
        -> list[Path]:
    """Delete func_*.s stubs no longer referenced by their segment's C unit.

    Splat normally stops emitting a stub once the function's INCLUDE_ASM
    (or INCLUDE_PSYQ) token leaves src/<seg>.c, but leftovers can survive
    (branch switches, interrupted finishes); this removes them.  Runs as
    the last phase of the FFH name pass so relabelling sees the complete
    tree first.  ``target`` scopes the segment/unit lists (exe by default).
    """
    removed = []
    t = _resolve_target(target)
    segs = t.segments if t is not None else SEGMENTS
    src_root = src or SRC
    nm_root = nm or (t.asm_nm if t is not None else ASM_NM)
    units = (t.src_units if t is not None
             else (list(_target_mod.get_target(None).src_units)
                   if _target_mod is not None else list(SEGMENTS)))
    for seg, unit in zip(segs, units):
        cfile = t.unit_src(unit) if t is not None else src_root / f"{unit}.c"
        if not cfile.is_file():
            continue
        ctext = cfile.read_text(errors="replace")
        d = nm_root / seg
        if not d.is_dir():
            continue
        for f in sorted(p for p in d.iterdir() if p.suffix == ".s"):
            name = f.stem
            if name.startswith("D_"):
                continue  # rodata pieces, keep
            if name.startswith("."):
                # dot-prefixed stubs (e.g. .L80040A00 GameLoop): prune when
                # the INCLUDE_ASM token is gone, same as regular function stubs
                pass
            if name.startswith("pad_"):
                # pad stubs are permanent alignment; keep if still referenced
                # but if token is gone they are stale padding - still remove
                pass
            # only consider stubs whose token is missing; keep pad/jtbl if still referenced
            if not re.search(
                    rf"INCLUDE_(?:ASM|RODATA|PSYQ)[^)]*{re.escape(name)}",
                    ctext):
                f.unlink()
                removed.append(f)
    return removed


def stub_health(path: Path) -> dict:
    """Classify one stub: merged / rodata / PSYQ / tail flags.

    A stub is clean (empty dict) only if it contains no extra bodies (no
    `alabel`, no second distinct-name glabel -- multiple `jr ra` are normal
    switch exits, not merges), ends `endlabel`, carries no embedded .rodata,
    and its glabel survived relabelling.
    """
    text = path.read_text(errors="replace")
    flags = {}
    n_alabel = len(re.findall(r"\balabel\b", text))
    if n_alabel:
        flags["merged"] = f"alabel={n_alabel}"
    # extra glabels: alias annotations carry inline comments (`/* func alias */`,
    # `/* FFH wiki */`, `/* PSYQ ... */`) and are the SAME function; bare
    # splat-emitted glabels (no comment) mark real merged bodies.
    others = []
    for gl in re.finditer(r"\bglabel\s+([A-Za-z_]\w*)([^\n]*)", text):
        name, rest = gl.group(1), gl.group(2)
        if "/*" in rest:
            continue  # relabel-pass alias for this very function
        others.append(name)
    if others:
        others = others[1:]  # first glabel is the function itself
    others = set(others)
    if others:
        flags["merged"] = (flags.get("merged") + f" glabel={sorted(others)}"
                           if "merged" in flags else f"glabel={sorted(others)}")
    if not (text.splitlines() and text.splitlines()[-1].startswith("endlabel")):
        flags["bad_tail"] = True
    if re.search(r"\.section \.rodata|dlabel D_", text):
        flags["rodata"] = True
    if re.search(r"\bglabel [A-Za-z_]", text) \
            and not re.search(rf"\bglabel {re.escape(path.stem)}\b", text):
        flags["psyq"] = True
    return flags


def implemented_vram(target=None) -> set[int]:
    """vram of every function already implemented as C in a target's units."""
    return set(src_func_addrs(target=target))


_psyq_addrs_cache: set[int] | None = None
_psyq_sizes_cache: dict[int, int] | None = None


def _psyq_rows() -> list[dict]:
    if not CSV_FILE.is_file():
        return []
    import csv
    with CSV_FILE.open() as f:
        return [r for r in csv.DictReader(f)
                if _hit(r) >= 0.999]


def _hit(r: dict) -> float:
    try:
        return float(r["hit"])
    except (ValueError, KeyError):
        return 0.0


def psyq_addrs() -> set[int]:
    """vram of every exact (1.000-hit) PSYQ fingerprint in psyq_matches.csv.

    These ROM functions are Sony SDK bytes: not-yet-decompiled ones are
    tagged INCLUDE_PSYQ stubs and excluded from game-code progress/pick
    counts (see docs/PSYQ_STUB_POLICY.md). Already-matched PSYQ C
    definitions keep counting as matched (matched is matched).
    """
    global _psyq_addrs_cache
    if _psyq_addrs_cache is not None:
        return _psyq_addrs_cache
    out: set[int] = set()
    for r in _psyq_rows():
        try:
            out.add(int(r["vram"], 16))
        except (ValueError, KeyError):
            pass
    _psyq_addrs_cache = out
    return out


def psyq_sizes() -> dict[int, int]:
    """csv vram -> object size for every exact PSYQ fingerprint."""
    global _psyq_sizes_cache
    if _psyq_sizes_cache is not None:
        return _psyq_sizes_cache
    out: dict[int, int] = {}
    for r in _psyq_rows():
        try:
            out[int(r["vram"], 16)] = int(r["size"])
        except (ValueError, KeyError):
            pass
    _psyq_sizes_cache = out
    return out


def is_psyq_stub(name: str, vram: int | None = None) -> bool:
    """True when a stub is tagged-out SDK code (excluded from game counts).

    Resolves vram from the stub name when omitted (`func_800XXXXX` hex;
    other names via the link map, falling back to the stub scan's
    instruction-comment address). Hand-written SDK objects are labeled one
    word past the csv start (the word at the csv vram belongs to the
    previous function's delay slot, e.g. func_8001C0C4 vs csv 0x8001c0c0).
    The one-word lookback only fires when the stub body size exactly equals
    the csv object size, so unrelated neighbors (e.g. the COP0 exception
    entry func_8001DAD0) never match.
    """
    if vram is None:
        vram = vram_from_name(name)
        if vram is None:
            vram = vram_from_map(name) or \
                stub_scan().get(name, {}).get("vram", 0) or 0
    addrs = psyq_addrs()
    if vram in addrs:
        return True
    if (vram - 4) in addrs:
        size = stub_scan().get(name, {}).get("size")
        if size is not None and size == psyq_sizes().get(vram - 4):
            return True
    return False


if __name__ == "__main__":
    import sys
    print(f"{len(src_func_addrs())} C definitions, "
          f"{len(stub_scan())} func stubs", file=sys.stderr)
