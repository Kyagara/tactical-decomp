#include "common.h"

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E476", func_801C2500);

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E476", func_801C2C7C);

void func_801C424C(s32 arg0, s32 arg1, u16 *arg2, u16 *arg3) {
    s32 idx;
    s32 tmp;
    u16 *tab;

    tmp = arg1 * 3;
    idx = (arg0 * 51 + tmp) * 2;
    tab = (u16 *) (0x1F800000 + idx);
    arg3[0] = tab[0] + arg2[0];
    arg3[1] = tab[1] + arg2[2];
    arg3[2] = tab[2] + arg2[4];
}

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E476", func_801C42C4);
