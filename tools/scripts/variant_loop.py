#!/usr/bin/env python3
"""Structured variant loop for one FFT stub (codified from docs/MATCHING_TECHNIQUES.md §9).

Reuses the decomp-permuter scratch dir (output/scratch/<func>/
via permute.py setup --no-run): target.o holds the ORIGINAL bytes of the function,
compile.sh is the repo gcc 2.6.0 -> maspsx -> as pipeline, base.c is the
m2c seed.

Variants generated from base.c:
  - statement-order rotations: adjacent top-level statement swaps
  - type-width swaps: int/s32/u32/u16/s16/u8/s8 per local/param
  - register pins: register T name asm("reg") per plain local x reg
    (PERM_TRICKS.md §1)
  - volatile pointers: volatile T *p per pointer local (PERM_TRICKS.md §3/§6)
  - manual shapes: every .c file in scratch/variants/ (write your own
    if/else <-> switch <-> ternary, comma-expr, clamp, ...)

Compiled in parallel and scored by byte-diff against target.o (0 = match).
The best variant is written back to base.c for `make permute` to continue
from. --rtl adds forensics: GCC 2.6 RTL dump pass list + asm-differ rows
(target vs best candidate).

Usage:
  python3 tools/scripts/variant_loop.py FUNC [--setup] [--rtl] [--max N]
"""
from __future__ import annotations

import argparse
import multiprocessing
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib

ROOT = lib.ROOT
SCRATCH = lib.SCRATCH
PY = lib.VENV_PY
PERMUTE = lib.PERMUTE

WIDTHS = ("s32", "u32", "s16", "u16", "s8", "u8", "int")
DECL_RE = re.compile(r"\b(s32|u32|s16|u16|s8|u8|int|char|short|long)\s+(\w+)\b")


def run(cmd, **kw) -> subprocess.CompletedProcess:
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def compile_variant(scratch: Path, name: str, ctext: str) -> Path | None:
    """compile input.c -> output.o; returns the .o path or None."""
    vdir = scratch / "variants"
    vdir.mkdir(exist_ok=True)
    src = vdir / f"{name}.c"
    src.write_text(ctext)
    out = scratch / "variants" / f"{name}.o"
    if not lib.compile(src, out):
        return None
    return out


def score_o(scratch: Path, obj: Path, target_bin: Path) -> tuple[int, int] | None:
    """(#differing bytes, size) vs target.bin, or None if sizes differ."""
    binp = obj.with_suffix(".bin")
    r = run([str(lib.OBJCOPY),
             "-O", "binary", "--only-section=.text", str(obj), str(binp)])
    if r.returncode != 0 or not binp.exists():
        return None
    tb = target_bin.read_bytes()
    vb = binp.read_bytes()
    if len(tb) != len(vb):
        return (10_000 + abs(len(tb) - len(vb)), len(vb))
    n = sum(1 for a, b in zip(tb, vb) if a != b)
    return (n, len(vb))


def statement_rotations(body: str) -> list[str]:
    """Adjacent top-level statement swaps of a function body."""
    stmts, cur, depth, start = [], "", 0, 0
    for i, ch in enumerate(body):
        cur += ch
        if ch in "{([":
            depth += 1
        elif ch in "})]":
            depth -= 1
        elif ch == ";" and depth == 0:
            stmts.append((start, i + 1))
            cur, start = "", i + 1
    if cur.strip():
        stmts.append((start, len(body)))
    if len(stmts) < 2:
        return []
    out = []
    for i in range(len(stmts) - 1):
        a, b = stmts[i], stmts[i + 1]
        v = body[:a[0]] + body[b[0]:b[1]] + body[a[1]:b[0]] + body[a[0]:a[1]] \
            + body[b[1]:]
        if v != body:
            out.append(v)
    return out[:40]


def width_variants(body: str) -> list[str]:
    """One variant per declared variable with a different integer width."""
    out = []
    seen = set()
    for m in DECL_RE.finditer(body):
        name = m.group(2)
        if name in seen:
            continue
        seen.add(name)
        for w in WIDTHS:
            if w == m.group(1):
                continue
            v = body[:m.start(1)] + w + body[m.end(1):]
            if v != body and v not in out:
                out.append(v)
        if len(out) >= 40:
            break
    return out[:40]


PIN_REGS = ("s0", "s1", "s2", "a1", "a0", "v0", "v1")


def pin_variants(body: str) -> list[str]:
    """One variant per plain local decl pinned to one exact register.

    Codifies docs/PERM_TRICKS.md §1 (register-asm pin): GCC 2.6's allocator
    insists on saved regs for call-crossing values; a
    ``register T name asm("reg")`` local overrides the home. Only plain
    (unpinned, non-extern, non-typedef) locals are touched; one variant per
    (decl, reg), capped like the other generators.
    """
    out = []
    for m in DECL_RE.finditer(body):
        line_start = body.rfind("\n", 0, m.start()) + 1
        line_end = body.find(";", m.end())
        if line_end == -1:
            continue
        line = body[line_start:line_end]
        if "register" in line or "extern" in line or "typedef" in line:
            continue
        after = body[m.end():m.end() + 8].lstrip()
        if after.startswith("[") or after.startswith("("):
            continue  # array or function declarator: cannot pin
        if "*" in line and "asm(" in body[max(0, m.start() - 40):m.start()]:
            continue
        for r in PIN_REGS:
            v = (body[:m.start()] + "register " + m.group(1) + " "
                 + m.group(2) + ' asm("' + r + '")'
                 + body[m.end():])
            if v != body and v not in out:
                out.append(v)
        if len(out) >= 40:
            break
    return out[:40]


def volatile_variants(body: str) -> list[str]:
    """One variant per pointer decl made volatile + per store-site cast.

    Codifies docs/PERM_TRICKS.md §3 (volatile destination pointer, blocks
    delay-slot fill) and §6 (base-register cast idiom): for each ``T *p``
    local, a ``volatile T *p`` variant. Pointer-typed DECL_RE hits carry the
    ``*`` on the declarator, so match them separately here.
    """
    out = []
    for m in re.finditer(r"\b(s32|u32|s16|u16|s8|u8|int|char|short|long)\s+(\*\s*\w+)",
                         body):
        line_start = body.rfind("\n", 0, m.start()) + 1
        line = body[line_start:body.find(";", m.end())]
        if "volatile" in line or "register" in line or "extern" in line:
            continue
        v = body[:m.start()] + "volatile " + m.group(1) + " " + m.group(2) \
            + body[m.end():]
        if v != body and v not in out:
            out.append(v)
        if len(out) >= 40:
            break
    return out[:40]


def gen_variants(scratch: Path, base: str) -> dict[str, str]:
    """{variant name: C source}."""
    m = re.search(r"\{.*\}", base, re.S)
    if not m:
        return {}
    variants = {}
    for i, v in enumerate(statement_rotations(m.group(0))):
        variants[f"rot{i}"] = base[:m.start()] + v + base[m.end():]
    for i, v in enumerate(width_variants(m.group(0))):
        variants[f"width{i}"] = base[:m.start()] + v + base[m.end():]
    for i, v in enumerate(pin_variants(m.group(0))):
        variants[f"pin{i}"] = base[:m.start()] + v + base[m.end():]
    for i, v in enumerate(volatile_variants(m.group(0))):
        variants[f"vol{i}"] = base[:m.start()] + v + base[m.end():]
    vdir = scratch / "variants"
    if vdir.is_dir():
        for f in sorted(vdir.glob("*.c")):
            variants.setdefault(f.stem, f.read_text())
    return variants


def make_target(scratch: Path) -> Path:
    """target.bin: .text bytes of target.o (single call, cached)."""
    binp = scratch / "target.bin"
    if not binp.exists():
        run([str(lib.OBJCOPY),
             "-O", "binary", "--only-section=.text",
             str(scratch / "target.o"), str(binp)])
    return binp


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("func")
    ap.add_argument("--setup", action="store_true",
                    help="only create the scratch dir (permute.py setup --no-run)")
    ap.add_argument("--rtl", action="store_true",
                    help="after scoring, print RTL pass list + asm-differ rows")
    ap.add_argument("--max", type=int, default=400,
                    help="cap on total variants tried (default 400)")
    ap.add_argument("--blob", default="",
                    help="blob name, so the stub lookup is scoped to that blob's "
                         "nonmatchings root (BLOB=<b> rtl FUNC=<f> reaches the "
                         "recipe but not the script without this)")
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    args = ap.parse_args()

    scratch = SCRATCH / args.func
    if not (scratch / "target.o").exists() or not (scratch / "base.c").exists():
        print("setting up scratch dir...")
        setup = [str(PY), str(PERMUTE), "setup"]
        if args.blob:
            setup += ["--blob", args.blob]
        setup += [args.func, "--no-run"]
        r = run(setup)
        print(r.stdout or r.stderr)
        if r.returncode != 0:
            return 1
    if args.setup:
        return 0

    base = (scratch / "base.c").read_text()
    target_bin = make_target(scratch)
    variants = gen_variants(scratch, base)

    # baseline: the seed itself
    all_v = {"base": base}
    all_v.update(variants)
    items = list(all_v.items())[: args.max]
    print(f"{len(items)} variants ({len(variants)} generated + base)")

    best = None  # (score, name, obj)
    with multiprocessing.Pool(args.jobs) as pool:
        results = pool.starmap(
            _work, [(scratch, name, text) for name, text in items])
    results = [r for r in results if r]
    results.sort(key=lambda r: r[0])
    for score, size, name, obj in results[:5]:
        print(f"  {score:6d}  {size:4d}B  {name}")
    if results:
        score, size, name, obj = results[0]
        print(f"best: {name} ({score} differing bytes)")
        if score == 0:
            print("BYTE-IDENTICAL variant found!")
        if name != "base" and score < 10_000:
            (scratch / "base.c").write_text(all_v[name])
            print(f"wrote {name} back to base.c (score {score})")

    if args.rtl:
        _rtl_forensics(scratch, obj if results else None, args.func, score
                       if results else None)
    return 0


def _work(scratch, name, text):
    obj = compile_variant(scratch, name, text)
    if obj is None:
        return None
    s = score_o(scratch, obj, scratch / "target.bin")
    if s is None:
        return None
    return (s[0], s[1], name, obj)


def _rtl_forensics(scratch: Path, best_obj, func, score) -> None:
    """GCC 2.6 RTL dumps of base.c + asm-differ rows vs the target."""
    tmp = scratch / "rtl"
    tmp.mkdir(exist_ok=True)
    shutil.copy(scratch / "base.c", tmp / f"{func}.c")
    gcc = lib.GCC
    r = run(["bash", "-c",
             f"cd {tmp} && {gcc} -EL -mno-abicalls -mgp32 -fno-builtin "
             f"-fno-common -G0 -O2 -S -da {func}.c -o {func}.s"])
    dumps = sorted(tmp.glob(f"{func}.c.*"))
    print(f"\n== RTL dumps ({len(dumps)} passes): "
          + ", ".join(p.name.rsplit(".", 1)[-1] for p in dumps))
    for key in ("rtl", "cse", "flow", "loop", "jump", "sched", "dbr"):
        p = tmp / f"{func}.c.{key}"
        if p.exists():
            print(f"\n-- {key} ({p.stat().st_size} bytes) --")
            print(p.read_text()[:1200])
    if best_obj is not None:
        diff = ROOT / "tools" / "third_party" / "asm-differ" / "diff.py"
        r = run([str(PY), str(diff), "-o", "-f", str(best_obj), "-F",
                 str(scratch / "target.o"), func, "--format=plain",
                 "--no-pager", "--no-line-numbers"])
        print(f"\n== asm-differ rows (best variant vs target, score {score}) ==")
        print(r.stdout[:4000] or r.stderr[:1000])


if __name__ == "__main__":
    sys.exit(main())