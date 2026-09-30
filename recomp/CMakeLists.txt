cmake_minimum_required(VERSION 3.20)
set(PSXRECOMP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/psxrecomp" CACHE PATH
    "Path to psxrecomp")
if(NOT EXISTS "${PSXRECOMP_ROOT}/runtime/runtime.cmake")
    message(FATAL_ERROR
        "PSXRecomp runtime is missing: ${PSXRECOMP_ROOT}/runtime/runtime.cmake\n"
        "This project expects the psxrecomp framework checkout at ${PSXRECOMP_ROOT}.\n"
        "Run: git submodule update --init --recursive\n"
        "If psxrecomp/ is not a submodule, set -DPSXRECOMP_ROOT=<path-to-psxrecomp>.")
endif()

project(tactical-recomp LANGUAGES C CXX)

# --- Opt-in product surfaces (OFF by default in the framework) -------------
# Scaffold prompts / flags fill these. Without recomp-ui, PSX_RECOMP_UI is OFF.
# Setup-host CI requires WIZARD_CMAKE_BLOCK / ENABLE_SETUP_WIZARD (FORCE_SETUP_HOST
# alone does not open first-run / Generate & rebuild).
# recomp-ui submodule present (PSX_RECOMP_UI defaults ON).
# Full netplay UI — enable after adding recomp-ui + testing:
# if(EXISTS "${PSXRECOMP_ROOT}/lib/recomp-net/CMakeLists.txt")
#     set(PSX_NETPLAY ON CACHE BOOL "…" FORCE)
# endif()
# First-run setup wizard — enable after testing:
# set(PSX_SETUP_WIZARD ON CACHE BOOL "…" FORCE)

# FFT: OpenBIOS only — never link the retail BIOS backend. Only
# recomp/psxrecomp/bios/OpenBIOS.toml is ever regenerated; no retail dump
# is required or accepted.
set(PSXRECOMP_BIOS_STEMS "OpenBIOS" CACHE STRING
    "Recompiled BIOS stems to link (FFT: OpenBIOS only)" FORCE)

# Frozen framework + game-owned patches (recomp/patches/).
# psxrecomp tracks no branch (.gitmodules pins the gitlink only); the exact
# commit is enforced here against recomp/framework_pins.txt and configure
# fails closed on drift. Patches in recomp/patches/psxrecomp/ apply to the
# submodule working tree idempotently (marker grep + git apply --check) —
# the same lazy-apply idiom as tools/get_tools.sh (maspsx) and tools/coddog.
find_package(Git QUIET)
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/framework_pins.txt" _FFT_PINS_TXT)
set(_FFT_PSXRECOMP_PIN "")
string(REGEX MATCH "psxrecomp=[0-9a-f]+ \\(([0-9a-f]+)\\)" _FFT_PIN_MATCH "${_FFT_PINS_TXT}")
if(_FFT_PIN_MATCH)
    set(_FFT_PSXRECOMP_PIN "${CMAKE_MATCH_1}")
endif()
unset(_FFT_PINS_TXT)
unset(_FFT_PIN_MATCH)
if(NOT _FFT_PSXRECOMP_PIN)
    message(FATAL_ERROR "FFT: cannot parse psxrecomp pin from recomp/framework_pins.txt")
endif()
if(GIT_FOUND AND EXISTS "${PSXRECOMP_ROOT}/.git")
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C "${PSXRECOMP_ROOT}" rev-parse HEAD
        OUTPUT_VARIABLE _FFT_PSXRECOMP_HEAD
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET)
    if(_FFT_PSXRECOMP_HEAD AND NOT _FFT_PSXRECOMP_HEAD STREQUAL _FFT_PSXRECOMP_PIN)
        message(FATAL_ERROR
            "FFT: psxrecomp pin mismatch: checkout is ${_FFT_PSXRECOMP_HEAD}, "
            "want ${_FFT_PSXRECOMP_PIN} (recomp/framework_pins.txt). "
            "Run: git submodule update --init recomp/psxrecomp")
    endif()
    unset(_FFT_PSXRECOMP_HEAD)
    # Belt-and-braces, mirroring tools/get_tools.sh: never push the locally
    # patched framework state upstream from this checkout.
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C "${PSXRECOMP_ROOT}" remote set-url --push origin no-push
        ERROR_QUIET)
endif()
# PMON pitch-modulation patch for the pinned runtime/src/spu.c (see the patch
# header for provenance and retire conditions). Skipped when already applied.
set(_FFT_SPU_PATCH "${CMAKE_CURRENT_SOURCE_DIR}/patches/psxrecomp/0ffab1ce-spu-pmon.patch")
file(READ "${PSXRECOMP_ROOT}/runtime/src/spu.c" _FFT_SPU_SRC)
string(FIND "${_FFT_SPU_SRC}" "s_pmon_prev_out" _FFT_SPU_PATCHED)
unset(_FFT_SPU_SRC)
if(_FFT_SPU_PATCHED EQUAL -1)
    if(NOT GIT_FOUND)
        message(FATAL_ERROR
            "FFT: git is required to apply ${_FFT_SPU_PATCH} "
            "(spu.c under ${PSXRECOMP_ROOT} is unpatched). Install git and re-configure.")
    endif()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C "${PSXRECOMP_ROOT}" apply --check "${_FFT_SPU_PATCH}"
        RESULT_VARIABLE _FFT_SPU_CHECK)
    if(NOT _FFT_SPU_CHECK EQUAL 0)
        message(FATAL_ERROR
            "FFT: ${_FFT_SPU_PATCH} does not apply cleanly against ${PSXRECOMP_ROOT} "
            "(pin drift? see recomp/framework_pins.txt).")
    endif()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C "${PSXRECOMP_ROOT}" apply "${_FFT_SPU_PATCH}"
        RESULT_VARIABLE _FFT_SPU_APPLY)
    if(NOT _FFT_SPU_APPLY EQUAL 0)
        message(FATAL_ERROR "FFT: failed to apply ${_FFT_SPU_PATCH}")
    endif()
    message(STATUS "FFT: applied spu PMON patch (recomp/patches/psxrecomp/)")
endif()
unset(_FFT_SPU_PATCHED)
unset(_FFT_SPU_CHECK)
unset(_FFT_SPU_APPLY)
unset(_FFT_SPU_PATCH)
include("${PSXRECOMP_ROOT}/runtime/runtime.cmake")

# This project's own mod catalog. The FRAMEWORK stages it -- together with its
# builtin psx.* packages -- into <exe-dir>/mods/bundled, and refuses to
# configure if a catalog exists here but is not declared. Never copy it by
# hand: five titles did, and framework 4cc04be3's rename of the staged
# directory broke all five silently (bead beads-eio.3.101).
set(PSX_PRELOADED_MODS "${CMAKE_CURRENT_SOURCE_DIR}/mods/preloaded")
if(NOT IS_DIRECTORY "${PSX_PRELOADED_MODS}")
    set(PSX_PRELOADED_MODS "NONE")
endif()

psxrecomp_add_game_runtime(psx-runtime
    PRELOADED_MODS_DIR "${PSX_PRELOADED_MODS}"
    # ENABLE_NETPLAY_IF_PRESENT
    # NETPLAY_LOBBY_URL
    # ENABLE_SETUP_WIZARD
    WINDOW_TITLE "tactical-recomp"
    # Pin the binary name: runtime.cmake otherwise derives it with
    # MAKE_C_IDENTIFIER(WINDOW_TITLE), which rewrites the hyphen to an
    # underscore (tactical_recomp). Codegen config, the release packager and
    # the setup host all key off the exe name, so pin it in one place.
    EXE_NAME "tactical-recomp"
    DEFAULT_GAME_CONFIG_PATH "game.toml"
    MAX_PLAYERS 1
    # LAUNCHER_BOXART "launcher_assets/img/boxart.tga" (join with
    # CMAKE_CURRENT_SOURCE_DIR when enabling)
    APP_ICON "${CMAKE_CURRENT_SOURCE_DIR}/assets/psxrecomp.ico"
    GEN_MARKER "generated/SCUS_942.21_dispatch.c"
    GEN_FULL_GLOB "generated/SCUS_942.21_full_*.c"
    CODEGEN_SETUP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/codegen_setup.c"
)

# Stage runtime configs next to the exe for direct build/ launches. Only copy
# files that exist — never fail POST_BUILD when game_options.toml is absent.
foreach(_PSX_RUNTIME_CONFIG game.toml game_options.toml)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${_PSX_RUNTIME_CONFIG}")
        add_custom_command(TARGET psx-runtime POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${CMAKE_CURRENT_SOURCE_DIR}/${_PSX_RUNTIME_CONFIG}"
                "$<TARGET_FILE_DIR:psx-runtime>/${_PSX_RUNTIME_CONFIG}"
            COMMENT "Staging ${_PSX_RUNTIME_CONFIG}"
            VERBATIM)
    endif()
endforeach()
