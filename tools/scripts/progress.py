#!/usr/bin/env python3
"""Regenerate the Progress section of README.md.

One collapsed row per target (exe + every config/blobs/*.yaml), except
targets whose yaml declares `family:` (e.g. `family: effect`): family
members fold into one aggregate row (SOTN weapon-family precedent), with
per-file detail in each member's `build/blobs/<blob>/progress.json`.
Per-segment detail stays available via `--verbose` (stdout) and
`build/progress.json` (+ `build/blobs/<blob>/progress.json`).

The single signal is a function count per target, derived from the repo
alone -- no build, no link map:

  * matched: C definitions in the target's `src/*.c` units
    (`symbols.src_func_addrs`: `func_800XXXXX` / `D_800XXXXX` /
    `<blob>_800XXXXX` encode their own vram) plus applied-name definitions
    (`symbols.src_applied_name_addrs`: GetWD, ClearOTag, ... , resolved
    through the target's link map, so those DO need one build).
  * remaining: the live `func_*` stubs in `symbols.stub_scan`, minus tagged
    `INCLUDE_PSYQ` SDK stubs, minus handwritten COP2/GTE lib stubs. `D_*`
    stubs are nop pads, not functions, and are excluded too.

Byte progress was tried and dropped. It was delegated to
`mapfile_parser.getProgress` over the link map, which made the number a
property of the last full build instead of of the source: a blob with no
`build/blobs/<blob>/<blob>.map` reported `0 / 0` (and, with the PSYQ/COP2
exclusion subtracted from that missing total, negative), `pathIndex`-based
object-folder arithmetic broke whenever the build tree depth changed, and
freezing the sizes per function only traded the staleness for a committed
table to keep in sync. Function counts are what the workflow actually gates
on (they match the stubs that exist), and `coddog` already answers
"which functions are like this one", size included, when that matters.

The result is rendered as a markdown table and injected into README.md
between the PROGRESS markers, leaving the rest of the file hand-editable.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib
import symbols
try:
    import target as target_mod
except ImportError:
    target_mod = None

ROOT = lib.ROOT
README = ROOT / "README.md"
MARK_START = "<!-- PROGRESS:START -->"
MARK_END = "<!-- PROGRESS:END -->"

# Keys of `data` that are not per-segment counts.
_NON_SEG_KEYS = ("all", "func_matched", "func_total", "func_per_seg",
                 "psyq_n", "psyq_bytes", "cop2_n", "cop2_bytes")


def _targets(blob: str | None, all_targets: bool) -> list:
    if target_mod is None:
        return [None]
    if blob:
        return [target_mod.get_target(blob)]
    if all_targets:
        out = [target_mod.get_target(None)]
        out += [target_mod.get_target(b) for b in target_mod.list_blobs()]
        return out
    return [target_mod.get_target(None)]


def _label(t) -> str:
    if t is None or t.is_exe:
        return "SCUS_942.21"
    return t.label.upper()


def _segments(t) -> list[str]:
    if t is not None:
        return list(t.segments)
    return list(symbols.SEGMENTS)


def fmt(n: int) -> str:
    return f"{n:,}"


# --- sources: what is C, what is still asm ---------------------------------

def matched_definitions(t) -> dict[int, dict]:
    """{vram: {c_name, path, line}} for every C definition in the target's units.

    Addressed names (`func_800XXXXX`, `D_800XXXXX`, `<blob>_800XXXXX`) plus
    applied-name definitions resolved through the link map.
    """
    defs = symbols.src_func_addrs(target=t)
    for vram, info in symbols.src_applied_name_addrs(target=t).items():
        defs.setdefault(vram, info)
    return defs


def remaining_stubs(t) -> dict[str, dict]:
    """{name: info} for the live stubs that still count as game code.

    `func_*` stubs only, minus tagged `INCLUDE_PSYQ` SDK stubs
    (`symbols.is_psyq_stub`) and minus handwritten COP2/GTE lib stubs
    (`symbols.cop2_stubs`); `D_*` stubs are nop pads, not functions. A stub
    whose vram already has a C definition (an interrupted `finish` leaves
    both behind) is dropped: that function is decompiled.
    """
    cop2 = symbols.cop2_stubs(target=t)
    done = set(matched_definitions(t))
    out: dict[str, dict] = {}
    for k, info in symbols.stub_scan(target=t).items():
        if not k.startswith("func_"):
            continue
        if symbols.is_psyq_stub(k, info.get("vram")):
            continue
        if k in cop2:
            continue
        if info.get("vram") in done:
            continue
        out[k] = info
    return out


def func_counts(t, defs: dict, rem: dict) -> tuple[int, int, dict[str, tuple[int, int]]]:
    """(matched, total, per_segment) functions by count.

    Matched is split per segment by the defining C unit (`src/<seg>.c`),
    remaining by the stub's segment. Segments with no functions still show
    up (0 / 0) so a target's segment list never depends on how far the work
    has progressed.
    """
    matched_per: dict[str, int] = {}
    for info in defs.values():
        seg = info["path"].stem  # src/<seg>.c -> <seg>
        matched_per[seg] = matched_per.get(seg, 0) + 1
    remaining_per: dict[str, int] = {}
    for info in rem.values():
        seg = info.get("segment", "")
        remaining_per[seg] = remaining_per.get(seg, 0) + 1
    per_seg: dict[str, tuple[int, int]] = {}
    for seg in sorted(set(_segments(t)) | set(matched_per) | set(remaining_per)):
        m = matched_per.get(seg, 0)
        r = remaining_per.get(seg, 0)
        per_seg[seg] = (m, m + r)
    matched = sum(matched_per.values())
    return matched, matched + sum(remaining_per.values()), per_seg


def psyq_excluded(t=None) -> tuple[int, int]:
    """(stubs, bytes) for tagged INCLUDE_PSYQ stubs.

    Byte total comes from the stubs' own `nonmatching` headers, so it needs
    no build; it is only used for the README footnote.
    """
    n = b = 0
    for k, info in symbols.stub_scan(target=t).items():
        if k.startswith("func_") \
                and symbols.is_psyq_stub(k, info.get("vram")):
            n += 1
            b += info.get("size") or 0
    return n, b


def cop2_excluded(t=None) -> tuple[int, int]:
    """(stubs, bytes) for handwritten COP2/GTE stubs.

    Sony LIBGTE asm (SquareRoot*, matrix/vector kernels, ...): never
    decompiled, same as PSYQ. Disjoint from `psyq_excluded` (PSYQ-tagged
    stubs count there even when they contain COP2 ops).
    """
    cop2 = symbols.cop2_stubs(target=t)
    return len(cop2), sum(info.get("size") or 0 for info in cop2.values())


def _fold_families(rows: list[tuple[str, dict]], targets: list) \
        -> list[tuple[str, dict]]:
    """Merge `Target.family` members into one aggregate row.

    SOTN weapon-family precedent (`DecompProgressWeaponStats` sums all 59
    `weapon/w0_###` overlays into one "weapon" entry): many per-file
    configs, one README line. Per-file detail stays in each member's
    `build/blobs/<blob>/progress.json` (still written per target).
    """
    out: list = []
    fams: dict[str, dict] = {}
    for (label, data), t in zip(rows, targets):
        fam = getattr(t, "family", None) if t is not None else None
        if not fam:
            out.append((label, data))
            continue
        agg = fams.get(fam)
        if agg is None:
            agg = {"n": 0, "data": {
                "all": {"matched": 0, "total": 0, "percentage": 0.0},
                "func_matched": 0, "func_total": 0,
                "psyq_n": 0, "psyq_bytes": 0, "cop2_n": 0, "cop2_bytes": 0,
            }}
            fams[fam] = agg
            out.append(("__fam__", fam))
        agg["data"]["all"]["matched"] += data["all"]["matched"]
        agg["data"]["all"]["total"] += data["all"]["total"]
        agg["data"]["func_matched"] += data.get("func_matched", 0)
        agg["data"]["func_total"] += data.get("func_total", 0)
        for k in ("psyq_n", "psyq_bytes", "cop2_n", "cop2_bytes"):
            agg["data"][k] += data.get(k, 0)
        agg["n"] += 1
    final: list[tuple[str, dict]] = []
    for item in out:
        if isinstance(item, tuple) and item[0] != "__fam__":
            final.append(item)
            continue
        fam = item[1]
        agg = fams[fam]
        d = agg["data"]
        d["all"]["percentage"] = round(
            d["all"]["matched"] / d["all"]["total"] * 100.0, 4) \
            if d["all"]["total"] else 0.0
        n = agg["n"]
        unit = "file" if n == 1 else "files"
        d["short_label"] = fam.upper()
        d["family_note"] = (
            f"aggregates {n} per-file blob targets "
            f"(`config/blobs/{fam}/*.yaml`, one splat config per "
            f"binary); per-file detail: `build/blobs/{fam}_*/progress.json`.")
        final.append((f"{fam.upper()} ({n} {unit})", d))
    return final


def render_all(rows: list[tuple[str, dict]]) -> str:
    """Collapsed table: one row per target, percentage inline."""
    lines = []
    lines.append("| Target | Functions |")
    lines.append("| --- | ---: |")
    foot_psyq: list[str] = []
    foot_cop2: list[str] = []
    for label, data in rows:
        e = data.get("all", {})
        matched = e.get("matched", 0)
        total = e.get("total", 0)
        pct = e.get("percentage", 0.0)
        lines.append(f"| {label} | {fmt(matched)} / {fmt(total)} ({pct:.2f}%) |")
        fl = data.get("short_label", label)
        if data.get("psyq_n"):
            n = data["psyq_n"]
            foot_psyq.append(
                f"{fl}: {fmt(n)} tagged `INCLUDE_PSYQ` "
                f"stub{'s' if n != 1 else ''} "
                f"({fmt(data['psyq_bytes'])} bytes) are SDK bytes and not counted above.")
        if data.get("cop2_n"):
            n = data["cop2_n"]
            plural = n != 1
            foot_cop2.append(
                f"{fl}: {fmt(n)} handwritten LIBGTE "
                f"stub{'s' if plural else ''} "
                f"({fmt(data['cop2_bytes'])} bytes) "
                f"{'are' if plural else 'is'} never-decompiled lib asm "
                f"(`config/hard_tails.txt`) and not counted above.")
    lines.append("")
    # One blank line between notes: each is its own markdown paragraph, so
    # GitHub renders them as separate lines instead of collapsing the block.
    notes = [f"_{l}_" for l in foot_psyq]
    notes += [f"_{l}_" for l in foot_cop2]
    for _label, data in rows:
        if data.get("family_note"):
            fl = data.get("short_label", _label)
            notes.append(f"_{fl}: {data['family_note']}_")
    if notes:
        lines.append("\n\n".join(notes))
        lines.append("")
    lines.append(
        "_One signal per target: function counts via `symbols` - matched C "
        "definitions in the target's `src/*.c` units (applied names resolved "
        "through the link map) vs remaining `func_*` stubs, minus `INCLUDE_PSYQ` "
        "SDK stubs, minus handwritten COP2/GTE lib stubs; `D_*` nop pads "
        "excluded. No build or link map required (byte progress was dropped: "
        "coddog already searches by size). Per-segment detail: `make status` / "
        "progress `--verbose`; machine readable: `build/progress.json` + "
        "`build/blobs/<blob>/progress.json`._"
    )
    return "\n".join(lines)


def render_verbose(label: str, data: dict, t=None) -> str:
    lines = [f"## {label} (per-segment)"]
    lines.append("| Segment | Decompiled | Total | Progress |")
    lines.append("| --- | ---: | ---: | ---: |")
    for seg in (k for k in data if k not in _NON_SEG_KEYS):
        e = data[seg]
        pct = e["matched"] / e["total"] * 100.0 if e["total"] else 0.0
        lines.append(f"| {seg} | {fmt(e['matched'])} | {fmt(e['total'])} | "
                     f"{pct:.2f}% |")
    return "\n".join(lines)


def compute(t=None) -> dict:
    """Return per-segment function counts keyed by segment (code unit) name.

    `data["all"]` sums the segments; `psyq_*` / `cop2_*` back the footnotes.
    """
    defs = matched_definitions(t)
    rem = remaining_stubs(t)
    f_matched, f_total, per_seg = func_counts(t, defs, rem)
    data: dict = {seg: {"matched": m, "total": tot,
                        "percentage": round(m / tot * 100.0, 4) if tot else 0.0}
                  for seg, (m, tot) in per_seg.items()}
    data["all"] = {
        "matched": f_matched,
        "total": f_total,
        "percentage": round(f_matched / f_total * 100.0, 4) if f_total else 0.0,
    }
    data["func_matched"] = f_matched
    data["func_total"] = f_total
    data["func_per_seg"] = {seg: list(v) for seg, v in per_seg.items()}
    data["psyq_n"], data["psyq_bytes"] = psyq_excluded(t)
    data["cop2_n"], data["cop2_bytes"] = cop2_excluded(t)
    return data


def json_path(t) -> Path:
    if t is not None:
        return t.build / "progress.json"
    return ROOT / "build" / "progress.json"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--blob", default=None, help="one blob target (no README write)")
    ap.add_argument("--all", action="store_true",
                    help="all targets (default; writes README)")
    ap.add_argument("--verbose", action="store_true",
                    help="per-segment detail on stdout")
    args = ap.parse_args()

    if args.blob:
        targets = _targets(args.blob, False)
        write_readme = False
    else:
        targets = _targets(None, True)
        write_readme = True

    rows = []
    for t in targets:
        data = compute(t)
        label = _label(t)
        rows.append((label, data))
        jp = json_path(t)
        jp.parent.mkdir(parents=True, exist_ok=True)
        jp.write_text(json.dumps(data, indent=2, default=str) + "\n")

    if args.verbose:
        for (label, data), t in zip(rows, targets):
            print(render_verbose(label, data, t))
            print()
    if not args.blob:
        rows = _fold_families(rows, targets)
    body = render_all(rows)
    print(body)

    if write_readme:
        block = f"{MARK_START}\n\n{body}\n\n{MARK_END}\n"
        text = README.read_text(errors="replace")
        pat = re.compile(re.escape(MARK_START) + r".*?" + re.escape(MARK_END), re.S)
        if pat.search(text):
            text = pat.sub(block.strip(), text)
        else:
            text = text.rstrip() + f"\n\n## Progress\n\n{block}"
        README.write_text(text)
        print("Updated README.md Progress section")
    return 0


if __name__ == "__main__":
    sys.exit(main())
