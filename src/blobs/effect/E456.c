#include "common.h"

extern u8 D_801BF02C[];
extern void func_800F0BE0(s32, s32, s32, s32);
extern void func_80093144(void);

void func_801C2500(s16 arg0, s32 arg1) {
    u8 *s0;
    u8 *off;
    s32 v1;

    off = D_801BF02C + arg0 * 0xF8;
    s0 = off + arg1;
    v1 = s0[0x22];
    if (v1 == 1)
        goto callp4;
    if (v1 < 2)
        goto epi;
    SCHED_BARRIER();
    if (v1 == 2)
        goto callp1;
    if (v1 == 3)
        goto store0;
    TAIL_JUMP_NOP(0x801C2598);
callp4:
    func_800F0BE0(0x9A, 1, 1, 1);
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C2598\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
callp1:
    __asm__ volatile(
        ".set\tnoreorder\n\tjal 0x801433E8\n\tnop\n\t.set\treorder");
    TAIL_JUMP_NOP(0x801C2598);
store0:
    s0[0x22] = 0;
epi:;
}

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E456", func_801C25AC);

void func_801C3118(s16 arg0, s32 arg1) {
    u8 *s0;
    u8 *off;
    s32 v1;

    off = D_801BF02C + arg0 * 0xF8;
    s0 = off + arg1;
    v1 = s0[0x22];
    if (v1 == 1)
        goto callp;
    if (v1 < 2)
        goto epi;
    SCHED_BARRIER();
    if (v1 == 2)
        goto epi;
    SCHED_BARRIER();
    if (v1 == 3)
        goto store0;
    TAIL_JUMP_NOP(0x801C3198);
callp:
    func_80093144();
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C3198\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}

extern void func_80093118(void);

void func_801C31AC(s16 arg0, s32 arg1) {
    u8 *s0;
    u8 *off;
    s32 v1;

    off = D_801BF02C + arg0 * 0xF8;
    s0 = off + arg1;
    v1 = s0[0x22];
    if (v1 == 1)
        goto callp;
    if (v1 < 2)
        goto epi;
    SCHED_BARRIER();
    if (v1 == 2)
        goto epi;
    SCHED_BARRIER();
    if (v1 == 3)
        goto store0;
    TAIL_JUMP_NOP(0x801C322C);
callp:
    func_80093118();
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C322C\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}
