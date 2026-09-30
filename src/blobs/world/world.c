#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();
extern void func_800FFD70();
extern void func_800F0F64();
extern void func_800F0A08();
extern s32 *D_801CD7E0;
extern u16 D_801CD6F0;
extern u16 D_801CD6EC;
extern u16 D_801CD50C;
extern u8 D_8019A1C0[];
extern u8 D_8018BA25;
extern u8 D_801531B0[];
extern void func_8012BD9C();
extern u32 func_8012372C();
extern s16 func_800F93A0();
extern void func_800F6EA8();
extern s32 func_800E7810();
extern s16 D_8018BA20;

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E0228);

extern void func_8002232C();
extern s32 D_800E0000;

s32 func_800E03EC(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 s0v = (s32) arg0;
    register s32 s2v asm("s2") = (s32) arg1;
    register s32 s3v asm("s3");
    register s32 s1v asm("s1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a2v asm("a2");

    KEEP_NOVOL(s0v);
    KEEP_NOVOL(s2v);
    s3v = arg3;
    v0v = *(s32 *) (s2v + 8);
    a2v = arg2 & 0xFFFF;
    s1v = a2v - v0v;
    if (s1v < 0) {
        func_8002232C(&D_800E0000, (s32) arg1);
    }
    v0v = *(s32 *) (s2v + 4);
    v1v = s1v << 2;
    v1v += v0v;
    v0v = s3v & 0xFF;
    v0v <<= 2;
    v0v += 4;
    *(s32 *) s0v = *(s32 *) v1v;
    *(s8 *) (s0v + 3) = s3v;
    *(s32 *) v1v = s0v;
    *(s8 *) (v1v + 3) = 0;
    v0v = s0v + v0v;
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E0480);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E097C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E0AF8);

extern s32 func_800E03EC();
extern s32 D_801CD518;

void func_800E0D5C(u8 *arg0, s32 arg1, s32 arg2) {
    register s32 t0 asm("t0");
    register s32 a1v asm("a1");
    register s32 ev asm("v1");
    register s32 h1 asm("v1");
    u8 *p;
    u8 *q;
    s32 w;
    s32 b;
    u16 t4;
    u16 t6;
    u16 t8;
    u16 tA;

    p = arg0;
    t0 = arg1;
    KEEP(t0);
    w = *(s32 *) p;
    if (w < 0) {
        return;
    }
    q = (u8 *) D_801CD518;
    *(s32 *) (q + 4) = ((w >> 23) & 0x60) | 0xE1000200;
    *(q + 8) = *(p + 0xC);
    *(q + 9) = *(p + 0xD);
    MEMORY_BARRIER();
    b = (w >> 29) & 2;
    ev = *(p + 0xE);
    b |= 0x40;
    *(q + 0xB) = b;
    *(q + 0xA) = ev;
    t4 = *(u16 *) (p + 4);
    arg1 = D_801CD6EC;
    h1 = D_801CD6F0;
    t4 += arg1;
    *(s16 *) (q + 0xC) = t4;
    t6 = *(u16 *) (p + 6);
    t6 += h1;
    *(s16 *) (q + 0xE) = t6;
    t8 = *(u16 *) (p + 8);
    arg2 &= 0xFFFF;
    t8 += arg1;
    a1v = t0;
    *(s16 *) (q + 0x10) = t8;
    tA = *(u16 *) (p + 0xA);
    arg0 = (u8 *) 4;
    tA += h1;
    *(s16 *) (q + 0x12) = tA;
    D_801CD518 = func_800E03EC(q, a1v, arg2, arg0);
}

extern void func_800E116C();
extern s16 D_801CD86C;

void func_800E0E34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 a0 = arg0;
    register s32 a1 asm("a1") = arg1;
    register s32 a2 asm("a2") = arg2;
    register s32 a3 asm("a3");
    register s32 t0 asm("t0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a3 = arg0;
    t0 = *(s32 *) a3;
    if (t0 < 0) {
        goto end;
    }
    a0 = 0xE1000200;
    v1 = (t0 >> 17) & 0x180;
    v0 = (t0 >> 23) & 0x60;
    v0 |= a0;
    a0 = D_801CD518;
    v1 |= v0;
    *(s32 *) (a0 + 4) = v1;
    v0 = *(u8 *) (a3 + 0xC);
    *(u8 *) (a0 + 8) = (u8) v0;
    v0 = *(u8 *) (a3 + 0xD);
    *(u8 *) (a0 + 9) = (u8) v0;
    v0 = (t0 >> 29) & 2;
    v1 = *(u8 *) (a3 + 0xE);
    v0 |= 0x60;
    *(u8 *) (a0 + 0xB) = (u8) v0;
    *(u8 *) (a0 + 0xA) = (u8) v1;
    v0 = *(u16 *) (a3 + 4);
    v1 = D_801CD6EC;
    v0 += v1;
    *(u16 *) (a0 + 0xC) = (u16) v0;
    v0 = *(u16 *) (a3 + 6);
    v1 = D_801CD6F0;
    v0 += v1;
    *(u16 *) (a0 + 0xE) = (u16) v0;
    v0 = *(u16 *) (a3 + 8);
    a2 &= 0xFFFF;
    *(u16 *) (a0 + 0x10) = (u16) v0;
    v0 = *(u16 *) (a3 + 0xA);
    a3 = 4;
    *(u16 *) (a0 + 0x12) = (u16) v0;
    v0 = func_800E03EC(a0, a1, a2, a3);
    MEMORY_BARRIER();
    D_801CD518 = v0;
end:
    return;
}

extern void func_800E0F84();
extern void func_800E1534();
extern void func_800E1648();
extern void func_800E1958();

void func_800E0F0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = arg0 & 0xFFFF;
    temp_s0 = arg1 & 0xFFFF;
    func_800E0F84(temp_s1, temp_s0, arg2 & 0xFFFF, arg3 & 0xFFFF, (s32) arg4);
    func_800E1958();
    D_801CD86C = 0;
    func_800E116C(temp_s1, temp_s0);
    func_800E1648();
    func_800E1534();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E0F84);

extern s16 D_801CD6D8;
extern s16 D_801CD6DA;
extern s16 D_801CD68C;
extern s8 D_801CD68E;
extern s8 D_801CD68F;
extern s8 D_801CD690;
extern s8 D_801CD6E4;
extern s8 D_801CD6E5;
extern s16 D_801CD880;

void func_800E10F4(s16 arg0, s16 arg1, s32 arg2, s8 arg3, u16 arg4) {
    s32 temp_a2;

    temp_a2 = arg2 & 4;
    D_801CD6D8 = arg0;
    D_801CD6DA = arg1;
    D_801CD68C = 0;
    D_801CD68E = arg3;
    D_801CD68F = 0;
    D_801CD690 = 0;
    D_801CD6E4 = arg2 & 1;
    D_801CD880 = temp_a2;
    D_801CD6E5 = (s8) arg4;
    func_800E116C(arg0 & 0xFFFF, arg1 & 0xFFFF, temp_a2);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E116C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E11C4);

extern s16 D_801CD1DC;
extern s16 D_801CD1E0;
extern u8 D_80195C18[];
extern u8 D_80195C19[];
extern u8 D_80195C1A[];
extern u8 D_80195C14;
extern u8 D_80195C1C[];
extern u8 D_80195C1E[];
extern u8 D_80195C20[];
extern u8 D_80195C22[];
extern s32 D_801CD760;
extern u16 D_801CD760u asm("D_801CD760");
extern s32 D_801CD74Cs asm("D_801CD74C");
extern u16 D_801CD74Cu asm("D_801CD74C");
extern u8 D_801CD6E5u asm("D_801CD6E5");

void func_800E13E8(u8 arg0, u8 arg1, u8 arg2, void *arg3) {
    extern void func_80023BB4(s32, u8 *);
    s32 v0v;
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");

    v0v = D_801CD86C;

    MEMORY_BARRIER();
    v0v <<= 4;
    D_80195C18[v0v] = arg0;
    v0v = D_801CD86C;
    v0v <<= 4;
    D_80195C19[v0v] = arg1;
    v0v = D_801CD86C;
    v0v <<= 4;
    D_80195C1A[v0v] = arg2;
    v0v = D_801CD86C;
    a0v = v0v << 1;
    a1v = v0v << 4;
    v1v = *(u16 *) ((u8 *) &D_801CD1DC + a0v);
    v0v = D_801CD760u;
    *(u16 *) ((u8 *) &D_80195C1C + a1v) = v1v;
    v1v = *(u16 *) ((u8 *) &D_801CD1E0 + a0v);
    *(u16 *) ((u8 *) &D_80195C22 + a1v) = v0v;
    *(u16 *) ((u8 *) &D_80195C1E + a1v) = v1v;
    if (D_801CD6E5u != 0) {
        v0v = D_801CD74Cs;
        v1v = v0v * 3;
        v1v = v1v / 2;
        *(u16 *) ((u8 *) &D_80195C20 + a1v) = v1v;
    } else {
        *(u16 *) ((u8 *) &D_80195C20 + a1v) = D_801CD74Cu;
    }
    v0v = (s32) &D_80195C14;
    a1v = D_801CD86C;
    a0v = *(s32 *) ((u8 *) arg3 + 0x10);
    a1v <<= 4;
    func_80023BB4(a0v, (u8 *) (a1v + v0v));
}

s16 func_800E1524(void) {
    return D_801CD86C;
}

extern u16 D_801CD508u asm("D_801CD508");
extern s16 D_801CD508s asm("D_801CD508");
extern u16 D_801CD50Au asm("D_801CD50A");
extern s16 D_801CD50As asm("D_801CD50A");
extern u16 D_801CD1DCu[] asm("D_801CD1DC");
extern s16 D_801CD1DCs[] asm("D_801CD1DC");
extern u16 D_801CD1E0u[] asm("D_801CD1E0");
extern s16 D_801CD1E0s[] asm("D_801CD1E0");
extern s16 D_801CD680;
extern s16 D_801CD682;
extern void func_80024CAC();
extern void func_8001D1A8();

void func_800E1534(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a1v asm("a1");
    s16 *p1;
    s16 *p2;
    s16 *p3;
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_s1;

    if (D_801CD880 != 0) {
        v1v = D_801CD86C;
        v0v = D_801CD508u;
        a1v = D_801CD1DCu[v1v];
        MEMORY_BARRIER();
        p3 = &D_801CD680;
        D_801CD6F0 = 0;
        D_801CD6EC = 0;
        MEMORY_BARRIER();
        v0v = v0v + a1v;
        *p3 = v0v;
        v0v = D_801CD50Au;
        v1v = D_801CD1E0u[v1v];
        v0v = v0v + v1v;
        D_801CD682 = v0v;
        func_80024CAC(p3 - 4);
    } else {
        p1 = D_801CD1DCs;
        temp_a0 = D_801CD508s;
        if (D_801CD86C == 0) {
            p1++;
        }
        v0v = p1[0];
        p2 = D_801CD1E0s;
        temp_s1 = temp_a0 + v0v;
        temp_a2 = D_801CD50As;
        if (D_801CD86C == 0) {
            p2++;
        }
        temp_s0 = temp_a2 + p2[0];
        func_8001D1A8(temp_s1, temp_s0);
        D_801CD6EC = temp_s1;
        D_801CD6F0 = temp_s0;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E1648);

extern s16 D_801CD678;
extern s16 D_801CD67A;
extern s16 D_801CD67C;
extern s16 D_801CD67E;
extern s16 D_801CD806;
extern u16 D_801CD808;
extern u16 D_801CD80A;

void func_800E1660(void) {
    s32 v0v;
    register s32 a0v asm("a0");
    register s32 v1v asm("v1");
    s32 t1;
    s32 t2;
    u16 t3;
    s32 t4;

    MEMORY_BARRIER();
    v0v <<= 1;
    t1 = *(s16 *) ((u8 *) &D_801CD1DC + v0v);
    t2 = *(s16 *) ((u8 *) &D_801CD1E0 + v0v);
    t3 = D_801CD80A;
    D_801CD67C = a0v;
    a0v = (s32) &D_801CD678;
    D_801CD67E = (s16) t3;
    t4 = D_801CD806;
    USE(a0v);
    *(s16 *) a0v = (s16) (v1v + t1);
    D_801CD67A = (s16) (t4 + t2);
    func_80024CAC();
}

extern u16 D_801CD804;

void func_800E16D8(u16 *arg0) {
    u16 t;
    t = arg0[0];
    D_801CD804 = t;
    t = arg0[1];
    D_801CD806 = t;
    t = arg0[2];
    D_801CD808 = t;
    t = arg0[3];
    D_801CD80A = t;
}

extern u16 D_801CD6D4;
extern u16 D_801CD6D6;
extern s32 D_801CD868;
extern void func_80024E84(u16 *);
extern void func_80024638(s32);

void func_800E1710(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    v0v = D_801CD86C;

    MEMORY_BARRIER();
    v0v <<= 1;
    a0v = (s32) &D_801CD6D4;
    v1v = *(u16 *) ((u8 *) &D_801CD1DC + v0v);
    *(u16 *) a0v = v1v;
    v0v = *(u16 *) ((u8 *) &D_801CD1E0 + v0v);
    *(u16 *) &D_801CD6D6 = v0v;
    func_80024E84(&D_801CD6D4);
    func_80024638(1);
    v0v = D_801CD868;
    v0v += 1;
    v1v = v0v;
    D_801CD868 = v1v;
    if (v1v == 0) {
        v1v = 1;
    }
    D_801CD868 = v1v;
    D_801CD86C = D_801CD86C == 0;
    func_800E1648();
    func_800E1534();
}

extern s16 D_801CD1DE;
extern s16 D_801CD1E2;
extern s16 D_801CD21C;
extern s16 D_801CD21E;
extern s16 D_801CD220;
extern s16 D_801CD222;

void func_800E17C4(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 v0v;
    v0v = D_801CD880;

    D_801CD1DC = arg0;
    D_801CD1DE = arg2;
    D_801CD1E0 = arg1;
    D_801CD1E2 = arg3;
    if (v0v == 0) {
        goto alternate;
    }
    D_801CD21C = 0;
    D_801CD21E = 0;
    D_801CD220 = 0;
    D_801CD222 = 0;
    goto common;
alternate:
    D_801CD21C = arg0;
    D_801CD21E = arg2;
    D_801CD220 = arg1;
    D_801CD222 = arg3;
common:
    func_800E1648();
    func_800E1534();
}

extern s16 D_801CD508;
extern s16 D_801CD50A;
extern s32 D_801CD7DC;
extern s32 D_801CD83C;
extern s32 D_801CD854;
extern s32 D_801CD74C;

void func_800E1864(void) {
    s32 v0v;
    register s32 v1v asm("v1");
    v0v = D_801CD74C;

    MEMORY_BARRIER();
    v1v = (u32) v0v >> 31;
    v0v = v0v + v1v;
    v0v >>= 1;
    D_801CD508 = v0v;
    v1v = D_801CD760;
    v1v = (s32) (v1v + ((u32) v1v >> 31)) >> 1;
    D_801CD50A = v1v;
    func_800E1534();
    D_801CD854 = 0xA;
    D_801CD83C = 0;
    D_801CD7DC = 0x3FFF;
}

extern void func_80024C38();

void func_800E18DC(s32 *arg0) {
    func_80024C38(arg0[4]);
}

extern void func_80024B40();

void func_800E1900(s32 arg0, s32 arg1, s32 *arg2) {
    arg2[2] = arg0 & 0xFFFF;
    arg2[3] = arg1 & 0xFFFF;
    arg2[4] = ((4 << arg2[0]) + arg2[1]) - 4;
    func_80024B40(arg2[1], 1 << arg2[0]);
}

extern void func_8001BEB8();
extern void func_8001D188();

void func_800E1958(void) {
    func_8001BEB8();
    func_8001D188(0, 0, 0);
    func_8001D1A8(0, 0);
    D_801CD6F0 = 0;
    D_801CD6EC = 0;
}

void func_800E19A4(void *arg0, void *arg1) {
    u32 t;
    u8 *q;

    t = *(u32 *) arg0;
    *(u32 *) arg1 = t;
    if (((t >> 3) & 1) != 0) {
        arg0 = (u8 *) arg0 + 4;
        q = (u8 *) arg0 + ((*(u32 *) arg0 >> 2) * 4);
        arg0 = (u8 *) arg0 + 4;
        *(u16 *) ((u8 *) arg1 + 0x10) = *(u16 *) arg0;
        *(u16 *) ((u8 *) arg1 + 0x12) = *(u16 *) ((u8 *) arg0 + 2);
        arg0 = (u8 *) arg0 + 4;
        *(u16 *) ((u8 *) arg1 + 0x14) = *(u16 *) arg0;
        q = q + 4;
        *(u16 *) ((u8 *) arg1 + 0x16) = *(u16 *) ((u8 *) arg0 + 2);
        arg0 = (u8 *) arg0 + 4;
        *(u32 *) ((u8 *) arg1 + 0x18) = (u32) arg0;
        *(u16 *) ((u8 *) arg1 + 4) = *(u16 *) q;
        *(u16 *) ((u8 *) arg1 + 6) = *(u16 *) (q + 2);
        q = q + 4;
        *(u16 *) ((u8 *) arg1 + 8) = *(u16 *) q;
        *(u16 *) ((u8 *) arg1 + 0xA) = *(u16 *) (q + 2);
        q = q + 4;
        *(u32 *) ((u8 *) arg1 + 0xC) = (u32) q;
    } else {
        arg0 = (u8 *) arg0 + 8;
        *(u16 *) ((u8 *) arg1 + 4) = *(u16 *) arg0;
        *(u16 *) ((u8 *) arg1 + 6) = *(u16 *) ((u8 *) arg0 + 2);
        arg0 = (u8 *) arg0 + 4;
        *(u16 *) ((u8 *) arg1 + 8) = *(u16 *) arg0;
        *(u16 *) ((u8 *) arg1 + 0xA) = *(u16 *) ((u8 *) arg0 + 2);
        arg0 = (u8 *) arg0 + 4;
        *(u32 *) ((u8 *) arg1 + 0xC) = (u32) arg0;
    }
}

void func_800E1A88(s32 arg0) {
    D_801CD518 = arg0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E1A98);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E1BC0);

extern s32 func_8008CDD0(s32);
extern s32 func_800EF1A8(s32);

void func_800E1CB4(s32 arg0, s32 arg1) {
    extern s32 func_8008CE20(s32);
    extern void func_8008C114(s32, s32);
    extern u8 *func_80180AFC(s32);
    s32 temp_v0;
    u8 *temp_p;

    if (func_800EF1A8(0x1FD) == 0) {
        temp_v0 = func_8008CDD0(arg0);
        if (temp_v0 >= 0) {
            temp_p = func_80180AFC(temp_v0);
            if (temp_p[0x182] != 0) {
                func_8008C114(func_8008CE20(temp_p[0x182] & 0x1F), arg1 & 0xFFFF);
            }
        }
    }
    func_8008C114(arg0, arg1 & 0xFFFF);
}

extern void func_800FFF50();

s32 func_800E1D44(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (arg0 >= 0x60) {
        arg0 = 0x7F;
    } else {
        arg0 = (arg0 * 0x7F) / 96;
    }
    return arg0;
}

extern s32 D_80153320;

void func_800E1D90(void) {
    s32 temp_v0;

    D_80153320 = 0xFF;
    do {
        func_800FFF50();
        temp_v0 = D_80153320 - 4;
        D_80153320 = temp_v0;
    } while (temp_v0 > 0);
    D_80153320 = 0;
}

void func_800E1DE4(void) {
    s32 temp_v0;

    D_80153320 = 0;
    do {
        func_800FFF50();
        temp_v0 = D_80153320 + 4;
        D_80153320 = temp_v0;
    } while (temp_v0 < 0x100);
    D_80153320 = 0xFF;
}

s32 func_800E1E38(void) {
    return 0;
}

s32 func_800E1E40(void) {
    s32 save;
    s32 ret;
    save = func_800E7810();
    if (save == 0x7D0) {
        return 0x7D0;
    }
    ret = func_8008CDD0(save);
    if (ret == -1) {
        return (ret = 0x7D0);
    }
    return ret;
}

extern s16 D_80153258;

void func_800E1E8C(void) {
    D_80153258 = 1;
}

void func_800E1EA0(void) {
    D_80153258 = 0;
}

extern s32 D_80153298;

void func_800E1EB0(void) {
    D_80153298 = 1;
}

void func_800E1EC4(void) {
    D_80153298 = 2;
}

void func_800E1ED8(void) {
    D_80153298 = 3;
}

extern void func_800FFE28();

void func_800E1EEC(void) {
    D_80153298 = 5;
}

extern void func_800E1EEC();

void func_800E1F00(void) {
    func_800E1EEC();
    func_800FFE28();
}

extern s32 func_8008E17C();
extern s32 *D_80153280;

void func_800E1F28(void) {
    do {
        func_800FFF50();
    } while (func_8008E17C() != 0);
}

void func_800E1F58(void) {
    D_80153280[0x1E] = (D_80153280[0x1E] + 0xA000) & 0xFFF;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E1F7C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E1F84);

extern s16 D_8013A36E;

s32 func_800E20A0(void) {
    s32 v0v;

    v0v = D_80153280[0x1E];
    __asm__ volatile(".word 0x00000000\n\t.word 0x04410005\n\t.word 0x00000000\n\t.word 0x24421000\n\t.word 0x0440ffff\n\t.word 0x24421000\n\t.word 0x2442f000" : "=r"(v0v) : "0"(v0v));
    return v0v;
}

extern u8 *func_80180AFC();

s32 func_800E20D4(void) {
    s32 a0v;

    a0v = D_8013A36E;
    func_80180AFC(a0v);
}

void func_800E20FC(s32 *arg0, s32 arg1, s32 arg2) {
    s32 t = *arg0;
    if (t < arg1) {
        *arg0 = arg1;
    } else if (arg2 < t) {
        *arg0 = arg2;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E212C);

void func_800E2390(void) {
}

extern void func_80023C90();
extern void func_80023D1C();

void func_800E2398(u8 *arg0) {
    func_80023D1C();
    func_80023C90(arg0, 0);
    arg0[0x4] = 0x80;
    arg0[0x5] = 0x80;
    arg0[0x6] = 0x80;
    arg0[0x14] = 1;
    arg0[0x1D] = 1;
    arg0[0x24] = 1;
    arg0[0x25] = 1;
    arg0[0xC] = 0;
    arg0[0xD] = 0;
    arg0[0x15] = 0;
    arg0[0x1C] = 0;
    *(s16 *) (arg0 + 8) = -0x200;
    *(s16 *) (arg0 + 0xA) = 0;
    *(s16 *) (arg0 + 0x10) = -0x200;
    *(s16 *) (arg0 + 0x12) = 0;
    *(s16 *) (arg0 + 0x18) = -0x200;
    *(s16 *) (arg0 + 0x1A) = 0;
    *(s16 *) (arg0 + 0x20) = -0x200;
    *(s16 *) (arg0 + 0x22) = 0;
    *(s16 *) (arg0 + 0x16) = func_8002398C(0, 0, 0x1C0, 0);
    *(s16 *) (arg0 + 0xE) = 0x7C3C;
}

extern void func_80023D80();
extern void func_80023C90(void *, s32);
extern void func_80023C68(void *, s32);

void func_800E2444(void *arg0) {
    u8 *s0 = (u8 *) arg0;
    register u8 *a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 v0 asm("v0");

    func_80023D80();
    func_80023C90(s0, 0);
    a0v = s0;
    a1v = 1;
    MEMORY_BARRIER();
    v0 = 0x80;
    a0v[4] = v0;
    a0v[5] = v0;
    a0v[6] = v0;
    v0 = 0x200;
    *(s16 *) (a0v + 8) = v0;
    v0 = 0x7C3C;
    a0v[0xC] = 0;
    a0v[0xD] = 0;
    *(s16 *) (a0v + 0x10) = 0;
    *(s16 *) (a0v + 0x12) = 0;
    *(s16 *) (a0v + 0xA) = 0;
    *(s16 *) (a0v + 0xE) = v0;
    func_80023C68(a0v, a1v);
}

void func_800E24B8(register u8 *arg0, register s32 arg1, register s16 arg2) {
    register s16 value asm("s3");
    register s32 i;
    s32 pad[2];

    value = arg2;
    KEEP_NOVOL(value);
    i = 0;
    if (arg1 <= 0) {
        goto end;
    }
    do {
        func_800E2444(arg0);
        *(s16 *) (arg0 + 0xE) = value;
        i += 1;
        arg0 += 0x14;
    } while (i < arg1);
end:
}

extern s32 D_8019B344;

void func_800E2520(void) {
    s32 neg = -1;
    s32 i = 5;
    s32 *p = &D_8019B344;
    do {
        *p = neg;
        i--;
        p--;
    } while (i >= 0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E2548);

extern s32 D_8019AB88[];
extern s32 D_8019AB8C[];
extern s32 D_8019ACA0[];

void func_800E279C(s32 arg0) {
    s32 a1 = 0;
    s32 v1 = 0x118;
    s32 v0;

loop:
    v0 = *(s32 *) ((u8 *) D_8019AB8C + v1);
    if (v0 == arg0) {
        *(s32 *) ((u8 *) D_8019AB88 + v1) = 0;
        *(s32 *) ((u8 *) D_8019ACA0 + v1) = 0;
        return;
    }
    a1 += 2;
    v1 += 0x230;
    if (a1 < 6) {
        goto loop;
    }
}

extern s32 D_8019ACA4[];
extern s32 D_8019B330;

void func_800E27F4(s32 arg0) {
    s32 v0v;
    s32 v1v;
    s32 a1v;
    s32 a2v;
    s32 a3v;
    s32 t0v;

    v0v = -1;
    if (arg0 == v0v) {
        goto end;
    }
    a3v = 0;
    t0v = -1;
    a1v = 0x118;
    v0v = (s32) &D_8019B330;
    a2v = v0v + 4;
    v1v = v0v;
    do {
        v0v = *(s32 *) v1v;
        a3v += 2;
        if (v0v == arg0) {
            *(s32 *) v1v = t0v;
            *(s32 *) a2v = t0v;
            *(s32 *) ((u8 *) D_8019AB88 + a1v) = 0;
            *(s32 *) ((u8 *) D_8019ACA0 + a1v) = 0;
            *(s32 *) ((u8 *) D_8019AB8C + a1v) = 0;
            *(s32 *) ((u8 *) D_8019ACA4 + a1v) = 0;
            goto end;
        }
        a1v += 0x230;
        a2v += 8;
        v1v += 8;
    } while (a3v < 6);
    func_800FFE28(arg0, a1v, a2v, a3v);
end:
    return;
}

void func_800E289C(u8 *arg0, s32 arg1) {
    arg0[4] = arg1;
    arg0[5] = arg1;
    arg0[6] = arg1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E28AC);

typedef struct {
    u8 b[16];
} Row16;

typedef struct {
    u8 pad06[6];
    u16 f06;
    u16 f08;
    u16 f0A;
    u16 f0C;
    u8 pad0E[8];
    u16 f16;
    u16 f18;
    u8 pad1A[6];
    u16 f20;
    u16 f22;
    u8 pad24[2];
} W23508Rec24;

extern Row16 D_8019A0D0[];

void func_800E2C0C(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 0xF; i++) {
        for (j = 0xF; j >= 0; j--) {
            D_8019A0D0[i].b[j] = 0;
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E2C48);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E2EDC);

extern s32 D_80153368;
extern s32 D_80153374;
extern u8 D_8019B368[];
extern s8 D_801A2457[];

void func_800E3088(void) {
    s32 v0;
    s32 v1;
    u8 *a0;
    u8 *a1;
    s8 *p;

    v1 = -1;
    v0 = 0x78;
    do {
        *(s32 *) (D_8019B368 + v0) = v1;
        v0 -= 8;
    } while (v0 >= 0);
    v1 = 0x6F;
    p = D_801A2457;
    do {
        *p = 0;
        v1--;
        p--;
    } while (v1 >= 0);
    v1 = 0;
    a1 = (u8 *) &D_80153374;
    a0 = (u8 *) &D_80153368;
    do {
        *(s32 *) a0 = 0;
        *(s32 *) a1 = 0;
        a1 += 4;
        v1++;
        a0 += 4;
    } while (v1 < 3);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E30FC);

extern s32 func_800E30FC();

void func_800E3278(void) {
    func_800E30FC();
}

extern s32 D_80010008;
extern u32 D_8019B3E8;
extern u32 D_8019B36C[];
extern u8 D_801A23E8[];

void func_800E3298(u32 arg0) {
    register u32 a0v asm("a0");
    register u32 v0v asm("v0");
    register u32 a1v asm("a1");
    register u32 a2v asm("a2");
    register u32 a3v asm("a3");
    register s32 *v1v asm("v1");
    register u32 t0v asm("t0");
    register u32 t1v asm("t1");
    volatile u32 pad;
    v0v = D_80010008;

    if ((a0v < v0v) && (a0v != 0xFFFFFFFFU)) {
        v0v = (u32) &D_8019B3E8;
        v0v = a0v - v0v;
        a2v = v0v >> 8;
        t0v = (u32) D_801A23E8;
        a1v = (u32) D_8019B36C;
        v1v = (s32 *) ((u8 *) a1v - 4);
        a3v = a1v + 0x80;
        t1v = -1;
loop:
        v0v = *(u32 *) v1v;
        if (v0v != a0v) {
            goto next;
        }
        *(u32 *) v1v = t1v;
        v0v = *(u32 *) a1v;
        if ((s32) v0v <= 0) {
            goto end;
        }
        v1v = 0;
        KEEP(v1v);
        do {
            v0v = (u32) v1v + a2v;
inner:
            v0v += t0v;
            *(u8 *) v0v = 0;
            v0v = *(u32 *) a1v;
            v1v = (s32 *) ((u8 *) v1v + 1);
            v0v = (s32) (u32) v1v < (s32) v0v;
        } while (v0v != 0);
        v0v = (u32) v1v + a2v;
        goto end;
next:
        a1v += 8;
        v0v = (s32) a1v < (s32) a3v;
        v1v += 2;
        if (v0v != 0) {
            goto loop;
        }
        func_800FFE28(a0v, a1v, a2v, a3v);
    }
end:
}

extern void func_80023DE4(void *);
extern s32 func_800254CC();
extern u8 D_80154CBC;
extern volatile u8 D_80154CD0[];
extern volatile u8 D_80154CD1[];
extern volatile u8 D_80154CD2[];
extern volatile u8 D_80154CD3[];
extern s8 D_80154CD4[];
extern s8 D_80154CD5[];
extern s8 D_80154CD6[];
extern s8 D_80154CD7[];

void func_800E3358(u16 *arg0, u8 *arg1) {
    extern void func_800E3618(u8 *);
    extern void func_800E2444(void *);
    u8 *var_s0;
    u8 *var_s3;
    register u8 *var_a0 asm("a0");
    s32 var_a1;
    s32 var_s2;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v0_2;

    var_s3 = arg1;
    var_s0 = arg1 + 0x18;
    var_s2 = 0;
    do {
        func_80023DE4(var_s0);
        var_s2 += 1;
        var_s0 += 0x10;
    } while (var_s2 < 0xC);
    func_800E3618(var_s3);
    var_a1 = 0;
    var_s2 = 0;
    var_a0 = var_s3 + 0x26;
    do {
        temp_v0 = ((s32) D_80154CD0[var_a1] << 24) >> 24;
        temp_v1 = arg0[0];
        *(u16 *) (var_a0 - 6) = (u16) (temp_v0 + temp_v1);
        temp_v0 = ((s32) D_80154CD1[var_a1] << 24) >> 24;
        temp_v1 = arg0[1];
        *(u16 *) (var_a0 - 4) = (u16) (temp_v0 + temp_v1);
        temp_v0 = ((s32) D_80154CD2[var_a1] << 24) >> 24;
        temp_v1 = arg0[0];
        *(u16 *) (var_a0 - 2) = (u16) (temp_v0 + temp_v1);
        temp_v0 = ((s32) D_80154CD3[var_a1] << 24) >> 24;
        temp_v1 = arg0[1];
        *(u16 *) var_a0 = (u16) (temp_v0 + temp_v1);
        if (D_80154CD4[var_a1] != 0) {
            *(u16 *) (var_a0 - 6) += arg0[2];
        }
        if (D_80154CD5[var_a1] != 0) {
            *(u16 *) (var_a0 - 4) += arg0[3];
        }
        if (D_80154CD6[var_a1] != 0) {
            *(u16 *) (var_a0 - 2) += arg0[2];
        }
        if (D_80154CD7[var_a1] != 0) {
            *(u16 *) var_a0 += arg0[3];
        }
        var_a1 += 8;
        var_a0 += 0x10;
        var_s2 += 1;
    } while (var_s2 < 0xC);
    temp_v0 = func_8002398C(0, 0, 0x3C0, 0x100);
    func_800254CC(var_s3 + 0xC, 1, 0, temp_v0 & 0xFFFF, &D_80154CBC);
    temp_v0 = func_8002398C(0, 2, 0x3C0, 0x100);
    func_800254CC(var_s3, 0, 0, temp_v0 & 0xFFFF, &D_801531B0);
    func_800E2444(var_s3 + 0xD8);
    *(u16 *) (var_s3 + 0xE0) = arg0[0];
    *(u16 *) (var_s3 + 0xE2) = arg0[1];
    *(u16 *) (var_s3 + 0xE8) = arg0[2];
    *(u16 *) (var_s3 + 0xEA) = arg0[3];
}

extern void func_800FDAA4();

void func_800E35AC(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0x18;
    do {
        func_800FDAA4(arg0 + var_s0);
        var_s1 += 1;
        var_s0 += 0x10;
    } while (var_s1 < 0xC);
    func_800FDAA4(arg0);
    func_800FDAA4(arg0 + 0xD8);
    func_800FDAA4(arg0 + 0xC);
}

extern u8 D_80154CC4[];

void func_800E3618(u8 *arg0) {
    register u8 *a1 asm("a1");
    s32 i;
    s32 v;

    i = 0;
    a1 = arg0 + 0x1E;
    do {
        v = D_80154CC4[i] * 2;
        a1[-2] = (D_8019A1C0[v] & 0x1F) * 8;
        a1[-1] = ((*(u16 *) &D_8019A1C0[v] >> 2) & 0xF8);
        a1[0] = ((*(u16 *) &D_8019A1C0[v] >> 7) & 0xF8);
        i += 1;
        a1 += 0x10;
    } while (i < 0xC);
    *(u16 *) (arg0 + 0xE6) = 0x7C3C;
}

extern s32 D_801CD170;

void func_800E36A0(u8 *arg0) {
    register u8 *a1 asm("a1");
    s32 i;
    s32 v;

    i = 0;
    a1 = arg0 + 0x1E;
    do {
        v = (D_80154CC4[i] + 0x10) * 2;
        a1[-2] = (D_8019A1C0[v] & 0x1F) * 8;
        a1[-1] = ((*(u16 *) &D_8019A1C0[v] >> 2) & 0xF8);
        a1[0] = ((*(u16 *) &D_8019A1C0[v] >> 7) & 0xF8);
        i += 1;
        a1 += 0x10;
    } while (i < 0xC);
    *(u16 *) (arg0 + 0xE6) = 0x7D3C;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E372C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E38A8);

void func_800E3B38(void) {
    s32 a0 = 0;
    s32 a2 = D_801CD170;
    u8 *a1 = (u8 *) &D_80153374;
    u8 *v1 = (u8 *) &D_80153368;
    s32 v0;

loop:
    v0 = *(s32 *) v1;
    if (a2 == v0) {
        *(s32 *) v1 = 0;
        *(s32 *) a1 = 0;
        return;
    }
    a1 += 4;
    a0++;
    v1 += 4;
    if (a0 < 3) {
        goto loop;
    }
}

extern s32 D_80195D1C[];

s32 func_800E3B8C(void) {
    s32 v;

    v = D_801CD170;
    return D_80195D1C[v << 8];
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E3BB0);

s32 func_800E41FC(s32 arg0, s32 arg1) {
    if (arg0 == 0xE0) {
        return 0x4000;
    }
    if (arg0 == 0xE1) {
        return arg1 + 0x4000;
    }
    if (arg0 == 0xE5) {
        return arg1 + 0x9000;
    }
    if (arg0 == 0xE9) {
        return arg1 + 0x3800;
    }
    if (arg0 == 0xEA) {
        return arg1 + 0x7000;
    }
    if (arg0 == 0xEB) {
        return arg1;
    }
    return -1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E4268);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E4668);

extern s32 func_800FF690_s() asm("func_800FF690");
extern s32 func_800FF9AC();
extern void func_800FE774_s(s32, s32, s32) asm("func_800FE774");
extern u16 D_80153284;
extern u16 D_80153286;
extern s32 D_8015328C;
extern s32 D_80153304;
extern s32 D_80153308;

void func_800E4B04(u8 *arg0) {
    u8 *s0;
    register s32 v1 asm("v1");
    register s32 v0 asm("v0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");

    s0 = arg0;
    v1 = *(u16 *) (s0 + 0x18);
    v0 = 0x10;
    if (v1 == 0) {
        return;
    }
    if (v1 == v0) {
        v0 = func_800FF690_s(*(u16 *) (s0 + 4), *(u16 *) (s0 + 6), s0 + 8,
                             *(u16 *) (s0 + 0x16), *(s16 *) (s0 + 0x30), 1);
        *(s32 *) s0 = v0;
    } else {
        v0 = func_800FF9AC(*(u16 *) (s0 + 4), *(u16 *) (s0 + 6), s0 + 8, 1);
        *(s32 *) s0 = v0;
    }
    v0 = *(u16 *) (s0 + 0x40);
    MEMORY_BARRIER();
    a2v = (s32) &D_80153284;
    KEEP_NOVOL(a2v);
    *(u16 *) a2v = v0;
    D_80153286 = *(u16 *) (s0 + 0x42);
    v0 = *(s16 *) (s0 + 0xC);
    D_8015328C = v0 * 4;
    v0 = *(u16 *) (s0 + 0x22);
    a0v = *(s32 *) (s0 + 0x10);
    a1v = *(s32 *) s0;
    KEEP_NOVOL(a1v);
    v1 = *(u16 *) (s0 + 0x24);
    D_80153304 = v0;
    D_80153308 = v1;
    func_800FE774_s(a0v, a1v, a2v);
    func_800248FC(s0 + 8, *(s32 *) s0);
    func_800FFF50();
    func_800E3298(*(s32 *) s0);
}

s32 func_800E4BF4(void *arg0, s32 arg1) {
    register s32 a0 asm("a0") = (s32) arg0;
    register s32 a1 asm("a1") = arg1;
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v0 = *(s32 *) (a0 + 0x18);
    a1 += 1;
    if (v0 > 0) {
        v0 -= 1;
        *(s32 *) (a0 + 0x18) = v0;
        if (v0 == 0) {
            a1 = *(s32 *) (a0 + 0x1C);
            v0 = -1;
            *(s32 *) (a0 + 0x1C) = v0;
        }
    }
    a2 = *(u8 *) a1;
    v0 = 0xF0;
    v1 = a2 & 0xF0;
    if (v1 == v0) {
        v0 = a2 & 0xF;
        v0 = (u32) v0 < 4U;
        if (v0 != 0) {
            v0 = a1 + 3;
            *(s32 *) (a0 + 0x1C) = v0;
            v0 = *(u8 *) a1;
            v0 &= 3;
            v0 <<= 3;
            *(volatile s32 *) (a0 + 0x14) = v0;
            v0 = *(u8 *) (a1 + 1);
            v1 = *(volatile s32 *) (a0 + 0x14);
            v0 >>= 5;
            *(volatile s32 *) (a0 + 0x18) = v0;
            v0 += v1;
            v0 += 4;
            *(s32 *) (a0 + 0x18) = v0;
            v0 = *(u8 *) (a1 + 1);
            v0 &= 0xF;
            v1 = v0 << 7;
            v1 -= v0;
            v1 <<= 1;
            *(s32 *) (a0 + 0x14) = v1;
            v0 = *(u8 *) (a1 + 2);
            v0 += v1;
            a1 -= v0;
            *(s32 *) (a0 + 0x14) = v0;
        }
    }
    return a1;
}

s32 func_800E4CB0(void *arg0, s32 arg1, void **arg2) {
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v0 = *(s32 *) arg0;
    arg1 += 1;
    if (v0 > 0) {
        v0 -= 1;
        *(s32 *) arg0 = v0;
        if (v0 == 0) {
            arg1 = *(s32 *) arg2;
            v0 = -1;
            *(s32 *) arg2 = v0;
        }
    }
    a3 = *(u8 *) arg1;
    v0 = 0xF0;
    v1 = a3 & 0xF0;
    if (v1 == v0) {
        v0 = a3 & 0xF;
        v0 = (u32) v0 < 4U;
        if (v0 != 0) {
            v0 = arg1 + 3;
            *(s32 *) arg2 = v0;
            v1 = *(u8 *) arg1;
            v0 = *(u8 *) (arg1 + 1);
            v1 &= 3;
            v1 <<= 3;
            v0 >>= 5;
            __asm__ volatile("" : "=r"(v0), "=r"(v1) : "0"(v0), "1"(v1));
            v0 = v1 + v0;
            v0 += 4;
            *(s32 *) arg0 = v0;
            v0 = *(u8 *) (arg1 + 1);
            v1 = v0 & 0xF;
            v0 = v1 << 7;
            v0 -= v1;
            v1 = *(u8 *) (arg1 + 2);
            v0 <<= 1;
            v1 = v0 + v1;
            arg1 -= v1;
        }
    }
    return arg1;
}

extern void func_800235AC();
extern s32 D_800E0050;
extern s32 D_801CD8A4;

void func_800E4D50(s32 arg0) {
    s32 a = arg0;
    register s32 *p asm("s1") = &D_800E0050;

    func_800235AC(p, a);
    func_800235AC(p, a + 1);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E4D9C);

extern void func_80100348();

void func_800E6EDC(s32 arg0) {
    func_80100348(*(s32 *) ((u8 *) &D_801CD8A4 + (((u32) (arg0 & 0xF800)) >> 9)), arg0 & 0x7FF);
}

s32 func_800E6F14(s32 arg0) {
    register s32 a0v asm("a0") = arg0;
    register s32 a1v asm("a1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a2v asm("a2");

    __asm__ volatile(".word 0x3c026666\n\t.word 0x34426667\n\t.word 0x00820018\n\t.word 0x00041fc3\n\t.word 0x00001010\n\t.word 0x00021083\n\t.word 0x00432023" : "=r"(a0v), "=r"(v0v), "=r"(v1v) : "0"(a0v));
    a1v = 1;
    if (a0v != 0) {
        __asm__ volatile(".word 0x3c066666\n\t.word 0x34c66667" : "=r"(a2v));
        do {
            __asm__ volatile(".word 0x00860018\n\t.word 0x00041fc3\n\t.word 0x00001010\n\t.word 0x00021083\n\t.word 0x00432023" : "=r"(a0v), "=r"(v0v), "=r"(v1v) : "0"(a0v));
            a1v += 1;
        } while (a0v != 0);
    }
    return a1v;
}

typedef struct {
    u8 pad00[12];
    u8 f0C;
    u8 f0D;
    u8 pad0E[6];
    u8 f14;
    u8 f15;
    u8 pad16[6];
    u8 f1C;
    u8 f1D;
    u8 pad1E[6];
    u8 f24;
    u8 f25;
    u8 pad26[2];
} W0E6F64Rec28;

void func_800E6F64(void *arg0, s32 arg1) {
    register W0E6F64Rec28 *a0 asm("a0") = (W0E6F64Rec28 *) arg0;
    register s32 a1 asm("a1") = arg1;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    if (a1 < 0) {
        v1 = a0->f0C;
        v0 = a0->f14;
        if (v1 != v0) {
            a1 = *(volatile u8 *) &a0->f0C;
            v1 = *(volatile u8 *) &a0->f14;
            v0 = *(volatile u8 *) &a0->f24;
            a0->f14 = a1;
            a1 = a0->f1C;
            a0->f0C = v1;
            a0->f1C = v0;
            a0->f24 = a1;
        } else {
            a1 = a0->f0D;
            v1 = a0->f15;
            v0 = a0->f25;
            a0->f15 = a1;
            a1 = a0->f1D;
            a0->f0D = v1;
            a0->f1D = v0;
            a0->f25 = a1;
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E6FCC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E727C);

s32 func_800E7508(s32 arg0, s32 arg1, s32 arg2) {
    return ((arg1 - arg0) * arg2) / 4096 + arg0;
}

extern s32 D_80195C34;

void func_800E752C(void *arg0, void *arg1, void *arg2, s32 arg3) {
    s16 *out = (s16 *) arg0;
    s16 *a = (s16 *) arg1;
    s16 *b = (s16 *) arg2;

    out[4] = func_800E7508(a[0], b[0], arg3);
    out[5] = func_800E7508(a[1], b[1], arg3);
    out[8] = func_800E7508(a[0] + a[2], b[0] + b[2], arg3);
    out[9] = func_800E7508(a[1], b[1], arg3);
    out[12] = func_800E7508(a[0], b[0], arg3);
    out[13] = func_800E7508(a[1] + a[3], b[1] + b[3], arg3);
    out[16] = func_800E7508(a[0] + a[2], b[0] + b[2], arg3);
    out[17] = func_800E7508(a[1] + a[3], b[1] + b[3], arg3);
}

extern s32 func_800E3B8C(void);

void func_800E7654(void) {
    do {
        func_800FFF50();
    } while ((func_800E3B8C() != 3) && ((D_80195C34 & 0x160) == 0));
}

extern s32 func_8008C410();
extern volatile u16 D_801A256C[];
extern volatile u16 D_801A256E;
extern volatile u16 D_801A2570;

void func_800E76A8(void) {
    volatile u16 *v0;
    u16 t;

    v0 = (volatile u16 *) func_8008C410();
    if (v0 != (volatile u16 *) -1) {
        t = v0[0];
        D_801A256C[0] = t;
        t = v0[1];
        D_801A256E = t;
        t = v0[2];
        D_801A2570 = t;
    }
}

extern void func_8008C550();

void func_800E7700(s32 dummy0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8008C410();
    if (temp_v0 != -1) {
        func_8008C550(temp_v0, arg1);
    }
}

void func_800E7740(s32 dummy0, s32 arg1) {
    s32 s0;
    u16 *v1;

    s0 = arg1;
    v1 = (u16 *) func_8008C410();
    if (v1 != (u16 *) -1) {
        ((u16 *) s0)[0] = v1[0];
        ((u16 *) s0)[1] = v1[1];
        ((u16 *) s0)[2] = v1[2];
    }
}

void func_800E779C(s32 arg0, s32 arg1) {
    s16 *src;
    s32 *dst;
    s32 s0 = arg1;

    src = (s16 *) func_8008C410(arg0);
    dst = (s32 *) s0;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

extern void func_8008C5E8();

void func_800E77E8(void) {
    func_8008C5E8();
}

void func_800E7808(void) {
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E7810);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E78C0);

s32 func_800E7B4C(s32 arg0) {
    return arg0;
}

s32 func_800E7B54(s32 arg0) {
    return arg0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E7B5C);

void func_800E7C20(u8 *arg0) {
    s32 v1 = 0xFE;
    s32 v0 = 0xF;
    u8 *a0 = arg0;

    do {
        *a0 = v1;
        v0--;
        a0++;
    } while (v0 >= 0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E7C40);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E7DCC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E7DD4);

s32 func_800E8310(void) {
    s32 basev;
    s32 iv;
    u8 *pv;
    s32 tmp;
    s32 t;

    basev = (s32) func_80180AFC();
    SCHED_BARRIER();
    iv = 0;
    __asm__ volatile("" : "=r"(tmp) : "0"(iv));
    iv = tmp;
    pv = (u8 *) (basev + iv);
    for (;;) {
        t = *(u8 *) ((u8 *) pv + 0x58);
        iv++;
        if (t != 0) {
            return 1;
        }
        if (iv < 5) {
            pv = (u8 *) (basev + iv);
            continue;
        }
        return 0;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E8364);

extern void func_800FF450();
extern s32 D_8013A310;
extern s32 D_8013A31C;
extern s32 D_8013A364;
extern s32 D_8013A384;

void func_800E8568(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    register s32 s0v asm("s0") = arg1;
    register s32 s1v asm("s1") = arg2;
    register s32 s2v asm("s2") = arg3;

    KEEP_NOVOL(s0v);
    KEEP_NOVOL(s1v);
    KEEP_NOVOL(s2v);
    func_800FF450((void *) arg0, (void *) &D_8013A31C, 0x22);
    func_800FF450((void *) s0v, (void *) &D_8013A364, 0xE);
    func_800FF450((void *) s1v, (void *) &D_8013A384, 0x40);
    func_800FF450((void *) s2v, (void *) &D_8013A310, 0xA);
}

void func_800E85F0(s32 arg0, s32 arg1, s32 arg2) {
    func_800FF450(&D_8013A31C, arg0, 0x22);
    func_800FF450(&D_8013A364, arg1, 0xE);
    func_800FF450(&D_8013A384, arg2, 0x40);
}

void func_800E8660(s32 *arg0) {
    s32 *a0 = arg0;
    s32 a1 = 0;
    s32 a2 = (s32) arg0 + 0x80;
    s32 *v1 = &D_801CD8A4;
    register s32 v0 asm("v0");

loop:
    v0 = *a0;
    a0++;
    a1++;
    v0 = a2 + v0;
    *v1 = v0;
    v1++;
    if (a1 < 0x20) {
        goto loop;
    }
}

extern s32 D_80154DA8;
extern s32 D_801A2574;

void func_800E8698(void) {
    s32 r;
    r = D_80154DA8;

    if (r != 0) {
        return;
    }
    func_800FF450(&D_801A2574, &D_801CD8A4, 0x80);
    D_80154DA8 += 1;
}

extern u8 *func_80059AF0();
extern u8 D_800596E0[];

void func_800E86EC(void) {
    func_800FF450(&D_801CD8A4, &D_801A2574, 0x80);
    D_80154DA8 = 0;
}

extern void func_80059FE0(s32);

void func_800E8724(s32 arg0) {
    s32 a0v;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 a2v;
    u8 *p;
    u8 temp_v1;
    s32 cond;

    s1 = arg0;
    s0 = 1;
    s2 = 0xFF;
    do {
        p = func_80059AF0(s0);
        if (p[1] == s2 || p[0] != s1) {
            s0++;
        } else {
            break;
        }
    } while (s0 < 0x14);
    if (s0 != 0x14) {
        a0v = 0;
        a2v = 0xFF;
        do {
            temp_v1 = ((u8 *) p + a0v)[0xE];
            a0v++;
            if (temp_v1 != 0 && temp_v1 != a2v) {
                D_800596E0[temp_v1]++;
            }
            cond = a0v < 7;
        } while (cond);
        func_80059FE0(s0);
    }
}

extern u8 *func_80180C90_2(u8, s32 *) asm("func_80180C90");
extern void func_80059BB0(void *, s32);

void func_800E87F8(void) {
    s32 s0v = 0;
    u8 *a0v;
    s32 v0v;
    s32 v1v;
    s32 sp10;
    u8 flag;

loop:
    v0v = (u8 *) func_80180AFC(s0v);
    a0v = *(u8 *) (v0v + 0x161);
    v0v = func_80180C90_2(a0v, &sp10);
    KEEP(v0v);
    v1v = sp10;
    a0v = v0v;
    if (v1v < 0) {
        goto next;
    }
    v0v = 0xFF;
    if (s0v != v1v) {
        goto next;
    }
    v1v = *(u8 *) (a0v + 2);
    if (v1v == v0v) {
        goto check;
    }
    v0v = *(u8 *) a0v;
    if (v0v == 0) {
        goto next;
    }
    v0v = (u32) v0v < 4U;
    if (v0v == 0) {
        goto next;
    }
check:
    flag = *(u8 *) (a0v + 6);
    v0v = flag & 0x10;
    if (v0v == 0) {
        goto next;
    }
    func_80059BB0((void *) a0v, flag & 1);
next:
    s0v += 1;
    v0v = s0v < 0x15;
    if (v0v != 0) {
        goto loop;
    }
}

extern void func_800EF25C();

void func_800E889C(void) {
    func_800EF25C(0x54, 0x16D);
}

void func_800E88C0(void) {
    s32 s0v = 0;
    s32 s1v = 0x64;
    s32 v0v;
    u8 *v1v;

loop:
    v1v = (u8 *) func_80180AFC(s0v);
    v0v = v1v[5] & 0x30;
    s0v += 1;
    if (v0v != 0) {
        goto check;
    }
    v0v = v1v[0x24];
    v0v += 0xA;
    v1v[0x24] = v0v;
    v0v = v1v[0x24];
    v0v = (u32) v0v < 0x64U;
    if (v0v == 0) {
        v1v[0x24] = s1v;
    }
check:
    v0v = s0v < 0x15;
    if (v0v != 0) {
        goto loop;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E8944);

extern s16 D_80154DFC;

void func_800E8A34(void) {
    D_80154DFC = 1;
}

void func_800E8A48(void) {
    D_80154DFC = 0;
}

extern void func_800E2C48();

void func_800E8A58(s16 *arg0, s16 arg1, s16 arg2, s16 *arg3, s32 arg4) {
    s32 s0;
    s16 *s1;

    s1 = arg3;
    arg0[2] = arg1;
    arg0[3] = arg2;
    s0 = arg4;
    func_800E2C48(arg0, s1, -1);
    s0 <<= 4;
    s0 += 0x7C3C;
    arg3[7] = s0;
}

void func_800E8AA8(void) {
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E8AB0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E8D6C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E8FB8);

void func_800E90E4(void) {
}

void func_800E90EC(void) {
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800E90F4);

extern void func_800E7DCC();
extern void func_800E90F4(u8 *, s32, s16 *, s16 *);
extern u8 D_80155AD4[];
extern s16 D_80155B44;
extern s16 D_8013A320;

void func_800E9FA8(void) {
    s16 *p1;
    s16 *p2;

    func_800E7DCC();
    p1 = &D_80155B44;
    p2 = &D_8013A320;
    *p1 = 2;
    if (*p2 < 0) {
        *p1 = 0xC00;
    }
    func_800E90F4(D_80155AD4, 0, p1 - 0x28, p2 - 2);
}

extern u8 D_80155AEC[];
extern s16 D_80155BBC;
extern s16 D_8013A344;

void func_800EA008(void) {
    s16 *p1;
    s16 *p2;

    func_800E7DCC();
    p1 = &D_80155BBC;
    p2 = &D_8013A344;
    *p1 = 2;
    if (*p2 < 0) {
        *p1 = 0xC00;
    }
    func_800E90F4(D_80155AEC, 3, p1 - 0x28, p2 - 2);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EA068);

extern void func_800FFEA0();
extern s32 D_80198D1C;
extern u16 D_8013A37E;
extern u16 D_8013A392;
extern u16 D_8013A3B6;
extern s16 D_8013A3D2;
extern s16 D_8013A3F6;
extern u8 D_80155AE4[];
extern s16 D_80155C44;
extern s16 D_8013A340;

void func_800EA1A4(void) {
    s32 s0v;
    s32 s1v;
    s32 v0v;
    s32 v1v;

    v1v = D_80198D1C;
    v0v = 0x13;
    if (v1v != v0v) {
        func_800FFEA0(0xC);
    }
    func_800FFF50();
    func_800FFF50();
    s0v = (s32) &D_8013A36E;
    v0v = D_8013A37E;
    s1v = *(s16 *) s0v;
    *(s16 *) s0v = (s16) v0v;
    func_800E7DCC();
    v0v = D_8013A392;
    v1v = D_8013A3B6;
    *(s16 *) s0v = s1v;
    D_8013A3D2 = (s16) v0v;
    D_8013A3F6 = (s16) v1v;
    func_800E7DCC();
    func_800E90F4(D_80155AE4, 2, &D_80155C44, &D_8013A340);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EA25C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EA990);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EAA50);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EABCC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EAF3C);

void func_800EBA28(void) {
}

extern void func_800EBB08();
extern s32 func_80100164(s32);
extern s32 D_801960D0;
extern s32 D_801964D0;
extern s32 D_8015330C;
extern s32 D_80153310;
extern u16 D_80153336;

s32 func_800EBA30(void) {
    extern s32 func_801000F8(void);
    extern s32 func_8010012C(void);
    register s32 v0v asm("v0");

    if ((func_80100164(1) != 0 && (D_801960D0 & 0x70) == 0x30) ||
        (func_80100164(2) != 0 && (D_801964D0 & 0x70) == 0x30)) {
        D_80153336 = 5;
        return 0;
    }
    v0v = 0;
    if (func_8010012C() != 0) {
        v0v = 0;
        goto end;
    }
    v0v = 0;
    if (func_801000F8() != 0) {
        v0v = 0;
        goto end;
    }
    v0v = D_8015330C;
    if (v0v != 0) {
        v0v = 0;
        goto end;
    }
    v0v = 0;
    v0v = D_80153310;
    if (v0v != 0) {
        v0v = 0;
        goto end;
    }
    v0v = 0;
    v0v = D_80153336;
    if (v0v != 0) {
        v0v = 0;
        goto end;
    }
    v0v = 1;
end:
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EBB08);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EBB10);

extern s32 func_800EBA30();

void func_800EBDCC(void *arg0, s32 *arg1) {
    s32 s0v = (s32) arg1;
    s32 s1v = (s32) arg0;
    s32 v0v;
    s32 v1v;

    if (func_800EBA30() != 0) {
        v0v = D_80195C34;
        if ((v0v & 0x1000) != 0) {
            v0v = *arg1;
            if (v0v == 0) {
                v0v = *(s16 *) ((u8 *) arg0 + 0x1E);
            } else {
                v0v -= 1;
            }
            *arg1 = v0v;
            func_800E1ED8();
        }
        v0v = D_80195C34;
        if ((v0v & 0x4000) != 0) {
            v0v = *(s16 *) ((u8 *) arg0 + 0x1E);
            v1v = *arg1;
            if (v1v == v0v) {
                *arg1 = 0;
            } else {
                v0v = v1v + 1;
                *arg1 = v0v;
            }
            func_800E1ED8();
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EBE7C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EBE84);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EBF8C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EBF94);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EC108);

extern s32 func_8010012C();

void func_800EC3EC(u8 *arg0) {
    register u8 *p asm("s0");
    register s32 v asm("v0");
    register s32 d asm("v1");

    p = arg0;
    v = func_8010012C();
    if (v != 0) {
        v = 0x7D3C;
    } else {
        d = D_8015330C;
        v = 1;
        if (d != v) {
            v = 0x7C3C;
        } else {
            v = 0x7D3C;
        }
    }
    *(u16 *) (p + 0xE) = v;
}

void func_800EC438(u8 *arg0) {
    register u8 *p asm("s0");
    register s32 v asm("v0");
    register s32 d asm("v1");

    p = arg0;
    v = func_8010012C();
    if (v != 0) {
        v = 0x7C7C;
    } else {
        d = D_8015330C;
        v = 1;
        if (d != v) {
            v = 0x7CBC;
        } else {
            v = 0x7C7C;
        }
    }
    *(u16 *) (p + 0xE) = v;
}

void func_800EC484(void *arg0) {
    register s32 a0 asm("a0") = (s32) arg0;
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s0 = a0;
    v0 = func_8010012C();
    if (v0 != 0) {
        v0 = 0x7D3C;
        goto true_case;
    }
    v1 = D_8015330C;
    v0 = 1;
    if (v1 != v0) {
        v0 = 0x7D3C;
        goto false_case;
    }
    v0 = 0x7D3C;
true_case:
    *(s16 *) (s0 + 0x26) = (s16) v0;
    v0 = 0x7DFC;
    *(s16 *) (s0 + 0x3A) = (s16) v0;
    v0 = 0x7E3C;
    *(s16 *) (s0 + 0x4E) = (s16) v0;
    v0 = 0x7C7C;
    goto store_last;
false_case:
    v0 = 0x7C3C;
    *(s16 *) (s0 + 0x26) = (s16) v0;
    v0 = 0x7D7C;
    *(s16 *) (s0 + 0x3A) = (s16) v0;
    v0 = 0x7DBC;
    *(s16 *) (s0 + 0x4E) = (s16) v0;
    v0 = 0x7CBC;
store_last:
    *(s16 *) (s0 + 0x62) = (s16) v0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EC504);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EC5B8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EC5C8);

void func_800EC764(void *arg0, void *arg1) {
    u8 *a0 = (u8 *) arg0;
    u8 *a1 = (u8 *) arg1;
    u32 v0;

    v0 = *(u16 *) (a0 + 8);
    *(u16 *) (a1 + 8) = v0;
    v0 = *(u16 *) (a0 + 0x0A);
    *(u16 *) (a1 + 0x0A) = v0;
    v0 = *(u16 *) (a0 + 0);
    v0 &= 0x3F;
    v0 <<= 2;
    *(u8 *) (a1 + 0x0C) = v0;
    v0 = *(u8 *) (a0 + 2);
    *(u8 *) (a1 + 0x0D) = v0;
    v0 = *(u16 *) (a0 + 0x14);
    *(u16 *) (a1 + 0x10) = v0;
    v0 = *(u16 *) (a0 + 0x16);
    *(u16 *) (a1 + 0x12) = v0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EC7B4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EC954);

void func_800ECB24(u8 *arg0) {
    *(u16 *) (arg0 + 0x1C) = 0;
    *(u16 *) (arg0 + 0x26) = 0;
    func_800FF450(arg0 + 0x20, D_801531B0, 8);
}

void func_800ECB58(s32 arg0) {
    func_800FDAA4(arg0 + 0x54);
    func_800FDAA4(arg0 + 0x2C);
    func_800FDAA4(arg0 + 0x40);
    func_800FDAA4(arg0 + 0xC);
    func_800FDAA4(arg0 + 0x18);
    func_800FDAA4(arg0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800ECBAC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800ECF20);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800ED104);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800ED114);

extern void func_800ED104();
extern void func_800EDAA8();
extern void func_800F6490();

void func_800ED5C4(void) {
    func_800ED104();
    func_800F6490(0xFA);
    func_800EDAA8();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800ED5F4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800ED7DC);

extern s32 D_8019A20C;

s32 func_800EDA98(void) {
    return D_8019A20C;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EDAA8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EDAB0);

extern s16 D_80156384;

void func_800EEAF4(s32 arg0) {
    D_80156384 = arg0;
}

struct Func800EEB04_Obj {
    u8 pad[4];
    s16 f04;
    s16 f06;
    s16 f08;
    u8 padA[2];
    s16 f0C;
    s16 f0E;
    u8 pad10[2];
    s16 f12;
    s16 f14;
    s16 f16;
    u8 pad18[4];
    s16 f1C;
};

extern void func_800E4668(s16 *, s16 *, s32);
extern s32 D_801532A0;

void func_800EEB04(struct Func800EEB04_Obj *arg0, s16 *arg1, s16 *arg2, s32 *arg3, s32 arg4) {
    register s32 temp_v0 asm("v0");
    s16 temp_a0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    func_800E6EDC(arg0->f1C);
    *arg3 = 0;
    func_800E4668(arg1, arg2, temp_v0);
    if (arg4 != 0) {
        temp_a0 = *arg1;
        if ((temp_a0 < 8) && (*arg2 == 1)) {
            *arg3 = (8 - temp_a0) * 5;
            *arg1 = 8;
        }
    }
    temp_v0 = (u16) *arg1 + 0x18;
    *arg1 = temp_v0 + (temp_v0 & 3);
    *arg2 = (*arg2 * 0x10) + 0x10;
    arg0->f08 = (s16) (0x102 - ((s32) ((u16) *arg1 << 0x10) >> 0x11));
    temp_v0_2 = (u16) *arg1;
    arg0->f14 = temp_v0_2;
    arg0->f04 = temp_v0_2;
    arg0->f0C = temp_v0_2;
    temp_v0_3 = (u16) *arg2;
    arg0->f16 = temp_v0_3;
    arg0->f06 = temp_v0_3;
    arg0->f0E = temp_v0_3;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EEC24);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EEC2C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EEE98);

extern void func_800EBE7C();
extern s32 func_800EBF8C();
extern s32 func_80100090();
extern s32 func_801000C4();

void func_800EF114(void) {
    s32 temp_s0;

    temp_s0 = func_80100090();
    D_801532A0 = 1;
loop_1:
    func_800FFF50();
    if (func_800EBF8C(&D_80195C34) == 0) {
        func_800EBB08(temp_s0, 0);
        func_800EBE7C(temp_s0);
        goto loop_1;
    }
    func_800FFF50();
    D_801532A0 = 0;
    if (func_801000C4() == 0) {
        func_800FFE28();
    }
}

extern void func_800FD4A8();

s32 func_800EF1A8(s32 arg0) {
    s32 temp_s2;
    register s32 first asm("s0");
    register s32 ret asm("v0");
    register s32 a0v asm("a0");
    register s32 finalv asm("v0");

    temp_s2 = *D_80153280;
    if (arg0 == 0x22) {
        ret = func_800EF1A8(0x24);
        first = ret & 1;
        ret = func_800EF1A8(0x23);
        ret &= 7;
        first <<= 0xF;
        KEEP(first);
        ret <<= 0xC;
        a0v = 0x22;
        KEEP(a0v);
        func_800EF25C(a0v, first | ret);
    }
    func_800FD4A8(0xBE, 0, 0, 0);
    func_800FD4A8(0xB1, 0, arg0, 0);
    finalv = *D_80153280;
    *D_80153280 = temp_s2;
    return finalv;
}

void func_800EF25C(s32 arg0, s32 arg1) {
    s32 temp_s2;
    s32 var_s1;

    temp_s2 = *D_80153280;
    var_s1 = arg1;
    if (arg0 == 0x2C) {
        if (var_s1 > 0x05F5E0FF) {
            var_s1 = 0x05F5E0FF;
        }
    }
    func_800FD4A8(0xBE, arg0, 0, 0);
    func_800FD4A8(0xB0, arg0, var_s1, 0);
    *D_80153280 = temp_s2;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EF2FC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EF4B0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EF4B8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800EF680);

extern s32 func_800444DC(s32, s32);
extern s32 D_80010010;
extern s32 D_800459D0;
extern s32 D_800E0054;

void func_800EF788(s32 arg0) {
loop_1:
    if (func_800444DC(D_80010010, arg0) != D_80010010) {
        func_800FFF50();
        if (D_800459D0 != 0) {
            func_800235AC(&D_800E0054);
        }
        goto loop_1;
    }
}

extern void func_80044600();

void func_800EF804(void) {
    s32 a0v;

    a0v = D_80010010;
    func_80044600(a0v);
}

extern s32 D_801532E8;
extern s32 D_801532EC;

void func_800EF82C(s32 arg0) {
    s32 s0 = arg0;
    s32 v0;
    v0 = D_801532E8;

    goto check;
loop:
    func_800FFF50();
    v0 = D_801532E8;
check:
    if (v0 != 0) {
        goto loop;
    }
    v0 = D_801532EC;
    if (v0 != 0) {
        goto loop;
    }
    D_801532E8 = s0;
    if (s0 != 0) {
        do {
            func_800FFF50();
            v0 = D_801532E8;
        } while (v0 != 0);
    }
    if (D_801CD50C == 1) {
        func_800FFE28();
    }
}

void func_800EF8D4(s32 arg0) {
    s32 s0 = arg0;
    s32 v0;
    v0 = D_801532E8;

    goto check;
loop:
    func_800FFF50();
    v0 = D_801532E8;
check:
    if (v0 != 0) {
        goto loop;
    }
    v0 = D_801532EC;
    if (v0 != 0) {
        goto loop;
    }
    D_801532EC = s0;
    if (s0 != 0) {
        do {
            func_800FFF50();
            v0 = D_801532EC;
        } while (v0 != 0);
    }
    if (D_801CD50C == 1) {
        func_800FFE28();
    }
}

void func_800EF97C(void) {
}

extern void func_801CAFD4();
extern s32 D_80153328;

void func_800EF984(void) {
    D_80153328 = 0;
    func_801CAFD4();
}

extern void func_800FD1D8();

void func_800EF9AC(void) {
    func_800FD1D8(0x36);
}

void func_800EF9CC(void) {
}

void func_800EF9D4(void) {
}

extern void func_800E1E8C();
extern void func_800EF82C();
extern void func_80102E78();

void func_800EF9DC(void) {
    func_800E1E8C();
    func_800EF82C(1);
    func_80102E78(0);
}

void func_800EFA0C(void) {
    func_800E1E8C();
    func_800EF82C(1);
    func_80102E78(1);
}

void func_800EFA3C(void) {
    func_800E1E8C();
    func_800EF82C(1);
    func_80102E78(2);
}

extern void func_800ECF20();
extern u16 D_8015332E;

void func_800EFA6C(void) {
    func_800FD1D8(0x42);
    while ((func_8008E17C() != 0) || (D_8015332E != 0)) {
        func_800FFF50();
    }
    func_800F6490(0xFE);
    D_80153328 = 0;
    func_800ECF20();
}

extern void func_800EF804();
extern void func_800E1EA0();
extern s32 D_801532F0;
extern s16 D_8015332C;

void func_800EFAD8(void) {
    extern void func_800FFD28(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    s32 var_s0;
    s32 var_s1;
    s32 var_v0;
    volatile s32 pad[2];

    D_8015332E = 4;
    do {
        func_800FFF50();
    } while (func_80100164(6) != 0);
    D_801532F0 = 2;
    D_80153310 = 0;
    do {
        func_800FFD28(1);
    } while (D_801532F0 != 0);
    var_s0 = 2;
    func_800EF804();
    do {
        func_800FFF08(var_s0, 0, 0, 1);
        var_s0 += 1;
    } while (var_s0 < 0xF);
    var_s0 = 0;
    var_s1 = 0xFF;
    do {
        D_80153320 = var_s1 - var_s0;
        var_s0 += 8;
        func_800FFF50();
    } while (var_s0 < 0x100);
    var_v0 = var_s1 - var_s0;
    func_800E1EA0();
    var_v0 = var_s1 - var_s0;
    D_8015332C = 0;
    D_80153320 = 0;
    D_8015332E = 0;
    func_800F0F64(2, D_8013A36E, 0xFF);
    func_800FFE28();
}

extern void func_800EF788();
extern void func_800F1340();
extern void func_800FFD28();
extern void func_800FFF08();

void func_800EFBE0(s32 arg0) {
    s32 var_a0;
    s32 var_s0;

    var_a0 = arg0;
    var_s0 = 0;
    do {
        D_80153320 = var_s0;
        var_s0 += 0x10;
        func_800FFF50(var_a0);
        var_a0 = 8;
    } while (var_s0 < 0x100);
    D_80153320 = 0xFF;
    D_8015332C = 1;
    func_800FFF08(8, 0, 0, 1);
    func_800FFF08(0xA, 0, 0, 1);
    func_800FFF08(0xB, 0, 0, 1);
    func_800FFF08(0xC, 0, 0, 1);
    func_800FFF08(0xD, 0, 0, 1);
    func_800F1340();
    func_800EF82C(2);
    func_800EF788(0x20000);
    func_800EF82C(0xF);
    func_800FFD28(2);
    D_80153310 = 1;
    func_800FFD70(0xD, &func_800EFAD8);
    func_800FFE28();
}

void func_800EFCE4(void) {
    func_800E1E8C();
    func_800FFD70(D_801CD170 - 1, &func_800EFBE0);
    func_800FFEA0(D_801CD170 - 1);
    func_800FFE28();
}

extern void func_800E1EB0();
extern s32 func_800FD14C(s32);
extern void func_8010487C();

void func_800EFD34(void) {
    if ((func_800FD14C(0x15) != 0) && (func_800FD14C(0x31) == 0)) {
        func_800E1EB0();
    }
    func_800EF788(0x20000);
    func_800EF82C(3);
    func_8010487C();
}

void func_800EFD8C(void) {
    if (func_80100164(3) != 0) {
        func_800FFE28();
    }
    if (func_80100164(1) != 0) {
        func_800FFE28();
    }
    func_800E1E8C();
    func_800E1EB0();
    func_800EF788(0x20000);
    func_800EF82C(7);
    func_800FFD28(2);
    D_801532F0 = 3;
    do {
        D_80195C34 = 0;
        func_800FFF50();
    } while (D_801532F0 != 0);
    D_80195C34 = 0;
    func_800EF804();
    func_800FFD28(2);
    func_800E1EA0();
    func_800FFE28();
}

extern u8 D_80195CD0[];
extern s32 D_80153DF4;
extern s32 D_80153264;
extern s16 D_80153D18;
extern s32 D_8019A228;

void func_800EFE54(void) {
    struct Obj {
        u8 pad[0x38];
        u16 unk38;
    };
    extern void func_800EF82C(s32);
    extern void func_800EF788(s32);
    extern void func_800FFE10(s32);
    extern u16 D_801531C8[];
    extern void func_800FFDF4(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_800FFD28(s32);
    s32 temp_s1;
    s32 var_s0;
    s32 var_a1;
    s32 var_v1;
    u16 *var_a0_2;
    u16 temp_v0;

    func_800E1E8C();
    temp_s1 = D_80153264;
    func_800F0F64(0, 0xFF, 0xFF);
    D_8015332C = 1;
    func_800F1340();
    func_800EF82C(9);
    func_800EF788(0x20000);
    func_800EF82C(0xA);
    func_800FFE10(8);
    func_800FFE10(7);
    D_801532F0 = 4;
    do {
        D_80195C34 = 0;
        func_800FFF50();
    } while (D_801532F0 != 0);
    D_801CD7E0 = (s32 *) &D_80153DF4;
    D_80153D18 = -3;
    D_801532A0 = 1;
    D_80195C34 |= 0x20;
    var_s0 = 9;
    if (D_8019A228 == 0) {
        func_800FFDF4(8);
        func_800FFDF4(7);
    }
    do {
        func_800FFF08(var_s0, 0, 0, 1);
        var_s0 += 1;
    } while (var_s0 < 0xF);
    func_800FFD28(4);
    var_v1 = 0;
    if (D_8019A228 != 0) {
        var_a1 = 8;
        var_a0_2 = D_801531C8;
        do {
            temp_v0 = (*(struct Obj **) (D_80195CD0 + ((var_a1 - var_v1) << 10)))->unk38;
            var_v1 += 1;
            *var_a0_2 = temp_v0;
            var_a0_2 += 1;
        } while (var_v1 < 2);
    }
    func_800EF804();
    D_8015332C = 0;
    func_800F0F64(temp_s1, 0xFF, 0xFF);
    D_801532A0 = 0;
    D_80195C34 = 0;
    func_800E1EA0();
    func_800FFE28();
}

extern s32 D_80153268;
extern void func_800F4104();
extern void func_8008DEA0();
extern void func_8008DEC8();

void func_800F001C(void) {
    extern void func_800EF82C(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_800FFEA0(s32);
    extern void func_801C3D84(s16);
    s16 *s0;

    s0 = &D_8013A36E;
    if (((u8 *) func_80180AFC(*s0))[0x182] != 0) {
        func_800F0F64(0, 0xFF, 0xFF);
        func_800E1E8C();
        D_8015332C = 1;
        func_800EF82C(0xB);
        func_800FFF08(8, 0, 0, 1);
        func_800FFEA0(8);
        func_800F1340();
        func_800F4104();
        func_8008DEA0();
        func_801C3D84(*s0);
        D_8015332C = 0;
        D_801532A0 = 0;
        D_80195C34 = 0;
        func_800F0A08(D_80153268);
        func_800F0F64(3, *s0, *s0);
        func_800E1EA0();
        func_8008DEC8();
        func_800FFE28();
    }
}

extern void func_801C438C();

void func_800F0118(void) {
    func_800F0F64(0, 0xFF, 0xFF);
    func_800E1E8C();
    D_8015332C = 1;
    func_800EF82C(0xB);
    func_800FFF08(8, 0, 0, 1);
    func_800FFEA0(8);
    func_800F1340();
    func_800FFF50();
    func_800FFF50();
    func_801C438C();
    D_8015332C = 0;
    D_801532A0 = 0;
    D_80195C34 = 0;
    func_800E1EA0();
    func_800FFE28();
}

extern void func_801C05D4();

void func_800F01C0(void) {
    func_800FD1D8(0x3D);
    func_800EF82C(0xC);
    func_801C05D4();
}

extern s32 func_80100384();
extern s32 *D_801CD78C;

void func_800F01F0(void) {
}

extern void func_800E3298();
extern s32 D_801531A0;
extern s32 D_801531A8;
extern s32 func_80044954;

void func_800F01F8(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_800E30FC(0x2000);
    D_801CD78C = &func_80044954;
    func_80100384((arg0 * 4) + 0x164B, 0x2000, temp_s0);
    func_800248FC(&D_801531A0, temp_s0);
    func_800248FC(&D_801531A8, temp_s0 + 0x1800);
    func_800E3298(temp_s0);
}

extern s32 func_800FD1D8_s32() asm("func_800FD1D8");
extern s32 D_801CD748;
extern s32 D_801CD924;
extern s32 func_80044694();
extern s32 func_800446C8();

void func_800F0274(void) {
    s32 s0;
    s32 s0v;
    s32 s1;
    s32 s2;
    s32 s3;
    extern s32 func_80044414(s32);

    s3 = func_80100090();
    s0v = func_801000C4();
    func_800FD1D8_s32(0x34);
    s1 = func_80044414(0x7800);
    s2 = (s32) &func_80044694;
    s0 = s0v * 15;
    do {
        func_800FFF50();
        D_801CD78C = (s32 *) s2;
    } while (func_80100384(s0 + 0x1D4C, 0x7800, s1) != 0);
    s0 = (s32) &func_800446C8;
    do {
        func_800FFF50();
        D_801CD78C = (s32 *) s0;
    } while (func_80100384() != 0);
    D_801CD748 = s3;
    D_801CD924 = s1;
    func_800FFF50();
    func_80044600(s1);
    func_800FFE28();
}

void func_800F0358(s32 arg0) {
    struct {
        u16 sp10;
        s16 pad;
        volatile s16 sp14;
        volatile s16 sp16;
    } locals;
    u16 temp;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    extern s32 func_800E30FC(s32);

    s2 = func_800E30FC(0x2000);
    s1 = (s32) &func_80044694;
    s0 = arg0 * 4;
    do {
        func_800FFF50();
        D_801CD78C = (s32 *) s1;
    } while (func_80100384(s0 + 0x164B, 0x2000, s2) != 0);
    s0 = (s32) &func_800446C8;
    do {
        func_800FFF50();
        D_801CD78C = (s32 *) s0;
    } while (func_80100384() != 0);
    s3 = s2 + 0x1800;
    func_800FF450(&locals.sp10, &D_801531A0, 8);
    s1 = 0;
    s0 = s2;
    locals.sp14 = 8;
    locals.sp16 = 0x30;
    do {
        func_800248FC(&locals.sp10, s0);
        temp = locals.sp10;
        USE(temp);
        s1 += 1;
        locals.sp10 = temp + 8;
        s0 += 0x300;
    } while (s1 < 8);
    func_800248FC(&D_801531A8, s3);
    func_800E3298(s2);
    func_800FFF50();
}

extern u8 D_8004A6BC[];
extern s32 *D_801CD75C;

void func_800F0470(s32 arg0) {
    s32 s1;
    s32 s0;
    s32 v0;
    s32 *v1;

    s1 = (s32) func_80044694;
    s0 = arg0 * 4;
    do {
        func_800FFF50();
        D_801CD78C = (s32 *) s1;
    } while (func_80100384(s0 + 0xE7B, 0x2000, D_8004A6BC) != 0);
    s0 = (s32) func_800446C8;
    do {
        func_800FFF50();
        D_801CD78C = (s32 *) s0;
    } while (func_80100384() != 0);
    v1 = D_801CD75C;
    v0 = *v1;
    if (v0 != 0xF2F2F2F2) {
        D_801CD8A4 = v0 + (s32) v1;
        *v1 = 0xF2F2F2F2;
    }
}

void func_800F0520(s32 arg0) {
    s32 s1v = arg0;
    s32 *s0v = &D_8019A1C0;

    func_800FF450(s0v, s1v, 0x20);
    func_800FF450(s0v + 8, s1v + 0x20, 0x20);
}

extern void func_800F0520();
extern void func_800FD9F4();
extern s32 D_8013B8B8;

void func_800F0574(void) {
    func_800F0520(&D_8013B8B8);
    func_800FD9F4();
}

void func_800F05A4(void) {
}

extern s32 D_80044694;
extern s32 D_80153300;
extern s32 D_80156448;
extern s32 D_80156488;
extern s32 D_801564C8;
extern s32 *D_801CD78C_p asm("D_801CD78C");

void func_800F05AC(void) {
    s32 v0v;
    s32 v1v;
    s32 a0v;
    s32 a1v;
    s32 a2v;
    v1v = D_801532EC;

    if (v1v != 0) {
        v0v = D_801564C8;
        if (v0v == 0) {
            v0v = v1v << 2;
            a0v = *(s32 *) ((u8 *) &D_80156448 + v0v);
            a1v = *(s32 *) ((u8 *) &D_80156488 + v0v);
            a2v = D_80153300;
            v0v = (s32) &D_80044694;
            D_801CD78C_p = (s32 *) v0v;
            v0v = func_80100384(a0v, a1v, a2v);
            if (v0v == 0) {
                D_801564C8 = 1;
            }
            goto end;
        }
        goto else_path;
    }
else_path:
    v0v = D_801532EC;
    if (v0v != 0) {
        v0v = D_801564C8;
        if (v0v != 0) {
            v0v = (s32) &func_800446C8;
            D_801CD78C_p = (s32 *) v0v;
            v0v = func_80100384();
            if (v0v == 0) {
                D_801564C8 = 0;
                D_801532EC = 0;
            }
        }
    }
end:
    return;
}

extern s32 D_80156388;
extern s32 D_801563C8;
extern s32 D_80156408;
extern s32 D_801564CC;

void func_800F068C(void) {
    s32 v0v;
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    v1v = D_801532E8;

    if (v1v != 0) {
        v0v = D_801564CC;
        if (v0v == 0) {
            v0v = (s32) &D_80044694;
            D_801CD78C_p = (s32 *) v0v;
            v0v = v1v << 2;
            v1v = *(s32 *) ((u8 *) &D_80156408 + v0v);
            MEMORY_BARRIER();
            a2v = D_80010008;
            a0v = *(s32 *) ((u8 *) &D_80156388 + v0v);
            a1v = *(s32 *) ((u8 *) &D_801563C8 + v0v);
            a2v = v1v + a2v;
            v0v = func_80100384(a0v, a1v, a2v);
            if (v0v == 0) {
                D_801564CC = 1;
            }
            goto end;
        }
        goto else_path;
    }
else_path:
    v0v = D_801532E8;
    if (v0v != 0) {
        v0v = D_801564CC;
        if (v0v != 0) {
            v0v = (s32) &func_800446C8;
            D_801CD78C_p = (s32 *) v0v;
            v0v = func_80100384();
            if (v0v == 0) {
                D_801564CC = 0;
                D_801532E8 = 0;
            }
        }
    }
end:
    return;
}

extern void func_800F312C();

void func_800F077C(void) {
    func_800F312C();
}

void func_800F079C(void) {
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F07A4);

extern s32 D_80156690;

void func_800F0A08(void) {
    D_80156690 = 0;
}

extern u16 D_80153258_alias asm("D_80153258");
extern u16 D_80153334;
extern s32 func_800EFD34_alias() asm("func_800EFD34");
extern void func_800FFD70_s(s32, s32 *) asm("func_800FFD70");
extern void func_800FFF08_s(s32, s32, s32, s32) asm("func_800FFF08");

void func_800F0A18(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");

    v0v = func_80100164(8);
    if (v0v != 0) {
        goto state;
    }
    v0v = func_80100164(3);
    if (v0v == 0) {
        goto check;
    }
state:
    v1v = D_80153268;
    v0v = 0xA;
    if (v1v == v0v) {
        goto check;
    }
    v0v = 1;
    D_80156690 = v0v;
check:
    v0v = D_80153334;
    if (v0v != 0) {
        goto end;
    }
    v0v = D_80153258_alias;
    if (v0v != 0) {
        goto end;
    }
    v0v = func_8008E17C();
    if (v0v != 0) {
        goto end;
    }
    v0v = D_801532F0;
    if (v0v != 0) {
        goto end;
    }
    v0v = func_80100164(3);
    if (v0v != 0) {
        goto end;
    }
    v0v = 1;
    D_80153310 = v0v;
    a0v = 3;
    a1v = (s32) &func_800EFD34_alias;
    func_800FFD70_s(a0v, (s32 *) a1v);
    a0v = 3;
    a1v = 0;
    a2v = 0;
    a3v = 0;
    func_800FFF08_s(a0v, a1v, a2v, a3v);
end:
    return;
}

void func_800F0AF4(void) {
    D_801532E8 = 8;
}

extern void func_800F068C();
extern void func_801D7000();

s32 func_800F0B08(void) {
    register s32 v0 asm("v0");
    v0 = D_801532E8;

    if (v0 == 0) {
        KEEP(v0);
        return 0;
    }
    func_800F068C();
    v0 = D_801532E8;
    if (v0 != 0) {
        v0 = 1;
    } else {
        func_801D7000();
        v0 = 0;
    }
    return v0;
}

s32 func_800F0B5C(void) {
    return 0;
}

extern void func_8008E304();

void func_800F0B64(void) {
    func_800FFF50();
    func_8008E304();
    func_800FFF50();
    func_800FFE28();
}

extern s32 func_8001DBA8();
extern s32 func_80043708();

void func_800F0B9C(void) {
    s32 *p = &func_80043708;

    do {
        func_8001DBA8(0);
        D_801CD78C = p;
    } while (func_80100384() != 0);
}

extern void func_80043F00();
extern void func_800F0B9C();
extern s32 D_800435C4;
extern s32 func_80043A90;

void func_800F0BE4(s32 arg0, s32 arg1) {
    func_80043F00();
    if (arg0 != 0) {
        D_801CD78C = &D_800435C4;
        func_80100384(arg0, 1);
        func_800F0B9C();
    }
    if (arg1 != 0) {
        D_801CD78C = &D_800435C4;
        func_80100384(arg1, 2);
        func_800F0B9C();
    }
    if (arg0 != 0) {
        D_801CD78C = &func_80043A90;
        func_80100384(1, 0x7F, 0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F0C8C);

extern s32 D_80197D1C;

void func_800F0E48(void) {
    if (func_80100164(8) == 0 && func_80100164(7) == 0 && *(u16 *) &D_8015332C == 0) {
        D_80153268 = 0xA;
        D_801CD7E0 = &D_80153DF4;
        func_800FFD70(8, &func_800EFA6C);
        func_800FFF08(8, (s32) D_801CD7E0 + 0x258, 0, 0);
        D_80197D1C = 0x42;
    }
}

s32 func_800F0EE4(void) {
    s32 s0;
    s32 v0;

    if (func_80100164(3) == 0) {
        s0 = 4;
loop:
        v0 = func_80100164(s0);
        if (v0 != 0) {
            v0 = s0 ^ 9;
            goto end2;
        }
        v0 = s0 ^ 9;
        s0++;
        if (s0 < 9) {
            goto loop;
        }
        v0 = s0 ^ 9;
end2:
        v0 = (v0 != 0) * 4;
    } else {
        v0 = 2;
    }
    return v0;
}

extern s16 D_80153330;

void func_800F0F40(void) {
    D_80153330 = 1;
}

void func_800F0F54(void) {
}

void func_800F0F5C(void) {
}

extern void func_800E7B5C();
extern void func_800F1034();
extern u16 D_8015332C_u asm("D_8015332C");
extern s32 D_80153344;
extern u8 D_801566B0[];
extern s16 D_8013A326;
extern s16 D_8013A34A;

void func_800F0F64(s32 arg0, s32 arg1, s32 arg2) {
    s32 s2v;
    s32 s0v;
    s32 s1v;
    s32 t;

    s2v = arg0;
    s0v = arg1;
    s1v = arg2;
    if (D_8015332C_u == 1) {
        return;
    }
    func_800E7B5C();
    D_80153344 = D_801566B0[s2v];
    if (s0v != 0xFF) {
        D_8013A36E = s0v;
        D_8013A326 = s0v;
    }
    if (s1v != 0xFF) {
        D_8013A37E = s1v;
        D_8013A34A = s1v;
    }
    t = 2;
    if (func_80100164(t) == 0) {
        func_800FFD70(t, &func_800F1034);
    }
    func_800FFF08(t, s2v, 0, 0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F1034);

extern s32 D_8015326C;

void func_800F1330(s32 arg0) {
    D_8015326C = arg0;
}

void func_800F1340(void) {
    func_800FFEA0(0xD);
    func_800FFEA0(0xC);
    func_800FFEA0(0xB);
    func_800FFEA0(0xA);
}

void func_800F1378(void) {
}

void func_800F1380(void) {
}

void func_800F1388(void) {
}

void func_800F1390(void) {
}

void func_800F1398(void) {
}

void func_800F13A0(s32 arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0;
    s32 *temp_v1;
    s32 temp_a1;
    s32 temp_a3;
    s32 var_v0;

    var_v0 = arg1;
    if (arg1 < 0) {
        var_v0 = arg1 + 0x1F;
    }
    temp_a3 = var_v0 >> 5;
    temp_a1 = 1 << (arg1 & 0x1F);
    if (arg2 != 0) {
        temp_v1 = (temp_a3 * 4) + arg0;
        *temp_v1 |= temp_a1;
        return;
    }
    temp_v0 = (temp_a3 * 4) + arg0;
    *temp_v0 &= ~temp_a1;
}

void func_800F13FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 base;
    s32 bit;
    s32 off;
    s32 i;

    base = arg1 * 9;
    bit = 1;
    i = 0;
    do {
        func_800F13A0(arg0, base + i, arg3 & (u8) bit);
        i += 1;
        bit <<= 1;
    } while (i < 5);
    bit = 1;
    i = 0;
    do {
        off = i + 5;
        func_800F13A0(arg0, base + off, arg2 & (u8) bit);
        i += 1;
        bit <<= 1;
    } while (i < 4);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F14B4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F18C8);

extern s32 func_80100188(s32, s32, s32);

s32 func_800F1E60(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_80100188(arg1 - arg0, arg2 << 0xC, arg3) + (arg0 << 0xC);
}

extern s32 D_800E0070;
extern s16 D_801532D8;

void func_800F1E9C(void) {
    func_800235AC(&D_800E0070);
    func_800FFF50();
    D_801532D8 = 1;
}

extern s32 func_8008C664();

void func_800F1ED8(u8 *arg0) {
    register u8 *s1 asm("s1") = arg0;
    register s32 s0 asm("s0");
    u16 b3[3];

    s0 = func_800E7810((s16) func_800F93A0(s1));
    if (s0 == 0x7D0) {
        return;
    }
    b3[0] = s1[2];
    b3[2] = s1[3];
    b3[1] = s1[4];
    func_8008C664(s0, (s32) b3, 0x100 - (s1[7] << 8), 3, (s16) func_800F93A0(s1 + 5));
}

extern void func_8008CC50(s32);
extern void func_8008CC80(s32);

void func_800F1F74(void *arg0) {
    register s32 s0 asm("s0") = (s32) arg0;
    register s32 v0 asm("v0");
    register s32 a0 asm("a0");

    v0 = func_800F93A0();
    v0 <<= 16;
    s0 = *(u8 *) ((u8 *) s0 + 2);
    v0 = func_800E7810(v0 >> 16);
    a0 = v0;
    v0 = 0x7D0;
    if (a0 != v0) {
        if (s0 == 1) {
            func_8008CC50(a0);
        } else {
            func_8008CC80(a0);
        }
    }
}

extern void func_8008CD24();

void func_800F1FDC(void) {
    s32 temp_v0;

    temp_v0 = func_800E7810(func_800F93A0());
    if (temp_v0 != 0x7D0) {
        func_8008CD24(temp_v0);
    }
}

extern void *func_8008CA48(s32);
extern void func_8008C9C4(s32, s16 *);
extern void func_8008C7CC(s32, u8, s32);

void func_800F2020(u8 *arg0) {
    s16 b[3];
    s32 temp_v0;
    register u16 *p asm("v0");
    register u16 v1 asm("v1");
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register u8 s1 asm("s1");
    register u8 *s2 asm("s2") = arg0;

    temp_v0 = func_800E7810((s16) func_800F93A0());
    s0 = temp_v0;
    if (s0 != 0x7D0) {
        p = (u16 *) func_8008CA48(s0);
        v1 = p[0];
        b[0] = -(s16) v1;
        v1 = p[1];
        b[1] = -(s16) v1;
        b[2] = -(s16) p[2];
        func_8008C9C4(s0, b);
        p = (u16 *) func_80180AFC(func_8008CDD0(s0));
        a0 = s0;
        s0 = (s32) p;
        s1 = ((u8 *) s0)[0x3B];
        ((u8 *) s0)[0x3B] = 6;
        func_8008C7CC(a0, s2[3], s2[2] - 1);
        ((u8 *) s0)[0x3B] = s1;
    }
}

extern s32 func_8008CEFC(s32);

void func_800F20E8(void) {
    s32 temp_v0;

    temp_v0 = func_800E7810();
    if (temp_v0 != 0x7D0) {
        do {
            func_800FFF50();
        } while (func_8008CEFC(temp_v0) != 0);
    }
}

extern void func_801C34B4();
extern void func_801C7FE4();
extern void func_801C8004();
extern s16 D_801532BE;

void func_800F2134(void) {
    if (func_800EF1A8(0x1FC) == 0) {
        D_801532BE = 2;
        func_800EF82C(0xD);
        func_800FFF50();
        func_801C34B4();
        func_801C7FE4();
        func_801C8004();
    }
}

extern s32 D_8008DDCC;
extern s32 D_8008DDEC;

void func_800F218C(void) {
    s32 v0;
    s32 *s0;

    v0 = (s32) &D_8008DDCC;
    D_801CD78C = (s32 *) v0;
    func_80100384();
    s0 = (s32 *) &D_8008DDEC;
    do {
        func_800FFF50();
        D_801CD78C = s0;
    } while (func_80100384() != 0);
}

extern void func_800F218C();

void func_800F21EC(void) {
    func_800FD1D8(0x41);
    func_800F218C();
    func_800FFE28();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F221C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F26F0);

extern void func_800F290C();
extern void func_800F0574();
extern void func_800E2390();
extern void func_800F2998();
extern void func_800F29D8();
extern void func_800EF2FC();

void func_800F28C4(void) {
    func_800F290C();
    ((void (*)(s32)) func_800F0574)(0);
    func_800E2390();
    func_800F2998();
    func_800F29D8();
    func_800EF2FC();
}

extern s32 D_8015327C;
extern s32 D_801AED8C;
extern s32 D_801CA6F0;
extern s32 D_801CA6F4;
extern s32 D_801CD66C;
extern s32 D_801CD830;
extern s32 D_8013B8F8;
extern s32 D_8013A8B8;
extern s32 D_8005771C;
extern s32 D_801CD844;
extern s16 D_80153332;
extern s16 D_8019A224;

void func_800F290C(void) {
    D_8015327C = (s32) &D_80195CD0;
    D_801CD66C = (s32) &D_8013B8F8;
    D_801CD830 = (s32) &D_8013A8B8;
    D_801CD75C = (s32 *) &D_8004A6BC;
    D_80153280 = &D_8005771C;
    D_801CD7E0 = &D_80153DF4;
    D_801CD844 = -1;
    D_80153332 = 0;
    D_8019A224 = 0;
    D_801CD50C = 0;
}

extern void func_800E2520();
extern void func_800E2C0C();
extern void func_800E3088();
extern void func_800FD93C();
extern void func_800FFE64();

void func_800F2998(void) {
    func_800FD93C();
    func_800E2520();
    func_800E2C0C();
    func_800E3088();
    func_800FFE64();
}

void func_800F29D8(void) {
}

extern u8 D_8019A241[];
extern s16 D_8019A2D0[];
extern s16 D_8019A2FC[];

void func_800F29E0(void) {
    register u8 *s0v asm("s0");
    register u8 *s2v asm("s2");
    register s32 s1v asm("s1");
    register s32 s3v asm("s3");
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");

    s1v = 0;
    s3v = 0xFF;
    s0v = D_8019A241;
    s2v = (u8 *) D_8019A2D0;
    do {
        a0v = s1v;
        s0v[-1] = 0;
        s0v[1] = 0;
        v0v = func_8008CBB4(a0v);
        if (v0v != 0) {
            a0v = s1v;
            s0v[0] = func_8008C0AC(a0v);
        } else {
            s0v[0] = s3v;
        }
        *(s16 *) s2v = 0;
        s2v += 2;
        v0v = s1v << 1;
        s1v += 1;
        *(s16 *) ((u8 *) D_8019A2FC + v0v) = 0;
        v0v = s1v < 0x15;
        s0v += 7;
    } while (v0v != 0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F2A84);

extern s16 D_801532C0;
extern s32 D_80153338;
extern void func_8008EFB4();
extern void func_800F6EC8();

void func_800F2C74(void) {
    func_800F29E0();
    D_801532BE = 1;
    if (func_800EF1A8(0x1FD) != 0) {
        func_800F6EA8();
        func_800F29D8();
        D_801532C0 = 0;
        D_80153338 = 0;
    }
    if (func_800EF1A8(0x27) != 0) {
        D_801532C0 = 0;
        D_80153338 = 0;
        func_8008EFB4(2, 0, 0, 0, 2);
        func_800FFD70(1, (s32 *) &func_800F6EC8);
    }
}

void func_800F2D18(void) {
}

extern void func_800F29E0();

void func_800F2D20(void) {
    func_800F29E0();
    if (func_80100164(1) == 0) {
        func_800F6EA8();
        func_800F29D8();
        D_80153338 = 0;
        D_801532C0 = 0;
    }
}

extern void func_800F67F0();
extern s32 func_800FFEEC();

void func_800F2D70(void) {
    func_800F67F0();
    func_800FFEEC(6);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F2D98);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F2DA8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F2EE0);

extern u8 D_801566C0;

void func_800F2FE4(void) {
    s32 a0 = 0;
    s32 a1 = (s32) D_801CD7E0;
    s32 v0;
    s32 v1;

    do {
        v0 = ((u8 *) &D_801566C0)[a0];
        a0++;
        v1 = v0 << 4;
        v1 -= v0;
        v1 <<= 2;
        v1 += a1;
        *(s16 *) (v1 + 0x38) = 0;
    } while (a0 < 0xB);
}

void func_800F3024(void) {
}

extern u8 D_8013A658[];
extern u8 D_8013A750[];
extern u8 D_801566CC[];
extern u8 D_801566CD[];

void func_800F302C(s32 arg0) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    register u8 *t0v asm("t0");
    register s32 t1v asm("t1");
    register u8 *t2v asm("t2");
    register s32 t3v asm("t3");

    v1v = 0;
    a1v = 0;
lookup:
    v0v = *(u16 *) (D_8013A658 + a1v);
    if (v0v == a0v) {
        v0v = 0xC;
        goto found;
    }
    v1v += 1;
    a1v += 8;
    if (v1v < 0xC) {
        goto lookup;
    }
    v0v = 0xC;
found:
    if (v1v == v0v) {
        return;
    }
    t3v = 0;
    t0v = D_801566CC;
    v0v = D_8013A36E;
    a3v = 0;
    v1v = v0v << 4;
    v1v += v0v;
    v0v = (s32) D_8013A750;
    t2v = (u8 *) (v1v + v0v);
outer:
    v0v = *(u8 *) (D_801566CC + a3v);
    if (a0v != v0v) {
        goto next;
    }
    t1v = a3v;
    KEEP_NOVOL(t1v);
    a1v = (s32) (t0v + 2);
    a2v = (s32) (t0v + 5);
inner:
    v1v = *(u8 *) t2v;
    v0v = *(u8 *) a1v;
    if (v1v == v0v) {
        v0v = *(u8 *) (D_801566CD + t1v);
        *t2v = (u8) v0v;
        goto next;
    }
    a1v += 1;
    if (a1v < a2v) {
        goto inner;
    }
next:
    t0v += 5;
    t3v += 1;
    a3v += 5;
    v0v = t3v < 8;
    if (v0v != 0) {
        goto outer;
    }
    v0v = a0v << 4;
    v0v -= a0v;
    v0v <<= 2;
    v1v = (s32) D_801CD7E0;
    a0v = *(u8 *) t2v;
    v0v += v1v;
    *(s16 *) (v0v + 0x38) = a0v;
}

void func_800F312C(void) {
    u8 val = 0xFF;
    s32 i = 0;
    u8 *p = D_8013A750;
    s32 j;
    u8 *q;

    do {
        j = 0x10;
        q = p + 0x10;
        do {
            *q = 0;
            q--;
            j--;
        } while (j >= 0);
        D_8013A750[i + 1] = val;
        i += 0x11;
        p += 0x11;
    } while (i < 0x165);
}

extern u8 D_8013A751[];

void func_800F3178(s32 arg0) {
    register s32 s0 asm("s0") = arg0;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3") = 0xFF;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a2 = (s32) func_80180AFC();
    KEEP_NOVOL(a2);
    a3 = 0xFF;
    v1 = (s32) D_8013A750;
    v0 = s0 << 4;
    a0 = v0 + s0;
    v1 = a0 + v1;
    a1 = v1 + 0x11;
    do {
        v0 = *(u8 *) (a2 + 0x1B8);
        if (v0 == 0) {
            *(u8 *) v1 = 0;
            D_8013A751[a0] = a3;
        }
        v1++;
    } while (v1 < a1);
}

extern s32 D_80195C8C;

s32 *func_800F31F0(void) {
    return &D_80195C8C;
}

extern s16 D_801531C8;

void func_800F3200(void) {
    func_800FD1D8(0x42);
    func_800FFD28(2);
    D_801531C8 = 7;
    func_800FFE28();
}

void func_800F323C(void) {
    D_80153298 = 1;
    func_800FD1D8(0x42);
    func_800FFD28(0x10);
    func_800FFE28();
}

s32 func_800F3278(s16 *arg0, u8 *arg1) {
    u8 *a0 = (u8 *) arg0;
    u8 *a1 = arg1;
    s32 v1 = 0;
    s32 a2 = 0xFF;
    u8 v0;

loop:
    v0 = *a1;
    if (v0 == a2) {
        goto end;
    }
    KEEP_NOVOL(v0);
    v0 = *a1;
    a1++;
    v1++;
    *(s16 *) a0 = v0;
    a0 += 2;
    goto loop;
end:
    return v1;
}

void func_800F32B0(u8 *arg0, u8 *arg1, s32 arg2) {
    volatile s32 pad[2];
    s32 i = 0;

    if (arg2 > 0) {
        do {
            *(s16 *) arg0 = *arg1;
            arg1++;
            i++;
            arg0 += 2;
        } while (i < arg2);
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F32E4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F32EC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F3AA0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F3AB0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F3D44);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F3FA4);

void func_800F4104(void) {
    register s16 *a3 asm("a3") = &D_8013A36E;
    register u8 *a2 asm("a2") = D_8013A750;
    register s32 a1 asm("a1") = 0;
    register s32 a0 asm("a0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    do {
        v0 = *(u16 *) (D_8013A658 + a1);
        a0 = D_80153268;
        if (a0 == v0) {
            v0 = *a3;
            v1 = v0 << 4;
            v1 += v0;
            v0 = a0 << 4;
            v0 -= a0;
            a0 = (s32) D_801CD7E0;
            v0 <<= 2;
            v0 += a0;
            v0 = *(u8 *) (v0 + 0x38);
            v1 += (s32) a2;
            *(u8 *) v1 = v0;
        }
        a1 += 8;
    } while (a1 < 0x60);
}

extern s32 D_80195CD4[];

void func_800F4180(void) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 v asm("v0");
    register s32 one asm("a0");
    s32 t;

    t = func_80100090();
    one = 1;
    s1v = t;
    SCHED_BARRIER();
    v = (s32) D_8013A750;
    D_80195CD4[D_801CD170 << 8] = one;
    s0v = (D_8013A36E << 4) + D_8013A36E;
    s0v = s0v + v;
    func_800ECF20();
    *(u8 *) s0v = ((u8 *) s1v)[0x38];
    func_800FFE28();
}

extern u8 D_8013A608;

void func_800F41F8(void) {
    if (D_8013A608 != 0)
        return;
    D_80153298 = 1;
}

void func_800F421C(s32 arg0) {
    D_801532A0 = 1;
    D_80195C34 = 0x20;
    func_800EBB08(arg0, 0);
    D_801532A0 = 0;
    D_80195C34 = 0;
}

extern void func_800F421C();
extern s16 D_80153D3C;
extern s16 D_80153D3E;

void func_800F4264(void) {
    s32 temp_v0;

    temp_v0 = func_80100090();
    D_80153D3C = -2;
    D_80153D3E = -2;
    func_800F421C(temp_v0);
    func_800FFE28();
}

extern s16 D_80153DC0;
extern void func_800EEE98();
extern u8 *func_800E20D4_s() asm("func_800E20D4");

void func_800F42A8(void) {
    s16 *s0v;
    s32 s1v;
    s32 v0v;
    s32 v1v;
    s32 temp_s1;
    u8 *p;

    temp_s1 = func_80100090();
    s0v = &D_80153DC0;
    MEMORY_BARRIER();
    v1v = -2;
    s1v = temp_s1;
    *s0v = v1v;
    p = func_800E20D4_s();
    v0v = p[0x5C] & 8;
    if (v0v != 0) {
        v0v = -1;
        *s0v = v0v;
        func_800E1EEC();
        func_800EEE98();
        func_800FFE28();
    }
    v1v = D_80153268;
    v0v = 0xE;
    if (v1v == v0v) {
        goto state;
    }
    v0v = 0x14;
    if (v1v == v0v) {
        goto state;
    }
    v0v = 0x21;
    if (v1v == v0v) {
        goto state;
    }
    v0v = 0x2F;
    if (v1v == v0v) {
        goto state;
    }
    v0v = 0x31;
    if (v1v == v0v) {
        goto state;
    }
    v0v = 0x33;
    if (v1v == v0v) {
        goto state;
    }
    goto finish;
state:
    func_800E1EEC();
    func_800FFE28();
finish:
    func_800F41F8();
    func_800F421C(s1v);
    func_800FFE28();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F437C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F454C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F474C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F4754);

extern u8 D_80156748;

s32 func_800F49D8(s32 arg0) {
    s32 var_a1;
    u8 *var_v1;
    s32 var_v0;
    u8 first;
    u8 sentinel;
    s32 needle = arg0;

    var_a1 = 0;
    first = D_80156748;
    if (first != 0xFF) {
        sentinel = 0xFF;
        var_v1 = &D_80156748;
        var_v0 = *var_v1;
loop_2:
        if (var_v0 == needle) {
            var_a1 = 1;
        } else {
            var_v1 += 1;
            var_v0 = *var_v1;
            if (var_v0 != sentinel) {
                goto loop_2;
            }
        }
    }
    return var_a1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F4A2C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F4CDC);

extern void func_800F2FE4();
extern s32 func_800F4CDC;

void func_800F4ECC(s32 arg0) {
    func_800F2FE4();
    func_800FFD70(4, &func_800F4CDC);
    func_800FFF08(4, arg0, 0, 0);
}

extern s32 func_800E20D4();
extern s16 D_80153DD4;

void func_800F4F18(void) {
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");
    s32 v1;
    u8 *p;

    s0 = func_80100090();
    p = (u8 *) func_800E20D4();
    v1 = *(s16 *) ((u8 *) D_801CD7E0 + 0x74);
    v0 = 3;
    if (v1 == v0) {
        v0 = 0x10;
        p[0x1B8] = v0;
    } else {
        v0 = 4;
        if (v1 == v0) {
            v0 = 0x11;
            p[0x1B8] = v0;
        } else {
            v0 = -3;
        }
    }
    v0 = -3;
    D_80153DD4 = v0;
    func_800F421C(s0);
    func_800FFE28();
}

extern u8 D_8013A5F8;
extern void func_800F4FD4(s32, s32, s32);

void func_800F4F94(s8 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = func_80180AFC(arg1);
    *(u8 *) (temp_v0 + 0x1B9) = arg0;
    *(u8 *) (temp_v0 + 0x1B8) = D_8013A5F8;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F4FD4);

extern s32 func_8008CED0(s32);
extern void func_800F5384(s32, s32, s32, s32, s32, s32);

void func_800F5230(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register s32 s0v asm("s0");
    register s32 s2v asm("s2");
    register s32 s1v asm("s1");
    register s32 s3v asm("s3");
    register s32 s4v asm("s4");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a2v asm("a2");
    s32 a1v;
    s32 a3v;
    s32 a4v;

    s0v = arg0;
    s2v = arg1;
    s1v = arg2;
    s3v = arg3;
    s4v = arg4;
    if (s0v != 8) {
        if (s0v != 6) {
            v1v = func_8008CED0(s1v);
            if (s0v == 5) {
                func_800F4FD4(v1v, s1v, s4v);
                return;
            }
            a0v = s0v;
            if (s0v != 7) {
                goto common;
            }
            a0v = 7;
            KEEP_NOVOL(a0v);
            a1v = 0;
            KEEP_NOVOL(a1v);
            a2v = s1v;
            a3v = 0;
            a4v = 0;
            func_800F5384(a0v, a1v, a2v, a3v, a4v, v1v);
            return;
        }
    }
common:
    func_800F5384(s0v, s2v, s1v, s3v, s4v, v1v);
}

extern s32 D_80180530;
extern s32 *D_801CD174;
extern void func_800449F8();

s32 func_800F5304(void) {
    s32 *pe;
    s32 *pl;
    u32 v1;
    s32 tmp;

    tmp = (s32) func_80180AFC();
    D_801CD78C = &D_80180530;
    pe = (s32 *) func_80100384(tmp);
    v1 = (u32) (pe[0] + 1);
    D_801CD174 = pe;
    if (v1 < 2) {
        func_800449F8(0x11, 7);
    }
    pl = D_801CD174;
    if (pl[0] != 4) {
        return -1;
    }
    return ((u8 *) pl)[0x52];
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F5384);

extern s32 func_80180B2C();

s32 func_800F5D80(s32 arg0) {
    extern void func_80180C90(s32, s32 *);
    extern s32 func_8008CE20(s32);
    register s32 s0v asm("s0");
    register s32 pv asm("v1");
    register s32 xv asm("v0");
    register s32 yv asm("v0");
    s32 sp10;
    s32 r;

    s0v = arg0;
    func_80180C90(arg0, &sp10);
    if (sp10 < 0) {
        xv = s0v - 1;
        if ((u32) xv >= 0x49) {
            return -1;
        }
        r = func_80180B2C(s0v);
        sp10 = r;
        if (r < 0) {
            return -1;
        }
        pv = (s32) func_80180AFC(r);
        yv = *(u8 *) ((u8 *) pv + 0x161);
        yv = yv - 0x78;
        yv = ((u32) yv < 5);
        if (yv == 0) {
            return -1;
        }
        return pv;
    }
    if (func_8008CE20(sp10) >= 0) {
        return (s32) func_80180AFC(sp10);
    }
    return -1;
}

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
} F5E28Entry;

extern u16 D_800475E0[];
extern F5E28Entry D_80049A18[];
extern u8 D_80156B4C[];
extern s32 func_800F5F0C(s16, s16, s16, s16, s32);

s32 func_800F5E28(void) {
    register u8 *s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    s32 result;

    s1v = 0;
    __asm__ volatile("sll $2,$17,1");
outer:
    v0v = *(u16 *) ((u8 *) D_800475E0 + v0v);
    v0v <<= 16;
    v1v = v0v >> 16;
    if (s1v != 0) {
        if (v1v == 0) {
            goto zero_return;
        }
    }
    v0v = (u32) v0v >> 31;
    v0v = v1v + v0v;
    v0v >>= 1;
    v0v <<= 1;
    v1v = (s32) D_80049A18;
    s0v = (u8 *) v1v + v0v;
inner:
    v0v = ((F5E28Entry *) s0v)->f8;
    a0v = ((F5E28Entry *) s0v)->f0;
    a1v = ((F5E28Entry *) s0v)->f2;
    a2v = ((F5E28Entry *) s0v)->f4;
    a3v = ((F5E28Entry *) s0v)->f6;
    result = func_800F5F0C((s16) a0v, (s16) a1v, (s16) a2v, (s16) a3v, v0v);
    v1v = ((F5E28Entry *) s0v)->f0;
    v1v = D_80156B4C[v1v];
    v1v = (v1v << 1) + 2;
    s0v += v1v;
    v1v = result;
    v0v = 1;
    if (v1v == v0v) {
        goto inner;
    }
    v0v = 2;
    if (v1v == v0v) {
        v0v = 1;
        goto end;
    }
    s1v++;
    v0v = s1v < 0xA;
    if (v0v != 0) {
        v0v = s1v << 1;
        goto outer;
    }
zero_return:
    v0v = 0;
end:
    return v0v;
}

void func_800F5F04(void) {
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F5F0C);

extern u16 D_8004E5D0[];
extern s16 D_801CD7D4;

s32 func_800F641C(void) {
    register s32 ret asm("v0");
    ret = D_801CD7D4;

    {
        register s32 v0v asm("v0");

        if (v0v != 0) {
            ret = D_8004E5D0[func_800EF1A8(0x27)];
            MEMORY_BARRIER();
            goto merge;
        }
    }
    __asm__ volatile("" ::: "$2");
    ret = 0;
merge:
    return ret;
}

extern s32 D_801A6690;

s32 func_800F6464(void) {
    s32 v0;

    v0 = D_801A6690;
    v0 <<= 1;
    v0 = (s32) D_8004E5D0 + v0;
    v0 = *(u16 *) v0;
    v0 &= 0xF300;
    return v0 >> 8;
}

extern u16 D_801532DA;

void func_800F6490(s32 arg0) {
    if (D_801532DA == 2) {
        func_800EF25C(0x56, arg0);
        func_800EF25C(0x29, 0xFFFF);
        func_800FFF50();
        func_800EF25C(0x56, 0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F64E4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F6568);

extern void func_800F64E4();
extern s32 D_8019A218;

void func_800F67C4(s32 *arg0) {
    D_8019A218 = *arg0;
    func_800F64E4();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F67F0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world", func_800F6800);

extern void func_800E212C();
extern void func_800E28AC();
extern s32 D_801CD814;

void func_800F6E2C(s32 arg0, s32 arg1) {
    func_800E212C(arg1);
    D_801CD814 = arg0;
    func_800E28AC();
}

extern s16 D_80153340;
