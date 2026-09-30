#!/usr/bin/env python3
"""Agent-friendly helper to pick which asm stub to decompile next.

Searches every code segment under rom/extracted/asm/nonmatchings/ (main, main_3,
main_4, main_5 -- splat emits one dir per code subsegment), so stubs
from the embedded GCC regions are pickable too.

Design goals for autonomous agents:
  - deterministic (stable ordering) so parallel/retried runs agree,
  - prefers small, self-contained functions first (highest success rate),
  - avoids symbols already implemented in C (real definitions in src/).

Usage:
  python3 tools/pick_function.py                 # pick one automatically
  python3 tools/pick_function.py --list 5        # show top 5 without claiming
  python3 tools/pick_function.py --segment main2 # restrict to one segment
  python3 tools/pick_function.py --symbol FUNC   # print the exact claim info
  python3 tools/pick_function.py --done FUNC     # mark FUNC done (removes stub)
  python3 tools/pick_function.py --clean         # list cleanly-decompilable stubs
  python3 tools/pick_function.py --health FUNC   # stub health flags (for workflow.py decompile)
  python3 tools/pick_function.py --include-psyq  # also list tagged INCLUDE_PSYQ SDK stubs
  python3 tools/pick_function.py --psyq-only     # list ONLY tagged INCLUDE_PSYQ SDK stubs
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "scripts"))

import symbols  # noqa: E402
import lib  # noqa: E402
try:
    import target as target_mod  # noqa: E402
except ImportError:
    target_mod = None  # noqa: E402

ROOT = lib.ROOT

SEGMENTS = symbols.SEGMENTS


def _target(args):
    blob = getattr(args, "blob", None)
    if blob and target_mod is not None:
        return target_mod.get_target(blob)
    return None


def _lines(path: Path, stubs: dict | None = None) -> int:
    """Instruction count: size from the stub's nonmatching header (// 4)."""
    return (stubs or symbols.stub_scan()).get(path.stem, {}).get("instrs", 0)


def claim_info(sym: str, target=None) -> dict:
    stub = symbols.find_stub(sym, target=target)
    info = {
        "function": sym,
        "stub_asm": str(stub.relative_to(ROOT)) if stub else None,
        "segment": stub.parent.name if stub else None,
        "exists": stub is not None,
    }
    if stub:
        info["asm_lines"] = _lines(stub)
    # associated rodata symbol (if any) is embedded in the same stub file
    return info


HARD_TAILS = (Path(__file__).resolve().parents[2] / "config"
              / "hard_tails.txt")


def load_hard_tails() -> set[str]:
    """Names registered in config/hard_tails.txt (comments ignored)."""
    out = set()
    for line in HARD_TAILS.read_text().splitlines():
        name = line.strip().split("//")[0].strip()
        if name and not name.startswith("#"):
            out.add(name)
    return out


def difficulty(path: Path, stubs: dict | None = None) -> int:
    """Cost estimate: insns + 2*calls + branches + 8*jumptables + 2*multdiv.

    GTE/COP2 presence doubles the score (m2c struggles with cop2).
    Uses the shared symbols.is_cop2_text detector (COP2 transfers +
    GTE macro ops).
    """
    text = path.read_text(errors="replace")
    stubs = stubs or symbols.stub_scan()
    insns = stubs.get(path.stem, {}).get("instrs", 0)
    calls = len(re.findall(r"\bjal\b", text))
    brs = len(re.findall(r"\b(beq|bne|beqz|bnez|blez|bgez|bltz|bgtz)\b",
                         text))
    jtbl = len(re.findall(r"\bjtbl_", text))
    md = len(re.findall(r"\b(mult|div|multu|divu)\b", text))
    score = insns + 2 * calls + brs + 8 * jtbl + 2 * md
    if symbols.is_cop2_text(text):
        score *= 2
    return score


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--symbol", help="Print claim info for a specific function")
    ap.add_argument("--list", type=int, metavar="N", help="List the N easiest functions")
    ap.add_argument("--segment",
                    help="Restrict to one segment (default: all)")
    ap.add_argument("--blob", default=None,
                    help="Blob target (scopes stubs + C units)")
    ap.add_argument("--done", metavar="SYM", help="Remove a stub that has been matched")
    ap.add_argument("--clean", action="store_true",
                    help="List stubs that are cleanly decompilable (see AGENTS.md "
                         "'Detect merged stubs'): exactly one jr ra, standard "
                         "jr ra / nop / endlabel tail, no alabel bodies, no "
                         "embedded .rodata, not PSYQ-relabelled. Flags non-clean "
                         "stubs too.")
    ap.add_argument("--health", metavar="SYM",
                    help="Print stub health + instruction count for one stub "
                         "(used by workflow.py decompile)")
    ap.add_argument("--include-hard-tails", action="store_true",
                      help="Include config/hard_tails.txt stubs in pick lists "
                           "(default: excluded from --list and default pick)")
    ap.add_argument("--include-psyq", action="store_true",
                    help="Include tagged INCLUDE_PSYQ SDK stubs in pick lists "
                         "(default: excluded from --list and --clean)")
    ap.add_argument("--psyq-only", action="store_true",
                    help="List only tagged INCLUDE_PSYQ SDK stubs "
                         "(implies --include-psyq)")
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()

    t = _target(args)
    segs = t.segments if t is not None else list(SEGMENTS)
    if args.segment and args.segment not in segs:
        print(f"error: unknown segment {args.segment} (known: {', '.join(segs)})",
              file=sys.stderr)
        return 1

    implemented = symbols.implemented_vram(target=t)

    if args.done:
        stub = symbols.find_stub(args.done, target=t)
        if stub:
            stub.unlink()
            print(f"Removed stub {stub}")
        else:
            print(f"No stub for {args.done}", file=sys.stderr)
        return 0

    if args.health:
        stub = symbols.find_stub(args.health, target=t)
        if not stub:
            print(f"error: no stub for {args.health}", file=sys.stderr)
            return 1
        flags = symbols.stub_health(stub)
        instrs = symbols.stub_scan(target=t).get(stub.stem, {}).get("instrs", "?")
        print(f"instrs={instrs}")
        print("flags=" + " ".join(
            f"{k}" + (f"({v})" if isinstance(v, str) else "")
            for k, v in sorted(flags.items())) or "flags=")
        return 0

    if args.symbol:
        import json
        print(json.dumps(claim_info(args.symbol, target=t), indent=2))
        return 0

    stubs = symbols.stub_scan(target=t)
    implemented = symbols.implemented_vram(target=t)
    funcs = []
    psyq_n = 0
    psyq_shown: set[str] = set()
    for name, info in stubs.items():
        if name.startswith("D_"):
            continue  # rodata/data symbols, not functions
        if info["vram"] in implemented:
            continue
        if args.segment and info["segment"] != args.segment:
            continue
        is_psyq = symbols.is_psyq_stub(name, info.get("vram"))
        if is_psyq:
            psyq_n += 1
            if not (args.include_psyq or args.psyq_only):
                continue  # tagged SDK stubs: stubbed by policy, never picked
            psyq_shown.add(name)
        elif args.psyq_only:
            continue
        funcs.append((info["file"], info["segment"]))

    if args.clean:
        # clean_stubs.sh equivalent: every stub with its health flags
        rows = []
        clean = 0
        for f, seg in sorted(funcs, key=lambda p: (p[1], p[0].name)):
            flags = symbols.stub_health(f)
            if not flags:
                clean += 1
            rows.append((f, seg, flags))
        for f, seg, flags in rows:
            detail = " ".join(
                f"{k}" + (f"({v})" if isinstance(v, str) else "")
                for k, v in sorted(flags.items()))
            marker = "CLEAN " if not flags else "      "
            tag = " [PSYQ]" if f.stem in psyq_shown else ""
            print(f"{marker}[{seg}] {f.name[:-2]:28s} "
                  f"({_lines(f, stubs):5d} asm lines){tag} {detail}")
        print("----")
        print(f"{clean}/{len(rows)} stubs clean (single jr ra, standard tail, "
              "no embedded rodata)")
        if psyq_n - len(psyq_shown) and not args.segment:
            print(f"({psyq_n - len(psyq_shown)} tagged INCLUDE_PSYQ SDK stubs "
                  "excluded - see docs/PSYQ_STUB_POLICY.md)")
        if clean == 0:
            print("no clean candidates in this scope")
        return 0

    hard = load_hard_tails()
    if not args.include_hard_tails:
        funcs = [p for p in funcs if p[0].stem not in hard]
    hard_live = sorted(hard & {f.stem for f, _ in funcs})

    # Sort by difficulty score ascending, then segment+name for determinism.
    funcs.sort(key=lambda p: (difficulty(p[0], stubs), p[1], p[0].name))

    pick = funcs[0] if funcs else None
    shown = funcs if args.list is None else funcs[: args.list]

    if args.json:
        import json
        payload = {"remaining": len(funcs),
                   "hard_tails_live": hard_live,
                   "psyq_shown": len(psyq_shown),
                   "psyq_excluded": psyq_n - len(psyq_shown),
                   "pick": str(pick[0]) if pick else None,
                   "segment": pick[1] if pick else None,
                   "candidates": [str(p[0]) for p in shown]}
        print(json.dumps(payload, indent=2))
        return 0

    if not shown:
        print("No nonmatching functions remain - all decompiled? Run make build + diff to confirm matches.")
        return 0

    print(f"{len(funcs)} functions still to decompile. Easiest choices:")
    for p, seg in shown:
        tag = " [PSYQ]" if p.name[:-2] in psyq_shown else ""
        print(f"  [{seg}] {p.name[:-2]:28s} ({_lines(p, stubs):5d} asm lines, "
              f"diff {difficulty(p, stubs):4d}){tag}")
    if psyq_n - len(psyq_shown) and not args.segment:
        print(f"({psyq_n - len(psyq_shown)} tagged INCLUDE_PSYQ SDK stubs "
              "excluded - see docs/PSYQ_STUB_POLICY.md)")
    if hard_live and not args.include_hard_tails:
        print(f"({len(hard_live)} hard-tails excluded - see "
              "config/hard_tails.txt; use --include-hard-tails)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
