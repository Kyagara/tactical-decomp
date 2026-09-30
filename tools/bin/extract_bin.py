#!/usr/bin/env python3
"""Extract files from a raw MODE2/2352 PSX bin/cue into rom/extracted/baserom/,
and emit a sector->file data map used later when reassembling the bin.

PSX discs are CD-ROM XA: each raw 2352-byte sector contains a 12-byte sync,
a 4-byte header, and an 8-byte subheader before the 2048-byte user data block.
We rebuild a clean ISO9660 image from the user-data stream and parse it with
pycdlib, which robustly handles XA directory record spanning.

The input bin/cue are verified against config/disc_checksums.txt before
anything is written; a wrong disc aborts extraction.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import sys
from dataclasses import dataclass
from pathlib import Path

import pycdlib

RAW_SECTOR = 2352
USER_SECTOR = 2048
DATA_OFFSET = 24  # sync(12) + header(4) + subheader(8)

ROOT = Path(__file__).resolve().parent.parent.parent
DEFAULT_CHECKSUMS = ROOT / "config" / "disc_checksums.txt"


@dataclass
class Track:
    start: int
    mode: int
    bin_path: str


def parse_cue(cue: Path) -> list[Track]:
    tracks: list[Track] = []
    bin_path: str | None = None
    cur_start: int | None = None
    cur_mode: int = 0
    for raw in cue.read_text(errors="replace").splitlines():
        parts = raw.split()
        if not parts:
            continue
        if parts[0].upper() == "FILE":
            bin_path = raw.split('"')[1] if '"' in raw else parts[1]
        elif parts[0].upper() == "TRACK":
            mode_tok = parts[3] if len(parts) > 3 and "/" in parts[3] else parts[2]
            cur_mode = int(mode_tok.split("/")[1] if "/" in mode_tok else mode_tok[4:])
        elif parts[0].upper() == "INDEX":
            mm, ss, ff = (int(x) for x in parts[2].split(":"))
            cur_start = mm * 60 * 75 + ss * 75 + ff
            if bin_path and cur_start is not None:
                tracks.append(Track(cur_start, cur_mode, bin_path))
    return tracks


def read_user_data(bin_path: str, sector: int) -> bytes:
    with open(bin_path, "rb") as fh:
        fh.seek(sector * RAW_SECTOR)
        raw = fh.read(RAW_SECTOR)
    if len(raw) < RAW_SECTOR:
        return b""
    mode = raw[15]
    if mode in (0, 1):
        return raw[16:16 + USER_SECTOR]
    return raw[DATA_OFFSET:DATA_OFFSET + USER_SECTOR]


def build_iso_image(track: Track, out: Path) -> int:
    """Write the user-data stream of the data track to out as a plain 2048-byte
    ISO9660 image; returns the number of usable user sectors."""
    n = 0
    with open(out, "wb") as fh:
        sector = track.start
        while True:
            data = read_user_data(track.bin_path, sector)
            if not data:
                break
            fh.write(data)
            sector += 1
            n += 1
    return n


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


def verify_sha1(name: str, path: Path, expected: str | None) -> bool:
    """Hash `path` and compare against `expected` (lowercase hex).

    Returns True when verified or when there is no checksum entry (warning),
    False on mismatch (hard error, caller must abort)."""
    if expected is None:
        print(f"warning: no SHA1 entry for {name} in {DEFAULT_CHECKSUMS.name}; skipping", file=sys.stderr)
        return True
    actual = sha1_file(path)
    if actual == expected:
        print(f"SHA1 OK: {name} ({actual[:8]}...)")
        return True
    print(f"SHA1 MISMATCH: {name}", file=sys.stderr)
    print(f"  expected  {expected}", file=sys.stderr)
    print(f"  actual    {actual}", file=sys.stderr)
    return False


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--cue", type=Path, default=Path("rom/Final Fantasy Tactics (USA).cue"))
    ap.add_argument("--out", type=Path, default=Path("rom/extracted/baserom"))
    ap.add_argument("--map", type=Path, default=Path("rom/extracted/data_map.json"))
    ap.add_argument("--tmp-bin", type=Path, default=Path("/tmp/fft.bin"))
    ap.add_argument("--checksums", type=Path, default=DEFAULT_CHECKSUMS)
    args = ap.parse_args()

    tracks = parse_cue(args.cue)
    if not tracks:
        print("No data track found.", file=sys.stderr)
        return 1
    cue_dir = args.cue.parent
    for t in tracks:
        p = Path(t.bin_path)
        if not p.is_absolute():
            p = cue_dir / p
        t.bin_path = str(p.resolve())

    # verify the input disc against config/disc_checksums.txt BEFORE writing
    # anything: a wrong disc must never clobber rom/extracted/baserom/.
    checksums = load_checksums(args.checksums)
    for t in tracks:
        name = Path(t.bin_path).name
        if not verify_sha1(name, Path(t.bin_path), checksums.get(name)):
            return 1
    if not verify_sha1(args.cue.name, args.cue, checksums.get(args.cue.name)):
        return 1

    args.out.mkdir(parents=True, exist_ok=True)

    track = tracks[0]
    n = build_iso_image(track, args.tmp_bin)
    if n < 100:
        print(f"Reconstructed bin too small ({n} sectors).", file=sys.stderr)
        return 1
    print(f"Reconstructed bin from {n} user sectors.")

    iso = pycdlib.PyCdlib()
    try:
        iso.open(str(args.tmp_bin))

        records: list[dict] = []

        for cur, _dirs, files in iso.walk(iso_path="/"):
            for fn in files:
                nid = fn.encode("latin-1")
                if not nid:
                    continue
                full_path = (cur.rstrip("/") + "/" + fn).lstrip("/")
                rec = iso.get_record(iso_path="/" + full_path)
                size = rec.data_length
                user_off = rec.extent_location() if callable(rec.extent_location) else rec.extent_location
                first = read_user_data(track.bin_path, track.start + user_off)
                # Strip the ";1" ISO9660 version suffix for a clean name
                clean = re.sub(r";\d+$", "", full_path)
                records.append({
                    "name": "/" + clean,
                    "iso_path": "/" + full_path,
                    "size": size,
                    "lbn": track.start + user_off,
                    "psx_exe": first[:16] == b"PS-X EXE",
                })

        print(f"Found {len(records)} files across {len(tracks)} track(s).")

        sector_map = []
        for rec in sorted(records, key=lambda r: r["lbn"]):
            name = rec["name"]
            dest = args.out / name.lstrip("/")
            dest.parent.mkdir(parents=True, exist_ok=True)
            with open(dest, "wb") as fh:
                iso.get_file_from_iso_fp(fh, iso_path=rec["iso_path"])
            sector_map.append({
                "lbn": rec["lbn"],
                "sectors": (rec["size"] + USER_SECTOR - 1) // USER_SECTOR,
                "file": name,
                "size": rec["size"],
                "psx_exe": rec["psx_exe"],
            })

        args.map.parent.mkdir(parents=True, exist_ok=True)
        args.map.write_text(json.dumps({
            "user_sector_bytes": USER_SECTOR,
            "raw_sector_bytes": RAW_SECTOR,
            "tracks": [{"lbn": t.start, "mode": t.mode, "bin": t.bin_path} for t in tracks],
            "files": sector_map,
        }, indent=2))
        print(f"Extracted {len(records)} files -> {args.out}")
        print(f"Data map -> {args.map}")
        return 0
    finally:
        iso.close()
        args.tmp_bin.unlink(missing_ok=True)


if __name__ == "__main__":
    sys.exit(main())
