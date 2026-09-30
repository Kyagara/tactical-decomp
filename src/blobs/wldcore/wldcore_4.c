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
extern u8 D_8004EAF4[];
extern void func_80092B04();
extern void func_80091174();
extern void func_8008FAD8();
extern void func_8008F514();
extern void func_8008EDBC();
extern s32 func_8008D2C8();
extern s16 D_800D486C;
extern s32 D_800D3CB8[];
extern s32 D_800BBC88[];
extern void func_80090D30();
extern s32 D_800BB504[];
extern s32 D_800BB508[];
extern s32 D_800BB510[];
extern s32 D_800BB514[];
extern s32 D_800BBC70[];
extern s16 D_800D0880[];
extern s32 D_800BB9BC[];
extern void func_8008FCC8();
extern s16 D_800D4852;
extern s32 D_800D3CD0[];
extern s32 D_800D3CD4[];
extern void func_8006C44C();
extern void func_8008F72C();
extern void func_8008F828();
extern s32 D_800BB9B0;
extern s16 D_800BBC9C[];
extern s16 D_800BBC9E[];
extern s16 D_800D4574;
extern s32 D_8004D950;
extern s32 func_8008CF14();
extern void func_8008E540();
extern void func_8008CB8C();
extern void func_8008D514();
extern void func_8008F284();
extern void func_8001DBA8();
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
extern s32 D_800BBC90[];
extern s32 D_800BBC80[];
extern s32 D_800D09AC;
extern s32 D_8009F27C;
extern s32 D_8009F280;
extern s32 D_800BB3EC;
extern s32 D_800BB98C[];
extern s32 D_800D0984;
extern s32 D_800D4644;
extern s32 D_800D4668;
extern s32 D_800D0AF8;
extern s32 D_8009F24C;
extern void func_8008D9A0();
extern void func_80069400(s32 arg0, s32 arg1);
extern u8 *func_80069E38(s32 arg0);
extern s32 D_8009EEFC;
extern s32 D_8009EF2C;
extern s32 D_8009EF3C;
extern s32 D_800E4D9C;
extern s32 D_800BBC8C[];
extern void func_80106A28(s32, s32, s32);
extern void func_800FFF08();
extern s16 D_800BB354;
extern void func_8010849C(s16, s16, s32);
extern s32 D_800BBC74[];
extern s32 D_800BBC98[];
extern s32 D_800D4624;
extern s32 D_800D462C;
extern void func_8006E860(s32 arg0, s32 arg1);
extern s16 D_800D485C;
extern s32 D_8009F2B0;
extern s32 D_8009F2B4;
extern s32 D_800BB4F4;
extern s32 D_800D4630;
extern s32 D_800D4640;
extern void func_80043A90();
extern void func_80043BE8();
extern void func_800440CC();
extern u16 D_800D484C;
extern u8 D_800D4849;
extern s16 D_800D4854;
extern u16 D_800D4860;
extern u16 D_800D4862;
extern u16 D_800D4864;
extern u16 D_800D4866;
extern u16 D_800D484E;
extern void func_8008B554();
extern u8 D_800D484A;
extern void func_8008B120(s32 arg0);
extern void func_8008B19C(s32 arg0);

void func_8008B5F4(void) {
    func_8008B554(0);
}

extern s32 D_800D4570;
extern s32 D_800D48FC;

void func_8008B614(void) {
    u16 *p = &D_800D484C;
    u16 a1v;
    u16 v0v;
    s32 v1;
    s32 v0b;
    a1v = *p;
    v0v = a1v | 8;
    *p = v0v;
    if ((v0v & 0x10) != 0) {
        D_800D4570 = 0;
        D_800D48FC = D_800D4849;
    }
    v1 = D_800D4570;
    MEMORY_BARRIER();
    v0b = D_800D48FC;
    if (v0b < v1) {
        v0b = a1v | 0xC;
        *p = v0b;
    } else {
        D_800D4570 = v1 + 1;
    }
}

extern u8 D_800D4848;
extern s16 D_800D485E;
extern s16 D_800D486E;
extern s16 D_800D4870;

void func_8008B68C(void) {
    extern unsigned short D_800D484C;
    extern s32 func_80022D10(s32, s32, s32);
    s32 s0;
    s32 s1;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 t0 asm("t0");
    register s32 *at asm("at");
    struct {
        s32 sp10;
        s32 sp14;
        s32 sp18;
        s32 sp1C;
        s32 sp20;
        s16 sp24;
        s16 sp26;
        s16 sp28;
        s16 sp2A;
        s32 sp2C;
        s16 sp30;
        s16 sp32;
        s32 sp34;
        s32 sp38;
        s32 sp3C;
        s16 sp40;
        s16 sp42;
        s16 sp44;
        s16 sp46;
        s32 sp48;
        s32 sp4C;
        s32 sp50;
        s32 sp54;
        s32 sp58;
        s32 sp5C;
    } sp;

    s0 = *(s32 *) &D_800D4848;
    KEEP(s0);
    a0 = (u32) s0 & 0xFF00;
    a0 = a0 >> 8;
    s1 = (u32) s0 >> 24;
    s0 = (u32) s0 >> 16;
    s0 = s0 & 0xFF;
    *(s16 *) &D_800D485E = (s16) a0;
    *(s16 *) &D_800D486E = (s16) s1;
    *(s16 *) &D_800D4870 = (s16) s0;
    func_80068AB4(a0);
    s1 = s1 - 0x80;
    func_800686C8();
    s0 = s0 - 0x78;
    a1 = (s32) &sp.sp20;
    KEEP(a1);
    v1 = D_800D485C;
    a0 = D_800BB988;
    v0 = v1 * 52;
    at = (s32 *) ((char *) &D_800BBC88[0] + v0);
    *(s32 *) at = s1;
    v1 = D_800D485C;
    v0 = v1 * 52;
    at = (s32 *) ((char *) &D_800BBC8C[0] + v0);
    *(s32 *) at = s0;
    func_800E19A4(a0 + 4, a1);
    __asm__ volatile(".set\tnoreorder\n\tlhu\t$2,38($sp)\n\tlhu\t$7,36($sp)\n\tlhu\t$3,40($sp)\n\tlhu\t$4,42($sp)\n\tlh\t$5,48($sp)\n\tlh\t$6,50($sp)\n\tsh\t$2,66($sp)\n\tsll\t$2,$2,16\n\tsra\t$2,$2,16\n\tsw\t$5,72($sp)\n\taddu\t$5,$0,$0\n\tsh\t$7,64($sp)\n\tsh\t$3,68($sp)\n\tsh\t$4,70($sp)\n\tsw\t$6,76($sp)\n\tsw\t$2,16($sp)\n\tlh\t$2,68($sp)\n\taddu\t$6,$0,$0\n\tsll\t$2,$2,2\n\tsw\t$2,20($sp)\n\tlh\t$2,70($sp)\n\tsll\t$7,$7,16\n\tsw\t$2,24($sp)\n\t.set\treorder" : : : "$2", "$3", "$4", "$5", "$6", "$7", "memory");
    a0 = sp.sp2C;
    a3 >>= 16;
    func_80022C24(a0, a1, a2, a3);
    a0 = sp.sp38;
    a1 = sp.sp48;
    a2 = sp.sp4C;
    func_80022D10(a0, a1, a2);
    __asm__ volatile(".set\tnoreorder\n\tori\t$2,$0,4\n\tsw\t$2,20($sp)\n\tlhu\t$3,64($sp)\n\tlhu\t$8,68($sp)\n\tlui\t$4,%%hi(D_800D485C)\n\tlh\t$4,%%lo(D_800D485C)($4)\n\tlhu\t$5,66($sp)\n\tlhu\t$6,70($sp)\n\tlw\t$2,76($sp)\n\tsll\t$5,$5,16\n\tor\t$5,$3,$5\n\tsll\t$6,$6,16\n\tsw\t$2,16($sp)\n\tlw\t$7,72($sp)\n\tjal\tfunc_8008F9BC\n\tor\t$6,$8,$6\n\t.set\treorder" : : : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$15", "$24", "$25", "hi", "lo", "ra", "memory");
    v1 = D_800D485C;
    v0 = v1 * 52;
    at = (s32 *) ((char *) &D_800BBC80[0] + v0);
    *(s32 *) at = 0;
    v0 = D_800D484C;
    v0 = v0 | 4;
    *(unsigned short *) &D_800D484C = (unsigned short) v0;
    return;
}

void func_8008B86C(void) {
    extern u16 D_800D484C;
    s32 v0;
    s32 v1;

    v1 = D_800D485C;
    v0 = v1 * 0x34;
    v1 = *(s32 *) ((char *) &D_800BBC70 + v0);
    v1 |= 0x10;
    *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
    v0 = D_800D484C;
    v1 = -1;
    D_800D485E = (s16) v1;
    v0 |= 0xC;
    D_800D484C = (u16) v0;
}

void func_8008B8DC(void) {
    extern s32 D_800BB990[];
    extern u16 D_800D484C;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");

    v0 = D_800D4849;
    a1 = -0x11;
    if (v0 != 0) {
        v0 = D_800D484C;
        a0 = D_800BB4F0;
        v0 |= 0x40;
        a0 -= 1;
        v1 = a0 * 92;
        D_800D484C = (u16) v0;
        v0 = *(s32 *) ((char *) &D_800BB98C + v1);
        a0 = v0 * 36;
        v0 = *(s32 *) ((char *) &D_800BB504[0] + a0);
        v0 &= a1;
        *(s32 *) ((char *) &D_800BB504[0] + a0) = v0;
        v0 = *(s32 *) ((char *) &D_800BB990[0] + v1);
        v1 = v0 * 36;
        v0 = *(s32 *) ((char *) &D_800BB504[0] + v1);
        v0 &= a1;
    } else {
        v0 = D_800D484C;
        v1 = D_800BB4F0;
        v0 &= 0xFFBF;
        v1 -= 1;
        a0 = v1 * 92;
        D_800D484C = (u16) v0;
        v0 = *(s32 *) ((char *) &D_800BB98C + a0);
        v1 = v0 * 36;
        v0 = *(s32 *) ((char *) &D_800BB504[0] + v1);
        v0 |= 0x10;
        *(s32 *) ((char *) &D_800BB504[0] + v1) = v0;
        v0 = *(s32 *) ((char *) &D_800BB990[0] + a0);
        v1 = v0 * 36;
        v0 = *(s32 *) ((char *) &D_800BB504[0] + v1);
        v0 |= 0x10;
    }
    *(s32 *) ((char *) &D_800BB504[0] + v1) = v0;
    v1 = (s32) &D_800D484C;
    KEEP(v1);
    v0 = *(u16 *) v1;
    v0 |= 4;
    *(u16 *) v1 = (u16) v0;
}

void func_8008BA84(void) {
    u8 temp_s0;

    temp_s0 = D_800D4849;
    func_800FFD70(0xE, &D_800E4D9C);
    func_800FFF08(0xE, 9, temp_s0 | 0x8800, 0);
    D_800D4854 = (s16) temp_s0;
    D_800D484C |= 4;
}

extern u8 D_800D484B;
extern s32 func_8002230C();

void func_8008BAEC(void) {
    extern u16 D_800D484C;
    s32 v0;
    s32 v1;
    s32 s0;
    s32 *at;

    v0 = func_8002230C();
    v1 = v0 << 1;
    v1 += v0;
    v1 >>= 15;
    if (v1 == 0)
        s0 = D_800D4849;
    if (v1 == 1)
        s0 = D_800D484A;
    if (v1 == 2)
        s0 = D_800D484B;
    v0 = D_800D484C;
    at = &D_800D484E;
    *(u16 *) at = s0;
    v0 |= 2;
    at = (s32 *) &D_800D484C;
    *(u16 *) at = v0;
}

extern void func_8008BB88();

void func_8008BB68(void) {
    func_8008BB88(1);
}

extern s32 D_80059374;

void func_8008BB88(s32 arg0) {
    u8 *p = &D_800D4848;
    s32 *q = &D_80059374;
    s32 v;
    volatile s32 pad[2];

    KEEP(p);
    v = func_80092148(q, (p[1] << 8) | p[2]);
    if (v == arg0) {
        D_800D484E = p[3];
        D_800D484C |= 2;
    } else {
        D_800D484C |= 4;
    }
}

void func_8008BC18(void) {
    func_8008BB88(0);
}

extern void func_8008BC58();

void func_8008BC38(void) {
    func_8008BC58(1);
}

extern s32 D_80059810;

void func_8008BC58(s32 arg0) {
    u8 *p = &D_800D4848;
    register u16 v asm("v0");
    register u8 w asm("v1");
    s32 r;

    KEEP(p);
    r = func_80092148(&D_80059810, p[1]);
    if (r == arg0) {
        v = D_800D484C;
        w = p[2];
        D_800D484E = w;
        v |= 2;
    } else {
        v = D_800D484C;
        v |= 4;
    }
    D_800D484C = v;
}

void func_8008BCE0(void) {
    func_8008BC58(0);
}

extern void func_8008BD20();

void func_8008BD00(void) {
    func_8008BD20(1);
}

extern s32 D_800D4564;

void func_8008BD20(s32 arg0) {
    u8 *p = &D_800D4848;
    register u16 v asm("v0");
    register u8 w asm("v1");
    s32 r;

    KEEP(p);
    r = func_80092148(&D_800D4564, p[1]);
    if (r == arg0) {
        v = D_800D484C;
        w = p[2];
        D_800D484E = w;
        v |= 2;
    } else {
        v = D_800D484C;
        v |= 4;
    }
    D_800D484C = v;
}

void func_8008BDA8(void) {
    func_8008BD20(0);
}

extern void func_800920E8();

void func_8008BDC8(void) {
    func_800920E8(&D_80059810, D_800D4849, 1);
    D_800D484C |= 4;
}

void func_8008BE10(void) {
    func_800920E8(&D_80059810, D_800D4849, 0);
    D_800D484C |= 4;
}

void func_8008BE58(void) {
    func_800920E8(&D_800D4564, D_800D4849, 1);
    D_800D484C |= 4;
}

void func_8008BEA0(void) {
    func_800920E8(&D_800D4564, D_800D4849, 0);
    D_800D484C |= 4;
}

extern s32 D_800D4874;

void func_8008BEE8(void) {
    u32 t = *(u32 *) &D_800D4848;
    u16 v = D_800D484C;
    t = (t << 8) >> 16;
    v |= 4;
    D_800D4874 = t;
    D_800D484C = v;
}

void func_8008BF1C(void) {
    extern u16 D_800D484C;
    u16 *p = &D_800D4852;
    u32 t;
    register u16 v asm("v0");
    u16 w;
    t = *(u32 *) &D_800D4848;
    v = *p;
    w = D_800D484C;
    t = (t << 8) >> 16;
    v = v + t;
    w |= 4;
    *p = v;
    D_800D484C = w;
}

void func_8008BF5C(void) {
    extern u16 D_800D484C;
    u16 *p = &D_800D4852;
    u32 t;
    register u16 v asm("v0");
    u16 w;
    t = *(u32 *) &D_800D4848;
    v = *p;
    w = D_800D484C;
    t = (t << 8) >> 16;
    v = v - t;
    w |= 4;
    *p = v;
    D_800D484C = w;
}

extern u16 D_800D4868;

void func_8008BF9C(void) {
    s32 temp;

    temp = D_800D4849;
    D_8004D950 &= ~0x800;
    D_800D4868 = temp;
    D_800D0984 = temp;
    if (temp != 2) {
        D_800D09AC = D_800D4874;
    }
    D_8009F2B0 = -32;
    D_8009F2B4 = 0x54;
    D_800BB4F4 = 10;
    D_800D484C |= 0x84;
}

void func_8008C02C(void) {
    u16 *p = &D_800D484C;
    register s32 t asm("v1");
    register u16 v asm("a0");
    t = D_8004D950;
    v = *p;
    t |= 0x800;
    v &= 0xFF7F;
    v |= 4;
    D_8004D950 = t;
    *p = v;
}

void func_8008C05C(void) {
    extern u16 D_800D484C;
    s32 *a0;
    s32 v0;
    s32 v1;

    a0 = &D_800D4874;
    v1 = D_800D4852;
    v0 = *a0;
    D_800D4852 = 0;
    v0 += v1;
    v1 = 0xFFFF;
    *a0 = v0;
    if (v1 < v0) {
        *a0 = v1;
    }
    v0 = *a0;
    if (v0 < 0) {
        *a0 = 0;
    }
    v0 = D_800D484C;
    v1 = *a0;
    v0 |= 4;
    D_800D09AC = v1;
    D_800D484C = (u16) v0;
}

extern void func_80044018();

void func_8008C0D0(void) {
    s32 a0;
    a0 = D_800D4849;
    ((void (*)(u8)) func_80044018)(a0);
    D_800D484C |= 4;
}

extern void func_8008C150();

void func_8008C110(void) {
    s32 a0;
    a0 = D_800D4849;
    ((void (*)(u8)) func_8008C150)(a0);
    D_800D484C |= 4;
}

extern void func_80043A38();
extern void func_800435C4();
extern s32 func_80043708();

void func_8008C150(s32 arg0) {
    extern void func_800439C0();
    extern void func_8001DBA8();
    extern u16 D_800D486A;
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    v0 = D_800D486A;

    s1 = arg0;
    KEEP(s1);
    v1 = v0 << 16;
    v0 &= 0xFF;
    if (v0 == 0) {
        s0 = v1 >> 24;
        goto after;
    }
    s0 = v1 >> 24;
    USE_NOVOL(s0);
    goto call_a38;
call_a38:
    func_80043A38();
after:
    if (s0 != 0) {
        a0 = s0;
        func_800439C0(a0);
    } else {
        s0 = 2;
    }
    a0 = 2;
    func_8001DBA8(a0);
    a0 = s1;
    a1 = s0;
    func_800435C4(a0, a1);
    v0 = s0 << 8;
    v0 |= s1;
    at = (s32 *) &D_800D486A;
    *(s16 *) at = v0;
loop:
    v0 = func_80043708();
    if (v0 == 0) {
        v0 = s0 << 2;
        goto final;
    }
    v0 = s0 << 2;
    USE_NOVOL(v0);
    a0 = 0;
    func_8001DBA8(a0);
    goto loop;
final:
    USE_NOVOL(v0);
    at = (s32 *) ((char *) &D_800D4630 + v0);
    *at = s1;
    D_800D463C = s0;
}

void func_8008C214(void) {
    u16 v0 = D_800D484C;
    u8 v1 = D_800D4849;
    v0 |= 4;
    D_800D486C = v1;
    D_800D484C = v0;
}

void func_8008C240(void) {
    s32 v1;
    s32 v0;
    u32 w;
    s32 h = D_800D4852;
    s32 w2 = D_800D4874;
    register s32 b3 asm("v1");
    v1 = w2 + h;
    if (v1 > 0xFFFF) {
        v1 = 0xFFFF;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    w = *(u32 *) &D_800D4848;
    v0 = (w >> 8) & 0xFFFF;
    if (v1 == v0) {
        v0 = D_800D484C | 2;
        b3 = w >> 24;
        D_800D484E = b3;
    } else {
        v0 = D_800D484C | 4;
    }
    D_800D484C = v0;
}

void func_8008C2CC(void) {
    s32 v1;
    s32 v0;
    u32 w;
    s32 h = D_800D4852;
    s32 w2 = D_800D4874;
    register s32 b3 asm("v1");
    v1 = w2 + h;
    if (v1 > 0xFFFF) {
        v1 = 0xFFFF;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    w = *(u32 *) &D_800D4848;
    v0 = (w >> 8) & 0xFFFF;
    if (v1 != v0) {
        v0 = D_800D484C | 2;
        b3 = w >> 24;
        D_800D484E = b3;
    } else {
        v0 = D_800D484C | 4;
    }
    D_800D484C = v0;
}

void func_8008C358(void) {
    s32 v1;
    s32 v0;
    u32 w;
    s32 h = D_800D4852;
    s32 w2 = D_800D4874;
    register s32 b3 asm("v1");
    v1 = w2 + h;
    if (v1 > 0xFFFF) {
        v1 = 0xFFFF;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    w = *(u32 *) &D_800D4848;
    v0 = (w >> 8) & 0xFFFF;
    if (v1 < v0) {
        v0 = D_800D484C | 2;
        b3 = w >> 24;
        D_800D484E = b3;
    } else {
        v0 = D_800D484C | 4;
    }
    D_800D484C = v0;
}

void func_8008C3E8(void) {
    s32 v1;
    s32 v0;
    u32 w;
    s32 h = D_800D4852;
    s32 w2 = D_800D4874;
    register s32 b3 asm("v1");
    v1 = w2 + h;
    if (v1 > 0xFFFF) {
        v1 = 0xFFFF;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    w = *(u32 *) &D_800D4848;
    v0 = (w >> 8) & 0xFFFF;
    if (v0 < v1) {
        v0 = D_800D484C | 2;
        b3 = w >> 24;
        D_800D484E = b3;
    } else {
        v0 = D_800D484C | 4;
    }
    D_800D484C = v0;
}

void func_8008C478(void) {
    extern u16 D_800D486A;
    s32 *p = &D_800D4630;
    s32 t = D_800D4849;
    s32 m = -2;
    s32 v;
    u16 w0;
    u16 w1;
    v = *p & m;
    *p = v;
    func_80043BE8(0, t * 3, t);
    w0 = D_800D484C;
    w1 = D_800D486A;
    w0 |= 4;
    w1 &= 0xFF00;
    D_800D484C = w0;
    D_800D486A = w1;
}

void func_8008C4E8(void) {
    extern u16 D_800D484C;
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register void *sp asm("sp");
    extern u16 D_800D486A;
    v0 = D_800D486A;

    v0 <<= 16;
    if (v0 == 0)
        goto epi;
    a0 = v0 >> 24;
    v1 = (s32) &D_800D4630;
    a1 = 0;
    v0 = *(s32 *) v1;
    v0 |= 1;
    *(s32 *) v1 = v0;
    s0 = D_800D4849;
    a2 = 0;
    func_80043A90(a0, a1, a2);
    a0 = D_800D4640;
    a1 = s0 << 1;
    a1 += s0;
    func_80043BE8(a0, a1);
epi:
    v0 = D_800D484C;
    v0 |= 4;
    D_800D484C = v0;
}

void func_8008C574(void) {
    s32 *a = &D_800D0AB8;
    s32 v1;
    u16 v2;

    v1 = *a;
    v1 &= ~2;
    v1 |= 8;
    *a = v1;
    func_80069400(2, D_800D4849);
    v2 = D_800D484C;
    v2 |= 4;
    D_800D484C = v2;
}

void func_8008C5D0(void) {
    extern void func_80069400();
    s32 *a = &D_800D0AB8;
    u16 *p = &D_800D484C;
    u8 t;
    u16 v1;
    register s32 v0 asm("v0");
    u16 v2;
    v0 = *a;
    v1 = *p;
    v0 |= 2;
    v1 &= 0xFEFF;
    *a = v0;
    *p = v1;
    t = D_800D4849;
    func_80069400(0, t);
    v2 = *p | 4;
    *p = v2;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008C638);

void func_8008C760(void) {
    if (D_800BC2F0 & 0x20) {
        u16 *p = &D_800D484C;
        *p |= 4;
    }
    {
        u16 *q = &D_800D484C;
        *q |= 8;
    }
}

extern s16 D_800D4872;

void func_8008C7AC(void) {
    extern u16 D_800D484C;
    s32 v0;
    s32 a0;
    s32 v1;
    volatile s32 pad[2];

    v0 = *(s32 *) &D_800D4848;
    a0 = D_800D4849;
    v1 = 0xFF0000;
    if (v0 & v1) {
        D_800D4872 = (s16) a0;
    }
    func_8008B120(a0);
    D_800D484C |= 4;
}

void func_8008C808(void) {
    func_800440CC();
    D_800D4872 = 0;
    D_800D484C |= 4;
}

extern s32 D_800D099C;
extern s32 D_800BB4F8;
extern s32 D_800D0988;

void func_8008C844(void) {
    s32 w;
    s32 b;
    u16 v;
    w = *(s32 *) &D_800D4848;
    D_800D099C = 0;
    b = ((u32) w << 8) >> 16;
    D_800BB4F8 = b * 60;
    MEMORY_BARRIER();
    v = D_800D484C;
    D_800D0988 = (u32) w >> 24;
    v |= 4;
    D_800D484C = v;
}

void func_8008C898(void) {
    extern u16 D_800D484C;
    register s32 v0 asm("v0");
    register s32 a0 asm("a0");
    register s32 v1 asm("v1");
    volatile s32 pad[2];

    v0 = *(s32 *) &D_800D4848;
    a0 = D_800D4849;
    v1 = 0xFF0000;
    if (v0 & v1) {
        v0 = a0 | 0x4000;
        D_800D4872 = (s16) v0;
    }
    func_8008B19C(a0);
    D_800D484C |= 4;
}

void func_8008C8F8(void) {
    extern u16 D_800D484C;
    extern void func_80018240(s32, s32);
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    volatile s32 pad[2];
    register s32 x asm("v0");

    x = D_800D484A;
    a0 = x << 1;
    a1 = a0 + x;
    v1 = *(s32 *) &D_800D4848;
    v1 &= 0xFF00;
    a0 = v1 >> 2;
    if (a1 == 0) {
        a1 = 1;
    }
    if (a0 == 0x3FC0) {
        a0 = 0x3FFF;
    }
    func_80018240(a0, a1);
    D_800D484C |= 4;
}

void func_8008C968(void) {
    extern u16 D_800D484C;
    extern s16 D_800D486A;
    extern void func_800439C0(s32);
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s16 *s1 asm("s1");
    register u8 *s0 asm("s0");

    s1 = &D_800D486A;
    v0 = *s1;
    if (v0 != 0) {
        v1 = -2;
        s0 = (u8 *) &D_800D4630;
        v0 = *(s32 *) s0 & v1;
        *(s32 *) s0 = v0;
        func_80043A38();
        a0 = *(u16 *) s1;
        a0 <<= 16;
        a0 >>= 24;
        func_800439C0(a0);
        v0 = *(u16 *) s1;
        s0 += 4;
        v0 <<= 16;
        v0 >>= 24;
        v0 <<= 2;
        v0 += (s32) s0;
        *(s32 *) v0 = 0;
        D_800D463C = 0;
        *s1 = 0;
    }
    v0 = D_800D484C;
    v0 |= 4;
    D_800D484C = (u16) v0;
}

void func_8008CA18(void) {
    s32 a0;
    s32 a1;
    s32 a2;
    volatile s32 pad[4];

    a0 = D_800D4849;
    a1 = D_800D484A;
    a2 = D_800D484B;
    func_80106A28(a0, a1, a2);
    D_800D484C |= 4;
}

void func_8008CA68(void) {
    extern u16 D_800D484C;
    u8 *p = &D_800D4848;
    u8 b;
    s32 r;
    s32 off;
    u32 x;

    KEEP(p);
    b = p[3];
    r = func_800EF1A8(0x18);
    off = -0x8000;
    if (r == b) {
        x = (*(u32 *) p << 8) >> 16;
        x += off;
        D_800D4852 += x;
    }
    D_800D484C |= 4;
}

void func_8008CAE8(void) {
    u16 *p;
    u16 v;

    if (!(D_8004D950 & 8)) {
        p = &D_800D484C;
        v = *p | 4;
    } else {
        p = &D_800D484C;
        v = *p | 8;
    }
    *p = v;
}

void func_8008CB30(void) {
    extern u16 D_800D484C;
    u16 a1;
    u8 a2;
    register u16 a0 asm("a0");

    u16 v0;
    u16 v1;
    a1 = D_800D4862;
    MEMORY_BARRIER();
    a2 = D_800D4849;
    MEMORY_BARRIER();
    v1 = D_800D4864;
    MEMORY_BARRIER();
    v0 = D_800D484C;
    MEMORY_BARRIER();
    a0 = D_800D4866;
    MEMORY_BARRIER();
    v0 |= 4;
    D_800D4860 = a1;
    MEMORY_BARRIER();
    D_800D4862 = v1;
    MEMORY_BARRIER();
    D_800D4864 = a0;
    MEMORY_BARRIER();
    D_800D4866 = a2;
    MEMORY_BARRIER();
    D_800D484C = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008CB8C);

extern u8 D_800D3CB0[];
extern s32 D_800D4568;

void func_8008CDF0(void) {
    extern s32 func_800EF1A8(s32);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[8];
    v0 = D_800D4568;

    s2 = 0;
    if (v0 > 0) {
        s0 = (s32) &D_800D3CB8[0];
        s1 = 0;
        do {
            a0 = (s32) &D_800D3CB0[0] + s1;
            a1 = (s32) sp + 16;
            a2 = (s32) sp + 32;
            func_8001D578((void *) a0, (void *) a1, (void *) a2);
            v0 = *(volatile s32 *) ((char *) sp + 16);
            at = (s32 *) ((char *) &D_800D3CD0[0] + s1);
            *at = v0;
            v0 = *(volatile s32 *) ((char *) sp + 20);
            at = (s32 *) ((char *) &D_800D3CD4[0] + s1);
            *at = v0;
            v0 = *(volatile s32 *) ((char *) sp + 16);
            v0 += 0x80;
            if ((u32) v0 >= 0x101) {
                v0 = *(s32 *) s0 | 0x10;
            } else {
                v0 = *(volatile s32 *) ((char *) sp + 20);
                v0 += 0x74;
                if ((u32) v0 >= 0xED) {
                    v0 = *(s32 *) s0 | 0x10;
                } else if (D_8004D950 & 0x10) {
                    v0 = *(s32 *) s0 | 0x10;
                } else {
                    v0 = func_800EF1A8(s2 + 0x200);
                    if (v0 == 0) {
                        v0 = *(s32 *) s0 | 0x10;
                    } else {
                        v0 = *(s32 *) s0;
                        v0 &= -0x11;
                    }
                }
            }
            *(s32 *) s0 = v0;
            s0 += 0x34;
            v0 = D_800D4568;
            s2 += 1;
            if (s2 < v0) {
                s1 += 0x34;
            } else {
                s1 += 0x34;
            }
        } while (s2 < v0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008CF14);

extern s32 D_800D3CC0[];

s32 func_8008D060(s32 arg0, s32 arg1) {
    extern s32 func_800EF1A8(s32);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[2];

    s3 = 0xFFFFFF;
    v0 = D_800D4568;
    s1 = 0;
    s2 = 0;
    *(s32 *) ((char *) sp + 48) = arg0;
    *(s32 *) ((char *) sp + 52) = arg1;
    if (v0 <= 0)
        goto epi;
    s0 = 0;
loop:
    a0 = s1 + 0x200;
    v0 = func_800EF1A8(a0);
    if (v0 == 0)
        goto next;
    at = (s32 *) ((char *) D_800D3CB8 + s0);
    v0 = *at;
    v0 &= 0x18;
    if (v0 != 0)
        goto next;
    at = (s32 *) ((char *) D_800D3CD0 + s0);
    v1 = *at;
    a0 = *(s32 *) ((char *) sp + 48);
    v0 = v1 - 0xA;
    if (a0 < v0)
        goto next;
    v0 = v1 + 0xA;
    if (v0 < a0)
        goto next;
    at = (s32 *) ((char *) D_800D3CD4 + s0);
    v1 = *at;
    a0 = *(s32 *) ((char *) sp + 52);
    v0 = v1 - 0xE;
    if (a0 < v0)
        goto next;
    v0 = v1 + 6;
    if (v0 < a0)
        goto next;
    at = (s32 *) ((char *) D_800D3CC0 + s0);
    v1 = *at;
    v0 = v1 < s3;
    if (v0 == 0)
        goto next;
    s2 = s1 + 1;
    s3 = v1;
next:
    v0 = D_800D4568;
    s1 += 1;
    if (s1 < v0) {
        s0 += 0x34;
        goto loop;
    }
epi:
    v0 = s2;
    return v0;
}

s32 func_8008D194(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    extern s32 func_8008D060(s32, s32);
    register s32 s0 asm("s0") = (s32) arg2;
    register s32 s1 asm("s1") = (s32) arg3;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");

    *(volatile s32 *) ((char *) sp + 0x20) = a0;
    *(volatile s32 *) ((char *) sp + 0x24) = a1;
    *(volatile s32 *) arg2 = 0;
    *(volatile s32 *) arg3 = 0;
    a0 = *(s32 *) ((char *) sp + 0x20);
    a1 = *(s32 *) ((char *) sp + 0x24);
    v0 = func_8008D060(a0, a1);
    a2 = v0;
    if (a2 == 0)
        goto end;
    v1 = a2 - 1;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    at = &D_800D3CD0[0];
    at = (s32 *) ((char *) at + v0);
    a0 = *at;
    at = &D_800D3CD4[0];
    at = (s32 *) ((char *) at + v0);
    v0 = *at;
    v1 = *(s32 *) ((char *) sp + 0x20);
    a1 = v0 - 4;
    if (a0 < v1) {
        v0 = v1 - 2;
        if (v0 < a0)
            v0 = a0 - v1;
        else
            v0 = -2;
        *arg2 = v0;
    }
    v1 = *(s32 *) ((char *) sp + 0x20);
    if (v1 < a0) {
        v0 = v1 + 2;
        if (a0 < v0)
            v0 = a0 - v1;
        else
            v0 = 2;
        *arg2 = v0;
    }
    v1 = *(s32 *) ((char *) sp + 0x24);
    if (a1 < v1) {
        v0 = v1 - 2;
        if (v0 < a1)
            v0 = a1 - v1;
        else
            v0 = -2;
        *arg3 = v0;
    }
    v1 = *(s32 *) ((char *) sp + 0x24);
    if (v1 < a1) {
        v0 = v1 + 2;
        if (a1 < v0)
            v0 = a1 - v1;
        else
            v0 = 2;
        *arg3 = v0;
    }
end:
    v0 = a2;
    return v0;
}

s32 func_8008D2C8(s32 arg0, s32 *arg1) {
    extern s32 func_800EF1A8(s32);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 *p asm("s2");
    register s32 a0 asm("a0");
    register s32 *ap asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    volatile s32 pad[2];

    s1 = arg0;
    USE_NOVOL(s1);
    p = arg1;
    KEEP_NOVOL(p);
    v0 = 0x16;
    USE_NOVOL(v0);
    if (s1 != v0)
        goto normal;
    a0 = 0x65;
    v0 = func_800EF1A8(a0);
    s0 = v0 + 1;
    if (s0 <= 0)
        goto epi;
    v1 = 0;
    a0 = 0xB8ED;
    ap = p;
loop:
    v0 = v1 + a0;
    *ap = v0;
    ap += 1;
    v1 += 1;
    if (v1 < s0)
        goto loop;
    goto epi;
normal:
    v0 = s1 << 2;
    v1 = D_80094DF8;
    v0 += v1;
    v1 = *(u8 *) (v0 + 3);
    if (v1 != 1) {
        s0 = 0;
        goto epi;
    }
    s0 = 3;
    a0 = 0x90;
    USE_NOVOL(a0);
    USE_NOVOL(p);
    v0 = 0xB85D;
    p[0] = v0;
    v0 = 0xB85E;
    p[1] = v0;
    v0 = 0xB85F;
    p[2] = v0;
    v0 = func_800EF1A8(a0);
    if (v0 == 0)
        goto epi;
    if (s1 == 9)
        goto value;
    v0 = 0xC;
    if (s1 == v0)
        goto value;
    v0 = 0xE;
    if (s1 != v0)
        goto epi;
value:
    v0 = s0 << 2;
    v0 += (s32) p;
    KEEP_NOVOL(v0);
    MEMORY_BARRIER();
    v1 = 0xB860;
    KEEP(v1);
    *(s32 *) v0 = v1;
    s0 += 1;
epi:
    return s0;
}

extern u16 D_800D4654;
extern u8 D_8009EDD3;

s32 func_8008D3C0(s32 arg0, s32 *arg1) {
    s32 temp_s0;
    register s32 var_s1 asm("s1");
    register s32 var_s2 asm("s2");
    register s32 *var_s3 asm("s3");
    register u8 *var_s4 asm("s4");
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    u8 *var_a0;
    u8 *var_base;
    s32 var_v0;
    volatile char pad1[8];

    var_s3 = arg1;
    if (arg0 == 0x14) {
        return -1;
    }
    var_v0 = 0;
    if (func_800EF1A8(arg0 + 0x267) != 0) {
        return var_v0;
    }
    if (func_80091238(D_8009F254, 4) == 0) {
        return var_v0;
    }
    var_s5 = 0;
    var_s1 = 0;
    var_base = (u8 *) &D_800D4654;
    var_a0 = var_base;
loop_6:
    if (*(s32 *) var_a0 != 0) {
        var_s5 += 1;
        var_s1 += 1;
        var_a0 += 4;
        if (var_s1 >= 4) {
        } else {
            goto loop_6;
        }
    }
    var_s1 = 0;
    if (var_s5 == 1) {
        temp_s0 = *(s32 *) var_base;
        *var_s3 = temp_s0 + 0xA7FF;
        return 1;
    }
    var_s2 = 0;
    if (var_s5 > 0) {
        var_s7 = 0xA7FF;
        var_s6 = 5;
        var_s4 = (u8 *) &D_800D4654;
        do {
            temp_s0 = *(s32 *) var_s4;
            if (func_800EF1A8(*((u8 *) &D_8009EDD3 + temp_s0) + 0x292) == 0) {
                *var_s3 = temp_s0 + var_s7;
                var_s2 += 1;
                var_s3 += 1;
                if (var_s2 == var_s6) {
                    break;
                }
            }
            var_s1 += 1;
            var_s4 += 4;
        } while (var_s1 < var_s5);
    }
    var_v0 = var_s2;

    return var_v0;
}

void func_8008D514(void) {
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008D51C);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008D524);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008D800);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008D9A0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008DBFC);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008DF98);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008DFA0);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008E2BC);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008E540);

s32 func_8008EC38(s32 arg0, s32 *arg1) {
    extern s32 func_8008ED00();
    extern s32 func_8001BE1C(s32, s32 *);
    extern s32 D_800D0B14[];
    extern s32 D_8009F2C0[];
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 *a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s0 = arg1;
    v0 = func_8008ED00();
    if (v0 == 0)
        goto false;
    a0 = (s32) arg1;
    s0 = D_800D0B14;
    KEEP_NOVOL(s0);
    a1 = s0;
    func_8008EDBC((s32 *) a0, (s32 *) a1);
    v0 = *(s32 *) ((char *) s0 - 28);
    v0 |= 1;
    *(s32 *) ((char *) s0 - 28) = v0;
    MEMORY_BARRIER();
    USE_NOVOL(v0);
    goto load_fields;
load_fields:
    a1 = D_8009F2C0;
    KEEP_NOVOL(a1);
    v0 = a1[0];
    v1 = a1[1];
    a0 = a1[2];
    *(s32 *) ((char *) s0 - 16) = v0;
    *(s32 *) ((char *) s0 - 12) = v1;
    *(s32 *) ((char *) s0 - 8) = a0;
    v0 = a1[3];
    USE_NOVOL(v0);
    *(s32 *) ((char *) s0 - 4) = v0;
    MEMORY_BARRIER();
    v0 = *(s32 *) ((char *) s0 - 0);
    v1 = *(s32 *) ((char *) s0 - 16);
    v0 -= v1;
    a0 = v0 * v0;
    v0 = *(s32 *) ((char *) s0 + 4);
    v1 = *(s32 *) ((char *) s0 - 12);
    v0 -= v1;
    v1 = v0 * v0;
    *(s32 *) ((char *) s0 - 20) = 0;
    v0 = func_8001BE1C(a0 + v1, a1);
    v1 = v0 >> 8;
    *(s32 *) ((char *) s0 - 24) = v1;
    v0 = 1;
    goto epi;
    false : v0 = 0;
epi:
    return v0;
}

extern s32 D_8009F2C4;

s32 func_8008ED00(void *arg0) {
    extern s32 D_8009F2C0;
    s32 a0;
    s32 a1;
    s32 v0;
    s32 v1;

    a1 = *(s32 *) arg0;
    v0 = a1 < -0x40;
    if (v0 == 0)
        goto lower;
    v0 = 0x80;
    v1 = D_8009F2C0;
    v0 -= v1;
    v0 = v0 < 0x21;
    if (v0 == 0) {
        v0 = 1;
        goto end;
    }
    v0 = 1;
lower:
    v0 = a1 < 0x49;
    if (v0 != 0)
        goto middle;
    v0 = D_8009F2C0 + 0x74;
    v0 = v0 < 0x21;
    if (v0 == 0) {
        v0 = 1;
        goto end;
    }
    v0 = 1;
middle:
    a0 = *(s32 *) ((char *) arg0 + 4);
    v0 = a0 < -0x40;
    if (v0 == 0)
        goto upper;
    v0 = 0x50;
    v1 = D_8009F2C4;
    v0 -= v1;
    v0 = v0 < 0x21;
    if (v0 == 0) {
        v0 = 1;
        goto end;
    }
    v0 = 1;
upper:
    v0 = a0 < 0x41;
    if (v0 != 0) {
        v0 = 0;
        goto end;
    }
    v0 = 0;
    v0 = D_8009F2C4 + 0x40;
    v0 = v0 < 0x21;
    if (v0 != 0) {
        v0 = 0;
        goto end;
    }
    v0 = 0;
    v0 = 1;
end:
    return v0;
}

void func_8008EDBC(s16 *arg0, s32 *arg1) {
    s32 v0;
    s32 v1;
    s32 a0;
    v0 = arg0[0];
    v1 = arg0[1];
    a0 = -v0;
    v1 = -v1;
    if (a0 < -0x74)
        a0 = -0x74;
    if (a0 >= 0x81)
        a0 = 0x80;
    v0 = v1 < -0x40;
    if (v0 != 0)
        v1 = -0x40;
    v0 = v1 < 0x51;
    if (v0 == 0)
        v1 = 0x50;
    ((volatile s32 *) arg1)[0] = a0;
    arg1[1] = v1;
}

extern s32 D_800D0AFC;
extern s32 D_800D0B00;
extern s32 D_800D0B04;
extern s32 D_800D0B08;
extern s32 D_800D0B18;

s32 func_8008EE10(void) {
    extern s32 D_8009F2C0[];
    extern s32 D_800D0B14;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 *a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 t0 asm("t0");
    register s32 at asm("at");

    v0 = D_800D0B14;
    a1 = D_800D0B04;
    t0 = D_800D0B00;
    v0 -= a1;
    __asm__("mult %0,%1" : : "r"(v0), "r"(t0) : "hi", "lo");
    __asm__ volatile("mflo %0" : "=r"(v0));
    v1 = D_800D0AFC;
    __asm__("div $zero,%0,%1" : : "r"(v0), "r"(v1) : "hi", "lo");
    if (v1 != 0)
        goto div1_nonzero;
    __asm__(".word 0x0007000d");
div1_nonzero:
    __asm__("addiu %0,$zero,-1" : "=r"(at));
    if (v1 != at)
        goto div1_ok;
    at = (s32) 0x80000000;
    if (v0 != at)
        goto div1_ok;
    __asm__(".word 0x0006000d");
div1_ok:
    __asm__ volatile("mflo %0" : "=r"(a2));
    a0 = D_800D0B08;
    v0 = D_800D0B18;
    v0 -= a0;
    v0 *= t0;
    __asm__("div $zero,%0,%1" : : "r"(v0), "r"(v1) : "hi", "lo");
    if (v1 != 0)
        goto div2_nonzero;
    __asm__(".word 0x0007000d");
div2_nonzero:
    __asm__("addiu %0,$zero,-1" : "=r"(at));
    if (v1 != at)
        goto div2_ok;
    at = (s32) 0x80000000;
    if (v0 != at)
        goto div2_ok;
    __asm__(".word 0x0006000d");
div2_ok:
    __asm__("mflo %0" : "=r"(v0));
    a3 = &D_8009F2C0[0];
    KEEP_NOVOL(a3);
    v1 = t0 < v1;
    KEEP_WITH_NOVOL(a1, a2);
    a1 += a2;
    a3[0] = a1;
    MEMORY_BARRIER();
    a0 += v0;
    at = (s32) &D_8009F2C4;
    *(s32 *) at = a0;
    if (v1 == 0)
        goto copy;
increment:
    v0 = t0 + 1;
    at = (s32) &D_800D0B00;
    *(s32 *) at = v0;
    v0 = 1;
    goto end;
copy:
    a1 = (s32) &D_800D0B14;
    KEEP_NOVOL(a1);
    v0 = ((s32 *) a1)[0];
    v1 = ((s32 *) a1)[1];
    a0 = ((s32 *) a1)[2];
    a3[0] = v0;
    a3[1] = v1;
    a3[2] = a0;
    MEMORY_BARRIER();
    v0 = ((s32 *) a1)[3];
    *(volatile s32 *) ((char *) a3 + 12) = v0;
    v1 = D_800D0AF8;
    at = (s32) &D_800D0AF8;
    v0 = 0;
    v1 ^= 1;
    *(s32 *) at = v1;
end:
    return v0;
}

void func_8008EF3C(s32 *arg0) {
    typedef struct {
        s32 e0;
        s32 e4;
        s32 e8;
        s32 eC;
    } T4;
    typedef struct {
        s32 sp10;
        s32 sp14;
        T4 l;
    } T6;
    extern s32 D_8009F2C0;
    T6 st;
    s32 t;
    s32 u;
    s32 *s0;
    s32 v1;

    s0 = arg0;
    st.l = *(T4 *) &D_8009F2C0;
    t = D_8009F27C + s0[0];
    st.sp10 = t;
    st.sp14 = D_8009F280 + s0[1];
    v1 = s0[0];
    if (v1 >= 0) {
        goto ge0;
    }
    if (t < -0x40) {
        goto do_call;
    }
ge0:
    if (v1 <= 0) {
        goto next;
    }
    if (t < 0x49) {
        goto next;
    }
do_call:
    func_8006AC08(s0, &D_8009F2C0);
next:
    v1 = s0[1];
    if (v1 >= 0) {
        goto ge0b;
    }
    if (st.sp14 < -0x40) {
        goto do_call2;
    }
ge0b:
    if (v1 <= 0) {
        goto next2;
    }
    if (st.sp14 < 0x41) {
        goto next2;
    }
do_call2:
    func_8006AC98(s0, &D_8009F2C0);
next2:
    if (st.l.e0 != D_8009F2C0) {
        goto setbit;
    }
    if (st.l.e4 == D_8009F2C4) {
        goto end;
    }
setbit:
    u = D_8004D950;
    u |= 2;
    D_8004D950 = u;
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008F08C);

void func_8008F284(void) {
    volatile s32 pad[14];

    __asm__ volatile(".set\tnoreorder\n"
                     "\tori\t$4,$0,0x31\n"
                     "\tsw\t$31,0x34($sp)\n"
                     "\tsw\t$20,0x30($sp)\n"
                     "\tsw\t$19,0x2C($sp)\n"
                     "\tsw\t$18,0x28($sp)\n"
                     "\tsw\t$17,0x24($sp)\n"
                     "\tjal\tfunc_800EF1A8\n"
                     "\tsw\t$16,0x20($sp)\n"
                     "\tlui\t$17,%%hi(D_8009F254)\n"
                     "\taddiu\t$17,$17,%%lo(D_8009F254)\n"
                     "\tsll\t$3,$2,1\n"
                     "\taddu\t$3,$3,$2\n"
                     "\tsll\t$3,$3,2\n"
                     "\taddu\t$3,$3,$2\n"
                     "\tsll\t$3,$3,2\n"
                     "\tlui\t$20,%%hi(D_800D3CB0)\n"
                     "\taddiu\t$20,$20,%%lo(D_800D3CB0)\n"
                     "\taddu\t$3,$3,$20\n"
                     "\tsw\t$2,0($17)\n"
                     "\tlwl\t$2,3($3)\n"
                     "\tlwr\t$2,0($3)\n"
                     "\tlwl\t$4,7($3)\n"
                     "\tlwr\t$4,4($3)\n"
                     "\tswl\t$2,0xB($17)\n"
                     "\tswr\t$2,8($17)\n"
                     "\tswl\t$4,0xF($17)\n"
                     "\tswr\t$4,0xC($17)\n"
                     "\tori\t$19,$0,3\n"
                     "\taddiu\t$2,$17,0x10\n"
                     "\tlui\t$3,%%hi(D_8009F198)\n"
                     "\tlw\t$3,%%lo(D_8009F198)($3)\n"
                     "\tori\t$16,$0,1\n"
                     "\tsw\t$0,D_8009F250\n"
                     "\tsw\t$19,D_8009F24C\n"
                     "\tsll\t$5,$3,2\n"
                     "\taddiu\t$3,$3,1\n"
                     "\tlui\t$1,%%hi(D_8009EF80)\n"
                     "\taddiu\t$1,$1,%%lo(D_8009EF80)\n"
                     "\taddu\t$1,$1,$5\n"
                     "\tsw\t$2,0($1)\n"
                     "\tori\t$2,$0,0xE\n"
                     "\tsw\t$16,0x10($17)\n"
                     "\tsw\t$2,D_8009F26C\n"
                     "\tori\t$2,$0,0x80\n"
                     "\tsw\t$3,D_8009F198\n"
                     "\tsw\t$0,D_8009F274\n"
                     "\tsw\t$0,D_8009F270\n"
                     "\tsb\t$2,D_8009F284\n"
                     "\tsb\t$2,D_8009F285\n"
                     "\tsb\t$2,D_8009F286\n"
                     "\tjal\tfunc_800EF1A8\n"
                     "\tori\t$4,$0,0x69\n"
                     "\taddu\t$3,$2,$0\n"
                     "\tsw\t$0,D_8009F278\n"
                     "\tbne\t$3,$16,1f\n"
                     "\taddiu\t$18,$17,8\n"
                     "\tori\t$2,$0,2\n"
                     "\tsw\t$2,D_8009F278\n"
                     "1:\n"
                     "\tori\t$2,$0,2\n"
                     "\tbne\t$3,$2,2f\n"
                     "\tnop\n"
                     "\tsw\t$19,D_8009F278\n"
                     "2:\n"
                     "\tlw\t$3,0($17)\n"
                     "\tnop\n"
                     "\tsll\t$2,$3,1\n"
                     "\taddu\t$2,$2,$3\n"
                     "\tsll\t$2,$2,2\n"
                     "\taddu\t$2,$2,$3\n"
                     "\tsll\t$2,$2,2\n"
                     "\taddu\t$2,$2,$20\n"
                     "\tlwl\t$3,3($2)\n"
                     "\tlwr\t$3,0($2)\n"
                     "\tlwl\t$5,7($2)\n"
                     "\tlwr\t$5,4($2)\n"
                     "\tswl\t$3,0xB($17)\n"
                     "\tswr\t$3,8($17)\n"
                     "\tswl\t$5,0xF($17)\n"
                     "\tswr\t$5,0xC($17)\n"
                     "\tlui\t$5,%%hi(D_8009F2C0)\n"
                     "\taddiu\t$5,$5,%%lo(D_8009F2C0)\n"
                     "\tjal\tfunc_8008EDBC\n"
                     "\taddu\t$4,$18,$0\n"
                     "\tjal\tfunc_8006A888\n"
                     "\tnop\n"
                     "\tjal\tfunc_8008F434\n"
                     "\tnop\n"
                     "\t.set\treorder" : : : "$1", "$2", "$3", "$4", "$5", "$24", "at", "hi", "lo", "memory");
    __asm__ volatile(".set\tnoreorder\n"
                     "\tlw\t$31,0x34($sp)\n"
                     "\tlw\t$20,0x30($sp)\n"
                     "\tlw\t$19,0x2C($sp)\n"
                     "\tlw\t$18,0x28($sp)\n"
                     "\tlw\t$17,0x24($sp)\n"
                     "\tlw\t$16,0x20($sp)\n"
                     "\t.set\treorder" : : : "at", "memory");
    return;
}

extern s32 D_8009F250;
extern s32 D_8009F268;
extern s32 D_8009F270;
extern s32 D_8009F274;

void func_8008F434(void) {
    register s32 *s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register void *sp asm("sp");
    volatile s32 pad[6];
    s32 temp_v1;

    a2 = (s32) &D_8009F24C;
    a1 = *(s32 *) a2;
    v0 = a1 & 2;
    if (v0 != 0) {
        v0 = D_8009F250;
        v0 += 0x100;
        v0 >>= 9;
        a0 = v0 & 7;
        v0 = a1 & 4;
        temp_v1 = a0 + 0x10;
        if (v0 != 0)
            temp_v1 += 8;
        v1 = temp_v1;
        v0 = D_8009F268;
        if (v0 != v1) {
            D_8009F268 = v1;
            D_8009F274 = 0;
            D_8009F270 = 0;
        }
        v0 = a1 ^ 2;
        *(volatile s32 *) a2 = v0;
    }
    MEMORY_BARRIER();
    s0 = (s32 *) &D_8009F24C;
    v0 = *s0;
    v0 &= 1;
    a0 = (s32) s0 + 0x10;
    if (v0 != 0) {
        a1 = (s32) sp + 0x10;
        a2 = (s32) sp + 0x20;
        func_8001D578((s32 *) a0, (s32 *) a1, (s32 *) a2);
        v0 = *(s32 *) ((char *) sp + 0x10);
        v1 = *s0;
        a0 = *(s32 *) ((char *) sp + 0x14);
        v1 ^= 1;
        D_8009F27C = v0;
        D_8009F280 = a0;
        *s0 = v1;
    }
}

extern s32 D_800BBC7C[];

void func_8008F514(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern void func_8008F698(s32, s32, s32, s32);
    extern void func_8010849C(s16, s16, s32);
    s32 s0 = arg0;
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[4];
    typedef struct {
        char c[8];
    } W;

    s0 <<= 1;
    s0 += arg0;
    s0 <<= 2;
    s0 += arg0;
    s0 <<= 2;
    v1 = -0x1D;
    a0 = arg3;
    *(volatile s32 *) ((char *) sp + 0x34) = arg1;
    *(volatile s32 *) ((char *) sp + 0x38) = arg2;
    a3 = (s32) sp + 0x10;
    s1 = (s32) &D_800BBC90[0];
    at = (s32 *) &D_800BBC70[0];
    at = (s32 *) ((char *) at + s0);
    v0 = *at;
    v0 &= v1;
    at = (s32 *) &D_800BBC70[0];
    at = (s32 *) ((char *) at + s0);
    *at = v0;
    v0 = *(s16 *) ((char *) sp + 0x34);
    v0 -= 0x80;
    at = (s32 *) &D_800BBC88[0];
    at = (s32 *) ((char *) at + s0);
    *at = v0;
    v0 = *(s16 *) ((char *) sp + 0x36);
    v1 = s0 + s1;
    at = (s32 *) &D_800BBC7C[0];
    at = (s32 *) ((char *) at + s0);
    *at = a0;
    v0 -= 0x78;
    at = (s32 *) &D_800BBC8C[0];
    at = (s32 *) ((char *) at + s0);
    *at = v0;
    v0 = 0x1E1;
    *(s32 *) (v1 + 4) = v0;
    v0 = s1 + 8;
    v0 += s0;
    *(volatile s32 *) v1 = 0;
    s2 = *(s32 *) ((char *) sp + 0x40);
    *(W *) ((char *) v0) = *(W *) ((char *) sp + 0x34);
    v0 = *(u16 *) ((char *) sp + 0x34);
    a1 = *(u16 *) ((char *) sp + 0x36);
    v1 = *(u16 *) ((char *) sp + 0x38);
    a2 = *(u16 *) ((char *) sp + 0x3A);
    a1 <<= 16;
    a1 = v0 | a1;
    a2 <<= 16;
    a2 = v1 | a2;
    func_8008F698(a0, a1, a2, a3);
    a0 = 0;
    a2 = *(s32 *) ((char *) sp + 0x10);
    a3 = *(s32 *) ((char *) sp + 0x14);
    v0 = func_8002398C(a0, 0, a2, a3);
    v0 &= 0xFFFF;
    s1 += 0x10;
    s1 += s0;
    at = (s32 *) &D_800BBC74[0];
    at = (s32 *) ((char *) at + s0);
    *at = v0;
    v0 = 0x80;
    *(s8 *) s1 = (s8) v0;
    *(s8 *) (s1 + 1) = (s8) v0;
    *(s8 *) (s1 + 2) = (s8) v0;
    at = (s32 *) &D_800BBC80[0];
    at = (s32 *) ((char *) at + s0);
    *at = 0;
    a0 = *(s16 *) ((char *) sp + 0x38);
    a1 = *(s16 *) ((char *) sp + 0x3A);
    a2 = s2;
    func_8010849C((s16) a0, (s16) a1, a2);
}

void func_8008F698(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register void *sp asm("sp");

    *(s32 *) ((char *) sp + 4) = a1;
    a0 = arg0;
    a1 = arg1;
    a2 = arg2;
    a3 = (s32) arg3;
    KEEP_NOVOL(a3);
    *(s32 *) ((char *) sp + 8) = a2;
    if (a0 < 0)
        goto end;
    if (a0 < 2)
        goto low_value;
    v0 = 2;
    if (a0 == 2)
        goto high_value;
    goto end;
low_value:
    v0 = *(s16 *) ((char *) sp + 4);
    if (v0 < 0)
        v0 += 3;
    KEEP_NOVOL(v0);
    v0 >>= 2;
    MEMORY_BARRIER();
    v1 = a0 << 6;
    v1 += 0x180;
    v0 += v1;
    *(s32 *) a3 = v0;
    v0 = *(s16 *) ((char *) sp + 6);
    *(s32 *) (a3 + 4) = v0;
    goto end;
high_value:
    v0 = *(s16 *) ((char *) sp + 4);
    if (v0 < 0)
        v0 += 3;
    KEEP_NOVOL(v0);
    v0 >>= 2;
    v0 += 0x240;
    *(s32 *) a3 = v0;
    v0 = *(s16 *) ((char *) sp + 6);
    v0 += 0x100;
    *(s32 *) (a3 + 4) = v0;
end:;
}

extern s32 D_800BBC9A[];

void func_8008F72C(s32 arg0, s32 arg1) {
    extern void func_8008F698(s32, s32, s32, s32);
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    volatile s32 pad[6];

    s1 = arg1;
    KEEP_NOVOL(s1);
    v0 = arg0;
    v0 <<= 1;
    v0 += arg0;
    v0 <<= 2;
    v0 += arg0;
    s0 = v0 << 2;
    a3 = (s32) sp + 0x10;
    at = (s32 *) &D_800BBC98[0];
    at = (s32 *) ((char *) at + s0);
    v0 = *(u16 *) at;
    at = (s32 *) &D_800BBC9C[0];
    at = (s32 *) ((char *) at + s0);
    v1 = *(u16 *) at;
    at = (s32 *) &D_800BBC9A[0];
    at = (s32 *) ((char *) at + s0);
    a1 = *(u16 *) at;
    at = (s32 *) &D_800BBC7C[0];
    at = (s32 *) ((char *) at + s0);
    a0 = *at;
    at = (s32 *) &D_800BBC9E[0];
    at = (s32 *) ((char *) at + s0);
    a2 = *(u16 *) at;
    a1 <<= 16;
    a1 = v0 | a1;
    a2 <<= 16;
    a2 = v1 | a2;
    func_8008F698(a0, a1, a2, a3);
    v0 = *(s32 *) ((char *) sp + 0x10);
    v1 = *(s32 *) ((char *) sp + 0x14);
    *(s16 *) ((char *) sp + 0x18) = (s16) v0;
    *(s16 *) ((char *) sp + 0x1A) = (s16) v1;
    at = (s32 *) &D_800BBC9C[0];
    at = (s32 *) ((char *) at + s0);
    v0 = *(s16 *) at;
    a0 = (s32) sp + 0x18;
    if (v0 < 0)
        v0 += 3;
    v0 >>= 2;
    *(s16 *) ((char *) sp + 0x1C) = (s16) v0;
    v0 = *(volatile u16 *) ((char *) &D_800BBC9E[0] + s0);
    *(s16 *) ((char *) sp + 0x1E) = (s16) v0;
    a1 = s1;
    func_800248FC((s32 *) a0, a1);
}

extern void func_800FE774(s32, s32, s16 *);

void func_8008F828(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 v0;
    s32 *at;
    struct {
        s16 sp10;
        s16 sp12;
        s32 pad;
        s32 sp18;
    } sp;

    v0 = arg0;
    v0 <<= 1;
    v0 += arg0;
    v0 <<= 2;
    v0 += arg0;
    v0 <<= 2;
    *(s32 *) ((char *) &sp + 0x20) = arg2;
    *(s32 *) ((char *) &sp + 0x24) = arg3;
    sp.sp10 = (s16) arg2;
    sp.sp12 = (s16) arg3;
    at = (s32 *) ((char *) &D_800BBC9C[0] + v0);
    v0 = *(s16 *) at;
    sp.sp18 = v0;
    func_800FE774(arg1, arg4, &sp.sp10);
}

extern void func_800E4668();
extern s32 func_800E6EDC();

void func_8008F888(s32 arg0, s32 *arg1) {
    s16 sp12;
    s16 sp10;
    s32 *dst;
    s32 ret;
    s32 w0;
    s32 w1;

    dst = arg1;
    ret = func_800E6EDC(arg0, arg1);
    func_800E4668(&sp10, &sp12, ret);
    w0 = (s32) ((sp10 + 0x18) & 0xFFFC);
    w1 = (s32) ((sp12 << 4) + 0x10);
    dst[0] = w0;
    dst[1] = w1;
}

void func_8008F8E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    register s32 s0 asm("s0") = arg0;
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 a0 asm("a0") = arg0;
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register void *sp asm("sp");
    volatile s32 pad[6];

    s2 = arg4;
    s1 = arg5;
    __asm__("" : "=r"(s0), "=r"(s2) : "0"(arg0), "1"(arg4));
    __asm__("" : : "r"(s0), "r"(a0));
    a1 = arg1;
    a2 = arg2;
    a3 = arg3;
    *(s32 *) ((char *) sp + 0x3C) = a1;
    *(s32 *) ((char *) sp + 0x40) = a2;
    *(volatile s32 *) ((char *) sp + 0x10) = s1;
    MEMORY_BARRIER();
    v0 = *(u16 *) ((char *) sp + 0x3C);
    a1 = *(u16 *) ((char *) sp + 0x3E);
    a1 <<= 16;
    a1 = v0 | a1;
    v1 = *(u16 *) ((char *) sp + 0x40);
    a2 = *(u16 *) ((char *) sp + 0x42);
    a2 <<= 16;
    __asm__ volatile("" : : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(v1) : "memory");
    ((void (*)(s32, s32, s32, s32)) func_8008F514)(a0, a1, v1 | a2, a3);
    v0 = 8;
    *(s32 *) ((char *) sp + 0x18) = v0;
    *(s32 *) ((char *) sp + 0x1C) = v0;
    if (s2 != 0) {
        a0 = s0;
        *(volatile s32 *) ((char *) sp + 0x10) = s1;
        a2 = *(volatile s32 *) ((char *) sp + 0x18);
        a3 = *(volatile s32 *) ((char *) sp + 0x1C);
        __asm__ volatile("" : : "r"(a2), "r"(a3) : "memory");
        ((void (*)(s32, s32, s32, s32)) func_8008F828)(a0, s2, a2, a3);
    }
    a0 = s0 + 0;
    func_8008F72C(a0, s1);
    v0 = s0 << 1;
    v0 += s0;
    v0 <<= 2;
    v0 += s0;
    v0 <<= 2;
    v1 = *(s32 *) ((char *) &D_800BBC70[0] + v0);
    v1 |= 0x100;
    *(s32 *) ((char *) &D_800BBC70[0] + v0) = v1;
}

void func_8008F9BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 s0;
    s32 s1;
    register s32 a0 asm("a0");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 *at asm("at");
    register void *sp asm("sp");
    extern s32 func_8002398C(s32, s32);

    s0 = arg0;
    s0 <<= 1;
    s0 += arg0;
    s0 <<= 2;
    s0 += arg0;
    s0 <<= 2;
    a0 = -0x19;
    *(s32 *) ((char *) sp + 0x24) = arg1;
    *(s32 *) ((char *) sp + 0x28) = a2;
    *(s32 *) ((char *) sp + 0x2C) = a3;
    s1 = (s32) &D_800BBC90[0];
    at = (s32 *) &D_800BBC70[0];
    at = (s32 *) ((char *) at + s0);
    v0 = *at;
    v1 = *(s32 *) ((char *) sp + 0x34);
    v0 &= a0;
    v0 |= v1;
    at = (s32 *) &D_800BBC70[0];
    at = (s32 *) ((char *) at + s0);
    *at = v0;
    v0 = s0 + s1;
    __asm__ volatile("" : : "r"(v0) : "memory");
    v1 = *(s32 *) ((char *) sp + 0x2C);
    a0 = *(s32 *) ((char *) sp + 0x30);
    *(volatile s32 *) v0 = v1;
    *(volatile s32 *) (v0 + 4) = a0;
    a0 = 0;
    a2 = *(s16 *) ((char *) sp + 0x24);
    a3 = *(s16 *) ((char *) sp + 0x26);
    __asm__ volatile("" : : "r"(a0), "r"(a2), "r"(a3) : "memory");
    v0 = func_8002398C(0, 0);
    v0 &= 0xFFFF;
    v1 = s1 + 8;
    at = (s32 *) &D_800BBC74[0];
    at = (s32 *) ((char *) at + s0);
    *at = v0;
    v0 = *(u16 *) ((char *) sp + 0x24);
    v1 = s0 + v1;
    v0 &= 0x3F;
    v0 <<= 1;
    *(s16 *) v1 = (s16) v0;
    v0 = *(u8 *) ((char *) sp + 0x26);
    *(s16 *) (v1 + 2) = (s16) v0;
    v0 = *(s16 *) ((char *) sp + 0x28);
    s1 += 0x10;
    v0 <<= 1;
    *(s16 *) (v1 + 4) = (s16) v0;
    v0 = *(u16 *) ((char *) sp + 0x2A);
    s1 = s0 + s1;
    *(s16 *) (v1 + 6) = (s16) v0;
    v0 = 0x80;
    *(u8 *) s1 = (u8) v0;
    *(u8 *) (s1 + 1) = (u8) v0;
    *(u8 *) (s1 + 2) = (u8) v0;
    at = (s32 *) &D_800BBC80[0];
    at = (s32 *) ((char *) at + s0);
    *at = 0;
}

extern void func_8008FB28();
extern volatile s16 D_800BB31C;
extern s32 D_801097DC;

void func_8008FAD8(s32 arg0, s32 arg1) {
    func_8008FB28();
    func_800FFD70(arg0, &D_801097DC);
    func_800FFF08(arg0, &D_800BB31C, 0, 0);
}

extern volatile s16 D_800BB31E;
extern volatile s16 D_800BB320;
extern volatile s16 D_800BB322;
extern volatile s16 D_800BB324;
extern volatile s16 D_800BB326;
extern volatile s16 D_800BB328;
extern volatile s16 D_800BB32A;
extern volatile s16 D_800BB32C;
extern volatile s16 D_800BB32E;
extern volatile s16 D_800BB330;
extern volatile s16 D_800BB332;
extern volatile s16 D_800BB334;
extern volatile s16 D_800BB336;
extern volatile s16 D_800BB338;
extern volatile s16 D_800BB33A;
extern volatile s16 D_800BB33C;
extern volatile void *D_800BB340;
extern volatile s16 D_800BB348;
extern s16 *volatile D_800BB34C;
extern volatile void *D_800BB350;
extern volatile s16 D_800BB394;
extern volatile s16 D_800BB396;
extern volatile s16 D_800BB398;
extern volatile s16 D_800BB39A;
extern volatile s16 D_800BB39E;
extern volatile s16 D_800BB3A0;
extern volatile s16 D_800BB3A2;
extern volatile void *D_800BB3A4;
extern volatile void *D_800BB3B0;
extern s32 D_8009EE30;

void func_8008FB28(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    extern s16 D_800BB3F0;
    s32 a0;
    s32 a1;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 t0 asm("t0");

    v1 = arg2[0];
    v0 = arg2[1];
    t0 = (s32) &D_800BB394;
    *(volatile s16 *) t0 = (s16) v0;
    MEMORY_BARRIER();
    a0 = arg2[1];
    __asm__ volatile("" : : "r"(a0) : "memory");
    v0 = 4;
    D_800BB39A = (s16) v0;
    D_800BB398 = (s16) v0;
    v0 = 2;
    D_800BB3A0 = (s16) v0;
    D_800BB3A2 = (s16) v0;
    v0 = (s32) &D_800D0880;
    D_800BB3A4 = (void *) v0;
    v0 = (s32) &D_800BB3F0;
    D_800BB3B0 = (void *) v0;
    v0 = 0x200;
    D_800BB31C = (s16) v0;
    v0 = 0x100;
    v1 += 0x18;
    v1 &= 0xFFFC;
    D_800BB39E = 0;
    D_800BB31E = (s16) v0;
    D_800BB320 = (s16) v1;
    D_800BB322 = 0;
    __asm__ volatile("" : : "r"(a1), "r"(a0) : "memory");
    a1 -= a0;
    D_800BB396 = (s16) a1;
    v0 = arg3[0];
    v0 = v0 - 128;
    D_800BB324 = (s16) v0;
    MEMORY_BARRIER();
    v0 = arg3[1];
    D_800BB328 = (s16) v1;
    D_800BB32A = 0;
    D_800BB32C = 0;
    D_800BB32E = 0;
    D_800BB330 = (s16) v1;
    D_800BB332 = 0;
    D_800BB334 = 0;
    D_800BB336 = 0;
    D_800BB338 = 0;
    v0 = v0 - 120;
    D_800BB326 = (s16) v0;
    MEMORY_BARRIER();
    v1 = arg2[1];
    v0 = (s32) &D_8009EE30;
    D_800BB340 = (void *) v0;
    v0 = 1;
    D_800BB33C = 0;
    D_800BB33A = (s16) v1;
    D_800BB348 = (s16) v0;
    v0 = (s32) &D_800D4574;
    D_800BB34C = (s16 *) t0;
    D_800BB350 = (void *) v0;
}

extern s16 D_800BB356;
extern s32 D_800D07D8;
extern s32 D_800D07DC;

void func_8008FC88(s32 arg0) {
    *(s32 *) ((char *) &D_800D07D8 + (arg0 << 3)) = D_800BB354;
    *(s32 *) ((char *) &D_800D07DC + (arg0 << 3)) = D_800BB356;
}

void func_8008FCC8(s32 arg0, s32 arg1, s32 arg2) {
    s32 v;
    s32 t0;
    s32 t1;

    arg0 <<= 3;
    if (arg1 < (*(s32 *) ((char *) &D_800D07D8 + arg0) + 1)) {
        *(s32 *) ((char *) &D_800D07D8 + arg0) = arg1 - 1;
        *(s32 *) ((char *) &D_800D07DC + arg0) = arg1 - arg2;
    }
    v = *(s32 *) ((char *) &D_800D07DC + arg0);
    v += arg2;
    if (arg1 - v < 0) {
        *(s32 *) ((char *) &D_800D07DC + arg0) = arg1 - arg2;
    }
    t0 = *(s32 *) ((char *) &D_800D07D8 + arg0);
    D_800BB354 = t0;
    t1 = *(s32 *) ((char *) &D_800D07DC + arg0);
    D_800BB356 = t1;
}

void func_8008FD88(s32 arg0) {
    arg0 <<= 3;
    *(s32 *) ((char *) &D_800D07DC + arg0) = 0;
    *(s32 *) ((char *) &D_800D07D8 + arg0) = 0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008FDB4);

void func_8008FFD8(void) {
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_8008FFE0);

void func_8009036C(s32 arg0, s32 arg1, s32 arg2) {
    s32 v0;
    s32 v1;
    s32 *at;

    v0 = arg0;
    v0 <<= 3;
    v0 += arg0;
    v0 <<= 2;
    at = (s32 *) ((char *) &D_800BB504[0] + v0);
    v1 = *at;
    at = (s32 *) ((char *) &D_800BB508[0] + v0);
    *at = arg2;
    at = (s32 *) ((char *) &D_800BB50C[0] + v0);
    *at = arg1;
    at = (s32 *) ((char *) &D_800BB514[0] + v0);
    *at = 0;
    at = (s32 *) ((char *) &D_800BB510[0] + v0);
    *at = 0;
    v1 |= 0x810;
    *(s32 *) ((char *) &D_800BB504[0] + v0) = v1;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_800903E4);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_800906C0);

void func_80090A28(volatile s32 *arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 *at asm("at");

    v0 = arg0[21];
    v1 = arg0[20];
    if (v0 < v1) {
        v0 = arg0[14];
        v1 = v0;
        v1 <<= 3;
        v1 += v0;
        v1 <<= 2;
        at = (s32 *) ((char *) &D_800BB504[0] + v1);
        v0 = *at;
        a0 = -0x11;
        v0 &= a0;
    } else {
        v0 = arg0[14];
        v1 = v0;
        v1 <<= 3;
        v1 += v0;
        v1 <<= 2;
        at = (s32 *) ((char *) &D_800BB504[0] + v1);
        v0 = *at;
        v0 |= 0x10;
    }
    at = (s32 *) ((char *) &D_800BB504[0] + v1);
    *at = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_80090AB4);

extern void func_80043FF8();

void func_80090D30(void) {
    func_80043FF8();
}

extern s32 D_800D45A4[];
extern s32 D_800D45E4[];

void func_80090D50(s32 arg0, s32 arg1) {
    extern void func_80011E38(s32 *);
    extern void func_80090E20();
    extern void func_8001DBA8(s32);
    s32 s0;
    s32 s1;
    s32 a0;
    s32 v0;
    s32 *at;
    volatile s32 pad[2];
    v0 = D_800D462C;

    s0 = arg0;
    s1 = arg1;
    if (v0 < 0x10)
        goto store;
loop:
    a0 = (s32) &D_8004EAF4;
    func_80011E38((void *) a0);
    func_80090E20();
    func_8001DBA8(0);
    v0 = D_800D462C;
    if (v0 >= 0x10)
        goto loop;
store:
    v0 = D_800D462C;
    v0 <<= 2;
    at = (s32 *) ((char *) D_800D45A4 + v0);
    *at = s0;
    v0 = D_800D462C;
    v0 <<= 2;
    at = (s32 *) ((char *) D_800D45E4 + v0);
    *at = s1;
    v0 = D_800D462C;
    v0 += 1;
    D_800D462C = v0;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_80090E20);

void func_80091174(s32 arg0) {
    extern void func_80090D50(s32, s32);
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    v0 = D_800D4630;

    s0 = arg0;
    v0 &= 1;
    if (v0 == 0)
        goto skip;
    a0 = 2;
    a1 = 0x10;
    func_80090D50(a0, a1);
skip:
    a0 = 1;
    USE_NOVOL(a0);
    a1 = s0;
    func_80090D50(a0, a1);
    a0 = 3;
    a1 = 0x10;
    func_80090D50(a0, a1);
}

void func_800911CC(void) {
    extern void func_80011E38();
    extern void func_80090E20();
    extern void func_8001DBA8(s32);
    s32 v0;
    v0 = D_800D462C;

    goto cond;
block:
    func_80011E38(D_8004EAF4);
    func_80090E20();
    func_8001DBA8(0);
    v0 = D_800D462C;
cond:
    if (v0 != 0)
        goto block;
    v0 = D_800D4624;
    if (v0 != 0)
        goto block;
    return;
}

void func_80091238(s32 arg0, s32 arg1) {
    volatile s32 pad[10];

    __asm__ volatile(".set\tnoreorder\n"
                     "\tlui\t$3,%%hi(D_800D4674)\n"
                     "\tlw\t$3,%%lo(D_800D4674)($3)\n"
                     "\tsll\t$4,$4,1\n"
                     "\tsw\t$31,0x24($sp)\n"
                     "\tsw\t$20,0x20($sp)\n"
                     "\tsw\t$19,0x1C($sp)\n"
                     "\tsw\t$18,0x18($sp)\n"
                     "\tsw\t$17,0x14($sp)\n"
                     "\tsw\t$16,0x10($sp)\n"
                     "\taddu\t$4,$4,$3\n"
                     "\tlhu\t$2,0($4)\n"
                     "\tlui\t$4,%%hi(D_800D4648)\n"
                     "\taddiu\t$4,$4,%%lo(D_800D4648)\n"
                     "\tandi\t$2,$2,0xFFFE\n"
                     "\taddu\t$3,$3,$2\n"
                     "\tsw\t$3,0($4)\n"
                     "\tlui\t$2,%%hi(D_800D4648)\n"
                     "\tlw\t$2,%%lo(D_800D4648)($2)\n"
                     "\taddu\t$20,$5,$0\n"
                     "\tlhu\t$3,0($2)\n"
                     "\tnop\n"
                     "\tbeqz\t$3,WLDC_RET\n"
                     "\taddu\t$17,$0,$0\n"
                     "\taddiu\t$18,$4,0x4\n"
                     "\taddiu\t$16,$4,0x8\n"
                     "\tlui\t$19,%%hi(D_8009EE50)\n"
                     "\taddiu\t$19,$19,%%lo(D_8009EE50)\n"
                     "1:\n"
                     "\tlui\t$2,%%hi(D_800D4674)\n"
                     "\tlw\t$2,%%lo(D_800D4674)($2)\n"
                     "\tandi\t$3,$3,0xFFFE\n"
                     "\tsh\t$0,4($18)\n"
                     "\tsw\t$0,-8($18)\n"
                     "\taddu\t$2,$2,$3\n"
                     "\tsw\t$2,0($18)\n"
                     "2:\n"
                     "\tlhu\t$3,0($16)\n"
                     "\tlui\t$4,%%hi(D_800D464C)\n"
                     "\tlw\t$4,%%lo(D_800D464C)($4)\n"
                     "\tsll\t$2,$3,1\n"
                     "\taddu\t$2,$2,$4\n"
                     "\tlhu\t$2,0($2)\n"
                     "\taddiu\t$3,$3,1\n"
                     "\tsh\t$3,0($16)\n"
                     "\tsll\t$2,$2,2\n"
                     "\taddu\t$2,$2,$19\n"
                     "\tlw\t$2,0($2)\n"
                     "\tnop\n"
                     "\tjalr\t$2\n"
                     "\tnop\n"
                     "\tlw\t$2,-0xC($16)\n"
                     "\tnop\n"
                     "\tandi\t$2,$2,3\n"
                     "\tbeqz\t$2,2b\n"
                     "\tnop\n"
                     "\tlui\t$3,%%hi(D_800D4644)\n"
                     "\tlw\t$3,%%lo(D_800D4644)($3)\n"
                     "\tnop\n"
                     "\tandi\t$2,$3,1\n"
                     "\tbeqz\t$2,3f\n"
                     "\tand\t$2,$3,$20\n"
                     "\tbnez\t$2,WLDC_RET2\n"
                     "\tori\t$2,$0,1\n"
                     "3:\n"
                     "\taddiu\t$17,$17,1\n"
                     "\tandi\t$2,$17,0xFFFF\n"
                     "\tlui\t$3,%%hi(D_800D4648)\n"
                     "\tlw\t$3,%%lo(D_800D4648)($3)\n"
                     "\tsll\t$2,$2,1\n"
                     "\taddu\t$2,$2,$3\n"
                     "\tlhu\t$3,0($2)\n"
                     "\tnop\n"
                     "\tbnez\t$3,1b\n"
                     "\tnop\n"
                     "\t.set\treorder" : : : "$2", "$3", "$4", "$5", "at", "hi", "lo", "memory");
    __asm__ volatile("WLDC_RET:");
    __asm__ volatile(".set\tnoreorder\n"
                     "\taddu\t$2,$0,$0\n"
                     "WLDC_RET2:\n"
                     "\tlw\t$31,0x24($sp)\n"
                     "\tlw\t$20,0x20($sp)\n"
                     "\tlw\t$19,0x1C($sp)\n"
                     "\tlw\t$18,0x18($sp)\n"
                     "\tlw\t$17,0x14($sp)\n"
                     "\tlw\t$16,0x10($sp)\n"
                     "\t.set\treorder" : : : "$2", "at", "memory");
    return;
}

void func_80091380(void) {
}

extern u16 D_800D4650;

void func_80091388(void) {
    u16 *ctr = &D_800D4650;

    *ctr += 1;
}

void func_800913A4(void) {
    u16 *ctr = &D_800D4650;

    *ctr += 2;
}

void func_800913C0(void) {
    u16 *ctr = &D_800D4650;

    *ctr += 3;
}

void func_800913DC(void) {
    u16 *ctr = &D_800D4650;

    *ctr += 4;
}

void func_80091450(s32 *arg0, s32 *arg1);

void func_800913F8(void) {
    s32 v0;
    s32 v1;

    func_80091450(&v0, &v1);
    if (func_800EF1A8(v0) != v1) {
        s32 *p = &D_800D4644;

        *p |= 2;
    }
}

extern u16 *D_800D464C;

void func_80091450(s32 *arg0, s32 *arg1) {
    u16 *ctr = &D_800D4650;
    u16 c;

    *arg0 = D_800D464C[*ctr];
    c = *ctr + 1;
    *ctr = c;
    *arg1 = D_800D464C[c];
    *ctr += 1;
}

void func_800914BC(void) {
    s32 v0;
    s32 v1;

    func_80091450(&v0, &v1);
    if (func_800EF1A8(v0) < v1) {
        s32 *p = &D_800D4644;

        *p |= 2;
    }
}

void func_80091518(void) {
    s32 v0;
    s32 v1;

    func_80091450(&v0, &v1);
    if (func_800EF1A8(v0) > v1) {
        s32 *p = &D_800D4644;

        *p |= 2;
    }
}

void func_80091574(void) {
    u8 *p;
    u16 *ctr = &D_800D4650;
    u16 c = *ctr;
    s32 temp;
    s32 i;

    temp = D_800D464C[c];
    *ctr = c + 1;
    for (i = 0; i < 0x14; i++) {
        p = func_80069E38(i);
        if (p[1] == 0xFF)
            continue;
        if (p[0] == temp)
            break;
    }
    if (i == 0x14) {
        s32 *q = &D_800D4644;

        *q |= 2;
    }
}

void func_80091630(void) {
    u16 *ctr = &D_800D4650;

    *ctr += 1;
}

s32 func_8009164C(void) {
    u16 *ctr = &D_800D4650;
    s32 c;

    c = *ctr + 1;
    *ctr = c;
    return c;
}

void func_80091668(void) {
    u16 *ctr = &D_800D4650;
    u16 c = *ctr;
    u16 temp_s0;

    temp_s0 = D_800D464C[c];
    *ctr = c + 1;
    if (func_800EF1A8(0x2C) < (s32) temp_s0) {
        D_800D4644 |= 2;
    }
}

void func_800916DC(void) {
    u16 *ctr = &D_800D4650;
    u16 c = *ctr;
    s32 temp_s0;

    temp_s0 = D_800D464C[c];
    *ctr = c + 1;
    if (temp_s0 < func_800EF1A8(0x2C)) {
        D_800D4644 |= 2;
    }
}

extern void func_800917CC(s32 *, s32 *, s32 *, s32 *);

void func_80091750(void) {
    s32 v0;
    s32 v1;
    s32 v2;
    s32 v3;

    func_800917CC(&v0, &v1, &v2, &v3);
    if ((v2 < v0) || ((v2 == v0) && (v3 < v1))) {
        s32 *p = &D_800D4644;

        *p |= 2;
    }
}

void func_800917CC(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u16 *ctr = &D_800D4650;
    u16 c;

    *arg0 = D_800D464C[*ctr];
    c = *ctr + 1;
    *ctr = c;
    *arg1 = D_800D464C[c];
    *ctr += 1;
    *arg2 = func_800EF1A8(0x2E);
    *arg3 = func_800EF1A8(0x2F);
}

void func_80091874(void) {
    s32 v0;
    s32 v1;
    s32 v2;
    s32 v3;

    func_800917CC(&v0, &v1, &v2, &v3);
    if ((v2 > v0) || ((v2 == v0) && (v3 > v1))) {
        s32 *p = &D_800D4644;

        *p |= 2;
    }
}

void func_800918F0(void) {
    u16 *ctr = &D_800D4650;
    u16 c = *ctr;
    u16 temp_s0;

    temp_s0 = D_800D464C[c];
    *ctr = c + 1;
    if (func_800EF1A8(0x62) < (s32) temp_s0) {
        D_800D4644 |= 2;
    }
}

void func_80091964(void) {
    u16 *ctr = &D_800D4650;
    u16 c = *ctr;
    s32 temp_s0;

    temp_s0 = D_800D464C[c];
    *ctr = c + 1;
    if (temp_s0 < func_800EF1A8(0x62)) {
        D_800D4644 |= 2;
    }
}

void func_800919D8(void) {
    u16 *base = D_800D464C;
    u16 c = D_800D4650;
    u16 v0;
    u16 c1;
    u16 v1;

    v0 = base[c];
    MEMORY_BARRIER();
    c1 = c + 1;
    D_800D4650 = c1;
    v1 = base[c1];
    D_800D4664 = v0;
    MEMORY_BARRIER();
    D_800D4650 = c + 2;
    D_800D4644 |= 0x9;
    MEMORY_BARRIER();
    D_800D4668 = v1;
}

void func_80091A48(void) {
    s32 *base;
    s32 *p;
    s32 *q;
    s32 i;
    s32 *status;
    u16 c;

    i = 0;
    base = (s32 *) &D_800D4654;
    q = base + 4;
    p = base;
    do {
        *p = D_800D464C[*(u16 *) ((char *) base - 4)];
        i++;
        c = *(u16 *) ((char *) base - 4);
        c += 1;
        *(u16 *) ((char *) base - 4) = c;
        *q = D_800D464C[c];
        c = *(u16 *) ((char *) base - 4);
        c += 1;
        *(u16 *) ((char *) base - 4) = c;
        p++;
        q++;
    } while (i < 4);
    status = &D_800D4644;
    *status |= 5;
}

extern void func_80091450();

void func_80091AE4(void) {
    s32 sp14;
    s32 sp10;

    func_80091450(&sp10, &sp14);
    func_800EF25C(sp10, sp14);
}

void func_80091B18(void) {
    u16 c = D_800D4650;
    u16 v = D_800D464C[c];

    MEMORY_BARRIER();
    D_800D4650 = c + 1;
    D_800D4644 |= 0x11;
    D_800D4664 = v;
}

extern s32 D_800D466C;

void func_80091B64(void) {
    u16 *base = D_800D464C;
    u16 c = D_800D4650;
    u16 v0;
    u16 c1;
    u16 v1;
    u16 c2;
    u16 v2;

    v0 = base[c];
    MEMORY_BARRIER();
    c1 = c + 1;
    D_800D4650 = c1;
    v1 = base[c1];
    D_800D4664 = v0;
    MEMORY_BARRIER();
    c2 = c + 2;
    D_800D4650 = c2;
    v2 = base[c2];
    D_800D4668 = v1;
    MEMORY_BARRIER();
    D_800D4650 = c + 3;
    D_800D4644 |= 0x21;
    MEMORY_BARRIER();
    D_800D466C = v2;
}

void func_80091BF8(void) {
    u16 *base = D_800D464C;
    u16 c = D_800D4650;
    u16 v0;
    u16 c1;
    u16 v1;

    v0 = base[c];
    MEMORY_BARRIER();
    c1 = c + 1;
    D_800D4650 = c1;
    v1 = base[c1];
    D_800D4664 = v0;
    MEMORY_BARRIER();
    D_800D4650 = c + 2;
    D_800D4644 |= 0x41;
    MEMORY_BARRIER();
    D_800D4668 = v1;
}

void func_80091C68(void) {
    u16 *base = D_800D464C;
    u16 c = D_800D4650;
    u16 v0;
    u16 c1;
    u16 v1;

    v0 = base[c];
    MEMORY_BARRIER();
    c1 = c + 1;
    D_800D4650 = c1;
    v1 = base[c1];
    D_800D4664 = v0;
    MEMORY_BARRIER();
    D_800D4650 = c + 2;
    D_800D4644 |= 0x81;
    MEMORY_BARRIER();
    D_800D4668 = v1;
}

void func_80091CD8(void) {
    u16 *base = D_800D464C;
    u16 c = D_800D4650;
    u16 v0;
    u16 c1;
    u16 v1;

    v0 = base[c];
    MEMORY_BARRIER();
    c1 = c + 1;
    D_800D4650 = c1;
    v1 = base[c1];
    D_800D4664 = v0;
    MEMORY_BARRIER();
    D_800D4650 = c + 2;
    D_800D4644 |= 0x101;
    MEMORY_BARRIER();
    D_800D4668 = v1;
}

void func_80091D48(void) {
    D_800D4664 = D_800D464C[D_800D4650];
    D_800D4644 |= 0x401;
}

void func_80091D88(void) {
    D_800D4664 = D_800D464C[D_800D4650];
    D_800D4644 |= 0x801;
}

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_80091DC8);

INCLUDE_ASM("rom/extracted/blobs/wldcore/nonmatchings/wldcore_4", func_80091DD8);

extern s32 func_80091F00(void);
extern u8 *func_80069E38(s32);

void func_80091E84(void) {
    u8 *p;
    u16 *ctr;
    u16 c;
    s32 temp;

    p = func_80069E38(func_80091F00());
    ctr = &D_800D4650;
    c = *ctr;
    temp = D_800D464C[c];
    *ctr = c + 1;
    if (p[0x17] < temp) {
        D_800D4644 |= 2;
    }
}

s32 func_80091F00(void) {
    extern u8 *func_80069E38();
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 a0 asm("a0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s0 = 0;
    s1 = 0xFF;
loop:
    a0 = s0;
    v0 = (s32) func_80069E38(a0);
    v1 = v0;
    v0 = *(u8 *) (v1 + 1);
    if (v0 == s1)
        goto next;
    v0 = *(u8 *) v1;
    if (v0 == 0)
        goto next;
    v0 = (u32) v0 < 4;
    if (v0 != 0) {
        v0 = s0;
        goto epi;
    }
next:
    s0 += 1;
    v0 = s0 < 0x10;
    if (v0 != 0)
        goto loop;
    v0 = s0;
epi:
    return v0;
}

void func_80091F74(void) {
    u8 *p;
    u16 *ctr;
    u16 c;
    s32 temp;

    p = func_80069E38(func_80091F00());
    ctr = &D_800D4650;
    c = *ctr;
    temp = D_800D464C[c];
    *ctr = c + 1;
    if (temp < p[0x17]) {
        D_800D4644 |= 2;
    }
}

void func_80091FF0(void) {
    u8 *p;
    u16 *ctr;
    u16 c;
    s32 temp;

    p = func_80069E38(func_80091F00());
    ctr = &D_800D4650;
    c = *ctr;
    temp = D_800D464C[c];
    *ctr = c + 1;
    if (p[0x18] < temp) {
        D_800D4644 |= 2;
    }
}

void func_8009206C(void) {
    u8 *p;
    u16 *ctr;
    u16 c;
    s32 temp;

    p = func_80069E38(func_80091F00());
    ctr = &D_800D4650;
    c = *ctr;
    temp = D_800D464C[c];
    *ctr = c + 1;
    if (temp < p[0x18]) {
        D_800D4644 |= 2;
    }
}

void func_800920E8(s32 *arg0, s32 arg1, s32 arg2) {
    s32 *p = arg0;
    s32 new_word;
    s32 adjusted_bit;
    s32 word_index;
    s32 bit_mask;
    s32 set_value;
    s32 bit_index;
    s32 old_word;

    MEMORY_BARRIER();
    if (arg1 < 0) {
        adjusted_bit = arg1 + 0x1F;
    } else {
        adjusted_bit = arg1;
    }
    word_index = adjusted_bit >> 5;
    bit_index = arg1 & 0x1F;
    bit_mask = 1 << bit_index;
    set_value = arg2;
    if (set_value) {
        old_word = p[word_index];
        p[word_index] = old_word | bit_mask;
    } else {
        new_word = p[word_index];
        p[word_index] = new_word & (~bit_mask);
    }
}

s32 func_80092148(s32 *arg0, s32 arg1) {
    register s32 *p asm("a2") = arg0;
    register s32 adjusted_bit asm("v0");
    s32 word = 0;
    s32 bit_index;
    register s32 bit_mask asm("v1");

    MEMORY_BARRIER();
    if (arg1 < 0) {
        adjusted_bit = arg1 + 0x1F;
    } else {
        adjusted_bit = arg1;
    }
    adjusted_bit >>= 5;
    bit_index = arg1 & 0x1F;
    bit_mask = 1 << bit_index;
    word = p[adjusted_bit];
    return (u32) (word & bit_mask) > 0;
}

s32 func_80092180(void) {
    s32 n = 0;
    s32 i = 0;
    register s32 x asm("v0");
    register s32 m asm("v1");
    register s32 hi asm("a2");
    register s32 h asm("v1");
    s32 s;
    s32 q;

    do {
        if (func_80092148(&D_80059374, i) != 0)
            n++;
        MEMORY_BARRIER();
        i++;
    } while (i < 0x1000);
    m = 0x6BCA1AF3;
    x = n * 100;
    __asm__ volatile("mult %0,%1" ::"r"(x), "r"(m));
    s = x >> 31;
    __asm__ volatile("mfhi %0" : "=r"(hi));
    h = hi >> 5;
    q = h - s;
    return q;
}

void func_80092208(void) {
    extern s32 func_800EF1A8(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s16 D_800BB3F0[];
    extern s32 D_800BB998;
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
    register s32 t0 asm("t0");
    register s32 *at asm("at");
    register void *sp asm("sp");

    s3 = 0;
    s0 = 0;
    s2 = D_800BB3F0;
    s1 = D_800D0880;
loop:
    a0 = s0 + 0x1A4;
    v0 = func_800EF1A8(a0);
    if (v0 != 0) {
        v0 = s0 - 0x6800;
        *s1 = v0;
        *s2 = 0;
        s2 += 1;
        s1 += 1;
        s3 += 1;
    }
    s0 += 1;
    v0 = s0 < 0x18;
    if (v0 != 0)
        goto loop;
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
    a0 = 0x14;
    KEEP_NOVOL(a0);
    a1 = s3;
    a2 = s0;
    ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32)) func_8008FCC8)(a0, a1, a2, a3, 0x8C, a2, 0x58, 0x50);
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
    ((void (*)(s32, s32, s32 *, s32 *)) func_8008FAD8)(a0, a1, (s32 *) ((char *) sp + 16), (s32 *) ((char *) sp + 24));
    a0 = 0xE;
    KEEP_NOVOL(a0);
    a1 = 0x19;
    KEEP_NOVOL(a1);
    v1 = D_800BB4F0;
    KEEP_NOVOL(v1);
    a2 = 0xB848;
    KEEP_WITH_NOVOL(a2, v1);
    v1 -= 1;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 -= v1;
    v0 <<= 2;
    at = (s32 *) &D_800BB998;
    at = (s32 *) ((char *) at + v0);
    v1 = *at;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 += v1;
    v0 <<= 2;
    KEEP_NOVOL(v0);
    v1 = D_8004D950;
    v1 |= 0x800;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    t0 = *at;
    t0 |= 0x10;
    D_8004D950 = v1;
    at = (s32 *) &D_800BBC70;
    at = (s32 *) ((char *) at + v0);
    *at = t0;
    MEMORY_BARRIER();
    func_800FFF08(a0, a1, a2, 0);
    v1 = D_800BB4F0;
    v0 = 0x160;
    D_800BB3C0 = v0;
    v0 = 9;
    D_800BB3EC = v0;
    v0 = 0x2E;
    a0 = v1 << 2;
    v1 += 1;
    at = (s32 *) D_800D4584;
    at = (s32 *) ((char *) at + a0);
    *at = v0;
    D_800BB4F0 = v1;
}

void func_8009240C(void) {
    D_800BB3C0 = 0x160;
}

void func_80092420(void) {
    D_800BB3C0 = -1;
}

void func_80092434(s32 *arg0) {
    extern s32 func_800FFEEC();
    extern void func_80092618();
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
        func_8008FC88(0x14);
        h = D_800BB354;
        func_80092618(D_800D0880[h] & 0x7FF);
    } else {
        func_8008FD88(0x14);
        func_8006C44C();
    }
    goto epi;
els:
    if ((D_800BC2F0 & 0x40) == 0)
        goto e2;
    if (D_8004EAF8 != 0)
        goto e2;
    ((void (*)()) func_80090D30)(2);
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
    ((s32 (*)()) func_80092420)(s0);
    func_8006E860(0x108F, 1);
    goto epi;
e3:
    if ((D_800BC2F0 & 0x20) == 0)
        goto epi;
    if (s0[12] == 0)
        goto epi;
    if (D_8004EAF8 != 0)
        goto epi;
    ((void (*)()) func_80090D30)(1);
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

void func_80092618(s32 arg0) {
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
    s0 += 0x9800;
    D_801531D8 = s0;
    func_800FFF08(0xE, 0x19, 0xB849, 0);
    v0 = D_800BB4F0;
    v1 = 0x2F;
    a0 = v0 * 4;
    v0 += 1;
    *(s32 *) ((char *) &D_800D4584 + a0) = v1;
    D_800BB4F0 = v0;
}

void func_800928AC(void) {
    extern s32 D_800BB994;
    extern s32 D_800BB990;
    extern s32 D_800BB9AC;
    extern s32 func_800903E4();
    extern void func_80092208();
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
            v1 &= a1;
            *(s32 *) ((char *) &D_800BBC70 + v0) = v1;
            v0 = *(s32 *) ((char *) &D_800BB9AC + a0);
            v1 = v0 * 36;
            v0 = *(s32 *) ((char *) &D_800BB504 + v1);
            v0 &= a1;
            *(s32 *) ((char *) &D_800BB504 + v1) = v0;
            v1 = *(s32 *) ((char *) &D_800BB9B0 + a0);
            v0 = v1 * 36;
            v1 = *(s32 *) ((char *) &D_800BB504 + v0);
            a2 -= 1;
            D_800BB4F0 = a2;
            v1 &= a1;
            *(s32 *) ((char *) &D_800BB504 + v0) = v1;
            func_80092208();
        }
    }
}

void func_80092B04(void **arg0) {
    register void *sp asm("sp");
    register s32 t0 asm("t0");

    t0 = (s32) arg0;
    KEEP(t0);
    *((void **) t0) = sp;
    t0 -= 4;
    KEEP(t0);
    sp = (void *) t0;
    USE(sp);
}

void func_80092B1C(void) {
    register void *sp asm("sp");

    sp = (void *) ((char *) sp + 4);
    sp = *(void **) sp;
}
