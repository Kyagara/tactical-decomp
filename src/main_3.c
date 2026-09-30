#include "common.h"

void func_80026F58(u8 *arg0, int arg1, int arg2);
void func_80024740(char *arg0, s32 arg1);
void func_80026F94(void *arg0, void *arg1, s32 arg2);

typedef struct {
    u16 counter;
    u16 unk2;
    u16 mode;
    u16 unk6;
    u16 target;
    u16 unkA;
    u32 unkC;
} TimerCounter;

extern volatile s32 *D_80031C98;
extern volatile TimerCounter *D_80031C9C;
extern s32 D_80031CA0[];

s32 StopRCnt(s32 spec, s16 target, s32 flags) {
    s32 i = spec & 0xFFFF;
    s32 final_mode = 0x48;
    if (i >= 3) {
        return 0;
    }
    D_80031C9C[i].mode = 0;
    D_80031C9C[i].target = target;
    if (i < 2u) {
        if (flags & 0x10) {
            final_mode = 0x49;
        }
        if (!(flags & 1)) {
            final_mode |= 0x100;
        }
    } else if (i == 2u) {
        if (!(flags & 1)) {
            final_mode = 0x248;
        }
    }
    if ((flags & 0x1000) != 0) {
        final_mode |= 0x10;
    }
    D_80031C9C[i].mode = final_mode;
    return 1;
}

s32 ResetRCnt(s32 spec) {
    s32 i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    return D_80031C9C[i].counter;
}

s32 StartRCnt(s32 spec) {
    s32 i = spec & 0xFFFF;
    D_80031C98[1] |= D_80031CA0[i];
    return i < 3;
}

s32 GetRCnt(s32 spec) {
    s32 i = spec & 0xFFFF;
    D_80031C98[1] &= ~D_80031CA0[i];
    return 1;
}

s32 SetRCnt(s32 spec) {
    s32 i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    D_80031C9C[i].counter = 0;
    return 1;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_8002228C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80022298);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_8002229C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800222A8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800222AC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800222B8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800222BC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800222C8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800222CC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800222D8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800222DC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800222E8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800222EC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800222F8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800222FC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80022308);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_8002230C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80022318);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_8002231C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80022328);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_8002232C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80022338);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_8002233C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_80022B98);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80022BA4);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_80022BA8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80022BB4);

u8 *memmove(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 temp_v1;
    s32 temp_v1_2;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;
    u8 temp_v0_2;
    s32 test;
    s32 test2;
    u8 *var_a3;
    register u8 *var_a1_2 asm("a1");

    var_a0 = arg0;
    var_a1 = arg1;
    if (var_a0 >= var_a1) {
        test = arg2;
        arg2 = arg2 - 1;
        if (test > 0) {
            var_a3 = (u8 *) (arg2 + (s32) var_a0);
            do {
                var_a1_2 = arg2 + var_a1;
                temp_v0 = *var_a1_2;
                var_a1_2 -= 1;
                temp_v1 = arg2;
                arg2 -= 1;
                *var_a3 = temp_v0;
                var_a3 -= 1;
            } while (temp_v1 > 0);
        }
    } else {
        test2 = arg2;
        arg2 = arg2 - 1;
        if (test2 > 0) {
            do {
                temp_v0_2 = *var_a1;
                var_a1 += 1;
                temp_v1_2 = arg2;
                arg2 -= 1;
                *var_a0 = temp_v0_2;
                var_a0 += 1;
            } while (temp_v1_2 > 0);
        }
    }
    return (u8 *) var_a0;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80022C24);

s32 LoadClut2(s32 arg0, s32 arg1, s32 arg2) {
    s16 clut[4];

    clut[2] = 0x100;
    clut[0] = arg1;
    clut[1] = arg2;
    clut[3] = 1;
    ClearOTag(clut, arg0);
    return P01GetClut(arg1, arg2) & 0xFFFF;
}

extern s32 ClearOTag(s16 *, s32);
extern s32 P01GetClut(s32, s32);

s32 LoadTPage(s32 tpage, s32 x, s32 y) {
    s16 rect[4];

    rect[2] = 0x10;
    rect[0] = (s16) x;
    rect[1] = (s16) y;
    rect[3] = 1;
    ClearOTag(rect, tpage);
    return P01GetClut(x, y) & 0xFFFF;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80022DE0);

void SetDefDispEnv(DispEnv *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    register s16 *p asm("v0") = (s16 *) arg0;

    p[0] = arg1;
    p[1] = arg2;
    p[2] = arg3;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    arg0->isrgb24 = 0;
    arg0->isinter = 0;
    arg0->pad1 = 0;
    arg0->pad0 = 0;
    p[3] = arg4;
}

extern s32 D_80031E3C;
extern s32 D_80031E40;
extern int (*D_80032890)();
extern void func_800235AC(void);

void FONTSetDumpFnt(s32 arg0) {
    if ((arg0 >= 0) && (D_80031E3C >= arg0)) {
        D_80031E40 = arg0;
        D_80032890 = (void *) func_800235AC;
    }
}

extern u8 D_80031E44[];
extern u8 D_80031CBC[];
extern s16 D_80036EAC;
extern s16 D_80036EB0;
extern s16 func_80022D78(u8 *, s32, s32);
extern s16 func_80022C24(u8 *, s32, s32, s32, s32, s32, s32);
extern void func_800222FC(u8 *, s32, s32);

void FntPrint(s32 arg0, s32 arg1) {
    D_80036EB0 = func_80022D78(D_80031E44, arg0, arg1 + 0x80);
    D_80036EAC = func_80022C24(D_80031E44 + 0x200, 0, 0, arg0, arg1, 0x80, 0x20);
    D_80031E3C = 0;
    func_800222FC(D_80031CBC, 0, 0x180);
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80022FD0);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80023288);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_800235AC);

s32 SetSprt8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if ((SYSGetGraphType() == 1) || (SYSGetGraphType() == 2)) {
        return ((arg0 & 3) << 9) | ((arg1 & 3) << 7) | ((arg3 & 0x300) >> 3) | ((arg2 & 0x3FF) >> 6);
    } else {
        return ((arg0 & 3) << 7) | ((arg1 & 3) << 5) | ((arg3 & 0x100) >> 4) | ((arg2 & 0x3FF) >> 6) | ((arg3 & 0x200) << 2);
    }
}

s32 P01GetClut(s32 arg0, s32 arg1) {
    return ((arg1 << 6) | ((arg0 >> 4) & 0x3F)) & 0xFFFF;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80023A6C);

extern char D_8001060C[];

void SetLineF2(s32 arg0) {
    ((void (*)(char *, s32, s32)) D_80032890)(D_8001060C, (arg0 & 0x3F) << 4,
                                              (arg0 & 0xFFFF) >> 6);
}

s32 P04NextPrim(s32 *arg0) {
    return (*arg0 & 0xFFFFFF) | 0x80000000;
}

s32 P05IsEndPrim(s32 *arg0) {
    return (*arg0 & 0xFFFFFF) == 0xFFFFFF;
}

void DumpClut(s32 *arg0, s32 *arg1) {
    s32 m1 = 0x00FFFFFF;
    register s32 m2 asm("a3") = 0xFF000000;

    arg1[0] = (arg1[0] & m2) | (arg0[0] & m1);
    arg0[0] = (arg0[0] & m2) | ((s32) arg1 & m1);
}

void SetLineG3(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 m1 = 0x00FFFFFF;
    register s32 m2 asm("t0") = 0xFF000000;

    arg2[0] = (arg2[0] & m2) | (arg0[0] & m1);
    arg0[0] = (arg0[0] & m2) | ((s32) arg1 & m1);
}

void SetLineF4(s32 *arg0, s32 arg1) {
    *arg0 = (*arg0 & 0xFF000000) | (arg1 & 0xFFFFFF);
}

void P09TermPrim(s32 *arg0) {
    *arg0 |= 0xFFFFFF;
}

void P10SetSemiTrans(GpuPacket *arg0, s32 arg1) {
    u8 v0;

    if (arg1 != 0) {
        v0 = arg0->len | 2;
    } else {
        v0 = arg0->len & 0xFD;
    }
    arg0->len = v0;
}

void P11SetShadeTex(GpuPacket *arg0, s32 arg1) {
    u8 v0;

    if (arg1 != 0) {
        v0 = arg0->len | 1;
    } else {
        v0 = arg0->len & 0xFE;
    }
    arg0->len = v0;
}

void P12SetPolyF3(GpuPacket *arg0) {
    arg0->code = 4;
    arg0->len = 0x20;
}

void P13SetPolyFT3(GpuPacket *arg0) {
    arg0->code = 7;
    arg0->len = 0x24;
}

void P14SetPolyG3(GpuPacket *arg0) {
    arg0->code = 6;
    arg0->len = 0x30;
}

void P15SetPolyGT3(GpuPacket *arg0) {
    arg0->code = 9;
    arg0->len = 0x34;
}

void P16SetPolyF4(GpuPacket *arg0) {
    arg0->code = 5;
    arg0->len = 0x28;
}

void P17SetPolyFT4(GpuPacket *arg0) {
    arg0->code = 9;
    arg0->len = 0x2C;
}

void P18SetPolyG4(GpuPacket *arg0) {
    arg0->code = 8;
    arg0->len = 0x38;
}

void P19SetPolyGT4(GpuPacket *arg0) {
    arg0->code = 0xC;
    arg0->len = 0x3C;
}

void P20SetSprt8(GpuPacket *arg0) {
    arg0->code = 3;
    arg0->len = 0x74;
}

void P21SetSprt16(GpuPacket *arg0) {
    arg0->code = 3;
    arg0->len = 0x7C;
}

void P22SetSprt(GpuPacket *arg0) {
    arg0->code = 4;
    arg0->len = 0x64;
}

void P23SetTile1(GpuPacket *arg0) {
    arg0->code = 2;
    arg0->len = 0x68;
}

void P24SetTile8(GpuPacket *arg0) {
    arg0->code = 2;
    arg0->len = 0x70;
}

void P25SetTile16(GpuPacket *arg0) {
    arg0->code = 2;
    arg0->len = 0x78;
}

void P26SetTile(GpuPacket *arg0) {
    arg0->code = 3;
    arg0->len = 0x60;
}

void P27SetLineF2(GpuPacket *arg0) {
    arg0->code = 3;
    arg0->len = 0x40;
}

void P28SetLineG2(GpuPacket *arg0) {
    arg0->code = 4;
    arg0->len = 0x50;
}

void SetBlockFill(GpuPacket *arg0) {
    arg0->code = 5;
    arg0->len = 0x48;
    ((s32 *) arg0)[5] = 0x55555555;
}

void SetPolyGT4(GpuPacket *arg0) {
    arg0->code = 7;
    arg0->len = 0x58;
    ((s32 *) arg0)[7] = 0x55555555;
}

void AddPrim(GpuPacket *arg0) {
    arg0->code = 6;
    arg0->len = 0x4C;
    ((s32 *) arg0)[6] = 0x55555555;
}

void CatPrim(GpuPacket *arg0) {
    arg0->code = 9;
    arg0->len = 0x5C;
    ((s32 *) arg0)[9] = 0x55555555;
}

void func_80023E8C(GpuPacket *arg0) {
    arg0->code = 3;
    arg0->len = 2;
}

void SetDrawMove(GpuPacket *arg0) {
    arg0->code = 5;
    arg0->len = 1;
    ((s32 *) arg0)[2] = 0x80000000;
}

typedef struct {
    u8 pad3[3];
    u8 unk3;
    s32 unk4;
} Packet23EBC;

void SetTile(Packet23EBC *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 base;
    s32 m;
    register s32 base2 asm("a3");
    s32 lo;
    arg0->unk3 = 1;
    if ((SYSGetGraphType() == 1) || (SYSGetGraphType() == 2)) {
        base = 0xE1000000;
        if (arg2 != 0) {
            base = 0xE1000800;
        }
        lo = arg3 & 0x27FF;
        if (arg1 != 0) {
            lo |= 0x1000;
        }
        lo = (m = base | lo);
    } else {
        base2 = 0xE1000000;
        if (arg2 != 0) {
            base2 = 0xE1000200;
        }
        lo = arg3 & 0x9FF;
        if (arg1 != 0) {
            lo |= 0x400;
        }
        lo = (m = base2 | lo);
    }
    arg0->unk4 = lo;
}

void P34SetDrawMoveSetDrawLoad(GpuPacket *arg0, s32 *arg1) {
    s32 temp_v0;
    s8 var_v1;

    temp_v0 = ((s16) ((GpuRect *) arg1)->w * (s16) ((GpuRect *) arg1)->h + 1) / 2;
    var_v1 = temp_v0 + 4;
    if ((u32) (temp_v0 - 1) >= 0xB) {
        var_v1 = 0;
    }
    ((s32 *) arg0)[1] = 0x01000000;
    arg0->code = var_v1;
    ((s32 *) arg0)[2] = 0xA0000000;
    ((s32 *) arg0)[3] = arg1[0];
    ((s32 *) arg0)[4] = arg1[1];
}

s32 P36MargePrim(GpuPacket *arg0, GpuPacket *arg1) {
    s32 temp_v1;

    temp_v1 = arg0->code + arg1->code + 1;
    if (temp_v1 >= 0x21) {
        return -1;
    }
    arg0->code = (u8) temp_v1;
    *(s32 *) arg1 = 0;
    return 0;
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u16 unk14;
    u8 unk16;
    u8 unk17;
} func_8002400CUnk;

extern int D_800105F4;
extern int D_8001061C;
extern int D_80010634;
extern int D_80010644;
extern int D_8001065C;
extern int D_80010668;

void GetTPage(func_8002400CUnk *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    D_80032890(&D_8001061C, arg0->unk0, arg0->unk2, arg0->unk4, (s32) arg0->unk6);
    D_80032890(&D_80010634, arg0->unk8, arg0->unkA);
    D_80032890(&D_80010644, arg0->unkC, arg0->unkE, arg0->unk10, (s32) arg0->unk12);
    D_80032890(&D_8001065C, (s16) arg0->unk16);
    D_80032890(&D_80010668, (s16) arg0->unk17);
    if ((SYSGetGraphType() == 1) || (SYSGetGraphType() == 2)) {
        temp_v0 = arg0->unk14;
        D_80032890(&D_800105F4, (temp_v0 >> 9) & 3, (temp_v0 >> 7) & 3, (temp_v0 << 6) & 0x7C0, (temp_v0 * 8) & 0x300);
        return;
    }
    temp_v0_2 = arg0->unk14;
    D_80032890(&D_800105F4, (temp_v0_2 >> 7) & 3, (temp_v0_2 >> 5) & 3, (temp_v0_2 << 6) & 0x7C0, ((temp_v0_2 * 0x10) & 0x100) + ((temp_v0_2 >> 2) & 0x200));
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 unk10;
    u8 unk11;
} func_8002418CUnk;

extern int D_80010674;
extern int D_80010690;
extern int D_800106AC;
extern int D_800106B8;

void SetTile8(func_8002418CUnk *arg0) {
    D_80032890(&D_80010674, arg0->unk0, arg0->unk2, arg0->unk4, (s32) arg0->unk6);
    D_80032890(&D_80010690, arg0->unk8, arg0->unkA, arg0->unkC, (s32) arg0->unkE);
    D_80032890(&D_800106AC, (s16) arg0->unk10);
    D_80032890(&D_800106B8, (s16) arg0->unk11);
}

int func_80026F84(s32);
s32 GPUReset(s32);
extern int func_8002232C();
int ETCResetCallback();
extern int D_800106F8;
extern int D_80010718;
extern int D_8003284C;
extern u8 D_80032895;
extern u16 D_80032898;
extern u16 D_8003289A;
extern u32 D_80036EB4;
extern u32 D_80036EB8;
extern u32 D_80036EBC;
extern u32 D_80036EC0;
extern u32 D_80036EC4;
extern u32 D_80036EC8;
extern u32 D_80036ECC;
extern u32 D_80036ED0;
extern u32 D_80036ED4;
extern u32 D_80036ED8;
extern u32 D_80036EDC;
extern u32 D_80036EE0;
extern void Cwc(s32 arg0);
extern s32 GPUParam(s32 arg0);
extern u8 D_80032894;
extern u8 D_80032896;
typedef void (*GpuSetDrawMode)(s32, s32, s32, s32);
typedef void (*GpuSetDrawArea)(s32);
typedef void (*GpuSetMode)(s32);
typedef s32 (*GpuCallArg)(s32);
extern GpuDispatch *D_8003288C;
extern int D_80032914;
extern int D_80032928;

s32 SYSResetGraph(s32 arg0) {
    s32 temp_s1;
    u8 *p;

    temp_s1 = arg0 & 7;
    if ((temp_s1 == 0) || (temp_s1 == 3)) {
        p = &D_80032894;
        func_8002232C(&D_800106F8, &D_8003284C, p);
        func_80026F58(p, 0, 0x80);
        ETCResetCallback();
        func_80026F84((s32) D_8003288C & 0xFFFFFF);
        *p = GPUReset(temp_s1 != 0);
        D_80032895 = 1;
        D_80032898 = *(u16 *) ((u8 *) &D_80032914 + (*p * 4));
        D_8003289A = *(u16 *) ((u8 *) &D_80032928 + (*p * 4));
        func_80026F58(p + 0x10, -1, 0x5C);
        func_80026F58(p + 0x6C, -1, 0x14);
        return *p;
    }
    if ((u8) D_80032896 >= 2U) {
        D_80032890(&D_80010718, arg0);
    }
    return ((GpuCallArg) D_8003288C->vec[13])(1);
}

extern u8 D_80032897;
extern char D_8001072C[];

u8 _qlog(s32 arg0) {
    register s32 arg_s1 asm("s1") = arg0;
    u8 *p_s0 = &D_80032897;
    u8 old_s2;
    GpuDispatch *dp;
    GpuDispatch *dp2;
    s32 v1;
    s32 v0;
    s32 a0;

    old_s2 = *p_s0;
    if (!(D_80032896 < 2U)) {
        ((void (*)(char *, s32)) D_80032890)(D_8001072C, arg_s1);
    }
    dp = D_8003288C;
    *p_s0 = arg_s1;
    v0 = ((GpuCallArg) dp->vec[10])(8);
    v1 = *p_s0;
    a0 = v0;
    if (v1 != 0) {
        a0 |= 0x8000080;
    } else {
        a0 |= 0x8000000;
    }
    ((GpuSetMode) D_8003288C->vec[4])(a0);
    if (D_80032894 == 2) {
        a0 = 0x20000504;
        dp2 = D_8003288C;
        if (D_80032897 != 0) {
            a0 = 0x20000501;
        }
        ((GpuSetMode) dp2->vec[4])(a0);
    }
    return old_s2;
}

extern char D_80010744[];

u8 SetDrawOffset(u8 arg0) {
    u8 temp_s0;
    u8 *p;

    p = &D_80032896;
    temp_s0 = *p;
    *p = arg0;
    if (arg0 != 0) {
        ((void (*)(char *, u8, u8, u8)) D_80032890)(D_80010744, *p, D_80032894,
                                                    D_80032897);
    }
    return temp_s0;
}

extern char D_80010770[];
extern s32 func_8001DDEC(s32, s32);

u8 DrawOTagEnv(s32 arg0) {
    u8 *p_s1;
    u8 old_s2;

    p_s1 = &D_80032895;
    old_s2 = *p_s1;
    if (!(D_80032896 < 2U)) {
        ((void (*)(char *, s32)) D_80032890)(D_80010770, arg0);
    }
    if (arg0 != *p_s1) {
        ((GpuCallArg) D_8003288C->vec[13])(1);
        *p_s1 = arg0;
        func_8001DDEC(2, 0);
    }
    return old_s2;
}

int SYSGetGraphType() {
    return D_80032894;
}

s32 SYSGetGraphDebug(void) {
    return D_80032896;
}

extern char D_80010784[];
extern s32 D_800328A0;

s32 _qout(s32 arg0) {
    s32 old;

    if (!(D_80032896 < 2U)) {
        ((void (*)(char *, s32)) D_80032890)(D_80010784, arg0);
    }
    old = D_800328A0;
    D_800328A0 = arg0;
    return old;
}

extern char D_800107A0[];

void DrawSync(s32 arg0) {
    int new_var;
    u8 *p;
    u32 mode;
    s32 s0;
    void **new_var2;
    new_var = 0x6A;
    s0 = arg0;
    p = &D_80032896;
    if (!(*p < 2U)) {
        ((void (*)(char *, s32)) D_80032890)(D_800107A0, arg0);
    }
    if (s0 == 0) {
        func_80026F58(p + new_var, -1, 0x14);
    }
    new_var2 = &D_8003288C->vec[4];
    mode = 0x03000001;
    if (s0 != 0) {
        mode = 0x03000000;
    }
    ((GpuCallArg) (*new_var2))(mode);
}

extern char D_800107B4[];

void SetDrawArea(s32 arg0) {
    if (!(D_80032896 < 2U)) {
        ((void (*)(char *, s32)) D_80032890)(D_800107B4, arg0);
    }
    ((GpuSetDrawArea) D_8003288C->vec[15])(arg0);
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80024740);

extern char D_800107EC[];

void SetDrawMode(s32 arg0, unsigned char arg1, s32 arg2, s32 arg3) {
    func_80024740(D_800107EC, arg0);
    ((GpuSetDrawMode) D_8003288C->vec[2])(
        (s32) D_8003288C->vec[3], arg0, 8, ((arg3 & 0xFF) << 0x10) | ((arg2 & 0xFF) << 8) | (arg1 & 0xFF));
}

extern char D_800107F8[];
extern void func_80024740(char *, s32);

s32 ClearOTag(s16 *arg0, s32 arg1) {
    func_80024740(D_800107F8, (s32) arg0);
    ((void (*)(s32, s32, s32, s32))((GpuDispatch *) D_8003288C)->vec[2])(
        (s32) ((GpuDispatch *) D_8003288C)->vec[8], (s32) arg0, 8, arg1);
}

extern char D_80010804[];

s32 LoadImage(s16 *arg0, s32 arg1) {
    func_80024740(D_80010804, (s32) arg0);
    ((void (*)(s32, s32, s32, s32))((GpuDispatch *) D_8003288C)->vec[2])(
        (s32) ((GpuDispatch *) D_8003288C)->vec[7], (s32) arg0, 8, arg1);
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_800249C4);

extern char D_8001081C[];
extern int D_80032950;

u8 *SetPriority(u8 *arg0, s32 arg1) {
    u8 *s0;
    s32 s1;
    u32 m1;
    u32 m2;
    u32 m3;
    u32 nxt;
    s0 = arg0;
    s1 = arg1;
    if (!(D_80032896 < 2U)) {
        ((void (*)(char *, void *, s32)) D_80032890)(D_8001081C, s0, s1);
    }
    s1 -= 1;
    if (s1 != 0) {
        m1 = 0x00FFFFFF;
        ;
        do {
            m3 = 0x00FFFFFF;
            do {
                s1 -= 1;
                nxt = (u32) (s0 + 4);
                s0[3] = 0;
                *(u32 *) s0 = (*(u32 *) s0 & 0xFF000000) | (nxt & m1);
                s0 = (u8 *) nxt;
            } while (s1 != 0);
        } while (0);
    }
    *(u32 *) s0 = 0x00FFFFFF;
    *(u32 *) s0 = (u32) &D_80032950 & *(u32 *) s0;
    return s0;
}

extern int D_80010834;

void ClearOTagR(s32 *arg0, int arg1) {
    s32 mask;
    s32 x;
    register s32 *q asm("v0");

    if (((u8) D_80032896) >= 2U) {
        ((int (*)(int *, s32 *, int)) D_80032890)(&D_80010834, arg0, arg1);
    }
    ((void (*)(void *, s32))((GpuDispatch *) D_8003288C)->vec[11])(arg0, arg1);
    mask = 0xFFFFFF;
    x = (s32) &D_80032950;
    if (x || x) {
        q = arg0;
    } else {
        q = arg0;
    }
    *q = x & mask;
}

void _qin(u8 *arg0) {
    s32 b = arg0[3];

    ((void (*)(s32))((GpuDispatch *) D_8003288C)->vec[15])(0);
    ((void (*)(u8 *, s32))((GpuDispatch *) D_8003288C)->vec[5])(arg0 + 4, b);
}

extern char D_8001084C[];

void _que(s32 arg0) {
    if (!(D_80032896 < 2U)) {
        ((void (*)(char *, s32)) D_80032890)(D_8001084C, arg0);
    }
    ((void (*)(s32, s32, s32, s32))((GpuDispatch *) D_8003288C)->vec[2])(
        (s32) ((GpuDispatch *) D_8003288C)->vec[6], arg0, 0, 0);
}

extern char D_80010860[];

u8 *GetGraphType(u8 *arg0) {
    u8 *p_s2 = &D_80032896;
    u8 *p_s1 = arg0;
    u8 *s0;

    if (!(*p_s2 < 2U)) {
        ((void (*)(char *, u8 *)) D_80032890)(D_80010860, p_s1);
    }
    s0 = (u8 *) &((DrawEnv *) p_s1)->unk1C;
    func_80025524(s0, p_s1);
    ((DrawEnv *) p_s1)->unk1C |= 0xFFFFFF;
    ((void (*)(s32, s32, s32, s32))((GpuDispatch *) D_8003288C)->vec[2])(
        (s32) ((GpuDispatch *) D_8003288C)->vec[6], (s32) s0, 0x40, 0);
    func_80026F94(p_s2 + 0xE, p_s1, 0x5C);
    return p_s1;
}

extern char D_80010878[];

void ClearImage(s32 arg0, u8 *arg1) {
    u8 *p_s3 = &D_80032896;
    u8 *p_s1 = arg1;
    s32 s2v;
    u8 *s0;

    s2v = arg0;
    if (!(*p_s3 < 2U)) {
        ((void (*)(char *, s32, u8 *)) D_80032890)(D_80010878, s2v, p_s1);
    }
    s0 = (u8 *) &((DrawEnv *) p_s1)->unk1C;
    func_80025524(s0, p_s1);
    ((DrawEnv *) p_s1)->unk1C = (((DrawEnv *) p_s1)->unk1C & 0xFF000000) | (s2v & 0xFFFFFF);
    ((void (*)(s32, s32, s32, s32))((GpuDispatch *) D_8003288C)->vec[2])(
        (s32) ((GpuDispatch *) D_8003288C)->vec[6], (s32) s0, 0x40, 0);
    func_80026F94(p_s3 + 0xE, p_s1, 0x5C);
}

extern u8 D_800328A4[];
extern void func_80026F94(void *arg0, void *arg1, s32 arg2);

s32 SetTexWindow(s32 arg0) {
    func_80026F94((void *) arg0, D_800328A4, 0x5C);
    return arg0;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80024E84);

extern u8 D_80032900[];

s32 GetDispEnv(s32 arg0) {
    func_80026F94((void *) arg0, D_80032900, 0x14);
    return arg0;
}

u32 GPU_printf(void) {
    return ((u32 (*)(void))((GpuDispatch *) D_8003288C)->vec[14])() >> 0x1F;
}

void SetDrawEnv(GpuPacket *arg0, s32 arg1) {
    arg0->code = 2;
    ((s32 *) arg0)[1] = GetTw((void *) arg1);
    ((s32 *) arg0)[2] = 0;
}

extern s32 func_80025824(s16, s16);
extern s32 func_800258F0(s16, s16);

void StoreImage(GpuPacket *arg0, s16 *arg1) {
    arg0->code = 2;
    ((s32 *) arg0)[1] = func_80025824(arg1[0], arg1[1]);
    ((s32 *) arg0)[2] = func_800258F0(
        (s16) (((u16) arg1[0] + (u16) arg1[2]) - 1),
        (s16) (((u16) arg1[1] + (u16) arg1[3]) - 1));
}

extern s32 ClearImage2(s32, s32);

void PutDrawEnv(GpuPacket *arg0, s16 *arg1) {
    arg0->code = 2;
    ((s32 *) arg0)[1] = ClearImage2(arg1[0], arg1[1]);
    ((s32 *) arg0)[2] = 0;
}

void PutDispEnv(GpuPacket *arg0, s32 arg1, s32 arg2) {
    s32 var_v1;

    arg0->code = 2;
    var_v1 = 0xE6000000;
    if (arg1 != 0) {
        var_v1 = 0xE6000002;
    }
    ((s32 *) arg0)[1] = var_v1 | (arg2 != 0);
    ((s32 *) arg0)[2] = 0;
}

extern s32 GetGraphDebug(void *, void *, s32);
extern s32 GetTw(void *);

void ResetGraph(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    s32 *p = arg0;

    ((GpuPacket *) arg0)->code = 2;
    p[1] = GetGraphDebug(arg1, arg2, arg3 & 0xFFFF);
    p[2] = GetTw((void *) arg4);
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80025524);

s32 GetGraphDebug(void *arg0, void *arg1, s32 arg2) {
    volatile u8 *p = (volatile u8 *) &D_80032894;
    s32 w;
    register s32 v asm("v0");

    if ((u32) (p[0] - 1) < 2) {
        if (arg1 != 0) {
            w = 0xE1000800;
        } else {
            w = 0xE1000000;
        }
        v = arg2 & 0x27FF;
        if (arg0 != 0) {
            v |= 0x1000;
        }
    } else {
        if (arg1 != 0) {
            w = 0xE1000200;
        } else {
            w = 0xE1000000;
        }
        v = arg2 & 0x9FF;
        if (arg0 != 0) {
            v |= 0x400;
        }
    }
    return w | v;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80025824);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_800258F0);

s32 ClearImage2(s32 arg0, s32 arg1) {
    volatile u8 *p = (volatile u8 *) &D_80032894;
    register s32 vy asm("v1");
    register s32 vx asm("v0");

    if ((u32) (p[0] - 1) >= 2) {
        vy = (arg1 & 0x7FF) << 11;
        vx = arg0 & 0x7FF;
        vx |= 0xE5000000;
    } else {
        vy = (arg1 & 0xFFF) << 12;
        vx = arg0 & 0xFFF;
        vx |= 0xE5000000;
    }
    return vy | vx;
}

s32 GetTw(void *arg0) {
    s32 sp[4];
    u32 temp_a1;
    s32 temp_a2;
    u32 temp_v0;
    s32 temp_v1;
    s32 b;
    u32 shift;

    if (arg0 != NULL) {
        temp_a1 = (u8) ((TimPos *) arg0)->unk00 >> 3;
        sp[0] = temp_a1;
        temp_a2 = (s32) (-(s32) ((TimPos *) arg0)->unk04 & 0xFF) >> 3;
        sp[2] = temp_a2;
        temp_v0 = (u8) ((TimPos *) arg0)->unk02 >> 3;
        sp[1] = temp_v0;
        shift = temp_v0 << 0xF;
        temp_v1 = (s32) (-(s32) ((TimPos *) arg0)->unk06 & 0xFF) >> 3;
        sp[3] = temp_v1;
        b = (temp_a1 << 0xA) | 0xE2000000;
        return shift | b | (temp_v1 << 5) | temp_a2;
    }
    return 0;
}

s32 GetDx(void *arg0) {
    volatile u8 *p = &D_80032894;
    s32 v1;
    s32 t;

    switch (*p & 0xFF) {
    case 1:
        if (D_80032897 == 0)
            return ((GpuRect *) arg0)->x;
        v1 = ((GpuRect *) arg0)->w;
        arg0 = (void *) (s32) ((GpuRect *) arg0)->x;
        t = 0x400 - v1;
shared:
        return t - (s32) arg0;
    case 2:
        if (D_80032897 != 0) {
            v1 = ((s16) * (u16 *) &((GpuRect *) arg0)->w) / 2;
            arg0 = (void *) (s32) ((GpuRect *) arg0)->x;
            t = 0x400 - v1;
            goto shared;
        }
        t = *(u16 *) &((GpuRect *) arg0)->x;
        if (arg0 != NULL) {
            t = ((s16) t) / 2;
        } else {
            t = ((s16) t) / 2;
        }
        return t;
    default:
        return ((GpuRect *) arg0)->x;
    }
}

extern vu32 *D_80032968;

s32 GPUStatus(void) {
    return *D_80032968;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80025B5C);

s32 Clr(u8 *arg0, s32 arg1) {
    u32 *ed4p;
    u32 maskv;
    s16 temp_a0;
    s16 temp_a0_2;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v1;
    s32 ec8v;
    u32 ed0v;

    temp_v1 = *(s16 *) &arg0[4];
    if (temp_v1 >= 0) {
        temp_a0 = (s16) * (volatile u16 *) &D_80032898;
        var_v1 = temp_v1;
        if ((temp_a0 - 1) < temp_v1) {
            var_v1 = temp_a0 - 1;
        }
        var_v0 = var_v1;
    } else {
        var_v0 = 0;
    }
    var_v1 = *(s16 *) &arg0[6];
    *(s16 *) &arg0[4] = var_v0;
    if (var_v1 >= 0) {
        temp_a0_2 = (s16) * (volatile u16 *) &D_8003289A;
        if ((temp_a0_2 - 1) < var_v1) {
            var_v1 = temp_a0_2 - 1;
        }
    } else {
        var_v1 = 0;
    }
    *(s16 *) &arg0[6] = var_v1;
    if ((*(u16 *) &arg0[0] & 0x3F) || (*(u16 *) &arg0[4] & 0x3F)) {
        ed4p = &D_80036ED4;
        maskv = 0xFFFFFF;
        D_80036EB4 = ((u32) ed4p & maskv) | 0x07000000;
        D_80036EB8 = 0xE3000000;
        D_80036EBC = 0xE4FFFFFF;
        D_80036EC0 = 0xE5000000;
        D_80036EC4 = 0xE6000000;
        ec8v = (arg1 & maskv) | 0x60000000;
        D_80036EC8 = ec8v;
        D_80036ECC = *(u32 *) &arg0[0];
        ed0v = *(u32 *) &arg0[4];
        *ed4p = 0x03FFFFFF;
        D_80036ED0 = ed0v;
        D_80036ED8 = GPUParam(3) | 0xE3000000;
        D_80036EDC = GPUParam(4) | 0xE4000000;
        D_80036EE0 = GPUParam(5) | 0xE5000000;
    } else {
        D_80036EB4 = 0x04FFFFFF;
        D_80036EB8 = 0xE6000000;
        D_80036EBC = (arg1 & 0xFFFFFF) | 0x02000000;
        D_80036EC0 = *(u32 *) &arg0[0];
        D_80036EC4 = *(u32 *) &arg0[4];
    }
    Cwc((s32) &D_80036EB4);
    return 0;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80025E5C);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_800260B0);

extern u8 D_80036EF4[];

void Ctl(u32 arg0) {
    *D_80032968 = arg0;
    D_80036EF4[arg0 >> 24] = arg0;
}

u8 GetCtl(s32 arg0) {
    return D_80036EF4[arg0];
}

extern vu32 *D_80032964;

s32 Cwb(s32 *arg0, int arg1) {
    *D_80032968 = 0x04000000;
    while (arg1-- != 0) {
        *D_80032964 = *arg0++;
    }
    return 0;
}

extern vu32 *D_8003296C;
extern vu32 *D_80032970;
extern vu32 *D_80032974;

void Cwc(s32 arg0) {
    *D_80032968 = 0x04000002;
    *D_8003296C = arg0;
    *D_80032970 = 0;
    *D_80032974 = 0x01000401;
}

s32 GPUParam(s32 arg0) {
    *D_80032968 = arg0 | 0x10000000;
    return *D_80032964 & 0xFFFFFF;
}

extern void func_80026478(s32, s32, s32, s32);

void Addque(s32 arg0, s32 arg1, s32 arg2) {
    func_80026478(arg0, arg1, 0, arg2);
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80026478);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_8002675C);

extern vu32 *D_80032984;
extern vu32 D_80032998;
extern vu32 D_8003299C;
extern u32 D_800329A8;
extern u8 D_8003F0BC[];
extern s32 func_8001DF08(s32);
extern s32 GPUVersion(s32);

s32 GPUReset(s32 arg0) {
    s32 t;
    s32 ret;
    s32 tt = func_8001DF08(0);

    D_8003299C = 0;
    D_80032998 = D_8003299C;
    D_800329A8 = tt;
    t = arg0 & 7;
    switch (t) {
    case 0:
        *D_80032974 = 0x401;
        *D_80032984 |= 0x800;
        *D_80032968 = 0;
        func_80026F58(&D_80036EF4[0], 0, 0x100);
        func_80026F58(&D_8003F0BC[0], 0, 0x1800);
        break;
    case 1:
        *D_80032974 = 0x401;
        *D_80032984 |= 0x800;
        *D_80032968 = 0x02000000;
        *D_80032968 = 0x01000000;
        break;
    }
    func_8001DF08(D_800329A8);
    ret = 0;
    if ((arg0 & 7) != 0) {
        return ret;
    }
    ret = GPUVersion(arg0);
    return ret;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80026B94);

extern s32 func_8001DBA8(s32);
extern s32 D_800329AC;
extern s32 D_800329B0;

void SetAlarm(void) {
    D_800329AC = func_8001DBA8(-1) + 0xF0;
    D_800329B0 = 0;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80026D10);

s32 GPUVersion(s32 arg0) {
    *D_80032968 = 0x10000007;
    if ((*D_80032964 & 0xFFFFFF) != 2) {
        *D_80032964 = (*D_80032968 & 0x3FFF) | 0xE1001000;
        (void) *D_80032964;
        if (!(*D_80032968 & 0x1000)) {
            return 0;
        }
        if (!(arg0 & 8)) {
            return 1;
        }
        *D_80032968 = 0x20000504;
        return 2;
    }
    if (!(arg0 & 8)) {
        return 3;
    }
    *D_80032968 = 0x09000001;
    return 4;
}

void func_80026F58(u8 *arg0, int arg1, int arg2) {
    while (arg2-- != 0)
        *arg0++ = (u8) arg1;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_80026F84);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80026F90);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_80026F94);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80026FA0);

extern s32 D_80036FF4;

s32 func_80026FA4(s32 arg0) {
    D_80036FF4 = arg0;
    return 0;
}

extern s32 func_80027308(s32, s32);

s32 ReadTIM(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_80027308(D_80036FF4, arg0);
    if (temp_v0 == -1) {
        return 0;
    }
    D_80036FF4 += temp_v0 * 4;
    return arg0;
}

extern s32 D_80036FF8;
extern s32 D_80036FFC;
extern s32 D_80037000;
extern s32 D_80037004;
extern s32 func_80027428(s32, s32, s32 *, s32 *, s32 *);

s32 OpenTMD(void) {
    s32 r, x, y;

    r = func_80027428(x, y, &D_80037000, &D_80036FF8, &D_80036FFC);
    D_80037004 = r;
    return r;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_8002705C);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80027308);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80027428);

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
} func_800275C0Src;

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u16 unk14;
    u16 unk16;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 pad24[68];
    u16 unk68;
    u16 unk6A;
    u16 unk6C;
    u16 unk6E;
    u16 unk70;
    u16 unk72;
    u16 unk74;
    u16 unk76;
} func_800275C0Dst;

extern char D_800109A4[];
extern char D_800109AC[];
extern char D_800109B4[];
extern char D_800109BC[];
extern char D_800109C4[];
extern char D_800109C8[];
extern char D_800109CC[];
extern char D_800109D4[];
extern char D_800109DC[];
extern char D_800109E4[];
extern char D_800109EC[];
extern char D_800109F4[];
extern char D_800109FC[];
extern char D_80010A00[];
extern char D_80010A04[];
extern char D_80010A0C[];
extern char D_80010A14[];

s32 CardUnpackPacket(func_800275C0Src *arg0, func_800275C0Dst *arg1) {
    s32 temp_v0;
    u32 temp_v1;

    func_800222FC((u8 *) arg1, 0, 0x78);
    temp_v0 = arg0->unk0;
    temp_v1 = temp_v0 & 0xFDFFFFFF;
    arg1->unk0 = temp_v0;
    switch (temp_v1) {
    case 0x20000304:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109A4);
        }
        arg1->unk4 = arg0->unk4;
        arg1->unk5 = arg0->unk5;
        arg1->unk6 = arg0->unk6;
        arg1->unk8 = arg0->unk4;
        arg1->unk9 = arg0->unk5;
        arg1->unkA = arg0->unk6;
        arg1->unkC = arg0->unk4;
        arg1->unkD = arg0->unk5;
        arg1->unkE = arg0->unk6;
        arg1->unk68 = *(u16 *) &arg0->unkA;
        arg1->unk6A = *(u16 *) &arg0->unkC;
        arg1->unk6C = *(u16 *) &arg0->unkE;
        arg1->unk70 = *(u16 *) &arg0->unk8;
        arg1->unk72 = *(u16 *) &arg0->unk8;
        arg1->unk74 = *(u16 *) &arg0->unk8;
        return 0x10;
    case 0x30000406:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109AC);
        }
        arg1->unk4 = arg0->unk4;
        arg1->unk5 = arg0->unk5;
        arg1->unk6 = arg0->unk6;
        arg1->unk8 = arg0->unk4;
        arg1->unk9 = arg0->unk5;
        arg1->unkA = arg0->unk6;
        arg1->unkC = arg0->unk4;
        arg1->unkD = arg0->unk5;
        arg1->unkE = arg0->unk6;
        arg1->unk68 = *(u16 *) &arg0->unkA;
        arg1->unk6A = *(u16 *) &arg0->unkE;
        arg1->unk6C = *(u16 *) &arg0->unk12;
        arg1->unk70 = *(u16 *) &arg0->unk8;
        arg1->unk72 = *(u16 *) &arg0->unkC;
        arg1->unk74 = *(u16 *) &arg0->unk10;
        return 0x14;
    case 0x24000507:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109B4);
        }
        arg1->unk14 = *(u16 *) &arg0->unkA;
        arg1->unk16 = *(u16 *) &arg0->unk6;
        arg1->unk18 = arg0->unk4;
        arg1->unk19 = arg0->unk5;
        arg1->unk1A = arg0->unk8;
        arg1->unk1B = arg0->unk9;
        arg1->unk1C = arg0->unkC;
        arg1->unk1D = arg0->unkD;
        arg1->unk68 = *(u16 *) &arg0->unk12;
        arg1->unk6A = *(u16 *) &arg0->unk14;
        arg1->unk6C = *(u16 *) &arg0->unk16;
        arg1->unk70 = *(u16 *) &arg0->unk10;
        arg1->unk72 = *(u16 *) &arg0->unk10;
        arg1->unk74 = *(u16 *) &arg0->unk10;
        return 0x18;
    case 0x34000609:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109BC);
        }
        arg1->unk14 = *(u16 *) &arg0->unkA;
        arg1->unk16 = *(u16 *) &arg0->unk6;
        arg1->unk18 = arg0->unk4;
        arg1->unk19 = arg0->unk5;
        arg1->unk1A = arg0->unk8;
        arg1->unk1B = arg0->unk9;
        arg1->unk1C = arg0->unkC;
        arg1->unk1D = arg0->unkD;
        arg1->unk68 = *(u16 *) &arg0->unk12;
        arg1->unk6A = *(u16 *) &arg0->unk16;
        arg1->unk6C = *(u16 *) &arg0->unk1A;
        arg1->unk70 = *(u16 *) &arg0->unk10;
        arg1->unk72 = *(u16 *) &arg0->unk14;
        arg1->unk74 = *(u16 *) &arg0->unk18;
        return 0x1C;
    case 0x21010304:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109C4);
        }
        arg1->unk4 = arg0->unk4;
        arg1->unk5 = arg0->unk5;
        arg1->unk6 = arg0->unk6;
        arg1->unk8 = arg0->unk4;
        arg1->unk9 = arg0->unk5;
        arg1->unkA = arg0->unk6;
        arg1->unkC = arg0->unk4;
        arg1->unkD = arg0->unk5;
        arg1->unkE = arg0->unk6;
        arg1->unk68 = *(u16 *) &arg0->unk8;
        arg1->unk6A = *(u16 *) &arg0->unkA;
        arg1->unk6C = *(u16 *) &arg0->unkC;
        return 0x10;
    case 0x31010506:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109C8);
        }
        arg1->unk4 = arg0->unk4;
        arg1->unk5 = arg0->unk5;
        arg1->unk6 = arg0->unk6;
        arg1->unk8 = arg0->unk8;
        arg1->unk9 = arg0->unk9;
        arg1->unkA = arg0->unkA;
        arg1->unkC = arg0->unkC;
        arg1->unkD = arg0->unkD;
        arg1->unkE = arg0->unkE;
        arg1->unk68 = *(u16 *) &arg0->unk10;
        arg1->unk6A = *(u16 *) &arg0->unk12;
        arg1->unk6C = *(u16 *) &arg0->unk14;
        return 0x18;
    case 0x25010607:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109CC);
        }
        arg1->unk14 = *(u16 *) &arg0->unkA;
        arg1->unk16 = *(u16 *) &arg0->unk6;
        arg1->unk18 = arg0->unk4;
        arg1->unk19 = arg0->unk5;
        arg1->unk1A = arg0->unk8;
        arg1->unk1B = arg0->unk9;
        arg1->unk1C = arg0->unkC;
        arg1->unk1D = arg0->unkD;
        arg1->unk4 = arg0->unk10;
        arg1->unk5 = arg0->unk11;
        arg1->unk6 = arg0->unk12;
        arg1->unk8 = arg0->unk10;
        arg1->unk9 = arg0->unk11;
        arg1->unkA = arg0->unk12;
        arg1->unkC = arg0->unk10;
        arg1->unkD = arg0->unk11;
        arg1->unkE = arg0->unk12;
        arg1->unk68 = *(u16 *) &arg0->unk14;
        arg1->unk6A = *(u16 *) &arg0->unk16;
        arg1->unk6C = *(u16 *) &arg0->unk18;
        return 0x1C;
    case 0x35010809:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109D4);
        }
        arg1->unk14 = *(u16 *) &arg0->unkA;
        arg1->unk16 = *(u16 *) &arg0->unk6;
        arg1->unk18 = arg0->unk4;
        arg1->unk19 = arg0->unk5;
        arg1->unk1A = arg0->unk8;
        arg1->unk1B = arg0->unk9;
        arg1->unk1C = arg0->unkC;
        arg1->unk1D = arg0->unkD;
        arg1->unk68 = *(u16 *) &arg0->unk1C;
        arg1->unk6A = *(u16 *) &arg0->unk1E;
        arg1->unk6C = *(u16 *) &arg0->unk20;
        arg1->unk4 = arg0->unk10;
        arg1->unk5 = arg0->unk11;
        arg1->unk6 = arg0->unk12;
        arg1->unk8 = arg0->unk14;
        arg1->unk9 = arg0->unk15;
        arg1->unkA = arg0->unk16;
        arg1->unkC = arg0->unk18;
        arg1->unkD = arg0->unk19;
        arg1->unkE = arg0->unk1A;
        return 0x24;
    case 0x28000405:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109DC);
        }
        arg1->unk4 = arg0->unk4;
        arg1->unk5 = arg0->unk5;
        arg1->unk6 = arg0->unk6;
        arg1->unk8 = arg0->unk4;
        arg1->unk9 = arg0->unk5;
        arg1->unkA = arg0->unk6;
        arg1->unkC = arg0->unk4;
        arg1->unkD = arg0->unk5;
        arg1->unkE = arg0->unk6;
        arg1->unk10 = arg0->unk4;
        arg1->unk11 = arg0->unk5;
        arg1->unk12 = arg0->unk6;
        arg1->unk68 = *(u16 *) &arg0->unkA;
        arg1->unk6A = *(u16 *) &arg0->unkC;
        arg1->unk6C = *(u16 *) &arg0->unkE;
        arg1->unk6E = *(u16 *) &arg0->unk10;
        arg1->unk70 = *(u16 *) &arg0->unk8;
        arg1->unk72 = *(u16 *) &arg0->unk8;
        arg1->unk74 = *(u16 *) &arg0->unk8;
        arg1->unk76 = *(u16 *) &arg0->unk8;
        return 0x14;
    case 0x38000508:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109E4);
        }
        arg1->unk4 = arg0->unk4;
        arg1->unk5 = arg0->unk5;
        arg1->unk6 = arg0->unk6;
        arg1->unk8 = arg0->unk4;
        arg1->unk9 = arg0->unk5;
        arg1->unkA = arg0->unk6;
        arg1->unkC = arg0->unk4;
        arg1->unkD = arg0->unk5;
        arg1->unkE = arg0->unk6;
        arg1->unk10 = arg0->unk4;
        arg1->unk11 = arg0->unk5;
        arg1->unk12 = arg0->unk6;
        arg1->unk68 = *(u16 *) &arg0->unkA;
        arg1->unk6A = *(u16 *) &arg0->unkE;
        arg1->unk6C = *(u16 *) &arg0->unk12;
        arg1->unk6E = *(u16 *) &arg0->unk16;
        arg1->unk70 = *(u16 *) &arg0->unk8;
        arg1->unk72 = *(u16 *) &arg0->unkC;
        arg1->unk74 = *(u16 *) &arg0->unk10;
        arg1->unk76 = *(u16 *) &arg0->unk14;
        return 0x18;
    case 0x2C000709:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109EC);
        }
        arg1->unk14 = *(u16 *) &arg0->unkA;
        arg1->unk16 = *(u16 *) &arg0->unk6;
        arg1->unk18 = arg0->unk4;
        arg1->unk19 = arg0->unk5;
        arg1->unk1A = arg0->unk8;
        arg1->unk1B = arg0->unk9;
        arg1->unk1C = arg0->unkC;
        arg1->unk1D = arg0->unkD;
        arg1->unk1E = arg0->unk10;
        arg1->unk1F = arg0->unk11;
        arg1->unk68 = *(u16 *) &arg0->unk16;
        arg1->unk6A = *(u16 *) &arg0->unk18;
        arg1->unk6C = *(u16 *) &arg0->unk1A;
        arg1->unk6E = *(u16 *) &arg0->unk1C;
        arg1->unk70 = *(u16 *) &arg0->unk14;
        arg1->unk72 = *(u16 *) &arg0->unk14;
        arg1->unk74 = *(u16 *) &arg0->unk14;
        arg1->unk76 = *(u16 *) &arg0->unk14;
        return 0x20;
    case 0x3C00080C:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109F4);
        }
        arg1->unk14 = *(u16 *) &arg0->unkA;
        arg1->unk16 = *(u16 *) &arg0->unk6;
        arg1->unk18 = arg0->unk4;
        arg1->unk19 = arg0->unk5;
        arg1->unk1A = arg0->unk8;
        arg1->unk1B = arg0->unk9;
        arg1->unk1C = arg0->unkC;
        arg1->unk1D = arg0->unkD;
        arg1->unk1E = arg0->unk10;
        arg1->unk1F = arg0->unk11;
        arg1->unk68 = *(u16 *) &arg0->unk16;
        arg1->unk6A = *(u16 *) &arg0->unk1A;
        arg1->unk6C = *(u16 *) &arg0->unk1E;
        arg1->unk6E = *(u16 *) &arg0->unk22;
        arg1->unk70 = *(u16 *) &arg0->unk14;
        arg1->unk72 = *(u16 *) &arg0->unk18;
        arg1->unk74 = *(u16 *) &arg0->unk1C;
        arg1->unk76 = *(u16 *) &arg0->unk20;
        return 0x24;
    case 0x29010305:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_800109FC);
        }
        arg1->unk4 = arg0->unk4;
        arg1->unk5 = arg0->unk5;
        arg1->unk6 = arg0->unk6;
        arg1->unk8 = arg0->unk4;
        arg1->unk9 = arg0->unk5;
        arg1->unkA = arg0->unk6;
        arg1->unkC = arg0->unk4;
        arg1->unkD = arg0->unk5;
        arg1->unkE = arg0->unk6;
        arg1->unk10 = arg0->unk4;
        arg1->unk11 = arg0->unk5;
        arg1->unk12 = arg0->unk6;
        arg1->unk68 = *(u16 *) &arg0->unk8;
        arg1->unk6A = *(u16 *) &arg0->unkA;
        arg1->unk6C = *(u16 *) &arg0->unkC;
        arg1->unk6E = *(u16 *) &arg0->unkE;
        return 0x10;
    case 0x39010608:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_80010A00);
        }
        arg1->unk4 = arg0->unk4;
        arg1->unk5 = arg0->unk5;
        arg1->unk6 = arg0->unk6;
        arg1->unk8 = arg0->unk8;
        arg1->unk9 = arg0->unk9;
        arg1->unkA = arg0->unkA;
        arg1->unkC = arg0->unkC;
        arg1->unkD = arg0->unkD;
        arg1->unkE = arg0->unkE;
        arg1->unk10 = arg0->unk10;
        arg1->unk11 = arg0->unk11;
        arg1->unk12 = arg0->unk12;
        arg1->unk68 = *(u16 *) &arg0->unk14;
        arg1->unk6A = *(u16 *) &arg0->unk16;
        arg1->unk6C = *(u16 *) &arg0->unk18;
        arg1->unk6E = *(u16 *) &arg0->unk1A;
        return 0x1C;
    case 0x2D010709:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_80010A04);
        }
        arg1->unk14 = *(u16 *) &arg0->unkA;
        arg1->unk16 = *(u16 *) &arg0->unk6;
        arg1->unk18 = arg0->unk4;
        arg1->unk19 = arg0->unk5;
        arg1->unk1A = arg0->unk8;
        arg1->unk1B = arg0->unk9;
        arg1->unk1C = arg0->unkC;
        arg1->unk1D = arg0->unkD;
        arg1->unk1E = arg0->unk10;
        arg1->unk1F = arg0->unk11;
        arg1->unk4 = arg0->unk14;
        arg1->unk5 = arg0->unk15;
        arg1->unk6 = arg0->unk16;
        arg1->unk8 = arg0->unk14;
        arg1->unk9 = arg0->unk15;
        arg1->unkA = arg0->unk16;
        arg1->unkC = arg0->unk14;
        arg1->unkD = arg0->unk15;
        arg1->unkE = arg0->unk16;
        arg1->unk10 = arg0->unk14;
        arg1->unk11 = arg0->unk15;
        arg1->unk12 = arg0->unk16;
        arg1->unk68 = *(u16 *) &arg0->unk18;
        arg1->unk6A = *(u16 *) &arg0->unk1A;
        arg1->unk6C = *(u16 *) &arg0->unk1C;
        arg1->unk6E = *(u16 *) &arg0->unk1E;
        return 0x20;
    case 0x3D010A0C:
        if (SYSGetGraphDebug() == 2) {
            func_8002232C(D_80010A0C);
        }
        arg1->unk14 = *(u16 *) &arg0->unkA;
        arg1->unk16 = *(u16 *) &arg0->unk6;
        arg1->unk18 = arg0->unk4;
        arg1->unk19 = arg0->unk5;
        arg1->unk1A = arg0->unk8;
        arg1->unk1B = arg0->unk9;
        arg1->unk1C = arg0->unkC;
        arg1->unk1D = arg0->unkD;
        arg1->unk1E = arg0->unk10;
        arg1->unk1F = arg0->unk11;
        arg1->unk68 = *(u16 *) &arg0->unk24;
        arg1->unk6A = *(u16 *) &arg0->unk26;
        arg1->unk6C = *(u16 *) &arg0->unk28;
        arg1->unk6E = *(u16 *) &arg0->unk2A;
        arg1->unk4 = arg0->unk14;
        arg1->unk5 = arg0->unk15;
        arg1->unk6 = arg0->unk16;
        arg1->unk8 = arg0->unk18;
        arg1->unk9 = arg0->unk19;
        arg1->unkA = arg0->unk1A;
        arg1->unkC = arg0->unk1C;
        arg1->unkD = arg0->unk1D;
        arg1->unkE = arg0->unk1E;
        arg1->unk10 = arg0->unk20;
        arg1->unk11 = arg0->unk21;
        arg1->unk12 = arg0->unk22;
        return 0x2C;
    default:
        func_8002232C(D_80010A14, arg1->unk0 & 0xFDFFFFFF);
        return -1;
    }
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_80028740);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_8002875C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_80028760);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_8002877C);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80028780);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800287B8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800287C4);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800287C8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800287D4);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_800287D8);

extern void func_80022034(void);
extern void func_80022044(void);
extern void func_800220F4(s32);
extern void func_800288A4(void);

void CardStartCARDEarlysafe(void) {
    func_80022034();
    func_800288A4();
    func_800220F4(0);
    func_80022044();
}

extern void func_800288B4(void);
extern void func_800289D4(void);
extern void func_80028A64(void);

void CardStopCARDEarlysafe(void) {
    func_800288B4();
    func_800289D4();
    func_80028A64();
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_80028894);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800288A0);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800288A4);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800288B0);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800288B4);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_800288C0);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_800288C4);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", D_800288D8);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_8002891C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_800289A4);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_800289D4);

void func_80028A40(void) {
    {
        register int t asm("t6") = 0x320000;
        do {
            t--;
        } while (t != 0);
        FORCE_REG(t);
    }
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80028A58);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80028A5C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", pad_80028A60);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_3", func_80028A64);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", D_80028ACC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", D_80028AD8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_3", func_80028AE4);
