#ifndef COMMON_H
#define COMMON_H

#ifndef INCLUDE_ASM_USE_MACRO_INC
#define INCLUDE_ASM_USE_MACRO_INC 1
#endif

#include "include_asm.h"

/* Same as INCLUDE_ASM. */
#ifndef INCLUDE_PSYQ
#define INCLUDE_PSYQ(FOLDER, NAME) INCLUDE_ASM(FOLDER, NAME)
#endif

/* Fixed-width types. These match PSYQ GCC's model: int is 32-bit. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;
typedef volatile signed char vs8;
typedef volatile signed short vs16;
typedef volatile signed int vs32;

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define TRUE 1
#define FALSE 0

/* Dead-tail preserver for disc blobs.
 * Some blob functions carry unreachable words (a stale lui/lX pair) after
 * their jr+nop that C cannot emit. This keeps the words symbolic with the
 * assembler state contained (push/pop); the surrounding C must otherwise be
 * score-0. Whole-function asm stays banned. reg is the MIPS register number
 * (2 = v0, 3 = v1, 4 = a0) matching the oracle's dead words. */
#define DEAD_TAIL_LOAD(reg, sym, op) __asm__(                                     \
    ".set push\n.set noreorder\n"                                                 \
    "lui $" #reg ", %hi(" #sym ")\n" #op " $" #reg ", %lo(" #sym ")($" #reg ")\n" \
    ".set pop\n");
#define DEAD_TAIL_LW(reg, sym) DEAD_TAIL_LOAD(reg, sym, lw)
#define DEAD_TAIL_LH(reg, sym) DEAD_TAIL_LOAD(reg, sym, lh)
#define DEAD_TAIL_LHU(reg, sym) DEAD_TAIL_LOAD(reg, sym, lhu)

/* Useful byte-access helpers for data definitions. Kept minimal for now. */
#define ARRAY_COUNT(x) (sizeof(x) / sizeof((x)[0]))

/* Compiler fence macros: zero bytes emitted. These spellings previously
 * appeared as raw __asm__ at ~500 sites; the macros expand to the
 * identical string so matching is unaffected. Volatile vs non-volatile
 * is NOT interchangeable (volatile pins scheduling), so both families are
 * provided: use the VOL variant iff the original site was volatile. */
#define MEMORY_BARRIER() __asm__ volatile("" ::: "memory")
#define SCHED_BARRIER() __asm__ volatile("")
#define KEEP(x) __asm__ volatile("" : "=r"(x) : "0"(x))
#define KEEP_NOVOL(x) __asm__("" : "=r"(x) : "0"(x))
#define USE(x) __asm__ volatile("" : : "r"(x))
#define USE_NOVOL(x) __asm__("" : : "r"(x))
#define USE2(x, y) __asm__ volatile("" : : "r"(x), "r"(y))
#define KEEP_WITH(x, y) __asm__ volatile("" : "=r"(x) : "0"(x), "r"(y))
#define KEEP_WITH_NOVOL(x, y) __asm__("" : "=r"(x) : "0"(x), "r"(y))
#define FORCE_REG(x) __asm__ volatile("" : "=r"(x))
#define FORCE_REG_NOVOL(x) __asm__("" : "=r"(x))
#define ASM_NOP() __asm__ volatile("nop")
#define ASM_NOP2() __asm__ volatile("nop\n\tnop")
#define ASM_NOP_NOVOL() __asm__("nop")

/* Tail-call jump macros: these DO emit bytes (j + delay slot) and exist
 * because GCC 2.6 will not fuse a call+store into a delay slot from plain
 * C. One-off delay-slot shapes (lui/lbu chains, multi-instr sequences)
 * stay as raw __asm__ at their sites. */
#define TAIL_JUMP(sym) __asm__ volatile("j " #sym)
#define TAIL_JUMP_MEM(sym) __asm__ volatile("j " #sym ::: "memory")
#define TAIL_JUMP_NOP(sym) __asm__ volatile(".set\tnoreorder\n\tj " #sym "\n\tnop\n\t.set\treorder")
#define TAIL_JUMP_SB_1C(sym, val, base, tmp) __asm__ volatile(".set\tnoreorder\n\tj " #sym "\n\tsb %0,0x1C(%1)\n\t.set\treorder" ::"r"(val), "r"(base), "r"(tmp))
#define TAIL_JUMP_SB_24(sym, val, base, tmp) __asm__ volatile(".set\tnoreorder\n\tj " #sym "\n\tsb %0,0x24(%1)\n\t.set\treorder" ::"r"(val), "r"(base), "r"(tmp))

#include "fft_battle.h"
#include "fft_save.h"
#include "fft_sound.h"
#include "fft_gpu.h"
#include "fft_effect.h"

#endif
