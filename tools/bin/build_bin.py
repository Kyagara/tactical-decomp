#!/usr/bin/env python3
"""Reassemble a bootable PSX disc bin from the extracted baserom, substituting
the rebuilt executable for the original /SCUS_942.21.

Strategy: copy the original raw MODE2/2352 image sector-for-sector, then patch
only the 2048 user-data bytes of the sectors belonging to the executable. All
other sectors (maps, sprites, music, BATTLE.BIN, audio) keep their original
sync/header/subheader/EDC/ECC bytes, so the result stays a valid disc image the
emulator can boot. Mirrors extract_bin.py's DATA_OFFSET (24) and config layout.

Since `make compare` guarantees the rebuilt executable is byte-identical to the
original, the output bin must be byte-identical to the retail disc -- verified
against config/disc_checksums.txt (hard fail, --no-verify to skip).
"""
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path

RAW_SECTOR = 2352
USER_SECTOR = 2048
DATA_OFFSET = 24

ROOT = Path(__file__).resolve().parent.parent.parent
DEFAULT_CHECKSUMS = ROOT / "config" / "disc_checksums.txt"


def load_checksums(path: Path) -> dict[str, str]:
    """filename -> sha1 from config/disc_checksums.txt (paths relative to rom/)."""
    out: dict[str, str] = {}
    if not path.is_file():
        return out
    for ln in path.read_text().splitlines():
        ln = ln.strip()
        if not ln or ln.startswith("#"):
            continue
        parts = ln.split(None, 1)
        if len(parts) == 2:
            out[parts[1].strip()] = parts[0].lower()
    return out


def sha1_file(path: Path) -> str:
    h = hashlib.sha1()
    with open(path, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--map", type=Path, default=Path("rom/extracted/data_map.json"))
    ap.add_argument("--exe", type=Path, default=Path("build/SCUS_942.21.bin"))
    ap.add_argument("--out", type=Path, default=Path("./build/fft.bin"))
    ap.add_argument("--cue", type=Path, default=Path("./build/fft.cue"))
    ap.add_argument("--checksums", type=Path, default=DEFAULT_CHECKSUMS)
    ap.add_argument("--no-verify", action="store_true",
                    help="skip the output-vs-retail SHA1 check")
    args = ap.parse_args()

    data = json.loads(args.map.read_text())
    files = data["files"]
    exe_rec = next(
        (f for f in files if f["file"].endswith("SCUS_942.21")),
        None,
    )
    if exe_rec is None:
        print(f"No /SCUS_942.21 record in {args.map}", file=sys.stderr)
        return 1

    src_bin = Path(data["tracks"][0]["bin"])
    if not src_bin.is_file():
        print(f"Original image not found: {src_bin}", file=sys.stderr)
        return 1

    exe = args.exe.read_bytes()
    want = exe_rec["size"]
    if len(exe) != want:
        print(
            f"Executable size mismatch: {args.exe} is {len(exe)} bytes, "
            f"record expects {want} (and disc covers {exe_rec['sectors']*USER_SECTOR}). "
            "Run a clean `make build` first.",
            file=sys.stderr,
        )
        return 1

    if len(exe) > exe_rec["sectors"] * USER_SECTOR:
        print("Executable larger than its recorded sector span.", file=sys.stderr)
        return 1

    lbn = exe_rec["lbn"]
    sectors = exe_rec["sectors"]

    # load the original image, patch the exe's user-data blocks, write once
    img = bytearray(src_bin.read_bytes())
    pos = lbn * RAW_SECTOR + DATA_OFFSET
    for off in range(0, len(exe), USER_SECTOR):
        img[pos:pos + USER_SECTOR] = exe[off:off + USER_SECTOR]
        pos += RAW_SECTOR
    if img[lbn * RAW_SECTOR + DATA_OFFSET:lbn * RAW_SECTOR + DATA_OFFSET + 8] != b"PS-X EXE":
        print("Patched exe missing PS-X EXE header.", file=sys.stderr)
        return 1

    args.out.write_bytes(img)
    args.cue.write_text(f'FILE "{args.out.name}" BINARY\n'
                        f"  TRACK 01 MODE2/2352\n"
                        f"    INDEX 01 00:00:00\n")
    print(f"Wrote {args.out} ({sectors} patched sectors) + {args.cue}")

    # The output must be byte-identical to the retail disc: only the exe's
    # user-data blocks were patched, and make compare forces those to match.
    if not args.no_verify:
        checksums = load_checksums(args.checksums)
        retail_name = Path(src_bin).name
        expected = checksums.get(retail_name)
        if expected is None:
            print(f"warning: no SHA1 entry for {retail_name} in {args.checksums}; skipping", file=sys.stderr)
            return 0
        actual = sha1_file(args.out)
        if actual == expected:
            print(f"SHA1 OK: {args.out.name} == retail bin ({actual[:8]}...)")
        else:
            print("SHA1 MISMATCH: output bin differs from the retail disc.", file=sys.stderr)
            print(f"  expected  {expected}", file=sys.stderr)
            print(f"  actual    {actual}", file=sys.stderr)
            print("  the rebuilt executable must be byte-identical -- run:  make compare", file=sys.stderr)
            print("  (or re-run with --no-verify to force)", file=sys.stderr)
            return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
