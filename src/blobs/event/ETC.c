#include "common.h"

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ETC", func_8006001C);

void func_800603D8(void) {
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ETC", func_800603E0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ETC", func_80060C58);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ETC", func_8006117C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ETC", func_800613AC);

extern s32 func_8014CBC0(void);
extern void func_801BF01C(s32);
extern void func_801C017C(s32);
extern void func_801C03AC(s32);
extern void func_8014C958(void);
extern s32 D_801C08B8[];

void func_800615D4(void) {
    register s32 v1 asm("v1");
    s32 s0;
    s32 one;

    s0 = func_8014CBC0();
    func_801BF01C(s0);
    one = 1;
    v1 = D_801C08B8[s0 << 3];
    if (v1 != 0) {
        goto L1;
    }
    func_801C017C(s0);
    __asm__ volatile("j func_801C062C" : "=r"(v1), "=r"(one));
L1:
    if (v1 != one) {
        goto L2;
    }
    func_801C03AC(s0);
L2:
    func_8014C958();
}
