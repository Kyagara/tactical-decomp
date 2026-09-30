#include "common.h"

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E453", func_801C2500);

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E453", func_801C46DC);

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E453", func_801C5E58);

extern u8 D_801BF02C[];
extern void func_800F0BE0(s32, s32, s32, s32);

void func_801C69C4(s16 arg0, s32 arg1) {
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
    TAIL_JUMP_NOP(0x801C6AF0);
callp:
    func_800F0BE0(0x98, 1, 1, 1);
    func_800F0BE0(0x80, 1, 3, 1);
    func_800F0BE0(0x80, 2, 3, 1);
    func_800F0BE0(0x80, 3, 3, 1);
    func_800F0BE0(0x80, 4, 3, 1);
    func_800F0BE0(0x80, 5, 3, 1);
    func_800F0BE0(0x80, 6, 3, 1);
    func_800F0BE0(0x80, 7, 3, 1);
    func_800F0BE0(0x80, 8, 3, 1);
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C6AF0\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}
