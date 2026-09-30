#include "common.h"

extern void func_8005E7A8();
extern void func_8018430C();
extern void func_80183BF0();
extern void func_80181F38();
extern void func_8017F388();
extern s32 func_8018E660();
extern s32 func_801743B8(s32);

s32 func_8016D370(void) {
    register s32 v1 asm("v1");

    s32 v0;
    v1 = func_8018E660();
    __asm__ volatile(".set\tnoreorder\n\tslti $2,$3,3\n\tbnez $2,.L8016D370_done\n\tori $2,$zero,1\n\t.set\treorder" : "=r"(v0) : "r"(v1));
    __asm__ volatile("ori $2,$zero,5" : "=r"(v0));
    __asm__ volatile(".set\tnoreorder\n\tbne $3,$2,.L8016D370_check\n\tori $2,$zero,3\n\t.set\treorder" : "=r"(v0) : "r"(v1));
    __asm__ volatile(".set\tnoreorder\n\tj func_801743B8\n\tori $2,$zero,1\n\t.set\treorder" : "=r"(v0));
    __asm__ volatile(".L8016D370_check:");
    __asm__ volatile(".set\tnoreorder\n\tbeq $3,$2,.L8016D370_two\n\tori $2,$zero,6\n\t.set\treorder" : "=r"(v0) : "r"(v1));
    __asm__ volatile(".set\tnoreorder\n\tbne $3,$2,.L8016D370_done\n\tori $2,$zero,3\n\t.set\treorder" : "=r"(v0) : "r"(v1));
    __asm__ volatile(".L8016D370_two:");
    __asm__ volatile("ori $2,$zero,2" : "=r"(v0));
    __asm__ volatile(".L8016D370_done:");
    return v0;
}

s32 func_8016D3C8(u8 *arg0) {
    register u8 *s0v asm("s0") = arg0;
    register s32 v0 asm("v0");
    register s32 a0v asm("a0");
    s32 v1;
    v0 = (unsigned) (s0v[3] - 0x5E) < 3;
    __asm__ volatile(".set\tnoreorder\n\tbeq %1,$0,1f\n\taddu $4,$16,$0\n\t.set\treorder" : "=r"(a0v) : "r"(v0) : "memory");
    if (func_8005E1B0((u8 *) a0v, 0xA) != 0) {
        __asm__ volatile(".set\tnoreorder\n1:\n\tj .L8017441C\n\taddu $2,$0,$0\n\t.set\treorder");
    }
    v1 = s0v[0x182];
    v0 = 2;
    if (v1 == 0) {
        v0 = 1;
    }
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016D430);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016D9C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016DB00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016DB48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016DB58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016DB8C);

extern u8 D_801908CC[];
extern u8 *D_8018F4F0;

void func_8016DDF8(void) {
    extern void func_801810A0();
    register u8 *s0v asm("$16");
    register s32 s1v asm("$17");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");

    s1v = 0;
    s0v = D_801908CC;
    while (s1v < 0x15) {
        v1 = s0v[1];
        v0 = 0xFF;
        s1v += 1;
        if (v1 != v0) {
            v0 = s0v[0x58];
            v0 &= 0x24;
            if (v0 != 0) {
                func_801810A0(s0v);
                v1 = (s32) D_8018F4F0;
                v1 = v1 + v0;
                v0 = *(u8 *) v1;
                v0 &= 0xEF;
                *(u8 *) v1 = v0;
            }
        }
        s0v += 0x1C0;
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016DE84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E288);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E3F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E40C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E428);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E440);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E47C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E49C);

extern u8 *D_8018F4E4;
extern void func_801755A8();

void func_8016E568(void) {
    u8 *p;
    s32 v1;

    p = D_8018F4E4;
    v1 = 0xFF;
    p[0x65] = v1;
    p[0x66] = v1;
    v1 = 0x7F;
    p[0x5A] = 0;
    p[0x5B] = 0;
    p[0x67] = v1;
    func_801755A8();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E5A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E67C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016E958);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016EAF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016EBA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016EE7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016EEA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016F4D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016F6B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016FC18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8016FCA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80170180);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801703B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801709DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80170C08);

extern void func_8017813C();

void func_80171098(s32 a0, s32 a1, s32 a2, s32 a3, s32 s4, s32 s5, s32 s6, s32 s7, s32 s8, s32 s9) {
    func_8017813C(a0, a1, a2, a3, s4, s5, s6, s7, s8, s9, 1);
}

void func_801710EC(s32 a0, s32 a1, s32 a2, s32 a3, s32 s4, s32 s5, s32 s6, s32 s7) {
    s32 x[2];

    func_8017813C(a0, a1, a2, a3, s4, s5, s6, s7, 1, x, 0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017113C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80171CA4);

extern u8 D_800E4E9C;
extern u8 func_800E4EA0;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
} Rec_5;

extern Rec_5 D_80192DD8[];

void func_80172424(s32 arg0, s32 arg1, s32 arg2) {
    s32 t0;
    s32 t1;
    s32 a3;
    s32 v0;
    s32 w;

    for (t0 = 0; t0 < func_800E4EA0; t0++) {
        t1 = (arg1 < t0) ? (t0 - arg1) : (arg1 - t0);
        for (a3 = 0; a3 < D_800E4E9C; a3++) {
            v0 = (arg0 < a3) ? (a3 - arg0) : (arg0 - a3);
            if (arg2 >= t1 + v0) {
                D_80192DD8[t0 * D_800E4E9C + a3].f0 = 0;
                w = a3 + 0x100;
                D_80192DD8[t0 * D_800E4E9C + w].f0 = 0;
            }
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80172518);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801727B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801728B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80172A20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80172B58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80172DC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017316C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173290);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173518);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801736DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801738C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173AF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173C34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173C48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173C6C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173C74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173C90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80173FC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174060);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174074);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174088);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174370);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801743B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801743C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801743C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801743F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174430);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174484);

extern u8 D_8018F8CC[];

void func_801744A0(void) {
    s32 a0v;
    volatile u8 *v1;
    s32 v0;

    a0v = 0;
    v1 = D_8018F8CC;
    do {
        v0 = v1[5];
        a0v = a0v + 1;
        v0 = v0 & 0x7F;
        v1[5] = v0;
        v1 = v1 + 8;
    } while (a0v < 0x200);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801744D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017454C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801745E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801746FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174700);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801747B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801747CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174860);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174874);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801748C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174A58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174B30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174B48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174B8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174BE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174C50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174C78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174DB4);

extern s32 func_801810A0();

s32 func_80174DD0(s32 arg0, s32 *arg1) {
    s32 s0v;
    u8 *p;
    s32 v0;
    s32 v1;

    s0v = (s32) arg1;
    v0 = arg0;
    v0 <<= 3;
    v0 -= arg0;
    v0 <<= 6;
    v1 = (s32) D_801908CC;
    p = (u8 *) (v0 + v1);
    *arg1 = func_801810A0(p);
    v1 = p[1];
    v0 = 0xFF;
    if (v1 == v0) {
        v0 = 1;
    } else {
        v0 = p[0x58] & 0x44;
        if (v0 != 0) {
            v0 = 1;
        } else {
            v0 = p[0x59] & 1;
            if (v0 != 0) {
                v0 = 1;
            } else {
                v0 = p[0x182] & 0x40;
                v0 = (v0 != 0);
            }
        }
    }
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174E68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174E84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80174F78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017503C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175158);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175194);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175244);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175248);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175288);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175368);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017536C);

extern s32 func_8017C45C();

void func_801753B8(s32 a0) {
    func_8017C45C(a0, a0, 0);
}

extern s32 func_80183DE0();
extern s32 D_8018F5F0;

s32 func_801753DC(u8 *arg0) {
    u8 *s1;
    s32 s0;

    s1 = &D_801908CC[((*arg0 << 3) - *arg0) << 6];
    s0 = func_8017C45C(arg0, s1 + 0x16E, 1);
    if ((s0 == 1) && (D_8018F5F0 == 0)) {
        func_80183DE0(s1);
    }
    return s0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017545C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175568);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801755A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801755E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175618);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017567C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175818);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801758DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175924);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017593C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175958);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801759B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175ACC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175C54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175D24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175E1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175E44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175E7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175EA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80175FA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176124);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017615C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176164);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017622C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176424);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176428);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801764A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801764D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801764D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801766B4);

extern u8 D_80192DD9[];
extern u8 D_8018F8D1[];
extern u8 D_8019390F;
extern u8 D_801938CC;
extern u8 D_801938CB;
extern u8 D_801938CA;
extern s32 func_8002230C();
extern void func_80179400();

void func_80176708(void) {
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 a1v asm("$5");
    register s32 a3v asm("$7");
    register u8 *t0 asm("$8");
    register s32 t1 asm("$9");
    register u8 *a2 asm("$6");
    s32 a0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s0 = 0;
    a1v = 0;
    t1 = 0x100;
    t0 = D_80192DD8;
    a2 = D_8018F8CC;
    a3v = 0;
    do {
        if (a1v == t1) {
            s1 = s0;
        }
        a0 = a2[5];
        if (a0 & 0x80) {
            v1 = a3v + (s32) t0;
            a3v += 5;
            s0 += 1;
            v0 = a0 & 0x7F;
            a2[5] = v0;
            *(u8 *) (v1 + 1) = a1v;
        }
        a1v += 1;
        a2 += 8;
    } while (a1v < 0x200);
    v1 = (func_8002230C() * s0) / 0x8000;
    v0 = v1 * 5;
    a0 = D_80192DD9[v0];
    if (v1 < s1) {
        v0 = a0 << 3;
    } else {
        a0 += 0x100;
        v0 = a0 << 3;
    }
    v1 = D_8018F8D1[v0];
    v1 |= 0x80;
    D_8018F8D1[v0] = v1;
    D_8019390F = 1;
    if (a0 >= 0) {
        a1v = a0;
    } else {
        a1v = a0 + 0xFF;
    }
    v1 = D_800E4E9C;
    v0 = (a0 & 0xFF) / v1;
    a0 = (a0 & 0xFF) % v1;
    v1 = a1v >> 8;
    D_801938CC = v1;
    D_801938CB = v0;
    D_801938CA = a0;
    func_80179400();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176850);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176A20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176B00);

void func_80176BC0() {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176BC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176BD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176BE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176C10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176C60);

extern s32 func_8017DCA8(s32, s32, s32, s32);

void func_80176C88(s32 arg0, s32 arg1, s32 arg2) {
    __asm__ volatile(".globl func_80176C90\nfunc_80176C90:");
    func_8017DCA8(arg0, arg1, arg2, 0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176CA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176E00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176E04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176EA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176EE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176EF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80176EFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801770FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017716C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177178);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177180);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801772C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017739C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801773B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177590);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177658);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177774);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177778);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177794);

void func_801777DC(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801777E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017782C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801779C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801779D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801779DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801779F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801779F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177A80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177B64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177B68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177C00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177C08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177C18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177D9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177E64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177FAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177FB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177FC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177FD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177FD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80177FE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017808C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178090);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801780EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017813C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178140);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017817C);

extern u8 D_8005E9D0[];

s32 func_801782D8(void) {
    extern s32 func_801810A0();
    s32 r;
    r = func_801810A0();
    return D_8005E9D0[D_8018F8CC[r << 3] & 0x3F];
}

extern u8 *D_80066234;
extern s32 func_8005A8D4();
extern s32 func_8005DFD4();

s32 func_8017831C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *a0 = D_80066234;
    u8 *s0;
    s32 b;

    s0 = &D_801908CC[((arg2 << 3) - arg2) << 6];
    b = *a0;
    s0[0x18A] = (u8) arg2;
    if (func_8005A8D4(s0, b, 0) == 0) {
        func_8005DFD4(s0, 1);
        return 0;
    }
    return -1;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178388);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178560);

extern s16 D_80193844;

void func_801785F8(s32 arg0) {
    D_80193844 = 0;
    func_8017F388(arg0, 1);
}

void func_80178620(s32 arg0) {
    func_8017F388(arg0, 0);
}

extern void func_8017F6C4();

void func_80178640(s32 arg0, u8 *arg1) {
    u8 *temp_a2;
    u16 n1;
    u16 h1;
    u16 n2;
    u16 h2;

    temp_a2 = &D_801908CC[((arg0 << 3) - arg0) << 6];
    n1 = (arg1[3] >> 7) << 15;
    h1 = *(volatile u16 *) &temp_a2[0x48] & 0x7FFF;
    *(u16 *) &temp_a2[0x48] = h1 | n1;
    temp_a2[0x48] = arg1[2];
    *(volatile u8 *) &temp_a2[0x47] = arg1[1];
    n2 = (arg1[3] & 0xF) << 8;
    h2 = *(volatile u16 *) &temp_a2[0x48] & 0xF0FF;
    *(u16 *) &temp_a2[0x48] = h2 | n2;
    func_8017F6C4(arg0, arg1, temp_a2);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801786C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801788A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178BEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178C68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178C70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178CA4);

extern void func_80180DB0();

s32 func_80178D08(s32 arg0) {
    register s32 a1v asm("a1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    u8 *p;
    s32 t;

    a1v = arg0;
    v0v = a1v;
    v0v <<= 3;
    v0v -= a1v;
    v0v <<= 6;
    v1v = (s32) D_801908CC;
    p = (u8 *) (v0v + v1v);
    v1v = p[1];
    v0v = 0xFF;
    if (v1v != v0v) {
        return 0;
    }
    v0v = p[0x183];
    if (v0v != 0) {
        return -1;
    }
    t = p[5];
    p[1] = (u8) a1v;
    p[0x183] = 1;
    if (t & 0x30) {
        func_80180DB0();
    }
    return 0;
}

s32 func_80178D80(s32 arg0) {
    u8 *p;

    p = D_801908CC + arg0 * 0x1C0;
    p[1] = 0xFF;
    p[0x183] = 0;
    return 0;
}

s32 func_80178DAC(s32 arg0) {
    u8 *p;

    p = D_801908CC + arg0 * 0x1C0;
    p[1] = 0xFF;
    p[0x183] = 2;
    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178DDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178E4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178E50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80178FC0);

extern s32 func_80180180();
extern void func_80180210();

#define TAIL_JUMP_ADDU(sym, x, y) __asm__ volatile(".set\tnoreorder\n\tj " #sym "\n\taddu $4,%0,%1\n\t.set\treorder" ::"r"(x), "r"(y))
#define TAIL_JUMP_LI_1(sym) __asm__ volatile(".set\tnoreorder\n\tj " #sym "\n\tori $2,$zero,0x1\n\t.set\treorder" ::: "$2")

s32 func_80179178(u8 *a0, s32 arg1) {
    register u8 *arg0 asm("$4");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");

    arg0 = a0;
    v0 = arg0[0x58];
    v0 &= 8;
    if (v0 != 0) {
        v0 = 0xFF;
        v1 = arg0[0x15D];
        if (v1 != v0) {
            v0 = 8;
            v1 = arg0[0x16F];
            if (v1 == v0) {
                SCHED_BARRIER();
                v0 = 1;
                if (arg1 == 0) {
                    return v0;
                }
                func_80180210();
                SCHED_BARRIER();
                TAIL_JUMP_LI_1(func_80180200);
            }
        }
    }
dispatch:
    v1 = arg0[0x182];
    v0 = v1 & 0x40;
    if (v0 == 0) {
        goto ret0;
    }
    v0 = v1 & 0x1F;
    v1 = (v0 << 3) - v0;
    v1 <<= 6;
    v0 = (s32) D_801908CC;
    TAIL_JUMP_ADDU(func_80180180, v1, v0);
ret0:
    return 0;
}

extern s32 func_8005E0CC();
extern s32 func_8013B590(s32);

void func_80179210(s32 arg0) {
    func_8005E7A8(arg0, 0);
}

extern s32 func_801802C8();
extern s32 func_801804C4();
extern char b_8018F8A4[];

__asm__(".globl b_8018F8A4\nb_8018F8A4 = func_8018F8A4");

s32 *func_80179230(s32 *arg0) {
    register s32 a0v asm("a0");
    register s32 *b asm("s1");
    s32 v;
    s32 r;

    b = func_801802C8(*(u8 *) ((u8 *) arg0 + 0x47), *(u8 *) ((u8 *) arg0 + 0x48),
                      *(u16 *) ((u8 *) arg0 + 0x48) >> 15);
    r = func_8005E0CC(0x64, 0x64 - *(u8 *) ((u8 *) arg0 + 0x24));
    a0v = 0x33;
    __asm__ volatile(".set\tnoreorder\n\tbnez %0,1f\n\tli $4,0x33\n"
                     "\tlbu $2,2(%1)\n\tj .L80180288\n\tnop\n1:\n"
                     "\t.set\treorder" ::"r"(r),
                     "r"(b) : "a0", "memory");
    v = *(u8 *) ((u8 *) b + 3);
    *(u8 *) b_8018F8A4 = v;
    r = func_8013B590(a0v);
    func_801804C4(r, *(u8 *) ((u8 *) b + 1), 1);
    *((s32 *) b_8018F8A4 - 1) = 0;
    return (s32 *) b_8018F8A4 - 1;
}

__asm__(".globl func_8017925C\nfunc_8017925C = func_80179230 + 0x2C");

__asm__(".globl func_801792A4\nfunc_801792A4 = func_80179230 + 0x74");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801792C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179318);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179360);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017937C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801793A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801793E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179400);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179420);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179424);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179498);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179518);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179530);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179614);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017963C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801796E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801796E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801797B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179894);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801798B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801798C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179904);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179A10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179A20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179AE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179B2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179B38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179B58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179C70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179C9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179D84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179DC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179F40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179F98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80179FE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A060);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A0A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A114);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A14C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A16C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A1E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A1F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A254);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A290);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A2F0);

extern u8 D_8018F8CF[];

s32 func_8017A30C(u8 *arg0) {
    extern s32 func_801810A0();
    s32 t;

    if (arg0[0x5C] & 4) {
        return 1;
    }
    if (arg0[0x182] & 0x40) {
        return 1;
    }
    t = D_8018F8CF[func_801810A0(arg0) * 8] >> 5;
    if (t < 2) {
        return 0;
    }
    if (arg0[0x5A] & 0x46) {
        return 0;
    }
    if (arg0[0x95] & 0xC8) {
        return 0;
    }
    return (arg0[0x182] & 0x80) == 0 ? 2 : 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A3C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A444);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A448);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A4E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A518);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A558);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A55C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A584);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A5BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A62C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A64C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A6BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A6DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A7BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A7C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017A8C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AA24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AA28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AAD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AAF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AB3C);

extern s32 func_80181B94();

s32 func_8017AB70(s32 arg0, s32 arg1) {
    return func_80181B94(arg0, arg1 & 0xFF) & 0xFF;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AB94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AC10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AC14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AC74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AC90);

extern s32 func_80181CDC();

s32 func_8017ACB8(s32 arg0, s32 arg1) {
    return func_80181CDC(arg0, arg1 & 0xFF) & 0xFF;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017ACDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AE58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AE5C);

void func_8017AEF0(s32 arg0, s32 arg1, s32 arg2) {
    func_80181F38(arg0, arg1 & 0xFF, arg2, 0xF0);
}

void func_8017AF14(s32 arg0, s32 arg1, s32 arg2) {
    func_80181F38(arg0, arg1 & 0xFF, arg2, 0xF);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AF38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AF40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AF94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017AFC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B030);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B068);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B088);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B1CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B2CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B3C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B3F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B3F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B408);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B430);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B484);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B4A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B4D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B4E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B508);

extern s32 func_80182688(s32, s32);

s32 func_8017B664(s32 arg0, s32 arg1) {
    return func_80182688(arg0, arg1 & 0xFF) & 0xFF;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B688);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B694);

extern void func_801827B4();

void func_8017B788(s32 a0, s32 a1, s32 a2) {
    u8 buf2[0x10];
    u8 buf1[0x10];
    func_801827B4(a0, a1 & 0xFF, a2, buf2, buf1);
}

extern void func_801817C0();

void func_8017B7B4(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 buf2[0x10];
    u8 buf1[0x10];
    func_801817C0(a0, a1 & 0xFF, a2, buf2, a3, 0, buf1, a4);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B7F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B860);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B874);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B8A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017B964);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BAA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BAFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BBC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BC34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BC38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BC50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BC78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BD58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BDD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017BE68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C010);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C044);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C078);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C0A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C150);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C158);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C204);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C280);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C2B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C2CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C344);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C374);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C3B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C3DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C45C);

extern s32 func_801835A8(u8 *);
extern void func_8018370C(s32 *, s32);

s32 func_8017C4BC(u8 *arg0) {
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register u8 *a0v asm("a0");
    s32 buf[40];

    s0 = (s32) arg0;
    v1 = ((u8 *) s0)[1];
    if (v1 == 0xFF) {
        v0 = -1;
        goto done;
    }
    a0v = (u8 *) s0;
    __asm__ volatile(".set\tnoreorder\n\tjal func_801835A8\n\tmove $4,$16\n\t.set\treorder" : "=r"(v0) : "r"(s0));
    if (v0 != 0) {
        v0 = -3;
        goto done;
    }
    a0v = (u8 *) buf;
    s0 = ((u8 *) s0)[0x18A];
    func_8018370C((s32 *) a0v, 1);
    __asm__ volatile("move $3,$zero\n\taddiu $4,$sp,0x10\n\tandi $16,$16,0xff");
loop:
    __asm__ volatile(".L8017C4BC_loop:");
    v0 = *(u8 *) a0v & 0x1F;
    if (v0 == s0) {
        v0 = v1;
        goto done;
    }
    __asm__ volatile(".set\tnoreorder\n\taddiu $3,$3,1\n\tslti $2,$3,0x28\n\tbnez $2,.L8017C4BC_loop\n\taddiu $4,$4,4\n\t.set\treorder" : "=r"(v1), "=r"(v0));
    v0 = -2;
done:
    __asm__ volatile(".L8017C4BC_done:");
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C544);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C5F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C714);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C728);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C7FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C8CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C8DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C94C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C954);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C958);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C964);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017C9B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CA78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CAAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CACC);

void func_8017CBA8(s32 arg0) {
    func_80183BF0(arg0, 0, 1);
}

void func_8017CBCC(s32 arg0) {
    func_80183BF0(arg0, 1, 0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CBF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CCC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CD00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CD04);

extern s32 func_8018130C();

s32 func_8017CD10(s32 arg0) {
    register u8 *s0v asm("s0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    s0v = (u8 *) arg0;
    v0v = func_8018130C();
    a0v = s0v[0x5C];
    v1v = s0v[0x187];
    a1v = s0v[0x188];
    a0v = v1v | (a0v & 8);
    a2v = a1v | v0v;
    v0v = 0;
    v1v = v1v | a1v;
    SCHED_BARRIER();
    if (a0v == 0) {
        goto end;
    }
    a1v = v1v;
    v1v = a2v & 0xFF;
    if (v1v == 0) {
        goto end;
    }
    v0v = (a1v != 0);
end:
    return v0v;
}

extern s32 func_801832CC(u8 *);
extern s32 func_80183DCC();

s32 func_8017CD70(s32 arg0) {
    register u8 *p asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    v0 = arg0;
    v0 <<= 3;
    v0 -= arg0;
    v0 <<= 6;
    v1 = (s32) D_801908CC;
    p = (u8 *) (v0 + v1);
    v1 = p[1];
    v0 = 0xFF;
    if (v1 == v0) {
        v0 = 1;
        return v0;
    }
    v0 = func_801832CC(p);
    if (v0 & 0xD) {
        v0 = 1;
        KEEP(v0);
        __asm__ volatile(".set\tnoreorder\n\tj func_80183DCC\n\tsb $0,0x186(%0)\n\t.set\treorder" : : "r"(p));
    }
    return p[0x186] == 0;
}

void func_8017CDE0(s32 arg0) {
    func_8005E7A8(arg0, 0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CE00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CE28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CE44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CF5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CF60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017CF78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D15C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D1C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D23C);

s32 func_8017D2F8(void) {
    s32 unused[2];

    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D30C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D324);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D328);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D350);

extern s32 D_8018F5FC;
extern s32 func_801843DC();

s32 func_8017D370(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_8018433C();
    s32 flag;

    flag = D_8018F5FC;
    *(s16 *) ((u8 *) arg1 + 0x2A) = (*(s16 *) ((u8 *) arg1 + 0x2A) * arg2) / 100;
    if (flag != 0) {
        goto tail;
    }
    if (func_8005E0CC(100, arg2) != 0) {
        goto false;
    }
tail:
    __asm__ volatile(".set\tnoreorder\n\tj func_801843DC\n\taddu $v0,$zero,$zero\n\t.set\treorder");
    false : func_8018433C();
    return 1;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D3EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D408);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D410);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D498);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D4A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D5F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D610);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D6EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D6F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D708);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D850);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D8B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D8B8);

extern u8 *D_80192D90;

s32 func_8017D8D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0;
    s32 s1;

    s0 = arg2;
    s1 = arg3;
    if (func_8005E0CC(arg1 & 0xFFFF, arg0 & 0xFFFF) != 0) {
        return 0;
    }
    if (D_8018F5FC != 0) {
        return 0;
    }
    D_80192D90[0] = 0;
    D_80192D90[2] = (u8) s0;
    D_80192D90[3] = (u8) s1;
    return 1;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D964);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017D9A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DA20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DB18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DBAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DBC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DC1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DC78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DC88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DCA8);

extern void func_8018BCF0();
extern void func_8018BD34();

void func_8017DE48(void) {
    register u8 *p asm("$2");
    register u8 *v1 asm("$3");
    s32 v0;

    p[0] = 0;
    v1 = D_80192D90;
    v0 = 5;
    v1[2] = v0;
    v0 = (s32) D_80192D90;
    *(u16 *) (v1 + 4) = 0;
    *(u16 *) (v1 + 0x2A) = 0;
    *(u16 *) (v1 + 0x10) = 0;
    *(u8 *) (v0 + 0x25) = 0;
    func_8018BCF0();
    func_8018BD34();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DE98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DEA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DEA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DED0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DED8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DEFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DF00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017DFA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E14C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E178);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E194);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E1B4);

extern u8 D_801938DE[];

void func_8017E2EC(void) {
    extern void func_8005E644();
    u8 *p;
    s32 v0;

    v0 = p[0x90];
    v0 &= 1;
    if (v0 != 0) {
        func_8005E644((s32) D_801938DE, 4);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E328);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E330);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E34C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E384);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E3DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E3E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E3FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E418);

extern s32 func_8017EA28(s32, s32, s32 *);
extern void func_8017EA80(s32, s32, s32, s32);

void func_8017E4C0(void) {
    extern void func_8005E644();
    u8 *p;
    s32 v0;

    v0 = p[0x5A];
    v0 &= 0x10;
    if (v0 != 0) {
        func_8005E644((s32) D_801938DE, 4);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E4FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E530);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E54C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E564);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E590);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E5C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E650);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E6EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E740);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E764);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E780);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E7DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E7E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E800);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E81C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017E9F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EA28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EA44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EA78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EA80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EA84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EAA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EBD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EC00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EC18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EC80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017ED10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017EFF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F020);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F06C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F094);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F0E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F0EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F2A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F2D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F388);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F3F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F4F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F570);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F578);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F59C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F5F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F620);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F624);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F640);

void func_8017F668(void) {
    s32 v0;
    u8 *v1;
    s32 unused[2];

    v0 |= 0x80;
    *(u8 *) (v1 + 0x25) = v0;
    __asm__ volatile("mfhi %0" : "=r"(v0));
    v0 >>= 5;
    *(s16 *) (v1 + 4) = v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F68C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F6C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F6C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F74C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F824);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F87C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F8A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F91C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F924);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017F9F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FB00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FB58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FBA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FBA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FBA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FBEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FC0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FC80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FCBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FCC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FCD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FD08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FD80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FDDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FED0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8017FFC0);

extern void func_80184E98();
extern u8 *D_80192D98;

void func_8017FFD8(void) {
    func_80184E98();
}

DEAD_TAIL_LW(2, D_80192D98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180000);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801800F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180134);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180140);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180148);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180178);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180180);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180200);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180210);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180230);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180250);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801802C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801802E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180340);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801803E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180470);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180474);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801804C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801804DC);

void func_801804EC(void) {
    u8 *p;
    u16 v;

    p = D_80192D90;
    v = *(u16 *) (p + 4);
    *(u16 *) (p + 4) = 0;
    *(u8 *) (p + 0x25) = 0x10;
    *(u16 *) (p + 0xA) = v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180510);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180518);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180528);

void func_801805C4(void) {
    u8 *p;
    s32 v0;

    v0 = p[0x15E];
    v0 -= 0xF;
    v0 = ((u32) v0 < 2);
    if (v0 == 0) {
        func_8018430C();
    }
}

void func_801805FC(void) {
    u8 *p;
    s32 v0;

    p = D_80192D98;
    v0 = p[0x5C];
    v0 &= 0x10;
    if (v0 != 0) {
        func_8018430C();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180638);

void func_80180698(void) {
    s32 v0;
    s32 p;
    u16 t;

    if (v0 == 0 && func_8005E0CC(0x64, 0x13) == 0) {
        p = (s32) D_80192D90;
        t = *(u16 *) ((u8 *) p + 0x10);
        t |= 0x200;
        *(u16 *) ((u8 *) p + 0x10) = t;
    }
}

extern u8 D_801938DA;
extern u8 D_801938C1;
extern s16 D_801938C8;
extern s16 D_801938C6;
extern u8 D_801938EF;

void func_801806E4(void) {
    s32 a0v;
    s32 v0v;
    s32 v1v;
    s32 unused[3];

    v0v = D_801938DA;
    a0v = D_801938C1;
    v1v = 1;
    D_801938C8 = v1v;
    D_801938C6 = v0v;
    D_801938EF = a0v;
    __asm__ volatile(".set\tnoreorder\n\tjal func_8018BD34\n\t.L8018071C:\n\tnop\n\t.set\treorder" ::: "ra", "memory");
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180730);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801808C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801808D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801808D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180904);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180908);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180918);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801809F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180A08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180A1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180AFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180B24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180B2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180C74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180C88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180C90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180CA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180DA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180DB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180DF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180EA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180EBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180F2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180F38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180F40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80180FE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181080);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801810A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801810D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181114);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018114C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801811E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801811E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801811F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801811FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801812F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181300);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018130C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181310);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801813B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801813C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801813C4);

extern void func_80185814();

s32 func_80181488(void) {
    func_80185814();
    return *D_80192D90 == 0;
}

extern void func_80187690();
extern void func_801852E4();
extern void func_8018537C();
extern void func_801853F4();
extern void func_801854FC();
extern void func_80188488();

s32 func_801814C0(void) {
    s32 v;

    func_80187690();
    if (D_8018F5FC == 2) {
        v = 0;
    } else {
        u32 t = *(u16 *) (D_80192D90 + 0x10);
        t &= 0x200;
        v = t < 1;
    }
    return v;
}

extern void func_80184F9C();
extern void func_80185328();
extern void func_80185738();

void func_80181510(void) {
    func_80184F9C();
    func_801852E4();
    func_80185328();
    func_8018537C();
    func_801853F4();
    func_80185738();
    func_801854FC();
    func_80188488();
}

void func_80181568(void) {
    func_80184F9C();
    func_801852E4();
    __asm__ volatile(".set\tnoreorder\n\tjal func_80185328\n\t.globl func_80181584\n\tfunc_80181584:\n\tnop\n\t.set\treorder" ::: "ra", "memory");
    func_8018537C();
    func_801853F4();
    func_801854FC();
    func_80188488();
}

extern void func_801851C4();
extern void func_801854B8();
extern void func_80186254();
extern void func_801862CC();
extern void func_8018636C();
extern void func_80184964();

void func_801815B8(void) {
    func_801851C4();
    func_801854B8();
    func_8018537C();
    func_801853F4();
    func_80188488();
}

extern void func_80186054();
extern void func_80185FA4();
extern void func_801886A4();
extern void func_80186FD0();
extern void func_801870FC();

void func_801815F8(void) {
    func_80186054();
    func_80186254();
    func_801862CC();
    func_8018636C();
    func_80184964();
}

extern void func_80185A9C();
extern void func_80185F80();
extern s32 func_801884C0();
extern void func_80186568();
extern void func_801864F8();

s32 func_80181638(void) {
    func_80185A9C();
    func_80185F80();
    func_80185FA4();
    func_801886A4();
    func_80186FD0();
    if (*D_80192D90 != 0) {
        func_801870FC();
        return func_801884C0();
    }
    return 1;
}

extern void func_801885F8();
extern void func_8018659C();
extern void func_80187510();

void func_801816A4(void) {
    func_801885F8();
    func_801864F8();
    func_80186568();
}

s32 func_801816D4(void) {
    func_801885F8();
    func_8018659C();
    func_80187510();
    return *D_80192D90 == 0;
}

extern void func_80186204();

void func_8018171C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    func_801870FC();
    func_801884C0();
}

__asm__(".globl func_80181720\nfunc_80181720 = func_8018171C + 0x4");

extern void func_8018631C();
extern void func_80186460();

void func_80181744(void) {
    func_80186204();
    func_8018631C();
    func_80186460();
    func_80184964();
}

extern void func_80186ED0();
extern void func_80186FF8();

s32 func_8018177C(void) {
    s32 v0v;

    func_80186568();
    func_80186ED0();
    func_80186FF8();
    v0v = (s32) D_80192D90;
    v0v = *(u8 *) v0v;
    return v0v == 0;
}

__asm__(".globl func_801817C0\nfunc_801817C0 = func_8018177C + 0x44");

__asm__(".globl .L801817B8\n.L801817B8 = func_8018177C + 0x3C");

extern void func_80187EB4();

s32 func_801817C4(void) {
    register s32 r asm("v0");

    func_801870FC();
    r = func_801884C0();
    if (r == 0) {
        func_80187EB4();
        r = 0;
    }
    return r;
}

extern void func_80187150();

s32 func_80181800(void) {
    func_80186204();
    func_80184964();
    func_8018659C();
    func_80187150();
    func_80187510();
    return *D_80192D90 == 0;
}

extern void func_80185FFC();

void func_80181858(void) {
    func_80186204();
    func_80184964();
    func_80186568();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181888);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181898);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018193C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181940);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181960);

extern void func_80188744();
extern s32 func_8018877C();
extern void func_801887C4();

void func_80181964(void) {
    func_80185FFC();
    func_80188744();
    if (func_8018877C() == 0) {
        func_801887C4();
    }
}

extern void func_80185CC0();
extern void func_80188964();
extern void func_80185D80();

void func_801819A4(void) {
    func_80185CC0();
    func_80188964();
}

s32 func_801819CC(void) {
    func_80185D80();
    func_80188744();
    func_8018659C();
    func_80187150();
    func_80187510();
    return *D_80192D90 == 0;
}

s32 func_80181A24(void) {
    func_80185D80();
    func_80185FFC();
    func_80188744();
    func_8018659C();
    func_80187150();
    func_80187510();
    return *D_80192D90 == 0;
}

s32 func_80181A84(void) {
    func_80185D80();
    func_80185FFC();
    func_80188744();
    func_8018659C();
    func_80187510();
    return *D_80192D90 == 0;
}

extern void func_8018614C();
extern void func_80188ADC();

void func_80181ADC(void) {
    func_80186254();
    func_801862CC();
    func_8018636C();
    func_80184964();
}

extern s32 func_80188510();

s32 func_80181B14(void) {
    func_8018614C();
    func_80188ADC();
    func_8018659C();
    func_80187510();
    return *D_80192D90 == 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181B64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181B70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181B74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181B94);

extern s32 func_80188638();
extern void func_801876E4();
extern u8 D_80193902;

void func_80181BA4(void) {
    if (func_80188510() == 0) {
        if (func_80188638() == 0) {
            func_801876E4();
        }
    }
}

DEAD_TAIL_LOAD(2, D_80193902, lbu);

extern u16 D_801938CE;
extern u16 D_801938D0;
extern u8 D_801938FA;

void func_80181BEC(void) {
    s32 v;

    D_801938CE = v;
    D_801938D0 = v;
    func_80185F80();
    func_801886A4();
}

extern void func_80187730();

void func_80181C24(void) {
    func_80187730();
    D_801938CE = D_80193902;
    D_801938D0 = D_801938FA;
    func_80185F80();
    func_80185FA4();
    func_80188744();
    if (func_8018877C() == 0) {
        func_80187150();
        func_801870FC();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181C9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181CB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181CBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181CDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181CE4);

extern void func_80187248();
extern void func_80187350();

void func_80181CF4(void) {
    if (func_80188510() == 0) {
        func_80185A9C();
        func_80185F80();
        func_801886A4();
        func_80187248();
    }
}

extern s32 func_801885B8();
extern void func_80185C94();

void func_80181D3C(void) {
    func_80185A9C();
    func_80184964();
    func_80185F80();
    func_801885F8();
    func_80186568();
    func_80187350();
}

extern s32 func_8018871C();

void func_80181D84(void) {
    if (func_801885B8() == 0) {
        func_80185C94();
        func_80185FFC();
        func_80188744();
        if (func_8018877C() == 0) {
            func_80187150();
            if (func_8018871C() == 0) {
                func_80187EB4();
            }
        }
    }
}

extern s32 func_80188A24();
extern void func_80186624();

void func_80181DF4(void) {
    if ((func_801885B8() == 0) && (func_80188A24() == 0)) {
        func_80186624();
        func_80186ED0();
        func_80186FF8();
        if ((*D_80192D90 != 0) && (func_8018871C() == 0)) {
            func_80187EB4();
        }
    }
}

extern void func_80187F24();

void func_80181E78(void) {
    if ((func_801885B8() == 0) && (func_80188A24() == 0)) {
        func_80187F24();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181EB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181EC0);

void func_80181EF0(void) {
}

void func_80181EF8(void) {
    func_80185C94();
    func_80185FFC();
    __asm__ volatile(".set\tnoreorder\n\tjal func_80188858\n\t.globl func_80181F14\nfunc_80181F14:\n\tnop\n\t.set\treorder" ::: "ra", "memory");
    func_80187150();
    func_80187350();
}

extern s32 func_80188800();
extern s32 func_8018ACDC();
extern s32 func_801889CC();

void func_80181F38(void) {
    func_80185D80();
    func_80185FFC();
    if (func_80188800() == 0) {
        if (func_8018ACDC() != 0) {
            func_80186624();
            func_80187350();
        }
    }
}

DEAD_TAIL_LW(2, D_80192D98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80181F98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80182044);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80182068);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018206C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80182074);

extern void func_8018668C();
extern void func_8018746C();

void func_80182084(void) {
    u16 *p;
    u16 t;

    if (func_801885B8() == 0) {
        if (func_801889CC() == 0) {
            func_8018668C();
            p = *(u16 **) &D_80192D90;
            t = p[4];
            p[2] = t;
            func_8018746C();
        }
    }
}

void func_801820DC(void) {
    if (func_801885B8() == 0) {
        if (func_801889CC() == 0) {
            func_80186624();
            func_80187248();
        }
    }
}

void func_80182124(void) {
}

extern void func_8018783C();

void func_8018212C(void) {
    func_80185D80();
    if (func_80188800() == 0) {
        func_8018783C();
    }
}

void func_80182164(void) {
}

extern s32 func_80188888();

void func_8018216C(void) {
    if (func_80188888() == 0) {
        *(u16 *) (D_80192D90 + 0x10) = 1;
        *(u8 *) (D_80192D90 + 0x25) = 1;
    }
}

void func_801821AC(void) {
    s32 v0v;
    if (func_801885B8() != 0) {
        return;
    }
    if (func_801889CC() != 0) {
        return;
    }
    v0v = 0x7F;
    D_80192D90[0x13] = v0v;
    D_80192D90[0x25] = 1;
}

void func_80182204(void) {
    u8 *p;
    u8 *q;
    s32 t;

    if (func_801885B8() != 0) {
        return;
    }
    if (func_801889CC() != 0) {
        return;
    }
    t = *(u16 *) (D_80192D98 + 0x2C);
    p = D_80192D90;
    *(p + 0x25) = 0x20;
    *(u16 *) (p + 8) = t;
}

extern void func_801866EC();

void func_8018225C(void) {
    if (func_801885B8() == 0) {
        if (func_801889CC() == 0) {
            func_801866EC();
        }
    }
}

void func_8018229C(void) {
}

void func_801822A4(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801822AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801822B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801822CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018232C);

void func_8018233C(void) {
    if ((func_801885B8() == 0) && (func_80188A24() == 0)) {
        func_8018668C();
    }
}

extern s32 func_80184360();
extern void func_801869EC();
extern void func_801875FC();

void func_8018237C(void) {
    func_801875FC();
    if ((*D_80192D90 != 0) && (func_80184360() == 0)) {
        func_80185C94();
        func_801869EC();
    }
}

void func_801823D8(void) {
    func_801875FC();
    if (*(u8 *) D_80192D90 != 0) {
        if (func_80184360() == 0) {
            func_80185A9C();
            func_80186AF8();
        }
    }
}

__asm__(".globl .L80182408\n.L80182408 = func_801823D8 + 0x30");

__asm__(".globl func_80182430\nfunc_80182430 = func_801823D8 + 0x58");

extern void func_801889A4();

void func_80182434(void) {
    if (func_801885B8() == 0) {
        func_801889A4();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80182464);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801824E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80182508);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801825B4);

extern void func_80187910();

void func_801825C4(void) {
    func_80187910();
    func_80185C94();
    func_80188964();
}

void func_801825F4(void) {
    u8 *p;
    u8 *q;
    u16 v;

    func_80187910();
    func_80185C94();
    func_80188744();
    v = D_801938CE * D_801938D0;
    p = D_80192D90;
    *(u8 *) (p + 0x25) = 0x20;
    *(u16 *) (p + 8) = v;
}

void func_80182654(void) {
    extern void func_80187F24();

    func_80187910();
    __asm__ volatile(".globl func_80182664\nfunc_80182664:");
    func_80187F24();
}

void func_8018267C(void) {
    __asm__ volatile(".set\tnoreorder\n\tjal func_80187910\n\t.globl func_80182688\n\tfunc_80182688:\n\tnop\n\t.set\treorder" ::: "ra", "memory");
    func_80185C94();
    func_80186568();
    func_80187350();
}

extern void func_80185D40();
extern void func_80185E30();

void func_801826B4(void) {
    if (func_801885B8() == 0) {
        func_80185D40();
        func_80188964();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801826EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80182768);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80182788);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80182794);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801827B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801827C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801827F0);

extern void func_80186744();
extern s32 func_80188B14();

void func_80182828(void) {
    if (func_80188510() == 0) {
        func_80185E30();
        if (func_80188B14() == 0) {
            func_80186744();
        }
    }
}

extern void func_80186814();

void func_80182870(void) {
    if (func_80188510() != 0) {
        return;
    }
    func_80185E30();
    func_8018614C();
    func_80186254();
    func_801862CC();
    func_8018636C();
    func_80184964();
    func_8018659C();
    func_80187510();
    if ((*D_80192D90 != 0) || (D_8018F5FC != 0)) {
        func_80186814();
    }
}

extern u8 *D_80192D94;

void func_80182910(void) {
    register u8 *p asm("a0");
    register u8 v0 asm("v0");
    register u8 v1 asm("v1");

    func_80185D80();
    func_80184964();
    func_8018659C();
    func_80187510();
    if (*D_80192D90 == 0) {
        goto end;
    }
    v1 = *(u8 *) (D_80192D98 + 6);
    p = D_80192D94;
    v0 = *(u8 *) (p + 6);
    v1 &= 0xE0;
    v0 &= 0xE0;
    if (v1 != v0) {
        goto false;
    }
    func_8018430C(p);
    __asm__ volatile("j D_80189994");
    false : func_80187F24(p);
end:
    return;
}

extern void func_80185E04();
extern void func_801882F8();
extern void func_80186C04();

void func_801829A4() {
    func_801875FC();
    if (D_80192D98[6] & 0x20) {
        if (!(D_80192D94[0x91] & 0x10)) {
            func_8018430C();
        }
    }
    if (D_80192D90[0] == 0) {
        return;
    }
    func_801882F8();
    if (D_80192D90[0] == 0) {
        return;
    }
    func_80185D80();
    func_80184964();
    func_8018659C();
    func_80187510();
    if (D_80192D90[0] == 0) {
        return;
    }
    func_80186C04();
}

extern void func_80187860();
extern s32 func_801886D4();

void func_80182A90(void) {
    if (func_80188510() == 0) {
        func_80185E04();
        if (func_801886D4() == 0) {
            func_80187860();
        }
    }
}

void func_80182AD8(void) {
    if (func_80188510() == 0) {
        func_80185E04();
        if (func_801886D4() == 0) {
            func_8018668C();
        }
    }
}

extern void func_80185E5C();

void func_80182B20(void) {
    if (func_80188510() == 0) {
        func_80185E5C();
        func_80185FA4();
        func_801886A4();
        func_80186FD0();
        if (*D_80192D90 != 0) {
            func_801870FC();
            func_80187EB4();
        }
    }
}

extern s32 func_801879C8();
extern void func_80184E40();
extern void D_80189C40();
extern void func_80187638();
extern void func_80185DD8();

void func_80182B94(void) {
    register s32 v0v asm("$2");
    register u8 *p asm("$3");

    if (func_80188510() != 0) {
        goto end;
    }
    if (func_801879C8() != 0) {
        func_80184E40();
        p = (u8 *) D_80192D90;
        v0v = 7;
        __asm__ volatile(".set\tnoreorder\n\tj D_80189C40\n\tsb $2,2($3)\n\t.set\treorder" ::"r"(p), "r"(v0v) : "memory");
    }
    func_80187638();
    p = (u8 *) D_80192D90;
    v0v = p[0];
    if (v0v == 0) {
        goto end;
    }
    *(u16 *) (p + 0x10) = 4;
    func_80185DD8();
    func_80185FA4();
    func_801886A4();
    func_80186FD0();
    v0v = (s32) (u32) D_80192D90;
    if (*(u8 *) v0v != 0) {
        func_801870FC();
    }
end:
    return;
}

void func_80182C50(void) {
    if (func_80188510() == 0) {
        func_80185DD8();
        func_801886A4();
        func_8018746C();
    }
}

void func_80182C90(void) {
    if (func_80188510() == 0) {
        func_80185DD8();
        func_801886A4();
        func_80187248();
    }
}

extern void func_80185D00();

void func_80182CD0(void) {
    extern void func_80186FF8();
    extern s32 func_801884C0();

    if (func_80188510() != 0) {
        return;
    }
    func_80185D00();
    func_80185FFC();
    func_8018614C();
    func_80188ADC();
    func_801864F8();
    func_80186568();
    func_80186ED0();
    func_80186FF8();
    if (*D_80192D90 == 0) {
        return;
    }
    func_801870FC();
    if (func_801884C0() != 0) {
        return;
    }
    func_80187EB4();
}

extern u8 D_801938EA;
extern u8 D_801938F9;
extern s32 func_8018EEA0();

void func_80182D74(void) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register u8 *a0 asm("a0");
    register u8 *a1 asm("a1");

    if (func_80188510() == 0) {
        func_80185D00();
        func_8018614C();
        func_80188ADC();
        func_801864F8();
        func_8018659C();
        v0 = func_8018EEA0();
        v1 = D_801938F9;
        a1 = &D_801938EA;
        v0 = (v0 * v1) / 32768;
        a0 = D_80192D90;
        v0 += 1;
        *a1 = v0;
        v0 = *a1;
        v1 = *(s16 *) (a0 + 4);
        a0[0x25] = 0x80;
        v0 = v1 * v0;
        *(s16 *) (a0 + 4) = v0;
    }
}

extern void func_80185DAC();

void func_80182E28(void) {
    func_80185DAC();
    func_8018614C();
    func_80186254();
    func_80184964();
    func_8018659C();
    func_80187510();
    if (*D_80192D90 != 0) {
        func_80187F24();
    }
}

void func_80182E94(void) {
    u16 *p;
    s16 t1;
    s16 t2;

    func_80185E04();
    func_8018614C();
    func_80184964();
    func_80186568();
    p = (u16 *) D_80192D90;
    t1 = p[2];
    p[2] = 0;
    p[3] = t1;
    t2 = *(volatile s16 *) &p[3];
    ((u8 *) p)[0x25] = 0x50;
    p[5] = t2 / 2;
}

void func_80182F08(void) {
    func_80185DAC();
    func_8018614C();
    func_80184964();
    func_8018659C();
    func_80187510();
    if ((*D_80192D90 != 0) && (func_8018ACDC() != 0)) {
        func_80186624();
        func_80187350();
    }
}

extern void func_8018691C();
extern s32 func_80188A84();

void func_80182F84(void) {
    if (func_80188510() == 0) {
        func_80185E04();
        func_8018614C();
        func_80188ADC();
        func_8018691C();
    }
}

void func_80182FCC(void) {
    if ((func_801885B8() == 0) && (func_80188A84() == 0)) {
        func_80187F24();
    }
}

void func_8018300C(void) {
    func_801866EC();
    MEMORY_BARRIER();
}

__asm__(".globl .L80183044\n.L80183044 = func_8018302C + 0x18");

__asm__(".globl .L80183038\n.L80183038 = func_8018302C + 0xC");

void func_8018302C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    func_80185E30();
    func_801885F8();
    func_8018659C();
    func_80187510();
    if (D_80192D90[0] != 0) {
        func_80187F24();
    }
}

__asm__(".globl func_80183078\nfunc_80183078 = func_8018302C + 0x4C");

void func_80183088(void) {
    func_80185E30();
    func_801885F8();
    func_8018659C();
    func_80187510();
    if (*D_80192D90 == 0) {
        goto end;
    }
    if ((*(u8 *) (D_80192D98 + 0x58) & 0x10) != 0) {
        goto false;
    }
    func_8018430C();
    __asm__ volatile("j D_8018A104");
    false : func_80187F24();
end:
    return;
}

void func_80183114(void) {
    register u8 *p asm("a0");
    register u16 v0 asm("v0");
    register u16 v1 asm("v1");

    if (func_80188A84() != 0) {
        goto end;
    }
    v1 = *(u16 *) (D_80192D98 + 8);
    p = D_80192D94;
    v0 = *(u16 *) (p + 8);
    v1 &= 0xF000;
    v0 &= 0xF000;
    if (v1 != v0) {
        goto false;
    }
    func_8018430C(p);
    __asm__ volatile("j D_8018A16C");
    false : func_80187F24(p);
end:
    return;
}

extern u8 *D_80192D8C;

void func_8018317C(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");

    func_80185E04();
    func_80184964();
    v1v = D_801938CE;
    v0v = D_801938D0;
    v0v = v1v * v0v;
    v1v = (s32) D_80192D90;
    *(s16 *) (v1v + 4) = v0v;
    v0v = (s16) v0v;
    v1v = D_801938F9;
    v0v = v0v / v1v;
    a0v = (s32) D_80192D8C;
    v1v = 1;
    *(u8 *) a0v = v1v;
    *(s16 *) (a0v + 4) = v0v;
    v0v = (s32) D_80192D90;
    v1v = 0x80;
    *(u8 *) (v0v + 37) = v1v;
    v0v = (s32) D_80192D8C;
    *(u8 *) (v0v + 37) = v1v;
}

__asm__(".globl .L801831F8\n.L801831F8 = func_8018317C + 0x7C");

__asm__(".globl D_801938F9\nD_801938F9 = 0x801938F9");

__asm__(".set\tpush\n.set\tnoreorder\n\tjr $31\n\tnop\n\t.set\tpop\n");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183220);

extern u8 func_80063F7C[];

void func_80183258(void) {
    s32 v1;

    MEMORY_BARRIER();
    *(s16 *) (D_80192D90 + 4) = func_80063F7C[0x1D + (v1 * 2 + v1)] * 10;
    func_80187350();
}

extern void func_80188288();

void func_801832A4(void) {
    func_80188288();
}

extern void func_801882C8();

void func_801832C4(void) {
    __asm__ volatile(".globl func_801832CC\nfunc_801832CC:");
    func_801882C8();
    func_80187350();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801832EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183360);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183374);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183390);

extern void func_80188858();

void func_801833A0(void) {
    func_80185C94();
    func_80188858();
    func_80187350();
}

void func_801833D0(void) {
    if (func_80188510() == 0) {
        func_80185D80();
        if (func_80188B14() == 0) {
            func_80186624();
            func_80187248();
        }
    }
}

void func_80183420(void) {
    if (func_801885B8() == 0) {
        func_80185C94();
        func_80188964();
    }
}

extern void func_80186E28();

void func_80183458(void) {
    if (func_80188510() == 0) {
        func_80185D80();
        if (func_80188B14() == 0) {
            func_80186E28();
        }
    }
}

void func_801834A0(void) {
    if (func_80188510() == 0) {
        func_80185D80();
        if (func_80188B14() == 0) {
            func_80187F24();
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801834E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183544);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183564);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183594);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801835A8);

void func_801835E4(void) {
    extern void func_80186FF8();
    if ((func_801885B8() == 0) && (func_80188A84() == 0)) {
        func_80186624();
        func_80186ED0();
        func_80186FF8();
        if ((*D_80192D90 != 0) && (func_8018871C() == 0)) {
            func_80187EB4();
        }
    }
}

extern void func_801874EC();

void func_80183668(void) {
    func_80185C94();
    func_80188858();
    func_801874EC();
}

void func_80183698(void) {
    if (func_801885B8() != 0) {
        return;
    }
    if (func_80188A84() != 0) {
        return;
    }
    *(D_80192D90 + 0x14) = D_801938FA & 0x7F;
    *(D_80192D90 + 0x25) = 1;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801836F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018370C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183710);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183748);

extern void D_8018A80C();

void func_80183758(void) {
    extern void func_80187F24();
    register u8 *a1p asm("$5");
    register u8 *s0p asm("$16");
    register u8 *s1p asm("$17");
    register u8 *a0p asm("$4");
    register u8 *p8c asm("$3");
    register s32 a2v asm("$6");
    register s32 v0v asm("$2");

    func_801882C8();
    func_80187350();
    a2v = 1;
    if (*(u8 *) (D_80192D98 + 0x22) >= 0x63U) {
        *(u8 *) (D_80192D90 + 0x25) = 0;
        func_8018430C();
        TAIL_JUMP(D_8018A80C);
    }
    a1p = D_80192D90;
    *(u8 *) (a1p + 0x25) = a2v;
    s0p = D_80192D98;
    s1p = *(volatile u8 **) &D_80192D90;
    a0p = D_80192D94;
    p8c = D_80192D8C;
    v0v = 0x80;
    *(u16 *) (a1p + 0x10) = v0v;
    D_80192D98 = a0p;
    D_80192D90 = p8c;
    *p8c = a2v;
    func_80187F24(a0p, a1p, a2v);
    D_80192D98 = s0p;
    D_80192D90 = s1p;
}

extern void D_8018A8F8();

void func_80183824(void) {
    register u32 v0v asm("$2");

    u8 *p98p;
    u8 *a0p;
    func_80185D80();
    func_80185FFC();
    func_80186204();
    func_80184964();
    func_8018659C();
    func_80187510();
    a0p = D_80192D90;
    if (a0p[0] == 0) {
        goto done;
    }
    p98p = D_80192D98;
    if ((p98p[5] & 4) != 0) {
        goto normal;
    }
    if (p98p[0x182] != 0) {
        goto normal;
    }
    v0v = (p98p[0] - 0x80) & 0xFF;
    if (v0v >= 3) {
        goto normal;
    }
    v0v = (p98p[3] + 0x7E) & 0xFF;
    if (v0v < 3) {
        goto normal;
    }
    *(u16 *) (a0p + 0x10) = 2;
    v0v = 1;
    __asm__ volatile(".set\tnoreorder\n\tj D_8018A8F8\n\tsb %0,0x25($4)\n\t.set\treorder" ::"r"(v0v));
normal:
    func_8018430C(a0p);
done:
    return;
}

void func_80183908(void) {
    u8 *p;
    u8 *q;

    if (func_801885B8() != 0) {
        return;
    }
    if (func_80188A84() != 0) {
        return;
    }
    if (*(D_80192D98 + 0x22) < 2) {
        func_8018430C();
    }
    p = D_80192D90;
    *(u16 *) (p + 0x10) = 0x100;
    *(p + 0x25) = 1;
}

extern void func_801875BC();

void func_80183980(void) {
    func_801875BC();
    if (*D_80192D90 != 0) {
        func_80187F24();
    }
}

extern void func_80186DBC();

void func_801839C4(void) {
    func_801875BC();
    if (*D_80192D90 != 0) {
        func_80186DBC();
        func_80187EB4();
    }
}

extern void func_80186D58();

void func_80183A10(void) {
    func_801875BC();
    if (*D_80192D90 != 0) {
        func_80186D58();
    }
}

void func_80183A54(void) {
    func_801875BC();
    if (*D_80192D90 != 0) {
        func_8018783C();
    }
}

void func_80183A98(void) {
    if (func_801885B8() == 0) {
        func_801889A4();
    }
}

void func_80183AC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    if (func_801885B8() == 0) {
        func_801889A4();
    }
}

__asm__(".globl func_80183ACC\nfunc_80183ACC = func_80183AC8 + 0x4");

void func_80183AF8(void) {
    func_801889A4();
}

extern void func_80186EA4();

void func_80183B18(void) {
    if ((func_801885B8() == 0) && (func_80188A24() == 0)) {
        func_80186EA4();
    }
}

void func_80183B58(void) {
    if (func_801885B8() == 0 && func_80188A84() == 0) {
        func_80186EA4();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183B98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183B9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183BA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183BCC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183BF0);

extern void func_80185E94();

void func_80183C44(void) {
    func_80185E94();
    func_80188ADC();
    func_80186568();
}

extern u8 D_80192DA0[];
extern u8 D_80192DC5;
extern u8 D_80192DC2;

void func_80183C74(s32 arg0) {
    u8 *p;

    p = D_80192DA0;
    D_80192D8C = p;
    if (*(u8 *) (arg0 + 0x16F) == 0x12) {
        if (*(u8 *) (arg0 + 0x1BD) & 0x10) {
            *p = 1;
            D_80192DC5 |= 8;
            D_80192DC2 |= 0x10;
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183CDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183D10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183D48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183D60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183D70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183DCC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183DE0);

void func_80183DFC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    func_8018BD74();
    func_8018BD74(D_80192D8C);
    D_80192D8C[0] = 0;
}

__asm__(".globl func_80183E00\nfunc_80183E00 = func_80183DFC + 0x4");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183E3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183E8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183EA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183EA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183EFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183F1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183F2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183F58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183F60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183F78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80183FB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184014);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018401C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184144);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018414C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184204);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184278);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801842DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801842E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801842F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018430C);

extern s8 D_801938D8;

void func_8018433C(s32 arg0, s8 arg1) {
    D_801938D8 = arg1;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018434C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184360);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801843DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801843EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801844DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184610);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801846CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184788);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184868);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184870);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184874);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801848B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801848D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184964);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184A4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184AF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184AF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184AFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184B00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184B24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184B60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184C3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184C40);

extern void func_8005E644(s32, s32);
extern void func_8018BDD4(s32);

void func_80184D74(s32 arg0) {
    s32 s0v;

    s0v = arg0;
    func_8005E644(s0v, 0xE);
    func_8005E644(s0v + 0x10, 0x16);
    func_8005E644(s0v + 0x28, 0x2);
    *(u16 *) (s0v + 0x2A) = 0x64;
    *(u8 *) (s0v + 0x25) = 0;
    *(s8 *) s0v = 1;
    func_8018BDD4(s0v);
}

extern u8 D_80193860[];

void func_80184DD4(s32 arg0) {
    s32 v0;
    s32 v1;

    v1 = 0;
    do {
        v0 = arg0 + v1;
        D_80193860[v1] = 0;
        v1 = v1 + 1;
        *(u8 *) (v0 + 0x1B) = 0;
        *(u8 *) (v0 + 0x20) = 0;
    } while (v1 < 5);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184E08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184E40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184E74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184E98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184F8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80184F9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185104);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801851AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801851C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801852E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185328);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018537C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801853F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801854B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801854FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185588);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185600);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185688);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801856EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185738);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185744);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185758);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185814);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185864);

extern s32 func_8018C968();
extern s32 func_8018C9A0();

void func_80185920(u8 *arg0) {
    u8 *s0v;
    s32 v0;

    s0v = arg0;
    v0 = func_8018C968();
    if (v0 != 0) {
        return;
    }
    v0 = func_8018C9A0(s0v);
    if (v0 != 0) {
        return;
    }
    func_8018130C(s0v);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185968);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185970);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801859D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801859D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801859EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185A9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185AF0);

extern u8 D_801938E5;
extern s32 func_8018C920(void *);
extern void D_8018CC1C(void *, s32);
extern void D_8018CC24();
extern void func_8018CF74(s32, s32);
extern void func_8018CE04(s32, s32);

void func_80185B00(void) {
    register u8 *a0p asm("$4");
    register s32 a1v asm("$5");
    register s32 v0v asm("$2");
    register s32 v1v asm("$3");

    v1v = D_801938E5;
    v0v = 7;
    if (v1v == v0v) {
        goto end;
    }
    a0p = (u8 *) D_80192D98;
    v0v = func_8018C920(a0p);
    if (v0v != 0) {
        goto end;
    }
    a0p = (u8 *) D_80192D98;
    v1v = a0p[0x8B];
    if (v1v & 0x10) {
        a1v = 0x10;
        __asm__ volatile(".set\tnoreorder\n\tj D_8018CC1C\n\tori $4,$zero,0x1a9\n\t.set\treorder" ::"r"(a1v) : "memory");
    }
    __asm__ volatile(".set\tnoreorder\n\tandi $2,%0,8\n\tbeqz $2,1f\n\tandi $2,%0,4\n\tj D_8018CC1C\n\tori $4,$zero,0x1aa\n1:\n\tbeqz $2,2f\n\tori $5,$zero,0x10\n\tj D_8018CC1C\n\tori $4,$zero,0x1ab\n2:\n\t.set\treorder" ::"r"(v1v) : "memory");
    __asm__ volatile(".set\tnoreorder\n\tandi $2,$3,1\n\tbeqz $2,1f\n\tnop\n\tj D_8018CC1C\n\tori $4,$zero,0x1ad\n1:\n\t.set\treorder" ::: "memory");
    v1v = a0p[0x8C];
    __asm__ volatile(".set\tnoreorder\n\tandi $2,%0,0x80\n\tbeqz $2,1f\n\tandi $2,%0,2\n\tjal func_8018CF74\n\tori $4,$zero,0x1ae\n\tj D_8018CC24\n\tnop\n1:\n\tbeqz $2,2f\n\tori $5,$zero,0x10\n\tj D_8018CC1C\n\tori $4,$zero,0x1b4\n2:\n\t.set\treorder" ::"r"(v1v) : "ra", "memory");
    __asm__ volatile(".set\tnoreorder\n\tandi $2,$3,1\n\tbeqz $2,1f\n\tori $5,$zero,0x80\n\tj D_8018CC1C\n\tori $4,$zero,0x1b5\n1:\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tlbu $4,0x8d($4)\n\tandi $2,$4,0x80\n\tbeqz $2,1f\n\tandi $2,$4,8\n\tjal func_8018CF74\n\tori $4,$zero,0x1b6\n\tj D_8018CC24\n\tnop\n1:\n\tbeqz $2,2f\n\tori $4,$zero,0x1ba\n\tj D_8018CC1C\n\tori $5,$zero,0x10\n2:\n\t.set\treorder" ::: "ra", "memory");
    __asm__ volatile(".set\tnoreorder\n\tandi $2,$3,4\n\tbeqz $2,.L80185B00_end\n\tori $4,$zero,0x1b3\n\tori $5,$zero,0x40\n\tjal func_8018CE04\n\tnop\n\t.set\treorder" ::: "ra", "memory");
    __asm__ volatile(".L80185B00_end:");
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185C34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185C74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185C78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185C80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185C94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185CC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185CC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185CD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185D00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185D40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185D80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185D84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185DAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185DD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185DF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185E04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185E30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185E5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185E74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185E90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185E94);

extern s32 func_8018D384(void *);

void func_80185EF4(s16 arg0) {
    if ((*(u8 *) (D_80192D98 + 0x5A) & 1) &&
        (*(u8 *) (D_80192D90 + 0x25) & 0x80) &&
        (func_8018D384(D_80192D98) == 0)) {
        *(u16 *) (D_80192D90 + 0xE) = arg0;
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185F74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185F78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185F80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185FA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80185FFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186054);

void func_80186058(void) {
    register s32 v0 asm("$2");
    register s32 a0v asm("$4");
    register s32 a1v asm("$5");
    register s32 v1 asm("$3");

    v0 &= 0x10;
    if (v0 == 0) {
        return;
    }
    a0v = (s32) D_80192D98;
    v0 = 0x64;
    v1 = *(u8 *) (a0v + 0x24);
    a1v = (s32) D_80192D90;
    v0 = v0 - v1;
    *(u16 *) (a1v + 0x2A) = v0;
    func_8018D384(a0v);
    if (v0 != 0) {
        return;
    }
    v0 = D_8018F5FC;
    if (v0 != 0) {
        return;
    }
    v0 = (s32) D_80192D90;
    *(u8 *) v0 = 0;
    v1 = (s32) D_80192D90;
    v0 = 0xB;
    *(u8 *) (v1 + 2) = v0;
    v1 = (s32) D_80192D90;
    v0 = 0x1C3;
    *(u16 *) (v1 + 0xE) = v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801860E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801860F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018614C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801861A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801861C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186204);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186254);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186298);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801862B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801862CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018631C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186320);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018636C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186370);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018638C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801863C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186460);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186464);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186498);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801864F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186550);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186568);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018659C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801865A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186624);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018668C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801866EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018670C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186730);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186744);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018676C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801867C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186800);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186814);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018681C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186854);

u8 func_80186868(u8 *arg0) {
    s32 v0;
    s32 v1;
    u8 *s0r;
    s0r = arg0;
    if (func_8018DA44() != 0) {
        return 0;
    }
    func_8018DA04(s0r);
    if (s0r[0x188] == 0) {
        goto Lend;
    }
    v1 = (s32) D_80192D98;
    if ((((u8 *) v1)[0x1BD] & 0x10) == 0) {
        goto Lend;
    }
    if (((u8 *) v1)[0x27] == 0) {
        goto Lend;
    }
    v0 = 0x10;
    v1 = (s32) D_80192D90;
    ((u8 *) v1)[0x22] = 0x10;
    v1 = (s32) D_80192D90;
    ((u8 *) v1)[0x25] = 8;
Lend:
    v0 = (s32) D_80192D90;
    return ((u8 *) v0)[0x25];
}

__asm__(".globl .L801868E0\n.L801868E0 = func_80186868 + 0x78");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186910);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018691C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801869EC);

extern void func_8018BD74(u8 *);

void func_80186A04(u8 *arg0) {
    u8 *v1v;

    v1v = arg0 + 0x18C;
    D_80192D98 = arg0;
    D_80192D90 = v1v;
    D_801938C1 = arg0[0x18A];
    func_8018BD74(v1v);
}

s32 func_80186A44(u8 *arg0) {
    s32 v0;

    if (arg0[1] == 0xFF) {
        return 1;
    }
    if ((arg0[0x58] & 0x64) != 0) {
        return 1;
    }
    v0 = arg0[0x59] & 0x81;
    if (v0 != 0) {
        v0 = 1;
    }
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186A88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186AD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186AE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186AF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186B04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186B98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186BB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186BE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186BF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186C04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186CE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186CF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186D44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186D58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186DBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186E28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186EA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186ED0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186F0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186FD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80186FD8);

extern s8 D_8019390D;

void func_80186FF8(void *arg0) {
    s32 sp10;
    s32 a2;
    u8 *s0;
    s32 s1;
    s32 s2;
    s32 a0;
    s32 temp_s1_2;

    s0 = (u8 *) arg0;
    a2 = (s32) &sp10;
    s2 = s0[3];
    s1 = s0[0x18A];
    temp_s1_2 = func_8017EA28(s0, s2, (s32 *) a2);
    a0 = s1;
    s1 = temp_s1_2;
    a2 = s0[0x1BA];
    func_8017EA80(a0, s0[0x1B5], a2 & 0x30, sp10);
    a0 = (s32) s0;
    if (func_8017EA28(a0, s2, &sp10) != s1) {
        D_8019390D = 1;
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018707C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801870FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187148);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187150);

struct Func80187248_Obj {
    u8 pad[0x1AC];
    u8 unk1AC;
    u8 pad2[0xE];
    u8 unk1BB;
};

extern s32 func_8005DB70(void *, s32, s32, void *);
extern s32 func_8005E744(void *);
extern void func_8018E9BC(s32, s32, s32);
extern s8 D_8019389C;

void func_80187248(s32 arg0) {
    s32 temp_v1;
    s32 var_s0;
    register s32 var_v0 asm("v0");
    void *temp_a3;
    u8 *temp_s1;

    temp_s1 = D_801908CC + arg0 * 0x1C0;
    var_s0 = 0;
    do {
        var_v0 = var_s0;
        if (var_s0 < 0) {
            var_v0 = var_s0 + 7;
        }
        var_v0 = var_v0 >> 3;
        temp_v1 = 0x80 >> (var_s0 & 7);
        temp_a3 = (struct Func80187248_Obj *) (temp_s1 + var_v0);
        if (((struct Func80187248_Obj *) temp_a3)->unk1AC & temp_v1) {
            ((struct Func80187248_Obj *) temp_a3)->unk1BB = (u8) (((struct Func80187248_Obj *) temp_a3)->unk1BB & ~temp_v1);
            if (func_8005DB70(temp_s1, var_s0, 1, temp_a3) == 0) {
                func_8018E9BC(var_s0 + 1, 0, arg0);
            }
        }
        var_s0 += 1;
    } while (var_s0 < 0x28);
    func_8005E744(temp_s1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187310);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187340);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187350);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801873D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801873D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018745C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018746C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801874EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187510);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801875AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801875BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801875E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801875FC);

extern s32 D_80193D24;

void func_80187628(void) {
    s32 a0v;
    s32 a1v;

    a0v = (s32) &D_80193D24;
    a1v = (s32) &D_8019389C;
    D_8018F5FC = 0;
    func_8005E254(a0v, a1v, 0x1E);
}

__asm__(".globl func_80187638\nfunc_80187638 = func_80187628 + 0x10");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187660);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187690);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801876A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801876C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801876E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187730);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801877EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_8018783C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187860);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801878AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801878EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187910);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801879B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801879BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801879C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801879C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801879F0);

typedef struct {
    u16 e0;
    u16 e1[5];
} T80187AA0;

extern T80187AA0 D_80062EC0[];
extern void func_8013B644(s32, s32);

s32 func_80187AA0(s32 arg0, s32 arg1, s32 arg2) {
    register s32 flag asm("v0");
    register s32 s0v asm("s0");
    register s32 v1v asm("v0");
    s32 a1v;
    s0v = arg1;
    if (flag != 0) {
        goto fast;
    }
    arg2 = arg2 & 0xFF;
    v1v = ((u8 *) arg0)[5] & 0x30;
    if (v1v == 0) {
        goto slow;
    }
fast:
    __asm__ volatile(".set\tnoreorder\n\tj func_8018EB3C\n\taddu $2,$zero,$zero\n\t.set\treorder");
slow:
    if (arg2 != 0) {
        v1v = D_80062EC0[arg2].e0 >> 2;
        s0v = s0v + v1v;
    }
    func_8013B590(0x2C);
    a1v = v1v + s0v;
    if (0x5F5E0FF < a1v) {
        __asm__ volatile(".set\tnoreorder\n\tlui $5,0x5F5\n\tj func_8018EB30\n\tori $5,$5,0xE0FF\n\t.set\treorder");
    }
    if (a1v < 0) {
        a1v = 0;
    }
    func_8013B644(0x2C, a1v);
    return s0v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187B50);

extern void func_8018E07C();

void func_80187C10(void) {
    D_8018F5FC = 2;
    func_8018E07C();
    D_8018F5FC = 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187C44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187C80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187C98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187CA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187E9C);

s32 func_80187EA0(void) {
    s32 v0v;

    v0v = D_8018F5FC;
    if (v0v != 0) {
        goto ret;
    }
    func_8002230C();
    TAIL_JUMP_NOP(func_8018EEC8);
ret:
    v0v = 0x4000;
    return v0v;
}

__asm__(".globl func_80187EB4\nfunc_80187EB4 = func_80187EA0 + 0x14");

__asm__(".globl func_80187EC4\nfunc_80187EC4 = func_80187EA0 + 0x24");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80187ED8);

void func_80187F24(void) {
    return;
}

void func_80187F2C(void) {
    return;
}

extern void func_8005E22C();
extern void func_8018EFAC();
extern s8 D_8019389D;
extern u8 D_8019389E;
extern u8 D_8019389F;
extern s8 D_801938A0;
extern s16 D_801938A2;
extern s16 D_801938A4;
extern u8 D_801938A6;

void func_80187F34(void *arg0) {
    register u8 *s0 asm("s0");
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    s0 = (u8 *) arg0;
    v1v = s0[3];
    v0v = 0x5D;
    if (v1v == v0v) {
        goto end;
    }
    func_8005E22C(s0 + 0x16E, &D_801938A6);
    v1v = s0[0x178];
    v0v = 6;
    if (v1v != v0v) {
        goto normal;
    }
    v0v = s0[0x179];
    v1v = v0v << 3;
    v1v -= v0v;
    v1v <<= 6;
    v0v = (s32) D_801908CC;
    v1v += v0v;
    a0v = *(u8 *) (v1v + 0x47);
    v1v = *(u8 *) (v1v + 0x48);
    __asm__ volatile(".set\tnoreorder\n\tj func_8018EFAC\n\tnop\n\t.set\treorder" ::"r"(a0v), "r"(v1v) : "memory");
normal:
    __asm__ volatile(".set\tnoreorder\n\tlbu %0,0x17A(%3)\n\tlbu %1,0x17E(%3)\n\tlbu %2,0x47(%3)\n\tnop\n\t.set\treorder" : "=r"(a0v), "=r"(v1v), "=r"(v0v) : "r"(s0) : "memory");
    v0v = a0v - v0v;
    D_801938A2 = v0v;
    v0v = s0[0x48];
    v0v = v1v - v0v;
    D_801938A4 = v0v;
    v0v = *(u16 *) (s0 + 0x48);
    v0v >>= 8;
    v0v &= 0xF;
    D_8019389C = v0v;
    v0v = s0[5];
    v0v &= 0x30;
    D_801938A0 = v0v;
    v0v = s0[0x1D];
    D_8019389E = v0v;
    v1v = s0[0x1F];
    v0v = 1;
    D_8019389D = v0v;
    D_8019389F = v1v;
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80188038);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801881BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801881C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80188268);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80188288);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80188290);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801882B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801882C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801882F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_801883AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_4", func_80188488);

s32 func_801884C0(void) {
}

extern s16 D_8019384A;

s16 func_801884C8(void) {
    return D_8019384A;
}
