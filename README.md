# tactical-decomp

<p align="center">
  <img src=".github/res/a-game-of-the-final-variety.webp" alt="A fantasy decomp, of the final variety." width="640" />
</p>

<p align="center">
  <em>A fantasy decomp, of the final variety.</em>
</p>

## About

I've always wanted to try my hands at a decomp project and FFT is easily my favorite game of all time, I even tried years and years ago matching some functions for the fun of it, now that and easily accessible and, in some cases, a good "replacement" of the original game is available on major platforms, and I have tokens to spare, I tried to force a decomp out.

My goal is first and foremost this decomp, with the [recomp/README.md](recomp/README.md) an afterthought (though I am currently in the process of verifying if it doesn't contain major bugs/unplayable). I wished for an actual port, but a wish is all it will be, that would be an entirely different beast.

This project was entirely vibe coded and has hit a 'slow grind' part, I am mostly in the process of removing unecessary/not needed anymore things made along the way and cutting down on the overly verbose nature of LLMs.

### 'Is this better than-'

No, you definitely want to play the [new version](https://store.steampowered.com/app/1004640/FINAL_FANTASY_TACTICS__The_Ivalice_Chronicles/).

## Credits

For the decomp tooling:

* Reverse-engineering references: [FFHacktics](https://www.ffhacktics.com/) wiki, forums, and modding docs, data maps, file formats, and community research used to understand the game.
* Splitting / building: [splat](https://github.com/ethteck/splat) (binary splitter), [spimdisasm](https://github.com/Decompollaborate/spimdisasm) (MIPS disassembler), [pycdlib](https://github.com/clalancette/pycdlib) (disc image reader).
* Decompile loop: [m2c](https://github.com/matt-kempster/m2c) (MIPS to C), [maspsx](https://github.com/mkst/maspsx) (assembler), [asm-differ](https://github.com/simonlindholm/asm-differ) (match check), [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) (variant search), [coddog](https://github.com/ethteck/coddog) (finding functions that look alike), [mapfile_parser](https://github.com/Decompollaborate/mapfile_parser) (map / symbol lookup).

## Quickstart

Put a dump of the retail USA disc in `rom/` as `Final Fantasy Tactics (USA).bin` + `Final Fantasy Tactics (USA).cue`, then:

```sh
make deps        # tools/.venv + splat/m2c/maspsx/asm-differ via tools/get_tools.sh
make toolchain   # GCC 2.6.0-psx + binutils under tools/toolchain/
make extract     # rom/Final Fantasy Tactics (USA).{bin,cue} -> rom/extracted/baserom/
make split       # splat -> per-function asm stubs under rom/extracted/asm/
make build       # src/*.c -> exe
make compare     # byte-diff the rebuilt exe against the baserom
```

Blob targets take a `BLOB=` prefix (see [Targets](#targets)).

## Verification

* `make compare` - the rebuilt exe vs. the baserom.
* `make diff FUNC=<func>` - instruction-level side-by-side for one function.
* `make finish FUNC=<func>` - swaps the stub for C, clean-builds, byte-compares, and runs the differ. Exits 0 only on a full byte match at score 0.

`make bin` patches the rebuilt exe (no other blob) into a copy of the retail image and SHA1-verifies the result against `config/disc_checksums.txt`, hard-failing on any mismatch.

## Targets

`BLOB=` scopes `split`, `build`, `compare`, `diff`, `show`, `decompile`, `finish`, `pick`, `cleanstubs`, `status`, `progress` and `clean` to one disc blob. Unset (or `BLOB=exe`) means the exe.

| Target             | `BLOB=`          | C units                               | Splat config                 |
| ------------------ | ---------------- | ------------------------------------- | ---------------------------- |
| SCUS_942.21        | _(default)_      | `src/main.c`, `main_2.c` … `main_5.c` | `config/boot.yaml`           |
| BATTLE             | `battle`         | `src/blobs/battle/battle*.c`          | `config/blobs/battle.yaml`   |
| OPEN               | `open`           | `src/blobs/open/open*.c`              | `config/blobs/open.yaml`     |
| WLDCORE            | `wldcore`        | `src/blobs/wldcore/wldcore*.c`        | `config/blobs/wldcore.yaml`  |
| WORLD              | `world`          | `src/blobs/world/world*.c`            | `config/blobs/world.yaml`    |
| EFFECT (110 files) | `effect_E000` …  | `src/blobs/effect/E*.c`               | `config/blobs/effect/*.yaml` |
| EVENT (11 files)   | `event_ATTACK` … | `src/blobs/event/*.c`                 | `config/blobs/event/*.yaml`  |

```sh
make BLOB=open split build compare
make BLOB=world finish FUNC=func_800E1F7C
```

`BLOB=` is always slash-free: family folders map to `<family>_<stem>` (`config/blobs/effect/E000.yaml` → `BLOB=effect_E000`). `make bin` is the only target that refuses a `BLOB=`.

## Commands

```sh
make status                # progress + the easiest next stub
make decompile FUNC=<func> # m2c the stub to C (read-only)
make finish FUNC=<func>    # stub -> C swap, clean build, compare, differ
make progress              # regenerate the Progress table below
```

`make decompile` prints the m2c output plus the exact `INCLUDE_ASM(...)` line in the matching `src/<segment>.c` unit to replace with real C89. `make finish` pre-flights (stub exists, C definition present) before deleting anything.

| Target                              | Does                                                           |
| ----------------------------------- | -------------------------------------------------------------- |
| `make pick`                         | list the 5 easiest remaining stubs                             |
| `make cleanstubs [SEG=main_4]`      | stubs that are cleanly decompilable (no embedded rodata)       |
| `make show FUNC=<f>`                | print the raw asm stub                                         |
| `make diff FUNC=<f>`                | asm-differ side-by-side for one function                       |
| `make context`                      | regenerate `build/ctx.c` (m2c type context) after header edits |
| `make permute FUNC=<f>`             | brute-force C variants via decomp-permuter                     |
| `make variants FUNC=<f>`            | structured variant matrix, scored by byte-diff                 |
| `make rtl FUNC=<f>`                 | GCC 2.6 RTL pass dumps + differ rows                           |
| `make format` / `make check-format` | `clang-format` over `src/` + `include/`                        |
| `make bin`                          | reassemble a bootable `fft.bin`                                |
| `make clean [BLOB=<b>]`             | full rebuild (blob-scoped)                                     |

## Layout

* Edit: `src/`, `include/`, `config/`, `docs/`.
* Generated, git-ignored, never hand-edited: `rom/` (disc, `baserom/`, split asm stubs), `build/` (objects, exe, `ctx.c`, `progress.json`), `output/` (permuter scratch).

## Docs

| Read this                                                          | When                                                |
| ------------------------------------------------------------------ | --------------------------------------------------- |
| [docs/PERM_TRICKS.md](docs/PERM_TRICKS.md)                         | decomp-permuter workflows, register-pin tricks      |
| [docs/PSYQ_COMPILE_FLAGS.md](docs/PSYQ_COMPILE_FLAGS.md)           | evidence for the `-O2 -G0 -mgp32` pin               |
| [docs/PSX_REFERENCE.md](docs/PSX_REFERENCE.md)                     | PSX hardware, PSYQ toolchain, EXE/disc/blob formats |
| [docs/MIPS_ASSEMBLY_REFERENCE.md](docs/MIPS_ASSEMBLY_REFERENCE.md) | MIPS I + COP2 (GTE) instruction reference           |

## Hard tails

Seems that not every function is representable in C, so `config/hard_tails.txt` is the registry for those, one line with cause each, covering structural thunks (crt0, BIOS thunk families, trampolines, jtbl-align divergence), `%gp_rel` allocator stubs, and the COP2/LIBGTE library. The picker excludes them from default lists.

## Progress

EXE is "almost" done, with PSYQ functions being intentionally skipped and excluded from progress. Most of the work left is in the `BATTLE.BIN`, which is scary to just look at.

<!-- PROGRESS:START -->

| Target | Functions |
| --- | ---: |
| SCUS_942.21 | 639 / 684 (93.42%) |
| BATTLE | 724 / 4,429 (16.35%) |
| OPEN | 117 / 169 (69.23%) |
| WLDCORE | 332 / 452 (73.45%) |
| WORLD | 676 / 1,098 (61.57%) |
| EFFECT (110 files) | 29 / 146 (19.86%) |
| EVENT (11 files) | 538 / 772 (69.69%) |

_SCUS_942.21: 105 tagged `INCLUDE_PSYQ` stubs (35,424 bytes) are SDK bytes and not counted above._

_SCUS_942.21: 2 handwritten LIBGTE stubs (288 bytes) are never-decompiled lib asm (`config/hard_tails.txt`) and not counted above._

_BATTLE: 9 handwritten LIBGTE stubs (6,264 bytes) are never-decompiled lib asm (`config/hard_tails.txt`) and not counted above._

_EFFECT: 64 handwritten LIBGTE stubs (408,908 bytes) are never-decompiled lib asm (`config/hard_tails.txt`) and not counted above._

_EFFECT: aggregates 110 per-file blob targets (`config/blobs/effect/*.yaml`, one splat config per binary); per-file detail: `build/blobs/effect_*/progress.json`._

_EVENT: aggregates 11 per-file blob targets (`config/blobs/event/*.yaml`, one splat config per binary); per-file detail: `build/blobs/event_*/progress.json`._

_One signal per target: function counts via `symbols` - matched C definitions in the target's `src/*.c` units (applied names resolved through the link map) vs remaining `func_*` stubs, minus `INCLUDE_PSYQ` SDK stubs, minus handwritten COP2/GTE lib stubs; `D_*` nop pads excluded. No build or link map required (byte progress was dropped: coddog already searches by size). Per-segment detail: `make status` / progress `--verbose`; machine readable: `build/progress.json` + `build/blobs/<blob>/progress.json`._

<!-- PROGRESS:END -->

## Disclaimer

This is an independent, non-commercial reverse-engineering project for research and preservation.

It is not endorsed by, affiliated with, or sponsored by Square Co., Ltd. / SquareSoft, Square Enix or Sony Computer Entertainment.

Final Fantasy Tactics (1997 tactical RPG developed by Square for PlayStation, released in North America in 1998 by Sony Computer Entertainment), Final Fantasy, PlayStation, and all related assets are trademarks / copyright of their respective owners.

This repo stores no game data: no disc image, music, graphics, you must provide your own retail USA dump. Do not use this to play without owning the game.
