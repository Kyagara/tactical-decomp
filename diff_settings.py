import os
import sys
from pathlib import Path

# asm-differ imports this file from the repo root (CWD). Make lib importable
# regardless of CWD, but fall back gracefully so `make diff` never breaks if
# lib.py is missing.
sys.path.insert(0, str(Path(__file__).resolve().parent / "tools" / "scripts"))
try:
    import lib
    ROOT = lib.ROOT
    _HAVE_LIB = True
except Exception:
    ROOT = Path(__file__).resolve().parent
    _HAVE_LIB = False

try:
    sys.path.insert(0, str(ROOT / "tools" / "scripts"))
    import target as _target_mod
except Exception:
    _target_mod = None


def _blob_target():
    blob = os.environ.get("BLOB")
    if blob and _target_mod is not None:
        try:
            return _target_mod.get_target(blob)
        except Exception:
            return None
    return None


def apply(config, args):
    t = _blob_target()
    if t is not None:
        baseimg = str(ROOT / t.oracle) if not t.oracle.is_absolute() else str(t.oracle)
        myimg = str(ROOT / t.out_bin)
        mapfile = str(ROOT / t.map)
    else:
        baseimg = str(ROOT / "rom" / "extracted" / "baserom" / "SCUS_942.21")
        myimg = str(ROOT / "build" / "SCUS_942.21.bin")
        mapfile = str(ROOT / "rom" / "extracted" / "baserom" / "SCUS_942.21.map")
    config["arch"] = "mipsel"
    config["baseimg"] = baseimg
    config["myimg"] = myimg
    config["mapfile"] = mapfile
    config["source_directories"] = ["."]
    config["makeflags"] = []
    config["objdump_executable"] = (
        str(lib.OBJDUMP) if _HAVE_LIB else "tools/toolchain/bin/mipsel-none-elf-objdump"
    )
    config["map_format"] = "gnu"
