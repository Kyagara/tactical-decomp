#!/usr/bin/env python3
"""Guard the committed asm-macro headers against machine-specific paths.

splat's `write_include_asm_h` (splat/util/file_presets.py) bakes the *absolute*
`generated_asm_macros_directory` into `include_asm.h` as an assembler
`.include`, because `parse_path` resolves that option against `base_path`. The
result is a committed header that only assembles on the machine that ran the
split, so a fresh clone elsewhere fails to build.

Every splat config sets `generate_asm_macros_files: False`, which stops splat
writing these files at all and leaves them hand-maintained. This script is the
belt-and-braces check: it fails loudly if that option is ever dropped, or if an
absolute path reaches the header some other way.

Runs as a post-split step in the same recipe as the other post-processing
helpers (see `fix_trailing_data.py` for the sibling pattern).

Usage: check_asm_macros.py
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent

HEADER = ROOT / "include" / "include_asm.h"
CONFIGS = [ROOT / "config" / "boot.yaml"] + sorted((ROOT / "config" / "blobs").rglob("*.yaml"))

# An assembler .include whose target is an absolute path.
ABS_INCLUDE = re.compile(r'\.include\s+\\?"(?P<path>/[^"\\]+)\\?"')

# Home-directory style prefixes that should never appear in a committed header.
LEAKY_PREFIXES = ("/home/", "/Users/", "/private/var/", "C:\\")


def check_config(path: Path) -> list[str]:
    errs: list[str] = []
    try:
        text = path.read_text(errors="replace")
    except OSError:
        return errs
    if "generate_asm_macros_files" not in text:
        errs.append(f"{path.relative_to(ROOT)}: missing generate_asm_macros_files")
    elif not re.search(r"^\s*generate_asm_macros_files:\s*False\s*$", text, re.M):
        errs.append(
            f"{path.relative_to(ROOT)}: generate_asm_macros_files is not False "
            "(splat would rewrite include_asm.h with an absolute path)"
        )
    return errs


def check_header(path: Path) -> list[str]:
    errs: list[str] = []
    if not path.is_file():
        return [f"{path.relative_to(ROOT)}: missing"]
    try:
        text = path.read_text(errors="replace")
    except OSError as exc:
        return [f"{path.relative_to(ROOT)}: unreadable ({exc})"]

    for m in ABS_INCLUDE.finditer(text):
        target = m.group("path")
        rel = path.relative_to(ROOT)
        if not any(target.startswith(p) for p in LEAKY_PREFIXES):
            # An absolute path that is not a leaked home dir is still
            # machine-specific; only repo-relative includes are portable.
            errs.append(f"{rel}: absolute .include {target!r} (use a repo-relative path)")
        else:
            errs.append(
                f"{rel}: absolute .include {target!r} leaks this machine's "
                "checkout path (use a repo-relative path)"
            )
    return errs


def main() -> int:
    errs: list[str] = []
    for cfg in CONFIGS:
        errs += check_config(cfg)
    errs += check_header(HEADER)

    if errs:
        print("asm-macro header check FAILED:", file=sys.stderr)
        for e in errs:
            print(f"  {e}", file=sys.stderr)
        print(
            "\nFix: set generate_asm_macros_files: False in the splat config(s) "
            "and make include_asm.h use a repo-relative .include "
            '(__asm__(".include \\"include/macro.inc\\"\\n");).',
            file=sys.stderr,
        )
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
