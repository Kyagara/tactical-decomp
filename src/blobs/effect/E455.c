#include "common.h"

extern u8 D_801BF02C[];
extern void func_800F0BE0(s32, s32, s32, s32);

void func_801C2500(s16 arg0, s32 arg1) {
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
    TAIL_JUMP_NOP(0x801C25F0);
callp:
    func_800F0BE0(0x80, 1, 1, 1);
    func_800F0BE0(0x80, 2, 1, 1);
    func_800F0BE0(0x80, 3, 1, 1);
    func_800F0BE0(0x80, 4, 1, 1);
    func_800F0BE0(0x80, 5, 1, 1);
    func_800F0BE0(0x80, 6, 1, 1);
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C25F0\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}

void func_801C2604(s16 arg0, s32 arg1) {
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
    TAIL_JUMP_NOP(0x801C26F4);
callp:
    func_800F0BE0(0x80, 1, 2, 1);
    func_800F0BE0(0x80, 2, 2, 1);
    func_800F0BE0(0x80, 3, 2, 1);
    func_800F0BE0(0x80, 4, 2, 1);
    func_800F0BE0(0x80, 5, 2, 1);
    func_800F0BE0(0x80, 6, 2, 1);
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C26F4\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}

extern void func_80093144(void);

void func_801C2708(s16 arg0, s32 arg1) {
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
    TAIL_JUMP_NOP(0x801C2788);
callp:
    func_80093144();
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C2788\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}

extern void func_80093118(void);

void func_801C279C(s16 arg0, s32 arg1) {
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
    TAIL_JUMP_NOP(0x801C281C);
callp:
    func_80093118();
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C281C\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}
