#!/usr/bin/env python3
# tools/scripts/permute.py -- drive simonlindholm/decomp-permuter against one
# FFT stub: sets up a scratch dir under output/scratch/<func>/ and runs the
# permuter against the original bytes of that function.
#
# Subcommands:
#   setup [--blob NAME] <func> [--no-run] [--fg] [permuter args...]
#       build the scratch dir and (by default) launch the permuter in the
#       background (pid + permuter.log). --no-run = setup only (old --setup);
#       --fg = foreground launch (old --fg). Remaining args go to permuter.py.
#       --blob selects a blob target (stub root + aspsx vintage via
#       target.py); omit for the exe. The choice is recorded in blob.txt so
#       `diff` scores through the same pipeline without flags.
#   run <func> [--fg] [permuter args...]
#       launch the permuter against an existing scratch dir (foreground or bg).
#   diff <func> [--base | --candidate [NAME]]
#       positional instruction diff (merged posdiff.sh + verify_win.sh).
#       --base (default) compiles base.c; --candidate compiles output-NAME/
#       source.c, or auto-picks the best output-* dir when NAME is omitted.
#
# The permuter writes its best candidate back into base.c on exit;
# `make finish FUNC=<func>` is the real byte-match oracle (standalone codegen
# can differ from in-file codegen).

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib
try:
    import target as target_mod
except ImportError:
    target_mod = None

SCRATCH = lib.SCRATCH


def seed_fix(src, func):
    if re.search(r"(?<![A-Za-z0-9_])[?](?![A-Za-z0-9_])", src):
        src = re.sub(r"(?<![A-Za-z0-9_])[?](?![A-Za-z0-9_])", "int", src)
    if re.search(r"\b(s8|s16|s32|u8|u16|u32)\b", src) and "typedef unsigned" not in src:
        src = ("typedef unsigned char u8; typedef unsigned short u16; "
               "typedef unsigned int u32; typedef signed char s8; "
               "typedef signed short s16; typedef signed int s32;\n\n" + src)
    if re.search(r"\w+->\w+", src) and not re.search(r"typedef\s+struct", src):
        names = set(re.findall(r"\b(\w+)->(\w+)", src))
        fields = []
        for field in sorted(set(f for _, f in names)):
            off = re.fullmatch(r"unk([0-9A-Fa-f]+)", field)
            if off and int(off.group(1), 16) > 0:
                fields.append("char pad%s[0x%s]; void *%s;"
                              % (off.group(1), off.group(1), field))
            else:
                fields.append("void *%s;" % field)
        src = "typedef struct { %s } UnkType;\n\n" % " ".join(fields) + src
        src = re.sub(r"(^void %s\()void \*arg0" % re.escape(func),
                     r"\1UnkType *arg0", src, count=1, flags=re.M)
        for m in re.finditer(r"\bvoid \*(var_\w+);", src):
            name = m.group(1)
            if re.search(r"\b%s->" % re.escape(name), src):
                src = src.replace(m.group(0), "UnkType *%s;" % name)
        for m in re.finditer(r"extern void \*(\w+);", src):
            name = m.group(1)
            if re.search(r"\b%s->" % re.escape(name), src):
                src = src.replace(m.group(0), "extern UnkType *%s;" % name)
    if "NULL" in src and "#define NULL" not in src:
        src = "#define NULL 0\n" + src
    src = re.sub(r"^(\w+)\(([^)]*)\)\s*;", r"void \1(\2);", src, flags=re.M)
    return src


def build_scratch(func, blob=None):
    t = None
    aspsx = None
    nm = None
    if blob and target_mod is not None:
        t = target_mod.get_target(blob)
        nm = t.asm_nm
        aspsx = t.aspsx_version or None
    stub, seg, inner_line, inner = lib.find_stub(func, nm)
    d = SCRATCH / func
    d.mkdir(parents=True, exist_ok=True)
    (d / "blob.txt").write_text(blob or "")

    print("func=%s segment=%s stub=%s inner=%s scratch=%s"
          % (func, seg, stub, inner, d))

    base = d / "base.c"
    if base.exists():
        print("keeping existing base.c (hand-tuned seed)")
    else:
        r = subprocess.run([str(lib.VENV_PY), str(lib.M2C), "--context", str(lib.CTX),
                            "-f", inner, str(stub)],
                           stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
        out = re.sub(r"(?m)^[?] ", "", r.stdout)
        if not out.strip():
            print("m2c produced no output for %s -- check the stub layout" % inner,
                  file=sys.stderr)
            sys.exit(1)
        out = re.sub(r"\b%s\b\(" % re.escape(inner), "%s(" % func, out)
        out = seed_fix(out, func)
        base.write_text(out)
    print("base.c: %d lines" % len(base.read_text().splitlines()))

    lib.write_compile_sh(d, aspsx)

    stub_lines = stub.read_text().splitlines()
    body_lines = stub_lines[inner_line:]
    body_lines = [l for l in body_lines if not re.match(r"^[ \t]*glabel ", l)]
    body_lines = [re.sub(r"^endlabel .*", "endlabel %s" % func, l) for l in body_lines]
    prelude = (lib.PERMUTER / "prelude.inc").read_text()
    prelude = "\n".join(l for l in prelude.splitlines() if "gp=64" not in l)
    target_s = prelude + "\nglabel %s\n" % func + "\n".join(body_lines) + "\n"
    (d / "target.s").write_text(target_s)
    subprocess.run([str(lib.AS), "-EL", "-o", str(d / "target.o"), str(d / "target.s")],
                   check=True)
    print("target.o: %d bytes" % ((d / "target.o").stat().st_size))

    settings = ('func_name = "%s"\n'
                'compiler_type = "gcc"\n'
                'objdump_command = "%s -drz -m mips:4300"\n'
                '\n'
                '# Repo GCC-2.6 tuning (docs/PERMUTER_TAIL_PLAN.md Phase A):\n'
                '# kill IDO-only noise, boost reorder/split/alias passes.\n'
                '[weight_overrides]\n'
                'perm_inline = 0\n'
                'perm_float_literal = 0\n'
                'perm_empty_stmt = 0\n'
                'perm_condition = 0\n'
                'perm_add_mask = 0\n'
                'perm_xor_zero = 0\n'
                'perm_refer_to_var = 0\n'
                'perm_mult_zero = 0\n'
                'perm_add_self_assignment = 0\n'
                'perm_duplicate_assignment = 0\n'
                'perm_dummy_comma_expr = 0\n'
                'perm_pad_var_decl = 0\n'
                'perm_sameline = 0\n'
                'perm_reorder_stmts = 30\n'
                'perm_reorder_decls = 20\n'
                'perm_split_assignment = 20\n'
                'perm_alias_array = 10\n'
                % (func, lib.OBJDUMP))
    (d / "settings.toml").write_text(settings)

    if not lib.compile(base, d / "base.o", aspsx):
        print("base.c does not compile through the pipeline -- fix base.c by hand",
              file=sys.stderr)
        sys.exit(1)
    (d / "base.o").unlink(missing_ok=True)
    return d


def extract_own_flags(argv):
    own = {"--no-run": False, "--fg": False}
    rest = []
    for a in argv:
        if a in own:
            own[a] = True
        else:
            rest.append(a)
    return own, rest


def launch_permuter(d, fg, extra):
    cmd = [str(lib.VENV_PY), str(lib.PERMUTER / "permuter.py"), str(d),
           "-j", str(os.cpu_count() or 1)] + extra
    if fg:
        subprocess.run(cmd)
    else:
        log = d / "permuter.log"
        with open(log, "w") as f:
            proc = subprocess.Popen(cmd, stdout=f, stderr=subprocess.STDOUT)
        print("permuter running: pid %d  log %s" % (proc.pid, log))


def _scratch_aspsx(d, blob=None):
    """Resolve the maspsx version for a scratch dir.

    Explicit ``--blob`` wins; otherwise fall back to the ``blob.txt`` record
    written at setup time (so ``diff`` works without flags). None = exe.
    """
    name = blob
    if not name:
        bf = d / "blob.txt"
        if bf.is_file():
            name = bf.read_text().strip() or None
    if name and target_mod is not None:
        return target_mod.get_target(name).aspsx_version or None
    return None


def cmd_setup(args):
    own, rest = extract_own_flags(args.rest)
    d = build_scratch(args.func, getattr(args, "blob", None))
    if own["--no-run"]:
        print("setup complete: %s" % d)
        return
    launch_permuter(d, own["--fg"], rest)


def cmd_run(args):
    own, rest = extract_own_flags(args.rest)
    d = SCRATCH / args.func
    if not d.exists():
        print("no scratch dir %s (run: permute.py setup %s --no-run)" % (d, args.func),
              file=sys.stderr)
        sys.exit(1)
    launch_permuter(d, own["--fg"], rest)


def cmd_diff(args):
    d = SCRATCH / args.func
    if not d.exists():
        print("no scratch dir %s (run: permute.py setup %s --no-run)" % (d, args.func),
              file=sys.stderr)
        sys.exit(1)
    if args.candidate is not None:
        if args.candidate == "__AUTO__":
            outs = sorted(p.name for p in d.glob("output-*"))
            if not outs:
                print("no output-* dirs in %s" % d, file=sys.stderr)
                sys.exit(1)
            name = outs[0]
        else:
            name = args.candidate
        src = d / name / "source.c"
        label = name
    else:
        src = d / "base.c"
        label = "base.c"
    if not src.exists():
        print("no %s" % src, file=sys.stderr)
        sys.exit(1)
    compiled = d / ("%s.tmp.o" % src.stem)
    aspsx = _scratch_aspsx(d, getattr(args, "blob", None))
    if not lib.compile(src, compiled, aspsx):
        print("%s does not compile through the pipeline" % label, file=sys.stderr)
        sys.exit(1)
    T = lib.objdump_disasm(d / "target.o")
    B = lib.objdump_disasm(compiled)
    print("candidate: %s  T=%d  B=%d" % (label, len(T), len(B)))
    for i, (t, b) in enumerate(zip(T, B)):
        t2 = t.replace("\t", " ")
        b2 = b.replace("\t", " ")
        if t2 != b2:
            print("%2d  T: %-30s | B: %s" % (i + 1, t2, b2))
    compiled.unlink(missing_ok=True)


def main():
    parser = argparse.ArgumentParser(prog="permute.py")
    sub = parser.add_subparsers(dest="cmd", required=True)

    p_setup = sub.add_parser("setup")
    p_setup.add_argument("func")
    p_setup.add_argument("--blob", default=None, help="blob target")
    p_setup.add_argument("rest", nargs=argparse.REMAINDER)
    p_setup.set_defaults(func_cmd=cmd_setup)

    p_run = sub.add_parser("run")
    p_run.add_argument("func")
    p_run.add_argument("rest", nargs=argparse.REMAINDER)
    p_run.set_defaults(func_cmd=cmd_run)

    p_diff = sub.add_parser("diff")
    p_diff.add_argument("func")
    p_diff.add_argument("--blob", default=None, help="blob target")
    p_diff.add_argument("--base", action="store_true")
    p_diff.add_argument("--candidate", nargs="?", const="__AUTO__")
    p_diff.set_defaults(func_cmd=cmd_diff)

    args = parser.parse_args()
    args.func_cmd(args)


if __name__ == "__main__":
    main()
