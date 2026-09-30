#include "common.h"

/* --- externs inherited from world.c at the unit split --- */
extern s16 D_801CD218;
extern s32 D_801CD5EC[];
extern s16 D_801CD230[];
extern s8 D_801CD788;
extern void func_800FFF08();
extern s32 func_8012457C(s32, s32);
extern s32 func_8001DB58();

void func_8012EBD0(void) {
    func_8001DB58(0);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8012EBF0);

extern void func_8012EBF0();
extern s32 func_80129B24();
extern void func_8012BD7C();
extern s32 func_8012D418();
extern s32 D_801CD750;
extern u8 D_80193DEC;
extern s8 D_8018BACD;

void func_8012EFCC(void) {
    extern s32 func_800FFEEC(s32);
    extern s32 D_8015330C;
    extern s8 D_8018BACC;
    s32 var_s0;
    u8 var_v1;

    var_s0 = 0;
    func_8012EBF0();
    if ((u32) (func_80129B24() - 1) >= 3U) {
        var_s0 = func_800FFEEC(1);
        if ((var_s0 != 0) || (D_801CD750 != 0)) {
            func_8012BD7C();
            if ((var_s0 != 0) && (D_8015330C != 0)) {
                var_v1 = 1;
                if (D_80193DEC != 0) {
                    var_v1 = 2;
                }
                D_80193DEC = var_v1;
            } else {
                D_80193DEC = 0;
            }
        } else if ((D_80193DEC != 0) || (func_8012D418() != 0)) {
            D_80193DEC = 0;
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
    if (D_80193DEC == 1) {
        D_8018BACC = 0x12;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8012F0F8);

extern s16 D_80193DF0;
extern s16 D_80193DFC;
extern s16 D_80193E70;
extern u8 D_80193E74;
extern u8 D_801CC800;
extern u8 D_801CC804;
extern s8 D_801CC80C;
extern s16 D_801CD732;
extern s32 D_801531D8;
extern u8 D_80057C69;
extern u8 D_80057C6A;

void func_8012F5E0(void) {
    extern void func_801325B4(s16, s16 *);
    extern s32 func_8012AB78(s32, void *);
    s8 var_v0;
    s16 *q;

    if (D_80193E74 == 0) {
        if (D_80193DF0 < 0x28) {
            D_80193DF0 += 1;
            return;
        }
        D_80193E74 = 1;
        D_801CC804 = 0xFF;
        D_801CC80C = 0;
        D_801CD732 = -1;
        D_80193E70 = (s16) D_80057C6A;
        return;
    }
    D_80193E74 = func_8012AB78(6, &D_80193DFC);
    if (D_80193E74 == 0) {
        q = &D_801CD732;
        if (*q == -1) {
            var_v0 = 9;
        } else {
            D_801531D8 = *q + 1;
            if (D_80057C6A != *q) {
                D_80057C69 = 0xFF;
            }
            D_80057C6A = (u8) *q;
            func_801325B4(*q, q);
            var_v0 = 2;
        }
        D_801CC800 = var_v0;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8012F700);

extern s32 D_801CD1EC;
extern u8 D_80194060;
extern u8 D_801CC7CC;
extern u8 D_801CC7D0;
extern s32 D_801CD52C;
extern s16 D_80193F70;
extern s16 D_80193FE8;
extern s32 D_80193CB4[];
extern void func_8012AC44();
extern void func_8012AB1C();
extern s32 func_80130338();
extern s32 func_801331FC();

void func_8012F994(s32 arg0) {
    extern u8 D_801CC808;
    extern u8 D_8018BACC;
    extern void func_800EF25C(s32, s32);
    s32 temp_s0;

    if (D_80194060 == 0) {
        D_80194060 = 1;
        D_801CC7CC = 0;
        D_801CC7D0 = 0;
        func_8012AC44(6, &D_80193F70);
        func_800222FC(D_801CD1EC, 0xFF, 0x1E80);
        return;
    }
    if ((u32) D_80194060 < 2U) {
        D_80194060 = D_80194060 + 1;
        return;
    }
    if (D_801CC7CC != 0) {
        func_8012AC44(6, &D_80193FE8);
        if ((D_801CD52C & 0x20) || (D_801CD52C & 0x40)) {
            func_8012AB1C(6);
            D_80194060 = 0;
            D_801CC800 = 2;
        }
    } else {
        temp_s0 = func_801331FC(D_80193CB4[arg0], D_801CD1EC, 0x1E00);
        func_8012AB1C(6);
        if (temp_s0 != 0x1E00) {
            D_80057C69 = 0xFF;
        } else if (func_80130338(0) != 0) {
            D_801CC808 = 1;
            D_80194060 = 0;
            D_801CC800 = 9;
            func_800EF25C(0x51, 1);
            D_8018BACC = 0x85;
            D_80057C69 = arg0;
            return;
        }
        D_801CC7CC = 1;
        D_8018BACC = 0x30;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8012FB40);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8012FB48);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8012FDD8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80130338);

extern void func_800222FC();
extern s32 func_80044414(s32);
extern s8 D_801CC808;
extern s16 D_801CC810;
extern s16 D_801CC818;
extern s16 D_801CC81C;
extern s16 D_801CC820;

void func_80130898(void) {
    s32 temp_v0;

    D_801CC818 = 0x18;
    D_801CC810 = 0;
    D_801CC820 = 0;
    D_801CC81C = 0;
    D_801CC80C = 0;
    D_801CC808 = 0;
    D_80193DF0 = 0;
    temp_v0 = func_80044414(0x2000);
    D_801CD1EC = temp_v0;
    func_800222FC(temp_v0, 0xFF, 0x1E80);
}

extern void func_80044600();

void func_8013090C(void) {
    s32 a0v;

    a0v = D_801CD1EC;
    func_80044600(a0v);
}

extern s8 D_80057C6C;
extern u8 D_800597E0[];
extern u8 D_800597E1[];
extern u8 D_800597E2[];

void func_80130934(s32 arg0) {
    s32 a3v;
    register s32 n asm("a2");
    s32 q;
    s32 r;
    s32 h;

    a3v = arg0;
    KEEP(a3v);
    if (*(s8 *) ((u8 *) &D_80057C6C + a3v) != 0) {
        D_800597E0[3 * a3v] = 0;
        D_800597E1[3 * a3v] = 0;
        D_800597E2[3 * a3v] = 0;
    } else {
        n = *(s32 *) (D_801CD1EC + 0x120);
        h = n / 3600;
        if (h >= 0x64) {
            h = 0x63;
        }
        q = n / 3600;
        r = n - q * 3600;
        D_800597E0[3 * a3v] = h;
        h = r / 60;
        r = r - h * 60;
        D_800597E1[3 * a3v] = h;
        D_800597E2[3 * a3v] = r;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80130A38);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80130A40);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801312A8);

extern u8 D_801CC82C[];
extern u8 D_80194260[];
extern void func_8012A5C0(void *, void *, s16 *, s32);
extern s32 D_801CD794;

void func_801315E4(s32 arg0) {
    register s32 a0 asm("a0") = arg0;
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    volatile s16 sp[4];

    v1 = a0;
    if (v1 < 6) {
        sp[0] = 0x240;
        v0 = (v1 << 5) + 0x130;
    } else if (v1 < 0xB) {
        sp[0] = 0x1C0;
        v0 = (v1 << 5) - 0x80;
    } else {
        sp[0] = 0x180;
        v0 = (v1 << 5) - 0x100;
    }
    sp[1] = (s16) v0;
    sp[2] = 0x32;
    sp[3] = 0x20;
    MEMORY_BARRIER();
    a0 = v1 << 3;
    a0 += v1;
    a0 <<= 2;
    a0 -= v1;
    a0 <<= 2;
    a0 += (s32) D_801CC82C;
    a2 = (s32) sp;
    a3 = 0;
    func_8012A5C0((void *) a0, (void *) D_80194260, (s16 *) a2, a3);
}

extern u8 D_801CC80C_u asm("D_801CC80C");
extern void func_801321D8(s32);

s32 func_80131690(void) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s8 *v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    s32 s0_2;

    s0v = 0;
    s1v = 0;
    a2v = -1;
    a1v = D_80057C69;
    a0v = D_801CC804;
    v1v = &D_80057C6C;
    D_801CD794 = 0;
    do {
        if (s0v == a1v) {
            D_801CC81C = s0v;
            D_801CC80C_u = s1v;
        }
        if (a0v != 0) {
            if (*v1v == 0) {
                s1v += 1;
            }
        } else if (*v1v != a2v) {
            s1v += 1;
        }
        s0v += 1;
        v1v += 1;
    } while (s0v < 0xF);
    s0_2 = 0;
    do {
        func_801321D8(D_801CC80C_u);
        if (D_801CC810 != 0) {
            s0_2 = 0;
        } else {
            s0_2 += 1;
        }
    } while (s0_2 < 0xA);
    return s1v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80131778);

extern u8 D_80194FDC;
extern u16 D_801CC818u asm("D_801CC818");

void func_801321D8(s32 arg0) {
    s32 v1v;
    register s32 v0v asm("v0");
    volatile s32 pad[6];

    v1v = D_801CC810;
    v0v = v1v;
    if (v1v == 0) {
        v0v = D_801CC820;
        v1v = v0v;
        v0v = arg0 < v0v;
        if (v0v != 0) {
            v1v = v1v - 1;
            D_801CC810 = 4;
            D_801CC820 = v1v;
        }
        v0v = D_801CC820;
        v1v = v0v;
        v0v = v0v + 4;
        v0v = arg0 < v0v;
        if (v0v == 0) {
            v1v = v1v + 1;
            D_801CC810 = -4;
            D_801CC820 = v1v;
        }
        return;
    }
    if (v1v < 0) {
        v0v = v0v - 4;
        D_801CC810 = v0v;
        if ((s16) v0v >= -0x2F) {
            return;
        }
        v0v = D_801CC818u;
        D_801CC810 = 0;
        v0v -= 0x30;
        goto tail;
    }
    if (v1v <= 0) {
        return;
    }
    v0v = v0v + 4;
    D_801CC810 = v0v;
    if ((s16) v0v < 0x30) {
        return;
    }
    v0v = D_801CC818u;
    D_801CC810 = 0;
    v0v += 0x30;
tail:
    D_801CC818 = v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801322E4);

void func_801325B4(s32 arg0) {
    D_80194FDC = arg0;
}

u8 func_801325C4(void) {
    return D_80194FDC;
}

void func_801325D4(void) {
}

extern void func_8013270C();
extern void func_8013286C();

void func_801325DC(void) {
    func_8013270C();
    func_8013286C();
}

extern s32 func_80021FA4();
extern s32 D_800596C4;
extern s32 D_800596C8;
extern s32 D_800596CC;
extern s32 D_800596C0;

s32 func_80132604(void) {
    s32 a0v;
    s32 var_s0;

    a0v = D_800596C0;
    var_s0 = -1;
    if (func_80021FA4(a0v) == 1) {
        var_s0 = 0;
    } else if (func_80021FA4(D_800596C4) == 1) {
        var_s0 = 1;
    } else if (func_80021FA4(D_800596C8) == 1) {
        var_s0 = 2;
    } else if (func_80021FA4(D_800596CC) == 1) {
        var_s0 = 3;
    }
    if (var_s0 != -1) {
        func_8013270C();
    }
    return var_s0;
}

extern s32 func_80028770(u8);
extern s32 func_80132604();

s32 func_801326C4(void) {
    s32 temp_s0;
    s32 var_v0;

loop_1:
    temp_s0 = func_80028770(D_80194FDC) & 1;
    var_v0 = func_80132604();
    if (var_v0 < 0) {
        var_v0 = 2;
        if (temp_s0 == 0) {
            goto loop_1;
        }
    }
    return var_v0;
}

void func_8013270C(void) {
    s32 a0v;

    a0v = D_800596C0;
    func_80021FA4(a0v);
    func_80021FA4(D_800596C4);
    func_80021FA4(D_800596C8);
    func_80021FA4(D_800596CC);
}

extern s32 D_800596D4;
extern s32 D_800596D8;
extern s32 D_800596DC;
extern s32 D_800596D0;

s32 func_80132764(void) {
    s32 a0v;
    s32 var_s0;

    a0v = D_800596D0;
    var_s0 = -1;
    if (func_80021FA4(a0v) == 1) {
        var_s0 = 0;
    } else if (func_80021FA4(D_800596D4) == 1) {
        var_s0 = 1;
    } else if (func_80021FA4(D_800596D8) == 1) {
        var_s0 = 2;
    } else if (func_80021FA4(D_800596DC) == 1) {
        var_s0 = 3;
    }
    if (var_s0 != -1) {
        func_8013286C();
    }
    return var_s0;
}

extern s32 func_80132764();

s32 func_80132824(void) {
    s32 temp_s0;
    s32 var_v0;

loop_1:
    temp_s0 = func_80028770(D_80194FDC) & 1;
    var_v0 = func_80132764();
    if (var_v0 < 0) {
        var_v0 = 2;
        if (temp_s0 == 0) {
            goto loop_1;
        }
    }
    return var_v0;
}

void func_8013286C(void) {
    s32 a0v;

    a0v = D_800596D0;
    func_80021FA4(a0v);
    func_80021FA4(D_800596D4);
    func_80021FA4(D_800596D8);
    func_80021FA4(D_800596DC);
}

extern s32 func_80028740();

s32 func_801328C4(s32 arg0, s32 arg1) {
    s32 s2v = arg0;
    register s32 s1v asm("s1") = arg1;
    register s32 s0v asm("s0") = 0;
    register s32 s3v asm("s3");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    volatile s32 pad[2];

    KEEP_NOVOL(s2v);
    KEEP_NOVOL(s1v);
    KEEP_NOVOL(s0v);
    if (s1v <= 0) {
        goto end;
    }
    s3v = 1;
loop:
    if (func_80028740(s2v) != s3v) {
        v1v = 2;
        goto failure;
    }
    v1v = func_801326C4();
    v0v = v1v;
    if (v1v == 0) {
        goto end;
    }
    s0v += 1;
    goto check;
failure:
    s0v += 1;
check:
    v0v = s0v < s1v;
    if (v0v != 0) {
        goto loop;
    }
end:
    v0v = v1v;
    return v0v;
}

extern s32 func_80028750();
extern s32 func_8001DBA8();

s32 func_80132950(s32 arg0, s32 arg1) {
    s32 s3v = arg0;
    register s32 s2v asm("s2") = arg1;
    register s32 s0v asm("s0") = 0;
    register s32 s4v asm("s4");
    register s32 s1v asm("s1");
    register s32 v0v asm("v0");
    volatile s32 pad[2];

    KEEP_NOVOL(s3v);
    KEEP_NOVOL(s2v);
    KEEP_NOVOL(s0v);
    if (s2v <= 0) {
        goto end;
    }
    s4v = 1;
loop:
    if (func_80028750(s3v) != s4v) {
        s1v = 2;
        goto failure;
    }
    s1v = func_801326C4();
    v0v = s1v;
    if (s1v == 0) {
        goto end;
    }
failure:
    func_8001DBA8(2);
    s0v += 1;
    v0v = s0v < s2v;
    if (v0v != 0) {
        goto loop;
    }
end:
    v0v = s1v;
    return v0v;
}

extern s32 func_80028780();
extern s32 func_80132B50();
extern s8 D_80194FDD;

s32 func_801329E4(s32 arg0, s32 arg1) {
    s32 s3v = arg0;
    s32 s2v = arg1;
    s32 s1v = 0;
    s32 s0v;
    s32 s4v;
    s32 v0v;
    volatile s32 pad[2];

    KEEP_NOVOL(s3v);
    KEEP_NOVOL(s2v);
    KEEP_NOVOL(s1v);
    if (s2v <= 0) {
        goto end;
    }
    s4v = 1;
loop:
    if (func_80028780(s3v) != s4v) {
        s0v = 2;
        goto failure;
    }
    s0v = func_80132824();
    v0v = s0v < 3;
    if (v0v != 0) {
        goto check;
    }
    s0v = 1;
check:
    v0v = s0v;
    if (s0v == 0) {
        goto end;
    }
    if (func_80132B50(1) != 0) {
        goto failure;
    }
    s0v = 0;
    goto end;
failure:
    s1v += 1;
    v0v = s1v < s2v;
    if (v0v != 0) {
        goto loop;
    }
end:
    v0v = s0v;
    return v0v;
}

extern s32 func_801328C4();

s32 func_80132A98(void) {
    s32 v0v;
    s32 temp_s0;
    s32 var_v0;
    s32 var_v1;
    v0v = *(u8 *) &D_80194FDD;

    if (v0v == 0) {
        func_80028740(D_80194FDC << 4);
        D_80194FDD = 1;
    }
    temp_s0 = func_80028770(D_80194FDC) & 1;
    var_v1 = func_80132604();
    if (temp_s0 != 0 && var_v1 == -1) {
        var_v1 = 2;
    }
    if (var_v1 >= 0) {
        D_80194FDD = 0;
        if (var_v1 > 0) {
            var_v1 = func_801328C4(D_80194FDC << 4, 2);
        }
    }
    var_v0 = var_v1;
    if (var_v1 == 1) {
        var_v0 = 2;
    }
    return var_v0;
}

s32 func_80132B50(s32 arg0) {
    s32 s1;
    s32 s0;
    s32 s2;
    s32 v0;
    register s32 v1 asm("v1");
    s32 pad[2];

    s1 = arg0;
    s0 = 0;
    if (s1 <= 0) {
        goto end;
    }
    s2 = -1;
loop:
    v0 = func_80132A98();
    v1 = v0;
    if (v1 == s2) {
        goto loop;
    }
    if (v1 == 0) {
        goto end;
    }
    s0++;
    v0 = s0 < s1;
    if (v0 != 0) {
        goto loop;
    }
end:
    v0 = v1;
    return v0;
}

extern s32 D_800E0200;
extern s16 D_800E0204;
extern s32 D_800E0208;
extern s16 D_800E020C;
extern s32 D_800E0210;
extern s32 D_800E0224;
extern void func_800222AC(u8 **, s32, s32);
extern s32 func_800220B4();
extern s32 func_800220C4(s32);

s32 func_80132BC0(s32 s0arg, s32 arg1) {
    struct Func80132BC0_Local {
        struct WorldFileRec r;
        u8 pad[0x78];
    } sp;
    s32 s0v;
    register s32 s1v asm("s1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a2v asm("a2") = arg1;
    s32 a1tmp;

    s0v = s0arg;
    KEEP_NOVOL(s0v);
    v0v = D_80194FDC;
    KEEP_NOVOL(v0v);
    if (v0v == 0) {
        sp.r.f00 = D_800E0200;
        v1v = D_800E0204;
        sp.r.f04 = v1v;
        MEMORY_BARRIER();
    } else {
        sp.r.f00 = D_800E0208;
        v1v = D_800E020C;
        sp.r.f04 = v1v;
    }
    if (a2v != 0) {
        a0v = (s32) &sp;
        goto nonzero;
    }
    MEMORY_BARRIER();
    a0v = (s32) &sp;
    a1tmp = (s32) &D_800E0210;
    goto call;
nonzero:
    a0v = (s32) &sp;
    a1tmp = (s32) &D_800E0224;
call:
    func_800222AC((u8 **) a0v, a1tmp, a2v);
    s1v = 0;
    KEEP_NOVOL(s1v);
    a0v = (s32) &sp;
    v0v = func_800220B4((u8 **) &sp, s0v);
    if (v0v != s0v) {
        v0v = s1v;
        goto end;
    }
    s1v += 1;
loop:
    s0v += 0x28;
    v0v = func_800220C4(s0v);
    s1v += 1;
    if (v0v == s0v) {
        goto loop;
    }
    s1v -= 1;
    KEEP_NOVOL(s1v);
    v0v = s1v;
end:
    return v0v;
}

s32 func_80132C90(s32 arg0, s32 arg1) {
    s32 i = 0;
    register s32 sum asm("a2") = 0;
    register s32 v0 asm("v0");
    register volatile u32 vu asm("v0");

    if (arg1 <= 0) {
        goto end;
    }
    do {
        v0 = *(s32 *) ((u8 *) arg0 + 0x18);
        KEEP_NOVOL(v0);
        i++;
        sum += v0 >> 13;
        sum += (v0 & 0x1FFF) != 0;
        arg0 += 0x28;
    } while (i < arg1);
end:
    if (sum < 0x10) {
        vu = 0xF;
        vu -= sum;
    } else {
        vu = 0;
    }
    return vu;
}

s32 func_80132CEC(void) {
    extern s32 func_80132B50(s32);
    extern s32 func_801329E4(s32, s32);
    extern s32 func_80132950(s32, s32);
    s32 v0v;
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");

    v1v = func_80132B50(0xA);
    v0v = 3;
    KEEP(v0v);
    if (v1v != v0v) {
        goto not3;
    }
    a0v = D_80194FDC << 4;
    a1v = 0xA;
    v0v = func_801329E4(a0v, a1v);
    if (v0v != 0) {
        v0v = 2;
        goto end;
    }
    goto call950;
not3:
    if (v1v != 0) {
        v0v = 3;
        goto process;
    }
    v0v = 3;
call950:
    a0v = D_80194FDC << 4;
    a1v = 0x1E;
    v1v = func_80132950(a0v, a1v);
    v0v = 3;
process:
    if (v1v == v0v) {
        goto end;
    }
    v0v = v1v;
    if (v1v == 0) {
        goto end;
    }
    v1v = 2;
    KEEP_NOVOL(v1v);
    v0v = v1v;
end:
    return v0v;
}

s32 func_80132D78(void) {
    struct Func80132D78_Local {
        struct WorldFileRec r;
    } sp;
    extern s32 func_80132B50(s32);
    extern s32 func_800220A4(s32 *);
    s32 v0v;
    s32 v1v;

    v0v = func_80132B50(0xA);
    if (v0v > 0) {
        return 0;
    }
    v0v = 0;
    {
        if (D_80194FDC == 0) {
            sp.r.f00 = D_800E0200;
            v1v = D_800E0204;
            sp.r.f04 = v1v;
            MEMORY_BARRIER();
        } else {
            sp.r.f00 = D_800E0208;
            v1v = D_800E020C;
            sp.r.f04 = v1v;
        }
        func_800220A4((s32 *) &sp);
        func_800220A4((s32 *) &sp);
        v0v = func_800220A4((s32 *) &sp);
    }
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80132E04);

extern s32 D_80194FD8;

s32 func_80132F08(s32 arg0) {
    extern s32 func_80132B50(s32);
    extern s32 func_80022094(s32);
    s32 s1;
    s32 s0;
    s32 s2;
    s32 v0;

    s1 = arg0;
    s0 = 0;

loop_1:
    s2 = func_80132B50(0xA) == 0;
    v0 = func_80022094(s1);
    if (v0 == s1) {
        v0 = -1;
        goto end;
    }
    s0++;
    s2 = 0;
    if (s0 < 0xA) {
        goto loop_1;
    }
    v0 = -1;
end:
    D_80194FD8 = v0;
    return s2;
}

extern s32 func_80022064();

s32 func_80132F7C(s32 arg0, s32 arg1, s32 arg2) {
    s32 s1v = arg0;
    register s32 s2v asm("s2") = arg1;
    register s32 s3v asm("s3") = arg2;
    register s32 s0v asm("s0") = 0;
    register s32 s4v asm("s4") = -1;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    KEEP_NOVOL(s1v);
    KEEP_NOVOL(s2v);
    KEEP_NOVOL(s3v);
    KEEP_NOVOL(s0v);
loop:
    v0v = func_80132B50(0xA);
    if (v0v != 0) {
        v0v = -1;
        goto end;
    }
    v0v = func_80022064(s1v, s2v, s3v);
    v1v = v0v;
    KEEP(v1v);
    if (v1v != s4v) {
        v0v = v1v;
        goto end;
    }
    s0v += 1;
    v0v = s0v < 0xA;
    if (v0v != 0) {
        goto loop;
    }
    v0v = v1v;
end:
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8013300C);

struct func_80133158_local {
    struct WorldFileRec r;
    u8 pad[0xF8];
};

extern u8 *func_800220D4(u8 **);

s32 func_80133158(s32 arg0) {
    s32 s0v;
    register s32 a2v asm("a2") = arg0;
    register u8 *v0v asm("v0");
    register s32 v1v asm("v1");
    struct func_80133158_local sp;

    v0v = D_80194FDC;
    if (v0v == 0) {
        sp.r.f00 = D_800E0200;
        v1v = D_800E0204;
        sp.r.f04 = (s16) v1v;
        MEMORY_BARRIER();
    } else {
        sp.r.f00 = D_800E0208;
        v1v = D_800E020C;
        sp.r.f04 = (s16) v1v;
    }
    func_800222AC((u8 **) &sp, a2v, a2v);
    s0v = 0;
    for (;;) {
        v0v = func_80132B50(0xA);
        if (v0v != 0) {
            return 0;
        }
        v0v = func_800220D4((u8 **) &sp);
        if (v0v != 0) {
            return (s32) v0v;
        }
        s0v += 1;
        if (s0v >= 0xA) {
            return 0;
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801331FC);

s32 func_80133308(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;
    s32 t;
    s32 i;

    r = func_80132F7C(arg0, 0, 1);
    if (r < 0)
        return -1;
    if (func_800220E4(arg0) != 0)
        return -1;
    i = 0;
    do {
        t = func_80022074(arg0, arg1, arg2);
        if (t == arg2)
            return t;
        if (func_80132F7C(arg0, r, 0) < 0)
            return -1;
        i += 1;
    } while (i < 10);
    return -1;
}

s32 func_801333C0(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;
    s32 t;
    s32 i;

    r = func_80132F7C(arg0, 0, 1);
    if (r < 0)
        return -1;
    if (func_800220E4(arg0) != 0)
        return -1;
    i = 0;
    do {
        t = func_80022084(arg0, arg1, arg2);
        if (t == arg2)
            return t;
        if (func_80132F7C(arg0, r, 0) < 0)
            return -1;
        i += 1;
    } while (i < 10);
    return -1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80133478);

void func_80133C18(void) {
}

extern void func_80114BC8();
extern void func_80133E1C();
extern s32 func_8012B950();
extern s16 D_8018BA20;
extern s8 D_8018BA24;
extern s16 D_8019515C;
extern u8 D_801952D4;
extern s16 D_801CD20C;
extern s16 D_801CD728;
extern s16 D_801CD784;

void func_80133C20(void) {
    extern void func_80118B3C();
    extern s32 func_8012AB78(s32, void *);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s8 D_801950D7;
    s8 temp_v0;

    if (D_801952D4 == 0) {
        D_8018BA24 = 0;
        D_801CD20C = 0;
    }
    temp_v0 = func_8012AB78(6, &D_8019515C);
    D_801952D4 = temp_v0;
    if (!(temp_v0 & 0xFF)) {
        func_80118B3C();
        if (D_801CD728 == 0) {
            D_801CD784 = 1;
            D_801950D7 = func_8012B950(0, 0);
        } else if (D_801CD728 == 1) {
            D_801CD784 = 4;
        } else {
            if (D_801CD728 == 2) {
                D_801CD784 = 6;
                D_8018BA20 = 0;
                func_80114BC8();
                func_800FFF08(2, 0x19, 0xF818, 0);
            } else {
                D_801CD784 = 0xD;
                func_800FFF08(2, 0x19, 0xF803, 0);
            }
        }
    }
    func_80133E1C();
}

extern u8 D_801952D5;
extern s8 D_801952D6;
extern u16 D_801CD838_u asm("D_801CD838");
extern s32 func_8012D5BC();
extern void func_80138EA4();
extern void func_80138EFC();

void func_80133D30(void) {
    extern void func_80043BE8(s32, s32);
    s32 v0v;
    register s32 v1v asm("v1");
    v0v = *(u8 *) &D_801952D6;

    if (v0v != 0) {
        goto check_flag;
    }
    v0v = 1;
    D_801952D5 = 0;
    D_801952D6 = v0v;
check_flag:
    v0v = D_801952D5;
    if (v0v == 0) {
        goto check_mask;
    }
    v0v = func_8012D5BC();
    if (v0v != 0) {
        goto after;
    }
    D_801CD784 = -1;
    D_801952D6 = 0;
    goto after;
check_mask:
    v0v = D_801CD838_u;
    v0v &= 0xF0;
    if (v0v == 0) {
        goto after;
    }
    func_8012D48C();
    func_80043BE8(0, 0xF0);
    func_800FFF08(2, 0x19, -1, 0);
    v0v = 1;
    D_801952D5 = v0v;
after:
    func_80133E1C();
    v1v = D_801CD218;
    v0v = 0x65;
    if (v1v != v0v) {
        goto end;
    }
    func_80138EA4();
    func_80138EFC();
end:
    return;
}

extern s32 D_801952D8;
extern s32 func_801207BC(s32);
extern void func_80126570();

void func_80133E1C(void) {
    s32 *p = (s32 *) &D_801CD794;
    s32 v0 = (s32) &func_801207BC;
    s32 s1;

    s1 = *p;
    *p = v0;
    func_80126570(&D_801952D8, 0, 0);
    *p = s1;
}

extern s32 func_801237E4(s32);
extern s16 D_801CD824;

s32 func_80133E74(void) {
    s32 v0v;
    s32 ret;
    v0v = D_801CD824;

    if (v0v != 0) {
        ret = func_801237E4(D_801CD230[D_801CD20C] & 0x3FF);
    } else {
        ret = 0;
    }
    return ret;
}

extern s32 func_80123764(s32);

s32 func_80133EC8(void) {
    s32 v0v;
    s32 ret;
    v0v = D_801CD824;

    if (v0v != 0) {
        ret = func_80123764(D_801CD230[D_801CD20C] & 0x3FF);
    } else {
        ret = 0;
    }
    return ret;
}

extern u16 func_80123708(s32);

s32 func_80133F1C(s32 arg0) {
    u8 *base = (u8 *) D_801CD230;
    s16 *p = (s16 *) (base + (arg0 << 1));
    s32 v = ((s32 (*)(s32)) func_80123708)(*p);
    s32 a = v;

    if (*(u16 *) p & 0x4000) {
        a = v | 0x40000000;
    }
    return a;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80133F78);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8013414C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80134154);

extern u8 D_8018DFB4;
extern s16 D_801952FC[];
extern s16 D_801953E2;
extern s16 D_801CD72E;
extern s16 D_801CD730;
extern s32 func_801208B8(s32, s32);

void func_801344B0(void) {
    extern u8 D_801950D7;
    extern s32 D_8015330C;
    extern s32 func_80134650(void);
    extern s32 func_80123708s(s32) asm("func_80123708");
    extern s32 func_801221D8(s32);
    extern void func_80133F78(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_80115D6C();
    s32 s0v;
    s32 temp_v0;

    s0v = 1;
    if (D_801953E2 != 0) {
        if ((D_801CD52C & 0xF0F0) != 0) {
            D_801953E2 = 0;
            func_800FFF08(2, 0x19, 0xF805, 0);
            D_8018DFB4 = 0;
            D_801CD784 = 1;
        }
    } else {
        s0v = func_80134650();
    }
    if (s0v == 0) {
        if (D_801CD730 == 0) {
            temp_v0 = func_80123708s(D_801CD230[D_801CD20C]);
            func_801207BC(-temp_v0 * D_801CD72E);
            func_801208B8(D_801CD230[D_801CD20C], D_801CD72E);
            func_800FFF08(2, 0x19, 0xF811, 0);
            func_801221D8(D_801950D7);
        } else {
            func_800FFF08(2, 0x19, 0xF80A, 0);
        }
    }
    if (s0v <= 0) {
        D_801953E2 = 1;
    }
    func_80133F78(0);
    func_80126570(D_801952FC, 0, D_8015330C);
    func_80115D6C(3, 0xBA, 0x4C, 0, 1, 1);
    func_80133E1C();
}

extern s16 D_801950DA;
extern u8 D_801953E4;
extern s32 D_801CD060;
extern s16 D_801CD064;
extern u8 D_801CD068;
extern u16 D_801CD230u[] asm("D_801CD230");
extern s32 D_801532A0;

s32 func_80134650(void) {
    extern u8 D_8018BACC;
    extern s16 D_801950E4[];
    extern s32 func_80123708s(s32) asm("func_80123708");
    s32 s0v;
    s32 s1v;
    s32 temp_v0;
    s32 temp_w0;
    u16 temp_v1;

    if (D_801953E4 == 0) {
        temp_v1 = D_801CD230u[D_801CD20C];
        D_801CD068 = 0;
        D_8018DFB4 = 1;
        D_801CD064 = temp_v1;
        s1v = func_801237E4((s16) temp_v1);
        if (s1v >= 0x63) {
            func_800FFF08(2, 0x19, 0xF807, 0);
            return -2;
        }
        temp_v0 = func_801207BC(0);
        temp_w0 = func_80123708s(D_801CD064);
        s0v = temp_v0 / temp_w0;
        D_801CD060 = temp_w0;
        if ((0x63 - s1v) < s0v) {
            s0v = 0x63 - s1v;
        }
        if (s0v == 0) {
            func_800FFF08(2, 0x19, 0xF806, 0);
            return -1;
        }
        func_800FFF08(2, 0x19, 0xF808, 0);
        D_801950DA = s0v;
        D_801CD068 = 0;
        D_801532A0 = 1;
    }
    D_801953E4 = func_8012AB78(0xF, &D_801950E4[0]);
    if ((func_800FFEEC(0xE) != 0) && (D_801CD068 == 0)) {
        D_801531D8 = D_801CD72E * D_801CD060;
        func_800FFF08(2, 0x19, 0xF809, 0);
        D_801CD068 = 1;
        D_8018BACC = 1;
    }
    if ((func_800FFEEC(0xE) == 0) && (D_801CD068 != 0)) {
        D_801CD068 = 0;
        func_800FFF08(2, 0x19, 0xF808, 0);
    }
    if (D_801953E4 == 0) {
        if (D_801CD730 == 0) {
            D_8018BACC = 0x97;
        }
        if (D_801CD730 == 1) {
            D_8018BACC = 1;
        }
        D_801532A0 = 0;
    }
    return D_801953E4;
}

extern s16 D_801CD074;

s32 func_80134890(s32 arg0) {
    s32 a0v;
    register s32 a1v asm("a1") = 0;
    register s32 a2v asm("a2") = D_801CD074;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    KEEP_NOVOL(a1v);
    KEEP_NOVOL(a2v);
    v0v = arg0 << 2;
    v1v = *(s32 *) ((u8 *) D_801CD5EC + v0v);
loop:
    a1v += 1;
    v0v = *(u16 *) (v1v + 0x54);
    if (v0v == a2v) {
        return 8;
    }
    v1v += 2;
    v0v = a1v < 5;
    if (v0v != 0) {
        goto loop;
    }
    a0v = arg0;
    a0v <<= 16;
    KEEP(a0v);
    a1v = D_801CD074;
    v0v = ((s32 (*)(s32, s32, s32)) func_8012457C)((s16) (a0v >> 16), a1v, a2v);
    a0v = v0v;
    v1v = 1;
    if (a0v != 1) {
        return 8;
    }
    return -1;
}

s32 func_80134914(s16 arg0) {
    s32 a0;
    s32 v0;
    s32 v1;

    a0 = arg0;
    a0 <<= 16;
    v0 = D_801CD074;
    v0 = func_8012457C(a0 >> 16, v0);
    v1 = 1;
    if (v0 == v1) {
        a0 = 0x80;
    } else {
        a0 = 0x40;
    }
    return a0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80134954);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8013495C);

s32 func_80134D1C(void) {
    s32 v0;
    v0 = D_801CD824;

    if (v0 != 0) {
        v0 = D_801CD20C;
        return func_8012372C(D_801CD230[v0]);
    }
    KEEP(v0);
    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80134D6C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80134D74);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80134F7C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80134F84);

extern s32 func_8012AB78();
extern s32 func_8012372C();
extern u8 D_80195512;
extern s16 D_801CD078;
extern u8 D_801CD07C;
extern u16 D_801CD230b[] asm("D_801CD230");

s32 func_8013517C(void) {
    extern s32 func_800FFEEC(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern u8 D_8018BACC;
    extern s16 D_801950E4;
    s32 temp_v0;
    u16 temp_v1;

    if (D_80195512 == 0) {
        D_801CD07C = 0;
        temp_v1 = D_801CD230b[D_801CD20C];
        D_8018DFB4 = 1;
        D_801CD078 = temp_v1;
        temp_v0 = func_801208B8((s16) temp_v1, 0);
        if (temp_v0 == 0) {
            func_800FFF08(2, 0x19, 0xF80E, 0);
            return -1;
        }
        func_800FFF08(2, 0x19, 0xF80F, 0);
        D_801950DA = temp_v0;
        D_801CD07C = 0;
        D_801532A0 = 1;
    }
    D_80195512 = func_8012AB78(0xF, &D_801950E4);
    if ((func_800FFEEC(0xE) != 0) && (D_801CD07C == 0)) {
        D_801531D8 = func_8012372C(D_801CD078) * D_801CD72E;
        func_800FFF08(2, 0x19, 0xF810, 0);
        D_801CD07C = 1;
        D_8018BACC = 1;
    }
    if ((func_800FFEEC(0xE) == 0) && (D_801CD07C != 0)) {
        D_801CD07C = 0;
        func_800FFF08(2, 0x19, 0xF80F, 0);
    }
    if (D_80195512 == 0) {
        if (D_801CD730 == 0) {
            D_8018BACC = 0x97;
        }
        if (D_801CD730 == 1) {
            D_8018BACC = 1;
        }
        D_801532A0 = 0;
    }
    return D_80195512;
}

extern s32 D_801CD080;

s32 func_80135360(s32 arg0) {
    s32 t;

    t = D_801CD080;
    return D_801CD080 = arg0 + t;
}

s32 func_80135380(void) {
    return -1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80135388);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80135390);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801356B0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801356B8);

extern s32 func_80135360(s32);

s32 func_80135CB8(void) {
    s32 temp_s0;

    temp_s0 = func_801207BC(0);
    return temp_s0 - func_80135360(0);
}

extern s32 func_800FFEEC();

s32 func_80135CF0(s32 arg0) {
    extern s32 D_8015330C;
    s32 v0;
    s32 s0 = 0;

    v0 = D_8015330C;
    if (v0 != 0) {
        s0 = 1;
    } else if (func_800FFEEC(6) != 0) {
        s0 = 1;
    }
    return s0;
}

extern s32 D_801CD798;
extern s32 D_801CD79C;
extern s32 D_8019567C;
extern s32 func_80135CB8();
extern s32 func_80135CF0();

void func_80135D38(void) {
    register s32 v0 asm("v0");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");

    v0 = (s32) &func_801207BC;
    D_801CD794 = v0;
    v0 = (s32) &func_80135360;
    D_801CD798 = v0;
    v0 = (s32) &func_80135CB8;
    D_801CD79C = v0;
    a0 = 0;
    func_80135CF0(a0);
    a1 = D_801CD52C;
    a0 = (s32) &D_8019567C;
    a2 = v0;
    func_80126570(a0, a1, a2);
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80135DA0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80135DB0);

extern void func_80115198();
extern s32 func_801361A8();
extern s8 D_8018BA25;
extern s8 D_801950D6;
extern s8 D_80195514;
extern u8 D_801CD09C;

void func_801360B4(void) {
    extern void func_800FFF08(s32, s32, s32, s32);
    s32 s0v;
    s32 v1v;

    s0v = 1;
    D_801950D6 = s0v;
    if (D_801CD09C != 0) {
        if (D_801CD52C & 0xF0) {
            D_801CD784 = 6;
            func_800FFF08(2, 0x19, -1, 0);
            D_801CD09C = 0;
            D_8018BA25 = s0v;
            func_80115198();
        }
    } else {
        v1v = func_801361A8();
        if (v1v == -1) {
            D_801CD784 = 0;
            func_800FFF08(2, 0x19, 0xF802, 0);
            D_80195514 = 0;
        } else if (v1v == 0) {
            D_801CD09C = s0v;
            func_800FFF08(2, 0x19, 0xF818, 0);
        }
    }
    func_80133E1C();
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801361A8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801361B0);

extern s16 D_801CD43C;
extern u8 D_801CD788_u asm("D_801CD788");

void func_8013649C(void) {
    volatile s32 pad[2];
    u8 *a2v;
    s32 *a3v;
    s32 t0v = 0;
    s32 t1v;
    register s32 v0v asm("v0");
    register s16 *v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");

    v0v = D_801CD788_u;
    if (v0v <= 0) {
        goto end;
    }
    a2v = (u8 *) &D_801CD43C;
    a3v = D_801CD5EC;
outer:
    do {
        v1v = (s16 *) a2v;
        a1v = 0;
        t1v = (s32) a2v + 0xA;
inner:
        v0v = *a3v;
        a0v = a1v + v0v;
        v0v = *(u16 *) (a0v + 0x54);
        v0v >>= 14;
        if (v0v != 0) {
            goto store;
        }
        v0v = *(s16 *) v1v;
        if (v0v == 0) {
            goto clear;
        }
store:
        v0v = *(u16 *) v1v;
        *(u16 *) (a0v + 0x54) = (u16) v0v;
clear:
        *v1v = 0;
        v1v += 1;
        v0v = (s32) v1v < t1v;
        if (v0v != 0) {
            a1v += 2;
            goto inner;
        }
        a2v += 0xA;
        v0v = D_801CD788_u;
        t0v += 1;
        v0v = t0v < v0v;
        a3v += 1;
    } while (v0v != 0);
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80136548);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80136550);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801368DC);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801368E4);

extern u8 D_801957F0;
extern u16 D_801CD0BCu asm("D_801CD0BC");
extern s16 D_801CD0BCs asm("D_801CD0BC");
extern s8 D_8018BA27;
extern void func_800FFD70();
extern void func_801158C4();
extern void func_80118B68();
extern void func_80134D6C();
extern void func_80134F7C();
extern void func_80114088();

void func_80136C70(void) {
    extern void func_8010F250();
    extern void func_80126374();
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    volatile s32 pad[1];

    v0v = D_801957F0;
    if (v0v != 0) {
        goto blk3;
    }
    if (func_800FFEEC(2) != 0) {
        return;
    }
    func_800FFD70(2, &func_8010F250);
    D_8018BA27 = 0;
    D_8018BA25 = 0;
    func_801158C4();
    D_8018BA24 = 0;
    D_801CD0BCu = 4;
    func_80118B68(5);
    func_80118B68(6);
    func_80118B68(7);
    func_80118B68(8);
    func_80118B68(9);
    D_801957F0 = 1;
blk3:
    v0v = D_801CD0BCu;
    D_801CD784 = v0v;
    MEMORY_BARRIER();
    v1v = (s16) v0v;
    if (v1v == 4) {
        func_80134D6C();
        if (D_801CD0BCs != D_801CD784) {
            func_80114088();
        }
    } else if (v1v == 5) {
        func_80134F7C();
    }
    v0v = D_801CD784;
    v1v = v0v;
    if (v0v == 0) {
        D_801CD784 = 6;
        D_8018BA24 = 2;
        D_801957F0 = 0;
        D_8018BA27 = 1;
        func_80126374(2);
        func_800FFF08(2, 0x19, -1, 0);
        return;
    }
    D_801CD0BCu = (u16) v1v;
    D_801CD784 = 0xB;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80136DF4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80136EB0);

void func_8013702C(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 s3v asm("s3");
    register s32 s4v asm("s4");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    volatile s32 pad[2];

    v0v = D_801CD788_u;
    s3v = 0;
    if (v0v > 0) {
        s4v = (s32) &D_801CD43C;
        s2v = (s32) D_801CD5EC;
        do {
            s1v = 0;
            s0v = s4v;
            do {
                v1v = *(s32 *) s2v;
                v0v = s1v << 1;
                v1v = v0v + v1v;
                v0v = *(volatile u16 *) (v1v + 0x54);
                __asm__ volatile("sra %0, %1, 14" : "=r"(v0v) : "0"(v0v));
                if (v0v != 0) {
                    v0v = *(volatile u16 *) (v1v + 0x54);
                    v0v &= 0x3FF;
                    *(u16 *) (v1v + 0x54) = v0v;
                }
                a0v = *(s16 *) s0v;
                a1v = 1;
                func_801208B8(a0v, a1v);
                *(s16 *) s0v = 0;
                s0v += 2;
                s1v += 1;
            } while (s1v < 5);
            s4v += 0xA;
            v0v = (u8) D_801CD788;
            s3v += 1;
            s2v += 4;
        } while (s3v < v0v);
    }
}

extern u8 D_80195198[];
extern u8 D_801957F4;
extern u8 D_801CD0C0b asm("D_801CD0C0");
extern u8 D_801CD0C4;
extern u8 D_801CD0C8;
extern u8 D_801CD0E4;

void func_801370FC(void) {
    extern u8 D_801950D7;
    extern s32 func_80126374(s32);
    extern s32 func_801228CC(s32);
    extern s32 func_80123824(s32, s32);
    extern s32 func_80123628(s32);
    extern s32 func_80118B3C();
    extern s32 func_8012AB78(s32, void *);
    extern void func_800FFF08(s32, s32, s32, s32);
    volatile s32 pad[2];
    s32 s0v;
    s32 s1v;
    s32 a2v;
    s32 temp_v0;

    if (D_801957F4 == 0) {
        D_801CD20C = 0;
        func_80126374(0);
        temp_v0 = D_801CD788_u;
        D_801CD0C4 = 0;
        D_801CD0C8 = 0;
        D_801CD0E4 = 0;
        D_801CD0C0b = 0;
        s0v = 0;
        if (temp_v0 > 0) {
            s1v = 1;
            do {
                if (func_801228CC(s0v) != 0) {
                    D_801CD0C4 = s1v;
                }
                s0v++;
            } while (s0v < D_801CD788_u);
        }
        s0v = 1;
        if (D_801CD0C4 != 0) {
            s1v = 1;
            do {
                if (func_80123824((s16) s0v, 0) != 0) {
                    D_801CD0C8 = s1v;
                }
                s0v++;
            } while (s0v < 0x100);
        }
        if (D_801CD0C4 == 0) {
            D_801CD784 = 0xD;
            func_800FFF08(2, 0x19, 0xF82D, 0);
            return;
        } else {
            D_801CD0E4 = 1;
            D_801957F4 = 1;
        }
    }
    if (D_801CD0C0b != 0) {
        if ((D_801CD52C & 0xF0) != 0) {
            func_800FFF08(2, 0x19, 0xF830, 0);
            D_801CD0C0b = 0;
        }
    } else {
        if (func_8012AB78(6, &D_80195198[0]) == 0) {
            func_80118B3C();
            if (D_801CD728 == 0) {
                if (D_801CD0C8 != 0) {
                    D_801950D7 = func_8012B950(0, 0);
                    D_801CD784 = 0xF;
                    D_801957F4 = 0;
                } else {
                    func_800FFF08(2, 0x19, 0xF82E, 0);
                    D_801CD0C0b = 1;
                }
            } else if (D_801CD728 == 1) {
                if (func_80123628(0) != 0) {
                    D_801CD784 = 0x12;
                    D_801957F4 = 0;
                } else {
                    func_800FFF08(2, 0x19, 0xF845, 0);
                    D_801CD0C0b = 1;
                }
            } else {
                D_801CD784 = 0xD;
                func_800FFF08(2, 0x19, 0xF831, 0);
                D_801957F4 = 0;
            }
        }
    }
    func_80133E1C();
}

s32 func_80137378(void) {
    s32 v0;
    v0 = D_801CD824;

    if (v0 != 0) {
        v0 = D_801CD20C;
        return func_80123824(D_801CD230[v0], 0);
    }
    KEEP(v0);
    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801373C8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_801373D0);

extern s32 func_80123824();
extern u8 D_801950D7v asm("D_801950D7");
extern u8 D_801957F8[];
extern s16 D_801958E4;
extern s32 D_801CD8C0;
extern s32 func_80124C54();
extern s32 func_80128C7C();

void func_801375C0(void) {
    extern u8 D_801950D7;
    extern s32 func_801377E8(void);
    extern s32 func_801221D8(s32);
    extern s32 func_80129B14(s32);
    extern s32 func_80133F78(s32);
    extern s32 func_800FFEEC(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    s16 *s0v;
    s32 s1v;
    s32 a1v;
    s32 a2v;
    s32 temp_v0;
    u8 temp_t0;

    s1v = 1;
    if (D_801958E4 != 0) {
        if ((D_801CD52C & 0xF0F0) != 0) {
            D_801958E4 = 0;
            func_800FFF08(2, 0x19, 0xF841, 0);
            D_801CD784 = 0x12;
            D_8018DFB4 = 0;
        }
    } else {
        s1v = func_801377E8();
    }
    if (s1v == 0) {
        if (D_801CD730 == 0) {
            temp_v0 = func_8012372C(D_801CD230[D_801CD20C]);
            func_801207BC(temp_v0 * D_801CD72E);
            func_801208B8(D_801CD230[D_801CD20C], -D_801CD72E);
            func_80123824(D_801CD230[D_801CD20C], D_801CD72E);
            func_800FFF08(2, 0x19, 0xF837, 0);
            func_801221D8(D_801950D7);
            temp_t0 = D_801950D7;
            a1v = temp_t0 + 1;
            if (D_801950D7v != 4) {
                a2v = (s8) (temp_t0 + 1);
            } else {
                a2v = 7;
            }
            s0v = D_801CD230;
            func_80124C54(0, a1v, a2v, s0v, 0);
            func_80128C7C(s0v, D_801CD20C, D_801CD8C0, D_801957F8);
            func_80129B14(0xA);
        } else {
            func_800FFF08(2, 0x19, 0xF838, 0);
        }
    }
    if (s1v <= 0) {
        D_801958E4 = 1;
    }
    func_80133F78(0);
    temp_v0 = func_800FFEEC(1);
    func_80126570(D_801957F8, 0, temp_v0);
    func_80133E1C();
}

extern u8 D_801958E6;
extern s16 D_801CD0CC;
extern u8 D_801CD0D0;

s32 func_801377E8(void) {
    extern s32 func_800FFEEC(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    extern u8 D_8018BACC;
    extern s16 D_801950E4;
    s32 temp_v0;
    u16 temp_v1;

    if (D_801958E6 == 0) {
        D_801CD0D0 = 0;
        temp_v1 = D_801CD230b[D_801CD20C];
        D_8018DFB4 = 1;
        D_801CD0CC = temp_v1;
        temp_v0 = func_801208B8((s16) temp_v1, 0);
        if (temp_v0 == 0) {
            func_800FFF08(2, 0x19, 0xF842, 0);
            return -1;
        }
        func_800FFF08(2, 0x19, 0xF843, 0);
        D_801950DA = temp_v0;
        D_801CD0D0 = 0;
        D_801532A0 = 1;
    }
    D_801958E6 = func_8012AB78(0xF, &D_801950E4);
    if ((func_800FFEEC(0xE) != 0) && (D_801CD0D0 == 0)) {
        D_801531D8 = func_8012372C(D_801CD0CC) * D_801CD72E;
        func_800FFF08(2, 0x19, 0xF844, 0);
        D_801CD0D0 = 1;
        D_8018BACC = 1;
    }
    if ((func_800FFEEC(0xE) == 0) && (D_801CD0D0 != 0)) {
        D_801CD0D0 = 0;
        func_800FFF08(2, 0x19, 0xF843, 0);
    }
    if (D_801958E6 == 0) {
        if (D_801CD730 == 0) {
            D_8018BACC = 0x97;
        }
        if (D_801CD730 == 1) {
            D_8018BACC = 1;
        }
        D_801532A0 = 0;
    }
    return D_801958E6;
}

s32 func_801379CC(s32 arg0) {
    u8 *base = (u8 *) D_801CD230;
    s16 *p = (s16 *) (base + (arg0 << 1));
    s32 v = ((s32 (*)(s32)) func_80123708)(*p);
    s32 a = v >> 1;

    if (*(u16 *) p & 0x4000) {
        a |= 0x40000000;
    }
    return a;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80137A28);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80137A30);

extern u8 D_801958E8[];
extern s16 D_801959E0;
extern s32 func_8012502C();

void func_80137D94(void) {
    extern u8 D_801950D7;
    extern s32 func_80137FD0(void);
    extern s32 func_80123708s(s32) asm("func_80123708");
    extern s32 func_80115D6C();
    extern s32 func_801221D8(s32);
    extern s32 func_80129B14(s32);
    extern s32 func_80133F78(s32);
    extern s32 func_800FFEEC(s32);
    extern void func_800FFF08(s32, s32, s32, s32);
    s16 *s0v;
    s32 s1v;
    s32 a1v;
    s32 a2v;
    s32 temp_v0;
    u8 temp_t0;

    s1v = 1;
    if (D_801959E0 != 0) {
        if ((D_801CD52C & 0xF0F0) != 0) {
            D_801959E0 = 0;
            func_800FFF08(2, 0x19, 0xF83B, 0);
            D_801CD784 = 0xF;
            D_8018DFB4 = 0;
        }
    } else {
        s1v = func_80137FD0();
    }
    if (s1v == 0) {
        if (D_801CD730 == 0) {
            func_801207BC(-(func_80123708s(D_801CD230[D_801CD20C]) >> 1) * D_801CD72E);
            func_801208B8(D_801CD230[D_801CD20C], D_801CD72E);
            func_80123824(D_801CD230[D_801CD20C], -D_801CD72E);
            func_801221D8(D_801950D7);
            temp_t0 = D_801950D7;
            a1v = D_801CD218;
            if (temp_t0 != 4) {
                a2v = D_801950D7v + 1;
            } else {
                a2v = 7;
            }
            s0v = D_801CD230;
            func_8012502C(-1, a1v, a2v, s0v, 0);
            func_80128C7C(s0v, D_801CD20C, D_801CD8C0, D_801958E8);
            func_80129B14(0xA);
            func_800FFF08(2, 0x19, 0xF837, 0);
        } else {
            func_800FFF08(2, 0x19, 0xF838, 0);
        }
    }
    if (s1v <= 0) {
        D_801959E0 = 1;
    }
    func_80133F78(0);
    temp_v0 = func_800FFEEC(1);
    func_80126570(D_801958E8, 0, temp_v0);
    func_80115D6C(3, 0xBA, 0x4C, 0, 1, 1);
    func_80133E1C();
}

extern u8 D_801959E2;
extern s32 D_801CD0D8;
extern s16 D_801CD0DC;
extern u8 D_801CD0E0;

s32 func_80137FD0(void) {
    extern u8 D_8018BACC;
    extern s16 D_801950E4[];
    extern s32 func_80123708s(s32) asm("func_80123708");
    s32 s0v;
    s32 s1v;
    s32 temp_v0;
    s32 temp_w0;
    u16 temp_v1;

    if (D_801959E2 == 0) {
        temp_v1 = D_801CD230u[D_801CD20C];
        D_801CD0E0 = 0;
        D_8018DFB4 = 1;
        D_801CD0DC = temp_v1;
        s1v = func_801237E4((s16) temp_v1);
        if (s1v >= 0x63) {
            func_800FFF08(2, 0x19, 0xF834, 0);
            return -2;
        }
        s0v = func_801207BC(0);
        temp_w0 = func_80123708s(D_801CD0DC) >> 1;
        s0v = s0v / temp_w0;
        D_801CD0D8 = temp_w0;
        if ((0x63 - s1v) < s0v) {
            s0v = 0x63 - s1v;
        }
        if (s0v == 0) {
            func_800FFF08(2, 0x19, 0xF833, 0);
            return -1;
        }
        func_800FFF08(2, 0x19, 0xF835, 0);
        temp_v0 = func_80123824(D_801CD0DC, 0);
        if (s0v >= temp_v0) {
            s0v = temp_v0;
        }
        D_801950DA = s0v;
        D_801532A0 = 1;
    }
    D_801959E2 = func_8012AB78(0xF, &D_801950E4[0]);
    if ((func_800FFEEC(0xE) != 0) && (D_801CD0E0 == 0)) {
        D_801531D8 = D_801CD72E * D_801CD0D8;
        func_800FFF08(2, 0x19, 0xF836, 0);
        D_801CD0E0 = 1;
        D_8018BACC = 1;
    }
    if ((func_800FFEEC(0xE) == 0) && (D_801CD0E0 != 0)) {
        D_801CD0E0 = 0;
        func_800FFF08(2, 0x19, 0xF835, 0);
    }
    if (D_801959E2 == 0) {
        if (D_801CD730 == 0) {
            D_8018BACC = 0x97;
        }
        if (D_801CD730 == 1) {
            D_8018BACC = 1;
        }
        D_801532A0 = 0;
    }
    return D_801959E2;
}

extern void func_80134954();

void func_8013822C(void) {
    func_80134954();
    if (D_801CD784 == 1) {
        D_801CD784 = 0xF;
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80138268);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80138270);

extern s32 D_801CD754;
extern s8 D_801CD80C;
extern s32 D_8018BA30;
extern u8 D_80195A60;

void func_801385A4(void) {
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 func_800FFEEC(s32);
    extern void func_80115650(s32);
    extern void func_8012A598(s32);
    extern s8 D_8018BACC;
    extern s32 func_8010F250();

    if (D_80195A60 == 0) {
        if (D_801CD52C & 0xF0) {
            func_800FFF08(2, 0x19, -1, 0);
        }
        if (func_800FFEEC(2) == 0) {
            D_8018BA27 = 1;
            D_8018BA25 = 1;
            D_801CD80C = 0;
            D_8018BA30 = 0;
            D_801CD754 = 0x20003;
            D_80195A60 = 1;
        }
        func_80133E1C();
        func_80138EA4();
        func_80138EFC();
        return;
    }
    if (D_801CD52C & 0xF0) {
        D_801CD784 = 0x16;
        D_8018BA27 = 0;
        D_8018BA25 = 0;
        func_80115650(0);
        func_8012A598(9);
        func_800FFD70(2, &func_8010F250);
        func_800FFF08(2, 0x19, 0xF826, 0);
        D_8018BACC = 1;
        D_80195A60 = 0;
    }
}

struct unk_801CD5EC_2C {
    s32 pad[11];
    s16 f2c;
};

extern s16 D_801CD72C;
extern s16 D_801959E8;
extern u8 D_80195A61;

void func_801386D0(void) {
    extern void func_800FFF08(s32, s32, s32, s32);
    extern s32 func_800FFEEC(s32);
    extern void func_80059FE0(s16);
    extern s32 func_8012AB78(s32, void *);
    extern u8 D_801959E4;

    if (D_80195A61 != 0) {
        if (D_801CD52C & 0xF0) {
            func_800FFF08(2, 0x19, -1, 0);
        }
        if (func_800FFEEC(2) == 0) {
            D_80195A61 = 0;
            D_801CD784 = 0x17;
        }
    } else if (func_8012AB78(0xF, &D_801959E8) == 0) {
        if ((D_801CD72C == 1) || (D_801CD72C == -1)) {
            func_800FFF08(2, 0x19, 0xF827, 0);
            D_801959E4 = 0;
            func_80059FE0(((struct unk_801CD5EC_2C *)
                               D_801CD5EC[D_8018BA20])
                              ->f2c);
            D_801CD784 = 0x14;
        } else if (D_801CD72C == 2) {
            func_800FFF08(2, 0x19, -1, 0);
            D_801CD784 = 0x15;
        } else {
            func_800FFF08(2, 0x19, 0xF829, 0);
            D_80195A61 = 1;
        }
    }
    func_80133E1C();
    func_80138EA4();
    func_80138EFC();
}

extern s32 D_801CD100;
extern s32 D_801CD104;
extern u8 D_80195A62;
extern void func_80115460();

void func_80138834(void) {
    extern s32 func_8010F250();
    extern s32 func_80138F5C(s32, s32);
    s32 temp_v0;

    if (D_80195A62 == 0) {
        D_8018BA25 = 0;
        func_80115460(0);
        D_80195A62 = 1;
    }
    temp_v0 = func_80138F5C(D_801CD5EC[D_8018BA20] + 0x10E, 0);
    D_801CD100 = temp_v0;
    if (temp_v0 != 0) {
        D_80195A62 = 0;
        D_801531D8 = D_801CD104;
        func_800FFD70(2, &func_8010F250);
        func_800FFF08(2, 0x19, 0xF82A, 0);
        D_801CD784 = 0x18;
    }
}

extern s16 D_80195A24;
extern s16 D_80195A5C;
extern u8 D_80195A63;

void func_801388F4(void) {
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_80059FE0(s16);
    extern s32 func_8012AB78(s32, void *);
    extern void func_80120A64(s32, u8 *);
    extern u8 D_801959E4;

    D_801CD754 = 0;
    if (D_80195A63 != 0) {
        if (D_801CD52C & 0xF0) {
            D_801CD784 = 0x19;
            D_80195A63 = 0;
        }
    } else if (func_8012AB78(0xF, &D_80195A24) == 0) {
        if (D_801CD730 == 0) {
            func_800FFF08(2, 0x19, 0xF82B, 0);
            func_801207BC(-D_801CD104);
            func_80120A64(D_8018BA20, (u8 *) D_801CD100);
            D_80195A63 = 1;
        } else if ((D_801CD730 == 1) || (D_801CD730 == -1)) {
            func_800FFF08(2, 0x19, 0xF827, 0);
            D_801CD784 = 0x14;
            func_80059FE0(((struct unk_801CD5EC_2C *)
                               D_801CD5EC[D_8018BA20])
                              ->f2c);
            D_801959E4 = 0;
        } else {
            func_800FFF08(2, 0x19, -1, 0);
            D_80195A5C = 0;
            D_801CD784 = 0x17;
        }
    }
    func_80133E1C();
    func_80138EA4();
    func_80138EFC();
}

extern s8 D_801959E4;

void func_80138A74(void) {
    func_800FFF08(2, 0x19, 0xF821, 0);
    D_801CD784 = 0x14;
    D_801959E4 = 0;
    func_80133E1C();
    func_80138EA4();
    func_80138EFC();
}

s32 func_80138ACC(void) {
    return -1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80138AD4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80138ADC);

extern void func_80120A64();
extern void func_80116264();
extern s32 func_80138ACC();
extern u8 D_80195A65;

void func_80138D78(void) {
    extern s32 func_80138F5C(s32, s32);
    extern s32 func_8010F250();
    extern s16 D_8015330C;
    s32 temp_v0;

    if (D_80195A65 == 0) {
        D_8018BA25 = 0;
        func_80115460(0);
        D_80195A65 = 1;
    }
    func_80116264(1, 0, 0, 0, (s32) D_8015330C, &func_80138ACC, 0);
    temp_v0 = func_80138F5C(D_801CD5EC[D_8018BA20] + 0x10E, 0);
    D_801CD100 = temp_v0;
    if (temp_v0 != 0) {
        D_801CD784 = 0x19;
        func_80120A64(D_8018BA20, temp_v0);
        func_800FFD70(2, &func_8010F250);
        func_800FFF08(2, 0x19, 0xF821, 0);
        D_801950D6 = 1;
        D_80195A65 = 0;
    }
}

extern s16 D_8019520C;

s32 func_80138E74(void) {
    if (D_8019520C == 0) {
        return 0x5DC;
    }
    return -(D_8019520C == 1) & 0x578;
}

extern s32 D_80195A68;
extern s32 func_80138E74();

void func_80138EA4(void) {
    s32 *p = (s32 *) &D_801CD794;
    s32 v0 = (s32) &func_80138E74;
    s32 s1;

    s1 = *p;
    *p = v0;
    func_80126570(&D_80195A68, 0, 0);
    *p = s1;
}

extern u8 D_80195AB5;
extern u8 D_801CD0FC;

void func_80138EFC(void) {
    s32 *s0 = (s32 *) &D_801CD794;
    s32 s1;
    register u8 *a0 asm("a0") = &D_80195AB5;
    register s32 a1 asm("a1") = 0;
    register s32 a2 asm("a2") = 0;
    register s32 v0 asm("v0");

    s1 = *s0;
    v0 = D_801CD0FC;
    *s0 = 0;
    *a0 = v0;
    func_80126570(a0 - 0x29, a1, a2);
    *s0 = s1;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80138F5C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80138F64);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80139184);

extern u8 D_801CD11C[];
extern s16 D_801CD12C;
extern u8 D_80195B5C[];

void func_801397F8(void) {
    s32 v0v = 8;
    s16 *v1v = (s16 *) &D_801CD12C;
    u8 *s0v;
    s32 a0v;
    s32 a1v;
    s32 a2v;
    s32 a3v;

    do {
        *v1v = v0v;
        v0v -= 1;
        v1v -= 1;
    } while (v0v >= 0);
    a0v = 7;
    KEEP(a0v);
    s0v = D_801CD11C;
    KEEP(s0v);
    v0v = -1;
    *(s16 *) (s0v + 0x12) = v0v;
    v0v = func_8012D898(a0v);
    a0v = (s32) s0v;
    a1v = D_801CD20C;
    a2v = v0v;
    a3v = (s32) D_80195B5C;
    func_80128C7C(a0v, a1v, a2v, a3v);
}

extern s16 D_80195AD8;
extern s16 D_80195B9C[];
extern u8 D_80195BA6;
extern u8 D_801CD110;
extern s16 D_801CD11Ch[] asm("D_801CD11C");
extern u8 D_801CD130;
extern u8 D_801CD134;
extern u8 D_801CD138;
extern u8 D_801CD13C;
extern u16 func_8012AA84();
extern void func_80139A2C();

void func_80139868(void) {
    extern u8 D_8018BACC;
    extern void func_800FFF08(s32, s32, s32, s32);
    extern void func_80139C80(s32);
    s32 var_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    if (D_80195BA6 == 0) {
        D_801CD110 = 0;
        func_800FFF08(2, 0x21, 0xC015, 0);
        D_80195BA6 = 1;
    }
    if (D_801CD110 < 0xA) {
        D_801CD110 = D_801CD110 + 1;
    }
    func_80139A2C();
    D_80195BA6 = 0;
    if ((D_801CD52C & 0x840) && (D_801CD110 >= 0xA)) {
        temp_v1 = D_801CD130;
        D_801CD130 = 1;
        D_801CD134 = temp_v1;
    } else {
        D_80195BA6 = 1;
    }
    if ((D_801CD52C & 0x20) && (D_801CD110 >= 0xA)) {
        D_8018BACC = 0x3C;
        if (D_801CD13C == 0) {
            if (D_801CD138 == 5) {
                temp_v1_2 = D_801CD130;
                D_801CD130 = 1;
                D_80195BA6 = 0;
                D_801CD134 = temp_v1_2;
            } else {
                func_80139C80(D_80195B9C[D_801CD138]);
            }
            D_8018BACC = 1;
        } else {
            var_a0 = (s16) func_8012AA84(&D_80195AD8, D_801CD11Ch[D_801CD13C], D_801CD138);
            if (var_a0 == 0xFE) {
                var_a0 = 0xFA;
            }
            func_80139C80(var_a0);
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80139A2C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80139A3C);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_80139C80);

extern s16 D_80195BD4;
extern u8 D_80195C10;
extern s16 D_80195C0C;
extern u8 *D_801CD164;
extern u8 *D_801CD908;
extern u8 D_801CD114;
extern u8 D_801CD118;
extern u8 D_801CD144[];
extern u8 D_801CD154;
extern s16 D_801CD16C;

void func_8013A004(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    s32 i;
    u8 *p;

    v0v = D_80195C10;
    if (v0v != 0) {
        goto tail;
    }
    p = D_801CD144;
    D_80195C0C = 0;
    MEMORY_BARRIER();
    a0v = *p;
    if (a0v == 0xFE) {
        v1v = 1;
        D_801CD118 = v1v;
        v0v = *(u8 *) D_801CD164;
        *p = v0v;
        i = 0;
        if (v0v != a0v) {
            a0v = 0xFE;
            for (;;) {
                if (i >= 0x10) {
                    v0v = 0xFE;
                    D_801CD154 = v0v;
                    a0v = 2;
                    goto call;
                }
                i++;
                v0v = *(u8 *) (D_801CD164 + i);
                D_801CD144[i] = v0v;
                if (v0v == a0v) {
                    a0v = 2;
                    goto call;
                }
            }
        }
        a0v = 2;
        goto call;
    } else {
        D_801CD118 = 0;
        a0v = 2;
    }
call:
    a1v = 0x21;
    a2v = 0xC01A;
    MEMORY_BARRIER();
    v0v = (s32) D_801CD144;
    D_801CD908 = (u8 *) v0v;
    D_801531D8 = 0xC800;
    func_800FFF08(a0v, a1v, a2v, 0);
    v1v = 1;
    MEMORY_BARRIER();
    v0v = -1;
    D_80195C10 = v1v;
    D_801CD114 = 0;
    D_801CD16C = v0v;
    D_8018DFB4 = v1v;
tail:
    v0v = D_801CD114;
    if (v0v != 0) {
        v0v = func_800FFEEC(2);
        if (v0v != 0) {
            return;
        }
        v0v = 0xFF;
        D_80195C10 = 0;
        D_801CD130 = v0v;
        D_8018DFB4 = 0;
        return;
    }
    v0v = func_8012AB78(0xF, &D_80195BD4);
    if (v0v != 0) {
        return;
    }
    v0v = D_801CD16C;
    if (v0v != 0) {
        goto tail2;
    }
    v0v = 1;
    D_801CD114 = 1;
    func_800FFF08(2, 0x21, -1, 0);
    return;
tail2:
    v0v = D_801CD134;
    v1v = D_801CD118;
    D_801CD130 = v0v;
    if (v1v == 0) {
        goto last;
    }
    v0v = 0xFE;
    D_801CD144[0] = v0v;
last:
    D_80195C10 = 0;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_5", func_8013A1E0);
