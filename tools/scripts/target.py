#!/usr/bin/env python3
"""Blob/exe target resolver: the single place knowing the path convention.

For blob ``<blob>`` (BLOB_PLAN.md section 1)::

    config/blobs/<blob>.yaml            # splat config
    config/blobs/<blob>.symbols.txt     # blob-local symbols only
    src/blobs/<blob>/<unit>.c           # one C unit per code range
    rom/extracted/blobs/<blob>/...      # splat asm_path root
    build/blobs/<blob>/...              # ld, .split.stamp, symbols.def, .map, .bin, progress.json

``None`` (or ``"exe"``) selects the exe (``config/boot.yaml``).  Blob code
units are discovered from the yaml's ``c`` subsegments, so no per-blob
lists live in any script.  Blob symbol names take a ``<blob>_`` prefix
(``open_8006F278``); the ``_800XXXXX`` suffix parses with the same
name-to-vram rule as ``func_``/``D_``.

Deliberate asymmetry: a blob yaml includes ONLY its own symbols file.
The exe's ``config/symbol_addrs.txt`` carries ``D_8006xxxx`` entries that
describe the battle-phase use of the shared ``0x80060000`` arena RAM, but
``OPEN.BIN`` has compiled code at those file offsets (verified: jal
chains into the exe at ``0xC4A0``, frameless entry stubs at the loader
targets).  Including the exe file would plant data labels mid-function.
Cross-references into the exe (``func_8001xxxx``, ``D_8001xxxx``) resolve
through name-encoded ``--defsym`` synthesis in ``gen_undefined_syms.py``,
which needs no include.

Stdlib-only: imported by the Makefile (``oracle`` subcommand) and by every
``--blob`` script, so no third-party imports here.
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent

EXE_NAME = "exe"
EXE_SEGMENTS = ("main", "main_2", "main_3", "main_4", "main_5")
EXE_UNITS = ("main", "main_2", "main_3", "main_4", "main_5")

BLOBS_DIR = ROOT / "config" / "blobs"

# `- [0xSTART, c, NAME]` subsegment lines (the C unit / stub dir name).
_C_SUBSEG_RE = re.compile(r"-\s*\[\s*0x[0-9A-Fa-f]+\s*,\s*c\s*,\s*([A-Za-z_]\w*)")

# `- [0xSTART, data, NAME]` subsegment lines (data object names).
_DATA_SUBSEG_RE = re.compile(r"-\s*\[\s*0x[0-9A-Fa-f]+\s*,\s*data\s*,\s*([A-Za-z_]\w*)")


@dataclass
class Target:
    """Derived paths + unit lists for one build target (exe or blob)."""

    name: str | None  # None = exe, else the blob name
    yaml: Path
    build: Path
    asm_root: Path
    asm_nm: Path
    oracle: Path  # baserom file the build must reproduce
    out_bin: Path  # built raw binary compared against oracle
    out_elf: Path
    ld_script: Path
    map: Path
    symbols_def: Path
    undefined_syms: Path
    undefined_funcs: Path
    sym_files: list[Path] = field(default_factory=list)
    src_units: list[str] = field(default_factory=list)
    segments: list[str] = field(default_factory=list)
    aspsx_version: str | None = None  # maspsx --aspsx-version; None = default (2.34)
    family: str | None = None  # progress family (many configs, one README
    # row, e.g. EFFECT E###.BIN via `family: effect`); None = own row

    @property
    def label(self) -> str:
        return EXE_NAME if self.name is None else self.name

    @property
    def is_exe(self) -> bool:
        return self.name is None

    def unit_src(self, unit: str) -> Path:
        """C file carrying a unit's tokens/code: src/blobs/<blob>/<unit>.c
        for blobs (per-blob folders, mirroring other PSX decomps),
        src/<unit>.c for the exe. Blobs declaring `family:` share one
        family folder: src/blobs/<family>/<unit>.c."""
        if self.name is not None:
            base = self.family or self.name
            return ROOT / "src" / "blobs" / base / f"{unit}.c"
        return ROOT / "src" / f"{unit}.c"


def _yaml_str(path: Path, key: str) -> str | None:
    """Top-level `key: value` lookup without a yaml dependency."""
    try:
        text = path.read_text(errors="replace")
    except OSError:
        return None
    m = re.search(rf"^\s*{re.escape(key)}:\s*(\S.*?)\s*$", text, re.M)
    return m.group(1) if m else None


def _resolve(yaml: Path, value: str | None) -> Path | None:
    """Resolve a yaml path relative to base_path (splat semantics).

    Returns a clean repo-relative path when the target lives under ROOT
    (the common case), so Make recipes stay readable.
    """
    if value is None:
        return None
    p = Path(value)
    if p.is_absolute():
        return p
    base = _yaml_str(yaml, "base_path") or "."
    import os
    joined = os.path.normpath(yaml.parent / base / p)
    try:
        return Path(os.path.relpath(joined, ROOT))
    except ValueError:
        return Path(joined)


def c_units_of_yaml(yaml: Path) -> list[str]:
    """C unit (stub dir) names from the yaml's `c` subsegments, in order."""
    try:
        text = yaml.read_text(errors="replace")
    except OSError:
        return []
    seen: list[str] = []
    for m in _C_SUBSEG_RE.finditer(text):
        if m.group(1) not in seen:
            seen.append(m.group(1))
    return seen


def d_units_of_yaml(yaml: Path) -> list[str]:
    """Data object names from the yaml's `data` subsegments, in order
    (splat emits `<name>.data.s` per data subsegment)."""
    try:
        text = yaml.read_text(errors="replace")
    except OSError:
        return []
    seen: list[str] = []
    for m in _DATA_SUBSEG_RE.finditer(text):
        if m.group(1) not in seen:
            seen.append(m.group(1))
    return seen


def list_blobs() -> list[str]:
    """Blob names from config/blobs/*.yaml (no hardcoded list).

    Family folders (config/blobs/<family>/*.yaml, e.g. effect/) map to
    `<family>_<stem>` blob names, so BLOB= stays slash-free.
    """
    if not BLOBS_DIR.is_dir():
        return []
    names = sorted(p.stem for p in BLOBS_DIR.glob("*.yaml"))
    for sub in sorted(p for p in BLOBS_DIR.iterdir() if p.is_dir()):
        names += sorted(f"{sub.name}_{p.stem}"
                        for p in sub.glob("*.yaml"))
    return names


def yaml_of(name: str) -> Path:
    """Yaml path for a blob name: config/blobs/<name>.yaml, else the
    family-folder form config/blobs/<family>/<Stem>.yaml for blob
    `<family>_<Stem>`."""
    top = BLOBS_DIR / f"{name}.yaml"
    if top.is_file():
        return top
    if "_" in name:
        sub, stem = name.split("_", 1)
        cand = BLOBS_DIR / sub / f"{stem}.yaml"
        if cand.is_file():
            return cand
    return top


def blob_unit_names() -> set[str]:
    """Every blob C-unit stem (used to scope exe scans away from blob units)."""
    out: set[str] = set()
    for blob in list_blobs():
        out.update(c_units_of_yaml(yaml_of(blob)))
    return out


def get_target(name: str | None = None) -> Target:
    """Return the Target for a blob name, None/"exe"/"" for the exe."""
    if name in (None, "", EXE_NAME):
        return Target(
            name=None,
            yaml=ROOT / "config" / "boot.yaml",
            build=ROOT / "build",
            asm_root=ROOT / "rom" / "extracted" / "asm",
            asm_nm=ROOT / "rom" / "extracted" / "asm" / "nonmatchings",
            oracle=ROOT / "rom" / "extracted" / "baserom" / "SCUS_942.21",
            out_bin=ROOT / "build" / "SCUS_942.21.bin",
            out_elf=ROOT / "build" / "SCUS_942.21.exe",
            ld_script=ROOT / "build" / "SCUS_942.21.ld",
            map=ROOT / "rom" / "extracted" / "baserom" / "SCUS_942.21.map",
            symbols_def=ROOT / "build" / "symbols.def",
            undefined_syms=ROOT / "build" / "undefined_syms_auto.txt",
            undefined_funcs=ROOT / "build" / "undefined_funcs_auto.txt",
            sym_files=[ROOT / "config" / "symbol_addrs.txt"],
            src_units=list(c_units_of_yaml(ROOT / "config" / "boot.yaml")
                           or list(EXE_UNITS)),
            segments=list(EXE_SEGMENTS),
        )
    yaml = yaml_of(name)
    build = ROOT / "build" / "blobs" / name
    raw_fam = _yaml_str(yaml, "family")
    family = raw_fam.strip().strip("\"'") if raw_fam else None
    asm_root = ROOT / "rom" / "extracted" / "blobs" / (family or name)
    oracle = _resolve(yaml, _yaml_str(yaml, "target_path")) or Path()
    units = c_units_of_yaml(yaml)
    raw_ver = _yaml_str(yaml, "aspsx_version")
    aspsx = raw_ver.strip().strip("\"'") if raw_ver else None
    return Target(
        name=name,
        yaml=yaml,
        build=build,
        asm_root=asm_root,
        asm_nm=asm_root / "nonmatchings",
        oracle=oracle,
        out_bin=build / f"{name}.bin",
        out_elf=build / f"{name}.elf",
        ld_script=build / f"{name}.ld",
        map=build / f"{name}.map",
        symbols_def=build / "symbols.def",
        undefined_syms=build / "undefined_syms_auto.txt",
        undefined_funcs=build / "undefined_funcs_auto.txt",
        sym_files=[yaml.with_name(f"{yaml.stem}.symbols.txt")],
        src_units=units,
        segments=units,
        aspsx_version=aspsx or None,
        family=family,
    )


def main() -> int:
    ap = argparse.ArgumentParser(prog="target.py")
    ap.add_argument("field", nargs="?",
                    help="oracle|out|build|asm|config|map|units|srcs|aspsx|"
                         "family|usrcs|dsegs|symfile|list")
    ap.add_argument("blob", nargs="?", default=None)
    args = ap.parse_args()
    if args.field in (None, "list"):
        for b in list_blobs():
            print(b)
        return 0
    t = get_target(args.blob)
    if args.blob and not t.yaml.is_file():
        print(f"no such blob: {args.blob} ({t.yaml} missing)", file=sys.stderr)
        return 1
    import os
    rel = lambda p: os.path.relpath(p, ROOT)
    mapping = {
        "oracle": t.oracle,
        "out": t.out_bin,
        "elf": t.out_elf,
        "build": t.build,
        "asm": rel(t.asm_root),
        "config": t.yaml,
        "map": t.map,
        "ld": t.ld_script,
        "units": " ".join(t.src_units),
        "srcs": " ".join(f"src/{u}.c" for u in t.src_units),
        "aspsx": t.aspsx_version or "",
        "family": t.family or "",
        "usrcs": " ".join(rel(t.unit_src(u)) for u in t.src_units),
        "dsegs": " ".join(d_units_of_yaml(t.yaml)),
        "symfile": rel(t.sym_files[0]) if t.sym_files else "",
    }
    if args.field not in mapping:
        print(f"unknown field {args.field}", file=sys.stderr)
        return 1
    print(mapping[args.field])
    return 0


if __name__ == "__main__":
    sys.exit(main())
