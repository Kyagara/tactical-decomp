#include "common.h"

extern void func_800248FC();
extern void func_800FFD70();
extern void func_80024868();
extern s32 D_8004EAF4;
extern void func_80067320();
extern s32 D_8004E5BC;
extern s32 D_800856F4;
extern u8 D_80085F44[];
extern s32 D_80085FC4;
extern u8 D_80086018[];
extern s32 D_8008E53C;
extern void func_80011E38();
extern void func_8001DBA8();
extern void func_80024638();
extern void func_800246D4();
extern void func_80024C38();
extern void func_800449EC();
extern void func_80067484();
extern void func_80067C1C();
extern void func_80067D84();
extern void func_8006854C();
extern void func_80068638();
extern void func_80068684();
extern void func_80068B74();
extern void func_80068CD0();
extern void func_80069EB4();

s32 func_800600F0(void) {
    func_80068684();
    if (D_8008E53C & 1) {
        u8 *base = D_80086018;
        u8 *base40 = base + 0x40;
        do {
            func_80011E38(&D_8004EAF4);
            func_80068B74();
            func_80067484();
            func_8006854C();
            func_80069EB4();
            func_80068CD0((D_8004E5BC << 6) + (s32) base, D_80085F44, D_80085FC4);
            func_80024C38((D_8004E5BC << 6) + (s32) base40 - 4);
            func_800246D4(0);
            func_80067D84();
            func_8001DBA8(0);
            func_80067C1C();
            func_800449EC();
        } while (D_8008E53C & 1);
    }
    func_80024638(0);
    func_80068638(0xC0, 0x78);
    return D_800856F4;
}

extern s32 D_8008FC14;
extern void func_800686DC();
extern void func_80068760();
extern void func_8006E8B0();

void func_8006020C(void) {
    func_800686DC();
    if (D_8008E53C & 1) {
        u8 *base = D_80086018;
        u8 *base40 = base + 0x40;
        do {
            func_80011E38(&D_8004EAF4);
            func_80068B74();
            func_80067484();
            func_8006E8B0((D_8004E5BC << 6) + (s32) base, D_8004E5BC);
            func_80069EB4();
            func_800246D4(0);
            func_80067D84();
            func_8001DBA8(D_8008FC14);
            func_80067C1C();
            func_80024C38(((D_8004E5BC ^ 1) << 6) + (s32) base40 - 4);
            func_800449EC();
        } while (D_8008E53C & 1);
    }
    func_80068760();
    func_80024638(0);
    func_80068638(0xC0, 0x78);
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80060320);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_8006048C);

extern void func_800246D4(s32);
extern void func_800736F8(s32);
extern void func_80020F3C();
extern void func_80067620();

void func_800605BC(s32 arg0) {
    func_800246D4(0);
    func_800736F8(0);
    func_80020F3C();
    if (arg0 != 0) {
        func_80067620();
    }
    D_8008E53C &= -3;
}

DEAD_TAIL_LW(2, D_8008E53C);

extern s32 func_8001EDEC(s32, s32, s32);
extern void func_8001DBA8(s32);
extern u16 D_800C5A00[];
extern u16 D_800EDA00[];
extern u16 D_800C0000[];
extern u16 D_800C2D00[];
extern s16 D_800852E0;

void func_80060628(void) {
    s32 flag;

    if (flag & 4) {
        func_80068638(0, 1);
        do {
        } while (func_8001EDEC(9, 0, 0) == 0);
        func_8001DBA8(4);
        D_8008E53C ^= 4;
    }
}

static s32 func_8006068C(s32 *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    volatile s32 *p = arg0;
    s32 v0;
    s32 v1;

    p[0] = (s32) D_800C5A00;
    p[1] = (s32) D_800EDA00;
    p[2] = 0;
    p[3] = (s32) D_800C0000;
    v1 = *(volatile s32 *) &arg4;
    p[4] = (s32) D_800C2D00;
    v0 = 0x18;
    p[5] = 0;
    ((volatile s16 *) p)[12] = arg1;
    ((volatile s16 *) p)[13] = arg2;
    ((volatile s16 *) p)[16] = arg3;
    p[10] = 0;
    ((volatile s16 *) p)[22] = arg1;
    ((volatile s16 *) p)[23] = arg2;
    ((volatile s16 *) p)[17] = v1;
    MEMORY_BARRIER();
    D_800852E0 = v0;
    ((s32 *) arg0)[13] = 0;
    return v0;
}

extern void func_8007348C(s32);
extern void func_8001E894(void *, s32);
extern void func_80021084(s32, s32, s32, s32, s32);
extern void func_80011BD0();
extern u8 D_80115A00[];
extern s32 D_8004EAF8;
extern s32 D_8004EB10;
extern s32 D_8003707C;

void func_800606F8(s32 arg0, s32 arg1) {
    s32 *b;

    func_8007348C(0);
    func_800736F8(arg1);
    func_8001E894(D_80115A00, 0x30);
    func_80021084(1, 0, -1, 0, 0);
    b = &D_8004EAF4;
    func_80011BD0(b, arg0, 1, 0);
    if (D_8004EAF8 != 0) {
        do {
            func_80011E38(b);
            func_8001DBA8(0);
        } while (D_8004EAF8 != 0);
    }
    do {
    } while (func_8001EB88(2, (s32) &D_8004EB10, 0) == 0);
}

DEAD_TAIL_LW(2, D_8003707C);

extern s32 D_800852C4;
extern u8 D_800852C8[];
extern u8 D_800852CA[];
extern u8 D_800852CC[];
extern s32 D_800852D8;
extern u16 D_800852DC;
extern u16 D_800852DE;
extern s16 D_800852E2;
extern s32 D_800852E4;
extern void func_800212EC(void);
extern void func_80073674(s32, s32, s32, s32);

void func_800607D4(void) {
    s32 v0;
    s32 v1;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 s1 asm("s1");
    s32 product;
    register u16 *s0 asm("s0");

    if (v0 != 0) {
        func_800212EC();
        D_8003707C = 0;
    }
    s0 = &D_800852DC;
    v0 = D_800852C4;
    s1 = (s32) s0 - 0x20;
    v0 <<= 2;
    v0 += s1;
    a1 = *(s32 *) v0;
    func_800248FC(s0, a1);
    v1 = D_800852C4;
    MEMORY_BARRIER();
    v0 = *s0;
    a1 = (u16) D_800852E0;
    a3 = (v1 == 0);
    MEMORY_BARRIER();
    v0 += a1;
    D_800852C4 = a3;
    *s0 = (u16) v0;
    a2 = D_800852D8;
    v0 <<= 16;
    a0 = a2 << 3;
    v1 = *(s16 *) (D_800852C8 + a0);
    a0 = *(s16 *) (D_800852CC + a0);
    MEMORY_BARRIER();
    v0 >>= 16;
    v1 += a0;
    a1 <<= 16;
    v0 = v0 < v1;
    if (v0 == 0) {
        goto else_path;
    }
    v0 = D_800852E2;
    a1 >>= 16;
    product = a1 * v0;
    v0 = a3 << 2;
    v0 += s1;
    a0 = *(s32 *) v0;
    a1 = product;
    a1 += ((u32) product >> 31);
    a1 >>= 1;
    func_80073674(a0, a1, a2, a3);
    __asm__ volatile("j 0x80067914");
else_path:
    v0 = 1;
    D_800852E4 = v0;
    v0 = (a2 == 0);
    D_800852D8 = v0;
    v0 <<= 3;
    v1 = *(u16 *) (D_800852C8 + v0);
    *s0 = (u16) v1;
    v0 = *(u16 *) (D_800852CA + v0);
    D_800852DE = (u16) v0;
}

extern s32 func_800679A0();
extern void func_80073BD0();
extern void func_8002110C();

s32 func_8006092C(s32 *arg0) {
    s32 *s0;
    s32 s1;
    s32 b;

    s0 = arg0;
    s1 = func_800679A0(s0);
    if (s1 == 0)
        goto end;
    b = (s0[2] == 0);
    s0[2] = b;
    func_80073BD0(s1, s0[b]);
    func_8002110C(s1);
    __asm__ volatile(".set\tnoreorder\n\tj 0x80067988\n\tori $2,$0,0x1\n\t.set\treorder");
end:
    SCHED_BARRIER();
    return 0;
}

extern s32 func_80021208(s32 *, void **);

struct O_609A0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    u16 f10;
    u16 f12;
};

struct H_609A0 {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
};

struct Out_609A0 {
    char p00[0x1C];
    s16 f1C;
    s16 f1E;
    char p20[4];
    s16 f24;
    u16 f26;
    char p28[0xA];
    s16 f32;
};

extern s32 D_8008E534;
extern s32 D_8008E538;
extern s32 D_8008E540;
extern s32 D_8008E544;
extern s32 D_8008FC08;
extern s32 D_8008FC10;
extern s32 D_8008FC18;

s32 func_800609A0(void *arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 i asm("s0");
    register struct Out_609A0 *out asm("s1");
    register struct O_609A0 *objp asm("a1");
    register s32 objaddr asm("a0");
    register struct H_609A0 *hp asm("a0");
    s32 anchor[4];
    register s32 *loc asm("a0");
    s32 limit32;
    u16 outval;

    out = arg0;
    i = 0;
    for (;;) {
        loc = &anchor[0];
        if (func_80021208(loc, (void **) &anchor[1]) != 0) {
            func_8001DBA8(0);
            if (i != 0x80) {
                i++;
                continue;
            }
            i++;
            __asm__ volatile(".set\tnoreorder\n\tj .L80067B1C\n\tmove %0,$zero\n\t.set\treorder"
                             : "=r"(v0)::"memory");
            break;
        }
        break;
    }
    objp = *(struct O_609A0 **) &anchor[1];
    limit32 = D_8008E534;
    v0 = ((volatile struct O_609A0 *) objp)->f8;
    v1 = objp->f8;
    D_8008FC18 = v0;
    if ((u32) v1 < (u32) limit32) {
        goto after_first;
    }
    D_8008E544 = 1;
after_first:
    v1 = D_8008FC08;
    v0 = -1;
    if (v1 == -1) {
        goto after_second;
    }
    v0 = objp->f8;
    if ((u32) v0 < (u32) v1) {
        goto after_second;
    }
    D_8008E544 = 2;
after_second:
    v0 = D_8008E538;
    objaddr = anchor[1];
    v1 = ((struct O_609A0 *) objaddr)->f10;
    if (v0 != v1) {
        goto change;
    }
    v1 = ((struct O_609A0 *) objaddr)->f12;
    v0 = D_8008E540;
    if (v0 == v1) {
        goto final;
    }
change:
    MEMORY_BARRIER();
    hp = (struct H_609A0 *) &anchor[2];
    hp->f0 = 0;
    hp->f2 = 0;
    hp->f4 = 0x1E0;
    hp->f6 = 0x1E0;
    func_80024868(&hp->f0, 0, 0, 0);
    v0 = anchor[1];
    v1 = ((volatile struct O_609A0 *) v0)->f10;
    limit32 = ((volatile struct O_609A0 *) v0)->f12;
    v0 = ((volatile struct O_609A0 *) v0)->f12;
    v0 = (v0 + 0xF) & 0xFFF0;
    D_8008E538 = v1;
    D_8008E540 = limit32;
    D_8008FC10 = v0;
final:
    limit32 = D_8008E538;
    v0 = anchor[0];
    v1 = (u32) limit32 * 3;
    limit32 = (u32) v1 >> 31;
    v1 += limit32;
    v1 = (u32) v1 >> 1;
    outval = D_8008FC10;
    out->f24 = v1;
    out->f1C = v1;
    out->f26 = outval;
    out->f1E = outval;
    out->f32 = outval;
    return v0;
}

struct B_80060B38 {
    char p00[0x18];
    u16 f18;
    u16 f1A;
    char p1C[0xC];
    s32 f28;
    s16 f2C;
    s16 f2E;
    char p30[4];
    s32 f34;
};

void func_80060B38(struct B_80060B38 *arg0) {
    volatile s32 sp0;
    s32 t = arg0->f34;
    s32 t2;
    s32 off;
    s32 off2;

    sp0 = 0x800000;
    if (t == 0) {
        s32 one = 1;
        do {
            sp0 = sp0 - 1;
            if (sp0 == 0) {
                arg0->f34 = one;
                t2 = arg0->f28 == 0;
                arg0->f28 = t2;
                off = t2 * 8;
                arg0->f2C = *(u16 *) ((char *) arg0 + off + 0x18);
                off2 = arg0->f28 * 8;
                arg0->f2E = *(u16 *) ((char *) arg0 + off2 + 0x1A);
            }
        } while (arg0->f34 == 0);
    }
    arg0->f34 = 0;
}

extern s32 func_8001EB88(s32, s32, s32);
extern s32 func_80020E28(s32);

void func_80060BD0(s32 arg0) {
    do {
        while (func_8001EB88(2, arg0, 0) == 0) {
        }
    } while (func_80020E28(0x1A0) == 0);
}

DEAD_TAIL_LW(2, D_8004E5BC);

extern u8 D_800851C0[];
extern s32 D_800855A8;
extern void func_800249C4(void *, s32, s32);
extern void func_80024CAC(void *);
extern void func_80024E84(void *);

struct H_60C24 {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fa;
    s16 fc;
    s16 fe;
};

struct H2_60C24 {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
};

void func_80060C24(void) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register u8 *base asm("s0");
    struct H_60C24 h;
    register struct H2_60C24 *p asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");

    base = D_800851C0;
    USE(base);
    v0 ^= 1;
    D_8004E5BC = v0;
    func_80024CAC(base + v0 * 0x70);
    v0 = D_8004E5BC;
    base += 0x5C;
    func_80024E84(base + v0 * 0x70);
    v1 = D_8008E53C;
    if (!(v1 & 2)) {
        v0 = 0xF0;
        h.f6 = v0;
        h.f0 = 0;
        if (v1 & 0x1000) {
            __asm__ volatile(".set\tnoreorder\n\tj .L80067CAC\n\tori %0,$zero,0x140\n\t.set\treorder"
                             : "=r"(v0), "=r"(v1) : "1"(v1));
        }
        v0 = 0x100;
        h.f4 = v0;
        v0 = D_8004E5BC;
        if (!(v0 & 1)) {
            goto set_f2;
        }
        v0 = 0xF0;
        __asm__ volatile(".set\tnoreorder\n\tj .L80067CD4\n\tsh %0,0x12($sp)\n\t.set\treorder"
                         : "=r"(v0) : "0"(v0));
set_f2:
        h.f2 = 0;
        MEMORY_BARRIER();
        v1 = D_8008E53C;
        v0 = v1 & 0x20000;
        if (v0) {
            func_80024868(&h.f0, 0, 0, 0);
            __asm__ volatile("j .L80067D54" : "=r"(v1) : "1"(v1));
        }
        v0 = v1 & 0x40000;
        if (v0) {
            v0 = 0x200;
            p = (struct H2_60C24 *) &h.f8;
            a1v = h.f0;
            a2v = h.f2;
            __asm__ volatile("" : : "r"(p), "r"(a1v), "r"(a2v));
            v1 = 0x100;
            p->f0 = v0;
            p->f4 = v0;
            v0 = 0xF0;
            p->f2 = v1;
            p->f6 = v0;
            func_800249C4(p, a1v, a2v);
            __asm__ volatile("j .L80067D54");
        }
        func_800248FC(&h, D_800855A8);
    }
    func_80024638((((u32) D_8008E53C >> 6) ^ 1) & 1);
}

extern s32 D_800851BC;
extern s32 D_800852AC;
extern s32 D_800855A4;
extern s32 D_800855AC;
extern s32 func_8001DB58(s32);
extern void func_80040974();

void func_80060D84(void) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s32 temp_v0;

    v0 = D_800855AC;
    D_800852AC = v0;
    temp_v0 = func_8001DB58(0);
    D_800855AC = temp_v0;
    v1 = D_8008E53C;
    v1 &= 0x10;
    if (v1 != 0) {
        D_800855A4 = 0;
        D_800851BC = 0;
        __asm__ volatile("j 0x80067DFC");
    }
    v0 = D_800852AC;
    D_800851BC = temp_v0;
    MEMORY_BARRIER();
    v0 = ~v0;
    v0 = temp_v0 & v0;
    D_800855A4 = v0;
    if (!(D_8008E53C & 0x80000) && D_800855AC == 0x90C) {
        func_800246D4(0);
        func_80018240(0x3FFF, 1);
        func_80018090(0xC0);
        func_80068638(0, 1);
        func_80040974();
    }
}

extern s32 D_80085CAC;
extern s32 D_80085CB0;
extern s32 D_80085CB4;

s32 func_80060E68(s32 arg0) {
    s32 *p;
    s32 v0;

    p = &D_80085CAC;
    v0 = *p;
    D_80085CB4 = arg0;
    D_80085CB0 = 0;
    v0 |= 5;
    *p = v0;
    return v0;
}

s32 func_80060E90(s32 arg0) {
    s32 *p;
    s32 v0;

    p = &D_80085CAC;
    v0 = *p;
    D_80085CB4 = arg0;
    D_80085CB0 = 0;
    v0 |= 6;
    *p = v0;
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80060EB8);

extern u8 D_800473A1;
extern u8 D_800473A2;
extern s32 D_8008642C;
extern s32 D_80086428;
extern s32 D_80086424;
extern s32 D_80086420;
extern s32 D_80086418;
extern s32 D_8008641C;

void func_80061220(void) {
    D_8008642C = 0;
    D_80086428 = 0;
    D_80086424 = 0;
    D_80086420 = 0;
    D_80086418 = D_800473A1;
    D_8008641C = D_800473A2;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80061268);

extern void func_80045234(s32 *);
extern void func_80042AB0(s32, s32);
extern void func_80108920();

void func_80061384(s32 arg0, s32 *arg1) {
    s32 s0;
    s32 w;
    s32 temp_a1;
    s32 v1;

    s0 = arg0;
    {
        s32 a0v;
        a0v = arg1;
        v1 = D_8008E53C;
        if (!(v1 & 0x80)) {
            D_8008E53C = v1 | 0x80;
            func_80045234(a0v);
        }
    }
    temp_a1 = 0x4000 << s0;
    w = D_8008E53C;
    if (!(w & 0x100) || !(w & temp_a1)) {
        SCHED_BARRIER();
        D_8008E53C = ((w | 0x100) & 0xFFFE3FFF) | temp_a1;
        func_80042AB0(s0, temp_a1);
        func_80108920();
    }
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80061420);

extern s32 D_800855EC;
extern s32 D_8008E430;
extern void func_80107E00();
extern void func_80107E10();

void func_80061554(void) {
    register s32 flag asm("v0");
    s32 base;
    register s32 sh asm("v1");
    s32 off;

    if (flag & 0x400) {
        D_8004E5BC ^= 1;
        func_80107E00(~D_8008E430);
        sh = (D_8004E5BC ^ 1) << 6;
        base = (s32) D_80086018;
        off = D_800855EC * 4 + base;
        func_80107E10((void *) (sh + off), D_800851BC);
        D_8004E5BC ^= 1;
    }
}

extern u8 D_80073F34[];

s32 func_800615EC(s32 arg0, s32 arg1) {
    s32 i;
    s32 sum = 0;
    s32 t;

    for (i = 0; i < arg0 - 1; i++)
        sum += D_80073F34[i];
    t = sum - 1;
    return t + arg1;
}

extern void func_80018090(s16);
extern void func_80018300(s32, s16);

void func_80061638(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        __asm__ volatile(".set\tnoreorder\n\tj 0x80068664\n\taddu $4,$0,$0\n\t.set\treorder");
    }
    func_80018090((s16) arg0);
    func_80018300(0x6400, (s16) arg1);
}

extern void func_80043F00();
extern void func_80068220();
extern void func_800687AC();
extern void func_80068AEC();
extern void func_80068BB0();
extern void func_80069A90();
extern void func_80069E60();

void func_80061684(s32 arg0) {
    func_80043F00();
    func_80068AEC();
    func_80069A90();
    func_800687AC(1);
    func_80068BB0();
    func_80068220();
    func_80069E60(arg0);
}

extern void func_80043F00(void);
extern void func_80068AEC(void);
extern void func_80069B6C(void);
extern void func_800687AC(s32);
extern void func_80068BB0(void);
extern void func_8006F8E0(void);

void func_800616DC(void) {
    struct H616DC {
        s16 f0, f1, f2, f3;
    } h;

    func_80043F00();
    func_80068AEC();
    h.f0 = 0x3C0;
    h.f1 = 0x100;
    h.f2 = 0x40;
    h.f3 = 0x100;
    func_800249C4(&h, 0x3C0, 0);
    func_800246D4(0);
    D_8008FC14 = 0;
    func_80069B6C();
    func_800687AC(1);
    func_80068BB0();
    func_8006F8E0();
}

void func_80061760(void) {
    struct H61760 {
        s16 f0, f1, f2, f3;
    } h;

    h.f0 = 0x3C0;
    h.f2 = 0x40;
    h.f1 = 0;
    h.f3 = 0x100;
    func_800249C4(&h, 0x3C0, 0x100);
    func_800246D4(0);
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_800617AC);

extern s32 D_80085CA8;
extern s32 D_8008E548;
extern s32 D_800852A4;
extern s32 D_800855F0;
extern s32 D_80085CBC;
extern s32 D_80085CC0;

void func_80061AEC(void) {
    D_8008E53C = 0x1041;
    D_800855A8 = 0x801D0000;
    D_80085CA8 = -1;
    D_800852A4 = 0x80140000;
    D_80085CBC = 2;
    D_80085CC0 = 2;
    D_800852AC = 0;
    D_800855A4 = 0;
    D_800851BC = 0;
    D_8008E430 = 0;
    D_800855EC = 4;
    D_8008E548 = 0;
    D_800855F0 = 0;
}

extern void func_80067EB8();
extern void func_80068C90();

void func_80061B74(void) {
    func_80068C90();
    func_80067EB8((D_8004E5BC << 6) + (s32) D_80086018);
}

extern s32 D_800852A0;
extern s32 D_800852A8;
extern u8 D_80085D04[];
extern u8 D_80085D0C[];
extern u8 D_80085D24[];
extern u8 D_80086098[];
extern u8 D_800860A4[];
extern u8 D_800860CC[];
extern s32 D_8008FC00;

void func_80061BB0(void) {
    register s32 i asm("a1");
    register s32 c1 asm("t0");
    register s32 c8 asm("a3");
    register s32 c80 asm("a2");
    register u8 *p asm("v1");
    register s32 off asm("a0");

    i = 0;
    c1 = 1;
    c8 = 8;
    c80 = 0x80;
    p = D_80085D24;
    off = 0;
    D_8008FC00 = 0;
    D_800852A8 = 0;
    D_800852A0 = 0;
    D_80085FC4 = 0;
    do {
        *(s32 *) (D_80085D04 + off) = c1;
        *(s32 *) (D_80085D0C + off) = c8;
        p[0] = c80;
        p[1] = c80;
        p[2] = c80;
        p += 0x24;
        i += 1;
        off += 0x24;
    } while (i < 0x10);
    i = 0;
    c1 = 2;
    c8 = 8;
    c80 = 0x80;
    p = D_800860CC;
    off = 0;
    do {
        *(s32 *) (D_80086098 + off) = c1;
        *(s32 *) (D_800860A4 + off) = c8;
        p[0] = c80;
        p[1] = c80;
        p[2] = c80;
        p += 0x38;
        i += 1;
        off += 0x38;
    } while (i < 0x10);
}

extern void func_80024B40(void *, s32);

void func_80061C90(void) {
    s32 unused[2];

    func_80024B40((void *) ((D_8004E5BC << 6) + (s32) D_80086018), 0x10);
    D_8008FC00 = 0;
}

DEAD_TAIL_LW(2, D_8008E53C);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80061CD8);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80061D80);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80062214);

extern void func_80069A34();

void func_800629D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80069A34();
    func_80011BD0(arg0, arg1, arg2, arg3);
}

extern void func_80011E38(s32 *);

void func_80062A34(void) {
    s32 *a = &D_8004EAF8;
    if (*a != 0) {
        s32 *p = a - 1;
        do {
            func_80011E38(p);
            func_8001DBA8(0);
        } while (D_8004EAF8 != 0);
    }
}

extern void func_800699D4();
extern void func_80069CC8();
extern void func_80069D7C();

void func_80062A90(void) {
    func_800699D4(&D_8004EAF4, 0x1505D, 0x11, D_800855A8);
    func_80069A34();
    func_80069D7C(D_800855A8);
    func_800699D4(&D_8004EAF4, 0x1506E, 0x11, D_800855A8);
    func_80069A34();
    func_80069D7C(D_800855A8);
    func_800699D4(&D_8004EAF4, 0x1507F, 0x21, D_800855A8);
    func_80069A34();
    func_80069D7C(D_800855A8);
    func_80069CC8(0, D_800855A8);
    func_80069A34();
}

extern void func_800699D4(s32 *, s32, s32, s32);
extern void func_80069A34(void);
extern void func_80069D7C(s32);

void func_80062B6C(void) {
    struct H62B6C {
        s16 f0, f1, f2, f3;
    } h;

    func_800699D4(&D_8004EAF4, 0x150C2, 0x11, D_800855A8);
    func_80069A34();
    func_80069D7C(D_800855A8);
    func_80069CC8(6, D_800852A4);
    func_80069A34();
    h.f0 = 0x200;
    h.f1 = 0x100;
    h.f2 = 0x200;
    h.f3 = 0xF0;
    func_800248FC(&h, D_800852A4);
    func_800246D4(0);
    func_800699D4(&D_8004EAF4, 0x150D3, 0x170, D_800852A4);
    func_80069A34();
}

void func_80062C38(void) {
    func_800699D4(&D_8004EAF4, 0x150A0, 0x11, D_800855A8);
    func_80069A34();
    func_80069D7C(D_800855A8);
    func_800699D4(&D_8004EAF4, 0x150B1, 0x11, D_800855A8);
    func_80069A34();
    func_80069D7C(D_800855A8);
}

extern s32 D_80073F58[];
extern s32 D_80073F5C[];

void func_80062CC8(s32 arg0, s32 arg1) {
    s32 v1;
    s32 unused[2];

    if (arg0 != D_80085CA8) {
        D_80085CA8 = arg0;
        v1 = D_80073F58[arg0];
        func_800699D4(&D_8004EAF4, v1 + 0x15243, D_80073F5C[arg0] - v1, arg1);
    }
}

extern s32 D_80069D6C(void);
extern s32 func_8001EB18(s32, s32);

s32 func_80062D38(void) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v1 = func_8001EB18(1, 0);
    v0 = 2;
    if (v1 != v0) {
        v0 = v1 ^ 5;
        goto result;
    }
    __asm__ volatile(".set\tnoreorder\n\tj D_80069D6C\n\tori %0,$0,1\n\t.set\treorder"
                     : "=r"(v0));
result:
    v0 = (v0 == 0);
    v0 = -v0;
    return v0;
}

typedef struct {
    s16 h10;
    u16 h12;
    s16 h14;
    u16 h16;
} S62D7C;

void func_80062D7C(s32 *arg0) {
    register s32 *s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 o asm("a1");
    register s32 w8 asm("v1");
    S62D7C s;
    s32 unused[4];
    s32 a2v;
    s32 prod;
    s32 w10;
    s32 *p;

    s0 = arg0;
    if ((s0[1] & 8) == 0) {
        goto else_path;
    }
    w8 = s0[2];
    s.h10 = ((volatile s32 *) s0)[3];
    s.h12 = ((u16 *) s0)[7];
    w10 = s0[4];
    s.h14 = w10;
    a2v = ((u16 *) s0)[9];
    prod = w10 * a2v;
    s1 = ((u32) w8 >> 2) + 2;
    *(volatile u16 *) &s.h16 = a2v;
    s.h16 = 1;
    s.h14 = prod;
    func_800248FC(&s, s0 + 5, a2v, prod);
    __asm__ volatile(".set\tnoreorder\n\tj D_80069E08\n\tsll %0,%1,2\n\t.set\treorder" : "=r"(o) : "r"(s1));
else_path:
    __asm__ volatile("li %0,2" : "=r"(s1));
    p = (s32 *) ((s1 << 2) + (s32) s0);
    s.h10 = ((volatile s32 *) p)[1];
    s.h12 = ((u16 *) p)[3];
    s.h14 = ((volatile s32 *) p)[2];
    s.h16 = ((u16 *) p)[5];
    func_800248FC(&s, (s32 *) ((char *) s0 + ((s1 << 2) + 12)));
    func_800246D4(0);
}

extern void func_80069F24(s32, s32, s32, s32);
extern void func_8006A174();
extern s32 D_8008FC04;

void func_80062E60(s32 arg0) {
    D_8008FC04 = 0;
    if (arg0 != 0) {
        goto else_path;
    }
    D_8004E5BC = 0;
    func_80069F24(0x153D6, 0x278A, 0x3DF, 0x2DE);
    __asm__ volatile("j D_80069EA4");
else_path:
    func_8006A174(0);
}

DEAD_TAIL_LW(3, D_8008FC04);

extern s32 D_8008FBEC[];
extern u8 D_800852C0[];
extern s32 D_80073F78[];

void func_80062EBC(void) {
    s32 idx;
    s32 off;
    s32 id;
    void (*fn)(u8 *);
    MEMORY_BARRIER();
    id = D_8008FBEC[idx];
    off = idx * 100;
    fn = (void (*)(u8 *)) D_80073F78[id];
    fn(D_800852C0 + off);
}

extern u8 D_80085324[];
extern u8 D_80085328[];
extern s32 D_8008FBF0[];

void func_80062F24(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s0;
    s32 s1;
    s32 t;
    s32 off;

    s0 = a0;
    s1 = a1;
    func_80067320(a0, a2, a3, 0x76);
    D_8008E53C &= -0x41;
    t = D_8008FC04;
    off = t * 100;
    *(s32 *) (D_80085324 + off) = s0;
    *(s32 *) (D_80085328 + off) = s1;
    D_8008FBF0[t] = 0;
    D_8008FC04 = t + 1;
}

DEAD_TAIL_LW(2, D_8008E53C);

extern void func_800675BC();

void func_80062FE0(s32 *arg0) {
    s32 flag;
    s32 t0;
    s32 t1;

    if (flag & 2) {
        if (D_800855A4 & 0x800) {
            func_800675BC(0);
            func_80024638(0);
            D_8008E53C |= 0x40;
        } else {
            return;
        }
    }
    t0 = arg0[0];
    t1 = arg0[1];
    D_8008FC04 -= 1;
    func_8006A174(t0 + t1);
}

void func_80063074(s32 arg0, s32 arg1, s32 arg2) {
    s32 v1;

    func_80067320(arg0, arg2, -1, 0x94);
    D_8008E53C &= -0x41;
    v1 = D_8008FC04;
    D_8008FBF0[v1] = 1;
    D_8008FC04 = v1 + 1;
}

DEAD_TAIL_LW(2, D_8008E53C);

void func_800630E8(void) {
    s32 flag;
    s32 t;

    if (flag & 2) {
        goto else_path;
    }
    func_80024638(0);
    D_800856F4 = 0;
    t = D_8008E53C | 0x40;
    D_8008E53C = t;
    D_8008FC04 -= 1;
    D_8008E53C = t ^ 1;
    __asm__ volatile("j D_8006A164");
else_path:
    if (D_800855A4 & 0x800) {
        func_800675BC(1);
    }
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80063174);

void func_80063578(s32 *arg0) {
    s32 m;
    s32 w;

    m = ~0x10;
    w = arg0[1] * 0x24;
    *(s32 *) (D_80085D04 + w) = *(s32 *) (D_80085D04 + w) & m;
    w = arg0[2] * 0x24;
    *(s32 *) (D_80085D04 + w) = *(s32 *) (D_80085D04 + w) & m;
    w = arg0[3] * 0x24;
    *(s32 *) (D_80085D04 + w) = *(s32 *) (D_80085D04 + w) & m;
    w = arg0[4] * 0x24;
    *(s32 *) (D_80085D04 + w) = *(s32 *) (D_80085D04 + w) & m;
}

void func_80063670(s32 *arg0) {
    s32 v0;
    s32 v1;

    v0 = arg0[1];
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) (D_80085D04 + v1);
    v0 |= 0x10;
    *(s32 *) (D_80085D04 + v1) = v0;

    v0 = arg0[2];
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) (D_80085D04 + v1);
    v0 |= 0x10;
    *(s32 *) (D_80085D04 + v1) = v0;

    v0 = arg0[3];
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) (D_80085D04 + v1);
    v0 |= 0x10;
    *(s32 *) (D_80085D04 + v1) = v0;

    v0 = arg0[4];
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) (D_80085D04 + v1);
    v0 |= 0x10;
    *(s32 *) (D_80085D04 + v1) = v0;
}

DEAD_TAIL_LW(2, D_80085CAC);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80063770);

extern u8 D_80085340[];
extern u8 D_80085344[];
extern u8 D_80085D08[];
extern u8 D_80085D10[];
extern u8 D_80085D18[];
extern s32 func_800696C8(void *, void *, s32);
extern s32 func_80018058(s32, s32 *, s32);

void func_80063EF8(s32 arg2) {
    s32 i = 0;
    u8 *b24 = D_80085324;
    u8 *bd04 = D_80085D04;
    u8 *bd0418 = D_80085D04 + 0x18;
    s32 s1 = 0x1E;
    volatile s32 pad[2];
    s32 offA;
    s32 a1v;
    s32 voff;
    s32 a2v;

    do {
        s32 v0 = func_800696C8(D_80085F44, &D_80085FC4, a2v);
        a1v = i * 4;
        a2v = i + 7;
        i++;
        offA = (D_8008FC04 * 25) << 2;
        a1v += offA + (s32) b24;
        voff = (v0 * 9) << 2;
        *(s32 *) a1v = v0;
        *(s32 *) (D_80085D0C + voff) = 4;
        *(s32 *) (D_80085D08 + voff) = a2v;
        *(s32 *) ((u8 *) voff + (s32) bd04 + 0x10) = 0;
        *(s32 *) (D_80085D10 + voff) = 0;
        {
            s32 *w18 = (s32 *) (voff + (s32) bd0418);
            w18[1] = s1;
            w18[0] = -0x14;
        }
        s1 += 0xC;
    } while (i < 3);
    *(s32 *) (D_80085344 + offA) = 0;
    {
        s32 ret = func_80018058(offA, a1v, a2v);
        register s32 fc2 asm("a0") = D_8008FC04;
        s32 offB;
        s32 r4;
        s32 bv;
        s32 v1k;
        register s32 nine asm("v1");
        s32 voff2;
        s32 foff;

        offB = (fc2 * 25) << 2;
        *(s32 *) (D_80085340 + offB) = ret;
        r4 = ret * 4;
        bv = offB + (s32) D_80085324;
        v1k = *(s32 *) (r4 + bv);
        foff = fc2 << 2;
        D_8008FC04 = fc2 + 1;
        voff2 = (v1k * 9) << 2;
        nine = 9;
        *(s32 *) (D_80085D18 + voff2) = nine;
        MEMORY_BARRIER();
        *(s32 *) ((u8 *) D_8008FBF0 + foff) = 3;
    }
}

extern s32 D_800473AC;
extern u8 D_80085338[];
extern void func_80017F6C(s32);
extern void func_80043FF8(s32);
extern s32 func_80068268(s32);
extern void func_8006A578(void *, s32);

struct B_800640A4 {
    char pad[0x1C];
    s32 unk1C;
    s32 unk20;
};

void func_800640A4(struct B_800640A4 *arg0) {
    s32 s0 = (s32) arg0;
    s32 s1 = 2;
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 loaded asm("v1");

    if (*(s32 *) (s0 + 0x20) != s1) {
        goto not2_path;
    }
    a1 = D_8008FC04 - 1;
    v0 = (s32) D_800852C0;
    a0 = a1 * 100 + v0;
    v1 = D_80085FC4 - 3;
    D_80085FC4 = v1;
    D_8008FC04 = a1;
    v0 = D_800852A0 - 3;
    D_800852A0 = v0;
    func_8006A578((void *) a0, a1);
    v1 = D_8008FC04 - 1;
    v0 = v1 * 100;
    *(s32 *) (D_80085338 + v0) = 0;
    __asm__ volatile("j D_8006B340");
not2_path:
    v0 = D_800855A4;
    if (v0 & 0x820) {
        register s32 customizedOptions asm("a1");
        a0 = ((struct B_800640A4 *) s0)->unk1C;
        func_80017F6C(a0);
        a2 = 0xFF9FFFFF;
        a0 = 1;
        KEEP(a0);
        customizedOptions = (s32) &D_800473AC;
        v1 = *(s32 *) customizedOptions;
        v0 = ((struct B_800640A4 *) s0)->unk1C;
        v1 &= a2;
        v0 &= 3;
        v0 <<= 21;
        v1 |= v0;
        __asm__ volatile(".set\tnoreorder\n\tj D_8006B1D8\n\tsw %1,0(%0)\n\t.set\treorder"
                         : : "r"(customizedOptions), "r"(v1) : "memory");
    }
not820_path:
    v0 = D_800855A4;
    a0 = 2;
    if (v0 & 0x40) {
        func_80043FF8(a0);
        __asm__ volatile(".set\tnoreorder\n\tj D_8006B340\n\tsw %1,0x20(%0)\n\t.set\treorder"
                         : : "r"(s0), "r"(s1) : "memory");
    }
    v0 = func_80068268(0x1000);
    if (v0 != 0) {
        v0 = ((struct B_800640A4 *) s0)->unk1C;
        v1 = *(s32 *) (s0 + v0 * 4);
        v0 = v1 * 0x24;
        *(s32 *) (D_80085D18 + v0) = 0;
        v0 = ((struct B_800640A4 *) s0)->unk1C - 1;
        ((struct B_800640A4 *) s0)->unk1C = v0;
        if (v0 < 0) {
            ((struct B_800640A4 *) s0)->unk1C = 2;
        }
        v0 = ((struct B_800640A4 *) s0)->unk1C;
        loaded = *(s32 *) (s0 + v0 * 4);
        v0 = loaded * 0x24;
        *(s32 *) (D_80085D18 + v0) = 9;
        func_80043FF8(3);
    }
    v0 = func_80068268(0x4000);
    if (v0 != 0 || (D_800855A4 & 0x100)) {
        v0 = ((struct B_800640A4 *) s0)->unk1C;
        v1 = *(s32 *) (s0 + v0 * 4);
        v0 = v1 * 0x24;
        *(s32 *) (D_80085D18 + v0) = 0;
        v0 = ((struct B_800640A4 *) s0)->unk1C + 1;
        ((struct B_800640A4 *) s0)->unk1C = v0;
        if (v0 >= 3) {
            ((struct B_800640A4 *) s0)->unk1C = 0;
        }
        v0 = ((struct B_800640A4 *) s0)->unk1C;
        v1 = *(s32 *) (s0 + v0 * 4);
        v0 = v1 * 0x24;
        *(s32 *) (D_80085D18 + v0) = 9;
        func_80043FF8(3);
    }
tail_path:
    return;
}

struct S64358_100 {
    s32 f0;
    char p[96];
};

extern void func_80018240(s32, s32);
extern void func_80043F88(s32);
extern void func_80067E68(s32);
extern void func_80069C38(void);
extern void func_8006D7AC(s32, s32, s32);
extern s32 D_80070CB4;
extern struct S64358_100 D_80085334[];

void func_80064358(void) {
    s32 v1;
    s32 unused[4];

    func_80018240(0, 1);
    func_80043F88(0x22);
    func_80018240(0x3FFF, 5);
    func_80069C38();
    func_80069CC8(1, D_800855A8);
    func_80069A34();
    func_8006D7AC(0xC, 3, D_80070CB4);
    func_80067E68(0x20);
    v1 = D_8008FC04;
    D_80085334[v1].f0 = 0;
    D_8008FBF0[v1] = 4;
    D_8008FC04 = v1 + 1;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80064420);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_8006463C);

extern s32 D_80087030;
extern s32 D_801531D8;
extern s32 func_800697B0(void *, void *);
extern void func_8006C8A8(s32, void *);
extern void func_8006C96C(s32, s32, s32, s32);
extern void func_800E4668(u16 *, u16 *, s32);
extern u8 D_800860B4[];

struct H64990x {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
};

void func_80064990(struct H64990x *arg0) {
    volatile s32 sp10;
    volatile s32 pad0;
    s32 s0v;
    s32 s1v;
    s32 *s2p;
    register s32 s3v asm("s3");
    register s32 s4v asm("s4");
    register s32 s5v asm("s5");
    s32 id;
    s32 off;
    u32 *p;
    volatile u16 sp18;
    volatile u16 sp1A;
    volatile u16 sp1C;
    volatile u16 sp1E;
    volatile s32 sp20;
    volatile s32 sp24;
    volatile u16 sp28;
    u16 h28;
    volatile u16 sp2A;
    s32 pad[2];
    s5v = (s32) arg0;
    id = func_800697B0(&D_80085F44, &D_80085FC4);
    __asm__ __volatile__(".set push\n\t"
                         ".set\tnoreorder\n\t"
                         "addu $4,$17,$zero\n\t"
                         "addu $7,$zero,$zero\n\t"
                         "ori $2,$zero,0x40\n\t"
                         "sw $17,12($21)\n\t"
                         "sh $2,0x1a($sp)\n\t"
                         "ori $2,$zero,0x50\n\t"
                         "sh $2,0x1c($sp)\n\t"
                         "ori $2,$zero,0x20\n\t"
                         "lui $19,0x8008\n\t"
                         "addiu $19,$19,0x7030\n\t"
                         "sh $zero,0x18($sp)\n\t"
                         "sh $2,0x1e($sp)\n\t"
                         "sw $19,0x10($sp)\n\t"
                         "lhu $3,0x18($sp)\n\t"
                         "lhu $5,0x1a($sp)\n\t"
                         "lhu $8,0x1c($sp)\n\t"
                         "lhu $6,0x1e($sp)\n\t"
                         "sll $5,$5,0x10\n\t"
                         "or $5,$3,$5\n\t"
                         "sll $6,$6,0x10\n\t"
                         "jal func_8006C750\n\t"
                         "or $6,$8,$6\n\t"
                         ".set\treorder\n\t"
                         ".set pop\n\t"
                         : : : "$2", "$3", "$4", "$5", "$6", "$7", "$8",
                               "$9", "$10", "$11", "$12", "$13", "$14",
                               "$15", "$24", "$25", "$30", "$31", "memory");
    s0v = arg0->f20;
    s0v += 0xB802;
    func_800E4668(&sp28, &sp2A, func_800E6EDC(s0v));
    h28 = sp28;
    s4v = 8;
    sp24 = s4v;
    sp20 = 0x1C - ((s16) h28 / 2);
    s2p = &D_801531D8;
    *s2p = s0v;
    sp10 = s3v;
    func_8006C96C(id, 0xB801, sp20, sp24);
    sp20 = 0x30;
    sp24 = s4v;
    *s2p = *(volatile s32 *) &arg0->f24;
    sp10 = s3v;
    func_8006C96C(id, 0xB802, sp20, sp24);
    func_8006C8A8(id, (void *) s3v);
    p = (u32 *) D_800860B4;
    off = id;
    off <<= 3;
    off -= id;
    off <<= 3;
    p = (u32 *) ((u8 *) p + off);
    p[1] = -0x10;
    p[0] = (s32) - ((s16) sp1C / 2);
    *(s32 *) (D_800860A4 + off) = 4;
    __asm__(".set push\n.set noreorder\n"
            "lui $1,0x8008\n"
            "addiu $1,$1,0x6098\n"
            "addu $1,$1,$4\n"
            "lw $2,0($1)\n"
            "addiu $3,$0,-257\n"
            "and $2,$2,$3\n"
            "lui $1,0x8008\n"
            "addiu $1,$1,0x6098\n"
            "addu $1,$1,$4\n"
            "sw $2,0($1)\n"
            ".set pop\n");
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80064B74);

extern u8 D_80085D25[];
extern u8 D_80085D26[];

struct S64BF8 {
    char pad[0x18];
    s32 f18;
};

void func_80064BF8(s32 *arg0, s32 arg1) {
    s32 v1;
    register u8 *b98 asm("a2");
    s32 unused[6];
    s32 sc;

    D_80085D25[v1 * 36] = (u8) arg1;
    v1 = arg0[1];
    MEMORY_BARRIER();
    b98 = D_80086098;
    MEMORY_BARRIER();
    D_80085D26[v1 * 36] = (u8) arg1;
    v1 = arg0[3];
    arg1 = arg0[0];
    sc = v1 * 56;
    v1 = arg0[2];
    ((struct S64BF8 *) (b98 + sc))->f18 = 0;
    ((struct S64BF8 *) (b98 + v1 * 56))->f18 = 0;
    *(s32 *) (D_80085D18 + arg1 * 36) = 0;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80064C9C);

extern s32 D_800860B0[];

void func_80064DB4(s32 arg0, s32 arg1) {
    s32 v1;
    s32 unused[6];

    D_800860B0[v1 * 0xE] = arg1;
}

extern u8 D_80073F33[];
extern u8 D_80085D1C[];
extern void func_8006B990(void *);
extern void func_8006BC9C(void *);
extern void func_8006C0D0();

struct F64DE0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    char pad[0x10];
    s32 f20;
    s32 f24;
    s32 f28;
};

void func_80064DE0(struct F64DE0 *arg0) {
    s32 s0v = (s32) arg0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0v asm("a0");

    v0 = ((struct F64DE0 *) s0v)->fc;
    v1 = v0 << 3;
    v1 -= v0;
    v1 <<= 3;
    v0 = *(s32 *) (D_80086098 + v1);
    if (v0 & 0x100) {
        goto end;
    }
    v0 = D_800855A4;
    if (!(v0 & 0x820)) {
        goto normal_820;
    }
    a0v = 1;
    func_80043FF8(a0v);
    a0v = s0v;
    func_8006BC9C((void *) a0v);
    func_8006C0D0();
    __asm__ volatile("j D_8006C0BC");

normal_820:
    a0v = 0x1000;
    v0 = func_80068268(a0v);
    if (v0 == 0) {
        goto path_4ef0;
    }
    v0 = ((struct F64DE0 *) s0v)->f28;
    if (v0 != 0) {
        goto path_4ecc;
    }
    v1 = ((struct F64DE0 *) s0v)->f24;
    a0v = ((struct F64DE0 *) s0v)->f20;
    v1 += 1;
    ((struct F64DE0 *) s0v)->f24 = v1;
    v0 = *(u8 *) (D_80073F33 + a0v);
    v0 = (s32) v0 < v1;
    if (v0 == 0) {
        goto path_4fac;
    }
    v0 = a0v + 1;
    ((struct F64DE0 *) s0v)->f20 = v0;
    if (v0 >= 0xD) {
        v0 = 1;
        ((struct F64DE0 *) s0v)->f20 = v0;
    }
    v0 = 1;
    __asm__ volatile(".set\tnoreorder\n\tj D_8006BFAC\n\tsw %0,0x24(%1)\n\t.set\treorder"
                     : : "r"(v0), "r"(s0v) : "memory");

path_4ecc:
    v0 = ((struct F64DE0 *) s0v)->f20;
    v0 += 1;
    ((struct F64DE0 *) s0v)->f20 = v0;
    if (v0 < 0xD) {
        goto path_4f7c;
    }
    v0 = 1;
    __asm__ volatile(".set\tnoreorder\n\tj D_8006BF7C\n\tsw %0,0x20(%1)\n\t.set\treorder"
                     : : "r"(v0), "r"(s0v) : "memory");

path_4ef0:
    a0v = 0x4000;
    v0 = func_80068268(a0v);
    if (v0 == 0) {
        goto path_4fe4;
    }
    v0 = ((struct F64DE0 *) s0v)->f28;
    if (v0 != 0) {
        goto path_4f60;
    }
    v0 = ((struct F64DE0 *) s0v)->f24;
    v0 -= 1;
    ((struct F64DE0 *) s0v)->f24 = v0;
    if (v0 <= 0) {
        v0 = ((struct F64DE0 *) s0v)->f20;
        v0 -= 1;
        ((struct F64DE0 *) s0v)->f20 = v0;
        if (v0 <= 0) {
            v0 = 0xC;
            ((struct F64DE0 *) s0v)->f20 = v0;
        }
        goto path_4f40;
    }
    goto path_4fac;

path_4f40:
    v0 = ((struct F64DE0 *) s0v)->f20;
    v0 = *(u8 *) (D_80073F33 + v0);
    __asm__ volatile(".set\tnoreorder\n\tj D_8006BFAC\n\tsw %0,0x24(%1)\n\t.set\treorder"
                     : : "r"(v0), "r"(s0v) : "memory");

path_4f60:
    v0 = ((struct F64DE0 *) s0v)->f20;
    v0 -= 1;
    ((struct F64DE0 *) s0v)->f20 = v0;
    if (v0 <= 0) {
        v0 = 0xC;
        ((struct F64DE0 *) s0v)->f20 = v0;
    }
    goto path_4f7c;

path_4f7c:
    v0 = ((struct F64DE0 *) s0v)->f20;
    v1 = *(u8 *) (D_80073F33 + v0);
    v0 = ((struct F64DE0 *) s0v)->f24;
    if ((s32) v1 < v0) {
        ((struct F64DE0 *) s0v)->f24 = v1;
    }

path_4fac:
    D_80085FC4 -= 1;
    D_800852A8 -= 1;
    a0v = s0v;
    func_8006B990((void *) a0v);
    a0v = 3;
    func_80043FF8(a0v);

path_4fe4:
    v0 = D_800855A4;
    if (!(v0 & 0x8000)) {
        goto path_65050;
    }
    v0 = ((struct F64DE0 *) s0v)->f28;
    if (v0 != 0) {
        goto path_65050;
    }
    a0v = ((struct F64DE0 *) s0v)->f0;
    v0 = 1;
    ((struct F64DE0 *) s0v)->f28 = v0;
    v1 = a0v << 3;
    v1 += a0v;
    v1 <<= 2;
    v0 = *(s32 *) (D_80085D1C + v1);
    v0 -= 0x20;
    *(s32 *) (D_80085D1C + v1) = v0;
    a0v = 3;
    func_80043FF8(a0v);

path_65050:
    v0 = D_800855A4;
    if (!(v0 & 0x2000)) {
        goto end;
    }
    v0 = ((struct F64DE0 *) s0v)->f28;
    if (v0 == 0) {
        goto end;
    }
    v0 = ((struct F64DE0 *) s0v)->f0;
    ((struct F64DE0 *) s0v)->f28 = 0;
    v1 = v0 << 3;
    v1 += v0;
    v1 <<= 2;
    v0 = *(s32 *) (D_80085D1C + v1);
    v0 += 0x20;
    *(s32 *) (D_80085D1C + v1) = v0;
    a0v = 3;
    func_80043FF8(a0v);
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_800650D0);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_8006546C);

struct J658A8_B;

extern struct J658A8_B D_800860A8[];
extern u8 D_8008609C[];
extern u8 D_800860A0[];
extern u8 D_800860AC[];
extern u8 D_800860B8[];
extern u8 D_800860BC[];
extern void func_8010849C();

struct O65750 {
    s16 w0;
    s16 w1;
    s16 w2;
    s16 w3;
};

void func_80065750(s32 arg0, struct O65750 s, s32 arg3, s32 arg4) {
    s32 v0 = arg0 << 3;
    s32 t0;
    u8 *bb = D_800860BC;
    s32 v;
    s32 w1v;
    s32 *w;
    u8 *b2;

    v0 = v0 - arg0;
    t0 = v0 << 3;

    v = *(s32 *) (D_80086098 + t0);
    v &= ~0x1C;
    *(s32 *) (D_80086098 + t0) = v;
    *(s32 *) (D_800860B4 + t0) = s.w0 - 0x80;
    w1v = s.w1 - 0x78;
    w = (s32 *) (t0 + bb);
    *(s32 *) ((u8 *) D_800860A8 + t0) = arg3;
    *(s32 *) (D_800860B8 + t0) = w1v;
    w[1] = 0x1E0;
    {
        u8 *c8base = bb + 8;
        u8 *c8 = (u8 *) (t0 + c8base);
        w[0] = 0;
        *(struct O65750 *) c8 = s;
    }
    {
        s32 d = s.w0 / 4;
        s32 m;
        MEMORY_BARRIER();
        m = (arg3 << 6) + 0x180;
        d = d + m;
        *(s32 *) (D_8008609C + t0) = d;
    }
    {
        u8 *bb16 = bb + 0x10;
        b2 = (u8 *) (t0 + bb16);
    }
    *(s32 *) (D_800860A0 + t0) = s.w1;
    b2[0] = 0x80;
    b2[1] = 0x80;
    b2[2] = 0x80;
    *(s32 *) (D_800860AC + t0) = 0;
    func_8010849C(s.w2, s.w3, arg4);
}

struct J658A8_A {
    s16 f;
    char p[54];
};

struct J658A8_B {
    s32 f;
    char p[52];
};

struct J658A8_C {
    u16 f;
    char p[54];
};

extern struct J658A8_A D_800860C4[];
extern struct J658A8_C D_800860C6[];
extern struct J658A8_A D_800860C8[];
extern struct J658A8_C D_800860CA[];

void func_800658A8(s32 idx, s32 a1, s32 a2) {
    struct O65750 o;
    s32 t1;
    u32 t2;

    t1 = D_800860C4[idx].f / 4;
    t2 = D_800860A8[idx].f;
    o.w0 = t1 + ((t2 << 6) + 0x180);
    o.w1 = D_800860C6[idx].f;
    o.w2 = D_800860C8[idx].f / 4;
    o.w3 = D_800860CA[idx].f;
    func_800248FC(&o, a1, a2);
}

extern void func_800FE774();

struct S596C {
    u16 h0;
    u16 h2;
    s32 pad;
    s32 w8;
};

struct S8 {
    s32 x;
    s32 y;
};

void func_8006596C(s32 arg0, s32 arg1, struct S8 s, s32 arg4) {
    struct S596C st;
    s32 tx;
    s32 ty;

    tx = s.x;
    ty = s.y;
    st.h0 = tx;
    st.h2 = ty;
    st.w8 = D_800860C8[arg0].f;
    func_800FE774(arg1, arg4, &st);
}

struct Pair32 {
    s32 v0;
    s32 v4;
};

extern void func_800E4268();
extern s32 func_800E6EDC();

void func_800659C4(s32 arg0, struct Pair32 *arg1) {
    s16 sp12;
    s16 sp10;

    func_800E4268(&sp10, &sp12, func_800E6EDC());
    arg1->v0 = (s32) (((sp10 * 0xA) + 0x18) & 0xFFFC);
    arg1->v4 = (s32) ((sp12 * 0x10) + 0x10);
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80065A2C);

struct pair65b00 {
    s32 x;
    s32 y;
};

struct rec65b00 {
    s16 f0;
    s16 f1;
    s16 f2;
    u16 f3;
    s32 f4;
    s32 g4;
};

void func_80065B00(s32 arg0, struct rec65b00 a, s32 arg5) {
    s32 off;
    u8 *bb;
    u8 *bb8;
    u8 *bb10;
    s32 *b;
    s16 *q;
    u8 *r;
    s32 t;
    register s32 g5 asm("v1");

    off = arg0 * 0x38;
    t = *(s32 *) (D_80086098 + off);
    t = t & ~0x1C;
    g5 = arg5;
    t = t | g5;
    bb = D_800860BC;
    *(s32 *) (D_80086098 + off) = t;
    *(struct pair65b00 *) (bb + off) = *(struct pair65b00 *) &a.f4;
    *(s32 *) (D_8008609C + off) = a.f0;
    bb8 = bb + 8;
    *(s32 *) (D_800860A0 + off) = a.f1;
    q = (s16 *) (bb8 + off);
    q[0] = ((u16) a.f0 & 0x3F) * 2;
    q[1] = (u8) a.f1;
    bb10 = bb + 0x10;
    q[2] = a.f2 * 2;
    q[3] = a.f3;
    r = bb10 + off;
    r[0] = 0x80;
    r[1] = 0x80;
    r[2] = 0x80;
    *(s32 *) (D_800860AC + off) = 0;
}

extern s16 D_800852E8;
extern s16 D_800852EA;
extern s16 D_800852EC;
extern s16 D_800852EE;
extern s16 D_800852F0;
extern s16 D_800852F2;
extern s16 D_800852F4;
extern s16 D_800852F6;
extern s16 D_800852F8;
extern s16 D_800852FA;
extern s16 D_800852FC;
extern s16 D_800852FE;
extern s16 D_80085300;
extern s16 D_80085302;
extern s16 D_80085304;
extern s16 D_80085306;
extern s16 D_80085308;
extern void *D_8008530C;
extern s16 D_80085314;
extern void *D_80085318;
extern void *D_8008531C;
extern s16 D_80085320;
extern s16 D_80085322;
extern s16 D_80085578;
extern s16 D_8008557A;
extern s16 D_8008557C;
extern s16 D_8008557E;
extern s16 D_80085582;
extern s16 D_80085584;
extern s16 D_80085586;
extern void *D_80085588;
extern void *D_80085594;
extern u8 D_80073FB4[];
extern s16 D_8008E434[];
extern s32 D_8008FC0C;
extern s16 D_800855F4[];
extern u8 D_801097DC[];
extern void func_800FFF08();

void func_80065BF8(s32 arg0, s32 arg1, struct Pair32 *arg2, struct Pair32 *arg3) {
    register s32 keep0 asm("s1") = arg0;
    register u8 *t0b asm("t0") = (u8 *) &D_80085578;
    register s16 *s0b asm("s0") = &D_800852E8;
    register s32 v1v asm("v1") = *(volatile s32 *) &arg2->v0;
    register s32 a0v asm("a0");
    s32 a1v;
    s32 first;
    s32 a2u4;
    s32 one;
    u8 *p73;
    register s32 a3v asm("v0");
    s32 c100;
    s16 tv;

    KEEP_NOVOL(keep0);
    first = *(volatile s32 *) &arg2->v4;
    *(s16 *) t0b = first;
    a0v = *(volatile s32 *) &arg2->v4;
    D_8008557E = 4;
    D_8008557C = 4;
    D_80085584 = 2;
    D_80085586 = 2;
    D_80085588 = D_8008E434;
    D_80085594 = &D_800855F4;
    D_80085582 = 0;
    s0b[0] = 0x200;
    c100 = 0x100;
    SCHED_BARRIER();
    tv = (v1v + 0x18) & 0xFFFC;
    s0b[1] = c100;
    s0b[2] = tv;
    s0b[3] = 0;
    {
        register s32 diff asm("a1");
        diff = arg1 - a0v;
        D_8008557A = diff;
    }
    a3v = *(volatile s32 *) &arg3->v0;
    a3v -= 0x80;
    s0b[4] = a3v;
    SCHED_BARRIER();
    a3v = *(volatile s32 *) &arg3->v4;
    KEEP_NOVOL(a3v);
    a1v = (s32) &D_801097DC;
    USE2(a3v, a1v);
    s0b[6] = tv;
    s0b[7] = 0;
    s0b[8] = 0;
    s0b[9] = 0;
    s0b[10] = tv;
    s0b[11] = 0;
    s0b[12] = 0;
    s0b[13] = 0;
    s0b[14] = 0;
    SCHED_BARRIER();
    s0b[5] = a3v - 0x78;
    a2u4 = *(volatile s32 *) &arg2->v4;
    p73 = D_80073FB4;
    s0b[16] = 0;
    SCHED_BARRIER();
    D_8008530C = p73;
    one = 1;
    s0b[15] = a2u4;
    SCHED_BARRIER();
    D_80085314 = one;
    D_80085318 = t0b;
    D_8008531C = &D_8008FC0C;
    D_80085320 = 0;
    D_80085322 = 0;
    func_800FFD70(keep0, (void *) a1v);
    func_800FFF08(keep0, s0b, 0, 0);
}

extern u8 D_8008532C[];
extern u8 D_80085330[];
extern void func_80067E68();
extern void func_800F1330();

void func_80065DB4(void) {
    s32 four;
    s32 v1b;
    s32 v0;
    s32 a0v;

    func_80069CC8(1, D_800855A8);
    func_80069A34();
    {
        s32 v1 = 0;
        s16 *a1 = D_800855F4;
        s16 *a0 = D_8008E434;
        do {
            *a0 = v1 - 0x4000;
            *a1 = 0;
            a1++;
            v1++;
            a0++;
        } while (v1 < 0x60);
        func_800F1330(1, a1);
    }
    four = 4;
    D_8008E430 = 0x160;
    D_800855EC = four;
    D_8008E53C |= 0x400;
    func_80067E68(0x20);
    v1b = D_8008FC04;
    v0 = v1b << 1;
    v0 += v1b;
    v0 <<= 3;
    v0 += v1b;
    v0 <<= 2;
    a0v = v1b << 2;
    *(s32 *) (D_80085324 + v0) = 0;
    *(s32 *) (D_80085328 + v0) = 0;
    *(s32 *) (D_8008532C + v0) = 0;
    *(s32 *) (D_80085330 + v0) = four;
    *(s32 *) (D_80085324 + 16 + v0) = 0;
    D_8008FBF0[v1b] = 7;
    D_8008FC04 = v1b + 1;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80065EF0);

extern u8 D_800E4D9C;
extern u8 D_8016EE68;
extern void func_800E8698();
extern void func_800E8660(u8 *);

void func_80066264(s32 arg0, s32 arg1) {
    register s32 b asm("v1");
    s32 temp_a1;
    s32 v0;
    s32 t;

    b = D_8008FC04;
    t = b << 1;
    t += b;
    t <<= 3;
    t += b;
    t <<= 2;
    *(s32 *) (D_80085324 + t) = arg1;
    if (arg1 != 0) {
        func_800E8698();
        func_800E8660(&D_8016EE68);
    }
    func_800FFD70(2, &D_800E4D9C);
    func_800FFF08(2, 0x33, arg0, 0);
    b = D_8008FC04;
    temp_a1 = D_8008E430;
    D_8008E430 = -1;
    t = b << 1;
    t += b;
    t <<= 3;
    t += b;
    t <<= 2;
    *(s32 *) (D_80085328 + t) = temp_a1;
    func_80043FF8(0x12);
    v0 = D_8008FC04;
    D_8008FBF0[v0] = 8;
    D_8008FC04 = v0 + 1;
}

extern void func_800E86EC();
extern s32 func_800FFEEC(s32);

void func_80066360(struct Pair32 *arg0) {
    if (func_800FFEEC(2) == 0) {
        D_8008E430 = arg0->v4;
        D_8008FC04 -= 1;
        if (arg0->v0 != 0) {
            func_800E86EC();
        }
    }
}

void func_800663CC(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s0;
    s32 s1;
    s32 t;
    s32 off;

    s0 = a0;
    s1 = a1;
    func_80067320(a0, a2, -1, a3);
    D_8008E53C &= -0x41;
    t = D_8008FC04;
    off = t * 100;
    *(s32 *) (D_80085324 + off) = s0;
    *(s32 *) (D_80085328 + off) = s1;
    D_8008FBF0[t] = 0xB;
    D_8008FC04 = t + 1;
}

DEAD_TAIL_LW(2, D_8008E53C);

void func_80066488(void) {
    s32 flag;
    s32 t0;
    s32 t1;

    if (flag & 2) {
        goto else_path;
    }
    func_80024638(0);
    D_8004E5BC = 1;
    t0 = D_8008E53C | 0x40;
    t1 = D_8008FC04 - 1;
    D_8008E53C = t0;
    D_8008FC04 = t1;
    func_80069F24(0x153D6, 0x278A, 0x3DF, 0x2DE);
    __asm__ volatile("j D_8006D514");
else_path:
    if (D_800855A4 & 0x800) {
        func_800675BC(1);
    }
}

extern s32 func_8007077C();
extern void func_8006B358();
extern s32 func_800696C8_2(void *, void *) __asm__("func_800696C8");
extern u8 D_80085D14[];

void func_80066524(void) {
    register s32 i asm("a1");
    register u8 *p1 asm("v1");
    u8 *p0;
    register s32 v0 asm("v0");
    s32 x;
    register s32 t asm("v0");
    register s32 off asm("v1");
    register s32 fc asm("a0");
    s32 unused[2];

    t = func_8007077C();
    i = 0;
    if (t == 0) {
        goto else_path;
    }
    func_8006B358();
    __asm__ volatile("j D_8006D648");
else_path:
    p1 = (u8 *) D_800855A8;
    p0 = (u8 *) D_800C5A00;
    do {
        i += 1;
        *(s32 *) p0 = *(s32 *) p1;
        *(s32 *) p1 = 0;
        p1 += 4;
        p0 += 4;
    } while (i < 0x7800);
    func_80067E68(0x10);
    v0 = func_800696C8_2(D_80085F44, &D_80085FC4);
    off = v0 << 3;
    off += v0;
    off <<= 2;
    *(s32 *) (D_80085D08 + off) = 0x12;
    *(s32 *) (D_80085D14 + off) = 0;
    *(s32 *) (D_80085D10 + off) = 0;
    p1 = (u8 *) (off + (s32) D_80085D1C);
    fc = D_8008FC04;
    *(s32 *) p1 = -4;
    *(s32 *) (p1 + 4) = -0x10;
    x = fc << 1;
    x += fc;
    x <<= 3;
    x += fc;
    x <<= 2;
    *(s32 *) (D_80085324 + x) = 0;
    D_8008FBF0[fc] = 0xC;
    D_8008FC04 = fc + 1;
}

DEAD_TAIL_LW(2, D_80085CAC);

extern void func_80067E90(s32);
extern void func_8006B358(s32);

void func_80066660(s32 *arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 s0v asm("s0");

    s0v = (s32) arg0;
    v0 &= 4;
    if (v0 != 0) {
        goto end;
    }
    KEEP_WITH(s0v, a0);
    v0 = *(s32 *) s0v;
    if (v0 == 0) {
        goto zero_path;
    }
    v0 = D_800852A0;
    v1 = D_8008FC04;
    a0 = *(s32 *) s0v;
    v0 -= 1;
    D_800852A0 = v0;
    v0 = D_80085FC4;
    v1 -= 1;
    D_8008FC04 = v1;
    v0 -= 1;
    D_80085FC4 = v0;
    v0 = 1;
    if (a0 != v0) {
        v0 = 2;
        goto case2;
    }
    func_80024638(0);
    a1 = 0;
    a0 = (s32) D_800C5A00;
    v0 = D_8008E53C;
    v1 = D_800855A8;
    v0 |= 0x40;
    D_8008E53C = v0;
copy_loop:
    v0 = *(s32 *) a0;
    a0 += 4;
    a1 += 1;
    *(s32 *) v1 = v0;
    v1 += 4;
    if (a1 < 0x7800) {
        goto copy_loop;
    }
    func_8006A174(0, a1);
    TAIL_JUMP_NOP(D_8006D798);
case2:
    if (a0 != v0) {
        goto end;
    }
    func_8006B358(a0);
    TAIL_JUMP_NOP(D_8006D798);
zero_path:
    v1 = D_800855A4;
    v0 = v1 & 0x40;
    if (v0 == 0) {
        v0 = v1 & 0x820;
        goto check820;
    }
    func_80043FF8(2);
    func_80067E90(0x20);
    __asm__ volatile(".set\tnoreorder\n\tj D_8006D794\n\tori %0, $zero, 1\n\t.set\treorder"
                     : "=r"(v0));
check820:
    if (v0 == 0) {
        goto end;
    }
    func_80043FF8(1);
    func_80067E90(0x20);
    v0 = 2;
    *(s32 *) s0v = v0;
end:
    return;
}

extern u16 D_800855B4;
extern u16 D_800855B6;
extern u16 D_800855B8;
extern u16 D_800855BA;
extern u16 D_800855E2;
extern s32 D_800855E4;

void func_800667AC(s32 arg0, s32 arg1, s32 arg2) {
    s32 v0;

    v0 = 1;
    D_800855B4 = (u16) v0;
    v0 = 0x80;
    D_800855B8 = 0;
    D_800855BA = (u16) arg0;
    D_800855E4 = arg2;
    D_800855B6 = (u16) arg1;
    D_800855E2 = (u16) v0;
}

void D_800667EC(void) {
}

extern s32 D_8006DB54();
extern s32 D_8006DB64(s16, s16);
extern s32 D_8006DB6C();
extern s32 D_8006DB70(void *);
extern s32 D_8006D9C8(u8);
extern void func_8006DB84(s16);
extern void func_8006E068(s32);
extern void func_8006E13C();
extern s8 D_800854B4;
extern s16 D_800855BC;
extern s16 D_800855BE;
extern s16 D_800855C0;
extern s16 D_800855C2;
extern u16 D_800855E0;
extern void *D_800855E8;

s32 func_800667F4(void) {
    register u16 *s0 asm("s0") = (u16 *) &D_800855B4;
    register u16 value2 asm("v0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    s16 value;
    u8 type;
    u8 *p;
    register s32 idx asm("a0");
    s32 unused[4];

    func_8006E13C();
    v0 = s0[0];
    if (v0 & 0x20) {
        goto block_669e4;
    }
    v0 = D_800855A4;
    if ((v0 & 0x800) == 0) {
        goto block_66850;
    }
    func_80043FF8(0x85);
    v0 = s0[0];
    v0 |= 0x20;
    s0[0] = v0;

block_66850:
    v1 = s0[0];
    if (v1 & 0x20) {
        goto block_669e4;
    }
    if ((v1 & 0x10) == 0) {
        v0 = v1 & 8;
        goto block_668c4;
    }
    v0 = v1 & 8;
    value = D_800855E2;
    value -= 2;
    D_800855E2 = value;
    func_8006DB84(value);
    v0 = *(s16 *) &D_800855E2;
    if (v0 != 0) {
        v0 = 1;
        goto end_body;
    }
    v0 = s0[0];
    v1 = 0x80;
    D_800855E2 = v1;
    v0 = (v0 ^ 0x10) | 1;
    __asm__ volatile(".set\tnoreorder\n\tj D_8006DB6C\n\tsh %0,0(%1)\n\t.set\treorder"
                     : : "r"(v0), "r"(s0) : "memory");

block_668c4:
    if (v0 == 0) {
        v0 = v1 & 1;
        goto block_668f4;
    }
    v0 = D_800855A4;
    if (v0 & 0x20) {
        v0 = v1 ^ 8;
        v0 |= 0x10;
        s0[0] = v0;
        __asm__ volatile(".set\tnoreorder\n\tj D_8006DB54\n\tori %0,$zero,0x80\n\t.set\treorder"
                         : : "r"(v0) : "memory");
    } else {
        goto block_66b5c;
    }

block_668f4:
    if (v0 == 0) {
        goto block_669e4;
    }
    v1 ^= 1;
    a0 = *(s16 *) &D_800855B8;
    v0 = *(s16 *) &D_800855BA;
    s0[0] = v1;
    if (a0 == v0) {
        goto block_66b48;
    }
    v0 = v1 | 2;
    s0[0] = v0;
    v0 = a0 << 2;
    v0 = v0 + (s32) D_800855E4;
    p = *(u8 **) v0;
    D_800855E8 = p;
    D_800855BE = p[0];
    D_800855C0 = (s16) (((u32) * (s32 *) p & 0xF00) >> 2);
    D_800855C2 = (s16) ((((u32) * (s32 *) p) >> 4) & 0x100);
    v0 = 0x10;
    type = p[2];
    v1 = type & 0xF0;
    if (v1 == v0) {
        goto type10;
    }
    v0 = 0x20;
    if (v1 == v0) {
        goto type20;
    }
    TAIL_JUMP_NOP(D_8006D9C8);
type10:
    func_8006E068(type & 0xF);
    TAIL_JUMP_NOP(D_8006D9C8);
type20:
    func_80069A34();
    v0 = 1;
    D_800854B4 = (u8) v0;
    MEMORY_BARRIER();
    v1 = (s32) &D_800855B8;
    v0 = *(u16 *) v1;
    D_800855BC = 0;
    v0++;
    *(u16 *) v1 = v0;

block_669e4:
    a3 = (s32) &D_800855B4;
    v1 = *(u16 *) a3;
    if ((v1 & 2) == 0) {
        goto block_66ab8;
    }
    a0 = D_800855BC;
    a1 = D_800855BE;
    v0 = v1 ^ 2;
    *(u16 *) a3 = v0;
    if (a0 != a1) {
        goto block_66a30;
    }
    a0 = *(s16 *) &D_800855E2;
    v0 |= 9;
    __asm__ volatile(".set\tnoreorder\n\tj D_8006DB64\n\tsh %0,0(%1)\n\t.set\treorder"
                     : : "r"(v0), "r"(a3) : "memory");

block_66a30:
    if (a0 != 0) {
        goto block_66a98;
    }
    if (a1 <= 0) {
        goto block_66a98;
    }
    idx = 0;
    __asm__ volatile("" : "=r"(idx) : "0"(0));
    a2 = a3 + 0x10;
    a3 = a3 + 0x1E;
    a1 = a3;
    do {
        v0 = (s32) D_800855E8;
        v1 = idx << 2;
        v0 = v1 + v0;
        v0 = *(u8 *) (v0 + 5);
        *(u16 *) a1 = v0;
        v0 = (s32) D_800855E8;
        idx++;
        v1 += v0;
        v0 = *(u8 *) (v1 + 4);
        a1 += 2;
        *(u16 *) a2 = v0;
        v0 = *(s16 *) (a3 - 0x14);
        a2 += 2;
    } while (idx < v0);

block_66a98:
    v0 = (s32) &D_800855BC;
    v1 = *(u16 *) v0;
    a0 = -0x10;
    D_800855E0 = a0;
    v1++;
    *(u16 *) v0 = v1;

block_66ab8:
    a0 = (s32) &D_800855E0;
    v1 = D_800855BC;
    value2 = *(u16 *) a0;
    *(u16 *) a0 = (value2++, value2);
    v1 <<= 1;
    KEEP_WITH(a0, v1);
    a0 = a0 + v1;
    v1 = *(s16 *) (a0 - 0x10);
    if ((s16) value2 != v1) {
        goto block_66b08;
    }
    v0 = D_800855B4;
    v0 |= 2;
    D_800855B4 = v0;

block_66b08:
    v0 = D_800855B4;
    if ((v0 & 0x20) == 0) {
        goto block_66b5c;
    }
    v0 = *(s16 *) &D_800855E2;
    v1 = v0;
    if (v0 == 0) {
        v0 = *(u8 *) &D_800854B4;
        if (v0 != 0) {
            goto block_66b5c;
        }
block_66b48:
        __asm__ volatile(".set\tnoreorder\n\tj D_8006DB70\n\taddu %0,$zero,$zero\n\t.set\treorder"
                         : : "r"(v0) : "memory");
    }

block_66b50:
    v0 = v1 - 2;
    D_800855E2 = v0;

block_66b5c:
    a0 = *(s16 *) &D_800855E2;
    func_8006DB84(a0);
end_body:
    return 1;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80066B84);

extern s8 D_800854B5;
extern u8 D_800854B6[];
extern u16 *D_8008556C;
extern u16 *D_80085570;
extern u16 *D_80085574;

void func_80067068(s32 arg0) {
    register u16 *p6c asm("a1");
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 row_base;
    s32 temp_v1;

    p6c = D_800C5A00;
    D_8008556C = p6c;
    D_80085570 = D_800EDA00;
    D_80085574 = (u16 *) (D_800855A8 + 0x5600);
    func_80069CC8(arg0 + 2);
    var_a2 = 0;
    var_a3 = 0;
    do {
        var_a1 = 0;
        row_base = var_a2 << 8;
loop_2:
        __asm__("" : "=r"(temp_v1) : "r"(var_a3 + var_a1));
        D_80085570[temp_v1] = D_80085574[row_base + var_a1];
        var_a1 += 1;
        if (var_a1 < 0xD2) {
            goto loop_2;
        }
        D_800854B6[var_a2] = 0;
        var_a2 += 1;
        var_a3 += 0xD2;
    } while (var_a2 < 0xB4);
    D_800854B4 = 0;
    D_800854B5 = 0;
}

void func_8006713C(void) {
    register s32 v0 asm("v0");
    register u32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register u32 a3 asm("a3");
    register s32 t0 asm("t0");
    register s32 t1 asm("t1");
    register s32 t2 asm("t2");
    register s32 t3 asm("t3");
    register u8 *p4 asm("t4");
    register s32 t5 asm("t5");
    register s32 t6x asm("t6");
    register s32 t7 asm("t7");
    register s32 t8 asm("t8");
    register s16 t9 asm("t9");

    v1 = (s32) &D_800854B4;
    v0 = *(u8 *) v1;
    if (v0 == 0) {
        goto end;
    }
    v0 = *(u8 *) &D_800854B5;
    t3 = v0 - 0x11;
    v0 = t3 < (s32) v0;
    if (v0 == 0) {
        goto block_15;
    }
    v0 = v1 + 2;
    t8 = 0xB3;
    p4 = (u8 *) (v0 + t3);
outer:
    v0 = (u32) t3 < 0xB4U;
    if (v0 == 0) {
        goto outer_end;
    }
    a0 = t8 - t3;
    t2 = 0;
    KEEP(t2);
    v1 = a0 << 3;
    v1 -= a0;
    v0 = v1 << 4;
    v0 -= v1;
    t7 = v0 << 1;
    v0 = *p4;
    KEEP(v0);
    t6x = a0 << 8;
    t5 = v0 & 0xFF;
    v0 += 1;
    *p4 = v0;
    v0 = t7 + t2;
inner:
    v0 <<= 1;
    v1 = (s32) D_8008556C;
    a0 = (s32) D_80085570;
    v1 = v0 + v1;
    v0 = v0 + a0;
    v1 = *(u16 *) v1;
    a3 = *(u16 *) v0;
    if (v1 == a3) {
        goto equal;
    }
    a0 = 0;
    t1 = 2;
compare:
    v0 = a0 & 0xFFFF;
    t0 = v0 >> 5;
    a1 = v1 & 0x1F;
    a2 = a3 & 0x1F;
    MEMORY_BARRIER();
    v0 = a1;
    a0 = a2;
    if (v0 == a0) {
        goto equal_bits;
    }
    v0 = v0 - a0;
    v0 <<= 24;
    v0 >>= 16;
    KEEP(v0);
    if (v0 < 0) {
        v0 += 0xF;
    }
    v0 >>= 4;
    t9 = v0 * t5;
    v0 = t9;
    v0 = (v0 << 16) >> 16;
    if (v0 < 0) {
        v0 += 0xFF;
    }
    v0 >>= 8;
    v0 = a2 + v0;
    __asm__ volatile(
        ".set\tnoreorder\n\tj D_8006E250\n\tsll %0, %0, 10\n\t.set\treorder"
        : "=r"(v0)
        : "0"(v0)
        : "memory");
equal_bits:
    v0 = a1 << 10;
    a0 = t0 | v0;
    KEEP(a0);
    v1 >>= 5;
    t1--;
    a3 >>= 5;
    if (t1 >= 0) {
        goto compare;
    }
    __asm__ volatile(
        ".set\tnoreorder\n\tj D_8006E274\n\taddu %0, %1, %2\n\t.set\treorder"
        : "=r"(v1), "=r"(t6x), "=r"(t2)
        : "1"(t6x), "2"(t2)
        : "memory");
equal:
    a0 = v1;
    v1 = t6x + t2;
    t2++;
    v0 = (s32) D_80085574;
    v1 <<= 1;
    v1 += v0;
    v0 = a0 | (a3 & 0x8000);
    *(u16 *) v1 = v0;
    if (t2 < 0xD2) {
        v0 = t7 + t2;
        goto inner;
    }
    v0 = t7 + t2;
outer_end:
    v0 = *(u8 *) &D_800854B5;
    t3++;
    v0 = t3 < (s32) v0;
    p4++;
    if (v0 != 0) {
        goto outer;
    }
block_15:
    v1 = (s32) &D_800854B5;
    v0 = *(u8 *) v1;
    v0++;
    *(u8 *) v1 = v0;
    v0 &= 0xFF;
    v0 = (u32) v0 < 0xC5U;
    if (v0 == 0) {
        *(u8 *) &D_800854B4 = 0;
    }
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_800672F0);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067320);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067484);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_800675BC);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067620);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_8006768C);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_800676F8);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_800677E0);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_800678B0);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_8006792C);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_800679A0);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067B38);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067B9C);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067BD0);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067C1C);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067D84);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067E68);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067E90);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80067EB8);

extern s32 D_8008E560;
extern s32 D_8008E564;
extern s32 D_8008E568;
extern s32 D_8008E578;
extern u32 D_8006F1B0;

/* Two cross-function tail transfers with live delay slots:
     0x80068140  beqz v1, func_80068220   (nop)
     0x80068178  j    D_8006F1B0         (addu v0,v0,a1)
   and the body falls through into func_80068220's `jr ra` at 0x80068220
   instead of carrying an epilogue of its own.  GCC 2.6.0-psx never
   sibling-calls, so none of the three is expressible in C; the block is
   written out and the frame-slot / global traffic it performs is exactly
   the C it would have been. */

void func_80068134(void) {
    __asm__ __volatile__(".set push\n\t"
                         ".set\tnoreorder\n\t"
                         "lui $3,0x8009\n\t"
                         "lw $3,-6816($3)\n\t"
                         "nop\n\t"
                         "beqz $3,func_80068220\n\t"
                         "nop\n\t"
                         "blez $3,.L80068180\n\t"
                         "nop\n\t"
                         "lui $2,0x8009\n\t"
                         "lw $2,-6812($2)\n\t"
                         "nop\n\t"
                         "addu $5,$3,$2\n\t"
                         "andi $3,$5,0xFF\n\t"
                         "lui $2,0x8009\n\t"
                         "lw $2,-6808($2)\n\t"
                         "sra $5,$5,8\n\t"
                         "lui $1,0x8009\n\t"
                         "sw $3,-6812($1)\n\t"
                         "j D_8006F1B0\n\t"
                         "addu $2,$2,$5\n\t"
                         ".L80068180:\n\t"
                         "lui $2,0x8009\n\t"
                         "lw $2,-6812($2)\n\t"
                         "nop\n\t"
                         "subu $5,$2,$3\n\t"
                         "andi $3,$5,0xFF\n\t"
                         "lui $2,0x8009\n\t"
                         "lw $2,-6808($2)\n\t"
                         "sra $5,$5,8\n\t"
                         "lui $1,0x8009\n\t"
                         "sw $3,-6812($1)\n\t"
                         "addu $2,$2,$5\n\t"
                         "negu $5,$5\n\t"
                         "lui $1,0x8009\n\t"
                         "sw $2,-6808($1)\n\t"
                         "addu $6,$zero,$zero\n\t"
                         "lui $3,0x8009\n\t"
                         "addiu $3,$3,-6792\n\t"
                         "addiu $4,$3,16\n\t"
                         ".L800681C8:\n\t"
                         "lw $2,0($3)\n\t"
                         "nop\n\t"
                         "andi $2,$2,1\n\t"
                         "beqz $2,.L8006820C\n\t"
                         "nop\n\t"
                         "lw $2,0($4)\n\t"
                         "nop\n\t"
                         "addu $2,$2,$5\n\t"
                         "sw $2,0($4)\n\t"
                         "addiu $2,$2,-16\n\t"
                         "sltiu $2,$2,0xF1\n\t"
                         "bnez $2,.L8006820C\n\t"
                         "nop\n\t"
                         "lw $2,0($3)\n\t"
                         "nop\n\t"
                         "xori $2,$2,1\n\t"
                         "sw $2,0($3)\n\t"
                         ".L8006820C:\n\t"
                         "addiu $3,$3,0x164\n\t"
                         "addiu $6,$6,1\n\t"
                         "slti $2,$6,0x10\n\t"
                         "bnez $2,.L800681C8\n\t"
                         "addiu $4,$4,0x164\n\t"
                         ".set\treorder\n\t"
                         ".set pop\n\t"
                         : : : "$1", "$2", "$3", "$4", "$5", "$6",
                               "$7", "$8", "$9", "$10", "$11", "$12",
                               "$13", "$14", "$15", "$24", "$25", "$30",
                               "memory");
}

__asm__(".globl func_80068220\nfunc_80068220 = .");

DEAD_TAIL_LW(2, D_8008E548);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068230);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068268);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068384);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068420);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_8006854C);

s32 func_80068598(s32 arg0) {
    u32 v1;
    u32 v0;

    v1 = arg0 - 0x30;
    if (v1 < 10) {
        return v1;
    }
    v0 = arg0 - 0x41;
    if (v0 < 6) {
        return arg0 - 0x37;
    }
    v0 = arg0 - 0x61;
    if (v0 < 6) {
        return arg0 - 0x57;
    }
    return 0;
}

extern s32 D_8008FBCC;
extern s32 D_8008FBD0;
extern s32 D_8008FBD4;
extern u8 D_80085FCC[];
extern u8 D_80085FCD[];
extern u8 D_80085FCE[];

void func_800685D4() {
    register s32 negv asm("at");

    s32 t0v;
    s32 v1v;
    s32 v0v;
    s32 a3v;
    s32 a2v;
    s32 a1v;
    s32 a0v;
    a3v = (s32) &D_8008E548;
    a2v = *(volatile s32 *) a3v;
    v0v = a2v & 0x40;
    KEEP(v0v);
    __asm__(".globl func_800685EC\nfunc_800685EC = . + 4");
    __asm__ volatile(".word 0x10400021\naddiu $sp,$sp,-0x10");
    v0v = D_8008FBCC;
    v1v = D_8008FBD0;
    a1v = v0v + 1;
    v0v = a1v << 7;
    __asm__ volatile(".word 0x0043001a");
    if (v1v == 0) {
        __asm__ volatile(".word 0x0007000d");
    }
    MEMORY_BARRIER();
    negv = -1;
    if (v1v == negv) {
        negv = (s32) 0x80000000;
        if (v0v == negv) {
            __asm__ volatile(".word 0x0006000d");
        }
    }
    __asm__ volatile("mflo $a0");

    __asm__(".globl func_80068638\nfunc_80068638 = . + 4");
    D_8008FBCC = a1v;
    v0v = a0v < 0x81;
    if (v0v == 0) {
        a0v = 0x80;
    }
    D_8008FBD4 = a0v;
    v0v = a1v < v1v;
    if (v0v != 0) {
        goto l68670;
    }
    v0v = 0x80;
    D_8008FBD4 = v0v;
    v0v = a2v ^ 0x40;
    *(s32 *) a3v = v0v;
l68670:
    __asm__(".L80068670:");
    t0v = (s32) &D_8008E548;
    a3v = *(s32 *) t0v;
    v0v = a3v & 0x80;

    __asm__(".globl func_80068684\nfunc_80068684:");
    if (v0v == 0) {
        goto l68714;
    }
    v0v = D_8008FBCC;
    a1v = D_8008FBD0;
    a2v = v0v + 1;
    v0v = a2v << 7;
    __asm__ volatile(".word 0x0045001a");
    if (a1v == 0) {
        __asm__ volatile(".word 0x0007000d");
    }
    MEMORY_BARRIER();
    negv = -1;
    if (a1v == negv) {
        negv = (s32) 0x80000000;
        if (v0v == negv) {
            __asm__ volatile(".word 0x0006000d");
        }
    }
    __asm__ volatile("mflo $v0");
    v1v = 0x80;
    D_8008FBD4 = v1v;

    __asm__(".globl func_800686DC\nfunc_800686DC:");
    D_8008FBCC = a2v;
    MEMORY_BARRIER();
    a0v = v1v - v0v;
    if (a0v < 0) {
        a0v = 0;
    }
    D_8008FBD4 = a0v;
    MEMORY_BARRIER();
    v0v = a2v < a1v;
    if (v0v != 0) {
        goto l68714;
    }
    v0v = a3v ^ 0x80;
    D_8008FBD4 = 0;
    *(s32 *) t0v = v0v;
l68714:
    v1v = D_8004E5BC;
    a0v = D_8008FBD4;
    v0v = v1v * 0x28;
    D_80085FCC[v0v] = (u8) a0v;
    v1v = D_8004E5BC;
    v0v = v1v * 0x28;
    D_80085FCD[v0v] = (u8) a0v;
    v1v = D_8004E5BC;
    v0v = v1v * 0x28;

    __asm__(".globl func_80068760\nfunc_80068760 = . - 0x20");
    D_80085FCE[v0v] = (u8) a0v;
    __asm__ volatile("addiu $sp,$sp,0x10");
}

extern s32 D_8008FBD8;
extern s32 D_8008FBDC;
extern s32 D_8008FBE0;
extern s32 D_8008FBE4;
extern s32 D_8008FBE8;

void func_8006879C(void) {
    s32 *arg0 = &D_8008FBE0;
    s32 *s0;
    s32 fbd8;
    s32 v0;
    s32 v1;

    KEEP(arg0);
    __asm__(".globl func_800687AC\nfunc_800687AC = . - 4");
    if (arg0[0] != 0) {
        v0 = D_8008FBE8;
        if (v0 != 0) {
            v0 = v0 - 1;
            D_8008FBE8 = v0;
            if (v0 == 0) {
                *(s32 *) ((char *) arg0 - 0xC) = 0x80;
                *(s32 *) ((char *) arg0 - 0x14) = 0;
                *(s32 *) ((char *) arg0 - 0x1698) |= 0x80;
                *(s32 *) ((char *) arg0 - 0x10) = arg0[3];
            }
        }
        s0 = &D_8008FBE4;
        v1 = s0[0] - 1;
        s0[0] = v1;
        if (v1 != 0) {
            goto end_body;
        }
        fbd8 = D_8008FBD8;
        arg0 = (s32 *) (fbd8 << 1);
        if (D_8008FBDC < fbd8) {
            D_8008FBE0 = 0;
            TAIL_JUMP_NOP(D_8006F8CC);
        }
else_body:
        arg0 = (s32 *) ((s32) arg0 + fbd8);
        arg0 = (s32 *) ((s32) arg0 << 3);
        arg0 = (s32 *) ((s32) arg0 - fbd8);
        arg0 = (s32 *) ((s32) arg0 << 11);
        {
            register s32 base asm("v0");
            base = D_800852A4;
            func_80069D7C(base + (s32) arg0);
        }
        D_8008E548 |= 0x40;
        D_8008FBCC = 0;
        D_8008FBD4 = 0;
        D_8008FBD0 = D_8008FBEC[0];
        D_8008FBD8 += 1;
        s0[0] = D_8008FBE0;
        D_8008FBE8 = D_8008FBE0 - D_8008FBEC[0];
end_body:;
    }
}

extern void func_8006F91C(s32, s32, s32);

void func_800688E0(void) {
    D_8008FC04 = 0;
    D_8004E5BC = 0;
    func_8006F91C(0x21908, 0x3858, 0x571);
}

void func_8006891C(s32 arg0, s32 arg1, s32 arg2) {
    s32 v1;

    func_80067320(arg0, arg2, -1, 0x7E);
    D_8008E53C &= -0x41;
    v1 = D_8008FC04;
    D_8008FBF0[v1] = 9;
    D_8008FC04 = v1 + 1;
}

DEAD_TAIL_LW(2, D_8008E53C);

extern void func_8006FA10();

void func_80068990(void) {
    s32 flag;
    s32 t0;
    s32 t1;

    if (flag & 2) {
        goto else_path;
    }
    func_80024638(0);
    t0 = D_8008E53C | 0x40;
    t1 = D_8008FC04 - 1;
    D_8008E53C = t0;
    D_8008FC04 = t1;
    func_8006FA10();
    __asm__ volatile("j D_8006FA00");
else_path:
    if (D_800855A4 & 0x800) {
        func_800675BC(1);
    }
}

extern void func_8006E2F0(void);

void func_80068A10(void) {
    s32 a0v;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v1 = -0x3001;
    v0 = D_8008E53C & v1;
    D_8008E53C = v0;
    func_800687AC(1);
    __asm__ volatile("lui $v0, 0x8009\nlw $v0, -0x1ac4($v0)");
    v1 = 0x40000;
    v0 |= v1;
    D_8008E53C = v0;
    func_8006E2F0();
    __asm__(".globl func_80068A54\nfunc_80068A54 = . - 4\n.L80068A54 = . - 4");
    v1 = D_8008FC04;
    v0 = 2;
    D_8008FC14 = v0;
    v0 = 0xA;
    a0v = v1 << 2;
    v1++;
    D_8008FBF0[a0v >> 2] = v0;
    D_8008FC04 = v1;
}

extern s32 func_8006E7E0(void);

void func_80068AA0(void) {
    register s32 v1 asm("v1");

    s32 v0;
    v0 = func_8006E7E0();
    if (v0 != 0) {
        goto end;
    }
    v0 = D_8008FC04;
    v1 = D_8008E53C;
    D_8008FC14 = 0;
    v0 -= 1;
    v1 ^= 1;
    D_8008FC04 = v0;
    D_8008E53C = v1;
end:
    return;
}

__asm__(".text\n.globl func_80068AEC\nfunc_80068AEC = . - 12\n.L80068AEC = . - 12\n");

extern s32 D_8008E574;

void func_80068AF8(void) {
    s32 a0v;
    s32 v0;
    s32 v1;

    a0v = (s32) &D_8008E548;
    v1 = *(s32 *) a0v;
    v0 = v1 & 0x30;
    if (v0 != 0) {
        v0 = v1 ^ 2;
        __asm__ volatile(".set\tnoreorder\n\tj 0x8006fb38\n\tsw %0,0(%1)\n\t.set\treorder" ::"r"(v0),
                         "r"(a0v));
    }
    v0 = D_8008E574;
    v1 ^= 1;
    *(s32 *) a0v = v1;
    v0 += 2;
    D_8008E574 = v0;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068B40);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068B74);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068BB0);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068C90);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open", func_80068CD0);

s32 func_80068D80(void) {
    s32 v0;
    s32 v1;
    s32 out = v0 + 4;
    D_8008E560 = v1;
    D_8008E574 = out;
    return out;
}
