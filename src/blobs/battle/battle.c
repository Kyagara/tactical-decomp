#include "common.h"

extern void func_8017FDDC();
extern s32 func_8007A724();
extern s32 D_80096110;

void func_800613D4(void) {
    D_80096110 = 0;
}

extern s32 D_800961B4;
extern s32 D_800961BC;
extern s32 D_800961B8;

void func_800613E4(u8 *arg0) {
    if (arg0 != 0) {
        D_800961B4 = arg0[0x7C];
        D_800961BC = arg0[0x7D];
        D_800961B8 = arg0[0x7E];
    }
}

struct Func80061418_Obj {
    u8 pad[0x134];
    BattleUnit *unk134;
    u8 pad2[0x40];
};

void func_80061418(struct Func80061418_Obj *arg0) {
    extern void func_800683E4(s32);
    register BattleUnit *a0v asm("a0");
    register struct Func80061418_Obj *a1v asm("a1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    a1v = arg0;
    a0v = a1v->unk134;
    v1v = a0v->actionFlag;
    v0v = 5;
    if (v1v != v0v) {
        goto else_path;
    }
    __asm__ volatile(".set\tnoreorder\n\tlh $4,0x17A($4)\n\tlw $2,0x134($5)\n\tlw $3,0x134($5)\n\tlh $2,0x17C($2)\n\tlh $3,0x17E($3)\n\tlui $1,%hi(D_800961B4)\n\tsw $4,%lo(D_800961B4)($1)\n\tlui $1,%hi(D_800961B8)\n\tsw $2,%lo(D_800961B8)($1)\n\tlui $1,%hi(D_800961BC)\n\tsw $3,%lo(D_800961BC)($1)\n\tj func_80068484\n\tnop\n\t.set\treorder");
else_path:
    func_800683E4(func_8007A724(a0v->targetId2, a1v));
}

extern void func_8008F710();
extern u8 D_8009B27C[];

void func_80061494(void) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = 0;
    do {
        if (D_8009B27C[var_s1] != 0) {
            func_8008F710(0xA, 4, 3, var_s0, 0, 0, 0, 0);
            func_8008F710(8, 4, 3, var_s0, 0, 0, 0, 0);
        }
        var_s1 += 8;
        var_s0 += 1;
    } while (var_s0 < 0x10);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80061534);

extern s32 func_8007A6E4(s32);
extern void func_80068534(s32, s32);

void func_80061634(void) {
    register s32 v0 asm("v0");
    register s32 s0r asm("s0");
    s0r = 0;
loop:
    func_8007A6E4(s0r & 0xFFFF);
    func_80068534(v0, 4);
    s0r = s0r + 1;
    v0 = s0r < 0x10;
    if (v0 != 0) {
        goto loop;
    }
}

extern s32 D_80096100;

void func_8006167C(void) {
    s32 v0;
    v0 = D_80096100;
    v0 = v0 + 1;
    D_80096100 = v0;
    if (v0 >= 0x28) {
        D_80096100 = 0;
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800616B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800617E0);

extern void func_800687E0();
extern void func_801ADFEC();
extern u8 D_80063ABE[];

void func_8006194C(u8 *arg0, s32 arg1) {
    u8 buf[0xC8];
    func_800687E0(arg0, buf);
    func_801ADFEC(D_80063ABE[arg0[0x13A] << 3], buf, arg1);
}

extern void func_801ADE7C(s32, s32 *);
extern u8 D_800943C4[];

void func_800619A4(void *arg0) {
    register u8 *s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0v asm("a0");
    s32 sp10[50];

    s0 = (u8 *) arg0;
    __asm__ volatile(".set\tnoreorder\n\tjal func_800687E0\n\taddiu $5,$sp,0x10\n\t.set\treorder");
    v1 = *(u16 *) (s0 + 0x138);
    __asm__ volatile(".set\tnoreorder\n\tori $2,$zero,0x94\n\tbne $3,$2,.L800619A4_not94\n\tori $2,$zero,0x17e\n\t.set\treorder" : "=r"(v0) : "r"(v1));
    __asm__ volatile(".set\tnoreorder\n\tj func_80068A04\n\tori $4,$zero,6\n\t.set\treorder");
not94:
    __asm__ volatile(".L800619A4_not94:");
    a0v = 0x10;
    if (v1 == v0) {
        goto final;
    }
    v0 = *(volatile u16 *) (s0 + 0x138);
    v0 = v0 - 0x170;
    if ((u32) v0 < 0x1A) {
        goto final;
    }
    v0 = s0[0x13B];
    a0v = D_800943C4[v0];
final:
    func_801ADE7C(a0v, sp10);
}

extern void func_801ADD54();

void func_80061A20(s32 *arg0, s32 arg1) {
    extern void func_800687BC();
    u8 buf[0xC8];
    s32 *p;
    func_800687BC(arg0, buf);
    p = (s32 *) arg0[0x4D];
    if (p != 0) {
        func_801ADD54(arg1, *(u8 *) ((u8 *) p + 4), buf);
    }
}

extern void func_80068A20();

void func_80061A74(s32 arg0) {
    func_80068A20(arg0, 0xB);
}

void func_80061A94(s32 arg0) {
    func_80068A20(arg0, 0xC);
}

void func_80061AB4(s32 arg0) {
    func_80068A20(arg0, 0xD);
}

void func_80061AD4(s32 arg0) {
    func_80068A20(arg0, 0xE);
}

void func_80061AF4(s32 arg0) {
    func_80068A20(arg0, 0xF);
}

void func_80061B14(s32 arg0) {
    func_80068A20(arg0, 9);
}

extern void func_80083978();
extern s32 func_8007A1D4();

void func_80061B34(s32 arg0) {
    func_80068A20(arg0, 0x13);
}

s32 func_80061B54(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_8007A6E4(arg0 & 0xFFFF);
    func_80083978(func_8007A1D4(), temp_s0);
    return 1;
}

s32 func_80061B94(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_8007A724(arg0 & 0xFFFF);
    func_80083978(func_8007A1D4(), temp_s0);
    return 1;
}

s32 func_80061BD4(s32 arg0) {
    extern void func_80044A34(s32);
    extern s32 func_800803E4(s32);
    extern void func_80068C08();
    register s32 v0v asm("v0");

    v0v = func_8007A6E4(arg0 & 0xFFFF);
    if (v0v == 0) {
        func_80044A34(0xC);
        __asm__ volatile(".set\tnoreorder\n\tj func_80068C08\n\taddu $2,$zero,$zero\n\t.set\treorder");
    }
    func_800803E4(v0v);
    return 1;
}

extern void func_80082620();
extern void func_80068BD4();
extern void func_8006894C();

void func_80061C18(s32 a0, s32 a1) {
    s32 s0;
    s32 s1;

    s0 = a0;
    s1 = a1;
    if (s0 == 0 || s1 == 0) {
        return;
    }
    func_80082620(s0, 1);
    func_80083978(s0, s1);
    func_80068BD4(*(u8 *) (s1 + 4));
    func_8006894C(s0, 1);
}

extern void func_80068C18();

void func_80061C80(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = func_8007A724(arg0 & 0xFFFF);
    func_80068C18(temp_s0, func_8007A724(arg1 & 0xFFFF));
}

extern u8 *func_80183FB4();

void func_80061CC4(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = func_8007A6E4(arg0 & 0xFFFF);
    func_80068C18(temp_s0, func_8007A6E4(arg1 & 0xFFFF));
}

extern void func_80082EEC();
extern void func_80081B88();
extern void func_80082550();
extern void func_80082508();
extern void func_80068DC4();
extern void func_80082468();
extern void func_8008346C();
extern void func_800831B8();
extern void func_80083570();
extern void func_8008258C();

void func_80061D08(void *arg0) {
    extern s32 D_8009612C;
    register u8 *s0 asm("s0");
    register u8 *s1 asm("s1");
    register s32 a0v asm("$4");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    s0 = (u8 *) arg0;
    if (s0 == 0) {
        goto end;
    }
    s1 = func_80183FB4(s0[0x7C], s0[0x7D], s0[0x7E]);
    a0v = (s32) s0;
    v1v = *(u32 *) (s0 + 0x150);
    a1v = *(u32 *) (s0 + 0x140);
    a2v = *(u32 *) (s0 + 0x148);
    a3v = *(u32 *) (s0 + 0x14C);
    v1v = ~v1v & a1v;
    *(u32 *) (s0 + 0x140) = v1v;
    v1v = *(u32 *) (s0 + 0x154);
    a1v = *(u32 *) (s0 + 0x144);
    v1v = ~v1v & a1v;
    KEEP(v1v);
    *(u32 *) (s0 + 0x144) = v1v;
    v1v = *(u32 *) (s0 + 0x140);
    a1v = *(u32 *) (s0 + 0x144);
    v1v |= a2v;
    a1v |= a3v;
    *(u32 *) (s0 + 0x140) = v1v;
    *(u32 *) (s0 + 0x144) = a1v;
    func_80081B88((void *) a0v, a1v, a2v, a3v);
    func_80082550(s0);
    func_80082508(s0);
    if (D_8009612C != 0) {
        a1v = s1[6];
        a2v = 0;
        __asm__ volatile(".set\tnoreorder\n\tj func_80068DC4\n\taddu $4,$16,$zero\n\t.set\treorder" ::"r"(s0), "r"(a1v), "r"(a2v) : "memory");
    }
    a1v = s1[6];
    a2v = 1;
    a1v >>= 2;
    a1v &= 3;
    func_80082468(s0, a1v, a2v);
    func_8008346C(s0);
    func_80082EEC(s0);
    func_800831B8(s0);
    a1v = s1[6];
    a1v >>= 2;
    a1v &= 3;
    func_80083570(s0, a1v);
    func_8008258C(s0);
    *(u32 *) (s0 + 0x154) = 0;
    *(u32 *) (s0 + 0x150) = 0;
    *(u32 *) (s0 + 0x14C) = 0;
    *(u32 *) (s0 + 0x148) = 0;
    *(u8 *) (s0 + 0x2D0) = 0;
end:
    return;
}

extern void func_80068D08();

void func_80061E30(s32 arg0) {
    func_80068D08(func_8007A6E4(arg0 & 0xFFFF));
}

void func_80061E58(s32 arg0) {
    func_80068D08(func_8007A724(arg0 & 0xFFFF));
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80061E80);

extern void func_80083758();

void func_800620F8(s32 arg0, s32 arg1) {
    func_80083758(arg0, func_8007A724(arg1 & 0xFFFF));
}

extern void func_80068E30();

void func_80062130(u8 *arg0, u8 *arg1) {
    typedef struct {
        char c[8];
    } W;
    typedef struct {
        int e[4];
    } T4;
    register s32 v1 asm("v1");

    s32 v0;
    arg0[0x130] = 1;
    arg0[0x131] = arg1[4];
    arg1[0x130] = 2;
    arg1[0x131] = arg0[4];
    *(u16 *) (arg0 + 0x70) = *(u16 *) (arg1 + 0x70);
    *(u16 *) (arg0 + 0x6C) = *(u16 *) (arg1 + 0x6C);
    *(u16 *) (arg0 + 0x6E) = *(u16 *) (arg1 + 0x6E);
    *(W *) (arg0 + 0x40) = *(W *) (arg1 + 0x40);
    v0 = *(u16 *) (arg0 + 0x42);
    v0 = v0 - 0xA;
    *(u16 *) (arg0 + 0x42) = v0;
    *(T4 *) (arg0 + 0x18) = *(T4 *) (arg1 + 0x18);
    v0 = *(s32 *) (arg0 + 0x1C);
    v1 = 0xFFFF6000;
    arg0[0x11E] = 0;
    v0 = v0 + v1;
    *(s32 *) (arg0 + 0x1C) = v0;
    v0 = arg1[0x7C];
    arg0[0x7C] = v0;
    v0 = arg1[0x7D];
    arg0[0x7D] = v0;
    v0 = *(s32 *) (arg0 + 0x140);
    v1 = arg1[0x7E];
    v0 = v0 | 2;
    *(s32 *) (arg0 + 0x140) = v0;
    arg0[0x7E] = v1;
    func_80082EEC(arg0);
    *(u16 *) (arg0 + 0x1DE) = *(u16 *) (arg1 + 0x1DE);
    func_80068E30(arg0[4]);
    func_80068E30(arg1[4]);
}

void func_80062254(u8 *arg0) {
    s32 v0;
    s32 v1;
    if (arg0[0x130] != 1)
        return;
    v0 = func_8007A6E4(arg0[0x131]);
    v1 = *(s32 *) (arg0 + 0x140) & -3;
    arg0[0x11E] = 0;
    arg0[0x130] = 0;
    arg0[0x131] = 0;
    *(s32 *) (arg0 + 0x140) = v1;
    if (v0 != 0) {
        ((u8 *) v0)[0x130] = 0;
        ((u8 *) v0)[0x131] = 0;
    }
}

void func_800622BC(u8 *arg0) {
    s32 v0;
    s32 v1;
    if (arg0[0x130] != 1)
        return;
    v0 = func_8007A6E4(arg0[0x131]);
    arg0[0x11E] = 0;
    arg0[0x130] = 0;
    arg0[0x131] = 0;
    v1 = *(s32 *) (arg0 + 0x140) & -3;
    *(s32 *) (arg0 + 0x140) = v1;
    func_80068E30(arg0[4], -3);
    if (v0 != 0) {
        ((u8 *) v0)[0x130] = 0;
        ((u8 *) v0)[0x131] = 0;
        func_80068E30(((u8 *) v0)[4]);
    }
}

s32 func_8006233C(s32 arg0, s32 arg1, s32 arg2) {
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");

    s0v = arg0;
    s1v = arg1;
    s2v = arg2;
    v0v = (s32) func_80183FB4(arg0, arg1, arg2);
    a0v = s0v;
    a1v = s1v;
    a2v = s2v ^ 1;
    s0v = v0v;
    a0v = (s32) func_80183FB4(a0v, a1v, a2v);
    v0v = *(u8 *) ((u8 *) a0v + 6) & 1;
    if (v0v) {
        v0v = 0x40;
    } else {
        v1v = *(u8 *) ((u8 *) s0v + 2);
        v0v = *(u8 *) ((u8 *) s0v + 3);
        v0v = v0v >> 5;
        v1v = v1v + v0v;
        v0v = *(u8 *) ((u8 *) a0v + 3);
        a1v = *(u8 *) ((u8 *) a0v + 2);
        v0v = v0v >> 5;
        v0v = a1v + v0v;
        v0v = v1v < v0v;
        if (!v0v) {
            goto set64;
        }
        v1v = v1v + 3;
        v0v = *(u8 *) ((u8 *) a0v + 5);
        v0v = v0v & 0x1F;
        v0v = a1v - v0v;
        v0v = v0v - v1v;
        KEEP(v0v);
        __asm__ volatile(".set\tnoreorder\n\tj func_800693D8\n\tsll $2,$2,1\n\t.set\treorder");
    }
set64:
    v0v = 0x40;
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800623F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800624D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80062744);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800629F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80062AF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80062BF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80062CFC);

extern void func_80081978(s32, s32, s32);

void func_80062E68(s32 arg0) {
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");

    s0v = arg0;
    v0v = 0x3C;
    a0v = 0x3C;
    KEEP(s0v);
    *(u8 *) ((u8 *) s0v + 0x7F) = v0v;
    a1v = ((s16 *) s0v)[0x38];
    a2v = s0v;
    func_80081978(a0v, a1v, a2v);
    v1v = ((u8 *) s0v)[0x9C];
    KEEP(v1v);
    v0v = 0xFE;
    if (v1v != v0v) {
        goto B;
    }
    v0v = ((u8 *) s0v)[0x9D];
    v1v = ((u8 *) s0v)[0x9E];
    a0v = ((u8 *) s0v)[0x9F];
    USE(v0v);
    USE(v1v);
    USE(a0v);
    __asm__ volatile(".set\tnoreorder\n\tj .L80069EC4\n\tsb $2,0x80($16)\n\t.set\treorder");
B:
    v0v = ((u8 *) s0v)[0x7C];
    v1v = ((u8 *) s0v)[0x7D];
    a0v = ((u8 *) s0v)[0x7E];
    *(u8 *) ((u8 *) s0v + 0x80) = v0v;
    *(u8 *) ((u8 *) s0v + 0x81) = v1v;
    *(u8 *) ((u8 *) s0v + 0x82) = a0v;
}

__asm__(".globl D_80062EB8\nD_80062EB8 = func_80062E68 + 0x50");

__asm__(".globl D_80062EBC\nD_80062EBC = func_80062E68 + 0x54");

__asm__(".globl D_80062EC0\nD_80062EC0 = func_80062E68 + 0x58");

void func_80062EE0(s32 arg0) {
    extern void func_800687BC();
    u8 buf[0xC8];
    func_800687BC(arg0, buf);
    *(u8 *) (arg0 + 0x7F) = 0x3B;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80062F14);

extern void func_80069DFC();
extern void func_80069254();
extern void func_8006A180();
extern void func_8006A17C();
extern void func_8006A178();
extern void func_800694D8();

void func_80063080(void *arg0) {
    extern s32 func_8007A6E4();
    extern void func_80081978();
    register u8 *s0 asm("s0");
    register s32 s1v asm("s1");
    register u8 *s2 asm("s2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    s0 = (u8 *) arg0;
    func_80069254();
    v0v = s0[0x11C];
    v1v = v0v >> 6;
    s2 = s0 + 0x11C;
    if (v1v == 1) {
        goto mode1;
    }
    v0v = v1v < 2;
    if (v0v == 0) {
        goto mode2_or_3;
    }
    __asm__ volatile(".set\tnoreorder\n\tbeqz $3,.L80063080_mode0\n\tori $2,$zero,0x24\n\tj func_8006A180\n\tori $4,$zero,0x12\n\t.set\treorder" ::: "memory");
mode2_or_3:
    __asm__ volatile(".set\tnoreorder\n\tori $2,$zero,2\n\tbeq $3,$2,.L80063080_mode2\n\tori $2,$zero,3\n\tbeq $3,$2,.L80063080_mode3\n\tori $2,$zero,0x26\n\tj func_8006A180\n\tori $4,$zero,0x12\n\t.set\treorder" ::: "memory");
mode0:
    __asm__ volatile(".L80063080_mode0:");
    __asm__ volatile("ori $17,$zero,0xc00");
    v1v = s0[0x7C];
    *(u8 *) (s0 + 0x7F) = v0v;
    v0v = s0[0x11C];
    v1v += 1;
    v0v &= 3;
    v1v += v0v;
    __asm__ volatile(".set\tnoreorder\n\tj func_8006A17C\n\tsb $3,0x80($16)\n\t.set\treorder" ::"r"(v1v) : "memory");
mode1:
    __asm__ volatile("ori $17,$zero,0x400");
    v1v = s0[0x7C];
    v0v = 0x28;
    *(u8 *) (s0 + 0x7F) = v0v;
    v0v = s0[0x11C];
    v1v += 0xFF;
    v0v &= 3;
    v1v -= v0v;
    __asm__ volatile(".set\tnoreorder\n\tj func_8006A17C\n\tsb $3,0x80($16)\n\t.set\treorder" ::"r"(v1v) : "memory");
mode2:
    __asm__ volatile(".L80063080_mode2:");
    __asm__ volatile("move $17,$zero");
    v1v = s0[0x7D];
    v0v = 0x22;
    *(u8 *) (s0 + 0x7F) = v0v;
    v0v = s0[0x11C];
    v1v += 0xFF;
    v0v &= 3;
    __asm__ volatile(".set\tnoreorder\n\tj func_8006A178\n\tsubu $3,$3,$2\n\t.set\treorder" ::"r"(v1v), "r"(v0v) : "memory");
mode3:
    __asm__ volatile(".L80063080_mode3:");
    __asm__ volatile("ori $17,$zero,0x800");
    v1v = s0[0x7D];
    *(u8 *) (s0 + 0x7F) = v0v;
    v0v = s0[0x11C];
    v1v += 1;
    v0v &= 3;
    v1v += v0v;
    *(u8 *) (s0 + 0x81) = v1v;
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,0x12\n\taddu $5,$17,$zero\n\tjal func_80081978\n\taddu $6,$16,$zero\n\t.set\treorder" ::"r"(s1v) : "ra", "memory");
    v1v = s0[0x130];
    v0v = 2;
    if (v1v != v0v) {
        goto after_lookup;
    }
    v0v = func_8007A6E4(s0[0x131]);
    if (v0v != 0) {
        func_80081978(0x32, *(s16 *) (s0 + 0x70), v0v);
    }
after_lookup:
    func_800694D8(s0, s0 + 0x9C, s2);
    func_80069DFC(s0, *(s32 *) (s0 + 0x38));
    v0v = s2[0] >> 5;
    *(u8 *) (s0 + 0x82) = v0v & 1;
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006320C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80063380);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80063538);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800637C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80063A80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80063D18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80063F7C);

void func_80064960(s32 *arg0, s32 arg1) {
    extern void func_80044018();
    if ((arg0[0x20] & 0x2000000) == 0) {
        func_80044018(arg1);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80064994);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80064A38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80064AD8);

extern void func_80081B0C();

void func_80064BFC(void *arg0) {
    extern void func_800683E4();
    extern s32 func_8007A6E4();
    extern s16 func_8007D3F4();
    void *temp_a0;
    s32 var_v0;
    void *temp_v0;
    s32 temp_v1;
    u32 var_v0_2;

    temp_a0 = *(void **) ((u8 *) arg0 + 0x134);
    if (temp_a0 == NULL) {
        goto end;
    }
    var_v0 = *(s16 *) ((u8 *) arg0 + 0x70);
    func_8017FDDC(*((u8 *) temp_a0 + 0x18A), ((u8 *) arg0)[0x7C], ((u8 *) arg0)[0x7D], ((u8 *) arg0)[0x7E], (((u32) (var_v0 < 0 ? var_v0 + 0x3FF : var_v0)) >> 10) & 0xFF);
    if (((u8 *) arg0)[0x130] == 0) {
        goto end;
    }
    temp_v0 = (void *) func_8007A6E4(((u8 *) arg0)[4]);
    if (*(void **) ((u8 *) arg0 + 0x134) == NULL) {
        goto end;
    }
    temp_v1 = *(s16 *) ((u8 *) arg0 + 0x70);
    func_8017FDDC(*((u8 *) (*(void **) ((u8 *) temp_v0 + 0x134)) + 0x18A), ((u8 *) arg0)[0x7C], ((u8 *) arg0)[0x7D], ((u8 *) arg0)[0x7E], (((u32) (temp_v1 < 0 ? temp_v1 + 0x3FF : temp_v1)) >> 10) & 0xFF);
end:
    func_80081B0C(arg0);
    func_8007D3F4(arg0);
    func_800683E4(arg0);
    ((u8 *) arg0)[0x9C] = 0;
    func_80082EEC(arg0);
}

extern s32 func_8006BBFC();
extern void func_80069130(s32, s32);
extern void func_8006B960(s32, s32);
extern s32 func_8007A4F4(s32, s32, s32);
extern void func_8006BCE8();

__asm__(".globl L8006BD8C\nL8006BD8C = func_8006BCE8 + 0xA4");

__asm__(".globl L8006BD94\nL8006BD94 = func_8006BCE8 + 0xAC");

void func_80064CE4(s32 arg0) {
    register s32 s0r asm("s0");
    register s32 a0v asm("a0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s0r = arg0;
    func_8006BBFC(s0r);
    a0v = *(u8 *) (s0r + 0x11B);
    v0 = a0v & 0x80;
    if (v0 != 0) {
        v0 = func_8007A724(a0v & 0x7F);
        if (v0 == 0) {
            return;
        }
        func_80069130(s0r, v0);
        func_8006B960(s0r, 0x29);
        TAIL_JUMP_NOP(L8006BD94);
    }
    v0 = func_8007A4F4(*(u8 *) (s0r + 0x7C), *(u8 *) (s0r + 0x7D), *(u8 *) (s0r + 0x7E));
    if (v0 != 0) {
        a0v = s0r;
        if (v0 == s0r) {
            return;
        }
        __asm__ volatile(".set\tnoreorder\n\tj L8006BD8C\n\taddu $5,%1,$zero\n\t.set\treorder" : : "r"(a0v), "r"(v0));
    }
    v1 = *(u8 *) (s0r + 0x130);
    if (v1 != 2) {
        return;
    }
    v0 = func_8007A6E4(*(u8 *) (s0r + 0x131));
    a0v = v0;
    if (v0 == 0) {
        return;
    }
    __asm__ volatile(".set\tnoreorder\n\taddu $5,%0,$zero\n\tjal func_80069130\n\tnop\n\t.set\treorder" : : "r"(s0r), "r"(a0v) : "a0", "a1", "a2", "a3", "v0", "v1",
                                                                                                                                 "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "memory");
}

extern s32 func_8006C2BC();
extern u8 *D_80096220;
extern u8 *D_80096224;
extern s32 D_80096240;
extern void func_8006BE54();

void func_80064DA8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 func_8007D3F4(void *);
    u8 *s0;
    s32 v0v;
    s32 v1v;

    s0 = (u8 *) arg0;
    v0v = *(u32 *) (s0 + 0x140);
    v0v &= 4;
    if (v0v != 0) {
        goto end;
    }
    v0v = *(u32 *) (s0 + 0x144);
    v0v &= 0x49;
    if (v0v != 0) {
        goto end;
    }
    v1v = D_80096240;
    v0v = 1;
    if (v1v == v0v) {
        goto mode1;
    }
    v0v = v1v < 2;
    if (v0v == 0) {
        goto mode2_or_3;
    }
    if (v1v == 0) {
        v0v = arg2 - arg3;
        goto mode0_common;
    }
    v0v = arg2 - arg3;
    TAIL_JUMP_NOP(func_8006BE54);
mode2_or_3:
    v0v = 2;
    if (v1v == v0v) {
        v0v = 3;
        goto mode2;
    }
    v0v = 3;
    if (v1v == v0v) {
        v0v = arg1 - arg3;
        goto mode3;
    }
    v0v = arg1 - arg3;
    TAIL_JUMP_NOP(func_8006BE54);
mode2:
    v0v = arg2 + arg3;
mode0_common:
    *(u16 *) (s0 + 0x44) = v0v;
    v0v = (s32) (v0v << 16) >> 4;
    __asm__ volatile(".set\tnoreorder\n\tj func_8006BE54\n\tsw %0,0x20(%1)\n\t.set\treorder" ::"r"(v0v), "r"(s0));
mode1:
    v0v = arg1 + arg3;
mode3:
    *(u16 *) (s0 + 0x40) = v0v;
    v0v = (s32) (v0v << 16) >> 4;
    *(s32 *) (s0 + 0x18) = v0v;
    SCHED_BARRIER();
    v0v = func_8007D3F4(s0);
    *(u16 *) (s0 + 0x42) = v0v;
    v0v = v0v << 16;
    v1v = *(u8 *) (s0 + 0x299);
    v0v = v0v >> 4;
    *(s32 *) (s0 + 0x1C) = v0v;
    v1v |= 1;
    *(u8 *) (s0 + 0x299) = v1v;
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80064E8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80065024);

extern void func_8006A20C();
extern void func_8006A380();
extern void func_8006C3C0();
extern u8 D_80093CA0[];
extern u8 D_80093C9C[];
extern u8 D_8009621C;

void func_80065320(void *arg0) {
    u8 *s0;
    s32 s1;
    s32 v1;

    s0 = (u8 *) arg0;
    s1 = func_8006C2BC();
    v1 = ((u8) D_8009621C >> 3) & 1;
    if (v1 != 0) {
        if (v1 == 1) {
            goto one;
        }
        TAIL_JUMP_NOP(func_8006C3C0);
    }
zero:
    func_8006A20C(s0, D_80096220, D_80096224);
    __asm__ volatile(".set\tnoreorder\n\tlui $1,%%hi(D_80093C9C)\n\taddu $1,$1,%0\n\tlbu $2,%%lo(D_80093C9C)($1)\n\tj func_8006C3C0\n\tsb $2,0x7f(%1)\n\t.set\treorder" : : "r"(s1), "r"(s0));
one:
    func_8006A380(s0, D_80096220, D_80096224);
    s0[0x7F] = D_80093CA0[s1];
end:
}

extern void func_8006C320();

void func_800653D8(u8 *arg0) {
    register s32 v1 asm("$3");

    u32 v0;
    v0 = *(u16 *) (arg0 + 0x1DC);
    v1 = 0x20;
    v0 >>= 1;
    if (v0 != v1) {
        goto call;
    }
    v0 = *(u16 *) (arg0 + 0x1E2);
    if (v0 != 0) {
        return;
    }
call:
    func_8006C320();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006541C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800654F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80065790);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80065AD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80065C94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80066060);

extern void func_8006AF7C();
extern s32 D_800960E4;
extern void func_8006BE8C();
extern s32 func_8006C878();
extern void func_8006CA3C();
extern s16 D_80096228;

void func_800661A0(void *arg0) {
    extern s16 func_8007D3F4();
    s16 temp_v0;
    s32 temp_s1;
    s32 var_v0;

    temp_s1 = func_8006C2BC();
    func_8006AF7C(arg0);
    if (D_800960E4 != 0x34) {
        func_8006BE8C(arg0, temp_s1);
    }
    if (func_8006C878(temp_s1, arg0) != 0) {
        func_8006CA3C(temp_s1, arg0);
        *(s32 *) ((u8 *) arg0 + 0x30) = 0;
        *(s32 *) ((u8 *) arg0 + 0x28) = 0;
        temp_v0 = func_8007D3F4(arg0);
        D_80096228 = temp_v0;
        if (*(s16 *) ((u8 *) arg0 + 0x42) >= temp_v0) {
            ((u8 *) arg0)[0x7C] = ((u8 *) arg0)[0x80];
            ((u8 *) arg0)[0x7D] = ((u8 *) arg0)[0x81];
            var_v0 = D_80096228;
            *(s32 *) ((u8 *) arg0 + 0x2C) = 0;
            var_v0 <<= 12;
            *(s32 *) ((u8 *) arg0 + 0x1C) = var_v0;
            if (var_v0 < 0) {
                var_v0 += 0xFFF;
            }
            *(s16 *) ((u8 *) arg0 + 0x42) = var_v0 >> 12;
            ((u8 *) arg0)[0x7F] = 0;
            ((u8 *) arg0)[0x299] |= 1;
        }
    }
}

extern s32 func_8006C024();
extern s32 func_8006C41C();
extern s32 func_80069F14();
extern u8 D_80093C98[];

void func_80066288(void *arg0) {
    extern s16 func_8007D3F4();
    s16 temp_v0;
    s32 temp_s1;
    s32 temp_v1;
    s32 temp_v2;

    temp_s1 = func_8006C2BC();
    func_8006AF7C(arg0);
    if (D_800960E4 != 0x34) {
        func_8006C024(arg0, temp_s1);
    }
    if (func_8006C41C(temp_s1, arg0) != 0) {
        *(s32 *) ((u8 *) arg0 + 0x30) = 0;
        *(s32 *) ((u8 *) arg0 + 0x28) = 0;
        temp_v0 = func_8007D3F4(arg0);
        if (*(s16 *) ((u8 *) arg0 + 0x42) >= temp_v0) {
            temp_v1 = D_80096220;
            temp_v2 = D_80096224;
            *(s32 *) ((u8 *) arg0 + 0x2C) = 0;
            func_80069F14(arg0, temp_v1, temp_v2);
            ((u8 *) arg0)[0x7F] = D_80093C98[temp_s1];
        }
    }
}

extern s32 func_8006CBB8();
extern void func_8006C94C();
extern void func_80069744();
extern u8 D_80096230;
extern u8 D_8009622C;

void func_80066344(void *arg0) {
    s32 temp_s1;

    temp_s1 = func_8006C2BC();
    func_8006AF7C(arg0);
    if (func_8006CBB8(temp_s1, arg0) != 0) {
        func_8006C94C(temp_s1, arg0);
        D_80096230 = D_80096220[2] * 2 + (D_80096220[3] & 0x1F) * ((u8 *) arg0)[0x97];
        ((u8 *) arg0)[0x11E] = 0;
        D_8009622C = D_80096224[2] * 2 + (D_80096224[3] & 0x1F) * ((u8 *) arg0)[0x96];
        func_80069744(arg0, (u8 *) arg0 + 0x9C, (u8 *) arg0 + 0x11C);
        func_80069DFC(arg0, *(void **) ((u8 *) arg0 + 0x38));
        ((u8 *) arg0)[0x7F] = 0x27;
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80066434);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80066598);

extern void func_80069E68();

void func_800667C4(void) {
    func_80069E68();
}

void func_800667E4(u8 *arg0) {
    s32 v0;
    s32 v1;
    u8 *p;
    if (arg0[0x11B] == 0) {
        return;
    }
    v1 = *(s32 *) (arg0 + 0x98);
    p = arg0 + v1;
    v0 = p[0x9D];
    v0 = v0 | 0x10;
    p[0x9D] = v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80066818);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80066B10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80066C8C);

extern void func_8006DC8C();

void func_80066DAC(u8 *arg0, u8 *arg1) {
    s32 v0;

    v0 = arg0[0x1A8];
    arg1[0x80] = v0;
    v0 = arg0[0x1A9];
    arg1[0x81] = v0;
    v0 = arg0[0x1AA];
    arg1[0x82] = v0;
    func_8006DC8C(arg1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80066DEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80067574);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800675D8);

void func_8006764C(void) {
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register u8 *p asm("v0");
    register u8 *s0v asm("s0");
    s32 t;
    func_8007A2B8();
    __asm__ volatile(".set\tnoreorder\n\tjal func_8007A218\n\taddu $16,$2,$zero\n\t.set\treorder" : "=r"(s0v) : : "ra", "$2", "$3", "$4", "$5", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    a0v = 5;
    if (s0v != 0) {
        v0 = *(s32 *) (p + 0x134);
        v1 = *(s32 *) (s0v + 0x134);
        __asm__ volatile(".set\tnoreorder\n\tlbu $5,0x18A(%1)\n\tlbu $6,0x18A(%2)\n\tj func_8006E694\n\tnop\n\t.set\treorder" : : "r"(a0v), "r"(v0), "r"(v1) : "memory");
    }
    t = *(s32 *) (p + 0x134);
    __asm__ volatile("ori $4,$0,2" : "=r"(a0v)::"memory");
    a1v = *(u8 *) (t + 0x18A);
    __asm__ volatile("ori $6,$0,255" : "=r"(a2v)::"memory");
    __asm__ volatile(".set\tnoreorder\n\tjal func_8013D634\n\tnop\n\t.set\treorder" : : "r"(a0v), "r"(a1v), "r"(a2v) : "ra", "memory");
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800676B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800677D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80067F08);

extern s32 D_800960C8;
extern s32 D_800E4E88;
extern void func_8006F13C();

void func_80068174(void) {
    s32 v0;
    v0 = 1;
    D_800960C8 = v0;
    D_800E4E88 = v0;
    func_8006F13C();
}

extern s16 D_800A7786;
extern s32 D_800C7C60;
extern s32 D_800B6694;

void func_800681A8(s32 arg0) {
    s32 v0;
    v0 = D_800A7786;
    D_800C7C60 = arg0;
    v0 = v0 & 0xFE00;
    D_800B6694 = v0;
    v0 = arg0 & 0x3FF;
    if (v0 == 0) {
        v0 = arg0 - 0x200;
        D_800C7C60 = v0;
    }
}

extern void func_8006F1A8();
extern s32 D_8004594C;

void func_800681E0(void) {
    D_800960C8 = 2;
    D_800E4E88 = 1;
    func_8006F1A8();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068218);

extern void func_8006F174();
extern void func_80044018();
extern void func_8006F1E0();
extern s32 D_800960CC;
extern void func_800683C0();
extern void func_80068494();

void func_80068294(void) {
    s32 flag;
    if (flag == 0) {
        if ((D_8004594C & 4) != 0) {
            func_8006F174((D_800A7786 & 0xFE00) - 0x400);
            func_80044018(0xB);
        }
        if ((D_8004594C & 8) != 0) {
            func_8006F1E0((D_800A7786 & 0xFE00) + 0x400);
            func_80044018(0xC);
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068320);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800683C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800683D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800683E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068418);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006844C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006846C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068484);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068494);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800684B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068534);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068540);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800685AC);

extern s32 D_800960D0;
extern s32 D_800C7C64;

s32 func_800685BC(void) {
    register s32 v1 asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1") = 1;
    register s32 v0 asm("v0");
    v1 = D_800960D0;
    if (v1 != a1v) {
        goto Lcont;
    }
    v0 = 4;
    D_800960CC = v0;
    D_800960D0 = v0;
    __asm__ volatile(".set\tnoreorder\n\tj func_8006F610\n\tori $4,$0,0x11\n\t.set\treorder");
Lcont:
    v0 = 4;
    __asm__ volatile(".set\tnoreorder\n\tbne %1,%2,1f\n\tori $4,$0,14\n\t.set\treorder" : "=r"(a0v) : "r"(v1), "r"(v0) : "memory");
    v0 = 2;
    D_800960D0 = a1v;
    D_800960CC = v0;
    func_80043FF8();
    v0 = 4;
    __asm__ volatile("1:" ::: "memory");
    D_800C7C64 = v0;
    return v0;
}

__asm__(".globl .L800685FC\n.L800685FC = func_800685BC + 0x40");

__asm__(".globl .L80068618\n.L80068618 = func_800685BC + 0x5C");

__asm__(".globl .L8006861C\n.L8006861C = func_800685BC + 0x60");

extern void func_8006F5BC();

void func_80068634(void) {
    s32 v0;
    s32 v1;

    v0 = D_800960CC;
    if (v0 == 0) {
        v1 = D_8004594C;
        v1 &= 1;
        if (v1 != 0) {
            func_8006F5BC();
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068678);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006867C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800686B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800686C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068748);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068768);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068794);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068798);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800687A4);

extern s32 D_80045980;

void func_800687BC(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800687C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800687E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800687E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068854);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800688C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800688E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006892C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006894C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068970);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800689A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068A04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068A20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068A74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068A94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068AB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068AD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068AF4);

extern s32 D_800E4E84;

void func_80068B14(void) {
    s32 v0;
    s32 v1;
    v1 = D_800E4E84;
    if (v1 < 0x30) {
        v0 = D_80045980;
        v0 = v0 * 2 + v1;
        D_800E4E84 = v0;
    }
}

__asm__(".globl func_80068B34\nfunc_80068B34 = func_80068B14 + 0x20");

__asm__(".globl .L80068B48\n.L80068B48 = func_80068B14 + 0x34");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068B50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068B54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068BD4);

extern void func_8006FB50();
extern s32 D_800A1C48;
extern s32 D_800A1C4C;
extern s32 D_800A1C50;

void func_80068C08(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 *p asm("v1");

    func_8006FB50();
    p = &D_800A1C48;
    v0v = *p;
    v0v = v0v << 1;
    *p = v0v;
    v0v = D_800A1C4C;
    v1v = D_800A1C50;
    v0v = v0v << 1;
    v1v = v1v << 1;
    D_800A1C4C = v0v;
    D_800A1C50 = v1v;
}

__asm__(".globl func_80068C18\nfunc_80068C18 = func_80068C08 + 0x10");

DEAD_TAIL_LW(4, D_800961B4);
DEAD_TAIL_LW(5, D_800961BC);
DEAD_TAIL_LW(6, D_800961B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068C80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068CC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068D08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068DC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068DF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068E30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068E80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80068F74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069094);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800690D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800690DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069130);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069254);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800692BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800692E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006933C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069368);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800693B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800693D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800693F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800694B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800694D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800695F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069648);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069664);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069668);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069744);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069750);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800697B4);

extern void func_8006D818();

void func_800697C4(void) {
    extern s32 func_8007A6E4(s32);
    register s32 v asm("a0");
    s32 i = 0;
    do {
        v = func_8007A6E4(i & 0xFFFF);
        i++;
        if (v != 0) {
            if (*(u8 *) (v + 0x9C) != 0) {
                func_8006D818(v);
            }
        }
    } while (i < 0x10);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069820);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069860);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800698C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069934);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069998);

void func_800699F4(void) {
}

extern void func_80070998();
extern void func_801419B8();

void func_800699FC(void) {
    func_80070998();
    func_801419B8(8, 0, 0xFF, 0, 1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069A38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069A94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069A98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069AF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069B14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069B18);

__asm__(".globl .L80069B98\n.L80069B98 = func_80069B7C + 0x1C");

__asm__(".globl .L80069B94\n.L80069B94 = func_80069B7C + 0x18");

void func_80069B7C(u8 *arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    register s32 v1 asm("v1");
    register u8 *q asm("v1");
    u8 b;
    s32 v0;
    v0 = *(volatile s32 *) (arg0 + 0x134);
    v1 = ((u8 *) v0)[5];
    v0 = *(volatile s32 *) (arg0 + 0x134);
    arg0[0x13D] = v1;
    v0 = ((u8 *) v0)[0x1B8];
    if (v0 != 0) {
        v0 = v1 & 0xF7;
        arg0[0x13D] = v0;
    }
    if (arg0[0x130] != 0) {
        b = arg0[0x131];
        q = (u8 *) func_8007A6E4(b);
        v0 = *(volatile s32 *) (q + 0x134);
        b = ((u8 *) v0)[5];
        v0 = *(volatile s32 *) (q + 0x134);
        q[0x13D] = b;
        v0 = ((u8 *) v0)[0x1B8];
        if (v0 != 0) {
            v0 = b & 0xF7;
            q[0x13D] = v0;
        }
    }
}

__asm__(".globl func_80069BF8\nfunc_80069BF8 = func_80069B7C + 0x7C");

extern void func_8006EEF0();
extern void func_80070820();
extern s32 func_80070A38(s32);
extern void func_80070B7C();
extern s32 func_8007A218();
extern s32 D_80098DB8;

void func_80069C04(void) {
    s32 temp_s0;
    s32 temp_s1;

    func_8006EEF0();
    temp_s1 = func_8007A1D4();
    temp_s0 = func_8007A218();
    func_800683C0();
    func_80070B7C(temp_s1);
    if (func_80070A38(temp_s0) == 0) {
        D_800960E4 = 3;
        D_80098DB8 = 0;
        func_80070820(temp_s1);
    }
}

extern void func_8006E55C();
extern void func_80070B7C(s32);
extern s32 D_800960EC;

void func_80069C78(void) {
    s32 temp_v0;

    D_80045980 = 1;
    func_8006EEF0();
    D_800960E4 = 0;
    D_800960EC = 0;
    func_8006E55C();
    func_800683C0();
    temp_v0 = func_8007A218();
    if (temp_v0 != 0) {
        func_80070B7C(temp_v0);
    }
}

extern void func_8013D0AC();

void func_80069CDC(void) {
    s32 v0v;

    func_8006EEF0();
    v0v = 1;
    D_800960E4 = v0v;
    __asm__ volatile("lui $1,0x8009\n\t.globl func_80069CFC\n\tfunc_80069CFC:\n\tsw $2,0x60EC($1)" : : "r"(v0v));
    func_8013D0AC();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069D18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069D98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069D9C);

extern s32 func_80070D18();

void func_80069DDC(void) {
    register s32 v1v asm("v1");

    s32 v0v;
    v0v = func_80070D18();
    if (v0v != 0) {
        goto dfc;
    }
    v0v = 1;
    __asm__ volatile(".set\tnoreorder\n\tj func_80070E14\n\taddu $2,$zero,$zero\n\t.set\treorder" : "=r"(v0v) : "0"(v0v));
dfc:
    __asm__ volatile(".globl func_80069DFC\nfunc_80069DFC:");
    v1v = 0x30;
    D_800960E4 = v1v;
    v1v = 1;
    D_80045980 = v1v;
}

s32 func_80069E24(void) {
    s32 rv;
    s32 t;
    t = func_80070D18();
    __asm__ volatile(".set\tnoreorder\n\tbnez $2,1f\n\tori $2,$0,1\n\t.set\treorder" : "=r"(rv)::"memory");
    __asm__ volatile(".set\tnoreorder\n\tj func_80070E5C\n\taddu $2,$0,$0\n\t.set\treorder");
    __asm__ volatile("1:" ::: "memory");
    D_800960E4 = 0x31;
    D_80045980 = 1;
    return rv;
}

__asm__(".globl func_80069E68\nfunc_80069E68 = func_80069E24 + 0x44");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069E6C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069EE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069F14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069F3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80069FF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A008);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A018);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A01C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A020);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A080);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A178);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A17C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A180);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A188);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A190);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A1A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A20C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A22C);

extern void func_800EC718(s32, s32);
extern void func_8013D634(s32, u8, s32);
extern s32 D_800960C4;
extern s32 D_800960C0;

void func_8006A2D8(void) {
    u8 *p;
    u8 *p2;

    func_8006EEF0();
    D_800960E4 = 5;
    p = (u8 *) func_8007A218();
    *(u16 *) (p + 8) = 0;
    *(u8 *) (p + 0x1B4) = 0;
    func_800EC718(0, 0);
    if (p != 0) {
        p2 = *(u8 **) (p + 0x134);
        if (p2 != 0) {
            func_8013D634(3, *(u8 *) (p2 + 0x18A), 0);
        }
    }
}

extern void func_8006EEDC();
extern void func_80068634();
extern void func_800683D4();

void func_8006A34C(void) {
    s32 v0v;
    s32 v1v;

    func_8006EEDC();
    v1v = D_800960C0;
    v0v = 2;
    D_800960E4 = v0v;
    D_800960C0 = v0v;
    D_800960C4 = v1v;
    __asm__ volatile(".globl func_8006A380\nfunc_8006A380:" : : "r"(v1v));
    func_80068634();
    func_800683D4();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A3A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A44C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A4AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A4B0);

extern s32 D_800960FC;
extern s32 D_80096118;
extern s32 D_8009611C;

void func_8006A50C(void) {
    register u8 *a0v asm("$4");
    s32 v0;
    s32 v1;

    v0 = func_8007A2B8();
    a0v = (u8 *) v0;
    if (a0v == 0) {
        return;
    }
    SCHED_BARRIER();
    v0 = a0v[4];
    v1 = D_800960FC;
    D_8009611C = v0;
    if (v1 != 0) {
        goto late;
    }
    SCHED_BARRIER();
    v1 = a0v[4];
    v0 = D_80096118;
    if (v1 != v0) {
        goto late;
    }
    SCHED_BARRIER();
    v0 = a0v[0x13D];
    v0 &= 8;
    if (v0 != 0) {
        SCHED_BARRIER();
        func_800713A0();
        SCHED_BARRIER();
        TAIL_JUMP_NOP(.L80071598);
    }
    func_800712D8();
    SCHED_BARRIER();
    TAIL_JUMP_NOP(.L80071598);
late:
    func_80071434();
    SCHED_BARRIER();
}

void func_8006A5A8(void) {
    func_8006EEF0();
    D_800960E4 = 6;
    D_800960EC = 1;
    func_8013D0AC();
}

extern s32 func_80174B8C();
extern void func_800EC718();
extern void func_80043FF8();

void func_8006A5E8(void) {
    u8 *temp_v0;
    u8 *temp_v1;
    s32 temp;

    func_8006EEDC();
    D_800960E4 = 7;
    temp_v0 = (u8 *) func_8007A1D4();
    temp_v1 = *(u8 **) (temp_v0 + 0x134);
    func_80174B8C(*(temp_v1 + 0x18A), *(temp_v0 + 0x7C), *(temp_v0 + 0x7D), *(temp_v0 + 0x7E));
    func_800EC718(1, 1);
    temp = D_800960C0;
    D_800960C0 = 2;
    D_800960C4 = temp;
    func_80043FF8(1);
}

extern void func_8013D4DC();

void func_8006A668(void) {
    func_8006EEF0();
    D_800960E4 = 8;
    func_8013D4DC();
}

extern void func_8013D610();

void func_8006A69C(void) {
    func_8006EEF0();
    D_800960E4 = 8;
    func_800EC718(0, 3);
    func_8013D610();
}

void func_8006A6DC(void) {
    func_8006EEF0();
    D_800960E4 = 9;
    D_800960EC = 1;
    func_8013D0AC();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A71C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A790);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A794);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A7C0);

void func_8006A7CC(void) {
    extern void func_801419B8();
    u8 *p;
    func_8006EEF0();
    D_800960E4 = 0xC;
    p = (u8 *) func_8007A218();
    func_801419B8(1, 0, *(u8 *) (*(s32 *) (p + 0x134) + 0x18A), 0, p[0x13D] & 8);
}

void func_8006A824(void) {
    u8 *p;

    func_8006EEF0();
    D_800960E4 = 0xE;
    p = (u8 *) func_8007A218();
    func_801419B8(1, 2, *(u8 *) (*(s32 *) (p + 0x134) + 0x18A), 0, p[0x13D] & 8);
}

extern void func_80071824();
extern void func_800718C8();
extern void func_80071918();

void func_8006A87C(void) {
    register u8 *s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    void *p;

    func_8006EEF0();
    p = (void *) func_8007A218();
    __asm__ volatile(".set\tnoreorder\n\tjal func_8007A1D4\n\taddu $16,$2,$zero\n\t.set\treorder");
    v1 = s0[0x13D];
    s0 = (u8 *) v0;
    if (v1 & 8) {
        func_800683C0();
        TAIL_JUMP_NOP(func_800718C8);
    }
    func_800683D4();
    if (func_80174B8C(*(u8 *) (*(s32 *) (s0 + 0x134) + 0x18A), s0[0x7C], s0[0x7D], s0[0x7E]) > 0) {
        func_800EC718(1, 1);
        D_800960E4 = 0xD;
        *(s16 *) (s0 + 8) = 0;
        func_8006E55C();
        TAIL_JUMP_NOP(func_80071918);
    }
    func_80071824();
}

void func_8006A92C(void) {
    extern void func_801419B8();
    u8 *p;
    func_8006EEF0();
    D_800960E4 = 0xF;
    p = (u8 *) func_8007A218();
    func_801419B8(2, 2, *(u8 *) (*(s32 *) (p + 0x134) + 0x18A), 0, p[0x13D] & 8);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A984);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006A9C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AA48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AA50);

void func_8006AA80(u8 *arg0) {
    register s32 vstale asm("v0");
    u8 b1;
    u8 b2;
    u16 h;
    u8 b3;
    u8 b4;
    u8 b5;
    b1 = arg0[0x7D];
    b2 = arg0[0x7E];
    h = *(u16 *) &arg0[0x70];
    b3 = arg0[0x130];
    b4 = arg0[0x131];
    b5 = arg0[0x11E];
    arg0[0x84] = vstale;
    arg0[0x85] = b1;
    arg0[0x86] = b2;
    *(u16 *) &arg0[0x94] = h;
    arg0[0x132] = b3;
    arg0[0x133] = b4;
    arg0[0x11F] = b5;
}

extern void func_80071A7C();
extern s32 D_8009612C;

void func_8006AAB8(void) {
    u8 *p;
    s32 t;
    s32 v;

    func_8006EEF0();
    D_800960E4 = 0x11;
    func_8006E55C();
    p = (u8 *) func_8007A1D4();
    func_80071A7C(p);
    if (p[0x130] != 2) {
        v = 0x2000;
    } else {
        __asm__ volatile(".globl .L8006AB00\n.L8006AB00:");
        t = func_8007A6E4(p[0x131]);
        if (t != 0) {
            func_80071A7C(t);
        }
        v = 0x2000;
    }
    *(s32 *) (p + 0x3C) = v;
    *(s32 *) (p + 0x98) = 0;
    D_8009612C = 0;
    func_800683D4();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AB4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AC20);

extern void func_800683E4(s32);
extern void func_801419B8(s32, s32, s32, s32, s32);

void func_8006AC8C(void) {
    D_80045980 = 1;
    D_800960E4 = 0x25;
    D_80098DB8 = 0;
    func_800683E4(func_8007A218());
    func_801419B8(6, 0, 0, 0, 0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006ACEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AD18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AD28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AD3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006ADD8);

extern void func_80043D20();
extern void func_80068AB4();
extern void func_80082CC4();
extern void func_8013AEDC();

s32 func_8006ADE8(void *arg0) {
    extern void func_800683E4();
    extern void func_801419B8();
    s32 var_v0;
    u8 temp_a2;

    if (((u8 *) arg0)[0x1B2] == 0) {
        var_v0 = 0;
    } else {
        func_8013AEDC(0xB4);
        temp_a2 = *(u8 *) (*(s32 *) ((u8 *) arg0 + 0x134) + 0x18A);
        func_801419B8(0xA, 0x183F, temp_a2, temp_a2, 1);
        func_80082CC4(arg0);
        func_800683E4(arg0);
        func_80068AB4(arg0);
        func_80043D20(1);
        var_v0 = 1;
    }
    return var_v0;
}

s32 func_8006AE68(u8 *arg0) {
    register u8 *s0v asm("s0") = arg0;
    register s32 rv asm("v0");
    s32 t;
    t = s0v[0x1B3];
    USE(t);
    __asm__ volatile(".set\tnoreorder\n\tbeq $2,$0,1f\n\taddu $2,$0,$0\n\t.set\treorder" : "=r"(rv)::"memory");
    func_8013AEDC(0xB4);
    t = *(s32 *) (s0v + 0x134);
    func_801419B8(0xA, 0x183E, *(u8 *) (t + 0x18A), *(u8 *) (t + 0x18A), 1);
    func_80082CC4(s0v);
    func_800683E4(s0v);
    func_80068AB4(s0v);
    func_80043D20(3);
    rv = 1;
    __asm__ volatile("1:" ::: "memory");
    return rv;
}

__asm__(".globl .L8006AED0\n.L8006AED0 = func_8006AE68 + 0x68");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AEE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AF44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AF4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006AF7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B0E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B160);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B2AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B3C8);

extern s32 func_8017FFC0(s32);
extern s32 func_8007241C();
extern void func_80071EE8();
extern volatile s32 D_80096208;
extern s32 D_80096204;

void func_8006B3D4(void) {
    {
        s32 temp_a0;

        func_8006EEF0();
        temp_a0 = *(s32 *) ((u8 *) func_8007A1D4() + 0x134);
        if (temp_a0 != 0) {
            D_80096208 = func_8017FFC0(temp_a0);
            TAIL_JUMP(func_8007241C);
        }
    }
    D_80096208 = 0;
    D_80096204 = 0;
    func_80071EE8();
    if (D_80096208 != 0) {
        func_800683D4();
    }
    D_8009612C = 0;
}

extern void func_80071CEC();
extern s32 func_8019ABB4();
extern s32 D_80096218;

void func_8006B460(void) {
    extern s32 func_8007A6E4(s32);
    s32 temp_v1;
    s32 var_v0;
    u8 *temp_a0;
    u8 *temp_s1;
    u8 *temp_s0;

    func_8006EEF0();
    temp_s1 = (u8 *) func_8007A218();
    temp_v1 = *(s16 *) (temp_s1 + 0x70);
    D_800960E4 = 0x13;
    D_80096218 = temp_v1;
    *(s16 *) (temp_s1 + 8) = 0;
    if (temp_s1[0x130] == 1) {
        temp_s0 = (u8 *) func_8007A6E4(temp_s1[0x131]);
        if (temp_s0 != NULL) {
            func_80071CEC(temp_s1, *(s16 *) (temp_s0 + 0x70));
            temp_a0 = (u8 *) *(s32 *) (temp_s1 + 0x134);
            if (temp_a0 != NULL) {
                var_v0 = *(s16 *) (temp_s0 + 0x70);
                func_8017FDDC(*(u8 *) (temp_a0 + 0x18A), temp_s1[0x7C], temp_s1[0x7D],
                              temp_s1[0x7E], ((u32) (var_v0 < 0 ? var_v0 + 0x3FF : var_v0) >> 10) & 0xFF);
            }
        }
    }
    if ((temp_s1[0x13D] & 8) == 0) {
        *(s32 *) (temp_s1 + 0x164) = func_8019ABB4();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B544);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B5CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B608);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B60C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B674);

struct Func8006B710_Obj {
    u8 pad[0x70];
    u16 unk70;
    s16 unk72;
};

void func_8006B710(struct Func8006B710_Obj *arg0) {
    __asm__ volatile("addiu $sp, $sp, -0x10");
    if (arg0->unk72 == -1) {
        arg0->unk72 = arg0->unk70;
    }
    __asm__ volatile(".L8006B730:\n\taddiu $sp, $sp, 0x10");
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B73C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B894);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B898);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B8A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B928);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B960);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B994);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B9F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006B9FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BA10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BA20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BA38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BA70);

extern s32 func_8007A6E4();
extern void func_80072928();

void func_8006BA88(void) {
    register s32 v0v asm("v0");

    s32 s0v;
    s0v = 0;
loop:
    __asm__ volatile(".set\tnoreorder\n\tjal func_8007A6E4\n\tandi $4,$16,0xffff\n\t.set\treorder" ::"r"(s0v) : "ra", "memory");
    s0v = s0v + 1;
    if (v0v != 0) {
        func_80072928(v0v);
    }
    v0v = s0v < 16;
    if (v0v != 0) {
        goto loop;
    }
    return;
}

__asm__(".globl .L8006BAB0\n.L8006BAB0 = func_8006BA88 + 0x28");

__asm__(".globl .L8006BAC4\n.L8006BAC4 = func_8006BA88 + 0x3C");

void func_8006BAD0(void) {
    s32 v0;
    D_80045980 = 1;
    D_800960E4 = 0x26;
    v0 = func_8007A218();
    if (v0 != 0) {
        *(s16 *) (v0 + 8) = 0;
    }
}

extern void func_800683E4();
extern void func_80071C8C();

void func_8006BB14(s32 arg0) {
    s32 s0;
    s0 = arg0;
    func_800683E4(arg0);
    func_80068E30(*(u8 *) (s0 + 4));
    func_80071C8C();
}

void func_8006BB50(void) {
    register s32 a0v asm("a0");
    register s32 q asm("v0");
    u8 *p;
    func_8006EEF0();
    D_800960E4 = 0x16;
    p = (u8 *) func_8007A218();
    a0v = 1;
    if (*(s32 *) (p + 0x174) == 3) {
        __asm__ volatile(".set\tnoreorder\n\tj func_80072B94\n\tori $5,$0,1\n\t.set\treorder");
    }
    q = *(s32 *) (p + 0x134);
    func_801419B8(a0v, 0, *(u8 *) (q + 0x18A), 0, p[0x13D] & 8);
    if (p[0x13D] & 8) {
        func_800683C0();
        TAIL_JUMP(func_80072BDC);
    }
    func_800683D4();
}

__asm__(".globl .L8006BBD0\n.L8006BBD0 = func_8006BB50 + 0x80");

__asm__(".globl .L8006BBDC\n.L8006BBDC = func_8006BB50 + 0x8C");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BBF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BBFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BCE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BCE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BDA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BE54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BE8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BFAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BFD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BFD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006BFDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C024);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C158);

void func_8006C15C(void) {
}

extern void func_80072D8C();
extern s32 D_80096244;

void func_8006C164(void) {
    s32 i;
    u8 *p;
    register u8 *q asm("v0");
    D_80096244 = 0;
    i = 0;
    p = (u8 *) func_8007A1D4();
    for (; i < p[0x18D]; i++) {
        q = p + i;
        func_8007A724(q[0x18E]);
        func_80072D8C(q);
    }
}

__asm__(".globl .L8006C17C\n.L8006C17C = func_8006C164 + 0x18");

__asm__(".globl .L8006C184\n.L8006C184 = func_8006C164 + 0x20");

__asm__(".globl .L8006C188\n.L8006C188 = func_8006C164 + 0x24");

extern s32 func_80072CE8();
extern s32 D_800473AC;

void func_8006C1D8(void) {
    u8 *p;
    p = (u8 *) func_8007A1D4();
    func_80072D8C(p);
    if (D_800473AC & 0x180000) {
        D_80096244 = 0;
    }
    if (func_80072CE8() == 0) {
        func_801419B8(0xA, 0, *(u8 *) (*(s32 *) (p + 0x134) + 0x18A), 0, 0);
    }
}

__asm__(".globl .L8006C21C\n.L8006C21C = func_8006C1D8 + 0x44");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C250);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C264);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C2BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C2C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C318);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C320);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C3C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C3D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C41C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C4BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C4C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C4CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C4F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C4F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C4FC);

extern s32 func_80072A88();
extern s32 func_8017E7E4(s32, s32);
extern void func_80080F44(s32);
extern void func_800734CC();

void func_8006C638(void) {
    s32 s0v;
    s32 v0v;
    s32 v1v;
    s32 a0v;
    s32 a1v;

    s0v = func_8007A218();
    func_80072A88();
    if (s0v == 0) {
        goto E;
    }
    v0v = *(s32 *) ((u8 *) s0v + 0x134);
    if (v0v == 0) {
        goto E;
    }
    a0v = ((u8 *) v0v)[0x18A];
    a1v = (s32) ((u8 *) s0v + 0x1B0);
    v0v = func_8017E7E4(a0v, a1v);
    v1v = -1;
    if (v0v != v1v) {
        goto E;
    }
    *(u8 *) ((u8 *) s0v + 0x1B3) = 0;
    *(u8 *) ((u8 *) s0v + 0x1B2) = 0;
    *(u8 *) ((u8 *) s0v + 0x1B1) = 0;
    *(u8 *) ((u8 *) s0v + 0x1B0) = 0;
E:
    func_80080F44(s0v);
    D_80096204 = 0;
    func_800683E4(s0v);
    func_800734CC();
    D_80098DB8 = 0;
    D_8009612C = 0;
}

__asm__(".globl .L8006C644\n.L8006C644 = func_8006C638 + 0xC");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C6D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C768);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C778);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C790);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C7B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C7D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C814);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C860);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C878);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C910);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C914);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C944);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C94C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006C9CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CA30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CA34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CA38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CA3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CA54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CAC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CAD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CAE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CB9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CBB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CC54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CC58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CC8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CC94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CC98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CDF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CDF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CEEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CF2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006CFE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D048);

void func_8006D060(void) {
}

void func_8006D068(void) {
    s32 temp_v0;

    func_8006EEF0();
    D_800960E4 = 0x1D;
    D_80098DB8 = 0;
    temp_v0 = func_8007A218();
    if (func_80070A38(temp_v0) == 0) {
        D_800960E4 = 0x1D;
        func_80070820(temp_v0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D0D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D188);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D18C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D1A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D1E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D204);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D288);

void func_8006D2C8(void) {
    func_8006EEF0();
    D_800960E4 = 0x1A;
    D_800960EC = 1;
    func_8013D0AC();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D308);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D344);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D434);

void func_8006D470(void) {
    extern void func_801419B8();
    u8 *p;
    func_8006EEF0();
    D_800960E4 = 0x18;
    p = (u8 *) func_8007A218();
    func_801419B8(4, 5, *(u8 *) (*(s32 *) (p + 0x134) + 0x18A), 0, p[0x13D] & 8);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D4C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D50C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D510);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D598);

#define TAIL_678() __asm__ volatile(".set\tnoreorder\n\tj func_80074678\n\tori $4,$zero,4\n\t.set\treorder")
#define CASE_67C(l, k) __asm__ volatile(".set\tnoreorder\n\tbeq $4,$0," #l "\n\tori $4,$zero,4\n\tj func_8007467C\n\tori $5,$zero," #k "\n\t" #l ":\n\tj func_8007467C\n\tori $5,$zero,2\n\t.set\treorder")

void func_8006D5AC(void) {
    register u8 *p asm("s0");
    register s32 a0v asm("a0");
    register s32 x0 asm("a0");
    register s32 x1 asm("a1");
    register s32 x2 asm("a2");
    s32 t;

    func_8006EEF0();
    D_800960E4 = 0x1B;
    func_8007A218();
    x0 = D_800961B4;
    x1 = D_800961BC;
    x2 = D_800961B8;
    __asm__ volatile(".set\tnoreorder\n\tjal func_8007A2B8\n\taddu $16,$2,$zero\n\t.set\treorder" : : "r"(x0), "r"(x1), "r"(x2));
    __asm__ volatile("addu $4,$2,$zero" : "=r"(a0v));
    t = *(s32 *) (p + 0x174);
    if (t == 1) {
        goto case1;
    }
    if (t >= 2) {
        goto ge2;
    }
    if (t == 0) {
        goto case0;
    }
    TAIL_678();
ge2:
    if (t == 2) {
        goto case2;
    }
    TAIL_678();
case0:
    CASE_67C(.Lb_case0, 1);
case1:
    CASE_67C(.Lb_case1, 4);
case2:
    CASE_67C(.Lb_case2, 3);
    func_801419B8(a0v, 0, *(u8 *) (*(s32 *) (p + 0x134) + 0x18A), 0, p[0x13D] & 8);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D6AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D73C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D748);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D79C);

void func_8006D7B8(void) {
    register s32 v0v asm("v0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    volatile s32 buf[2];

    __asm__ volatile(".set\tnoreorder\n\tjal func_8006EEF0\n\t.globl func_8006D7C4\n\tfunc_8006D7C4:\n\tnop\n\t.set\treorder" ::: "ra", "memory");
    v0v = 0x1F;
    D_800960E4 = v0v;
    v0v = func_8007A1D4();
    a0v = 1;
    __asm__ volatile("move $5,$zero\n\t.globl func_8006D7E4\nfunc_8006D7E4:" : : "r"(a0v));
    v0v = *(s32 *) ((u8 *) v0v + 0x134);
    a3v = 0;
    a2v = *(u8 *) ((u8 *) v0v + 0x18A);
    v0v = 1;
    __asm__ volatile(".set\tnoreorder\n\tjal func_801419B8\n\tsw $2,16($sp)\n\t.set\treorder" : : "r"(a0v), "r"(a1v), "r"(a2v), "r"(a3v), "r"(v0v));
    func_800683C0();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D814);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D818);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006D85C);

extern s32 func_8007A2B8();

void func_8006D930(void) {
    s32 a0v;
    s32 a1v;
    s32 a2v;
    s32 t;
    func_8006EEF0();
    a0v = D_800961B4;
    a1v = D_800961BC;
    a2v = D_800961B8;
    D_800960E4 = 0x22;
    t = func_8007A2B8(a0v, a1v, a2v);
    if (t != 0) {
        t = *(s32 *) (t + 0x134);
        if (t != 0) {
            func_8013D634(3, *(u8 *) (t + 0x18A), 0);
        }
    }
    t = func_8007A1D4();
    func_801419B8(9, 0, *(u8 *) (*(s32 *) (t + 0x134) + 0x18A), 0, 1);
}

__asm__(".globl .L8006D96C\n.L8006D96C = func_8006D930 + 0x3C");

void func_8006D9C8(void) {
    extern void func_8013D634();
    extern void func_801419B8();

    func_8006EEF0();
    D_800960E4 = 0x23;
    func_8013D634(1, 0xFF, 0xFF);
    func_801419B8(1, 0, *(u8 *) (*(s32 *) ((u8 *) func_8007A1D4() + 0x134) + 0x18A), 0, 1);
    D_80098DB8 = 0;
    func_800683C0();
}

void func_8006DA3C(void) {
    extern void func_800683E4();
    extern void func_8013D634();
    s32 s0;
    s32 v0;

    func_8006EEF0();
    D_800960E4 = 0x24;
    s0 = func_8007A724(*(u8 *) (*(s32 *) ((u8 *) func_8007A1D4() + 0x134) + 0x1B9));
    func_800683E4(s0);
    func_80070820(s0);
    if (s0 != 0) {
        v0 = *(s32 *) (s0 + 0x134);
        if (v0 != 0) {
            func_8013D634(3, *(u8 *) (v0 + 0x18A), 0);
        }
    }
}

void func_8006DAC0(void) {
    D_80045980 = 2;
    D_800960E4 = 0x33;
    func_800683C0();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DAF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DAFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DB10);

extern void func_8008924C();
extern void func_80074B9C();
extern void func_800890B8(volatile s32 *, volatile s32 *, volatile s32 *);

void func_8006DB70(void) {
    s32 v0v;
    volatile s32 local[8];

    if (v0v != 0) {
        func_8008924C();
        TAIL_JUMP_NOP(func_80074B9C);
    }
    func_800890B8(&local[4], &local[0], &local[2]);
}

extern void func_80086B44();
extern s32 D_800960F0;
extern void func_8008719C();
extern void func_80086DC4();
extern void func_80074B68();
extern void func_80070C78();
extern void func_80074BAC();

void func_8006DBAC(void) {
    func_80086B44();
    if (D_800960F0 != 1) {
        func_8008719C();
    }
    func_80086DC4();
    func_80074B68();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DBF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DC78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DC8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DC90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DD8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DD90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DD94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DD98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DDAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DDB0);

extern s32 func_8013D578();
extern s32 func_80044A60();
extern void func_8013F520();
extern s32 D_80045944;

void func_8006DDD0(void) {
    s32 v0v;
    s32 v1v;

    v0v = func_8013D578();
    v1v = 2;
    if (v0v == v1v) {
        goto L;
    }
    D_800960EC = 0;
    func_80070C78();
L:
    func_80074BAC();
    v0v = func_80044A60();
    func_8013F520(v0v, D_80045944);
}

__asm__(".globl func_8006DDEC\nfunc_8006DDEC = func_8006DDD0 + 0x1C");

__asm__(".globl func_8006DDFC\nfunc_8006DDFC = func_8006DDD0 + 0x2C");

__asm__(".set push\n.set noreorder\nlui $2,0x8004\n\tlw $2,0x5950($2)\n.set pop\n");

extern void func_8006F28C();
extern void func_8006F634();
extern void func_8006F968();

void func_8006DE34(void) {
    s32 v;
    if (v & 0x80) {
        D_800960C0 = D_800960C4;
        func_80070C78();
        func_80068494();
    }
    func_8006F28C();
    func_8006F634();
    func_8006F968();
    func_80074BAC();
}

__asm__(".globl .L8006DEA4\n.L8006DEA4 = func_8006DE94 + 0x10");

void func_8006DE94(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 v0;
    s32 v1;
    func_80074BAC();
    v0 = func_80044A60();
    func_8013F520(v0, D_80045944);
    v0 = func_8013F978();
    v1 = *(s32 *) v0;
    if (v1 < 7) {
        goto Lchk;
    }
    v0 = (v1 < 9);
    if (v0 != 0) {
        v0 = 1;
        D_80098DB8 = v0;
        goto Lchk;
    }
    v0 = 0xFF;
    if (v1 != v0) {
        goto Lchk;
    }
    v0 = 1;
    D_80098DB8 = v0;
Lchk:
    v0 = D_800A1C48 | D_800A1C4C | D_800A1C50;
    if (v0 != 0) {
        goto Lend;
    }
    if (D_800960C8 != 0) {
        goto Lend;
    }
    if (D_80098DB8 == 0) {
        goto Lend;
    }
    func_800714F4();
Lend:;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DF5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006DF84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E09C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E0EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E138);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E13C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E144);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E2D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E2D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E310);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E538);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E53C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E55C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E5A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E5C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E5E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E5FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E618);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E634);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E660);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E694);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E698);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E6B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E6D4);

void func_8006E714(void) {
}

extern void func_800716DC();
extern void func_8007171C();
extern s32 func_80075794();

void func_8006E71C(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0v asm("a0");
    v0 = func_8013D578();
    v1 = D_8004594C & 0x100;
    a0v = v0;
    if (v1 == 0) {
        goto path2;
    }
    func_800716DC(a0v);
    TAIL_JUMP(func_80075794);
path2:
    if (a0v != 0) {
        v0 = a0v < 0x64;
        goto chk;
    }
    D_800960C0 = D_800473AC & 7;
    func_80070C78();
    TAIL_JUMP(func_80075794);
chk:
    if (v0 != 0) {
        goto done;
    }
    a0v = a0v - 0x64;
    func_8007171C(a0v);
done:
    func_80074BAC();
    v0 = func_80044A60();
    func_8013F520(v0, D_80045944);
}

__asm__(".globl .L8006E7AC\n.L8006E7AC = func_8006E71C + 0x90");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E7C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E7C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E814);

extern void func_8007169C();

void func_8006E828(void) {
    register s32 v1 asm("v1");
    extern void func_8013F520();
    if (((v1 & 0x20) != 0) || ((v1 & 0x40) != 0)) {
        func_8007169C();
    }
    KEEP(v1);
    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
}

extern void func_8007187C();
extern void func_800713A0();
extern void func_80075900();
extern s32 *func_8013F978();

void func_8006E87C(void) {
    s32 v1;
    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
    v1 = *func_8013F978();
    if (v1 == 8) {
        goto L713A0;
    }
    if (v1 < 9) {
        if (v1 == 7) {
            goto L7;
        }
        TAIL_JUMP(func_80075900);
    }
    if (v1 == 0xFF) {
        goto L713A0;
    }
    TAIL_JUMP(func_80075900);
L7:
    func_8007187C();
    TAIL_JUMP(func_80075900);
L713A0:
    func_800713A0();
}

__asm__(".globl .L8006E8C0\n.L8006E8C0 = func_8006E87C + 0x44");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006E910);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EAD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EAD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EAD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EAE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EB28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EB2C);

extern void func_800714F4();

void func_8006EC34(void) {
    s32 temp_v1;

    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
    temp_v1 = *func_8013F978();
    if ((temp_v1 >= 7) && ((temp_v1 < 9) || (temp_v1 == 0xFF))) {
        func_800714F4();
    }
}

void func_8006ECA0(void) {
    s32 temp_v1;

    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
    temp_v1 = *func_8013F978();
    if ((temp_v1 >= 7) && ((temp_v1 < 9) || (temp_v1 == 0xFF))) {
        func_8007187C();
    }
}

void func_8006ED0C(void) {
    register s32 sv asm("s0");
    register u8 *q asm("v1");
    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
    func_8013F978();
    __asm__ volatile(".set\tnoreorder\n\tjal func_8007A1D4\n\taddu $16,$2,$zero\n\taddu $3,$2,$zero\n\tlw $16,0($16)\n\t.set\treorder"
                     : "=r"(sv), "=r"(q) : : "ra", "$2", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    if (sv == 8) {
        goto L94;
    }
    if (sv < 9) {
        if (sv == 7) {
            goto L84;
        }
        TAIL_JUMP(func_80075D9C);
    }
    if (sv == 0xFF) {
        goto L94;
    }
    TAIL_JUMP(func_80075D9C);
L84:
    func_80071AB8();
    TAIL_JUMP(func_80075D9C);
L94:
    __asm__ volatile(".set\tnoreorder\n\tjal func_8007187C\n\tsb $0,156($3)\n\t.set\treorder"
                     : : : "ra", "$2", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

__asm__(".globl .L8006ED5C\n.L8006ED5C = func_8006ED0C + 0x50");

__asm__(".globl .L8006ED60\n.L8006ED60 = func_8006ED0C + 0x54");

extern void func_80071B4C();
extern void func_8013F520(s32, s32);

__asm__(".globl .L8006EDFC\n.set .L8006EDFC, func_8006EDB0 + 0x4C");

extern s32 func_80081988();

void func_8006EDB0(void) {
    register u32 v1v asm("v1");
    u32 v0v;
    s32 s0r;
    func_8006F28C();
    func_8006F634();
    func_8006F968();
    s0r = func_8007A1D4();
    func_8006D818(s0r);
    v0v = *(u8 *) (s0r + 0x7F);
    if (v0v != 0) {
        goto tail;
    }
    __asm__ volatile("lbu %0,0x9C(%1)" : "=r"(v1v) : "r"(s0r));
    v0v = *(u32 *) (s0r + 0x98);
    v0v = v0v < v1v;
    if (v0v != 0) {
        goto tail;
    }
    v0v = D_8009612C;
    if (v0v != 0) {
        goto tail;
    }
    func_80068E30(*(u8 *) (s0r + 0x4));
    func_80071B4C();
tail:
    func_80074BAC();
    v0v = func_80044A60();
    func_8013F520(v0v, D_80045944);
}

void func_8006EE68(s32 arg0) {
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    register s32 t0v asm("t0");
    register s32 t1v asm("t1");
    u8 *p;

    s0v = arg0;
    p = (u8 *) s0v;
    v0v = p[0x84];
    v1v = p[0x85];
    a1v = p[0x86];
    a2v = *(u16 *) (p + 0x94);
    a3v = p[0x132];
    t0v = p[0x133];
    t1v = p[0x11F];
    p[0x7C] = v0v;
    p[0x7D] = v1v;
    p[0x7E] = a1v;
    *(u16 *) (p + 0x70) = a2v;
    p[0x130] = a3v;
    p[0x131] = t0v;
    p[0x11E] = t1v;
    func_80081B0C();
    v0v = *(s32 *) (p + 0x134);
    v1v = *(s16 *) ((u8 *) s0v + 0x70);
    a1v = p[0x7C];
    __asm__ volatile(".L8006EEC0:" : : "r"(a1v));
    a2v = p[0x7D];
    a3v = p[0x7E];
    a0v = ((u8 *) v0v)[0x18A];
    v0v = (u32) v1v >> 10;
    if (v1v < 0) {
        v1v = v1v + 0x3FF;
        v0v = (u32) v1v >> 10;
    }
    __asm__ volatile(".globl func_8006EEDC\nfunc_8006EEDC:" : : "r"(v0v));
    v0v = v0v & 0xFF;
    func_8017FDDC(a0v, a1v, a2v, a3v, v0v);
    a2v = s0v;
    a0v = *(u16 *) (a2v + 476);
    __asm__ volatile(".globl func_8006EEF0\nfunc_8006EEF0:" : : "r"(a0v));
    a1v = *(s16 *) (a2v + 112);
    a0v = a0v >> 1;
    func_80081988(a0v, a1v, a2v);
}

__asm__(".globl func_8006EF00\nfunc_8006EF00 = func_8006EE68 + 0x98");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EF10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EFD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006EFEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F01C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F074);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F078);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F084);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F13C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F158);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F174);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F1A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F1AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F1CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F1E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F218);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F274);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F28C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F29C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F320);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F33C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F344);

struct Func8006F358_Obj {
    u8 pad[0x6C];
    u16 f6c;
    u16 f6e;
    s16 f70;
    u8 pad72[0xA];
    u8 f7c;
    u8 f7d;
    u8 f7e;
    u8 pad7f[0xB1];
    u8 f130;
    u8 f131;
    u8 pad132[2];
    BattleUnit *p134;
    u8 pad138[0x52];
};

void func_8006F358(void *arg0) {
    register struct Func8006F358_Obj *s0 asm("s0");
    register BattleUnit *p asm("v0");
    register struct Func8006F358_Obj *p1 asm("v1");
    register s32 v0 asm("v0");
    register u16 valuev asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    s0 = (struct Func8006F358_Obj *) arg0;
    p = s0->p134;
    v1 = s0->f70;
    a1 = s0->f7c;
    a2 = s0->f7d;
    a3 = s0->f7e;
    a0 = p->unitId2;
    v0 = (u32) v1 >> 10;
    if (v1 < 0) {
        v1 = v1 + 0x3ff;
        v0 = (u32) v1 >> 10;
    }
    v0 &= 0xFF;
    func_8017FDDC(a0, a1, a2, a3, v0);
    v0 = s0->f130;
    if (v0 != 0) {
        a0 = s0->f131;
        p = (BattleUnit *) func_8007A6E4(a0);
        __asm__ volatile("addu $3,$2,$zero" : "=r"(p1) : "r"(p));
        if (p1 == 0)
            goto end;
        valuev = s0->f70;
        p1->f70 = valuev;
        valuev = s0->f6c;
        p1->f6c = valuev;
        valuev = s0->f6e;
        p1->f6e = valuev;
        v0 = (s32) p1->p134;
        v1 = s0->f70;
        a1 = s0->f7c;
        a2 = s0->f7d;
        a3 = s0->f7e;
        a0 = ((BattleUnit *) v0)->unitId2;
        v0 = (u32) v1 >> 10;
        if (v1 < 0) {
            v1 = v1 + 0x3ff;
            v0 = (u32) v1 >> 10;
        }
        v0 &= 0xFF;
        func_8017FDDC(a0, a1, a2, a3, v0);
    }
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F430);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F46C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F5A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F5AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F5B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F5BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F610);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F634);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F640);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F658);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F678);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F778);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F8A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F8B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F8B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F8B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F8C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F918);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F91C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F948);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F94C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F968);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F96C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F974);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F988);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F998);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F9AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006F9B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FB08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FB0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FB50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FB54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FB5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FB64);

extern void func_800744C8();

void func_8006FB7C(void) {
    s32 temp_v1;

    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
    temp_v1 = *func_8013F978();
    if ((temp_v1 >= 7) && ((temp_v1 < 9) || (temp_v1 == 0xFF))) {
        func_800744C8();
    }
}

void func_8006FBE8(void) {
    s32 v0v;
    s32 v1v;

    v0v = func_8013D578();
    v1v = 2;
    if (v0v != v1v) {
        __asm__ volatile("lui $1,0x8009\n\t.globl func_8006FC08\n\tfunc_8006FC08:\n\tsw $0,0x60EC($1)" : : "r"(v0v), "r"(v1v));
        func_8006EEDC();
        v0v = 0x19;
        D_800960E4 = v0v;
    }
    __asm__ volatile(".globl func_8006FC20\nfunc_8006FC20:");
    func_80074BAC();
    v0v = func_80044A60();
    func_8013F520(v0v, D_80045944);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FC50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FC68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FD84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FDF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FDFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FE04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FE18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FE24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FE58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8006FEA4);

extern void func_800740D4();

__asm__(".globl .L8006FF20\n.set .L8006FF20, func_8006FF14 + 0xC");

void func_8006FF14(void) {
    register s32 a0v asm("a0");
    s32 v1v;
    u32 v0v;
    func_80074BAC();
    v0v = func_80044A60();
    func_8013F520(v0v, D_80045944);
    v1v = func_8007A218();
    v0v = *(u16 *) (v1v + 0x1E2);
    if (v0v == 0) {
        goto shared;
    }
    v0v = *(u16 *) (v1v + 0x1E4);
    if (v0v != 0) {
        goto shared;
    }
    v0v = *(u16 *) (v1v + 0x8);
    if (v0v < 0x3D) {
        goto done;
    }
shared:
    v0v = D_800A1C48;
    v1v = D_800A1C4C;
    a0v = D_800A1C50;
    v0v = v0v | v1v;
    v0v = v0v | a0v;
    if (v0v != 0) {
        goto done;
    }
    v0v = D_800960C8;
    if (v0v != 0) {
        goto done;
    }
    func_800740D4();
done:
    return;
}

__asm__(".globl .L80070030\n.L80070030 = func_8006FFD0 + 0x60");

__asm__(".globl .L8006FFD4\n.L8006FFD4 = func_8006FFD0 + 0x4");

void func_8006FFD0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 v0;
    s32 v1;
    func_80074BAC();
    v0 = func_80044A60();
    func_8013F520(v0, D_80045944);
    v0 = func_8013F978();
    v1 = *(s32 *) v0;
    if (v1 < 7) {
        goto Lchk;
    }
    v0 = (v1 < 9);
    if (v0 != 0) {
        v0 = 1;
        D_80098DB8 = v0;
        goto Lchk;
    }
    v0 = 0xFF;
    if (v1 != v0) {
        goto Lchk;
    }
    v0 = 1;
    D_80098DB8 = v0;
Lchk:
    v0 = D_800A1C48 | D_800A1C4C | D_800A1C50;
    if (v0 != 0) {
        goto Lend;
    }
    if (D_800960C8 != 0) {
        goto Lend;
    }
    if (D_80098DB8 == 0) {
        goto Lend;
    }
    func_80074204();
Lend:;
}

extern s32 D_80096214;

void func_80070098(void) {
    register s32 v1 asm("$3");

    s32 v0;
    s32 s0v;
    func_80074BAC();
    v0 = func_80044A60();
    func_8013F520(v0, D_80045944);
    s0v = func_8007A218();
    v1 = *(s32 *) (s0v + 0x17C);
    v0 = 3;
    if (v1 != v0) {
        goto late;
    }
    v0 = *(u16 *) (s0v + 0x1E2);
    if (v0 != 0) {
        return;
    }
    v0 = *(s32 *) (s0v + 0x134);
    func_80183BA8(*(u8 *) (v0 + 0x18A));
    func_80072B14(s0v);
    TAIL_JUMP_NOP(func_80077120);
late:
    D_80096214 = 0;
    func_800739CC();
}

extern void func_80073FB8();

void func_80070134(void) {
    s32 temp_v1;

    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
    temp_v1 = *func_8013F978();
    if ((temp_v1 >= 7) && ((temp_v1 < 9) || (temp_v1 == 0xFF))) {
        func_80073FB8();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800701A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070218);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800702D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800702E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800702E8);

extern s32 func_801A13BC();
extern s32 func_80077344();
extern void func_80073B9C();
extern volatile s32 D_8009612C;

void func_80070314(void) {
    if (func_801A13BC() != 0) {
        D_8009612C = 1;
        TAIL_JUMP(func_80077344);
    }
    D_8009612C = 0;
    if (D_8009612C == 0) {
        func_80073B9C();
    }
    func_80074BAC();
}

extern void func_80072BF0();

void func_80070378(void) {
    s32 v0;
    u16 v1;
    v0 = func_8007A1D4();
    v1 = *(u16 *) (v0 + 8) + 1;
    *(u16 *) (v0 + 8) = v1;
    func_80072BF0();
    func_80074BAC();
}

void func_800703B4(s32 arg0, u8 *arg1) {
    if ((arg0 != 0) && (arg1 != 0)) {
        func_80083978();
        func_80068BD4(arg1[4]);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800703F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070498);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070604);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070614);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007062C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070630);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070640);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070658);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070738);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070740);

extern void func_800731D8();

void func_80070760(void) {
    s32 v0;
    s32 v1;

    func_80074BAC();
    v0 = func_80044A60();
    func_8013F520(v0, D_80045944);
    v0 = func_8013F978();
    v1 = *(s32 *) v0;
    if (v1 >= 7) {
        if (v1 >= 9) {
            v0 = 0xFF;
            if (v1 != v0) {
                goto tail;
            }
        }
        D_80098DB8 = 1;
    }
tail:
    v0 = D_80098DB8;
    if (v0 != 0) {
        func_800731D8();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800707EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070820);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070890);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070980);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070984);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070988);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007098C);

void func_80070998(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800709A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800709FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070A0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070A38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070A50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070B18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070B2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070B3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070B58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070B7C);

extern void func_80071008();
extern s32 func_80077B58();

void func_80070BD8(void) {
    if (func_80077B58() != 0) {
        func_80071008();
    }
}

void func_80070C08(void) {
    if (func_80077B58() != 0) {
        func_80071C8C();
    }
}

__asm__(".globl func_80070C78\nfunc_80070C78 = func_80070C38 + 0x40");

void func_80070C38(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 v0;
    s32 v1;
    func_80074BAC();
    v0 = func_80044A60();
    func_8013F520(v0, D_80045944);
    v0 = func_8013F978();
    v1 = *(s32 *) v0;
    if (v1 < 7) {
        goto Lend;
    }
    v0 = (v1 < 9);
    if (v0 != 0) {
        func_80074814();
        goto Lend;
    }
    v0 = 0xFF;
    if (v1 == v0) {
        func_80074814();
    }
Lend:;
}

__asm__(".globl func_80070C94\nfunc_80070C94 = func_80070C38 + 0x5C");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070CA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070CDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070D18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070DB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070DC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070DDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070DE0);

void func_80070E14(void) {
}

__asm__(".globl func_80070E5C\nfunc_80070E5C = func_80070E1C + 0x40");

__asm__(".globl func_80070E24\nfunc_80070E24 = func_80070E1C + 0x8");

void func_80070E1C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 v0;
    s32 v1;
    func_80074BAC();
    v0 = func_80044A60();
    func_8013F520(v0, D_80045944);
    v0 = func_8013F978();
    v1 = *(s32 *) v0;
    if (v1 < 7) {
        goto Lend;
    }
    v0 = (v1 < 9);
    if (v0 != 0) {
        func_80074814();
        goto Lend;
    }
    v0 = 0xFF;
    if (v1 == v0) {
        func_80074814();
    }
Lend:;
}

__asm__(".globl func_80070E6C\nfunc_80070E6C = func_80070E1C + 0x50");

extern void func_8014171C(s32, s32);
extern void func_80070C04();
extern void func_80074814();
extern void func_80077EC0();

__asm__(".globl L80077F54\nL80077F54 = func_80077EC0 + 0x94");

__asm__(".globl .L80070ED0\n.set .L80070ED0, func_80070E88 + 0x48");

void func_80070E88(void) {
    register s32 s0r asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    func_80074BAC();
    v0v = func_80044A60();
    func_8013F520(v0v, D_80045944);
    v0v = (s32) func_8013F978();
    v1v = *(s32 *) v0v;
    if (v1v == 8) {
        goto f4c;
    }
    if (!(v1v < 9)) {
        goto ge9;
    }
    if (v1v == 7) {
        goto ef4;
    }
    TAIL_JUMP_NOP(L80077F54);
ge9:
    if (v1v == 0xFF) {
        goto f4c;
    }
    TAIL_JUMP_NOP(L80077F54);
ef4:
    v0v = func_8007A1D4();
    s0r = v0v;
    func_8007A2B8(D_800961B4, D_800961BC, D_800961B8);
    v0v = *(s32 *) (v0v + 0x134);
    v1v = *(s32 *) (s0r + 0x134);
    func_8014171C(*(u8 *) (v0v + 0x18A), *(u8 *) (v1v + 0x18A));
    func_800683E4(s0r);
    func_80070C04();
    TAIL_JUMP_NOP(L80077F54);
f4c:
    func_80074814();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070F68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070FB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80070FBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071008);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071020);

void func_80071030(void) {
    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
    if ((D_8004594C & 0x20) || (D_8004594C & 0x40)) {
        func_800683E4(func_8007A1D4());
        func_80070C04();
    }
}

extern void func_80072AD0();

void func_800710A0(void) {
    struct Obj {
        u8 pad[0x2BC];
        u8 unk2BC;
    } *temp_v1;
    s32 *temp_s0;
    s32 temp_s0_2;
    extern void func_8013F520();

    func_80074BAC();
    func_8013F520(func_80044A60(), D_80045944);
    temp_s0 = func_8013F978();
    temp_v1 = (struct Obj *) func_8007A218();
    temp_s0_2 = *temp_s0;
    if ((temp_s0_2 >= 7) && ((temp_s0_2 < 9) || (temp_s0_2 == 0xFF))) {
        D_80098DB8 = 1;
    }
    if ((D_80098DB8 != 0) && (temp_v1->unk2BC == 0)) {
        func_80072AD0();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071148);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071178);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007117C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071190);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800711A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800711A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800712A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800712C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800712D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800712DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071310);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071328);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007134C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800713A0);

void func_80071434(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007143C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800714D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800714F4);

extern s32 D_800960E8;
extern s32 D_8004D958;

void func_80071504(void) {
    func_80086B44();
    if (D_800960F0 != 1) {
        func_8008719C();
        func_8008F130();
        func_8008B440();
        func_8008B6E4();
        func_8008B968();
        func_8008BB94();
    }
    func_80086DC4();
    func_8008F208();
    if (D_8009612C == 0) {
        D_800960E4 = D_800960E8;
        D_80045980 = D_8004D958;
    }
}

__asm__(".globl .L80071598\n.L80071598 = func_80071504 + 0x94");

__asm__(".globl func_800715A8\nfunc_800715A8 = func_80071504 + 0xA4");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800715AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800715E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071608);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071668);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007169C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800716A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800716DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007171C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007179C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800717CC);

extern void func_800F5984();

void func_800717DC(void) {
    func_800F5984();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800717FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071824);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071828);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007187C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800718C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800718CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071918);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007192C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071964);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071984);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071A48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071A4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071A7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071AB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071ABC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071ACC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071B4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071BE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071C04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071C28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071C48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071C74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071C8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071C90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071CEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071D30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071DD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071DD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071DE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071DEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071E58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071E68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071EE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071F9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80071FB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007207C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072080);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800720A8);

extern void func_800926D8(s32, s32, s32, s32);
extern u8 D_80094AE4[];
extern u8 D_80094B44[];
extern u8 D_80094B64[];
extern u8 D_80094BC4[];
extern u8 D_80094BE4[];

void func_800721E8(s32 arg0) {
    s32 s0v;
    s32 unused[2];

    s0v = (s32) D_80094AE4;
    func_800926D8(s0v, 2, 1, 0);
    func_800926D8(s0v + 0x20, 2, 2, 0);
    func_800926D8((s32) D_80094B44, 2, 3, 0);
    func_800926D8((s32) D_80094B64, 2, 4, 0);
    func_800926D8((s32) D_80094BC4, 2, 5, 0);
    func_800926D8((s32) D_80094BE4, 2, 7, 0);
}

void func_80072298(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800722A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800722C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072374);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800723B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800723D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007241C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072460);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072544);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072630);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007265C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072674);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007270C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007273C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072810);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072814);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072928);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800729FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072A88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072A98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072AD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072B14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072B50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072B94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072BDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072BF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072CC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072CC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072CE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072CEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072D78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072D7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80072D8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073100);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073110);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073114);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073164);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800731D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073250);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800732B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800732C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007338C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800733F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073438);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800734A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800734CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800734D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800734E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800734E8);

void *func_800734F4(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_80098A54;
    void *stack[18];
    void **var_a3;
    register void *var_v0 asm("$2");
    void *var_v1;
    s32 var_t0;
    s32 temp_t1;
    u8 temp_v1;

    var_v1 = (void *) D_80098A54;
    var_t0 = 0;
    if (var_v1 != NULL) {
        temp_t1 = 0x86;
        var_a3 = stack;
        do {
            if (*(u8 *) (var_v1 + 0x7C) == arg0 &&
                *(u8 *) (var_v1 + 0x7D) == arg1 &&
                *(u8 *) (var_v1 + 0x7E) == arg2 &&
                *(u8 *) (var_v1 + 0x6) == temp_t1) {
                *var_a3 = var_v1;
                var_a3 += 1;
                var_t0 += 1;
            }
            var_v1 = *(void **) var_v1;
        } while (var_v1 != NULL);
    }
    var_v0 = NULL;
    if (var_t0 != 0) {
        register s32 var_a0 asm("$4");
        register void **var_a1 asm("$5");
        register s32 temp_s1 asm("$7");
        register s32 temp_s2 asm("$6");

        var_a0 = 0;
        if (var_t0 > 0) {
            var_a1 = stack;
            temp_s1 = D_80096118;
            temp_s2 = D_8009611C;
loop_11:
            var_v0 = *var_a1;
            temp_v1 = *(u8 *) (var_v0 + 4);
            var_a1 += 1;
            if (temp_v1 == temp_s1 || temp_v1 == temp_s2) {
                var_a0 += 1;
                var_v0 = NULL;
                var_v0 = (void *) (var_a0 < var_t0);
                if (var_v0 != 0) {
                    goto loop_11;
                }
                var_v0 = NULL;
            }
        }
    }
    return var_v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800735D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073618);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073638);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073678);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073688);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800736D4);

s32 func_800737B8(s32 arg0) {
    extern s32 *D_80098A54;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0v asm("a0");
    register s32 *key asm("a1");
    func_8007A6E4(arg0 & 0xFFFF);
    __asm__ volatile("addu $5,$2,$zero" : "=r"(key));
    __asm__ volatile(".set\tnoreorder\n\tbeqz %0,1f\n\tnop\n\t.set\treorder" : : "r"(key) : "memory");
    __asm__ volatile(".set\tnoreorder\n\tlui $3,%%hi(D_80098A54)\n\taddiu $3,$3,%%lo(D_80098A54)\n\tbeqz $3,1f+4\n\taddu $2,$0,$0\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile(".set\tnoreorder\n3:\n\tlw $2,0($3)\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 == (s32) key) {
        goto Lfound;
    }
    v1 = v0;
    __asm__ volatile(".set\tnoreorder\n\tbnez $3,3b\n\taddu $2,$0,$0\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("j func_8007A830" : : "r"(key));
Lfound:
    v0 = *(s32 *) key;
    a0v = (s32) &D_80098A54;
    *(s32 *) v1 = v0;
    v1 = *(s32 *) a0v;
    v0 = 1;
    *(s32 *) key = v1;
    __asm__ volatile(".set\tnoreorder\n\tj func_8007A830\n\tsw %1,0(%0)\n\t.set\treorder" : : "r"(a0v), "r"(key) : "memory");
    __asm__ volatile(".set\tnoreorder\n1:\n\taddu $2,$0,$0\n\t.set\treorder");
    return v0;
}

__asm__(".globl .L80073818\n.L80073818 = func_800737B8 + 0x60");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073840);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007399C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800739A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800739CC);

extern u8 *D_800962D0;
extern s32 D_800962CC;
extern s32 D_800962C8;

s32 func_800739E8(void) {
    register s32 idx asm("v1");
    register s32 ret asm("v1");
    register s32 f asm("v0");
    register s32 r2 asm("v0");
    register u8 *base asm("v0");
    u8 b;
    base = D_800962D0;
    idx = D_800962CC;
    b = base[idx];
    idx += 1;
    D_800962CC = idx;
    ret = b & 0xF;
    KEEP(ret);
    f = D_800962C8;
    f ^= 1;
    D_800962C8 = f;
    r2 = ret;
    return r2;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073A34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073AF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073AF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073B4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073B9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073BA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073EC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073EC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073ED4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073EEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073F44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073F9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073FB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80073FE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074050);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074068);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800740D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800741E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800741E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800741F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074204);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074308);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007436C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074454);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074470);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800744C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074594);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800745AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074678);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007467C);

extern void func_8007B58C();

void func_80074688(s32 arg0, s32 arg1) {
    func_8007B58C(arg0, arg1, 1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800746A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800746AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074784);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074790);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800747B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074814);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007485C);

void func_80074904(s32 arg0, s32 arg1, s32 arg2) {
    register s32 x asm("v0");
    register s32 y asm("v1");
    register volatile s16 *p asm("t0");
    register s16 d asm("v1");
    d = y - x;
    p[2] = d * 28 + arg2;
}

void func_8007492C(s32 arg0, s32 arg1) {
    func_8007B6C8(arg0, arg1, 1);
}

__asm__(".globl func_80074930\nfunc_80074930 = func_8007492C + 0x4");

extern void func_8007B6C8();

void func_8007494C(s32 arg0, s32 arg1) {
    func_8007B6C8(arg0, arg1, 5);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007496C);

void func_800749C8(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800749D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074A3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074B38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074B68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074B9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074BAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074BF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074DC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074DD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074E2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074E94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80074F5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800750A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800751AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075270);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800752C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800752F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075310);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075444);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075460);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800755A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800755DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800755E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800755E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800755FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075660);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075690);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800756A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800756F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075708);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007571C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075720);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075738);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075794);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800757C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800757EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007580C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075820);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007587C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075900);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075910);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075A6C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075C00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075C18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075C34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075CA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075D0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075D9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075DB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075E68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075F10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075FF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80075FF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007601C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076024);

s32 func_800760A0(u8 *arg0) {
    extern s32 func_8007A6E4(s32);
    if (arg0[0x130] == 1) {
        return func_8007A6E4(arg0[0x131]);
    }
    return (s32) arg0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800760D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800761CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076284);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007629C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800762A8);

__asm__(".globl .L80076344\n.L80076344 = func_800762DC + 0x68");

extern u8 *func_8007D0A0();
extern s32 func_8007D0D4(u8 *, s16 *);

s16 func_800762DC(u8 *arg0, s32 arg1) {
    register s32 a0v asm("a0");
    s32 s2r;
    s32 s0r;
    u8 *s1r;
    s32 v1;
    s32 v0;
    s1r = arg0;
    s0r = arg1;
    s2r = func_8007D0A0();
    a0v = s2r;
    a0v = func_8007D0D4(a0v, s0r);
    v1 = s1r[0x130];
    v0 = 1;
    if (v1 != v0) {
        v0 = a0v << 16;
    } else {
        v1 = *(u16 *) (s2r + 0x76);
        v0 = a0v - 0xA;
        a0v = v1 + v0;
        v0 = a0v << 16;
    }
    return v0 >> 16;
}

s32 func_80076350(void *arg0) {
    s16 sp[3];
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    s32 a0;
    u8 *s0;
    u8 *s1;

    s0 = (u8 *) arg0;
    s1 = func_8007D0A0();
    sp[0] = (s16) (s1[0x80] * 0x1C + 0xE);
    sp[2] = (s16) (s1[0x81] * 0x1C + 0xE);
    sp[1] = s1[0x82];
    temp_v0_2 = func_8007D0D4(s1, sp);
    a0 = temp_v0_2;
    temp_v1 = s0[0x130];
    var_v0 = 1;
    if (temp_v1 != var_v0) {
        var_v0 = a0 << 16;
    } else {
        temp_v1 = *(u16 *) (s1 + 0x76);
        var_v0 = a0 - 0xA;
        a0 = temp_v1 + var_v0;
        var_v0 = a0 << 16;
    }
    return var_v0 >> 16;
}

__asm__(".globl func_80076358\nfunc_80076358 = func_80076350 + 8");

struct F80076430 {
    u16 f10;
    u16 f12;
    u16 f14;
};

s16 func_800763F4(u8 *arg0) {
    s32 v0;
    s32 v1;
    u8 *s0r;
    s32 s1r;
    s32 a0v;
    struct F80076430 s;
    s0r = arg0;
    s1r = func_8007D0A0();
    s.f10 = *(u16 *) (s1r + 0x40);
    s.f14 = *(u16 *) (s1r + 0x44);
    s.f12 = ((u8 *) s1r)[0x7E];
    a0v = func_8007D0D4((u8 *) s1r, (s16 *) &s);
    v1 = s0r[0x130];
    v0 = 1;
    if (v1 != v0) {
        v0 = a0v << 16;
    } else {
        v1 = *(u16 *) (s1r + 0x76);
        v0 = a0v - 0xA;
        a0v = v1 + v0;
        v0 = a0v << 16;
    }
    return v0 >> 16;
}

__asm__(".globl func_80076430\nfunc_80076430 = func_800763F4 + 0x3C");

s32 func_80076478(void *arg0) {
    s16 sp[3];
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    s32 a0;
    u8 *s0;
    u8 *s1;

    s0 = (u8 *) arg0;
    s1 = func_8007D0A0();
    sp[0] = (s16) (s1[0x7C] * 0x1C + 0xE);
    sp[2] = (s16) (s1[0x7D] * 0x1C + 0xE);
    sp[1] = (s16) s1[0x7E];
    temp_v0_2 = func_8007D0D4(s1, sp);
    a0 = temp_v0_2;
    temp_v1 = s0[0x130];
    var_v0 = 1;
    if (temp_v1 != var_v0) {
        var_v0 = a0 << 16;
    } else {
        temp_v1 = *(u16 *) (s1 + 0x76);
        var_v0 = a0 - 0xA;
        a0 = temp_v1 + var_v0;
        var_v0 = a0 << 16;
    }
    return var_v0 >> 16;
}

s32 func_8007651C(s32 *arg0) {
    s32 *b;
    u16 buf[3];
    s32 r;
    s32 t;

    b = func_8007D0A0();
    buf[0] = *(u8 *) ((u8 *) *(u8 **) ((u8 *) b + 308) + 0x47) * 28 + 14;
    buf[2] = *(u8 *) ((u8 *) *(u8 **) ((u8 *) b + 308) + 0x48) * 28 + 14;
    buf[1] = *(u8 *) ((u8 *) b + 0x7E);
    r = func_8007D0D4(b, buf);
    if (*(u8 *) ((u8 *) arg0 + 0x130) == 1) {
        t = r - 10;
        r = *(u16 *) ((u8 *) b + 0x76) + t;
    }
    return (s16) r;
}

__asm__(".globl .L80076534\n.L80076534 = func_8007651C + 0x18");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800765D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076640);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076658);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076764);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800768F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800768F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007691C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800769A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800769B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076B1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076B44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076B64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076B7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076BE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076C50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076D50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076D84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076E74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076EC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076EFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076F14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80076FD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077098);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077120);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077134);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800771A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800772E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077304);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077314);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077344);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077378);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800773B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800773F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007763C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007772C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077738);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077760);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800777EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007798C);

void func_800779A0(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800779A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077A94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077B18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077B58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077B78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077B94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077BD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077BE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077C08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077C38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077CA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077D98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077DB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077E08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077E1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077E88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077EA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077EC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077F68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80077F98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078000);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078030);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078088);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800780A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078148);

extern void func_8007E9A8();
extern void func_8007EB8C();

void func_800781D4(void *arg0) {
    u8 temp_v1;

    temp_v1 = ((u8 *) arg0)[0x7F];
    if ((temp_v1 != 0x2D) && (temp_v1 != 0x31) && (temp_v1 != 0x39) && (temp_v1 != 0x35)) {
        func_8007E9A8();
    }
    if (((u8 *) arg0)[0x2DC] != 0) {
        func_8007EB8C(arg0);
    }
}

void func_80078240(void *arg0) {
    extern void func_80042B1C();
    s32 var_s2;

    *(s32 *) ((u8 *) arg0 + 0x2E8) = 1;
    for (var_s2 = 0; var_s2 < 6; var_s2++) {
        func_80042B1C((u8 *) arg0 + 0x2EC + var_s2 * 8, *(s16 *) ((u8 *) arg0 + 0x40), *(s16 *) ((u8 *) arg0 + 0x42), *(s16 *) ((u8 *) arg0 + 0x44));
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800782AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078310);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078328);

extern void func_8007B96C();

struct Func80078400_8 {
    u8 e[8];
};

void func_80078400(u8 *arg0) {
    register u8 *t0 asm("$8");
    register s32 a3v asm("$7");
    register u8 *a2v asm("$6");
    struct Func80078400_8 *s;
    struct Func80078400_8 *d;

    t0 = arg0;
    SCHED_BARRIER();
    a3v = 5;
    a2v = t0 + 0x28;
    do {
        s = (struct Func80078400_8 *) (a2v + 0x2E4);
        d = (struct Func80078400_8 *) (a2v + 0x2EC);
        *d = *s;
        a3v -= 1;
        a2v -= 8;
    } while (a3v > 0);
    func_8007B96C(t0 + 0x2EC, t0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007845C);

void func_80078504(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007850C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800785AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800785F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800786D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800786D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800787DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800787FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800788D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078964);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078ACC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078BF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078D20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078E58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80078FB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80079098);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800790A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800791E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80079298);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800792A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800793E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80079748);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800797AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800798B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80079918);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80079B14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80079BEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80079F44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80079FC4);

extern void func_800808B8();
extern void func_8008106C();
extern void func_80081078();

void func_80079FEC(void *arg0, s32 arg1) {
    register u8 *a0p asm("$4");
    register u8 *a1p asm("$5");
    register u8 *a2p asm("$6");
    register s32 a3v asm("$7");
    register s32 v0v asm("$2");
    register s32 v1v asm("$3");

    a2p = (u8 *) arg0;
    a3v = arg1;
    __asm__ volatile("lw $5,0x2c4($6)\nlw $4,0x2c8($6)\nlw $3,0x2cc($6)" : "=r"(a1p), "=r"(a0p), "=r"(v1v) : : "memory");
    v0v = 0x1F;
    *(u16 *) (v1v + 4) = v0v;
    *(u16 *) (a0p + 4) = v0v;
    *(u16 *) (a1p + 4) = v0v;
    __asm__ volatile(".set\tnoreorder\n\tori $2,$zero,2\n\tbeq $7,$2,.L80079FEC_mode2\n\tslti $2,$7,3\n\tbeqz $2,.L80079FEC_mode3_or\n\tori $2,$zero,1\n\tbeq $7,$2,.L80079FEC_mode1\n\tnop\n\tj func_80081078\n\tnop\n.L80079FEC_mode3_or:\n\tori $2,$zero,3\n\tbeq $7,$2,.L80079FEC_mode3\n\tlui $3,0x2000\n\tj func_80081078\n\tnop\n.L80079FEC_mode1:\n\tlw $2,0x1b8($6)\n\tj func_8008106C\n\tlui $3,0x0800\n.L80079FEC_mode2:\n\tlw $2,0x1b8($6)\n\tj func_8008106C\n\tlui $3,0x1000\n.L80079FEC_mode3:\n\t.set\treorder" ::: "memory");
mode3:
    v0v = *(u32 *) (a2p + 0x1B8);
    v0v |= v1v;
    *(u32 *) (a2p + 0x1B8) = v0v;
    v0v = a2p[0x2BC];
    if (v0v != 0) {
        goto end;
    }
    *(u16 *) (a2p + 0x2C2) = 0;
    a0p = a2p;
    func_800808B8(a0p, a1p, a2p, a3v);
end:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A0A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A154);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A15C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A1D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A218);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A25C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A2B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A3EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A3F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A4E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A4F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A5D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A6D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A6E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A724);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A774);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A7B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A830);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A840);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A944);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A958);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A968);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007A9B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AA14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AA34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AA80);

extern s16 func_8007D3F4();
extern s32 func_80089554();

void func_8007AB0C(s32 arg0) {
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a0v asm("a0");
    u8 *p;
    volatile u8 *q;

    s0v = arg0;
    a0v = s0v;
    p = (u8 *) s0v;
    q = (volatile u8 *) s0v;
    v0v = p[124];
    a1v = p[125];
    __asm__ volatile(".L8007AB24:" : : "r"(a1v));
    a2v = p[126];
    __asm__ volatile(".L8007AB28:" : : "r"(a2v));
    v1v = q[124];
    q[128] = v0v;
    v0v = (v1v << 3) - v1v;
    v0v = v0v << 2;
    v1v = q[125];
    v0v = v0v + 14;
    q[129] = a1v;
    q[130] = a2v;
    *(s16 *) (s0v + 64) = v0v;
    v0v = (v1v << 3) - v1v;
    v0v = v0v << 2;
    v0v = v0v + 14;
    __asm__ volatile(".L8007AB60:" : : "r"(v0v));
    __asm__ volatile(".set\tnoreorder\n\tjal func_8007D3F4\n\tsh $2,0x44($16)\n\t.set\treorder"
                     : : "r"(a0v), "r"(a1v) : "ra", "memory");
    __asm__ volatile("addu $4,$16,$zero");
    __asm__ volatile(".set\tnoreorder");
    v0v = func_80089554(s0v);
    *(volatile s16 *) (a0v + 66) = v0v;
    __asm__ volatile(".set\treorder");
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AB88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007ABA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007ABD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AC08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AC60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007ACAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AD08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AD24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AD54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AD7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AD84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007ADB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AE48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AECC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AED4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AF08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007AF44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B110);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B15C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B194);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B204);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B26C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B2BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B2DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B468);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B4A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B4EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B554);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B584);

void func_8007B58C(u8 *arg0) {
    register u8 *s0v asm("s0") = arg0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    v0 = *(s32 *) (s0v + 0x144) & 0x20;
    __asm__ volatile(".set\tnoreorder\n\tbeq %1,$0,1f\n\tlui $3,0x1000\n\t.set\treorder" : "=r"(v1) : "r"(v0) : "memory");
    __asm__ volatile(".set\tnoreorder\n\tlw $2,0x80($16)\n\tj .L800825CC\n\tor $2,$2,$3\n1:\n\t.set\treorder" : : : "memory");
    v1 = 0xEFFFFFFF;
    v0 = *(s32 *) (s0v + 0x80);
    v0 = v0 & v1;
    *(s32 *) (s0v + 0x80) = v0;
    MEMORY_BARRIER();
    v0 = *(s32 *) (s0v + 0x144) & 0x240;
    if (v0 != 0) {
        return;
    }
    v0 = *(s32 *) (s0v + 0x154) & 0x40;
    if (v0 != 0) {
        return;
    }
    __asm__ volatile(".set\tnoreorder\n\tjal func_8007D3F4\n\taddu $4,$16,$zero\n\t.set\treorder" : "=r"(v0) : : "ra", "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    *(s16 *) (s0v + 0x42) = v0;
    func_80089554(s0v);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B620);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B668);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B67C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B680);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B688);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B694);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B6A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B6C8);

extern s32 func_8017F020();

u32 func_8007B78C(void *arg0) {
    u8 *s0;
    u8 *s1;
    s32 v0v;
    s32 v1v;
    s16 x;
    s16 y;
    s32 q0;
    s32 q1;
    s32 temp_a0;

    s0 = (u8 *) arg0;
    x = *(s16 *) (s0 + 0x40);
    y = *(s16 *) (s0 + 0x44);
    q0 = x / 28;
    q1 = y / 28;
    s1 = func_80183FB4(q0, q1, s0[0x7E]);
    temp_a0 = *(u32 *) (s0 + 0x134);
    if (temp_a0 == 0) {
        goto value;
    }
    v1v = func_8017F020(temp_a0);
    v0v = v1v & 0x20;
    if (v0v != 0) {
        v0v = 0;
        goto ret;
    }
    temp_a0 = *(u32 *) (s0 + 0x144);
    v0v = temp_a0 & 0x20;
    if (v0v != 0) {
        v0v = 0;
        goto ret;
    }
    v0v = temp_a0 & 0xE;
    if (v0v != 0) {
        v0v = 1;
        goto ret;
    }
    v0v = v1v & 0x10;
    if (v0v != 0) {
        v0v = 1;
        goto ret;
    }
    v0v = temp_a0 & 1;
    if (v0v != 0) {
        v0v = 0;
        goto ret;
    }
value:
    v0v = s1[3] >> 5;
ret:
    __asm__ volatile(".L8007B78C_return:");
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B88C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B8DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B920);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B924);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B92C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B94C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B958);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B96C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007B9D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007BA04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007BA28);

extern void func_8007F45C();

void func_8007BA44(u8 *arg0, u8 *arg1) {
    register u8 *s1v asm("s1") = arg0;
    register u8 *s0v asm("s0") = arg1;
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    func_8007F45C(arg0, s1v[0x13A]);
    SCHED_BARRIER();
    a1v = 0;
    if (s0v == 0) {
        goto l8c;
    }
    a1v = s0v[0x7C];
    v1v = s1v[0x7C];
    SCHED_BARRIER();
    a0v = s0v[0x7D];
    v0v = s1v[0x7D];
    a1v = a1v - v1v;
    __asm__ volatile(".set\tnoreorder\n\tj func_80082A90\n\tsubu %0,%0,%1\n\t.set\treorder" ::"r"(a0v), "r"(v0v));
l8c:
    __asm__ volatile("addu $4,$zero,$zero" : "=r"(a0v));
    if (a1v < 0) {
        SCHED_BARRIER();
        a1v = -a1v;
    }
    if (a0v < 0) {
        SCHED_BARRIER();
        a0v = -a0v;
    }
    v0v = (a1v < 2);
    if (a1v > 0) {
        goto lab8;
    }
    if (a0v <= 0) {
        goto lad8;
    }
lab8:
    if (v0v == 0) {
        goto lac8;
    }
    if (a0v == 0) {
        goto lad8;
    }
lac8:
    v0v = (a0v < 2);
    if (a1v != 0) {
        goto laf0;
    }
    a0v = 0x4C;
    if (v0v == 0) {
        goto laf4;
    }
lad8:
    a0v = 0x39;
    a1v = *(s16 *) (s1v + 0x70);
    __asm__ volatile(".set\tnoreorder\n\tjal func_80081978\n\taddu $6,%2,$zero\n\t.set\treorder" ::"r"(a0v), "r"(a1v), "r"(s1v));
    TAIL_JUMP_NOP(func_80082B04);
laf0:
    a0v = 0x4C;
laf4:
    a1v = *(s16 *) (s1v + 0x70);
    a2v = (s32) s1v;
    __asm__ volatile(".set\tnoreorder\n\tjal func_80081988\n\tsb $0,0x2D0(%2)\n\t.set\treorder" ::"r"(a0v), "r"(a1v), "r"(a2v));
}

extern u8 D_80093E10[];
extern u8 D_80093DE8[];

void func_8007BB1C(u8 *arg0) {
    extern void func_80081978();
    u16 t;
    s32 i;
    s32 a0;
    t = *(u16 *) (arg0 + 0x138);
    i = D_80093E10[t * 3];
    a0 = D_80093DE8[i * 2];
    if (a0 != 0) {
        func_80081978(a0, *(s16 *) (arg0 + 0x70), arg0);
    }
}

extern u8 D_80093DE9[];

void func_8007BB80(u8 *arg0) {
    extern s32 func_8008278C();
    extern void func_80081978();
    u8 *s0;
    s32 s1;
    u16 t;
    s32 i;
    u32 v0;

    t = *(u16 *) (arg0 + 0x138);
    i = D_80093E10[t * 3];
    s1 = D_80093DE9[i * 2];
    if (s1 == 0) {
        return;
    }
    s0 = arg0;
    v0 = (u32) func_8008278C() & 0xFF;
    func_80081978(((v0 < 2) ? s1 : 9), *(s16 *) (s0 + 0x70), s0);
}

extern void func_80081978();
extern void func_8008288C();
extern void func_80082A44();
extern void func_80082CAC();
extern void func_80082CB4();
extern u8 D_80093E11[];
extern u8 D_80094749[];

void func_8007BC10(void *arg0) {
    register u8 *a2 asm("a2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0v asm("a0");

    a2 = (u8 *) arg0;
    v1 = D_80094749[*(u8 *) (a2 + 6) * 4];
    __asm__ volatile(".set\tnoreorder\n\tslti $2,%0,8\n\tbeqz $2,.L8007BC10_not_range\n\tslti $2,%0,5\n\tbnez $2,.L8007BC10_not_range\n\t.set\treorder" : : "r"(v1));
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,0x2c\n\tlh $5,0x70(%0)\n\tj func_80082CAC\n\tnop\n\t.set\treorder" : : "r"(a2));
    __asm__ volatile(".L8007BC10_not_range:");
not_range:
    a0v = D_80093E11[*(u16 *) (a2 + 0x138) * 3];
    v0 = 1;
    if (a0v != 0) {
        goto one;
    }
    func_8008288C(a2);
    TAIL_JUMP_NOP(func_80082CB4);
one:
    if (a0v != v0) {
        goto final;
    }
    func_80082A44(a2);
    TAIL_JUMP_NOP(func_80082CB4);
final:
    func_80081978(a0v, *(s16 *) (a2 + 0x70), a2);
}

extern s32 func_8008278C();
extern void func_80082D38();

void func_8007BCC4(u8 *arg0) {
    register s32 a0v asm("a0");

    s32 v1;
    s32 v0;
    s32 s1 = 1;
    u8 *s0;
    s0 = arg0;
    a0v = 0x1D;
    if (s0[0x130] == s1) {
        goto final;
    }
    v1 = func_8008278C(s0) & 0xFF;
    if (v1 == s1) {
        goto one;
    }
    v0 = v1 < 2;
    if (v0 == 0) {
        goto high;
    }
    if (v1 == 0) {
        a0v = 0x1C;
        goto final;
    }
    TAIL_JUMP_NOP(func_80082D38);
high:
    if (v1 == 2) {
        a0v = 9;
        goto final;
    }
    a0v = 9;
    TAIL_JUMP_NOP(func_80082D38);
one:
    a0v = 0x1D;
final:
    func_80081978(a0v, *(s16 *) (s0 + 0x70), s0);
}

void func_8007BD50(u8 *arg0) {
    extern s32 func_8008278C(u8 *);
    extern s32 func_8007A6E4(s32);
    extern void func_80081978();
    register u8 *s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0v asm("a0");

    s0 = arg0;
    a0v = 0x32;
    v1 = s0[0x130];
    v0 = 1;
    if (v1 == v0) {
        goto d4;
    }
    a0v = s0;
    v0 = func_8008278C(s0) & 0xFF;
    if ((s32) v0 < 0) {
        goto c8;
    }
    s1 = 2;
    if (v0 >= 2) {
        goto c8;
    }
    v0 = s0[0x130];
    if (v0 != s1) {
        goto cc;
    }
    a0v = s0[0x131];
    v0 = func_8007A6E4(a0v);
    if (v0 == 0) {
        goto cc;
    }
    func_80081978(0x32, *(s16 *) (s0 + 0x70), v0);
    TAIL_JUMP_NOP(label_80082DCC);
c8:
    s1 = 9;
cc:
    if (s1 == 0) {
        goto e0;
    }
    a0v = s1;
d4:
    func_80081978(a0v, *(s16 *) (s0 + 0x70), s0);
e0:;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007BDF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007BEEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C1B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C380);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C384);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C388);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C3E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C420);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C424);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C428);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C444);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C458);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C46C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C570);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C758);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C764);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C78C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C7B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C7DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C7EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C7F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C80C);

void func_8007C854(void) {
    func_80082EEC();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C874);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C978);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007C998);

void func_8007CC58(u8 *arg0) {
    s32 var_s0;
    s32 dummy;
    u8 temp_v0;
    s32 temp_v0_copy;
    s32 temp_v0_2;
    u8 *var_v0;

    temp_v0 = arg0[0x18D];
    if (temp_v0 != 0) {
        __asm__ volatile("" : "=r"(temp_v0_copy) : "0"(temp_v0), "m"(dummy));
        var_s0 = 0;
        if (temp_v0_copy != 0) {
            do {
                var_v0 = arg0 + var_s0;
                temp_v0_2 = func_8007A724(var_v0[0x18E]);
                if (temp_v0_2 != 0) {
                    func_80068E30(((u8 *) temp_v0_2)[4]);
                }
                var_s0 += 1;
                var_v0 = arg0 + var_s0;
            } while (var_s0 < (s32) arg0[0x18D]);
        }
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CCD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CE10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CF18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CF58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CF5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CFA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CFA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CFD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CFDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007CFF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D000);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D028);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D02C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D08C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D0A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D0D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D154);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D184);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D194);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D214);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D28C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D2B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D2DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D2E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D350);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D3F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D478);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D51C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D5D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D818);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D944);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007D948);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007DAA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007DAF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007DB1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E138);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E178);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E180);

extern void func_80084214();

void func_8007E234(void) {
    u8 *p;
    p = (u8 *) func_8007A1D4();
    if (p != 0) {
        func_80084214(p, p + 0x1D8, *(u16 *) (p + 0x1E0), *(u16 *) (p + 0x1DC));
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E26C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E2C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E2D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E304);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E4D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E72C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E940);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E948);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007E9A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EA18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EB4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EB8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EBF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EC0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EC60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EC8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EE78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EE7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EEA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EEC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007EEC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F088);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F1D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F240);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F2AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F308);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F400);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F45C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F50C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F55C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F578);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F5A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F5F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F630);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F640);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F874);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F90C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F93C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007F9D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007FADC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007FB44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007FC2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007FDCC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007FEF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8007FF2C);

extern void func_80086F2C();

void func_80080064(void) {
    extern s32 D_80098A54;
    s32 p;
    p = D_80098A54;
    if (p != 0) {
        do {
            func_80086F2C((void *) p);
            p = *(s32 *) p;
        } while (p != 0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800800AC);

extern void func_8007F1D4();
extern void func_800870AC();

void func_8008019C(void) {
    extern void func_80085C0C();
    extern s32 D_80098A54;
    s32 p;
    p = D_80098A54;
    if (p != 0) {
        do {
            func_80085C0C((void *) p);
            func_8007F1D4((void *) p);
            func_800870AC((void *) p);
            p = *(s32 *) p;
        } while (p != 0);
    }
}

extern s32 D_800A1C58;

void func_800801F4(void *arg0, void *arg1) {
    register u8 *t0 asm("t0");
    register s32 t1v asm("t1");
    register u8 *t2 asm("t2");
    register s32 t3v asm("t3");
    register u8 *a3v asm("a3");
    register u8 *a1v asm("a1");
    register u32 a2v asm("a2");
    register s32 a0v asm("a0");
    register s32 v0v asm("$2");
    register s32 v1v asm("v1");
    volatile s32 pad[2];

    t2 = (u8 *) arg1;
    KEEP(t2);
    a2v = 0;
    t3v = -1;
    KEEP(t3v);
    t0 = (u8 *) arg0;
    a3v = (u8 *) arg1;
    a3v += 4;
    t1v = D_800A1C58;
    KEEP(t1v);
    v0v = ((u8 *) arg1)[1];
    v1v = ((u8 *) arg1)[0];
    v0v <<= 8;
    KEEP(v0v);
    KEEP(v1v);
    v1v += v0v;
    *(s32 *) t0 = v1v;
    v0v = ((u8 *) arg1)[3];
    v1v = ((u8 *) arg1)[2];
    v0v <<= 8;
    KEEP(v0v);
    KEEP(v1v);
    v1v += v0v;
    *(s32 *) (t0 + 4) = v1v;
    do {
        v0v = a3v[1];
        a0v = a3v[0];
        v1v = a3v[2];
        v0v <<= 8;
        __asm__ volatile("addu $4,$4,$2" : "=r"(a0v) : "0"(a0v), "2"(v0v));
        v1v <<= 16;
        __asm__ volatile(".set\tnoreorder\n\tlbu $2,3($7)\n\taddu $4,$4,$3\n\tsll $2,$2,24\n\taddu $2,$4,$2\n\t.set\treorder" : "=r"(v0v), "=r"(a0v) : "r"(a3v), "r"(v1v));
        a3v += 4;
        if (v0v == t3v) {
            v0v = 0;
        }
        v0v += t1v;
        *(s32 *) (t0 + 8) = v0v;
        a2v += 1;
        t0 += 4;
    } while (a2v < 0x100);

    v0v = t2[0x405];
    v1v = t2[0x404];
    v0v <<= 8;
    KEEP(v0v);
    KEEP(v1v);
    a0v = v1v;
    a0v += v0v;
    a2v = 0;
    if (a0v != 0) {
        a1v = (u8 *) arg1 + 0x406;
        do {
            v0v = D_800A1C58;
            v1v = a1v[0];
            v0v += a2v;
            a2v += 1;
            *(u8 *) v0v = v1v;
            a1v += 1;
        } while (a2v < (u32) a0v);
    }
    v0v = a2v + D_800A1C58;
    D_800A1C58 = v0v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800802EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080388);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008038C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080394);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800803BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800803E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080504);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080574);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800805B4);

extern s32 D_800BF78C;
extern u8 *D_800BF78C_p asm("D_800BF78C");

void func_800805F0(s32 *arg0, u8 *arg1) {
    register u32 t0v asm("t0");
    register u8 *t1v asm("t1");
    register s32 t2v asm("t2");
    register u8 *t3v asm("t3");
    register s32 t4v asm("t4");
    register u8 *p asm("a2");
    register s32 off asm("a3");
    register u32 j asm("a0");
    u8 *q;
    u8 *w;
    s32 v;
    s32 cnt;

    __asm__ volatile("addiu $sp,$sp,-8");
    t3v = arg1;
    t0v = 0;
    off = (s32) arg0;
    p = arg1 + 4;
    do {
        *(u16 *) off = p[0] | (p[1] << 8);
        off = off + 2;
        p = p + 2;
        t0v = t0v + 1;
    } while (t0v < 0x20);
    off = 0x44;
    t0v = 0;
    t4v = -1;
    t2v = D_800BF78C;
    t1v = arg0;
    p = t3v + 0x44;
    do {
        v = p[0] + (p[1] << 8) + (p[2] << 16) + (p[3] << 24);
        if (v == t4v) {
            v = 0;
        }
        *(s32 *) (t1v + 0x40) = v + t2v;
        p = p + 4;
        off = off + 4;
        t0v = t0v + 1;
        t1v = t1v + 4;
    } while (t0v < 0x200);
    __asm__("addu %0, %1, %2" : "=&r"(w) : "r"(t3v), "r"(off));
    off = off + 2;
    cnt = w[0] + (w[1] << 8);
    j = 0;
    if (cnt != 0) {
        q = (u8 *) (off + (s32) arg1);
        do {
            D_800BF78C_p[j] = *q;
            j = j + 1;
            q = q + 1;
        } while (j < cnt);
    }
    v = j + D_800BF78C;
    D_800BF78C = v;
    __asm__ volatile("addiu $sp,$sp,8");
}

__asm__(".globl .L800805F4\n.L800805F4 = func_800805F0 + 0x4");

__asm__(".globl .L80080634\n.L80080634 = func_800805F0 + 0x44");

__asm__(".globl .L80080674\n.L80080674 = func_800805F0 + 0x84");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080704);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800807B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080884);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080888);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008088C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800808A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800808B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800809C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800809E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080A28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080AFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080EF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080EFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080F04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080F20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080F44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080F5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80080FEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008106C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081078);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800810A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081130);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800811D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081298);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008135C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081420);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800814E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800815A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800816B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081730);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081734);

__asm__(".globl .L8008182C\n.L8008182C = func_80081808 + 0x24");

void func_80081808(void) {
    s32 v0;
    s32 s0r;
    s0r = 0;
loop:
    func_8008719C();
    s0r = s0r + 1;
    v0 = s0r < 3;
    if (v0 != 0) {
        goto loop;
    }
}

extern s32 D_80098D74;
extern s32 D_80098D78;
extern s32 D_80098D7C;
extern s32 D_80098D80;

void func_80081840(void) {
    D_80098D74 = 0;
    D_80098D78 = 0;
    D_80098D7C = 0;
    D_80098D80 = 0;
}

extern s32 func_8013B590();
extern s32 func_801C5A50();
extern void func_8017F5F8();
extern void func_8017F620();
extern s32 *D_80096108;
extern s32 D_800459A0;
extern s32 D_80049C18;

void func_80081868(void) {
    register s32 a0v asm("a0");
    D_80049C18 = 0;
    if (func_8013B590(0x1FE) == 0) {
        if (D_80096108 == 0) {
            goto LC0;
        }
        a0v = (s32) &D_800459A0;
        __asm__ volatile("j func_800888CC" : : "0"(a0v) : "memory");
    }
    func_8017F5F8(func_801C5A50(), 0);
LC0:
    func_8017F620(func_801C5A50(), 0);
    D_80098D74 = 0;
    D_80098D78 = 0;
    D_80098D7C = 0;
    D_80098D80 = 0;
}

__asm__(".globl .L80081894\n.L80081894 = func_80081868 + 0x2C");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081904);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081978);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008197C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081988);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008198C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800819A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081A00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081A08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081A48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081A50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081A58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081A94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081AD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081AE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081AF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081B0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081B88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081C1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081C50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081C60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081C74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081CAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081CB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081CF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081D44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081D54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081DFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081E30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081E7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081EFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081F7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80081FA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008206C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008209C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800820B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082110);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082248);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008224C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082298);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800822BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082384);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082438);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008243C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082440);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082458);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008245C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082468);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082508);

extern void func_8008945C(s32, s32, s32, s32, s32);

void func_80082528(s32 arg0) {
    func_8008945C(arg0, 4, 0x1F, 0, 0);
}

__asm__(".globl .L80082548\n.L80082548 = func_80082528 + 0x20");

__asm__(".globl func_80082550\nfunc_80082550 = func_80082528 + 0x28");

__asm__(".globl lbl_80082590\nlbl_80082590 = func_80082528 + 0x68");

__asm__(".set\tpush\n.set\tnoreorder\n\tlh $2,0x40($4)\n\tlh $3,0x44($4)\n\tsll $2,$2,12\n\tsw $2,0x18($4)\n\tlh $2,0x42($4)\n\tsll $3,$3,12\n\tsw $3,0x20($4)\n\tsll $2,$2,12\n\tjr $31\n\tsw $2,0x1c($4)\n\tlw $2,0x18($4)\n\tnop\n\t.globl .L80082584\n.L80082584:\n\tbgez $2,lbl_80082590\n\tnop\n\t.set\treorder\n\t.set\tpop\n");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008258C);

extern void func_8007D478();

void func_800825C4(s32 arg0) {
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    u16 buf[4];

    s0v = arg0;
    v1v = ((u8 *) s0v)[0x7C];
    v0v = v1v * 28 + 14;
    buf[0] = v0v;
    v1v = ((u8 *) s0v)[0x7D];
    v0v = v0v << 12;
    *(s32 *) ((u8 *) s0v + 0x18) = v0v;
    v0v = v1v * 28 + 14;
    buf[2] = v0v;
    v0v = v0v << 12;
    *(s32 *) ((u8 *) s0v + 0x20) = v0v;
    func_8007D478();
    v0v = v0v << 12;
    *(s32 *) ((u8 *) s0v + 0x1C) = v0v;
}

__asm__(".globl .L800825CC\n.L800825CC = func_800825C4 + 0x8");

__asm__(".globl func_80082620\nfunc_80082620 = func_800825C4 + 0x5C");

__asm__(".set\tpush\n.set\tnoreorder\n\tjr $31\n\tnop\n\t.set\tpop\n");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082640);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082750);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008276C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008278C);

void func_80082790(s32 arg0, u8 *arg1, s32 arg2) {
    s32 v0v;
    s32 v1v;

    v1v = *(s32 *) (arg1 + 0x1C);
    v0v = arg0 < v1v;
    if (v0v) {
        v0v = arg2 + v1v;
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_800897B4\n\t"
                         "sw %0,0x1C(%1)\n\t"
                         ".set\treorder" ::"r"(v0v),
                         "r"(arg1) : "memory");
    }
    *(s32 *) (arg1 + 0x1C) = arg0;
    *(u8 *) (arg1 + 0x87) = 0;
    MEMORY_BARRIER();
    v0v = *(s32 *) (arg1 + 0x1C);
    if (v0v < 0) {
        v0v += 0xFFF;
    }
    v0v = v0v >> 12;
    *(s16 *) (arg1 + 0x42) = v0v;
    *(s32 *) (arg1 + 0x8C) = arg2;
    *(s32 *) (arg1 + 0x90) = arg0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800827DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008288C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800828A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082A20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082A44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082A90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082AF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082AFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082B04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082B1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082B80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082BA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082C10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082CAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082CB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082CC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082CF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082D38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082D50);

extern void func_800898A0();

void func_80082DA0(s32 arg0) {
    func_800898A0(arg0, 1);
}

extern void func_80089BA0();

void func_80082DC0(s32 arg0) {
    func_80089BA0(arg0, 1);
}

void func_80082DE0(s32 arg0) {
    func_800898A0(arg0, 0);
}

void func_80082E00(s32 arg0) {
    func_80089BA0(arg0, 0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082E20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082E60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082EC0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082EEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80082F24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800830EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083118);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008318C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800831B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800831F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008320C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083250);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083274);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800832F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008335C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083450);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083458);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008346C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800834AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008355C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083570);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800835C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800835E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083624);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083700);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008371C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083758);

extern void func_8008A7C8(s32, s32);
extern void func_8008A7D8(s32);
extern void func_8008A7EC();
extern void func_801A15B4(s32, s32, s32 *);
extern void func_80068B34(u8 *);
extern void func_80044018(s32);

s32 func_80083780(void *arg0) {
    u8 *s0;
    s32 v0;
    s32 v1;
    s32 a0v;
    s32 sp10[50];

    s0 = (u8 *) arg0;
    __asm__ volatile(".set\tnoreorder\n\tjal func_8008A6D8\n\taddiu $5,$sp,0x10\n\t.set\treorder");
    __asm__ volatile("lbu $3,6($16)" : "=r"(v1) : "r"(s0));
    __asm__ volatile(".set\tnoreorder\n\tori $2,$zero,0x41\n\tbeq $3,$2,.L80083780_b8\n\tori $2,$zero,0x49\n\t.set\treorder" : "=r"(v0) : "r"(v1));
    __asm__ volatile(".set\tnoreorder\n\tbeq $3,$2,.L80083780_c4\n\taddu $4,$zero,$zero\n\tj func_8008A7D8\n\tnop\n\t.set\treorder" : "=r"(v0), "=r"(a0v) : "r"(v1));
    __asm__ volatile(".L80083780_b8:");
    __asm__ volatile(".set\tnoreorder\n\taddu $4,$zero,$zero\n\tj func_8008A7C8\n\tori $5,$zero,0xb8\n\t.set\treorder");
    __asm__ volatile(".L80083780_c4:");
    func_801A15B4(a0v, 0x28, sp10);
    __asm__ volatile(".set\tnoreorder\n\tj func_8008A7EC\n\tori $2,$zero,1\n\t.set\treorder" : "=r"(v0));
    func_80068B34(s0);
    func_80044018(0x6B);
    v0 = 0;
    return v0;
}

extern void func_801A1880();
extern void func_800933C4(s32, s32, s32, s32, s32, s32);

void func_80083800(s32 arg0) {
    s32 s0v;
    s32 v0v;
    s32 v1v;
    s32 a0v;
    s32 a1v;
    s32 a2v;
    s32 a3v;

    s0v = arg0;
    v1v = ((u8 *) s0v)[6];
    v0v = 0x41;
    if (v1v == v0v) {
        goto A;
    }
    v0v = 0x49;
    a0v = 4;
    if (v1v != v0v) {
        goto B;
    }
A:
    func_801A1880();
    a0v = 4;
B:
    a1v = 2;
    a3v = 0x1F;
    v0v = ((u16 *) s0v)[9];
    a2v = ((u8 *) s0v)[4];
    v0v = v0v & 0xFF9F;
    v0v = v0v | 0x21;
    ((u16 *) s0v)[9] = v0v;
    v0v = 0x1F;
    func_800933C4(a0v, a1v, a2v, a3v, v0v, v0v);
    v0v = *(s32 *) ((u8 *) s0v + 0x88);
    *(s32 *) ((u8 *) s0v + 0x8C) = 0;
    v0v = v0v + 1;
    *(s32 *) ((u8 *) s0v + 0x88) = v0v;
}

__asm__(".globl func_80083854\nfunc_80083854 = func_80083800 + 0x54");

__asm__(".globl func_80083874\nfunc_80083874 = func_80083800 + 0x74");

extern u8 D_800961AC;

void func_80083884(u8 *arg0) {
    extern void func_800933C4();
    u8 *s0;
    u8 *v0;
    u8 v1;

    s0 = arg0;
    v1 = s0[6];
    if ((v1 == 0x41) || (v1 == 0x49)) {
        func_801A1880();
    }
    v0 = func_80183FB4(s0[0x7C], s0[0x7D], s0[0x7E]);
    func_80082468(s0, (v0[6] >> 2) & 3, 1);
    func_800933C4(4, 0, s0[4], -0x1F, -0x1F, -0x1F);
    v0 = (u8 *) ((s32 *) s0)[0x22];
    ((s32 *) s0)[0x23] = 0;
    ((s32 *) s0)[0x22] = (s32) v0 + 1;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083924);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083954);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083978);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008397C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083984);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083B20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083B34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083B3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083C38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083C58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083CD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083D70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083D78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083DF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083E00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083E10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80083F18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800840C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084170);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084174);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084184);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800841E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084214);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084234);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800845E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084674);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008467C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800846B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084750);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084758);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084770);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084810);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80084818);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008489C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800848C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800848CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800848D0);

extern s16 D_800A7784;
extern s16 D_800A7788;
extern u16 D_80096166;
extern u16 D_800A1C6C;
extern u16 D_800A1C6E;
extern u16 D_800A1C70;
extern u16 D_800C7CB0;
extern u16 D_800C7CB2;
extern u16 D_800C7CB4;
extern u8 D_800961AD;
extern u8 D_800961AE;
extern u8 D_800A77C0;
extern u8 D_800A77C1;
extern u8 D_800A77C2;

void func_800849DC(void) {
    s32 v0;
    s32 v1;
    s32 a0v;
    ASM_NOP();
    v0 = *(u16 *) &D_800A7784;
    v1 = *(u16 *) &D_800A7786;
    a0v = *(u16 *) &D_800A7788;
    D_800C7CB0 = v0;
    D_800C7CB2 = v1;
    D_800C7CB4 = a0v;
}

void func_80084A18(void) {
    s32 v0;
    s32 v1;
    s32 a0v;
    v0 = D_800C7CB0;
    v1 = D_800C7CB2;
    a0v = D_800C7CB4;
    D_800A7784 = v0;
    D_800A7786 = v1;
    D_800A7788 = a0v;
}

s16 *func_80084A50(void) {
    return &D_800A7784;
}

void func_80084A60(u16 *arg0) {
    s32 v0;
    v0 = arg0[0];
    D_800A7784 = v0;
    v0 = arg0[1];
    D_800A7786 = v0;
    v0 = arg0[2];
    D_800A7788 = v0;
}

void func_80084A8C(s32 arg0, s32 arg1) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a1v asm("a1");
    v0 = D_80045980;
    a1v = arg1 & 0xFFFF;
    a1v = a1v / v0;
    v1 = D_800A7784;
    v0 = *(s16 *) arg0;
    D_80096166 = a1v;
    a1v = D_80096166;
    v0 = v0 - v1;
    v0 = v0 / a1v;
    v1 = D_800A7786;
    D_800A1C6C = v0;
    v0 = *(s16 *) arg0;
    v0 = v0 - v1;
    v0 = v0 / a1v;
    v1 = D_800A7788;
    D_800A1C6E = v0;
    v0 = *(s16 *) arg0;
    v0 = v0 - v1;
    v0 = v0 / a1v;
    D_800A1C70 = v0;
}

void func_80084B20(s32 arg0, s32 arg1) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a1v asm("a1");
    v0 = D_80045980;
    a1v = arg1 & 0xFFFF;
    a1v = a1v / v0;
    v0 = *(s16 *) arg0;
    D_80096166 = a1v;
    v1 = D_80096166;
    v0 = v0 / v1;
    D_800A1C6C = v0;
    v0 = *(s16 *) (arg0 + 2);
    v0 = v0 / v1;
    D_800A1C6E = v0;
    v0 = *(s16 *) (arg0 + 4);
    v0 = v0 / v1;
    D_800A1C70 = v0;
}

void func_80084B94(void) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    v0 = D_80096166;
    if (v0 != 0) {
        v0 = v0 - 1;
        a1v = (s32) &D_800A7784;
        v1 = *(u16 *) a1v;
        a0v = (s32) &D_800A1C6C;
        a0v = *(u16 *) a0v;
        D_80096166 = v0;
        v1 = v1 + a0v;
        *(u16 *) a1v = v1;
        v0 = *(u16 *) &D_800A7786;
        a0v = D_800A1C6E;
        v1 = *(u16 *) &D_800A7788;
        a1v = D_800A1C70;
        v0 = v0 + a0v;
        v1 = v1 + a1v;
        D_800A7786 = v0;
        D_800A7788 = v1;
    }
}

void func_80084C0C(void) {
    s32 v0;
    s32 v1;
    s32 a0v;
    v0 = D_800961AC;
    v1 = D_800961AD;
    a0v = D_800961AE;
    D_800A77C0 = v0;
    D_800A77C1 = v1;
    D_800A77C2 = a0v;
}

void func_80084C44(void) {
    extern volatile u8 D_800A77C0;
    extern volatile u8 D_800A77C1;
    extern volatile u8 D_800A77C2;
    extern void func_800E77B8();
    s32 t0;
    s32 t1;
    u8 *p;
    s32 v1;

    v1 = D_800A77C0;
    t0 = D_800A77C1;
    t1 = D_800A77C2;
    p = &D_800961AC;
    p[0] = v1;
    D_800961AD = t0;
    D_800961AE = t1;
    func_800E77B8(9, p[0], D_800961AD, D_800961AE);
}

u8 *func_80084CAC() {
    return &D_800961AC;
}

void func_80084CBC(u8 arg0, u8 arg1, u8 arg2) {
    extern void func_800E77B8(s32, u8, u8, u8);
    u8 *p = &D_800961AC;
    *p = arg0;
    D_800961AD = arg1;
    D_800961AE = arg2;
    func_800E77B8(9, *p, D_800961AD, D_800961AE);
}

void func_80084D0C(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_800E77B8(s32, u8, u8, u8);
    register s32 a0v asm("$4");
    register s32 a1v asm("$5");
    register s32 a2v asm("$6");
    register s32 a3v asm("$7");
    register s32 v0v asm("$2");
    register s32 v1v asm("$3");

    a3v = arg0;
    v1v = (s32) &D_800961AC;
    a0v = arg0;
    KEEP_NOVOL(a0v);
    a0v <<= 16;
    v0v = *(volatile u8 *) v1v;
    a0v >>= 16;
    a0v = v0v + a0v;
    a0v = (a0v < v0v);
    if (a0v != 0) {
        v0v = 0xFF;
    } else {
        v0v = *(volatile u8 *) v1v;
        __asm__ volatile("addu $2,$7,$2" : "=r"(v0v) : "r"(a3v));
    }
    *(u8 *) v1v = (u8) v0v;
    MEMORY_BARRIER();

    a0v = (s32) &D_800961AD;
    v1v = *(volatile u8 *) a0v;
    MEMORY_BARRIER();
    v0v = a3v;
    v0v <<= 16;
    v0v >>= 16;
    v0v = v1v + v0v;
    if (v0v < v1v) {
        v0v = 0xFF;
    } else {
        v0v = *(volatile u8 *) a0v;
        __asm__ volatile("addu $2,$5,$2" : "=r"(v0v) : "r"(a1v));
    }
    *(u8 *) a0v = (u8) v0v;

    a0v = (s32) &D_800961AE;
    v1v = *(volatile u8 *) a0v;
    MEMORY_BARRIER();
    v0v = a2v;
    v0v <<= 16;
    v0v >>= 16;
    v0v = v1v + v0v;
    if (v0v < v1v) {
        v0v = 0xFF;
    } else {
        v0v = *(volatile u8 *) a0v;
        __asm__ volatile("addu $2,$6,$2" : "=r"(v0v) : "r"(a2v));
    }
    *(u8 *) a0v = (u8) v0v;

    a1v = D_800961AC;
    MEMORY_BARRIER();
    a2v = D_800961AD;
    MEMORY_BARRIER();
    a3v = D_800961AE;
    MEMORY_BARRIER();
    a0v = 9;
    func_800E77B8(a0v, a1v, a2v, a3v);
}

void func_80084DE4(void) {
    func_80068E30();
}

extern void func_80082D50();

void func_80084E04(s32 arg0) {
    func_80082D50(func_8007A6E4(arg0 & 0xFFFF));
}

extern void func_80082DF8(s32);

void func_80084E2C(s32 arg0) {
    func_80082DF8(func_8007A6E4(arg0 & 0xFFFF));
}

void func_80084E54(s32 arg0) {
    func_80082EEC(func_8007A6E4(arg0 & 0xFFFF));
}

void func_80084E7C(s32 arg0, s32 arg1) {
    s32 v0;
    v0 = func_8007A6E4(arg0 & 0xFFFF);
    if (v0 != 0) {
        func_80081978(arg1, *(s16 *) (v0 + 0x70), v0);
    }
}

void func_80084EBC(u8 *arg0) {
    extern s32 *D_80098A54;
    extern void func_80081978();
    s32 *s0v;
    u8 *s1v;
    s16 v1;

    s0v = D_80098A54;
    s1v = arg0;
    while (s0v != 0) {
        v1 = *(s16 *) ((u8 *) s0v + 0x6C);
        func_80081978(s1v, v1, s0v);
        s0v = *(s32 *) s0v;
    }
}

s32 func_80084F14() {
    return 1;
}

s32 func_80084F1C(s32 arg0) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    v0v = func_8007A6E4(arg0 & 0xFFFF);
    if (v0v == 0) {
        goto null;
    }
    __asm__ volatile("lh %0,0x70(%0)" : "=r"(v0v) : "0"(v0v));
    ASM_NOP();
    __asm__ volatile(".L80084F3C:");
    v1v = v0v >> 10;
    if (v0v < 0) {
        v1v = (v0v + 0x3FF) >> 10;
    }
    if (v1v < 0) {
        v0v = v1v + 3;
    } else {
        v0v = v1v;
    }
    v0v = v0v >> 2;
    v0v = v0v << 2;
    v0v = v1v - v0v;
    v0v = v0v << 16;
    __asm__ volatile(".set\tnoreorder\n\tj .L8008BF74\n\tsra $2,$2,16\n\t.set\treorder" : "=r"(v0v) : "0"(v0v));
null:
    return -1;
}

s32 func_80084F84(s32 arg0, s32 arg1) {
    register s32 s1v asm("s1") = arg0;
    register s32 s0v asm("s0") = arg1;
    register s32 a0v asm("a0");
    register s32 a2v asm("a2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    SCHED_BARRIER();
    a2v = func_8007A6E4(s1v & 0xFFFF);
    if (a2v == 0) {
        goto null;
    }
    v1v = s0v << 10;
    v0v = *(u16 *) (a2v + 0x1DC);
    a0v = v0v >> 1;
    *(s16 *) (a2v + 0x70) = (s16) v1v;
    if (a0v < 3) {
        a0v = 2;
    }
    func_80081988(a0v, (s16) (s0v << 10), a2v);
    __asm__ volatile(".set\tnoreorder\n\tj .L8008BFE4\n\taddu $2,$17,$zero\n\t.set\treorder" : "=r"(v0v) : "r"(s1v));
null:
    return -1;
}

s32 func_80084FFC(s32 arg0) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    s32 temp_v0;

    temp_v0 = func_8007A6E4(arg0 & 0xFFFF);
    if (temp_v0 == 0) {
        goto null;
    }
    v1v = *(s16 *) (temp_v0 + 0x6C);
    if (v1v < 0) {
        v0v = v1v + 3;
    } else {
        v0v = v1v;
    }
    v0v = v0v >> 2;
    v0v = v0v << 2;
    v0v = v1v - v0v;
    v0v = v0v << 16;
    __asm__ volatile(".set\tnoreorder\n\tj .L8008C044\n\tsra $2,$2,16\n\t.set\treorder" : "=r"(v0v) : "0"(v0v));
null:
    return -1;
}

s32 func_80085054(s32 arg0) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    s32 temp_v0;

    temp_v0 = func_8007A724(arg0 & 0xFFFF);
    if (temp_v0 == 0) {
        goto null;
    }
    v1v = *(s16 *) (temp_v0 + 0x6C);
    if (v1v < 0) {
        v0v = v1v + 3;
    } else {
        v0v = v1v;
    }
    v0v = v0v >> 2;
    v0v = v0v << 2;
    v0v = v1v - v0v;
    v0v = v0v << 16;
    __asm__ volatile(".set\tnoreorder\n\tj .L8008C09C\n\tsra $2,$2,16\n\t.set\treorder" : "=r"(v0v) : "0"(v0v));
null:
    return -1;
}

s32 func_800850AC(s32 arg0) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    v0v = func_8007A6E4(arg0 & 0xFFFF);
    if (v0v == 0) {
        goto null;
    }
    __asm__ volatile("lh %0,0x70(%0)" : "=r"(v0v) : "0"(v0v));
    v1v = v0v >> 8;
    if (v0v < 0) {
        v1v = (v0v + 0xFF) >> 8;
    }
    if (v1v < 0) {
        v0v = v1v + 0xF;
    } else {
        v0v = v1v;
    }
    v0v = v0v >> 4;
    v0v = v0v << 4;
    v0v = v1v - v0v;
    v0v = v0v << 16;
    __asm__ volatile(".set\tnoreorder\n\tj .L8008C104\n\tsra $2,$2,16\n\t.set\treorder" : "=r"(v0v) : "0"(v0v));
null:
    return -1;
}

s32 func_80085114(s32 arg0, s32 arg1) {
    register s32 s1v asm("s1") = arg0;
    register s32 s0v asm("s0") = arg1;
    register s32 a0v asm("a0");
    register s32 a2v asm("a2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    SCHED_BARRIER();
    a2v = func_8007A6E4(s1v & 0xFFFF);
    if (a2v == 0) {
        goto null;
    }
    v1v = s0v << 8;
    v0v = *(u16 *) (a2v + 0x1DC);
    a0v = v0v >> 1;
    *(s16 *) (a2v + 0x70) = (s16) v1v;
    if (a0v < 3) {
        a0v = 2;
    }
    func_80081988(a0v, (s16) (s0v << 8), a2v);
    __asm__ volatile(".set\tnoreorder\n\tj .L8008C174\n\taddu $2,$17,$zero\n\t.set\treorder" : "=r"(v0v) : "r"(s1v));
null:
    return -1;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008518C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800851E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800851E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80085200);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80085234);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008523C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008524C);

void func_80085260(void) {
}

s32 func_80085268(s32 arg0) {
    s32 v0;
    s32 p;

    v0 = func_8007A6E4(arg0 & 0xFFFF);
    p = v0;
    KEEP(p);
    __asm__ volatile(".set\tnoreorder\n\tbnez $3,1f\n\tori $2,$zero,1\n\tj 0x8008C294\n\taddu $2,$zero,$zero\n1:\n\t.set\treorder");
    *(u8 *) ((u8 *) p + 0x298) = v0;
    return 1;
}

__asm__(".globl func_8008526C\nfunc_8008526C = func_80085268 + 4");

extern s32 D_80096104;
extern s32 D_8009610C;
extern s32 D_800A778C;
extern s32 D_80098A54;
extern void func_8008C1C4();

__asm__(".globl L8008C2CC\nL8008C2CC = func_8008C1C4 + 0x108");

__asm__(".globl .L80085310\n.set .L80085310, func_800852DC + 0x34");

__asm__(".globl .L80085318\n.set .L80085318, func_800852DC + 0x3C");

__asm__(".globl .L8008531C\n.set .L8008531C, func_800852DC + 0x40");

s32 func_800852A4(s32 arg0) {
    s32 v0;
    v0 = func_8007A6E4(arg0 & 0xFFFF);
    if (v0 == 0) {
        __asm__ volatile(".set\tnoreorder\n\tj L8008C2CC\n\taddu $2,$zero,$zero\n\t.set\treorder");
    }
    *(u8 *) (v0 + 0x298) = 0;
    return 1;
}

void func_800852DC(s32 arg0, s32 arg1) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    v1 = D_800960E4;
    v0 = 0x35;
    D_80096104 = arg0;
    MEMORY_BARRIER();
    D_800960E4 = v0;
    D_800960E8 = v1;
    v0 = 0x100;
    if (arg1 != 0) {
        v0 = v0 / arg1;
    }
    D_8009610C = v0;
}

void func_80085320(s32 arg0, s32 arg1) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    v1 = D_800960E4;
    v0 = 0x38;
    D_80096104 = arg0;
    MEMORY_BARRIER();
    D_800960E4 = v0;
    D_800960E8 = v1;
    v0 = 0x100;
    if (arg1 != 0) {
        v0 = v0 / arg1;
    }
    D_8009610C = v0;
}

void func_80085364(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    v1 = D_800960E4;
    v0 = 0x3A;
    D_800960E4 = v0;
    D_800960E8 = v1;
    v0 = 0x100;
    if (arg0 != 0) {
        v0 = v0 / arg0;
    }
    D_8009610C = v0;
}

void func_800853A0(s32 arg0) {
    register s32 v0 asm("v0");
    v0 = 2;
    D_80045980 = v0;
    v0 = 0x3B;
    D_800960E4 = v0;
    v0 = 0x100;
    if (arg0 != 0) {
        v0 = v0 / arg0;
    }
    D_8009610C = v0;
    v0 = 1;
    D_800A778C = v0;
}

s32 func_800853E4(void) {
    s32 v0;
    s32 v1;
    v1 = D_80098A54;
    v0 = 0;
    if (v1 != 0) {
        do {
            v1 = *(s32 *) v1;
            v0 = v0 + 1;
        } while (v1 != 0);
    }
    return v0;
}

s32 func_80085410(s32 arg0) {
    s32 v0;
    v0 = func_8007A6E4(arg0 & 0xFFFF);
    if (v0 != 0) {
        return v0 + 0x40;
    }
    return 0;
}

s32 func_8008543C(s32 arg0) {
    s32 v0;
    v0 = func_8007A724(arg0 & 0xFFFF);
    if (v0 != 0) {
        return v0 + 0x40;
    }
    return 0;
}

extern s32 func_8007D51C();

s32 func_80085468(s32 arg0, s32 arg1) {
    s32 temp_s1;
    s32 temp_s0;
    BattleUnit *p;
    temp_s0 = func_8007A724(arg0 & 0xFFFF);
    temp_s1 = arg1;
    if (temp_s0 != 0) {
        p = *(BattleUnit **) (temp_s0 + 0x134);
        func_80183FB4(p->x, p->y, *(u16 *) &p->y >> 15);
        p = *(BattleUnit **) (temp_s0 + 0x134);
        *(u16 *) temp_s1 = (((p->x << 3) - p->x) << 2) + 0xE;
        p = *(BattleUnit **) (temp_s0 + 0x134);
        {
            s32 cv;
            cv = (((p->y << 3) - p->y) << 2) + 0xE;
            *(u16 *) (temp_s1 + 4) = cv;
            *(u16 *) (temp_s1 + 2) = func_8007D51C(temp_s0);
        }
        return 1;
    }
    return 0;
}

extern void func_8007B92C();
extern s32 func_8008C410(s32);

void func_80085518(s32 arg0, s32 arg1) {
    func_8007B92C(func_8008C410(arg0 & 0xFFFF), arg1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80085550);

struct Func800855F0_Node {
    struct Func800855F0_Node *next;
    u8 id;
    u8 pad[0x77];
    u8 x;
    u8 y;
    u8 z;
};

extern void func_80044A34(s32);
extern s32 func_8008C654(s32);

s32 func_800855F0(s32 arg0, u16 *out) {
    register s32 idv asm("a0");

    s32 v0;
    struct Func800855F0_Node *node;
    if (node != 0) {
        idv = arg0 & 0xffff;
        __asm__ volatile(".L800855F0_loop:");
        __asm__ volatile(".set\tnoreorder\n\tlbu $2,4($3)\n\tbne $2,$4,.L800855F0_next\n\tnop\n\t.set\treorder" : "=r"(v0) : "r"(node), "r"(idv));
        out[0] = node->x;
        out[2] = node->y;
        __asm__ volatile(".set\tnoreorder\n\tlbu $3,0x7e($3)\n\tori $2,$zero,1\n\tj func_8008C654\n\tsh $3,2($5)\n\t.set\treorder");
        __asm__ volatile(".L800855F0_next:");
        __asm__ volatile(".set\tnoreorder\n\tlw $3,0($3)\n\tnop\n\tbnez $3,.L800855F0_loop\n\tnop\n\t.set\treorder");
    }
    func_80044A34(0xC);
    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80085664);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008576C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800857CC);

s32 func_800858E4(s32 arg0, s32 arg1) {
    extern s32 func_8007A6E4();
    extern void func_80069130(s32, s32);
    s32 s0v = arg1;
    s32 v0v;
    s32 temp_s0;
    s32 temp_v0;

    SCHED_BARRIER();
    temp_s0 = func_8007A6E4(arg0 & 0xFFFF);
    temp_v0 = func_8007A6E4(s0v & 0xFFFF);
    if ((temp_s0 != 0) && (temp_v0 != 0)) {
        func_80069130(temp_s0, temp_v0);
        __asm__ volatile(".set\tnoreorder\n\tj .L8008C92C\n\tori %0,$zero,1\n\t.set\treorder" : "=r"(v0v) : : "memory");
    }
    return 0;
}

s32 func_80085940(s32 arg0, u16 *arg1) {
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    a0v = arg0 & 0xffff;
    a1v = func_8007A6E4(a0v);
    if (a1v == 0) {
        func_80044A34(0xc);
        __asm__ volatile(".set\tnoreorder\n\tj .L8008C9B0\n\taddu $2,$zero,$zero\n\t.set\treorder");
    }
    v0v = ((u16 *) a1v)[0x30];
    v1v = arg1[0];
    v0v = v0v + v1v;
    ((u16 *) a1v)[0x30] = v0v;
    v0v = ((u16 *) a1v)[0x31];
    v1v = arg1[1];
    v0v = v0v + v1v;
    v1v = ((u16 *) a1v)[0x32];
    ((u16 *) a1v)[0x31] = v0v;
    a0v = arg1[2];
    v0v = 1;
    v1v = v1v + a0v;
    ((u16 *) a1v)[0x32] = v1v;
    return v0v;
}

s32 func_800859C4(s32 arg0, u16 *arg1) {
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    a0v = arg0 & 0xffff;
    a1v = func_8007A6E4(a0v);
    if (a1v == 0) {
        func_80044A34(0xc);
        __asm__ volatile(".set\tnoreorder\n\tj .L8008CA34\n\taddu $2,$zero,$zero\n\t.set\treorder");
    }
    v0v = ((u16 *) a1v)[0x30];
    v1v = arg1[0];
    v0v = v0v + v1v;
    ((u16 *) a1v)[0x30] = v0v;
    v0v = ((u16 *) a1v)[0x31];
    v1v = arg1[1];
    v0v = v0v + v1v;
    v1v = ((u16 *) a1v)[0x32];
    ((u16 *) a1v)[0x31] = v0v;
    a0v = arg1[2];
    v0v = 1;
    v1v = v1v + a0v;
    ((u16 *) a1v)[0x32] = v1v;
    return v0v;
}

__asm__(".globl .L800859D4\n.L800859D4 = func_800859C4 + 0x10");

__asm__(".globl .L800859E4\n.L800859E4 = func_800859C4 + 0x20");

__asm__(".globl func_80085A18\nfunc_80085A18 = func_800859C4 + 0x54");

s32 func_80085A48(s32 arg0) {
    s32 v0;
    v0 = func_8007A6E4(arg0 & 0xFFFF);
    if (v0 != 0) {
        return v0 + 0x60;
    }
    func_80044A34(0xC);
    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80085A7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80085BA0);

s32 func_80085BB4(s32 arg0) {
    return func_8007A6E4(arg0 & 0xFFFF) != 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80085BD8);

void func_80085C0C(void) {
}

void func_80085C14(s32 arg0) {
    arg0 = func_8007A6E4(arg0 & 0xFFFF);
    if (arg0 != 0) {
        *(s32 *) (arg0 + 0x80) &= 0xFEFFFFFF;
    }
}

void func_80085C50(s32 arg0) {
    s32 v1;
    v1 = func_8007A6E4(arg0 & 0xFFFF);
    if (v1 != 0) {
        *(u8 *) (v1 + 0x13F) = 2;
    }
}

void func_80085C80(s32 arg0) {
    s32 v0;
    v0 = func_8007A6E4(arg0 & 0xFFFF);
    if (v0 != 0) {
        *(u8 *) (v0 + 0x13F) = 0;
    }
}

void func_80085CAC(s32 arg0) {
    arg0 = func_8007A6E4(arg0 & 0xFFFF);
    if (arg0 != 0) {
        *(s32 *) (arg0 + 0x80) |= 0x4000000;
    }
}

void func_80085CE8(s32 arg0) {
    arg0 = func_8007A6E4(arg0 & 0xFFFF);
    if (arg0 != 0) {
        *(s32 *) (arg0 + 0x80) &= 0xFBFFFFFF;
    }
}

extern void func_80081D54();

void func_80085D24(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_8007A6E4(arg0 & 0xFFFF);
    if (temp_v0 != 0) {
        func_80081D54(temp_v0, 0, 1);
    }
}

void func_80085D58(s32 arg0) {
    arg0 = func_8007A6E4(arg0 & 0xFFFF);
    if (arg0 != 0) {
        *(s32 *) (arg0 + 0x80) |= 0x2000000;
    }
}

void func_80085D94(s32 arg0) {
    arg0 = func_8007A6E4(arg0 & 0xFFFF);
    if (arg0 != 0) {
        *(s32 *) (arg0 + 0x80) &= 0xFDFFFFFF;
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80085DD0);

s32 func_80085ED0(s32 arg0) {
    s32 v0;
    v0 = func_8007A724(arg0 & 0xFFFF);
    if (v0 != 0) {
        return v0 + 0x15C;
    }
    return 0;
}

s32 func_80085EFC(s32 arg0) {
    extern s32 func_8007A6E4(s32);
    s32 v0v;

    v0v = func_8007A6E4(arg0 & 0xFFFF);
    __asm__ volatile(".set\tnoreorder\n\tbeqz %0,1f\n\tnop\n\tlbu %0,0x9C(%0)\n\tj D_8008CF2C\n\tsltu %0,$zero,%0\n1:\tjal func_80044A34\n\tori $4,$zero,0xc\n\taddu %0,$zero,$zero\n\t.set\treorder"
                     : "=r"(v0v));
    return v0v;
}

void func_80085F3C(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8007A6E4(arg1 & 0xFFFF);
    if (temp_v0 != 0) {
        func_80083758(arg0, temp_v0);
    }
}

extern void func_8008E540();

s32 func_80085F78(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    register s32 var_s0 asm("$16");
    register s32 var_s1 asm("$18");
    register s32 var_s2 asm("$17");
    register s32 var_s3 asm("$19");
    register s32 var_s4 asm("$20");
    register s32 var_s5 asm("$21");
    register s32 var_s6 asm("$22");
    register s32 ret asm("$2");
    s16 temp_arg4;
    s16 temp_arg5;

    var_s0 = arg0;
    var_s5 = arg1;
    var_s6 = arg2;
    var_s4 = arg3;
    var_s1 = arg4;
    var_s2 = arg5;
    var_s3 = arg6;
    if (func_8007A6E4(var_s2 & 0xFFFF) != 0) {
        ret = 0;
    } else {
        D_80049C18 = 0;
        D_80098D74 = 0;
        D_80098D78 = 0;
        D_80098D7C = 0;
        D_80098D80 = 0;
        temp_arg4 = (s16) var_s1;
        temp_arg5 = (s16) var_s2;
        func_8008E540(var_s0, var_s5, var_s6, (s16) var_s4, temp_arg4, 0,
                      temp_arg5, 0, var_s3);
        ret = 1;
    }
    return ret;
}

extern s32 func_80180AFC();
extern s32 func_8017FD08();

s32 func_8008605C(s32 arg0, s32 arg1) {
    s32 s0;
    s32 s1;
    s32 tmp;
    u16 h;
    s0 = arg0;
    D_80049C18 = 0;
    D_80098D74 = 0;
    D_80098D78 = 0;
    D_80098D7C = 0;
    D_80098D80 = 0;
    s1 = arg1;
    tmp = func_80180AFC(s0, s1);
    func_8017FD08(s0);
    s0 = tmp;
    h = *(u16 *) (s0 + 0x48);
    func_8008E540(*(u8 *) (s0 + 0x47), *(u8 *) (s0 + 0x48), h >> 15, (h >> 8) & 0xF,
                  *(u8 *) (s0 + 0x15F), *(u8 *) (s0 + 0x160), 0xFF, s0, s1);
    return 1;
}

extern s32 func_80088904();

void func_80086104(void) {
    do {
    } while (func_80088904() == 2);
    __asm__ volatile(".set .L80086120, . - 4");
}

s32 func_80086138(s32 arg0) {
    extern s32 func_8007A6E4(s32);
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    a0v = arg0 & 0xFFFF;
    v1v = func_8007A6E4(a0v);
    v0v = 1;
    if (v1v == 0) {
        goto l78;
    }
    a0v = *(s32 *) ((u8 *) v1v + 0x134);
    *(u16 *) ((u8 *) v1v + 0xA) = v0v;
    *(u16 *) ((u8 *) v1v + 0x1D8) = v0v;
    if (a0v == 0) {
        goto l70;
    }
    __asm__ volatile(".L80086164:");
    a0v = ((u8 *) a0v)[0x18A];
    func_8017FD08(a0v);
l70:
    __asm__ volatile(".set\tnoreorder\n\tj D_8008D17C\n\tori $2,$zero,1\n\t.set\treorder");
l78:
    v0v = 0;
    return v0v;
}

void func_8008618C(s32 arg0) {
    extern s32 func_8007A6E4(s32);
    register s32 p asm("v1");

    p = func_8007A6E4(arg0 & 0xFFFF);
    __asm__ volatile(".set\tnoreorder\n\tbnez $3,1f\n\tori $2,$zero,1\n\tj D_8008D1B8\n\taddu $2,$zero,$zero\n1:\n\t.set\treorder");
    *(u16 *) ((u8 *) p + 0xA) = 0;
    *(u16 *) ((u8 *) p + 0x1D8) = 0;
    __asm__ volatile(".set .L800861B8, .");
}

extern void func_8008D18C();

void func_800861C8(void) {
    extern s32 D_80098A54;
    u8 *p;
    p = (u8 *) D_80098A54;
    if (p != 0) {
        do {
            if ((*(s32 *) (p + 0x144) & 0x40) != 0) {
                func_8008D18C(p[4]);
            }
            p = *(u8 **) p;
        } while (p != 0);
    }
}

s32 func_80086228(s32 arg0) {
    extern s32 func_8007A6E4(s32);
    s32 v0v;

    v0v = func_8007A6E4(arg0 & 0xFFFF);
    __asm__ volatile(".set\tnoreorder\n\tbnez %0,1f\n\tnop\n\tjal func_80044A34\n\tori $4,$zero,0xc\n\tj D_8008D25C\n\taddu %0,$zero,$zero\n1:\tjal func_80086F2C\n\taddu $4,%0,$zero\n\tori %0,$zero,1\n\t.set\treorder"
                     : "=r"(v0v));
    return v0v;
}

void func_8008626C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    extern void func_8008945C();
    s16 v0;

    v0 = arg4;
    func_8008945C(arg0, arg1, arg2, arg3, v0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800862A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008638C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800864C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800864C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800865A4);

void func_800865C0(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800865C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086640);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086708);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800867CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008692C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086998);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800869AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086AB4);

extern s32 D_800A8728;

void func_80086AC0(s32 arg0, s32 arg1, s32 arg2) {
    s32 s0v;
    s32 s1v;
    s32 v0v;
    s32 a0v;

    v0v = arg1 * 477;
    s0v = v0v * 63 + arg1;
    s0v = s0v + (s32) &D_800A8728;
    s1v = arg2 * 32;
    a0v = s0v + s1v;
    func_800926D8(a0v, 3, arg0, 0);
    s1v = s1v + 0x100;
    a0v = s0v + s1v;
    func_800926D8(a0v, 0xA, arg0, 0);
}

__asm__(".globl func_80086B44\nfunc_80086B44 = func_80086AC0 + 0x84");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086B54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086BDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086BE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086C14);

extern void func_8008DC24();

void func_80086C74(s32 arg0) {
    func_8008DC24(func_8007A6E4(arg0 & 0xFFFF));
}

void func_80086C9C(s32 arg0) {
    func_8008DC24(func_8007A724(arg0 & 0xFFFF));
}

extern void func_801A15B4();

__asm__(".globl .L80086CEC\n.L80086CEC = func_80086CC4 + 0x28");

void func_80086CC4(s32 arg0) {
    u8 buf[0xC8];

    *(s16 *) (buf + 0x00) = 1;
    *(s16 *) (buf + 0xA4) = 0;
    *(u8 *) (buf + 0xA6) = 0;
L86CEC:
    *(s16 *) (buf + 0x04) = 0;
    *(u8 *) (buf + 0x06) = 1;
    *(u8 *) (buf + 0x07) = 0;
    *(u8 *) (buf + 0x02) = 0;
    func_801A15B4(0, arg0, buf);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086D10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086D68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086DA8);

void func_80086DC4(void) {
}

#define DEAD_TAIL_LOAD(reg, sym, op) __asm__(".set push\n.set noreorder\nlui $" #reg ", %hi(" #sym ")\n" #op " $" #reg ", %lo(" #sym ")($" #reg ")\n.set pop\n");
#define DEAD_TAIL_LW(reg, sym) DEAD_TAIL_LOAD(reg, sym, lw)

void func_80086DCC(void) {
    func_801A1880();
}

DEAD_TAIL_LW(2, D_8009612C);

__asm__(".set push\n.set noreorder\njr $31\nnop\n.set pop\n");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086DFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086EB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086EE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80086EE8);

void func_80086F28(void) {
    func_80042B1C();
}

__asm__(".globl func_80086F2C\nfunc_80086F2C = func_80086F28 + 0x4");

extern u8 D_800E4E9C;
extern u8 func_800E4EA0;

void func_80086F48(s32 arg0) {
    extern void func_80042B1C();
    func_80042B1C(arg0, D_800E4E9C, 0, func_800E4EA0);
}

void func_80086F78(s32 arg0) {
    s32 v0;
    v0 = func_8007A6E4(arg0 & 0xFFFF);
    func_80183FB4(*(u8 *) (v0 + 0x7C), *(u8 *) (v0 + 0x7D), *(u8 *) (v0 + 0x7E));
}

void func_80086FAC(s32 arg0) {
    s32 v0;
    v0 = func_8007A724(arg0 & 0xFFFF);
    func_80183FB4(*(u8 *) (v0 + 0x7C), *(u8 *) (v0 + 0x7D), *(u8 *) (v0 + 0x7E));
}

void func_80086FE0(s32 arg0) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");
    register s32 t0v asm("t0");

    v0v = func_8007A6E4(arg0 & 0xFFFF);
    t0v = 0x92492493;
    v1v = *(u16 *) ((u8 *) v0v + 0x40);
    v1v = v1v << 16;
    a1v = v1v >> 16;
    __asm__ volatile("mult %0,%1" : : "r"(a1v), "r"(t0v));
    a2v = *(u16 *) ((u8 *) v0v + 0x44);
    __asm__ volatile("mfhi %0" : "=r"(a0v));
    a2v = a2v << 16;
    a3v = a2v >> 16;
    __asm__ volatile("mult %0,%1" : : "r"(a3v), "r"(t0v));
    v1v = v1v >> 31;
    a2v = a2v >> 31;
    a0v = a0v + a1v;
    a0v = a0v >> 4;
    a0v = a0v - v1v;
    a0v = (s16) a0v;
    __asm__ volatile("mfhi %0" : "=r"(a1v));
    a1v = a1v + a3v;
    a1v = a1v >> 4;
    a1v = a1v - a2v;
    a1v = a1v << 16;
    __asm__ volatile(".L8008704C:" : : "r"(a1v));
    a2v = ((u8 *) v0v)[0x7E];
    __asm__ volatile(".set\tnoreorder\n\tjal func_80183FB4\n\tsra $5,$5,16\n\t.set\treorder"
                     : : "r"(a0v), "r"(a1v), "r"(a2v) : "ra", "memory");
    __asm__ volatile(".set\tnoreorder");
}

__asm__(".globl func_80087064\nfunc_80087064:\n\tnop\n.set\treorder");

extern s32 func_800F3718(s32, s32);

s32 func_80087068(void) {
    return func_800F3718(D_80096104, 0x75) != 0;
}

extern void func_800F0BE0();

void func_80087094(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    func_800F3718(D_80096104, 0x76);
}

__asm__(".globl func_800870AC\nfunc_800870AC = func_80087094 + 0x18");

s32 func_800870BC(s32 arg0, s32 arg1) {
    func_800F0BE0(0x80, arg0, arg1, 1);
    return 1;
}

void func_800870F0(s32 arg0) {
    func_800F0BE0(0x81, arg0, 1, 1);
}

s32 func_8008711C(s32 arg0, s32 arg1) {
    func_800F0BE0(0x83, arg0, arg1, 1);
    return 1;
}

void func_80087150(void *arg0) {
    func_800F0BE0(0x82, arg0, 1, 1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008717C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087188);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008719C);

void func_800871F0(void) {
    return;
}

s32 func_800871F8(s32 arg0) {
    extern void func_800683E4(s32);
    s32 temp_v0;

    temp_v0 = func_8007A724(arg0 & 0xFFFF);
    __asm__ volatile(".set\tnoreorder\n\tbnez $2,1f\n\tnop\n\tj D_8008E224\n\taddu $2,$zero,$zero\n1:\n\t.set\treorder");
    func_800683E4(temp_v0);
    return 1;
}

struct Func80087234_Obj {
    u8 pad[0x7C];
    u8 unk7C;
    u8 unk7D;
    u8 unk7E;
    u8 pad2[0x10E];
    u8 unk18D;
    u8 unk18E;
};

extern s32 D_8008E2AC();

s32 func_80087234(s32 arg0, s32 arg1) {
    extern void func_80042B1C();
    extern void func_801B0818(s32, void *, s32);
    struct Func80087234_Obj *p;
    struct Func80087234_Obj *q;
    register s32 v0v asm("$2");
    register s32 v1v asm("$3");
    u8 buf[8];

    p = (struct Func80087234_Obj *) func_8007A724(arg0 & 0xFFFF);
    q = (struct Func80087234_Obj *) func_8007A724(arg1 & 0xFFFF);
    if (q != 0) {
        func_80042B1C(buf, q->unk7C, q->unk7D, q->unk7E);
        func_801B0818(arg0, buf, arg1);
        if (p != 0) {
            v0v = 1;
            USE(v0v);
            v1v = 1;
            p->unk18D = (u8) v1v;
            __asm__ volatile(".set\tnoreorder\n\tj D_8008E2AC\n\tsb %1,0x18E(%0)\n\t.set\treorder" ::"r"(p), "r"(arg1) : "memory");
        }
    }
    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800872C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800872EC);

extern void func_80042B2C(s32 *, s32, s32, s32);
extern void func_80042B1C(u16 *, u16, u16, u16);
extern s32 D_800E4E74;
extern s32 D_800E4E7C;
extern s32 D_800E4E78;

void func_80087358(s16 *arg0, u16 *arg1) {
    s32 w1;
    s32 w2;
    s32 w3;
    s32 *p = &D_800E4E74;
    u16 *d;
    s32 v2;
    s32 v4;
    s32 v5;
    u8 *q;

    func_80042B2C(p, -arg0[0] << 12, -arg0[1] << 12, -arg0[2] << 12);
    __asm__ volatile("lui %0,%%hi(D_800A7784)\n\taddiu %0,%0,%%lo(D_800A7784)" : "=r"(d));
    w1 = arg1[0];
    w2 = arg1[1];
    w3 = arg1[2];
    w1 &= 0x1FFF;
    __asm__ volatile(".globl func_800873BC\nfunc_800873BC:");
    w2 &= 0x1FFF;
    w3 &= 0x1FFF;
    func_80042B1C(d, w1, w2, w3);
    D_800961B8 = 0;
    v4 = *p / 0x1C000;
    v5 = D_800E4E7C / 0x1C000;
    D_800961B4 = v4;
    D_800961BC = v5;
    q = func_80183FB4(v4, v5, 0);
    v2 = q[2];
    D_800E4E78 = -v2 * 0xC000;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087468);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800875F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800876D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087704);

void func_800877B0(void) {
}

extern s32 func_80042880();
extern void func_800449CC();
extern void func_8017F8A0();
extern s32 D_80047604;

s32 func_800877B8(void) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = func_80042880();
    if (temp_v0 != -1) {
        var_v0 = 1;
        if (temp_v0 != 0) {
            func_8017F8A0(temp_v0, 0);
            func_800449CC(D_80047604);
            goto block_3;
        }
    } else {
block_3:
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008780C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800878A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800878E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800879B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087A0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087A28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087A2C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087A6C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087BCC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087C70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087EDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087FB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80087FE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088018);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008811C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088130);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088220);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088420);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088498);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800884D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008853C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088644);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088680);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800886B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088710);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800887E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800887EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088808);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088840);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088868);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800888CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088904);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088A10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088B1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088BF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088C28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088E14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088EB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80088EEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089048);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089054);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089080);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800890B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800890F4);

extern void func_80090048();
extern s32 D_800A1B48;
extern s32 D_800A1B4C;

typedef struct {
    char c[4];
} S4;

void func_800891F8(s32 arg0, u8 *arg1) {
    s32 s0v;
    S4 *d;

    s0v = (s32) arg1;
    func_80090048(arg0, arg1);
    d = (S4 *) &D_800A1B48;
    *d = *(S4 *) s0v;
    d = (S4 *) &D_800A1B4C;
    *d = *(S4 *) ((u8 *) s0v + 4);
}

__asm__(".globl .L80089208\n.L80089208 = func_800891F8 + 0x10");

__asm__(".globl func_8008924C\nfunc_8008924C = func_800891F8 + 0x54");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089258);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089384);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008945C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800894A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089528);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089554);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008957C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800895C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008969C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089730);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800897B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800897D4);

extern s32 D_800A1B70;
extern void func_8009069C();

void func_800897FC(s32 a0, s32 a1) {
    typedef struct {
        char c[4];
    } W;
    s32 s0 = a1;
    func_8009069C(a0);
    *(W *) &D_800A1B70 = *(W *) s0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089840);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089864);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089884);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_800898A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089AA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089AB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089AFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089B4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089B50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089BA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089C48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089D4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089D50);

extern s32 D_800A1B94;
extern void func_80090C48();

void func_80089DA8(s32 a0, s32 a1) {
    typedef struct {
        char c[4];
    } W;
    s32 s0 = a1;
    func_80090C48(a0);
    *(W *) &D_800A1B94 = *(W *) s0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089DEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_80089E20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A040);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A060);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A06C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A0D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A0D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A26C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A2A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A304);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A464);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A468);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A60C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A640);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A694);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A698);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A6D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A6E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A6F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A700);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A748);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A758);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A76C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A780);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A798);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A7C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A7D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A7EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A800);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008A884);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008AAE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008AAF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008AB20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008ACF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008AD78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008ADB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008ADB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008AFAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008AFBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B078);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B1EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B1F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B234);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B27C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B280);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B2FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B30C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B440);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B6D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B6E4);

void func_8008B7B4() {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B7BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B824);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B834);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008B968);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008BA50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008BA60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008BA8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008BB94);

extern void func_800927BC();

void func_8008BD4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7) {
    func_800927BC(8, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

typedef struct {
    char c[4];
} S4_BDC0;

extern s32 D_800A1B18;
extern s32 D_800A1B1C;
extern s32 D_800A1B20;
extern s32 D_800A1B30;
extern s32 D_800A1B34;
extern s32 D_800A1B38;

void func_8008BDC0(s32 arg0, s32 arg1, s32 arg2) {
    register s32 a0v asm("a0");
    register s32 a2v asm("a2") = arg2;
    register s32 r asm("v0");
    volatile s32 pad[4];
    a0v = 0x57;
    __asm__ volatile(".set\tnoreorder\n\tjal func_800E8190\n\tmove $5,$6\n\t.set\treorder" : "=r"(r) : "r"(a0v), "r"(a2v) : "ra", "$3", "$4", "$5", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    a2v = r;
    *(S4_BDC0 *) &D_800A1B48 = *(S4_BDC0 *) a2v;
    *(S4_BDC0 *) &D_800A1B4C = *(S4_BDC0 *) ((u8 *) a2v + 4);
    D_800A1B18 = ((u8 *) a2v)[0] << 16;
    D_800A1B1C = ((u8 *) a2v)[1] << 16;
    D_800A1B20 = ((u8 *) a2v)[2] << 16;
    D_800A1B30 = ((u8 *) a2v)[4] << 16;
    D_800A1B34 = ((u8 *) a2v)[5] << 16;
    D_800A1B38 = ((u8 *) a2v)[6] << 16;
}

__asm__(".globl func_8008BE54\nfunc_8008BE54 = func_8008BDC0 + 0x94");

__asm__(".globl func_8008BE7C\nfunc_8008BE7C = func_8008BDC0 + 0xBC");

typedef struct {
    char c[4];
} S4_BE98;

extern void func_800E8190();
extern s32 D_800A1B58;
extern s32 D_800A1B5C;
extern s32 D_800A1B60;

void func_8008BE98(s32 arg0, s32 arg1, s32 arg2) {
    register s32 a0v asm("a0");
    register s32 a2v asm("a2") = arg2;
    register s32 r asm("v0");
    volatile s32 pad[4];
    a0v = 0x5D;
    __asm__ volatile(".set\tnoreorder\n\tjal func_800E8190\n\tmove $5,$6\n\t.set\treorder" : "=r"(r) : "r"(a0v), "r"(a2v) : "ra", "$3", "$4", "$5", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    a2v = r;
    *(S4_BE98 *) &D_800A1B70 = *(S4_BE98 *) a2v;
    D_800A1B58 = ((u8 *) a2v)[0] << 16;
    D_800A1B5C = ((u8 *) a2v)[1] << 16;
    D_800A1B60 = ((u8 *) a2v)[2] << 16;
}

__asm__(".globl func_8008BF14\nfunc_8008BF14 = func_8008BE98 + 0x7C");

typedef struct {
    char c[4];
} S4_BF18;

extern s32 D_800A1B7C;
extern s32 D_800A1B80;
extern s32 D_800A1B84;

void func_8008BF18(s32 arg0, s32 arg1, s32 arg2) {
    register s32 a0v asm("a0");
    register s32 a2v asm("a2") = arg2;
    register s32 r asm("v0");
    volatile s32 pad[4];
    a0v = 0x65;
    __asm__ volatile(".set\tnoreorder\n\tjal func_800E8190\n\tmove $5,$6\n\t.set\treorder" : "=r"(r) : "r"(a0v), "r"(a2v) : "ra", "$3", "$4", "$5", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    a2v = r;
    *(S4_BF18 *) &D_800A1B94 = *(S4_BF18 *) a2v;
    D_800A1B7C = ((u8 *) a2v)[0] << 16;
    D_800A1B80 = ((u8 *) a2v)[1] << 16;
    D_800A1B84 = ((u8 *) a2v)[2] << 16;
}

__asm__(".globl func_8008BF1C\nfunc_8008BF1C = func_8008BF18 + 0x4");

__asm__(".globl .L8008BF74\n.L8008BF74 = func_8008BF18 + 0x5C");

extern s32 D_800995F0[];
extern s32 D_800995EC;
extern s32 D_800E4EA4;

void func_8008BF98(void) {
    s16 buf[4];
    s32 *s0v = D_800995F0;
    if (*s0v != 0) {
        buf[0] = 0;
        buf[1] = 0x1EE;
        buf[2] = 0x100;
        buf[3] = 0xE;
        func_800249C4(buf, 0, 0x1E0);
        *s0v = 0;
    }
    if (D_800995EC != 0) {
        buf[0] = 0;
        buf[1] = 0x1EE;
        buf[2] = 0x100;
        buf[3] = 0xE;
        func_800248FC(buf, &D_800E4EA4);
        D_800995EC = 0;
        *s0v = 1;
    }
}

__asm__(".globl .L8008BFE4\n.L8008BFE4 = func_8008BF98 + 0x4C");

__asm__(".globl .L8008C044\n.L8008C044 = func_8008BF98 + 0xAC");

extern u8 D_800995F4[];
extern u8 D_800995F5[];
extern u8 D_800995F6[];
extern u8 D_8009967A[];
extern u8 D_800A1B10;
extern u8 D_800A1B14;
extern u8 D_800A1B50;
extern u8 D_800A1B54;
extern u8 D_8009A8F8;
extern u8 D_8009B27A;
extern u8 D_8009BBFC;
extern u8 D_8009D882;
extern void func_80091280();

void func_8008C048(void) {
    s32 one;
    s32 i;
    s32 n;
    s32 v0;
    s32 w;

    one = 1;
    i = 0;
    n = 0x851C;
    D_800995EC = 0;
    D_800995F0[0] = 0;
    do {
        w = 0xF;
        v0 = i + 0x78;
        D_800995F5[i] = 0;
        D_800995F4[i] = one;
        do {
            D_800995F6[v0] = 0;
            w = w - 1;
            v0 = v0 - 8;
        } while (w >= 0);
        D_8009967A[i] = 0;
        i = i + 0x982;
    } while (i < n);
    D_800A1B10 = 0;
    D_800A1B14 = 0;
    D_800A1B50 = 0;
    D_800A1B54 = 0;
    D_8009A8F8 = 0;
    D_8009B27A = 0;
    D_8009BBFC = 0;
    D_8009D882 = 0;
    func_80091280();
}

__asm__(".globl .L8008C09C\n.L8008C09C = func_8008C048 + 0x54");

__asm__(".globl .L8008C104\n.L8008C104 = func_8008C048 + 0xBC");

void func_8008C118(void) {
    func_800F0BE0(0x71, 0, 0, 0);
}

void func_8008C144(void) {
    func_800F0BE0(0x72, 0, 0, 0);
}

__asm__(".globl .L8008C174\n.L8008C174 = func_8008C170 + 0x4");

void func_8008C170(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4) {
    register s32 v1 asm("v1");
    s32 v0;
    v0 = 1;
    v1 = arg4;
    func_8008F710(arg0, arg1, 0, 0, v0, (s16) arg2, (s16) arg3, (s16) v1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C1C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C1D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C1E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C250);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C268);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C2A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C2DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C320);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C364);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C3A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C3C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C410);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C448);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C468);

extern void func_80090258();

void func_8008C49C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    func_80090258(arg0, arg1, arg2, arg3, arg4);
}

extern void func_80090840();

void func_8008C4D0(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    func_80090840(arg0, arg1, arg2, arg3, arg4);
}

extern void func_80090DEC();

void func_8008C504(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    func_80090DEC(arg0, arg1, arg2, arg3, arg4);
}

extern void func_8008F498();

void func_8008C538(s32 arg0, s32 arg1) {
    func_8008F498(arg0, 0, 0, 1, arg1);
}

extern s32 D_80093594;

void func_8008C564(s32 arg0, s32 arg1, s32 arg2) {
    register s32 s2v asm("s2");
    register s32 s1v asm("s1");
    register s32 s0v asm("s0");
    register s32 v1v asm("v1");
    register s32 v0v asm("v0");

    s2v = arg0;
    v1v = arg1;
    s1v = arg2;
    if (v1v < 0x10) {
        goto alt;
    }
    s0v = 0;
    KEEP(s0v);
    KEEP(s2v);
    func_8008F498(s2v, 3, s0v, 0, s1v);
    s0v++;
    v0v = s0v < 0x10;
    if (!v0v) {
        goto done;
    }
    __asm__ volatile(".set\tnoreorder\n\t"
                     "j D_80093594\n\t"
                     "sw %0,0x10($sp)\n\t"
                     ".set\treorder" ::"r"(s1v) : "memory");
alt:
    func_8008F498(s2v, 3, v1v, 0, s1v);
done:
    return;
}

void func_8008C5F4(void) {
    func_80090048();
}

void func_8008C614(void) {
    func_8009069C();
}

void func_8008C634(void) {
    func_80090C48();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C654);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C77C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C7A8);

extern s32 func_8001DB58(s32);
extern void func_80040974();
extern s32 D_80045948;
extern s32 D_80045950;

s32 func_8008C7F8(void) {
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = func_8001DB58(1);
    temp_a0 = D_80045948;
    D_80045944 = temp_v0;
    D_80045948 = temp_v0;
    D_8004594C = ~temp_a0 & temp_v0;
    D_80045950 = ~temp_v0 & temp_a0;
    if ((temp_v0 & 0x90C) == 0x90C) {
        func_80040974(temp_a0);
    }
    return 1;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C86C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C8CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008C9C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008CA48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008CA7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008CA98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008CB98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008CBB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle", func_8008CBD8);

extern s32 D_8004597C;
extern MixerState D_8004EACC[2];
extern DrawEnv D_8004EA14[2];
extern void func_800246D4(s32);
extern s32 func_8001DBA8(s32);
extern void func_80024E84(void *);
extern void func_80024CAC(void *);
extern void func_80024C38(s32);
extern void func_80023288(s32);

s32 func_8008CBF0(s32 arg0) {
    s32 temp;

    func_800246D4(0);
    temp = func_8001DBA8(0);
    func_80024E84(&D_8004EACC[D_8004597C]);
    func_80024CAC(&D_8004EA14[D_8004597C]);
    func_80024C38(arg0);
    func_80023288(-1);
    return temp;
}
