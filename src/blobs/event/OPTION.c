#include "common.h"

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_80060000);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_800601E0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_8006045C);

extern s16 D_801C9CE4;
extern s16 D_801C9CE6;
extern s16 D_801C9CE8;
extern s16 D_801C9CEA;

void func_800610C0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_801C9CE4 = arg0;
    D_801C9CE6 = arg1;
    D_801C9CE8 = arg2;
    D_801C9CEA = arg3;
}

extern s16 D_801C9CF4;
extern s16 D_801C9CF6;

void func_800610E8(s16 arg0, s16 arg1) {
    D_801C9CF4 = arg0;
    D_801C9CF6 = arg1;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_80061100);

extern void func_8014BF54();
extern u8 D_801C347C[];

void func_800612D0(u8 *arg0) {
    *(u16 *) (arg0 + 0x1C) = 0;
    *(u16 *) (arg0 + 0x26) = 0;
    func_8014BF54(arg0 + 0x20, D_801C347C, 8);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_80061304);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_80061894);

void func_80061E30(void) {
    func_8014CA80();
    TAIL_JUMP(func_801C0E38);
}

extern void func_8014C958();
extern void func_8014CA80();

void func_80061E58(void) {
    func_8014CA80();
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_80061E80);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_800624EC);

extern void func_8014C940();
extern void func_8013D634();
extern void func_8014C9D0();
extern void func_8014C924();
extern u16 D_801C38E4;
extern u16 D_80166048;
extern u16 D_8016604A;
extern u16 D_8016604C;
extern u16 D_80165F74;
extern s32 D_80174038;
extern s32 D_80174008;
extern s32 D_801CB79C;

void func_80062814(void) {
    D_80165F74 = 1;
    D_80166048 = 2;
    func_8014C940(D_80174038 + 1);
    func_8014C940(D_80174038 + 2);
    func_8014C940(D_80174038 + 3);
    func_8014C940(D_80174038 + 4);
    TAIL_JUMP(func_801C1884);
    do {
        func_8014CA80();
        D_8016604A = D_801C38E4 + 0x64;
    } while (D_8016604C == 0);
    D_8016604C = 0;
    D_8016604A = 0;
    func_8013D634(0, 0xFF, 0xFF);
    func_8014C9D0(0xD);
    func_8014C9D0(0xC);
    func_8014C9D0(0xB);
    func_8014C9D0(0xA);
    D_80174008 = &D_801CB79C;
    func_8014C924(D_80174038 + 1);
    func_8014C924(D_80174038 + 2);
    func_8014C924(D_80174038 + 3);
    func_8014C924(D_80174038 + 4);
    D_80165F74 = 0;
    D_80166048 = 0;
    func_8014C958();
}

extern void *D_80173CB8;
extern s16 D_801C38E6;
extern s32 D_801C38AC;
extern s32 D_801C35AC;
extern s32 D_801C38DC;
extern s32 D_801BF45C;
extern void func_801C14EC();
extern void func_8014C8A0();
extern void func_8014CA38();
extern s32 func_8014CC94();

void func_8006295C(void) {
    void *temp_s1;

    temp_s1 = D_80173CB8;
    D_801C38E6 = 0x13;
    D_80173CB8 = &D_801C38AC;
    D_801C38DC = (s32) &D_801C35AC;
    func_801C14EC(&D_801C38AC);
    func_8014C8A0(D_80174038 - 2, &D_801BF45C);
    func_8014CA38(D_80174038 - 2, &D_801C38AC, 0, 0);
    for (;;) {
        func_8014CA80();
        if (func_8014CC94(D_80174038 - 2) == 0) {
            if (func_8014CC94(D_80174038 - 3) == 0) {
                break;
            }
        }
    }
    D_80173CB8 = temp_s1;
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_80062A3C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_80062CBC);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/OPTION", func_80063DDC);
