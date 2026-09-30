#include "common.h"

extern void func_8014BF54();
extern void func_80044600();
extern void func_8014C958();
extern u8 D_80173F8C[];
extern u8 D_801F7504[];
extern s32 D_80010010;
extern s32 D_8016602C;

void func_80060000(void) {
    func_8014BF54(D_80173F8C, D_801F7504, 0x80);
    func_80044600(D_80010010);
    D_8016602C = 0;
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/HELPMENU", func_80060050);

extern u8 *D_80165F98;

s32 func_80060DD4(void) {
    s32 i;
    s32 one;
    u8 *p;
    u8 *q;
    s32 v;

    i = 4;
    q = D_80165F98;
    one = 1;
    p = q + 0x1000;
    for (;;) {
        v = *(s32 *) (p + 0x48);
        MEMORY_BARRIER();
        if (v == one) {
            goto done;
        }
        i++;
        p += 0x400;
        if (i < 9) {
            continue;
        }
        break;
    }
done:
    return i;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/HELPMENU", func_80060E10);
