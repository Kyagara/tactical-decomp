# PSX Reference - hardware, toolchain & file formats

Background for the decompilation. This document
collects the facts an agent needs to make sense of the disassembly, the
PSYQ-era toolchain, and the formats this repo manipulates. It is a condensed
reference, not a full spec - see [psx-spx](https://psx-spx.consoledev.net/) for
authoritative hardware detail and [PSDevWiki](https://www.psdevwiki.com/ps1/)
for reverse-engineering notes.

---

## 1. The console

The original PlayStation (PS1/PSX) is a 32-bit CD-based console. Everything the
decompiled `SCUS_942.21` executable touches lives in a flat 32-bit address space
with no MMU.

### 1.1 CPU

- **MIPS R3000A-compatible** core (LSI Logic CW33300-based R3051), 32-bit RISC,
  running at **33.8688 MHz**, ~30 MIPS.
- **Little-endian** byte order. This is why the whole build uses `-EL`, and why
  instruction encodings appear byte-swapped in the raw ROM dump.
- **No FPU.** The console has no floating-point unit (COP1 is absent); all
  geometry math is fixed-point, mostly via the GTE.
- **Cache:** 4 KB direct-mapped instruction cache (256 lines × 4 words). The
  1 KB data cache is exposed as the **scratchpad** (see 1.4), not a general
  data cache.
- Coprocessors:
  - **COP0** - system control (SR, Cause, EPC, cache control …). Modified from
    the stock R3000A COP0; no MMU.
  - **COP2 = GTE** (Geometry Transformation Engine) - a vector/matrix
    coprocessor for 3D transforms, lighting and clipping, 66 MIPS, fixed-point.
    GTE instructions are the `COP2` opcodes (`mfc2`, `ctc2`, `mtc2`, `cfc2`,
    and the `R*`/`N*`/`S*`/`L*` transform/color instructions). splat
    disassembles them; m2c struggles with them - flag such functions rather
    than guessing. Assembler-side macros live in `include/gte_macros.inc`
    (verbatim Silent Hill `cop2op` set, via `include/macro.inc`); C-side
    inline macros in `include/psx_gte.h` (real oracle words, never
    `common.h`-included). Matching policy and the hard-tail levers
    borrowed from the NFSHS/Silent Hill playbooks live in
    `MATCHING_TECHNIQUES.md` §8 (COP2/GTE entry).
- **Load/branch pipelines:** MIPS I has **branch delay slots** (the instruction
  after a `beq`/`j`/`jalr`/`jr` executes regardless of the branch) and the
  R3000 has a **load delay** (GCC fills a `nop` after loads that are followed
  by use). Both appear constantly in the stubs and shape every matched
  function's schedule.

### 1.2 System chips

- **GPU** (separate chip): rasterizer for textured/flat/Gouraud polygons and
  sprites; framebuffer lives in VRAM; no hardware Z-buffer. The CPU feeds it a
  stream of primitive commands through FIFO registers or DMA.
- **SPU**: 24-channel ADPCM audio, 44.1 kHz, reverb; 512 KB of dedicated
  Sound RAM (not in the CPU's address map; accessed via DMA or FIFO).
- **MDEC**: hardware motion-JPEG decoder for FMV.
- **DMA controller**: 7 channels moving data between main RAM and GPU/SPU/
  MDEC/CD-ROM/OT. PSYQ code (`libetc`, `libgpu`, `libcd`) wraps this.
- **Timers**, **SIO** (controllers/memory cards), **CD-ROM** drive (2× speed).

### 1.3 CPU memory map (psx-spx)

Main RAM is mirrored into three segments; the raw code runs from KUSEG/KSEG0.

```
 KUSEG     KSEG0     KSEG1      size   region
 00000000  80000000  A0000000   2 MB   Main RAM (first 64 KB reserved for BIOS)
 1F000000  9F000000  BF000000   8 MB   Expansion Region 1 (ROM/RAM)
 1F800000  9F800000  --         1 KB   Scratchpad (fast SRAM, NOT executable)
 1F801000  9F801000  BF801000   4 KB   I/O ports (GPU, SPU, DMA, timers, CD...)
 1F802000  9F802000  BF802000   8 KB   Expansion Region 2 (I/O)
 1FA00000  9FA00000  BFA00000   2 MB   Expansion Region 3 (DTL debugger SRAM)
 1FC00000  9FC00000  BFC00000   512 KB BIOS ROM (kernel)
 FFFE0000  (KSEG2)             0.5 KB  CPU cache/BIU control registers
```

- **KUSEG / KSEG0** are cached; **KSEG1** is uncached and bypasses the 4-entry
  write queue (use `BF8018xx` for hardware registers when ordering matters).
- **Scratchpad** at `1F800000` is the re-purposed 1 KB data cache; fast, but
  jumping to it causes a bus error.
- Not on the CPU bus: 1 MB VRAM, 512 KB Sound RAM, CD-ROM controller RAM/ROM,
  32 KB CD buffer, memory cards.

For this project the interesting region is **RAM at `0x80010000`+** - the EXE's
text and data load target (see §3), with `gp` set to `0x800329BC`
(`config/boot.yaml`) and the stack top at `0x801FFFF0`.

**Loader view (Ghidra PSX loader plugin):** maps the console address space as
one contiguous block from the scratchpad/hardware-region low end (`0x1F800000`)
through the top of cached RAM (`0x801FFFFF`) - mirroring the physical PS1 bus -
and reports main RAM itself as 2,097,152 bytes (2 MiB), little-endian, 32-bit
addresses; consistent with the table above.

### 1.4 Consequences for decompilation

- **Endianness:** raw bytes in the ROM are little-endian; a disassembly tool
  must know the target is `mipsel`.
- **Delay slots:** a matching function's instruction order is fixed by GCC
  scheduling into delay slots - moving any instruction changes bytes, and
  `maspsx` cannot reorder the epilogue (see `AGENTS.md` "Compiler pin").
- **No FPU:** any float-looking math in the code is either GTE or fixed-point
  emulation.
- **Hardware access:** globals like `D_800329BC`-style addresses are just RAM;
  `0x1F80xxxx` constants are I/O ports (GPU/SPU/DMA/CD), not data.

---

## 2. MIPS I ISA & instruction encoding

> For the full mnemonic-by-mnemonic reference - registers, alignment, delay
> slots, and the COP2/GTE set - see `MIPS_ASSEMBLY_REFERENCE.md`.

- Fixed 32-bit instructions, three formats:
  - **R-type**: `op rs rt rd sa funct` - `add`, `sub`, `sll`, `srl`, `jr`,
    `jalr`, `mult`, `div`, …
  - **I-type**: `op rs rt imm16` - `addiu`, `lw/sw/lhu/sb`, `beq/bne`,
    `lui`, `andi/ori`, …
  - **J-type**: `op target26` - `j`, `jal`.
- **Register conventions** (GCC MIPS):
  - `$0` zero, `$2/$3` return values, `$4–$7` args, `$8–$15` temps (`t0–t7`),
    `$16–$23` saved (`s0–s7`), `$24/$25` temps, `$28` **gp**, `$29` **sp**,
    `$30` fp, `$31` ra. Note PSYQ GCC's `$at` (assembler temp) usage.
- **Addressing:** 32-bit addresses are built as `lui $at,%hi(sym)` +
  `addiu $at,%lo(sym)`. The splat stubs show this as `lui $v0,%hi(D_...)` /
  `lw $v0,%lo(D_...)($v0)`.
- **Pseudo-instructions** (`li`, `la`, `move`, `bal`, `b`) are expanded by the
  assembler (e.g. `move rd,rs` → `addu rd,rs,$0`). splat disassembles to the
  canonical form; `maspsx` re-emits PSYQ-compatible mnemonics from GNU `as`
  output. This is why `ori $v0,$0,1` and `addu $v0,$0,$0` appear where a modern
  disassembler would show `li`/`move`.
- **HI/LO:** `mult`/`div` leave results in HI/LO; `mfhi`/`mflo` read them.
  GCC 2.6 emits these for 64-bit `long long` multiplies and division.

---

## 3. PS-X EXE format

The PlayStation executable header is **2048 bytes (0x800)**, followed by the
text/data image and then an **0x800-byte relocation table** (footer).

Key header fields (offsets in bytes):

| offset | field |
| --- | --- |
| 0x00 | magic `PS-X EXE` |
| 0x08 | `.text` vram address |
| 0x10 | **Initial PC** (this game: `0x80010A30`) |
| 0x14 | Initial `$gp` (this game: `0x0`; `gp` is set by the boot code) |
| 0x18 | **`.text` load address** (this game: `0x80010000`) |
| 0x1C | `.text` size (this game: `0x56800`) |
| 0x20 | `.data` load address |
| 0x24 | `.data` size |
| 0x28 | `.bss` address / 0x2C `.bss` size |
| 0x30 | Initial `$sp`/`$fp` base (this game: `0x801FFFF0`) |
| 0x34 | Initial `$sp`/`$fp` offset |
| 0x3C+ | reserved |
| 0x800 | relocation table |

- `config/boot.yaml` mirrors this: header segment, text subsegment starting at
  `0x1224` (file offset of the first function at vram `0x80010A24`), data at
  file offset `0x192F4`.
- `rom/extracted/asm/header.s` reproduces the header bytes so the linked output matches the
  original exactly.
- The **relocation table** exists so an executable loaded from CD can be
  relocated at runtime (overlays - §5). The kernel's `Exec`/`LoadExec`
  functions use it.

---

## 4. Disc format (CD-ROM XA)

- PSX discs are **CD-ROM XA**: each raw 2352-byte sector = 12-byte sync +
  4-byte header + 8-byte subheader + 2048-byte user data (Mode 2).
- `tools/bin/extract_bin.py` rebuilds a clean 2048-byte ISO9660 image from the user-data
  stream and reads it with `pycdlib`, so directory records spanning sectors are
  handled correctly. It writes:
  - `rom/extracted/baserom/` - every file extracted (the exe plus data files);
  - `rom/extracted/data_map.json` - the sector→file map needed later to **reassemble**
    the bin without decompiling the assets.
- Both input files are SHA1-verified against `config/disc_checksums.txt` before
  extraction writes anything, and `make bin` verifies the rebuilt
  `build/fft.bin` against the retail bin hash (a matching exe must
  reproduce the retail disc byte-for-byte; `--no-verify` forces past the check).
- The FFT (USA) disc layout (from `rom/extracted/baserom/`):
  - `SCUS_942.21` - the main executable (this project's target);
  - `SYSTEM.CNF` - boot descriptor (`BOOT = cdrom:\SCUS_942.21;1`);
  - `BATTLE.BIN` - battle tables/maps;
  - `BATTLE/`, `EVENT/`, `MAP/`, `MENU/`, `WORLD/` - sprites (`.SPR`/`.SHP`),
    map data, scripts; `SOUND/` - music (`.SMD`/`.SED`); `EFFECT/`, `OPEN/`.
  - Most of these are **data** loaded through the CD library, but several are
    **runtime-loaded code** - see §5.2: `WORLD.BIN`, `WLDCORE.BIN`, `OPEN.BIN`,
    the 11 `EVENT/*.OUT` menu overlays, and 110 of the 512 `EFFECT/E###.BIN`
    battle-effect files.

---

## 5. Overlays

"Overlay" on the PS1 is used in two senses, and FFT fits the second:

- **Kernel-style overlays:** loading a *code* module from CD into RAM at
  runtime, applying the module's relocation table, and jumping into it. Games
  that use them ship multiple small EXE-style modules (a `PS-X EXE` header +
  relocation table) and swap them as needed; the kernel's `Exec`/`LoadExec`
  load and relocate them.
- **FFT's "overlays" - runtime-loaded fixed-address code blobs.** FFT does
  **not** use kernel-style overlays: the disc has no EXE modules, no
  relocation tables, and the game never calls `LoadExec`/`Exec`. Instead, the
  game loads **raw code blobs** (no header, no relocation) through the CD
  library into a fixed RAM region (base `0x80060000`), then jumps into fixed
  entry points. This is why "FFT has no overlays" (strict kernel sense) and
  "the disc contains overlay code" (functional sense) are both true: the FFT
  community calls these files overlays because they are executed code, not
  data.

### 5.1 Kernel-style overlays: none

`config/reloc_addrs.txt` is empty; the relocation table inside `SCUS_942.21`
exists but is never used (no EXE-format overlay is ever loaded). All *game*
code lives in the single `SCUS_942.21` image (0x56800 bytes of text starting
at `0x80010000`) plus the loaded code blobs of §5.2.

### 5.2 Disc code blobs (runtime-loaded code)

The following disc files contain executable MIPS code - GCC 2.6-style output,
same compiler as the exe - loaded at runtime and executed by the game:

| File(s) | Functions (`jr ra`) | Size | Contents |
| --- | --- | --- | --- |
| `WORLD/WORLD.BIN` | ~1014 | 973 KB | world map overlay |
| `WORLD/WLDCORE.BIN` | ~435 | 449 KB | world map core (pointer table → base `0x80060000`) |
| `OPEN/OPEN.BIN` | ~154 | 223 KB | opening sequence code |
| `EVENT/*.OUT` (11 files) | ~777 | 1.1 MB | menu overlays (`BUNIT` 183, `EQUIP` 179, `CARD` 95, `JOBSTTS` 94, `REQUIRE` 81, `ATTACK` 77, `DEBUGCHR` 37, `OPTION` 18, `ETC` 7, `HELPMENU` 4, `SMALL` 2) - code + data tables |
| `EFFECT/E###.BIN` (110 of 512) | ~210 | code ≈ 5–12 KB each | battle effects: 1–4 functions per file + data (sine tables, coordinates, palettes) |

Evidence these are code, not data:

- They start directly with GCC 2.6 prologues (`addiu sp,sp,-imm`, `sw s*`):
  `EFFECT/E000.BIN` at file offset 0, `EVENT/EQUIP.OUT` at offset 0x4.
- Hundreds of `jr ra` (`0x03e00008`, exact 32-bit constant - ~0 false
  positives in data) and `jal` instructions.
- **Absolute, compiled-in addresses, valid only at the fixed load base:**
  every `jal` target has top bits `0x3` (resolved to `0x8xxxxxxx` from the
  fixed PC), `lui`/`lw` hit RAM globals (`0x8017xxxx`+), and effect code
  `jal`s *into the exe* (e.g. `0x80044a60`, the embedded island). Load a blob
  at any other base and it crashes. The pointer tables at the start of
  `BATTLE.BIN`/`OPEN.BIN`/`WLDCORE.BIN` pin the base to `0x80060000`.
- They are interdependent with the exe: they call exe functions and share its
  RAM globals.

### 5.3 Embedded code inside the `data` segment - now split as main_4/main_5

The “contiguous GCC code region” inside the old `data` subsegment
(`[0x192F4, data, main]`, vram `0x80028AF4–0x80056800`, file
`0x311C4–0x4F104`) is now split as **two embedded islands** per
`config/boot.yaml`: `main_4` (`0x80040934–0x8004593C`) and `main_5`
(`0x80059854–0x8005E90C`), each with its own `src/main_*.c` C unit and
`rom/extracted/asm/nonmatchings/main_*/` stubs. The surrounding data
(`gap_ab`, `tail_b`) remains pure data.

### 5.4 Disc code blobs - byte-exact pilot (`OPEN.BIN`)

Disc blobs (§5.2) are raw, fixed-address code (no headers, no relocation,
`BATTLE.BIN`/`OPEN.BIN`/`WLDCORE.BIN` pointer tables pin `0x80060000`); they
call into the exe and share its RAM globals. `OPEN.BIN` is an active
byte-exact decomp pilot alongside the executable: own splat config
(`config/blobs/open.yaml`, never segments in `config/boot.yaml`), own C
units (`src/blobs/open/*.c`, one per code cluster), own stubs
(`rom/extracted/blobs/open/`) and build tree (`build/blobs/open/`),
scoped behind `BLOB=<name>` (`make BLOB=open split/build/compare/decompile/finish`).
Blob design follows `AGENTS.md` (exe + blob pilots) with per-blob configs in
`config/blobs/`.
`rom/extracted/data_map.json` is exe-patching only in the decomp (`tools/bin/build_bin.py`
patches `SCUS_942.21`); blob bytes are copied back verbatim so the disc stays
bootable at every step. A future full-ISO target must stay pack-only: depend
on the per-target `.bin`s (each built with its own frozen `GCC_FLAGS` +
per-target `aspsx_version`), never re-assemble sources under one flag set.

---

## 6. PSYQ - Sony's PS1 SDK

**Psy-Q** is Sony's official PlayStation development kit. For a decompiler the
important parts are the toolchain and the libraries, because they determine the
exact bytes the original binary was built with.

### 6.1 Toolchain

- **ccpsx** - the SN Systems C compiler (Lattice-flavoured), and **psyq-link** -
  the SN linker. These produce COFF objects and the PS-X EXE.
- **PSYQ GCC** - a GNU fork (GCC **2.6–2.8** era) shipped in later PSYQ
  revisions; many western titles, FFT included, were built with it.
- **SDK revision:** the Ghidra PSX loader plugin identifies this binary as
  **PSYQ 3.6.10** - Sony's SDK/library release. That is a separate datum from
  the GCC version: byte-matching pins the compiler to GCC 2.6.0/2.6.3 (see
  `AGENTS.md` "Compiler pin").
- **Object format:** PSYQ uses **COFF**; GNU tools use ELF. `maspsx` bridges
  the gap by rewriting GNU `as` output into PSYQ-compatible form so the bytes
  match what ccpsx/PSYQ-GCC + psyq-link produced.
- **snasm** - the SN assembler.

### 6.2 Compiler flags that matter

- `-O2` - the original's optimisation level (GCC 2.6).
- `-G0` - no `$gp`-relative small-data addressing (all globals accessed via
  `lui`/`lw`); this is why the stubs never use `%gp_rel()`. (The single
  exception - the allocator family `func_8001423C`/`func_80014278`/
  `func_80014358`, which genuinely use `%gp_rel` - is forensically documented
  in `docs/PSYQ_COMPILE_FLAGS.md`.)
- little-endian (`-EL`), MIPS I, no soft-float FPU code.
- This project pins **GCC 2.6.0/2.6.3** (2.7.2+ produces different epilogue
  scheduling). See `AGENTS.md` "Compiler pin" for the sniffing evidence.

### 6.3 Libraries

PSYQ ships a set of `.lib` files the game links against (`libps`, and per-area
`libetc`, `libgpu`, `libgte`, `libspu`, `libcd`, `libsnd`, `libpress`,
`libcard`, `libmath`, `liboss`).

**`.LIB` archive format:** a `LIB\x01` magic, then members chained by an
absolute next-member offset. Each member is a symbol directory + `LNK` section
map + a source path (e.g. `C:\NEWEST\SRC\ETC\PAD.C`) + the raw code. Symbols
(`PadInit`, `PadRead`, `VSync`, …) extract cleanly. The canonical map
lives at `config/applied_names.txt` (reference-only, not wired into `boot.yaml`). Sony's library *bootstrap* code sits at the
start of the executable's text - in this binary that is the handwritten stub
`func_80010A24`, which sets `$gp` (`D_800329BC`), zeroes `.bss`, and prepares
the stack before jumping to the game. Functions in the main text that call
library routines reference `D_8001xxxx` jump tables; name them in
`config/symbol_addrs.txt` as they are identified.

---

## 7. How this maps to the decomp pipeline

```
rom/*.bin/.cue
   │  make extract  (tools/bin/extract_bin.py, pycdlib)
   ▼
rom/extracted/baserom/SCUS_942.21 + rom/extracted/data_map.json
   │  make split    (splat64, config/boot.yaml)
   ▼
rom/extracted/asm/nonmatchings/main/<func>.s      (per-function stubs + .rodata/.data)
   │  m2c --context build/ctx.c  (MIPS → C89, make context)
   ▼
src/main.c          (real C replaces the INCLUDE_ASM line)
   │  gcc-2.6.0-psx -EL -O2 -G0 -S  (build/src/main.pre.s)
   │  maspsx                          (GNU as → PSYQ-compatible asm)
   │  mipsel-none-elf-as -EL          (build/src/main.o)
   ▼
build/SCUS_942.21.exe  ← link (ld -Map, symbols.def for D_*/func_*)
   │  objcopy -O binary
   ▼
build/SCUS_942.21.bin ── make compare ──► rom/extracted/baserom/SCUS_942.21
        │
        └── make diff FUNC=<func>  (asm-differ, reads build/*.map)
```

Because the target is little-endian MIPS I built with PSYQ GCC 2.6.x at `-O2
-G0`, every decompiled function must be written as C89 that that exact compiler
turns back into the same bytes - including delay-slot scheduling, load-delay
`nop`s, `lui/%hi`+`%lo` addressing, and the countdown-loop forms (see
`docs/MATCHING_TECHNIQUES.md` §8).
