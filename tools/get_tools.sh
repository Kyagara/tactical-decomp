#!/usr/bin/env bash
# Materialise the five third-party tool repos (m2c, maspsx, asm-differ,
# decomp-permuter, coddog) under tools/third_party/.
#
# They are real git submodules (declared in .gitmodules), so this is a
# thin wrapper over `git submodule update --init`: the superproject gitlink
# is the version pin, and there is no clone step to keep in sync. The
# maspsx %gp_rel patch is already committed inside the submodule; the
# `patch` call below only covers a checkout that predates that commit.
#
# Usage:
#   ./tools/get_tools.sh
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
THIRD="$ROOT/tools/third_party"

# path => url, kept in step with .gitmodules (which is the real source).
PATHS=(m2c maspsx asm-differ decomp-permuter coddog)

SUBS=("${PATHS[@]/#/tools/third_party/}")

# Never push the local-only commits upstream: maspsx carries the %gp_rel
# load pass-through and coddog the compare-raw bounds fix. Re-asserted on
# every run, like the equivalent guard in recomp/CMakeLists.txt.
no_push() {
    git -C "$1" remote set-url --push origin no-push 2>/dev/null || true
}

git -C "$ROOT" submodule update --init -- "${SUBS[@]}"

# %gp_rel load pass-through (see tools/third_party/maspsx-gp_rel.patch).
# The submodule gitlink already points at the commit carrying it; this only
# rescues a checkout pinned to the upstream base.
if [ -d "$THIRD/maspsx" ] \
    && ! grep -q "gp_rel" "$THIRD/maspsx/maspsx/__init__.py" 2>/dev/null; then
    printf '[tools] patching maspsx for %%gp_rel support\n'
    patch -p1 -d "$THIRD/maspsx" < "$THIRD/maspsx-gp_rel.patch" || true
fi

for name in "${PATHS[@]}"; do
    no_push "$THIRD/$name"
done

printf '[tools] done. %s are ready (tools/third_party/).\n' "${PATHS[*]}"

