#!/usr/bin/env python3
"""Complete the linker symbol table for the all-stubs baseline build.

splat writes referenced-but-undefined symbols to build/undefined_syms_auto.txt,
but it misses many data symbols that live in unsplit .data/.rodata regions. The
split stubs still reference them by name (`D_800329BC`, `func_88A5E0E0`, ...);
those names encode the VRAM address, so we can synthesise absolute definitions
for everything referenced but not defined by the split output.

Function symbols referenced only from decompiled C (e.g. a C wrapper calling
an address that never appears as a `j`/`jal` in the asm tree) never appear in
the asm tree, so they are taken from build/undefined_funcs_auto.txt, which
splat already excludes C-defined names from (a --defsym would clash with the
real definition).

Emits build/symbols.def, a GNU ld response-file fragment of `--defsym` flags
that the Makefile passes as `@build/symbols.def` to the linker.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib

ROOT = lib.ROOT
ASM_DIR = ROOT / "rom" / "extracted" / "asm"
SYMS_AUTO = ROOT / "build" / "undefined_syms_auto.txt"
FUNCS_AUTO = ROOT / "build" / "undefined_funcs_auto.txt"
OUT = ROOT / "build" / "symbols.def"
SYM_SEED_FILES = [ROOT / "config" / "symbol_addrs.txt"]
SRC_GLOB = "*.c"

# Symbol names that are already defined by the link environment.
BUILTIN = {"_gp"}

_DEF_RE = re.compile(
    r"^\s*\.?(?:glabel|dlabel|jlabel|alabel|ehlabel)\s+([A-Za-z_.$][\w.$]*)\b",
    re.MULTILINE,
)
_NONMATCH_RE = re.compile(
    r"^\s*nonmatching\s+([A-Za-z_.$][\w.$]*)\b",
    re.MULTILINE,
)
_LOCAL_RE = re.compile(r"^\s*\.L[\w.$]+\s*:", re.MULTILINE)

# Symbol reference patterns. The capture group is always the referenced symbol.
# Registers ($xx) never match because symbol names must start with a letter or
# underscore.
_REF_RES = [
    re.compile(r"%hi\(([A-Za-z_][\w.$]*)\)"),
    re.compile(r"%lo\(([A-Za-z_][\w.$]*)\)"),
    re.compile(r"%gp_rel\(([A-Za-z_][\w.$]*)\)"),
    re.compile(r"^\s*(?:j|jal|bal)\s+([A-Za-z_][\w.$]*)\b", re.MULTILINE),
    # BATTLE-style conditional tail-calls (`beqz $v0, func_80083B20`):
    # splat renders cross-function branch targets as func_ names, but the
    # branch mnemonics were never scanned, so no --defsym was synthesised.
    # Only affects targets that previously failed to link (green targets
    # have no undefined branch targets, so nothing new is synthesised).
    re.compile(
        r"^\s*(?:beqz|bnez|beq|bne|bgez|bgezal|bgtz|blez|bltz|bltzal)\s+"
        r"\$\w+\s*(?:,\s*\$\w+\s*)?,\s*([A-Za-z_][\w.$]*)\b",
        re.MULTILINE,
    ),
    re.compile(r"^\s*(?:la|li)\s+\$\w+\s*,\s*([A-Za-z_][\w.$]*)\b", re.MULTILINE),
    re.compile(
        r"^\s*(?:lw|sw|ld|sd|lhu|lh|lbu|lb|sh|sb)\s+\$\w+\s*,\s*"
        r"([A-Za-z_][\w.$]*)\s*\(",
        re.MULTILINE,
    ),
    re.compile(
        r"^\s*(?:addiu|addu|subu|or|and|sltiu)\s+\$\w+\s*,\s*\$\w+\s*,\s*"
        r"([A-Za-z_][\w.$]*)\b",
        re.MULTILINE,
    ),
    re.compile(r"^\s*\.word\s+([A-Za-z_][\w.$]*)\b", re.MULTILINE),
]

# symbol names whose address can be parsed straight out of the name
# (func_/D_/jtbl/... plus <blob>_800XXXXX: one rule, any prefix).
_ADDR_NAME = re.compile(
    r"^(?:func|D|jtbl|alabel|ehlabel|label|[a-z][a-z0-9]*)_([0-9A-Fa-f]{8})$")

# addr-encoded names appearing in a target's C units (definitions/externs).
# Covers blob vram too (801xxxx inline-asm jumps, e.g. `j func_801C1440`).
_C_REF_RE = re.compile(r"\b[a-z][a-z0-9]*_80[0-9A-Fa-f]{6}\b")
# Data globals (`D_801CA940`) referenced only from decompiled C, or from an
# inline-asm `%hi(D_xxx)` string.  `_C_REF_RE` needs a LOWERCASE prefix, so the
# splat-style `D_` names it never matched; once the last split stub that
# referenced them is unlinked, the scan below sees nothing and the blob link
# fails with "undefined reference to `D_801CA940'".  Referenced-only: these are
# never defined in a C unit (they live in unsplit .data/.bss regions).
_C_DATA_RE = re.compile(r"\bD_([0-9A-Fa-f]{8})\b")


def c_func_names(src_dirs=("src",), src_glob=SRC_GLOB,
                 exclude: set[str] | None = None) -> tuple[set[str], set[str]]:
    """(defined, referenced) addr-encoded names in the target's C units.

    The asm tree may reference a function only by address (e.g. a `j` target
    that splat renders as `.L80040A00`), so C-extern'd functions would never
    reach the auto lists and no defsym would be synthesised for them.  Scan
    the C units directly; definitions are excluded so a synthesized --defsym
    never clashes with the real definition.  `exclude` drops unit stems
    (belt and braces: blob units live under src/blobs/ anyway).
    """
    defined: set[str] = set()
    referenced: set[str] = set()
    files: list[Path] = []
    for d in src_dirs:
        files += sorted((ROOT / d).glob(src_glob))
    for f in files:
        if exclude and f.stem in exclude:
            continue
        text = re.sub(r"/\*.*?\*/", "", f.read_text(errors="replace"),
                      flags=re.S)
        for ln in text.splitlines():
            ln = re.sub(r"/\*.*?\*/", "", ln).rstrip()
            if re.search(r"INCLUDE_(?:ASM|PSYQ)\s*\(", ln):
                continue  # covered by the asm tree
            referenced.update(_C_REF_RE.findall(ln))
            referenced.update("D_" + h for h in _C_DATA_RE.findall(ln))
            m = re.match(
                r"^(?:[A-Za-z_][\w ]*?\s+)?([a-z][a-z0-9]*_800[0-9A-Fa-f]{5})\s*\(",
                ln)
            if m and not ln.endswith(";") and not ln.lstrip().startswith("extern"):
                defined.add(m.group(1))
    return defined, referenced


def _iter_asm_files(asm_dir: Path | list[Path] | None,
                     default: Path):
    """Yield stub .s files: a dir is scanned recursively, a file is used
    directly. Lets family targets (EVENT/EFFECT: one asm tree per family)
    scope scans to the current blob's own stubs + data instead of the
    whole shared tree."""
    if asm_dir is None:
        asm_dir = default
    dirs = [asm_dir] if isinstance(asm_dir, Path) else list(asm_dir)
    for d in dirs:
        if d.is_dir():
            yield from sorted(d.rglob("*.s"))
        elif d.is_file() and d.suffix == ".s":
            yield d


def defined_names(asm_dir: Path | list[Path] | None = None) -> set[str]:
    defined = set(BUILTIN)
    for s in _iter_asm_files(asm_dir, ASM_DIR):
        text = s.read_text(errors="replace")
        for m in _DEF_RE.finditer(text):
            defined.add(m.group(1))
        for m in _NONMATCH_RE.finditer(text):
            defined.add(m.group(1))
        for ln in text.splitlines():
            if _LOCAL_RE.match(ln):
                defined.add(ln.split(":")[0].strip())
    return defined


def referenced_names(asm_dir: Path | list[Path] | None = None) -> set[str]:
    refs: set[str] = set()
    for s in _iter_asm_files(asm_dir, ASM_DIR):
        text = s.read_text(errors="replace")
        for ln in text.splitlines():
            if ln.lstrip().startswith("*") or ln.lstrip().startswith("//"):
                continue
            # strip the spimdisasm `/* <romoff> <vram> <bytes> */` prefix so
            # the mnemonic-anchored patterns can match
            if "*/" in ln:
                ln = ln.split("*/", 1)[1]
            for pat in _REF_RES:
                for m in pat.finditer(ln):
                    refs.add(m.group(1))
    return refs


def main() -> int:
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("--blob", default=None,
                    help="blob target (paths from tools/scripts/target.py)")
    args = ap.parse_args()

    asm_dir = ASM_DIR
    syms_auto = SYMS_AUTO
    funcs_auto = FUNCS_AUTO
    out = OUT
    seed_files = list(SYM_SEED_FILES)
    src_dirs = ("src",)
    src_glob = SRC_GLOB
    if args.blob:
        sys.path.insert(0, str(Path(__file__).resolve().parent))
        from target import get_target, d_units_of_yaml
        t = get_target(args.blob)
        asm_dir = t.asm_root
        # Scope scans to this blob's own stubs + data segments. Family
        # targets share one asm tree (EVENT/EFFECT), so a family-wide
        # `defined` scan would suppress --defsym synthesis for names
        # another blob's data labels (e.g. REQUIRE's jal to BUNIT-data
        # func_8008CE20), breaking this blob's link. `refs` stay scoped
        # too: the current link only needs its own references, and the
        # C-unit scan (below) is already blob-scoped.
        units = t.src_units or [args.blob]
        scope: Path | list[Path] = [t.asm_nm / u for u in units]
        scope += [t.asm_root / "data" / f"{s}.data.s"
                  for s in d_units_of_yaml(t.yaml)]
        syms_auto = t.undefined_syms
        funcs_auto = t.undefined_funcs
        out = t.symbols_def
        seed_files = list(t.sym_files)
        import os
        units = t.src_units or [args.blob]
        unitdir = os.path.relpath(t.unit_src(units[0]).parent, ROOT)
        src_dirs = (unitdir,)
        src_glob = f"{os.path.commonprefix(units)}*.c"

    defined = defined_names(scope if args.blob else asm_dir)
    refs = referenced_names(scope if args.blob else asm_dir)
    if args.blob:
        c_defined, c_refs = c_func_names(src_dirs, src_glob)
    else:
        try:
            sys.path.insert(0, str(Path(__file__).resolve().parent))
            from target import blob_unit_names
            _exclude = blob_unit_names()
        except ImportError:
            _exclude = set()
        c_defined, c_refs = c_func_names(src_dirs, src_glob, exclude=_exclude)

    # All C-defined names via src_func_addrs (name-derived vram), scoped to
    # the target so blob C defs never suppress exe --defsym synthesis
    # (and vice versa).
    try:
        sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "scripts"))
        import symbols as _sym  # noqa: E402

        _c_all = {info["c_name"]
                  for info in _sym.src_func_addrs(
                      target=args.blob).values()}
        c_defined |= _c_all
        defined |= _c_all
    except Exception:
        pass

    # start from splat's auto-detected undefined symbols (may include special
    # symbols whose names do not encode an address, e.g. D_31FFFF)
    extra: dict[str, str] = {}
    for auto_path in (syms_auto, funcs_auto):
        if not auto_path.exists():
            continue
        for ln in auto_path.read_text().splitlines():
            ln = ln.strip()
            if "=" in ln and ln.endswith(";"):
                name, _, val = ln.partition("=")
                name = name.strip()
                if name in defined:
                    continue  # split output actually defines it; drop the auto entry
                extra[name] = val.strip().rstrip(";")

    # Seed human-named symbols from the target's symbol files so .word
    # references to wiki-named C functions can be linked.
    try:
        _all_refs = refs | c_refs
        for _sym_path in seed_files:
            if not _sym_path.is_file():
                continue
            for ln in _sym_path.read_text().splitlines():
                m = re.match(r"(\w+)\s*=\s*0x([0-9A-Fa-f]+)", ln.strip())
                if m:
                    name, addr = m.group(1), m.group(2)
                    if name in _all_refs and name not in defined and name not in c_defined:
                        extra.setdefault(name, f"0x{addr}")
    except Exception:
        pass

    missing = sorted((refs | c_refs) - defined - c_defined)
    synth = 0
    for name in missing:
        m = _ADDR_NAME.match(name)
        if m:
            extra.setdefault(name, f"0x{m.group(1)}")
            synth += 1
        elif name not in extra:
            print(f"warning: referenced symbol with no address available: {name}",
                  file=sys.stderr)

    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open("w") as f:
        # NB: no comment lines -- this is passed to `ld @symbols.def`, and ld
        # response files treat every line as a command-line argument.
        for name in sorted(extra):
            f.write(f"--defsym {name}={extra[name]}\n")

    print(f"wrote {out} ({len(extra)} symbols; {synth} synthesised from stub refs)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
