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

INCLUDE_ASM("rom/extracted/blobs/effect/nonmatchings/E338", func_801C2578);
