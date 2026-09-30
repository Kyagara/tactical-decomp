#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();
extern void SetDrawMode();
extern u8 D_800D0BBC[];
extern u8 D_8004EAF4[];
extern void func_800246D4(s32);
extern void DrawSync(s32);
extern void SetAllVoicesReleaseShiftTo6(void);
extern void func_80019448(void);
void MRTAUnloadScenarioMusicAndPlayTunes(void);
void func_800449EC(void);
void func_80044ACC(void);
void func_800452EC(void);
void func_80045514(void);
void AccumulateChannelsToPause();
void CallFree();
s32 CallBuildFileHeader(s32 arg0, u32 arg1, s32 arg2);

void GameResetQuitSound(void) {
    func_800246D4(0);
    func_800246D4(0);
    DrawSync(0);
    SetAllVoicesReleaseShiftTo6();
    func_80019448();
}

extern u8 D_80047608[];
extern void func_80011BC0(void *);

void GameReset(void) {
    GameResetQuitSound();
    func_80011BC0(&D_80047608);
}

extern void func_80010BA8(void);

void CallBATTLEBINEntrypoint(void) {
    func_80010BA8();
}

extern u32 D_80010000;
extern u32 D_80010010;

void OpenExecBATTLEBIN(void) {
    GetDATAsWD(0x3E8, D_80010010 - D_80010000, D_80010000);
    CallBATTLEBINEntrypoint();
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_4", .L80040A00);

extern void func_80010AD0(void);
extern void Startup(void);
extern void PutStackPointer(void *);
extern void func_80040A00(void);
extern void func_8001DB88(void);
extern void ETCStopCallback(void);

void Main(void) {
    func_80010AD0();
    Startup();
    PutStackPointer(&D_80047608);
    func_80040A00();
    func_8001DB88();
    ETCStopCallback();
}

extern void P10SetSemiTrans(GpuPacket *, s32);
extern s16 func_80022D78(u8 *, s32, s32, u8 *);
extern u8 D_800459E0[];
extern s32 D_8004760C;
/* Keep these scalar: a NowLoadingPrim struct overlay lets GCC CSE address
 * materialization across stores (e.g. sh via blk) and breaks byte-match. */
extern int D_8004D720;
extern s32 D_8004E5B8;
extern u8 D_8004D748[];
extern u8 D_8004D770[];
extern u8 D_8004D798[];
extern u8 D_8004D7C0[];
extern u8 D_8004D7E8[];
extern u8 D_8004D810[];
extern u8 D_8004D723;
extern u8 D_8004D724;
extern u8 D_8004D725;
extern u8 D_8004D726;
extern u8 D_8004D727;
extern s16 D_8004D728;
extern s16 D_8004D72A;
extern u8 D_8004D72C;
extern u8 D_8004D72D;
extern s16 D_8004D72E;
extern s16 D_8004D730;
extern s16 D_8004D732;
extern u8 D_8004D734;
extern u8 D_8004D735;
extern s16 D_8004D736;
extern s16 D_8004D738;
extern s16 D_8004D73A;
extern u8 D_8004D73C;
extern u8 D_8004D73D;
extern s16 D_8004D740;
extern s16 D_8004D742;
extern u8 D_8004D744;
extern u8 D_8004D745;
extern s16 D_8004D750;
extern s16 D_8004D752;
extern u8 D_8004D754;
extern u8 D_8004D755;
extern s16 D_8004D758;
extern s16 D_8004D75A;
extern u8 D_8004D75C;
extern u8 D_8004D75D;
extern s16 D_8004D760;
extern s16 D_8004D762;
extern u8 D_8004D764;
extern u8 D_8004D765;
extern s16 D_8004D768;
extern s16 D_8004D76A;
extern u8 D_8004D76C;
extern u8 D_8004D76D;
extern s16 D_8004D778;
extern s16 D_8004D77A;
extern u8 D_8004D77C;
extern u8 D_8004D77D;
extern s16 D_8004D780;
extern s16 D_8004D782;
extern u8 D_8004D784;
extern u8 D_8004D785;
extern s16 D_8004D788;
extern s16 D_8004D78A;
extern u8 D_8004D78C;
extern u8 D_8004D78D;
extern s16 D_8004D790;
extern s16 D_8004D792;
extern u8 D_8004D794;
extern u8 D_8004D795;
extern s16 D_8004D7A0;
extern s16 D_8004D7A2;
extern u8 D_8004D7A4;
extern u8 D_8004D7A5;
extern s16 D_8004D7A8;
extern s16 D_8004D7AA;
extern u8 D_8004D7AC;
extern u8 D_8004D7AD;
extern s16 D_8004D7B0;
extern s16 D_8004D7B2;
extern u8 D_8004D7B4;
extern u8 D_8004D7B5;
extern s16 D_8004D7B8;
extern s16 D_8004D7BA;
extern u8 D_8004D7BC;
extern u8 D_8004D7BD;
extern s16 D_8004D7C8;
extern s16 D_8004D7CA;
extern u8 D_8004D7CC;
extern u8 D_8004D7CD;
extern s16 D_8004D7D0;
extern s16 D_8004D7D2;
extern u8 D_8004D7D4;
extern u8 D_8004D7D5;
extern s16 D_8004D7D8;
extern s16 D_8004D7DA;
extern u8 D_8004D7DC;
extern u8 D_8004D7DD;
extern s16 D_8004D7E0;
extern s16 D_8004D7E2;
extern u8 D_8004D7E4;
extern u8 D_8004D7E5;
extern s16 D_8004D7F0;
extern s16 D_8004D7F2;
extern u8 D_8004D7F4;
extern u8 D_8004D7F5;
extern s16 D_8004D7F8;
extern s16 D_8004D7FA;
extern u8 D_8004D7FC;
extern u8 D_8004D7FD;
extern s16 D_8004D800;
extern s16 D_8004D802;
extern u8 D_8004D804;
extern u8 D_8004D805;
extern s16 D_8004D808;
extern s16 D_8004D80A;
extern u8 D_8004D80C;
extern u8 D_8004D80D;
extern s16 D_8004D818;
extern s16 D_8004D81A;
extern u8 D_8004D81C;
extern u8 D_8004D81D;
extern s16 D_8004D820;
extern s16 D_8004D822;
extern u8 D_8004D824;
extern u8 D_8004D825;
extern s16 D_8004D828;
extern s16 D_8004D82A;
extern u8 D_8004D82C;
extern u8 D_8004D82D;
extern s16 D_8004D830;
extern s16 D_8004D832;
extern u8 D_8004D834;
extern u8 D_8004D835;

typedef struct {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
} WordCopy16;

typedef struct {
    s32 w0;
    s32 w1;
    s32 w2;
} WordCopy12;

typedef struct {
    s32 w0;
    s32 w1;
} WordCopy8;

typedef struct {
    char d[8];
} Blob8;

void BuildNowLoading(s32 show, s32 baseX, s32 baseY) {
    u8 *pos;
    register s32 idx asm("t1");
    u8 *end;
    u8 *pkts;
    u8 *src;
    u8 *dst;
    s16 valC;
    s16 valB;
    s16 valA;
    u8 *blk;
    pkts = (u8 *) &D_8004D720;
    D_8004760C = show;
    D_8004D723 = 9;
    D_8004D727 = 0x2C;
    D_8004E5B8 = 0;
    D_8004D724 = 0x80;
    D_8004D725 = 0x80;
    D_8004D726 = 0x80;
    P10SetSemiTrans((GpuPacket *) &D_8004D720, 0);
    idx = 1;
    end = (u8 *) &D_8004D720 + 0x20;
    pos = (u8 *) &D_8004D720 + 0x28;
    D_8004D736 = 0x1F;
    D_8004D72E = 0x7887;
    do {
        dst = pos;
        src = pkts;
        do {
            *(WordCopy16 *) dst = *(WordCopy16 *) src;
            src += 0x10;
            dst += 0x10;
        } while (src != end);
        *(WordCopy8 *) dst = *(WordCopy8 *) src;
        idx += 1;
        pos += 0x28;
    } while (idx < 7);
    blk = (u8 *) &D_8004D720;
    dst = blk + 0x118;
    src = blk;
    pos = src + 0x20;
    valA = baseX + 0xA0;
    valB = baseY + 0xC8;
    valC = baseX + 0xAC;
    D_8004D72A = valB;
    D_8004D732 = valB;
    valB = baseY + 0xD0;
    D_8004D728 = valA;
    D_8004D738 = valA;
    valA = 0xE4;
    D_8004D73A = valB;
    D_8004D742 = valB;
    valB = 0x9B;
    D_8004D730 = valC;
    D_8004D740 = valC;
    valC = 0xF0;
    D_8004D72D = valB;
    D_8004D735 = valB;
    valB = 0xA3;
    D_8004D72C = valA;
    D_8004D734 = valC;
    D_8004D73C = valA;
    D_8004D73D = valB;
    D_8004D744 = valC;
    D_8004D745 = valB;
    do {
        *(WordCopy16 *) dst = *(WordCopy16 *) src;
        src += 0x10;
        dst += 0x10;
    } while (src != pos);
    *(WordCopy8 *) dst = *(WordCopy8 *) src;
    blk = D_8004D748;
    dst = blk + 0x118;
    src = blk;
    pos = src + 0x20;
    valA = baseX + 0xAB;
    valB = baseY + 0xC8;
    valC = baseX + 0xB2;
    D_8004D752 = valB;
    D_8004D75A = valB;
    valB = baseY + 0xD0;
    D_8004D750 = valA;
    D_8004D760 = valA;
    valA = 0xE4;
    D_8004D762 = valB;
    D_8004D76A = valB;
    valB = 0xA3;
    D_8004D758 = valC;
    D_8004D768 = valC;
    valC = 0xEB;
    D_8004D755 = valB;
    D_8004D75D = valB;
    valB = 0xAB;
    D_8004D754 = valA;
    D_8004D75C = valC;
    D_8004D764 = valA;
    D_8004D765 = valB;
    D_8004D76C = valC;
    D_8004D76D = valB;
    do {
        *(WordCopy16 *) dst = *(WordCopy16 *) src;
        src += 0x10;
        dst += 0x10;
    } while (src != pos);
    *(WordCopy8 *) dst = *(WordCopy8 *) src;
    blk = D_8004D770;
    dst = blk + 0x118;
    src = blk;
    pos = src + 0x20;
    valA = baseX + 0xB7;
    valB = baseY + 0xC8;
    valC = baseX + 0xC3;
    D_8004D77A = valB;
    D_8004D782 = valB;
    valB = baseY + 0xD0;
    D_8004D778 = valA;
    D_8004D788 = valA;
    valA = 0xAD;
    D_8004D78A = valB;
    D_8004D792 = valB;
    valB = 0x55;
    D_8004D780 = valC;
    D_8004D790 = valC;
    valC = 0xB9;
    D_8004D77D = valB;
    D_8004D785 = valB;
    valB = 0x5D;
    D_8004D77C = valA;
    D_8004D784 = valC;
    D_8004D78C = valA;
    D_8004D78D = valB;
    D_8004D794 = valC;
    D_8004D795 = valB;
    do {
        *(WordCopy16 *) dst = *(WordCopy16 *) src;
        src += 0x10;
        dst += 0x10;
    } while (src != pos);
    *(WordCopy8 *) dst = *(WordCopy8 *) src;
    blk = D_8004D798;
    dst = blk + 0x118;
    src = blk;
    pos = src + 0x20;
    valA = baseX + 0xC3;
    valB = baseY + 0xC8;
    valC = baseX + 0xC8;
    D_8004D7A2 = valB;
    D_8004D7AA = valB;
    valB = baseY + 0xD0;
    D_8004D7A0 = valA;
    D_8004D7B0 = valA;
    valA = 0xD1;
    D_8004D7B2 = valB;
    D_8004D7BA = valB;
    valB = 0x60;
    D_8004D7A8 = valC;
    D_8004D7B8 = valC;
    valC = 0xD6;
    D_8004D7A5 = valB;
    D_8004D7AD = valB;
    valB = 0x68;
    D_8004D7A4 = valA;
    D_8004D7AC = valC;
    D_8004D7B4 = valA;
    D_8004D7B5 = valB;
    D_8004D7BC = valC;
    D_8004D7BD = valB;
    do {
        *(WordCopy16 *) dst = *(WordCopy16 *) src;
        src += 0x10;
        dst += 0x10;
    } while (src != pos);
    *(WordCopy8 *) dst = *(WordCopy8 *) src;
    blk = D_8004D7C0;
    dst = blk + 0x118;
    src = blk;
    pos = src + 0x20;
    valA = baseX + 0xC7;
    valB = baseY + 0xC8;
    valC = baseX + 0xCA;
    D_8004D7CA = valB;
    D_8004D7D2 = valB;
    valB = baseY + 0xD0;
    D_8004D7C8 = valA;
    D_8004D7D8 = valA;
    valA = 0x7C;
    D_8004D7DA = valB;
    D_8004D7E2 = valB;
    valB = 0x52;
    D_8004D7D0 = valC;
    D_8004D7E0 = valC;
    valC = 0x7F;
    D_8004D7CD = valB;
    D_8004D7D5 = valB;
    valB = 0x5A;
    D_8004D7CC = valA;
    D_8004D7D4 = valC;
    D_8004D7DC = valA;
    D_8004D7DD = valB;
    D_8004D7E4 = valC;
    D_8004D7E5 = valB;
    do {
        *(WordCopy16 *) dst = *(WordCopy16 *) src;
        src += 0x10;
        dst += 0x10;
    } while (src != pos);
    *(WordCopy8 *) dst = *(WordCopy8 *) src;
    blk = D_8004D7E8;
    dst = blk + 0x118;
    src = blk;
    pos = src + 0x20;
    valA = baseX + 0xC9;
    valB = baseY + 0xC8;
    valC = baseX + 0xCE;
    D_8004D7F2 = valB;
    D_8004D7FA = valB;
    valB = baseY + 0xD0;
    D_8004D7F0 = valA;
    D_8004D800 = valA;
    valA = 0xCE;
    D_8004D802 = valB;
    D_8004D80A = valB;
    valB = 0xCC;
    D_8004D7F8 = valC;
    D_8004D808 = valC;
    valC = 0xD3;
    D_8004D7F5 = valB;
    D_8004D7FD = valB;
    valB = 0xD4;
    D_8004D7F4 = valA;
    D_8004D7FC = valC;
    D_8004D804 = valA;
    D_8004D805 = valB;
    D_8004D80C = valC;
    D_8004D80D = valB;
    do {
        *(WordCopy16 *) dst = *(WordCopy16 *) src;
        src += 0x10;
        dst += 0x10;
    } while (src != pos);
    *(WordCopy8 *) dst = *(WordCopy8 *) src;
    blk = D_8004D810;
    dst = blk + 0x118;
    src = blk;
    pos = src + 0x20;
    valA = baseX + 0xCD;
    valB = baseY + 0xCA;
    valC = baseX + 0xD2;
    D_8004D81A = valB;
    D_8004D822 = valB;
    valB = baseY + 0xD2;
    D_8004D818 = valA;
    D_8004D828 = valA;
    valA = 0xEB;
    D_8004D82A = valB;
    D_8004D832 = valB;
    valB = 0xA4;
    D_8004D820 = valC;
    D_8004D830 = valC;
    valC = 0xF0;
    D_8004D81D = valB;
    D_8004D825 = valB;
    valB = 0xAC;
    D_8004D81C = valA;
    D_8004D824 = valC;
    D_8004D82C = valA;
    D_8004D82D = valB;
    D_8004D834 = valC;
    D_8004D835 = valB;
    do {
        *(WordCopy16 *) dst = *(WordCopy16 *) src;
        src += 0x10;
        dst += 0x10;
    } while (src != pos);
    *(WordCopy8 *) dst = *(WordCopy8 *) src;
    func_80022D78(D_800459E0, 0x70, 0x1E2, dst);
}

extern void BuildNowLoading(s32, s32, s32);

void BuildNowLoadingCentre(s32 arg0) {
    BuildNowLoading(arg0, 0x80, 0);
}

extern s32 D_8004597C;
extern void DumpClut(s32 *, s32 *);

void NowLoadingIntoOTAG(s32 arg0) {
    u8 *var_s0;
    s32 var_s1;

    if (D_8004760C != 0) {
        if (!(((D_8004E5B8 & 0xFFFFFFFF) / 60) & 1)) {
            var_s1 = 0;
            var_s0 = (u8 *) &D_8004D720;
            do {
                var_s1 += 1;
                DumpClut((s32 *) arg0, (void *) ((D_8004597C * 0x118) + (s32) var_s0));
                var_s0 += 0x28;
            } while (var_s1 < 7);
        }
        D_8004E5B8 += 1;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 *unk8;
    s16 *unkC;
    u8 *unk10;
} GetEFCFNT_buf;

extern void FntPrint(s32, s32);
extern u8 func_80022F2C_patch[] asm("FntPrint");
extern s32 func_80026FA4(s32);
extern s32 ReadTIM(u8 *);
extern s32 GetBINAsTIM();
extern void func_80022C24(u8 *, s32, s32, s32, s32, s32, s32);
extern s32 func_8001DBA8(s32);
extern void func_80011E38(u8 *);
extern s32 func_80022FD0(s32, s32, s32, s32, s32, s32);
extern void FONTSetDumpFnt(s32);

void GetEFCFNT(void) {
    GetEFCFNT_buf buf;
    s32 s0;
    s32 flag;

    flag = 0;
    func_80022F2C_patch[0x30] = 0x7F;
    FntPrint(0x280, 0);
    do {
        s0 = GetBINAsTIM(0xDEA8, 0x8800);
        if (s0 != 0) {
            if ((func_80026FA4(s0) == 0) && (ReadTIM((u8 *) &buf) != 0)) {
                func_80022C24(buf.unk10, 0, 0, 0x280, 0, buf.unkC[2] * 4, buf.unkC[3]);
                flag = 1;
                ((s16 (*)(u8 *, s32, s32)) func_80022D78)(buf.unk8, 0x280, 0x7F);
            }
            CallFree(s0);
        } else {
            func_8001DBA8(0);
            func_80011E38(D_8004EAF4);
        }
    } while (flag == 0);
    FONTSetDumpFnt(func_80022FD0(0x88, 0x10, 0x100, 0x100, 0, 0x200));
    func_800246D4(0);
    func_800246D4(0);
}

extern void StoreScreenOffsetsToGTE(s32, s32);
extern void func_8001D1C8(s32);
extern void func_80022DE0(void *, s32, s32, s32, s32);
extern void func_80022EB0(void *, s32, s32, s32, s32);
extern void func_80024E84(void *);
extern void GetGraphType(void *);
extern u8 D_8004091C[];
extern DrawEnv D_8004EA14[2];
extern MixerState D_8004EACC[2];
extern u8 D_8004EA86;
extern u8 D_8004EA2A;
extern u8 D_8004EA88;
extern u8 D_8004EA2C;
extern u8 D_8004EA2D;
extern u8 D_8004EA89;
extern u8 D_8004EA2E;
extern u8 D_8004EA2F;
extern u8 D_8004EA8A;
extern u8 D_8004EA8B;

void SetDisplayDraw(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5) {
    u8 r06;
    s32 rs2;
    s32 rs1;
    u8 *new_var3;
    s32 rs3;
    register s32 rs5 asm("s5");
    u8 *rs4;
    s32 new_var4;
    s32 new_var2;
    int new_var;
    s32 rs0;
    s32 idx;
    u8 *ba1;
    u8 r07;
    Blob8 fr;
    r06 = arg4;
    r07 = arg5;
    rs2 = arg0;
    rs3 = arg2;
    new_var2 = arg1;
    rs1 = new_var2;
    ba1 = D_8004091C;
    *((Blob8 *) (&fr)) = *((Blob8 *) ba1);
    new_var4 = rs1;

    {
        rs5 = arg3;
        rs0 = (new_var = (char) (((new_var4 ^ 0x1E0) != 0) ? (-1) : (0)));
        rs0 &= 0xF0;
        DrawSync(0);
    }

    {
        s32 t = new_var4 / 2;
        StoreScreenOffsetsToGTE(arg0 / 2, t);
    }
    func_8001D1C8(rs3);
    new_var3 = (u8 *) &D_8004EA14[0];
    func_80022DE0(new_var3, 0, 0, rs2, new_var4);
    rs3 = (s32) &D_8004EACC[0];
    func_80022EB0((void *) rs3, 0, rs0, arg0, new_var4);
    func_80022DE0(new_var3 + 0x5C, 0, rs0, rs2, new_var4);
    func_80022EB0((void *) (rs3 + 0x14), 0, 0, rs2, new_var4);
    idx = D_8004597C;
    D_8004EA86 = 0;
    D_8004EA2A = 0;
    D_8004EA88 = 1;
    D_8004EA2C = 1;
    D_8004EA2D = (u8) rs5;
    D_8004EA89 = (u8) rs5;
    D_8004EA2E = r06;
    D_8004EA2F = r07;
    D_8004EA8A = r06;
    D_8004EA8B = r07;
    func_80024E84(&D_8004EACC[idx]);
    GetGraphType(&D_8004EA14[D_8004597C]);
}

extern u8 D_8004EA16[];
extern void _que(s32);
extern void func_80023288(s32);

s32 DrawSquaresoftLogo(void *arg0, u8 *arg1) {
    s16 sp[4];
    s32 v1tmp;
    s32 temp;

    D_8004597C = D_8004597C == 0;
    func_800246D4(0);
    temp = func_8001DBA8(0);
    func_80024E84(&D_8004EACC[D_8004597C]);
    GetGraphType(&D_8004EA14[D_8004597C]);
    sp[0] = 0x46;
    v1tmp = *(u16 *) &D_8004EA16[D_8004597C * 0x5C] + 0x70;
    sp[2] = 0xB4;
    sp[3] = 0x10;
    sp[1] = v1tmp;
    func_800248FC((char *) sp, (s32) arg1);
    _que((s32) arg0);
    func_80023288(-1);
    return temp;
}

typedef struct {
    s32 v18;
    u8 v1C;
    u8 v1D;
    u8 v1E;
    u8 pad1F;
    u16 v20;
    u16 v22;
    u16 v24;
    u16 v26;
    u16 v28;
    u16 v2A;
    u16 v2C;
    u16 v2E;
    s32 v30;
    s32 v34;
    s32 v38;
    s32 v3C;
    s32 v40;
    s32 v44;
    s32 v48;
    s32 v4C;
    s32 v50;
    s32 v54;
    s32 v58;
    s32 v5C;
    u8 v60[0x10];
    GpuRect v70;
} f41890_Frame;

extern void SetDisplayDraw(s32, s32, s32, s32, u8, u8);
extern void P16SetPolyF4(GpuPacket *);
extern void func_800254CC(s32 *, s32, s32, s32, s16 *);
extern int SetPriority(void *, int);
extern void func_80023BB4(void *, void *);
extern s32 DrawSquaresoftLogo(void *, u8 *);
extern u8 D_80040924[];
extern u8 D_80045A00[];

void BuildDrawSquaresoftLogo(void) {
    register s32 vs0 asm("s0");
    s32 rs1;
    s32 ps2;
    u8 *ps3;
    u8 *ps4;
    s32 tv0;
    f41890_Frame fr;
    u8 *p70;
    s16 c140 asm("v0");

    *(Blob8 *) &fr.v70 = *(Blob8 *) D_80040924;
    ps2 = 0xF8;
    SetDisplayDraw(0x140, 0xF0, 0x200, 0, 0, 0);
    P16SetPolyF4((GpuPacket *) &fr.v18);
    c140 = 0x140;
    rs1 = 0x100;
    fr.v1C = 0;
    fr.v1D = 0;
    fr.v1E = 0;
    fr.v20 = 0;
    fr.v22 = 0;
    fr.v24 = c140;
    fr.v26 = 0;
    fr.v28 = 0;
    fr.v2A = 0x100;
    fr.v2C = c140;
    fr.v2E = rs1;
    P10SetSemiTrans((GpuPacket *) &fr.v18, 1);
    *(WordCopy16 *) &fr.v30 = *(WordCopy16 *) &fr.v18;
    *(WordCopy8 *) &fr.v40 = *(WordCopy8 *) &fr.v28;
    p70 = (u8 *) &fr.v70;
    func_800254CC((s32 *) &fr.v48, 0, 0, 0x40, (s16 *) p70);
    *(WordCopy12 *) &fr.v54 = *(WordCopy12 *) &fr.v48;
    fr.v70.x = 0;
    fr.v70.y = 0;
    fr.v70.w = rs1;
    fr.v70.h = 0x1E0;
    SetDrawMode(p70, 0, 0, 0);
    func_800246D4(0);
    DrawSync(1);
    vs0 = 0;
    do {
        func_8001DBA8(0);
        vs0 += 1;
    } while (vs0 < 0xF);
    if ((ps2 << 16) >= 0) {
        ps4 = &fr.v60[0];
        rs1 = (s32) &fr.v18;
        ps3 = (u8 *) &fr.v48;
        do {
            vs0 = (s32) ps4 + (D_8004597C * 8);
            SetPriority((void *) vs0, 2);
            *(u8 *) ((u8 *) rs1 + (D_8004597C * 0x18) + 4) = (u8) ps2;
            *(u8 *) ((u8 *) rs1 + (D_8004597C * 0x18) + 5) = (u8) ps2;
            *(u8 *) ((u8 *) rs1 + (D_8004597C * 0x18) + 6) = (u8) ps2;
            func_80023BB4((void *) vs0, (u8 *) rs1 + (D_8004597C * 0x18));
            func_80023BB4((void *) vs0, ps3 + (D_8004597C * 0xC));
            DrawSquaresoftLogo((void *) vs0, D_80045A00);
            tv0 = ps2 - 8;
            ps2 = tv0;
            KEEP(tv0);
        } while ((tv0 << 16) >= 0);
    }
    func_800246D4(0);
    func_800246D4(0);
}

typedef struct {
    s32 v18;
    u8 v1C;
    u8 v1D;
    u8 v1E;
    u8 pad1F;
    u16 v20;
    u16 v22;
    u16 v24;
    u16 v26;
    u16 v28;
    u16 v2A;
    u16 v2C;
    u16 v2E;
    s32 v30;
    s32 v34;
    s32 v38;
    s32 v3C;
    s32 v40;
    s32 v44;
    s32 v48;
    s32 v4C;
    s32 v50;
    s32 v54;
    s32 v58;
    s32 v5C;
    u8 v60[0x10];
    GpuRect v70;
} f41B1C_Frame;

void SquaresoftFadeOut(void) {
    register u8 *vs0 asm("s0");
    s32 s1;
    register u8 *ps2 asm("s2");
    u8 *ps3;
    u8 *ps4;
    s32 tv0;
    f41B1C_Frame fr;
    u8 *p70;
    s16 c100;
    s16 c140;

    *(Blob8 *) &fr.v70 = *(Blob8 *) D_80040924;
    s1 = 0;
    P16SetPolyF4((GpuPacket *) &fr.v18);
    c140 = 0x140;
    c100 = 0x100;
    fr.v1C = 0;
    fr.v1D = 0;
    fr.v1E = 0;
    fr.v20 = 0;
    fr.v22 = 0;
    fr.v24 = c140;
    fr.v26 = 0;
    fr.v28 = 0;
    fr.v2A = c100;
    fr.v2C = c140;
    fr.v2E = c100;
    P10SetSemiTrans((GpuPacket *) &fr.v18, 1);
    *(WordCopy16 *) &fr.v30 = *(WordCopy16 *) &fr.v18;
    *(WordCopy8 *) &fr.v40 = *(WordCopy8 *) &fr.v28;
    vs0 = (u8 *) &fr.v48;
    p70 = (u8 *) &fr.v70;
    func_800254CC((s32 *) vs0, 0, 0, 0x40, (s16 *) p70);
    *(WordCopy12 *) &fr.v54 = *(WordCopy12 *) &fr.v48;
    ps4 = &fr.v60[0];
    ps2 = (u8 *) &fr.v18;
    ps3 = vs0;
    do {
        if (((s1 << 16) >> 16) >= 0xF8) {
            s1 = 0xFF;
        }
        vs0 = ps4 + (D_8004597C * 8);
        SetPriority((void *) vs0, 2);
        *(u8 *) ((u8 *) ps2 + (D_8004597C * 0x18) + 4) = (u8) s1;
        *(u8 *) ((u8 *) ps2 + (D_8004597C * 0x18) + 5) = (u8) s1;
        *(u8 *) ((u8 *) ps2 + (D_8004597C * 0x18) + 6) = (u8) s1;
        func_80023BB4((void *) vs0, (u8 *) ps2 + (D_8004597C * 0x18));
        func_80023BB4((void *) vs0, ps3 + (D_8004597C * 0xC));
        DrawSquaresoftLogo((void *) vs0, D_80045A00);
        tv0 = s1 + 8;
        s1 = tv0;
        KEEP(tv0);
    } while (((tv0 << 16) >> 16) < 0x100);
    func_800246D4(0);
    fr.v70.w = 0x100;
    fr.v70.x = 0;
    fr.v70.y = 0;
    fr.v70.h = 0x1E0;
    SetDrawMode((u8 *) &fr.v70, 0, 0, 0);
    func_800246D4(0);
}

s32 DrawSCEAP(void *arg0, u8 *arg1) {
    s16 sp[4];
    s32 v1tmp;
    s32 temp;

    D_8004597C = D_8004597C == 0;
    func_800246D4(0);
    temp = func_8001DBA8(0);
    func_80024E84(&D_8004EACC[D_8004597C]);
    GetGraphType(&D_8004EA14[D_8004597C]);
    sp[0] = 0;
    v1tmp = *(u16 *) &D_8004EA16[D_8004597C * 0x5C] + 0x68;
    sp[2] = 0x140;
    sp[3] = 0x20;
    sp[1] = v1tmp;
    func_800248FC((char *) sp, (s32) arg1);
    _que((s32) arg0);
    func_80023288(-1);
    return temp;
}

typedef struct {
    s32 v18;
    u8 v1C;
    u8 v1D;
    u8 v1E;
    u8 pad1F;
    u16 v20;
    u16 v22;
    u16 v24;
    u16 v26;
    u16 v28;
    u16 v2A;
    u16 v2C;
    u16 v2E;
    s32 v30;
    s32 v34;
    s32 v38;
    s32 v3C;
    s32 v40;
    s32 v44;
    s32 v48;
    s32 v4C;
    s32 v50;
    s32 v54;
    s32 v58;
    s32 v5C;
    u8 v60[0x10];
    GpuRect v70;
} f41E98_Frame;

extern s32 DrawSCEAP(void *, u8 *);
extern s32 GetDATAsWD(s32, s32, s32);

void BuildDrawSCEAP(void) {
    register s32 rs1 asm("s1");
    u8 *ps3;
    u8 *ps4;
    u8 *vs0;
    s32 new_var;
    s32 tv0;
    int new_var2;
    s32 dtmp;
    f41E98_Frame fr;
    s16 cF0 asm("v0");
    *(GpuRect *) &fr.v70 = *(GpuRect *) D_80040924;
    new_var2 = 0xC6;
    SetDisplayDraw(0x140, 0xF0, 0x200, 0, 0, 0);

    {
        new_var = (s32) D_80010010;
        {
            s32 a2t = new_var;
            GetDATAsWD(new_var2, 0x5000, a2t);
            new_var = 0;
        }
    }

    P16SetPolyF4((GpuPacket *) (&fr.v18));
    cF0 = 0xF0;
    fr.v1C = 0;
    fr.v1D = 0;
    fr.v1E = 0;
    fr.v20 = 0;
    fr.v22 = 0;
    fr.v24 = 0x140;
    fr.v26 = 0;
    fr.v28 = 0;
    fr.v2A = cF0;
    fr.v2C = 0x140;
    fr.v2E = cF0;
    P10SetSemiTrans((GpuPacket *) (&fr.v18), 1);
    *((WordCopy16 *) (&fr.v30)) = *((WordCopy16 *) (&fr.v18));
    *((WordCopy8 *) (&fr.v40)) = *((WordCopy8 *) (&fr.v28));
    func_800254CC((s32 *) (&fr.v48), 0, 0, 0x40, (s16 *) &fr.v70);
    *((WordCopy12 *) (&fr.v54)) = *((WordCopy12 *) (&fr.v48));
    fr.v70.x = 0;
    fr.v70.y = 0;
    fr.v70.w = 0x140;
    fr.v70.h = 0x1E0;
    SetDrawMode((u8 *) &fr.v70, 0, 0, 0);
    func_800246D4(0);
    DrawSync(1);
    do {
        func_8001DBA8(0);
        new_var += 1;
        rs1 = 0xF8;
    } while (new_var < 0xF);
    ps4 = &fr.v60[0];
    new_var = (s32) (&fr.v18);
    ps3 = (u8 *) (&fr.v48);
    do {
        dtmp = D_8004597C << 3;
        vs0 = ps4 + dtmp;
        SetPriority((void *) vs0, 2);
        *((u8 *) ((((u8 *) new_var) + (D_8004597C * 0x18)) + 4)) = (u8) rs1;
        *((u8 *) ((((u8 *) new_var) + (D_8004597C * 0x18)) + 5)) = (u8) rs1;
        *((u8 *) ((((u8 *) new_var) + (D_8004597C * 0x18)) + 6)) = (u8) rs1;
        func_80023BB4((void *) vs0, ((u8 *) new_var) + (D_8004597C * 0x18));
        func_80023BB4((void *) vs0, ps3 + (D_8004597C * 0xC));
        DrawSCEAP((void *) vs0, (u8 *) D_80010010);
        tv0 = rs1 - 8;
        rs1 = tv0;
        KEEP(tv0);
    } while (((tv0 << 13) << 3) >= 0);
    new_var = 0;
    do {
        func_8001DBA8(0);
        new_var += 1;
    } while (new_var < 0xB4);
    rs1 = 0;
    ps4 = &fr.v60[0];
    new_var = (s32) (&fr.v18);
    ps3 = (u8 *) (&fr.v48);
    do {
        if (((rs1 << 16) >> 16) >= 0xF8) {
            rs1 = 0xFF;
        }
        dtmp = D_8004597C << 3;
        vs0 = ps4 + dtmp;
        SetPriority((void *) vs0, 2);
        *((u8 *) ((((u8 *) new_var) + (D_8004597C * 0x18)) + 4)) = (u8) rs1;
        *((u8 *) ((((u8 *) new_var) + (D_8004597C * 0x18)) + 5)) = (u8) rs1;
        *((u8 *) ((((u8 *) new_var) + (D_8004597C * 0x18)) + 6)) = (u8) rs1;
        func_80023BB4((void *) vs0, ((u8 *) new_var) + (D_8004597C * 0x18));
        func_80023BB4((void *) vs0, ps3 + (D_8004597C * 0xC));
        DrawSCEAP((void *) vs0, (u8 *) D_80010010);
        tv0 = rs1 + 8;
        rs1 = tv0;
        KEEP(tv0);
    } while (((tv0 << 16) >> 16) < 0x100);
    func_800246D4(0);
    fr.v70.w = 0x140;
    fr.v70.x = 0;
    fr.v70.y = 0;
    fr.v70.h = 0x1E0;
    SetDrawMode((u8 *) &fr.v70, 0, 0, 0);
    func_800246D4(0);
}

extern void func_8001BEB8(void);
extern void SYSResetGraph(s32);

void ResetDisplay(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5) {
    u8 r06;
    s32 rs2;
    s32 rs1;
    u8 *new_var3;
    s32 rs3;
    register s32 rs5 asm("s5");
    u8 *rs4;
    s32 new_var4;
    s32 new_var2;
    int new_var;
    s32 rs0;
    u8 *ba1;
    u8 r07;
    Blob8 fr;
    r06 = arg4;
    r07 = arg5;
    rs2 = arg0;
    rs3 = arg2;
    new_var2 = arg1;
    rs1 = new_var2;
    ba1 = D_8004091C;
    *((Blob8 *) (&fr)) = *((Blob8 *) ba1);
    new_var4 = rs1;

    {
        rs5 = arg3;
        rs0 = (new_var = (char) (((new_var4 ^ 0x1E0) != 0) ? (-1) : (0)));
        rs0 &= 0xF0;
        DrawSync(0);
    }
    SYSResetGraph(0);
    func_8001BEB8();

    {
        s32 t = new_var4 / 2;
        StoreScreenOffsetsToGTE(arg0 / 2, t);
    }
    func_8001D1C8(rs3);
    new_var3 = (u8 *) &D_8004EA14[0];
    func_80022DE0(new_var3, 0, 0, rs2, new_var4);
    rs3 = (s32) &D_8004EACC[0];
    func_80022EB0((void *) rs3, 0, rs0, rs2, new_var4);
    func_80022DE0(new_var3 + 0x5C, 0, rs0, rs2, new_var4);
    func_80022EB0((void *) (rs3 + 0x14), 0, 0, rs2, new_var4);
    D_8004EA86 = 0;
    D_8004EA2A = 0;
    D_8004EA88 = 0;
    D_8004EA2C = 0;
    D_8004EA2D = (u8) rs5;
    D_8004EA89 = (u8) rs5;
    D_8004EA2E = r06;
    D_8004EA2F = r07;
    D_8004EA8A = r06;
    D_8004EA8B = r07;
    SetDrawMode((u8 *) &fr, 0, 0, 0);
    func_800246D4(0);
    FntPrint(0x280, 0);
    FONTSetDumpFnt(func_80022FD0(0x28, 0x10, 0x200, 0x100, 0, 0x200));
    func_80024E84(&D_8004EACC[D_8004597C]);
    GetGraphType(&D_8004EA14[D_8004597C]);
}

extern void func_80021F54(s32);
extern void func_8001E8C4(void);
extern void _CdSetDebug(s32);
extern void ResetPauseCDROM(void *);
extern s32 D_8004EAF8;
extern s8 D_800597D0;
extern s8 D_800597D1;
extern s8 D_800597D2;
extern s8 D_800597D3;
extern s8 D_800597D4;
extern s8 D_800597D5;
extern s8 D_800597D6;
extern s8 D_800597D7;
extern s8 D_800597D8;
extern s8 D_800597D9;
extern s8 D_800597DA;
extern s8 D_800597DB;
extern s8 D_800597DC;
extern s8 D_800597DD;
extern s8 D_800597DF;
extern s8 D_800473A1;
extern s8 D_800473A2;
extern s8 D_800473A3;
extern s8 D_800473A4;
extern s8 D_800473A5;
extern s8 D_800473A6;
extern s8 D_800473A7;
extern s8 D_800473A8;
extern s32 CustomizedOptions;
extern s32 DefaultOptions;
extern s32 Month;
extern s32 Day;
extern s32 D_80057B18;

void ResetCDROMCPURAM(void) {
    func_80021F54(2);
    func_8001E8C4();
    _CdSetDebug(0);
    ResetPauseCDROM(&D_8004EAF4);
    D_8004EAF8 = 0;
}

extern char D_8004092C[];
extern s32 MRTAFree();
extern void OpenFrameBINToVRAM(void);

void GetZODIACFRAMEToFrameBuffer(void) {
    Blob8 sp10;
    s32 temp_v0;

    sp10 = *(Blob8 *) D_8004092C;
    temp_v0 = ((s32 (*)(s32, s32)) GetBINAsTIM)(0xEC61, 0x10000);
    func_800248FC(sp10.d, temp_v0);
    func_800246D4(0);
    MRTAFree(temp_v0);
    OpenFrameBINToVRAM();
}

extern void func_80044670(void);
extern void ETCResetCallback(void);
extern s32 Hours;
extern s32 Minutes;
extern s32 Seconds;
extern s32 Milliseconds;
extern void SetIntrMask(s32);
extern void func_800245DC(s32);
extern s32 _CdReadyCallback(s32);
extern s32 _CdReadCallback(s32);
extern void func_800244A4(s32);
extern void PadIdentifier(s32);
extern void SPUSsUtReverbOff(void);
extern void ResetDisplay(s32, s32, s32, s32, u8, u8);
extern void BuildDrawSCEAP(void);
extern void BuildDrawSquaresoftLogo(void);
extern void InitMemCardEVT(void);
extern void OpenGnrcSFX(void);
extern void func_8002231C(s32);
extern void SquaresoftFadeOut(void);
extern s32 D_8004D9B4;
extern void VsyncCallbackFunc(void);
extern void func_800435AC(void);
extern void func_800435B4(void);
extern void func_800435BC(void);

void Startup(void) {
    func_80044670();
    ETCResetCallback();
    Hours = 0;
    Minutes = 0;
    Seconds = 0;
    Milliseconds = 0;
    SetIntrMask((s32) &VsyncCallbackFunc);
    func_800245DC((s32) &func_800435AC);
    _CdReadyCallback((s32) &func_800435B4);
    _CdReadCallback((s32) &func_800435BC);
    SYSResetGraph(0);
    func_800244A4(0);
    PadIdentifier(0);
    SPUSsUtReverbOff();
    ResetCDROMCPURAM();
    ResetDisplay(0x100, 0xF0, 0x200, 0, 0, 0);
    BuildDrawSCEAP();
    BuildDrawSquaresoftLogo();
    InitMemCardEVT();
    OpenGnrcSFX();
    GetZODIACFRAMEToFrameBuffer();
    func_8002231C(1);
    SquaresoftFadeOut();
    D_8004D9B4 = 0;
}

void Startup2(void) {
    s32 var_s0;

    if (D_8004D9B4 != 0) {
        func_80044670();
        MRTAUnloadScenarioMusicAndPlayTunes();
        Hours = 0;
        Minutes = 0;
        Seconds = 0;
        Milliseconds = 0;
        SYSResetGraph(1);
        func_800244A4(0);
        SPUSsUtReverbOn();
        ResetCDROMCPURAM();
        ResetDisplay(0x100, 0xF0, 0x200, 0, 0, 0);
        BuildDrawSquaresoftLogo();
        OpenGnrcSFX();
        GetZODIACFRAMEToFrameBuffer();
    }
    func_80044ACC();
    func_80059854();
    func_800452EC();
    func_80045514();
    if (D_8004D9B4 != 0) {
        var_s0 = 0;
        do {
            func_8001DBA8(0);
            var_s0 += 1;
        } while (var_s0 < 0x3C);
        SquaresoftFadeOut();
    }
    D_8004D9B4 = 1;
}

s32 MRTAMalloc(u32);
extern s32 D_80047600;
extern s32 D_80047604;

s32 OpenENTD(void) {
    int var_a0;
    s32 var_v0;

    if (D_80047600 != 0) {
        if (D_80047600 < 0x80) {
            var_v0 = MRTAMalloc(0x14000);
            D_80047604 = var_v0;
            var_a0 = 0xEBC1;
        } else if (D_80047600 < 0x100) {
            var_v0 = MRTAMalloc(0x14000);
            D_80047604 = var_v0;
            var_a0 = 0xEBE9;
        } else if (D_80047600 < 0x180) {
            var_v0 = MRTAMalloc(0x14000);
            D_80047604 = var_v0;
            var_a0 = 0xEC11;
        } else {
            var_v0 = MRTAMalloc(0x14000);
            D_80047604 = var_v0;
            var_a0 = 0xEC39;
        }
        if (CallBuildFileHeader(var_a0, 0x14000, var_v0) != 0) {
            CallFree(D_80047604);
            return 0;
        }
        return 1;
    }
    return 1;
}

s32 CheckFileStillLoading(void);

s32 GetENTD(void) {
    s32 *sp = &D_80047600;
    s32 var_v0;
    s32 var_v1;
    s32 var_v0_2;

    if (*sp != 0) {
        if (CheckFileStillLoading() == 0) {
            var_v1 = *sp;
            if (var_v1 < 0x80) {
                return (var_v1 * 0x280) + D_80047604;
            }
            if (var_v1 < 0x100) {
                var_v0_2 = var_v1 - 0x80;
            }
            if (var_v1 >= 0x100) {
                if (var_v1 < 0x180) {
                    var_v0_2 = var_v1 - 0x100;
                } else {
                    var_v0_2 = var_v1 - 0x180;
                }
            }
            var_v1 = var_v0_2 * 0x280;
            var_v0 = var_v1 + D_80047604;
            return var_v0;
        }
        var_v0 = 0;
    } else {
        var_v0 = -1;
    }
    return var_v0;
}

extern s32 OpenENTD(void);
extern s32 GetENTD(void);
extern s32 func_80059B18(u8 *, s32, s32, s32);
extern void func_80059AC8(void);
extern void CallFree(void);

void EventStartInitializeUnitData(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    D_80047600 = arg0;
    while (OpenENTD() == 0) {
        func_8001DBA8(0);
        func_80011E38(D_8004EAF4);
    }
    var_s0 = -1;
    while (1) {
        var_s1 = GetENTD();
        if (var_s1 == var_s0) {
            break;
        }
        if (var_s1 != 0) {
            func_80059AC8();
            var_s0 = 0;
            do {
                func_80059B18((u8 *) var_s1, var_s0, 0, 1);
                var_s0 += 1;
            } while (var_s0 < 0x10);
            ((void (*)(s32)) CallFree)(D_80047604);
            break;
        }
        func_8001DBA8(0);
        func_80011E38(D_8004EAF4);
    }
}

void NewGameSetInventory(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 0xFF;
    var_v0 = &D_800597DF;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    D_800597D0 = 5;
    D_800597D1 = 2;
    D_800597D2 = 1;
    D_800597D3 = 1;
    D_800597D4 = 1;
    D_800597D5 = 1;
    D_800597D6 = 1;
    D_800597D7 = 2;
    D_800597D8 = 1;
    D_800597D9 = 1;
    D_800597DA = 1;
    D_800597DB = 1;
    D_800597DC = 1;
    D_800597DD = 2;
}

extern void func_8010656C(void);
extern void func_80059ED4(s32);
extern void EventStartInitializeUnitData(s32);
extern void func_800EF25C(s32, s32);

void NewGameSetParty(s32 arg0) {
    func_8010656C();
    func_80059AC8();
    if (arg0 == 0) {
        func_80059ED4(2);
    } else if (arg0 == 2) {
        EventStartInitializeUnitData(0xFE);
    }
    NewGameSetInventory();
    func_800EF25C(0x2C, 0x7D0);
}

void Save3UShort(u16 *arg0, u16 arg1, u16 arg2, u16 arg3) {
    arg0[0] = arg1;
    arg0[1] = arg2;
    arg0[2] = arg3;
}

void Save3ULong(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0[0] = arg1;
    arg0[1] = arg2;
    arg0[2] = arg3;
}

typedef struct {
    char d[8];
} f42B3C_C8;

typedef struct {
    f42B3C_C8 c8;
} f42B3C_Frame;

void func_80042B3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5) {
    u8 r06;
    s32 rs2;
    s32 rs1;
    u8 *new_var3;
    s32 rs3;
    register s32 rs5 asm("s5");
    u8 *rs4;
    s32 new_var4;
    s32 new_var2;
    int new_var;
    s32 rs0;
    s32 idx;
    u8 *ba1;
    u8 r07;
    f42B3C_Frame fr;
    r06 = arg4;
    r07 = arg5;
    rs2 = arg0;
    rs3 = arg2;
    new_var2 = arg1;
    rs1 = new_var2;
    ba1 = D_8004091C;
    *((f42B3C_C8 *) (&fr.c8)) = *((f42B3C_C8 *) ba1);
    new_var4 = rs1;

    {
        rs5 = arg3;
        rs0 = (new_var = (char) (((new_var4 ^ 0x1E0) != 0) ? (-1) : (0)));
        rs0 &= 0xF0;
        DrawSync(0);
    }

    {
        s32 t = new_var4 / 2;
        StoreScreenOffsetsToGTE(arg0 / 2, t);
    }
    func_8001D1C8(rs3);
    new_var3 = (u8 *) &D_8004EA14[0];
    ;
    func_80022DE0(new_var3, 0, 0, rs2, new_var4);
    rs3 = (s32) &D_8004EACC[0];
    func_80022EB0((void *) rs3, 0, rs0, arg0, new_var4);
    func_80022DE0(new_var3 + 0x5C, 0, rs0, rs2, new_var4);
    func_80022EB0((void *) (rs3 + 0x14), 0, 0, rs2, new_var4);
    idx = D_8004597C;
    D_8004EA86 = 0;
    D_8004EA2A = 0;
    D_8004EA88 = 1;
    D_8004EA2C = 1;
    D_8004EA2D = (u8) rs5;
    D_8004EA89 = (u8) rs5;
    D_8004EA2E = r06;
    D_8004EA2F = r07;
    D_8004EA8A = r06;
    D_8004EA8B = r07;
    func_80024E84(&D_8004EACC[idx]);
    GetGraphType(&D_8004EA14[D_8004597C]);
}

s32 SwapDisplayArea(s32 arg0) {
    s32 v1;
    s32 s0;
    s32 unused[2];
    D_8004597C = !D_8004597C;
    func_800246D4(0);
    s0 = func_8001DBA8(0);
    v1 = D_8004597C;
    func_80024E84(&D_8004EACC[v1]);
    GetGraphType(&D_8004EA14[D_8004597C]);
    _que(arg0);
    func_80023288(-1);
    return s0;
}

typedef struct {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
} f42DD4_W16;

typedef struct {
    s32 w0;
    s32 w1;
    s32 w2;
} f42DD4_W12;

typedef struct {
    s32 w0;
    s32 w1;
} f42DD4_W8;

typedef struct {
    char d[8];
} f42DD4_C8;

typedef struct {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
} f42DD4_Q16;

typedef struct {
    s32 v18;
    u8 v1C;
    u8 v1D;
    u8 v1E;
    u8 pad1F;
    u16 v20;
    u16 v22;
    u16 v24;
    u16 v26;
    u16 v28;
    u16 v2A;
    u16 v2C;
    u16 v2E;
    s32 v30;
    s32 v34;
    s32 v38;
    s32 v3C;
    s32 v40;
    s32 v44;
    s32 v48;
    s32 v4C;
    s32 v50;
    s32 v54;
    s32 v58;
    s32 v5C;
    u8 v60[4];
    u8 v64;
    u8 v65;
    u8 v66;
    u8 v67;
    u16 v68;
    u16 v6A;
    u8 v6C;
    u8 v6D;
    u16 v6E;
    u16 v70;
    u16 v72;
    u8 v74;
    u8 v75;
    u16 v76;
    u16 v78;
    u16 v7A;
    u8 v7C;
    u8 v7D;
    u8 v7E;
    u8 v7F;
    u16 v80;
    u16 v82;
    u8 v84;
    u8 v85;
    u8 v86;
    u8 v87;
    s32 v88[10];
    u8 vB0[0x10];
    GpuRect vC0;
} f42DD4_Frame;

extern void func_80042B3C(s32, s32, s32, s32, u8, u8);
extern s32 SetSprt8(s32, s32, s32, s32);
extern s32 P01GetClut(s32, s32);

void func_80042DD4(void) {
    s32 ps2;
    register u8 *vs0 asm("s0");
    u8 *ps1;
    u8 *ps4;
    u8 *ps3;
    u8 *ps5;
    s32 tv0;
    register u8 *pa0 asm("a0");
    register s32 pa1 asm("a1");
    f42DD4_Frame fr;
    f42DD4_Q16 *psrc;
    f42DD4_Q16 *pdsq;
    u8 *pend;
    s16 c74;
    s16 cFFa;
    register s16 cFFb asm("v1");
    s16 c8C;
    s16 c18;

    *(f42DD4_C8 *) &fr.vC0 = *(f42DD4_C8 *) D_80040924;
    ps2 = 0xF8;
    func_80042B3C(0x100, 0xF0, 0x200, 0, 0, 0);
    P16SetPolyF4((GpuPacket *) &fr.v18);
    fr.v1C = 0;
    fr.v1D = 0;
    fr.v1E = 0;
    fr.v20 = 0;
    fr.v22 = 0;
    fr.v24 = 0x100;
    fr.v26 = 0;
    fr.v28 = 0;
    fr.v2A = 0x100;
    fr.v2C = 0x100;
    fr.v2E = 0x100;
    P10SetSemiTrans((GpuPacket *) &fr.v18, 1);
    *(f42DD4_W16 *) &fr.v30 = *(f42DD4_W16 *) &fr.v18;
    *(f42DD4_W8 *) &fr.v40 = *(f42DD4_W8 *) &fr.v28;
    func_800254CC((s32 *) &fr.v48, 0, 0, 0x40, (s16 *) &fr.vC0);
    *(f42DD4_W12 *) &fr.v54 = *(f42DD4_W12 *) &fr.v48;
    vs0 = &fr.v60[0];
    pa0 = vs0;
    pa1 = 0;
    fr.v60[3] = 9;
    fr.v67 = 0x2C;
    fr.v64 = 0x80;
    fr.v65 = 0x80;
    fr.v66 = 0x80;
    c74 = 0x74;
    __asm__ volatile("" : "=r"(cFFa) : "0"(cFFb));
    fr.v6A = c74;
    fr.v72 = c74;
    cFFa = 0xFF;
    c8C = 0x8C;
    fr.v70 = cFFa;
    fr.v80 = cFFa;
    KEEP(cFFa);
    cFFb = 0xFF;
    fr.v7A = c8C;
    fr.v82 = c8C;
    c18 = 0x18;
    fr.v68 = 0;
    fr.v78 = 0;
    fr.v6C = 0;
    fr.v6D = 0;
    fr.v74 = cFFb;
    fr.v75 = 0;
    fr.v7C = 0;
    fr.v7D = c18;
    fr.v84 = cFFb;
    fr.v85 = c18;
    P10SetSemiTrans((GpuPacket *) pa0, pa1);
    fr.v76 = SetSprt8(0, 0, 0x380, 0x100);
    fr.v6E = P01GetClut(0x380, 0x11F);
    psrc = (f42DD4_Q16 *) vs0;
    pdsq = (f42DD4_Q16 *) &fr.v88[0];
    pend = (u8 *) &fr.v80;
    do {
        *pdsq = *psrc;
        psrc += 1;
        pdsq += 1;
    } while ((u8 *) psrc != pend);
    *(f42DD4_W8 *) pdsq = *(f42DD4_W8 *) psrc;
    fr.vC0.w = 0x100;
    fr.vC0.x = 0;
    fr.vC0.y = 0;
    fr.vC0.h = 0x1E0;
    SetDrawMode((u8 *) &fr.vC0, 0, 0, 0);
    func_800246D4(0);
    DrawSync(1);
    if ((ps2 << 16) >= 0) {
        ps5 = &fr.vB0[0];
        ps1 = (u8 *) &fr.v18;
        ps4 = (u8 *) &fr.v48;
        ps3 = (u8 *) &fr.v60[0];
        do {
            vs0 = ps5 + (D_8004597C * 8);
            SetPriority((void *) vs0, 2);
            *(u8 *) ((u8 *) ps1 + (D_8004597C * 0x18) + 4) = (u8) ps2;
            *(u8 *) ((u8 *) ps1 + (D_8004597C * 0x18) + 5) = (u8) ps2;
            *(u8 *) ((u8 *) ps1 + (D_8004597C * 0x18) + 6) = (u8) ps2;
            func_80023BB4((void *) vs0, (u8 *) ps1 + (D_8004597C * 0x18));
            func_80023BB4((void *) vs0, ps4 + (D_8004597C * 0xC));
            func_80023BB4((void *) vs0, ps3 + (D_8004597C * 0x28));
            SwapDisplayArea((s32) vs0);
            tv0 = ps2 - 8;
            ps2 = tv0;
            KEEP(tv0);
        } while ((tv0 << 16) >= 0);
    }
    func_800246D4(0);
    func_800246D4(0);
}

void func_8004315C(void) {
    s32 cs1;
    s32 tv0;
    register u8 *pv18 asm("s2");
    register u8 *vs0 asm("s0");
    u8 *ps4;
    u8 *ps3;
    u8 *ps5;
    register u8 *pa0 asm("a0");
    register s32 pa1 asm("a1");
    f42DD4_Frame fr;
    f42DD4_Q16 *psrc;
    f42DD4_Q16 *pdsq;
    u8 *pend;
    s16 c74;
    s16 cFFa;
    register s16 cFFb asm("v1");
    s16 c8C;
    s16 c18;

    *(f42DD4_C8 *) &fr.vC0 = *(f42DD4_C8 *) D_80040924;
    cs1 = 0;
    P16SetPolyF4((GpuPacket *) &fr.v18);
    fr.v1C = 0;
    fr.v1D = 0;
    fr.v1E = 0;
    fr.v20 = 0;
    fr.v22 = 0;
    fr.v24 = 0x100;
    fr.v26 = 0;
    fr.v28 = 0;
    fr.v2A = 0x100;
    fr.v2C = 0x100;
    fr.v2E = 0x100;
    P10SetSemiTrans((GpuPacket *) &fr.v18, 1);
    *(f42DD4_W16 *) &fr.v30 = *(f42DD4_W16 *) &fr.v18;
    *(f42DD4_W8 *) &fr.v40 = *(f42DD4_W8 *) &fr.v28;
    func_800254CC((s32 *) &fr.v48, 0, 0, 0x40, (s16 *) &fr.vC0);
    *(f42DD4_W12 *) &fr.v54 = *(f42DD4_W12 *) &fr.v48;
    vs0 = &fr.v60[0];
    pa0 = vs0;
    pa1 = 0;
    fr.v60[3] = 9;
    fr.v67 = 0x2C;
    fr.v64 = 0x80;
    fr.v65 = 0x80;
    fr.v66 = 0x80;
    c74 = 0x74;
    __asm__ volatile("" : "=r"(cFFa) : "0"(cFFb));
    fr.v6A = c74;
    fr.v72 = c74;
    cFFa = 0xFF;
    c8C = 0x8C;
    fr.v70 = cFFa;
    fr.v80 = cFFa;
    KEEP(cFFa);
    cFFb = 0xFF;
    fr.v7A = c8C;
    fr.v82 = c8C;
    c18 = 0x18;
    fr.v68 = 0;
    fr.v78 = 0;
    fr.v6C = 0;
    fr.v6D = 0;
    fr.v74 = cFFb;
    fr.v75 = 0;
    fr.v7C = 0;
    fr.v7D = c18;
    fr.v84 = cFFb;
    fr.v85 = c18;
    P10SetSemiTrans((GpuPacket *) pa0, pa1);
    fr.v76 = SetSprt8(0, 0, 0x380, 0x100);
    fr.v6E = P01GetClut(0x380, 0x11F);
    psrc = (f42DD4_Q16 *) vs0;
    pdsq = (f42DD4_Q16 *) &fr.v88[0];
    pend = (u8 *) &fr.v80;
    do {
        *pdsq = *psrc;
        psrc += 1;
        pdsq += 1;
    } while ((u8 *) psrc != pend);
    *(f42DD4_W8 *) pdsq = *(f42DD4_W8 *) psrc;
    if ((s16) cs1 < 0x100) {
        ps5 = &fr.vB0[0];
        pv18 = (u8 *) &fr.v18;
        ps4 = (u8 *) &fr.v48;
        ps3 = (u8 *) &fr.v60[0];
        do {
            if ((s16) cs1 >= 0xF8) {
                cs1 = 0xFF;
            }
            vs0 = ps5 + (D_8004597C * 8);
            SetPriority((void *) vs0, 2);
            *(u8 *) ((u8 *) pv18 + (D_8004597C * 0x18) + 4) = (u8) cs1;
            *(u8 *) ((u8 *) pv18 + (D_8004597C * 0x18) + 5) = (u8) cs1;
            *(u8 *) ((u8 *) pv18 + (D_8004597C * 0x18) + 6) = (u8) cs1;
            func_80023BB4((void *) vs0, (u8 *) pv18 + (D_8004597C * 0x18));
            func_80023BB4((void *) vs0, ps4 + (D_8004597C * 0xC));
            func_80023BB4((void *) vs0, ps3 + (D_8004597C * 0x28));
            SwapDisplayArea((s32) vs0);
            tv0 = cs1 + 8;
            cs1 = tv0;
            KEEP(tv0);
        } while ((s16) tv0 < 0x100);
    }
    func_800246D4(0);
    fr.vC0.w = 0x100;
    fr.vC0.x = 0;
    fr.vC0.y = 0;
    fr.vC0.h = 0x1E0;
    SetDrawMode((u8 *) &fr.vC0, 0, 0, 0);
    func_800246D4(0);
}

int func_8002230C();
extern s32 TimePlayedThisSession;

void VsyncCallbackFunc(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    func_8002230C();
    temp_v0 = Milliseconds + 1;
    Milliseconds = temp_v0;
    if (temp_v0 >= 0x3C) {
        Milliseconds = 0;
        temp_v0_2 = Seconds + 1;
        Seconds = temp_v0_2;
        if (temp_v0_2 >= 0x3C) {
            Seconds = 0;
            temp_v0_3 = Minutes + 1;
            Minutes = temp_v0_3;
            if (temp_v0_3 >= 0x3C) {
                Minutes = 0;
                if (Hours < 0x3E8) {
                    Hours += 1;
                }
            }
        }
    }
    TimePlayedThisSession += 1;
}

void func_800435AC(void) {
}

void func_800435B4(void) {
}

void func_800435BC(void) {
}

extern s32 D_8004D98C[];
extern s32 D_80047080[];
extern s32 D_80047084[];
extern s32 GetSMD(s32, u32);

s32 MRTAOpenAndPlayMusic(s32 arg0, s32 arg1) {
    s32 smd;
    s32 *base = &D_8004D98C[0];
    s32 *p = base + arg1;
    if (*p == 0) {
        smd = GetSMD(D_80047080[arg0 * 2], D_80047084[arg0 * 2]);
        *p = smd;
        *(&D_8004D98C[arg1 - 7]) = SUZUKIPutPlaySMD(smd);
        return arg1;
    }
    return 0;
}

extern s32 D_8004D990[];

s32 MRTAOpenMUSIntoFreeSlot(s32 arg0) {
    s32 i = 0;
    s32 music = arg0 * 8;
    s32 *base = &D_8004D990[0];
    s32 *q = base - 7;
    s32 *p = base;
    do {
        if (*p != 0) {
            q++;
            p++;
            i++;
        } else {
            s32 smd = GetSMD(*(s32 *) ((u8 *) D_80047080 + music), *(s32 *) ((u8 *) D_80047084 + music));
            *p = smd;
            *q = SUZUKIPutPlaySMD(smd);
            return i + 1;
        }
    } while (i < 2);
    return 0;
}

s32 func_80043708(void) {
    return 0;
}

extern s32 D_8004D970[];
extern s32 MRTASMDMalloc(u32);
extern s32 CallBuildFileHeader(s32, u32, s32);
extern void AnimationExceptionHandler(s32);

s32 func_80043710(s32 arg0, s32 arg1) {
    s32 s0;
    s32 s1;
    register s32 s2 asm("s2") = arg1;
    s32 *base = &D_8004D98C[0];
    s32 off = s2 << 2;
    s32 *s3 = (s32 *) (((u8 *) base) + off);

    if ((*s3) != 0) {
        return 0;
    }
    do {
        s0 = arg0 << 3;
        s1 = MRTASMDMalloc(*((s32 *) (((u8 *) D_80047084) + s0)));
        if (s1 == 0) {
            AnimationExceptionHandler(0x11);
            return 0;
        }
        if (CallBuildFileHeader(*((s32 *) (((u8 *) D_80047080) + s0)), *((s32 *) (((u8 *) D_80047084) + s0)), s1) != 0) {
            AnimationExceptionHandler(0x11);
            return 0;
        }
        *s3 = s1;
    } while (0);
    if (s1) {
        D_8004D970[0] = s2;
    } else {
        D_8004D970[0] = s2;
    }
    {
        s32 rv = s2;
        D_8004D970[0] = rv;
        return rv;
    }
}

s32 func_800437D8(arg0)

s32 arg0;
{
    s32 v1 = 0;
    s32 s0;
    s32 s3 = arg0 << 3;
    register s32 s2 asm("s2") = 1;
    register s32 *s4 asm("s4") = D_8004D990;
    register s32 *s1 asm("s1") = s4;
head:
    if (*s1 != 0) {
        goto latch;
    }
    s0 = MRTASMDMalloc(*(s32 *) ((u8 *) D_80047084 + s3));
    if (s0 == 0) {
        goto fail2;
    }
    if (CallBuildFileHeader(*(s32 *) ((u8 *) D_80047080 + s3), *(s32 *) ((u8 *) D_80047084 + s3), s0) != 0) {
        goto fail1;
    }
    *s1 = s0;
    *((s32 *) ((u8 *) s4 - 0x20)) = s2;
    goto success;
fail1:
    AnimationExceptionHandler(0x11);
    SCHED_BARRIER();
    return 0;
fail2:
    AnimationExceptionHandler(0x11);
    return 0;
success:
    return s2;
latch:
    s2 += 1;
    s1 += 1;
    v1 += 1;
    if (v1 < 2) {
        goto head;
    }
    return 0;
}
extern s32 CheckFileStillLoading(void);
extern s32 SUZUKIPutPlaySMD(s32);

s32 MRTACheckSMDFileStilOpening(void) {
    if (D_8004D970[0] != 0) {
        if (CheckFileStillLoading() != 0) {
            return 1;
        }
        D_8004D970[D_8004D970[0]] = SUZUKIPutPlaySMD(D_8004D970[D_8004D970[0] + 7]);
        D_8004D970[0] = 0;
        return 0;
    }
    return 0;
}

extern s32 func_800437D8();
extern s32 MRTACheckSMDFileStilOpening(void);

s32 func_80043958(void) {
    s32 temp_v0;

    temp_v0 = func_800437D8();
    if (temp_v0 != 0) {
loop_1:
        if (MRTACheckSMDFileStilOpening() != 0) {
            func_8001DBA8(0);
            func_800449EC();
            func_80011E38(D_8004EAF4);
            goto loop_1;
        }
    }
    return temp_v0;
}

extern void SUZUKIUnloadMUS(s32);

s32 MRTAUnloadScenarioMUS(s32 arg0) {
    if (D_8004D98C[arg0] != 0) {
        SUZUKIUnloadMUS(D_8004D98C[arg0 - 7]);
        D_8004D98C[arg0 - 7] = 0;
        MRTASMDRealloc(D_8004D98C[arg0]);
        D_8004D98C[arg0] = 0;
        return 1;
    }
    return 0;
}

extern void SUZUKIDeallocateMUSChannels(s32);
extern s32 D_8004D95C;
extern s32 D_8004D960;
extern s32 D_8004D964;

s32 MRTASetNoForcedMUSPlaying(void) {
    s32 *p;
    s32 v;

    p = &D_8004D960;
    v = 0;
    if (*p != 0) {
        SUZUKIDeallocateMUSChannels(*p);
        v = 1;
        D_8004D95C = 0;
        D_8004D964 = 0;
        *p = 0;
    }
    return v;
}

extern s32 MRTASetNoForcedMUSPlaying(void);
extern void SUZUKIResetMUS(s32, s16, s16);
extern s16 D_8004D968;

s32 MRTASwitchTrack(s32 arg0, s32 arg1, s16 arg2) {
    s16 ext1;
    s32 *p;
    s32 *q;
    s32 v;

    MRTASetNoForcedMUSPlaying();
    if (arg0 != 0) {
        p = &D_8004D98C[arg0];
        if (*p != 0) {
            D_8004D95C = arg0;
            q = &D_8004D98C[arg0 - 7];
            D_8004D964 = *p;
            v = *q;
            *(s32 *) &D_8004D968 = arg1;
            D_8004D960 = v;
            SUZUKIResetMUS(v, ext1 = (s16) arg1, arg2);
        }
        return D_8004D960;
    }
    return 0;
}

s32 func_80043B44(void) {
    return D_8004D95C;
}

extern void SUZUKICalcMUSVolChange(s32, s16, s16);

s32 MRTAChangeVolumeCurrentSong(s16 arg0, s16 arg1) {
    if (D_8004D960 != 0) {
        SUZUKICalcMUSVolChange(D_8004D960, arg0, arg1);
        return 1;
    }
    return 0;
}

s32 MRTAVolumeWithTargetTimeCurrentSong(s16 arg0) {
    if (D_8004D960 != 0) {
        SUZUKICalcMUSVolChange(D_8004D960, D_8004D968, arg0);
        return 1;
    }
    return 0;
}

s32 MRTASetTargetVolShiftTimeCurrentSong(s32 arg0, s16 arg1) {
    if (D_8004D960 != 0) {
        *(s32 *) &D_8004D968 = arg0;
        SUZUKICalcMUSVolChange(D_8004D960, (s16) arg0, arg1);
        return 1;
    }
    return 0;
}

extern void func_80012E88(s32, s16, s16);

s32 func_80043C3C(s16 arg0, s16 arg1) {
    if (D_8004D960 != 0) {
        func_80012E88(D_8004D960, arg0, arg1);
        return 1;
    }
    return 0;
}

extern void func_80013014(s32, s16, s16);

s32 func_80043C88(s16 arg0, s16 arg1) {
    if (D_8004D960 != 0) {
        func_80013014(D_8004D960, arg0, arg1);
        return 1;
    }
    return 0;
}

extern void func_80013094(s32, s16, s16);

s32 func_80043CD4(s16 arg0, s16 arg1) {
    if (D_8004D960 != 0) {
        func_80013094(D_8004D960, arg0, arg1);
        return 1;
    }
    return 0;
}

extern s32 D_8004D96C[];

s32 PlayTune(s32 arg0) {
    if (arg0 != 0) {
        s32 *p;

        p = D_8004D96C;
        if (*p == 0) {
            MRTASetTargetVolShiftTimeCurrentSong(0, 0x78);
            *p = arg0 | 0x80;
        }
    }
    return 1;
}

s32 MRTASetPlayTuneVolume(s16 arg0) {
    s32 v;

    v = D_8004D96C[0];
    if (v != 0) {
        if (v & 0x80) {
            D_8004D96C[0] = 0;
        } else {
            SUZUKICalcMUSVolChange(D_8004D96C[(v & 0x3F) + 3], 0, arg0);
        }
    }
    return 1;
}

extern s32 SUZUKIGetMusicPlaying(s32);
extern s32 MRTASetTargetVolShiftTimeCurrentSong(s32, s16);

s32 func_80043DE0(void) {
    register s32 v1 asm("v1");
    s32 *s0;
    s32 a0;

    v1 = D_8004D96C[0];
    if (v1 & 0x80) {
        if (SUZUKIGetMusicPlaying(D_8004D960) != 0) {
            return 0;
        }
        a0 = D_8004D96C[0] & 0x3F;
        D_8004D96C[0] &= 0x7F;
        SCHED_BARRIER();
        {
            u8 *base = (u8 *) D_8004D96C + 0xC;
            s32 sh = a0 << 2;

            s0 = (s32 *) (base + sh);
        }
        if (*s0 == 0) {
            *s0 = SUZUKIPutPlaySMD(D_8004D96C[a0 + 10]);
        }
        SUZUKIResetMUS(*s0, 0x7F, 0);
        return 1;
    }
    if (v1 != 0) {
        a0 = v1 & 0x3F;
        {
            u8 *base = (u8 *) D_8004D96C + 0xC;
            s32 sh = a0 << 2;

            s0 = (s32 *) (base + sh);
        }
        if (SUZUKIGetMusicPlaying(*s0) != 0) {
            return 0;
        }
        SUZUKIDeallocateMUSChannels(*s0);
        a0 = *s0;
        if (a0 != 0) {
            SUZUKIUnloadMUS(a0);
        }
        *s0 = 0;
        D_8004D96C[0] = 0;
        return MRTASetTargetVolShiftTimeCurrentSong(0x7F, 0x78);
    }
    return 0;
}

extern s32 MRTAUnloadScenarioMUS(s32);
extern s32 MRTASetPlayTuneVolume(s16);

void MRTAUnloadScenarioMusicAndPlayTunes(void) {
    MRTASetNoForcedMUSPlaying();
    MRTAUnloadScenarioMUS(1);
    MRTAUnloadScenarioMUS(2);
    MRTASetPlayTuneVolume(0);
}

s32 func_80043F38(u32 arg0) {
    return D_8004D970[arg0];
}

void func_80043F50(void) {
    s32 temp_s0;

    temp_s0 = D_8004D95C;
    MRTASetNoForcedMUSPlaying();
    MRTAUnloadScenarioMUS(temp_s0);
}

extern s32 MRTAOpenMUSIntoFreeSlot(s32);
extern s32 MRTASwitchTrack(s32, s32, s16);

void func_80043F88(s32 arg0) {
    s32 s;

    if (D_8004D964 != 0) {
        s = D_8004D95C;
        MRTASetNoForcedMUSPlaying();
        MRTAUnloadScenarioMUS(s);
    }
    s = MRTAOpenMUSIntoFreeSlot(arg0);
    if (s != 0) {
        MRTASwitchTrack(s, 0x7F, 0);
    }
}

extern void SUZUKIPlaySound1(void);
extern void SUZUKIPlaySoundFindChannel(void);

void MRTACallPlaySound(void) {
    SUZUKIPlaySound1();
}

void MRTACallPlaySoundFindChannel(void) {
    SUZUKIPlaySoundFindChannel();
}

extern s32 D_8004599C;
extern void SUZUKIPlaySound2(s32);

void MRTACallPlaySound2(s32 arg0) {
    D_8004599C = arg0;
    SUZUKIPlaySound2(arg0);
}

void func_80044060(void) {
    if (D_8004599C != 0) {
        SUZUKIPlaySound2(D_8004599C);
    }
}

extern void SUZUKISetSFXEcho(s32, s16);

void MRTACallSetSFXEcho(s32 arg0, s32 arg1) {
    if ((D_8004599C == arg0) && (arg1 == 0)) {
        D_8004599C = 0;
    }
    SUZUKISetSFXEcho(arg0, arg1);
}

extern void TurnOffAllMUS(void);

void func_800440CC(void) {
    D_8004599C = 0;
    TurnOffAllMUS();
}

void MRTAStopPlayingSFX(s32 arg0) {
    if (arg0 == D_8004599C) {
        D_8004599C = 0;
    }
    AccumulateChannelsToPause();
}

extern void AccumulateChannelsToPause();

void func_80044128(void) {
    if (D_8004599C != 0) {
        AccumulateChannelsToPause(D_8004599C);
    }
}

extern s32 GetWD(u32, u32, s32);
extern void SUZUKISPUInitialiser(s32);
extern s32 PutWAVESETWDInSPU(s32);
extern void SUZUKIAppendVFXSMD(void *);
extern void MRTASMDFree(void);
extern s32 D_800471E8;
extern s32 D_800471EC;
extern s32 D_800471F0;
extern s32 D_800471F4;
extern s32 D_800471F8;
extern s32 D_800471FC;
extern s32 D_80047200;
extern s32 D_80047204;
extern s32 D_80047208;
extern s32 D_8004720C;
extern u8 D_80047610[];
extern s32 D_8004D998;
extern s32 D_8004D99C;
extern s32 D_8004D9A0;
extern s32 D_8004D9A4;
extern s32 D_8004D9A8;
extern u8 D_8004D9B8[];

void OpenGnrcSFX(void) {
    s32 *base;
    s32 *var_v1;
    s32 var_a0;

    SUZUKISPUInitialiser(0);
    MRTASMDFree();
    PutWAVESETWDInSPU(GetWD(0x14C0F, 0x79000, D_80010000));
    SUZUKIAppendVFXSMD((void *) GetWD(0x14C0A, 0x2800, (s32) D_80047610));
    SUZUKIAppendVFXSMD((void *) GetWD(0x14C08, 0x1000, (s32) D_8004D9B8));
    var_a0 = 6;
    base = &D_8004D964;
    var_v1 = base + 10;
    *base = 0;
    D_8004D96C[0] = 0;
    D_8004D970[0] = 0;
    do {
        *var_v1 = 0;
        var_a0 -= 1;
        var_v1 -= 1;
    } while (var_a0 >= 0);
    D_8004599C = 0;
    D_8004D998 = GetSMD(D_800471E8, D_800471EC);
    D_8004D99C = GetSMD(D_800471F0, D_800471F4);
    D_8004D9A0 = GetSMD(D_800471F8, D_800471FC);
    D_8004D9A4 = GetSMD(D_80047200, D_80047204);
    D_8004D9A8 = GetSMD(D_80047208, D_8004720C);
}

extern u8 D_8004E5C0[];
extern u8 D_8004EB18[];

s32 MRTASMDMalloc(u32 arg0) {
    u32 a2 = 0;
    u32 a3 = arg0 >> 11;
    u32 a0 = arg0 & 0x7FF;
    u32 t0 = 1;
    u32 v1;
    u32 a1;
    volatile u8 pad[8];

    if (a0 != 0) {
        a3 += 1;
    }
    a1 = 0;
    do {
        a0 = D_8004E5C0[a1];
        if (a0 == 0) {
            if (a2 == 0) {
                v1 = a1;
            }
            a2 += 1;
            if (a2 < a3) {
                a1 += 1;
            } else {
                goto done;
            }
        } else {
            a2 = 0;
            if (a0 >= t0) {
                t0 = a0 + 1;
            }
            a1 += 1;
        }
    } while (a1 < 16);
    if (a2 < a3) {
        return 0;
    }
done:
    a1 = 0;
    if (a2 != 0) {
        do {
            SCHED_BARRIER();
            D_8004E5C0[v1 + a1] = t0;
            a1 += 1;
        } while (a1 < a2);
    }
    return (s32) &D_8004EB18[v1 << 11];
}

extern u8 D_8004E5BF[];

s32 MRTASMDRealloc(s32 arg0) {
    u32 idx;
    s32 c;
    u8 *p;

    idx = (u32) (arg0 - (s32) &D_8004EB18) >> 11;
    c = D_8004E5C0[idx];
    if ((idx < 1) | (c != D_8004E5BF[idx])) {
        p = D_8004E5C0 + idx;
        do {
            *p = 0;
        } while (*++p == c);
        return 1;
    }
    return 0;
}

extern u8 D_8004E5CF;

void MRTASMDFree(void) {
    s32 i = 0xF;
    u8 *p = &D_8004E5CF;

    for (; i >= 0; i--) {
        *p = 0;
        p--;
    }
}

extern u8 D_8004E9D4[];

s32 MRTAMalloc(u32 arg0) {
    u32 run = 0;
    u32 need = arg0 >> 11;
    u32 a0 = arg0 & 0x7FF;
    u32 max = 1;
    u32 start;
    u32 i;
    u32 vv;
    volatile u8 pad[8];

    if (a0 != 0) {
        need += 1;
    }
    i = 0;
    do {
        vv = D_8004E9D4[i];
        if (vv == 0) {
            if (run == 0) {
                start = i;
            }
            run += 1;
            if (run < need) {
                i += 1;
            } else {
                goto done;
            }
        } else {
            run = 0;
            if (vv >= max) {
                max = vv + 1;
            }
            i += 1;
        }
    } while (i < 0x40);
    if (run < need) {
        return 0;
    }
done:
    i = 0;
    if (run != 0) {
        do {
            SCHED_BARRIER();
            D_8004E9D4[start + i] = max;
            i += 1;
        } while (i < run);
    }
    return (start << 11) + D_80010010;
}

s32 MRTARealloc(u32 arg0, u32 arg1) {
    s32 v0 = (s32) (arg0 - D_80010010);
    u32 a2 = 1;
    u32 a3;
    u32 ab;
    s32 t0;
    u32 v1;
    u32 a0b;
    volatile u8 pad[8];

    if (v0 < 0) {
        v0 += 0x7FF;
    }
    t0 = v0 >> 11;
    ab = arg1 & 0x7FF;
    a3 = arg1 >> 11;
    if (ab != 0) {
        a3 += 1;
    }
    if (arg0 < D_80010010) {
        return 0;
    }
    if (arg0 >= (D_80010010 + 0x20000)) {
        return 0;
    }
    a0b = 0x40;
    do {
        v1 = 0;
        do {
            if (D_8004E9D4[v1] == a2) {
                a2 += 1;
                goto next_a2;
            } else {
                v1 += 1;
            }
        } while (v1 < 0x40);
next_a2:;
    } while (v1 != a0b);
    {
        u32 cur;
        u32 end;
        s32 vv;

        cur = (u32) t0;
        end = ((u32) t0) + a3;
        if (((u32) t0) < end) {
            do {
                vv = D_8004E9D4[cur];
                if (vv != 0) {
                    v0 = t0 + ((s32) a3);
                    goto check;
                }
                cur += 1;
            } while (cur < end);
        }
check:
        if (cur == ((u32) (t0 + ((s32) a3)))) {
            u32 i = 0;

            if (a3 != 0) {
                do {
                    SCHED_BARRIER();
                    D_8004E9D4[t0 + i] = (u8) a2;
                    i += 1;
                } while (i < a3);
            }
            return (t0 << 11) + D_80010010;
        }
    }
    return 0;
}

extern u8 D_8004E9D3[];

s32 MRTAFree(arg0)

s32 arg0;
{
    u32 idx;
    s32 c;
    u8 *p;

    idx = (u32) (arg0 - D_80010010) >> 11;
    c = D_8004E9D4[idx];
    if ((idx < 1) | (c != D_8004E9D3[idx])) {
        p = D_8004E9D4 + idx;
        do {
            *p = 0;
        } while (*++p == c);
        return 1;
    }
    return 0;
}
extern u8 D_8004EA13;

void func_80044670(void) {
    s32 i = 0x3F;
    u8 *p = &D_8004EA13;

    for (; i >= 0; i--) {
        *p = 0;
        p--;
    }
}

extern s32 BuildFileHeaderNNL(void *, s32, u32, s32);

s32 CallBuildFileHeader(s32 arg0, u32 arg1, s32 arg2) {
    return BuildFileHeaderNNL(&D_8004EAF4, arg0, arg1 >> 0xB, arg2);
}

s32 CheckFileStillLoading(void) {
    return D_8004EAF8;
}

s32 GetSMD(s32 arg0, u32 arg1) {
    register u32 a1c asm("s0") = arg1;
    u8 *p1;
    u8 *p2;
    register s32 ret asm("s2");

    ret = MRTASMDMalloc(a1c);
    if (ret == 0) {
        AnimationExceptionHandler(0x11);
    }
    p1 = D_8004EAF4;
loop_1:
    if (BuildFileHeaderNNL(p1, arg0, a1c >> 11, ret) != 0) {
        func_8001DBA8(0);
        func_800449EC();
        func_80011E38(p1);
        goto loop_1;
    }
    if (D_8004EAF8 == 0) {
        return ret;
    }
    p2 = p1;
loop_2:
    func_8001DBA8(0);
    func_800449EC();
    func_80011E38(p2);
    if (D_8004EAF8 != 0) {
        goto loop_2;
    }
    return ret;
}

s32 GetTIM(arg0, arg1)

s32 arg0;
u32 arg1;
{
    register u32 a1c asm("s0") = arg1;
    u8 *p1;
    u8 *p2;
    register s32 ret asm("s2");

    ret = MRTAMalloc(a1c);
    if (ret == 0) {
        AnimationExceptionHandler(1);
    }
    p1 = D_8004EAF4;
loop_1:
    if (BuildFileHeaderNNL(p1, arg0, a1c >> 11, ret) != 0) {
        func_8001DBA8(0);
        func_800449EC();
        func_80011E38(p1);
        goto loop_1;
    }
    if (D_8004EAF8 == 0) {
        return ret;
    }
    p2 = p1;
loop_2:
    func_8001DBA8(0);
    func_800449EC();
    func_80011E38(p2);
    if (D_8004EAF8 != 0) {
        goto loop_2;
    }
    return ret;
}

s32 GetWD(u32 arg0, u32 arg1, s32 arg2) {
    register u8 *s0 asm("s0") = D_8004EAF4;
    while (BuildFileHeaderNNL(s0, arg0, arg1 >> 11, arg2) != 0) {
        func_8001DBA8(0);
        func_800449EC();
        func_80011E38(s0);
    }
    while (D_8004EAF8 != 0) {
        func_8001DBA8(0);
        func_800449EC();
        func_80011E38(s0);
    }
    return arg2;
}

s32 GetDATAsWD(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_800448A0();
    if (temp_v0 == 0) {
        AnimationExceptionHandler(2);
    }
    return temp_v0;
}

s32 GetBINAsTIM(void) {
    s32 temp_v0;

    temp_v0 = GetTIM();
    if (temp_v0 == 0) {
        AnimationExceptionHandler(2);
    }
    return temp_v0;
}

void CallFree(void) {
    MRTAFree();
}

void func_800449EC(void) {
    ASM_NOP_NOVOL();
}

void func_800449F8(u32 arg0, s32 arg1) {
}

void MallocExceptionHandler(u32 arg0, s32 arg1) {
}

extern s32 D_8004C6C4;

void AnimationExceptionHandler(s32 arg0) {
    func_800449F8(0, arg0);
    D_8004C6C4 = 0;
}

void PointerExceptionHandler(s32 arg0) {
    MallocExceptionHandler(0, arg0);
    D_8004C6C4 = 0;
}

extern s32 *D_8011A2D4;

s32 GetOTAG(void) {
    return D_8011A2D4[0x396D];
}

extern void ClearOTagR(u32, s32);
extern u8 D_800FC55C[];

void PutOtag(void) {
    u8 *v1;
    u32 ot;

    v1 = D_800FC55C;
    if (D_8011A2D4 == (s32 *) v1) {
        v1 += 0xEE28;
    }
    ot = *(u32 *) (v1 + 0xE5B4);
    D_8011A2D4 = (s32 *) v1;
    ClearOTagR(ot, 0x180);
}

void func_80044ACC(void) {
    s32 *var_v0;
    s32 var_v1;
    s32 t;
    register s32 c4 asm("v1");

    var_v1 = 0xFF;
    var_v0 = &D_80057B18;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    c4 = 4;
    D_800473A2 = c4;
    D_800473A5 = c4;
    D_800473A6 = c4;
    t = DefaultOptions;
    Month = 1;
    Day = 1;
    D_800473A1 = 0xE;
    D_800473A3 = 0xA;
    D_800473A4 = 0x20;
    D_800473A7 = 1;
    D_800473A8 = 0;
    CustomizedOptions = t;
}

extern s32 func_8014A81C(void);

s32 CallBATTLEReturn0(void) {
    if (D_80057B18 == 0) {
        return 0;
    }
    return func_8014A81C();
}

void func_80044BA0(u8 *arg0, u8 *arg1, u16 *arg2, u8 *arg3, EventDrawArgs args) {
    u8 *s1;
    u8 *s0;
    s32 s2;
    register s32 s3 asm("s3");
    register s32 s4 asm("s4");
    register s32 s5 asm("s5");
    u16 *s6;
    u16 *s7;
    register u8 *t3 asm("t3");
    s32 a0t;
    s32 v1t;
    register s32 f1 asm("a3");
    register s32 f2 asm("t0");
    register s32 f3 asm("t1");
    s32 f4;
    s32 v0;
    int new_var;
    s32 a2t;
    s32 a1t;
    int new_var2;
    s32 a0t2;
    s32 v1t2;
    s16 *p4;

    s1 = arg0;
    s0 = arg3;
    p4 = args.coords;
    asm volatile("" : "=r"(s1), "=r"(s0) : "0"(s1), "1"(s0));
    a0t = p4[0];
    s3 = (*((s16 *) (s0 + 8))) * a0t;
    v1t = p4[1];
    s5 = (*((s16 *) (s0 + 0xA))) * v1t;
    s2 = (*((s16 *) (s0 + 4))) * a0t;
    s4 = (*((s16 *) (s0 + 6))) * v1t;
    t3 = arg1;
    s6 = arg2;
    __asm__("" : : "r"(t3), "r"(s6));
    f1 = 0;
    f2 = 0;
    f3 = 0;
    f4 = 0;
    s7 = *((u16 *volatile *) (&args.extra));

    v0 = s3;
    if (s3 < 0) {
        v0 = s3 + 0xFFF;
    }
    a2t = v0 >> 12;
    v0 = s3 - (a2t << 12);
    if (v0 >= 0x800) {
        f1 = 1;
    }
    v0 = s5;
    if (s5 < 0) {
        v0 = s5 + 0xFFF;
    }
    a1t = v0 >> 12;
    v0 = s5 - (a1t << 12);
    if (v0 >= 0x800) {
        f2 = 1;
    }
    v0 = s2;
    if (s2 < 0) {
        v0 = s2 + 0xFFF;
    }
    a0t2 = v0 >> 12;
    v0 = s2 - (a0t2 << 12);
    if (v0 >= 0x800) {
        f3 = 1;
    }
    v0 = s4;
    if (s4 < 0) {
        v0 = s4 + 0xFFF;
    }
    v1t2 = v0 >> 12;
    v0 = s4 - ((v1t2 << 3) << 9);
    if (v0 >= 0x800) {
        f4 = 1;
    }
    s3 = a2t + f1;
    s5 = a1t + f2;
    s2 = a0t2 + f3;
    s4 = v1t2 + f4;
    if (s2 < 0) {
        s2 = -s2;
    }
    if (s4 < 0) {
        s4 = -s4;
    }
    *((u16 *) (s1 + 0x16)) = func_8002398C(1, 0, *((s16 *) t3), (*((u16 *) (t3 + 2))) & 0xF00);
    *(s1 + 0xC) = *s0;
    *(s1 + 0xD) = *(s0 + 2);
    *(s1 + 0x14) = (*s0) + (*(s0 + 4));
    *(s1 + 0x15) = *(s0 + 2);
    *(s1 + 0x1C) = *s0;
    *(s1 + 0x1D) = (*(s0 + 2)) + (*(s0 + 6));
    *(s1 + 0x24) = (*s0) + (*(s0 + 4));
    *(s1 + 0x25) = (*(s0 + 2)) + (*(s0 + 6));
    f1 = s3;
    *((u16 *) (s1 + 8)) = ((f1 + (*(s6 + 0))) + (*(s7 + 4))) + 0x100;
    v1t = s3;
    f2 = s5;
    *((u16 *) (s1 + 0xA)) = ((f2 + (*(s6 + 1))) + (*(s7 + 5))) + 0x78;
    *((u16 *) (s1 + 0x10)) = ((v1t + (*(s6 + 0))) + (*(s7 + 4))) + (s2 + 0x100);
    a0t = s3;
    v0 = s5;
    *((u16 *) (s1 + 0x12)) = ((v0 + (*(s6 + 1))) + (*(s7 + 5))) + 0x78;
    *((u16 *) (s1 + 0x18)) = ((a0t + (*(s6 + 0))) + (*(s7 + 4))) + 0x100;
    f3 = s5;
    *((u16 *) (s1 + 0x1A)) = ((f3 + (*(s6 + 1))) + (*(s7 + 5))) + (s4 + 0x78);
    *((u16 *) (s1 + 0x20)) = (new_var = ((*(s6 + 0)) + s3) + (*(s7 + 4))) + (s2 + 0x100);
    new_var2 = (*(s6 + 1)) + s5;
    *((u16 *) (s1 + 0x22)) = (new_var2 + (*(s7 + 5))) + (s4 + 0x78);
    asm volatile("" : : "r"(s2), "r"(s4), "r"(s3), "r"(s5));
}

extern u8 D_800473B4[];
extern u8 D_800473BC[];
extern u8 D_800473C4[];
extern u8 D_80047520[];
extern u8 D_80047522[];
extern u8 D_80047595;
extern void P17SetPolyFT4(void *);
extern void P11SetShadeTex(GpuPacket *, s32);
void BuildZODIACBIN();

void BuildZODIACBIN(arg0, arg1)

    u8 *arg0;
u8 *arg1;
{
    register EventCoord28 *s0 asm("s0");
    u8 *p2;
    s16 buf[5];
    EventDrawArgs *args;
    s32 s3;
    register s32 s4 asm("s4");
    register s32 s5 asm("s5");
    s32 s6;
    s32 s7;
    register s32 a2 asm("a2");
    register u8 *table asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 c0 asm("a0");
    register s32 c1 asm("a1");

    s0 = (EventCoord28 *) arg1;
    s4 = 0;
    v0 = D_80047595;
    if (v0 <= 0) {
        goto end;
    }
    s6 = 0xFFFFFF;
    s7 = 0xFF000000;
    s5 = 0;
    s3 = 0;
    p2 = arg1 + 6;
loop:
    P17SetPolyFT4(s0);
    *(u16 *) (p2 + 8) = P01GetClut(0, 0x1FD);
    p2[-2] = *(volatile u8 *) (arg0 + 4);
    p2[-1] = *(volatile u8 *) (arg0 + 4);
    p2[0] = *(volatile u8 *) (arg0 + 4);
    P10SetSemiTrans((GpuPacket *) s0, 1);
    P11SetShadeTex((GpuPacket *) s0, 0);
    a2 = *(s16 *) (D_80047520 + s3);
    v0 = *(s16 *) (arg0 + 0xC);
    a2 = a2 * v0;
    v1 = *(s16 *) (D_80047522 + s3);
    v0 = *(s16 *) (arg0 + 0xE);
    v1 = v1 * v0;
    v0 = a2;
    if (a2 < 0) {
        v0 = a2 + 0xFFF;
    }
    v0 >>= 12;
    v0 <<= 12;
    v0 = a2 - v0;
    if (!(v0 < 0x800)) {
        a2++;
    }
    v0 = v1;
    if (v1 < 0) {
        v0 = v1 + 0xFFF;
    }
    v0 >>= 12;
    v0 <<= 12;
    v0 = v1 - v0;
    if (!(v0 < 0x800)) {
        v1++;
    }
    v0 = a2;
    if (a2 < 0) {
        v0 = a2 + 0xFFF;
    }
    a2 = v0 >> 12;
    v0 = v1;
    if (v1 < 0) {
        v0 = v1 + 0xFFF;
    }
    v1 = v0 >> 12;
    c0 = (s32) s0;
    c1 = (s32) D_800473BC;
    buf[0] = a2;
    buf[1] = v1;
    args = (EventDrawArgs *) ((u8 *) buf - 8);
    v0 = (s32) buf;
    args->coords = (s16 *) v0;
    MEMORY_BARRIER();
    v0 = (s32) (arg0 + 0x18);
    args->extra = (u8 *) v0;
    table = D_800473C4;
    a2 = (s32) D_800473B4 + ((s32) table - (s32) table);
    func_80044BA0((u8 *) c0, (u8 *) c1, (u16 *) a2, table + s5, *args);
    s5 += 0xC;
    if (*(s32 *) (arg0 + 8) != 0) {
        p2 += 0x28;
        v0 = *(u32 *) arg0;
        v1 = s0->packed;
        v0 = *(u32 *) v0;
        v1 &= s7;
        v0 &= s6;
        v1 |= v0;
        s0->packed = v1;
        v1 = *(u32 *) arg0;
        v0 = *(u32 *) v1;
        c0 = (s32) s0 & s6;
        s0++;
        v0 &= s7;
        v0 |= c0;
        *(u32 *) v1 = v0;
    }
    s4++;
    if (s4 < D_80047595) {
        s3 += 4;
        goto loop;
    }
end:
    P16SetPolyF4((GpuPacket *) s0);
    s0->at_04 = 8;
    s0->at_05 = 8;
    s0->at_06 = 8;
    P10SetSemiTrans((GpuPacket *) s0, 1);
    P11SetShadeTex((GpuPacket *) s0, 0);
    {
        register s32 cm asm("a0");
        register s32 am asm("a1");
        register s32 ev asm("v0");

        cm = 0xFFFFFF;
        s0->at_08 = 0;
        s0->at_0A = 0;
        ev = 0xFF;
        am = 0xFF000000;
        s0->at_10 = ev;
        s0->at_12 = 0;
        s0->at_18 = 0;
        s0->at_1A = ev;
        s0->at_20 = ev;
        s0->at_22 = ev;
        v0 = *(u32 *) arg0;
        v1 = s0->packed;
        v0 = *(u32 *) v0;
        v1 &= am;
        v0 &= cm;
        v1 |= v0;
        s0->packed = v1;
        v1 = *(u32 *) arg0;
        v0 = *(u32 *) v1;
        cm = (s32) s0 & cm;
        v0 &= am;
        v0 |= cm;
        *(u32 *) v1 = v0;
    }
}

void CallBuildZODIACBIN(void) {
    BuildZODIACBIN();
}

extern char D_80047598[];
extern char D_800475A0[];
extern char D_800475A8[];

void OpenFrameBINToVRAM(void) {
    s32 var_s0;

    var_s0 = ((s32 (*)(s32, s32)) GetBINAsTIM)(0xE68, 0x9800);
    func_800248FC(D_80047598, var_s0 + 0x1000);
    func_800248FC(D_800475A0, var_s0 + 0x9000);
    func_800248FC(D_800475A8, var_s0 + 0x9200);
    func_800246D4(0);
    ((void (*)(s32)) CallFree)(var_s0);
}

extern u32 D_80010004;
extern void OpenWORLDFile(s32, s32, s32, s32);
extern void func_800672F8(void);

void OpenWORLDBINAndWLDCOREBIN(s32 arg0) {
    OpenWORLDFile(0x14849, 0xDC, D_80010000, 0);
    if (arg0 != 0) {
        OpenWORLDFile(0x14925, 0x1E0, D_80010004, 1);
    }
    func_800672F8();
}

void OpenWORLDBIN(s32 arg0) {
    OpenWORLDFile(0x14925, 0x1E0, D_80010004, arg0 - 1);
}

extern void BuildFileHeader(u8 *, s32, s32, s32, s32);

void OpenWORLDFile(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p = D_8004EAF4;

    BuildFileHeader(p, arg0, arg1, arg2, arg3);
    if (D_8004EAF8 != 0) {
        do {
            func_80011E38(p);
            func_8001DBA8(0);
        } while (D_8004EAF8 != 0);
    }
}

typedef struct {
    u8 b[16];
} B16;

typedef struct {
    s32 w[4];
} W16;

extern u8 D_80059594[];
extern u8 D_800595AE[];
extern u8 D_800595A2[];
extern u8 D_800595C8[];
extern u8 D_800595A6[];
extern u8 *D_800454CC;
extern u8 D_80057F34[];
extern u8 D_800595AA[];
extern u8 D_800595E2[];
extern u8 D_8005961A[];
extern u8 D_80059652[];
extern u8 D_8005968A[];
extern u8 D_80059410[];
extern u8 D_80059814[];
extern u8 D_80057D83[];
extern u8 D_80057CE8;
extern u32 D_8004D950;

void func_800452EC(void) {
    s32 a0 = 0;
    s32 cm1 = -1;
    u8 *a3 = D_800D0BBC;
    register u8 *v1 asm("v1") = D_80059594;
    s32 a1 = 0;
    do {
        *(u16 *) (v1 + 0x26) = cm1;
        *(u16 *) (v1 + 0x24) = cm1;
        *(u16 *) (v1 + 0x22) = cm1;
        *(u16 *) (v1 + 0x20) = cm1;
        *(u16 *) (v1 + 0x1E) = cm1;
        __asm__ volatile("lui $at, %%hi(D_800595AE)\n\taddiu $at, $at, %%lo(D_800595AE)\n\taddu $at, $at, %1\n\tsh %0, 0($at)" : : "r"(cm1), "r"(a1) : "at", "memory");
        *(u16 *) (v1 + 0x2C) = 0;
        *(u16 *) (v1 + 0x2A) = 0;
        *(u16 *) (v1 + 0x0C) = 0;
        __asm__ volatile("lui $at, %%hi(D_800595A2)\n\taddiu $at, $at, %%lo(D_800595A2)\n\taddu $at, $at, %0\n\tsh $zero, 0($at)" : : "r"(a1) : "at", "memory");
        __asm__ volatile("lui $at, %%hi(D_800595C8)\n\taddiu $at, $at, %%lo(D_800595C8)\n\taddu $at, $at, %0\n\tsw $zero, 0($at)" : : "r"(a1) : "at", "memory");
        *(u16 *) (v1 + 0x18) = 0;
        *(u16 *) (v1 + 0x14) = 0;
        v1 += 0x38;
        __asm__ volatile("lui $at, %%hi(D_800595A6)\n\taddiu $at, $at, %%lo(D_800595A6)\n\taddu $at, $at, %0\n\tsh $zero, 0($at)" : : "r"(a1) : "at", "memory");
        __asm__ volatile("lui $at, %%hi(D_80059594)\n\taddiu $at, $at, %%lo(D_80059594)\n\taddu $at, $at, %1\n\tsw %0, 0($at)" : : "r"(a3), "r"(a1) : "at", "memory");
        a1 += 0x38;
        a0 += 1;
    } while (a0 < 5);
    a3 = D_80057F34;
    {
        u8 *a2 = D_800454CC;
        u8 *t0;
        *(u16 *) D_800595AA = 0x10;
        *(u16 *) D_800595E2 = 0x10;
        *(u16 *) D_8005961A = 0;
        *(u16 *) D_80059652 = 0;
        *(u16 *) D_8005968A = 0x10;
        t0 = a2 + 0x40;
        if ((((u32) a2 | (u32) a3) & 3) != 0) {
            do {
                *(B16 *) a3 = *(B16 *) a2;
                a2 += 0x10;
                a3 += 0x10;
            } while (a2 != t0);
            a0 = 0x27;
        } else {
            do {
                *(W16 *) a3 = *(W16 *) a2;
                a2 += 0x10;
                a3 += 0x10;
            } while (a2 != t0);
            a0 = 0x27;
        }
    }
    {
        s32 *v0 = (s32 *) D_80059410;
        do {
            *v0 = 0;
            a0 -= 1;
            v0 -= 1;
        } while (a0 >= 0);
        a0 = 1;
        v0 = (s32 *) D_80059814;
        do {
            *v0 = 0;
            a0 -= 1;
            v0 -= 1;
        } while (a0 >= 0);
    }
    {
        u8 *v0;
        a0 = 0x5F;
        v0 = D_80057D83;
        do {
            *v0 = 0;
            a0 -= 1;
            v0 -= 1;
        } while (a0 >= 0);
    }
    D_80057CE8 = 0;
    D_8004D950 = 0;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_4", D_800454CC);

extern u8 D_80057B20;
extern u8 D_80057B21;
extern u8 D_80057B22;
extern u8 D_80057B23;
extern u8 D_80057B24;
extern u8 D_80057B25;
extern u8 D_80057B26;
extern u8 D_80057B27;
extern u8 D_80057B28;
extern u8 D_80057B29;
extern u8 D_80057B2A;
extern s8 D_80057B2B;
extern u8 D_80057B2C;
extern u8 D_80057B2D;
extern u8 D_80057B2E;
extern u8 D_80057B2F;
extern u8 D_80057B30;
extern u8 D_80057B31;
extern u8 D_80057B32;
extern s8 D_80057B33;
extern u8 D_80057B34;
extern u8 D_80057B35;
extern u8 D_80057B36;
extern u8 D_80057B37;
extern u8 D_80057B38;
extern u8 D_80057B39;
extern s8 D_80057B3A;
extern u8 D_80057B3C;
extern u8 D_80057B3D;
extern u8 D_80057B3E;
extern u8 D_80057B3F;
extern s8 D_80057B40;
extern u8 D_80057B44;
extern u8 D_80057B45;
extern u8 D_80057B46;
extern u8 D_80057B47;
extern s8 D_80057B48;
extern u8 D_80057B4C;
extern u8 D_80057B4D;
extern u8 D_80057B4E;
extern u8 D_80057B4F;
extern u8 D_80057B50;
extern u8 D_80057B51;
extern s8 D_80057B52;
extern u8 D_80057B54;
extern u8 D_80057B55;
extern u8 D_80057B56;
extern u8 D_80057B57;
extern s8 D_80057B58;
extern u8 WeaponPageOrder;
extern u8 HelmetPageOrder;
extern u8 ArmorPageOrder;
extern u8 AccessoryPageOrder;
extern u8 D_80057C54;
extern u8 PoachedItemQuantities[];
extern void func_800222FC(u8 *, s32, s32);

void func_80045514(void) {
    register s32 c1 asm("a1");
    register s32 c2 asm("a0");
    s32 c3;
    s32 c4;
    s32 c5;
    register s32 c7 asm("t0");
    register s32 c9 asm("a2");
    register s32 cv asm("v0");
    c1 = 1;
    c2 = 2;
    c3 = 3;
    c4 = 4;
    c5 = 5;
    cv = 6;
    c7 = 7;
    __asm__("" : "=r"(c3), "=r"(c4), "=r"(c5), "=r"(c7) : "0"(c3), "1"(c4), "2"(c5), "3"(c7));
    D_80057B26 = cv;
    cv = 8;
    c9 = 9;
    D_80057B28 = cv;
    cv = 10;
    D_80057B2A = cv;
    cv = -1;
    D_80057B20 = 0;
    D_80057B21 = c1;
    D_80057B22 = c2;
    D_80057B23 = c3;
    D_80057B24 = c4;
    D_80057B25 = c5;
    D_80057B27 = c7;
    D_80057B29 = c9;
    D_80057B2B = cv;
    D_80057B2C = 0;
    D_80057B2D = c1;
    D_80057B2E = c2;
    D_80057B2F = c4;
    D_80057B30 = c5;
    D_80057B31 = c7;
    D_80057B32 = c9;
    D_80057B33 = cv;
    D_80057B34 = 0;
    D_80057B35 = c1;
    D_80057B36 = c2;
    D_80057B37 = c3;
    D_80057B38 = c4;
    D_80057B39 = c5;
    D_80057B3A = cv;
    D_80057B3C = 0;
    D_80057B3D = c1;
    D_80057B3E = c2;
    D_80057B3F = c5;
    D_80057B40 = cv;
    D_80057B44 = 0;
    D_80057B45 = c1;
    D_80057B48 = cv;
    D_80057B52 = cv;
    D_80057B58 = cv;
    D_80057B46 = c2;
    D_80057B4E = c2;
    D_80057B56 = c2;
    D_80057B4D = c1;
    D_80057B55 = c1;
    D_80057B47 = c5;
    D_80057B4C = 0;
    D_80057B4F = c3;
    D_80057B50 = c4;
    D_80057B51 = c5;
    D_80057B54 = 0;
    D_80057B57 = c5;
    cv = 0xFF;
    WeaponPageOrder = cv;
    HelmetPageOrder = cv;
    ArmorPageOrder = cv;
    AccessoryPageOrder = cv;
    D_80057C54 = cv;
    func_800222FC(PoachedItemQuantities, 0, 0x100);
}

extern u8 D_80057C6B;
extern s32 D_800596C0;
extern s32 D_800596C4;
extern s32 D_800596C8;
extern s32 D_800596CC;
extern s32 D_800596D0;
extern s32 D_800596D4;
extern s32 D_800596D8;
extern s32 D_800596DC;
extern void func_80022034(void);
extern void func_80022044(void);
extern s32 func_80021F74(s32, s32, s32, s32);
extern void func_80021FB4(s32);
extern void func_800220F4(s32);
extern void func_80021F34(void);
extern void func_80028760(s32);
extern void func_800287D8(s32);
extern void CardStartCARDEarlysafe(void);

void InitMemCardEVT(void) {
    s32 *var_s0;
    s32 temp_a0;
    s32 var_s1;

    if (D_80057C6B == 0) {
        s32 c0;
        s32 *nv;

        var_s1 = 0;
        func_80022034();
        c0 = func_80021F74(0xF4000001, 4, 0x2000, 0);
        var_s0 = &D_800596C0;
        *var_s0 = c0;
        D_800596C4 = func_80021F74(0xF4000001, 0x8000, 0x2000, 0);
        D_800596C8 = func_80021F74(0xF4000001, 0x100, 0x2000, 0);
        D_800596CC = func_80021F74(0xF4000001, 0x2000, 0x2000, 0);
        D_800596D0 = func_80021F74(0xF0000011, 4, 0x2000, 0);
        D_800596D4 = func_80021F74(0xF0000011, 0x8000, 0x2000, 0);
        D_800596D8 = func_80021F74(0xF0000011, 0x100, 0x2000, 0);
        D_800596DC = func_80021F74(0xF0000011, 0x2000, 0x2000, 0);
        func_800287D8(1);
        CardStartCARDEarlysafe();
        func_800220F4(0);
        func_80021F34();
        func_80028760(0);
        nv = var_s0;
        do {
            temp_a0 = *nv;
            nv += 1;
            var_s1 += 1;
            func_80021FB4(temp_a0);
        } while (var_s1 < 8);
        func_80022044();
        D_80057C6B = 1;
    }
}

extern void func_800670F0(s32);

void OpenExecOPENBIN1(s32 arg0) {
    GetDATAsWD(0x14FF0, 0x36800, D_80010000);
    func_800670F0(arg0);
}

extern void func_8006720C(void);

void OpenExecOPENBIN2(void) {
    GetDATAsWD(0x14FF0, 0x36800, D_80010000);
    func_8006720C();
}
