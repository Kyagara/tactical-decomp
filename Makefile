# Targets: deps toolchain extract split build compare diff context status
#   show decompile finish progress pick cleanstubs permute variants rtl
#   format check-format bin clean all (= split build compare).
#
# Blob scope (see docs/BLOB_PLAN.md): BLOB=<name> selects one disc blob
# (config/blobs/<name>.yaml) for split/build/compare/diff/show/decompile/
# finish/pick/cleanstubs/status/progress/clean. Default (empty) is the exe.
#
# Example: make BLOB=open split build compare
#
# Everything is repo-local: no sudo, no PATH edits, no global installs.

SHELL := /bin/bash

VENV       := tools/.venv
PY         := $(VENV)/bin/python
SPLAT      := $(VENV)/bin/splat

BLOB       ?=

ifeq ($(BLOB),)
CONFIG     := config/boot.yaml
else
CONFIG     := $(shell $(PY) tools/scripts/target.py config $(BLOB))
endif
ROMX       := rom/extracted
ifeq ($(BLOB),)
ASM        := $(ROMX)/asm
BUILD      := build
TARGET     := $(ROMX)/baserom/SCUS_942.21
OUT_EXE    := $(BUILD)/SCUS_942.21.exe
OUT_BIN    := $(BUILD)/SCUS_942.21.bin
LD_SCRIPT  := $(BUILD)/SCUS_942.21.ld
MAP_FILE   := $(ROMX)/baserom/SCUS_942.21.map
else
ASM        := $(shell $(PY) tools/scripts/target.py asm $(BLOB))
BUILD      := build/blobs/$(BLOB)
TARGET     := $(shell $(PY) tools/scripts/target.py oracle $(BLOB))
OUT_EXE    := $(BUILD)/$(BLOB).elf
OUT_BIN    := $(BUILD)/$(BLOB).bin
LD_SCRIPT  := $(BUILD)/$(BLOB).ld
MAP_FILE   := $(BUILD)/$(BLOB).map
endif

# --- MIPS cross tools (installed by `make toolchain`) ---
TOOLCHAIN  := tools/toolchain
MIPS_GCC   := $(TOOLCHAIN)/bin/mipsel-none-elf-gcc
MIPS_AS    := $(TOOLCHAIN)/bin/mipsel-none-elf-as
MIPS_LD    := $(TOOLCHAIN)/bin/mipsel-none-elf-ld
MIPS_OBJCOPY := $(TOOLCHAIN)/bin/mipsel-none-elf-objcopy
# maspsx mimics one ASPSX version's nop/expansion. Frozen per target like
# GCC_FLAGS: exe = default 2.34, blobs declare aspsx_version in yaml.
MASPSX     := tools/third_party/maspsx/maspsx.py
ASPSX_VER   := $(shell $(PY) tools/scripts/target.py aspsx $(BLOB))
MASPSX_FLAGS := $(if $(ASPSX_VER),--aspsx-version $(ASPSX_VER),)
GEN_SYMS   := $(PY) tools/scripts/gen_undefined_syms.py

# -W silences spimdisasm .ent noise (unbalanced .ent, .data trampolines).
AS_FLAGS   := -EL -Iinclude -W

# --- gcc -S flags. Frozen PSYQ-era set; `make clean` once if changed. ---
# Whole build is -EL (R3000A + EXE header are little-endian).
GCC_FLAGS  := -EL -mno-abicalls -mgp32 -fno-builtin -fno-common -G0 -O2 \
              -Iinclude -I. -S

# --- second compiler (Sony PSYQ-fork lineage: native FSF 2.7.2-psx) ---------
# OPEN.BIN's open_2 unit needs 2.7.2 trailing-store scheduling; same
# GCC_FLAGS/ASPSX, only cc1 differs. Extend FORK_SRCS if more TUs proven.
FORK_GCC   := $(TOOLCHAIN)/gcc-2.7.2-psx/bin/mipsel-none-elf-gcc
FORK_SRCS  := src/blobs/open/open_2.c
$(patsubst %.c,$(BUILD)/%.pre.s,$(FORK_SRCS)): MIPS_GCC := $(FORK_GCC)
$(patsubst %.c,$(BUILD)/%.pre.s,$(FORK_SRCS)): $(FORK_GCC)

# --- per-unit frame-pointer island (WORLD.BIN world_4) ----------------------
# That island kept the frame pointer; -O2 omits it and `alloca` is the only
# in-language trigger, so it lives in its own unit + gets -fno-omit-frame-pointer.
FP_C_SRCS  := src/blobs/world/world_4.c
FP_FLAGS   := -fno-omit-frame-pointer
$(patsubst %.c,$(BUILD)/%.pre.s,$(FP_C_SRCS)): EXTRA_GCC_FLAGS := $(FP_FLAGS)

# clang-format files (include_asm.h excluded: tooling rewrites it).
FORMAT_SRC := $(wildcard src/*.c) $(wildcard src/blobs/*/*.c) $(filter-out include/include_asm.h,$(wildcard include/*.h))

# Pick one function to diff:  make diff FUNC=func_80011BF4
FUNC       ?=

.PHONY: all deps toolchain extract split build build-blob-inner compare diff context status show decompile finish permute progress pick bin clean cleanstubs variants rtl format check-format


all: split build compare

## --- convenience ---
deps:
	python3 -m venv "$(VENV)"
	"$(PY)" -m pip install -r tools/requirements.txt
	./tools/get_tools.sh

## --- toolchain ---
toolchain:
	./tools/get_toolchain.sh

## --- disc extraction ---
# Retail dump filename is the disc's own name. ROM_CUE is the shell-quoted
# form (recipe); ROM_CUE_ESC / ROM_BIN_ESC escape the spaces so make reads
# each dump file as ONE prerequisite instead of splitting on whitespace.
DUMP_STEM   := Final Fantasy Tactics (USA)
ROM_CUE     := rom/$(DUMP_STEM).cue
ROM_BIN     := rom/$(DUMP_STEM).bin
ROM_CUE_ESC := rom/Final\ Fantasy\ Tactics\ (USA).cue
ROM_BIN_ESC := rom/Final\ Fantasy\ Tactics\ (USA).bin

# Alias for rom/extracted/data_map.json; re-runs when disc/tool changes.
$(ROMX)/data_map.json: $(ROM_CUE_ESC) $(ROM_BIN_ESC) tools/bin/extract_bin.py
	"$(PY)" tools/bin/extract_bin.py --cue "$(ROM_CUE)" \
		--out "$(ROMX)/baserom" --map $(ROMX)/data_map.json

extract: $(ROMX)/data_map.json

## --- splitting ---
# Stamp-gated splat re-run; also orders `make -j build` (split before compiles).
SPLIT_STAMP := $(BUILD)/.split.stamp
ifeq ($(BLOB),)
# Exe units mirror boot.yaml `c` subsegments (blob touches never re-split exe).
SPLIT_DEPS := $(CONFIG) config/symbol_addrs.txt $(wildcard src/main.c src/main_2.c src/main_3.c src/main_4.c src/main_5.c) \
	$(wildcard tools/scripts/symbols.py) tools/scripts/regen_psyq_stubs.py \
	tools/scripts/check_asm_macros.py
else
SPLIT_DEPS := $(CONFIG) $(shell $(PY) tools/scripts/target.py symfile $(BLOB)) \
	$(shell $(PY) tools/scripts/target.py usrcs $(BLOB)) \
	$(wildcard tools/scripts/symbols.py) $(wildcard tools/scripts/target.py) \
	tools/scripts/check_asm_macros.py
endif

$(SPLIT_STAMP): $(SPLIT_DEPS)
	@mkdir -p "$(BUILD)"
	"$(SPLAT)" split "$(CONFIG)"
ifeq ($(BLOB),)
	@"$(PY)" -c "import sys; sys.path.insert(0, 'tools/scripts'); import symbols; symbols.prune_stale_stubs()"
	@"$(PY)" tools/scripts/regen_psyq_stubs.py
else
	@"$(PY)" -c "import sys; sys.path.insert(0, 'tools/scripts'); import symbols, target; symbols.prune_stale_stubs(target=target.get_target('$(BLOB)'))"
endif
# splat would rewrite include_asm.h with an absolute path (parse_path resolves
# generated_asm_macros_directory against base_path), which is only valid on the
# machine that ran the split. Every splat config sets
# generate_asm_macros_files: False, so this is the belt-and-braces check.
	@"$(PY)" tools/scripts/check_asm_macros.py
# splat drops non-aligned data tails; re-append them for an exact link.
	@"$(PY)" tools/scripts/fix_trailing_data.py $(BLOB)
	@touch "$@"

split: $(SPLIT_STAMP)

## --- build ---
ifeq ($(BLOB),)
build: split build-dirs $(OUT_BIN)
else
BLOB_C_SRCS := $(shell $(PY) tools/scripts/target.py usrcs $(BLOB))
BLOB_C_OBJS := $(patsubst %.c,$(BUILD)/%.o,$(BLOB_C_SRCS))
BLOB_DATA_SRCS = $(foreach s,$(shell $(PY) tools/scripts/target.py dsegs $(BLOB)),$(ASM)/data/$(s).data.s)
BLOB_DATA_OBJS = $(patsubst $(ASM)/data/%.data.s,$(BUILD)/$(ASM)/data/%.data.o,$(BLOB_DATA_SRCS))
# Two-phase blob build: split first, then re-exec to pick up fresh data objs.
build: split
	@$(MAKE) --no-print-directory BLOB=$(BLOB) build-blob-inner
build-blob-inner: build-dirs $(OUT_BIN)
$(BLOB_C_OBJS): $(SPLIT_STAMP)
endif

# C pipeline: gcc -S -> maspsx -> as. Stem mirrors src tree. .o deps cover
# INCLUDE_ASM-included stubs; change GCC_FLAGS deliberately + `make clean` once.
MAIN_STUBS := $(wildcard $(ASM)/nonmatchings/main/*.s)
MAIN_2_STUBS := $(wildcard $(ASM)/nonmatchings/main_2/*.s)
MAIN_3_STUBS := $(wildcard $(ASM)/nonmatchings/main_3/*.s)
MAIN_4_STUBS := $(wildcard $(ASM)/nonmatchings/main_4/*.s)
MAIN_5_STUBS := $(wildcard $(ASM)/nonmatchings/main_5/*.s)

$(BUILD)/%.pre.s: %.c include/common.h include/include_asm.h $(MIPS_GCC)
	@mkdir -p "$(dir $@)"
	"$(MIPS_GCC)" $(GCC_FLAGS) $(EXTRA_GCC_FLAGS) -o "$@" "$<"

# maspsx prefers stdin over its file arg; pin stdin so `make < list` is safe.
$(BUILD)/%.s: $(BUILD)/%.pre.s $(MASPSX)
	"$(PY)" "$(MASPSX)" $(MASPSX_FLAGS) "$<" > "$@" < /dev/null

$(BUILD)/%.o: $(BUILD)/%.s include/macro.inc
	"$(MIPS_AS)" $(AS_FLAGS) -o "$@" "$<"

$(BUILD)/src/main.o: $(MAIN_STUBS) $(SPLIT_STAMP)
$(BUILD)/src/main_2.o: $(MAIN_2_STUBS) $(SPLIT_STAMP)
$(BUILD)/src/main_3.o: $(MAIN_3_STUBS) $(SPLIT_STAMP)
$(BUILD)/src/main_4.o: $(MAIN_4_STUBS) $(SPLIT_STAMP)
$(BUILD)/src/main_5.o: $(MAIN_5_STUBS) $(SPLIT_STAMP)

# Keep gcc/maspsx intermediates (pattern rules auto-delete them otherwise).
.SECONDARY: \
	$(BUILD)/src/main.pre.s \
	$(BUILD)/src/main_2.pre.s \
	$(BUILD)/src/main_3.pre.s \
	$(BUILD)/src/main_4.pre.s \
	$(BUILD)/src/main_5.pre.s \
	$(BUILD)/src/main.s \
	$(BUILD)/src/main_2.s \
	$(BUILD)/src/main_3.s \
	$(BUILD)/src/main_4.s \
	$(BUILD)/src/main_5.s
ifeq ($(BLOB),)
else
BLOB_INTERMEDIATES := $(patsubst %.c,$(BUILD)/%.pre.s,$(BLOB_C_SRCS)) \
	$(patsubst %.c,$(BUILD)/%.s,$(BLOB_C_SRCS))
.SECONDARY: $(BLOB_INTERMEDIATES)
endif

# split asm/data objects (paths mirror splat's ld script).
$(BUILD)/$(ASM)/header.o: $(ASM)/header.s
	@mkdir -p "$(dir $@)"
	"$(MIPS_AS)" $(AS_FLAGS) -o "$@" "$<"

$(BUILD)/$(ASM)/data/%.data.o: $(ASM)/data/%.data.s
	@mkdir -p "$(dir $@)"
	"$(MIPS_AS)" $(AS_FLAGS) -o "$@" "$<"

# Synthesized --defsym table for stub-referenced D_*/func_*.
$(BUILD)/symbols.def: $(GEN_SYMS) $(BUILD)/undefined_syms_auto.txt
	@mkdir -p "$(dir $@)"
	$(GEN_SYMS)$(if $(BLOB), --blob $(BLOB))

# Link + flatten to the oracle binary; -Map feeds asm-differ.
ifeq ($(BLOB),)
$(OUT_EXE): $(LD_SCRIPT) $(BUILD)/$(ASM)/header.o $(BUILD)/src/main.o $(BUILD)/src/main_2.o $(BUILD)/src/main_3.o $(BUILD)/src/main_4.o $(BUILD)/src/main_5.o $(BUILD)/$(ASM)/data/trampolines.data.o $(BUILD)/$(ASM)/data/post_tramp_tail.data.o $(BUILD)/$(ASM)/data/main_data.data.o $(BUILD)/$(ASM)/data/gap_ab.data.o $(BUILD)/$(ASM)/data/tail_b.data.o $(BUILD)/symbols.def
	"$(MIPS_LD)" -EL -T "$(LD_SCRIPT)" -Map "$(MAP_FILE)" \
		"$(BUILD)/$(ASM)/header.o" "$(BUILD)/src/main.o" "$(BUILD)/src/main_2.o" "$(BUILD)/src/main_3.o" "$(BUILD)/src/main_4.o" "$(BUILD)/src/main_5.o" \
		"$(BUILD)/$(ASM)/data/trampolines.data.o" "$(BUILD)/$(ASM)/data/post_tramp_tail.data.o" "$(BUILD)/$(ASM)/data/main_data.data.o" "$(BUILD)/$(ASM)/data/gap_ab.data.o" "$(BUILD)/$(ASM)/data/tail_b.data.o" \
		@$(BUILD)/symbols.def -o "$@"
else
$(OUT_EXE): $(LD_SCRIPT) $(BLOB_C_OBJS) $(BLOB_DATA_OBJS) $(BUILD)/symbols.def
	"$(MIPS_LD)" -EL -T "$(LD_SCRIPT)" -Map "$(MAP_FILE)" \
		$(BLOB_C_OBJS) $(BLOB_DATA_OBJS) \
		@$(BUILD)/symbols.def -o "$@"
endif

$(OUT_BIN): $(OUT_EXE)
	"$(MIPS_OBJCOPY)" -O binary "$<" "$@"

build-dirs:
	mkdir -p "$(BUILD)"

## --- verification ---
compare: build $(OUT_BIN)
	@cmp "$(TARGET)" "$(OUT_BIN)" && \
		echo "MATCH: build is byte-identical to $(TARGET)" || \
		{ echo "MISMATCH: $(TARGET) vs $(OUT_BIN)"; exit 1; }

# FUNC is required; map comes from the link above.
diff: build
	@if [ -z "$(FUNC)" ]; then echo "usage: make diff FUNC=func_8001E9CC"; exit 1; fi
	BLOB="$(BLOB)" PYTHONDONTWRITEBYTECODE=1 "$(PY)" tools/third_party/asm-differ/diff.py "$(FUNC)"

## --- progress / picking ---
progress:
	"$(PY)" tools/scripts/progress.py $(if $(BLOB),--blob $(BLOB),--all)

pick:
	"$(PY)" tools/scripts/pick_function.py --list 5 $(if $(BLOB),--blob $(BLOB))

# Clean stubs: single jr ra, standard tail, no rodata. SEG=... restricts.
# PSYQ stubs excluded by default (--include-psyq/--psyq-only to audit).
cleanstubs:
	"$(PY)" tools/scripts/pick_function.py --clean $(if $(SEG),--segment $(SEG)) $(if $(BLOB),--blob $(BLOB))

status:
	@echo "ASPSX: exe=default(2.34) $(shell $(PY) -c "import sys; sys.path.insert(0,'tools/scripts'); import target; print(' '.join('%s=%s' % (b, target.get_target(b).aspsx_version or 'default(2.34)') for b in target.list_blobs()))")"
	"$(PY)" tools/scripts/progress.py $(if $(BLOB),--blob $(BLOB),--all)
	"$(PY)" tools/scripts/pick_function.py --list 5 $(if $(BLOB),--blob $(BLOB))

# Variant matrix for one stub (rotations + widths + variants/, byte-scored).
variants:
	"$(PY)" tools/scripts/variant_loop.py $(FUNC) $(if $(VARGS),$(VARGS))

# GCC 2.6 RTL dumps + asm-differ rows for one stub.
rtl:
	"$(PY)" tools/scripts/variant_loop.py $(FUNC) --rtl $(if $(BLOB),--blob $(BLOB),) $(if $(VARGS),$(VARGS))

# clang-format (struct expansion only, never rewraps long lines).
format:
	clang-format -i $(FORMAT_SRC)

check-format:
	@clang-format --dry-run --Werror $(FORMAT_SRC)

context:
	"$(PY)" tools/scripts/m2ctx.py

show:
	@if [ -z "$(FUNC)" ]; then echo "usage: make show FUNC=func_8001E9CC"; exit 1; fi
	@cat $(ASM)/nonmatchings/*/$(FUNC).s 2>/dev/null || { echo "no stub for $(FUNC)"; exit 1; }

decompile:
	@if [ -z "$(FUNC)" ]; then echo "usage: make decompile FUNC=func_8001E9CC"; exit 1; fi
	"$(PY)" tools/scripts/workflow.py decompile "$(FUNC)" $(if $(BLOB),--blob $(BLOB))

# decomp-permuter brute force (background; ARGS="--fg" for foreground).
permute:
	@if [ -z "$(FUNC)" ]; then echo "usage: make permute FUNC=func_8001E9CC"; exit 1; fi
	"$(PY)" tools/scripts/permute.py setup $(if $(BLOB),--blob $(BLOB)) "$(FUNC)" $(ARGS)

finish:
	@if [ -z "$(FUNC)" ]; then echo "usage: make finish FUNC=func_8001E9CC"; exit 1; fi
	"$(PY)" tools/scripts/workflow.py finish "$(FUNC)" $(if $(BLOB),--blob $(BLOB))

## --- emulator disc ---
# Bootable fft.bin from retail image + rebuilt exe (exe-only).
bin: build $(ROMX)/data_map.json
	@if [ -n "$(BLOB)" ]; then echo "bin is exe-only (reassembles SCUS_942.21 sectors)"; exit 1; fi
	"$(PY)" tools/bin/build_bin.py

clean:
ifeq ($(BLOB),)
	rm -rf "$(BUILD)" "$(ASM)"
else
# Blob-scoped: family blobs share one asm_path, so only wipe this blob's units.
	rm -rf "$(BUILD)"
	for u in $(shell $(PY) tools/scripts/target.py units $(BLOB)); do rm -rf "$(ASM)/nonmatchings/$$u"; done
	for d in $(shell $(PY) tools/scripts/target.py dsegs $(BLOB)); do rm -f "$(ASM)/data/$$d.data.s"; done
endif
