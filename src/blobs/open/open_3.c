#include "common.h"

extern void func_800248FC();
extern s32 D_8004EAF4;
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
extern s32 D_8008FC14;
extern void func_800686DC();
extern void func_80068760();
extern void func_8006E8B0();
extern u8 D_80073F34[];
extern void func_80043F00();
extern void func_80068220();
extern void func_800687AC();
extern void func_80068AEC();
extern void func_80068BB0();
extern void func_80069A90();
extern void func_80069E60();
extern void func_80043F00(void);
extern void func_80068AEC(void);
extern void func_800249C4(void *, s32, s32);
extern void func_800246D4(s32);
extern void func_80069B6C(void);
extern void func_800687AC(s32);
extern void func_80068BB0(void);
extern void func_8006F8E0(void);
extern void func_80067EB8();
extern void func_80068C90();
extern s32 D_800852A0;
extern s32 D_800852A8;
extern u8 D_80085D04[];
extern u8 D_80085D0C[];
extern u8 D_80085D24[];
extern u8 D_80086098[];
extern u8 D_800860A4[];
extern u8 D_800860CC[];
extern s32 D_8008FC00;
extern void func_80011BD0();
extern void func_80069A34();
extern s32 D_8004EAF8;
extern void func_80011E38(s32 *);
extern void func_8001DBA8(s32);
extern void func_800699D4();
extern void func_80069CC8();
extern void func_80069D7C();
extern s32 D_800855A8;
extern s32 D_800852A4;
extern void func_800699D4(s32 *, s32, s32, s32);
extern void func_80069A34(void);
extern void func_80069CC8(s32, s32);
extern void func_80069D7C(s32);
extern s32 D_80085CA8;
extern s32 D_80073F58[];
extern s32 D_80073F5C[];
extern void func_80018240(s32, s32);
extern void func_80043F88(s32);
extern void func_80067E68(s32);
extern void func_80069C38(void);
extern void func_8006D7AC(s32, s32, s32);
extern s32 D_80070CB4;
extern struct S64358_100 D_80085334[];
extern s32 D_8008FBF0[];
extern s32 D_8008FC04;
extern s32 D_800860B0[];
extern struct J658A8_A D_800860C4[];
extern struct J658A8_B D_800860A8[];
extern struct J658A8_C D_800860C6[];
extern struct J658A8_A D_800860C8[];
extern struct J658A8_C D_800860CA[];
extern void func_800E4268();
extern s32 func_800E6EDC();
extern u8 D_80085324[];
extern u8 D_80085328[];
extern u8 D_8008532C[];
extern u8 D_80085330[];
extern s32 D_800855EC;
extern s16 D_800855F4[];
extern s32 D_8008E430;
extern s16 D_8008E434[];
extern void func_80067E68();
extern void func_800F1330();
extern void func_800E86EC();
extern s32 func_800FFEEC(s32);
extern void func_8006F91C(s32, s32, s32);
extern s32 D_8008E560;
extern s32 D_8008E574;
extern s32 D_8008E548;
extern s32 D_8008FBCC;
extern s32 D_8008FBD0;
extern s32 D_8008FBD4;
extern s32 D_8008FBC4;

void func_8006905C(void) {
    s32 a0v;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a0v = (s32) &D_8008E548;
    v1 = *(s32 *) a0v;
    v0 = v1 & 4;
    if (v0 == 0) {
        goto path_a4;
    }
    v0 = v1 & 0x10;
    if (v0 == 0) {
        goto path_90;
    }
    v0 = v1 ^ 2;
    KEEP(v0);
    __asm__ volatile(".word 0x0801c03c\n.word 0xac820000");
path_90:
    v0 = D_8008E574;
    KEEP(v0);
    v1 ^= 4;
    __asm__ volatile(".word 0x0801c02e\n.word 0xac830000");
path_a4:
    v0 = v1 & 0x28;
    if (v0 != 0) {
        v0 = -59;
        goto path_d0;
    }
    v0 = D_8008E574;
    v0 += 2;
    D_8008E574 = v0;
    __asm__ volatile(".word 0x0801c03c\n.word 0x00000000");
path_d0:
    v0 = v1 & v0;
    v0 |= 0x14;
    D_8008FBC4 = 0;
    *(s32 *) a0v = v0;
    a0v = 0;
    func_80068638(0, 1);
end:
    return;
}

void func_80069100(s16 *arg0) {
    s32 a0;
    s32 v0;

    v0 = arg0[1];
    a0 = v0;
    a0 <<= 1;
    a0 += v0;
    a0 <<= 3;
    a0 -= v0;
    v0 = D_800852A4;
    a0 <<= 11;
    func_80069D7C(v0 + a0);
    v0 = D_8008E574;
    D_8008FBD4 = 0;
    v0 += 4;
    D_8008E574 = v0;
}

void func_80069160(void) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a1 = *(s16 *) (a0 + 2);
    a0 = (s32) &D_8008E548;
    D_8008FBCC = 0;
    D_8008FBD4 = 0;
    v0 = *(s32 *) a0;
    v1 = D_8008E574;
    v0 |= 0x40;
    v1 += 4;
    *(s32 *) a0 = v0;
    D_8008FBD0 = a1;
    D_8008E574 = v1;
}

void func_800691AC(void) {
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v0 = 0x80;
    a1 = *(s16 *) (a0 + 2);
    a0 = (s32) &D_8008E548;
    D_8008FBCC = 0;
    D_8008FBD4 = v0;
    v0 = *(s32 *) a0;
    v1 = D_8008E574;
    v0 |= 0x80;
    v1 += 4;
    *(s32 *) a0 = v0;
    D_8008FBD0 = a1;
    D_8008E574 = v1;
}

__asm__(".globl func_800691FC\nfunc_800691FC:\n"

        "lui $a0,0x8009\n"
        "addiu $a0,$a0,-0x1ab8\n"
        "lw $v1,0($a0)\n"
        "nop\n");

extern s32 D_8008FBD8;
extern s32 D_8008FBDC;
extern s32 D_8008FBE0;
extern s32 D_8008FBE4;
extern s32 D_8008FBEC;
extern u8 D_80074074;

void func_8006920C(void) {
    s32 a0;
    s32 v0;
    s32 v1;

    v0 = v1 & 0x38;
    if (v0 != 0) {
        v0 = v1 ^ 2;
        __asm__ volatile(".set\tnoreorder\n\tj D_80070238\n\tsw %0,0(%1)\n\t.set\treorder"
                         : : "r"(v0), "r"(a0) : "memory");
    }
    v0 = D_8008E574;
    v0 += 2;
    D_8008E574 = v0;
}

void func_80069240(void) {
    s32 a0;
    s32 v0;
    register s32 v1 asm("v1");

    a0 += 2;
    v0 = *(s16 *) a0;
    a0 += 2;
    D_8008FBD8 = v0;
    v0 = *(s16 *) a0;
    a0 += 2;
    D_8008FBDC = v0;
    v0 = *(s16 *) a0;
    D_8008FBE0 = v0;
    a0 = *(s16 *) (a0 + 2);
    MEMORY_BARRIER();
    v0 = D_8008E574;
    v1 = 1;
    D_8008FBE4 = v1;
    v0 += 0xA;
    D_8008E574 = v0;
    D_8008FBEC = a0;
}

void func_800692A8(void) {
    register s32 a0 asm("a0");

    D_80074074 = (u8) a0;
}

extern void func_800703E8();
extern void func_80070548();
extern s32 D_800596C0;

void func_800692B8(void) {
    func_800703E8();
    func_80070548();
}

DEAD_TAIL_LW(4, D_800596C0);

extern s32 D_800596C4;
extern s32 D_800596C8;
extern s32 D_800596CC;
extern s32 func_80021FA4();

s32 func_800692E8(void) {
    s32 s0 = -1;
    s32 s1;
    s32 v;
    s32 r;

    r = func_80021FA4();
    s1 = 1;
    if (r == 1) {
        __asm__ volatile(
            ".set\tnoreorder\n\tj 0x80070370\n\taddu $16,$0,$0\n\t.set\treorder"
            : "=r"(s0));
    }
    if (func_80021FA4(D_800596C4) == 1) {
        __asm__ volatile(
            ".set\tnoreorder\n\tj 0x80070370\n\tori $16,$0,0x1\n\t.set\treorder"
            : "=r"(s0));
    }
    if (func_80021FA4(D_800596C8) == 1) {
        __asm__ volatile(
            ".set\tnoreorder\n\tj 0x80070370\n\tori $16,$0,0x2\n\t.set\treorder"
            : "=r"(s0));
    }
    v = func_80021FA4(D_800596CC);
    if (v == 1) {
        v = -1;
        s0 = 3;
        FORCE_REG(v);
        v = -1;
    } else {
        v = -1;
    }
    if (s0 == v)
        goto end;
    func_800703E8();
end:
    return s0;
}

extern s32 func_80028770(u8);
extern s32 func_800702E0();

s32 func_800693A0(void) {
    s32 s0;
    s32 v0;

    do {
        s0 = func_80028770(D_80074074) & 1;
        v0 = func_800702E0();
        if (v0 >= 0) {
            break;
        }
        v0 = 2;
    } while (s0 == 0);
    return v0;
}

DEAD_TAIL_LW(4, D_800596C0);

void func_800693F0(s32 arg0) {
    func_80021FA4(arg0);
    func_80021FA4(D_800596C4);
    func_80021FA4(D_800596C8);
    func_80021FA4(D_800596CC);
}

DEAD_TAIL_LW(4, D_800596D0);

extern s32 D_800596D4;
extern s32 D_800596D8;
extern s32 D_800596DC;

s32 func_80069448(void) {
    s32 s0 = -1;
    s32 s1 = 1;
    s32 v;
    s32 r;

    r = func_80021FA4();
    if (r == 1) {
        __asm__ volatile(
            ".set\tnoreorder\n\tj 0x800704D0\n\taddu $16,$0,$0\n\t.set\treorder"
            : "=r"(s0));
    }
    if (func_80021FA4(D_800596D4) == 1) {
        __asm__ volatile(
            ".set\tnoreorder\n\tj 0x800704D0\n\tori $16,$0,0x1\n\t.set\treorder"
            : "=r"(s0));
    }
    if (func_80021FA4(D_800596D8) == 1) {
        __asm__ volatile(
            ".set\tnoreorder\n\tj 0x800704D0\n\tori $16,$0,0x2\n\t.set\treorder"
            : "=r"(s0));
    }
    v = func_80021FA4(D_800596DC);
    if (v == 1) {
        v = -1;
        s0 = 3;
        FORCE_REG(v);
        v = -1;
    } else {
        v = -1;
    }
    if (s0 == v)
        goto end;
    func_80070548();
end:
    return s0;
}

extern s32 func_80070440();
extern s32 D_800596D0;

s32 func_80069500(void) {
    s32 s0;
    s32 v0;

    do {
        s0 = func_80028770(D_80074074) & 1;
        v0 = func_80070440();
        if (v0 >= 0) {
            break;
        }
        v0 = 2;
    } while (s0 == 0);
    return v0;
}

DEAD_TAIL_LW(4, D_800596D0);

void func_80069550(s32 arg0) {
    func_80021FA4(arg0);
    func_80021FA4(D_800596D4);
    func_80021FA4(D_800596D8);
    func_80021FA4(D_800596DC);
}

extern s32 func_80028740(s32);
extern void func_800703A0(void);

s32 func_800695A0(s32 arg0, s32 arg1) {
    s32 s0 = 0;
    s32 s3;
    s32 v1;
    register s32 v0 asm("v0");
    volatile s32 unused[2];

    if (arg1 <= 0) {
        goto end;
    }
    s3 = 1;
loop:
    func_80028740(arg0);
    USE(s3);
    if (v0 != s3) {
        v1 = 1;
        goto loop_inc;
    }
    func_800703A0();
    v1 = v0;
    if (v1 == 0) {
        goto end;
    }
    __asm__ volatile(".word 0x0801c17f\n.word 0x26100001");
loop_inc:
    s0++;
    if (s0 < arg1) {
        goto loop;
    }
end:
    return v1;
}

__asm__(".text\n.globl func_80069628\nfunc_80069628 = . - 4\nlui $v0, %hi(D_80074075)\nlbu $v0, %lo(D_80074075)($v0)\n");

extern s8 D_80074075;
extern s32 func_800705A0(s32, s32);

s32 func_80069634(void) {
    s32 s0;
    s32 v0;
    s32 v1;

    if (v0 == 0) {
        func_80028740(D_80074074 << 4);
        D_80074075 = 1;
    }
    s0 = func_80028770(D_80074074) & 1;
    v1 = func_800702E0();
    if (s0 != 0 && v1 == -1) {
        D_80074075 = 0;
    }
    if (v1 >= 0) {
        D_80074075 = 0;
        if (v1 > 0) {
            v1 = func_800705A0(D_80074074 << 4, 2);
        }
    }
    v0 = 1;
    __asm__(".globl func_800696C8\nfunc_800696C8 = . + 4");
    if (v1 != v0) {
        v0 = v1;
        goto end;
    }
    v1 = 2;
    KEEP(v1);
    v0 = v1;
end:
    return v0;
}

extern s32 func_8007062C(void);
extern s32 D_8007074C(void);

s32 func_800696E8(s32 arg0) {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 v0;
    s32 v1;
    volatile s32 unused[2];

    s2 = arg0;
    s1 = 0;
    s0 = 0;
    if (s2 > 0) {
        s3 = -1;
loop:
        v1 = func_8007062C();
        if (v1 == s3) {
            goto loop;
        }
        if (v1 != 0) {
            goto nonzero;
        }
        s1++;
        s0--;
        if (s1 == 3) {
            goto end;
        }
        __asm__ volatile(".set\tnoreorder\n\tj D_8007074C\n\taddiu %0,%0,1\n\t.set\treorder"
                         : "=r"(s0) : "0"(s0));
nonzero:
        s1 = 0;
        MEMORY_BARRIER();
        s0++;
        v0 = s0 < s2;
        if (v0) {
            goto loop;
        }
    }
end:
    return v1;
}

extern void func_800702B8(void);
extern s32 func_800702A8(s32);
extern s32 func_800706E8(s32);

s32 func_8006977C(void) {
    s32 s0;
    s32 v0;
    s32 v1;

    s0 = 0;
    func_800702B8();
    func_800702A8(1);
    v1 = func_800706E8(3);
    if (v1 == 0) {
        goto set_s0;
    }
    v0 = 3;
    if (v1 != v0) {
        goto second;
    }
    __asm__(".globl func_800697B0\nfunc_800697B0 = . - 4");
set_s0:
    s0 = 1;
second:
    func_800702A8(0);
    v1 = func_800706E8(3);
    if (v1 == 0) {
        goto set_s0_2;
    }
    v0 = 3;
    if (v1 != v0) {
        v0 = s0;
        goto end;
    }
set_s0_2:
    s0 = 1;
    KEEP(s0);
    v0 = s0;
end:
    return v0;
}
