#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();
extern void func_800FFD70();
extern void func_800F0F64();
extern s32 *D_801CD7E0;
extern u8 D_8018BA25;
extern u8 D_801531B0[];
extern void func_8012BD9C();
extern u32 func_8012372C();
extern s16 func_800F93A0();
extern void func_800F6EA8();
extern s32 func_800E7810();
extern s16 D_8018BA20;
extern s32 func_8008CDD0(s32);
extern s32 func_800EF1A8(s32);
extern void func_800FFF50();
extern s16 D_80153258;
extern s32 D_80153298;
extern void func_800FFE28();
extern s32 *D_80153280;
extern u8 *func_80180AFC();
extern void func_80023C90(void *, s32);
extern void func_80023C68(void *, s32);
extern s32 D_8019ACA0[];
extern void func_80023DE4(void *);
extern s32 func_800254CC();
extern void func_800FDAA4();
extern s32 D_801CD170;
extern s32 D_80195D1C[];
extern s32 func_800FF690_s() asm("func_800FF690");
extern s32 func_800FF9AC();
extern void func_800FE774_s(s32, s32, s32) asm("func_800FE774");
extern u16 D_80153284;
extern u16 D_80153286;
extern s32 D_8015328C;
extern s32 D_80153304;
extern s32 D_80153308;
extern s32 D_801CD8A4;
extern void func_80100348();
extern s32 D_80195C34;
extern void func_800FF450();
extern u8 *func_80059AF0();
extern u8 D_800596E0[];
extern void func_80059FE0(s32);
extern void func_800EF25C();
extern void func_800FFEA0();
extern s32 func_80100164(s32);
extern s32 D_8015330C;
extern s32 D_80153310;
extern s32 func_8010012C();
extern void func_800EDAA8();
extern s32 D_8019A20C;
extern s32 D_801532A0;
extern s32 func_80100090();
extern s32 func_801000C4();
extern void func_800FD4A8();
extern s32 D_80010010;
extern void func_80044600();
extern void func_800FD1D8();
extern void func_80102E78();
extern u16 D_8015332E;
extern s16 D_8015332C;
extern void func_800FFD28();
extern void func_800FFF08();
extern s32 func_800FD14C(s32);
extern void func_8010487C();
extern s32 func_80100384();
extern s32 *D_801CD78C;
extern void func_800E3298();
extern s32 func_80044954;
extern s32 *D_801CD75C;
extern void func_800F0520();
extern void func_800FD9F4();
extern s32 *D_801CD78C_p asm("D_801CD78C");
extern void func_80043F00();
extern s16 D_80153330;
extern s32 func_80100188(s32, s32, s32);
extern s32 func_8008CEFC(s32);
extern void func_800F218C();
extern void func_800F290C();
extern void func_800F2998();
extern s32 D_8015327C;
extern s32 D_801AED8C;
extern s32 D_801CA6F0;
extern s32 D_801CA6F4;
extern s32 D_801CD66C;
extern s32 D_801CD830;
extern void func_800FD93C();
extern void func_800FFE64();
extern void func_800F6EC8();
extern s32 func_800FFEEC();
extern s16 D_801531C8;
extern void func_800EEE98();
extern s32 D_801CD814;
extern s16 D_80153340;
extern s32 func_800E1E40(void);
extern void func_800E2444(void *arg0);
extern void func_800E3618(u8 *arg0);
extern void func_800E36A0(u8 *arg0);
extern void func_800F0470(s32 arg0);
extern void func_800F1330(s32 arg0);

void func_800F6E68(void) {
    if (D_80153340 == 1) {
        D_80153340 += 1;
    }
}

void func_800F6E98(void) {
}

void func_800F6EA0(void) {
}

void func_800F6EA8(void) {
}

s32 func_800F6EB0(void) {
    return D_80153280[0x23];
}

extern void func_800F6F20();
extern s32 func_800F92A0();

void func_800F6EC8(void) {
    func_800F92A0();
    func_800F6F20();
}

void func_800F6EF0(void) {
    func_800F92A0();
    func_800F6F20();
}

void func_800F6F18(void) {
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800F6F20);

extern s32 D_80156B8C;

s32 func_800F92A0(void) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1") = 0xF;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    func_800FFF50();
    s0v = 4;
outer:
    v0v = func_800FD14C(s0v);
    if (v0v != 0) {
        goto after;
    }
    s0v += 1;
    v0v = s0v < 0xF;
    if (v0v != 0) {
        goto outer;
    }
after:
    if (s0v != s1v) {
        func_800FFF50();
        s0v = 4;
        goto outer;
    }
    v0v = func_800EF1A8(0x27);
    v1v = D_80156B8C;
    KEEP_WITH(v0v, v1v);
    s0v = v0v;
    v0v = 0;
    if (s0v == v1v) {
        goto end;
    }
    func_800F0470(s0v);
    D_80156B8C = s0v;
    v0v = 1;
end:
    return v0v;
}

extern s32 func_8008CBB4(s32);
extern s32 func_8008CEFC_noarg() asm("func_8008CEFC");

s32 func_800F932C(s32 arg0) {
    s32 v0;
    s32 s0;

    v0 = -1;
    if (arg0 != -1) {
        v0 = func_8008CEFC_noarg();
        if (v0 == 0) {
            goto zero_result;
        }
        return 1;
    }
    s0 = 0;
loop:
    v0 = func_8008CBB4(s0);
    if (v0 == 0) {
        goto advance;
    }
    v0 = func_8008CEFC(s0);
    if (v0 != 0) {
        return 1;
    }
advance:
    s0++;
    v0 = 0;
    if (s0 < 0x15) {
        goto loop;
    }
zero_result:
    v0 = 0;
    return v0;
}

s16 func_800F93A0(u8 *arg0) {
    return arg0[0] | (arg0[1] << 8);
}

void func_800F93BC(u8 *arg0, u16 arg1) {
    arg0[0] = arg1;
    arg0[1] = arg1 >> 8;
}

extern u16 D_80153350;

void func_800F93CC(void) {
    s32 v0v;
    v0v = D_80153350;

    if (v0v != 0) {
        do {
            func_800FFF50();
        } while (D_80153350 != 0);
    }
}

extern u16 D_801531C4;

void func_800F940C(void) {
    register s32 v1 asm("v1");
    register s32 v0 asm("v0");

    v1 = D_801531C4;
    v0 = D_80153280;
    v1 = (v1 << 2) + v0;
    v0 = *(s32 *) v1;
    *(s32 *) v1 = v0 & -2;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800F9438);

extern void func_800934D0();
extern u16 D_80156B90[];

void func_800F99DC(void) {
    u8 *temp_v0;
    s8 *temp_s0;

    func_800FD1D8(6);
    temp_v0 = (u8 *) func_80100090();
    temp_s0 = (s8 *) temp_v0;
    func_800934D0(temp_v0[0], temp_v0[4], temp_s0[1], temp_s0[2], temp_s0[3]);
    func_800FFD28(D_80156B90[temp_v0[4]]);
    func_800FFE28();
}

extern u16 D_801532D4;

void func_800F9A54(void) {
    s32 s0v;
    s32 s1v;
    u8 *s2v;
    s32 a0v;
    s32 v0v;
    s32 v1v;

    a0v = 0xD;
    func_800FD1D8(a0v);
    s1v = 0;
    s2v = (u8 *) func_80100090();
    s0v = 0;
loop:
    s1v += 1;
    func_800FFF50();
    s0v += 1;
    v0v = s2v[1];
    if (s1v != v0v) {
        goto check;
    }
    v0v = s2v[0];
    v1v = D_801532D4;
    s1v = 0;
    v0v += v1v;
    D_801532D4 = (u16) v0v;
check:
    v0v = s2v[3];
    if (s0v != v0v) {
        goto loop;
    }
    v0v = s2v[2];
    v1v = D_801532D4;
    v0v += v1v;
    D_801532D4 = (u16) v0v;
    s0v = 0;
    goto loop;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800F9B04);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800F9C8C);

extern void func_800F9C8C();

void func_800FA254(void) {
    func_800FD1D8(0xB);
    func_800F9C8C(func_80100090(), 0);
    func_800FFE28();
}

void func_800FA290(void) {
    func_800FD1D8(0xB);
    func_800F9C8C(func_80100090(), 1);
    func_800FFE28();
}

extern s32 D_80195D20[];

void func_800FA2CC(void) {
    register s32 r asm("s2");
    register s32 eleven asm("s3");
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");

    r = func_800E7810();
    if (r == 0x7D0) {
        return;
    }
    eleven = 0xB;
    s0 = 0;
    s1 = 0;
loop:
    if ((func_80100164(s0) == 0) || (*(s32 *) ((u8 *) D_80195D1C + s1) != eleven) || (*(s32 *) ((u8 *) D_80195D20 + s1) != r)) {
        s0 += 1;
        s1 += 0x400;
        if (s0 < 0x11) {
            goto loop;
        }
    }
    if (s0 == 0x11) {
        return;
    }
    s0 = 0;
    func_800FFF50();
    s1 = 0;
    goto loop;
}

void func_800FA38C(s32 arg0, s32 arg1) {
    func_800FF450(arg0, arg1, 0x20);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FA3AC);

extern s32 D_8015334C;

void func_800FA724(s32 arg0) {
    s32 v1 = -0x4000;

    do {
        if ((arg0 < (v1 + 0x1000)) && (arg0 >= v1)) {
            D_8015334C = v1;
        }
        v1 += 0x1000;
    } while (v1 < 0x3FF8);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FA760);

extern void func_800F93BC_s16(u8 *, s16) asm("func_800F93BC");

void func_800FA8EC(u8 *arg0, s32 *arg1) {
    u8 *s1v = arg0;
    u32 *s4v = (u32 *) arg1;
    u8 *s3v;
    s32 s2v;
    s32 s0v;
    s32 a;
    s16 v;
    s32 t;

    s3v = s1v + 0xF;
    if (*(u8 *) (s1v + 0xE) == 0x38) {
        s3v = s1v + 0x12;
    }
    s2v = 0;
    do {
        s0v = s4v[0];
        if (s2v < 3) {
            if (s0v < 0) {
                t = s0v + 0x3FF;
            } else {
                t = s0v;
            }
            s0v = t >> 10;
        }
        v = func_800F93A0(s1v);
        if (v == 0x2710) {
            a = 0x2710;
        } else {
            v = func_800F93A0(s1v);
            a = s0v + v;
        }
        func_800F93BC_s16(s3v, a);
        s1v += 2;
        s3v += 2;
        s2v++;
        s4v++;
    } while (s2v < 7);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FA9CC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FABC8);

void func_800FAD84(void) {
    volatile s32 pad[12];
}

s32 func_800FAD94(u16 *arg0, s32 *arg1) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register u32 a0v asm("a0");
    register s32 s0v asm("s0");

    s0v = (s32) arg0;
    a0v = *(u16 *) s0v;
    if (a0v == 0) {
        goto blk_f4;
    }
    if (a0v >= 0x100) {
        goto blk_ec;
    }
    v0v = func_800E7810(a0v);
    *(u16 *) s0v = v0v;
    *(s32 *) arg1 = 0;
    v1v = *(u16 *) s0v;
    v0v = 0x7D0;
    if (v1v != v0v) {
        v0v = 1;
        goto end;
    }
    v0v = 0;
    goto end;
blk_ec:
    v0v = a0v - 0xFE;
    if (a0v != 0) {
        goto blk_f8;
    }
blk_f4:
    v0v = 1;
blk_f8:
    *(s32 *) arg1 = v0v;
    v0v = 1;
end:
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FAE18);

extern s32 func_8008D26C();
extern s32 D_8008E2C8;

void func_800FB03C(s32 arg0, s32 arg1) {
    extern s32 func_800E1BC0();
    extern s32 func_8017FD80(s32);
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2") = arg1;
    register s32 v0v asm("v0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");

    s0v = func_800E7810();
    v0v = 0x7D0;
    if (s0v == v0v) {
        goto end;
    }
    v0v = 0x6A;
    D_80153298 = v0v;
    v0v = (s32) &D_8008E2C8;
    D_801CD78C_p = (s32 *) v0v;
    func_80100384(s0v);
    func_8008CDD0(s0v);
    s1v = v0v;
    func_800E1BC0(s0v, 0x1B);
    a0v = s0v;
    a1v = 2;
    a2v = 0x1F;
    a3v = 0x1F;
    MEMORY_BARRIER();
    v0v = 0x1F;
    func_8008D26C(a0v, a1v, a2v, a3v, v0v);
    func_800FFD28(0x3C);
    a0v = s0v;
    a1v = 2;
    a2v = -0x1F;
    a3v = -0x1F;
    MEMORY_BARRIER();
    v0v = -0x1F;
    func_8008D26C(a0v, a1v, a2v, a3v, v0v);
    func_800FFD28(0x3C);
    if (s2v != 0) {
        func_8017FD80(s1v);
    }
end:
}

void func_800FB114(void) {
    s32 temp_v0;

    temp_v0 = func_800E7810();
    if (temp_v0 != 0x7D0) {
        D_801CD78C = &D_8008E2C8;
        func_80100384(temp_v0);
    }
}

extern s32 func_8008CBB4();
extern s32 func_80180C90();

void func_800FB15C(void) {
    s32 sp18;
    s32 temp_v0;
    u8 *p;
    s32 s0v;

    s0v = 0;
    do {
        if (func_8008CBB4(s0v) != 0) {
            temp_v0 = func_8008CDD0(s0v);
            if (temp_v0 != -1) {
                p = (u8 *) func_80180C90(*(u8 *) (func_80180AFC(temp_v0) + 0x161), &sp18);
                if ((*(u8 *) (p + 0x1BA) & 0x30) && (sp18 != -2)) {
                    func_8008D26C(s0v, 2, -0x1F, -0x1F, 0);
                }
            }
        }
        s0v += 1;
    } while (s0v < 0x15);
}

void func_800FB204(s32 arg0) {
    s32 sp18;
    s32 temp_v0;
    u8 *temp_v0_2;
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_8008CBB4(var_s0) != 0) {
            temp_v0 = func_8008CDD0(var_s0);
            if (temp_v0 != -1) {
                temp_v0_2 = (u8 *) func_80180C90(*(u8 *) (func_80180AFC(temp_v0) + 0x161), &sp18);
                if ((*(u8 *) (temp_v0_2 + 5) & 0x30) && (sp18 != -2) &&
                    (*(u8 *) (temp_v0_2 + 0x161) == arg0)) {
                    func_8008D26C(var_s0, 2, -0x1F, -0x1F, 0);
                }
            }
        }
        var_s0 += 1;
    } while (var_s0 < 0x15);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FB2CC);

extern s32 D_8019A23C;
extern s32 func_800F93A0_s32_noarg() asm("func_800F93A0");
extern s32 func_800F93A0_s32_arg(u8 *) asm("func_800F93A0");
extern s32 func_800E7810_s16_arg(s16) asm("func_800E7810");
extern s32 func_8008CC14_s(s32) asm("func_8008CC14");
extern s32 func_8008CBD8_s(s32) asm("func_8008CBD8");
extern void func_800E1BC0(s32, s16);
extern void func_800E1CB4(s32, s32);

void func_800FB418(void *arg0) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 s3v asm("s3");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    u8 *p;
    u8 value;
    s32 temp;
    s32 temp_s3;

    s0v = (s32) arg0;
    s1v = func_800F93A0_s32_noarg();
    KEEP(s1v);
    s2v = *(u8 *) (s0v + 2);
    temp_s3 = func_800F93A0_s32_arg((u8 *) (s0v + 3));
    a0v = s1v;
    a0v <<= 16;
    a0v >>= 16;
    a0v = func_800E7810_s16_arg((s16) s1v);
    s3v = temp_s3;
    s1v = a0v;
    if (*(u8 *) (s0v + 4) == 0) {
        a0v = (s16) a0v;
        func_8008CC14_s(a0v);
        s0v = s1v << 16;
    } else {
        a0v = (s16) a0v;
        func_8008CBD8_s(a0v);
        s0v = s1v << 16;
    }
    s0v >>= 16;
    a0v = s0v;
    a1v = s2v;
    v0v = s0v << 3;
    v0v -= s0v;
    v1v = (s32) &D_8019A23C;
    v0v += v1v;
    *(u8 *) v0v = s2v;
    *(u8 *) (v0v + 6) = 0;
    *(u8 *) (v0v + 4) = 0;
    func_800E1CB4(s0v, s2v);
    a1v = s3v << 16;
    a1v >>= 16;
    func_800E1BC0(s0v, a1v);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FB4F0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FB6F0);

extern s32 D_80068E80;

void func_800FB8F4(s32 arg0, s32 arg1) {
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 s3v asm("s3");
    register s32 s4v asm("s4");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    s1v = arg0;
    s3v = arg1;
    s2v = (s32) func_80180AFC((u8 *) arg0);
    v0v = (s32) &D_80068E80;
    s0v = 0;
    s4v = 0x80;
    D_801CD78C = (s32 *) v0v;
loop:
    if (s0v < 0) {
        v0v = s0v + 7;
    } else {
        v0v = s0v;
    }
    v0v >>= 3;
    v1v = v0v << 3;
    v1v = s0v - v1v;
    v0v = s2v + v0v;
    v0v = *(u8 *) (v0v + 0x58);
    v1v = s4v >> v1v;
    v0v &= v1v;
    if (v0v != 0) {
        a0v = s0v + 1;
        a1v = s3v;
        a2v = s1v;
        func_80100384(a0v, a1v, a2v);
    }
    s0v++;
    if (s0v < 0x28) {
        goto loop;
    }
}

extern s32 D_801A66A8;

void func_800FB9A8(void) {
    s32 v0;
    s32 v1;

    v1 = 0;
    do {
        v0 = D_801A66A8;
        *(u8 *) (v0 + v1 + 0x39C) = 0;
        v0 = D_801A66A8;
        v0 += v1;
        v1++;
        *(u8 *) (v0 + 0x3B1) = 0;
    } while (v1 < 0x15);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FB9EC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FB9F4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FBD14);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FC144);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FC154);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FC2F4);

extern u8 D_8018E07C[];

void func_800FC56C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern u8 *func_80180AFC(s32);
    register s32 s0v asm("s0");
    register s32 s2v asm("s2");
    register s32 s3v asm("s3");
    register s32 s1v asm("s1");
    register s32 a0v asm("a0");
    register s32 v1v asm("v1");
    u8 *base;
    u8 *p;
    u8 *q;
    s32 v0v;

    s0v = arg1;
    s2v = arg2;
    s3v = arg3;
    s1v = func_800E1E40();
    if (s1v == 0x7D0) {
        return;
    }
    base = func_80180AFC(s1v);
    for (v1v = 0; v1v < 5; v1v++) {
        p = base + v1v;
        p[0x1A7] = 0;
        p[0x1AC] = 0;
    }
    if (s0v < 0) {
        v0v = s0v + 7;
    } else {
        v0v = s0v;
    }
    a0v = v0v >> 3;
    v0v = s0v - (a0v << 3);
    v1v = 1 << v0v;
    if (s2v != 0) {
        q = base + a0v;
        q[0x1A7] = v1v;
    } else {
        q = base + a0v;
        q[0x1AC] = v1v;
    }
    D_801CD78C = (s32 *) D_8018E07C;
    func_80100384(s1v, s3v);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FC644);

struct B_800FC804_0 {
    char pad_0[4];
    u8 unk4;
};

extern void func_8008CBD8();
extern void func_8008CC14();
extern void func_800E1BC0();
extern s16 func_800F93A0_noarg() asm("func_800F93A0");
extern s32 func_800FAD94(u16 *, s32 *);
extern s32 func_800FAE18(u16 *, s32 *, s32 *);

void func_800FC804(struct B_800FC804_0 *arg0) {
    s32 sp18;
    s32 sp14;
    u16 sp10;
    s16 temp_v0;
    s32 temp_v0_2;
    u8 temp_v1;

    sp10 = func_800F93A0_noarg();
    if (func_800FAD94(&sp10, &sp14) != 0) {
        sp18 = 0;
loop_2:
        if (func_800FAE18(&sp10, &sp18, &sp14) != 0) {
            temp_v1 = arg0->unk4;
            if (temp_v1 == 0) {
                func_8008CC14(sp10);
            } else if (temp_v1 == 1) {
                func_8008CBD8(sp10);
            }
            temp_v0 = func_800F93A0_s32_arg((u8 *) arg0 + 2);
            func_800E1BC0(sp10, temp_v0);
            if ((u32) (temp_v0 - 0x53) < 3U) {
                func_800F218C();
            }
            if (sp14 != 0) {
                goto block_10;
            }
        } else {
block_10:
            temp_v0_2 = sp18 + 1;
            sp18 = temp_v0_2;
            if (temp_v0_2 < 0x15) {
                goto loop_2;
            }
        }
    }
}

extern void func_8008BE54(u16);

void func_800FC8FC(u8 *arg0) {
    s32 sp18;
    s32 sp14;
    u16 sp10;
    u8 *s0v = arg0;

    sp10 = func_800F93A0_noarg();
    if (func_800FAD94(&sp10, &sp14) != 0) {
        sp18 = 0;
loop:
        if (func_800FAE18(&sp10, &sp18, &sp14) == 0) {
            goto increment;
        }
        func_8008BE54(sp10);
        func_800FFD28(s0v[2]);
        if (sp14 == 0) {
            goto end;
        }
increment:
        sp18 += 1;
        if (sp18 < 0x15) {
            goto loop;
        }
    }
end:
    return;
}

extern void func_8008CD58();
extern void func_8008CD94();

void func_800FC998(u8 *arg0) {
    s32 sp18;
    s32 sp14;
    u16 sp10;
    u8 *s0v = arg0;

    sp10 = func_800F93A0(arg0);
    if (func_800FAD94(&sp10, &sp14) != 0) {
        sp18 = 0;
loop:
        if (func_800FAE18(&sp10, &sp18, &sp14) != 0) {
            if (s0v[2] != 0) {
                func_8008CD58(sp10);
            } else {
                func_8008CD94(sp10);
            }
            if (sp14 == 0) {
                goto end;
            }
        }
        sp18++;
        if (sp18 < 0x15) {
            goto loop;
        }
    }
end:
    return;
}

extern void func_800933C4(s32, s32, s32, s32, s32, s32);

void func_800FCA4C(u8 *arg0) {
    s32 sp20;
    s32 sp1c;
    u16 sp18;
    u8 *s0v = arg0;
    s32 v0v;

    sp18 = func_800F93A0_noarg();
    v0v = func_800FAD94(&sp18, &sp1c);
    s0v += 2;
    if (v0v != 0) {
        sp20 = 0;
loop:
        if (func_800FAE18(&sp18, &sp20, &sp1c) == 0) {
            goto increment;
        }
        func_800933C4(s0v[0], s0v[4], sp18, (s32) (s8) s0v[1], (s32) (s8) s0v[2], (s32) (s8) s0v[3]);
        if (sp1c == 0) {
            goto end;
        }
increment:
        sp20 += 1;
        if (sp20 < 0x15) {
            goto loop;
        }
    }
end:
    return;
}

extern void func_8008CCAC();
extern void func_8008CCE8();

void func_800FCAF8(u16 arg0, s32 arg1) {
    s32 sp18;
    s32 sp14;
    u16 sp10;
    s32 temp_v0;

    sp10 = arg0;
    if (func_800FAD94(&sp10, &sp14) != 0) {
        sp18 = 0;
loop_2:
        if (func_800FAE18(&sp10, &sp18, &sp14) != 0) {
            if (arg1 == 0) {
                func_8008CCE8(sp10);
            } else {
                func_8008CCAC(sp10);
            }
            if (sp14 != 0) {
                goto block_7;
            }
        } else {
block_7:
            temp_v0 = sp18 + 1;
            sp18 = temp_v0;
            if (temp_v0 < 0x15) {
                goto loop_2;
            }
        }
    }
}

extern s32 func_8008C0AC(s32);
extern s32 func_800E20A0();

s32 func_800FCBA0(void) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = func_800E7810();
    temp_s0 = (s32) ((func_800E20A0() + 0x200) & 0xF00) >> 8;
    return (u32) (((temp_s0 + func_8008C0AC(temp_s1)) & 0xF) - 7) < 6U;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FCBF8);

extern u8 D_8019A240[];

void func_800FCD68(s32 arg0) {
    s32 a0v;
    s32 s0v;
    s32 v0v;
    s32 v1v;

    a0v = arg0;
    if (a0v == -1) {
        s0v = 0x15;
loop2:
        func_800FFF50(a0v);
        a0v = 0;
        v1v = 0;
loop3:
        v0v = D_8019A240[v1v];
        if (v0v == 0) {
            a0v++;
            v1v += 7;
            if (a0v < 0x15) {
                goto loop3;
            }
        }
        if (a0v != s0v) {
            goto loop2;
        }
    } else {
        v1v = func_800E7810();
        v0v = 0x7D0;
        if (v1v == v0v) {
            goto end;
        }
        v0v = v1v << 3;
        s0v = v0v - v1v;
loop4:
        func_800FFF50();
        v0v = D_8019A240[s0v];
        if (v0v != 0) {
            goto loop4;
        }
    }
end:
    return;
}

extern void func_80044018(s32);
extern void func_800FCEC0();

void func_800FCE18(void) {
    struct Func800FCE18_Obj {
        u8 f00;
        u8 f01;
        u8 f02;
        u8 f03;
    };
    extern void func_800440F4(s32);
    extern void func_80044038(s32);
    extern void func_8004408C(s32, s32);
    struct Func800FCE18_Obj *temp_v0;
    s32 temp_s0;
    register u32 s3v asm("s3");
    register u8 temp_s2 asm("s2");
    register s32 var_a1 asm("a1");
    u8 flag;

    func_800FD1D8(0x35);
    temp_v0 = (struct Func800FCE18_Obj *) func_80100090();
    s3v = 0x10000;
    KEEP(s3v);
    FORCE_REG(s3v);
    flag = temp_v0->f03;
    USE(flag);
    temp_s2 = temp_v0->f00;
    temp_s0 = temp_s2 + s3v;
    if (flag != 0) {
        func_800440F4(temp_s0);
        func_80044018(temp_s0);
        goto common;
    }
    func_800440F4(temp_s0);
    func_80044038(temp_s0);
common:
    var_a1 = temp_v0->f01;
    if (var_a1 == 0) {
        var_a1 = 1;
    }
    func_8004408C(temp_s2 | s3v, var_a1);
    func_800FCEC0();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FCEC0);

extern s32 D_8019ACA8[];
extern s32 D_8019ACBC[];

void func_800FCFC8(void) {
    s32 s0v;
    s32 v0v;
    s32 v1v;
    s32 a0v;
    s32 a1v;
    s32 a2v;

    v0v = func_800F93A0_noarg();
    a0v = 0;
    v0v = (s32) (s16) v0v << 16;
    a2v = v0v >> 16;
    v0v = s0v << 3;
    v0v += s0v;
    v0v <<= 2;
    v0v -= s0v;
    v1v = v0v << 3;
    v0v = (s32) D_8019ACA0;
    a1v = v1v + v0v;
loop:
    v0v = *(s32 *) ((u8 *) D_8019ACA8 + v1v);
    a0v += 1;
    if (v0v != a2v) {
        goto check;
    }
    v0v = *(s32 *) ((u8 *) D_8019ACBC + v1v) + 1;
    *(s32 *) (a1v + 0x1C) = v0v;
    v0v = *(s32 *) ((u8 *) D_8019ACBC + v1v) & 1;
    *(s32 *) ((u8 *) D_8019ACBC + v1v) = v0v;
check:
    v0v = a0v < 6;
    if (v0v != 0) {
        goto loop;
    }
}

void func_800FD074(void) {
}

s32 func_800FD07C(s32 arg0) {
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");

    if (arg0 < 0x10) {
        v0 = arg0;
        goto end;
    }
    s0 = 1;
    do {
        if (func_80100164(s0) == 0) {
            v0 = s0;
            goto end;
        }
        s0++;
    } while (s0 < 0x11);
    func_800FFE28();
end:
    return v0;
}

s32 func_800FD0D8(s32 arg0) {
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");

    if (arg0 < 0x10) {
        v0v = arg0;
        goto end;
    }
    v0v = D_801CD170;
    s0v = v0v + 1;
    if (s0v < 0x11) {
        do {
            if (func_80100164(s0v) == 0) {
                v0v = s0v;
                goto end;
            }
            s0v++;
        } while (s0v < 0x11);
    }
    func_800FFE28();
end:
    return v0v;
}

s32 func_800FD14C(s32 arg0) {
    s32 s2v = arg0;
    s32 s0v = 1;
    s32 s1v = 0x400;
    s32 v0v;

loop:
    v0v = D_801CD170;
    if (s0v == v0v) {
        goto next;
    }
    v0v = func_80100164(s0v);
    if (v0v == 0) {
        goto next;
    }
    v0v = *(s32 *) ((u8 *) D_80195D1C + s1v);
    if (v0v == s2v) {
        v0v = s0v;
        goto end;
    }
next:
    s0v += 1;
    v0v = s0v < 0x11;
    if (v0v == 0) {
        v0v = 0;
        goto end;
    }
    s1v += 0x400;
    goto loop;
end:
    return v0v;
}

void func_800FD1D8(s32 arg0) {
    s32 v;

    v = D_801CD170;
    D_80195D1C[v << 8] = arg0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FD1FC);

extern u8 D_8013A454[];

s32 func_800FD34C(s32 arg0, s32 arg1) {
    register s32 a0 asm("a0") = arg0;
    register s32 a1 asm("a1") = arg1;
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a2 = (s32) D_801CD75C;
    a3 = 0xDB;
loop:
    v0 = *(u8 *) (a2 + a0);
    if (v0 == a3) {
        return 0;
    }
    if (v0 == a1) {
        return a0;
    }
    v1 = *(u8 *) ((u8 *) D_8013A454 + v0);
    v0 = a0 + 1;
    a0 = v0 + v1;
    goto loop;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FD3A0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FD4A8);

s32 func_800FD7C4(s32 arg0) {
    s32 s0v;
    s32 v0v;
    s32 v1v;

    if (arg0 < 0x80) {
        v1v = (s32) D_80153280;
        v0v = arg0 << 2;
        s0v = v0v + v1v;
        goto end;
    }
    if (arg0 < 0x360) {
        v0v = arg0 - 0x80;
        if (v0v < 0) {
            v0v = arg0 - 0x61;
        }
        v0v >>= 5;
        v0v <<= 2;
        v1v = (s32) D_80153280;
        v0v += 0x200;
        s0v = v0v + v1v;
        goto end;
    }
    if (arg0 < 0x400) {
        v0v = arg0 - 0x360;
        if (v0v < 0) {
            v0v = arg0 - 0x359;
        }
        v0v >>= 3;
        v0v <<= 2;
        v1v = (s32) D_80153280;
        v0v += 0x25C;
        s0v = v0v + v1v;
        goto end;
    }
    func_800FFE28();
end:
    return s0v;
}

s32 func_800FD874(s32 arg0) {
    s32 var_s0;

    var_s0 = -1;
    if (arg0 >= 0x80) {
        if (arg0 < 0x360) {
            var_s0 = arg0 & 0x1F;
        } else if (arg0 < 0x400) {
            var_s0 = (arg0 & 7) * 4;
        } else {
            func_800FFE28();
        }
    }
    return var_s0;
}

void func_800FD8D0(s32 arg0) {
    s32 s0v = arg0;
    s32 s1v;
    s16 temp;

    temp = func_800F93A0((u8 *) arg0);
    s1v = temp;
    temp = func_800F93A0((u8 *) (arg0 + 2));
    s0v = temp;
loop:
    if (func_800EF1A8(s1v) < s0v) {
        func_800FFF50();
        goto loop;
    }
}

extern s32 func_8001DBA8(s32);
extern s32 D_801A66AC;

void func_800FD93C(void) {
    D_801A66AC = func_8001DBA8(-1);
}

u32 func_800FD964(void) {
    u32 a0;
    register u32 v0 asm("v0");
    register u32 v1 asm("v1");

    a0 = (u32) D_801A66AC;
    v1 = (a0 << 1) + a0;
    v0 = v1 << 4;
    v1 += v0;
    v1 <<= 2;
    v1 -= a0;
    v0 = v1 << 5;
    v0 -= v1;
    v0 <<= 2;
    v0 += a0;
    v0 += 0x3619;
    v0 &= 0xFFFF;
    D_801A66AC = v0;
    return v0;
}

extern s32 func_8008BF14(s32);

void func_800FD9B0(s32 arg0) {
loop_1:
    if (func_8008BF14(arg0) == 0) {
        func_800FFF50();
        goto loop_1;
    }
}

extern s32 D_8014E5C0;

void func_800FD9F4(void) {
    register s32 *v1 asm("v1");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 *a0 asm("a0");
    register s32 v0 asm("v0");

    v1 = &D_8014E5C0;
    a1 = 0;
    a2 = (s32) v1 + 0x80;
    a0 = &D_801CD8A4;
loop:
    v0 = *v1;
    v1++;
    a1++;
    v0 += a2;
    *a0 = v0;
    a0++;
    if (a1 < 0x20) {
        goto loop;
    }
}

extern s32 D_8019A204;

s32 *func_800FDA34(s32 arg0) {
    s32 *p;

    p = &D_80195C34;
    if (arg0 != 0)
        p = &D_8019A204;
    return p;
}

extern s32 D_8019A208;
extern s32 D_8019A210;
extern s32 D_8019A214;

void func_800FDA54(void *arg0) {
    s32 *p = (s32 *) arg0;
    s32 v0;
    s32 v1;
    s32 a1v;
    s32 a2v;
    s32 a3v;

    v0 = p[0];
    v1 = p[1];
    a1v = p[2];
    a2v = p[3];
    a3v = p[4];
    p = (s32 *) p[5];
    D_80195C34 = v0;
    D_8019A204 = v1;
    D_8019A208 = a1v;
    D_8019A20C = a2v;
    D_8019A210 = a3v;
    D_8019A214 = (s32) p;
}

extern u16 D_801532D6;
extern void func_80024BD8(s32 *);

void func_800FDAA4(s32 *arg0) {
    register s32 a0v asm("a0") = (s32) arg0;
    s32 a3v;
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    v0v = D_801532D6;
    a3v = (s32) arg0;
    if (v0v != 0) {
        func_80024BD8(arg0);
        return;
    }
    a0v = 0x00FFFFFF;
    a2v = 0xFF000000;
    a1v = D_801CD814;
    v1v = *(s32 *) a3v;
    v0v = *(s32 *) a1v;
    v1v &= a2v;
    v0v &= a0v;
    v1v |= v0v;
    *(s32 *) a3v = v1v;
    v0v = *(s32 *) a1v;
    a0v &= a3v;
    v0v &= a2v;
    v0v |= a0v;
    *(s32 *) a1v = v0v;
}

void func_800FDB1C(s32 *arg0) {
    s32 a0 = (s32) arg0;
    s32 a1;
    register u32 a2 asm("a2");
    register u32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a2 = 0x00FF0000U;
    KEEP_NOVOL(a2);
    a2 |= 0xFFFFU;
    a3 = 0xFF000000;
    a1 = D_801CD814;
    v1 = *(s32 *) a0;
    v0 = *(s32 *) (a1 + 4);
    v1 &= a3;
    v0 &= a2;
    v1 |= v0;
    *(s32 *) a0 = v1;
    v0 = *(s32 *) (a1 + 4);
    a0 &= a2;
    v0 &= a3;
    v0 |= a0;
    *(s32 *) (a1 + 4) = v0;
}

extern s16 D_801533D0;
extern s16 D_801533D2;
extern s16 D_801533D4;
extern s16 D_801533D6;

void func_800FDB60(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_801533D0 = arg0;
    D_801533D2 = arg1;
    D_801533D4 = arg2;
    D_801533D6 = arg3;
}

void func_800FDB88(u16 arg0, u16 arg1) {
    D_80153284 = arg0;
    D_80153286 = arg1;
}

void func_800FDBA0(void *arg0, s32 arg1) {
    register s32 s0v asm("s0");
    register s32 qv asm("v1");
    s32 r;

    s0v = (s32) arg0;
    if (arg1 == 0) {
        r = func_8002398C(0, 0, 0x3C0, 0x100);
    } else if (arg1 == 1) {
        r = func_8002398C(0, 0, 0x1C0, 0);
    } else if (arg1 == 2) {
        r = func_8002398C(0, 0, 0x180, 0);
    } else if (arg1 == 3) {
        r = func_8002398C(0, 0, 0x340, 0x100);
    } else {
        r = func_8002398C(0, 0, 0x380, 0x120);
    }
    qv = (s32) D_801531B0;
    func_800254CC(s0v, 0, 0, r & 0xFFFF, qv);
}

void func_800FDC64(s32 arg0, u16 *arg1) {
    s32 r;

    r = func_8002398C(0, 0, (s32) (s16) (arg1[0] & 0xFFC0),
                      (s32) (s16) (arg1[1] & 0xFF00));
    func_800254CC((s32 *) arg0, 0, 0, r & 0xFFFF, (s32) D_801531B0);
}

s32 func_800FDCD8(void) {
    return 0;
}

void func_800FDCE0(void) {
}

extern void func_800FDCF0(void *, void *, void *, void *);

void func_800FDCE8(void) {
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FDCF0);

extern void func_800FE37C();
extern void func_800FE0EC();

void func_800FDF38(s32 arg0, void *arg1, s16 *arg2, s32 arg3) {
    register s32 s4v asm("s4");
    register u8 *s3v asm("s3");
    register s16 *s1v asm("s1");
    register s32 s5v asm("s5");
    register s32 s2v asm("s2");
    register u8 *s0v asm("s0");
    s32 v1v;
    volatile s32 pad[2];

    s4v = arg0;
    KEEP_NOVOL(s4v);
    s3v = (u8 *) arg1;
    KEEP_NOVOL(s3v);
    s1v = arg2;
    KEEP_NOVOL(s1v);
    s5v = arg3;
    KEEP_NOVOL(s5v);
    s2v = 0;
    if (s5v <= 0) {
        return;
    }
    s0v = (u8 *) arg1 + 8;
    do {
        s1v[0] = *(u16 *) s3v;
        s1v[1] = *(u16 *) (s0v - 6);
        v1v = *(s16 *) (s0v + 2);
        if (v1v == 0) {
            func_800FE37C(*(s16 *) *(s32 *) (s0v - 4), *(s16 *) s0v, s4v, s1v);
        } else if (v1v == 1) {
            func_800FE0EC(*(s16 *) *(s32 *) (s0v - 4), *(s16 *) s0v, s4v, s1v);
        }
        s0v = s0v + 0xC;
        s2v++;
        s3v = s3v + 0xC;
    } while (s2v < s5v);
}

extern void func_800FF284();
extern s32 D_80153270;

void func_800FE014(s32 a0, s32 a1, s32 a2, u16 *a3) {
    register s32 s3 asm("s3");
    register s32 s2 asm("s2");
    register u16 *s1 asm("s1");
    register s32 s0 asm("s0");
    register s32 v1 asm("v1");
    s32 s;
    s32 a3v;
    s32 r;
    s32 x;
    s32 t;
    u16 h;

    s3 = a2;
    s2 = 0x66666667;
    s1 = a3;
    a1 = (a1 & 0xFF) - 1;
    t = a1 * 6;
    h = *s1;
    h += t;
    *s1 = h;
    do {
        __asm__ volatile("mult %0,%1" ::"r"(a0), "r"(s2));
        s = a0 >> 31;
        __asm__ volatile("addu %0,%1,$zero" : "=r"(a1) : "r"(s3));
        __asm__ volatile("addu %0,%1,$zero" : "=r"(a2) : "r"(s1));
        v1 = D_801CD66C;
        a3v = D_80153270;
        __asm__ volatile("mfhi %0" : "=r"(s0));
        s0 >>= 2;
        s0 -= s;
        r = a0 - s0 * 10;
        x = r * 35;
        func_800FF284(x + v1, a1, a2, a3v);
        t = *s1 - 6;
        a0 = s0;
        *s1 = t;
    } while (a0 != 0);
    KEEP(s0);
    D_80153270 = 0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FE0EC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FE37C);

extern u16 D_80156C30[];
extern u16 D_80156C20[];
extern void func_800FEFF0();
extern void func_800FE818();

void func_800FE6E8(s32 arg0, void *arg1) {
    s32 a0v = D_801CD830;
    u16 x = ((u16 *) arg1)[0];
    u16 y = ((u16 *) arg1)[1];

    ((u16 *) arg1)[0] = x - 2;
    ((u16 *) arg1)[1] = y + 2;
    func_800FEFF0(a0v, arg0, (s32) D_80156C30, arg1);
    ((u16 *) arg1)[1] = ((u16 *) arg1)[1] + 4;
    func_800FEFF0(D_801CD830, arg0, (s32) D_80156C20, arg1);
}

void func_800FE774(void) {
    s32 a0v;
    s32 a1v;
    s32 a2v;
    s32 a3v;

    D_801CD78C = &func_800FE818;
    a3v = 0;
    func_80100384(a0v, a1v, a2v, a3v);
}

void func_800FE7A4(void) {
    s32 a0v;
    s32 a1v;
    s32 a2v;
    s32 a3v;

    D_801CD78C = &func_800FE818;
    a3v = 1;
    func_80100384(a0v, a1v, a2v, a3v);
}

void func_800FE7D4(s32 arg0, s32 arg1, s32 arg2) {
    D_801CD78C = &func_800FE818;
    func_80100384(0, arg0, arg1, arg2);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FE818);

s32 func_800FEF34(void *arg0, s32 arg1) {
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

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FEFF0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FF284);

void func_800FF3D4(s32 arg0, u32 arg1) {
    __asm__ volatile(
        ".word 0x30880003\n"
        ".word 0x1100000B\n"
        ".word 0x00000000\n"
        ".word 0x10A00019\n"
        ".word 0x00000000\n"
        ".word 0x11000007\n"
        ".word 0x00000000\n"
        ".word 0xA0800000\n"
        ".word 0x20840001\n"
        ".word 0x2108FFFF\n"
        ".word 0x20A5FFFF\n"
        ".word 0x0401FFF7\n"
        ".word 0x00000000\n"
        ".word 0x30A90003\n"
        ".word 0x00052882\n"
        ".word 0x10A00006\n"
        ".word 0x00000000\n"
        ".word 0xAC800000\n"
        ".word 0x20840004\n"
        ".word 0x20A5FFFF\n"
        ".word 0x0401FFFA\n"
        ".word 0x00000000\n"
        ".word 0x11200006\n"
        ".word 0x00000000\n"
        ".word 0xA0800000\n"
        ".word 0x20840001\n"
        ".word 0x2129FFFF\n"
        ".word 0x0401FFFA\n"
        ".word 0x00000000\n" ::: "memory");
}

void func_800FF450(u8 *arg0, u8 *arg1, s32 arg2) {
    __asm__ volatile(".word 0x90a70000\n\t.word 0x00000000\n\t.word 0xa0870000\n\t.word 0x20840001\n\t.word 0x20a50001\n\t.word 0x20c6ffff\n\t.word 0x14c0fff9\n\t.word 0x00000000" ::: "memory");
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FF478);

extern void func_800FF690();

void func_800FF668(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_800FF690(arg0, arg1, arg2, arg3, arg4, 0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FF690);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FF9AC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FFC28);

void func_800FFC38(void) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 t0 asm("t0");
    register s32 t1 asm("t1");
    register s32 t2 asm("t2");
    volatile s32 pad[8];

    *(u16 *) a1 = (u16) v0;
    v0 = *(u16 *) (v1 + 2);
    t1 = a1 + 4;
    *(u16 *) (a1 + 2) = (u16) v0;
    v0 = a2 << 1;
    a0 = *(u16 *) (v1 + 0xC);
    v0 += a1;
    *(u16 *) (v0 - 8) = (u16) a0;
    a0 = *(u16 *) (v1 + 0xE);
    *(u16 *) (v0 - 6) = (u16) a0;
    a0 = *(u16 *) (v1 + 4);
    v1 = a2 - 6;
    t0 = 0;
    if (v1 > 0) {
        do {
            *(u16 *) t1 = (u16) a0;
            t0 += 4;
            t1 += 8;
        } while (t0 < v1);
    }
    v0 = (a3 << 1) + t2;
    a0 = *(u16 *) (v0 + 6);
    t1 = a1 + 6;
    v1 = a2 - 7;
    t0 = 0;
    if (v1 > 0) {
        do {
            *(u16 *) t1 = (u16) a0;
            t0 += 4;
            t1 += 8;
        } while (t0 < v1);
    }
    v0 = (a3 << 1) + t2;
    a0 = *(u16 *) (v0 + 8);
    t1 = a1 + 8;
    v1 = a2 - 8;
    t0 = 0;
    if (v1 > 0) {
        do {
            *(u16 *) t1 = (u16) a0;
            t0 += 4;
            t1 += 8;
        } while (t0 < v1);
    }
    v0 = (a3 << 1) + t2;
    a0 = *(u16 *) (v0 + 10);
    t1 = a1 + 10;
    a2 -= 9;
    t0 = 0;
    if (a2 > 0) {
        do {
            *(u16 *) t1 = (u16) a0;
            t0 += 4;
            t1 += 8;
        } while (t0 < a2);
    }
}

void func_800FFD28(s32 arg0) {
    s32 s1v = arg0;
    s32 s0v = 0;
    volatile s32 pad[2];

    if (s1v > 0) {
        do {
            func_800FFF50();
            s0v++;
        } while (s0v < s1v);
    }
}

extern s32 func_80100084();

void func_800FFD70(s32 arg0, s32 *arg1) {
    s32 s0v;
    s32 s1v;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    s0v = arg0;
    s1v = (s32) arg1;
    v0v = func_80100084();
    v1v = D_8015327C;
    s0v <<= 10;
    s0v += v1v;
    *(s32 *) (s0v + 0x38) = v0v;
    v0v = s0v + 0x3F0;
    *(s32 *) (s0v + 0x3C) = v0v;
    *(s32 *) (s0v + 0x40) = v0v;
    v0v = 1;
    *(s32 *) (s0v + 0x44) = s1v;
    *(s32 *) (s0v + 0x48) = v0v;
    *(s32 *) (s0v + 0x4C) = 0;
    *(s32 *) (s0v + 0x0C) = 0;
    *(s32 *) (s0v + 0x50) = 0;
    *(s32 *) (s0v + 0x54) = 0;
    *(s32 *) (s0v + 0x58) = 0;
    *(s32 *) (s0v + 0x5C) = 0;
    *(s32 *) (s0v + 0x60) = 0;
    *(s32 *) (s0v + 0x64) = 0;
    *(s32 *) (s0v + 0x68) = 0;
}

void func_800FFDF4(s32 arg0) {
    arg0 = D_8015327C + (arg0 << 10);
    *(s32 *) (arg0 + 0x48) = 1;
}

void func_800FFE10(s32 arg0) {
    arg0 = D_8015327C + (arg0 << 10);
    *(s32 *) (arg0 + 0x48) = 0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FFE28);

void func_800FFE38(void) {
    s32 v0v;
    s32 v1v;
    s32 *p;

    MEMORY_BARRIER();
    p = (s32 *) ((v0v << 10) + v1v);
    p[0x12] = 0;
    p[0x13] = 0;
    func_800FFF50();
}

void func_800FFE64(void) {
    u8 *v0;
    s32 v1;

    v1 = 0xFFF;
    v0 = (u8 *) (D_8015327C + 0x3FFC);
    do {
        *(s32 *) v0 = 0;
        v1--;
        v0 -= 4;
    } while (v1 >= 0);
    D_801CD170 = 0;
    *(s32 *) (D_8015327C + 0x48) = 1;
}

void func_800FFEA0(s32 arg0) {
    s32 s0 = arg0 << 10;

    do {
        func_800FFF50();
    } while (*(s32 *) (s0 + D_8015327C + 0x48) != 0);
}

s32 func_800FFEEC(s32 arg0) {
    arg0 = D_8015327C + (arg0 << 10);
    return *(s32 *) (arg0 + 0x48);
}

void func_800FFF08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0 = D_8015327C + (arg0 << 10);
    *(s32 *) (arg0) = arg1;
    *(s32 *) (arg0 + 4) = arg2;
    *(s32 *) (arg0 + 8) = arg3;
}

void func_800FFF28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0 = D_8015327C + (arg0 << 10);
    *(s32 *) (arg0) = arg1;
    *(s32 *) (arg0 + 4) = arg2;
    *(s32 *) (arg0 + 8) = arg3;
    *(s32 *) (arg0 + 0xC) = arg4;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_800FFF50);

s32 func_80100084(void) {
    register s32 gpv asm("gp");
    register s32 v0v asm("v0");

    v0v = gpv;
    __asm__ volatile("" : : "r"(v0v) : "memory");
    return v0v;
}

s32 func_80100090(void) {
    __asm__ volatile(
        "lui $1, %%hi(D_801CD170)\n"
        "addu $1, $1, $0\n"
        "lw $8, %%lo(D_801CD170)($1)\n"
        "nop\n"
        "sll $8, $8, 10\n"
        "lui $1, %%hi(D_8015327C)\n"
        "addu $1, $1, $0\n"
        "lw $9, %%lo(D_8015327C)($1)\n"
        "nop\n"
        "add $8, $8, $9\n"
        "lw $2, 0($8)\n" ::: "memory");
}

s32 func_801000C4(void) {
    __asm__ volatile(
        "lui $1, %%hi(D_801CD170)\n"
        "addu $1, $1, $0\n"
        "lw $8, %%lo(D_801CD170)($1)\n"
        "nop\n"
        "sll $8, $8, 10\n"
        "lui $1, %%hi(D_8015327C)\n"
        "addu $1, $1, $0\n"
        "lw $9, %%lo(D_8015327C)($1)\n"
        "nop\n"
        "add $8, $8, $9\n"
        "lw $2, 4($8)\n" ::: "memory");
}

s32 func_801000F8(void) {
    __asm__ volatile(
        "lui $1, %%hi(D_801CD170)\n"
        "addu $1, $1, $0\n"
        "lw $8, %%lo(D_801CD170)($1)\n"
        "nop\n"
        "sll $8, $8, 10\n"
        "lui $1, %%hi(D_8015327C)\n"
        "addu $1, $1, $0\n"
        "lw $9, %%lo(D_8015327C)($1)\n"
        "nop\n"
        "add $8, $8, $9\n"
        "lw $2, 8($8)\n" ::: "memory");
}

s32 func_8010012C(void) {
    __asm__ volatile(
        "lui $1, %%hi(D_801CD170)\n"
        "addu $1, $1, $0\n"
        "lw $8, %%lo(D_801CD170)($1)\n"
        "nop\n"
        "addi $8, $8, -1\n"
        "sll $8, $8, 10\n"
        "lui $1, %%hi(D_8015327C)\n"
        "addu $1, $1, $0\n"
        "lw $9, %%lo(D_8015327C)($1)\n"
        "nop\n"
        "add $8, $8, $9\n"
        "lw $2, 0x48($8)\n" ::: "memory");
}

s32 func_80100164(s32 arg0) {
    __asm__ volatile(
        "sll $8, $4, 10\n"
        "lui $1, %%hi(D_8015327C)\n"
        "addu $1, $1, $0\n"
        "lw $9, %%lo(D_8015327C)($1)\n"
        "nop\n"
        "add $8, $8, $9\n"
        "lw $2, 0x48($8)\n" ::: "memory");
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80100188);

extern s32 D_801CD82C;

s32 func_801002D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    __asm__ volatile(
        ".word 0x00850018\n"
        ".word 0x00002012\n"
        ".word 0x00002810\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".word 0x00C70018\n"
        ".word 0x00003012\n"
        ".word 0x00003810\n"
        ".word 0x0086402B\n"
        ".word 0x00861023\n"
        ".word 0x00A71823\n"
        ".word 0x00681823\n"
        ".word 0x00034021\n"
        ".word 0x00084303\n"
        ".word 0x11000008\n"
        ".word 0x00000000\n"
        ".word 0x25080001\n"
        ".word 0x11000005\n"
        ".word 0x00000000\n"
        ".word 0x20080001\n"
        "lui $1, %%hi(D_801CD82C)\n"
        "addu $1, $1, $0\n"
        "sw $8, %%lo(D_801CD82C)($1)\n"
        ".word 0x00031D00\n"
        ".word 0x00021302\n"
        ".word 0x00431025\n" ::: "memory");
}

void func_80100348(u8 *arg0, s32 arg1) {
    __asm__ volatile(
        ".word 0x20090000\n"
        ".word 0x200a00fe\n"
        ".word 0x90880000\n"
        ".word 0x10a90008\n"
        ".word 0x00000000\n"
        ".word 0x310800fe\n"
        ".word 0x150a0002\n"
        ".word 0x00000000\n"
        ".word 0x21290001\n"
        ".word 0x20840001\n"
        ".word 0x0401fff7\n"
        ".word 0x00000000\n"
        ".word 0x00041020\n" ::: "memory");
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80100384);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80100430);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80100610);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010088C);

extern s16 D_801AC91C;
extern s16 D_801AC91E;
extern s16 D_801AC920;
extern s16 D_801AC922;

void func_801014FC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_801AC91C = arg0;
    D_801AC91E = arg1;
    D_801AC920 = arg2;
    D_801AC922 = arg3;
}

extern u16 D_801AC92C;
extern u16 D_801AC92E;

void func_80101524(u16 arg0, u16 arg1) {
    D_801AC92C = arg0;
    D_801AC92E = arg1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010153C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80101544);

extern u8 D_80156C8C[];

void func_8010170C(u8 *arg0) {
    *(u16 *) (arg0 + 0x1C) = 0;
    *(u16 *) (arg0 + 0x26) = 0;
    func_800FF450(arg0 + 0x20, D_80156C8C, 8);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80101740);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80101CD0);

void func_8010226C(void) {
loop_1:
    func_800FFF50();
    goto loop_1;
}

void func_80102294(void) {
    func_800FFF50();
    func_800FFE28();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801022BC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80102928);

extern u16 D_801570F4;
extern s32 D_801AE3D4;
extern s32 *D_801CD920;

void func_80102C50(void) {
    extern void func_800FFE10(s32);
    extern void func_800FFEA0(s32);
    extern void func_800FFDF4(s32);

    D_80153258 = 1;
    D_8015332C = 2;
    func_800FFE10(D_801CD170 + 1);
    func_800FFE10(D_801CD170 + 2);
    func_800FFE10(D_801CD170 + 3);
    func_800FFE10(D_801CD170 + 4);
    for (;;) {
        D_8015332E = D_801570F4 + 0x64;
        if (*(u16 *) &D_80153330 != 0) {
            break;
        }
        func_800FFF50();
    }
    D_80153330 = 0;
    D_8015332E = 0;
    func_800F0F64(0, 0xFF, 0xFF);
    func_800FFEA0(0xD);
    func_800FFEA0(0xC);
    func_800FFEA0(0xB);
    func_800FFEA0(0xA);
    D_801CD920 = &D_801AE3D4;
    func_800FFDF4(D_801CD170 + 1);
    func_800FFDF4(D_801CD170 + 2);
    func_800FFDF4(D_801CD170 + 3);
    func_800FFDF4(D_801CD170 + 4);
    D_80153258 = 0;
    D_8015332C = 0;
    func_800FFE28();
}

extern s32 func_80100164();
extern s16 D_801570F6;
extern s32 D_801570BC;
extern s32 D_801570EC;
extern s32 D_80156DBC;
extern void func_80102928();
extern s32 func_8010088C();

void func_80102D98(void) {
    s32 *temp_s1;

    temp_s1 = D_801CD7E0;
    D_801570F6 = 0x13;
    D_801CD7E0 = &D_801570BC;
    D_801570EC = &D_80156DBC;
    func_80102928(&D_801570BC);
    func_800FFD70(D_801CD170 - 2, &func_8010088C);
    func_800FFF08(D_801CD170 - 2, &D_801570BC, 0, 0);
    for (;;) {
        func_800FFF50();
        if (func_80100164(D_801CD170 - 2) == 0) {
            if (func_80100164(D_801CD170 - 3) == 0) {
                break;
            }
        }
    }
    D_801CD7E0 = temp_s1;
    func_800FFE28();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80102E78);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80103080);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801041B8);

extern s32 D_801AECC0;

void func_8010482C(void) {
    func_800FF450(&D_801CD8A4, &D_801AECC0, 0x80);
    func_80044600(D_80010010);
    D_80153310 = 0;
    func_800FFE28();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010487C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80104884);

s32 func_80105600(void) {
    register s32 v1 asm("v1");
    register s32 a1 asm("a1");
    register s32 base asm("v0");
    register u8 *p asm("a0");

    v1 = 4;
    a1 = 1;
    base = D_8015327C;
    p = (u8 *) base + 0x1000;
loop:
    if (*(s32 *) (p + 0x48) != a1) {
        v1++;
        p += 0x400;
        if (v1 < 9) {
            goto loop;
        }
    }
    return v1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010563C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80105E04);

extern s32 D_8004D950;
extern volatile s32 D_8004D950_v asm("D_8004D950");
extern s16 D_801531CA;
extern u16 D_8016E498[];
extern s16 D_8016E500[];

void func_80105F7C(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");

    v0v = (s32) D_801CD7E0;
    v0v = *(s16 *) (v0v + 0x1A0);
    a1v = v0v << 1;
    v1v = *(s16 *) ((u8 *) D_8016E500 + a1v);
    v0v = 4;
    a0v = 0x33;
    if (v1v != v0v) {
        v1v = *(u16 *) ((u8 *) D_8016E498 + a1v);
        D_80153298 = 1;
        D_801531C8 = 0;
        v1v += 0x7000;
        D_801531CA = v1v;
        a0v = 0x33;
        a1v = (s16) v1v;
        a2v = 0;
        a3v = 1;
        func_800EF25C(a0v, a1v);
        a0v = D_801CD170;
        a1v = 0;
        a2v = 0;
        a3v = 1;
        v0v = D_8004D950_v;
        KEEP(v0v);
        v0v |= 0x4000;
        D_8004D950 = v0v;
        a0v += 1;
        func_800FFF08(a0v, a1v, a2v, a3v);
        a0v = D_801CD170 + 2;
        a1v = 0;
        a2v = 0;
        a3v = 1;
        func_800FFF08(a0v, a1v, a2v, a3v);
    } else {
        D_80153298 = 5;
    }
    D_80153270 = 0;
    func_800FFE28();
}

extern u8 D_8016E594[];
extern u8 D_8016E68C[];
extern s16 D_8016E86C;
extern s16 D_8016E86E;
extern s16 D_801AED74[];

void func_8010606C(s32 unused0, s16 *arg1, s32 unused2, s32 arg3) {
    s32 v0v;
    s32 v1v;
    s32 a0v;
    s16 *a1v;
    s32 a2v;
    s32 a3v = arg3;
    s32 index;
    volatile s32 pad;
    v0v = (s32) D_801CD7E0;

    v0v = *(s16 *) (v0v + 0x254);
    v1v = v0v << 2;
    a2v = D_8016E594[v0v];
    v0v = *(s32 *) &D_8016E68C[v1v];
    a0v = 0;
    a1v = arg1;
    if (a2v != 0) {
        a3v = 0x902B;
        a1v = &D_801AED74;
        v1v = v0v;
        do {
            v0v = *(u8 *) v1v;
            v1v += 1;
            a0v += 1;
            v0v += a3v;
            a1v[0] = v0v;
            a1v += 1;
        } while (a0v < a2v);
    }
    if (a2v < 7) {
        D_8016E86C = a2v;
        D_8016E86E = 0;
    } else {
        D_8016E86C = 7;
        D_8016E86E = a2v - 7;
    }
    func_800EDAA8(a0v, a1v, a2v, a3v);
}

extern s16 D_8016EA34;

void func_80106128(s32 arg0) {
    D_8016EA34 = arg0;
}

void func_80106138(void) {
}

extern s32 D_80189C4C;
extern s32 D_80189C54;
extern s32 D_80189C5C;
extern s32 D_80189C64;
extern s32 func_800246D4(s32);
extern s32 func_800449CC(s32);
extern s32 func_80044990();

void func_80106140(void) {
    s32 s0v;
    s32 v0v;

    v0v = (s32) &func_80044990;
    D_801CD78C = (s32 *) v0v;
    s0v = func_80100384(0x18BA, 0x20000);
    func_800248FC(&D_80189C4C, s0v);
    func_800248FC(&D_80189C54, s0v + 0x8000);
    func_800248FC(&D_80189C5C, s0v + 0x10000);
    func_800248FC(&D_80189C64, s0v + 0x18000);
    func_800246D4(0);
    func_800449CC(s0v);
}

extern u8 D_800473A8;
extern s32 D_801CD78Cv asm("D_801CD78C");
extern s32 D_80189CAC;
extern s32 D_8016ED44;
extern s32 D_8016ED4C;
extern s32 D_8016ED54;
extern s32 D_8016ED64;
extern s32 D_8016ED84;
extern s32 D_8016ED8C;
extern s32 D_8016ED94;
extern s32 D_8016ED9C;
extern s32 func_80044990a asm("func_80044990");

void func_801061E0(s32 arg0) {
    s32 v0v;
    s32 s0v;
    s32 s1v;
    s32 s2v;

    v0v = D_800473A8;
    s2v = arg0;
    if (v0v == 0) {
        D_801CD78Cv = (s32) &func_80044990a;
        s0v = func_80100384(0x1899, 0x8800);
        func_800248FC(&D_8016ED64, s0v);
        func_800248FC(&D_8016ED8C, s0v + 0x8000);
        func_800246D4(0);
        func_800449CC(s0v);
        D_800473A8 += 1;
    }
    func_800248FC(&D_8016ED84, &D_80189CAC);
    func_800246D4(0);
    s1v = (s32) &func_80044990a;
    D_801CD78Cv = s1v;
    s0v = func_80100384(0xE68, 0x9800);
    func_800248FC(&D_8016ED54, s0v + 0x1000);
    func_800248FC(&D_8016ED44, s0v + 0x9000);
    func_800248FC(&D_8016ED4C, s0v + 0x9200);
    func_800F0520(D_801CD830 + 0x1000);
    func_800246D4(0);
    func_800449CC(s0v);
    if (s2v != 0) {
        D_801CD78Cv = s1v;
        s0v = func_80100384(0x166B, 0x10000);
        func_800248FC(&D_8016ED94, s0v);
        func_800248FC(&D_8016ED9C, s0v + 0x8000);
        func_800246D4(0);
        func_800449CC(s0v);
    }
}

extern s32 D_8016E478;
extern s32 D_8016E47C;

void func_80106374(s32 arg0, s32 arg1) {
    D_8016E478 = arg0 + 0xA000;
    D_8016E47C = arg1;
}

extern s32 D_8016E480;
extern s32 D_8016E484;

void func_80106394(s32 arg0) {
    D_8016E480 = arg0;
    D_8016E484 = 0;
}

extern s32 D_8016E90C;
extern s32 *D_801CD7E0_p asm("D_801CD7E0");
extern s32 D_801CD8A4_p[] asm("D_801CD8A4");

void func_801063AC(void) {
    extern void func_800EF25C(s32, s32);
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");

    func_800F290C();
    a0v = 0x1C18;
    a1v = 0x5800;
    MEMORY_BARRIER();
    v0v = (s32) &func_80044954;
    s0v = (s32) &D_801AED8C;
    D_801CD78C_p = (s32 *) v0v;
    func_80100384(a0v, a1v, &D_801AED8C);
    func_800F2998();
    func_800EF25C(0x1FE, 0);
    a0v = 0;
    a1v = s0v + 0x80;
    v1v = (s32) D_801CD8A4_p;
    v0v = (s32) &D_8016E90C;
    D_801CD7E0_p = (s32 *) v0v;
    do {
        v0v = *(s32 *) s0v;
        s0v += 4;
        a0v += 1;
        v0v += a1v;
        *(s32 *) v1v = v0v;
        v0v = a0v < 0x20;
        v1v += 4;
    } while (v0v != 0);
    func_800EF25C(0x1FF, 0);
    func_800EF25C(0x34, 1);
    func_800EF25C(0x35, 0);
    func_800EF25C(0x36, 1);
}

extern void func_801061E0();
extern void func_80106140();
extern s32 D_8016E1A0;
extern s32 *D_801CD8EC;

void func_8010647C(void) {
    extern void func_800EF25C(s32, s32);
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");

    func_800F290C();
    func_801061E0(1);
    func_80106140();
    a0v = 0x1BD8;
    a1v = 0xE800;
    MEMORY_BARRIER();
    v0v = (s32) &func_80044954;
    s0v = (s32) &D_801AED8C;
    D_801CD78C_p = (s32 *) v0v;
    func_80100384(a0v, a1v, &D_801AED8C);
    func_800F2998();
    func_800EF25C(0x1FE, 0);
    a0v = 0;
    a1v = s0v + 0x80;
    v1v = (s32) D_801CD8A4_p;
    v0v = (s32) &D_8016E90C;
    D_801CD7E0_p = (s32 *) v0v;
    do {
        v0v = *(s32 *) s0v;
        s0v += 4;
        a0v += 1;
        v0v += a1v;
        *(s32 *) v1v = v0v;
        v0v = a0v < 0x20;
        v1v += 4;
    } while (v0v != 0);
    D_801CD8EC = (s32 *) &D_8016E1A0;
    func_800EF25C(0x1FF, 0);
    func_800EF25C(0x34, 1);
    func_800EF25C(0x35, 0);
    func_800EF25C(0x36, 1);
}

void func_8010656C(void) {
    extern void func_800EF25C(s32, s32);
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");

    D_801CD170 = 0;
    func_800F290C();
    func_801061E0(0);
    a0v = 0x1BD8;
    a1v = 0xE800;
    MEMORY_BARRIER();
    v0v = (s32) &func_80044954;
    s0v = (s32) &D_801AED8C;
    D_801CD78C_p = (s32 *) v0v;
    func_80100384(a0v, a1v, &D_801AED8C);
    func_800F2998();
    func_800EF25C(0x1FE, 0);
    a0v = 0;
    a1v = s0v + 0x80;
    v1v = (s32) D_801CD8A4_p;
    v0v = (s32) &D_8016E90C;
    D_801CD7E0_p = (s32 *) v0v;
    do {
        v0v = *(s32 *) s0v;
        s0v += 4;
        a0v += 1;
        v0v += a1v;
        *(s32 *) v1v = v0v;
        v0v = a0v < 0x20;
        v1v += 4;
    } while (v0v != 0);
    D_801CD8EC = (s32 *) &D_8016E1A0;
    func_800EF25C(0x1FF, 0);
    func_800EF25C(0x34, 1);
    func_800EF25C(0x35, 0);
    func_800EF25C(0x36, 1);
}

extern void func_80024868();
extern s32 func_800EF1A8();
extern void func_8010647C();
extern void func_80106998();
extern void func_80106A28();
extern void func_80113748();
extern u8 D_800473A1;
extern u8 D_800473A2;
extern u8 D_800473A3;
extern u8 D_800473A4;
extern u8 D_800473A5;
extern u8 D_800473A6;
extern u32 D_800473AC;
extern u8 D_8016E814[];
extern s32 D_80189EAC;

void func_80106660(void) {
    s32 v1v;
    s32 temp_v1;

    func_80043F00();
    func_80024868(&D_80189EAC, 0, 0, 0);
    func_800246D4(0);
    func_8001DBA8(0);
    func_8010647C();
    func_800246D4(0);
    func_8001DBA8(0);
    func_80106998();
    func_800246D4(0);
    func_8001DBA8(0);
    temp_v1 = ((D_800473AC >> 9) & 7) * 6;
    v1v = temp_v1;
    D_800473A1 = D_8016E814[v1v];
    D_800473A2 = D_8016E814[v1v + 1];
    D_800473A3 = D_8016E814[v1v + 2];
    D_800473A4 = D_8016E814[v1v + 3];
    D_800473A5 = D_8016E814[v1v + 4];
    D_800473A6 = D_8016E814[v1v + 5];
    func_80106A28(0x80, 0x80, 0x80);
    func_80113748(0, 0);
    func_80106998();
    func_80024868(&D_80189EAC, 0, 0, 0);
    func_800246D4(0);
    func_800EF25C(0x27, func_800EF1A8(0x55));
    func_800EF25C(0x55, 0);
    if (func_800EF1A8(0x64) != 0) {
        func_800EF25C(0x64, 0);
    }
}

extern s32 D_8016E494;

s32 func_801067F0(void) {
    s32 temp_v0;

    temp_v0 = D_8016E494;
    D_8016E494 = 0;
    return temp_v0;
}

extern s32 D_8015331C;

s32 func_80106808(void) {
    return D_8015331C;
}

void func_80106818(s32 arg0) {
    arg0 = D_8015327C + (arg0 << 10);
    *(s32 *) (arg0 + 0x4C) = 3;
}

void func_80106834(s32 arg0) {
    register s32 a0 asm("a0") = arg0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v0 = D_8015327C;
    a0 <<= 10;
    a0 += v0;
    v1 = *(s32 *) (a0 + 0x4C);
    v0 = 0x33;
    if (v1 == v0) {
        v0 = 1;
        *(s32 *) (a0 + 0x4C) = v0;
        v0 = 0xFFFF;
        *(s32 *) (a0 + 4) = v0;
    }
}

s32 func_80106868(s32 arg0) {
    arg0 = D_8015327C + (arg0 << 10);
    return *(s32 *) (arg0 + 0x4C) == 1;
}

void func_8010688C(void) {
loop_1:
    func_800FFF50();
    goto loop_1;
}

extern void func_8010688C();

void func_801068B4(void) {
    s32 s0 = 8;
    s32 basev;
    s32 *p;

    do {
        basev = D_8015327C;
        p = (s32 *) ((s0 << 10) + basev);
        if (p[0x12] == 0) {
            func_800FFD70(s0, (s32) &func_8010688C);
        }
        s0--;
    } while (s0 >= 5);
}

extern s32 D_8016E490;

void func_80106918(void) {
    D_8016E490 = 1;
}

void func_8010692C(void) {
    extern void func_800FFE10(s32);
    s32 s0 = 8;
    s32 basev;
    s32 *p;

    do {
        basev = D_8015327C;
        p = (s32 *) ((s0 << 10) + basev);
        if (p[0x12] == 0) {
            func_800FFE10(s0 + 1);
        }
        s0--;
    } while (s0 >= 5);
}

void func_80106988(void) {
    D_8016E490 = 0;
}

extern void func_800E8660(s32 *);
extern void func_80108920();

void func_80106998(void) {
    func_800246D4(0);
    func_800F290C();
    func_800F2998();
    func_800E8660(&D_801AED8C);
    func_80108920();
    func_800246D4(0);
    D_801CD7E0 = &D_8016E90C;
    D_801CD8EC = &D_8016E1A0;
    D_80153270 = 0;
}

extern s32 D_80189EB4;
extern s32 D_80189EB8;

void func_80106A10(s32 arg0, s32 arg1) {
    D_80189EB4 = arg0;
    D_80189EB8 = arg1;
}

extern s32 D_80189EC0;
extern s32 D_80189EC4;
extern s32 D_80189EC8;

void func_80106A28(s32 arg0, s32 arg1, s32 arg2) {
    D_80189EC0 = arg0;
    D_80189EC4 = arg1;
    D_80189EC8 = arg2;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80106A48);

void func_80106F44(void) {
    func_80102E78(0);
}

void func_80106F64(void) {
    s32 a0v;
    s32 v0v;
    s32 v1v;

    func_800FFD70(D_801CD170 - 1, &func_80106F44);
    v0v = D_801CD170;
    a0v = v0v - 1;
    v1v = D_8015327C;
    v0v <<= 10;
    func_800FFF08(a0v, *(s32 *) (v0v + v1v), 0, 0);
    func_800FFEA0(D_801CD170 - 1);
    func_800FFE28();
}

extern void func_800FDA54();
extern s16 D_8016E460;
extern s32 D_801AED44;

void func_80106FD8(void) {
    D_8016E460 = 1;
    D_801AED44 = 0;
    func_800FDA54(&D_801AED44);
    func_800FFE28();
}

extern s16 D_8016E45E;
extern s16 D_8016E466;

void func_8010701C(void) {
    D_8016E45E = 1;
    D_801AED44 = 0;
    func_800FDA54(&D_801AED44);
    func_800FFE28();
}

extern s16 D_8016E464;

void func_80107060(void) {
    D_8016E466 = 1;
    D_801AED44 = 0;
    func_800FDA54(&D_801AED44);
    func_800FFE28();
}

void func_801070A4(void) {
    D_8016E464 = 1;
    D_801AED44 = 0;
    func_800FDA54(&D_801AED44);
    func_800FFE28();
}

extern s16 D_8016E45C;

void func_801070E8(void) {
    D_8016E45C = 1;
    D_801AED44 = 0;
    func_800FDA54(&D_801AED44);
    func_800FFE28();
}

extern s16 D_8016E462;

void func_8010712C(void) {
    D_8016E462 = 1;
    D_801AED44 = 0;
    func_800FDA54(&D_801AED44);
    func_800FFE28();
}

extern s32 D_801BF00C;

void func_80107170(void) {
    D_801BF00C = D_8004D950;
    D_8004D950 |= 0x3E70;
}

void func_80107194(void) {
    D_8004D950 = D_801BF00C;
}

extern s32 D_800BBC6C;
extern s32 D_8016E908;

void func_801071AC(void) {
    D_8004D950 += 3;
    func_800EF25C(0x1FE, 1);
    func_800EF25C(0x27, 0);
    func_800EF25C(0x30, 0);
    func_800EF25C(0x22, 0);
    func_800EF25C(0x23, 0);
    func_800EF25C(0x24, 0);
    D_800BBC6C = D_8016E908;
    func_800FFE28();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80107238);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80107240);

extern void func_80113748(s32, s32);
extern s16 D_8016E458;

void func_80107424(s32 arg0) {
    s32 s0 = arg0;
    s32 v0;

    func_80106998();
    func_80113748(s0 + 1, 0);
    func_80106998();
    D_8016E458 = 0;
    v0 = (s32) &D_8016E90C;
    D_801CD7E0 = (s32 *) v0;
}

extern void func_80069400();

void func_80107478(void) {
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 tv asm("v0");
    volatile s32 pad[2];
    v1v = D_8016E45E;

    MEMORY_BARRIER();
    a0v = v1v;
    if (v1v != 0) {
        if (v1v == 1) {
            D_8016E458 = 1;
            func_80069400(0x12, 0x10);
            D_8016E45E = D_8016E45E + 1;
        } else if (v1v == 2) {
            tv = D_8004D950;
            if ((tv & 8) == 0) {
                D_8016E45E = a0v + 1;
                __asm__ volatile("" : : "0"(a0v));
            }
        } else {
            func_80106998();
            func_80106A28(0x80, 0x80, 0x80);
            tv = D_8004D950;
            D_8016E45E = 0;
            D_8004D950 = tv | 0x100000;
        }
    }
}

void func_8010754C(void) {
    s32 v1v;
    s32 v0;
    v1v = D_8016E464;

    if (v1v != 0 && v1v == 1) {
        D_8016E458 = 1;
        func_80106998();
        func_80106A28(0x80, 0x80, 0x80);
        v0 = D_8004D950;
        D_8016E464 = 0;
        v0 |= 0x800000;
        D_8004D950 = v0;
    }
}

extern void func_80106A28(s32, s32, s32);

void func_801075BC(void) {
    s32 v0v;
    register s32 v1v asm("v1");
    register s32 s0v asm("s0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    v1v = D_8016E466;

    if (v1v == 0) {
        goto end;
    }
    if (v1v != 1) {
        goto end;
    }
    D_8016E458 = 1;
    func_80106998();
    a0v = 0x1BD8;
    a1v = 0xE800;
    KEEP_WITH(a0v, a1v);
    s0v = (s32) &D_801AED8C;
    KEEP_WITH(s0v, a0v);
    v0v = (s32) &func_80044954;
    D_801CD78C = v0v;
    func_80100384(a0v, a1v, s0v);
    func_800E8660((s32 *) s0v);
    func_80106A28(0x80, 0x80, 0x80);
    v0v = D_8004D950;
    v1v = 0x01000000;
    D_8016E466 = 0;
    v0v |= v1v;
    D_8004D950 = v0v;
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80107664);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010766C);

extern u16 D_8016E462u asm("D_8016E462");

void func_80107884(void) {
    s32 v1v;
    s32 a0v;
    s32 tv;
    volatile s32 pad[2];

    v1v = D_8016E462;
    MEMORY_BARRIER();
    a0v = v1v;
    if (v1v != 0) {
        __asm__ volatile("" : "=r"(a0v) : "0"(a0v));
        if (v1v == 1) {
            D_8016E458 = 1;
            a0v = 0x12;
            func_80069400(a0v, 0x10);
            D_8016E462u = D_8016E462u + 1;
        } else if (v1v == 2) {
            tv = D_8004D950;
            if ((tv & 8) == 0) {
                D_8016E462 = a0v + 1;
            }
        } else if (v1v == 3) {
            func_80106998();
            tv = D_8004D950;
            D_8016E462 = 0;
            D_8004D950 = tv | 0x100;
        }
    }
}

extern s32 D_8016E46C;
extern s32 D_8016E468;
extern s32 D_8016E470;
extern s32 D_8016E474;
extern s32 D_8016E488;
extern s16 D_8016E98C;
extern s16 D_8016E98E;
extern s16 D_8016E9A0;
extern s32 func_80107A14;

void func_8010794C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0v = arg0;
    s32 v0v;
    s32 v1v = arg1;
    s32 a1v;

    v0v = D_8016E458;
    if (v0v != 0) {
        goto end;
    }
    v0v = D_8016E46C;
    if (v0v != v1v) {
        v0v = D_8015327C;
        *(s32 *) ((u8 *) v0v + 0x304C) = 0;
    }
    a1v = (s32) &func_80107A14;
    KEEP(a1v);
    v0v = 0x9000;
    v0v += v1v;
    D_8016E488 = v0v;
    v0v = v1v - 0x7000;
    D_8016E468 = s0v;
    D_8016E46C = v1v;
    D_8016E470 = arg2;
    D_8016E474 = arg3;
    D_8016E9A0 = (s16) v0v;
    D_8016E98C = (s16) arg2;
    D_8016E98E = (s16) arg3;
    func_800FFD70(2, (s32 *) a1v);
    func_800FFF08(2, s0v, 0, 0);
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80107A14);

void func_80107C90(void *arg0, void *arg1, void *arg2) {
    s32 s0v = (s32) arg1;
    s32 s1v;
    s32 v0v;
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");

    KEEP_NOVOL(s0v);
    v0v = *(u16 *) s0v;
    v1v = (s32) arg0;
    *(volatile u16 *) v1v = v0v;
    v0v = *(u16 *) (s0v + 2);
    *(volatile u16 *) (v1v + 2) = v0v;
    v0v = *(u16 *) (s0v + 4);
    v0v <<= 16;
    v0v >>= 18;
    *(volatile u16 *) (v1v + 4) = v0v;
    s1v = (s32) arg2;
    v0v = *(u16 *) (s0v + 6);
    *(u16 *) (v1v + 6) = v0v;
    a0v = s1v;
    func_800E2444((void *) a0v);
    a0v = s1v;
    v0v = 0x7C3C;
    KEEP(v0v);
    a1v = s0v;
    a2v = a1v + 8;
    a3v = a1v + 0x10;
    KEEP_WITH_NOVOL(a2v, a3v);
    *(u16 *) (a0v + 0xE) = v0v;
    func_800FDCF0((void *) a0v, (void *) a1v,
                  (void *) a2v, (void *) a3v);
}

void func_80107D14(void *arg0, void *arg1) {
    u8 *s1v;
    u8 *s0v;
    s32 v0v;
    s32 v1v;

    s0v = (u8 *) arg1;
    s1v = (u8 *) arg0;
    func_800E2444(s0v);
    v0v = 0x7D7C;
    *(s16 *) (s0v + 0xE) = v0v;
    v1v = *(s16 *) (s1v + 0x2C);
    v0v = 1;
    if (v1v == v0v) {
        v0v = *(u16 *) (s1v + 8);
        *(u16 *) (s0v + 8) = v0v;
        v1v = *(u16 *) (s1v + 0xA);
        *(u8 *) (s0v + 0xC) = 0xA8;
        *(u8 *) (s0v + 0xD) = 0x88;
        *(u16 *) (s0v + 0x10) = 0x28;
        *(u16 *) (s0v + 0x12) = 8;
        v1v -= 1;
    } else if (v1v == 2) {
        v0v = *(u16 *) (s1v + 8);
        v0v -= 6;
        *(u16 *) (s0v + 8) = v0v;
        v1v = *(u16 *) (s1v + 0xA);
        *(u8 *) (s0v + 0xC) = 0xA8;
        *(u8 *) (s0v + 0xD) = 0x78;
        *(u16 *) (s0v + 0x10) = 0x28;
        *(u16 *) (s0v + 0x12) = 0x10;
        v1v -= 6;
    } else {
        goto end;
    }
    *(s16 *) (s0v + 0xA) = v1v;
end:
    s0v += 0x14;
    func_800E2444(s0v);
    v0v = 0x10;
    *(u16 *) (s0v + 0x10) = v0v;
    *(u16 *) (s0v + 0x12) = v0v;
    v0v = 0x7D7C;
    *(s16 *) (s0v + 0xE) = v0v;
}

extern s32 D_80189F60;

void func_80107E00(s32 arg0) {
    D_80189F60 = arg0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80107E10);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80107E18);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80108388);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010849C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801085A0);

void func_801085B0(void) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 t0 asm("t0");
    register s32 t1 asm("t1");
    register s32 t2 asm("t2");
    volatile s32 pad[8];

    *(u16 *) a1 = (u16) v0;
    v0 = *(u16 *) (v1 + 2);
    t1 = a1 + 4;
    *(u16 *) (a1 + 2) = (u16) v0;
    v0 = a2 << 1;
    a0 = *(u16 *) (v1 + 0xC);
    v0 += a1;
    *(u16 *) (v0 - 8) = (u16) a0;
    a0 = *(u16 *) (v1 + 0xE);
    *(u16 *) (v0 - 6) = (u16) a0;
    a0 = *(u16 *) (v1 + 4);
    v1 = a2 - 6;
    t0 = 0;
    if (v1 > 0) {
        do {
            *(u16 *) t1 = (u16) a0;
            t0 += 4;
            t1 += 8;
        } while (t0 < v1);
    }
    v0 = (a3 << 1) + t2;
    a0 = *(u16 *) (v0 + 6);
    t1 = a1 + 6;
    v1 = a2 - 7;
    t0 = 0;
    if (v1 > 0) {
        do {
            *(u16 *) t1 = (u16) a0;
            t0 += 4;
            t1 += 8;
        } while (t0 < v1);
    }
    v0 = (a3 << 1) + t2;
    a0 = *(u16 *) (v0 + 8);
    t1 = a1 + 8;
    v1 = a2 - 8;
    t0 = 0;
    if (v1 > 0) {
        do {
            *(u16 *) t1 = (u16) a0;
            t0 += 4;
            t1 += 8;
        } while (t0 < v1);
    }
    v0 = (a3 << 1) + t2;
    a0 = *(u16 *) (v0 + 10);
    t1 = a1 + 10;
    a2 -= 9;
    t0 = 0;
    if (a2 > 0) {
        do {
            *(u16 *) t1 = (u16) a0;
            t0 += 4;
            t1 += 8;
        } while (t0 < a2);
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801086A0);

extern s32 D_801CD8C4;
extern s32 D_80189F6C;

void func_80108920() {
    u8 *s0v;
    s32 s1v;
    s32 s2v;
    s32 s3v;
    u8 *p;
    u8 *q;
    s32 v1v;
    s32 v0v;

    s0v = (u8 *) D_801CD8C4;
    s1v = 0;
    s2v = 0xFE;
    s3v = 0xF;
    do {
        p = func_80059AF0(s1v);
        if (p[1] == 0xFF) {
            *s0v = 0xFE;
            s0v++;
        } else {
            for (v1v = 0; v1v < 0x10; v1v++) {
                q = p + v1v;
                v0v = q[0xBE];
                *s0v = v0v;
                if ((v0v & 0xFE) == 0xFE) {
                    s0v++;
                    break;
                }
                s0v++;
                if (v1v == 0xF) {
                    *s0v = 0xFE;
                    s0v++;
                }
            }
        }
    } while (++s1v < 0x14);
    D_80189F6C = D_80189F6C + 1;
}

extern s32 D_80153318;

void func_801089F8(s32 arg0) {
    D_80153318 = arg0;
}

extern s32 D_801BF440;

void func_80108A08(s32 arg0) {
    D_801BF440 = arg0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80108A18);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80108CE8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80108CF0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80108F9C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80108FA4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801090C8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80109248);

void func_80109358(s32 arg0) {
    arg0 = D_8015327C + (arg0 << 10);
    *(s32 *) (arg0 + 0x60) = 1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80109374);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80109554);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801097DC);

extern s16 D_801C000C;
extern s16 D_801C000E;
extern s16 D_801C0010;
extern s16 D_801C0012;

void func_8010A480(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_801C000C = arg0;
    D_801C000E = arg1;
    D_801C0010 = arg2;
    D_801C0012 = arg3;
}

extern u16 D_801C001C;
extern u16 D_801C001E;

void func_8010A4A8(u16 arg0, u16 arg1) {
    D_801C001C = arg0;
    D_801C001E = arg1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010A4C0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010A4C8);

extern u8 D_8016E44C[];

void func_8010A690(u8 *arg0) {
    *(u16 *) (arg0 + 0x1C) = 0;
    *(u16 *) (arg0 + 0x26) = 0;
    func_800FF450(arg0 + 0x20, D_8016E44C, 8);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010A6C4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010AC68);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010B204);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010B340);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010B54C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010B55C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010B7E8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010BDF8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010C488);

extern s32 func_8010BDF8();
extern void func_8010B7E8();

void func_8010C5B4(s32 arg0, s32 arg1) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    s1v = arg1;
    s2v = (s32) &func_8010BDF8;
loop:
    v0v = a0v << 4;
    v0v -= a0v;
    v1v = (s32) D_801CD7E0;
    v0v <<= 2;
    s0v = v0v + v1v;
    a1v = *(s32 *) (s0v + 0x28);
    a0v = s1v;
    func_800FFD70(a0v, a1v);
    a0v = s1v;
    a1v = s0v;
    a2v = 0;
    a3v = 0;
    func_800FFF08(a0v, a1v, a2v, a3v);
    v1v = *(s32 *) (s0v + 0x28);
    if (v1v == s2v) {
        goto end;
    }
    v0v = (s32) &func_8010B7E8;
    if (v1v == v0v) {
        goto end;
    }
    v0v = *(s16 *) (s0v + 0x38);
    v1v = *(s32 *) (s0v + 0x24);
    v0v <<= 1;
    v0v += v1v;
    a0v = *(s16 *) v0v;
    v0v = (u32) a0v < 0x3E8U;
    if (v0v != 0) {
        s1v -= 1;
        goto loop;
    }
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010C66C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010C67C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010C798);

extern s32 func_800E6F14_noarg() asm("func_800E6F14");

void func_8010C7A8(void) {
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");

    MEMORY_BARRIER();
    v0v <<= 10;
    v0v += v1v;
    s0v = *(s32 *) v0v;
    v0v = *(s32 *) (s0v + 0x24);
    v1v = *(s16 *) v0v;
    if ((u32) v1v < 0x3E8U) {
        v0v = v1v << 4;
        v0v -= v1v;
        v0v <<= 2;
        v1v = (s32) D_801CD7E0;
        s0v = v0v + v1v;
        v0v = func_800E6F14_noarg();
        v1v = v0v << 1;
        v1v += v0v;
        v1v <<= 1;
        v0v &= 1;
        v0v <<= 1;
        KEEP(v0v);
        v0v += 0x18;
        v1v += v0v;
        a0v = *(s16 *) (s0v + 4);
        KEEP(a0v);
        v0v = *(u16 *) (s0v + 8);
        *(s16 *) (s0v + 4) = v1v;
        *(s16 *) (s0v + 0xC) = v1v;
        *(s16 *) (s0v + 0x14) = v1v;
        v1v -= a0v;
        v0v -= v1v;
        *(s16 *) (s0v + 8) = v0v;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010C848);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010C850);

extern u8 D_8018AE6C[];

void func_8010CA18(u8 *arg0) {
    *(u16 *) (arg0 + 0x1C) = 0;
    *(u16 *) (arg0 + 0x26) = 0;
    func_800FF450(arg0 + 0x20, D_8018AE6C, 8);
}

extern s16 D_8018AAEA;

s32 func_8010CA4C(void) {
    s32 a0v;
    u8 *temp_v0;

    a0v = D_8018AAEA;
    temp_v0 = func_80059AF0(a0v);
    return (temp_v0[0xCF] << 8) | temp_v0[0xCE];
}

void func_8010CA84(u8 *arg0, u32 arg1) {
    u32 v = arg1 & 0x3F;

    v <<= 4;
    arg1 &= 0xFFFF;
    arg1 >>= 6;
    *(u16 *) arg0 = v;
    *(u16 *) (arg0 + 4) = 0x10;
    *(u16 *) (arg0 + 2) = arg1;
    *(u16 *) (arg0 + 6) = 1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010CAB0);

void func_8010CBDC(u8 *arg0, s32 arg1) {
    s32 v0v;
    s32 v1v;

    v1v = arg0[0xC];
    v0v = arg0[0x14];
    if (v1v != v0v) {
        MEMORY_BARRIER();
        v0v = arg0[0xC];
        v1v = arg0[0x1C];
        MEMORY_BARRIER();
        v0v += arg1;
        v1v += arg1;
        arg0[0xC] = v0v;
        arg0[0x1C] = v1v;
    } else {
        v0v = arg0[0xD];
        v1v = arg0[0x1D];
        v0v += arg1;
        v1v += arg1;
        arg0[0xD] = v0v;
        arg0[0x1D] = v1v;
    }
    v0v = *(u16 *) (arg0 + 0x10);
    v1v = *(u16 *) (arg0 + 0x20);
    v0v -= arg1;
    v1v -= arg1;
    *(u16 *) (arg0 + 0x10) = v0v;
    *(u16 *) (arg0 + 0x20) = v1v;
}

void func_8010CC40(u8 *arg0, s32 arg1) {
    u8 *p;
    u8 c;
    s32 s14;
    s32 s24;
    s32 t8;
    s32 t18;
    s32 m15;
    s32 m25;

    p = arg0;
    t8 = *(u16 *) (p + 8) + arg1;
    c = p[0xC];
    *(u16 *) (p + 8) = t8;
    t18 = *(u16 *) (p + 0x18) + arg1;
    *(u16 *) (p + 0x18) = t18;
    if (c != p[0x14]) {
        MEMORY_BARRIER();
        s14 = p[0x14];
        s24 = p[0x24];
        MEMORY_BARRIER();
        s14 -= arg1;
        s24 -= arg1;
        p[0x14] = s14;
        p[0x24] = s24;
    } else {
        m15 = p[0x15] - arg1;
        m25 = p[0x25] - arg1;
        p[0x15] = m15;
        p[0x25] = m25;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010CCA4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010D0CC);

void func_8010E2C8(u8 *arg0) {
    u8 *s0;
    register s32 v1 asm("v1");
    register s32 v0 asm("v0");
    register s32 a2v asm("a2");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");

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
    a2v = (s32) &D_8015328C;
    KEEP_NOVOL(a2v);
    v0 = *(s16 *) (s0 + 0xC);
    *(u16 *) (a2v - 8) = 8;
    D_80153286 = 8;
    *(s32 *) a2v = v0 * 4;
    a0v = *(s32 *) (s0 + 0x10);
    KEEP_NOVOL(a0v);
    a1v = *(s32 *) s0;
    KEEP_NOVOL(a1v);
    v0 = *(u16 *) (s0 + 0x22);
    v1 = *(u16 *) (s0 + 0x24);
    D_80153304 = v0;
    D_80153308 = v1;
    func_800FE774_s(a0v, a1v, a2v - 8);
    func_800248FC(s0 + 8, *(s32 *) s0);
    func_800FFF50();
    func_800E3298(*(s32 *) s0);
}

extern s32 D_8018AF2C;
extern s32 D_8018AF38;

void func_8010E3B0(void) {
    s32 a0 = 0;
    s32 a2 = D_801CD170;
    u8 *a1 = (u8 *) &D_8018AF38;
    u8 *v1 = (u8 *) &D_8018AF2C;
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

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010E404);

void func_8010EA28(u8 *arg0, s32 arg1) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register u8 v0 asm("v0");
    register u8 v1 asm("v1");
    volatile u8 *p;

    if (arg1 >= 0) {
        goto end;
    }
    a2 = (s32) arg0;
    p = (volatile u8 *) a2;
    v0 = p[0x0C];
    v1 = p[0x14];
    a3 = 1;
    if (v0 < v1) {
        a3 = -1;
    }
    v0 = p[0x0C];
    v1 = p[0x14];
    a0 = p[0x1C];
    a1 = v0 + a3;
    p[0x14] = a1;
    a1 = a0 + a3;
    v0 = p[0x24];
    v1 = v1 + a3;
    p[0x0C] = v1;
    p[0x24] = a1;
    v0 = v0 + a3;
    p[0x1C] = v0;
end:
    return;
}

s32 func_8010EA84(s32 arg0, s32 arg1, s32 arg2) {
    return ((arg1 - arg0) * arg2) / 4096 + arg0;
}

void func_8010EAA8(void *arg0, void *arg1, void *arg2, s32 arg3) {
    s16 *out = (s16 *) arg0;
    s16 *a = (s16 *) arg1;
    s16 *b = (s16 *) arg2;

    out[4] = func_8010EA84(a[0], b[0], arg3);
    out[5] = func_8010EA84(a[1], b[1], arg3);
    out[8] = func_8010EA84(a[0] + a[2], b[0] + b[2], arg3);
    out[9] = func_8010EA84(a[1], b[1], arg3);
    out[12] = func_8010EA84(a[0], b[0], arg3);
    out[13] = func_8010EA84(a[1] + a[3], b[1] + b[3], arg3);
    out[16] = func_8010EA84(a[0] + a[2], b[0] + b[2], arg3);
    out[17] = func_8010EA84(a[1] + a[3], b[1] + b[3], arg3);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010EBD0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010EFA8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8010F250);

extern void func_80023DD0(void *);
extern void func_800FDBA0(void *, s32);

void func_80110260(u8 *arg0) {
    register u8 *s0 asm("s0");
    register s32 s1 asm("s1");
    register u8 *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");

    s2 = arg0;
    s0 = s2 + 0x204;
    func_80023DD0(s0);
    s1 = (s32) (s2 + 0x214);
    func_80023DD0((void *) s1);
    func_80023C68(s0, 1);
    func_80023C68((void *) s1, 1);
    s3 = 0;
    s1 = 0x224;
    s2[0x208] = 0x30;
    s2[0x209] = 0x30;
    s2[0x20A] = 0x30;
    s2[0x218] = 0x30;
    s2[0x219] = 0x30;
    s2[0x21A] = 0x30;
    *(u16 *) (s2 + 0x20C) = 0x12;
    *(u16 *) (s2 + 0x20E) = 1;
    *(u16 *) (s2 + 0x210) = 0x10;
    *(u16 *) (s2 + 0x212) = 0x5A;
    *(u16 *) (s2 + 0x21C) = 0x7C;
    *(u16 *) (s2 + 0x21E) = 1;
    *(u16 *) (s2 + 0x220) = 0x10;
    *(u16 *) (s2 + 0x222) = 0x5A;
    do {
        s0 = s2 + s1;
        func_80023DE4(s0);
        func_80023C68(s0, 1);
        s3 += 1;
        s1 += 0x10;
    } while (s3 < 8);
    a0 = (s32) s2;
    a1 = 0;
    v1 = 0x10;
    v0 = 0x20;
    s2[0x238] = v0;
    s2[0x239] = v0;
    s2[0x23A] = v0;
    s2[0x248] = v0;
    s2[0x249] = v0;
    s2[0x24A] = v0;
    s2[0x278] = v0;
    s2[0x279] = v0;
    s2[0x27A] = v0;
    s2[0x288] = v0;
    s2[0x289] = v0;
    s2[0x28A] = v0;
    v0 = 0x10;
    a2 = 1;
    USE(a2);
    s2[0x228] = v1;
    s2[0x229] = v1;
    s2[0x22A] = v1;
    s2[0x258] = v1;
    s2[0x259] = v1;
    s2[0x25A] = v1;
    s2[0x268] = v1;
    s2[0x269] = v1;
    s2[0x26A] = v1;
    s2[0x298] = v1;
    s2[0x299] = v1;
    s2[0x29A] = v1;
    v1 = 0x5A;
    *(u16 *) (s2 + 0x22C) = v0;
    *(u16 *) (s2 + 0x230) = v0;
    v0 = 0x11;
    *(u16 *) (s2 + 0x23C) = v0;
    *(u16 *) (s2 + 0x240) = v0;
    MEMORY_BARRIER();
    v0 = 0x22;
    *(volatile u16 *) (s2 + 0x22E) = a2;
    *(volatile u16 *) (s2 + 0x232) = v1;
    *(volatile u16 *) (s2 + 0x23E) = a2;
    *(volatile u16 *) (s2 + 0x242) = v1;
    *(volatile u16 *) (s2 + 0x24C) = v0;
    *(volatile u16 *) (s2 + 0x24E) = a2;
    *(volatile u16 *) (s2 + 0x250) = v0;
    v0 = 0x23;
    *(volatile u16 *) (s2 + 0x25C) = v0;
    *(volatile u16 *) (s2 + 0x260) = v0;
    v0 = 0x7A;
    *(volatile u16 *) (s2 + 0x26C) = v0;
    *(volatile u16 *) (s2 + 0x270) = v0;
    v0 = 0x7B;
    *(volatile u16 *) (s2 + 0x27C) = v0;
    *(volatile u16 *) (s2 + 0x280) = v0;
    v0 = 0x8C;
    *(volatile u16 *) (s2 + 0x28C) = v0;
    *(volatile u16 *) (s2 + 0x290) = v0;
    v0 = 0x8D;
    *(volatile u16 *) (s2 + 0x252) = v1;
    *(volatile u16 *) (s2 + 0x25E) = a2;
    *(volatile u16 *) (s2 + 0x262) = v1;
    *(volatile u16 *) (s2 + 0x26E) = a2;
    *(volatile u16 *) (s2 + 0x272) = v1;
    *(volatile u16 *) (s2 + 0x27E) = a2;
    *(volatile u16 *) (s2 + 0x282) = v1;
    *(volatile u16 *) (s2 + 0x28E) = a2;
    *(volatile u16 *) (s2 + 0x292) = v1;
    *(volatile u16 *) (s2 + 0x29C) = v0;
    *(volatile u16 *) (s2 + 0x29E) = a2;
    *(volatile u16 *) (s2 + 0x2A0) = v0;
    *(u16 *) (s2 + 0x2A2) = v1;
    func_800FDBA0(s2, 0);
    func_800FDBA0(s2 + 0xC, 2);
    func_800FDBA0(s2 + 0x18, 4);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80110480);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80110AB4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80111070);

void func_801117F0(u8 *arg0, u8 *arg1) {
    register s32 s0 asm("s0");
    register u8 *s1 asm("s1");
    register s32 s2 asm("s2");
    register u8 *s3 asm("s3");
    register s32 s4 asm("s4");
    register s32 s5 asm("s5");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");

    s3 = arg0;
    v0 = *(s32 *) (arg1 + 0x10);
    v1 = 1;
    if (v0 != 1 && D_8015330C != 1) {
        v1 = 0x7D7C;
        goto second;
    }
    v1 = 0x7DFC;
    s0 = 0xB;
    v0 = (s32) s3 + 0xDC;
    do {
        *(u16 *) (v0 + 0x32) = v1;
        s0 -= 1;
        v0 -= 0x14;
    } while (s0 >= 0);
    s0 = 0xC;
    a0 = 0x7D3C;
    v1 = (s32) s3 + 0xF0;
    do {
        *(u16 *) (v1 + 0x32) = a0;
        s0 += 1;
        v1 += 0x14;
    } while (s0 < 0x13);
    s0 = 0;
    s4 = 0x40;
    s5 = 0x80;
    s1 = s3;
    s2 = 0x1A0;
    v0 = 0x7C7C;
    *(u16 *) (s3 + 0x32) = v0;
    *(u16 *) (s3 + 0x46) = v0;
    do {
        a0 = (s32) s3 + s2;
        func_80023C90((void *) a0, 0);
        s1[0x1A4] = s4;
        s1[0x1A5] = s4;
        s1[0x1A6] = s5;
        s1 += 0x14;
        s0 += 1;
        s2 += 0x14;
    } while (s0 < 5);
    goto done;
second:
    s0 = 0xB;
    v0 = (s32) s3 + 0xDC;
    do {
        *(u16 *) (v0 + 0x32) = v1;
        s0 -= 1;
        v0 -= 0x14;
    } while (s0 >= 0);
    s0 = 0xC;
    a0 = 0x7C3C;
    v1 = (s32) s3 + 0xF0;
    do {
        *(u16 *) (v1 + 0x32) = a0;
        s0 += 1;
        v1 += 0x14;
    } while (s0 < 0x13);
    s0 = 0;
    s4 = 0x80;
    s1 = s3;
    s2 = 0x1A0;
    v0 = 0x7CBC;
    *(u16 *) (s3 + 0x32) = v0;
    *(u16 *) (s3 + 0x46) = v0;
    do {
        a0 = (s32) s3 + s2;
        func_80023C90((void *) a0, 0);
        s1[0x1A4] = s4;
        s1[0x1A5] = s4;
        s1[0x1A6] = s4;
        s1 += 0x14;
        s0 += 1;
        s2 += 0x14;
    } while (s0 < 5);
done:;
}

void func_8011196C(s32 arg0, u8 *arg1) {
    if (*(s32 *) (arg1 + 0x10) == 1 || D_8015330C == 1) {
        ((void (*)(void)) func_800E36A0)();
    } else {
        ((void (*)(void)) func_800E3618)();
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801119C0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80111ACC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80111BC0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80111EC4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8011241C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8011260C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8011261C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80112704);

extern void func_800EA990(u8 *);

void func_80112878(u8 *arg0) {
    u8 buf[24];

    func_800EA990(buf);
    *(u16 *) arg0 = buf[0xC];
    *(u16 *) (arg0 + 2) = buf[0xD];
    *(u16 *) (arg0 + 4) = 0x10;
    *(u16 *) (arg0 + 6) = 0x10;
    *(u16 *) (arg0 + 8) = *(u16 *) (buf + 0xE);
    *(u16 *) (arg0 + 0xA) = func_8002398C(0, 0, 0x380, 0x120);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801128E0);

extern s8 D_801CD788;

s32 func_80112C6C(s32 arg0) {
    arg0 = D_8015327C + (arg0 << 10);
    return *(s32 *) (arg0 + 0x48);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80112C88);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_8011315C);

extern s16 D_801CD218;
extern s32 D_801CD5EC[];
extern s8 D_8018BAEA;
extern s32 func_801210E8(s32, s32, s32);
extern void func_801221D8(s32);
extern s32 func_801161E8(s32);

void func_801133E4(void) {
    s32 var_a2;

    MEMORY_BARRIER();
    if (D_801CD218 == -1) {
        var_a2 = 0;
    } else {
        var_a2 = 2;
        if (D_801CD218 == 0x65) {
            goto common;
        }
        var_a2 = 1;
    }
common:
    D_801CD788 = func_801210E8(0, (s32) &D_801CD5EC, var_a2);
    func_801221D8(0);
    func_801221D8(1);
    func_801221D8(2);
    func_801221D8(3);
    func_801221D8(4);
    func_801161E8(0);
    D_8018BAEA = 1;
}

extern s32 D_801CD750;

s32 func_80113478(void) {
    s32 s0;

    MEMORY_BARRIER();
    s0 = 0;
    if (D_801CD750 != 0 || func_800FFEEC(0xF) != 0 || D_8015330C != 0 ||
        func_800FFEEC(6) != 0) {
        s0 = 1;
    }
    return s0;
}

extern s8 D_8018BACD;
extern void func_8012A370(s32, s32, s32, s32);

void func_801134E8(s32 arg0, s32 arg1) {
    s32 a0;
    s32 a1;
    register s32 a2 asm("a2");
    register s32 s0 asm("s0");

    MEMORY_BARRIER();
    a2 = arg0 + 0;
    s0 = arg1;
    MEMORY_BARRIER();
    a0 = 1;
    a1 = 0x2B;
    func_8012A370(a0, a1, a2, 0);
    D_8018BACD = 1;
    func_80044018(s0);
    D_8015330C = 1;
}

s32 func_80113540(s32 arg0, s32 arg1) {
    s32 a0 = arg0;
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");

    MEMORY_BARRIER();
    a2 = arg1 + 0;
    MEMORY_BARRIER();
    a0 <<= 16;
    a0 >>= 14;
    v0 = *(s32 *) ((u8 *) D_801CD5EC + a0);
    a0 = 1;
    a3 = *(s16 *) (v0 + 0x2C);
    func_8012A370(1, 0x1B, a2, a3);
}

extern s32 D_8018BA34;
extern volatile u8 D_8018C192;
extern void func_8012BD7C();

void func_80113580(void) {
    s32 v0v;

    v0v = func_800FFEEC(7);
    if (v0v != 0) {
        v0v = 0xA;
        goto store;
    }
    v0v = D_8018BA34 & 0x60;
    if (v0v != 0) {
        v0v = 0xA;
        goto store;
    }
    v0v = D_8018C192;
    if (v0v == 0) {
        goto end;
    } else {
        v0v = D_8018C192;
        v0v -= 1;
    }
store:
    D_8018C192 = v0v;
    v0v = D_8018C192;
    if (v0v != 0) {
        func_8012BD7C();
    }
end:
    return;
}

u8 func_80113608(void) {
    return D_8018C192;
}

extern u8 D_8018E48D;
extern s32 D_8018BA1C;
extern s32 D_801CD754;
extern s32 func_8012BD14();
extern s32 func_80113608_2() asm("func_80113608");

s32 func_80113618(void) {
    extern u8 D_8018E0B2;
    s32 s0v;

    MEMORY_BARRIER();
    s0v = func_8012BD14(0);
    MEMORY_BARRIER();
    if (D_8018E48D != 0) {
        s0v = 0;
    } else if (D_8018E0B2 != 0) {
        s0v = 0;
    } else if (func_80113608_2() != 0) {
        s0v = 0;
    } else if (func_800FFEEC(1) != 0) {
        if (D_8018BA1C == 4) {
            s0v = s0v & 0xF0FF;
        }
    } else {
        if (D_801CD754 != 0) {
            s0v = s0v & 0xF0FF;
        } else if (D_801CD750 != 0) {
            s0v = s0v & 0xF0FF;
        }
    }
    return s0v;
}

extern u8 D_8018C193;
extern u8 D_8018C18C;
extern s32 D_8018BA38;

void func_801136E0(void) {
    register s32 value asm("v0");

    if (D_8018C193 < 9) {
        MEMORY_BARRIER();
        D_8018C193++;
        MEMORY_BARRIER();
        D_8018BA38 = 0;
        return;
    }
    D_8018C193 = 0;
    D_8018C18C = 0;
    value = 1;
    __asm__ volatile("lui $3, %%hi(D_8018BA38)\n\t"
                     "addiu $3, $3, %%lo(D_8018BA38)\n\t"
                     "sw %0, 0($3)\n\t"
                     "sw $zero, -4($3)"
                     : : "r"(value) : "$3", "memory");
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80113748);

void func_80113DD4(void) {
    extern u8 D_8018BACC;
    extern void func_80043FF8(s32);
    s32 v0v;
    s32 v1v;
    s32 a0v;

    SCHED_BARRIER();
    if (*(u8 *) &D_8018BACD != 0) {
        D_8018BACC = 0;
    }
    v1v = D_80153298;
    KEEP(v1v);
    if (v1v == 0x73 || v1v == 0x2D) {
        func_80044018(D_80153298);
        D_80153298 = 0;
    } else {
        if (D_8018BACC == 0x30) {
            func_80044018(0x30);
            D_8018BACC = 0;
        }
    }
    v0v = D_80153298;
    v0v = v0v - 2;
    if ((u32) v0v < 2) {
        D_8018BACC = *(u8 *) &D_80153298;
    }
    v0v = D_80153298;
    if (v0v < 0) {
        D_80153298 = 0;
    } else if (D_801532A0 != 0) {
        D_80153298 = 0;
    }
    a0v = D_80153298;
    if (a0v == 0) {
        a0v = D_8018BACC;
    }
    D_8018BACC = 0;
    D_80153298 = 0;
    if (a0v != 0) {
        func_80043FF8(a0v);
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80113F00);

extern s16 D_801CD728[];

void func_80114088(void) {
    s32 v1;
    s16 *a1;
    s16 a0;

    v1 = 0;
    a1 = D_801CD728;
    a0 = -1;
loop:
    a1[v1] = a0;
    v1++;
    if (v1 < 16) {
        goto loop;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_801140BC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80114758);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80114BC8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80114D4C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80115198);

extern void func_8010D0CC();
extern void func_8012A598();
extern u8 D_8018BA2C[];

void func_80115460(s32 arg0) {
    if (arg0 != 0) {
        if (func_800FFEEC(8) == 0) {
            func_800FFD70(8, &func_8010D0CC);
            func_800FFF08(8, D_8018BA2C, 0, 0);
        }
    } else {
        func_8012A598(8);
    }
}

extern u8 D_8018BA40[];

void func_801154C4(s32 arg0) {
    if (arg0 != 0) {
        if (func_800FFEEC(7) == 0) {
            func_800FFD70(7, &func_8010D0CC);
            func_800FFF08(7, D_8018BA40, 0, 0);
        }
    } else {
        func_8012A598(7);
    }
}

extern s32 D_8018BA54;
extern s32 func_80110480();

void func_80115528(s32 arg0) {
    extern s32 func_800FFEEC(s32);
    extern void func_80115650(s32);
    s32 s0;

    if (arg0 != 0) {
        if (!(D_8018BA34 & 0x60)) {
            s0 = 1;
            KEEP_NOVOL(s0);
            if (func_800FFEEC(0xA) == 0) {
                func_800FFD70(0xA, (s32 *) &func_80110480);
                func_800FFF08(0xA, (s32) &D_8018BA54, 0, 0);
            }
            func_80115650(s0);
        }
    } else {
        ((void (*)(s32)) func_8012A598)(0xA);
        ((void (*)(s32)) func_8012A598)(0xC);
    }
}

extern s32 D_8018BA64;
extern s32 D_8018BA68;

void func_801155BC(s32 arg0) {
    extern s32 func_800FFEEC(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    s32 s0v;

    MEMORY_BARRIER();
    s0v = arg0;
    if (s0v != 0) {
        s0v = 1;
        if (!(D_8018BA34 & 0x60) && func_800FFEEC(9) == 0) {
            func_800FFD70(9, (s32 *) &func_80110480);
            func_800FFF08(9, (s32) &D_8018BA68, 0, 0);
        }
    } else {
        ((void (*)(s32)) func_8012A598)(9);
    }
    D_8018BA64 = s0v;
}

extern void func_80111EC4();
extern u8 D_8018BAA4[];

void func_80115650(s32 arg0) {
    if (arg0 != 0) {
        if (func_800FFEEC(0xC) == 0) {
            func_800FFD70(0xC, &func_80111EC4);
            func_800FFF08(0xC, D_8018BAA4, 0, 0);
        }
    } else {
        func_8012A598(0xC);
    }
}

extern s32 D_8018BAB4;
extern s32 D_8018BAB8;
extern s32 D_8018AA88;

void func_801156B4(s32 arg0) {
    s32 s0v;

    MEMORY_BARRIER();
    s0v = arg0;
    if (s0v != 0) {
        s0v = 1;
        if (!(D_8018BA34 & 0x60) && func_800FFEEC(0xB) == 0) {
            func_800FFD70(0xB, &func_80111EC4);
            func_800FFF08(0xB, &D_8018BAB8, 0, 0);
        }
    } else {
        func_8012A598(0xB);
    }
    D_8018BAB4 = s0v;
    D_8018AA88 = s0v;
}

extern s32 func_80110AB4();
extern u8 D_8018BA7C[];

void func_80115750(s32 arg0) {
    extern s32 func_800FFEEC(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_80115650(s32);
    s32 s0;

    if (arg0 != 0) {
        s0 = 1;
        KEEP(s0);
        if (func_800FFEEC(10) == 0) {
            if (func_800FFEEC(9) == 0) {
                func_800FFD70(10, (s32 *) &func_80110AB4);
                func_800FFF08(10, (s32) &D_8018BA7C, 0, 0);
            }
        }
        D_8018BA25 = 1;
        func_80115650(s0);
    } else {
        func_8012A598(10);
        func_8012A598(12);
    }
}

extern s32 func_80111070();
extern u8 D_8018BA90[];

void func_801157EC(s32 arg0) {
    extern s32 func_800FFEEC(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_80115650(s32);
    s32 s0;

    if (arg0 != 0) {
        if ((D_8018BA34 & 0x60) != 0) {
            goto end;
        }
        s0 = 1;
        KEEP(s0);
        if (func_800FFEEC(9) == 0) {
            if (func_800FFEEC(10) == 0) {
                func_800FFD70(9, (s32 *) &func_80111070);
                func_800FFF08(9, (s32) &D_8018BA90, 0, 0);
            }
        }
        func_80115650(s0);
    }
end:
    return;
}

extern s32 D_8018BA4C;
extern s32 D_8018BA60;
extern s32 D_8018BA74;
extern s32 D_8018BA88;
extern s32 D_8018BA9C;
extern s32 D_8018BAB0;
extern s32 D_8018BAC4;

void func_80115878(void) {
    D_8018BA38 = 1;
    D_8018BA4C = 1;
    D_8018BA9C = 1;
    D_8018BAB0 = 1;
    D_8018BAC4 = 1;
    D_8018BA60 = 1;
    D_8018BA74 = 1;
    D_8018BA88 = 1;
}

extern void func_801155BC();
extern void func_801156B4();
extern s32 D_8018BA78;
extern s32 D_8018BA8C;
extern s32 D_8018BAA0;
extern s32 D_8018BAC8;

void func_801158C4(void) {
    func_8012A598(8);
    func_8012A598(7);
    func_8012A598(0xA);
    func_8012A598(0xC);
    func_801156B4(0);
    func_801155BC(0);
    D_8018BAC8 = 0;
    D_8018BA78 = 0;
    D_8018BAA0 = 0;
    D_8018BA8C = 0;
}

extern u8 D_8018C197;
extern u8 D_8018C197x asm("D_8018C197");

s32 func_8011592C(s32 arg0, s32 arg1) {
    s32 a0 = arg0;
    s32 a1 = arg1;
    s32 v0;
    s32 v1;

    v0 = D_8018C197;
    if (v0 == 0) {
        a1 = *(s16 *) (D_801CD5EC[a0] + 0xC);
    } else {
        v1 = D_8018C197x;
        if (v1 == 1) {
            a1 = *(s16 *) (D_801CD5EC[a0] + 0x12);
        } else if (v1 == 2) {
            a1 = 0x20000064;
        }
    }
    return a1;
}

s16 func_801159AC(s32 arg0) {
    return *(s16 *) D_801CD5EC[arg0];
}

s16 func_801159CC(s32 arg0) {
    return *(s16 *) ((s8 *) D_801CD5EC[arg0] + 8);
}

s16 func_801159EC(s32 arg0) {
    return *(s16 *) ((s8 *) D_801CD5EC[arg0] + 0x26);
}

s16 func_80115A0C(s32 arg0) {
    return *(s16 *) ((s8 *) D_801CD5EC[arg0] + 0x28);
}

s32 func_80115A2C(s32 arg0) {
    s32 v0;
    register s32 v1 asm("v1");

    v0 = D_801CD5EC[arg0];
    v1 = *(u16 *) (v0 + 0x120);
    v1 &= 0xF;
    __asm__ volatile("" : "=r"(v1) : "0"(v1) : "memory");
    v0 = *(volatile u16 *) (v0 + 0x120) >> 4;
    return v0 - v1;
}

s32 func_80115A60(s32 arg0) {
    return (*(u16 *) ((u8 *) D_801CD5EC[arg0] + 0x120)) >> 4;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80115A80);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80115B70);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_2", func_80115B7C);

extern s16 D_8018BA20_s asm("D_8018BA20");
extern s16 D_8018BA20_t asm("D_8018BA20");
extern s8 D_8018C18D;
extern s8 D_8018C18E;

s32 func_80115CA0(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");

    a0v = 0;
    v0v = D_8018C18E;
    if (v0v != 0) {
        goto one;
    }
    v1v = D_8018C18D;
    v0v = -60;
    if (v1v == v0v) {
        goto case60;
    }
    v0v = v1v < -59;
    if (v0v == 0) {
        goto low;
    }
    v0v = -120;
    if (v1v == v0v) {
        goto case120;
    }
    goto end;
low:
    if (v1v == 0) {
        goto case0;
    }
    goto end;
case120:
    v0v = D_8018BA20_s;
    v0v = v0v < 8;
    if (v0v == 0) {
        goto end;
    }
    goto one;
case60:
    v0v = D_8018BA20_s;
    v0v = v0v < 16;
    if (v0v == 0) {
        goto one;
    }
    v0v = D_8018BA20_t;
    KEEP(v0v);
    v0v = v0v < 4;
    if (v0v != 0) {
        goto one;
    }
    goto end;
case0:
    v0v = D_8018BA20_s;
    v0v = v0v < 12;
    if (v0v == 0) {
        goto one;
    }
    goto end;
one:
    a0v = 1;
end:
    return a0v;
}
