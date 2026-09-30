#!/usr/bin/env python3
"""Convenience wrapper around the m2c decompiler using repo settings."""
from __future__ import annotations

import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib

M2C = lib.M2C
VENV_PY = lib.VENV_PY


def main() -> int:
    args = sys.argv[1:]
    if not args:
        print(__doc__)
        print("usage: m2c [options] <asm files>")
        return 2
    # Spawn the third-party m2c as a subprocess: runpy.run_path misbehaves
    # under Python 3.14 (sets __file__ to a Path, which the m2c internals
    # choke on), and a fresh interpreter is version-agnostic.
    cmd = [str(VENV_PY), str(M2C)] + args
    return subprocess.run(cmd).returncode


if __name__ == "__main__":
    sys.exit(main())
