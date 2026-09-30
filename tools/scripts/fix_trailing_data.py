#!/usr/bin/env python3
"""Append trailing partial-word bytes to splat data stubs.

splat emits data segments as `.word` lines only, silently dropping a
non-word-aligned tail (1-3 bytes). SMALL.OUT is the only disc file with a
non-aligned size (7891 bytes: data tail `[0x6C, 0x1ED3)` lost `32 31 FE`),
so its link came out 3 bytes short. This script re-appends the missing
bytes as `.byte` lines (splat-style address comments, ignored by the
assembler) so the link reproduces the oracle byte-identical.

Runs as a post-split step (`make split`, every target incl. exe); it is a
no-op unless a `data` subsegment ends off-alignment AND the generated
`.data.s` is actually short (idempotent: skips when the `.byte` tail is
already present). Generated `rom/extracted/` files stay reproducible from
`make extract` + `make split` per AGENTS.md.

Usage: fix_trailing_data.py [BLOB]   (empty = exe)
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib
import target as _target_mod  # noqa: E402  (target.py lives beside lib.py)

SEG_RE = re.compile(r"^  - name: (\S+)\s*$")
TYPE_RE = re.compile(r"^    type: (\S+)\s*$")
START_RE = re.compile(r"^    start: (0x[0-9A-Fa-f]+)\s*$")
VRAM_RE = re.compile(r"^    vram: (0x[0-9A-Fa-f]+)\s*$")
SUB_RE = re.compile(r"^      - \[(0x[0-9A-Fa-f]+),\s*(\S+?),\s*(\S+?)\]$")
END_RE = re.compile(r"^  - \[(0x[0-9A-Fa-f]+)\]\s*$")
WORD_RE = re.compile(r"/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s*\*/\s*\.word\b")
BYTE_RE = re.compile(r"/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s*\*/\s*\.byte\b")


def parse_segments(yaml_path: Path) -> tuple[list[dict], int | None]:
    """Minimal splat-segment parse: [{name,type,start,subs:[(s,kind,name)]}],
    plus the bare end-marker value (or None)."""
    segs: list[dict] = []
    cur: dict | None = None
    file_end: int | None = None
    for line in yaml_path.read_text(errors="replace").splitlines():
        m = SEG_RE.match(line)
        if m:
            cur = {"name": m.group(1), "type": None, "start": None,
                   "vram": None, "subs": []}
            segs.append(cur)
            continue
        m = END_RE.match(line)
        if m:
            file_end = int(m.group(1), 16)
            continue
        if cur is None:
            continue
        for rx, key in ((TYPE_RE, "type"), (START_RE, "start"),
                        (VRAM_RE, "vram")):
            m = rx.match(line)
            if m:
                v = m.group(1)
                cur[key] = int(v, 16) if v.startswith("0x") else v
        m = SUB_RE.match(line)
        if m:
            cur["subs"].append((int(m.group(1), 16), m.group(2), m.group(3)))
    return segs, file_end


def main() -> int:
    name = sys.argv[1] if len(sys.argv) > 1 else ""
    t = _target_mod.get_target(name or None)
    oracle = t.oracle.read_bytes()
    yaml_path = Path(t.yaml)
    asm_data = t.asm_root / "data"
    segs, file_end = parse_segments(yaml_path)
    # Segment end = next segment start, else the bare end marker, else EOF.
    ends: list[int | None] = []
    for i, s in enumerate(segs):
        if i + 1 < len(segs) and segs[i + 1]["start"] is not None:
            ends.append(segs[i + 1]["start"])
        else:
            ends.append(file_end if file_end is not None else len(oracle))
    rc = 0
    for seg, end in zip(segs, ends):
        if seg["type"] != "data" or end is None:
            continue
        for s_off, kind, sub in seg["subs"]:
            if kind != "data":
                continue
            rem = end % 4
            if rem == 0:
                continue
            last_word = end - rem
            want = oracle[last_word:end]
            path = asm_data / f"{sub}.data.s"
            if not path.is_file():
                print(f"fix_trailing_data: {path} not found, skip",
                      file=sys.stderr)
                rc = 1
                continue
            text = path.read_text(errors="replace")
            words = WORD_RE.findall(text)
            if not words or int(words[-1], 16) + 4 != last_word:
                print(f"fix_trailing_data: {path} last .word "
                      f"{words[-1] if words else None} + 4 != "
                      f"{last_word:X}, skip", file=sys.stderr)
                rc = 1
                continue
            if BYTE_RE.search(text):
                continue  # already fixed (idempotent re-run)
            vram = (seg["vram"] or 0) + (last_word - (seg["start"] or 0))
            tail = ", ".join(f"0x{b:02X}" for b in want)
            hexs = "".join(f"{b:02X}" for b in want)
            line = (f"    /* {last_word:X} {vram:X} {hexs} */ "
                    f".byte {tail}\n")
            lines = text.splitlines(keepends=True)
            # Keep the bytes inside the section: insert before a
            # trailing enddlabel line when present, else append.
            if lines and lines[-1].lstrip().startswith("enddlabel"):
                lines.insert(len(lines) - 1, line)
                path.write_text("".join(lines))
            else:
                with path.open("a") as f:
                    f.write(line)
            print(f"fix_trailing_data: {path} +{rem} trailing bytes")
    return rc


if __name__ == "__main__":
    raise SystemExit(main())
