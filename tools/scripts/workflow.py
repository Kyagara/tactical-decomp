#!/usr/bin/env python3
# tools/scripts/workflow.py -- decompile/finish workflow for one FFT stub.
#
# Replaces the former decompile.sh and finish.sh shell scripts with one Python
# CLI (importing lib + symbols for shared paths/stub logic):
#
#   decompile <func>   read-only m2c decompilation + next-step checklist.
#                      No stub removal, no build. Prints warnings for stubs that
#                      are likely unmatchable (merged bodies) or carry embedded
#                      .rodata.
#   finish <func>      remove the stub, clean build, and verify a byte match.
#                      Exits 0 only when the exe is byte-identical AND
#                      asm-differ reports score 0. Every failure point prints an
#                      actionable diagnostic; nothing is deleted until the
#                      pre-flight checks (stub exists, C definition present)
#                      pass.

from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
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
NM = lib.ASM_NM
SRC = ROOT / "src"
VENV_PY = lib.VENV_PY
M2C = lib.M2C
CTX = lib.CTX
TARGET = lib.BASE_ROM
OUT_BIN = lib.OUT_BIN
PICK = Path(__file__).resolve().parent / "pick_function.py"
PROGRESS = Path(__file__).resolve().parent / "progress.py"
DIFF = ROOT / "tools" / "third_party" / "asm-differ" / "diff.py"


def _target(args):
    blob = getattr(args, "blob", None)
    if blob and target_mod is not None:
        return target_mod.get_target(blob)
    return None


def _has_c_definition(func, target=None):
    pat = re.compile(r"\b%s\s*\([^;]*\)\s*\{" % re.escape(func))
    if target is not None:
        files = [target.unit_src(u) for u in target.src_units]
    elif target_mod is not None:
        t = target_mod.get_target(None)
        files = [t.unit_src(u) for u in t.src_units]
    else:
        files = SRC.glob("*.c")
    for c in files:
        if not c.is_file():
            continue
        if pat.search(c.read_text(errors="replace")):
            return True
    return False


def cmd_decompile(args):
    func = args.func
    t = _target(args)
    stub, seg, _, _ = lib.find_stub(func, t.asm_nm if t is not None else None)
    text = stub.read_text(errors="replace")

    # m2c -f label: prefer the func_ glabel, else the first other glabel.
    if re.search(r"glabel %s\b" % re.escape(func), text):
        label = func
    else:
        m = re.search(r"glabel ([A-Za-z_]\w*)", text)
        if not m:
            print("error: no glabel found in %s -- cannot run m2c" % stub,
                  file=sys.stderr)
            sys.exit(1)
        label = m.group(1)
        print("note: stub is PSYQ-relabelled -- using inner glabel '%s' as "
              "m2c target" % label, file=sys.stderr)

    # health warnings (nothing blocks the m2c run)
    flags = symbols.stub_health(stub)
    instrs = symbols.stub_scan(target=t).get(stub.stem, {}).get("instrs", "?")
    if flags:
        print("warning: %s is not cleanly decompilable: %s"
              % (func, " ".join(sorted(flags))), file=sys.stderr)
        print("warning: merged stubs are unmatchable and rodata/PSYQ need "
              "special handling -- see AGENTS.md", file=sys.stderr)

    cmd = [str(VENV_PY), str(M2C), "-f", label]
    if CTX.is_file():
        cmd += ["--context", str(CTX)]
    else:
        print("warning: build/ctx.c missing -- run 'make context' for "
              "type-aware output; continuing without it", file=sys.stderr)
    cmd.append(str(stub))

    print("=== %s [%s] -- %s instructions in %s ===" % (func, seg, instrs, stub))
    print()
    subprocess.run(cmd)
    print()
    print("=== next steps ===")
    cfile = t.unit_src(seg) if t is not None else SRC / ("%s.c" % seg)
    print("1. Place the C into %s, replacing this line:"
          % cfile.relative_to(ROOT))
    folder = (str((t.asm_nm / seg).relative_to(ROOT)) if t is not None
              else "rom/extracted/asm/nonmatchings/%s" % seg)
    rg = subprocess.run(
        ["rg", "-n",
         r'INCLUDE_(?:ASM|PSYQ)\("%s", %s\)' % (folder, func),
         str(cfile)],
        capture_output=True, text=True)
    if rg.stdout.strip():
        for line in rg.stdout.strip().splitlines():
            print("     " + line)
    print("2. Verify a byte match:  %smake finish FUNC=%s"
          % (("BLOB=%s " % t.name) if t is not None else "", func))


def cmd_finish(args):
    func = args.func
    t = _target(args)
    blob = getattr(args, "blob", None)
    oracle = (ROOT / t.oracle) if t is not None else TARGET
    out_bin = (ROOT / t.out_bin) if t is not None else OUT_BIN
    make_blob = ["BLOB=%s" % blob] if blob else []
    stub, seg, _, _ = lib.find_stub(func, t.asm_nm if t is not None else None)

    if not _has_c_definition(func, t):
        print("error: no C definition '%s(...)' found in src/ -- decompile "
              "first with:  make decompile %s  (stub left in place)"
              % (func, func), file=sys.stderr)
        sys.exit(1)

    if re.search(r"\.section \.rodata|dlabel D_", stub.read_text(errors="replace")):
        print("warning: stub carries embedded .rodata -- keep the "
              "INCLUDE_RODATA(D_...) line in src/%s.c or the .rodata shrinks "
              "by 4 bytes" % seg, file=sys.stderr)

    print("==> removing stub: %s" % stub)
    pick_cmd = [str(VENV_PY), str(PICK), "--done", func]
    if blob:
        pick_cmd += ["--blob", blob]
    r = subprocess.run(pick_cmd, capture_output=True, text=True)
    if r.stdout.strip():
        print(r.stdout.strip())
    if stub.exists():
        print("error: pick_function.py failed to remove %s" % stub,
              file=sys.stderr)
        sys.exit(1)

    print("==> clean build (slow step, ~30s)")
    subprocess.run(["make"] + make_blob + ["clean"], cwd=ROOT,
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    build = subprocess.run(["make"] + make_blob + ["build"], cwd=ROOT,
                           capture_output=True, text=True)
    if build.returncode != 0:
        print("BUILD FAILED. Last 30 lines:", file=sys.stderr)
        tail = (build.stderr or build.stdout).splitlines()[-30:]
        print("\n".join(tail), file=sys.stderr)
        print("fix the C in %s and re-run:  %smake finish %s  (to bail "
              "out: revert the C edit and 'make split' re-emits the stub)"
              % ((t.unit_src(seg).relative_to(ROOT) if t is not None
                  else "src/%s.c" % seg),
                 ("BLOB=%s " % blob if blob else ""), func), file=sys.stderr)
        sys.exit(1)

    print("==> byte-compare vs original")
    if subprocess.run(["cmp", "-s", str(oracle), str(out_bin)]).returncode != 0:
        print("MISMATCH: built %s differs from the original:"
              % ("blob %s" % blob if blob else "exe"), file=sys.stderr)
        d = subprocess.run(["cmp", str(oracle), str(out_bin)],
                           capture_output=True, text=True)
        if d.stdout:
            print("  " + d.stdout.splitlines()[0])
        print("  likely causes: wrong instruction count, lost jr ra "
              "delay-slot fill,", file=sys.stderr)
        print("  or missing embedded .rodata (see AGENTS.md '4-byte shift "
              "cascade').", file=sys.stderr)
        print("  inspect with:  make diff FUNC=%s" % func, file=sys.stderr)
        sys.exit(1)
    print("  byte-identical")

    print("==> asm-differ verdict")
    env = dict(os.environ)
    env["PYTHONDONTWRITEBYTECODE"] = "1"
    if blob:
        env["BLOB"] = blob
    j = subprocess.run([str(VENV_PY), str(DIFF), func, "--format", "json"],
                       cwd=ROOT, capture_output=True, text=True, env=env)
    if j.returncode != 0:
        print("asm-differ failed for %s -- run 'make diff FUNC=%s' to see why"
              % (func, func), file=sys.stderr)
        sys.exit(1)

    try:
        data = json.loads(j.stdout)
        rows = data["rows"]
    except Exception:
        print("  asm-differ produced no usable verdict.", file=sys.stderr)
        sys.exit(1)

    def txt(cell):
        if not cell:
            return ""
        return re.sub(r"\s+", " ",
                      "".join(s.get("text", "") for s in cell.get("text", []))
                      ).strip()

    bad = [(txt(r.get("base")), txt(r.get("current")))
           for r in rows if txt(r.get("base")) != txt(r.get("current"))]
    score = data["current_score"]

    if score == 0 and not bad:
        print("  MATCHED: %s -- asm-differ score 0/%s"
              % (func, data.get("max_score")))
        score_ok = 0
    else:
        print("  NOT MATCHED: %s -- score %s/%s, %d differing rows"
              % (func, score, data.get("max_score"), len(bad)))
        for b, c in bad[:10]:
            print("    base    | %s" % b)
            print("    current | %s" % c)
        score_ok = 1

    subprocess.run([str(VENV_PY), str(PROGRESS)], cwd=ROOT,
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    if score_ok == 0:
        print("==> DONE: %s matched." % func)
    else:
        print("==> NOT DONE: %s still mismatches (rows above). Re-edit "
              "%s and re-run:  %smake finish %s"
              % (func,
                 (t.unit_src(seg).relative_to(ROOT) if t is not None
                  else "src/%s.c" % seg),
                 ("BLOB=%s " % blob if blob else ""), func))
    sys.exit(score_ok)


def main():
    ap = argparse.ArgumentParser(prog="workflow.py")
    sub = ap.add_subparsers(dest="cmd", required=True)

    p_dec = sub.add_parser("decompile", help="m2c decompile a stub (read-only)")
    p_dec.add_argument("func")
    p_dec.add_argument("--blob", default=None, help="blob target")
    p_dec.set_defaults(func_cmd=cmd_decompile)

    p_fin = sub.add_parser("finish", help="remove stub, build, verify match")
    p_fin.add_argument("func")
    p_fin.add_argument("--blob", default=None, help="blob target")
    p_fin.set_defaults(func_cmd=cmd_finish)

    args = ap.parse_args()
    args.func_cmd(args)


if __name__ == "__main__":
    main()
