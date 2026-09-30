# PERM_TRICKS.md - Reusable PERM templates for stubborn FFT stubs

decomp-permuter's **randomizer** is a stateless AST/text mutator written for
IDO-era codegen: it widens types, adds casts, swaps commutative operands, and
reorders statements. It **cannot** synthesize the GCC-2.6 codegen tricks this
project has learned the hard way (register-asm pins, `volatile` delay-slot
blocking, comma-expression value-idioms, switch-vs-if). None of those appear
anywhere in `tools/third_party/decomp-permuter/src/randomizer.py`.

But the manual PERM macro system *can* enumerate any of them. This doc turns
every trick catalogued in `docs/MATCHING_TECHNIQUES.md` §8 into a ready-to-paste
`PERM_GENERAL` / `PERM_LINESWAP` / `PERM_ONCE` fragment, with the func_ citation
and the seed spot where it goes.

## How to use these

1. `make permute FUNC=<func> ARGS="--setup"` (or use the existing scratch dir).
2. Edit `output/scratch/<func>/base.c`, splicing a template around the exact
   statement/decl the trick targets.
3. Because a multi-choice PERM macro disables auto-randomization, wrap the
   function body (or just the targeted region) in `PERM_RANDOMIZE(...)` if you
   still want the randomizer active too.
4. `make permute FUNC=<func> ARGS="-j N"` and watch the log for the best score.

Keep variant counts tiny. A `PERM_GENERAL(a, b)` adds only 1 extra variant; a
`PERM_LINESWAP` of k statements adds k!−1. Don't mix many big `PERM_LINESWAP`s
into one seed.

## Escape hatches

- If pycparser round-trips a fragment badly (rare, but e.g. the `__asm__`
  operand-constraint forms), wrap it in `PERM_IGNORE(...)` - it's emitted raw,
  not parsed.
- `PERM_PRETEND(...)` gives pycparser a placeholder to reason about, then swaps
  in the real text afterwards. Pair with `PERM_IGNORE` for inline asm that the
  randomizer should not touch.

## Backups & landing workflow (read before running anything)

- **Permuter data ALWAYS lives in the permuter's own folder
  (`output/scratch/` scratch, `docs/parked/` snapshots, `tools/scripts/` scripts), never in `build/`.** Scratch dirs are
  `output/scratch/<func>/` (set up by `make permute
  FUNC=<func> ARGS="--setup"`), seed snapshots and verified winners in
  `docs/parked/`. `make clean` only does `rm -rf build/`,
  so it kills running permuter *processes* but can never delete seeds,
  logs, or `output-<score>-<n>/` candidates. `output/` is git-ignored, so
  scratch survives reboots (override with `FFT_PERMUTER_SCRATCH` env var;
  this rule is why the 2026-08-16 18D88-era runs survived a surprise
  `make clean && make build` with zero data loss - only CPU time was lost).
  Caveat: `output/scratch/` is local-only and git-ignored -
  a `make deps` re-clone of the tool would wipe
  it; if seeds become irreplaceable, promote them to the committed seed
  dir `docs/parked/` and update this doc:
  - `docs/parked/` - seed/base.c snapshots and verified
    winning candidates. Copy them there whenever a seed changes or a winner
    appears:
    `cp output/scratch/<func>/base.c docs/parked/func_800<addr>_base.c`
    and `cp output/scratch/<func>/output-0-*/source.c docs/parked/func_800<addr>_win.c`.
    Restore after a re-setup (`make permute FUNC=<func> ARGS="--setup"`) by
    copying the backup back over the fresh `base.c` (setup regenerates
    `compile.sh`, `target.o`, `settings.toml`, which are cheap).
  - `tools/scripts/` - reusable scripts (repo-root-agnostic,
    resolve the root from their own path):
    - `permute.py setup <func>` - builds the scratch dir (`compile.sh` via
      `lib.write_compile_sh`, `target.o`, `settings.toml`).
    - `permute.py diff <func>` - compile `output/scratch/<func>/base.c`,
      objdump it vs `target.o`, print a normalized positional diff. With
      `--candidate [NAME]` it scores a permuter winner (default: the
      lowest-score `output-*`). Empty diff + equal instruction counts =
      standalone match.
  - **A `score = 0` line in permuter.log is only a claim.** The log line
    `wrote to .../output-0-13` + `iteration N, E errors, score = 0` can pair a
    real 0-score write with a large (irrelevant) error counter. Verify with
    `permute.py diff <func> --candidate` before trusting it (the script's empty
    diff at equal counts is a standalone match; then land with
    `make finish FUNC=<func>` - the in-file byte check is the final oracle).
- func_80018D88 (`_spu_inTransfer`) was won exactly this way: a 120-point seed
  (struct `UnkType` statement-casts over `D_8002AD44` + `(u16)` cast on the
  `unk1AA |= 0x30` RMW) became a 0-score solely by declaring
  `extern volatile unsigned int *D_8002AD48;` - volatile on the *pointed-to*
  type preserved the target's `lui/lw/nop/sw` store sequence (non-volatile
  lets GCC fill the delay slot / reorder the store). The winner landed in
  `src/main.c`.

---

## 1. Register-asm pin (force a value into one exact register)

GCC 2.6's allocator insists on saved registers for values that outlive calls
(`s0` instead of the original's `a1`) and picks its own load placement. A
`register <type> <name> asm("reg") = <expr>;` local overrides *both*: the value
lives in that exact register for its whole lifetime, and a load in its
initializer emits at the statement position.

```c
/* func_80013F74: pin arg0 into s0 (was an allocator stalemate until the pin). */
PERM_GENERAL(
    register void **keep asm("s0") = arg0;,
    void **keep = arg0;)

/* func_8001915C / 800190D4: keep a shift result in a1 across repeated calls. */
PERM_GENERAL(
    register u32 shift asm("a1") = D_8002AD5C << D_8002AD6C;,
    u32 shift = D_8002AD5C << D_8002AD6C;)

/* func_800194C4: entry `move v0,a0` + hold arg0 in v0; load D_8002AD6C into a0 at top of block. */
PERM_GENERAL(
    register s32 keep asm("v0") = arg0;,
    s32 keep = arg0;)
PERM_GENERAL(
    register s32 count asm("a0") = D_8002AD6C;,
    s32 count = D_8002AD6C;)
```

Seed spot: replace the plain declaration of the variable you're pinning. The
compiler must accept `register ... asm("reg")` - GCC 2.6.0 does, and pycparser
parses it (its `p_init_declarator` includes `asm_label_opt`).

## 2. Pin an immediate to a caller-saved reg via repeated assignment

GCC's local allocator prefers `v0` for a *later* immediate and will hoist an
earlier store to free it, reordering stores. Force the immediate into a shared
caller-saved reg; statement order controls where the `lui` is emitted.

```c
/* func_800194C4: keep both constants in v1, reused as each prior use dies. */
PERM_GENERAL(
    register s32 hi asm("v1");, s32 hi;)
hi = 0x40001010;
arg1[0] = hi;
hi = 0x10000;
arg1[1] = (hi << count) - 0x1010;
```

## 3. `volatile` destination pointer - block delay-slot fill

GCC keeps hoisting a following load into the previous store's delay slot,
shifting every instruction by one. Declare the destination `volatile`.

```c
/* func_8001934C / 80019378 (and the u16 bitfield write at 80019D88). */
PERM_GENERAL(
    volatile s32 *dst = ...;, s32 *dst = ...;)
/* or cast at the store site: */
((volatile u16 *)D_8002AD44)[arg0] = (u16)arg1;
```

## 4. Comma-expression `== const` value-idiom at a chosen expand point

`((arg1 | ((arg2 == 5) << 7)) << 8)` inline in a store's RHS compiles the eq
to a *branch* plus bogus code; a precomputed statement gives the clean
`xori/sltiu/sll` chain but the store's index `sll` lands after it. Write the eq
as a comma-expression inside the RHS so the store statement expands first and
the assignment context preserves the value-idiom.

```c
/* func_8001B938: original has `sll a0,4` BEFORE `xori/sltiu/sll`. */
s32 bit;
base[voice * 8 + 4] = (base[voice * 8 + 4] & 0xFF) |
                      ((bit = (arg2 == 5) << 7, (arg1 | bit)) << 8);
```

## 5. switch-vs-if for dead stores in branch delay slots

Some targets emit dead stores in branch delay slots (`li a1,0x100` fills a
`beq`'s slot, `move a1,0` fills a `j`'s slot). Every `if/else` phrasing is a
near-miss; a `switch (arg1)` with cases in source order is byte-exact because
GCC 2.6's expand emits the comparison chain with all bodies out of line and dbr
fills the slots from the fall-through chain's first store.

```c
/* func_8001AC7C (SpuReadDecodedData). */
PERM_GENERAL(
    switch (arg1) { case 5: ...; break; case 6: ...; break; default: ...; },)
```

## 6. Single-global base-register cast idiom

For base-register store form on one global byte that isn't array/struct
indexed, cast through a derived index. `volatile` also blocks delay-slot fill.

```c
/* func_800200D4: ((volatile u8 *)&D_80031B5A)[-1] = ...; addresses D_80031B59. */
((volatile u8 *)&D_80031B5A)[-1] = ...;
```

## 7. Pointer-arithmetic fold trap - insert an intermediate pointer

`int *p = &D_80037034; p[-5] |= 0x300;` folds back to direct-symbol
`D_80037034-20` and mismatches. An intermediate pointer stops the re-fold and
keeps `lw -0x14($p)` base-relative.

```c
/* func_800183C0 / 80018400. */
PERM_GENERAL(
    int *q = p - 5;, int *q = &D_80037034[-5];)
```

## 8. Argument-width variations (s32 vs s16 vs u8)

Types are load-bearing for mask placement and unsigned compare selection.

```c
/* func_8001B428 (SpuSetVoiceVolume): s16 args put both `andi` masks at function entry. */
/* func_8005B500 (GetRandomUnlockedJob): u8 keeps `andi v0,v1,0xFF; sltiu`. */
PERM_GENERAL(s16 arg2;, s32 arg2;)   /* or u8 / s16 / s32 per the target's mask/compare */
```

## 9. Clamp must be if/else, not else-if

For `noise = clamp(arg0, 0, 0x3F)`, m2c's `else if` emits `move a1,a0` + a
misplaced `slti`. Write the negative case as fallthrough and the assignment
inside the `else`.

```c
/* func_80019D88. */
PERM_GENERAL(
    noise = 0; if (arg0 >= 0) { noise = arg0; if (noise >= 0x40) noise = 0x3F; },
    noise = arg0 >= 0 ? (arg0 >= 0x40 ? 0x3F : arg0) : 0;)
```

---

## When to reach for these

The randomizer alone usually just reshuffles register allocation. If a seed has
been running a while and the score plateaued above 0 with a *few* clearly
localized diffs (an `s0` vs `a1`, a store ordering, a delay-slot `nop`), splice
the matching template in by hand and re-run. These are the same tricks the
project already uses in `src/main.c` (grep for `asm(` and `volatile` there for
in-file working examples).

Do **not** use register pins for transient base loads the allocator handles
fine - pins only help lifetime-long values, and bleeding them into simple
dependent expressions can drag unrelated code into the pinned register.
