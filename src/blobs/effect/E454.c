#include "common.h"

extern u8 D_801BF02C[];
extern u8 *D_801BBF88;
extern u8 D_801C48DC[];
extern u8 D_801C48DD[];
extern s32 D_801251C4;
extern s32 func_801A4DE8(s32, s32);
extern void func_801A4E9C(s32);
extern void func_800F0BE0(s32, s32, s32, s32);
extern void func_801A60AC(s32, s32, s32, void *);

void func_801C2504(s16 arg0, s32 arg1, s32 arg2, s32 s4) {
    s32 buf[22];
    register u8 *s3 asm("s3");
    u8 *s2;
    s32 s5;
    s32 s0;
    u8 *s1;
    EffectMeta *meta;
    s32 v1;
    s32 s6;
    s32 v0;
    s32 a0v;
    s32 a0x;
    s32 idx;
    s32 *vec;
    s32 v0t;
    s32 a2v;
    s32 *a3v;

    s0 = (arg0 << 16) >> 16;
    s2 = D_801BF02C + s0 * 0xF8;
    s3 = s2 + arg1;
    v1 = s3[0x22];
    if (v1 == 1)
        goto case1;
    if (v1 < 2)
        goto epi;
    SCHED_BARRIER();
    if (v1 == 2)
        goto case2;
    if (v1 == 3)
        goto case3;
    goto epi_store;
case1:
    __asm__ volatile(
        "sll $2,%1,0x2\n\taddu %0,$2,%2"
        : "=r"(s1) : "r"(arg1), "r"(s2) : "$2");
    a0v = ((EffectSlot *) s1)->handle;
    if (a0v != 0)
        func_801A4E9C(a0v);
    v0 = func_801A4DE8(0x200, s0);
    ((EffectSlot *) s1)->handle = v0;
    D_801251C4 = v0;
    func_800F0BE0(0x80, 1, 1, 1);
    func_800F0BE0(0x80, 2, 1, 1);
    func_800F0BE0(0x80, 3, 1, 1);
    func_800F0BE0(0x80, 4, 1, 1);
    func_800F0BE0(0x80, 5, 1, 1);
    func_800F0BE0(0x80, 6, 1, 1);
    s3[0x22] = 2;
    goto epi_store;
case2:
    s5 = *(s32 *) (arg1 * 4 + s2 + 0xE4);
    s3 = 0;
    s6 = 0x14;
loop11:
    meta = (EffectMeta *) (D_801BBF88 + s6);
    v1 = meta->kind;
    a0x = v1 - 1;
    if ((u32) a0x >= 0xCU)
        goto checkD;
    if (s4 < meta->range_start)
        goto block28;
    if (s4 >= meta->range_end)
        goto block28;
    idx = a0x * 2;
    vec = (s32 *) (s5 + ((D_801C48DC[idx] << 4) + (D_801C48DD[idx] << 6)));
    buf[3] = vec[0] << 12;
    buf[4] = vec[1] << 12;
    buf[5] = vec[2] << 12;
    func_801A60AC(((EffectSlot *) s2)->field02, ((EffectSlot *) s2)->field20 - meta->range_start, (s32) s3, &buf[0]);
    SCHED_BARRIER();
    s3++;
    goto block28;
checkD:
    if (v1 != 0xD)
        goto checkE;
    if (s4 < meta->range_start)
        goto block28;
    if (s4 >= meta->range_end)
        goto block28;
    s0 = 0;
    do {
        vec = (s32 *) (s5 + ((D_801C48DC[s0] << 4) + (D_801C48DD[s0] << 6)));
        v0t = vec[0];
        __asm__ volatile("move %0,%1" : "=r"(a2v) : "r"(s3));
        buf[3] = v0t << 12;
        v0t = vec[1];
        __asm__ volatile("addiu %0,$29,16" : "=r"(a3v));
        buf[4] = v0t << 12;
        v0t = vec[2];
        s0 += 2;
        buf[5] = v0t << 12;
        func_801A60AC(((EffectSlot *) s2)->field02, ((EffectSlot *) s2)->field20 - meta->range_start, a2v, a3v);
    } while (s0 < 8);
    s3++;
    goto block28;
checkE:
    if (v1 != 0xE)
        goto block28;
    if (s4 < meta->range_start)
        goto block28;
    if (s4 >= meta->range_end)
        goto block28;
    s0 = 8;
    do {
        vec = (s32 *) (s5 + ((D_801C48DC[s0] << 4) + (D_801C48DD[s0] << 6)));
        v0t = vec[0];
        __asm__ volatile("move %0,%1" : "=r"(a2v) : "r"(s3));
        buf[3] = v0t << 12;
        v0t = vec[1];
        __asm__ volatile("addiu %0,$29,16" : "=r"(a3v));
        buf[4] = v0t << 12;
        v0t = vec[2];
        s0 += 2;
        buf[5] = v0t << 12;
        func_801A60AC(((EffectSlot *) s2)->field02, ((EffectSlot *) s2)->field20 - meta->range_start, a2v, a3v);
    } while (s0 < 0x18);
block28:
    s3++;
    s6 += 0xC4;
    if ((s32) s3 < 0x10)
        goto loop11;
    goto epi_store;
case3:
    __asm__ volatile(
        "sll $2,%1,0x2\n\taddu %0,$2,%2"
        : "=r"(s0) : "r"(arg1), "r"(s2) : "$2");
    a0v = *(s32 *) (s0 + 0xE4);
    if (a0v == 0)
        goto epi_store;
    func_801A4E9C(a0v);
    *(s32 *) (s0 + 0xE4) = 0;
    D_801251C4 = 0;
epi_store:
    (*(volatile u8 *) (s3 + 0x22)) = 0;
epi:;
}

void func_801C28FC(s16 arg0, s32 arg1) {
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
    TAIL_JUMP_NOP(0x801C29D8);
callp:
    func_800F0BE0(0x80, 1, 2, 1);
    func_800F0BE0(0x80, 2, 2, 1);
    func_800F0BE0(0x80, 3, 2, 1);
    func_800F0BE0(0x80, 4, 2, 1);
    func_800F0BE0(0x80, 5, 2, 1);
    func_800F0BE0(0x80, 6, 2, 1);
    __asm__ volatile(
        ".set\tnoreorder\n\tori $2,$0,0x2\n\tj 0x801C29D8\n\tsb $2,0x22(%0)\n\t.set\treorder" ::"r"(s0));
store0:
    s0[0x22] = 0;
epi:;
}

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E454", func_801C29F0);

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E454", func_801C416C);
