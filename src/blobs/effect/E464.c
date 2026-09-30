#include "common.h"

void func_801C2500(s32 arg0, s32 arg1, u16 *arg2, u16 *arg3) {
    s32 v0;
    U16x3 *src;

    v0 = arg1 * 6 + arg0 * 102;
    src = (U16x3 *) (0x1F800000 + v0);
    arg3[0] = src->v0 + arg2[0];
    arg3[1] = src->v1 + arg2[2];
    arg3[2] = src->v2 + arg2[4];
}

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E464", func_801C2578);

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E464", func_801C3800);

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr) ((u8 *) (expr) + (offset)))

s32 func_800F0BE0(s32, s32, s32, s32); /* extern */
s32 func_801A4DE8(s32, s16); /* extern */
s32 func_801A4E9C(s32); /* extern */
s32 func_801A60AC(s16, s32, s32, s32 *); /* extern */
s32 func_801C4C9C() __attribute__((noreturn)); /* extern */
s32 func_801C4DA0() __attribute__((noreturn)); /* extern */
extern s32 D_801251C4;
extern u8 *D_801BBF88;
extern u8 D_801BF02C[];
extern u8 D_801C4ECC[];
extern u8 D_801C4ECD[];

void func_801C4B54(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 out_args[6];
    volatile u8 stack_pad[0x40];
#define sp24 out_args[5]
#define sp20 out_args[4]
#define sp1C out_args[3]
#define sp10 out_args[0]
    s32 temp_a0;
    s32 temp_a0_3;
    s32 loop_i;
    s32 meta_off;
    s32 temp_v0;
    s32 temp_v0_2;
    u32 temp_v1_2;
    s32 temp_v1;
    EffectMeta *temp_a0_2;
    s32 temp_s0;
    void *temp_s1;
    s32 temp_s1_2;
    void *temp_s2;
    s32 temp_arg3;
    void *temp_s4;
    s32 *temp_v1_3;

    temp_arg3 = arg3;
    temp_s1 = (void *) (D_801BF02C + arg0 * 0xF8);
    temp_s2 = temp_s1 + arg1;
    temp_v1 = M2C_FIELD(temp_s2, u8 *, 0x22);
    if (temp_v1 == 1) {
        goto block_6;
    }
    if ((s32) temp_v1 < 2) {
        goto block_20;
    }
    __asm__ volatile("" : : : "memory");
    if (temp_v1 == 2) {
        goto block_10;
    }
    if (temp_v1 == 3) {
        goto block_17;
    }
    goto tail_default;
tail_default:
    __asm__ volatile("j func_801C4DA0" : : : "$2", "memory");
block_6:
    temp_s1_2 = (arg1 << 2) + (s32) temp_s1;
    temp_a0 = M2C_FIELD(temp_s1_2, s32 *, 0xE4);
    if (temp_a0 == 0) {
        goto block_8;
    }
    func_801A4E9C(temp_a0);
block_8:
    temp_v0 = func_801A4DE8(0x200, arg0);
    M2C_FIELD(temp_s1_2, s32 *, 0xE4) = temp_v0;
    D_801251C4 = temp_v0;
    func_800F0BE0(0x80, 1, 1, 1);
    func_800F0BE0(0x80, 2, 1, 1);
    func_800F0BE0(0x80, 3, 1, 1);
    func_800F0BE0(0x80, 4, 1, 1);
    func_800F0BE0(0x80, 5, 1, 1);
    func_800F0BE0(0x80, 6, 1, 1);
    __asm__(".macro jal target\n"
            ".word 0x08000000\n"
            ".reloc .-4, R_MIPS_26, \\target\n"
            ".purgem jal\n"
            ".endm\n");
    M2C_FIELD(temp_s2, u8 *, 0x22) = 2;
    func_801C4DA0();
    return;
block_10:
    temp_s4 = M2C_FIELD(((arg1 * 4) + temp_s1), s32 *, 0xE4);
    loop_i = 0;
    meta_off = 0x14;
    do {
        temp_a0_2 = (EffectMeta *) (D_801BBF88 + meta_off);
        temp_v1_2 = temp_a0_2->kind - 1;
        if (temp_v1_2 < 0xCU) {
            if (temp_arg3 >= temp_a0_2->range_start) {
                if (temp_arg3 < temp_a0_2->range_end) {
                    temp_v0_2 = temp_v1_2 * 2;
                    temp_v1_3 = (void *) temp_s4 + ((D_801C4ECC[temp_v0_2] * 0x10) + (D_801C4ECD[temp_v0_2] << 6));
                    sp1C = temp_v1_3[0] << 0xC;
                    sp20 = temp_v1_3[1] << 0xC;
                    sp24 = temp_v1_3[2] << 0xC;
                    func_801A60AC(M2C_FIELD(temp_s1, s16 *, 2), M2C_FIELD(temp_s1, s16 *, 0x20) - temp_a0_2->range_start, loop_i, &sp10);
                }
            }
        }
        loop_i += 1;
        meta_off += 0xC4;
        __asm__(".macro bne r1,r2,target\n"
                ".word 0x10400000\n"
                ".reloc .-4, R_MIPS_PC16, ($L2 - 4)\n"
                ".purgem bne\n"
                ".endm\n");
    } while (loop_i < 0x10);
    __asm__(".macro jal target\n"
            ".word 0x08000000\n"
            ".reloc .-4, R_MIPS_26, \\target\n"
            ".purgem jal\n"
            ".endm\n");
    func_801C4C9C();
    return;
block_17:
    SCHED_BARRIER();
    temp_s0 = (arg1 * 4) + (s32) temp_s1;
    temp_a0_3 = M2C_FIELD(temp_s0, s32 *, 0xE4);
    if (temp_a0_3 == 0) {
        goto block_19;
    }
    func_801A4E9C(temp_a0_3);
    M2C_FIELD(temp_s0, s32 *, 0xE4) = 0;
    D_801251C4 = 0;
block_19:
    M2C_FIELD(temp_s2, u8 *, 0x22) = 0U;
block_20:
    return;
}
