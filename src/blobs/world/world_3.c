#include "common.h"

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

extern void func_800248FC();
extern s32 func_8002398C();
extern void func_800FFD70();
extern s32 *D_801CD7E0;
extern u8 D_8018BA25;
extern void func_8012BD9C();
extern u32 func_8012372C();
extern s16 D_8018BA20;
extern s32 func_800EF1A8();
extern u8 *func_80059AF0();
extern u8 D_800596E0[];
extern void func_80059FE0(s32);
extern void func_800EF25C();
extern s32 D_8015330C;
extern void func_800FFD28();
extern void func_800FFF08();
extern s32 D_801CA6F0;
extern s32 D_801CA6F4;
extern s32 func_800FFEEC();
extern void func_800EEE98();
extern void func_800F1330(s32 arg0);
extern s32 func_800246D4(s32);
extern s32 func_80044990();
extern u8 D_800473A3;
extern u32 D_800473AC;
extern void func_80108920();
extern s32 D_801CD8C4;
extern void func_8010B7E8();
extern s8 D_801CD788;
extern s32 D_801CD5EC[];
extern void func_801221D8(s32);
extern s32 func_801161E8(s32);
extern s32 D_801CD750;
extern s8 D_8018BACD;
extern void func_8012A370(s32, s32, s32, s32);
extern void func_8012BD7C();
extern s32 D_8018BA1C;
extern s32 D_801CD754;
extern s32 func_8012BD14();
extern void func_8012A598();
extern s32 D_8018BAB4;
extern void func_801156B4();
extern s32 D_8018BAA0;
extern u8 D_8018C197;
extern s16 D_8018BA20_s asm("D_8018BA20");
extern void func_80112878(u8 *arg0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80115D6C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011604C);

extern u8 D_801CD80C;
extern u8 D_801CD80Cx asm("D_801CD80C");
extern u8 D_8018BA26;
extern u8 D_8018BAE9;
extern s32 D_8018BA30;

s32 func_801161E8(s32 arg0) {
    extern void func_8011604C(s16);
    s32 v;
    u8 t;

    MEMORY_BARRIER();
    func_8011604C((s16) arg0);
    D_8018C197 = 0;
    MEMORY_BARRIER();
    D_8018BA26 = D_801CD80C;
    MEMORY_BARRIER();
    t = D_801CD80Cx;
    if (t != 0) {
        v = 0x90;
        D_8018BA30 = v;
        v = 1;
    } else {
        D_8018BA30 = 0;
        v = 1;
    }
    D_8018BA25 = (u8) v;
    D_8018BAE9 = (u8) v;
    return v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80116264);

extern s16 D_8018BAD0[];
extern s32 func_8001BE1C(s32);

s32 func_80116DD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    s32 result;

    __asm__ volatile("" ::: "ra");
    s0v = arg2;
    s1v = arg3;
    KEEP_NOVOL(s0v);
    KEEP_NOVOL(s1v);
    v0v = (s32) D_8018BAD0;
    KEEP_NOVOL(v0v);
    v1v = *(s16 *) (v0v + 0);
    v1v -= arg0;
    if (v1v < 0) {
        v1v = -v1v;
    }
    MEMORY_BARRIER();
    v1v *= v1v;
    KEEP(v1v);
    v0v = *(s16 *) (v0v + 2);
    v0v -= arg1;
    if (v0v < 0) {
        v0v = -v0v;
    }
    v0v <<= 1;
    v0v *= v0v;
    a0v = v0v + v1v;
    a0v <<= 12;
    v0v = func_8001BE1C(a0v) >> 12;
    v1v = s0v - v0v;
    result = v1v;
    if (v1v < s1v) {
        result = s1v;
    }
    return result;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80116E74);

extern s16 D_801C8344[];
extern s16 D_8018C876;
extern s16 D_8018C88A;

void func_801170B4(void) {
    s32 a0v;
    s32 v0v;
    s32 v1v;

    v1v = 0;
    KEEP(v1v);
    a0v = -1;
    v0v = v1v << 2;
loop:
    *(s16 *) ((u8 *) D_801C8344 + v0v) = a0v;
    v1v++;
    v0v = v1v < 8;
    if (v0v != 0) {
        v0v = v1v << 2;
        goto loop;
    }
    v0v = func_8002398C(0, 2, 0x3C0, 0x100);
    D_8018C876 = v0v;
    MEMORY_BARRIER();
    v0v = func_8002398C(0, 1, 0x3C0, 0x100);
    D_8018C88A = v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011712C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011751C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80117738);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801179A0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80117C58);

extern void func_80117DB8(s16, s16 *, s32, s32);

void func_80117D78(s16 arg0) {
    s16 sp[2];

    MEMORY_BARRIER();
    sp[0] = 0x8B;
    sp[1] = 0x9E;
    MEMORY_BARRIER();
    func_80117DB8(arg0, sp, 0, 6);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80117DB8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80117FFC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011814C);

s32 func_8011822C(u32 arg0, u32 arg1) {
    s32 var_v0;

    var_v0 = arg1 < 0xFFU;
    if (arg0 >= 0xFFU) {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80118244);

extern void func_800222FC();
extern s32 D_801C8364;

void func_80118B3C(void) {
    func_800222FC(&D_801C8364, 0, 0x54);
}

void func_80118B68(s32 arg0) {
    func_800222FC(&((u16 *) &D_801C8364)[arg0 * 3], 0, 6);
}

extern s32 D_801C8366;
extern s32 D_801C8368;
extern u16 D_801C83F8[];

void func_80118BA4(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 v1;
    s32 a1;
    s32 v0;

    v1 = arg0;
    v1 = (v1 << 1) + arg0;
    v1 <<= 1;
    *(s16 *) ((u8 *) &D_801C8364 + v1) = arg1;
    *(s16 *) ((u8 *) &D_801C8366 + v1) = arg2;
    MEMORY_BARRIER();
    a1 = arg1;
    a1 <<= 1;
    a1 += arg3;
    v0 = *(u16 *) a1;
    v0 &= 0x3FF;
    *(s16 *) ((u8 *) &D_801C8368 + v1) = v0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80118BF0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80118D04);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80118D10);

extern s16 func_801223B8();
extern s16 D_801C83F4;

s32 func_80118E1C(void) {
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    s32 r;
    v0v = D_801C83F4;

    MEMORY_BARRIER();
    a0v = *(s16 *) &D_801C83F8[v0v];
    r = ((s32 (*)(s16)) func_801223B8)(a0v);
    a0v = r >> 1;
    v1v = D_8018BA20_s;
    v1v = D_801CD5EC[v1v];
    r &= 1;
    v1v += a0v;
    v1v = *(u8 *) (v1v + 0xB3);
    if (r == 0) {
        __asm__ volatile("" ::: "$3");
        v1v >>= 4;
    } else {
        v1v &= 0xF;
    }
    return v1v;
}

extern s16 D_801C83F0;

s32 func_80118E94(void) {
    if (D_801C83F0 < 2) {
        return 0;
    }
    return ((D_801C83F8[D_801C83F4] >> 0xE) ^ 1) & 1;
}

s16 func_80118EE8(s16 arg0) {
    s16 var_v0;

    if (arg0 >= 0x4A) {
        var_v0 = arg0 - 0x4A;
    } else {
        var_v0 = arg0 + 0x13;
    }
    return var_v0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80118F14);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80118F1C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80119AA0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80119AA8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80119D60);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80119D68);

extern s8 D_8018C93B;
extern u16 D_8018C8A0;

void func_8011A274(void) {
    extern s8 D_8018C939;

    if (D_801C83F0 < 2) {
        D_8018BA1C = 0x15;
    } else {
        D_8018C93B = 1;
    }
    D_8018C939 = 0;
    D_8018C8A0 = D_8018BA20;
}

extern void func_8011A274();

void func_8011A2C8(void) {
    extern void func_80119AA0(s32, s32, s32);
    extern u8 D_8018C939;
    s32 v0;
    s32 temp_a1;
    v0 = *(u8 *) &D_8018C93B;

    if (v0 == 0) {
        func_8011A274();
    }
    temp_a1 = (D_8018C939 * 0x140) + 0x1000;
    func_80119AA0(((D_8018C939 + 1) << 0xA) / 20, temp_a1, temp_a1);
    D_8018C939 += 1;
    if ((u8) D_8018C939 >= 0x14U) {
        D_8018C93B = 0;
        D_8018BA1C = 0x15;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011A378);

extern void func_8011A378();
extern u8 D_8018C93A;

void func_8011A4E4(void) {
    extern s8 D_8018C93C;
    extern void func_80119AA0(s32, s32, s32);
    extern s8 D_8018C93C;
    s32 v0;
    s32 temp_a1;
    v0 = *(u8 *) &D_8018C93C;

    if (v0 == 0) {
        func_8011A378();
    }
    temp_a1 = (D_8018C93A * 0x140) + 0x1000;
    func_80119AA0((((0x14 - D_8018C93A) << 0xA) / 20) + 0xC00, temp_a1, temp_a1);
    v0 = (u8) D_8018C93A;
    v0 = v0 - 1;
    D_8018C93A = (u8) v0;
    if (D_8018C93A == 0) {
        D_8018C93C = 0;
        D_8018BA1C = 3;
    }
}

extern u16 D_8018BA20_u asm("D_8018BA20");
extern u8 D_8018C93C;
extern void func_8011A684();

void func_8011A598(void) {
    s32 v0v;
    s32 v1v;
    s32 s0v;
    volatile s32 pad[6];
    v0v = *(u8 *) &D_8018C93B;

    if (v0v != 0) {
        v1v = D_8018BA20_u;
        D_8018BA1C = 0x15;
        D_8018C93B = 0;
        D_8018C8A0 = v1v;
        goto end;
    }
    v0v = D_8018C93C;
    if (v0v == 0) {
        v0v = 0x14;
        goto store;
    }
    s0v = D_8018C93A;
    D_8018C8A0 = D_8018BA20_u;
    func_8011A378();
    v0v = func_801263A8();
    v1v = D_800473A3;
    v1v = v1v / v0v;
    s0v += v1v;
    D_8018C93A = s0v;
    v0v = D_8018C93A;
    v0v = (u8) v0v < 0x11;
    if (v0v == 0) {
        v0v = 0x10;
        D_8018C93A = v0v;
    }
    MEMORY_BARRIER();
    v0v = 0x15;
store:
    D_8018BA1C = v0v;
end:
    func_8011A684();
}

extern s16 D_8018C8A4;
extern s16 D_8018C8A6;
extern u16 D_8018C8B0;
extern s16 D_8018C8B4;
extern s16 D_8018C8B6;

void func_8011A684(void) {
    struct Func8011A684_Record {
        u16 f00;
        u16 f02;
        u16 f04;
        u16 f06;
        u16 f08;
        s16 f0A;
        u16 pad0C;
        u16 pad0E;
        s16 f10;
        u16 f12;
        s16 f14;
        u16 f16;
    };
    extern void func_801256C8(s16, void *, s32);
    extern void func_8012CECC(void *, s32, s32, s32);
    struct Func8011A684_Record rec;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");

    func_801256C8(D_8018BA20, &rec, 0);
    a0v = 0x80;
    v0v = (s32) rec.f04 << 16;
    v0v >>= 17;
    a0v -= v0v;
    v1v = (s32) rec.f06 << 16;
    v1v >>= 17;
    v0v = 0x7B;
    v0v -= v1v;
    v1v = rec.f0A;
    D_8018C8A6 = v0v;
    D_8018C8B6 = v0v;
    D_8018C8A4 = a0v;
    D_8018C8B4 = a0v;
    D_8018C8B0 = rec.f08;
    v0v = 0x64;
    if (v1v == v0v) {
        v0v = (s32) rec.f00 << 16;
        v0v >>= 18;
        v0v += 0x100;
    } else {
        v0v = (s32) rec.f00 << 16;
        v0v >>= 18;
        v0v += 0x140;
    }
    rec.f10 = v0v;
    MEMORY_BARRIER();
    a0v = (s32) &rec.f10;
    rec.f12 = rec.f02;
    v1v = rec.f04 << 16;
    v0v = rec.f02;
    rec.f14 = v1v >> 18;
    rec.f16 = rec.f06;
    func_8012CECC((void *) a0v, 0x240, 0x130, 0);
}

extern void func_8012A5C0();
extern u16 D_8018C940;
extern s16 D_801C8450;
extern s16 D_801C8452;
extern s16 D_801C8454;
extern s16 D_801C8456;
extern s32 D_801CD8BC;
extern s32 D_801CD910;

void func_8011A778(void) {
    s32 s0v;
    s32 s1v;
    s32 v0v;
    s16 a2buf[4];
    s8 res;

    v0v = D_801C83F0;
    if (v0v < 2) {
        s1v = D_801CD910;
        v0v = 0x1B;
    } else {
        v0v = D_801C83F4;
        s1v = D_801CD8BC;
        v0v = D_801C83F8[v0v];
    }
    D_8018C940 = v0v;
    MEMORY_BARRIER();
    s0v = (s32) &D_8018C940;
    a2buf[0] = 0x24C;
    a2buf[1] = 0x130;
    a2buf[2] = 0x14;
    a2buf[3] = 0x10;
    func_8012A5C0(s1v, (u16 *) s0v, a2buf, 0);
    res = func_8012A9D4(func_8012A08C((u8 *) s1v, *(u16 *) s0v & 0x3FF, 2));
    D_801C8450 = ((0x50 - res) >> 1) + 0x58;
    MEMORY_BARRIER();
    D_801C8452 = 0xD7;
    D_801C8454 = res;
    D_801C8456 = 0xE;
}

extern s16 D_8018C944;
extern s16 D_8018C946;
extern s16 D_8018C94C;
extern void func_8012C8BC(s16 *, s32, s32, s32, s32);

void func_8011A880(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t0v;
    s32 v0v;
    s32 a0v;
    s32 var_v0;
    s32 var_v1;

    MEMORY_BARRIER();
    t0v = arg0;
    if (arg3 < 0x50) {
        var_v1 = 0;
        if (arg3 >= 0x3C) {
            var_v1 = 1;
            if (arg3 >= 0x42) {
                var_v1 = 2;
                if (arg3 >= 0x48) {
                    var_v1 = 4;
                    var_v0 = arg3 < 0x4C;
                    goto block_9;
                }
            }
        }
    } else {
        var_v1 = 0;
        if (arg3 >= 0x5E) {
            var_v1 = 1;
            if (arg3 >= 0x60) {
                var_v1 = 2;
                if (arg3 >= 0x62) {
                    var_v1 = 4;
                    var_v0 = arg3 < 0x64;
block_9:
                    if (var_v0 != 0) {
                        var_v1 = 3;
                    }
                }
            }
        }
    }
    MEMORY_BARRIER();
    a0v = (s32) &D_8018C944;
    v0v = t0v + 7;
    *(s16 *) a0v = v0v;
    D_8018C946 = arg1 - 0xC;
    D_8018C94C = var_v1 * 0xA + 0x24;
    func_8012C8BC((s16 *) a0v, 0, 0, 0, arg2);
}

void func_8011A954(void) {
loop_1:
    func_800FFD28(1);
    goto loop_1;
}

extern s32 func_801237E4(s32);
extern s16 D_801CD230[];

s32 func_8011A97C(s32 arg0) {
    u8 *base = D_801CD230;
    u16 *p = (u16 *) (base + (arg0 << 1));
    s32 v = func_801237E4(*p & 0x3FF);
    s32 a = v;

    if (*p & 0x4000) {
        a = v | 0x40000000;
    }
    return a;
}

extern s32 func_80123764(s32);

s32 func_8011A9D8(s32 arg0) {
    u8 *base = (u8 *) D_801CD230;
    u16 *p = (u16 *) (base + (arg0 << 1));
    s32 v = func_80123764(*p & 0x3FF);
    s32 a = v;

    if (*p & 0x4000) {
        a = v | 0x40000000;
    }
    return a;
}

extern u8 func_80124FD0(s32);
extern void func_80124FF4(s32, u8 *);
extern u8 D_801C8458[];
extern u16 D_801C8460;
extern u16 D_801C8462;
extern u16 D_801CD1BC;
extern u16 D_8018DF8A;

u8 *func_8011AA34(s32 arg0) {
    func_80124FF4(((s32 (*)(s32)) func_80124FD0)(D_801CD230[arg0]), D_801C8458);
    D_801C8460 = D_801CD1BC;
    D_801C8462 = D_8018DF8A;
    return D_801C8458;
}

extern u8 D_801C8464[];

u8 *func_8011AAA4(s32 arg0) {
    ((void (*)(u8 *, u8)) func_80112878)(D_801C8464, ((u8 *) D_801CD230)[arg0 * 2]);
    return D_801C8464;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011AAE8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011AAF0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011AF4C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011AF54);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011B554);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011B55C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011B794);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011B7A4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011BC4C);

void func_8011BDB0(void) {
}

void func_8011BDB8(void) {
    func_8010B7E8();
}

extern s16 D_8018AAA6;

s16 func_8011BDD8(void) {
    return D_8018AAA6;
}

extern s16 D_8018AAAC;

s16 func_8011BDE8(void) {
    return D_8018AAAC;
}

s32 func_8011BDF8(void) {
    s32 t = D_8018AAA6;

    if (t == 0)
        return 0x20000000;
    return t;
}

s32 func_8011BE18(void) {
    s32 t = D_8018AAAC;

    if (t == 0)
        return 0x20000000;
    return t;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011BE38);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011BE40);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011C1A8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011C1B0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011C5D4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011C5DC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011C8D8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011C8E0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011CFA8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011CFB0);

extern s16 D_801CD20C;
extern s8 D_8018BADD;
extern u16 D_8018BA20u asm("D_8018BA20");
extern u8 D_8018BA24u asm("D_8018BA24");
extern u8 D_8018BACCu asm("D_8018BACC");
extern u8 D_8018BA25u asm("D_8018BA25");
extern u8 D_8018BA27u asm("D_8018BA27");
extern s16 D_801C8514;
extern u16 D_801CD838u asm("D_801CD838");
extern void func_801212B8();
extern s32 func_801210E8();
extern void func_80114BC8();
extern void func_80126374();

s32 func_8011D2F8(void) {
    s32 v0v;
    s32 v1v;
    s32 s0v;
    s16 t0v;

    v0v = D_8018BADD;
    if (v0v == 0) {
        s0v = 1;
        func_801212B8();
        D_801CD788 = func_801210E8(
            *(s16 *) ((u8 *) D_801CD230 + (D_801CD20C * 2)), &D_801CD5EC, 0);
        D_801CD754 = 0x20002;
        D_8018BA27u = s0v;
        D_8018BA25u = s0v;
        func_801156B4(0);
        t0v = D_8018BA20u;
        D_8018BA20u = 0;
        D_801C8514 = t0v;
        func_80114BC8();
        D_8018BADD = s0v;
        func_80126374(0);
        D_8018BA24u = 2;
    }
    if (func_800FFEEC(7) != 0) {
        return 6;
    }
    v1v = D_801CD838u;
    v0v = v1v & 0x40;
    if (v0v != 0) {
        goto body;
    }
    v0v = v1v & 0x20;
    if (v0v == 0) {
        goto ret6;
    }
body:
    D_8018BA27u = 0;
    D_8018BA25u = 0;
    D_801CD788 = func_801210E8(0, &D_801CD5EC, 0);
    D_8018BA20u = D_801C8514;
    func_80114BC8();
    func_8012A598(9);
    func_8012A598(0xC);
    func_8012A598(8);
    D_8018BADD = 0;
    D_8018BA24u = 0;
    v1v = 2;
    D_8018BACCu = v1v;
    return 0;
ret6:
    return 6;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011D474);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011D584);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011D8AC);

void func_8011DC70(void) {
loop_1:
    func_800FFD28(1);
    goto loop_1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011DC98);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011DCA0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011E0B4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011E0C4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011E4B4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011E630);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011E640);

extern s8 D_8018BAE1;
extern s8 D_8018BA24;
extern s8 D_801C854C;
extern s32 func_8011F5F0();

s32 func_8011ED18(void) {
    extern void func_80118B68(s32);
    extern s32 func_8011F090();
    extern void func_801263C8(s32, s32, s32);
    extern void func_8012B950(s32, s32);
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    v0v = D_8018BAE1;

    if (v0v != 0) {
        goto check;
    }
    D_801C854C = 0;
    D_8018BA25 = 0;
    ((void (*)(s32)) func_8012A598)(0xC);
    ((void (*)(s32)) func_8012A598)(0xA);
    v0v = 8;
    D_8018BA24 = 0;
    func_8012B950(8, 0);
    func_80118B68(9);
    v0v = 1;
    D_8018BAE1 = v0v;
check:
    v0v = D_801C854C;
    if (v0v != 0) {
        goto other;
    }
    v0v = func_8011F090();
    v1v = v0v;
    v0v = 1;
    if (v1v != v0v) {
        v0v = -1;
        goto not_one;
    }
    func_801263C8(0, 0, 0);
    v0v = 1;
    goto store;
not_one:
    if (v1v != v0v) {
        goto end1;
    }
    D_8018BAE1 = 0;
    D_8018BA25 = 1;
    func_801212B8();
    v0v = 0;
    goto end2;
other:
    v0v = func_8011F5F0();
store:
    D_801C854C = v0v;
end1:
    v0v = 1;
end2:
    return v0v;
}

s32 func_8011EE04(s32 arg0, s32 arg1) {
    u32 v0v;
    s32 v1v;
    u32 u;

    arg0 = (s16) arg0;
    if (arg0 == 0x14) {
        return 0;
    }
    v0v = D_800473AC & 0x60000000;
    if (v0v != 0) {
        return 0;
    } else {
        u = arg1 - 0x1C6;
        if ((u & 0xFFFF) < 8) {
            return 1;
        }
        v1v = (s16) arg1;
        if (v1v == 0x1D8) {
            return 1;
        }
        if (v1v != 0x1DC) {
            return (v1v == 0x1DD);
        }
        return 1;
    }
}

s32 func_8011EE78(void) {
    return D_8015330C;
}

extern s16 D_801C8568[];
extern s32 D_801C85C8;

s32 func_8011EE88(s32 arg0) {
    s32 r;
    s32 c;
    s32 cond;

    r = ((s32 (*)(s16)) func_801223B8)(D_801C8568[arg0]);
    c = *(u8 *) (D_801CD5EC[D_8018BA20] + (r >> 1) + 0xB3);
    cond = r & 1;
    D_801C85C8 = c;
    MEMORY_BARRIER();
    if (cond == 0) {
        D_801C85C8 = ((s32) c) >> 4;
    } else {
        D_801C85C8 = c & 0xF;
    }
    MEMORY_BARRIER();
    return D_801C85C8;
}

s32 func_8011EF08(s32 arg0) {
    s32 r;

    r = ((s32 (*)(s16)) func_801223B8)(D_801C8568[arg0]);
    return *(u16 *) (D_801CD5EC[D_8018BA20] + (r * 2) + 0xBE);
}

extern s32 D_801C85CC;

void func_8011EF60(s32 arg0) {
    s32 r;

    r = ((s32 (*)(s16)) func_801223B8)(D_801C8568[arg0]);
    D_801C85CC = *(u16 *) (D_801CD5EC[D_8018BA20] + (r * 2) + 0xE6);
}

extern u16 D_80066184[];
extern s32 D_801C85D0;

s32 func_8011EFC0(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    u16 *p;

    func_801223B8(D_801C8568[arg0]);
    v0 = D_801C85C8;
    v1 = v0 & 0xF;
    if (v1 < 8) {
        goto assign;
    }
    v0 = D_801C85D0;
    v0 |= 0x20000000;
    goto end;
assign:
    p = &D_80066184[v1];
    v0 = *p;
end:
    D_801C85D0 = v0;
    MEMORY_BARRIER();
    return D_801C85D0;
}

extern s32 func_801228F0();
extern s32 D_801C85D4;

void func_8011F040(s32 arg0) {
    D_801C85D4 = func_801228F0(D_8018BA20, D_801C8568[arg0], 0xF, 0, 3) == 0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011F090);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011F098);

extern s16 D_801C8594[];
extern s32 D_801531D8;

void func_8011F2D4(void) {
    s32 v0v;
    v0v = D_801CD20C;

    MEMORY_BARRIER();
    v0v = D_801C8594[v0v];
    v0v += 0x7000;
    D_801531D8 = v0v;
    func_800EEE98();
}

extern s16 D_801C8564;

u16 func_8011F31C(void) {
    s32 v0;
    s32 v1;

    v0 = D_8018BA20;
    v1 = D_801C8564;
    v0 <<= 2;
    v0 = *(s32 *) ((u8 *) D_801CD5EC + v0);
    v1 <<= 1;
    v1 += v0;
    return *(u16 *) (v1 + 0xBE);
}

s32 func_8011F350(void) {
    return D_801C85C8;
}

s32 func_8011F360(void) {
    return D_801C85D0;
}

s32 func_8011F370(void) {
    return D_801C85CC;
}

extern s32 D_801C85D8;

s32 func_8011F380(void) {
    return D_801C85D4;
}

extern s32 D_801C85DC;
extern u8 D_801C85E0;
extern s32 func_8005A72C();

s32 func_8011F390(s32 arg0) {
    register s32 a0 asm("a0") = arg0;
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register u16 *s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v0 = (s32) D_801C8594;
    a0 <<= 1;
    s0 = (u16 *) (v0 + a0);
    a1 = (s32) &D_801C85E0;
    a0 = s0[0] & 0x3FF;
    a2 = (s32) &D_801C85DC;
    v0 = func_8005A72C(a0, (void *) a1, (void *) a2);
    D_801C85D8 = v0;
    v1 = 0;
    if (v0 != 0) {
        v0 = s0[0];
        v0 >>= 14;
        v1 = v0 < 1;
    }
    return v1;
}

s32 func_8011F400(s32 arg0) {
    register u32 v0 asm("v0");
    register s32 v1 asm("v1") = 0;

    if (D_801C85D8 != 0) {
        v0 = ((u16 *) D_801C8594)[arg0];
        v1 = (v0 >> 14) != 0;
    }
    return v1;
}

s32 func_8011F438(void) {
    return D_801C85D8 == 0;
}

s32 func_8011F448(s32 arg0) {
    register s32 a0 asm("a0") = arg0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s16 temp;

    a0 <<= 1;
    temp = *(s16 *) ((u8 *) D_801C8594 + a0);
    a0 = temp;
    v0 = a0 & 0x2000;
    if (v0 != 0) {
        v1 = 0x20000000;
    } else {
        v1 = *(u8 *) (D_801C85DC + 0x0D);
    }
    v0 = a0 >> 14;
    if (v0 != 0) {
        v0 = 0x40000000;
        v1 |= v0;
    }
    return v1;
}

s32 func_8011F494(s32 arg0) {
    register s32 a0 asm("a0") = arg0;
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a0 <<= 1;
    a1 = *(s16 *) ((u8 *) D_801C8594 + a0);
    v0 = a1 & 0x2000;
    if (v0 != 0) {
        a0 = 0x20000000;
    } else {
        a0 = *(u8 *) (D_801C85DC + 0x0C);
        v1 = 0x64;
        v0 = v1 % a0;
        a0 = v1 / a0 + (v0 != 0);
    }
    v0 = a1 >> 0xE;
    if (v0 != 0) {
        v0 = 0x40000000;
        a0 |= v0;
    }
    return a0;
}

extern u16 D_8005EBF0[];

s32 func_8011F4F8(s32 arg0) {
    s32 a0 = arg0;
    s32 v0;
    s32 v1;

    a0 <<= 1;
    a0 = *(s16 *) ((u8 *) D_801C8594 + a0);
    v0 = a0 & 0x2000;
    if (v0 != 0) {
        v1 = 0x20000000;
    } else {
        v0 = (a0 & 0x3FF) << 3;
        v1 = *(u16 *) ((u8 *) D_8005EBF0 + v0);
    }
    v0 = a0 >> 14;
    if (v0 != 0) {
        v0 = 0x40000000;
        v1 |= v0;
    }
    return v1;
}

extern s16 D_8018D1A0;

s32 func_8011F548(void) {
    return D_8018D1A0 == 0;
}

s32 func_8011F558(void) {
    return D_8018D1A0 == 1;
}

s32 func_8011F570(void) {
    return D_8018D1A0 == 2;
}

s32 func_8011F588(void) {
    return D_8018D1A0 == 3;
}

s32 func_8011F5A0(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v1 = D_8018BA1C;
    v0 = 0xC;
    if (v1 != v0) {
        v0 = arg0 << 1;
        v0 = *(u16 *) ((u8 *) D_801C8594 + v0);
        v0 >>= 0xE;
        v0 ^= 1;
        v0 &= 1;
    } else {
        v0 = arg0 << 1;
        v0 = *(u16 *) ((u8 *) D_801C8594 + v0);
        v0 &= 0x1000;
    }
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011F5F0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011F5F8);

extern s8 D_8018BAE5;
extern s8 D_801C8558;
extern s32 D_8018BA3C;
extern s32 D_801CD530;
extern void func_80118B3C();
extern s8 func_8011FD28();

void func_8011FC18(void) {
    extern u8 D_8018BACC;
    extern void func_8012B950(s32, s32);
    extern s8 func_8011F090();

    if (D_8018BAE5 == 0) {
        D_8018BAE5 = 1;
        D_8018BA24 = 1;
        D_801C8558 = 0;
        D_8018BA3C = 1;
        D_8018BAB4 = 1;
        D_8018BAA0 = 1;
        func_8012B950(8, 0);
        func_80118B3C();
        D_8018BACC = 1;
    }
    if (D_801C8558 == 0) {
        D_801C8558 = func_8011F090();
    } else if (D_801C8558 == 1) {
        D_801C8558 = func_8011FD28();
    }
    if (D_801C8558 == -1) {
        D_8018BAB4 = 0;
        D_8018BAA0 = 0;
        D_8018BA1C = 0;
        D_8018BA24 = 2;
        func_8012BD7C();
        D_801CD530 = 0;
        D_8018BA3C = 0;
        D_8018BAE5 = 0;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011FD28);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8011FD30);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801200F8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80120100);

extern u16 D_8018D544;
extern void func_8011260C();

void func_801202FC(void) {
    s32 v0v;
    v0v = D_8018BA20;

    MEMORY_BARRIER();
    v0v = D_801CD5EC[v0v];
    v0v = *(u16 *) (v0v + 0x2C);
    D_8018D544 = v0v;
    func_8011260C();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80120344);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012034C);

s32 func_801207BC(s32 arg0) {
    s32 var_s0;

    var_s0 = func_800EF1A8(0x2C) + arg0;
    if (var_s0 < 0) {
        var_s0 = 0;
    }
    if (var_s0 > 0x05F5E0FF) {
        var_s0 = 0x05F5E0FF;
    }
    func_800EF25C(0x2C, var_s0);
    return var_s0;
}

void func_8012081C(void) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 s3v asm("s3");
    register s32 v0v asm("v0");

    s3v = 0;
    s2v = (s32) &D_800596E0;
    KEEP_NOVOL(s3v);
    KEEP_NOVOL(s2v);
loop:
    v0v = s3v << 16;
    s1v = v0v >> 16;
    s0v = func_801237E4(s1v);
    s3v += 1;
    if (s0v < 0x64) {
        goto check;
    }
    v0v = func_8012372C(s1v);
    s0v -= 0x63;
    v0v *= s0v;
    func_801207BC(v0v);
    v0v = *(u8 *) s2v;
    v0v -= s0v;
    *(u8 *) s2v = v0v;
check:
    s2v += 1;
    v0v = s3v < 0xFD;
    if (v0v != 0) {
        goto loop;
    }
}

s32 func_801208B8(s32 arg0, s32 arg1) {
    s32 idx = arg0 & 0x3FF;
    s32 v0 = 0;

    if (idx != 0) {
        v0 = D_800596E0[idx] + arg1;
        if (v0 < 0) {
            v0 = 0;
        }
        D_800596E0[idx] = v0;
    }
    return v0;
}

s32 func_801208F8(s32 arg0) {
    s32 a0 = arg0;
    s32 v0;
    s32 v1;

    a0 <<= 16;
    a0 >>= 14;
    v1 = *(s32 *) ((u8 *) D_801CD5EC + a0);
    v0 = *(u8 *) (v1 + 0x72);
    v1 = *(s16 *) (v1 + 0x2C);
    v0 = v0 < 4;
    if (v0 != 0) {
        v0 = 0;
    } else {
        v0 = v1 < 0x10;
    }
    return v0;
}

extern void func_80124428();

void func_80120930(s32 arg0) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 v0v asm("v0") = arg0;

    KEEP_NOVOL(v0v);
    s1v = v0v << 16;
    arg0 = s1v >> 16;
    s2v = v0v;
    v0v = func_801208F8(arg0);
    s0v = 0;
    if (v0v == 0) {
        goto end;
    }
loop:
    arg0 = s1v >> 16;
    func_80124428(arg0, (s16) (s0v << 16 >> 16), 0);
    s0v += 1;
    v0v = s0v < 5;
    if (v0v != 0) {
        goto loop;
    }
    v0v = s2v << 16;
    v0v >>= 14;
    func_80059FE0(*(s16 *) (*(s32 *) ((u8 *) D_801CD5EC + v0v) + 0x2C));
end:
    return;
}

extern s32 D_801CD8C8;
extern s32 func_80059ED4(s16);
extern s32 func_80125844(s16);

s32 func_801209C4(s16 arg0) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 v0v asm("v0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");

    s0v = (s32) &D_801CD8C4;
    a0v = (s32) arg0 << 16;
    s1v = *(s32 *) s0v;
    v0v = D_801CD8C8;
    KEEP_WITH(s1v, v0v);
    a0v >>= 16;
    *(s32 *) s0v = v0v;
    v0v = func_80059ED4(a0v);
    *(s32 *) s0v = s1v;
    s0v = v0v;
    KEEP_WITH(s0v, v0v);
    if (s0v < 0) {
        v0v = -1;
        goto end;
    }
    a0v = s0v;
    v0v = (s32) func_80059AF0(a0v);
    a0v = 0;
    a1v = (s32) &D_801CD5EC;
    a2v = 0;
    *(u8 *) (v0v + 7) = 0;
    *(u8 *) (v0v + 8) = 0;
    *(u8 *) (v0v + 9) = 0;
    *(u8 *) (v0v + 0xA) = 0;
    *(u8 *) (v0v + 0xB) = 0;
    *(u8 *) (v0v + 0xC) = 0;
    *(u8 *) (v0v + 0xD) = 0;
    func_801210E8(0, a1v, a2v);
    a0v = s0v << 16;
    a0v >>= 16;
    v0v = func_80125844(a0v);
end:
    return v0v;
}

void func_80120A64(s32 arg0, u8 *arg1) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    s0v = arg0;
    s0v <<= 16;
    v0v = (s32) D_801CD5EC;
    s0v >>= 14;
    s0v += v0v;
    v0v = *(s32 *) s0v;
    a0v = *(s16 *) (v0v + 0x2C);
    v0v = (s32) func_80059AF0(a0v);
    s1v = (s32) arg1;
    a1v = v0v;
    a0v = 0;
    a2v = 0xFE;
loop:
    v0v = *(s32 *) s0v;
    v1v = *(u8 *) s1v;
    *(u8 *) (v0v + a0v + 0x10E) = v1v;
    *(u8 *) (a1v + a0v + 0xBE) = v1v;
    v0v = *(u8 *) s1v;
    a0v += 1;
    if (v0v == a2v) {
        goto end;
    }
    v0v = a0v < 0x10;
    if (v0v != 0) {
        s1v += 1;
        goto loop;
    }
end:
    func_80108920(a0v, a1v, a2v);
}

extern u8 D_80063AB9[];

s32 func_80120AFC(void *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0;
    u8 temp_v1;

    var_a3 = 0;
    temp_v0 = *(s16 *) arg0;
    var_a2 = 0;
    if (temp_v0 != 0) {
        if (*(s16 *) ((u8 *) arg0 + 2) == 0) {
            var_a2 = temp_v0 & 0x3FF;
        }
    } else {
        temp_v0_2 = *(s16 *) ((u8 *) arg0 + 2);
        if (temp_v0_2 != 0) {
            var_a2 = temp_v0_2 & 0x3FF;
        }
    }
    if (var_a2 != 0 && var_a2 < 0x7A) {
        temp_v1 = D_80063AB9[var_a2 * 8];
        if (!(temp_v1 & 1)) {
            if (arg1 != 0) {
                var_v0 = 0;
                if (temp_v1 & 4) {
                    goto block_10;
                }
                goto block_11;
            } else {
                goto block_11;
            }
        } else {
            goto block_10;
        }
block_10:
        var_a3 = 1;
    }
block_11:
    var_v0 = var_a3;
    return var_v0;
}

s32 func_80120B90(s32 arg0) {
    s32 v;

    v = (u32) (arg0 - 0x3C) < 0xE;
    if ((u32) (arg0 - 0x90) < 0xB)
        v = 1;
    return v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80120BB0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801210E8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801212B8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801212C0);

extern s32 func_80125374(s32);
extern u8 D_80062EBA[];
extern u8 D_80062EBC[];
extern u8 D_80063ABC[];
extern u8 D_80063EB8[];
extern u8 D_80063ED8[];

u8 func_80121568(s32 arg0) {
    s32 s0;
    s32 v0;
    s32 v1;
    s32 t;

    s0 = arg0;
    v1 = func_80125374((s16) s0);
    if (s0 == 0) {
        v0 = 1;
        goto not_a;
    }
    if (v1 != 0) {
        v0 = 1;
        goto not_a;
    }
    v0 = D_80062EBC[s0 * 12];
    return D_80063ABC[v0 << 3];
not_a:
    if (v1 == v0) {
        v0 = D_80062EBC[s0 * 12];
        return D_80063EB8[v0 << 1];
    }
    v0 = v1 < 4;
    if (v0 == 0) {
        v0 = D_80062EBA[s0 * 12];
        return v0;
    }
    t = s0 - 0x90;
    v0 = D_80063ED8[t * 2];
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80121654);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80121C60);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80121C80);

extern s32 D_8018D7AC[];

void func_80121FC8(s32 arg0, s16 *arg1) {
    s32 a0 = arg0;
    s32 a1 = (s32) arg1;
    s32 v0;
    s32 v1;
    s32 a2;
    u8 c;

    a0 = D_8018D7AC[a0];
    c = *(volatile u8 *) a0;
    v1 = -1;
    v0 = c;
    v0 <<= 24;
    v0 >>= 24;
    *(s16 *) a1 = v0;
    if (v0 != v1) {
        a2 = -1;
        v1 = a0;
        do {
            v1++;
            c = *(volatile u8 *) v1;
            v0 = c;
            v0 <<= 24;
            v0 >>= 24;
            a1 += 2;
            *(s16 *) a1 = v0;
        } while (v0 != a2);
    }
}

extern s32 D_8018D7D8[];

void func_80122020(s32 arg0, u8 *arg1) {
    s32 a0 = arg0;
    s32 a1 = (s32) arg1;
    s32 a2;
    s32 v0;
    s32 v1;

    a0 = D_8018D7AC[a0];
    KEEP(a0);
    v0 = *(u8 *) a1;
    v1 = -1;
    *(u8 *) a0 = v0;
    v0 <<= 24;
    v0 >>= 24;
    if (v0 != v1) {
        a2 = -1;
        MEMORY_BARRIER();
        v1 = a0;
        a1 += 2;
        do {
            v0 = *(u8 *) a1;
            KEEP(v0);
            v1++;
            *(u8 *) v1 = v0;
            v0 <<= 24;
            v0 >>= 24;
            a1 += 2;
        } while (v0 != a2);
        a1 -= 2;
        USE(a1);
    }
}

void func_80122080(s32 arg0, s16 *arg1) {
    s32 a0 = arg0;
    s32 a1 = (s32) arg1;
    s32 a2;
    s32 a3;
    s32 v0;
    s32 v1;

    a0 <<= 2;
    v1 = -1;
    v0 = *(s16 *) a1;
    a0 = *(s32 *) ((u8 *) D_8018D7D8 + a0);
    a2 = 0;
    if (v0 != v1) {
        a3 = -1;
        v1 = a0;
        do {
            v0 = *(u8 *) a1;
            a1 += 2;
            a2 += 1;
            *(u8 *) v1 = v0;
            v0 = *(s16 *) a1;
            v1++;
        } while (v0 != a3);
    }
    v1 = a0 + a2;
    KEEP(v1);
    v0 = 0xFF;
    *(u8 *) v1 = v0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801220D8);

extern s32 func_8012227C(s32, s32);
extern void func_801222D0(s32, s32);
extern void func_80122338(s32, s32);

void func_801221D8(s32 arg0) {
    register s32 s2v asm("s2") = arg0;
    register s32 s0v asm("s0") = 1;
    register s32 s1v asm("s1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    KEEP_NOVOL(s0v);
loop:
    v0v = s0v << 16;
    s1v = v0v >> 16;
    a0v = s1v;
    v0v = func_80125374(a0v);
    v1v = 0;
    if (v0v != 0) {
        v1v = v0v - 1;
    }
    if (s2v != v1v) {
        goto advance;
    }
    a0v = s1v;
    v0v = func_801237E4(a0v);
    if (v0v == 0) {
        a0v = s0v;
        a1v = s2v;
        func_80122338(a0v, a1v);
        goto advance;
    }
    a0v = s0v;
    a1v = s2v;
    v0v = func_8012227C(a0v, a1v);
    if (v0v != 0) {
        goto advance;
    }
    a0v = s0v;
    a1v = s2v;
    func_801222D0(a0v, a1v);
    s0v += 1;
    goto check;
advance:
    s0v += 1;
check:
    v0v = s0v < 0xFE;
    if (v0v != 0) {
        v0v = s0v << 16;
        goto loop;
    }
}

s32 func_8012227C(s32 arg0, s32 arg1) {
    s32 a0 = arg0;
    s32 a1 = arg1;
    s32 v0;
    s32 v1;

    a1 <<= 2;
    a1 = *(s32 *) ((u8 *) D_8018D7D8 + a1);
    v1 = *(u8 *) a1;
    v0 = 0xFF;
    if (v1 != v0) {
        v1 = 0xFF;
        do {
            v0 = *(u8 *) a1;
            if (v0 == a0) {
                return 1;
            }
            a1++;
            v0 = *(u8 *) a1;
        } while (v0 != v1);
    }
    return 0;
}

void func_801222D0(s32 arg0, s32 arg1) {
    register s32 a0 asm("a0") = arg0;
    register s32 a1 asm("a1") = arg1;
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a1 <<= 2;
    a2 = *(s32 *) ((u8 *) D_8018D7D8 + a1);
    a1 = 0;
    v1 = *(u8 *) a2;
    v0 = 0xFF;
    if (v1 != v0) {
        a3 = 0xFF;
        v1 = a2;
        do {
            v1++;
            v0 = *(u8 *) v1;
            a1++;
        } while (v0 != a3);
    }
    if (a1 >= 0) {
        v1 = a1 + a2;
        do {
            v0 = *(u8 *) v1;
            a1--;
            *(u8 *) (v1 + 1) = v0;
            v1--;
        } while (a1 >= 0);
    }
    *(u8 *) a2 = a0;
}

void func_80122338(s32 arg0, s32 arg1) {
    register s32 a0 asm("a0") = arg0;
    register s32 a1 asm("a1") = arg1;
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register u8 *v1 asm("v1");

    a1 <<= 2;
    a2 = *(s32 *) ((u8 *) D_8018D7D8 + a1);
    a1 = 0;
    v0 = *(u8 *) a2;
    if (v0 == a0) {
        goto shift;
    }
    a3 = 0xFF;
    v1 = (u8 *) a2;
    do {
        v0 = *(u8 *) v1;
        if (v0 == a3) {
            return;
        }
        v1++;
        v0 = *(u8 *) v1;
        a1++;
    } while (v0 != a0);
shift:
    a0 = 0xFF;
    v1 = (u8 *) (a1 + a2);
    do {
        v0 = *(u8 *) (v1 + 1);
        *(u8 *) v1 = v0;
        v1++;
        v0 = *(u8 *) v1;
    } while (v0 != a0);
}

s16 func_801223B8(s32 arg0) {
    register s32 v0 asm("v0");

    v0 = arg0;
    v0 -= 0x4A;
    if ((u16) v0 < 0x14U) {
        MEMORY_BARRIER();
        v0 = arg0 - 0x4A;
    } else {
        MEMORY_BARRIER();
        v0 = 0;
    }
    return (s16) v0;
}

extern u8 *func_8005A8A4();

s32 func_801223E4(s32 arg0) {
    s32 i = 0;

    do {
        if (*func_8005A8A4(i) == arg0) {
            return i;
        }
        i++;
    } while (i < 0xA0);
    return -1;
}

s32 func_8012243C(s32 arg0) {
    s32 a0 = arg0;
    s32 v0;
    s32 v1;

    a0 <<= 16;
    a0 >>= 14;
    a0 = *(s32 *) ((u8 *) D_801CD5EC + a0);
    v1 = *(u8 *) (a0 + 0x72);
    if (v1 == 0x82) {
        v1 = *(s16 *) (a0 + 0x24);
    } else if ((u32) v1 >= 0x80) {
        v1 = 0x4A;
    }
    return v1;
}

extern void func_8012B1D0(s32);
extern s32 func_8012B354(s32);

s32 func_80122488(s16 arg0) {
    s32 s0v;
    s32 s1v;
    s32 s2v;
    s32 a0v;
    s32 v0v;
    volatile s32 pad[2];
    v0v = *(u8 *) &D_801CD788;

    s1v = 0;
    if (v0v <= 0) {
        goto one;
    }
    v0v = (s32) arg0 << 16;
    s2v = v0v >> 16;
    s0v = (s32) D_801CD5EC;
loop:
    v0v = *(s32 *) s0v;
    a0v = *(s16 *) (v0v + 0x24);
    v0v = func_80120B90(a0v);
    KEEP_WITH(v0v, s1v);
    s1v += 1;
    if (v0v != 0) {
        goto advance;
    }
    a0v = *(s32 *) s0v + 0x77;
    func_8012B1D0(a0v);
    a0v = s2v - 0x4A;
    func_8012B354(a0v);
    a0v = 1;
    v0v = func_8012B354(a0v);
    if (v0v != 0) {
        v0v = 0;
        goto epilogue;
    }
advance:
    v0v = (u8) D_801CD788;
    v0v = s1v < v0v;
    if (v0v != 0) {
        s0v += 4;
        goto loop;
    }
one:
    v0v = 1;
epilogue:
    return v0v;
}

extern s32 func_8005DC14();

void func_80122534(u8 *arg0, u8 *arg1) {
    u8 *dst = arg1;
    s32 v;

    arg1 = (u8 *) arg0[4];
    arg0 += 0x64;
    v = func_8005DC14(arg0, (s32) arg1 & 0xC0);
    dst[0] = v >> 16;
    dst[1] = v >> 8;
    dst[2] = v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012257C);

u8 func_8012276C(void) {
    return *func_8005A8A4();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80122790);

s32 func_80122884(s32 arg0) {
    return (*(u8 *) (D_801CD5EC[(s16) arg0] + 0x126) & 1);
}

s32 func_801228A8(s32 arg0) {
    return (*(u8 *) (D_801CD5EC[(s16) arg0] + 0x126) & 2);
}

s32 func_801228CC(s32 arg0) {
    return (*(u8 *) (D_801CD5EC[(s16) arg0] + 0x126) & 0x40);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801228F0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80122C20);

typedef struct {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u16 f0A;
    u16 f0C;
    u8 pad0E[4];
    u16 f12;
    u16 f14;
    u16 f16;
    u16 f18;
    u8 pad1A[2];
    u16 f1C;
    u16 f1E;
    u16 f20;
    u16 f22;
} W122E40Rec24;

void func_80122E40(u8 *arg0, u8 *arg1) {
    W122E40Rec24 *r1 = (W122E40Rec24 *) arg1;

    *(u16 *) (arg0 + 0xE) = 0;
    *(u16 *) (arg0 + 0x14) = 0;
    r1->f00 = 0;
    r1->f02 = 0;
    r1->f04 = 0;
    r1->f06 = 0;
    r1->f08 = 0;
    r1->f0C = 0;
    r1->f0A = 0;
    r1->f12 = 0;
    r1->f14 = 0;
    r1->f16 = 0;
    r1->f18 = 0;
    r1->f1C = 0;
    r1->f1E = 0;
    r1->f20 = 0;
    r1->f22 = 0;
}

void func_80122E88(s32 arg0, void *arg1) {
    register s32 s0v asm("s0") = arg0;
    register s32 s1v asm("s1") = (s32) arg1;
    register s32 s2v asm("s2");
    register s32 v0v asm("v0");
    s32 sp10;
    volatile s32 pad[8];

    KEEP_NOVOL(s0v);
    KEEP_NOVOL(s1v);
    ((void (*)(void *)) func_80122E40)((void *) ((u8 *) &sp10 - 0x20));
    s2v = s0v;
    v0v = (s0v - 0x1E6) & 0xFFFF;
    v0v = (u32) v0v < 3U;
    if (v0v == 0) {
        goto zero0;
    }
    v0v = s0v - 0x1E5;
    *(u16 *) s1v = v0v;
    goto second;
zero0:
    *(u16 *) s1v = 0;
second:
    v0v = (s2v - 0x1E9) & 0xFFFF;
    v0v = (u32) v0v < 3U;
    if (v0v == 0) {
        goto zero4;
    }
    v0v = s2v - 0x1E8;
    *(u16 *) (s1v + 4) = v0v;
    goto end;
zero4:
    *(u16 *) (s1v + 4) = 0;
end:
    return;
}

void func_80122F0C(void *arg0, s32 arg1, s32 arg2) {
    struct Func80122F0C_First {
        s32 f00;
        u8 pad[0x24];
    } sp10;
    struct Func80122F0C_Record {
        u16 f00;
        u8 pad0[2];
        u16 f04;
        u8 pad[0x3A];
    } sp38;
    struct Func80122F0C_Record sp78;
    extern void func_80122E40(u8 *, u8 *);
    extern void func_80122E88(s32, void *);
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register u8 *s2v asm("s2") = (u8 *) arg0;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");

    s0v = arg1;
    s1v = arg2;
    KEEP_NOVOL(s2v);
    func_80122E40((u8 *) &sp10, (u8 *) s2v);
    s0v <<= 16;
    a0v = s0v >> 16;
    func_80122E88(a0v, &sp38);
    s1v <<= 16;
    a0v = s1v >> 16;
    func_80122E88(a0v, &sp78);
    v0v = sp78.f00;
    v1v = sp38.f00;
    v0v -= v1v;
    *(s16 *) s2v = (s16) v0v;
    v0v = sp78.f04;
    v1v = sp38.f04;
    v0v -= v1v;
    *(s16 *) (s2v + 4) = (s16) v0v;
}

extern u8 D_80062EBF;
extern u8 D_80063ABD;
extern u8 D_80063EB9;
extern u8 D_80063ED9;
extern u8 D_80063F58;
extern u8 D_80063F59;
extern u8 D_800642C4;
extern u8 D_800642C5;
extern u8 D_800642C6;
extern u8 D_800642C7;
extern u8 D_800642C8;

void func_80122F9C(s32 arg0, u16 *arg1, u16 *arg2, s32 arg3) {
    extern void func_80122E40(u8 *, u8 *);
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 s3v asm("s3");
    s32 v0v, v1v, s0v, a0v;

    s0v = arg0;
    s2v = (s32) arg1;
    s1v = (s32) arg2;
    s3v = arg3;
    func_80122E40((u8 *) s2v, (u8 *) s1v);
    s0v = s0v & 0x3FF;
    v0v = s0v - 1;
    if ((u32) v0v >= 0xFD) {
        return;
    }
    v1v = (s0v * 2 + s0v) * 4;
    a0v = *(u8 *) ((s32) &D_80062EBF + v1v);
    if (s0v < 0x80) {
        v0v = *(u8 *) ((s32) &D_80062EBC + v1v);
        v0v = v0v * 8;
        v1v = *(u8 *) ((s32) &D_80063ABC + v0v);
        v0v = *(u8 *) ((s32) &D_80063ABD + v0v);
        if (s3v != 0) {
            *(u16 *) (s1v + 8) = v1v;
            *(u16 *) (s1v + 0xC) = v0v;
        } else {
            *(u16 *) (s1v + 6) = v1v;
            *(u16 *) (s1v + 0xA) = v0v;
        }
    } else if (s0v < 0x90) {
        v0v = *(u8 *) ((s32) &D_80062EBC + v1v);
        v0v = v0v * 2;
        v0v = *(u8 *) ((s32) &D_80063EB8 + v0v);
        *(u16 *) (s1v + 0x16) = v0v;
        v0v = *(u8 *) ((s32) &D_80062EBC + v1v);
        v0v = v0v * 2;
        v0v = *(u8 *) ((s32) &D_80063EB9 + v0v);
        *(u16 *) (s1v + 0x20) = v0v;
    } else if (s0v < 0xD0) {
        v0v = (s0v - 0x90) * 2;
        v1v = *(u8 *) ((s32) &D_80063ED8 + v0v);
        *(u16 *) (s2v + 0xE) = v1v;
        v0v = *(u8 *) ((s32) &D_80063ED9 + v0v);
        *(u16 *) (s2v + 0x14) = v0v;
    } else if (s0v < 0xF0) {
        v0v = *(u8 *) ((s32) &D_80062EBC + v1v);
        v0v = v0v * 2;
        v0v = *(u8 *) ((s32) &D_80063F58 + v0v);
        *(u16 *) (s1v + 0x18) = v0v;
        v0v = *(u8 *) ((s32) &D_80062EBC + v1v);
        v0v = v0v * 2;
        v0v = *(u8 *) ((s32) &D_80063F59 + v0v);
        *(u16 *) (s1v + 0x22) = v0v;
    }
    v0v = (a0v * 2 + a0v) * 8 + a0v;
    v1v = *(u8 *) ((s32) &D_800642C7 + v0v);
    *(u16 *) (s1v + 0) = v1v;
    v1v = *(u8 *) ((s32) &D_800642C6 + v0v);
    *(u16 *) (s1v + 2) = v1v;
    v1v = *(u8 *) ((s32) &D_800642C8 + v0v);
    *(u16 *) (s1v + 4) = v1v;
    v1v = *(u8 *) ((s32) &D_800642C4 + v0v);
    *(u16 *) (s1v + 0x12) = v1v;
    v0v = *(u8 *) ((s32) &D_800642C5 + v0v);
    *(u16 *) (s1v + 0x1C) = v0v;
    return;
}

extern void func_80122F9C();
extern void func_80123288();

void func_801231CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 b1[0x28];
    u8 b2[0x28];
    u8 b3[0x40];
    u8 b4[0x40];

    func_80122F9C((s16) arg2, b1, b3, arg4);
    func_80122F9C((s16) arg3, b2, b4, arg4);
    *(u16 *) (arg1 + 0xE) = *(u16 *) (b2 + 0xE) - *(u16 *) (b1 + 0xE);
    *(u16 *) (arg1 + 0x14) = *(u16 *) (b2 + 0x14) - *(u16 *) (b1 + 0x14);
    func_80123288(arg0, b3, b4, 1);
}

void func_80123288(void *arg0, void *arg1, void *arg2, s32 arg3) {
    *(s16 *) ((u8 *) arg0 + 0x0) = (s16) (*(u16 *) ((u8 *) arg2 + 0x0) - arg3 * *(s16 *) ((u8 *) arg1 + 0x0));
    *(s16 *) ((u8 *) arg0 + 0x2) = (s16) (*(u16 *) ((u8 *) arg2 + 0x2) - arg3 * *(s16 *) ((u8 *) arg1 + 0x2));
    *(s16 *) ((u8 *) arg0 + 0x4) = (s16) (*(u16 *) ((u8 *) arg2 + 0x4) - arg3 * *(s16 *) ((u8 *) arg1 + 0x4));
    *(s16 *) ((u8 *) arg0 + 0x6) = (s16) (*(u16 *) ((u8 *) arg2 + 0x6) - arg3 * *(s16 *) ((u8 *) arg1 + 0x6));
    *(s16 *) ((u8 *) arg0 + 0x8) = (s16) (*(u16 *) ((u8 *) arg2 + 0x8) - arg3 * *(s16 *) ((u8 *) arg1 + 0x8));
    *(s16 *) ((u8 *) arg0 + 0xA) = (s16) (*(u16 *) ((u8 *) arg2 + 0xA) - arg3 * *(s16 *) ((u8 *) arg1 + 0xA));
    *(s16 *) ((u8 *) arg0 + 0xC) = (s16) (*(u16 *) ((u8 *) arg2 + 0xC) - arg3 * *(s16 *) ((u8 *) arg1 + 0xC));
    *(s16 *) ((u8 *) arg0 + 0x12) = (s16) (*(u16 *) ((u8 *) arg2 + 0x12) - arg3 * *(s16 *) ((u8 *) arg1 + 0x12));
    *(s16 *) ((u8 *) arg0 + 0x14) = (s16) (*(u16 *) ((u8 *) arg2 + 0x14) - arg3 * *(s16 *) ((u8 *) arg1 + 0x14));
    *(s16 *) ((u8 *) arg0 + 0x16) = (s16) (*(u16 *) ((u8 *) arg2 + 0x16) - arg3 * *(s16 *) ((u8 *) arg1 + 0x16));
    *(s16 *) ((u8 *) arg0 + 0x18) = (s16) (*(u16 *) ((u8 *) arg2 + 0x18) - arg3 * *(s16 *) ((u8 *) arg1 + 0x18));
    *(s16 *) ((u8 *) arg0 + 0x1C) = (s16) (*(u16 *) ((u8 *) arg2 + 0x1C) - arg3 * *(s16 *) ((u8 *) arg1 + 0x1C));
    *(s16 *) ((u8 *) arg0 + 0x1E) = (s16) (*(u16 *) ((u8 *) arg2 + 0x1E) - arg3 * *(s16 *) ((u8 *) arg1 + 0x1E));
    *(s16 *) ((u8 *) arg0 + 0x20) = (s16) (*(u16 *) ((u8 *) arg2 + 0x20) - arg3 * *(s16 *) ((u8 *) arg1 + 0x20));
    *(s16 *) ((u8 *) arg0 + 0x22) = (s16) (*(u16 *) ((u8 *) arg2 + 0x22) - arg3 * *(s16 *) ((u8 *) arg1 + 0x22));
}

void func_80123430(s32 arg0, s32 arg1, u16 *arg2, u16 *arg3) {
    extern void func_80122E40(u8 *, u8 *);
    extern void func_801231CC(s32, s32, s32, s32, s32);
    register s32 s4v asm("s4");
    register u16 *s2v asm("s2");
    register u16 *s1v asm("s1");
    register u16 *s0v asm("s0");
    register s32 s3v asm("s3");
    register s32 s5v asm("s5");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    u16 buf1[0x14];
    u8 buf2[0x80];
    s32 i;
    s32 j;

    s4v = arg0;
    KEEP_NOVOL(s4v);
    s2v = (u16 *) arg1;
    KEEP_NOVOL(s2v);
    s1v = arg2;
    s0v = arg3;
    func_80122E40((u8 *) s2v, (u8 *) s4v);
    s3v = 0;
    s5v = (s32) buf2;
    do {
        a0v = s5v;
        a1v = (s32) buf1;
        KEEP_NOVOL(a1v);
        j = s1v[0] & 0x3FF;
        i = s0v[0] & 0x3FF;
        s0v++;
        func_801231CC(a0v, a1v, j, i, s3v);
        func_80123288(s4v, s4v, s5v, -1);
        s2v[7] = s2v[7] + buf1[7];
        s2v[10] = s2v[10] + buf1[10];
        s1v++;
        s3v++;
    } while (s3v < 5);
}

extern void func_80122F9C(s32, u16 *, u16 *, s32);

void func_80123508(void *arg0, u16 *arg1) {
    u16 sp[0x54];
    W23508Rec24 *s0 = (W23508Rec24 *) arg0;
    s32 s1 = 0;
    u8 *s2 = (u8 *) arg1;

    KEEP(s0);
    s0->f06 = 0;
    s0->f08 = 0;
    s0->f0C = 0;
    s0->f0A = 0;
    s0->f16 = 0;
    s0->f18 = 0;
    s0->f20 = 0;
    s0->f22 = 0;
    do {
        func_80122F9C(*(u16 *) s2 & 0x3FF, &sp[0], &sp[0x14], s1);
        s0->f06 = s0->f06 + sp[0x17];
        s0->f08 = s0->f08 + sp[0x18];
        s0->f0A = s0->f0A + sp[0x19];
        s0->f0C = s0->f0C + sp[0x1A];
        s0->f16 = s0->f16 + sp[0x1F];
        s0->f18 = s0->f18 + sp[0x20];
        s0->f20 = s0->f20 + sp[0x24];
        s0->f22 = s0->f22 + sp[0x25];
        s1 += 1;
        KEEP(s1);
        s2 += 2;
    } while (s1 < 5);
}

extern s16 D_801C8634;

s32 func_80123628(s32 arg0) {
    register s32 t1v asm("t1") = 0;
    register s32 t0v asm("t0") = 0;
    register s32 t2v asm("t2");
    register s32 a2v asm("a2");
    s32 *a3;
    s32 a1;
    u8 *v1;
    s32 v0;
    volatile s32 pad[2];

    a2v = 1;
    while (a2v < 0xFE) {
        if (D_800596E0[a2v] != 0) {
            t1v = 1;
            break;
        }
        a2v++;
    }
    v0 = D_801C8634;
    a2v = 0;
    if (v0 > 0) {
        t2v = v0;
        a3 = D_801CD5EC;
        do {
            a1 = 0;
            v1 = (u8 *) a3[0];
            while (a1 < 5) {
                if (*(u16 *) (v1 + 0x54) != 0) {
                    t0v = 1;
                    break;
                }
                a1++;
                v1 += 2;
            }
            a2v++;
            a3++;
        } while (a2v < t2v);
    }
    if (arg0 == 0) {
        v0 = 0;
        if (t0v != 0) {
            goto set_one;
        }
        if (t1v != 0) {
set_one:
            v0 = 1;
        }
    } else {
        register s32 one asm("v1") = 1;
        if (arg0 != one) {
            v0 = t0v;
        } else {
            v0 = t1v;
        }
    }
    return v0;
}

extern u32 D_80062EC0[];

u16 func_80123708(s32 arg0) {
    arg0 &= 0x3FF;
    return *(u16 *) &D_80062EC0[arg0 * 3];
}

u32 func_8012372C(s32 arg0) {
    register s32 a0 asm("a0") = arg0;
    register s32 v0 asm("v0");

    a0 &= 0x3FF;
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 2;
    v0 = *(u16 *) ((u8 *) D_80062EC0 + v0);
    v0 >>= 1;
    if (v0 == 0) {
        v0 = 1;
    }
    return v0;
}

s32 func_80123764(s32 arg0) {
    register s32 t0v asm("t0") = 0;
    register s32 a0v asm("a0") = arg0;
    register s32 a1v asm("a1") = 0;
    register s32 a2v asm("a2") = 0;
    register s32 a3v asm("a3");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    volatile s32 pad[2];

    v0v = D_801C8634;
    a0v &= 0x3FF;
    if (v0v <= 0) {
        goto end;
    }
    a3v = (s32) &D_801CD5EC;
outer:
    a1v = 0;
    v1v = *(s32 *) a3v;
inner:
    v0v = *(u16 *) (v1v + 0x54);
    if (v0v == a0v) {
        a2v += 1;
    }
    v1v += 2;
    a1v += 1;
    v0v = a1v < 5;
    if (v0v != 0) {
        goto inner;
    }
    v0v = D_801C8634;
    t0v += 1;
    v0v = t0v < v0v;
    a3v += 4;
    if (v0v != 0) {
        goto outer;
    }
end:
    v0v = a2v;
    return v0v;
}

extern s32 func_801208B8(s32, s32);

s32 func_801237E4(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;

    temp_s0_2 = arg0 & 0x3FF;
    temp_s0 = func_801208B8(temp_s0_2, 0);
    return temp_s0 + func_80123764(temp_s0_2);
}

extern u8 D_80059494;

s32 func_80123824(s32 arg0, s32 arg1) {
    register s32 a0 asm("a0") = arg0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a0 &= 0x3FF;
    v0 = *(u8 *) ((u8 *) &D_80059494 + a0);
    v1 = v0 + arg1;
    v0 = v1 < 0x100;
    if (v1 < 0) {
        v1 = 0;
        KEEP_NOVOL(v1);
        v0 = v1 < 0x100;
    }
    if (v0 == 0) {
        v1 = 0xFF;
    }
    *(u8 *) ((u8 *) &D_80059494 + a0) = v1;
    return v1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012386C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80123DD8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80124428);

extern void func_8012B1B4(s32);
extern s32 func_8012B1EC(s32);

s32 func_8012457C(s32 arg0, s32 arg1) {
    s32 s1 = arg0;
    s32 s0 = arg1 & 0x3FF;
    s32 v1;

    if (s0 == 0) {
        return 1;
    }
    if (func_80125374(s0) == 5) {
        return -1;
    }
    func_8012B1B4(*(s32 *) ((u8 *) D_801CD5EC + ((arg0 << 16) >> 14)) + 0x73);
    func_8012B1EC(((s32 (*)(s32)) func_80124FD0)(s0));
    if (func_8012B1EC(1) == 0) {
        v1 = -1;
    } else {
        v1 = 1;
    }
    return v1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80124614);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801247E8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012499C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80124C54);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80124F14);

extern u32 D_80062EBD[];

u8 func_80124FD0(s32 arg0) {
    arg0 &= 0x3FF;
    return *(u8 *) &D_80062EBD[arg0 * 3];
}

extern u8 D_8018D7FC;
extern u8 D_8018D7FD;

void func_80124FF4(s32 arg0, u8 *arg1) {
    s32 a0 = arg0;
    u8 *a1 = arg1;
    s32 v0;
    register s32 v1 asm("v1");

    a0 <<= 1;
    v0 = *(u8 *) ((u8 *) &D_8018D7FC + a0);
    *(u16 *) a1 = v0;
    v1 = *(u8 *) ((u8 *) &D_8018D7FD + a0);
    v0 = 0x0C;
    *(u16 *) ((u8 *) a1 + 4) = v0;
    *(u16 *) ((u8 *) a1 + 6) = v0;
    *(u16 *) ((u8 *) a1 + 2) = v1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012502C);

s32 func_80125374(s32 arg0) {
    s32 v0;
    s32 v1;

    arg0 &= 0x3FF;
    v1 = 0;
    if (arg0 < 0x7A) {
        goto end;
    }
    v1 = 5;
    if (arg0 < 0x80) {
        goto end;
    }
    v1 = 1;
    if (arg0 < 0x90) {
        goto end;
    }
    v1 = 2;
    if (arg0 < 0xAC) {
        goto end;
    }
    if (arg0 < 0xD0) {
        v1 = 3;
        goto end;
    }
    v1 = 5;
    if (arg0 < 0xF0) {
        v1 = 4;
    }
end:
    return v1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801253D4);

s32 func_80125540(s32 arg0) {
    s32 s0v;
    s32 v0v;
    s32 v1v;
    s32 a0v;

    v0v = (s32) D_801CD5EC;
    a0v = arg0 << 2;
    s0v = a0v + v0v;
    v1v = *(s32 *) s0v;
    v0v = *(u8 *) (v1v + 0x11F);
    if (v0v != 0) {
        v0v = -2;
        goto end;
    }
    v0v = *(s16 *) (v1v + 0x3E);
    if (v0v != 0) {
        v0v = -3;
        goto end;
    }
    a0v = *(s16 *) (v1v + 0x24);
    v0v = func_80120B90(a0v);
    if (v0v != 0) {
        v0v = -3;
        goto end;
    }
    a0v = *(s32 *) s0v;
    v0v = *(u8 *) (a0v + 0x70) & 4;
    v1v = 0x5D;
    if (v0v != 0) {
        v0v = -4;
        goto end;
    }
    a0v = *(s16 *) (a0v + 0x24);
    if (a0v != v1v) {
        v0v = 1;
    } else {
        v0v = -6;
    }
end:
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801255E4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801256C8);

s32 func_80125844(s16 arg0) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s32 pad;

    USE_NOVOL(&pad);
    a1 = D_801C8634;
    v1 = a1 - a1;
    if (a1 <= 0) {
        goto end;
    }
    v0 = arg0;
    v0 <<= 16;
    a2 = v0 >> 16;
    a0 = (s32) D_801CD5EC;
loop:
    v0 = *(s32 *) a0;
    v0 = *(s16 *) (v0 + 0x2C);
    if (v0 == a2) {
        goto end;
    }
    v1++;
    a0 += 4;
    if (v1 < a1) {
        goto loop;
    }
end:
    v0 = v1;
    return v0;
}

extern u8 D_8018DE34[];
extern s32 D_8018DA44[];
extern void func_800222DC();

void func_801258A4(s32 arg0, s32 arg1, s32 arg2) {
    s16 tv;
    s16 w;
    s32 t2;
    s32 r;
    s32 a0v;

    tv = arg0;
    if (tv < 0x35) {
        w = D_8018DE34[tv];
        goto Lend;
    }
    if (tv == 0x5C) {
        w = 0x3B;
        goto Lend;
    }
    if (tv == 0x5B) {
        w = 0x3A;
        goto Lend;
    }
    if (tv == 0x5D) {
        w = 0x3C;
        goto L908;
    }
    t2 = arg0 * 2;
    w = t2 - 0x7C;
L908:
    if ((s16) arg1 != 0) {
        w = w + 1;
    }
Lend:
    r = w;
    a0v = r * 3 * 4;
    a0v = a0v + (s32) D_8018DA44;
    func_800222DC(a0v, arg2, 0xC);
}

extern s32 D_801CD63C;

void func_80125954(s32 arg0) {
    s32 a0;

    a0 = *(s32 *) ((u8 *) D_801CD5EC + ((arg0 << 16) >> 14));
    func_800222DC(a0, D_801CD63C, 0x128);
}

extern u8 D_8018DE84[];
extern u8 D_8018DE85[];
extern u8 D_8018DE86[];

u8 func_80125990(s32 arg0, s32 arg1) {
    register s32 var_a2 asm("a2");
    register s32 var_a3 asm("a3");
    register u8 temp_v1 asm("v1");
    register s32 v0 asm("v0");

    var_a3 = 0;
    var_a2 = 0;
loop_1:
    temp_v1 = *(D_8018DE84 + var_a2);
    if (arg0 < (s32) temp_v1) {
        goto result_index;
    }
    if (arg0 != temp_v1) {
        goto advance;
    }
    v0 = *(D_8018DE85 + var_a2);
    if ((s32) v0 < arg1) {
        v0 = var_a3 * 2;
        goto advance;
    }
    v0 = var_a3 * 2;
    goto result_add;
advance:
    var_a3 += 1;
    var_a2 += 3;
    if (var_a3 < 0xD) {
        goto loop_1;
    }
result_index:
    v0 = var_a3 * 2;
result_add:
    v0 = v0 + var_a3;
    return *(D_8018DE86 + v0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80125A04);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80125A14);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80125CFC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80125D04);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80125E40);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80125E48);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80126058);

extern s8 D_8018DF7C;

void func_80126374(s32 arg0) {
    D_8018DF7C = arg0;
    if (arg0 == 0) {
        arg0 = 1;
    }
    func_800F1330(arg0);
}

s32 func_801263A8(void) {
    s32 t = D_8018DF7C;

    if (t == 0)
        return 1;
    return t;
}

extern u8 D_801C9E84[];
extern s16 D_801C9E88;
extern s16 D_8018DF80;
extern u8 D_8018DFB4;
extern u8 D_8018E028;
extern s16 D_801C9E9C;
extern u8 D_801C9EA8;
extern s32 D_801C9EAC;
extern volatile s32 D_801C9EAC_v asm("D_801C9EAC");
extern s32 D_801C9EB0;
extern s8 D_801C9ED0;
extern s16 D_801CD54C;
extern u16 D_801CD824;

void func_801263C8() {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    u16 temp;

    D_801C9EAC = a0v;
    D_801C9EB0 = a2v;
    v0v = -1;
    if (a0v != 0) {
        D_801CD824 = 0;
        v1v = *(s16 *) a0v;
        if (v1v != v0v) {
            v1v = D_801C9EAC_v;
            a0v = -1;
            do {
                v0v = D_801CD824;
                v0v += 1;
                D_801CD824 = v0v;
                v0v <<= 16;
                v0v >>= 15;
                v0v = v0v + v1v;
                v0v = *(s16 *) v0v;
            } while (v0v != a0v);
        }
    }
    D_801CD20C = a1v;
    if (a1v == 0) {
        D_801CD54C = 0;
    }
    v1v = 0x80;
    D_801C9E88 = 0;
    D_801C9E9C = 0;
    D_8018DF80 = 0;
    MEMORY_BARRIER();
    v0v = (s32) &D_801C9E84;
    KEEP(v0v);
    *(u8 *) (v0v + 0) = v1v;
    *(u8 *) (v0v + 1) = v1v;
    *(u8 *) (v0v + 2) = v1v;
    v0v = 1;
    D_801C9EA8 = v0v;
    D_8018E028 = 0;
    D_801C9ED0 = 0;
    D_8018DFB4 = 0;
}

extern u16 D_801C9EA0;
extern void func_801263C8();

void func_801264A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    register s32 s0 asm("s0");
    MEMORY_BARRIER();

    s0 = arg2;
    func_801263C8(arg0, arg1, arg3);
    D_801CD54C = s0;
}

extern s32 D_8018DFB8[];
extern s32 D_801C9E8C;

void func_801264DC(u8 *arg0, s32 arg1) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    u8 *p;

    D_801C9E88 = 0;
    D_801C9EA0 = 0;
    D_801C9E8C = arg1;
    D_801C9ED0 = 0;
    p = arg0;
    v1v = *p;
    v0v = 0x1C;
    if (v1v == v0v) {
        goto end;
    }
    s0v = 0x1C;
    s1v = (s32) D_8018DFB8;
    KEEP(s1v);
    v0v = *(volatile u8 *) p;
    v0v <<= 2;
loop:
    v0v += s1v;
    v0v = *(s32 *) v0v;
    ((s32 (*)(u8 *)) v0v)(p);
    p = (u8 *) v0v;
    v0v = *p;
    if (v0v != s0v) {
        v0v <<= 2;
        goto loop;
    }
end:
    return;
}

extern void func_801264DC(u8 *, s32);
extern void func_801298C0(s32);

void func_80126570(u8 *arg0, u8 *arg1, s32 arg2) {
    register s32 a0v asm("a0");
    register u8 *s1v asm("s1");
    register u8 *s0v asm("s0");

    SCHED_BARRIER();
    s1v = arg0;
    a0v = arg2;
    if (a0v != 0) {
        s0v = 0;
    } else {
        s0v = arg1;
    }
    func_801298C0(a0v);
    func_801264DC(s1v, s0v);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801265C0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801266E8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80126888);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80126968);

extern void func_8012C1E0();

void *func_80126A98(u8 *arg0) {
    register u8 *s0 asm("s0");
    s16 sp[4];
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");

    MEMORY_BARRIER();
    s0 = arg0;
    sp[0] = s0[2];
    sp[1] = s0[3];
    sp[2] = s0[4];
    sp[3] = s0[5];
    MEMORY_BARRIER();
    a2v = (u8) D_801C9EA0;
    a3v = D_801C9E88;
    func_8012C1E0(sp, s0 + 6, a2v, a3v);
    return s0 + s0[1];
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80126B14);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80126C30);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801274D8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80127620);

extern s16 func_80023A54(s32, s32);
extern s16 D_801C9EB8;

void *func_801279FC(void *arg0) {
    register u8 *s0 asm("s0");
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 a1v asm("a1");

    __asm__ volatile("" ::: "ra");
    s0 = (u8 *) arg0;
    a0v = s0[3];
    v0v = s0[4];
    KEEP(v0v);
    a1v = s0[2];
    a1v <<= 8;
    a0v <<= 4;
    KEEP_WITH(a1v, v0v);
    a1v = v0v + a1v;
    D_801C9EB8 = func_80023A54(a0v, a1v);
    return s0 + s0[1];
}

extern u8 D_801C9EC8;

void *func_80127A54(u8 *arg0) {
    register u8 *s0 asm("s0");
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 a1v asm("a1");

    MEMORY_BARRIER();
    s0 = arg0;
    if (D_801C9EC8 != 0) {
        a0v = s0[6];
        v0v = s0[7];
        KEEP(v0v);
        a1v = s0[5];
        a1v <<= 8;
    } else {
        a0v = s0[3];
        v0v = s0[4];
        KEEP(v0v);
        a1v = s0[2];
        a1v <<= 8;
    }
    a0v <<= 4;
    D_801C9EB8 = func_80023A54(a0v, v0v + a1v);
    return s0 + s0[1];
}

extern s16 D_801C9EB4;

void *func_80127AD0(void *arg0) {
    register u8 *s0 asm("s0");
    u8 temp_a3;

    __asm__ volatile("" ::: "ra");
    s0 = (u8 *) arg0;
    temp_a3 = s0[2];
    D_801C9EB4 = func_8002398C(s0[4], temp_a3 >> 4, s0[3] * 0x10, temp_a3 << 8);
    return s0 + s0[1];
}

u8 *func_80127B24(u8 *arg0) {
    D_801C9EA0 = arg0[3];
    return arg0 + arg0[1];
}

extern void func_8012D340();

void *func_80127B3C(u8 *arg0) {
    s32 pad[2];
    register u8 *s0 asm("s0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    register s32 v0v asm("v0");
    s32 v1v;

    __asm__ volatile("" ::: "memory", "ra", "$16");
    s0 = arg0;
    a0v = 0;
    a1v = s0[2];
    MEMORY_BARRIER();
    a2v = 0x100;
    a3v = 0;
    v0v = func_8002398C(a0v, a1v, a2v, a3v);
    v1v = D_801C9E88;
    pad[0] = v1v;
    MEMORY_BARRIER();
    a0v = 0;
    a1v = 0;
    MEMORY_BARRIER();
    a2v = v0v & 0xFFFF;
    a3v = 0;
    func_8012D340(a0v, a1v, a2v, a3v);
    return s0 + s0[1];
}

u8 *func_80127BA4(u8 *arg0) {
    register u8 *a0 asm("a0") = arg0;
    register u8 *v1 asm("v1");
    register s32 v0 asm("v0");

    v0 = D_801C9EC8;
    if (v0 != 0) {
        v1 = (u8 *) &D_801C9E84;
        KEEP(v1);
        v0 = a0[5];
        v1[0] = v0;
        v0 = a0[6];
        v1[1] = v0;
        v0 = a0[7];
        v1[2] = v0;
    } else {
        v1 = (u8 *) &D_801C9E84;
        KEEP(v1);
        v0 = a0[2];
        v1[0] = v0;
        v0 = a0[3];
        v1[1] = v0;
        v0 = a0[4];
        v1[2] = v0;
    }
    v0 = a0[1];
    return a0 + v0;
}

u8 *func_80127C1C(u8 *arg0) {
    D_801C9E88 = arg0[3];
    return arg0 + arg0[1];
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80127C34);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801280FC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801282DC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012859C);

u8 *func_801288F0(u8 *arg0) {
    s32 v0v;
    s32 v1v;
    s32 v1;

    v1v = arg0[0];
    v0v = 1;
    if (v1v == v0v) {
        v1v = arg0[4];
        v1v += 1;
    } else if (v1v == 2) {
        v1v = arg0[4];
        v0v = arg0[5];
        v1v += v0v;
        v1v += 1;
    } else {
        v1 = 1;
        v1v = v1;
    }
    v1v--;
    if (v1v != -1) {
        do {
            v1v--;
            arg0 += arg0[1];
        } while (v1v != -1);
    }
    return arg0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012895C);

extern void func_8012895C(s32);

void func_80128C7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    register s32 s0 asm("s0") = arg3;

    __asm__("" ::: "ra");
    func_801263C8();
    func_8012895C(s0);
}

extern void func_801264A8();

void func_80128CAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 s0 = arg4;

    __asm__("" ::: "ra");
    func_801264A8(arg0, arg1, arg2, arg3);
    func_8012895C(s0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80128CE0);

void func_80129874(u8 *arg0) {
    u8 *p;

    if (arg0 != 0) {
        p = D_801C9E84;
        KEEP_NOVOL(p);
        p[0] = arg0[0];
        ((volatile u8 *) p)[1] = arg0[1];
        ((volatile u8 *) p)[2] = arg0[2];
    }
}

void func_801298B0(s32 arg0) {
    D_801C9E88 = arg0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_801298C0);

extern s16 D_8018E02E;
extern void func_8012D25C(s16 *, s32);

u8 *func_801299C8(u8 *arg0) {
    register u8 *p asm("s0");
    s16 *q;
    s32 cond;

    MEMORY_BARRIER();
    cond = D_801C9ED0;
    MEMORY_BARRIER();
    p = arg0;
    if (cond != 0) {
        q = &D_8018E02E;
        *q = 0;
        func_8012D25C((s16 *) ((u8 *) q - 2), D_801C9E88 + 1);
        D_801C9ED0 = 0;
    }
    return p + p[1];
}

void *func_80129A30(void *arg0) {
    register u8 *p asm("s0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    s16 sp[4];
    s32 cond;

    MEMORY_BARRIER();
    cond = D_801C9ED0;
    p = (u8 *) arg0;
    if (cond == 0) {
        sp[0] = p[2];
        sp[1] = p[3];
        sp[2] = p[4];
        sp[3] = p[5];
        MEMORY_BARRIER();
        a1 = D_801C9E88;
        a0 = (s32) sp;
        a1 -= 1;
        func_8012D25C((s16 *) a0, a1);
    }
    return p + p[1];
}

u8 *func_80129AB4(u8 *arg0) {
    register u8 *p asm("s0");
    s16 *q;
    s32 cond;

    MEMORY_BARRIER();
    cond = D_801C9ED0;
    MEMORY_BARRIER();
    p = arg0;
    if (cond == 0) {
        q = &D_8018E02E;
        *q = 0;
        func_8012D25C((s16 *) ((u8 *) q - 2), D_801C9E88 + 1);
    }
    return p + p[1];
}

void func_80129B14(s32 arg0) {
    D_8018E028 = arg0;
}

s32 func_80129B24(void) {
    return *(s8 *) &D_8018E028;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80129B34);

s32 func_80129B4C(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s32 unused[2];

    v0 = v1 + 1;
    D_8018E028 = (s8) v0;
    __asm__ volatile(".L80129B5C:");
    v0 = arg0 + 1;
    return v0;
}

s32 *func_80129B6C(void) {
    return (s32 *) D_801C9E84;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80129B7C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80129CEC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_80129E4C);

u8 *func_8012A08C(u8 *arg0, s32 arg1, s32 arg2) {
    register u8 *a0 asm("a0") = arg0;
    register s32 a1 asm("a1") = arg1;
    register s32 a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a2 = arg1 + 0;
    a1 <<= 16;
    if (a1 != 0) {
        do {
            v0 = *a0;
            KEEP(v0);
            v1 = v0 & 0xFF;
            a0 += 1;
            if (v1 >= 0xD0U) {
                if (v1 < 0xE0U) {
                    a0 += 1;
                    goto block_6;
                }
                v0 = v1 < 0xFEU;
                if (v0 == 0) {
                    a2 -= 1;
                }
                goto block_6;
            } else {
block_6:
                v0 = a2 << 16;
            }
        } while (v0 != 0);
    }
    return a0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012A0E8);

extern s32 func_800E4D9C;

void func_8012A370(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32 (*)()) func_800FFEEC)() == 0) {
        func_800FFD70(arg0, &func_800E4D9C);
        func_800FFF08(arg0, arg1, arg2, arg3);
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012A3E8);

void func_8012A4C8(u8 *arg0, u8 *arg1, s16 *arg2, s32 arg3) {
    extern u8 *func_8012A08C(u8 *, s32, s32);
    register u8 *s0v asm("s0");
    register u8 *s3v asm("s3");
    register s32 s2v asm("s2");
    register s16 *s1v asm("s1");
    u8 *pa;

    s3v = arg0;
    s0v = arg1;
    KEEP_NOVOL(s3v);
    s2v = arg3;
    if (*arg2 != -1) {
        s1v = arg2;
        do {
            pa = func_8012A08C(s3v, *(u16 *) s1v & 0x7FF, 1);
            while (*pa != 0xFE) {
                *s0v = *pa;
                pa++;
                s0v++;
            }
            s1v++;
            if (s2v != 0) {
                *s0v = 0xF8;
                s0v++;
            }
        } while (*s1v != -1);
    }
    if (s2v != 0) {
        s0v--;
    }
    *s0v = 0xFE;
}

void func_8012A598(void) {
    s32 a0v;
    func_800FFF08(a0v, 0, 0, 1);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012A5C0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012A6D8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012A818);

void *func_8012A908(u8 *arg0, s32 arg1) {
    s32 a0 = (s32) arg0;
    s32 a1 = arg1;
    s32 a3 = 0;
    s32 a2;
    s32 t0;
    s32 v0;
    s32 v1;
    s32 pad;

    USE_NOVOL(&pad);
    a2 = a1 - a1;
    if (a1 <= 0) {
        goto end;
    }
    t0 = 0xFE;
    v1 = a0;
loop:
    v0 = *(u8 *) v1;
    if (v0 == t0) {
        goto end;
    }
    v0 = a0 + a2;
    v0 = *(volatile u8 *) v1;
    v0 = (v0 + 0x30) & 0xFF;
    if ((u32) v0 < 0x10) {
        v1 += 2;
        a2 += 2;
    } else {
        v1++;
        a2++;
    }
    a3++;
    if (a3 < a1) {
        goto loop;
    }
end:
    v0 = a0 + a2;
    return (void *) v0;
}

s32 func_8012A980(u8 *arg0) {
    u8 *p = arg0;
    s32 ret = 0;
    u8 endc;
    u8 c;

    endc = *p;
    if (endc != 0xFE) {
        endc = 0xFE;
loop_2:
        c = *p;
        KEEP_NOVOL(c);
        if (((u32) (c + 0x30) & 0xFF) < 0x10U) {
            p += 2;
        } else {
            p += 1;
        }
        ret++;
        c = *p;
        if (c != endc) {
            goto loop_2;
        }
    }
    return ret;
}

extern u8 D_801533E0[];

s32 func_8012A9D4(u8 *arg0) {
    register u8 *a0v asm("a0") = arg0;
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    register s32 t0v asm("t0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    v1v = *a0v;
    v0v = 0xFE;
    a1v = 0;
    if (v1v == v0v) {
        goto end;
    }
    t0v = 0xFA;
    a3v = 0xE7;
    a2v = 0xFE;
loop:
    v1v = *a0v;
    v0v = v1v < 0xE0;
    if (v0v == 0) {
        goto special;
    }
    v0v = v1v < 0xD0;
    if (v0v != 0) {
        goto table;
    }
    v0v = v1v & 0xF;
    a0v += 1;
    v1v = v0v << 1;
    v1v += v0v;
    v1v <<= 2;
    v1v += v0v;
    v0v = *a0v;
    v1v <<= 4;
    v1v += v0v;
table:
    v0v = *(u8 *) ((u8 *) D_801533E0 + v1v);
    a1v += v0v;
    goto advance;
special:
    if (v1v == t0v) {
        a1v += 4;
        goto advance;
    }
    if (v1v == a3v) {
        a0v += 1;
        v0v = *a0v;
        a1v += v0v;
    }
advance:
    a0v += 1;
    v0v = *a0v;
    if (v0v != a2v) {
        goto loop;
    }
end:
    return a1v;
}

extern s32 D_8018E430;
extern void *func_8012A908();

s16 func_8012AA84(s32 arg0, s32 arg1, s32 arg2) {
    s32 s0v = arg2;
    s32 pv;
    s32 t;
    s32 a1v;

    a1v = (s16) arg1;
    MEMORY_BARRIER();
    pv = (s32) func_8012A908(func_8012A08C(arg0, a1v, 2), s0v);
    USE(pv);
    t = *(u8 *) pv;
    if ((u32) (t - 0xD0) < 0x10) {
        pv = pv + 1;
        USE(pv);
        t = *(u8 *) pv | (t << 8);
    }
    return (s16) t;
}

void func_8012AAF4(void) {
    func_8012A598();
    D_8018E430 = 0;
}

extern void func_801128E0(void *, s32, s32);

void func_8012AB1C(s32 arg0) {
    s32 sp10;
    s32 s0 = arg0;

loop:
    if (func_800FFEEC(s0) != 0) {
        ((void (*)(s32)) func_8012A598)(s0);
        func_801128E0(&sp10, 0, 0);
        goto loop;
    }
    D_8018E430 = 0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012AB78);

s32 func_8012AB80(s32 arg0, void *arg1) {
    register s32 s0v asm("s0") = arg0;
    register s32 s1v asm("s1") = (s32) arg1;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    s32 temp;

    KEEP_NOVOL(s0v);
    KEEP_NOVOL(s1v);
    if (v0v != 0) {
        goto alternate;
    }
    v0v = ((s32 (*)()) func_800FFEEC)();
    if (v0v != 0) {
        v0v = 1;
        goto end;
    }
    temp = *(s32 *) ((u8 *) s1v + 0x28);
    D_801CD7E0 = (s32 *) s1v;
    func_800FFD70(s0v, temp);
    func_800FFF08(s0v, (s32) D_801CD7E0, 0, 0);
    v1v = 1;
    D_8018E430 = v1v;
    v0v = 1;
    goto end;
alternate:
    v0v = func_800FFEEC(s0v);
    D_8018E430 = v0v;
end:
    return v0v;
}

extern void func_8012AB78();

void func_8012AC14(s32 dummy0, u8 *arg1, s16 arg2) {
    s32 v0v;
    v0v = D_8018E430;

    if (v0v == 0) {
        *(u16 *) (arg1 + 0x38) = arg2;
    }
    func_8012AB78();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012AC44);

void func_8012AC4C(s32 arg0, void *arg1) {
    register s32 s1v asm("s1") = arg0;
    register s32 s2v asm("s2") = (s32) arg1;
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    s32 sp10;
    s32 temp;

    KEEP_NOVOL(s1v);
    KEEP_NOVOL(s2v);
    if (v0v != 0) {
        goto alternate;
    }
    ((void (*)()) func_8012AB1C)();
    s0v = 0;
    temp = *(s32 *) ((u8 *) s2v + 0x28);
    D_801CD7E0 = (s32 *) s2v;
    func_800FFD70(s1v, temp);
    func_800FFF08(s1v, (s32) D_801CD7E0, 0, 0);
loop:
    func_801128E0(&sp10, 0, 0);
    s0v += 1;
    v0v = s0v < 0x14;
    if (v0v != 0) {
        goto loop;
    }
    v0v = 1;
    goto end;
alternate:
    v0v = func_800FFEEC(s1v);
end:
    D_8018E430 = v0v;
}

void func_8012ACF4(s32 arg0) {
    if (D_801CD754 > 0x1FFFF) {
        D_801CD750 = D_801CD754;
        return;
    }
    if (D_801CD754 > 0) {
        func_800FFD70(1, &func_800E4D9C);
        func_800FFF08(1, arg0 + 0x38, D_801CD754, 0);
        D_8015330C = 1;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012AD7C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012AD84);

extern s8 D_8018E0B2;
extern s16 D_8018E458;
extern s32 D_8018E464;
extern s8 D_8018E478;
extern void func_8012A598_s(s32) asm("func_8012A598");

s32 func_8012B0E8(s16 arg0, s32 arg1) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 s0v asm("s0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    volatile s32 pad[2];

    a2v = arg0;
    v0v = D_8018E478;
    v1v = arg1;
    if (v0v != 0) {
        goto check;
    }
    a0v = 6;
    a1v = D_8018E464;
    s0v = (s32) &D_8018E458;
    D_8018E478 = v1v;
    *(s16 *) s0v = arg0;
    func_800FFD70(a0v, a1v);
    a0v = 6;
    a1v = s0v - 0x1C;
    a2v = 0;
    a3v = 0;
    func_800FFF08(a0v, a1v, a2v, a3v);
    v0v = 1;
    D_8018E0B2 = v0v;
check:
    v1v = D_8018E478;
    a0v = v1v + (v0v - v0v);
    v0v = 1;
    switch (v1v) {
    case 1:
        a0v = 6;
        func_8012A598_s(a0v);
        a0v = 6;
        v0v = func_800FFEEC(a0v);
        if (v0v == 0) {
            D_8018E0B2 = 0;
            D_8018E478 = 0;
            v0v = v1v - v1v;
            goto end;
        }
        v0v = 1;
        break;
    default:
        v0v = a0v - 1;
        D_8018E478 = v0v;
        v0v = 1;
        goto end;
    }
end:
    return v0v;
}

extern u8 D_8018E47C;

void func_8012B1B4(s32 arg0) {
    D_8018E47C = 1;
    D_801CA6F0 = arg0;
}

extern u8 D_8018E47D;

void func_8012B1D0(s32 arg0) {
    D_8018E47D = 1;
    D_801CA6F4 = arg0;
}

extern s32 D_8018E480;

s32 func_8012B1EC(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 a3 asm("a3");
    register s32 a1 asm("a1");
    register u8 *a2 asm("a2");
    register s32 v1 asm("v1");
    register s32 t0 asm("t0");
    register s32 t1 asm("t1");
    register s32 t2 asm("t2");

    v0 = 0;
    if (arg0 == 0) {
        return v0;
    }
    a3 = 0;
    if (D_8018E47C != 0) {
        D_8018E480 = 7;
        D_8018E47C = 0;
    }
    arg0--;
    v0 = -1;
    if (arg0 != v0) {
        t2 = 1;
        t1 = 7;
        t0 = -1;
        do {
            a2 = (u8 *) D_801CA6F0;
            v1 = D_8018E480;
            v0 = *a2;
            a1 = v1 - 1;
            D_8018E480 = a1;
            v0 >>= v1;
            v0 &= 1;
            if (v0 != 0) {
                v0 = 1 << arg0;
                a3 |= v0;
            }
            arg0--;
            if (a1 < 0) {
                v0 = a2 + 1;
                D_8018E480 = 7;
                D_801CA6F0 = v0;
            }
            v0 = a3;
        } while (arg0 != -1);
    }
    return a3;
}

extern s32 D_8018E484;

void func_8012B298(s32 arg0) {
    register s32 a0 asm("a0") = arg0;
    register s32 a1 asm("a1");
    register s32 a2 asm("a2") = arg0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v0 = D_8018E47C;
    if (v0 != 0) {
        D_8018E484 = 7;
        D_8018E47C = 0;
    }
    v1 = D_8018E484;
    v0 = v1 - 1;
    D_8018E484 = v0;
    a0 = (s32) D_801CA6F0;
    v0 = 1;
    a1 = v0 << v1;
    v0 = *(u8 *) a0;
    v1 = ~a1;
    v0 &= v1;
    *(u8 *) a0 = (u8) v0;
    v0 = a2 & 0xFF;
    if (v0 != 0) {
        v1 = (s32) D_801CA6F0;
        v0 = *(u8 *) v1;
        v0 = a1 | v0;
        *(u8 *) v1 = (u8) v0;
    }
    v0 = D_8018E484;
    if (v0 < 0) {
        v1 = 7;
        v0 = (s32) D_801CA6F0;
        D_8018E484 = v1;
        v0 += 1;
        D_801CA6F0 = (s32) (u8 *) v0;
    }
}

extern s32 D_8018E488;

s32 func_8012B354(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 a3 asm("a3");
    register s32 a1 asm("a1");
    register u8 *a2 asm("a2");
    register s32 v1 asm("v1");
    register s32 t0 asm("t0");
    register s32 t1 asm("t1");
    register s32 t2 asm("t2");

    v0 = 0;
    if (arg0 == 0) {
        return v0;
    }
    a3 = 0;
    if (D_8018E47D != 0) {
        D_8018E488 = 7;
        D_8018E47D = 0;
    }
    arg0--;
    v0 = -1;
    if (arg0 != v0) {
        t2 = 1;
        t1 = 7;
        t0 = -1;
        do {
            a2 = (u8 *) D_801CA6F4;
            v1 = D_8018E488;
            v0 = *a2;
            a1 = v1 - 1;
            D_8018E488 = a1;
            v0 >>= v1;
            v0 &= 1;
            if (v0 != 0) {
                v0 = 1 << arg0;
                a3 |= v0;
            }
            arg0--;
            if (a1 < 0) {
                v0 = a2 + 1;
                D_8018E488 = 7;
                D_801CA6F4 = v0;
            }
            v0 = a3;
        } while (arg0 != -1);
    }
    return a3;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012B400);

extern s8 D_8018BACC;
extern void func_8012B400();
extern s32 func_80129B24();
extern s32 func_8012D418();
extern u8 D_8018E492;

void func_8012B7E0(void) {
    extern s32 func_800FFEEC(s32);
    s32 var_s0;
    u8 var_v1;

    var_s0 = 0;
    func_8012B400();
    if ((u32) (func_80129B24() - 1) >= 3U) {
        var_s0 = func_800FFEEC(1);
        if ((var_s0 != 0) || (D_801CD750 != 0)) {
            func_8012BD7C();
            if ((var_s0 != 0) && (D_8015330C != 0)) {
                var_v1 = 1;
                if (D_8018E492 != 0) {
                    var_v1 = 2;
                }
                D_8018E492 = var_v1;
            } else {
                D_8018E492 = 0;
            }
        } else if ((D_8018E492 != 0) || (func_8012D418() != 0)) {
            D_8018E492 = 0;
            goto block_12;
        }
    } else {
block_12:
        func_8012BD7C();
    }
    if (var_s0 == 0) {
        D_8015330C = 0;
        D_8018BACD = 0;
    }
    if (D_8018E492 == 1) {
        D_8018BACC = 0x12;
    }
}

extern s16 D_801CA75A;

void func_8012B90C(void) {
    s32 i = 0xF;
    s16 *p = &D_801CA75A;

    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}

extern u16 D_801CA73C[];

s16 func_8012B930(s32 arg0, s32 arg1) {
    D_801CA73C[arg0 & 0xFF] = arg1;
    return arg1;
}

s16 func_8012B950(s32 arg0, s32 arg1) {
    D_801CA73C[arg0 & 0xFF] = arg1;
    return arg1;
}

s16 func_8012B970() {
    __asm__ volatile(
        ".word 0x27BDFFF0\n"
        ".word 0x30C21000\n"
        ".word 0x1040000E\n"
        ".word 0x00803821\n"
        ".word 0x30A200FF\n"
        "lui $3, %%hi(D_801CA73C)\n"
        "addiu $3, $3, %%lo(D_801CA73C)\n"
        ".word 0x00021040\n"
        ".word 0x00433021\n"
        ".word 0x84C20000\n"
        ".word 0x00000000\n"
        ".word 0x14400003\n"
        ".word 0x00401821\n"
        ".word 0x0804AE7C\n"
        ".word 0x2482FFFF\n"
        ".word 0x0804AE7C\n"
        ".word 0x2462FFFF\n"
        ".word 0x30C24000\n"
        ".word 0x1040000E\n"
        ".word 0x30A200FF\n"
        "lui $3, %%hi(D_801CA73C)\n"
        "addiu $3, $3, %%lo(D_801CA73C)\n"
        ".word 0x00021040\n"
        ".word 0x00433021\n"
        ".word 0x84C30000\n"
        ".word 0x30E2FFFF\n"
        ".word 0x2442FFFF\n"
        ".word 0x00602021\n"
        ".word 0x0062182A\n"
        ".word 0x14600002\n"
        ".word 0x24820001\n"
        ".word 0x00001021\n"
        ".word 0xA4C20000\n"
        ".word 0x30A200FF\n"
        ".word 0x00021040\n"
        "lui $1, %%hi(D_801CA73C)\n"
        "addu $1, $1, $2\n"
        "lh $2, %%lo(D_801CA73C)($1)\n"
        ".word 0x27BD0010\n" ::: "memory");
}

extern s16 func_8012B970();

void func_8012BA14(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 t;
    u16 s;

    t = arg1 & 0xFF;
    s = D_801CA73C[t];
    if ((s16) s != func_8012B970(arg0 & 0xFFFF, t)) {
        D_8018BACC = arg3;
    }
}

s16 func_8012BA7C() {
    __asm__ volatile(
        ".word 0x27BDFFF0\n"
        ".word 0x30C28000\n"
        ".word 0x1040000E\n"
        ".word 0x00803821\n"
        ".word 0x30A200FF\n"
        "lui $3, %%hi(D_801CA73C)\n"
        "addiu $3, $3, %%lo(D_801CA73C)\n"
        ".word 0x00021040\n"
        ".word 0x00433021\n"
        ".word 0x84C20000\n"
        ".word 0x00000000\n"
        ".word 0x14400003\n"
        ".word 0x00401821\n"
        ".word 0x0804AEBF\n"
        ".word 0x2482FFFF\n"
        ".word 0x0804AEBF\n"
        ".word 0x2462FFFF\n"
        ".word 0x30C22000\n"
        ".word 0x1040000E\n"
        ".word 0x30A200FF\n"
        "lui $3, %%hi(D_801CA73C)\n"
        "addiu $3, $3, %%lo(D_801CA73C)\n"
        ".word 0x00021040\n"
        ".word 0x00433021\n"
        ".word 0x84C30000\n"
        ".word 0x30E2FFFF\n"
        ".word 0x2442FFFF\n"
        ".word 0x00602021\n"
        ".word 0x0062182A\n"
        ".word 0x14600002\n"
        ".word 0x24820001\n"
        ".word 0x00001021\n"
        ".word 0xA4C20000\n"
        ".word 0x30A200FF\n"
        ".word 0x00021040\n"
        "lui $1, %%hi(D_801CA73C)\n"
        "addu $1, $1, $2\n"
        "lh $2, %%lo(D_801CA73C)($1)\n"
        ".word 0x27BD0010\n" ::: "memory");
}

extern s16 func_8012BA7C();

void func_8012BB20(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 t;
    u16 s;

    t = arg1 & 0xFF;
    s = D_801CA73C[t];
    if ((s16) s != func_8012BA7C(arg0 & 0xFFFF, t)) {
        D_8018BACC = arg3;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012BB88);

extern u16 D_801CD810;
extern void func_801325D4();
extern u8 D_8018E48C;

s32 func_8012BD14(void) {
    s32 a0v;
    s32 s0v;
    s32 v0v;
    v0v = D_8018E48C;

    if (v0v != 0) {
        s0v = D_801CD810;
        v0v = 0x90C;
        goto merge;
    }
    v0v = 0;
    __asm__ volatile("" ::: "$2");
    a0v = 0;
    s0v = func_8001DB58(a0v);
    v0v = 0x90C;
merge:
    if (s0v == v0v) {
        func_801325D4();
        func_8012BD9C();
    }
    v0v = s0v;
    return v0v;
}

extern s16 D_801CD838;
extern s32 D_801CD668;
extern s32 D_801CD52C;

void func_8012BD7C(void) {
    D_801CD838 = 0;
    D_801CD668 = 0;
    D_801CD52C = 0;
}

extern void func_80040974();

void func_8012BD9C(void) {
    func_80040974();
}

extern s32 *D_801CD528;
extern u16 D_801CD514;
extern void func_80023C68();

void func_8012BDBC(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u16 n;
    u8 *p;
    s32 *b1;
    s32 *b2;
    register s32 mlo asm("a0");
    s32 i;

    n = D_801CD514;
    D_801CD514 = n + 1;
    b1 = D_801CD528;
    p = *(u8 **) ((u8 *) b1 + 0x3C) + n * 0x10;
    p[4] = arg1[0];
    p[5] = arg1[1];
    p[6] = arg1[2];
    func_80023C68(p, arg2 & 0xFF);
    b2 = D_801CD528;
    i = arg3 * 4;
    mlo = 0xFFFFFF;
    *(s16 *) (p + 8) = *(u16 *) arg0 + 0x80;
    *(u16 *) (p + 10) = *(u16 *) (arg0 + 2);
    *(u16 *) (p + 12) = *(u16 *) (arg0 + 4);
    *(u16 *) (p + 14) = *(u16 *) (arg0 + 6);
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & 0xFF000000) | ((s32) p & mlo);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012BEBC);

extern u16 D_801CD864;

void func_8012C014(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u16 n;
    u8 *p;
    s32 *b1;
    register s32 *b2 asm("a2");
    register s32 mlo asm("a0");
    s32 i;

    n = D_801CD864;
    D_801CD864 = n + 1;
    b1 = D_801CD528;
    p = (u8 *) ((((n << 3) + n) * 4) + *(u32 *) ((u8 *) b1 + 0x1C));
    func_80023C68(p, arg2);
    *(s16 *) (p + 8) = *(u16 *) arg0 + 0x80;
    *(u16 *) (p + 10) = *(u16 *) (arg0 + 2);
    *(s16 *) (p + 16) = *(u16 *) (arg0 + 4) + 0x80;
    *(u16 *) (p + 18) = *(u16 *) (arg0 + 6);
    *(s16 *) (p + 24) = *(u16 *) (arg0 + 8) + 0x80;
    *(u16 *) (p + 26) = *(u16 *) (arg0 + 10);
    *(s16 *) (p + 32) = *(u16 *) (arg0 + 12) + 0x80;
    *(u16 *) (p + 34) = *(u16 *) (arg0 + 14);
    p[4] = arg1[0];
    p[5] = arg1[1];
    p[6] = arg1[2];
    p[12] = arg1[3];
    p[13] = arg1[4];
    p[14] = arg1[5];
    p[20] = arg1[6];
    p[21] = arg1[7];
    p[22] = arg1[8];
    p[28] = arg1[9];
    p[29] = arg1[10];
    p[30] = arg1[11];
    i = arg3 * 4;
    b2 = D_801CD528;
    mlo = 0xFFFFFF;
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & 0xFF000000) | ((s32) p & mlo);
}

extern u16 D_801CD198;

void func_8012C1E0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u16 n;
    u8 *p;
    s32 *b1;
    s32 *b2;
    register s32 mlo asm("a0");
    s32 i;

    n = D_801CD198;
    D_801CD198 = n + 1;
    b1 = D_801CD528;
    p = *(u8 **) ((u8 *) b1 + 0x24) + n * 0x10;
    p[4] = arg1[0];
    p[5] = arg1[1];
    p[6] = arg1[2];
    func_80023C68(p, arg2 & 0xFF);
    mlo = 0xFFFFFF;
    *(s16 *) (p + 8) = *(u16 *) arg0 + 0x80;
    *(u16 *) (p + 10) = *(u16 *) (arg0 + 2);
    b2 = D_801CD528;
    i = arg3 * 4;
    *(u16 *) (p + 12) = *(u16 *) (arg0 + 4) + 0x80;
    *(u16 *) (p + 14) = *(u16 *) (arg0 + 6);
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & 0xFF000000) | ((s32) p & mlo);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012C2E4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012C430);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012C6A8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012C8BC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012CCD0);

extern u16 D_801CD520;
extern void func_80023EA0();

void func_8012CECC(u8 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    register s32 v1v asm("v1");
    register s32 s1v asm("s1") = arg3;
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    void *p;
    u16 t;
    s32 i;
    s32 *q;

    v1v = *(u16 *) &D_801CD520;
    MEMORY_BARRIER();
    D_801CD520 = v1v + 1;
    p = (void *) (((v1v * 2 + v1v) * 8) + *(s32 *) ((u8 *) D_801CD528 + 0x58));
    func_80023EA0(p);
    t = *(u16 *) arg0;
    a2v = (s32) D_801CD528;
    a0v = 0xFF0000;
    MEMORY_BARRIER();
    *(u16 *) ((u8 *) p + 0xC) = t;
    t = *(u16 *) (arg0 + 2);
    a0v |= 0xFFFF;
    *(u16 *) ((u8 *) p + 0x10) = arg1;
    *(u16 *) ((u8 *) p + 0x12) = arg2;
    *(u16 *) ((u8 *) p + 0xE) = t;
    *(u16 *) ((u8 *) p + 0x14) = *(u16 *) (arg0 + 4);
    *(u16 *) ((u8 *) p + 0x16) = *(u16 *) (arg0 + 6);
    i = s1v << 2;
    a1v = 0xFF000000;
    *(s32 *) p = (*(s32 *) p & a1v) |
        (*(s32 *) (i + *(s32 *) a2v) & a0v);
    q = (s32 *) ((u8 *) *(s32 *) a2v + i);
    *q = (*q & a1v) | ((s32) p & a0v);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012CFD4);

extern u16 D_801CD1D8;
extern u16 D_801CD430;
extern void func_800253DC();

void func_8012D25C(s16 *arg0, s32 arg1) {
    u16 limit;
    register s32 i asm("s1");
    register s32 j asm("a0");
    u16 n;
    s32 *p;
    s32 *b1;
    register void *src asm("a2");
    register s32 *b3 asm("a3");
    register s32 mlo asm("a1");

    limit = D_801CD1D8;
    src = arg0;
    __asm__("move %0, %1" : "=&r"(i) : "r"(arg1), "r"(src));
    if (limit >= 0x65) {
        *(u16 *) ((u8 *) src + 2) += 0xF0;
    }
    n = D_801CD430;
    D_801CD430 = n + 1;
    b1 = D_801CD528;
    p = (s32 *) (*(u8 **) ((u8 *) b1 + 0x5C) + n * 0xC);
    func_800253DC(p, src, src);
    b3 = D_801CD528;
    mlo = 0xFFFFFF;
    j = i * 4;
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (j + *b3) & mlo);
    *(s32 *) (j + *b3) = (*(s32 *) (j + *b3) & 0xFF000000) | ((s32) p & mlo);
}

extern u16 D_801CD504;
extern s32 func_800254CC(s32 *, s32, s32, s32, s32);

void func_8012D340(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u16 n;
    s32 *p;
    s32 *b1;
    s32 *b2;
    s32 *b3;
    register s32 i asm("s1");
    register s32 mlo asm("a0");
    register s32 mhi asm("a1");
    register s32 r0 asm("t0");
    register s32 r1 asm("t1");
    register s32 r2 asm("t2");

    r0 = arg0;
    r1 = arg1;
    r2 = arg2;
    __asm__("" : "=r"(r0), "=r"(r1), "=r"(r2) : "0"(r0), "1"(r1), "2"(r2));
    i = arg4;
    b1 = D_801CD528;
    n = D_801CD504;
    p = (s32 *) (*(u8 **) ((u8 *) b1 + 0x60) + n * 0xC);
    D_801CD504 = n + 1;
    func_800254CC(p, r0, r1, r2, arg3);
    b2 = D_801CD528;
    b3 = D_801CD528;
    mlo = 0xFFFFFF;
    i <<= 2;
    mhi = 0xFF000000;
    *(s32 *) p = (*(s32 *) p & mhi) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & mhi) | ((s32) p & mlo);
}

extern u8 D_8018E494;
extern u8 D_8018E495;
extern u8 D_8018E496;
extern s16 D_801CA760;

s32 func_8012D418(void) {
    s32 ret;

    if (D_8018E495 == 0) {
        ret = D_8018E494 + (D_8018E496 * 2);
    } else {
        ret = 0;
    }
    return ret;
}

void func_8012D454(void) {
    if (D_8018E495 == 0) {
        D_8018E494 = 1;
        D_8018E496 = 0;
        D_801CA760 = 0xF0;
    }
}

void func_8012D48C(void) {
    if (D_8018E495 == 0) {
        D_8018E494 = 0;
        D_8018E496 = 1;
        D_801CA760 = 0;
    }
}

extern s32 func_801263A8();
extern u8 D_8018E498;
extern u8 D_801CA75C;
extern u8 D_801CA75D;
extern u8 D_801CA75E;
extern u16 D_801CA760_u asm("D_801CA760");
extern u8 D_801CA760_b asm("D_801CA760");
extern u16 D_801CD224_u asm("D_801CD224");

s32 func_8012D4C0(void) {
    extern s32 func_8002398C(s32, s32, s32, s32);
    extern void func_8012BDBC(u8 *, u8 *, s32, s32);
    extern void func_8012D340(s32, s32, s32, s32, s32);
    s32 s0v;
    u16 temp_v1;
    u8 *p;

    s0v = 1;
    if (D_8018E495 != 0) {
        return 0;
    }
    if (D_8018E494 != 0) {
        temp_v1 = D_801CA760_u - (func_801263A8() * 0x10);
        D_801CA760_u = temp_v1;
        if ((temp_v1 << 0x10) <= 0) {
            D_8018E494 = 0;
            s0v = 0;
        }
        func_8012D340(0, 0, func_8002398C(0, 2, 0x100, 0) & 0xFFFF, 0,
                      D_801CD224_u - 2);
        D_801CA75E = D_801CA760_b;
        D_801CA75D = D_801CA760_b;
        p = &D_801CA75C;
        *p = D_801CA760_b;
        func_8012BDBC(&D_8018E498, p, 1, D_801CD224_u - 1);
    }
    return s0v;
}

s32 func_8012D5BC(void) {
    extern s32 func_8002398C(s32, s32, s32, s32);
    extern void func_8012BDBC(u8 *, u8 *, s32, s32);
    extern void func_8012D340(s32, s32, s32, s32, s32);
    s32 s0v;
    volatile s32 pad[4];
    u16 temp_v1;
    u8 *p;

    s0v = 1;
    if (D_8018E495 != 0) {
        return 0;
    }
    if (D_8018E496 != 0) {
        temp_v1 = D_801CA760_u + (func_801263A8() * 0x10);
        D_801CA760_u = temp_v1;
        if ((s16) temp_v1 >= 0x100) {
            s0v = 0;
            D_8018E496 = 0;
            D_801CA760_u = 0xFF;
        }
        func_8012D340(0, 0, func_8002398C(0, 2, 0x100, 0) & 0xFFFF, 0,
                      D_801CD224_u - 2);
        D_801CA75E = D_801CA760_b;
        D_801CA75D = D_801CA760_b;
        p = &D_801CA75C;
        *p = D_801CA760_b;
        func_8012BDBC(&D_8018E498, p, 1, D_801CD224_u - 1);
    }
    return s0v;
}

void func_8012D6CC(s32 arg0) {
    D_8018E495 = arg0;
}

void func_8012D6DC(void) {
    func_800248FC();
    do {
    } while (func_800246D4(1) != 0);
}

extern void func_80024960();

void func_8012D70C(void) {
    func_80024960();
    do {
    } while (func_800246D4(1) != 0);
}

extern void func_800249C4();

void func_8012D73C(s32 dummy0, s16 arg1, s16 arg2) {
    func_800249C4(dummy0, arg1, arg2);
    do {
    } while (func_800246D4(1) != 0);
}

extern s32 D_8018E4A0[];

void func_8012D778(s32 arg0) {
    s32 *p;
    s32 off;
    s32 *q;

    p = (s32 *) D_8018E4A0;
    off = arg0 << 3;
    q = (s32 *) ((u8 *) p + off);
    KEEP_NOVOL(p);
    p = (s32 *) ((u8 *) p + off);
    func_80044990(q[0], ((volatile s32 *) p)[1]);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_3", func_8012D7B4);

extern s32 D_80193C1C[];

s32 func_8012D898(s32 arg0) {
    return D_80193C1C[arg0];
}

extern s32 D_80193C40[];
extern s32 D_80193C78[];

void func_8012D8B0(s32 arg0, s32 *arg1) {
    extern s32 func_80044990(s32, s32);
    s32 s0v;
    s32 s1v;

    s0v = arg0 - 1;
    s1v = (s32) arg1;
    arg1[0x780] = func_80044990(D_80193C40[s0v * 2], *(s32 *) ((u8 *) D_80193C40 + s0v * 8 + 4));
    arg1[0x781] = func_80044990(D_80193C78[s0v * 2], *(s32 *) ((u8 *) D_80193C78 + s0v * 8 + 4));
}
