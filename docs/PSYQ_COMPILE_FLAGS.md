# PSYQ functions and compile flags: what the ROM actually shows

*Status: investigated 2026-08-14. Supersedes the earlier "PSYQ library members
use a nonzero `-G`" note in AGENTS.md, which this document corrects.*

## TL;DR

- **Every PSYQ SDK function linked into FFT was compiled with `-G0`**, the same
  as the game code. There is no "library flag" to chase.
- The only `%gp_rel` (nonzero-`-G`) code in the whole main segment is one
  **allocator family** (`func_8001423C`, `func_80014278`, and the merged stub
  `func_80014358`), which matches **no** SDK library member and is **game-side**
  (or at least not identifiable from the SDK archives we have).
- PSYQ functions that are hard to decompile are hard for **codegen/size
  reasons** (huge state machines, embedded `.rodata`, merged stubs, allocator
  stalemates) - **not** because they were built with different flags.

## Evidence

### 1. ROM-wide scan: only one function family uses `%gp_rel`

Scanning every instruction of the main text segment for `$gp`-base (register
28) load/store operations finds **11 memory ops in 4 function bodies**:

| vram | function | status |
| --- | --- | --- |
| 0x80014248-0x80014260 | func_8001423C | decompiled (inline asm) |
| 0x80014288, 0x800142D4 | func_80014278 | decompiled (inline asm) |
| 0x80014358-0x800143A0 | func_80014358 | merged stub, kept |
| 0x800143AC-0x800143FC | func_800143AC (dead tail of the stub above) | - |

All four are free-list/heap routines touching the same `.bss` globals
(`D_800329F8/FC`, `D_80032A38`, `D_80032A50/5C/64`). The boot vector
`func_80010A24` also sets up `$gp` itself (`lui $gp,%hi(_gp)`), which is the
only other `$gp` reference.

Every other function in the segment - including **all** fingerprint-matched
PSYQ members (LIBSPU, LIBGTE, LIBGPU, LIBETC, LIBCD, LIBAPI, LIBC…) - uses
plain `%hi/%lo` addressing. Same for the embedded `main_4`/`main_5` islands.

### 2. SDK archive scan: the libraries themselves are `-G0`

All 1040 members of `tools/toolchain/psyq/PSX/LIB/*.LIB` (PSYQ 3.6) were scanned for
`$gp`-base memory ops:

- **0 gp-relative instructions** in the extracted member text.
- The only oddity is `LIBGTE.LIB` member `CLIP_INI`: 7 consecutive
  `sw rt, 0($gp)` stores (relocation slots, offsets patched at link). `CLIP_INI`
  is **not** linked into FFT (no `psyq_matches.csv` entry) and its gp-relative
  style does not appear anywhere in the ROM.
- The 3.5 libs (`PSX/LIB/OLD_LIBS/LIB35.ZIP`) and the 3.5 `MALLOC.OBJ` were
  checked the same way: **zero** gp-relative ops. (`MALLOC.OBJ` declares
  `.sdata`/`.sbss` sections but its text never addresses them via `$gp`.)

### 3. func_80014358 matches no SDK member

The full 0xD4-byte body of `func_80014358` (gp-relative words wildcarded) was
slid against every member of:

- all 3.6 `*.LIB` files,
- all 3.5 `*.LIB` files (from `OLD_LIBS/LIB35.ZIP`),
- the 3.5 standalone `MALLOC.OBJ`,

with a 60% match threshold - **zero hits**. It is not the Sony libc
malloc/free family (`LIBAPI.MALLOC2`/`FREE2`/`I_HEAP2` and `LIBC.C51/C52`
malloc/free are different code and do not use `$gp`).

So the old AGENTS.md claim that `func_80014358` is "a Sony library member
compiled with a nonzero `-G`" is **not supported** by fingerprinting. The
function is a **merged stub** (two `jr ra`, dead tail after `.L800143A4`), which
is unmatchable as C regardless of flags. The surrounding allocator family was
already decompiled (see `src/main.c` `func_8001423C`/`func_80014278`) using
inline `__asm__` with `%gp_rel` - that is the workaround that works, and
`func_80014358` itself stays a stub.

### 4. `_gp` has no small-data section behind it

The linker map defines `_gp = 0x800329BC` but contains **no `.sdata`/`.sbss`
sections** - `_gp` is a bare symbol into plain `.bss`. Only the allocator
family's globals happen to sit within ±0x8000 of it. This is consistent with a
single object (or hand-tuned section placement) using `-G != 0`, not with the
whole SDK being built that way.

## So why ARE some PSYQ functions hard to decompile?

Not flags - the same codegen gotchas as game code (`docs/MATCHING_TECHNIQUES.md` §8), made worse by size:

| stub | reason it resists |
| --- | --- |
| `_spu_FsetRXXa` (func_80018858, 2988 B) | huge state machine, **embedded `.rodata`** (`D_80010054` string) |
| `SpuSetReverbModeParam` (func_8001A014, 2528 B) | huge mode-switch state machine |
| `SpuSetCommonAttr` (func_8001B094, 916 B) | large, **embedded `.rodata`** |
| `SpuSetVoiceVolumeAttr` (func_8001B4B0) | **embedded `.rodata`** |
| `SpuReadDecodedData` (func_8001AC7C) | allocator stalemate: dead stores parked in branch delay slots (documented in AGENTS.md) |
| `func_80014358` | merged stub + `%gp_rel`; kept as stub |

Most remaining PSYQ stubs are *clean* (single `jr ra`) and simply large; and
many PSYQ functions are **already matched** with the standard `-O2 -G0` flags
(SpuInitMalloc, SpuSetNoiseClock, SpuSetVoiceDR/RR/SL/ARAttr, SpuFree,
SpuSetReverbDepth, SpuRead, `_SpuIsInAllocateArea`, …) - the strongest proof
that the game's frozen `GCC_FLAGS` reproduce SDK bytes.

## Practical rules

1. **Decompile PSYQ functions with the game's flags** (`-O2 -G0`, the frozen
   `GCC_FLAGS`). Do not invent a "library `-G`" for them - the ROM says `-G0`.
2. `func_80014358` is the only `%gp_rel` anomaly: keep it a stub (merged), and
   if neighbouring allocator code needs the same globals, use inline
   `__asm__("... %%gp_rel(D_...)(...)($gp)")` like `src/main.c` already does.
3. PSYQ functions that are large or carry embedded `.rodata` are *hard*, not
   *unmatchable* - the rodata must be split/handled per the "Split embedded
   `.rodata`" rules in AGENTS.md before m2c can produce a clean body.
4. `CLIP_INI`-style `sw rt, 0($gp)` code exists in the SDK but is **not** in
   FFT; if a future function shows this pattern, expect a link-time relocation
   patch and handle it as data, not as a flag mystery.

## Assembler-layer note: ASPSX 2.34 == maspsx defaults (verified 2026-08-26)

The assembler layer can insert/omit nops at *assemble time* that never appear
in cc1's `.s` output, and the behavior is version-dependent (maspsx README
"Known Differences": the `mult`/`div`→`mflo`/`mfhi` gap nop appears only with
ASPSX ≥ 2.30; a nop before `$at` expansion only with ASPSX ≤ 2.21; etc.).

- `tools/toolchain/psyq/PSYQ/BIN/ASPSX.EXE` reports `Psy-Q ASPSX version 2.34`.
- maspsx's *default* config (`AspsxVersionConfig`, no `--aspsx-version`
  passed - the Makefile invokes `maspsx.py` bare) matches ASPSX 2.34 exactly:
  `nop_mflo_mfhi=True`, `nop_at_expansion=False`, `addiu_at=False`,
  `sltu_at=True`, `expand_li=True`, `gp_allow_offset=False`.
- Conclusion: the assembler layer is correctly configured; a mystery nop in
  a target is compiler-layer (dbr scheduling), not a maspsx flag bug. If a
  future target shows a *missing* gap nop after `mult`/`mflo` or an extra one
  around `$at` expansion, re-check `--aspsx-version` before touching C.
  Full technique notes: `docs/MATCHING_TECHNIQUES.md` §1b.

## `.set noreorder` in inline asm: TAB vs space, and the per-file leak

Consolidated 2026-09-26 from five independent measurements (BATTLE, EVENT,
OPEN, EXE, WLDCORE). Earlier notes in this file and in per-agent branches
carried a partial version of this and it was wrong; this is the reconciled
statement. `gcc -S` passes **both** spellings verbatim - the divergence is
entirely in `maspsx/__init__.py`, which tracks the reorder flag **only** from
the TAB form.

| spelling | maspsx `is_reorder` | effect |
| --- | --- | --- |
| `.set<TAB>noreorder` | flips | maspsx stops injecting `nop # DEBUG: branch/jump`; `as` fills the delay slot |
| `.set noreorder` (space) | ignored | maspsx keeps injecting its `nop`; `as` is contained by the push/pop pair |

So the two forms are **different tools**, not competing spellings of one:

- **TAB form = a delay-slot tool.** Use it when a hand-written branch's slot
  must be filled by the following instruction. Verified on a `jal` inside a
  hand-written block: 85/121 with the space form, 121/121 with TAB. It does
  **not** *buy* a `nop` - it *suppresses* maspsx's and hands the slot to `as`.
  If you want a `nop` there, use the reorder form instead.
- **Space form = a block-order tool.** Use it to stop GCC re-picking block
  order. It cannot hand a slot to `as`.
- **The working combination for branch + delay-slot placement** (EVENT,
  `REQUIRE func_800637C4`): the **space-form pair before the `if`**, with the
  **TAB forms inside the `asm`**. TAB-only inside the asm lets maspsx inject
  its own `nop` in the branch's delay slot; space-only with no asm lets GCC
  re-pick block order and flip the test polarity.

### The per-file leak - the failure mode that costs a whole function

`is_reorder` is a **per-FILE switch, not a push/pop**. A TAB `.set noreorder`
with no matching TAB `.set\treorder` leaves it off for the rest of the
translation unit and costs a `nop` in every later branch. Measured: a dead-tail
template in BATTLE broke the **next, untouched** function, made the segment
4 bytes short, and broke 14,522 words of `jal` targets - while the function
being worked on stayed byte-identical and the probe still reported 0.

**Always balance a TAB `.set` pair inside the same file, and never trust a
per-function probe as evidence that a file-wide change is contained.** If a
candidate changes code *outside* the function, suspect an unbalanced TAB.

### The operand-free `%` rule, corrected

An operand-free inline `asm` (no constraints at all) skips GCC's template
substitution, so `%hi` must be written `%hi` and `%%hi` fails to assemble. But
an asm **with a clobber list** still goes through substitution, so there it must
be `%%hi`. **Rule: no constraints at all → single `%`; any constraint or clobber
→ double `%%`.**

## Version caveat

The vendored SDK (PSYQ 3.6, `FINISH.TXT`) may not be the exact library
revision FFT linked (Ghidra reports the binary as 3.6.10). This does not
change any conclusion above: the flag story is read from the **ROM's own
bytes**, not from the archives.

### Version-pin result (investigated 2026-09-06)

- Ghidra's "3.6.10" is signature set `3610` in
  `lab313ru/psx_psyq_signatures` (which also has `3611`).
- `3610` vs `3611` are byte-identical for **every** library FFT links
  (LIBAPI/LIBC/LIBC2/LIBCARD/LIBCD/LIBETC/LIBGPU/LIBGTE/LIBSPU/...).
  The single differing object is `LIBSND/MIDIREAD.OBJ`, and FFT links
  **zero** LIBSND objects (`config/psyq_matches.csv` has no LIBSND rows,
  no `Ss*` references in `src/`).
- Residual drift (e.g. `rsin_tbl` HI/LO address words in `GEO_00`,
  member-layout differences in `PRIM`, global slot-order differences in
  `COUNTER`/`EXT`/`VSYNC`/`COR_05`/`SMP_01`/`S_M_UTIL`) is address words
  and link-ordering, not code: no other SDK revision rescues the
  non-matching members. They stay tagged `INCLUDE_PSYQ` stubs
  (see `docs/PSYQ_STUB_POLICY.md`).

## Two compilers ship in this tree; the pin is 2.6.0

**This section exists because an agent read the `tools/toolchain/` directory
listing, saw a directory named `gcc-2.7.2-psx/`, and concluded the pin had
moved off 2.6.0. It has not. There are two compilers here on purpose, and both
directory names are accurate.**

| path | `--version` | role |
| --- | --- | --- |
| `tools/toolchain/bin/mipsel-none-elf-gcc` | `2.6.0` | **the pin** - `MIPS_GCC`, used by every TU by default |
| `tools/toolchain/gcc-2.7.2-psx/bin/mipsel-none-elf-gcc` | `2.7.2` | a deliberate **second** compiler - `FORK_GCC`, one TU only |

The pin is the one under `bin/`, and it is what `MIPS_GCC` names. Confirm it
with `tools/toolchain/bin/mipsel-none-elf-gcc --version` (prints `2.6.0`); the
bare directory listing is not evidence either way, because the 2.7.2 tree has an
equally honest name and an equally honest version string.

**Why 2.7.2 is present at all.** "2.7.2+ is ruled out" (AGENTS.md) is true of
the *game* code - it schedules epilogue delay slots differently and so cannot
byte-match. But **OPEN.BIN is not uniform**: it links translation units from two
compilers. Most of the blob matches FSF 2.6.0-psx, while the `open_fork` unit
was built with **Sony's PSYQ fork (2.7.2.SN.1)**, whose trailing-store schedule
*fills* live `j` delay slots that 2.6.0 provably leaves as `nop`. Native FSF
2.7.2-psx reproduces that fork's codegen exactly on the proven shapes, so the
build needs no emulator. Same `GCC_FLAGS`, same ASPSX; **only cc1 differs.**

The exception is scoped in the Makefile as target-specific overrides, so it is
invisible in a plain `grep` for the compiler:

```make
FORK_GCC  := $(TOOLCHAIN)/gcc-2.7.2-psx/bin/mipsel-none-elf-gcc
FORK_SRCS := src/blobs/open/open_fork.c
$(patsubst %.c,$(BUILD)/%.pre.s,$(FORK_SRCS)): MIPS_GCC := $(FORK_GCC)
```

Two consequences, both of which have been got wrong already:

- **Do not "fix" `src/blobs/open/open_fork.c` to build under 2.6.0.** It is the
  one TU that requires the other compiler; building it with the pin is a byte
  mismatch by construction.
- **Do not conclude from `tools/toolchain/` that the pin moved.** If a
  2.7.2-shaped instruction sequence shows up in game or exe code, that is a bug
  in your C or in a Makefile override, not a licence to use `FORK_GCC`.

To extend the exception, add repo-root paths to `FORK_SRCS` - but only for a TU
with byte-level evidence that the PSYQ fork built it.

## GCC 2.6.0-psx: `register ... asm("vN")` pins and reload placement

A `register s32 x asm("v1")` (or `asm("t0")`, any caller-saved register) is a
**request, not a guarantee**: if `x` has a single use, GCC 2.6 coalesces the
copy away and the value never reaches the named register. Isolation proof
(`s32 f(void){ register s32 x asm("v1"); x = g(); return x + 1; }` compiles to
`jal g` / `addu v0,v0,1` - no `v1` at all). A pin only sticks when the variable
has more than one use, or when the surrounding expression cannot be folded into
the destination. Do not spend shapes on pins to steer a single-use reload.

Related, and the reason a "liveness" explanation for a wrong reload register is
usually wrong: when several short-lived values are precomputed for one call, the
reload allocator picks among the caller-saved registers by its own preference
(v0/v1 first) - it is not steered by which registers are live across the
precompute, and not by pins. Two candidate bodies that differ only in statement
order routinely swap v0 and v1 between the precompute slots. If a specific
register is required in a precompute, write the block as inline asm.

## maspsx eats hand-written asm delay slots unless you use tabs

`tools/third_party/maspsx` tracks the assembler's reorder flag **only** from
lines of the exact form `.set<TAB>noreorder` / `.set<TAB>reorder`
(`maspsx/maspsx/__init__.py`, `line.startswith(".set\t")`). Written with a
space - `.set noreorder` - the flag stays `reorder`, and maspsx then injects
`nop  # DEBUG: branch/jump` after every `jal`/`j` in the block, pushing your
delay-slot instruction out. The symptom is a build that is one word too long with
a `nop` in the delay slot (85/121 instead of 0/121 in the func_80064990 case).
Use tabs in `.set` directives inside inline asm.
