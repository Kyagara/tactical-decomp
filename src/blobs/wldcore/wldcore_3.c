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
extern void func_80068B3C();
extern s16 D_800D486C;
extern s32 D_800D3CB8[];
extern s32 D_800BBC88[];
extern s32 D_8009EF80[];
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
extern void func_8008E540();
extern void func_8008CB8C();
extern void func_8008D514();
extern void func_8008F284();
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
extern s32 D_800BC2F0;
extern s32 D_800D0AB8;
extern void func_80090D50(s32 arg0, s32 arg1);
extern s32 func_8006AC08();
extern s32 func_8006AC98();
extern s32 D_800BB50C[];
extern s32 D_800BBC78[];
extern s32 D_800BBC90[];
extern s32 D_800BBC80[];
extern s32 D_800D09AC;
extern s32 D_8009F27C;
extern s32 D_8009F280;
extern s32 D_800BB3EC;
extern s32 D_800BB98C[];
extern s32 D_800D4580[];
extern s32 D_800BB99C;
extern s32 D_800D0984;
extern s32 D_800D4644;
extern s32 D_800D4668;
extern s32 D_800D0AF8;
extern s32 D_8009F24C;
extern void func_8008D9A0();
extern s32 func_80068BC4(s32 arg0);
extern void func_80069400(s32 arg0, s32 arg1);
extern u8 *func_80069E38(s32 arg0);
extern void func_80069F04(s32 arg0, s32 arg1, void *arg2);
extern s32 D_8009EEFC;
extern s32 D_8009EF2C;
extern s32 D_8009EF3C;
extern s32 D_800E4D9C;
extern s32 D_800459BC;
extern s32 D_800459C0;
extern s32 D_800459C4;
extern s32 D_800D09B0;
extern s32 D_800D09B4;
extern s32 D_800BBC8C[];
extern s32 func_8006B548();
extern s32 D_800C87D8;
extern void func_80106A28(s32, s32, s32);
extern void func_800FFF08();
extern s16 D_800BB354;
extern void func_8010849C(s16, s16, s32);
extern s32 D_800BBC74[];
extern s32 D_800BBC98[];
extern void func_80087254();
extern s32 D_800D4624;
extern s32 D_800D462C;
extern void func_8006E860(s32 arg0, s32 arg1);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007AF9C);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007B4E0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007B7D4);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007BAB8);

extern s16 D_800D485A;
extern s16 D_800D485C;

void func_8007C008(void *arg0) {
    extern void func_800686C8();
    extern void func_800FFDF4(s32);
    extern u16 D_800D484C;
    register s32 *at asm("at");

    s32 v1;
    s32 v0;
    s32 a0;
    s32 *s0;
    s0 = (s32 *) arg0;
    KEEP_NOVOL(s0);
    a0 = D_800D485A;
    if (a0 != -1) {
        func_80068B3C((s16) a0);
        func_800686C8();
    }
    v1 = D_800D485C;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    a0 = -9;
    v1 &= a0;
    at = (s32 *) D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    v0 = D_800D484C;
    v0 &= 0x40;
    if (v0 == 0)
        goto end;
    a0 = -17;
    v0 = s0[0];
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 &= a0;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    v0 = s0[1];
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 &= a0;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
end:
    a0 = 0xE;
    func_800FFDF4(a0);
}

void func_8007C12C(void) {
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007C134);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007C88C);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007CCA8);

void func_8007CD3C(void) {
    s32 v0;
    s32 v1;
    s32 *at;
    s32 local;

    __asm__ volatile("" : : "m"(local));
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB514[0] + v0);
    *at = 0;
    at = (s32 *) ((char *) &D_800BB510[0] + v0);
    *at = 0;
}

void func_8007CD78(s32 *arg0) {
    s32 v0;
    register s32 *at asm("at");

    at = (s32 *) ((char *) D_800BB518 + ((arg0[0] * 9) << 2));
    *at = 0xA;
    at = (s32 *) ((char *) D_800BB518 + ((arg0[1] * 9) << 2));
    *at = 6;
    at = (s32 *) ((char *) D_800BBC84 + ((arg0[2] * 13) << 2));
    *at = 2;
    at = (s32 *) ((char *) D_800BB508 + ((arg0[0] * 9) << 2));
    *at = 0;
    v0 = arg0[0] * 9;
    at = (s32 *) ((char *) D_800BB514 + (v0 << 2));
    *at = 0;
    at = (s32 *) ((char *) D_800BB510 + (v0 << 2));
    *at = 0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007CE58);

extern s32 D_800D4900;
extern s32 D_800D4904;
extern s32 D_8009F2B0;
extern s32 D_8009F2B4;
extern s32 D_800BB4F4;

void func_8007D38C(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 g;

    a = D_800D4900;
    b = D_800D4904;
    D_8009F2B0 = a;
    D_8009F2B4 = b;
    MEMORY_BARRIER();
    D_800D0984 = 2;
    D_800BB4F4 = 1;
    MEMORY_BARRIER();
    c = D_8004D950;
    d = D_800459C4;
    e = D_800459C0;
    g = D_800459BC;
    D_8004D950 = c | 0x800;
    D_800D09AC = d;
    D_800D09B0 = e;
    D_800D09B4 = g;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007D410);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007D948);

void func_8007DF84(s32 *arg0, s32 arg1) {
    extern void func_8008AEA0(s32, s32);
    register s32 *a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a0 = arg0;
    a1 = arg1;
    v0 = a0[7];
    a1 += v0;
    KEEP(a1);
    a1 *= 4;
    a1 += (s32) a0;
    v1 = *(s32 *) a1;
    if (v1 != -1) {
        func_8008AEA0(a0[2], v1 + 0x8800);
    }
}

void func_8007DFCC(void) {
    extern s32 func_800EF1A8(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s16 D_800BB3F0[];
    register s32 s0 asm("s0");
    register s16 *s1 asm("s1");
    register s16 *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");

    s3 = 0;
    s0 = 0;
    s2 = D_800BB3F0;
    s1 = D_800D0880;
loop:
    a0 = s0 + 0x350;
    v0 = func_800EF1A8(a0);
    if (v0 != 0) {
        v0 = s0 - 0x2800;
        *s1 = v0;
        *s2 = 0;
        s2 += 1;
        s1 += 1;
        s3 += 1;
    }
    s0 += 1;
    v0 = s0 < 0x10;
    if (v0 != 0)
        goto loop;
    a0 = 0xE;
    a1 = 0x19;
    a2 = 0xB848;
    a3 = 0;
    func_800FFF08(a0, a1, a2, a3);
    v0 = D_800BB4F0;
    v1 = v0 << 1;
    v1 += v0;
    v1 <<= 3;
    v1 -= v0;
    v1 <<= 2;
    v0 = s3 < 8;
    at = (s32 *) D_800BB9BC;
    at = (s32 *) ((char *) at + v1);
    *at = s3;
    s0 = 0;
    s0 |= 8;
    if (v0 == 0)
        goto count;
    s0 = s3;
    goto common;
count:
common:
    a0 = 7;
    KEEP_NOVOL(a0);
    a1 = s3;
    a2 = s0;
    func_8008FCC8(a0, a1, a2, a3, 0x60, a2, 0x80, 0x50);
    a0 = 0xC;
    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) D_800BB9BC;
    at = (s32 *) ((char *) at + v0);
    a1 = *at;
    func_8008FAD8(a0, a1, (s32 *) ((char *) sp + 16), (s32 *) ((char *) sp + 24));
    v1 = D_800BB4F0;
    v0 = 0x160;
    D_800BB3C0 = v0;
    v0 = 0x18;
    a0 = v1 << 2;
    v1 += 1;
    at = (s32 *) ((char *) D_800D4584 + a0);
    *at = v0;
    D_800BB4F0 = v1;
}

void func_8007E140(void) {
    D_800BB3C0 = 0x160;
    func_800FFF08(0xE, 0x19, 0xB848, 0);
}

s32 func_8007E178(void) {
    return D_800BB3C0 = -1;
}

void func_8007E18C(s32 *arg0) {
    register s32 v0 asm("v0");
    extern s32 func_800FFEEC();
    extern s32 func_8007E178();
    extern void func_8007E360(s32);
    extern void func_8006E860(s32, s32);
    extern void func_8008FC88(s32);
    extern void func_8008FD88(s32);
    extern void func_800FFF08();
    register s32 e asm("v0");
    s32 *s0 = arg0;
    register s32 w0 asm("v0");
    register s32 w1 asm("v1");
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
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
        func_8008FC88(7);
        h = D_800BB354;
        func_8007E360(D_800D0880[h] & 0x7FF);
    } else {
        func_8008FD88(7);
        func_8006C44C();
    }
    goto epi;
els:
    if ((D_800BC2F0 & 0x40) == 0)
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
    if (D_8004EAF8 != 0)
        goto e3;
    ((s32 (*)(s32)) func_8007E178)(s0);
    func_8006E860(0x1058, 1);
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
    w0 = 1;
    s0[0] = w0;
fjoin:
    func_800FFF08(c0, c1, c2, c3);
    D_8004D950 |= 4;
epi:;
}

extern s32 D_8009EB48;
extern s32 D_800596AC;

void func_8007E360(s32 arg0) {
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB9AC;
    extern s32 D_800BB998;
    extern s32 D_801531D8;
    extern void func_80069F04(s32, s32, void *);
    extern void func_8008FFE0();
    extern void func_800FFF08();
    s32 s0 = arg0;
    register s32 v1 asm("v1");
    register s32 v0 asm("v0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    s32 s1v;
    volatile s32 pad[2];
    u8 buf[8];
    v1 = D_800BB4F0;
    a0 = *(u8 *) ((char *) &D_8009EB48 + s0);
    KEEP(v1);
    v0 = v1 * 92;
    *(s32 *) ((char *) &D_800BB98C + v0) = s0;
    s1v = 1;
    func_80068AB4(a0);
    v0 = func_8006B548(&D_8009EF80, &D_8009F198);
    a0 = (s32) &D_800596AC;
    a2 = D_800BB4F0;
    USE(a2);
    a1 = s0;
    v1 = a2 * 92;
    *(s32 *) ((char *) &D_800BB990 + v1) = v0;
    v1 = v0 * 52;
    v0 = *(s32 *) ((char *) &D_800BBC70 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BBC70 + v1) = v0;
    v0 = (s32) &D_800BBC88;
    v1 += v0;
    v0 = -0x74;
    *(s32 *) v1 = v0;
    v0 = -0x22;
    *(s32 *) (v1 + 4) = v0;
    func_80069F04(a0, a1, buf);
    v1 = (s32) &D_8009EF2C;
    a0 = v1 - 0x34;
    USE(a0);
    KEEP(v1);
    v0 = s0 + 0x8800;
    *(s32 *) v1 = v0;
    v0 = 0x70;

    MEMORY_BARRIER();
    *(s32 *) (v1 - 52) = 0;
    MEMORY_BARRIER();
    D_8009EEFC = v0;
    v0 = -0x7A;
    *(s32 *) (v1 - 44) = v0;
    v0 = -0x28;
    *(s32 *) (v1 - 40) = v0;
    v0 = 0xDC;
    *(s32 *) (v1 - 36) = v0;
    v0 = 8;
    *(s32 *) (v1 - 32) = v0;
    v0 = 0xA;
    *(s32 *) (v1 + 24) = v0;
    *(s32 *) (v1 + 40) = s1v;
    v0 = -1;
    *(s32 *) (v1 + 48) = v0;
    a1 = 0xB84F;
    v0 = buf[0];
    a2 = buf[1];
    v0 = v0 + a1;
    *(s32 *) (v1 + 52) = v0;
    *(s32 *) (v1 + 56) = a2;
    func_8008FFE0();
    v0 = D_800BB4F0;
    v0 -= 1;
    a1 = v0 * 92;
    v0 = *(s32 *) ((char *) &D_800BB98C + a1);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = *(s32 *) ((char *) &D_800BB990 + a1);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v1 = *(s32 *) ((char *) &D_800BB994 + a1);
    v0 = v1 * 52;
    v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
    v1 |= 0x10;
    *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
    v0 = *(s32 *) ((char *) &D_800BB9AC + a1);
    a0 = 0xE;
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = *(s32 *) ((char *) &D_800BB9B0 + a1);
    a2 = 0xB849;
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    s0 += 0xD800;
    D_801531D8 = s0;
    func_800FFF08(a0, 0x19, a2, 0);
    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    a0 = v1 * 4;
    *(s32 *) ((char *) &D_800BB998 + v0) = s1v;
    v0 = 0x19;
    v1 += 1;
    *(s32 *) ((char *) &D_800D4584 + a0) = v0;
    D_800BB4F0 = v1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007E6F4);

void func_8007EBFC(void) {
    extern s32 func_800EF1A8(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s16 D_800BB3F0[];
    register s32 s0 asm("s0");
    register s16 *s1 asm("s1");
    register s16 *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");

    s3 = 0;
    s0 = 0;
    s2 = D_800BB3F0;
    s1 = D_800D0880;
loop:
    a0 = s0 + 0x321;
    v0 = func_800EF1A8(a0);
    if (v0 != 0) {
        v0 = s0 - 0x2000;
        *s1 = v0;
        *s2 = 0;
        s2 += 1;
        s1 += 1;
        s3 += 1;
    }
    s0 += 1;
    v0 = s0 < 0x2F;
    if (v0 != 0)
        goto loop;
    a0 = 0xE;
    a1 = 0x19;
    a2 = 0xB848;
    a3 = 0;
    func_800FFF08(a0, a1, a2, a3);
    v0 = D_800BB4F0;
    v1 = v0 << 1;
    v1 += v0;
    v1 <<= 3;
    v1 -= v0;
    v1 <<= 2;
    v0 = s3 < 8;
    at = (s32 *) D_800BB9BC;
    at = (s32 *) ((char *) at + v1);
    *at = s3;
    s0 = 0;
    s0 |= 8;
    if (v0 == 0)
        goto count;
    s0 = s3;
    goto common;
count:
common:
    a0 = 8;
    KEEP_NOVOL(a0);
    a1 = s3;
    a2 = s0;
    func_8008FCC8(a0, a1, a2, a3, 0x5A, a2, 0x88, 0x50);
    a0 = 0xC;
    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) D_800BB9BC;
    at = (s32 *) ((char *) at + v0);
    a1 = *at;
    func_8008FAD8(a0, a1, (s32 *) ((char *) sp + 16), (s32 *) ((char *) sp + 24));
    v1 = D_800BB4F0;
    v0 = 0x160;
    D_800BB3C0 = v0;
    v0 = 0x1A;
    a0 = v1 << 2;
    v1 += 1;
    at = (s32 *) ((char *) D_800D4584 + a0);
    *at = v0;
    D_800BB4F0 = v1;
}

void func_8007ED70(void) {
    D_800BB3C0 = 0x160;
    func_800FFF08(0xE, 0x19, 0xB848, 0);
}

s32 func_8007EDA8(void) {
    return D_800BB3C0 = -1;
}

void func_8007EDBC(s32 *arg0) {
    register s32 v0 asm("v0");
    extern s32 func_800FFEEC();
    extern void func_8007EFA0();
    extern void func_8006E860();
    extern void func_8008FC88(s32);
    extern void func_8008FD88(s32);
    extern void func_800FFF08();
    register s32 e asm("v0");
    s32 *s0 = arg0;
    register s32 w0 asm("v0");
    register s32 w1 asm("v1");
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
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
        func_8008FC88(0x8);
        h = D_800BB354;
        func_8007EFA0(D_800D0880[h] & 0x7FF);
    } else {
        func_8008FD88(0x8);
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
    ((s32 (*)()) func_8007E178)(s0);
    func_8006E860(0x101F, 1);
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
    w0 = 1;
    s0[0] = w0;
fjoin:
    func_800FFF08(c0, c1, c2, c3);
    D_8004D950 |= 4;
epi:;
}

extern s32 D_8009EB58;
extern s32 D_80057CEC;

void func_8007EFA0(s32 arg0) {
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB9AC;
    extern s32 D_800BB998;
    extern s32 D_801531D8;
    extern void func_80069F04(s32, s32, void *);
    extern void func_8008FFE0();
    extern void func_800FFF08();
    s32 s0 = arg0;
    register s32 v1 asm("v1");
    register s32 v0 asm("v0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    s32 s1v;
    volatile s32 pad[2];
    u8 buf[8];
    v1 = D_800BB4F0;
    a0 = *(u8 *) ((char *) &D_8009EB58 + s0);
    KEEP(v1);
    v0 = v1 * 92;
    *(s32 *) ((char *) &D_800BB98C + v0) = s0;
    s1v = 1;
    func_80068AB4(a0);
    v0 = func_8006B548(&D_8009EF80, &D_8009F198);
    a0 = (s32) &D_80057CEC;
    a2 = D_800BB4F0;
    USE(a2);
    a1 = s0;
    v1 = a2 * 92;
    *(s32 *) ((char *) &D_800BB990 + v1) = v0;
    v1 = v0 * 52;
    v0 = *(s32 *) ((char *) &D_800BBC70 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BBC70 + v1) = v0;
    func_80069F04(a0, a1, buf);
    v1 = (s32) &D_8009EF2C;
    a0 = v1 - 0x34;
    USE(a0);
    KEEP(v1);
    v0 = s0 + 0x8800;
    *(s32 *) v1 = v0;
    v0 = 0x70;
    MEMORY_BARRIER();
    *(s32 *) (v1 - 52) = 0;
    MEMORY_BARRIER();
    D_8009EEFC = v0;
    v0 = -0x7A;
    *(s32 *) (v1 - 44) = v0;
    v0 = -0x28;
    *(s32 *) (v1 - 40) = v0;
    v0 = 0xDC;
    *(s32 *) (v1 - 36) = v0;
    v0 = 8;
    *(s32 *) (v1 - 32) = v0;
    v0 = 0xA;
    *(s32 *) (v1 + 24) = v0;
    *(s32 *) (v1 + 40) = s1v;
    v0 = -1;
    *(s32 *) (v1 + 48) = v0;
    a1 = 0xB84F;
    v0 = buf[0];
    a2 = buf[1];
    v0 = v0 + a1;
    *(s32 *) (v1 + 52) = v0;
    *(s32 *) (v1 + 56) = a2;
    func_8008FFE0();
    v0 = D_800BB4F0;
    v0 -= 1;
    a1 = v0 * 92;
    v0 = *(s32 *) ((char *) &D_800BB98C + a1);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = *(s32 *) ((char *) &D_800BB990 + a1);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v1 = *(s32 *) ((char *) &D_800BB994 + a1);
    v0 = v1 * 52;
    v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
    v1 |= 0x10;
    *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
    v0 = *(s32 *) ((char *) &D_800BB9AC + a1);
    a0 = 0xE;
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = *(s32 *) ((char *) &D_800BB9B0 + a1);
    a2 = 0xB849;
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    s0 += 0xE000;
    D_801531D8 = s0;
    func_800FFF08(a0, 0x19, a2, 0);
    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    a0 = v1 * 4;
    *(s32 *) ((char *) &D_800BB998 + v0) = s1v;
    *(s32 *) ((char *) &D_800BB99C + v0) = 0;
    v0 = 0x1B;
    v1 += 1;
    *(s32 *) ((char *) &D_800D4584 + a0) = v0;
    D_800BB4F0 = v1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007F32C);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007F998);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8007FBF0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80080164);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8008047C);

extern s32 D_8009F288;

void func_80080758(s32 arg0) {
    extern s32 D_800BB9AC[];
    extern void func_800E0480(s32 *, s32, s32);
    s32 a0;
    s32 a1;
    s32 v0;
    s32 v1;
    s32 *at;

    a1 = arg0;
    a0 = D_800BB4F0;
    v0 = a0 << 2;
    at = (s32 *) ((char *) &D_800D4580[0] + v0);
    v1 = *at;
    v0 = 0x23;
    if (v1 != v0)
        goto exit;
    v1 = a0 - 1;
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB9AC[0] + v0);
    v1 = *at;
    v0 = 2;
    if (v1 == v0)
        goto exit;
    func_800E0480(&D_8009F288, a1, 2);
exit:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_800807DC);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80080E54);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80081744);

void func_80081D68(register s32 *s0) {
    extern void func_800FFF08();
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    s32 local[4];

    a1 = (s32) &D_800BBC70;
    KEEP_NOVOL(a1);
    a3 = 0;
    KEEP_NOVOL(a3);
    v1 = s0[3];
    a2 = s0[0];
    a0 = s0[1];
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = s0[2];
    KEEP_NOVOL(v1);
    v0 += a1;
    KEEP_NOVOL(v0);
    *(volatile s32 *) (v0 + 0x14) = 0;
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v0 += a1;
    *(volatile s32 *) (v0 + 0x14) = 0;
    v0 = a0;
    v0 <<= 3;
    v0 += a0;
    v0 <<= 2;
    at = (s32 *) &D_800BB518[0];
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    v0 = a2;
    v0 <<= 3;
    v0 += a2;
    v0 <<= 2;
    at = (s32 *) &D_800BB518[0];
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    v1 = s0[9];
    a0 = 14;
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v1 = s0[8];
    KEEP_NOVOL(v1);
    v0 <<= 2;
    at = (s32 *) &D_800BB518[0];
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) &D_800BB518[0];
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    v1 = s0[0];
    a1 = 0x19;
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    v1 = 2;
    at = (s32 *) &D_800BB508[0];
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    v1 = s0[0];
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) &D_800BB514[0];
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    at = (s32 *) &D_800BB510[0];
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    a2 = 0xB848;
    func_800FFF08(a0, a1, a2, a3);
    v1 = s0[2];
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    v0 = *at;
    v0 &= 0x10;
    if (v0 == 0)
        goto second;
    a0 = -0x11;
    v0 = s0[0];
    v1 = v0;
    v1 <<= 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) ((char *) &D_800BB504[0] + v1);
    v0 &= a0;
    *(s32 *) ((char *) &D_800BB504[0] + v1) = v0;
    v0 = s0[1];
    v1 = v0;
    v1 <<= 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) ((char *) &D_800BB504[0] + v1);
    v0 &= a0;
    *(s32 *) ((char *) &D_800BB504[0] + v1) = v0;
    v1 = s0[2];
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = *(volatile s32 *) ((char *) &D_800BBC70 + v0);
    v1 &= a0;
    *(volatile s32 *) ((char *) &D_800BBC70 + v0) = v1;
    v1 = s0[2];
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = *(volatile s32 *) ((char *) &D_800BBC70 + v0);
    v1 |= 0x100;
    *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
    v0 = s0[8];
    v1 = v0;
    v1 <<= 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) ((char *) &D_800BB504[0] + v1);
    v0 &= a0;
    *(s32 *) ((char *) &D_800BB504[0] + v1) = v0;
    v0 = s0[9];
    v1 = v0;
    v1 <<= 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) ((char *) &D_800BB504[0] + v1);
    v0 &= a0;
    *(s32 *) ((char *) &D_800BB504[0] + v1) = v0;
second:
    v0 = s0[3];
    v1 = v0;
    v1 <<= 1;
    v1 += v0;
    v1 <<= 2;
    v1 += v0;
    v1 <<= 2;
    a0 = *(s32 *) ((char *) &D_800BBC70 + v1);
    v0 = a0 & 0x10;
    if (v0 == 0)
        goto done;
    v0 = a0 & -0x11;
    *(s32 *) ((char *) &D_800BBC70 + v1) = v0;
    v1 = s0[3];
    a1 = -0x801;
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = D_8004D950;
    v1 &= a1;
    a0 = *(volatile s32 *) ((char *) &D_800BBC70 + v0);
    a0 |= 0x100;
    D_8004D950 = v1;
    *(s32 *) ((char *) &D_800BBC70 + v0) = a0;
done:
    s0[6] = 0;
}

void func_8008211C(s32 *arg0) {
    struct entry {
        char pad[0x34];
        s32 value;
    };
    s32 *a1;
    register s32 *at asm("at");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    s32 temp;

    a1 = arg0;
    KEEP_NOVOL(a1);
    at = (s32 *) ((char *) D_800BB518 + ((a1[0] * 9) << 2));
    *at = 0xA;
    at = (s32 *) ((char *) D_800BB518 + ((a1[1] * 9) << 2));
    *at = 6;
    at = (s32 *) ((char *) &D_800BBC84 + ((a1[2] * 13) << 2));
    *at = 2;
    at = (s32 *) ((char *) D_800BB518 + ((a1[8] * 9) << 2));
    *at = 5;
    at = (s32 *) ((char *) D_800BB518 + ((a1[9] * 9) << 2));
    *at = 5;
    at = (s32 *) ((char *) D_800BB508 + ((a1[0] * 9) << 2));
    *at = 1;
    temp = a1[0] * 9;
    at = (s32 *) ((char *) D_800BB514 + (temp << 2));
    *at = 0;
    at = (s32 *) ((char *) D_800BB510 + (temp << 2));
    *at = 0;
    if (a1[6] == 2) {
        v1 = a1[3];
        v0 = v1 * 13;
        *(s32 *) ((char *) &D_800BBC84 + (v0 << 2)) = 2;
        return;
    }
    v0 = a1[7];
    v0 = ((struct entry *) ((v0 << 2) + (s32) a1))->value;
    if (v0 == 2)
        return;
    v1 = a1[3];
    v0 = v1 * 13;
    a0 = *(s32 *) ((char *) &D_800BBC70 + (v0 << 2));
    v1 = D_8004D950;
    v1 |= 0x800;
    a0 |= 0x10;
    D_8004D950 = v1;
    *(s32 *) ((char *) &D_800BBC70 + (v0 << 2)) = a0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80082300);

void func_800829E8(void) {
    extern s16 D_800BB3F0;
    extern s32 func_800EF1A8(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    s32 s0;
    register u8 *s1 asm("s1");
    register u8 *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    struct {
        s32 sp10;
        s32 sp14;
        s32 sp18;
        s32 sp1c;
    } sp;

    func_800FFF08(0xE, 0x19, 0xB848, 0);
    s3 = 0;
    s0 = 0;
    s2 = &D_800BB3F0;
    s1 = &D_800D0880;
    do {
        if (func_800EF1A8(s0 + 0x1BC) != 0) {
            v0 = s0 - 0x1800;
            *(s16 *) s1 = (s16) v0;
            *(s16 *) s2 = 0;
            s2 += 2;
            s1 += 2;
            s3 += 1;
        }
        s0 += 1;
    } while (s0 < 0x40);
    v0 = D_800BB4F0;
    v1 = v0 * 92;
    *(s32 *) ((char *) &D_800BB9BC[0] + v1) = s3;
    v0 = s3 < 8;
    KEEP(s0);
    s0 = 8;
    if (v0) {
        s0 = s3;
    }
    a0 = 0xA;
    KEEP(a0);
    a1 = s3;
    KEEP(a1);
    a2 = s0;
    KEEP(a2);
    v0 = 0x94;
    sp.sp10 = v0;
    v0 = 0x4C;
    sp.sp18 = v0;
    sp.sp14 = a2;
    v0 = 0x4F;
    sp.sp1c = v0;
    func_8008FCC8(a0, a1, a2);
    a0 = 0xC;
    KEEP(a0);
    v1 = D_800BB4F0;
    a2 = (s32 *) &sp.sp10;
    v0 = v1 * 92;
    a1 = *(s32 *) ((char *) &D_800BB9BC[0] + v0);
    ((void (*)(s32, s32, s32 *, s32 *)) func_8008FAD8)(a0, a1, (s32 *) &sp.sp10, (s32 *) &sp.sp18);
    v0 = 0x160;
    D_800BB3C0 = v0;
    v0 = 9;
    D_800BB3EC = v0;
    v0 = D_8004D950;
    v1 = D_800BB4F0;
    v0 |= 0x800;
    a0 = v1 << 2;
    D_8004D950 = v0;
    v0 = 0x1D;
    v1 += 1;
    *(s32 *) ((char *) &D_800D4584[0] + a0) = v0;
    D_800BB4F0 = v1;
}

void func_80082B80(void) {
    func_800FFF08(0xE, 0x19, 0xB848, 0);
    D_800BB3C0 = 0x160;
}

s32 func_80082BB8(void) {
    return D_800BB3C0 = -1;
}

void func_80082BCC(s32 *arg0) {
    extern s32 D_800BB998[];
    extern s32 func_800FFEEC();
    extern void func_80082E14();
    extern void func_8006E860();
    extern void func_8008FC88(s32);
    extern void func_8008FD88(s32);
    extern void func_800FFF08();
    register s32 e asm("v0");
    s32 *s0 = arg0;
    register s32 v1 asm("v1");
    register s32 t asm("a0");
    register s32 v0 asm("v0");
    s32 q;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    v0 = D_8004D950;
    if ((e & 4) == 0)
        goto els;
    if (func_800FFEEC(0xC) != 0)
        goto els;
    v1 = 1;
    v0 = D_8004D950;
    t = D_800BB4F0;
    D_800BB3EC = v1;
    v1 = s0[0];
    D_800BB3C0 = 0;
    D_8004D950 = v0 ^ 4;
    D_800BB4F0 = t - 1;
    if (v1 != 0) {
        s16 h;
        func_8008FC88(0xA);
        h = D_800BB354;
        func_80082E14(D_800D0880[h] & 0x7FF);
    } else {
        v1 = t - 2;
        v0 = v1 * 92;
        q = *(s32 *) ((char *) D_800BB998 + v0);
        v0 = q * 52;
        q = *(s32 *) ((char *) D_800BBC70 + v0);
        q |= 0x100;
        *(s32 *) ((char *) D_800BBC70 + v0) = q;
        func_8008FD88(0xA);
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
    ((s32 (*)()) func_80082BB8)(s0);
    func_8006E860(0x1055, 1);
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

void func_80082E14(s32 arg0) {
    extern s32 D_800BB990[];
    extern s32 D_800BB994[];
    extern s32 D_800BB9AC[];
    extern s32 D_801531D8;
    extern void func_8008FFE0();
    extern void func_800FFF08();
    s32 s0 = arg0;
    s32 *a1;
    register s32 v1 asm("v1");
    register s32 v0 asm("v0");
    register s32 a0 asm("a0");
    volatile s32 pad[2];
    a1 = &D_8009EF2C;
    v1 = D_800BB4F0;
    a0 = (s32) (a1 - 13);
    USE(a0);
    KEEP(a1);
    v0 = v1 * 92;
    *(s32 *) ((char *) &D_800BB98C + v0) = s0;
    v0 = s0 + 0x8800;
    *a1 = v0;
    v0 = 0x70;
    MEMORY_BARRIER();
    *(a1 - 13) = 0;
    MEMORY_BARRIER();
    D_8009EEFC = v0;
    v0 = -0x7A;
    *(a1 - 11) = v0;
    v0 = -0x28;
    *(a1 - 10) = v0;
    v0 = 0xDC;
    *(a1 - 9) = v0;
    v0 = 8;
    *(a1 - 8) = v0;
    v0 = 9;
    *(a1 + 6) = v0;
    v0 = 1;
    *(a1 + 10) = v0;
    v0 = -1;
    *(a1 + 12) = v0;
    *(a1 + 14) = v0;
    *(a1 + 13) = v0;
    func_8008FFE0();
    v0 = D_800BB4F0;
    v0 -= 1;
    a0 = v0 * 92;
    v0 = *(s32 *) ((char *) &D_800BB98C + a0);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = *(s32 *) ((char *) &D_800BB990 + a0);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v1 = *(s32 *) ((char *) &D_800BB994 + a0);
    v0 = v1 * 52;
    v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
    v1 |= 0x10;
    *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
    v0 = *(s32 *) ((char *) &D_800BB9AC + a0);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = *(s32 *) ((char *) &D_800BB9B0 + a0);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    s0 += 0xE800;
    D_801531D8 = s0;
    func_800FFF08(0xE, 0x19, 0xB849, 0);
    v0 = D_800BB4F0;
    v1 = 0x1E;
    a0 = v0 * 4;
    v0 += 1;
    *(s32 *) ((char *) &D_800D4584 + a0) = v1;
    D_800BB4F0 = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_800830A8);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_800830B0);

void func_8008343C(void) {
    extern s16 D_800BB3F0;
    extern s32 D_800BB998[];
    extern s32 func_800EF1A8(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    register s32 s0 asm("s0");
    register u8 *s1 asm("s1");
    register u8 *s3 asm("s3");
    register s32 s2 asm("s2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    struct {
        s32 sp10;
        s32 sp14;
        s32 sp18;
        s32 sp1c;
    } sp;

    func_800FFF08(0xE, 0x19, 0xB848, 0);
    s2 = 0;
    s0 = 0;
    s3 = (u8 *) &D_800BB3F0;
    s1 = (u8 *) &D_800D0880;
    do {
        v1 = func_800EF1A8(s0 + 0x3C0);
        if (v1 != 0) {
            v0 = s0 << 4;
            v1 += -0x1000;
            v0 += v1;
            *(s16 *) s1 = (s16) v0;
            *(s16 *) s3 = 0;
            s3 += 2;
            s1 += 2;
            s2 += 1;
        }
        s0 += 1;
    } while (s0 < 0x40);
    v0 = D_800BB4F0;
    v1 = v0 * 92;
    *(s32 *) ((char *) &D_800BB9BC[0] + v1) = s2;
    v0 = s2 < 8;
    KEEP(s0);
    s0 = 8;
    if (v0) {
        s0 = s2;
    }
    a0 = 0xB;
    KEEP(a0);
    a1 = s2;
    KEEP(a1);
    a2 = s0;
    KEEP(a2);
    v0 = 0x60;
    sp.sp10 = v0;
    v0 = 0x80;
    sp.sp18 = v0;
    sp.sp14 = a2;
    v0 = 0x50;
    sp.sp1c = v0;
    func_8008FCC8(a0, a1, a2);
    a0 = 0xC;
    KEEP(a0);
    v1 = D_800BB4F0;
    a2 = (s32 *) &sp.sp10;
    v0 = v1 * 92;
    a1 = *(s32 *) ((char *) &D_800BB9BC[0] + v0);
    ((void (*)(s32, s32, s32 *, s32 *)) func_8008FAD8)(a0, a1, (s32 *) &sp.sp10, (s32 *) &sp.sp18);
    v0 = 0x160;
    D_800BB3C0 = v0;
    v0 = 9;
    D_800BB3EC = v0;
    v0 = D_8004D950;
    a1 = D_800BB4F0;
    v0 |= 0x800;
    v1 = a1 - 1;
    D_8004D950 = v0;
    v0 = v1 * 92;
    a0 = a1 << 2;
    v1 = *(s32 *) ((char *) &D_800BB998[0] + v0);
    v0 = 0x1F;
    *(s32 *) ((char *) &D_800D4584[0] + a0) = v0;
    v0 = v1 * 52;
    v1 = *(s32 *) ((char *) &D_800BBC70[0] + v0);
    a1 += 1;
    D_800BB4F0 = a1;
    *(s32 *) ((char *) &D_800BBC70[0] + v0) = v1 | 0x10;
}

void func_80083640(void) {
    func_800FFF08(0xE, 0x19, 0xB848, 0);
    D_800BB3C0 = 0x160;
}

s32 func_80083678(void) {
    return D_800BB3C0 = -1;
}

void func_8008368C(s32 *arg0) {
    extern s32 D_800BB998[];
    extern s32 func_800FFEEC();
    extern void func_8008389C(s32);
    extern void func_8006E860(s32, s32);
    extern void func_8008FC88(s32);
    extern void func_8008FD88(s32);
    extern void func_800FFF08();
    register s32 e asm("v0");
    s32 *s0 = arg0;
    register s32 v1 asm("v1");
    register s32 t asm("a0");
    register s32 v0 asm("v0");
    s32 q;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    v0 = D_8004D950;

    if ((e & 4) == 0)
        goto els;
    if (func_800FFEEC(0xC) != 0)
        goto els;
    v1 = 1;
    v0 = D_8004D950;
    t = D_800BB4F0;
    D_800BB3EC = v1;
    v1 = s0[0];
    D_800BB3C0 = 0;
    D_8004D950 = v0 ^ 4;
    D_800BB4F0 = t - 1;
    if (v1 != 0) {
        s16 h;
        func_8008FC88(0xB);
        h = D_800BB354;
        func_8008389C(D_800D0880[h] & 0x7FF);
    } else {
        v1 = t - 2;
        v0 = v1 * 92;
        q = *(s32 *) ((char *) D_800BB998 + v0);
        v0 = q * 52;
        q = *(s32 *) ((char *) D_800BBC70 + v0);
        q |= 0x100;
        *(s32 *) ((char *) D_800BBC70 + v0) = q;
        func_8008FD88(0xB);
        func_8006C44C();
    }
    goto epi;
els:
    v1 = D_800BC2F0;
    KEEP(v1);
    if ((v1 & 0x40) == 0)
        goto e2;
    func_80090D30(2);
    c0 = 0xC;
    c1 = 0;
    c2 = 0;
    c3 = 1;
    s0[0] = 0;
    goto fjoin;
e2:
    v0 = v1 & 0x100;
    if (v0 == 0)
        goto e3;
    if (s0[12] == 0)
        goto e3;
    ((s32 (*)(s32 *)) func_80083678)(s0);
    func_8006E860(0x1056, 1);
    goto epi;
e3:
    if ((D_800BC2F0 & 0x20) == 0)
        goto epi;
    if (s0[12] == 0)
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

void func_8008389C(s32 arg0) {
    extern s32 func_80068BC4(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB998;
    extern s32 D_800BB9AC;
    extern s32 D_801531D8;
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    volatile s32 pad[12];

    s1 = arg0;
    s0 = s1 >> 4;
    a0 = s0;
    if (s0 < 0)
        a0 = s0 + 0xF;
    a0 >>= 4;
    a0 += 6;
    func_80068BC4(a0);
    a0 = (s32) &D_8009EF80;
    v1 = D_800BB4F0;
    a1 = (s32) &D_8009F198;
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + v0);
    *at = s1;
    v0 = func_8006B548(a0, a1);
    a0 = v0;
    a0 <<= 1;
    a0 += v0;
    a0 <<= 2;
    a0 += v0;
    a1 = D_800BB4F0;
    KEEP(a1);
    a0 <<= 2;
    KEEP(a0);
    v1 = a1;
    v1 <<= 1;
    v1 += a1;
    v1 <<= 3;
    v1 -= a1;
    v1 <<= 2;
    at = (s32 *) &D_800BB990;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    MEMORY_BARRIER();
    v0 = -5;
    a1 -= 1;
    a2 = a1;
    a2 <<= 1;
    a2 += a1;
    a2 <<= 3;
    a2 -= a1;
    a2 <<= 2;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + a0);
    a1 = *at;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + a2);
    v1 = *at;
    a1 &= v0;
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) &D_800BB504[0];
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    KEEP(v1);
    a1 |= 0x10;
    *(volatile s32 *) ((char *) &D_800BBC70[0] + a0) = a1;
    MEMORY_BARRIER();
    v1 |= 0x10;
    at = (s32 *) &D_800BB504[0];
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    at = (s32 *) &D_800BB990;
    at = (s32 *) ((char *) at + a2);
    v0 = *at;
    v1 = v0;
    v1 <<= 3;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) &D_800BB504[0];
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) &D_800BB504[0];
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    at = (s32 *) &D_800BB994;
    at = (s32 *) ((char *) at + a2);
    v1 = *at;
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    v1 |= 0x10;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    at = (s32 *) &D_800BB9AC;
    at = (s32 *) ((char *) at + a2);
    v0 = *at;
    v1 = v0;
    v1 <<= 3;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) &D_800BB504[0];
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) &D_800BB504[0];
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    at = (s32 *) &D_800BB9B0;
    at = (s32 *) ((char *) at + a2);
    v0 = *at;
    v1 = v0;
    v1 <<= 3;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) &D_800BB504[0];
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) &D_800BB504[0];
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    if (s0 == 0) {
        v0 = s1 & 0xF;
        v1 = 0xB869;
        v0 += v1;
        D_801531D8 = v0;
        a0 = 0xE;
        a1 = 0x19;
        a2 = 0xB868;
    } else {
        v0 = 0xF000;
        v0 += s1;
        D_801531D8 = v0;
        a0 = 0xE;
        a1 = 0x19;
        a2 = 0xB849;
    }
    a3 = 0;
    func_800FFF08(a0, a1, a2, a3);
    a0 = D_800BB4F0;
    v0 = a0;
    v0 <<= 1;
    v0 += a0;
    v0 <<= 3;
    v0 -= a0;
    v0 <<= 2;
    at = (s32 *) &D_800BB998;
    at = (s32 *) ((char *) at + v0);
    v1 = 1;
    *at = v1;
    at = (s32 *) &D_800BB99C;
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    v1 = a0;
    v1 <<= 2;
    at = (s32 *) &D_800D4584;
    at = (s32 *) ((char *) at + v1);
    v0 = 0x20;
    *at = v0;
    a0 += 1;
    D_800BB4F0 = a0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80083BC4);

void func_80084230(void) {
    extern s16 D_800BB3F0;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register u16 *v1p asm("v1");
    register s32 *at asm("at");
    struct {
        s32 sp10;
        s32 sp14;
        s32 sp18;
        s32 sp1c;
    } sp;

    a1 = 0;
    a2 = 0;
    a3 = -0x8000;
    a0 = (s32) &D_800BB3F0;
    v1p = (u16 *) &D_800D0880[0];
    do {
        v0 = a2 + a3;
        *(s16 *) v1p = v0;
        *(s16 *) a0 = 0;
        a0 += 2;
        v1p += 1;
        a2 += 1;
        a1 += 1;
        v0 = a2 < 0x29;
    } while (v0);
    {
        register s32 v1 asm("v1");

        v0 = D_800BB4F0;
        v1 = v0;
        v1 <<= 1;
        v1 += v0;
        v1 <<= 3;
        v1 -= v0;
        v1 <<= 2;
        v0 = a1 < 8;
        *(s32 *) ((char *) &D_800BB9BC[0] + v1) = a1;
        a2 = 8;
        if (a1 < 8) {
            a2 = a1;
        }
        a0 = 0xC;
        KEEP(a0);
        v0 = 0x8C;
        sp.sp10 = v0;
        v0 = 0x54;
        sp.sp18 = v0;
        sp.sp14 = a2;
        v0 = 0x50;
        sp.sp1c = v0;
        func_8008FCC8(a0, a1, a2, a3);
        a0 = 0xC;
        KEEP(a0);
        v1 = D_800BB4F0;
        KEEP(v1);
        a2 = (s32) &sp.sp10;
        v0 = v1;
        v0 <<= 1;
        v0 += v1;
        v0 <<= 3;
        v0 -= v1;
        v0 <<= 2;
        a1 = *(s32 *) ((char *) &D_800BB9BC[0] + v0);
        func_8008FAD8(a0, a1, (s32 *) &sp.sp10, (s32 *) &sp.sp18);
        v1 = D_800BB4F0;
        v0 = 0x160;
        D_800BB3C0 = v0;
        v0 = 9;
        D_800BB3EC = v0;
        v0 = 0x21;
        a0 = v1 << 2;
        v1 += 1;
        at = (s32 *) ((char *) &D_800D4584[0] + a0);
        *at = v0;
        D_800BB4F0 = v1;
    }
}

void func_8008436C(void) {
    D_800BB3C0 = 0x160;
}

s32 func_80084380(void) {
    return D_800BB3C0 = -1;
}

void func_80084394(s32 *arg0) {
    extern s32 func_800FFEEC();
    extern void func_80084578();
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
    s32 v1;
    s32 e;
    e = D_8004D950;
    if ((e & 4) == 0)
        goto els;
    if (func_800FFEEC(0xC) != 0)
        goto els;
    v1 = 1;
    v0 = D_8004D950;
    D_800BB3EC = v1;
    v1 = s0[0];
    D_8004D950 = v0 ^ 4;
    MEMORY_BARRIER();
    v0 = D_800BB4F0;
    D_800BB3C0 = 0;
    D_800BB4F0 = v0 - 1;
    if (v1 != 0) {
        s16 h;
        func_8008FC88(0xC);
        h = D_800BB354;
        func_80084578(D_800D0880[h] & 0x7FF);
    } else {
        func_8008FD88(0xC);
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
    ((s32 (*)()) func_80084380)(s0);
    func_8006E860(0x108D, 1);
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

void func_80084578(s32 arg0) {
    extern void func_8008FFE0();
    extern s32 D_800BB990[];
    extern s32 D_800BB994[];
    s32 a0;
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");

    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    v1 = (s32) &D_8009EF2C;
    KEEP_NOVOL(v1);
    at = (s32 *) ((char *) &D_800BB98C + v0);
    *at = arg0;
    v0 = 0x8800;
    a0 = arg0 + v0;
    v0 = 0x70;
    *(s32 *) v1 = a0;
    *(s32 *) (v1 - 0x34) = 0;
    D_8009EEFC = v0;
    v0 = -0x7A;
    *(s32 *) (v1 - 0x2C) = v0;
    v0 = -0x28;
    *(s32 *) (v1 - 0x28) = v0;
    v0 = 0xDC;
    *(s32 *) (v1 - 0x24) = v0;
    v0 = 8;
    *(s32 *) (v1 - 0x20) = v0;
    v0 = 9;
    *(s32 *) (v1 + 0x18) = v0;
    v0 = 1;
    *(s32 *) (v1 + 0x28) = v0;
    v0 = -1;
    a0 = v1 - 0x34;
    *(s32 *) (v1 + 0x30) = v0;
    *(s32 *) (v1 + 0x38) = v0;
    *(s32 *) (v1 + 0x34) = v0;
    func_8008FFE0((void *) a0);
    a1 = D_800BB4F0;
    v0 = a1 - 1;
    a0 = v0 << 1;
    a0 += v0;
    a0 <<= 3;
    a0 -= v0;
    a0 <<= 2;
    at = (s32 *) ((char *) &D_800BB98C + a0);
    v0 = *at;
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    at = (s32 *) ((char *) D_800BB990 + a0);
    v0 = *at;
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    v0 = a1 + 1;
    at = (s32 *) ((char *) D_800BB994 + a0);
    v1 = *at;
    a1 <<= 2;
    D_800BB4F0 = v0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    a0 = 0x22;
    at = (s32 *) D_800D4584;
    at = (s32 *) ((char *) at + a1);
    *at = a0;
    v1 |= 0x10;
    at = (s32 *) D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
}

void func_80084748(void) {
    extern s32 D_800BB994;
    extern s32 D_800BB990;
    extern s32 func_800903E4();
    extern void func_80084230();
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    a0 = (s32) &D_8009EF3C;
    v0 = *(s32 *) a0;
    v1 = v0 * 52;
    v0 = *(s32 *) ((char *) &D_800BBC70 + v1);
    if ((v0 & 0x100) == 0) {
        v0 = func_800903E4(a0 - 0x44);
        if (v0 == 0) {
            func_80090D30(2);
            a2 = D_800BB4F0;
            v0 = a2 - 2;
            a0 = v0 * 92;
            v1 = *(s32 *) ((char *) &D_800BB994 + a0);
            v0 = v1 * 52;
            v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
            a1 = *(s32 *) ((char *) &D_800BB98C + a0);
            v1 |= 0x100;
            *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
            v1 = a1 * 36;
            v0 = *(s32 *) ((char *) &D_800BB504 + v1);
            a1 = -0x11;
            v0 &= a1;
            *(s32 *) ((char *) &D_800BB504 + v1) = v0;
            v0 = *(s32 *) ((char *) &D_800BB990 + a0);
            v1 = v0 * 36;
            v0 = *(s32 *) ((char *) &D_800BB504 + v1);
            v0 &= a1;
            *(s32 *) ((char *) &D_800BB504 + v1) = v0;
            v1 = *(s32 *) ((char *) &D_800BB994 + a0);
            v0 = v1 * 52;
            v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
            a2 -= 1;
            D_800BB4F0 = a2;
            v1 &= a1;
            *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
            func_80084230();
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80084918);

void func_80084F78(s32 *arg0) {
    extern s32 D_800BB998;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    s32 a0v;
    v1 = D_800BB4F0;
    KEEP(v1);
    a2 = (s32) &D_800BBC70;
    KEEP(a2);
    v1 -= 2;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    a3 = v0 << 2;
    v1 = *(s32 *) ((char *) &D_800BB998 + a3);
    a1 = arg0[0];
    v0 = v1 * 52;
    v1 = arg0[1];
    v0 += a2;
    *(s32 *) (v0 + 0x14) = 0;
    v0 = v1 * 52;
    v0 += a2;
    *(s32 *) (v0 + 0x14) = 0;
    v0 = a1 * 36;
    *(s32 *) ((char *) D_800BB518 + v0) = 0;
    v1 = arg0[0];
    v0 = v1 * 36;
    v1 = 2;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f04 = v1;
    v1 = arg0[0];
    v0 = v1 * 36;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f10 = 0;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f0C = 0;
    MEMORY_BARRIER();
    v1 = *(s32 *) ((char *) &D_800BB998 + a3);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    a0v = v0 << 2;
    v1 = *(s32 *) ((char *) &D_800BBC70 + a0v);
    if ((v1 & 0x10) != 0) {
        v0 = -0x11;
        v0 = v1 & v0;
        *(s32 *) ((char *) &D_800BBC70 + a0v) = v0;
        MEMORY_BARRIER();
        v1 = *(s32 *) ((char *) &D_800BB998 + a3);
        a1 = -0x801;
        v0 = v1 * 52;
        v1 = D_8004D950;
        a0v = *(s32 *) ((char *) &D_800BBC70 + v0);
        v1 &= a1;
        a0v |= 0x100;
        D_8004D950 = v1;
        *(s32 *) ((char *) &D_800BBC70 + v0) = a0v;
    }
}

void func_8008512C(void *arg0) {
    extern s32 D_800BB998[];
    s32 a0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    s32 *p;

    p = (s32 *) arg0;
    v1 = p[0];
    v0 = v1 << 3;
    v0 += v1;
    v0 <<= 2;
    v1 = 0xA;
    at = (s32 *) ((char *) D_800BB518 + v0);
    *at = v1;
    v1 = p[1];
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = 2;
    at = (s32 *) ((char *) D_800BBC84 + v0);
    *at = v1;
    v1 = p[0];
    v0 = v1 << 3;
    v0 += v1;
    v0 <<= 2;
    at = (s32 *) ((char *) D_800BB508 + v0);
    *at = 0;
    v1 = p[0];
    v0 = v1 << 3;
    v0 += v1;
    v1 = D_800BB4F0;
    v0 <<= 2;
    at = (s32 *) ((char *) D_800BB514 + v0);
    *at = 0;
    at = (s32 *) ((char *) D_800BB510 + v0);
    *at = 0;
    v1 -= 2;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) ((char *) D_800BB998 + v0);
    v1 = *at;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = D_8004D950;
    at = (s32 *) D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    a0 = *at;
    v1 |= 0x800;
    a0 |= 0x10;
    D_8004D950 = v1;
    at = (s32 *) D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = a0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80085264);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80085760);

void func_800862AC(volatile s32 *arg0) {
    register s32 t0;
    register s32 a3;
    register s32 a2;
    register s32 v1 asm("v1");
    register s32 v0 asm("v0");
    register s32 a1 asm("a1") = (s32) &D_800BB504;
    register s32 temp;

    KEEP_NOVOL(a1);
    v1 = arg0[4];
    t0 = arg0[0];
    a3 = arg0[1];
    a2 = arg0[2];
    v0 = v1 * 13;
    v1 = arg0[3];
    v0 = v0 << 2;
    *(s32 *) ((char *) &D_800BBC84 + v0) = 0;
    *(s32 *) ((char *) a1 + v1 * 36 + 20) = 0;
    *(s32 *) ((char *) a1 + a2 * 36 + 20) = 0;
    *(s32 *) ((char *) a1 + a3 * 36 + 20) = 0;
    D_800BB518[t0 * 9] = 0;
    D_800BB508[arg0[0] * 9] = 2;
    temp = arg0[0] * 9;
    v0 = temp << 2;
    a1 = v0 + a1;
    *(s32 *) (a1 + 16) = 0;
    D_800BB510[temp] = 0;
}

void func_800863A0(volatile s32 *arg0) {
    s32 v0;
    s32 v1;
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 *a3 asm("a3");
    register s32 *at asm("at");

    v1 = arg0[0];
    KEEP(v1);
    a3 = &D_800BB504;
    KEEP(a3);
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    v1 = 0xA;
    at = (s32 *) ((char *) &D_800BB518 + v0);
    *at = v1;
    v1 = arg0[3];
    a2 = arg0[1];
    a1 = arg0[2];
    v0 = v1;
    v0 <<= 3;
    v0 += v1;
    v0 <<= 2;
    v0 += (s32) a3;
    v1 = 6;
    *(s32 *) ((char *) v0 + 0x14) = v1;
    v0 = a1;
    v0 <<= 3;
    v0 += a1;
    v0 <<= 2;
    v0 += (s32) a3;
    *(s32 *) ((char *) v0 + 0x14) = v1;
    v0 = a2;
    v0 <<= 3;
    v0 += a2;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB518 + v0);
    *at = v1;
    v1 = arg0[4];
    v0 = v1;
    v0 <<= 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    v1 = 2;
    at = (s32 *) ((char *) &D_800BBC84 + v0);
    *at = v1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80086458);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_800867F0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80086B9C);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80086F1C);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80087254);

void func_80087658(s32 *arg0) {
    s32 v0;
    s32 v1;

    v1 = arg0[1];
    v0 = v1 * 9;
    v1 = arg0[0];
    v0 = v0 * 4;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f14 = 0;
    v0 = v1 * 36;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f14 = 0;
}

void func_800876A4(void) {
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_800876AC);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_800876B4);

void func_80087B94(void) {
    extern s16 D_800BB3F0;
    extern s32 D_800BB998[];
    extern s32 func_800EF1A8(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    register s32 s0 asm("s0");
    register u8 *s1 asm("s1");
    register u8 *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    struct {
        s32 sp10;
        s32 sp14;
        s32 sp18;
        s32 sp1c;
    } sp;

    func_800FFF08(0xE, 0x19, 0xB848, 0);
    s3 = 0;
    s0 = 0;
    s2 = (u8 *) &D_800BB3F0;
    s1 = (u8 *) &D_800D0880;
    do {
        if ((func_800EF1A8(s0 + 0x360) & 4) != 0) {
            v0 = s0 + 0x6000;
            *(s16 *) s1 = (s16) v0;
            *(s16 *) s2 = 0;
            s2 += 2;
            s1 += 2;
            s3 += 1;
        }
        s0 += 1;
    } while (s0 < 0x60);
    v0 = D_800BB4F0;
    v1 = v0 * 92;
    *(s32 *) ((char *) &D_800BB9BC[0] + v1) = s3;
    v0 = s3 < 8;
    KEEP(s0);
    s0 = 8;
    if (v0) {
        s0 = s3;
    }
    a0 = 0x10;
    KEEP(a0);
    a1 = s3;
    KEEP(a1);
    a2 = s0;
    KEEP(a2);
    v0 = 0x96;
    sp.sp10 = v0;
    v0 = 0x4C;
    sp.sp18 = v0;
    sp.sp14 = a2;
    v0 = 0x50;
    sp.sp1c = v0;
    func_8008FCC8(a0, a1, a2);
    a0 = 0xC;
    KEEP(a0);
    v1 = D_800BB4F0;
    a2 = (s32 *) &sp.sp10;
    v0 = v1 * 92;
    a1 = *(s32 *) ((char *) &D_800BB9BC[0] + v0);
    ((void (*)(s32, s32, s32 *, s32 *)) func_8008FAD8)(a0, a1, (s32 *) &sp.sp10, (s32 *) &sp.sp18);
    v0 = 0x160;
    D_800BB3C0 = v0;
    v0 = 8;
    D_800BB3EC = v0;
    v0 = D_8004D950;
    a1 = D_800BB4F0;
    v0 |= 0x800;
    v1 = a1 - 1;
    D_8004D950 = v0;
    v0 = v1 * 92;
    a0 = a1 << 2;
    v1 = *(s32 *) ((char *) &D_800BB998[0] + v0);
    v0 = 0x29;
    *(s32 *) ((char *) &D_800D4584[0] + a0) = v0;
    v0 = v1 * 52;
    v1 = *(s32 *) ((char *) &D_800BBC70[0] + v0);
    a1 += 1;
    D_800BB4F0 = a1;
    *(s32 *) ((char *) &D_800BBC70[0] + v0) = v1 | 0x10;
}

void func_80087D90(void) {
}

void func_80087D98(void) {
}

void func_80087DA0(s32 *arg0) {
    extern s32 D_800BB998[];
    extern s32 func_800FFEEC();
    extern void func_80087FA4(s32);
    extern void func_8006E860(s32, s32);
    extern void func_8008FC88(s32);
    extern void func_8008FD88(s32);
    extern void func_800FFF08();
    register s32 e asm("v0");
    s32 *s0 = arg0;
    register s32 v1 asm("v1");
    register s32 t asm("a0");
    register s32 v0 asm("v0");
    s32 q;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    v0 = D_8004D950;

    if ((e & 4) == 0)
        goto els;
    if (func_800FFEEC(0xC) != 0)
        goto els;
    v1 = 1;
    v0 = D_8004D950;
    t = D_800BB4F0;
    D_800BB3EC = v1;
    v1 = s0[0];
    D_800BB3C0 = 0;
    D_8004D950 = v0 ^ 4;
    D_800BB4F0 = t - 1;
    if (v1 != 0) {
        s16 h;
        func_8008FC88(0x10);
        h = D_800BB354;
        func_80087FA4(D_800D0880[h] & 0x7FF);
    } else {
        v1 = t - 2;
        v0 = v1 * 92;
        q = *(s32 *) ((char *) D_800BB998 + v0);
        v0 = q * 52;
        q = *(s32 *) ((char *) D_800BBC70 + v0);
        q |= 0x100;
        *(s32 *) ((char *) D_800BBC70 + v0) = q;
        func_8008FD88(0x10);
        func_8006C44C();
    }
    goto epi;
els:
    v1 = D_800BC2F0;
    KEEP(v1);
    if ((v1 & 0x40) == 0)
        goto e2;
    func_80090D30(2);
    c0 = 0xC;
    c1 = 0;
    c2 = 0;
    c3 = 1;
    s0[0] = 0;
    goto fjoin;
e2:
    v0 = v1 & 0x100;
    if (v0 == 0)
        goto e3;
    if (s0[12] == 0)
        goto e3;
    func_8006E860(0x105B, 1);
    goto epi;
e3:
    if ((D_800BC2F0 & 0x20) == 0)
        goto epi;
    if (s0[12] == 0)
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

extern s32 D_80057C7C;

void func_80087FA4(s32 arg0) {
    extern void func_800686C8();
    extern void func_80069F04(s32, s32, void *);
    extern void func_8008FFE0(void *, s32, s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 D_800BB990;
    extern s32 D_801531D8;
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[2];
    volatile u8 sp18;

    s0 = arg0 + 0;
    func_800686C8();
    a0 = (s32) &D_80057C7C;
    KEEP_NOVOL(a0);
    a1 = s0;
    v1 = D_800BB4F0;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + v0);
    *at = s0;
    a2 = (s32) &sp18;
    func_80069F04((void *) a0, a1, (u8 *) a2);
    v1 = (s32) &D_8009EF2C;
    KEEP_NOVOL(v1);
    a0 = v1 - 0x34;
    v0 = 0x8800;
    v0 += s0;
    *(s32 *) v1 = v0;
    v0 = 0x70;
    *(s32 *) (v1 - 0x34) = 0;
    MEMORY_BARRIER();
    D_8009EEFC = v0;
    v0 = -0x7A;
    *(s32 *) (v1 - 0x2C) = v0;
    v0 = -0x28;
    *(s32 *) (v1 - 0x28) = v0;
    v0 = 0xDC;
    *(s32 *) (v1 - 0x24) = v0;
    v0 = 8;
    *(s32 *) (v1 - 0x20) = v0;
    *(s32 *) (v1 + 0x18) = v0;
    v0 = 1;
    *(s32 *) (v1 + 0x28) = v0;
    v0 = -1;
    a1 = 0xB84F;
    KEEP_NOVOL(a1);
    *(s32 *) (v1 + 0x30) = v0;
    v0 = sp18;
    a2 = *((volatile u8 *) &sp18 + 1);
    v0 += a1;
    *(s32 *) (v1 + 0x34) = v0;
    *(s32 *) (v1 + 0x38) = a2;
    func_8008FFE0((void *) a0, a1, a2);
    v0 = D_800BB4F0;
    MEMORY_BARRIER();
    a0 = 0xE;
    KEEP_WITH_NOVOL(a0, v0);
    v0 -= 1;
    v1 = v0 * 92;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    MEMORY_BARRIER();
    a2 = 0xB849;
    KEEP_WITH_NOVOL(a2, v0);
    a1 = v0 * 36;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + a1);
    v0 = *at;
    MEMORY_BARRIER();
    s0 += 0x6000;
    KEEP_WITH(s0, v0);
    v0 |= 0x10;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + a1);
    *at = v0;
    MEMORY_BARRIER();
    at = (s32 *) &D_800BB990;
    at = (s32 *) ((char *) at + v1);
    v1 = *at;
    MEMORY_BARRIER();
    a3 = 0;
    KEEP_WITH_NOVOL(a3, v1);
    v0 = v1 * 52;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    v1 |= 0x10;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    D_801531D8 = s0;
    func_800FFF08(a0, 0x19, a2, a3);
    v0 = D_800BB4F0;
    v1 = 0x2A;
    a0 = v0 << 2;
    v0 += 1;
    at = (s32 *) &D_800D4584;
    at = (s32 *) ((char *) at + a0);
    *at = v1;
    D_800BB4F0 = v0;
}

void func_80088180(void) {
    extern s32 D_800BB990;
    extern s32 func_800903E4();
    extern void func_80087B94();
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    a0 = (s32) &D_8009EF3C;
    v0 = *(s32 *) a0;
    v1 = v0 * 52;
    v0 = *(s32 *) ((char *) &D_800BBC70 + v1);
    if ((v0 & 0x100) == 0) {
        v0 = func_800903E4(a0 - 0x44);
        if (v0 == 0) {
            a2 = -0x11;
            a1 = D_800BB4F0;
            v0 = a1 - 2;
            a0 = v0 * 92;
            v0 = *(s32 *) ((char *) &D_800BB98C + a0);
            v1 = v0 * 36;
            v0 = *(s32 *) ((char *) &D_800BB504 + v1);
            v0 &= a2;
            *(s32 *) ((char *) &D_800BB504 + v1) = v0;
            v1 = *(s32 *) ((char *) &D_800BB990 + a0);
            v0 = v1 * 52;
            v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
            v1 &= a2;
            *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
            v1 = *(s32 *) ((char *) &D_800BB990 + a0);
            v0 = v1 * 52;
            v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
            a1 -= 1;
            D_800BB4F0 = a1;
            v1 |= 0x100;
            *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
            func_80087B94();
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80088308);

void func_800886E4(void) {
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    extern s32 D_800BB998;
    extern s32 D_800BB9AC;
    s32 a0;
    s32 a1;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");

    v0 = D_800BB4F0;
    v0 -= 1;
    a0 = v0 * 92;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    v0 = v1 * 36;
    v1 = 10;
    at = (s32 *) &D_800BB518;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    v0 = v1 * 36;
    at = (s32 *) &D_800BB508;
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    MEMORY_BARRIER();
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    v0 = v1 * 36;
    at = (s32 *) &D_800BB514;
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    at = (s32 *) &D_800BB510;
    at = (s32 *) ((char *) at + v0);
    *at = 0;
    at = (s32 *) &D_800BB98C;
    at = (s32 *) ((char *) at + a0);
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
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    v0 = v1 * 36;
    v1 = 6;
    at = (s32 *) &D_800BB518;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    at = (s32 *) &D_800BB990;
    at = (s32 *) ((char *) at + a0);
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
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    a1 = 2;
    v0 = v1 * 52;
    at = (s32 *) &D_800BBC84;
    at = (s32 *) ((char *) at + v0);
    *at = a1;
    MEMORY_BARRIER();
    at = (s32 *) &D_800BB994;
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    v0 = v1 * 52;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    v1 |= 0x10;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    at = (s32 *) &D_800BB998;
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    v0 = v1 * 52;
    at = (s32 *) &D_800BBC84;
    at = (s32 *) ((char *) at + v0);
    *at = a1;
    MEMORY_BARRIER();
    at = (s32 *) &D_800BB998;
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    v0 = v1 * 52;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    v1 |= 0x10;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    at = (s32 *) &D_800BB9AC;
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    a1 = 5;
    v0 = v1 * 36;
    at = (s32 *) &D_800BB518;
    at = (s32 *) ((char *) at + v0);
    *at = a1;
    at = (s32 *) &D_800BB9AC;
    at = (s32 *) ((char *) at + a0);
    v0 = *at;
    v1 = v0 * 36;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
    at = (s32 *) &D_800BB9B0;
    at = (s32 *) ((char *) at + a0);
    v1 = *at;
    v0 = v1 * 36;
    at = (s32 *) &D_800BB518;
    at = (s32 *) ((char *) at + v0);
    *at = a1;
    at = (s32 *) &D_800BB9B0;
    at = (s32 *) ((char *) at + a0);
    v0 = *at;
    v1 = v0 * 36;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    v0 = *at;
    v0 |= 0x10;
    at = (s32 *) &D_800BB504;
    at = (s32 *) ((char *) at + v1);
    *at = v0;
}

void func_80088A78(void) {
    extern s32 D_800BB990;
    extern s32 D_800BB994;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    v0 = D_800BB4F0;
    v0 -= 1;
    a0 = v0 * 92;
    v1 = *(volatile s32 *) ((char *) &D_800BB98C + a0);
    v0 = v1 * 36;
    v1 = 0xA;
    *(s32 *) ((char *) D_800BB518 + v0) = v1;
    v1 = *(volatile s32 *) ((char *) &D_800BB98C + a0);
    v0 = v1 * 36;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f04 = 0;
    v0 = *(volatile s32 *) ((char *) &D_800BB98C + a0);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    a1 = *(volatile s32 *) ((char *) &D_800BB98C + a0);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v0 = a1 * 36;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f10 = 0;
    (*(WldCoreRec24 *) ((char *) &D_800BB504[0] + v0)).f0C = 0;
    MEMORY_BARRIER();
    v1 = *(s32 *) ((char *) &D_800BB990 + a0);
    v0 = v1 * 36;
    v1 = 6;
    *(s32 *) ((char *) D_800BB518 + v0) = v1;
    v0 = *(s32 *) ((char *) &D_800BB990 + a0);
    v1 = v0 * 36;
    v0 = *(s32 *) ((char *) &D_800BB504 + v1);
    v0 |= 0x10;
    *(s32 *) ((char *) &D_800BB504 + v1) = v0;
    v1 = *(s32 *) ((char *) &D_800BB994 + a0);
    v0 = v1 * 52;
    v1 = 2;
    *(s32 *) ((char *) &D_800BBC84 + v0) = v1;
    v1 = *(s32 *) ((char *) &D_800BB994 + a0);
    v0 = v1 * 52;
    v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
    v1 |= 0x10;
    *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80088C90);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_800890F0);

void func_8008953C(void *arg0) {
    register s32 s0 asm("s0");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 s4 asm("s4");
    register s32 s5 asm("s5");
    register s32 s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    u16 v_init;
    volatile s32 pad[10];

    v_init = 0x44;
    s3 = (s32) arg0;
    KEEP_NOVOL(s3);
    a3 = 0;
    s2 = *(s32 *) (s3 + 8);
    __asm__ volatile("la $17,D_800C87D8" : "=r"(s1) : "r"(s2) : "memory");
    *(volatile u16 *) ((char *) sp + 0x18) = 0;
    *(volatile u16 *) ((char *) sp + 0x1A) = 0;
    *(volatile u16 *) ((char *) sp + 0x1C) = v_init;
    v0 = *(s32 *) (s3 + 0x30);
    a0 = s2;
    v0 <<= 4;
    v0 += 0x10;
    *(volatile u16 *) ((char *) sp + 0x1E) = (u16) v0;
    *(volatile s32 *) ((char *) sp + 0x10) = s1;
    v0 = *(volatile u16 *) ((char *) sp + 0x18);
    a1 = *(volatile u16 *) ((char *) sp + 0x1A);
    v1 = *(volatile u16 *) ((char *) sp + 0x1C);
    a2 = *(volatile u16 *) ((char *) sp + 0x1E);
    a1 <<= 16;
    a1 |= v0;
    a2 <<= 16;
    __asm__ volatile(".set\tnoreorder\n\tjal\tfunc_8008F514\n\tor\t$6,$3,$6\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(v1) : "v0", "ra", "memory");
    v0 = s2 << 1;
    v0 += s2;
    v0 <<= 2;
    v0 += s2;
    v0 <<= 2;
    KEEP(s2);
    at = (s32 *) &D_800BBC70[0];
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    a0 = 0xA;
    at = (s32 *) &D_800BBC78[0];
    at = (s32 *) ((char *) at + v0);
    *at = a0;
    v1 |= 0x100;
    at = (s32 *) &D_800BBC70[0];
    at = (s32 *) ((char *) at + v0);
    *at = v1;
    v1 = (s32) &D_800BBC88[0];
    v1 += v0;
    *(s32 *) v1 = -0x78;
    *(s32 *) (v1 + 4) = -0x28;
    *(volatile s32 *) ((char *) sp + 0x20) = 8;
    *(volatile s32 *) ((char *) sp + 0x24) = 8;
    v0 = *(s32 *) (s3 + 0x30);
    s0 = 0;
    if (v0 > 0) {
        s5 = 0xB8D9;
        s4 = s1;
        s1 = s3;
        do {
            a1 = *(s32 *) (s1 + 0x34);
            a0 = s2;
            *(volatile s32 *) ((char *) sp + 0x10) = s4;
            a2 = *(volatile s32 *) ((char *) sp + 0x20);
            a3 = *(volatile s32 *) ((char *) sp + 0x24);
            func_8008F828(a0, a1 + s5, a2, a3);
            v0 = *(volatile s32 *) ((char *) sp + 0x24);
            v0 += 0x10;
            *(volatile s32 *) ((char *) sp + 0x24) = v0;
            v0 = *(s32 *) (s3 + 0x30);
            MEMORY_BARRIER();
            s0 += 1;
            s1 += 4;
        } while (s0 < v0);
    }
    a1 = (s32) &D_800C87D8;
    func_8008F72C(s2, (void *) a1);
}

void func_800896C4(s32 *arg0) {
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
    func_800FFF08(0xE, 0x19, 0xB8DD, 0);
}

void func_800897B0(volatile s32 *arg0) {
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

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_80089894);

extern s32 D_8004C6BC;

void func_80089E50(void) {
    extern s16 D_800BB3F0;
    extern s32 func_80092148(s32 *, s32);
    register s32 s0 asm("s0");
    register u8 *s1 asm("s1");
    register u8 *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    struct {
        s32 sp10;
        s32 sp14;
        s32 sp18;
        s32 sp1c;
    } sp;

    s0 = 0;
    s3 = 8;
    s1 = &D_800BB3F0;
    s2 = &D_800D0880;
    do {
        *(s16 *) s2 = s0 - 0x4000;
        if (func_80092148(&D_8004C6BC, s0) != 0) {
            *(s16 *) s1 = s3;
        } else {
            *(s16 *) s1 = 0;
        }
        s1 += 2;
        s0 += 1;
        s2 += 2;
    } while (s0 < 7);
    v0 = D_800BB4F0;
    a1 = s0;
    v1 = v0 * 92;
    v0 = a1 < 8;
    KEEP(s0);
    *(s32 *) ((char *) &D_800BB9BC[0] + v1) = s0;
    s0 = 8;
    if (v0) {
        s0 = a1;
    }
    a0 = 0x12;
    KEEP(a0);
    a2 = s0;
    KEEP(a2);
    v0 = 0x8C;
    sp.sp10 = v0;
    v0 = 0x54;
    sp.sp18 = v0;
    sp.sp14 = a2;
    v0 = 0x50;
    sp.sp1c = v0;
    func_8008FCC8(a0, a1, a2);
    a0 = 0xC;
    KEEP(a0);
    v1 = D_800BB4F0;
    a2 = (s32 *) &sp.sp10;
    v0 = v1 * 92;
    a1 = *(s32 *) ((char *) &D_800BB9BC[0] + v0);
    ((void (*)(s32, s32, s32 *, s32 *)) func_8008FAD8)(a0, a1, (s32 *) &sp.sp10, (s32 *) &sp.sp18);
    v1 = D_800BB4F0;
    v0 = 0x160;
    D_800BB3C0 = v0;
    v0 = 9;
    D_800BB3EC = v0;
    v0 = v1 * 92;
    a0 = v1 << 2;
    *(s32 *) ((char *) &D_800BB98C + v0) = 0;
    v0 = 0x2C;
    v1 += 1;
    *(s32 *) ((char *) &D_800D4584[0] + a0) = v0;
    D_800BB4F0 = v1;
}

void func_80089FEC(void) {
    D_800BB3C0 = 0x160;
}

s32 func_8008A000(void) {
    return D_800BB3C0 = -1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8008A014);

extern s32 D_8004C6C0;

void func_8008A2B0(void) {
    extern s16 D_800BB3F0;
    extern s32 func_80092148(s32 *, s32);
    register s32 s0 asm("s0");
    register u8 *s1 asm("s1");
    register u8 *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    struct {
        s32 sp10;
        s32 sp14;
        s32 sp18;
        s32 sp1c;
    } sp;

    s0 = 0;
    s3 = 8;
    s1 = &D_800BB3F0;
    s2 = &D_800D0880;
    do {
        *(s16 *) s2 = s0 - 0x3FF0;
        if (func_80092148(&D_8004C6C0, s0) != 0) {
            *(s16 *) s1 = s3;
        } else {
            *(s16 *) s1 = 0;
        }
        s1 += 2;
        s0 += 1;
        s2 += 2;
    } while (s0 < 8);
    a0 = 0x13;
    KEEP(a0);
    v1 = D_800BB4F0;
    MEMORY_BARRIER();
    a1 = s0;
    v0 = v1 * 92;
    *(s32 *) ((char *) &D_800BB9BC[0] + v0) = a1;
    MEMORY_BARRIER();
    s0 = 8;
    KEEP(s0);
    a2 = s0;
    KEEP(a2);
    v0 = 0x8C;
    sp.sp10 = v0;
    v0 = 0x54;
    sp.sp18 = v0;
    sp.sp14 = a2;
    v0 = 0x50;
    sp.sp1c = v0;
    func_8008FCC8(a0, a1, a2);
    a0 = 0xC;
    KEEP(a0);
    v1 = D_800BB4F0;
    a2 = (s32 *) &sp.sp10;
    v0 = v1 * 92;
    a1 = *(s32 *) ((char *) &D_800BB9BC[0] + v0);
    ((void (*)(s32, s32, s32 *, s32 *)) func_8008FAD8)(a0, a1, (s32 *) &sp.sp10, (s32 *) &sp.sp18);
    v1 = D_800BB4F0;
    v0 = 0x160;
    D_800BB3C0 = v0;
    v0 = 9;
    D_800BB3EC = v0;
    v0 = v1 * 92;
    a0 = v1 << 2;
    *(s32 *) ((char *) &D_800BB98C + v0) = 0;
    v0 = 0x2D;
    v1 += 1;
    *(s32 *) ((char *) &D_800D4584[0] + a0) = v0;
    D_800BB4F0 = v1;
}

void func_8008A440(void) {
    D_800BB3C0 = 0x160;
}

s32 func_8008A454(void) {
    return D_800BB3C0 = -1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8008A468);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8008A6F8);

extern void func_8008ABE4(volatile s16 *);
extern s32 D_80059594;
extern s16 D_800BB4FC;

void func_8008ABA8(void) {
    s32 v0;
    s32 a0;

    v0 = D_800BB4FC;
    a0 = v0 << 3;
    a0 -= v0;
    a0 <<= 3;
    func_8008ABE4((s32) &D_80059594 + a0);
}

void func_8008ABE4(volatile s16 *arg0) {
    s32 v0;

    v0 = -1;
    *(s16 *) ((char *) arg0 + 0x26) = v0;
    *(s16 *) ((char *) arg0 + 0x24) = v0;
    *(s16 *) ((char *) arg0 + 0x22) = v0;
    *(s16 *) ((char *) arg0 + 0x20) = v0;
    *(s16 *) ((char *) arg0 + 0x1E) = v0;
    *(s16 *) ((char *) arg0 + 0x1A) = v0;
    v0 = 0x30;
    *(s16 *) ((char *) arg0 + 0x2C) = 0;
    *(s16 *) ((char *) arg0 + 0x2A) = 0;
    *(s16 *) ((char *) arg0 + 0x32) = 0;
    *(s16 *) ((char *) arg0 + 0x0C) = 0;
    *(s16 *) ((char *) arg0 + 0x0E) = 0;
    *(s32 *) ((char *) arg0 + 0x34) = 0;
    *(s16 *) ((char *) arg0 + 0x18) = 0;
    *(s16 *) ((char *) arg0 + 0x14) = 0;
    *(s16 *) ((char *) arg0 + 0x12) = 0;
    *(s16 *) ((char *) arg0 + 0x16) = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8008AC30);

extern s32 D_800D4840;

s32 func_8008AE38(s32 arg0, s32 arg1) {
    s32 a0;
    s32 a2;
    s32 a3;
    s32 v0;
    s32 v1;

    a2 = 0;
    a0 = arg0 << 2;
    v0 = D_800D4840;
    a3 = 1;
    a0 += v0;
    v0 = *(s32 *) (a0 + 4);
    v1 = (s32) &D_800D0BBC[0];
    v0 = (u32) v0 >> 2;
    v0 <<= 2;
    a0 = v0 + v1;
loop:
    v0 = *(s32 *) a0;
    v1 = v0 & 0xFF;
    if (arg1 == v1)
        goto exit;
    if (v1 == a3) {
        v0 = 0;
        goto exit;
    }
    a2 += 1;
    a0 += 4;
    v0 = a2 < 0x100;
    if (v0)
        goto loop;
    v0 = 0;
exit:
    return v0;
}

void func_8008AEA0(s32 arg0, s32 arg1) {
    extern s32 func_800E6EDC(s32);
    extern void func_800E4668(s16 *, s16 *, s32);
    extern void func_800EF25C(s32, s32);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s16 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[6];

    s0 = arg0;
    s1 = arg1;
    a0 = s1;
    v0 = func_800E6EDC(a0);
    a0 = (s32) sp + 0x20;
    a1 = (s32) sp + 0x22;
    a2 = v0;
    func_800E4668((s16 *) a0, (s16 *) a1, a2);
    a3 = 0;
    v0 = s0;
    v0 <<= 1;
    v0 += s0;
    v0 <<= 2;
    v0 += s0;
    v0 <<= 2;
    KEEP_NOVOL(v0);
    a2 = v0;
    a1 = (s32) &D_800C87D8;
    at = (s16 *) ((char *) &D_800BBC9C[0] + a2);
    v0 = *at;
    a0 = *(s16 *) ((char *) sp + 0x20);
    v1 = 10;
    *(s32 *) ((char *) sp + 0x1C) = v1;
    v0 -= a0;
    v1 = (u32) v0 >> 31;
    v0 += v1;
    v0 >>= 1;
    v0 &= 0xFFFE;
    v0 += 8;
    *(s32 *) ((char *) sp + 0x18) = v0;
loop:
    at = (s16 *) ((char *) &D_800BBC9C[0] + a2);
    v1 = *at;
    at = (s16 *) ((char *) &D_800BBC9E[0] + a2);
    v0 = *at;
    v0 = v1 * v0;
    if (v0 < 0)
        v0 += 7;
    v0 >>= 3;
    v0 = a3 < v0;
    if (v0 != 0) {
        a3 += 1;
        *(s32 *) a1 = 0;
        a1 += 4;
        goto loop;
    }
    if (s1 == 0)
        goto skip_828;
    a0 = s0;
    v0 = (s32) &D_800C87D8;
    *(s32 *) ((char *) sp + 0x10) = v0;
    MEMORY_BARRIER();
    a2 = *(s32 *) ((char *) sp + 0x18);
    a3 = *(s32 *) ((char *) sp + 0x1C);
    func_8008F828(s0, s1, a2, a3);
skip_828:
    a1 = (s32) &D_800C87D8;
    func_8008F72C(s0, (s32 *) a1);
    a0 = 0x5C;
    a1 = 0;
    func_800EF25C(a0, a1);
    a0 = 0x5D;
    a1 = 0;
    func_800EF25C(a0, a1);
    a0 = 0x5E;
    a1 = 0;
    func_800EF25C(a0, a1);
}

extern s32 D_800D4630;
extern s32 D_800D4640;
extern void func_80043A90();
extern void func_80043BE8();

void func_8008AFF0(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 D_800D486A;
    extern void func_8008B120(s32);
    extern void func_8008C150();
    s32 s0 = arg1;
    s32 s1 = arg2;
    s32 v1;
    s32 v0;
    if ((arg0 | s0 | s1) == 0)
        return;
    v1 = D_800D486C;
    if (v1 == 0)
        goto l38;
    v0 = 1;
    if (v1 == 1)
        goto l60;
    goto e8;
l38:
    if (arg0 != 0)
        func_80090D30();
    if (s0 != 0)
        func_8008B120(s0);
    goto e8;
l60:
    if (arg0 != 0)
        func_80090D30();
    if (s0 != 0)
        func_8008B120(s0);
    if (s1 == 0)
        goto e4;
    v0 = D_800D486A;
    if (v0 == s1)
        goto e8;
    {
        s32 *p = &D_800D4630;
        s32 t;
        func_8008C150(s1);
        t = (*(u16 *) &D_800D486A << 16) >> 24;
        *p |= 1;
        func_80043A90(t, 0, 0);
        func_80043BE8(D_800D4640, 0x28);
    }
e4:
e8:
    func_800EF25C(0x5C, 0);
    func_800EF25C(0x5D, 0);
    func_800EF25C(0x5E, 0);
}

extern void func_800440CC();
extern void func_800127B4();
extern s32 D_8009EC18[];

void func_8008B120(s32 arg0) {
    s32 buf[4];
    u8 *p;
    s32 i;
    s32 c;
    s32 *dst;
    s32 t;
    s32 *b;
    func_800440CC();
    t = arg0;
    i = 0;
    c = 0xE10000;
    dst = buf;
    b = D_8009EC18;
    p = (u8 *) &b[t];
    do {
        *dst = *p + c;
        p++;
        i++;
        dst++;
    } while (i < 4);
    func_800127B4(buf[0], buf[1], buf[2], buf[3]);
}

extern void func_80044038();

void func_8008B19C(s32 arg0) {
    func_800440CC();
    func_80044038(arg0 + 0x10000);
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8008B1D0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8008B1D8);

extern u16 D_800D484C;

void func_8008B354(void) {
    u16 *p = &D_800D484C;

    *p |= 0x20;
}

void func_8008B370(void) {
    u16 *p = &D_800D484C;
    *p |= 0xA;
}

void func_8008B38C(void) {
    u16 *p = &D_800D484C;
    *p |= 4;
}

extern u8 D_800D4849;
extern s16 D_800D4854;
extern u16 D_800D4860;
extern u16 D_800D4862;
extern u16 D_800D4864;
extern u16 D_800D4866;

void func_8008B3A8(void) {
    extern u16 D_800D484C;
    extern void func_800FFF08(s32, s32, s32, s32);
    s32 s0;
    s32 v0;
    s32 v1;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");

    s0 = D_800D4849;
    func_800FFD70(0xE, &D_800E4D9C);
    func_800FFF08(0xE, 9, s0 | 0x8800, 0);
    v1 = D_800D4862;
    MEMORY_BARRIER();
    a0 = D_800D4864;
    MEMORY_BARRIER();
    a1 = D_800D4866;
    MEMORY_BARRIER();
    v0 = D_800D484C;
    MEMORY_BARRIER();
    D_800D4854 = (s16) s0;
    D_800D4866 = (u16) s0;
    v0 |= 4;
    D_800D4860 = (u16) v1;
    D_800D4862 = (u16) a0;
    D_800D4864 = (u16) a1;
    D_800D484C = (u16) v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_3", func_8008B448);

void func_8008B498(void) {
    s32 b = D_800D4849;
    s16 h = D_800D485A;

    if (h != b) {
        func_800246D4(0);
        D_800D485A = b;
        func_80068B3C(b);
        func_800686C8();
    }
    D_800D484C |= 4;
}

extern u16 D_800D484E;

void func_8008B508(void) {
    u16 v0 = D_800D484C;
    u8 v1 = D_800D4849;
    v0 |= 2;
    D_800D484E = v1;
    D_800D484C = v0;
}

extern void func_8008B554();
extern u8 D_800D484A;

void func_8008B534(void) {
    func_8008B554(1);
}

void func_8008B554(s32 arg0) {
    s32 flag;
    s32 r;
    u16 *p;

    flag = D_800D484A;
    r = func_800EF1A8(0x18);
    if (flag == r) {
        if (arg0 == 1)
            goto main;
        goto els;
    }
    if (arg0 != 0)
        goto els;
main:
    D_800D484E = D_800D4849;
    D_800D484C |= 2;
    goto end;
els:
    p = &D_800D484C;
    *p |= 4;
end:;
}
