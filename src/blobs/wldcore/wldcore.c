#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();
extern void func_800FFD70();
extern void func_80024868();
extern void func_8001D578();
extern u8 D_800D0BBC[];
extern u8 D_8004EAF4[];
extern void func_80092B04();
extern void func_80091174();
extern void func_8008FAD8();
extern void func_8008F514();
extern void func_8008EDBC();
extern s32 func_8008D2C8();
extern void func_8007A6B8();
extern void func_8006ED30();
extern void func_8006C844();
extern void func_80068D74();
extern void func_80068B3C();
extern s16 D_800D486C;
extern s32 D_800D3CB8[];
extern s32 D_800D09A0[];
extern s32 D_800BBC88[];
extern s32 D_8009EF80[];
extern u8 D_80057EEC[];
extern void func_800674E0();
extern void func_80090D30();
extern s32 D_800BB504[];
extern s32 D_800BB508[];
extern s32 D_800BB510[];
extern s32 D_800BB514[];
extern s32 D_800BB518[];
extern s32 D_800BBC70[];
extern s16 D_800D0880[];
extern s32 D_800BB9BC[];
extern void func_8008FCC8();
extern s16 D_800D4852;
extern s32 D_800D3CD0[];
extern s32 D_800D3CD4[];
extern s32 D_800BBC84[];
extern void func_8006C44C();
extern void func_8008F72C();
extern void func_8008F828();
extern s32 D_800BB9B0;
extern s16 D_800BBC9C[];
extern s16 D_800BBC9E[];
extern s16 D_800D4574;

typedef struct WldCoreTempPair {
    s32 first;
    s32 second;
} WldCoreTempPair;

typedef struct WldCoreRec24 {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 f20[3];
} WldCoreRec24;

extern s32 D_800D4584[];
extern s32 D_800BB3C0;
extern s32 func_800EF1A8(s32);
extern s32 D_8004E5BC;
extern s32 D_8004D950;
extern s32 D_8009F31C;
extern s32 func_800E1524();
extern s32 func_800694A8();
extern s32 func_8008CF14();
extern s32 func_800449EC();

s32 func_800672F8(void) {
    extern s32 func_8006858C();
    extern s32 func_80067C2C();
    extern s32 func_80069400();
    extern s32 func_80011E38();
    extern s32 func_80090E20();
    extern s32 func_800E1A88();
    extern s32 func_8006C3DC();
    extern s32 func_80067484();
    extern s32 func_800677A4();
    extern s32 func_80067A78();
    extern s32 func_80024638();
    extern s32 func_800682A0();
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

top:
    v0 = func_8006858C();
    if (v0 != 0) {
        v0 = 0;
        goto fin;
    }
    func_80067C2C();
    func_80069400(0, 0x10);
    while (D_8004D950 & 1) {
        a0 = (s32) &D_8004EAF4[0];
        func_80011E38(a0);
        func_80090E20();
        v0 = func_800E1524();
        a0 = v0 * 57344;
        v1 = (s32) &D_8009F31C;
        D_8004E5BC = v0;
        a0 = a0 + v1;
        func_800E1A88(a0);
        func_800694A8();
        func_8008CF14();
        func_8006C3DC();
        func_80067484();
        v0 = D_8004D950;
        v0 = v0 & 2;
        if (v0 != 0) {
            func_800677A4();
        } else {
            func_80067A78();
        }
        v0 = D_8004D950;
        v0 = v0 & 0x40;
        if (v0 == 0) {
            a0 = 1;
        } else {
            USE(v0);
            a0 = 0;
        }
        func_80024638(a0);
        func_800449EC();
    }
    v1 = 0x10000;
    v0 = D_8004D950;
    v0 = v0 & v1;
    if (v0 != 0)
        goto top;
    func_800682A0();
    v1 = D_8004D950;
    if (v1 & 0x10000000) {
        v0 = 5;
        goto fin;
    }
    if (v1 & 0x2000000) {
        v0 = 4;
        goto fin;
    }
    if (v1 & 0x200000) {
        v0 = 2;
        goto fin;
    }
    if (v1 & 0x40000) {
        v0 = 2;
        goto fin;
    }
    v0 = v1 & 0x8000;
    v0 = v0 != 0;
fin:
    return v0;
}

extern s32 D_8009F1E4;

void func_80067484(void) {
    s32 v0;

    v0 = D_8004D950;
    if (((v0 & 2) == 0) && ((D_8009F1E4 & 2) != 0))
        func_800674E0();
    D_8009F1E4 = D_8004D950;
}

extern s32 D_800BB364;
extern s32 D_8009F198;
extern s32 D_8009F1E8;
extern s32 D_8009F1A0;
extern s32 D_800BB3C4;
extern s32 D_800BB500;
extern s32 D_800C72F4;
extern void func_800E1710();
extern void func_800E13E8();

void func_800674E0(void) {
    extern void func_800246D4(s32);
    extern void func_8001DBA8(s32);
    extern s32 func_800E1A88();
    extern void func_800E1900();
    extern void func_80080758(void *);
    extern void func_8006A9D8(void *);
    extern void func_8008D51C(void *);
    extern void func_8008CDF0();
    extern void func_8006AE20();
    extern void func_80092B1C();
    extern void func_800E18DC(void *);
    extern void func_80024960(s32, s32);
    extern void func_8008F434();
    extern void func_8006C248(void *);
    extern void func_8006B78C(void *);
    extern void func_8006BF9C(void *);
    extern void func_8006C108(void *);
    s32 *s0;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    volatile s32 sp10[2];

    func_800246D4(0);
    func_8001DBA8(0);
    func_800E1710();
    v0 = func_800E1524();
    a0 = v0 * 0xE000;
    D_8004E5BC = v0;
    a0 += (s32) &D_8009F31C;
    func_800E1A88(a0);
    a0 = 0;
    a1 = 0;
    MEMORY_BARRIER();
    v0 = D_8004E5BC;
    s0 = &D_800BB3C4;
    a2 = v0 * 0x14;
    a2 += (s32) s0;
    func_800E1900(a0, a1, (void *) a2);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_80080758((void *) a0);
    a0 = 0x1F8003FC;
    func_80092B04(a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006A9D8((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8008D51C((void *) a0);
    func_8008CDF0();
    a1 = (s32) &D_8009F1A0;
    v0 = D_8004E5BC;
    a2 = D_8009F1E8;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006AE20((void *) a0, (void *) a1, a2);
    func_80092B1C();
    a0 = 0;
    a1 = 0;
    v0 = D_8004E5BC;
    a2 = 0;
    a3 = v0 * 0x14;
    a3 += (s32) s0;
    func_800E13E8(a0, a1, a2, (void *) a3);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_800E18DC((void *) a0);
    func_800246D4(0);
    a0 = D_8004E5BC;
    a1 = (s32) &sp10[0];
    func_80068D74(a0, (s16 *) a1);
    a1 = D_800C72F4;
    func_80024960((s32) &sp10[0], a1);
    func_800246D4(0);
    a0 = 0;
    a1 = 0;
    MEMORY_BARRIER();
    v0 = -1;
    v1 = D_8004E5BC;
    s0 = &D_800BB364;
    D_800BB500 = v0;
    a2 = v1 * 0x14;
    a2 += (s32) s0;
    func_800E1900(a0, a1, (void *) a2);
    func_8008F434();
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006C248((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006B78C((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006BF9C((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006C108((void *) a0);
    a1 = (s32) &D_8009EF80;
    v0 = D_8004E5BC;
    a2 = D_8009F198;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006AE20((void *) a0, (void *) a1, a2);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_800E18DC((void *) a0);
    func_800246D4(0);
}

extern void func_8008E540();

void func_800677A4(void) {
    extern void func_800E1900();
    extern void func_80080758(void *);
    extern void func_8006A888();
    extern void func_8006A9D8(void *);
    extern void func_80092B1C();
    extern void func_8008D51C(void *);
    extern void func_8008DBFC(void *);
    extern void func_8008CDF0();
    extern void func_8008F434();
    extern void func_8006C248(void *);
    extern void func_8006B78C(void *);
    extern void func_8006BF9C(void *);
    extern void func_8006C108(void *);
    extern void func_8006AE20();
    extern void func_800246D4(s32);
    extern void func_80068DA4();
    extern void func_8001DBA8(s32);
    extern void func_800E18DC(void *);
    s32 *s0;
    s32 *s1;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 v0;
    register s32 v1 asm("v1");

    a0 = 0;
    v0 = D_8004E5BC;
    a1 = 0;
    s1 = &D_800BB3C4;
    a2 = v0 * 0x14;
    a2 += (s32) s1;
    func_800E1900(a0, a1, (void *) a2);
    a0 = 0;
    a1 = 0;
    v0 = D_8004E5BC;
    s0 = &D_800BB364;
    a2 = v0 * 0x14;
    a2 += (s32) s0;
    func_800E1900(a0, a1, (void *) a2);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_80080758((void *) a0);
    a0 = 0x1F8003FC;
    func_80092B04(a0);
    func_8006A888();
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s1;
    func_8006A9D8((void *) a0);
    func_80092B1C();
    func_8008E540();
    a0 = 0x1F8003FC;
    func_80092B04(a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s1;
    func_8008D51C((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s1;
    func_8008DBFC((void *) a0);
    func_8008CDF0();
    func_8008F434();
    func_80092B1C();
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006C248((void *) a0);
    a0 = 0x1F8003FC;
    func_80092B04(a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006B78C((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006BF9C((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006C108((void *) a0);
    a1 = (s32) &D_8009F1A0;
    v0 = D_8004E5BC;
    a2 = D_8009F1E8;
    a0 = v0 * 0x14;
    a0 += (s32) s1;
    func_8006AE20((void *) a0, (void *) a1, a2);
    a1 = (s32) &D_8009EF80;
    v0 = D_8004E5BC;
    a2 = D_8009F198;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006AE20((void *) a0, (void *) a1, a2);
    func_80092B1C();
    func_800246D4(0);
    func_80068DA4();
    func_8001DBA8(0);
    func_800E1710();
    a0 = 0;
    a1 = 0;
    v0 = D_8004E5BC;
    a2 = 0;
    a3 = v0 * 0x14;
    a3 += (s32) s1;
    func_800E13E8(a0, a1, a2, (void *) a3);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s1;
    func_800E18DC((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_800E18DC((void *) a0);
    v0 = D_8004D950;
    v1 = -3;
    v0 &= v1;
    D_8004D950 = v0;
}

void func_80067A78(void) {
    extern void func_800E1900(s32, s32, void *);
    extern void func_800246D4(s32);
    extern void func_80080758(void *);
    extern void func_8006C248(void *);
    extern void func_8006B78C(void *);
    extern void func_8006BF9C(void *);
    extern void func_8006C108(void *);
    extern void func_8006AE20(void *, s32 *, s32);
    extern void func_80069810();
    extern void func_80092B1C();
    extern void func_80068DA4();
    extern void func_8001DBA8(s32);
    extern void func_800E18DC(void *);
    s32 *s0;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 *at asm("at");
    s32 sp10;

    s0 = &D_800BB364;
    a0 = 0;
    v0 = D_8004E5BC;
    a1 = 0;
    a2 = v0 * 0x14;
    a2 += (s32) s0;
    func_800E1900(a0, a1, (void *) a2);
    func_800246D4(0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_80080758((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006C248((void *) a0);
    a0 = 0x1F8003FC;
    func_80092B04(a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006B78C((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006BF9C((void *) a0);
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006C108((void *) a0);
    a1 = (s32) &D_8009EF80;
    v0 = D_8004E5BC;
    a2 = D_8009F198;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_8006AE20((void *) a0, (s32 *) a1, a2);
    func_80069810();
    func_80092B1C();
    func_800246D4(0);
    func_80068DA4();
    func_8001DBA8(0);
    func_800E1710();
    v0 = D_8004D950;
    v0 &= 0x200;
    if (v0 == 0) {
        a1 = (s32) &sp10;
        a0 = D_8004E5BC;
        a0 = (u32) a0 < 1;
        func_80068D74(a0, (s32 *) a1);
        a0 = (s32) &sp10;
        a1 = D_800C72F4;
        func_800248FC((s32 *) a0, a1);
    }
    v0 = D_8004E5BC;
    a0 = v0 * 0x14;
    a0 += (s32) s0;
    func_800E18DC((void *) a0);
}

extern void func_80024638();
extern void func_80067D70();
extern void func_80067E38();
extern void func_80068308();
extern void func_800683FC();
extern void func_80068640();
extern void func_80068FA8();
extern void func_8006A58C();
extern void func_8006AD28();
extern void func_8006C1FC();
extern void func_8006C350();
extern void func_8008CB8C();
extern void func_8008D514();
extern void func_8008F284();

void func_80067C2C(void) {
    func_80024638(0);
    func_80067E38();
    func_80068FA8();
    func_80068640();
    func_80067D70();
    func_8006AD28();
    func_8006A58C();
    func_8006C1FC();
    func_8008CB8C();
    func_8008D514();
    func_8008F284();
    func_8006C350();
    func_80068308();
    func_800683FC();
}

extern void func_800E1648();

void func_80067CB4(s32 arg0) {
    extern void func_800246D4(s32);
    extern void func_800E16D8(s16 *);
    s32 s0;
    s32 s1;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    struct {
        s16 sp10;
        s16 sp12;
        s16 sp14;
        s16 sp16;
    } sp;

    s0 = arg0;
    a0 = (s32) &sp.sp10;
    KEEP_NOVOL(a0);
    s1 = 0x100;
    KEEP_NOVOL(s1);
    v1 = 0x04000000;
    a1 = 0;
    a2 = 0;
    v0 = 0x1E0;
    sp.sp16 = (s16) v0;
    v0 = D_8004D950;
    D_8004D950 = v0 | v1;
    sp.sp10 = 0;
    sp.sp12 = 0;
    sp.sp14 = (s16) s1;
    func_80024868((s16 *) a0, a1, a2, 0);
    func_800246D4(0);
    v0 = 0xEE;
    if (s0 == 0) {
        v0 = 8;
        sp.sp12 = (s16) v0;
        v0 = 0xFC;
        sp.sp14 = (s16) v0;
        v0 = 0xE4;
        sp.sp10 = 0;
    } else {
        sp.sp10 = 0;
        sp.sp12 = 0;
        sp.sp14 = (s16) s1;
    }
    sp.sp16 = (s16) v0;
    func_800E16D8(&sp.sp10);
    func_800E1648();
}

extern void func_8001D1A8(s32, s32);
extern void func_80067CB4();
extern void func_800E10F4(s32, s32, s32, s32, s32);
extern void func_800E17C4(s32, s32, s32, s32);
extern void func_800E1864(void);
extern u8 *D_800BB368;
extern s32 D_800BB378;
extern u8 *D_800BB37C;
extern u8 *D_800BB3C8;
extern s32 D_800BB3D8;
extern u8 *D_800BB3DC;
extern u8 D_800D487C;
extern u8 D_800D4908;

void func_80067D70(void) {
    func_80024638(0);
    func_800E10F4(0x100, 0xF0, 4, 0, 0);
    func_800E17C4(0, 0, 0, 0xF0);
    func_800E1864();
    func_8001D1A8(0, 0);
    func_80067CB4(0);
    D_800BB3D8 = 2;
    D_800BB3C4 = 2;
    D_800BB3C8 = &D_800D4908;
    D_800BB3DC = &D_800D4908 + 0x10;
    D_800BB378 = 4;
    D_800BB364 = 4;
    D_800BB368 = &D_800D487C;
    D_800BB37C = &D_800D487C + 0x40;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_80067E38);

extern void func_8001DBA8();
extern void func_800246D4();
extern void func_80043F00();
extern void func_800911CC();
extern void func_800EF25C();
extern s32 D_800BBC6C;

void func_800682A0(void) {
    func_800246D4(0);
    func_8001DBA8(0);
    func_80024638(0);
    func_800911CC();
    if (!(D_8004D950 & 0x200000)) {
        func_80043F00();
    }
    func_800EF25C(0x33, D_800BBC6C);
}

extern s32 D_8009F254;
extern void func_80024238();
extern s32 D_8009F258;

void func_80068308(void) {
    extern void func_80024638();
    extern s32 func_80068A68();
    extern void func_800686C8();
    extern void func_800E1A88();
    extern void func_8001DBA8();
    extern void func_800E1900();
    extern void func_8006A018();
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    volatile s32 pad[2];

    func_80024638(0);
    a0 = D_8009F254;
    v0 = func_80068A68(a0);
    D_8009F258 = v0;
    func_800686C8();
    v0 = func_800E1524();
    D_8004E5BC = v0;
    a0 = v0 * 0xE000;
    a0 += (s32) &D_8009F31C;
    func_800E1A88(a0);
    func_800674E0();
    func_8001DBA8(0);
    func_80024238(1);
    a0 = 0;
    v0 = D_8004E5BC;
    a1 = 0;
    a2 = v0 * 20;
    a2 += (s32) &D_800BB3C4;
    func_800E1900(a0, a1, a2);
    a0 = 0;
    v0 = D_8004E5BC;
    a1 = 0;
    a2 = v0 * 20;
    a2 += (s32) &D_800BB364;
    func_800E1900(a0, a1, a2);
    func_8006A018(0);
    func_800E1710();
    func_80024638(0);
}

extern s32 D_8004D9B0;
extern s32 D_800BB4F0;
extern s32 D_800D4634;
extern s32 D_800D4638;
extern s32 D_800D463C;
extern s32 D_800D4664;

void func_800683FC(void) {
    extern void func_8006C894(void);
    extern void func_80070BE4(s32);
    extern void func_80088308(s32, s32, s32);
    extern void func_80090D50(s32, s32);
    extern void func_800EF25C(s32, s32);
    extern u8 D_800BB930[];
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    v1 = 0xFFFEFFFF;
    v0 = D_8004D950;
    v1 &= v0;
    D_8004D950 = v1;
    v0 = v1 & 0x202C0000;
    if (v0 == 0) {
        a2 = 0x40000;
        a0 = D_8009F254;
        __asm__ volatile(".set\tnoreorder\n\tjal\tfunc_80091238\n\tori\t$5,$zero,0x10\n\t.set\treorder" : "=r"(v0) : "r"(a0), "r"(a2) : "ra", "memory");
        if (v0 != 0) {
            v0 = D_800BB4F0;
            a0 = v0 * 0x5C;
            a0 += (s32) &D_800BB930[0];
            func_8006C844((void *) a0);
            a0 = D_800D4664 + 0x5800;
            func_80070BE4(a0);
        } else {
            func_8006C894();
        }
        a0 = 1;
        a1 = 0x11B;
        func_80090D50(a0, a1);
        a0 = 3;
        a1 = 4;
        func_80090D50(a0, a1);
        return;
    }
    a2 = 0x40000;
    v0 = v1 & a2;
    if (v0 != 0) {
        v0 = v1 ^ a2;
        D_8004D950 = v0;
        a0 = 0x23;
        a1 = D_8004D9B0;
        func_800EF25C(a0, a1);
        a0 = 0x1D;
        a1 = 0;
        a2 = 0;
        func_80088308(a0, a1, a2);
        return;
    }
    a2 = 0x200000;
    v0 = v1 & a2;
    if (v0 != 0) {
        v0 = v1 ^ a2;
        D_8004D950 = v0;
        a0 = 0x23;
        a1 = D_8004D9B0;
        func_800EF25C(a0, a1);
        a0 = 0x2D;
        a1 = 1;
        a2 = 0;
        D_800D4634 = 0x1B;
        D_800D4638 = 0x1A;
        D_800D463C = 2;
        func_80088308(a0, a1, a2);
        return;
    }
    v0 = v1 & 0x80000;
    if (v0 != 0) {
        a0 = 0x2B;
        a1 = 0;
        a2 = 1;
        func_80088308(a0, a1, a2);
        return;
    }
    v0 = v1 & 0x20000000;
    if (v0 != 0) {
        a0 = 0x1C;
        a1 = 0;
        a2 = 0;
        func_80088308(a0, a1, a2);
    }
}

extern void func_80106660(void);

s32 func_8006858C(void) {
    if (func_800EF1A8(0x55) != 0) {
        D_8004D950 &= 0xFFFEFFFF;
        func_80106660();
        return 1;
    }
    return 0;
}

extern void func_80011BD0();
extern void func_800686C8();

void func_800685E0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_800686C8();
    func_80011BD0(arg0, arg1, arg2, arg3);
}

extern s32 D_8004EAF8;

void func_80068640(void) {
    extern void func_800685E0(u8 *, s32, s32, s32);
    extern void func_8006872C(s32 *);
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    volatile s32 pad[2];

    v0 = D_8004D950;
    v1 = 0x10000;
    v0 &= v1;
    if (v0 != 0)
        goto exit;
    s0 = (s32 *) &D_8004EAF4;
    a0 = (s32) s0;
    a1 = 0x11D28;
    a2 = 0x86;
    a3 = D_800C72F4;
    func_800685E0((u8 *) a0, a1, a2, a3);
    v0 = D_8004EAF8;
    if (v0 == 0)
        goto exit;
loop:
    a0 = (s32) s0;
    func_8006872C(a0);
    v0 = D_8004EAF8;
    if (v0 != 0)
        goto loop;
exit:
    return;
}

extern void func_80011E38(s32 *);
extern void func_80090E20(void);

void func_800686C8(void) {
    s32 *p = &D_8004EAF8;
    s32 *q;

    if (*p != 0) {
        q = p - 1;
        do {
            func_80011E38(q);
            func_80090E20();
            func_8001DBA8(0);
        } while (D_8004EAF8 != 0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006872C);

extern s32 D_80094DF8;
extern s32 func_80068AB4(s32);

s32 func_80068A68(s32 arg0) {
    u8 t;
    t = *(u8 *) (D_80094DF8 + arg0 * 4 + 2);
    if (t != 0)
        func_80068AB4(t - 1);
    return t;
}

extern s32 D_800BB988;
extern s32 D_800D0AF0;
extern s32 D_8009E0EC[];
extern s32 D_8009E0F0[];

s32 func_80068AB4(s32 arg0) {
    s32 v0;
    s32 v1;
    volatile s32 vs;
    v0 = D_800D0AF0;

    if (arg0 != v0) {
        func_800686C8();
        v1 = D_8009E0EC[arg0];
        D_800D0AF0 = arg0;
        func_800685E0(D_8004EAF4, v1 + 0x11DAE, D_8009E0F0[arg0] - v1, D_800BB988);
    }
}

extern s32 D_8009E260[];
extern s32 D_8009E264[];

void func_80068B3C(s32 arg0) {
    s32 v0;
    s32 v1;
    volatile s32 vs;
    v0 = D_800BB500;

    if (arg0 != v0) {
        func_800686C8();
        v1 = D_8009E260[arg0];
        D_800BB500 = arg0;
        func_800685E0(D_8004EAF4, v1 + 0x12995, D_8009E264[arg0] - v1, D_800C72F4);
    }
}

extern u8 D_800BC2F4[];
extern u8 *D_801CD8E8;
extern s32 D_800D0AF4;
extern s32 D_8009E470[];
extern s32 D_8009E474[];

s32 func_80068BC4(s32 arg0) {
    s32 v0;
    s32 v1;
    volatile s32 vs;
    u8 *s1 = D_800BC2F4;
    v0 = D_800D0AF4;

    D_801CD8E8 = s1;
    if (arg0 != v0) {
        func_800686C8();
        v1 = D_8009E470[arg0];
        D_800D0AF4 = arg0;
        func_800685E0(D_8004EAF4, v1 + 0x11F59, D_8009E474[arg0] - v1, (s32) s1);
    }
}

extern s32 D_8009E634[];
extern s32 D_8009E638[];
extern s32 D_8009E650[];
extern s32 D_8009E654[];

void func_80068C64(s32 arg0) {
    extern void func_800685E0(u8 *, s32, s32, s32);
    extern void func_800686C8();
    s32 s0;
    s32 *s1;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 *at asm("at");
    volatile s32 pad[4];

    s0 = arg0;
    func_800686C8();
    a1 = 0x128F9;
    s1 = &D_8004EAF4;
    a0 = (s32) s1;
    a3 = &D_800D0BBC;
    USE(a3);
    s0 <<= 2;
    at = (s32 *) ((char *) &D_8009E634[0] + s0);
    v0 = *at;
    at = (s32 *) ((char *) &D_8009E638[0] + s0);
    a2 = *at;
    a1 += v0;
    a2 -= v0;
    func_800685E0((u8 *) a0, a1, a2, a3);
    func_800686C8();
    a1 = 0x1291D;
    a0 = (s32) s1;
    s1 = &D_800BC2F4;
    a3 = (s32) s1;
    at = (s32 *) ((char *) &D_8009E650[0] + s0);
    v0 = *at;
    at = (s32 *) ((char *) &D_8009E654[0] + s0);
    a2 = *at;
    a1 += v0;
    a2 -= v0;
    func_800685E0((u8 *) a0, a1, a2, a3);
    v0 = -1;
    D_801CD8E8 = (s32 *) s1;
    D_800D0AF4 = v0;
}

extern void func_800685E0();
extern s32 D_800459C8;

void func_80068D40(void) {
    func_800685E0(D_8004EAF4, D_800459C8, 1, 0);
}

void func_80068D74(s32 arg0, s16 *arg1) {
    arg1[2] = 0x100;
    arg1[0] = 0;
    arg1[3] = 0xEE;
    if (arg0 == 0) {
        arg1[1] = 0;
    } else {
        arg1[1] = 0xF0;
    }
}

extern void func_80018090();
extern void func_80018240();
extern void func_80018300();
extern s32 func_8001DB58(s32);
extern void func_80040974();
extern s32 D_8009F2E8;
extern s32 D_800BB984;
extern s32 D_800BC2F0;
extern s32 D_800C731C;

void func_80068DA4(void) {
    s32 temp_v0;

    D_800BB984 = D_800C731C;
    temp_v0 = func_8001DB58(0);
    D_800C731C = temp_v0;
    if (D_8004D950 & 4) {
        D_800BC2F0 = 0;
        D_8009F2E8 = 0;
    } else {
        D_8009F2E8 = temp_v0;
        D_800BC2F0 = temp_v0 & ~D_800BB984;
    }
    if (D_800C731C == 0x90C) {
        func_800246D4(0);
        func_80018240(0x3FFF, 1);
        func_80018090(0xC0);
        func_80018300(0x74FF, 1);
        func_80040974();
    }
}

struct UNK_80068E70 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_80068E70(struct UNK_80068E70 *arg0, s32 arg1) {
    s32 v0;
    s32 v1;
    s32 t;

    switch (arg1) {
    case 1:
        v1 = arg0->unk0;
        if (v1 < arg0->unk4) {
            arg0->unk0 = v1 + arg0->unk8;
        }
        if (arg0->unk0 > arg0->unk4) {
            arg0->unk0 = arg0->unk4;
        }
        v0 = arg0->unk0;
        KEEP(v0);
        v0 >>= 8;
        goto store;
    case 0:
        v1 = arg0->unk0;
        if (v1 == 0) {
            return;
        }
        if (v1 > 0) {
            v0 = v1 - arg0->unkC;
            arg0->unk0 = v0;
            if (v0 <= 0) {
                arg0->unk0 = 0;
            }
            v0 = arg0->unk0 >> 8;
            goto store;
        }
        v0 = v1 + arg0->unkC;
        arg0->unk0 = v0;
        if (v0 >= 0) {
            arg0->unk0 = 0;
        }
        goto neg_tail;
    case -1:
        t = arg0->unk0;
        if (-t < arg0->unk4) {
            arg0->unk0 = t - arg0->unk8;
        }
        v1 = arg0->unk4;
        if (v1 < -arg0->unk0) {
            arg0->unk0 = -v1;
        }
neg_tail:
        v0 = -((-arg0->unk0) >> 8);
store:
        arg0->unk10 = v0;
    }
}

extern u8 D_800473A1;
extern u8 D_800473A2;
extern u8 D_800473A3;
extern s32 D_800C72F8;
extern s32 D_800C72FC;
extern s32 D_800C7300;
extern s32 D_800C7304;
extern s32 D_800C7308;
extern s32 D_800C730C;
extern s32 D_800C7310;
extern s32 D_800C7314;
extern s32 D_800C7318;
extern s32 D_800D0AB8;

void func_80068FA8(void) {
    u8 t0 = D_800473A1;
    u8 t1 = D_800473A2;
    u8 t2 = D_800473A3;

    D_800C7318 = 0;
    D_800C7314 = 0;
    D_800C7310 = 0;
    D_800C730C = 0;
    D_800C7308 = 0;
    D_800C7304 = 0;
    D_800C72F8 = t0;
    D_800C72FC = t1;
    D_800C7300 = t2;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_80069010);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_800692AC);

extern s32 D_800D0AC8;
extern s32 D_800D0ACC;
extern void func_80090D50(s32 arg0, s32 arg1);

void func_80069400(s32 arg0, s32 arg1) {
    s32 *p = &D_800D0AB8;

    if ((*p & 2) != (arg0 & 2)) {
        s32 b = D_8004D950;
        s32 a = arg0 | 1;

        *p = a;
        D_800D0AC8 = 0;
        D_800D0ACC = arg1;
        D_8004D950 = b | 8;
        if (arg0 & 0x20) {
            func_80090D50(1, 0x11B);
            func_80090D50(3, 0x10);
        }
        if (arg0 & 0x10) {
            func_80090D50(2, 4);
            func_80090D50(4, 2);
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_800694A8);

extern u8 D_8009F19C;
extern u8 D_8009F19D;
extern u8 D_8009F19E;

struct UNK_80069718 {
    u8 x[4];
};

void func_80069718(u8 *arg0, u8 *arg1, s32 arg2) {
    register s32 v0 asm("v0");
    register s32 t0 asm("t0");
    u8 *a2 = arg0;
    u8 *a3 = arg1;
    s32 a0;
    s32 a1;
    register s32 v1 asm("v1");

    if (D_800D0AB8 & 1) {
        v0 = a2[0];
        v0 <<= 16;
        v0 = v0 / 0x80;
        t0 = v0 * D_8009F19C;
        a1 = t0 >> 16;
        v0 = a2[1];
        v0 <<= 16;
        v0 = v0 / 0x80;
        t0 = v0 * D_8009F19D;
        a0 = t0 >> 16;
        v0 = a2[2];
        v0 <<= 16;
        v0 = v0 / 0x80;
        t0 = v0 * D_8009F19E;
        v1 = t0 >> 16;
        if (a1 >= 0x100) {
            a1 = 0xFF;
        }
        if (a0 >= 0x100) {
            a0 = 0xFF;
        }
        if (v1 >= 0x100) {
            v1 = 0xFF;
        }
        KEEP(v1);
        a3[0] = a1;
        a3[1] = a0;
        a3[2] = v1;
    } else {
        *(struct UNK_80069718 *) a3 = *(struct UNK_80069718 *) a2;
    }
}

extern void func_800E0E34(s32 *, void *, u16);
extern s32 D_800D0ADC[];
extern s32 D_800D0ADD[];
extern s32 D_800D0ADE[];

void func_80069810(void) {
    s32 s0;
    s32 *s1;
    s32 *s2;
    s32 *s3;
    s32 *s4;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 v0;
    s32 *at;

    v0 = (s32) &D_800D0AB8;
    s1 = (s32 *) (v0 + 8);
    s4 = s1;
    s3 = (s32 *) (v0 + 0x18);
    s0 = 0;
    s2 = (s32 *) v0;
loop:
    v0 = *s2;
    v0 &= 9;
    if (v0 == 0)
        goto next;
    at = (s32 *) ((char *) D_800D0ADC + s0);
    v0 = *(u8 *) at;
    if (v0 != 0)
        goto call;
    at = (s32 *) ((char *) D_800D0ADD + s0);
    v0 = *(u8 *) at;
    if (v0 != 0)
        goto call;
    at = (s32 *) ((char *) D_800D0ADE + s0);
    v0 = *(u8 *) at;
    if (v0 == 0)
        goto next;
call:
    v0 = D_8004E5BC;
    a2 = *(u16 *) s1;
    a1 = v0 << 2;
    a1 += v0;
    a1 <<= 2;
    v0 = (s32) &D_800BB364;
    a1 += v0;
    a0 = (s32) s3;
    func_800E0E34((s32 *) a0, (void *) a1, (u16) a2);
next:
    s1 += 1;
    s3 += 4;
    s0 += 0x10;
    v0 = (s32) s4 + 8;
    s2 += 1;
    if ((s32) s1 < v0)
        goto loop;
}

extern s32 D_8009D340;

s32 func_80069918(s32 arg0) {
    s32 b;

    b = D_8009D340;
    return b + ((s32 *) b)[arg0];
}

void func_80069934(s16 *arg0, s32 arg1) {
    extern s32 func_80069918();
    register s32 *s1 asm("s1");
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register u8 *a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s1 = (s32 *) arg0;
    s0 = arg1;
    USE(s0);
    {
        register s32 call_a0 asm("a0") = 0;
        a2 = (u8 *) func_80069918(call_a0);
        KEEP(a2);
    }
    v1 = 0;
    v0 = s0;
    v0 <<= 1;
    v0 += s0;
    v0 <<= 3;
    a1 = v0 - s0;
    a0 = (s32) s1;
    do {
        v0 = a1 + v1;
        v0 += a2;
        v0 = *(u8 *) v0;
        v1 += 1;
        *(s16 *) a0 = v0;
        a0 += 2;
        v0 = v1 < 0x17;
    } while (v0);
    v0 = func_80069918(1);
    v1 = *(u16 *) ((char *) s1 + 8);
    v1 <<= 1;
    v1 += v0;
    KEEP(v1);
    a0 = *(u16 *) v1;
    *(u16 *) ((char *) s1 + 8) = a0;
    v1 = *(u16 *) ((char *) s1 + 0xA);
    v1 <<= 1;
    v1 += v0;
    KEEP(v1);
    v0 = *(u16 *) v1;
    *(u16 *) ((char *) s1 + 0xA) = v0;
}

s32 func_800699E4(s32 arg0, s32 arg1) {
    extern void func_80069934(s16 *, s32);
    extern s32 func_80069BB0(s32 *, s32 *);
    extern s32 func_800EF1A8(s32);
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register void *sp asm("sp");
    volatile s32 pad[14];

    v0 = arg0;
    s0 = arg1;
    KEEP_NOVOL(s0);
    a0 = (s32) sp + 0x10;
    KEEP_NOVOL(a0);
    MEMORY_BARRIER();
    a1 = v0;
    func_80069934((s16 *) a0, a1);
    v0 = *(u16 *) ((char *) sp + 0x30);
    if (v0 != 0) {
        if (s0 != v0) {
            v0 = 0;
            goto end;
        }
    }
    v0 = *(u16 *) ((char *) sp + 0x32);
    v0 &= 1;
    if (v0 != 0) {
        a0 = 0x6F;
        v0 = func_800EF1A8(a0);
        v1 = *(u16 *) ((char *) sp + 0x3A);
        v0 = v0 < v1;
        if (v0 != 0) {
            v0 = 0;
            goto end;
        }
    }
    v0 = *(u16 *) ((char *) sp + 0x32);
    v0 &= 2;
    if (v0 != 0) {
        a0 = 0x2E;
        v0 = func_800EF1A8(a0);
        *(s32 *) ((char *) sp + 0x40) = v0;
        a0 = 0x2F;
        v0 = func_800EF1A8(a0);
        *(s32 *) ((char *) sp + 0x44) = v0;
        a0 = (s32) sp + 0x40;
        a1 = (s32) sp + 0x44;
        func_80069BB0((s32 *) a0, (s32 *) a1);
        v1 = *(u16 *) ((char *) sp + 0x3C);
        v0 = *(s32 *) ((char *) sp + 0x40);
        if (v0 != v1) {
            v0 = 0;
            goto end;
        }
    }
    v0 = *(u16 *) ((char *) sp + 0x32);
    v0 &= 4;
    if (v0 == 0) {
        v0 = 1;
        goto end;
    }
    a0 = *(u16 *) ((char *) sp + 0x3C);
    v0 = func_800EF1A8(a0 + 0x360);
    v0 &= 4;
    if (v0 != 0) {
        v0 = 1;
        goto end;
    }
    v0 = 0;
end:
    return v0;
}

extern u8 D_8009E66B[];

void func_80069ADC(void) {
    extern s32 func_800EF1A8(s32);
    extern void func_800EF25C(s32, s32);
    extern void func_80074B30();
    extern void func_80069D40();
    extern void func_80125A04(s32);
    s32 s0;
    s32 s1;
    s32 a1;
    s32 v0;
    s32 v1;
    s32 *at;

    s0 = func_800EF1A8(0x2E);
    s1 = func_800EF1A8(0x2F) + 1;
    at = (s32 *) ((char *) D_8009E66B + s0);
    v1 = *(u8 *) at;
    if (v1 < s1) {
        s0 += 1;
        s1 = 1;
        if (s0 == 0xD)
            s0 = 1;
    }
    MEMORY_BARRIER();
    func_800EF25C(0x2E, s0);
    func_800EF25C(0x2F, s1);
    v0 = 3;
    if (s0 != v0)
        goto skip;
    v0 = 0x15;
    if (s1 != v0)
        goto skip;
    a1 = func_800EF1A8(0x67) + 1;
    if (a1 >= 0x64)
        a1 = 0x63;
    func_800EF25C(0x67, a1);
skip:
    func_80074B30();
    func_80069D40();
    func_80125A04(1);
}

extern u8 D_8009E678[];
extern u8 D_8009E679[];

void func_80069BB0(s32 *arg0, s32 *arg1) {
    s32 *s1;
    s32 *s0;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 t0 asm("t0");
    register s32 t1 asm("t1");
    register s32 *at asm("at");

    s1 = arg0;
    KEEP_NOVOL(s1);
    s0 = arg1;
    KEEP(s0);
    v1 = s1[0];
    v0 = v1 - 1;
    v0 = (u32) v0 < 0xC;
    if (v0 == 0)
        goto bf8;
    a1 = 0;
    MEMORY_BARRIER();
    v0 = s0[0];
    v0 = v0 - 1;
    v0 = (u32) v0 < 0x1F;
    if (v0 != 0)
        goto c10;
bf8:
    func_80090D30(5);
    v0 = 1;
    s0[0] = v0;
    s1[0] = v0;
    goto end;
c10:
    a3 = (s32) &D_8009E678[0];
    v0 = *(u8 *) a3;
    if (v0 == v1)
        goto c70;
    a2 = v1;
    __asm__ volatile(".set\tnoreorder\n\tlui\t$8,%2\n\tori\t$8,$8,%3\n\taddu\t$4,$5,1\n1:\n\tmult\t$4,$8\n\tsra\t$2,$4,31\n\tmfhi\t$9\n\tsra\t$3,$9,1\n\tsubu\t$5,$3,$2\n\tsll\t$2,$5,1\n\taddu\t$2,$2,$5\n\tsll\t$2,$2,2\n\tsubu\t$5,$4,$2\n\tsll\t$2,$5,1\n\taddu\t$2,$2,%0\n\tlbu\t$2,0($2)\n\tnop\n\tbne\t$2,%1,1b\n\taddu\t$4,$5,1\n\t.set\treorder" : : "r"(a3), "r"(a2), "i"(0x2AAAAAAB >> 16), "i"(0x2AAAAAAB & 0xFFFF) : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "hi", "lo", "memory");
c70:
    a2 = (s32) &D_8009E679[0];
    v0 = a1 * 2;
    a0 = v0 + a2;
    v1 = *(u8 *) a0;
    v0 = s0[0];
    v0 = v0 < v1;
    if (v0 == 0)
        goto d08;
    v0 = 0x2AAAAAAB;
    __asm__ volatile(".set\tnoreorder\n\taddiu\t$3,$5,0xB\n\tmult\t$3,$2\n\tsra\t$2,$3,31\n\tmfhi\t$9\n\tsra\t$4,$9,1\n\tsubu\t$5,$4,$2\n\tsll\t$2,$5,1\n\taddu\t$2,$2,$5\n\tsll\t$2,$2,2\n\tsubu\t$5,$3,$2\n\t.set\treorder" : : "r"(v0) : "$2", "$3", "$4", "$5", "$9", "hi", "lo", "memory");
    v0 = a1 + 1;
    s1[0] = v0;
    v0 = a1 * 2;
    __asm__ volatile("addu\t$3,%0,%1\n\taddu\t$2,%1,%0" : : "r"(a2), "r"(v0) : "$2", "$3");
    v1 = *(u8 *) ((char *) v1 - 1);
    a0 = *(u8 *) v0;
    at = (s32 *) ((char *) &D_8009E66B[0] + v1);
    v0 = *(u8 *) at;
    v1 = s0[0];
    v0 = v0 - a0;
    a0 = v0 + 1;
    v1 = v1 + a0;
    s0[0] = v1;
    goto end;
d08:
    v0 = a1 + 1;
    s1[0] = v0;
    v1 = *(u8 *) a0;
    v0 = s0[0];
    v0 = v0 - v1;
    v0 = v0 + 1;
    s0[0] = v0;
end:
    return;
}

extern s32 D_80096A48;
extern u8 D_80057F34;
extern u8 D_80057F35;

void func_80069D40(void) {
    extern s32 func_800EF1A8(s32);
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 v0;
    u32 v1;

    s3 = D_80096A48;
    a0 = 0x2F;
    v0 = func_800EF1A8(a0);
    s2 = v0;
    a0 = 0x2E;
    v0 = func_800EF1A8(a0);
    s1 = v0;
    a0 = 0x5F;
    v0 = func_800EF1A8(a0);
    s0 = v0;
    a0 = 0x60;
    v0 = func_800EF1A8(a0);
    a2 = 1;
    if (s1 != s0)
        goto loop_init;
    if (s2 != v0)
        goto loop_init;
    a0 = (s32) &D_80057F34;
    v1 = *(u8 *) a0;
    v0 = v1 < 0x63;
    if (v0 == 0)
        goto loop_init;
    v0 = v1 + 1;
    *(u8 *) a0 = v0;
    FORCE_REG(a2);
    a2 = 1;
loop_init:
    a1 = (s32) &D_80057F35;
    a0 = s3 + 2;
loop:
    v0 = *(u8 *) a0;
    if (s1 != v0)
        goto next;
    v0 = *(u8 *) (a0 + 1);
    if (s2 != v0)
        goto next;
    v1 = *(u8 *) a1;
    v0 = v1 < 0x63;
    if (v0 == 0)
        goto next;
    v0 = v1 + 1;
    *(u8 *) a1 = v0;
next:
    a1 += 1;
    MEMORY_BARRIER();
    a2 += 1;
    v0 = a2 < 0x40;
    a0 += 2;
    if (v0 != 0)
        goto loop;
}

extern void func_80059AF0();

u8 *func_80069E38(s32 arg0) {
    func_80059AF0();
}

void func_80069E58(s32 arg0, s32 arg1, void *arg2) {
    extern void func_800920E8(s32, s32, s32);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3") = arg0;
    register u8 *s4 asm("s4") = (u8 *) arg2;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");

    v0 = arg1;
    v0 <<= 3;
    s2 = v0 + arg1;
    s1 = 1;
    s0 = 0;
    do {
        a0 = s3;
        a1 = s2 + s0;
        a2 = *(volatile u8 *) ((char *) s4 + 1);
        s0 += 1;
        a2 &= s1;
        func_800920E8(a0, a1, a2);
        s1 <<= 1;
        v0 = s0 < 5;
    } while (v0);
    s1 = 1;
    s0 = 0;
    do {
        a0 = s3;
        a1 = s0 + 5;
        a1 = s2 + a1;
        a2 = *(volatile u8 *) s4;
        s0 += 1;
        a2 &= s1;
        func_800920E8(a0, a1, a2);
        s1 <<= 1;
        v0 = s0 < 4;
    } while (v0);
}

void func_80069F04(s32 arg0, s32 arg1, void *arg2) {
    extern s32 func_80092148(s32 *, s32);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 s4 asm("s4");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");

    s4 = arg0;
    v0 = arg1 << 3;
    s3 = v0 + arg1;
    s1 = 1;
    s2 = (s32) arg2;
    KEEP_NOVOL(s2);
    s0 = 0;
    *(u8 *) (s2 + 1) = 0;
loop1:
    a0 = s4;
    a1 = s3 + s0;
    v0 = func_80092148((s32 *) a0, a1);
    if (v0 == 0)
        goto next1;
    v0 = *(u8 *) (s2 + 1);
    v0 |= s1;
    *(u8 *) (s2 + 1) = v0;
next1:
    MEMORY_BARRIER();
    s0 += 1;
    v0 = s0 < 5;
    if (v0 != 0) {
        s1 <<= 1;
        goto loop1;
    }
    s1 = 1;
    *(u8 *) s2 = 0;
    s0 = 0;
loop2:
    a0 = s4;
    a1 = s0 + 5;
    a1 = s3 + a1;
    v0 = func_80092148((s32 *) a0, a1);
    if (v0 == 0)
        goto next2;
    v0 = *(u8 *) s2;
    v0 |= s1;
    *(u8 *) s2 = v0;
next2:
    MEMORY_BARRIER();
    s0 += 1;
    v0 = s0 < 4;
    if (v0 != 0) {
        s1 <<= 1;
        goto loop2;
    }
    v0 = *(u8 *) (s2 + 1);
    if ((u32) v0 == 0 || (u32) v0 >= 0x20)
        *(u8 *) (s2 + 1) = 1;
    v0 = *(u8 *) s2;
    if ((u32) v0 == 0 || (u32) v0 >= 0xD)
        *(u8 *) s2 = 1;
}

void func_8006A018(s32 arg0) {
    u16 buf[4];
    s32 *p;
    s32 i;

    func_800246D4(0);
    func_8001DBA8(0);
    buf[2] = 0x100;
    buf[0] = 0;
    buf[1] = 0;
    buf[3] = 0x1E0;
    func_80024868((u8 *) buf, 0, 0, 0);
    if (arg0 != 0) {
        i = 0x77FF;
        p = (s32 *) (D_800C72F4 + 0x1DFFC);
        do {
            *p-- = 0;
            i--;
        } while (i >= 0);
    }
    func_800246D4(0);
}

extern u8 D_8009E66C[];

s32 func_8006A0AC(s32 arg0, s32 arg1) {
    s32 i;
    s32 sum;
    s32 n;
    s32 t;
    volatile s32 vs;

    i = 0;
    n = arg0 - 1;
    sum = 0;
    if (n > 0) {
        do {
            sum += D_8009E66C[i];
            i++;
        } while (i < n);
    }
    t = sum - 1;
    return t + arg1;
}

void func_8006A0F8(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 v1;
    u8 a3;

    v1 = 0;
loop_1:
    a3 = D_8009E66C[v1];
    if (arg0 >= (s32) a3) {
        v1 += 1;
        arg0 -= a3;
        if (v1 < 0xC) {
            goto loop_1;
        }
    }
    *arg1 = v1 + 1;
    *arg2 = arg0 + 1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006A140);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006A58C);

extern s32 D_8009F2E0;
extern s32 D_800C7320[];
extern s32 D_800C7334[];
extern s32 D_800C7328[];
extern s32 D_800C732C[];
extern s32 D_800C7330[];

void func_8006A888(void) {
    extern void func_8001D658(void *, void *);
    extern void func_8001CF48(void *, void *);
    extern void func_8001CF78(void *, void *);
    extern void func_8001D0A8(void *);
    extern void func_8001D138(void *);
    extern void func_8001D578(s16 *, s32 *, void *);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    s32 *p;
    volatile s32 sp10[8];
    s16 fld[3];
    volatile s32 sp38;
    volatile s32 sp3C;
    volatile s32 sp40;
    volatile s32 sp44;
    volatile s32 sp48;

    s0 = (s32) &D_8009F2E0;
    a0 = s0;
    a1 = (s32) &sp10[0];
    func_8001D658((void *) a0, (void *) a1);
    a0 = (s32) &sp10[0];
    a1 = s0 - 0x20;
    func_8001CF48((void *) a0, (void *) a1);
    a0 = (s32) &sp10[0];
    a1 = s0 - 0x10;
    func_8001CF78((void *) a0, (void *) a1);
    a0 = (s32) &sp10[0];
    func_8001D0A8((void *) a0);
    a0 = (s32) &sp10[0];
    func_8001D138((void *) a0);
    s2 = 0;
    s1 = (s32) &D_800C7320[0];
    s0 = 0;
loop:
    a0 = (s32) &fld[0];
    at = (s32 *) ((char *) &D_800C7328[0] + s0);
    v0 = *at;
    a1 = (s32) &sp38;
    fld[0] = v0;
    p = (s32 *) ((char *) &D_800C732C[0] + s0);
    v0 = *p;
    a2 = (s32) &sp48;
    *(volatile s16 *) &fld[2] = 0;
    fld[1] = v0;
    func_8001D578((s16 *) a0, (s32 *) a1, (void *) a2);
    v0 = sp38;
    at = (s32 *) ((char *) &D_800C7330[0] + s0);
    *at = v0;
    v0 = sp3C;
    at = (s32 *) ((char *) &D_800C7334[0] + s0);
    *at = v0;
    v1 = *(s32 *) s1;
    v0 = v1 & 0x200;
    if (v0 == 0) {
        v0 = sp38;
        v0 += 0xA0;
        if ((u32) v0 >= 0x121U) {
            v0 = v1 | 0x100;
        } else {
            v0 = sp3C;
            v0 += 0x98;
            if ((u32) v0 >= 0x111U) {
                v0 = v1 | 0x100;
            } else {
                v0 = ~0x100;
                v0 &= v1;
            }
        }
        *(s32 *) s1 = v0;
    }
    s1 += 0x18;
    s2 += 1;
    v0 = s2 < 0xDD;
    s0 += 0x18;
    if (v0 != 0) {
        goto loop;
    }
}

void func_8006A9D8(void) {
    struct {
        s32 pre[4];
        volatile s32 pad[7];
        struct {
            s32 sp10;
            s8 sp14;
            s8 sp15;
            s8 sp16;
            s16 sp18;
            s16 sp1A;
            s8 sp1C;
            s8 sp1D;
            s16 sp1E;
            s16 sp20;
            s16 sp22;
            s8 sp24;
            s8 sp25;
            s16 sp26;
            s16 sp28;
            s16 sp2A;
            s8 sp2C;
            s8 sp2D;
            s16 sp2E;
            s16 sp30;
            s16 sp32;
            s8 sp34;
            s8 sp35;
            s16 sp36;
            s8 sp38;
            s8 sp39;
            s8 sp3A;
            s8 sp3B;
        } sp;
    } f;

    __asm__ volatile(".set\tnoreorder\n"
                     "\tsw\t$19,0x4C($sp)\n"
                     "\taddu\t$19,$4,$0\n"
                     "\taddiu\t$4,$sp,0x10\n"
                     "\tsw\t$31,0x50($sp)\n"
                     "\tsw\t$18,0x48($sp)\n"
                     "\tsw\t$17,0x44($sp)\n"
                     "\tjal\tfunc_80023D1C\n"
                     "\tsw\t$16,0x40($sp)\n"
                     "\taddiu\t$4,$sp,0x38\n"
                     "\taddu\t$5,$4,$0\n"
                     "\tori\t$2,$0,0x80\n"
                     "\tsb\t$2,0x38($sp)\n"
                     "\tsb\t$2,0x39($sp)\n"
                     "\tjal\tfunc_80069718\n"
                     "\tsb\t$2,0x3A($sp)\n"
                     "\t.set\treorder" : : : "$2", "$4", "$5", "at", "hi", "lo", "memory");
    __asm__ volatile(".set\tnoreorder\n"
                     "\taddu\t$4,$0,$0\n"
                     "\tori\t$5,$0,0x1E0\n"
                     "\tlbu\t$2,0x38($sp)\n"
                     "\tlbu\t$3,0x39($sp)\n"
                     "\tlbu\t$6,0x3A($sp)\n"
                     "\taddu\t$18,$0,$0\n"
                     "\tsb\t$2,0x14($sp)\n"
                     "\tsb\t$3,0x15($sp)\n"
                     "\tjal\tfunc_80023A54\n"
                     "\tsb\t$6,0x16($sp)\n"
                     "\tsh\t$2,0x1E($sp)\n"
                     "\t.set\treorder" : : : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10",
                                             "$11", "$12", "$13", "$14", "$15", "$24", "at", "hi", "lo", "memory");
    __asm__ volatile(".set\tnoreorder\n"
                     "\tsll\t$3,$18,4\n"
                     "1:\n"
                     "\taddu\t$3,$3,$18\n"
                     "\tsll\t$4,$3,1\n"
                     "\taddu\t$4,$4,$3\n"
                     "\tsll\t$4,$4,3\n"
                     "\taddu\t$17,$0,$0\n"
                     "\tlui\t$1,%%hi(D_800C7334)\n"
                     "\taddiu\t$1,$1,%%lo(D_800C7334)\n"
                     "\taddu\t$1,$1,$4\n"
                     "\tlhu\t$2,0($1)\n"
                     "\taddiu\t$3,$3,0x11\n"
                     "\tsh\t$2,0x22($sp)\n"
                     "\tsh\t$2,0x1A($sp)\n"
                     "\tsll\t$2,$3,1\n"
                     "\taddu\t$2,$2,$3\n"
                     "\tsll\t$2,$2,3\n"
                     "\tlui\t$1,%%hi(D_800C7334)\n"
                     "\taddiu\t$1,$1,%%lo(D_800C7334)\n"
                     "\taddu\t$1,$1,$2\n"
                     "\tlhu\t$2,0($1)\n"
                     "\taddiu\t$16,$4,0x18\n"
                     "\tsh\t$2,0x32($sp)\n"
                     "\tsh\t$2,0x2A($sp)\n"
                     "2:\n"
                     "\tlui\t$1,%%hi(D_800C7308)\n"
                     "\taddiu\t$1,$1,%%lo(D_800C7308)\n"
                     "\taddu\t$1,$1,$16\n"
                     "\tlw\t$3,0($1)\n"
                     "\tnop\n"
                     "\tandi\t$2,$3,0x300\n"
                     "\tbnez\t$2,5f\n"
                     "\tandi\t$2,$3,0xFF\n"
                     "\tsh\t$2,0x26($sp)\n"
                     "\tlui\t$1,%%hi(D_800C7318)\n"
                     "\taddiu\t$1,$1,%%lo(D_800C7318)\n"
                     "\taddu\t$1,$1,$16\n"
                     "\tlhu\t$2,0($1)\n"
                     "\tnop\n"
                     "\tsh\t$2,0x28($sp)\n"
                     "\tsh\t$2,0x18($sp)\n"
                     "\tlui\t$1,%%hi(D_800C7330)\n"
                     "\taddiu\t$1,$1,%%lo(D_800C7330)\n"
                     "\taddu\t$1,$1,$16\n"
                     "\tlhu\t$2,0($1)\n"
                     "\tnop\n"
                     "\tsh\t$2,0x30($sp)\n"
                     "\tsh\t$2,0x20($sp)\n"
                     "\tlui\t$1,%%hi(D_800C730C)\n"
                     "\taddiu\t$1,$1,%%lo(D_800C730C)\n"
                     "\taddu\t$1,$1,$16\n"
                     "\tlw\t$3,0($1)\n"
                     "\tnop\n"
                     "\tandi\t$2,$3,0xFF00\n"
                     "\tsrl\t$5,$2,8\n"
                     "\tsrl\t$7,$3,24\n"
                     "\tsrl\t$2,$3,16\n"
                     "\tandi\t$8,$2,0xFF\n"
                     "\taddu\t$2,$7,$5\n"
                     "\tslti\t$2,$2,0x100\n"
                     "\tbnez\t$2,3f\n"
                     "\tandi\t$4,$3,0xFF\n"
                     "\taddiu\t$5,$5,-1\n"
                     "3:\n"
                     "\taddu\t$2,$8,$4\n"
                     "\tslti\t$2,$2,0x100\n"
                     "\tbnez\t$2,4f\n"
                     "\taddu\t$3,$7,$5\n"
                     "\taddiu\t$4,$4,-1\n"
                     "4:\n"
                     "\taddu\t$6,$8,$4\n"
                     "\taddiu\t$4,$sp,0x10\n"
                     "\taddu\t$5,$19,$0\n"
                     "\taddu\t$2,$7,$0\n"
                     "\tsb\t$2,0x2C($sp)\n"
                     "\tsb\t$2,0x1C($sp)\n"
                     "\taddu\t$2,$8,$0\n"
                     "\tsb\t$6,0x35($sp)\n"
                     "\tsb\t$6,0x2D($sp)\n"
                     "\tori\t$6,$0,2\n"
                     "\tsb\t$2,0x25($sp)\n"
                     "\tsb\t$2,0x1D($sp)\n"
                     "\tsb\t$3,0x34($sp)\n"
                     "\tjal\tfunc_800E0228\n"
                     "\tsb\t$3,0x24($sp)\n"
                     "5:\n"
                     "\taddiu\t$17,$17,1\n"
                     "\tslti\t$2,$17,0x10\n"
                     "\tbnez\t$2,2b\n"
                     "\taddiu\t$16,$16,0x18\n"
                     "\taddiu\t$18,$18,1\n"
                     "\tslti\t$2,$18,0xC\n"
                     "\tbnez\t$2,1b\n"
                     "\tsll\t$3,$18,4\n"
                     "\t.set\treorder" : : : "$1", "$2", "$3", "$4",
                                             "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "at",
                                             "hi", "lo", "memory");
    __asm__ volatile(".set\tnoreorder\n"
                     "\tlw\t$31,0x50($sp)\n"
                     "\tlw\t$19,0x4C($sp)\n"
                     "\tlw\t$18,0x48($sp)\n"
                     "\tlw\t$17,0x44($sp)\n"
                     "\tlw\t$16,0x40($sp)\n"
                     "\t.set\treorder" : : : "at", "memory");
    return;
}

extern s32 func_8006AC08();
extern s32 func_8006AC98();

void func_8006ABC8(s32 arg0, s32 arg1) {
    func_8006AC08();
    func_8006AC98(arg0, arg1);
}

s32 func_8006AC08(s32 *arg0, s32 *arg1) {
    s32 delta;
    s32 reference;
    s32 clamped;
    s32 result;
    delta = -*arg0;
    *arg0 = delta;
    if (delta < 0) {
        reference = *arg1;
        clamped = reference + delta;
        if (clamped < -0x74)
            clamped = -0x74;
        result = delta - (clamped - reference);
        *arg0 = result;
        *arg1 = clamped;
    }
    delta = *arg0;
    if (delta > 0) {
        reference = *arg1;
        clamped = reference + delta;
        if (clamped >= 0x81)
            clamped = 0x80;
        result = delta - (clamped - reference);
        *arg0 = result;
        *arg1 = clamped;
    }
    result = -*arg0;
    *arg0 = result;
    return result;
}

s32 func_8006AC98(s32 *arg0, s32 *arg1) {
    s32 delta;
    s32 reference;
    s32 clamped;
    s32 result;
    delta = -arg0[1];
    arg0[1] = delta;
    if (delta < 0) {
        reference = arg1[1];
        clamped = reference + delta;
        if (clamped < -0x40)
            clamped = -0x40;
        result = delta - (clamped - reference);
        arg0[1] = result;
        arg1[1] = clamped;
    }
    delta = arg0[1];
    if (delta > 0) {
        reference = arg1[1];
        clamped = reference + delta;
        if (clamped >= 0x51)
            clamped = 0x50;
        result = delta - (clamped - reference);
        arg0[1] = result;
        arg1[1] = clamped;
    }
    result = -arg0[1];
    arg0[1] = result;
    return result;
}

extern s32 D_8009F180;
extern s32 D_8009F244;
extern s32 D_800BB50C[];
extern s32 D_800BB524[];
extern s32 D_800BBC78[];
extern s32 D_800BBC90[];

void func_8006AD28(void) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 t0 asm("t0");
    register s32 t1 asm("t1");
    register s32 t2 asm("t2");
    register s32 t3 asm("t3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    a2 = 0;
    a3 = 1;
    a1 = 0x80;
    v1 = (s32) &D_800BB524[0];
    a0 = 0;
    D_8009F244 = 0;
    D_8009F180 = 0;
    D_8009F198 = 0;
    D_8009F1E8 = 0;
    do {
        *(s32 *) ((char *) &D_800BB504[0] + a0) = a3;
        (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + a0)).f08 = a3;
        *(u8 *) v1 = a1;
        *(u8 *) (v1 + 1) = a1;
        *(u8 *) (v1 + 2) = a1;
        v1 += 0x24;
        a2 += 1;
        v0 = a2 < 0x20;
        a0 += 0x24;
    } while (v0);
    a2 = 0;
    t3 = 2;
    t2 = 1;
    t1 = 0x3C0;
    t0 = 0x1F0;
    a3 = 0x80;
    v0 = (s32) &D_800BBC90[0];
    v1 = v0 + 0x10;
    a1 = v0;
    a0 = 0;
    do {
        *(s32 *) ((char *) &D_800BBC70[0] + a0) = t3;
        *(s32 *) ((char *) &D_800BBC78[0] + a0) = t2;
        *(s32 *) a1 = t1;
        *(s32 *) (a1 + 4) = t0;
        *(u8 *) v1 = a3;
        *(u8 *) (v1 + 1) = a3;
        *(u8 *) (v1 + 2) = a3;
        v1 += 0x34;
        a1 += 0x34;
        a2 += 1;
        v0 = a2 < 0x20;
        a0 += 0x34;
    } while (v0);
}

void func_8006AE20(s32 arg0, s32 **arg1, s32 arg2) {
    extern void func_8006AED0(s32 *, s32);
    extern void func_8006B26C(s32 *, s32);
    s32 v0;
    s32 v1;
    register s32 s0 asm("s0");
    register s32 **s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 *a0 asm("a0");
    register s32 a1 asm("a1");
    s32 pad[2];

    v0 = D_8004D950;
    s2 = arg0;
    s3 = arg2;
    v0 &= 0x400;
    if (v0 != 0)
        goto epi;
    if (s3 <= 0)
        goto epi;
    s0 = 0;
    s1 = arg1;
loop:
    a0 = *s1;
    v1 = *a0;
    v0 = v1 & 0x18;
    if (v0 == 0) {
        v0 = v1 & 1;
        if (v0 != 0) {
            a1 = s2;
            func_8006AED0(a0, a1);
            s0 += 1;
            goto tst;
        }
        v0 = v1 & 2;
        if (v0 != 0) {
            a1 = s2;
            func_8006B26C(a0, a1);
        }
    }
cnt:
    s0 += 1;
tst:
    v0 = s0 < s3;
    if (v0 != 0) {
        s1 = (s32 **) ((char *) s1 + 4);
        goto loop;
    }
epi:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006AED0);

void func_8006B26C(s32 *arg0, s32 *arg1) {
    typedef struct {
        s32 f00;
        u16 f04;
        u16 f06;
        u16 f08;
        u16 f0A;
        u16 f0C;
        u8 f0E;
        u8 f0F;
        u16 f10;
        u16 f12;
        u8 f14;
        u8 f15;
        u8 f16;
        u8 f17;
        u8 f18[0x10];
        u16 f28;
        u16 f2A;
        u16 f2C;
        u16 f2E;
    } T;
    typedef struct {
        u8 c0;
        u8 c1;
        u8 c2;
        u8 c3;
    } T4b;
    extern void func_80069718(u8 *, u8 *, s32);
    extern void func_800E097C(void *, s32, u16);
    T st;
    T4b buf;
    s32 *s0;
    s32 *s1;
    s32 v6;
    s32 v7;
    s32 w;
    register void *spf asm("sp");

    s32 u;
    s32 q;
    s32 p;
    s0 = arg0;
    s1 = arg1;
    if (s0[0] & 4) {
        st.f00 = 0x1000000;
    } else {
        st.f00 = 0;
    }
    st.f10 = *(volatile s32 *) &s0[8];
    st.f12 = *(volatile s32 *) &s0[9];
    if (s0[5] != 0) {
        st.f10 = *(volatile s32 *) &s0[8] + (s0[5] - 1) * 16;
    }
    if (s0[0] & 0x400) {
        buf = *(T4b *) &s0[12];
    } else {
        register s32 a0 asm("a0");

        ((void (*)(u8 *, u8 *)) func_80069718)((u8 *) &s0[12], (u8 *) ((char *) spf + 0x40));
    }
    st.f14 = buf.c0;
    st.f15 = buf.c1;
    st.f16 = buf.c2;
    st.f0C = *(volatile s32 *) &s0[1];
    if (s0[0] & 0x100) {
        func_8006B678(s0[4] / 2, (void *) &s0[10], (void *) &st.f28);
        v6 = *(volatile s32 *) &s0[6];
        MEMORY_BARRIER();
        p = st.f28;
        q = st.f2A;
        st.f04 = p + v6;
        v7 = *(volatile s32 *) &s0[7];
        st.f06 = q + v7;
        MEMORY_BARRIER();
        st.f0E = p + ((u8 *) s0)[0x28];
        w = q + ((u8 *) s0)[0x2A];
        st.f08 = st.f2C;
        st.f0A = st.f2E;
        st.f0F = w;
        if (s0[4] / 2 >= 4) {
            s0[4] = 0;
            s0[0] ^= 0x100;
            goto L438;
        }
        s0[4] = s0[4] + 1;
    } else {
        st.f04 = *(volatile s32 *) &s0[6];
        st.f06 = *(volatile s32 *) &s0[7];
        u = ((u16 *) s0)[20];
        st.f0E = u;
        u = ((u16 *) s0)[21];
        st.f0F = u;
        st.f08 = ((u16 *) s0)[22];
        st.f0A = ((u16 *) s0)[23];
    }
L438:
    func_800E097C((void *) &st, s1, (u16) s0[2]);
}

s32 func_8006B460() {
    register s32 a0 asm("a0");
    register s32 *a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register volatile s32 *at asm("at");

    a3 = (s32) &D_800BB504[0];
    a2 = *a1;
    v0 = D_8009F180;
    a2 <<= 2;
    __asm__ volatile("addu $6, $6, $4");
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    v0 = v1 + a3;
    a0 = -0x419;
    USE(a0);
    *(volatile s32 *) a2 = v0;
    __asm__ volatile("la %0, D_800BB504" : "=r"(at));
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    MEMORY_BARRIER();
    a3 += 0x20;
    at = (s32 *) &D_800BB518[0];
    __asm__ volatile("addu $1, $1, $3");
    *at = 0;
    __asm__ volatile("and $2, $2, $4");
    __asm__ volatile("la %0, D_800BB504" : "=r"(at));
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    __asm__ volatile("addu $3, $3, $7");
    a0 = 0x80;
    USE(a0);
    *(u8 *) v1 = a0;
    v1 = D_8009F180;
    v0 = v1 << 3;
    v0 += v1;
    v0 <<= 2;
    v0 += a3;
    *(u8 *) (v0 + 1) = a0;
    v1 = D_8009F180;
    v0 = v1 << 3;
    v0 += v1;
    v0 <<= 2;
    v0 += a3;
    *(u8 *) (v0 + 2) = a0;
    v0 = *a1;
    v0 += 1;
    *a1 = v0;
    v0 = D_8009F180;
    v1 = v0 + 1;
    D_8009F180 = v1;
}

extern s32 D_800BBC80[];

s32 func_8006B548() {
    register s32 a0 asm("a0");
    register s32 *a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register volatile s32 *at asm("at");

    a3 = (s32) &D_800BBC70[0];
    a2 = *a1;
    v1 = D_8009F244;
    a2 <<= 2;
    __asm__ volatile("addu $6, $6, $4");
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = v0 + a3;
    a0 = -0x419;
    USE(a0);
    *(volatile s32 *) a2 = v1;
    __asm__ volatile("la %0, D_800BBC70" : "=r"(at));
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    MEMORY_BARRIER();
    a3 += 0x30;
    __asm__ volatile("and $3, $3, $4");
    __asm__ volatile("la %0, D_800BBC70" : "=r"(at));
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    __asm__ volatile("addu $2, $2, $7");
    a0 = 0x80;
    USE(a0);
    *(u8 *) v0 = a0;
    v1 = D_8009F244;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v0 += a3;
    *(u8 *) (v0 + 1) = a0;
    v1 = D_8009F244;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v0 += a3;
    *(u8 *) (v0 + 2) = a0;
    v1 = D_8009F244;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    __asm__ volatile("la %0, D_800BBC84" : "=r"(at));
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    __asm__ volatile("la %0, D_800BBC80" : "=r"(at));
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    v0 = *a1;
    v0 += 1;
    *a1 = v0;
    v0 = D_8009F244;
    v1 = v0 + 1;
    D_8009F244 = v1;
}

void func_8006B678(s32 arg0, void *arg1, void *arg2) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 t0 asm("t0");
    register s32 t1 asm("t1");
    register s32 t2 asm("t2");
    register s32 t3 asm("t3");

    a0 = arg0;
    a3 = (s32) arg1;
    t3 = (s32) arg2;
    v0 = 1;
    if (a0 == v0)
        goto b678_case_two;
    v0 = a0 < 2;
    if (v0 == 0)
        goto b678_other;
    v0 = 0x14;
    if (a0 == 0)
        goto b678_join;
    v0 = 0x64;
    goto b678_join;
b678_other:
    v0 = 2;
    if (a0 == v0)
        goto b678_case_one;
    v0 = 3;
    __asm__ volatile(".set\tnoreorder\n\tbeq\t%0,%1,1f\n\tori\t%2,$zero,0x5A\n\t.set\treorder" : : "r"(a0), "r"(v0), "r"(v0) : "memory");
    v0 = 0x64;
    goto b678_join;
b678_case_two:
    v0 = 0x32;
    goto b678_join;
b678_case_one:
    v0 = 0x50;
b678_join:
    __asm__ volatile("1:" ::: "memory");
    a1 = *(volatile u16 *) ((char *) a3 + 4);
    a1 <<= 16;
    a2 = a1 >> 16;
    __asm__ volatile("mult %0,%1" : : "r"(a2), "r"(v0));
    a3 = *(volatile u16 *) ((char *) a3 + 6);
    __asm__ volatile("mflo %0" : "=r"(v1));
    a3 <<= 16;
    t0 = a3 >> 16;
    __asm__ volatile("mult %0,%1" : : "r"(t0), "r"(v0));
    __asm__ volatile("mflo %0" : "=r"(a0));
    v0 = 0x51EB851F;
    __asm__ volatile("mult %0,%1" : : "r"(v1), "r"(v0));
    __asm__ volatile("mfhi %0" : "=r"(t1));
    a1 = (u32) a1 >> 31;
    a2 += a1;
    __asm__ volatile("mult %0,%1" : : "r"(a0), "r"(v0));
    a2 >>= 1;
    a2 &= 0xFFFC;
    a3 = (u32) a3 >> 31;
    t0 += a3;
    t0 >>= 1;
    v1 >>= 31;
    v0 = t1 >> 6;
    v0 -= v1;
    t1 = v0 & 0xFFFC;
    a0 >>= 31;
    __asm__ volatile("mfhi %0" : "=r"(t2));
    v0 = t2 >> 6;
    v0 -= a0;
    v1 = v0 & 0xFFFC;
    t0 &= 0xFFFC;
    if (a2 < t1) {
        t1 = a2;
    }
    if (t0 < v1) {
        v1 = t0;
    }
    v0 = a2 - t1;
    *(volatile s16 *) ((char *) t3 + 0) = (s16) v0;
    v0 = t0 - v1;
    *(volatile s16 *) ((char *) t3 + 2) = (s16) v0;
    v0 = t1 << 1;
    *(volatile s16 *) ((char *) t3 + 4) = (s16) v0;
    v0 = v1 << 1;
    *(s16 *) ((char *) t3 + 6) = (s16) v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006B78C);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006B794);

extern s32 D_800D09AC;

void func_8006BAD4(s32 arg0, void *arg1, void *arg2) {
    extern void func_800E097C(void *, s32, u16);
    extern void func_800E0D5C(void *, s32, u16);
    extern void func_8006BD84(s32, s32, void *, void *, s32);
    extern u16 D_800BB4F4;
    register s32 s1 asm("s1") = arg0;
    register void *s0 asm("s0") = arg1;
    register void *s2 asm("s2") = arg2;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    KEEP_NOVOL(s1);
    KEEP_NOVOL(s0);
    KEEP_NOVOL(s2);
    a0 = s0;
    a1 = s1;
    v0 = 0x9C;
    *(u8 *) (s0 + 0xE) = (u8) v0;
    v0 = 0x78;
    *(u8 *) (s0 + 0xF) = (u8) v0;
    a2 = D_800BB4F4;
    v0 = 0x29;
    *(u16 *) (s0 + 8) = (u16) v0;
    *(u16 *) (s0 + 0xA) = 8;
    *(u16 *) (s0 + 0x10) = 0x20;
    func_800E097C((void *) s0, s1, (u16) a2);
    a0 = s2;
    *(s32 *) s2 = 0;
    *(u8 *) (s2 + 0xC) = 0;
    *(u8 *) (s2 + 0xD) = 0;
    *(u8 *) (s2 + 0xE) = 0;
    v0 = *(u16 *) (s0 + 4);
    v1 = v0 + 0x24;
    v0 = v0 + 0x28;
    *(u16 *) (s2 + 4) = (u16) v1;
    *(u16 *) (s2 + 8) = (u16) v0;
    v0 = *(u16 *) (s0 + 6);
    a2 = D_800BB4F4;
    v0 += 8;
    *(u16 *) (s2 + 0xA) = (u16) v0;
    *(u16 *) (s2 + 6) = (u16) v0;
    a1 = s1;
    func_800E0D5C((void *) a0, a1, (u16) a2);
    a1 = 8;
    a2 = s0;
    KEEP(a2);
    a3 = s1;
    KEEP(a3);
    a0 = D_800D09AC;
    v0 = *(u16 *) (a2 + 4);
    v0 += 4;
    v1 = *(u16 *) (a2 + 6);
    v1 += 8;
    *(u16 *) (a2 + 4) = (u16) v0;
    *(u16 *) (a2 + 6) = (u16) v1;
    func_8006BD84(a0, a1, (void *) a2, (void *) a3, 0);
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006BBC8);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006BD84);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006BF9C);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006BFA4);

extern s32 D_8009EEF4;
extern s32 D_800D0BB4;

void func_8006C108(s32 arg0) {
    extern void func_80069718(u8 *, u8 *, s32);
    extern void func_8006AED0(s32 *, s32, u8, u8);
    extern volatile s32 D_800D0BB4_v __asm__("D_800D0BB4");
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[12];
    v0 = D_8004D950;

    s0 = arg0;
    v0 &= 0x2000;
    if (v0 != 0)
        goto end;
    v1 = D_800D0BB4;
    if (v1 == 0)
        goto end;
    a0 = (s32) sp + 0x38;
    KEEP_NOVOL(a0);
    v0 = 1;
    v1 -= 1;
    *(volatile s32 *) ((char *) sp + 0x10) = v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = *(volatile s32 *) ((char *) &D_800D3CD0[0] + v0);
    KEEP_NOVOL(v1);
    a1 = a0;
    *(volatile s32 *) ((char *) sp + 0x28) = v1;
    a2 = *(volatile s32 *) ((char *) &D_800D3CD4[0] + v0);
    KEEP_NOVOL(a2);
    v1 = D_8009EEF4;
    KEEP_NOVOL(v1);
    v0 = 4;
    *(volatile s32 *) ((char *) sp + 0x18) = v0;
    *(volatile s32 *) ((char *) sp + 0x24) = 0;
    *(volatile s32 *) ((char *) sp + 0x20) = 0;
    *(volatile s32 *) ((char *) sp + 0x1C) = 0;
    *(volatile u8 *) ((char *) sp + 0x38) = v1;
    *(volatile u8 *) ((char *) sp + 0x39) = v1;
    *(volatile u8 *) ((char *) sp + 0x3A) = v1;
    *(s32 *) ((char *) sp + 0x2C) = a2;
    func_80069718((u8 *) a0, (u8 *) a1, a2);
    a0 = (s32) sp + 16;
    a1 = s0;
    v1 = *(volatile u8 *) ((char *) sp + 0x38);
    a2 = *(volatile u8 *) ((char *) sp + 0x39);
    __asm__ volatile("" : : "r"(a2) : "memory");
    v0 = D_800D0BB4_v;
    a3 = *(volatile u8 *) ((char *) sp + 0x3A);
    v0 += 0x36;
    __asm__ volatile("" : : "r"(v0) : "memory");
    *(volatile u8 *) ((char *) sp + 0x30) = v1;
    *(volatile u8 *) ((char *) sp + 0x31) = a2;
    *(volatile u8 *) ((char *) sp + 0x32) = a3;
    *(s32 *) ((char *) sp + 0x14) = v0;
    func_8006AED0((s32 *) a0, a1, a2, a3);
end:
    return;
}

extern void func_8009DE1C();
extern void func_8010647C();
extern void func_80108920();

void func_8006C1FC(void) {
    s32 temp_v0;

    func_8010647C();
    func_80108920();
    temp_v0 = func_800EF1A8(0x54);
    if (temp_v0 != 0) {
        func_8009DE1C(temp_v0);
        func_800EF25C(0x54, 0);
    }
}

extern s32 D_8009F27C;
extern s32 D_8009F280;
extern void func_800E28AC();
extern s32 D_800BB3EC;
extern s32 D_80153298;
extern s32 D_801CD814;

void func_8006C248(s32 *arg0) {
    extern void func_80108A08(s32);
    extern void func_80107E00(s32);
    extern void func_80107E10(s32, s32);
    extern void func_801128E0(s32, s32, s32);
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    v0 = D_8004D950;

    s0 = arg0;
    v0 &= 0x80;
    if (v0 != 0)
        goto end;
    a0 = s0[1];
    a0 += 0x3C;
    func_80108A08(a0);
    a0 = ~D_800BB3C0;
    func_80107E00(a0);
    v0 = D_8004D950;
    v1 = 0x20000;
    v0 &= v1;
    if (v0 != 0) {
        v0 = D_800BB3EC;
        v1 = s0[1];
        v0 <<= 2;
        v1 += v0;
        at = (s32 *) &D_801CD814;
        *at = v1;
        func_800E28AC();
        a1 = D_8009F2E8;
        v0 = D_800BB3EC;
        a0 = s0[1];
        v0 <<= 2;
        a0 += v0;
        v0 = D_8004E5BC;
        a0 += 8;
        a2 = v0 << 4;
        a2 -= v0;
        a2 <<= 4;
        func_801128E0(a0, a1, a2);
        a0 = D_80153298;
        v0 = -1;
        if (a0 != v0)
            func_80090D30(a0);
    } else {
        a1 = D_8009F2E8;
        a0 = D_800BB3EC;
        v0 = s0[1];
        a0 <<= 2;
        a0 = v0 + a0;
        func_80107E10(a0, a1);
    }
end:
    return;
}

extern s32 D_800BB98C[];
extern s32 D_800BB51C[];
extern s32 D_800BB520[];
extern void func_8006C52C();

void func_8006C350(void) {
    volatile s32 *p = (volatile s32 *) &D_800BB98C;
    s32 i1;
    s32 i2;

    D_800BB4F0 = 0;
    func_8006C52C();
    i1 = *p;
    D_800BB51C[i1 * 9] = D_8009F27C;
    i2 = *p;
    D_800BB520[i2 * 9] = D_8009F280 - 4;
}

extern s32 D_800D4580[];
extern s32 D_8009E690[];

void func_8006C3DC(void) {
    extern s32 D_800BB930;
    s32 a0;
    s32 v0;
    s32 v1;
    s32 *at;

    v1 = D_800BB4F0;
    v0 = v1 << 2;
    a0 = v1 << 1;
    a0 += v1;
    a0 <<= 3;
    a0 -= v1;
    a0 <<= 2;
    MEMORY_BARRIER();
    at = (s32 *) ((char *) &D_800D4580[0] + v0);
    v0 = *at;
    v1 = (s32) &D_800BB930;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_8009E690[0] + v0);
    v0 = *at;
    ((void (*)(s32)) v0)(a0 + v1);
}

extern s32 D_8009E774[];

void func_8006C44C() {
    extern s32 D_800BB930;
    s32 a0;
    s32 v0;
    s32 v1;
    s32 *at;
    v1 = D_800BB4F0;
    v0 = v1 << 2;
    a0 = v1 << 1;
    a0 += v1;
    a0 <<= 3;
    a0 -= v1;
    a0 <<= 2;
    MEMORY_BARRIER();
    at = (s32 *) ((char *) &D_800D4580[0] + v0);
    v0 = *at;
    v1 = (s32) &D_800BB930;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_8009E774[0] + v0);
    v0 = *at;
    ((void (*)(s32)) v0)(a0 + v1);
}

extern s32 D_8009E858[];

void func_8006C4BC() {
    extern s32 D_800BB930;
    s32 a0;
    s32 v0;
    s32 v1;
    s32 *at;
    v1 = D_800BB4F0;
    v0 = v1 << 2;
    a0 = v1 << 1;
    a0 += v1;
    a0 <<= 3;
    a0 -= v1;
    a0 <<= 2;
    at = (s32 *) ((char *) &D_800D4580[0] + v0);
    v0 = *at;
    v1 = (s32) &D_800BB930;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_8009E858[0] + v0);
    v0 = *at;
    ((void (*)(s32)) v0)(a0 + v1);
}

extern s32 D_8009F188;
extern s32 D_8009EF70;
extern s32 D_8009F184;
extern s32 D_8009EF6C;
extern s32 D_8009F194;
extern s32 D_8009EF7C;
extern s32 D_8009F190;
extern s32 D_8009EF78;
extern s32 D_8009F18C;
extern s32 D_8009EF74;
extern s32 D_800BB99C;
extern s32 D_800D0984;
extern s32 func_8006B460();

void func_8006C52C(void) {
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB998;
    extern s32 func_800EF1A8();
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 *s0 asm("s0");
    register s32 *s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    s0 = (s32 *) &D_8009EF80;
    a0 = (s32) s0;
    USE_NOVOL(a0);
    s1 = (s32 *) &D_8009F198;
    s2 = 0xC;
    v0 = func_8006B460((s32 *) &D_8009EF80, (s32 *) &D_8009F198);
    a2 = v0;
    a0 = (s32) s0;
    a1 = (s32) s1;
    s2 = 0xC;
    USE_NOVOL(s2);
    s0 = &D_800BB51C[0];
    v1 = D_800BB4F0;
    s1 = (s32 *) ((char *) s0 - 0x18);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = a2;
    v0 = a2 << 3;
    v0 += a2;
    v0 <<= 2;
    v1 = (s32) s0 + v0;
    KEEP(v1);
    at = (s32 *) ((char *) &D_800BB508 + v0);
    *at = 0;
    at = (s32 *) ((char *) &D_800BB50C + v0);
    *at = s2;
    *(s32 *) v1 = 0;
    *(s32 *) (v1 + 4) = 0;
    v1 = (s32) ((char *) s1 + v0);
    *(s32 *) (v1 + 0x10) = 0;
    at = (s32 *) ((char *) &D_800BB510 + v0);
    *at = 0;
    v0 = func_8006B460(a0, a1, a2);
    a2 = v0;
    v1 = D_800BB4F0;
    v0 = 1;
    D_800D0984 = v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB990 + v0);
    *at = a2;
    v0 = a2 << 3;
    v0 += a2;
    v0 <<= 2;
    v1 = 0xD;
    s0 = (s32 *) ((char *) s0 + v0);
    KEEP(s0);
    a1 = *(s32 *) ((char *) &D_800BB504 + v0);
    USE(a1);
    s1 = (s32 *) ((char *) s1 + v0);
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f04 = v1;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f08 = s2;
    __asm__ volatile("" : : "m"(*(s32 *) ((char *) &D_800BB50C + v0)));
    a1 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v0) = a1;
    *(s32 *) s0 = 0;
    *(s32 *) ((char *) s0 + 4) = 0;
    *(s32 *) ((char *) s1 + 0x10) = 0;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f0C = 0;
    v0 = 0x400;
    D_8009F188 = v0;
    D_8009EF70 = v0;
    v0 = 0x80;
    D_8009F184 = 0;
    D_8009EF6C = 0;
    D_8009F194 = 0;
    D_8009EF7C = 0;
    D_8009F190 = v0;
    D_8009EF78 = v0;
    D_8009F18C = v0;
    D_8009EF74 = v0;
    a0 = 0x2C;
    v0 = ((s32 (*)(s32, s32, s32)) func_800EF1A8)(a0, a1, a2);
    D_800D09AC = v0;
    a0 = D_800BB4F0;
    v1 = a0 << 1;
    v1 += a0;
    v1 <<= 3;
    v1 -= a0;
    v1 <<= 2;
    v0 = a0 + 1;
    at = (s32 *) ((char *) &D_800BB994 + v1);
    *at = 0;
    a1 = D_8009F254;
    a0 <<= 2;
    at = (s32 *) ((char *) &D_800BB99C + v1);
    *at = 0;
    D_800BB4F0 = v0;
    a1 += 1;
    KEEP(a1);
    at = (s32 *) ((char *) &D_800BB998 + v1);
    *at = a1;
    at = (s32 *) ((char *) &D_800D4584 + a0);
    *at = 0;
}

extern s32 D_800D4878;

void func_8006C7AC(s32 *arg0) {
    extern s32 func_800EF1A8(s32);
    extern void func_8006A140(s32);
    extern void func_8006C894();
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 *at asm("at");

    v1 = arg0[0];
    USE(v1);
    v0 = 1;
    D_800D0984 = v0;
    v0 = v1 << 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB518 + v0);
    *at = 0;
    v0 = func_800EF1A8(0x2C);
    a0 = D_800D4878;
    v1 = a0 << 3;
    v1 += a0;
    v1 <<= 2;
    at = (s32 *) ((char *) &D_800BB504 + v1);
    v1 = *at;
    D_800D09AC = v0;
    v1 &= 0x10;
    if (v1 != 0) {
        a0 = 0;
        func_8006A140(a0);
    }
    func_8006C894();
}

void func_8006C844(s32 *arg0) {
    s32 i = *arg0;

    D_800BB518[i * 9] = 0xA;
    MEMORY_BARRIER();
    D_8009F184 = 0;
    D_8009EF6C = 0;
    D_8009F194 = 0;
    D_8009EF7C = 0;
}

extern s32 D_800D4644;
extern s32 D_800D4668;

void func_8006C894(void) {
    extern s32 func_80091238(s32, s32);
    extern void func_8006D7F4(s32);
    extern void func_8006DA88(s32, s32, s32);
    extern void func_8006DE50(s32, s32);
    extern s32 D_800BB930[];
    register s32 *s0 asm("s0");
    register s32 *s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    s1 = &D_8009F254;
    KEEP_NOVOL(s1);
    a0 = s1[0];
    a1 = 0xF80;
    v0 = func_80091238(a0, a1);
    if (v0 == 0)
        goto end;
    s0 = &D_800D4644;
    v1 = s0[0];
    v0 = v1 & 0x180;
    if (v0 == 0) {
        v0 = v1 & 0xC00;
        goto second;
    }
    v0 = v1 & 0xC00;
    v0 = D_800BB4F0;
    a0 = v0;
    a0 <<= 1;
    a0 += v0;
    a0 <<= 3;
    a0 -= v0;
    a0 <<= 2;
    v0 = (s32) &D_800BB930[0];
    a0 += v0;
    func_8006C844((s32 *) a0);
    a0 = (s32) &D_800D4664;
    a0 = *(s32 *) a0;
    a1 = (s32) &D_800D4668;
    a1 = *(s32 *) a1;
    a2 = s0[0] & 0x100;
    a2 = a2 != 0;
    func_8006DA88(a0, a1, a2);
    goto end;
second:
    if (v0 == 0) {
        v0 = v1 & 0x200;
        goto third;
    }
    v0 = D_800BB4F0;
    KEEP_NOVOL(v0);
    a0 = v0;
    a0 <<= 1;
    a0 += v0;
    a0 <<= 3;
    a0 -= v0;
    a0 <<= 2;
    v0 = (s32) &D_800BB930[0];
    a0 += v0;
    func_8006C844((s32 *) a0);
    a0 = (s32) &D_800D4664;
    a0 = *(s32 *) a0;
    a1 = s0[0] & 0x800;
    a1 = a1 != 0;
    func_8006DE50(a0, a1);
    goto end;
third:
    if (v0 == 0)
        goto end;
    v0 = D_800BB4F0;
    KEEP_NOVOL(v0);
    a0 = v0;
    a0 <<= 1;
    a0 += v0;
    a0 <<= 3;
    a0 -= v0;
    a0 <<= 2;
    v0 = (s32) &D_800BB930[0];
    a0 += v0;
    func_8006C844((s32 *) a0);
    a0 = (s32) &D_800D4664;
    a0 = *(s32 *) a0;
    v0 = 0xFF;
    if (a0 == v0)
        a0 = s1[0];
    func_8006D7F4(a0);
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006C9FC);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore", func_8006CA04);

extern s32 D_800D0AF8;

void func_8006D7F4(s32 arg0) {
    extern void func_8008EC38(void *, void *);
    s32 a0;
    s32 a1;
    s32 v0;
    s32 v1;

    a1 = arg0;
    a1 <<= 1;
    a1 += arg0;
    a1 <<= 2;
    a1 += arg0;
    v1 = D_800BB4F0;
    a1 <<= 2;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    *(s32 *) ((char *) &D_800BB98C + v0) = arg0;
    v0 = (s32) D_800D3CB8;
    a0 = a1 + v0;
    v0 -= 8;
    a0 += 0x18;
    a1 += v0;
    func_8008EC38((void *) a0, (void *) a1);
    v0 = D_800D0AF8;
    v0 &= 1;
    if (v0 == 0)
        goto end;
    v1 = D_800BB4F0;
    v1 -= 1;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    v0 = *(s32 *) ((char *) &D_800BB98C + v0);
    a0 = v0 << 3;
    a0 += v0;
    a0 <<= 2;
    v0 = D_8004D950;
    v1 = *(s32 *) ((char *) D_800BB504 + a0);
    v0 |= 0x2000;
    v1 |= 0x10;
    D_8004D950 = v0;
    *(s32 *) ((char *) D_800BB504 + a0) = v1;
end:
    v0 = D_800BB4F0;
    v1 = 0x32;
    a0 = v0 << 2;
    v0 += 1;
    *(s32 *) ((char *) D_800D4584 + a0) = v1;
    D_800BB4F0 = v0;
}

extern s32 D_8009F24C;

void func_8006D928(s32 *arg0) {
    extern void func_8008EE10(s32 *);
    s32 a0;
    s32 a1;
    s32 a2;
    s32 v0;
    s32 v1;
    s32 *at;

    v0 = D_800D0AF8;
    a2 = (s32) arg0;
    v0 &= 1;
    if (v0 == 0)
        goto normal;
    func_8008EE10(arg0);
    v0 = (s32) &D_8009F24C;
    v1 = *(s32 *) v0;
    a0 = D_8004D950;
    v1 |= 1;
    a0 |= 2;
    *(s32 *) v0 = v1;
    D_8004D950 = a0;
    return;
normal:
    v1 = D_800BB4F0;
    v0 = v1 - 2;
    a0 = v0 << 1;
    a0 += v0;
    a0 <<= 3;
    a0 -= v0;
    a0 <<= 2;
    v0 = *(volatile s32 *) ((char *) &D_800BB98C + a0);
    v1 -= 1;
    D_800BB4F0 = v1;
    v1 = *arg0;
    a1 = v0 << 3;
    a1 += v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    a1 <<= 2;
    v0 = *(s32 *) ((char *) &D_800D3CD0[0] + v0);
    v1 = -0x2001;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + a1)).f18 = v0;
    v0 = D_8004D950;
    a1 = *(volatile s32 *) ((char *) &D_800BB98C + a0);
    v0 &= v1;
    a0 = a1 << 3;
    v1 = *arg0;
    a0 += a1;
    D_8004D950 = v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v0 = *(s32 *) ((char *) &D_800D3CD4[0] + v0);
    a0 <<= 2;
    v0 -= 4;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + a0)).f1C = v0;
    func_8006C44C(a0, a1, arg0);
}

extern void func_8008D9A0();

void func_8006DA88(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_800BB990[];
    extern s32 D_800BB994[];
    extern s32 D_800BB998[];
    s32 s0;
    s32 s1;
    s32 s2;
    s32 a0;
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    s0 = arg0;
    s1 = arg1;
    s2 = arg2;
    func_8008D9A0();
    a0 = 1;
    a1 = D_800BB4F0;
    v1 = D_8004D950;
    v0 = a1 << 1;
    v0 += a1;
    v0 <<= 3;
    v0 -= a1;
    v0 <<= 2;
    v1 |= 0x2000;
    D_8004D950 = v1;
    v1 = a1 - 1;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = s0;
    at = (s32 *) ((char *) D_800BB990 + v0);
    *at = s1;
    at = (s32 *) ((char *) D_800BB994 + v0);
    *at = s2;
    at = (s32 *) ((char *) D_800BB998 + v0);
    *at = a0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    a0 = a1 << 2;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    v1 = *at;
    v0 = 0x35;
    at = (s32 *) ((char *) D_800D4584 + a0);
    *at = v0;
    v0 = v1 << 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    a1 += 1;
    D_800BB4F0 = a1;
    v1 |= 0x10;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
}

extern u16 D_800D3BBC;
extern s16 D_800D3BBE;
extern u16 D_800D3BC0;
extern s16 D_800D3BC2;
extern u16 D_800D3BE4;

void func_8006DBB8(void *arg0) {
    extern void func_800EF25C(s32, s32);
    extern volatile s32 D_8004D950_v __asm__("D_8004D950");
    extern volatile u16 D_800D3BC2_u __asm__("D_800D3BC2");
    register s32 s0 asm("s0");
    register s32 s1 asm("s1") = (s32) arg0;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 at asm("at");
    s32 pad[2];

    KEEP_NOVOL(s1);
    v0 = *(volatile s32 *) (s1 + 0xC);
    if (v0 != 0) {
        v0 = D_8004D950_v;
        v0 &= 8;
        if (v0 != 0)
            goto end;
        v0 = *(volatile s32 *) (s1 + 8);
        a1 = 0;
        if (v0 != 0) {
            s0 = (s32) &D_800D3BBE;
            a0 = *(s16 *) ((u8 *) s0 + 0);
            a0 += 0x22C;
            func_800EF25C(a0, a1);
            v0 = D_800D3BC0;
            v1 = v0 - 1;
            v0 <<= 16;
            v0 >>= 15;
            __asm__ volatile("sh %0,4(%1)" : : "r"(v1), "r"(s0) : "memory");
            __asm__ volatile("addu %0,%1,%2" : "=r"(s0) : "0"(s0), "r"(v0));
            v0 = *(volatile u16 *) (s0 + 4);
            v0 -= 1;
            D_800D3BE4 = v0;
            a0 = 0x76;
        } else {
            a0 = 0x76;
        }
        func_80090D30(a0);
        *(volatile s32 *) (s1 + 0xC) = 0;
    }
    a1 = (s32) &D_800D3BBC;
    v0 = *(volatile u16 *) a1;
    v0 &= 1;
    if (v0 == 0)
        goto tail_call;
    v0 = *(volatile s32 *) (s1 + 8);
    if (v0 != 0)
        goto decrement;
    v0 = D_800D3BE4;
    v0 += 1;
    v1 = D_800D3BC2;
    a0 = v1;
    v1 <<= 1;
    __asm__ volatile("addu %0,%1,%2" : "=r"(v1) : "r"(a1), "0"(v1));
    D_800D3BE4 = v0;
    v0 <<= 16;
    v1 = *(s16 *) ((u8 *) v1 + 8);
    v0 = v0 >> 16;
    v0 = (s32) (s16) v0 < v1;
    if (v0 != 0)
        goto update;
    v0 = a0 + 1;
    D_800D3BC2 = v0;
    v0 <<= 16;
    __asm__ volatile("lui %0,%%hi(D_800D3BC0)\n\tlh %0,%%lo(D_800D3BC0)(%0)" : "=r"(v1));
    v0 >>= 16;
    __asm__ volatile("lui $at,0x800d\n\tsh $zero,0x3be4($at)" ::: "at", "memory");
    v0 = (s32) (s16) v0 < v1;
    if (v0 != 0)
        goto update;
    a1 = 1;
    a0 = D_800D3BBE;
    a0 += 0x22C;
    func_800EF25C(a0, a1);
    goto update;
decrement:
    v0 = D_800D3BE4;
    v0 -= 1;
    D_800D3BE4 = v0;
    v0 <<= 16;
    if (v0 > 0)
        goto update;
    v0 = D_800D3BC2_u;
    v0 -= 1;
    D_800D3BC2 = v0;
    v0 <<= 16;
    v0 >>= 16;
    if (v0 < 0)
        goto update;
    v0 <<= 1;
    __asm__ volatile("addu %0,%1,%2" : "=r"(v0) : "r"(a1), "0"(v0));
    v0 = *(volatile u16 *) (v0 + 8);
    D_800D3BE4 = v0;
update:
    v0 = D_8004D950_v;
    v0 |= 2;
    D_8004D950_v = v0;
    goto end;
tail_call:
    __asm__(".macro J6DBB8CALL target\n"
            ".word 0x0c000000\n"
            ".reloc .-4, R_MIPS_26, \\target\n"
            ".purgem J6DBB8CALL\n"
            ".endm\n");
    __asm__ volatile("J6DBB8CALL func_80090D30\n\taddu $4,$zero,$zero" ::: "memory");
    a0 = D_8004D950_v;
    KEEP_NOVOL(a0);
    v1 = D_800BB4F0;
    a0 |= 2;
    v0 = v1 - 1;
    v1 -= 2;
    D_800BB4F0 = v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    KEEP_NOVOL(v0);
    MEMORY_BARRIER();
    at = (s32) &D_800BB98C;
    __asm__ volatile("addu %0,%1,%2" : "=r"(at) : "0"(at), "r"(v0));
    v0 = *(volatile s32 *) at;
    KEEP_NOVOL(v0);
    v1 = -0x2001;
    D_8004D950_v = a0;
    a0 &= v1;
    D_8004D950_v = a0;
    MEMORY_BARRIER();
    v1 = v0 * 0x24;
    at = (s32) &D_800BB504[0];
    __asm__ volatile("addu %0,%1,%2" : "=r"(at) : "0"(at), "r"(v1));
    __asm__ volatile("lw %0,0(%1)" : "=r"(v0) : "r"(at));
    a0 = -0x11;
    v0 &= a0;
    at = (s32) &D_800BB504[0];
    __asm__ volatile("addu %0,%1,%2" : "=r"(at) : "0"(at), "r"(v1));
    *(volatile s32 *) at = v0;
    func_8006C44C(a0);
end:;
}

void func_8006DE50(s32 arg0, s32 arg1) {
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB998;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 *at asm("at");

    a2 = D_800BB4F0;
    v1 = 0x10;
    v0 = a2;
    v0 <<= 1;
    v0 += a2;
    v0 <<= 3;
    v0 -= a2;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB994 + v0);
    *at = v1;
    v1 = D_8004D950;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = a0;
    a0 = 1;
    at = (s32 *) ((char *) &D_800BB998 + v0);
    *at = a0;
    a0 = a2 << 2;
    at = (s32 *) ((char *) &D_800BB990 + v0);
    *at = a1;
    v1 |= 0x2000;
    at = &D_8004D950;
    *at = v1;
    v1 = a2 - 1;
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    v1 = *at;
    v0 = 0x36;
    at = (s32 *) ((char *) &D_800D4584 + a0);
    *at = v0;
    v0 = v1 * 36;
    v1 = *(s32 *) ((char *) &D_800BB504 + v0);
    KEEP(v1);
    a2 += 1;
    at = &D_800BB4F0;
    *at = a2;
    KEEP(a2);
    v1 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v0) = v1;
}
