#include "common.h"

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E458", func_801C2500);

extern u8 D_801BF02C[];
extern void func_800F5A2C(s32, s32);

void func_801C2C74(s16 arg0, s32 arg1) {
    register s32 h asm("a1");
    u8 *s0;
    u8 *p;
    s32 v1;
    u8 *ptr;
    u16 w;

    p = D_801BF02C + arg0 * 0xF8;
    s0 = p + arg1;
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
    TAIL_JUMP_NOP(0x801C2D08);
callp:
    ptr = *(u8 **) 0x801BBF84;
    h = *(s16 *) ((u8 *) p + 0x28);
    w = *(u16 *) (ptr + 2);
    arg1 = w - h;
    func_800F5A2C(0x96, arg1);
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C2D08\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}
