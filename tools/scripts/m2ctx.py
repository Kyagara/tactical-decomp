#!/usr/bin/env python3
"""Generate a m2c context file (ctx.c) from include/.

Uses the host C preprocessor to flatten all repo headers into a single context
file that m2c/decomp.me can parse, mirroring the `m2ctx.py` used by other PSX
decomp projects. m2c only needs the type/struct declarations; inline asm and
guards are resolved away by preprocessing.
"""
from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib

ROOT = lib.ROOT


def collect_headers(extra: Path | None = None) -> list[Path]:
    roots = [ROOT / "include"]
    if extra:
        roots.append(extra)
    headers: list[Path] = []
    for root in roots:
        if root.is_dir():
            headers += sorted(root.rglob("*.h"))
    return headers


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("out", nargs="?", default="build/ctx.c",
                    help="Output C file (default: build/ctx.c)")
    ap.add_argument("-i", "--include", dest="extra_dir", type=Path, default=None,
                    help="Extra directory to scan for headers")
    args = ap.parse_args()

    headers = collect_headers(args.extra_dir)
    if not headers:
        print("No headers found under include/.", file=sys.stderr)
        return 1

    includes = "\n".join(f'#include "{h.relative_to(ROOT).as_posix()}"' for h in headers)
    cmd = [
        "gcc", "-E", "-P",
        "-I", str(ROOT),         # resolve "include/..."
        "-D", "M2CTX=1",
        "-D", "__asm__(...)=...".replace("...", ""),  # neutralise inline asm
        "-D", "__attribute__(...)=...",
        "-D", "INCLUDE_ASM_USE_MACRO_INC=1",
        "-xc", "-",
    ]

    try:
        proc = subprocess.run(
            cmd,
            input=includes + "\n",
            capture_output=True,
            text=True,
            cwd=ROOT,
        )
    except FileNotFoundError:
        print("`gcc` not found; m2ctx needs a working C preprocessor.", file=sys.stderr)
        return 1

    if proc.returncode != 0:
        print(proc.stderr, file=sys.stderr)
        return 1

    body = proc.stdout
    # Filter out empty/whitespace-only lines for a compact context.
    lines = [ln for ln in body.splitlines() if ln.strip()]
    out = ROOT / args.out
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text("\n".join(lines) + "\n")
    print(f"Wrote {out} (preprocessed {len(headers)} headers)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
