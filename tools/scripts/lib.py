#!/usr/bin/env python3
"""Shared constants and helpers for the FFT decomp tooling.

Single source of truth for:
  * repo-root path + toolchain/tool paths (so every script stops re-declaring
    ``ROOT = Path(__file__).resolve().parent.parent.parent`` and the gcc /
    maspsx / as / objdump locations).
  * stub lookup (``find_stub``) returning the inner glabel the m2c ``-f``
    target needs.
  * ``objdump_disasm`` positional disassembly (used by the permuter diff).
  * the gcc 2.6.0 -> maspsx -> as compile pipeline, both as an in-process
    ``compile()`` and as a generated ``compile.sh`` (which decomp-permuter
    shells out to).

Stdlib-only on purpose: asm-differ imports ``diff_settings`` from the repo
root, and that module imports this file, so ``lib`` must not pull in any
repo-specific module (no ``symbols`` import here).
"""
from __future__ import annotations

import re
import subprocess
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
VENV_PY = ROOT / "tools" / ".venv" / "bin" / "python"
M2C = ROOT / "tools" / "third_party" / "m2c" / "m2c.py"
GCC = ROOT / "tools" / "toolchain" / "bin" / "mipsel-none-elf-gcc"
MASPSX = ROOT / "tools" / "third_party" / "maspsx" / "maspsx.py"
AS = ROOT / "tools" / "toolchain" / "bin" / "mipsel-none-elf-as"
OBJDUMP = ROOT / "tools" / "toolchain" / "bin" / "mipsel-none-elf-objdump"
OBJCOPY = ROOT / "tools" / "toolchain" / "bin" / "mipsel-none-elf-objcopy"
CTX = ROOT / "build" / "ctx.c"
PERMUTER = ROOT / "tools" / "third_party" / "decomp-permuter"
PERMUTE = ROOT / "tools" / "scripts" / "permute.py"
SCRATCH = Path(os.environ.get("FFT_PERMUTER_SCRATCH", ROOT / "output" / "scratch"))
ASM_NM = ROOT / "rom" / "extracted" / "asm" / "nonmatchings"
BASE_ROM = ROOT / "rom" / "extracted" / "baserom" / "SCUS_942.21"
MAP = ROOT / "rom" / "extracted" / "baserom" / "SCUS_942.21.map"
OUT_BIN = ROOT / "build" / "SCUS_942.21.bin"


def find_stub(func, nm=None):
    """Locate a stub file by name in any segment.

    Returns ``(stub, segment, inner_line, inner)`` where ``inner`` is the last
    ``glabel`` before the body (the m2c ``-f`` target). Exits the process if
    not found (callers treat a missing stub as a fatal error). ``nm`` scopes
    the search to another target's nonmatchings root (e.g. a blob's).
    """
    matches = list((nm or ASM_NM).rglob("%s.s" % func))
    if not matches:
        print("no stub found for %s" % func, file=sys.stderr)
        sys.exit(1)
    stub = matches[0]
    seg = stub.parent.name
    lines = stub.read_text().splitlines()
    glabel_lines = [i for i, l in enumerate(lines) if re.match(r"^[ \t]*glabel ", l)]
    if not glabel_lines:
        print("no glabel found in %s" % stub, file=sys.stderr)
        sys.exit(1)
    inner_line = glabel_lines[-1]
    inner = lines[inner_line].split()[1]
    return stub, seg, inner_line, inner


def objdump_disasm(path):
    """Disassemble ``path`` and return normalized instruction lines.

    Strips the address + machine-code columns and any ``<symbol>`` operands so
    two objdumps can be compared positionally.
    """
    r = subprocess.run([str(OBJDUMP), "-d", str(path)],
                       stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
    out = []
    for line in r.stdout.splitlines():
        line = re.sub(r"^\s*[0-9a-f]+:\s+[0-9a-f]+\s+", "", line)
        line = re.sub(r" <[^>]*>", "", line)
        if line.strip() == "":
            continue
        out.append(line)
    return out


def write_compile_sh(d, aspsx=None):
    """Write the gcc -> maspsx -> as wrapper as ``compile.sh`` into ``d``.

    decomp-permuter invokes this file as ``./compile.sh input.c -o output.o``;
    variant_loop.py and permute.py use it too. Keep this the single source of
    the pipeline. ``aspsx`` is a maspsx ``--aspsx-version`` value (e.g. blob
    vintage ``"2.21"``); None keeps the exe default (2.34).
    """
    maspsx_arg = (" --aspsx-version %s" % aspsx) if aspsx else ""
    content = (
        "#!/bin/bash\n"
        "# decomp-permuter compile wrapper: repo gcc -> maspsx -> binutils as.\n"
        "set -e\n"
        'REPO="%s"\n' % ROOT +
        'IN="$1"\n'
        '[ "${2:-}" = "-o" ] || { echo "usage: compile.sh input.c -o output.o" >&2; exit 1; }\n'
        'OUT="$3"\n'
        'TMP="$(mktemp /tmp/permuter-XXXXXX)"\n'
        'trap \'rm -f "$TMP.pre.s" "$TMP.s" "$TMP"\' EXIT\n'
        '"$REPO/tools/toolchain/bin/mipsel-none-elf-gcc" -EL -mno-abicalls -mgp32 \\\n'
        '    -fno-builtin -fno-common -G0 -O2 -I"$REPO/include" -I"$REPO" -S -o "$TMP.pre.s" "$IN"\n'
        '"$REPO/tools/.venv/bin/python" "$REPO/tools/third_party/maspsx/maspsx.py"%s "$TMP.pre.s" > "$TMP.s" < /dev/null\n'
        % maspsx_arg +
        '"$REPO/tools/toolchain/bin/mipsel-none-elf-as" -EL -I"$REPO/include" -W -o "$OUT" "$TMP.s"\n'
    )
    p = d / "compile.sh"
    p.write_text(content)
    p.chmod(0o755)


def compile(in_c, out_o, aspsx=None):
    """Compile one C file through the pinned gcc -> maspsx -> as pipeline.

    Returns True on success. Used by variant_loop.py so it no longer shells out
    to a ``compile.sh`` file. ``aspsx`` is a maspsx ``--aspsx-version`` value
    (blob vintage); None keeps the exe default.
    """
    pre = out_o.with_suffix(".pre.s")
    asm = out_o.with_suffix(".s")
    try:
        gcc = subprocess.run([str(GCC), "-EL", "-mno-abicalls", "-mgp32",
                              "-fno-builtin", "-fno-common", "-G0", "-O2",
                              "-I%s/include" % ROOT, "-I%s" % ROOT, "-S",
                              "-o", str(pre), str(in_c)],
                             stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if gcc.returncode != 0:
            return False
        mpy_cmd = [str(VENV_PY), str(MASPSX)]
        if aspsx:
            mpy_cmd += ["--aspsx-version", str(aspsx)]
        mpy_cmd += [str(pre)]
        # maspsx reads stdin first unless it is a TTY (see MASPSX_FLAGS notes
        # in the Makefile): pin it to /dev/null so a redirected parent stdin
        # cannot be assembled instead of our .pre.s.
        mpy = subprocess.run(mpy_cmd, stdin=subprocess.DEVNULL,
                             stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
        if mpy.returncode != 0:
            return False
        asm.write_text(mpy.stdout)
        asl = subprocess.run([str(AS), "-EL", "-I%s/include" % ROOT, "-W",
                              "-o", str(out_o), str(asm)],
                             stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return asl.returncode == 0
    finally:
        pre.unlink(missing_ok=True)
        asm.unlink(missing_ok=True)
