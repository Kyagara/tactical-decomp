#!/usr/bin/env bash
# Snapshot the current build's GNU map as the BSS-reorder baseline used by
# `./tools/mapfile bss_check`. Run this after a verified-good `make build`
# (the rebuilt bin must be byte-identical to the original).
#
# The baseline lives under rom/expected/ which is gitignored (see .gitignore
# `/rom/`), so it is a local, non-committed reference -- not build output that
# gets committed.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
MAP="$ROOT/rom/extracted/baserom/SCUS_942.21.map"
DEST_DIR="$ROOT/rom/expected"
DEST="$DEST_DIR/SCUS_942.21.map"

if [ ! -f "$MAP" ]; then
  echo "[update_expected] $MAP not found; run 'make build' first." >&2
  exit 1
fi

mkdir -p "$DEST_DIR"
cp -f "$MAP" "$DEST"
echo "[update_expected] wrote BSS baseline -> $DEST"
