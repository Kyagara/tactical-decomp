#include "common.h"

extern s32 D_801D7070;
extern volatile s32 D_801D7074;
extern s32 D_80173FE4;
extern volatile s32 D_80173FAC;
extern s32 D_80173F94;
extern s32 D_80173FA4;
extern char D_801D70EC[];
extern void func_8013B644(s32, s32);

void func_80060000(void) {
    char *p;
    s32 x;
    s32 y;
    s32 z;

    p = D_801D70EC;
    x = D_801D7070;
    y = D_80173FE4;
    D_80173FAC = x + (s32) p;
    z = D_801D7074;
    D_80173F94 = y;
    D_80173FA4 = z + (s32) p;
    func_8013B644(0x39, 0);
}

s32 func_80060064(void) {
    return 0;
}
