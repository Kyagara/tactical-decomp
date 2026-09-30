# tactical-recomp

Static recompilation of **Final Fantasy Tactics** (`SCUS_942.21`) built on [psxrecomp](https://github.com/mstan/psxrecomp) and [recomp-ui](https://github.com/RetroPortingToolKit/recomp-ui).

The decomp's verified address map supplies the recompiler's function seeds, and its names are catalogued for future host hooks. It reads the same disc dump the decomp uses (`../rom/`), staged for itself into `disc/`.

## Credits

For the recomp tooling:

- Recompiler: [psxrecomp](https://github.com/mstan/psxrecomp) (static MIPS to C recompiler) - pinned via `framework_pins.txt`.
- Launcher / settings UI: [recomp-ui](https://github.com/RetroPortingToolKit/recomp-ui) (shared Dear ImGui launcher + in-game overlay).
- BIOS: [OpenBIOS](https://github.com/grumpycoders/pcsx-redux) (PCSX-Redux project's from-scratch MIT-licensed PS1 BIOS, `src/mips/openbios`) - default and only linked BIOS, no retail BIOS redistributed.
- Inputs: this repo's own decomp (`config/boot.yaml`, `symbol_addrs.txt`, `applied_names.txt`) via `recomp/tools/import_decomp.py` to `seeds/`, `symbols.toml`.

## Relationship to the decomp

One-way link, decomp ground truth -> recomp inputs. Nothing builds against `../src/`:

```
config/symbol_addrs.txt      ─┐
config/applied_names.txt      ├─► import_decomp.py ─► seeds/ghidra_funcs.txt
config/psyq_matches.csv       │                       symbols.toml (+ game.toml block)
config/hard_tails.txt        ─┘                               │
                                                              ▼
                                              sync_symbols.py ─► psx_symbols.h
```

Ranges frozen from `config/boot.yaml`. `symbols.toml` stays `emit = false` until safe for host hooks (see `psxrecomp/docs/SYMBOLS.md`). `game.toml` gains a `# --- decomp reference ---` block plus `overlay_region_floor = "0x80060000"`.

```sh
tools/.venv/bin/python recomp/tools/import_decomp.py           # rewrite the three outputs
tools/.venv/bin/python recomp/tools/import_decomp.py --check   # drift gate
cd recomp && python3 tools/sync_symbols.py                     # symbols.toml -> psx_symbols.h
```

Exe only. Blob funcs (`config/blobs/`, incl. `effect/` + `event/` per-file) are excluded and stay overlay-eligible.

## Pins & patches

`framework_pins.txt` vs submodule gitlinks; `CMakeLists.txt` aborts on drift. Fix with `git submodule update --init recomp/psxrecomp`; push URL is set to `no-push` to avoid accidental push.

One game-owned patch: `patches/psxrecomp/44a45d3c-spu-pmon.patch` applies PMON (`0x1F801D90/92`) in SPU synthesis (upstream parses it for status only). Applied lazily at configure (marker + `git apply --check`); retire when upstream handles PMON, rebase on pin bump.

## Config map

| Path                                                     | Owner                                    | What it is                        |
| -------------------------------------------------------- | ---------------------------------------- | --------------------------------- |
| `game.toml`                                              | hand-edited (importer appends one block) | runtime + recompiler config       |
| `game_options.toml`                                      | hand-edited                              | OPTION persistence, no rows yet   |
| `catalog_identity.json`                                  | hand-edited                              | catalog metadata, disc digests    |
| `.recomp.json`                                           | hand-edited                              | project manifest                  |
| `framework_pins.txt`                                     | hand-edited                              | framework SHAs, enforced by CMake |
| `codegen_setup.c` / `.h`                                 | hand-edited                              | codegen host title config         |
| `CMakeLists.txt`                                         | hand-edited                              | pins, patches, runtime wiring     |
| `patches/psxrecomp/*.patch`                              | hand-edited                              | game-owned framework patches      |
| `mods/preloaded/`                                        | hand-edited                              | mod catalog                       |
| `scripts/package_setup_release.sh`                       | hand-edited                              | setup-host packager wrapper       |
| `seeds/ghidra_funcs.txt`                                 | **generated** by `import_decomp.py`      | exe seeds                         |
| `symbols.toml`                                           | **generated** by `import_decomp.py`      | name map                          |
| `psx_symbols.h`                                          | **generated** by `sync_symbols.py`       | `PSX_FN_*` hooks                  |
| `disc_probe.json`                                        | probe output                             | raw disc probe                    |
| `psxrecomp/`, `recomp-ui/`                               | submodules                               | framework + launcher              |
| `generated/`, `build-*/`, `disc/`, `analysis/`, `saves/` | generated, gitignored                    | output, builds, media, scratch    |

`generated/SCUS_942.21_dispatch.c` is the `GEN_MARKER` that generation has happened.

## Status

With very little time spent testing, the game seems to be playable.

Issues:

- Visual glitch when the opening starts playing after not moving the cursor in the title menu.
- The 'typing' sound effect when a character talks is inconsistent, not playing in the Orbonne Monastery, to then playing in the first battle but not sounding the same as the original.

## Quick start (dev)

Run from `recomp/`. The disc dump is shared with the decomp in `../rom/`.

```bash
git submodule update --init --recursive
./psxrecomp/tools/ci/build_emitters.sh
python3 psxrecomp/psxrecomp_cli.py generate \
  --config game.toml --project-root . --disc "../rom/Final Fantasy Tactics (USA).cue"
cmake -S . -B build-release -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build-release --target psx-runtime
```

The product lands at `build-release/tactical-recomp` and reads `game.toml` from beside it. Re-run `generate` after changing the disc, the seeds or the `overlay_region_floor`; a bare `cmake --build` will not pick that up.

To pull fresh decomp knowledge into the seeds and symbol map, run the importer from the parent repo first - see [Relationship to the decomp](#relationship-to-the-decomp).

Zip prefix for CI artifacts: `tactical-recomp`.

## Disclaimer

This is an independent, non-commercial reverse-engineering project for research and preservation.

It is not endorsed by, affiliated with, or sponsored by Square Co., Ltd. / SquareSoft, Square Enix or Sony Computer Entertainment.

Final Fantasy Tactics (1997 tactical RPG developed by Square for PlayStation, released in North America in 1998 by Sony Computer Entertainment), Final Fantasy, PlayStation, and all related assets are trademarks / copyright of their respective owners.

This repo stores no game data: no disc image, music, graphics, you must provide your own retail USA dump. Do not use this to play without owning the game.
