#include "common.h"

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

extern void func_800248FC();
extern s32 func_8002398C();
extern void func_800FFD70();
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
extern void func_80068B3C();
extern s16 D_800D486C;
extern s32 D_800D3CB8[];
extern s32 D_800D09A0[];
extern s32 D_800BBC88[];
extern s32 D_8009EF80[];
extern u8 D_80057EEC[];
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
extern s32 D_8004D950;
extern s32 func_8008CF14();
extern s32 D_8009F198;
extern s32 D_800C72F4;
extern void func_8008E540();
extern void func_8008CB8C();
extern void func_8008D514();
extern void func_8008F284();
extern void func_80067CB4();
extern void func_8001DBA8();
extern void func_800246D4();
extern void func_800911CC();
extern void func_800EF25C();
extern s32 D_8009F254;
extern s32 D_800BB4F0;
extern s32 D_800D463C;
extern s32 D_800D4664;
extern void func_800686C8();
extern s32 D_8004EAF8;
extern void func_80011E38(s32 *);
extern void func_80090E20(void);
extern s32 D_80094DF8;
extern s32 func_80068AB4(s32);
extern s32 D_800BB988;
extern void func_80018240();
extern s32 D_8009F2E8;
extern s32 D_800BC2F0;
extern s32 D_800D0AB8;
extern s32 D_800D0AC8;
extern void func_80090D50(s32 arg0, s32 arg1);
extern s32 func_8006AC08();
extern s32 func_8006AC98();
extern s32 D_8009F180;
extern s32 D_8009F244;
extern s32 D_800BB50C[];
extern s32 D_800BBC78[];
extern s32 D_800BBC90[];
extern s32 D_800BBC80[];
extern s32 D_800D09AC;
extern void func_80108920();
extern s32 D_8009F27C;
extern s32 D_8009F280;
extern s32 D_800BB3EC;
extern s32 D_800BB98C[];
extern s32 D_800BB51C[];
extern s32 D_800BB520[];
extern s32 D_800D4580[];
extern s32 D_800BB99C;
extern s32 D_800D0984;
extern s32 func_8006B460();
extern s32 D_800D4644;
extern s32 D_800D4668;
extern s32 D_800D0AF8;
extern s32 D_8009F24C;
extern void func_8008D9A0();
extern s32 func_80068BC4(s32 arg0);
extern void func_80069400(s32 arg0, s32 arg1);
extern s32 func_80069918(s32 arg0);
extern void func_80069934(s16 *arg0, s32 arg1);
extern u8 *func_80069E38(s32 arg0);
extern void func_80069F04(s32 arg0, s32 arg1, void *arg2);

void func_8006DF4C(void *arg0) {
    extern void func_800EF25C(s32, s32);
    extern volatile s32 D_8004D950_v __asm__("D_8004D950");
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 at asm("at");

    s0 = (s32) arg0;
    v0 = *(volatile s32 *) (s0 + 0xC);
    if (v0 != 0) {
        v0 = D_8004D950_v;
        v0 &= 8;
        if (v0 != 0)
            goto end;
        v0 = *(volatile s32 *) (s0 + 4);
        a1 = 1;
        if (v0 != 0) {
            a0 = 2;
            goto call_90D30;
        }
        __asm__ volatile("lw %0,0(%1)" : "=r"(a0) : "r"(s0) : "memory");
        a0 += 0x200;
        a1 = 1;
        func_800EF25C(a0, a1);
        a0 = 0x77;
call_90D30:
        func_80090D30(a0);
        *(volatile s32 *) (s0 + 0xC) = 0;
    }
    v0 = *(volatile s32 *) (s0 + 8);
    if (v0 != 0) {
        v0 = D_8004D950_v;
        v1 = *(volatile s32 *) (s0 + 8);
        v0 |= 2;
        v1 -= 1;
        D_8004D950_v = v0;
        *(s32 *) (s0 + 8) = v1;
        goto end;
    }
    v0 = *(volatile s32 *) (s0 + 4);
    a1 = 0;
    if (v0 != 0) {
        v1 = *(volatile s32 *) s0;
        v0 = v1 << 1;
        v0 += v1;
        v0 <<= 2;
        v0 += v1;
        v0 <<= 2;
        KEEP_NOVOL(v0);
        MEMORY_BARRIER();
        v1 = *(volatile s32 *) ((char *) &D_800D3CB8[0] + v0);
        KEEP_NOVOL(v1);
        v1 |= 0x10;
        *(volatile s32 *) ((char *) &D_800D3CB8[0] + v0) = v1;
        a0 = *(volatile s32 *) s0;
        a0 += 0x200;
        func_800EF25C(a0, a1);
    }
    a0 = D_8004D950_v;
    MEMORY_BARRIER();
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
    v0 = *(volatile s32 *) ((char *) &D_800BB98C[0] + v0);
    KEEP_NOVOL(v0);
    v1 = -0x2001;
    MEMORY_BARRIER();
    D_8004D950_v = a0;
    MEMORY_BARRIER();
    a0 &= v1;
    MEMORY_BARRIER();
    D_8004D950_v = a0;
    MEMORY_BARRIER();
    v1 = v0 * 0x24;
    v0 = *(volatile s32 *) ((char *) &D_800BB504[0] + v1);
    KEEP_NOVOL(v0);
    a0 = -0x11;
    v0 &= a0;
    *(volatile s32 *) ((char *) &D_800BB504[0] + v1) = v0;
    func_8006C44C(a0);
end:;
}

void func_8006E0FC(void) {
    extern void func_80108388(s32, s32, s32);
    extern s32 func_800EF1A8(s32);
    extern s32 D_800BB990[];
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    a0 = 4;
    USE_NOVOL(a0);
    v0 = -1;
    a1 = -0x30;
    D_800BB3C0 = v0;
    func_80108388(a0, a1, -0x38);
    s0 = 1;
    D_800D0984 = s0;
    a0 = 0x2C;
    v0 = func_800EF1A8(a0);
    a1 = 0xFBFFFFFF;
    v1 = D_800BB4F0;
    a0 = D_8004D950;
    D_800D09AC = v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    v1 = 3;
    a1 &= a0;
    a0 &= 8;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = v1;
    at = (s32 *) ((char *) D_800BB990 + v0);
    *at = 0;
    D_8004D950 = a1;
    if (a0 != 0) {
        v0 = 0x08000000;
        a0 = (s32) &D_800D0AC8;
        v1 = *(s32 *) a0;
        v0 |= a1;
        D_8004D950 = v0;
        v1 -= 4;
        *(s32 *) a0 = v1;
    }
    v0 = D_800BB4F0;
    v1 = v0 << 2;
    v0 += 1;
    at = (s32 *) ((char *) D_800D4584 + v1);
    *at = s0;
    D_800BB4F0 = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8006E208);

extern s32 D_8009EEFC;
extern s32 D_8009EF00;
extern s32 D_8009EF04;
extern s32 D_8009EF08;
extern s32 D_8009EF0C;
extern s32 D_8009EF2C;
extern s32 D_8009EF44;
extern s32 D_8009EF54;
extern s32 D_8009EF5C;
extern s32 D_8009EF60;
extern s32 D_8009EF64;
extern void func_800E8698();

void func_8006E4A8(s32 arg0, s32 arg1) {
    extern s32 D_800BB990[];
    extern s32 D_800BB994[];
    extern s32 D_8016EE68[];
    extern void func_800E8660(s32 *);
    extern s32 func_800E6EDC(s32);
    extern void func_800E4668(s16 *, s16 *, s32);
    extern void func_8008FFE0(void *, s32, s32);
    extern void func_80090D30();
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    volatile s32 sp10;
    volatile s32 sp14;
    volatile s32 pad[2];
    s16 sp20;
    s16 sp22;
    s32 t;
    s32 tail1;
    s32 tail2;

    s2 = a0;
    v1 = D_800BB4F0;
    v0 = v1 * 2;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB98C[0] + v0);
    at[0] = a1;
    if (a1 == 0)
        goto loc1;
    func_800E8698();
    func_800E8660(&D_8016EE68[0]);
loc1:
    a0 = (s32) &D_8009EF80[0];
    a1 = (s32) (s32 *) &D_8009F198;
    a2 = func_8006B460((s32 *) a0, (s32 *) a1);
    s0 = 1;
    v1 = D_800BB4F0;
    v0 = v1 * 2;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB994[0] + v0);
    at[0] = a2;
    v0 = a2 * 8;
    v0 += a2;
    v0 <<= 2;
    v1 = 0xE;
    at = (s32 *) ((char *) &D_800BB508[0] + v0);
    at[0] = v1;
    at = (s32 *) ((char *) &D_800BB50C[0] + v0);
    at[0] = s0;
    at = (s32 *) ((char *) &D_800BB514[0] + v0);
    at[0] = 0;
    at = (s32 *) ((char *) &D_800BB510[0] + v0);
    at[0] = 0;
    a0 = s2;
    t = func_800E6EDC(a0);
    a0 = (s32) &sp20;
    a1 = (s32) &sp22;
    KEEP(t);
    a2 = t;
    func_800E4668((s16 *) a0, (s16 *) a1, a2);
    v0 = sp22;
    s1 = (s32) &D_800BB504[0];
    if (v0 >= 4) {
        v0 = 3;
        sp22 = v0;
    }
    v0 = (s32) &D_8009EF2C;
    a0 = v0 - 52;
    *(s32 *) v0 = s2;
    *(s32 *) (v0 - 52) = 0;
    a2 = sp20;
    a1 = sp22;
    v0 = 0xC0;
    D_8009EF44 = s0;
    s0 = -1;
    D_8009EEFC = v0;
    D_8009EF54 = 0;
    D_8009EF5C = s0;
    D_8009EF64 = s0;
    D_8009EF60 = s0;
    v1 = a2 + 24;
    v1 &= 0xFFFC;
    v0 = a1 * 16;
    v0 += 16;
    sp10 = v1;
    v1 = v1 / 2;
    v1 = -v1;
    sp14 = v0;
    v0 = v0 / 2;
    v0 = -v0;
    D_8009EF00 = v1;
    D_8009EF04 = v0;
    D_8009EF08 = a2;
    D_8009EF0C = a1;
    func_8008FFE0((void *) a0, a1, a2);
    v1 = D_800BB4F0;
    v0 = v1 * 2;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    v1 = s1 + 24;
    a2 = *(s32 *) ((char *) &D_800BB994[0] + v0);
    v0 = sp10;
    a1 = a2 * 8;
    a1 += a2;
    a1 <<= 2;
    a1 += v1;
    *(s32 *) a1 = -(v0 / 2) + 2;
    v0 = sp14;
    a0 = 0x12;
    ((s32 *) a1)[1] = -(v0 / 2) - 2;
    func_80090D30(a0, (s32 *) a1, a2);
    v1 = D_800BB4F0;
    a0 = D_800BB3C0;
    D_800BB3C0 = s0;
    v0 = v1 * 2;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB990[0] + v0);
    at[0] = a0;
    a0 = v1 << 2;
    v0 = 2;
    v1 = v1 + 1;
    at = (s32 *) ((char *) &D_800D4584[0] + a0);
    at[0] = v0;
    D_800BB4F0 = v1;
    at = (s32 *) &tail1;
    at = (s32 *) &tail2;
    return;
}

extern void func_800E86EC();
extern s32 D_8009EF3C;

void func_8006E77C(void *arg0) {
    extern s32 func_800903E4(s32 *);
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    s0 = (s32 *) arg0;
    KEEP_NOVOL(s0);
    a0 = (s32) &D_8009EF3C;
    v0 = *(s32 *) a0;
    v1 = v0 << 1;
    v1 += v0;
    v1 <<= 2;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) ((char *) D_800BBC70 + v1);
    v0 = *at;
    v0 &= 0x100;
    if (v0 != 0)
        goto epi;
    v0 = func_800903E4((s32 *) (a0 - 0x44));
    if (v0 != 0)
        goto epi;
    v0 = s0[1];
    v1 = D_8009F198;
    D_8009F2E8 = 0;
    D_800BB3C0 = v0;
    v0 = D_8009F180;
    v1 -= 1;
    D_8009F198 = v1;
    v0 -= 1;
    D_8009F180 = v0;
    v0 = D_800BB4F0;
    v1 = s0[0];
    v0 -= 1;
    D_800BB4F0 = v0;
    if (v1 == 0)
        goto call;
    func_800E86EC();
call:
    func_8006C44C();
epi:
    return;
}

extern s32 D_800E4D9C;

void func_8006E860(s32 arg0, s32 arg1) {
    extern void func_800E8660(s32 *);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 D_800BB990[];
    extern s32 D_800BB994[];
    extern s32 D_800BB998[];
    extern s32 D_8016EE68;
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");

    v1 = D_800BB4F0;
    FORCE_REG_NOVOL(s0);
    s0 = arg0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = arg1;
    if (arg1 == 0)
        goto zero;
    goto nonzero;
nonzero:
    func_800E8698();
    a0 = (s32) &D_8016EE68;
    func_800E8660((s32 *) a0);
zero:
    a1 = (s32) &D_800E4D9C;
    a0 = 2;
    func_800FFD70(a0, (s32 *) a1);
    v0 = D_8004D950;
    v1 = 0x20000;
    v0 &= v1;
    if (v0 != 0) {
        a1 = 0x3B;
        a0 = 2;
        goto call;
    }
    a0 = 2;
    a1 = 0x33;
call:
    a2 = s0;
    a3 = 0;
    func_800FFF08(a0, a1, a2, a3);
    v1 = D_800BB4F0;
    USE_NOVOL(v1);
    a1 = D_800BB3C0;
    USE_NOVOL(a1);
    v0 = -1;
    D_800BB3C0 = v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) D_800BB990 + v0);
    *at = a1;
    a0 = 0x12;
    func_80090D30(a0, a1);
    a0 = D_800BB4F0;
    v1 = 8;
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    v0 -= a0;
    v0 <<= 2;
    at = (s32 *) ((char *) D_800BB998 + v0);
    *at = v1;
    v1 = a0 << 2;
    at = (s32 *) ((char *) D_800BB994 + v0);
    *at = 0;
    v0 = 3;
    a0 += 1;
    at = (s32 *) ((char *) D_800D4584 + v1);
    *at = v0;
    D_800BB4F0 = a0;
}

extern s32 D_800D457C;
extern s32 D_800459BC;
extern s32 D_800459C0;
extern s32 D_800459C4;
extern s32 D_800D09B0;
extern s32 D_800D09B4;

void func_8006E9BC(void *arg0) {
    extern s32 func_800FFEEC();
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    v0 = D_800BB4F0;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800D457C + v0);
    v1 = *at;
    s0 = (s32) arg0;
    v0 = 0x1C;
    if (v1 == v0)
        goto copy;
    v0 = 0x25;
    if (v1 != v0)
        goto after_copy;
copy:
    v0 = D_800459C4;
    v1 = D_800459C0;
    a0 = D_800459BC;
    D_800D09AC = v0;
    D_800D09B0 = v1;
    D_800D09B4 = a0;
after_copy:
    a0 = 2;
    v0 = func_800FFEEC(a0);
    if (v0 != 0)
        goto epi;
    v1 = D_800BB4F0;
    v0 = s0[1];
    v1 -= 1;
    D_800BB3C0 = v0;
    D_800BB4F0 = v1;
    func_8006C44C();
    v0 = s0[0];
    if (v0 != 0)
        func_800E86EC();
epi:
    return;
}

extern s32 D_800BBC8C[];
extern s32 func_8006B548();

void func_8006EA90(void) {
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB998;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 s0 asm("s0");
    register s32 *s1 asm("s1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    volatile s32 pad[4];

    s0 = (s32 *) &D_8009EF80;
    s1 = (s32 *) &D_8009F198;
    v0 = func_8006B460((s32 *) &D_8009EF80, (s32 *) &D_8009F198);
    a2 = v0;
    a0 = (s32) s0;
    USE_NOVOL(a0);
    v1 = D_800BB4F0;
    USE_NOVOL(v1);
    s0 = 3;
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
    v1 = 2;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f04 = v1;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f08 = s0;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f10 = 0;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f0C = 0;
    v0 = func_8006B548((s32 *) &D_8009EF80, (s32 *) &D_8009F198, a2);
    a2 = v0;
    v0 = a2 << 1;
    v0 += a2;
    v0 <<= 2;
    v0 += a2;
    a0 = D_800BB4F0;
    KEEP_NOVOL(a0);
    v0 <<= 2;
    v1 = a0;
    v1 <<= 1;
    v1 += a0;
    v1 <<= 3;
    v1 -= a0;
    v1 <<= 2;
    a0 = (s32) &D_800BB98C;
    at = (s32 *) ((char *) &D_800BB990 + v1);
    *at = a2;
    __asm__ volatile("" : : "m"(*(s32 *) ((char *) &D_800BB990 + v1)));
    a1 = *(s32 *) ((char *) &D_800BBC70[0] + v0);
    at = (s32 *) ((char *) &D_800BBC78[0] + v0);
    *at = 3;
    a1 |= 0x100;
    KEEP(a1);
    *(s32 *) ((char *) &D_800BBC70[0] + v0) = a1;
    at = (s32 *) ((char *) &D_800BB994 + v1);
    *at = 0;
    a0 += v1;
    func_8006ED30((s32 *) a0, a1, a2);
    a2 = D_800BB4F0;
    a0 = a2 << 1;
    a0 += a2;
    a0 <<= 3;
    a0 -= a2;
    a0 <<= 2;
    at = (s32 *) ((char *) &D_800BB998 + a0);
    *at = 0;
    v0 = *(volatile s32 *) ((char *) &D_800BB98C + a0);
    v1 = *(s32 *) ((char *) &D_800BB990 + a0);
    a1 = v0 << 3;
    a1 += v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v0 = *(s32 *) ((char *) &D_800BBC88[0] + v0);
    a1 <<= 2;
    v0 += 8;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + a1)).f18 = v0;
    v0 = a2 + 1;
    v1 = *(volatile s32 *) ((char *) &D_800BB98C + a0);
    a2 <<= 2;
    D_800BB4F0 = v0;
    a1 = v1 << 3;
    a1 += v1;
    v1 = *(s32 *) ((char *) &D_800BB990 + a0);
    a1 <<= 2;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = *(s32 *) ((char *) &D_800BB998 + a0);
    at = (s32 *) ((char *) &D_800BBC8C[0] + v0);
    v0 = *at;
    v1 <<= 4;
    KEEP(v1);
    v1 += 0xC;
    v0 += v1;
    at = (s32 *) ((char *) &D_800BB520[0] + a1);
    *at = v0;
    v0 = 0xB;
    at = (s32 *) ((char *) &D_800D4584 + a2);
    *at = v0;
}

extern s32 D_800C87D8;

void func_8006ED30(void *arg0) {
    extern s32 func_800EF1A8(s32);
    extern s32 D_801531D8[];
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3") = (s32) arg0;
    register s32 s4 asm("s4");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[10];

    s1 = *(s32 *) (s3 + 8);
    v0 = s1 + 0xA;
    v0 = v0 < 0x400 ? 0xA : 0x400 - s1;
    *(s32 *) (s3 + 0x30) = v0;
    USE(v0);
    a3 = 0;
    v1 = *(volatile s32 *) (s3 + 0x30);
    s2 = *(s32 *) (s3 + 4);
    v0 = 0x68;
    *(volatile u16 *) ((char *) sp + 0x18) = 0;
    *(volatile u16 *) ((char *) sp + 0x1A) = 0;
    *(volatile u16 *) ((char *) sp + 0x1C) = (u16) v0;
    a0 = s2;
    USE(a0);
    v0 = v1 << 4;
    v0 += 0x10;
    *(volatile u16 *) ((char *) sp + 0x1E) = (u16) v0;
    v0 = (s32) &D_800C87D8;
    *(volatile s32 *) ((char *) sp + 0x10) = v0;
    v0 = *(volatile u16 *) ((char *) sp + 0x18);
    a1 = *(volatile u16 *) ((char *) sp + 0x1A);
    v1 = *(volatile u16 *) ((char *) sp + 0x1C);
    a2 = *(volatile u16 *) ((char *) sp + 0x1E);
    a1 <<= 16;
    a1 = v0 | a1;
    a2 <<= 16;
    __asm__ volatile("" : : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(v0), "r"(v1) : "memory");
    ((void (*)(s32, s32, s32, s32)) func_8008F514)(a0, a1, v1 | a2, a3);
    v0 = (s32) &D_800BBC88[0];
    v1 = s2 << 1;
    v1 += s2;
    v1 <<= 2;
    v1 += s2;
    v1 <<= 2;
    v1 += v0;
    a0 = *(u16 *) ((char *) sp + 0x1C);
    v0 = -0x58;
    *(s32 *) (v1 + 4) = v0;
    a0 <<= 16;
    v0 = a0 >> 16;
    a0 = (u32) a0 >> 31;
    v0 += a0;
    v0 >>= 1;
    v0 = -v0;
    *(s32 *) v1 = v0;
    *(volatile s32 *) ((char *) sp + 0x20) = 8;
    *(volatile s32 *) ((char *) sp + 0x24) = 8;
    v0 = *(s32 *) (s3 + 0x30);
    s0 = 0;
    if (v0 > 0) {
        s4 = (s32) &D_801531D8[0];
        do {
            USE(s1);
            v0 = func_800EF1A8(s1);
            v1 = v0;
            v0 = (u32) v1 < 0x2710U;
            if (v0 != 0) {
                a1 = 0x24;
                *(s32 *) s4 = s1;
                *(s32 *) (s4 + 4) = v1;
                goto join;
            } else {
                at = (s32 *) &D_801531D8[0];
                *(s32 *) at = s1;
                a1 = 0x25;
            }
join:
            a0 = s2;
            v0 = (s32) &D_800C87D8;
            *(volatile s32 *) ((char *) sp + 0x10) = v0;
            a2 = *(volatile s32 *) ((char *) sp + 0x20);
            a3 = *(volatile s32 *) ((char *) sp + 0x24);
            __asm__ volatile("" : : "r"(a0), "r"(a1), "r"(a2), "r"(a3) : "memory");
            ((void (*)(s32, s32, s32, s32)) func_8008F828)(a0, a1 | 0xB800, a2, a3);
            v0 = *(s32 *) ((char *) sp + 0x24);
            v0 += 0x10;
            *(volatile s32 *) ((char *) sp + 0x24) = v0;
            v0 = *(s32 *) (s3 + 0x30);
            USE(v0);
            s0 += 1;
            USE(s0);
            s1 += 1;
        } while (s0 < v0);
    }
    a0 = s2;
    a1 = (s32) &D_800C87D8;
    func_8008F72C(a0, (void *) a1);
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8006EEEC);

void func_8006F294(s32 arg0, s16 arg1) {
    extern void func_8008FDB4(s32, s32, s32, s32 *);
    extern s32 D_800BB990;
    s32 s0;
    s32 a0;
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 *a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    WldCoreTempPair sp;

    s0 = arg0;
    v0 = 0x60;
    D_800BB3C0 = v0;
    v0 = 2;
    D_800BB3EC = v0;
    v0 = 0x20;
    a0 = 0xC;
    KEEP_NOVOL(a0);
    D_800D4574 = arg1;
    a1 = 0x270F0000;
    KEEP_NOVOL(a1);
    a2 = 0;
    a3 = &sp.first;
    KEEP_WITH_NOVOL(a3, a2);
    sp.first = v0;
    sp.second = v0;
    func_8008FDB4(a0, a1, a2, a3);
    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    a0 = v1 << 2;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = 0;
    at = (s32 *) ((char *) &D_800BB990 + v0);
    *at = s0;
    v0 = 0x30;
    v1 += 1;
    at = (s32 *) ((char *) &D_800D4584 + a0);
    *at = v0;
    D_800BB4F0 = v1;
}

void func_8006F35C(s32 *arg0) {
    extern s32 func_800FFEEC(s32);
    extern void func_800EF25C();
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 D_800BB930;
    extern s32 D_800BB990[];
    register s32 *s0 asm("s0") = arg0;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    KEEP(s0);
    v0 = s0[0];
    if (v0 == 0)
        goto alternate;
    a0 = 0xC;
    v0 = func_800FFEEC(a0);
    if (v0 != 0)
        goto alternate;
    v0 = 1;
    v1 = D_800BB4F0;
    a0 = s0[0];
    D_800BB3C0 = 0;
    D_800BB3EC = v0;
    v1 -= 1;
    D_800BB4F0 = v1;
    if (a0 != v0)
        goto call_cleanup;
    a0 = v1;
    a0 <<= 1;
    a0 += v1;
    a0 <<= 3;
    a0 -= v1;
    a0 <<= 2;
    a0 += (s32) &D_800BB930;
    func_8006ED30((s32 *) a0);
call_cleanup:
    v0 = D_800BB4F0;
    v0 -= 1;
    v1 = v0;
    v1 <<= 1;
    v1 += v0;
    v1 <<= 3;
    v1 -= v0;
    v1 <<= 2;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + v1);
    a0 = *at;
    v0 = a0;
    v0 <<= 3;
    v0 += a0;
    v0 <<= 2;
    a0 = 2;
    at = (s32 *) &D_800BB508[0];
    at = (s32 *) ((char *) at + v0);
    *at = a0;
    at = (s32 *) &D_800BB990[0];
    at = (s32 *) ((char *) at + v1);
    a0 = *at;
    v0 = a0;
    v0 <<= 1;
    v0 += a0;
    v0 <<= 2;
    v0 += a0;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + v1);
    a0 = *at;
    v0 <<= 2;
    at = (s32 *) &D_800BBC84[0];
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    v0 = (s32) &D_800BB504[0];
    v1 = a0;
    v1 <<= 3;
    v1 += a0;
    v1 <<= 2;
    v0 += v1;
    *(s32 *) (v0 + 0x14) = 0;
    *(s32 *) (v0 + 0xC) = 0;
    at = (s32 *) &D_800BB514[0];
    at = (s32 *) ((char *) at + v1);
    *at = 0;
    goto done;
alternate:
    v1 = D_800BC2F0;
    v0 = v1 & 0x40;
    if (v0 == 0)
        goto check20;
    *s0 = 2;
    goto call_flags;
check20:
    v0 = v1 & 0x20;
    if (v0 == 0)
        goto done;
    func_80090D30(1);
    a0 = s0[1];
    a1 = D_800D4574;
    *s0 = 1;
    func_800EF25C(a0, a1);
call_flags:
    a0 = 0xC;
    a1 = 0;
    a2 = 0;
    a3 = 1;
    func_800FFF08(a0, a1, a2, a3);
done:
    return;
}

void func_8006F528(void) {
    extern void func_8006F67C(void *, s32);
    extern s32 D_800BB990[];
    extern s32 D_800BB994[];
    extern s32 D_800BB998[];
    s32 s0;
    s32 a0;
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    v1 = D_800BB4F0;
    a1 = D_800BB3EC;
    a0 = (s32) D_8009EF80;
    s0 = 1;
    D_800BB3EC = s0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) D_800BB998 + v0);
    *at = a1;
    a1 = (s32) &D_8009F198;
    v0 = func_8006B460((void *) a0, (void *) a1);
    v1 = D_800BB4F0;
    a0 = (s32) &D_800BB98C;
    a1 = v1 << 1;
    a1 += v1;
    a1 <<= 3;
    a1 -= v1;
    a1 <<= 2;
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + a1);
    *at = v0;
    v0 = 0x78;
    at = (s32 *) ((char *) D_800BB508 + v1);
    *at = v0;
    v0 = 2;
    at = (s32 *) ((char *) D_800BB50C + v1);
    *at = v0;
    at = (s32 *) ((char *) D_800BB514 + v1);
    *at = 0;
    at = (s32 *) ((char *) D_800BB510 + v1);
    *at = 0;
    at = (s32 *) ((char *) D_800BB990 + a1);
    *at = 0;
    at = (s32 *) ((char *) D_800BB994 + a1);
    *at = s0;
    func_8006F67C((void *) (a0 + a1), a1);
    v0 = D_800BB4F0;
    v1 = 0x38;
    a0 = v0 << 2;
    v0 += 1;
    at = (s32 *) ((char *) D_800D4584 + a0);
    *at = v1;
    D_800BB4F0 = v0;
}

extern s16 D_8009E946[];
extern s16 D_8009E948[];
extern s16 D_8009E94A[];

void func_8006F67C(s32 *arg0) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    a1 = (s32) arg0;
    a0 = (s32) &D_800BB51C[0];
    KEEP(a0);
    a3 = arg0[0];
    MEMORY_BARRIER();
    v1 = arg0[1];
    v0 = a3;
    v0 <<= 3;
    v0 += a3;
    a2 = v0 << 2;
    USE(a2);
    v1 <<= 4;
    KEEP(v1);
    at = (s32 *) ((char *) &D_8009E946[0] + v1);
    v0 = *(s16 *) at;
    a0 = a2 + a0;
    v0 = v0 + 0xE;
    *(s32 *) a0 = v0;
    at = (s32 *) ((char *) &D_8009E948[0] + v1);
    v0 = *(s16 *) at;
    v0 = v0 + 0xC;
    *(s32 *) (a0 + 4) = v0;
    at = (s32 *) ((char *) &D_8009E94A[0] + v1);
    v1 = *(s16 *) at;
    v0 = arg0[2];
    if (v1 == v0)
        goto end;
    __asm__ volatile(".set\tnoreorder\n\tbeqz\t%1,1f\n\tsw\t%1,0x8(%0)\n\tj\t2f\n\tori\t$2,$zero,0x78\n1:\n\tori\t$2,$zero,0x2\n2:\n\t.set\treorder" : : "r"(a1), "r"(v1) : "memory");
st:
    at = (s32 *) ((char *) &D_800BB508[0] + a2);
    at[0] = v0;
    v0 = a3 << 3;
    v0 += a3;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB514[0] + v0);
    at[0] = 0;
    at = (s32 *) ((char *) &D_800BB510[0] + v0);
    at[0] = 0;
end:
    return;
}

extern s32 D_8015330C;

void func_8006F750(s32 *arg0) {
    s32 *a;
    s32 v0;
    register s32 v1 asm("v1");

    v1 = arg0[0];
    a = (s32 *) &D_800BB504;
    D_8015330C = 0;
    v0 = v1 * 36;
    v1 = (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f04;
    a = (s32 *) ((char *) a + v0);
    v1 += 1;
    *(s32 *) ((char *) a + 4) = v1;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f14 = 0;
    *(s32 *) ((char *) a + 16) = 0;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f0C = 0;
}

void func_8006F7B8(void) {
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8006F7C0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8006F7C8);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8006FAF0);

void func_800702E4(s32 *arg0) {
    s32 v1 = arg0[4];
    if (v1 == -1)
        return;
    D_800BBC84[v1 * 13] = 0;
}

void func_8007031C(s32 *arg0) {
    s32 v1 = arg0[4];
    if (v1 == -1)
        return;
    D_800BBC84[v1 * 13] = 2;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80070358);

void func_80070968(s32 *arg0, s32 arg1) {
    s32 a0;
    s32 a1;
    s32 a2;
    s32 v0;
    s32 v1;
    s32 *at;

    v0 = arg0[1];
    a2 = -1;
    D_800BB3C0 = 0;
    if (v0 != a2) {
        v0 = D_8009F180;
        v1 = D_8009F198;
        v0 -= 1;
        v1 -= 1;
        D_8009F180 = v0;
        D_8009F198 = v1;
    }
    v0 = arg0[2];
    if (v0 != a2) {
        v0 = D_8009F244;
        v1 = D_8009F198;
        v0 -= 1;
        v1 -= 1;
        D_8009F244 = v0;
        D_8009F198 = v1;
    }
    v0 = arg0[3];
    if (v0 != a2) {
        v0 = D_8009F180;
        v1 = D_8009F198;
        v0 -= 1;
        v1 -= 1;
        D_8009F180 = v0;
        D_8009F198 = v1;
    }
    v0 = arg0[4];
    if (v0 != a2) {
        v0 = D_8009F244;
        v1 = D_8009F198;
        v0 -= 1;
        v1 -= 1;
        D_8009F244 = v0;
        D_8009F198 = v1;
    }
    v0 = D_800BB4F0;
    v0 -= 1;
    D_800BB4F0 = v0;
    if (arg1 != 0)
        func_8006C44C();
    v0 = D_8004D950;
    v1 = -0x2001;
    v0 &= v1;
    D_8004D950 = v0;
}

extern void func_80106A28(s32, s32, s32);

void func_80070AA8(s32 arg0) {
    extern void func_80106A28(s32, s32, s32);
    extern void func_800911CC();
    extern void func_80133478(s32);
    extern s32 func_800EF1A8(s32);
    extern void func_8006FAF0(s32);
    extern void func_80069400(s32, s32);
    extern void func_80067CB4(s32);
    extern s32 D_800BB930;
    register s32 s0 asm("s0");
    register s32 *s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    s0 = arg0;
    a0 = 0x80;
    a1 = 0x80;
    a2 = 0x80;
    func_80106A28(a0, a1, a2);
    func_800911CC();
    func_80133478(s0);
    a0 = 0x2C;
    v0 = func_800EF1A8(a0);
    v1 = D_800BB4F0;
    s0 = (s32) &D_800BB930;
    D_800D09AC = v0;
    a0 = v1 * 92;
    a0 += s0;
    func_8006C844((void *) a0);
    s1 = (s32 *) &D_8009F254;
    KEEP_NOVOL(s1);
    s0 += 0x90;
    v0 = D_800BB4F0;
    a0 = *s1;
    a1 = v0 * 92;
    a1 += s0;
    v0 = func_8008D2C8(a0, (void *) a1);
    a0 = D_800BB4F0;
    v1 = a0 * 92;
    at = (s32 *) &D_800BB9BC;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    a0 = *s1;
    func_8006FAF0(a0);
    a0 = 4;
    a1 = 0x10;
    func_80069400(a0, a1);
    a0 = 0;
    func_80067CB4(a0);
    a0 = 0x77FF;
    v1 = 0x1DFFC;
    v0 = D_800C72F4;
    v0 += v1;
loop:
    *(s32 *) v0 = 0;
    a0 -= 1;
    v0 -= 4;
    if (a0 >= 0)
        goto loop;
    a0 = 0x11B;
    func_80091174(a0);
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80070BE4);

void func_80070F00(s32 *arg0) {
    extern s32 func_800903E4(s32 *);
    register s32 *s0 asm("s0") = (s32 *) &D_8009EF3C;
    register s32 *s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");

    MEMORY_BARRIER();
    v0 = *s0;
    v1 = v0 * 52;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v1);
    v1 = *at;
    v0 = v1 & 0x10;
    if (v0 == 0)
        goto no_bit;
    s1 = arg0;
    KEEP_NOVOL(s1);
    v0 = D_8004D950;
    v0 &= 8;
    if (v0 != 0)
        goto exit;
    a0 = 0x12;
    func_80090D30(a0);
    v0 = *s1;
    v1 = v0 * 36;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 &= -0x11;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    v1 = *s0;
    v0 = v1 * 52;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    v1 &= -0x11;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    goto exit;
no_bit:
    v0 = v1 & 0x100;
    if (v0 != 0)
        goto exit;
    a0 = (s32) ((char *) s0 - 0x44);
    v0 = func_800903E4((s32 *) a0);
    if (v0 != 0)
        goto exit;
    a0 = 0xF7FF0000;
    a0 |= 0xDFFF;
    v0 = D_8009F180;
    v0 -= 1;
    D_8009F180 = v0;
    v0 = D_8009F198;
    v0 -= 1;
    D_8009F198 = v0;
    v1 = D_800BB4F0;
    v0 = v1 - 1;
    D_800BB4F0 = v0;
    v1 -= 2;
    v0 = v1 * 92;
    KEEP_NOVOL(v0);
    v1 = D_8004D950;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + v0);
    v0 = *at;
    v1 &= a0;
    D_8004D950 = v1;
    v1 = v0 * 36;
    a0 = -0x11;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 &= a0;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    func_8006C44C(a0);
exit:
    return;
}

void func_800710E8(void) {
    extern void func_8008FDB4(s32, s32, s32, s32 *);
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    WldCoreTempPair sp;

    v0 = 0x60;
    D_800BB3C0 = v0;
    v0 = 3;
    D_800BB3EC = v0;
    v0 = -0x28;
    sp.first = v0;
    v0 = -0x16;
    sp.second = v0;
    a0 = 0xC;
    a1 = 0x03E70000;
    a2 = 0xB826;
    D_800D4574 = 0;
    func_8008FDB4(a0, a1, a2, &sp.first);
    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    a0 = v1 << 2;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = 0;
    v0 = 0x34;
    v1 += 1;
    at = (s32 *) ((char *) &D_800D4584 + a0);
    *at = v0;
    D_800BB4F0 = v1;
}

void func_80071198(void) {
    extern s32 func_800FFEEC(s32);
    extern void func_80042930(s16);
    extern void func_800FFF08(s32, s32, s32, s32);
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    s0 = (s32 *) a0;
    v0 = *s0;
    if (v0 == 0)
        goto alternate;
    a0 = 0xC;
    v0 = func_800FFEEC(a0);
    if (v0 != 0)
        goto alternate;
    v0 = 1;
    v1 = D_800BB4F0;
    a0 = *s0;
    D_800BB3C0 = 0;
    D_800BB3EC = v0;
    v1 -= 1;
    D_800BB4F0 = v1;
    if (a0 != v0)
        goto call_cleanup;
    a0 = D_800D4574;
    v0 = a0 < 0x200;
    if (v0 == 0)
        goto call_cleanup;
    func_80042930((s16) a0);
    func_80108920();
    v0 = D_8004D950;
    v0 |= 2;
    D_8004D950 = v0;
call_cleanup:
    func_8006C44C();
    return;
alternate:
    v1 = D_800BC2F0;
    v0 = v1 & 0x40;
    if (v0 == 0)
        goto check20;
    a0 = 2;
    func_80090D30(a0);
    v0 = -1;
    goto set_state;
check20:
    v0 = v1 & 0x20;
    if (v0 == 0)
        goto done;
    a0 = 1;
    func_80090D30(a0);
    v0 = 1;
set_state:
    *s0 = v0;
    a0 = 0xC;
    a1 = 0;
    a2 = 0;
    a3 = 1;
    func_800FFF08(a0, a1, a2, a3);
done:
    return;
}

extern s32 D_8010F250;

void func_800712B0(void) {
    extern s32 D_800BB990[];
    extern s32 D_800BB994[];
    extern s32 D_800BB998[];
    extern void func_80067CB4(s32);
    extern void func_800692AC(s32);
    extern void func_80069400(s32, s32);
    extern s32 func_800EF1A8(s32);
    extern void func_80068B3C(s32);
    extern void func_800686C8();
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_8007148C(s32 *);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a1 asm("a1");
    s32 a0;
    s32 a2;

    func_80067CB4(1);
    func_800692AC(0);
    func_80069400(0, 0x10);
    v0 = func_800EF1A8(0x69);
    v1 = (v0 == 1) ? -1 : 0;
    a0 = v1 & 0x16;
    if (v0 == 2) {
        a0 = 0x17;
    }
    func_80068B3C(a0);
    func_800686C8();
    v0 = D_8004D950;
    v0 = v0 | 0x3000;
    D_8004D950 = v0;
    a1 = (s32) &D_8010F250;
    func_800FFD70(0xE, a1);
    func_800FFF08(0xE, 0x19, 0xB806, 0);
    s0 = (s32) D_8009EF80;
    s1 = (s32) &D_8009F198;
    v0 = func_8006B460(s0, s1);
    a2 = D_800BB4F0;
    v1 = a2 * 92;
    *(s32 *) ((u8 *) &D_800BB98C[0] + v1) = v0;
    v0 = func_8006B460(s0, s1);
    a2 = D_800BB4F0;
    v1 = a2 * 92;
    *(s32 *) ((u8 *) &D_800BB990[0] + v1) = v0;
    v0 = func_8006B548(s0, s1);
    a0 = D_800BB4F0;
    v1 = a0 * 92;
    *(s32 *) ((u8 *) &D_800BB994[0] + v1) = v0;
    func_8007148C((s32 *) ((u8 *) &D_800BB98C[0] + v1));
    v1 = D_800BB4F0;
    v0 = v1 * 3;
    v0 = v0 * 8;
    v0 = v0 - v1;
    v0 = v0 * 4;
    a0 = v1 * 4;
    *(s32 *) ((u8 *) &D_800BB998[0] + v0) = 0;
    v0 = 5;
    *(s32 *) ((u8 *) &D_800D4584[0] + a0) = v0;
    D_800BB4F0 = D_800BB4F0 + 1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8007148C);

void func_800718D0(s32 *arg0) {
    extern void func_800FFF08();
    s32 index2 = arg0[2];
    s32 index0 = arg0[0];
    s32 index1 = arg0[1];
    s32 index0_b;
    s32 index0_c;
    D_800BBC84[index2 * 13] = 0;
    D_800BB518[index1 * 9] = 0;
    D_800BB518[index0 * 9] = 0;
    index0_b = arg0[0];
    D_800BB508[index0_b * 9] = 2;
    index0_c = arg0[0];
    D_800BB514[index0_c * 9] = 0;
    D_800BB510[index0_c * 9] = 0;
    func_800FFF08(0xE, 0x19, 0xB806, 0);
}

void func_800719BC(volatile s32 *arg0) {
    s32 v0;
    s32 v1;
    register s32 *at asm("at");

    v1 = arg0[0];
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    v1 = 0xA;
    at = (s32 *) ((char *) &D_800BB518[0] + v0);
    *at = v1;
    v1 = arg0[1];
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    v1 = 6;
    at = (s32 *) ((char *) &D_800BB518[0] + v0);
    *at = v1;
    v1 = arg0[2];
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = 2;
    at = (s32 *) ((char *) &D_800BBC84[0] + v0);
    *at = v1;
    v1 = arg0[0];
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    v1 = 1;
    at = (s32 *) ((char *) &D_800BB508[0] + v0);
    *at = v1;
    v1 = arg0[0];
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB514[0] + v0);
    *at = 0;
    at = (s32 *) ((char *) &D_800BB510[0] + v0);
    *at = 0;
}

extern s32 D_800BB9C0;
extern void func_8006C4BC();

void func_80071AA0(void) {
    extern void func_800692AC(s32);
    extern void func_8006FAF0(s32);
    extern void func_80069400(s32, s32);
    extern void func_80067CB4(s32);
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    a0 = 1;
    func_800692AC(a0);
    v0 = D_800BB4F0;
    v0 -= 1;
    D_800BB4F0 = v0;
    v0 = D_8004D950;
    v1 = -0x3001;
    v0 &= v1;
    D_8004D950 = v0;
    func_8006C4BC();
    s0 = (s32 *) &D_8009F254;
    v0 = D_800BB4F0;
    a0 = *s0;
    a1 = v0 * 92;
    v0 = (s32) &D_800BB9C0;
    a1 += v0;
    v0 = func_8008D2C8(a0, (void *) a1);
    a0 = D_800BB4F0;
    v1 = a0 * 92;
    at = (s32 *) &D_800BB9BC;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    a0 = *s0;
    func_8006FAF0(a0);
    a0 = 4;
    a1 = 0x10;
    func_80069400(a0, a1);
    a0 = 0;
    func_80067CB4(a0);
    a0 = 0x77FF;
    v1 = 0x1DFFC;
    v0 = D_800C72F4;
    v0 += v1;
loop:
    *(s32 *) v0 = 0;
    a0 -= 1;
    v0 -= 4;
    if (a0 >= 0)
        goto loop;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80071BB0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8007206C);

extern void func_800FFF08();

void func_800723B8(void) {
    D_800BB3C0 = 0x160;
    func_800FFF08(0xE, 0x19, 0xB808, 0);
}

s32 func_800723F0(void) {
    return D_800BB3C0 = -1;
}

void func_80072404(void) {
    s32 a;
    s32 b;

    D_800BB3EC = 1;
    MEMORY_BARRIER();
    a = D_8004D950;
    b = D_800BB4F0;
    D_800BB3C0 = 0;
    a ^= 4;
    b -= 1;
    D_8004D950 = a;
    D_800BB4F0 = b;
}

extern s16 D_800BB354;

void func_80072448(s32 *arg0) {
    extern s32 func_800FFEEC();
    extern void func_80072404();
    extern void func_80072618();
    extern s32 func_800723F0();
    extern void func_8006E860();
    extern void func_8008FC88(s32);
    extern void func_8008FD88(s32);
    extern void func_800FFF08();
    s32 *s0 = arg0;
    register s32 v0 asm("v0");
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    s32 e;
    e = D_8004D950;
    if ((e & 4) == 0)
        goto els;
    if (func_800FFEEC(0xC) != 0)
        goto els;
    ((void (*)()) func_80072404)(s0);
    if (*s0 != 0) {
        s16 h;
        func_8008FC88(0x2);
        h = D_800BB354;
        func_80072618(D_800D0880[h] & 0x7FF);
    } else {
        func_8008FD88(0x2);
        D_8004D950 &= ~0x800;
        func_8006C44C();
    }
    goto epi;
els:
    if ((D_800BC2F0 & 0x40) == 0)
        goto e2;
    if (D_8004EAF8 != 0)
        goto e2;
    func_80090D30(2);
    c0 = 0xC;
    c1 = 0;
    c2 = 0;
    c3 = 1;
    s0[0] = 0;
    goto fjoin;
e2:
    if ((D_800BC2F0 & 0x100) == 0)
        goto e3;
    if (s0[12] == 0)
        goto e3;
    ((s32 (*)()) func_800723F0)(s0);
    func_8006E860(0x105E, 1);
    goto epi;
e3:
    if ((D_800BC2F0 & 0x20) == 0)
        goto epi;
    if (s0[12] == 0)
        goto epi;
    if (D_8004EAF8 != 0)
        goto epi;
    func_80090D30(1);
    c0 = 0xC;
    c1 = 0;
    c2 = 0;
    c3 = 1;
    v0 = 1;
    s0[0] = v0;
fjoin:
    func_800FFF08(c0, c1, c2, c3);
    D_8004D950 |= 4;
epi:;
}

void func_80072618(s32 arg0) {
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB998;
    extern s32 D_801531D8;
    extern void func_8008FFE0();
    extern void func_800FFF08();
    s32 s0 = arg0;
    s32 v1;
    register s32 v0 asm("v0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    volatile s32 pad[2];
    a0 = 0xE;
    v0 = 0xC800;
    v0 = s0 + v0;
    a1 = 0x19;
    a2 = 0xB809;
    USE(a0);
    D_801531D8 = v0;
    func_800FFF08(a0, a1, a2, 0);
    a1 = (s32) &D_8009EF2C;
    v1 = D_800BB4F0;
    USE(v1);
    a0 = a1 - 0x34;
    USE(a0);
    KEEP(a1);
    v0 = v1 * 92;
    *(s32 *) ((char *) &D_800BB98C + v0) = s0;
    v0 = 0x8800;
    s0 += v0;
    *(s32 *) a1 = s0;
    v0 = 0x60;
    MEMORY_BARRIER();
    *(s32 *) (a1 - 52) = 0;
    MEMORY_BARRIER();
    D_8009EEFC = v0;
    v0 = -0x7A;
    *(s32 *) (a1 - 44) = v0;
    v0 = -0x28;
    *(s32 *) (a1 - 40) = v0;
    v0 = 0xDC;
    s0 = 8;
    *(s32 *) (a1 - 36) = v0;
    v0 = 9;
    *(s32 *) (a1 + 24) = v0;
    v0 = -1;
    *(s32 *) (a1 - 32) = s0;
    *(s32 *) (a1 + 40) = 0;
    *(s32 *) (a1 + 48) = v0;
    *(s32 *) (a1 + 56) = v0;
    *(s32 *) (a1 + 52) = v0;
    func_8008FFE0();
    a2 = D_800BB4F0;
    v0 = a2 - 1;
    a1 = v0 * 92;
    a0 = a2 << 1;
    a0 += a2;
    v0 = *(s32 *) ((char *) &D_800BB98C + a1);
    a0 <<= 3;
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    a0 -= a2;
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = *(s32 *) ((char *) &D_800BB98C + a1);
    a0 <<= 2;
    *(s32 *) ((char *) &D_800BB994 + a0) = v0;
    v0 = *(s32 *) ((char *) &D_800BB990 + a1);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = *(s32 *) ((char *) &D_800BB990 + a1);
    *(s32 *) ((char *) &D_800BB998 + a0) = v0;
    MEMORY_BARRIER();
    v1 = *(s32 *) ((char *) &D_800BB994 + a1);
    v0 = v1 * 52;
    v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
    v1 |= 0x10;
    *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
    v0 = a2 + 1;
    v1 = *(s32 *) ((char *) &D_800BB994 + a1);
    a2 <<= 2;
    D_800BB4F0 = v0;
    *(s32 *) ((char *) &D_800BB99C + a0) = v1;
    MEMORY_BARRIER();
    *(s32 *) ((char *) &D_800D4584 + a2) = s0;
}

extern void func_8007206C();

void func_80072888(s32 arg0) {
    extern s32 func_800903E4();
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    s32 *s0 = arg0;
    a0 = (s32) &D_8009EF3C;
    v0 = *(s32 *) a0;
    v1 = v0 * 52;
    v0 = *(s32 *) ((char *) &D_800BBC70 + v1);
    if ((v0 & 0x100) == 0) {
        v0 = func_800903E4(a0 - 0x44);
        if (v0 == 0) {
            v0 = s0[2];
            v1 = v0 * 36;
            v0 = *(s32 *) ((char *) &D_800BB504 + v1);
            v0 ^= 0x10;
            *(s32 *) ((char *) &D_800BB504 + v1) = v0;
            v0 = s0[3];
            v1 = v0 * 36;
            v0 = *(s32 *) ((char *) &D_800BB504 + v1);
            v0 ^= 0x10;
            *(s32 *) ((char *) &D_800BB504 + v1) = v0;
            v1 = s0[4];
            v0 = v1 * 52;
            v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
            v1 ^= 0x10;
            *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
            v1 = s0[4];
            v0 = v1 * 52;
            v1 = D_800BB4F0;
            a0 = *(s32 *) ((char *) &D_800BBC70 + v0);
            v1 -= 1;
            a0 |= 0x100;
            D_800BB4F0 = v1;
            *(s32 *) ((char *) &D_800BBC70 + v0) = a0;
            func_8007206C();
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80072A18);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80072A20);

void func_80072EA8(void) {
    D_800BB3C0 = 0x160;
    func_800FFF08(0xE, 0x19, 0xB80B, 0);
}

s32 func_80072EE0(void) {
    return D_800BB3C0 = -1;
}

void func_80072EF4(void) {
    s32 a;
    s32 b;

    D_800BB3EC = 1;
    MEMORY_BARRIER();
    a = D_8004D950;
    b = D_800BB4F0;
    D_800BB3C0 = 0;
    a ^= 4;
    b -= 1;
    D_8004D950 = a;
    D_800BB4F0 = b;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80072F38);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80072F40);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_800732B8);

void func_80073594(s32 *arg0) {
    s32 v = arg0[1];
    D_800BBC84[v * 13] = 0;
}

void func_800735C8(s32 *arg0) {
    s32 v = arg0[1];
    D_800BBC84[v * 13] = 2;
}

extern u16 D_8009F2F4;
extern u16 D_8009F2F6;
extern s32 D_800D0980;

void func_80073600(s32 *arg0) {
    extern void func_80072A18();
    extern void func_800735C8(s32 *);
    extern void func_80073778(s32, s32, s32, s32, s32, s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 D_801531D8;
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    WldCoreTempPair sp;

    s0 = arg0;
    v0 = s0[1];
    v1 = v0 << 1;
    v1 += v0;
    v1 <<= 2;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) ((char *) &D_800BBC70[0] + v1);
    v0 = *at;
    v0 &= 0x100;
    if (v0 != 0)
        goto end;
    v1 = D_800BC2F0;
    v0 = v1 & 0x40;
    if (v0 == 0) {
        v0 = v1 & 0x20;
        goto alternate;
    }
    v0 = v1 & 0x20;
    a0 = 2;
    func_80090D30(a0);
    v0 = D_8009F244;
    v0 -= 1;
    D_8009F244 = v0;
    v1 = D_800BB4F0;
    v0 = D_8009F198;
    v1 -= 1;
    D_800BB4F0 = v1;
    v0 -= 1;
    D_8009F198 = v0;
    func_80072A18();
    goto end;
alternate:
    if (v0 == 0)
        goto end;
    a0 = 1;
    func_80090D30(a0);
    v1 = D_8009F2F4;
    v0 = D_8009F2F6;
    v1 += v0;
    D_800D0980 = v1;
    a1 = 0x19;
    if (v1 != 0) {
        D_801531D8 = v1;
        a0 = 0xE;
        a2 = 0xB810;
    } else {
        a0 = 0xE;
        a2 = 0xB80F;
    }
    a3 = 0;
    func_800FFF08(a0, a1, a2, a3);
    a0 = (s32) s0;
    func_800735C8((s32 *) a0);
    a0 = 0x48;
    KEEP_NOVOL(a0);
    a1 = 0x20;
    KEEP_NOVOL(a1);
    v0 = 0x48;
    sp.first = v0;
    v0 = 0x20;
    sp.second = v0;
    ((void (*)(s32, s32)) func_80073778)(a0, a1);
    v0 = D_800BB4F0;
    v1 = 0xA;
    a0 = v0 << 2;
    v0 += 1;
    at = (s32 *) ((char *) &D_800D4584[0] + a0);
    *at = v1;
    at = (s32 *) &D_800BB4F0;
    *at = v0;
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80073778);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80073B2C);

extern u16 D_8009F2F8;
extern u16 D_8009F2FA;
extern s32 D_801531DC;

void func_80073EF8(void) {
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_8008FDB4(s32, s32, s32, s32 *);
    extern s32 D_801531D8;
    s32 s1;
    s32 s0;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 *a3;
    s32 v0;
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    WldCoreTempPair sp;

    a0 = 0xE;
    KEEP_NOVOL(a0);
    a1 = 0x19;
    KEEP_NOVOL(a1);
    s1 = D_8009F2F8;
    KEEP_NOVOL(s1);
    a2 = 0xB813;
    KEEP_NOVOL(a2);
    s0 = D_8009F2FA;
    KEEP_NOVOL(s0);
    D_801531D8 = s1;
    D_801531DC = s0;
    func_800FFF08(a0, a1, a2, 0);
    a0 = 0xC;
    KEEP_NOVOL(a0);
    s0 <<= 16;
    a1 = s1 | s0;
    KEEP_NOVOL(a1);
    a2 = 0xB823;
    KEEP_NOVOL(a2);
    v0 = 0x60;
    D_800BB3C0 = v0;
    v0 = 8;
    D_800BB3EC = v0;
    v0 = 0x38;
    sp.first = v0;
    v0 = 0x20;
    sp.second = v0;
    a3 = &sp.first;
    KEEP_WITH_NOVOL(a3, v0);
    D_800D4574 = s1;
    func_8008FDB4(a0, a1, a2, &sp.first);
    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    a0 = v1 << 2;
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = 0;
    v0 = 0xC;
    v1 += 1;
    at = (s32 *) ((char *) &D_800D4584 + a0);
    *at = v0;
    D_800BB4F0 = v1;
}

extern s32 D_800D4578;

void func_80073FF0(void) {
    extern s32 func_800FFEEC(s32);
    extern void func_80074134(s32);
    extern void func_80072A18(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    s0 = (s32 *) a0;
    v0 = *s0;
    if (v0 == 0)
        goto alternate;
    a0 = 0xC;
    v0 = func_800FFEEC(a0);
    if (v0 != 0)
        goto alternate;
    a0 = 1;
    v0 = D_8009F244;
    v1 = D_8009F198;
    D_800BB3C0 = 0;
    D_800BB3EC = a0;
    v0 -= 1;
    D_8009F244 = v0;
    v0 = D_800BB4F0;
    v1 -= 1;
    D_8009F198 = v1;
    v1 = *s0;
    v0 -= 2;
    D_800BB4F0 = v0;
    if (v1 == a0) {
        func_80074134(1);
        goto done;
    }
    func_80072A18(1);
    goto done;
alternate:
    v1 = D_800BC2F0;
    v0 = v1 & 0x40;
    if (v0 == 0)
        goto check20;
    a0 = 2;
    func_80090D30(a0);
    a0 = 0xC;
    a1 = 0;
    a2 = 0;
    a3 = 1;
    v0 = 1;
    D_800D0984 = v0;
    v0 = -1;
    *s0 = v0;
    goto call_common;
check20:
    v0 = v1 & 0x20;
    if (v0 == 0)
        goto done;
    a0 = 1;
    func_80090D30(a0);
    a0 = 0xC;
    a1 = 0;
    a2 = 0;
    a3 = 1;
    v1 = D_800D4574;
    v0 = 1;
    *s0 = v0;
    D_800D4578 = v1;
call_common:
    func_800FFF08(a0, a1, a2, a3);
done:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80074134);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80074788);

extern u8 D_80057CE8;
extern u8 D_80057D24;
extern u8 D_80057EEF;

void func_80074B30(void) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 t0 asm("t0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[2];

    MEMORY_BARRIER();
    v0 = D_80057CE8;
    if (v0 <= 0)
        goto second;
    a0 = (s32) &D_80057EEC;
    a1 = a0 + 2;
    t0 = a0;
    a2 = 0;
    a3 = 0;
loop:
    v0 = *(u8 *) a0;
    v0 &= 4;
    if (v0 != 0)
        goto next;
    v0 = *(u8 *) a1;
    v0 += 1;
    *(u8 *) (t0 + 2) = v0;
    at = (s32) &D_80057EEF;
    at += a3;
    v1 = *(u8 *) at;
    v0 = *(u8 *) a1;
    if (v1 == v0)
        goto set;
    v0 = *(u8 *) a0;
    v0 &= 2;
    if (v0 == 0)
        goto next;
set:
    v0 = *(u8 *) a0;
    v0 |= 4;
    *(u8 *) a0 = v0;
next:
    a0 += 9;
    a1 += 9;
    t0 += 9;
    MEMORY_BARRIER();
    v0 = D_80057CE8;
    a2 += 1;
    v0 = a2 < v0;
    if (v0 == 0)
        goto second;
    a3 += 9;
    goto loop;
second:
    a0 = (s32) &D_80057D24;
    a2 = a0 + 0x60;
second_loop:
    a1 = *(u8 *) a0;
    v1 = a1 & 0x3F;
    if (v1 != 0) {
        v0 = v1 < 0x21;
        if (v0 != 0) {
            v1 -= 1;
        } else {
            v1 = 0x20;
            KEEP_NOVOL(v1);
            v1 -= 1;
        }
        v0 = a1 & 0xC0;
        v0 |= v1;
        *(u8 *) a0 = v0;
    }
    a0 += 1;
    v0 = a0 < a2;
    if (v0 != 0)
        goto second_loop;
}

extern u8 D_80057EF0[];

s32 func_80074C40(s32 arg0) {
    s32 a1;
    s32 a2;
    s32 a3;
    s32 t0;
    s32 v0;
    s32 v1;
    u8 *at;
    s32 pad;

    __asm__ volatile("" : : "m"(pad));
    a2 = 0;
    v0 = D_80057CE8;
    a1 = 0;
    if (v0 > 0) {
        t0 = -1;
        a3 = v0;
        v1 = 0;
loop:
        at = (u8 *) ((char *) &D_80057EEC[0] + v1);
        v0 = *at & 4;
        if (v0 != 0) {
            if (arg0 == t0) {
                a1 += 1;
            } else {
                at = (u8 *) ((char *) &D_80057EF0[0] + v1);
                v0 = *at;
                if (v0 != arg0)
                    goto next;
                a1 += 1;
            }
        }
next:
        a2 += 1;
        v0 = a2 < a3;
        v1 += 9;
        if (v0)
            goto loop;
    }
    v0 = a1;
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80074CD0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80074CD8);

extern s16 D_800D09B8[];

s32 func_800757B8(u8 *arg0) {
    extern u8 *func_80069E38(s32);
    extern s16 D_800BB3F0[];
    volatile s32 pad[2];
    register u8 *s1 asm("s1") = arg0;
    register s32 s0 asm("s0") = 0;
    register s32 *s3 asm("s3") = D_800D09A0;
    register s16 *s2 asm("s2") = D_800BB3F0;
    u8 *p;
    s32 *vp;
    s32 a0;
    s32 a1;
    s32 v0;
    s32 v1;

    KEEP(s1);
    *(s32 *) (s1 + 0x30) = 0;
    do {
        p = func_80069E38(s0);
        if (p[0xD0] == 0 && p[1] != 0xFF && !(p[4] & 0x20) && p[0] >= 0x4A) {
            a1 = D_800D457C;
            if (a1 > 0) {
                a0 = 0;
                vp = s3;
search:
                v0 = *vp;
                if (v0 == s0)
                    goto sdone;
                a0++;
                if (a0 >= a1)
                    goto sdone;
                vp++;
                goto search;
sdone:
                if (a0 < D_800D457C)
                    s2[*(s32 *) (s1 + 0x30)] = 8;
                else
                    s2[*(s32 *) (s1 + 0x30)] = 0;
            } else {
                s2[*(s32 *) (s1 + 0x30)] = 0;
            }
            D_800D0880[*(s32 *) (s1 + 0x30)] = s0 + 0x4000;
            D_800D09B8[*(s32 *) (s1 + 0x30)] = p[0x16];
            *(s32 *) (s1 + 0x30) = *(s32 *) (s1 + 0x30) + 1;
        }
        s0++;
    } while (s0 < 0x10);
    a0 = *(s32 *) (s1 + 0x30);
    s0 = 6;
    if (a0 < 6)
        s0 = a0;
    return s0;
}

extern void func_8010849C(s16, s16, s32);

void func_80075950(void *arg0) {
    register s32 s0 asm("s0");
    register s32 s1 asm("s1") = (s32) &D_800C87D8;
    register s32 s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[6];

    s2 = *(s32 *) ((char *) arg0 + 4);
    a2 = s1;
    v0 = s2;
    v0 <<= 1;
    v0 += s2;
    v0 <<= 2;
    v0 += s2;
    v0 <<= 2;
    at = (s32 *) &D_800BBC9C[0];
    at = (s32 *) ((char *) at + v0);
    a0 = *(s16 *) at;
    at = (s32 *) &D_800BBC9E[0];
    at = (s32 *) ((char *) at + v0);
    a1 = *(s16 *) at;
    __asm__ volatile("" : : "r"(a0), "r"(a1), "r"(a2) : "memory");
    s0 = 0;
    func_8010849C(a0, a1, a2);
    v1 = D_800D457C;
    v0 = 8;
    *(s32 *) ((char *) sp + 0x18) = v0;
    __asm__ volatile("" : : "r"(v0), "r"(v1) : "memory");
    __asm__ volatile(".set\tnoreorder\n\tblez\t$3,.L75950_exit\n\tsw\t$2,0x1c($sp)\n\t.set\treorder" ::: "memory");
    s3 = s1;
    s1 = (s32) &D_800D09A0[0];
loop:
    do {
        a0 = s2;
        a1 = *(s32 *) s1;
        s1 += 4;
        s0 += 1;
        *(s32 *) ((char *) sp + 0x10) = s3;
        USE2(s0, s3);
        a2 = *(s32 *) ((char *) sp + 0x18);
        a3 = *(s32 *) ((char *) sp + 0x1C);
        __asm__ volatile("" : : "r"(a0), "r"(a1), "r"(a2), "r"(a3) : "memory");
        func_8008F828(a0, a1 + 0x4000, a2, a3);
        v0 = *(s32 *) ((char *) sp + 0x1C);
        v1 = D_800D457C;
        v0 += 0x10;
        v1 = s0 < v1;
        *(s32 *) ((char *) sp + 0x1C) = v0;
    } while (v1 != 0);
    __asm__ volatile(".L75950_exit:");
    func_8008F72C(s2, (void *) &D_800C87D8);
}

extern s32 func_80109248(s32);
extern void func_800EAA50(void *, s32);
extern s32 D_800BBC74[];
extern s32 D_800BBC94[];
extern s32 D_800BBC98[];

void func_80075A48(s32 arg0, s32 arg1, s32 arg2) {
    register s32 s0 asm("s0");
    register s32 s2 asm("s2");
    register s32 s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[10];

    s0 = arg2;
    __asm__("" : "=r"(s0), "=r"(a0) : "0"(s0), "1"(arg1));
    s1 = func_80109248(a0);
    a0 = (s32) sp + 0x10;
    func_800EAA50((void *) a0, s1);
    v0 = 0x66666667;
    __asm__ volatile("mult %0,%1" : : "r"(s1), "r"(v0));
    a1 = s1;
    s2 = s1;
    KEEP(s2);
    v0 = s0;
    v0 <<= 1;
    v0 += s0;
    v0 <<= 2;
    v0 += s0;
    a2 = v0 << 2;
    KEEP(a2);
    v0 = s1 >> 31;
    __asm__ volatile("mfhi %0" : "=r"(a3));
    v1 = a3;
    v1 >>= 4;
    v1 -= v0;
    KEEP(v1);
    if (s1 < 0) {
        a1 = s1 + 3;
        goto div_common;
    }
    a0 = v1 << 6;
div_common:
    v0 = a1 >> 2;
    v0 <<= 2;
    v0 = s2 - v0;
    v0 <<= 4;
    v0 += 0x280;
    v0 = a0 + v0;
    at = (s32 *) &D_800BBC90[0];
    at = (s32 *) ((char *) at + a2);
    *at = v0;
    v0 = v1 << 2;
    v0 += v1;
    v0 <<= 3;
    v0 = s2 - v0;
    if (v0 < 0)
        v0 += 3;
    v0 >>= 2;
    v0 += 0x1F0;
    at = (s32 *) &D_800BBC94[0];
    at = (s32 *) ((char *) at + a2);
    *at = v0;
    v0 = *(u16 *) ((char *) sp + 0x26);
    at = (s32 *) &D_800BBC74[0];
    at = (s32 *) ((char *) at + a2);
    *at = v0;
    a0 = (s32) &D_800BBC98[0];
    a1 = a2 + a0;
    v0 = *(u8 *) ((char *) sp + 0x1C);
    *(u16 *) (a1 + 0) = (u16) v0;
    v0 = *(u8 *) ((char *) sp + 0x1D);
    *(u16 *) (a1 + 2) = (u16) v0;
    v0 = *(u8 *) ((char *) sp + 0x24);
    v1 = *(u8 *) ((char *) sp + 0x1C);
    a0 += 8;
    v0 -= v1;
    *(u16 *) (a1 + 4) = (u16) v0;
    v0 = *(u8 *) ((char *) sp + 0x2D);
    v1 = *(u8 *) ((char *) sp + 0x1D);
    a0 = a2 + a0;
    v0 -= v1;
    *(u16 *) (a1 + 6) = (u16) v0;
    v0 = 0x80;
    *(u8 *) (a0 + 0) = (u8) v0;
    *(u8 *) (a0 + 1) = (u8) v0;
    *(u8 *) (a0 + 2) = (u8) v0;
    at = (s32 *) &D_800BBC70[0];
    at = (s32 *) ((char *) at + a2);
    v0 = *at;
    v1 = -0x11;
    at = (s32 *) &D_800BBC80[0];
    at = (s32 *) ((char *) at + a2);
    *at = 0;
    v0 &= v1;
    at = (s32 *) &D_800BBC70[0];
    at = (s32 *) ((char *) at + a2);
    *at = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80075BD8);

extern void func_80087254();
extern s32 D_8009EBC0;
extern s32 D_8009EBC4;
extern s32 D_8009EBD8;
extern s32 D_8009EBEC;
extern s32 D_8010D0CC;
extern s32 D_80111070;
extern s32 D_80111EC4;

void func_80075F50(void) {
    extern void func_800FFF08(s32, s32, s32, s32);
    s32 *s0;
    s32 *s1;
    s32 *s2;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 v0;
    s32 v1;
    s32 *at;

    func_80087254();
    a0 = 8;
    KEEP_NOVOL(a0);
    a1 = (s32) &D_8010D0CC;
    s2 = &D_8009EBEC;
    s1 = &D_8009EBD8;
    s0 = &D_8009EBC0;
    *s2 = 0;
    *s1 = 0;
    D_8009EBC4 = 0;
    *s0 = 0;
    func_800FFD70(a0, (void *) a1);
    func_800FFF08(8, (void *) s0, 0, 0);
    func_800FFD70(0xC, (void *) &D_80111EC4);
    func_800FFF08(0xC, (void *) (s1 - 1), 0, 0);
    func_800FFD70(9, (void *) &D_80111070);
    func_800FFF08(9, (void *) (s2 - 1), 0, 0);
    v0 = D_8004D950;
    v1 = 0x20000;
    v0 |= v1;
    D_8004D950 = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80076034);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80076744);

void func_80076840(volatile s32 *arg0) {
    s32 v0;
    s32 v1;
    register s32 *at asm("at");
    s32 local;

    __asm__ volatile("" : : "m"(local));
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v1 = arg0[16];
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB518[0] + v0);
    *at = 0;
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB518[0] + v0);
    *at = 0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8007688C);

extern u8 D_800BBCA2[];

void func_80076998(void) {
    s32 v0;
    s32 v1;
    u8 *at;
    s32 local;
    s32 local2;

    __asm__ volatile("" : : "m"(local), "m"(local2));
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = 0x70;
    at = (u8 *) ((char *) &D_800BBCA2[0] + v0);
    *at = v1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_800769D0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80077174);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8007717C);

void func_8007756C(void) {
    D_800BB3C0 = 0x160;
    func_800FFF08(0xE, 0x19, 0xB819, 0);
}

s32 func_800775A4(void) {
    return D_800BB3C0 = -1;
}

void func_800775B8(s32 arg0) {
    extern s32 D_801531D8;
    extern s32 func_800FFEEC(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_8008FD88(s32);
    extern void func_8008FC88(s32);
    extern void func_8006E860(s32, s32);
    extern void func_80073778(s32, s32, s32, s32, s32, s32);
    extern void func_80079184(s32);
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *s0 asm("s0");
    register s32 *s1 asm("s1");
    register s32 *at asm("at");
    register s32 a0 asm("a0");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");

    v0 = D_8004D950;
    s1 = arg0;
    v0 &= 4;
    if (v0 != 0) {
        if (func_800FFEEC(0xC) == 0) {
            v0 = 1;
            D_800BB3EC = v0;
            v0 = D_8004D950;
            v1 = D_800BB4F0;
            D_800BB3C0 = 0;
            v0 ^= 4;
            v1 -= 1;
            D_8004D950 = v0;
            D_800BB4F0 = v1;
            func_8006C44C();
            goto epi;
        }
    }
    v1 = D_800BC2F0;
    v0 = v1 & 0x40;
    if (v0 != 0) {
        MEMORY_BARRIER();
        ((void (*)(s32)) func_80090D30)(2);
        func_8008FD88(4);
        D_8004D950 |= 4;
        func_800FFF08(0xC, 0, 0, 1);
    } else {
        v0 = v1 & 0x100;
        if (v0 != 0) {
            ((void (*)(s32)) func_800775A4)(s1);
            func_8006E860(0x1061, 1);
        } else {
            v0 = v1 & 0x20;
            if (v0 != 0) {
                ((void (*)(s32)) func_80090D30)(1);
                ((void (*)(s32)) func_800775A4)(s1);
                s0 = (s32 *) &D_800BB354;
                func_80079184(*(s32 *) ((char *) s1 + *(s16 *) s0 * 4 + 0x34));
                func_8008FC88(4);
                a2 = 0xB81A;
                a3 = 0;
                D_801531D8 = D_800D0880[*(s16 *) s0];
                func_800FFF08(0xE, 0x19, a2, a3);
                func_80073778(0x48, 0x20, a2, a3, 0x48, 0x20);
                a0 = D_800BB4F0;
                v0 = 0xF;
                v1 = a0 << 2;
                at = (s32 *) ((char *) &D_800D4584[0] + v1);
                *at = v0;
                v0 = a0 + 1;
                D_800BB4F0 = v0;
                v0 = a0 << 1;
                v0 += a0;
                v0 <<= 3;
                v1 = *(s16 *) s0;
                v0 -= a0;
                v1 = v1 * 4;
                v1 = v1 + (s32) (char *) s1;
                v1 = *(s32 *) ((char *) v1 + 0x34);
                v0 <<= 2;
                at = (s32 *) ((char *) &D_800BB99C + v0);
                *at = v1;
            }
        }
    }
epi:
    return;
}

struct rec777C4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern s32 func_80069010(s32);
extern void func_800779D0(s32, s32);

void func_800777C4(struct rec777C4 *arg0) {
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_t;
    s32 temp_v0;
    s32 temp_v1;

    if (!(*(s32 *) ((u8 *) D_800BBC70 + (arg0->unk4 * 0x34)) & 0x100)) {
        if (D_800BC2F0 & 0x40) {
            func_80090D30(2);
        } else {
            goto mid;
        }
tail:
        D_8009F180 -= 2;
        D_8009F244 -= 1;
        D_8009F198 -= 3;
        D_800BB4F0 -= 1;
        func_8006C44C();
        return;
    }
    return;
mid:
    if ((func_80069010(0x1000) != 0) || (func_80069010(0x4000) != 0)) {
        temp_v1 = arg0->unk8;
        temp_v0 = arg0->unk0;
        temp_v1 = temp_v1 ^ 1;
        temp_a2 = temp_v0 * 0x24;
        temp_a1 = arg0->unk4;
        temp_v0 = temp_a1 * 0x34;
        arg0->unk8 = temp_v1;
        temp_t = (temp_v1 * 0x10) + 0xE;
        temp_v0 = *(s32 *) ((u8 *) D_800BBC8C + temp_v0);
        temp_v0 = temp_v0 + temp_t;
        *(s32 *) ((u8 *) D_800BB520 + temp_a2) = temp_v0;
        func_80090D30(3, temp_a1, temp_a2);
        return;
    }
    if (D_800BC2F0 & 0x20) {
        func_80090D30(1);
        if (arg0->unk8 != 0) {
            goto tail;
        }
        func_800FFF08(0xC, 0, 0, 1);
        D_8009F180 -= 2;
        D_8009F244 -= 1;
        D_8009F198 -= 3;
        D_800BB4F0 -= 2;
        ((void (*)(s32)) func_800779D0)(arg0->unk10);
    }
}

extern s32 D_8009F20C;
extern s32 D_800BB9B8;

void func_800779D0(s32 arg0, s32 unused) {
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB998;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");

    a2 = D_800BB4F0;
    MEMORY_BARRIER();
    v0 = a2 - 1;
    a1 = v0 * 92;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + a1);
    v0 = *at;
    v1 = v0 * 36;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    at = (s32 *) &D_800BB990;
    at = (s32 *) ((char *) at + a1);
    v0 = *at;
    v1 = v0 * 36;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    at = (s32 *) &D_800BB994;
    at = (s32 *) ((char *) at + a1);
    v0 = *at;
    v1 = v0 * 52;
    v0 = a2;
    v0 <<= 1;
    v0 += a2;
    v0 <<= 3;
    v0 -= a2;
    a2 = v0 << 2;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    a1 = -1;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + a2);
    *at = a1;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    MEMORY_BARRIER();
    v0 = 1;
    at = (s32 *) &D_800BB9B8;
    at = (s32 *) ((char *) at + a2);
    *at = a0;
    at = (s32 *) &D_800BB990;
    at = (s32 *) ((char *) at + a2);
    *at = 0;
    at = (s32 *) &D_800BB998;
    at = (s32 *) ((char *) at + a2);
    *at = v0;
    at = (s32 *) &D_800BB99C;
    at = (s32 *) ((char *) at + a2);
    *at = a1;
    v1 = D_8009F20C;
    v0 = 9;
    D_800BB3EC = v0;
    if (v1 != 0) {
        v0 = 0x63;
        at = (s32 *) &D_800BB98C;
        at = (s32 *) ((char *) at + a2);
        *at = v0;
        a0 = 0xE;
        goto common;
    }
    func_80091174(0x223, -1, a2);
    a0 = 0xE;
common:
    a1 = 0;
    a2 = -1;
    func_800FFF08(a0, a1, a2, 0);
    v0 = D_800BB4F0;
    v1 = 0x10;
    a0 = v0 << 2;
    v0 += 1;
    at = (s32 *) &D_800D4584;
    at = (s32 *) ((char *) at + a0);
    *at = v1;
    D_800BB4F0 = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80077BCC);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_800785DC);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80078BB8);

extern s32 D_8009F1F8;
extern u8 D_80057EED;
extern s32 D_8009F1EC;
extern s16 D_8009F2EC;
extern void func_80079844();
extern void func_80079E14();
extern void func_8007A148();

void func_80079184(s32 arg0) {
    extern void func_80069934(s16 *, s32);
    extern s32 func_8007920C(s32);
    extern void func_80079C6C();
    s32 s0;
    s32 a0;
    s32 a1;
    s32 v0;
    s32 *at;

    s0 = arg0;
    v0 = s0 << 3;
    v0 += s0;
    at = (s32 *) ((char *) &D_80057EED + v0);
    a1 = *(u8 *) at;
    a0 = (s32) &D_8009F2EC;
    func_80069934((s16 *) a0, a1);
    a0 = s0;
    D_8009F1F8 = a0;
    v0 = func_8007920C(a0);
    D_8009F1EC = v0;
    func_80079844();
    func_80079C6C();
    func_80079E14();
    func_8007A148();
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8007920C);

s32 func_800793F0(s32 arg0, s32 arg1) {
    extern u8 *func_80069E38(s32);
    extern s32 func_80069918(s32);
    register s32 s0 asm("s0");
    s32 s1;
    s32 s2;
    register s32 s3 asm("s3");
    register s32 a0 asm("a0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s3 = arg0;
    a0 = arg1;
    a0 = (s32) func_80069E38(a0);
    v1 = *(u8 *) (a0 + 0x17);
    if (v1 < 0x65U)
        s2 = 2;
    if (v1 < 0x42U)
        s2 = 1;
    v0 = v1 < 0x24U;
    if (v0 != 0)
        s2 = 0;
    v1 = *(u8 *) (a0 + 0x18);
    if (v1 < 0x65U)
        s1 = 2;
    if (v1 < 0x42U)
        s1 = 1;
    v0 = v1 < 0x24U;
    if (v0 != 0)
        s1 = 0;
    s0 = *(u8 *) (a0 + 4);
    s0 &= 0x80;
    s0 = (s0 == 0);
    v0 = (s32) func_80069918(2);
    v1 = s1 << 1;
    v1 += s1;
    v1 += s2;
    v0 = v0 + v1;
    KEEP_NOVOL(v0);
    v1 = *(u8 *) v0;
    KEEP_NOVOL(s0);
    v0 = s0 << 1;
    v0 = v0 + s0;
    v1 = s3 + v1;
    v0 = v1 + v0;
    return v0;
}

s32 func_800794D0(s32 *arg0, s32 arg1) {
    extern s32 func_800FFEEC(s32);
    extern s32 func_80109248(s32);
    extern void func_800EF25C(s32, s32);
    extern s32 func_800793F0(s32, s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 func_80106808();
    extern s32 D_801531D8;
    s32 s0;
    s32 s1;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 v0;
    s32 v1;

    s0 = (s32) arg0;
    s1 = arg1;
    v0 = arg0[1];
    if (v0 != 0)
        goto second;
    v0 = 1;
    arg0[1] = v0;
    a0 = 0xE;
    v0 = func_800FFEEC(a0);
    if (v0 == 0) {
        a0 = 0xE;
        a1 = (s32) &D_8010F250;
        func_800FFD70(a0, (void *) a1);
    }
    s0 = (s32) &D_8009F1EC;
    a0 = *(s32 *) s0;
    v0 = a0 + 0x4000;
    D_801531D8 = v0;
    v0 = func_80109248(a0);
    func_800EF25C(0x5A, v0);
    a0 = s1;
    a1 = *(s32 *) s0;
    v0 = func_800793F0(a0, a1);
    a0 = 0xE;
    a1 = 0x19;
    a2 = v0 + 0x8800;
    a3 = 0;
    func_800FFF08(a0, a1, a2, a3);
    return 0;
second:
    v0 = D_800BC2F0;
    v0 &= 0x20;
    if (v0 == 0)
        return 0;
    v0 = func_80106808();
    if (v0 == 0)
        return 0;
    v0 = 1;
    arg0[1] = 0;
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_800795C4);

s32 func_80079820(s32 arg0) {
    s32 v0;

    if (arg0 < 0x4A) {
        v0 = 0x16;
        goto epi;
    }
    v0 = 0x16;
    if (arg0 < 0x5E) {
        v0 = arg0 - 0x4A;
        goto epi;
    }
    v0 = arg0 - 0x4A;
    v0 = 0x15;
epi:
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80079844);

extern u8 D_80057EF1[];

void func_80079C6C(void) {
    register s32 *s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 v0 asm("v0");
    volatile s32 pad[4];

    s0 = &D_8009F20C;
    MEMORY_BARRIER();
    v0 = *(s32 *) s0;
    if (v0 == 0) {
        func_80069918(8);
        __asm__ volatile(".set\tnoreorder\n"
                         "\tori\t$4,$0,9\n"
                         "\tjal\tfunc_80069918\n"
                         "\taddu\t$17,$2,$0\n"
                         "\tlui\t$4,%%hi(D_8009F1F8)\n"
                         "\tlw\t$4,%%lo(D_8009F1F8)($4)\n"
                         "\taddu\t$7,$0,$0\n"
                         "\tsll\t$3,$4,3\n"
                         "\taddu\t$3,$3,$4\n"
                         "\tlui\t$at,%%hi(D_80057EF1)\n"
                         "\taddiu\t$at,$at,%%lo(D_80057EF1)\n"
                         "\taddu\t$at,$at,$3\n"
                         "\tlbu\t$10,0($at)\n"
                         "\tnop\n"
                         "\tbeqz\t$10,WLDC1\n"
                         "\taddu\t$15,$2,$0\n"
                         "\t.set\treorder" : "=r"(s1) : : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10",
                                                          "$11", "$12", "$13", "$14", "$15", "$24", "at", "hi", "lo", "ra", "memory");
        __asm__ volatile(".set\tnoreorder\n"
                         "\tlui\t$14,%%hi(D_8009F2FE)\n"
                         "\taddiu\t$14,$14,%%lo(D_8009F2FE)\n"
                         "\taddiu\t$13,$16,-0x10\n"
                         "\tori\t$12,$0,1\n"
                         "\tlui\t$9,0x6666\n"
                         "\tori\t$9,$9,0x6667\n"
                         "\tori\t$11,$0,2\n"
                         "\taddiu\t$6,$16,0x14\n"
                         "\taddiu\t$8,$16,0x20\n"
                         "1:\n"
                         "\tlhu\t$2,0($14)\n"
                         "\tlw\t$5,0($13)\n"
                         "\tsll\t$2,$2,1\n"
                         "\taddu\t$2,$2,$17\n"
                         "\tlhu\t$4,-2($2)\n"
                         "\tbne\t$5,$12,2f\n"
                         "\tmult\t$4,$9\n"
                         "\tsra\t$2,$4,31\n"
                         "\tmfhi\t$24\n"
                         "\tsra\t$3,$24,2\n"
                         "\tsubu\t$4,$3,$2\n"
                         "2:\n"
                         "\tbne\t$5,$11,3f\n"
                         "\tmult\t$4,$9\n"
                         "\tsra\t$2,$4,31\n"
                         "\tmfhi\t$24\n"
                         "\tsra\t$3,$24,3\n"
                         "\tsubu\t$4,$3,$2\n"
                         "3:\n"
                         "\tsw\t$4,0($6)\n"
                         "\tlw\t$2,0($8)\n"
                         "\taddiu\t$8,$8,4\n"
                         "\taddiu\t$7,$7,1\n"
                         "\taddu\t$2,$4,$2\n"
                         "\tsw\t$2,0($6)\n"
                         "\tslt\t$2,$7,$10\n"
                         "\tbnez\t$2,1b\n"
                         "\taddiu\t$6,$6,4\n"
                         "\t.set\treorder" : : : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11",
                                                 "$12", "$13", "$14", "$24", "at", "hi", "lo", "memory");
        __asm__ volatile("WLDC1:");
        __asm__ volatile(".set\tnoreorder\n"
                         "\tbeqz\t$10,WLDC2\n"
                         "\taddu\t$7,$0,$0\n"
                         "\tlui\t$14,%%hi(D_8009F304)\n"
                         "\taddiu\t$14,$14,%%lo(D_8009F304)\n"
                         "\tori\t$13,$0,1\n"
                         "\tlui\t$9,0x6666\n"
                         "\tori\t$9,$9,0x6667\n"
                         "\tori\t$12,$0,2\n"
                         "\tlui\t$11,%%hi(D_8009F1FC)\n"
                         "\taddiu\t$11,$11,%%lo(D_8009F1FC)\n"
                         "\taddiu\t$6,$11,0x3C\n"
                         "\taddiu\t$8,$11,0x30\n"
                         "1:\n"
                         "\tlhu\t$2,0($14)\n"
                         "\tlw\t$5,0($11)\n"
                         "\tsll\t$2,$2,1\n"
                         "\taddu\t$2,$2,$15\n"
                         "\tlhu\t$4,-2($2)\n"
                         "\tbne\t$5,$13,2f\n"
                         "\tmult\t$4,$9\n"
                         "\tsra\t$2,$4,31\n"
                         "\tmfhi\t$24\n"
                         "\tsra\t$3,$24,1\n"
                         "\tsubu\t$4,$3,$2\n"
                         "2:\n"
                         "\tbne\t$5,$12,3f\n"
                         "\tmult\t$4,$9\n"
                         "\tsra\t$2,$4,31\n"
                         "\tmfhi\t$24\n"
                         "\tsra\t$3,$24,3\n"
                         "\tsubu\t$4,$3,$2\n"
                         "3:\n"
                         "\tsw\t$4,0($6)\n"
                         "\tlw\t$2,0($8)\n"
                         "\taddiu\t$8,$8,4\n"
                         "\taddiu\t$7,$7,1\n"
                         "\taddu\t$2,$4,$2\n"
                         "\tsw\t$2,0($6)\n"
                         "\tslt\t$2,$7,$10\n"
                         "\tbnez\t$2,1b\n"
                         "\taddiu\t$6,$6,4\n"
                         "\t.set\treorder" : : : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11",
                                                 "$12", "$13", "$14", "$24", "at", "hi", "lo", "memory");
    }
    __asm__ volatile("WLDC2:");
    return;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_80079E14);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8007A148);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8007A2A8);

extern s32 D_8009F200;

void func_8007A508(void) {
    extern s32 func_8007A72C();
    extern s32 func_800FFEEC(s32, s32);
    extern s32 D_800BB990;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v0 = func_8007A72C();
    a1 = v0;
    v1 = D_8009F200;
    v0 = 1;
    if (v1 != v0)
        goto alternate;
    v0 = D_800BB4F0;
    v1 = v0 * 0x5C;
    v0 = 0xB8F9;
    goto store;
alternate:
    v0 = D_800BB4F0;
    v1 = v0 * 0x5C;
    v0 = 0xB904;
store:
    *(s32 *) ((char *) &D_800BB98C + v1) = v0;
    a0 = 1;
    if (a1 == a0) {
        v0 = D_800BB4F0;
        v1 = v0 * 0x5C;
        v0 = 4;
        *(s32 *) ((char *) &D_800BB990 + v1) = v0;
    } else {
        v0 = D_800BB4F0;
        v1 = v0 * 0x5C;
        v0 = *(s32 *) ((char *) &D_800BB98C + v1);
        *(s32 *) ((char *) &D_800BB990 + v1) = a0;
        v0 += 2;
        v0 += a1;
        *(s32 *) ((char *) &D_800BB98C + v1) = v0;
    }
    a0 = 0xE;
    v0 = func_800FFEEC(a0, a1);
    if (v0 == 0) {
        a0 = 0xE;
        a1 = (s32) &D_8010F250;
        func_800FFD70(a0, a1);
    }
    v0 = D_800BB4F0;
    a0 = v0 * 0x5C;
    v0 = (s32) &D_800BB98C;
    a0 += v0;
    func_8007A6B8((void *) a0);
    v0 = D_800BB4F0;
    a0 = v0 << 2;
    v1 = 0x37;
    v0 += 1;
    *(s32 *) ((char *) &D_800D4584 + a0) = v1;
    D_800BB4F0 = v0;
}

void func_8007A6B8(s32 *arg0) {
    extern void func_800FFF08();
    extern void func_80090D50(s32, s32);
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s0 = arg0;
    a0 = 0xE;
    a1 = 0x19;
    a2 = s0[0];
    a3 = 0;
    func_800FFF08(a0, a1, a2, a3);
    v0 = s0[0];
    v1 = s0[1];
    v0 += 1;
    v1 -= 1;
    s0[0] = v0;
    s0[1] = v1;
    if (v1 != 0)
        goto notzero;
    a0 = 2;
    a1 = 4;
    func_80090D50(a0, a1);
    v0 = 1;
    s0[2] = v0;
    s0[3] = 0;
    goto epi;
notzero:
    s0[2] = 0;
epi:
    return;
}

extern u8 D_8009EB34[];
extern u8 D_8009EB3C[];
extern s32 D_8009F1FC;

s32 func_8007A72C(s32 arg0) {
    s32 v0;
    s32 v1;
    s32 a0 = arg0;
    s32 i;
    s32 n;
    v0 = D_8009F1FC;

    if (v0 != 0) {
        return 0;
    }
    v1 = D_8009F200;
    v0 = v1 - 1;
    if ((u32) v0 >= 2U) {
        return 0;
    }
    v0 = 1;
    if (v1 == v0) {
        n = 0;
        i = 0;
        do {
            if (func_800EF1A8(i + 0x321) != 0) {
                n += 1;
            }
            KEEP(n);
            i += 1;
        } while (i < 0x1F);
        for (i = 0; i < 8; i++) {
            if (D_8009EB34[i] == n) {
                break;
            }
        }
        if (i == 8) {
            return 0;
        }
        a0 = i;
        v1 = D_8009F200;
    }
    v0 = 2;
second:
    if (v1 != v0) {
        return a0 + 1;
    }
    n = 0;
    i = 0;
    do {
        if (func_800EF1A8(i + 0x350) != 0) {
            n += 1;
        }
        KEEP(n);
        i += 1;
    } while (i < 0x10);
    for (i = 0; i < 8; i++) {
        if (D_8009EB3C[i] == n) {
            break;
        }
    }
    if (i != 8) {
        a0 = i;
        goto found;
    }
    v0 = 0;
    return v0;
found:
    KEEP(a0);
    v0 = a0 + 1;
    return v0;
}

extern s32 D_800D4624;
extern s32 D_800D462C;

void func_8007A86C(s32 *arg0) {
    extern void func_80077174(s32);
    extern s32 func_80106808(s32);
    extern void func_80090D50(s32, s32);
    register s32 *s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s0 = arg0;
    v1 = s0[2];
    USE(v1);
    a0 = 3;
    if (v1 != a0)
        goto not3;
    v0 = D_800D462C;
    if (v0 != 0)
        goto epi;
    v0 = D_800D4624;
    if (v0 != 0)
        goto epi;
    v0 = D_800BB4F0;
    v0 -= 1;
    D_800BB4F0 = v0;
    func_80077174(3);
    goto epi;
not3:
    if (v1 != 2)
        goto not2;
    v0 = s0[3];
    v1 = v0 + 1;
    s0[3] = v1;
    __asm__ volatile("" : : "m"(s0[3]));
    v0 = D_800D462C;
    if (v0 != 0)
        goto epi;
    v0 = D_800D4624;
    if (v0 != 0)
        goto epi;
    v0 = v1 < 0xB4;
    if (v0 != 0)
        goto epi;
    s0[2] = 3;
    a1 = 0x10;
    func_80090D50(2, a1);
    a0 = 1;
    a1 = 0x221;
    func_80090D50(a0, a1);
    a0 = 3;
    a1 = 0x10;
    func_80090D50(a0, a1);
    goto epi;
not2:
    if (v1 != 1)
        goto other;
    v0 = func_80106808(3);
    if (v0 == 0)
        goto epi;
    v0 = D_800D4624;
    if (v0 != 0)
        goto epi;
    v0 = D_800D462C;
    if (v0 != 0)
        goto epi;
    a0 = 1;
    a1 = 0x214;
    func_80090D50(a0, a1);
    a0 = 3;
    a1 = 0x10;
    func_80090D50(a0, a1);
    s0[2] = 2;
    goto epi;
other:
    v0 = D_800BC2F0;
    v0 &= 0x20;
    if (v0 == 0)
        goto epi;
    a0 = (s32) s0;
    func_8007A6B8(s0);
epi:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_2", func_8007A9EC);

void func_8007ADA4(void) {
    D_800BB3C0 = 0x160;
    func_800FFF08(0xE, 0x19, 0xB81B, 0);
}

s32 func_8007ADDC(void) {
    return D_800BB3C0 = -1;
}

void func_8007ADF0(s32 *arg0) {
    register s32 v0 asm("v0");
    extern s16 D_800BB3F0[];
    extern s32 func_800FFEEC();
    extern s32 func_8007ADDC();
    extern void func_8007AF9C(s32);
    extern void func_8006E860(s32, s32);
    extern void func_8008FC88(s32);
    extern void func_8008FD88(s32);
    extern void func_800FFF08();
    register s32 e asm("v0");
    s32 *s0 = arg0;
    register s32 w0 asm("v0");
    register s32 w1 asm("v1");
    register s32 a0 asm("a0");
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    volatile s32 pad[2];
    v0 = D_8004D950;
    if ((e & 4) == 0)
        goto els;
    if (func_800FFEEC(0xC) != 0)
        goto els;
    w0 = 1;
    w1 = D_8004D950;
    D_800BB3EC = w0;
    w0 = D_800BB4F0;
    D_800BB3C0 = 0;
    D_8004D950 = w1 ^ 4;
    w1 = s0[0];
    D_800BB4F0 = w0 - 1;
    if (w1 != 0) {
        s16 h;
        h = D_800BB354;
        w0 = h;
        w0 <<= 2;
        w0 += (s32) s0;
        a0 = *(s32 *) (w0 + 0x34);
        func_8007AF9C(a0);
    } else {
        func_8006C44C();
    }
    goto epi;
els:
    w1 = D_800BC2F0;
    w0 = w1 & 0x40;
    if (w0 == 0)
        goto e2;
    func_80090D30(2);
    s0[0] = 0;
    func_8008FD88(5);
    c0 = 0xC;
    goto fjoin;
e2:
    w0 = w1 & 0x100;
    if (w0 == 0)
        goto e3;
    ((s32 (*)(s32 *)) func_8007ADDC)(s0);
    func_8006E860(0x1062, 1);
    goto epi;
e3:
    w0 = w1 & 0x20;
    if (w0 == 0)
        goto epi;
    w0 = D_800BB354;
    w0 <<= 1;
    w0 = *(s16 *) ((char *) &D_800BB3F0[0] + w0);
    if (w0 != 0) {
        func_80090D30(5);
        c0 = 0xE;
        c1 = 0x19;
        c2 = 0xB81C;
        c3 = 0;
        goto call;
    }
    func_80090D30(1);
    s0[0] = 1;
    func_8008FC88(5);
    c0 = 0xC;
fjoin:
    c1 = 0;
    c2 = 0;
    c3 = 1;
    D_8004D950 |= 4;
call:
    func_800FFF08(c0, c1, c2, c3);
epi:;
}
