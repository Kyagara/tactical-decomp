#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();
extern s32 func_80133158();
extern s32 func_8014CEB4();

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80125C54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80125F44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801262B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80126568);

struct Func801268E4_Obj {
    u8 pad[0x58];
    u8 unk58;
    u8 pad59;
    u8 unk5A;
};

extern s32 func_80146078();
extern void func_8012D900();
extern u8 D_80148E88;
extern u8 D_8014D202;

void func_801268E4(void) {
    extern s32 func_80149EBC(s32, s32);
    extern s32 func_8008CDD0(s32);
    extern s32 func_80149BEC(s32);
    extern void func_8014C8A0();
    extern void func_8014CA38(s32, s32, s32, s32);
    extern void func_8014C9D0(s32);
    extern s32 D_80173CA4_value __asm__("D_80173CA4");
    register s32 s0v asm("s0");
    register s32 s1v asm("s1") = 0;
    register s32 s2v asm("s2") = 0x7D0;
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s16 temp_80146078;
    u8 *temp_a0;
    struct Func801268E4_Obj *temp_v0_4;

    __asm__ volatile("addu $4,$17,$zero" : "=r"(a0v) : "r"(s1v));
    temp_v0 = func_80149EBC(a0v, 0x92);
    s1v = temp_v0;
    if (s1v == 0) {
        goto end;
    }
    v0v = D_80173CA4_value;
    temp_a0 = (u8 *) (v0v + s1v);
    if (*temp_a0 != 0x92) {
        goto update;
    }
    temp_80146078 = (s16) func_80146078(temp_a0 + 1);
    temp_v0_2 = func_80133158(temp_80146078);
    if (temp_v0_2 == s2v) {
        goto update;
    }
    temp_v0_3 = func_8008CDD0(temp_v0_2);
    if (temp_v0_3 == s2v) {
        goto update;
    }
    temp_v0_4 = (struct Func801268E4_Obj *) func_80180AFC(temp_v0_3);
    v1v = (s32) temp_v0_4;
    v0v = temp_v0_4->unk5A;
    if ((v0v & 0x40) != 0) {
        goto create;
    }
    v0v = temp_v0_4->unk58;
    if ((v0v & 4) == 0) {
        goto update;
    }
create:
    temp_v0_5 = func_80149BEC(0x10);
    s0v = temp_v0_5;
    func_8014C8A0(s0v, &D_80148E88);
    {
        register s32 a1v asm("a1");

        a1v = D_80173CA4_value;
        func_8014CA38(s0v, s1v + a1v + 1, 0, 0);
    }
    func_8014C9D0(s0v);
update:
    v1v = D_8014D202;
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$17,1\n\tj func_8012D900\n\taddu $17,$2,%0\n\t.set\treorder" : : "r"(v1v));
end:
    return;
}

extern s32 D_80173CA8;
extern char func_8008BDC0[];
extern char func_8008BE54;

void func_80126A0C(s32 arg0, u32 arg1) {
    extern s32 func_8013B590(s32);
    extern s32 func_8008CDD0(s32);
    extern void *func_80180AFC(s32);
    extern s32 func_8018401C(s32, u8, u8, u32);
    extern s32 func_8008BE7C(s32, u32);
    struct Func80126A0C_Obj {
        u8 pad[0x47];
        u8 unk47;
        u16 unk48;
        u8 pad4A[0x138];
        u8 unk182;
    };
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register struct Func80126A0C_Obj *p0v asm("v0");
    s32 temp_v0_3;
    struct Func80126A0C_Obj *p;

    func_8013B590(0x1FD);
    __asm__ volatile(".set\tnoreorder\n\tbnez $2,.La0c_call\n\taddu $4,$17,$zero\n\tjal func_8013B590\n\tori $4,$zero,0x6f\n\tbeqz $2,.La0c_call\n\taddu $4,$17,$zero\n\t.set\treorder");
    v0v = func_8008CDD0(arg0);
    __asm__ volatile(".set\tnoreorder\n\taddu $4,%1,$zero\n\tbltz $4,.La0c_pre_call\n\tsltiu $2,%2,0x1f4\n\tbeqz $2,.La0c_pre_call\n\tnop\n\t.set\treorder" : "=r"(a0v) : "r"(v0v), "r"(arg1));
    p0v = (struct Func80126A0C_Obj *) func_80180AFC(a0v);
    p = p0v;
    temp_v0_3 = func_8018401C(4, p0v->unk47, *(u8 *) &p->unk48, (u16) p->unk48 >> 0xF);
    __asm__ volatile(".set\tnoreorder\n\tlbu $3,0x182(%0)\n\tnop\n\tandi $3,$3,0xc0\n\tbeqz $3,1f\n\tandi $2,%1,0xff\n\t.set\treorder" : : "r"(p), "r"(temp_v0_3));
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(func_8008BE54)\n\taddiu $2,$2,%%lo(func_8008BE54)\n\tj .L8012DAC0\n\tnop\n1:\n\tslti $2,%0,2\n\tbnez $2,.La0c_call\n\taddu $4,$17,$zero\n\t.set\treorder" : : "r"(temp_v0_3));
    D_80173CA8 = (s32) (func_8008BDC0 + 0x44);
    func_8014CEB4(arg0);
    TAIL_JUMP_NOP(.L8012DAE4);
    __asm__ volatile(".La0c_pre_call:");
    __asm__ volatile(".set .La0c_call, .La0c_pre_call + 4");
    func_8008BE7C(arg0, arg1);
}

void func_80126B00(s32 arg0, s32 arg1) {
    extern s32 func_8013B590(s32);
    extern s32 func_8008CDD0(s32);
    extern s32 func_8008CE20(s32);
    extern void func_8008C114(s32, s32);
    extern u8 *func_80180AFC(s32);
    s32 temp_v0;
    u8 *temp_p;

    if (func_8013B590(0x1FD) == 0) {
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

extern void func_8014CA80();

static s32 func_80126B90(s32 arg0) {
    register s32 a0v asm("a0") = arg0;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    __asm__ volatile(".set\tnoreorder\n\tbnez %1,1f\n\tslti %0,%1,96\n\tj func_8012DBD4\n\taddu %0,$zero,$zero\n1:\n\tbnez %0,2f\n\tlui %0,0x2aaa\n\tj func_8012DBD0\n\tori %1,$zero,127\n2:\n\tori %0,%0,0xaaab\n\t.set\treorder"
                     : "=&r"(v0v) : "r"(a0v));
    v1v = a0v << 7;
    v1v -= a0v;
    __asm__ volatile("mult %0,%1" : : "r"(v1v), "r"(v0v));
    v1v >>= 31;
    __asm__ volatile("mfhi %0" : "=r"(v0v));
    v0v >>= 4;
    a0v = v0v - v1v;
    __asm__ volatile("addu %0,%1,$zero" : "=r"(v0v) : "r"(a0v));
    return v0v;
}

extern s32 D_8016603C;

void func_80126BDC(void) {
    s32 temp_v0;

    D_8016603C = 0xFF;
    do {
        func_8014CA80();
        temp_v0 = D_8016603C - 4;
        D_8016603C = temp_v0;
    } while (temp_v0 > 0);
    D_8016603C = 0;
}

void func_80126C30(void) {
    s32 temp_v0;

    D_8016603C = 0;
    do {
        func_8014CA80();
        temp_v0 = D_8016603C + 4;
        D_8016603C = temp_v0;
    } while (temp_v0 < 0x100);
    D_8016603C = 0xFF;
}

extern s32 func_8013B590(s32);

s32 func_80126C84(void) {
    return (u32) (func_8013B590(0x27) - 0x19A) < 0x10U;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80126CAC);

extern void func_8012DD58();
extern void func_8014C958();

void func_80126D6C(void) {
    func_8012DD58();
    func_8014C958();
}

extern s32 func_8008E17C();

void func_80126D94(void) {
    do {
        func_8014CA80();
    } while (func_8008E17C() != 0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80126DC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80126DF0);

void func_80126F48(void) {
    func_80180AFC();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80126F68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80126F98);

extern void func_80023C90();
extern void func_80023D1C();

void func_80127198(u8 *arg0) {
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

extern void func_80023C68();
extern void func_80023D80();

void func_80127244(u8 *arg0) {
    func_80023D80(arg0);
    func_80023C90(arg0, 1);
    arg0[0x4] = 0x80;
    arg0[0x5] = 0x80;
    arg0[0x6] = 0x80;
    *(s16 *) (arg0 + 8) = 0x200;
    arg0[0xC] = 0;
    arg0[0xD] = 0;
    *(s16 *) (arg0 + 0x10) = 0;
    *(s16 *) (arg0 + 0x12) = 0;
    *(s16 *) (arg0 + 0xA) = 0;
    *(s16 *) (arg0 + 0xE) = 0x7C3C;
    func_80023C68(arg0, 1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801272B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80127348);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80127398);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801275A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012765C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801279FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80127C90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80127EB0);

extern s32 func_8012EEB0();

void func_8012802C(void) {
    func_8012EEB0();
}

DEAD_TAIL_LW(2, D_80010008);

extern u32 D_8016EB08[];
extern u32 D_8016EB84;
extern u8 D_80172084[];

void func_80128054(u32 arg0) {
    register u32 a0v asm("a0");
    register u32 v0v asm("v0");
    register u32 a1v asm("a1");
    register u32 a2v asm("a2");
    register u32 a3v asm("a3");
    register s32 *v1v asm("v1");
    register u32 t0v asm("t0");
    register u32 t1v asm("t1");
    volatile u32 pad;

    if ((a0v < v0v) && (a0v != 0xFFFFFFFFU)) {
        v0v = (u32) &D_8016EB84;
        v0v = a0v - v0v;
        a2v = v0v >> 8;
        t0v = (u32) D_80172084;
        a1v = (u32) D_8016EB08;
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
        v0v = (u32) v1v + a2v;
inner:
        v0v += t0v;
        *(u8 *) v0v = 0;
        v0v = *(u32 *) a1v;
        v1v = (s32 *) ((u8 *) v1v + 1);
        if ((s32) (u32) v1v < (s32) v0v) {
            v0v = (u32) v1v + a2v;
            goto inner;
        }
        v0v = (u32) v1v + a2v;
        TAIL_JUMP(func_8012F0FC);
next:
        a1v += 8;
        v0v = (s32) a1v < (s32) a3v;
        v1v += 2;
        if (v0v != 0) {
            goto loop;
        }
        ((void (*)(u32, u32, u32, u32)) func_8014C958)(a0v, a1v, a2v, a3v);
    }
end:
}

extern s32 D_80165ECC;
extern void func_80023DE4(u8 *);
extern void func_8012F3CC(u8 *);
extern void func_800254CC(u8 *, s32, s32, s32, void *);
extern void func_8012E244(u8 *);
extern u8 D_80167830;
extern volatile u8 D_80167844[];
extern volatile u8 D_80167845[];
extern volatile u8 D_80167846[];
extern volatile u8 D_80167847[];
extern s8 D_80167848[];
extern s8 D_80167849[];
extern s8 D_8016784A[];
extern s8 D_8016784B[];

void func_8012810C(u16 *arg0, u8 *arg1) {
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
    func_8012F3CC(var_s3);
    var_a1 = 0;
    var_s2 = 0;
    var_a0 = var_s3 + 0x26;
    do {
        temp_v0 = ((s32) D_80167844[var_a1] << 24) >> 24;
        temp_v1 = arg0[0];
        *(u16 *) (var_a0 - 6) = (u16) (temp_v0 + temp_v1);
        temp_v0 = ((s32) D_80167845[var_a1] << 24) >> 24;
        temp_v1 = arg0[1];
        *(u16 *) (var_a0 - 4) = (u16) (temp_v0 + temp_v1);
        temp_v0 = ((s32) D_80167846[var_a1] << 24) >> 24;
        temp_v1 = arg0[0];
        *(u16 *) (var_a0 - 2) = (u16) (temp_v0 + temp_v1);
        temp_v0 = ((s32) D_80167847[var_a1] << 24) >> 24;
        temp_v1 = arg0[1];
        *(u16 *) var_a0 = (u16) (temp_v0 + temp_v1);
        if (D_80167848[var_a1] != 0) {
            *(u16 *) (var_a0 - 6) += arg0[2];
        }
        if (D_80167849[var_a1] != 0) {
            *(u16 *) (var_a0 - 4) += arg0[3];
        }
        if (D_8016784A[var_a1] != 0) {
            *(u16 *) (var_a0 - 2) += arg0[2];
        }
        if (D_8016784B[var_a1] != 0) {
            *(u16 *) var_a0 += arg0[3];
        }
        var_a1 += 8;
        var_a0 += 0x10;
        var_s2 += 1;
    } while (var_s2 < 0xC);
    temp_v0 = func_8002398C(0, 0, 0x3C0, 0x100);
    func_800254CC(var_s3 + 0xC, 1, 0, temp_v0 & 0xFFFF, &D_80167830);
    temp_v0 = func_8002398C(0, 2, 0x3C0, 0x100);
    func_800254CC(var_s3, 0, 0, temp_v0 & 0xFFFF, &D_80165ECC);
    func_8012E244(var_s3 + 0xD8);
    *(u16 *) (var_s3 + 0xE0) = arg0[0];
    *(u16 *) (var_s3 + 0xE2) = arg0[1];
    *(u16 *) (var_s3 + 0xE8) = arg0[2];
    *(u16 *) (var_s3 + 0xEA) = arg0[3];
}

extern void func_8014A5E8();

void func_80128360(u8 *arg0) {
    s32 s0v;
    s32 s1v;
    u8 *s2v;

    s2v = arg0;
    s1v = 0;
    s0v = 0x18;
    do {
        func_8014A5E8(s2v + s0v);
        s1v += 1;
        s0v += 0x10;
    } while (s1v < 0xC);
    func_8014A5E8(s2v);
    func_8014A5E8(s2v + 0xD8);
    func_8014A5E8(s2v + 0xC);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801283CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801284E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801286D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80128D8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012918C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80129628);

extern void func_800235AC();
extern u8 D_8012D8A0[];

void func_80129874(s32 arg0) {
    register s32 x asm("s0");
    u8 *p;
    x = arg0;
    p = D_8012D8A0;
    func_800235AC(p, x);
    func_800235AC(p, x + 1);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801298C0);

extern void func_8014CE78();

void func_8012B824(s32 arg0) {
    extern u8 D_80173F8C[];
    s32 a1v;
    u32 v0;

    a1v = arg0;
    v0 = a1v & 0xF800;
    v0 >>= 9;
    func_8014CE78(*(s32 *) (D_80173F8C + v0), a1v & 0x7FF);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012B85C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012B914);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012BBC4);

extern s16 func_80132E50();

void func_8012BE74(void *arg0, void *arg1, void *arg2, s32 arg3) {
    s16 *out = (s16 *) arg0;
    s16 *a = (s16 *) arg1;
    s16 *b = (s16 *) arg2;

    out[4] = func_80132E50(a[0], b[0], arg3);
    out[5] = func_80132E50(a[1], b[1], arg3);
    out[8] = func_80132E50(a[0] + a[2], b[0] + b[2], arg3);
    out[9] = func_80132E50(a[1], b[1], arg3);
    out[12] = func_80132E50(a[0], b[0], arg3);
    out[13] = func_80132E50(a[1] + a[3], b[1] + b[3], arg3);
    out[16] = func_80132E50(a[0] + a[2], b[0] + b[2], arg3);
    out[17] = func_80132E50(a[1] + a[3], b[1] + b[3], arg3);
}

extern s32 func_8012F6B0();
extern s32 D_801697D0;

void func_8012BF9C(void) {
    s32 s0;

    s0 = 3;
    do {
        func_8014CA80();
        if (func_8012F6B0() == s0) {
            break;
        }
    } while ((D_801697D0 & 0x160) == 0);
}

extern s32 func_8008C410();
extern volatile u16 D_801721D0[];
extern volatile u16 D_801721D2;
extern volatile u16 D_801721D4;

void func_8012BFF0(void) {
    volatile u16 *v0;
    u16 t;

    v0 = (volatile u16 *) func_8008C410();
    if (v0 != (volatile u16 *) -1) {
        t = v0[0];
        D_801721D0[0] = t;
        t = v0[1];
        D_801721D2 = t;
        t = v0[2];
        D_801721D4 = t;
    }
}

extern void func_8008C550();

void func_8012C048(s32 dummy0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8008C410();
    if (temp_v0 != -1) {
        func_8008C550(temp_v0, arg1);
    }
}

void func_8012C088(s32 a0, s32 a1) {
    s32 s0;
    u16 *v1;

    s0 = a1;
    v1 = (u16 *) func_8008C410(a0, a1);
    if (v1 != (u16 *) -1) {
        ((u16 *) s0)[0] = v1[0];
        ((u16 *) s0)[1] = v1[1];
        ((u16 *) s0)[2] = v1[2];
    }
}

void func_8012C0E4(s32 a0, s32 a1) {
    s16 *src;
    s32 *dst;
    s32 s0 = a1;
    src = (s16 *) func_8008C410(a0);
    dst = (s32 *) s0;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

extern void func_8008C5E8();

void func_8012C130(void) {
    func_8008C5E8();
}

__asm__(".set push\n.set noreorder\njr $31\nnop\n.set pop\n");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012C158);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012C4A4);

extern s32 func_8008CBB4();
extern s32 func_8008CDD0();
extern s32 func_80180AFC();
extern s32 func_80180C90();
extern s32 D_801834BC;

void func_8012C588(u8 *arg0, u16 *arg1) {
    register u8 *s0 asm("s0");
    register s32 s1 asm("s1");
    register u16 *s2 asm("s2");
    s32 s3;
    register s32 s4 asm("s4");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    s32 stack[4];

    s0 = arg0;
    v0 = *(u8 *) (s0 + 0x22);
    s2 = arg1;
    s2[1] = 0;
    s2[0] = v0;
    if (*(u8 *) (s0 + 0x1BA) & 0x30) {
        s2[1] = 1;
    }
    if (!(*(u8 *) (s0 + 0x1BA) & 0x38)) {
        s2[1] = 2;
    }
    if (*(u8 *) (s0 + 0x1B8) != 0) {
        s2[1] = 3;
    }
    s2[4] = *(u8 *) (s0 + 0x21);
    v0 = *(u16 *) (s0 + 0x2A);
    s2[8] = v0;
    if (v0 == 0) {
        s2[8] = v0 + 1;
        v0 += 1;
    }
    v0 = *(u16 *) (s0 + 0x28);
    s2[7] = 0;
    s2[6] = v0;
    v0 = *(u16 *) (s0 + 0x2E);
    s2[11] = v0;
    if (v0 == 0) {
        s2[11] = v0 + 1;
        v0 += 1;
    }
    s1 = 0x64;
    USE(s1);
    v0 = *(u16 *) (s0 + 0x2C);
    __asm__ volatile("addu %0,%1,$zero" : "=r"(a0) : "r"(s0));
    s2[10] = 0;
    s2[14] = s1;
    s2[9] = v0;
    v1 = *(u8 *) (s0 + 0x39);
    s2[12] = v1;
    v0 = (s32) &D_801834BC;
    *(volatile u16 *) (s2 + 2) = 0;
    *(volatile u16 *) (s2 + 3) = 0;
    D_80173CA8 = v0;
    s2[2] = func_8014CEB4((void *) a0);
    if (*(u8 *) (s0 + 0x186) != 0) {
        s2[12] = s1;
    }
    v0 = *((s16 *) s2 + 2);
    if (v0 >= 0) {
        v1 = v0;
        USE_NOVOL(v1);
        v0 = v1 + 1;
        s2[2] = v0;
    }
    s2[3] = 0x15;
    __asm__ volatile("addu %0,$zero,$zero" : "=r"(s4));
    s1 = 0;
    do {
        if (func_8008CBB4(s1) != 0) {
            v0 = func_8008CDD0(s1);
            s3 = v0;
            v0 = (s32) func_80180AFC(s3);
            func_80180C90(*(u8 *) (v0 + 0x161), &stack[0]);
            v1 = stack[0];
            s0 = (u8 *) v0;
            if (v1 >= 0 && s3 == v1 && *(u8 *) (s0 + 0x161) != 0) {
                s4 += 1;
            }
        }
        s1 += 1;
    } while (s1 < 0x15);
    s2[3] = s4;
}

DEAD_TAIL_LH(4, D_8014D09A);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012C75C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012CC54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012CC74);

extern s32 func_80133CDC();

s32 func_8012CC98(void) {
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    a0v = func_80180AFC();
    KEEP(a0v);
    v1v = 0;
    __asm__ volatile("addu %0,%1,%2" : "=r"(v0v) : "r"(a0v), "r"(v1v));
loop:
    v0v = ((u8 *) v0v)[0x58];
    v1v = v1v + 1;
    if (v0v != 0) {
        __asm__ volatile(".set\tnoreorder\n\t.L8012CCC4:\n\tj func_80133CDC\n\tori $2,$zero,1\n\t.set\treorder");
    }
    SCHED_BARRIER();
    v0v = v1v < 5;
    if (v0v != 0) {
        v0v = a0v + v1v;
        goto loop;
    }
    v0v = 0;
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012CCEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012CEF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012CF44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012CF78);

extern s32 D_8016791C;
extern s32 D_801721D8;

void func_8012D028(void) {
    extern void func_8014BF54();
    extern s32 D_80173F8C;
    s32 r;

    if (r != 0) {
        return;
    }
    func_8014BF54(&D_801721D8, &D_80173F8C, 0x80);
    D_8016791C += 1;
}

extern void func_8014BF54();
extern s32 D_80173F8C;

void func_8012D074(void) {
    func_8014BF54(&D_80173F8C, &D_801721D8, 0x80);
    D_8016791C = 0;
}

extern Unit *func_80059AF0(s32);
extern void func_80059FE0(s32);
extern u8 D_800596E0[];

void func_8012D0AC(s32 arg0) {
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_a2;
    Unit *var_a1;
    u8 temp_v1;
    s32 var_v0_2;

    var_s1 = arg0;
    var_s0 = 1;
    var_s2 = 0xFF;
    do {
        var_a1 = func_80059AF0(var_s0);
        if (var_a1->partyId == var_s2 || var_a1->sprite != var_s1) {
            var_s0 += 1;
        } else {
            break;
        }
    } while (var_s0 < 0x14);
    if (var_s0 != 0x14) {
        var_a0 = 0;
        var_a2 = 0xFF;
        do {
            temp_v1 = ((u8 *) var_a1 + var_a0)[0xE];
            var_a0 += 1;
            if (temp_v1 != 0 && temp_v1 != var_a2) {
                D_800596E0[temp_v1] += 1;
            }
            var_v0_2 = var_a0 < 7;
        } while (var_v0_2);
        func_80059FE0(var_s0);
    }
}

extern s32 func_80059BB0();

void func_8012D180(void) {
    register s32 s0v asm("s0") = 0;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s32 local;
    u8 *p;
    s0v = 0;
loop:
    func_80180AFC(s0v);
    p = (u8 *) v0;
    func_80180C90(p[0x161], &local);
    v1 = local;
    p = (u8 *) v0;
    if (v1 < 0) {
        goto Lend;
    }
    v0 = 0xFF;
    if (s0v != v1) {
        goto Lend;
    }
    v1 = p[2];
    if (v1 != v0) {
        v0 = p[0];
        if (v0 == 0) {
            goto Lend;
        }
        if ((unsigned) v0 >= 4) {
            goto Lend;
        }
    }
    v0 = p[6] & 0x10;
    if (v0 == 0) {
        goto Lend;
    }
    func_80059BB0(p, p[6] & 1);
Lend:
    __asm__ volatile(".set\tnoreorder\n1:\n\t.set\treorder");
    s0v = s0v + 1;
    v0 = s0v < 0x15;
    if (v0 != 0) {
        goto loop;
    }
}

__asm__(".globl .L8012D210\n.L8012D210 = func_8012D180 + 0x90");

extern void func_8013B644();

void func_8012D224(void) {
    func_8013B644(0x54, 0x16D);
}

__asm__(".globl .L8012D2AC\n.L8012D2AC = func_8012D248 + 0x64");

void func_8012D248(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 v0;
    s32 v1;
    s32 s0r;
    s32 s1r;
    s0r = 0;
    s1r = 0x64;
loop:
    v1 = func_80180AFC(s0r);
    v0 = ((u8 *) v1)[5];
    v0 = v0 & 0x30;
    s0r = s0r + 1;
    if (v0 != 0) {
        goto Lflags;
    }
    v0 = ((u8 *) v1)[0x24];
    v0 = v0 + 0xA;
    ((u8 *) v1)[0x24] = v0;
    v0 = ((u8 *) v1)[0x24];
    if ((unsigned) v0 >= 0x64) {
        ((u8 *) v1)[0x24] = s1r;
    }
Lflags:
    v0 = s0r < 0x15;
    if (v0 != 0) {
        goto loop;
    }
}

__asm__(".globl func_8012D2B4\nfunc_8012D2B4 = func_8012D248 + 0x6C");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012D2CC);

extern void func_8012E9FC();

void func_8012D3E0(s16 *arg0, s16 arg1, s16 arg2, s16 *arg3, s32 arg4) {
    s32 s0;
    s16 *s1;

    s1 = arg3;
    arg0[2] = arg1;
    arg0[3] = arg2;
    s0 = arg4;
    func_8012E9FC(arg0, s1, -1);
    s0 <<= 4;
    s0 += 0x7C3C;
    arg3[7] = s0;
}

extern void func_8012DD94();

static void func_8012D430(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012D438);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012D568);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012D6F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012D8E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012D900);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012D930);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012D940);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DA0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DA74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DB00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DB90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DBD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DBD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DBDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DC30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DC84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DCAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DCF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DD0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DD1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DD30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DD44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DD58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DD94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DDC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DDE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DE54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DE58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DE6C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DF0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DF10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DF40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DF68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DF90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012DF98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E15C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E17C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E190);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E198);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E244);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E2B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E2BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E320);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E348);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E570);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E5A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E63C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E64C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E65C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E774);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E7F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E96C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E9C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012E9FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012EBF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012EC68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012EC90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012EE3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012EEB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012EEF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012EF08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012EFAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F02C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F04C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F0FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F10C);

extern void func_80133754();
extern void func_801352BC();
extern s16 D_8014D03C;
extern u8 D_80168648[];
extern s16 D_801686B8;

void func_8012F128(void) {
    s16 *p1;
    s16 *p2;
    func_80133754();
    p1 = &D_801686B8;
    p2 = &D_8014D03C;
    *p1 = 2;
    if (*p2 < 0) {
        *p1 = 0xC00;
    }
    func_801352BC(&D_80168648, 0, p1 - 0x28, p2 - 2);
}

extern s16 D_8014D060;
extern u8 D_80168660[];
extern s16 D_80168730;

void func_8012F188(void) {
    s16 *p1;
    s16 *p2;
    func_80133754();
    p1 = &D_80168730;
    p2 = &D_8014D060;
    *p1 = 2;
    if (*p2 < 0) {
        *p1 = 0xC00;
    }
    func_801352BC(&D_80168660, 3, p1 - 0x28, p2 - 2);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F1E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F324);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F360);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F3CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F3DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F454);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F4E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F554);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F65C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F6A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F6B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F6D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F738);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F768);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F7A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F8C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F9DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012F9E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FA74);

extern void *func_8005A884(s32);
extern s32 func_80023A54(s32, s32, s32);
extern s16 D_80165EB4;
extern s16 D_80165EB6;

void func_8012FB10(u8 *arg0, s32 arg1) {
    register s32 tab4 asm("a0");
    u8 *p;
    s32 v;
    s32 n;
    s32 q;
    s32 r;
    s32 d;
    s32 e;
    s32 f;

    p = func_8005A884(arg1);
    v = p[1];
    n = p[0];
    r = v % 15;
    q = v / 15;
    arg0[0xC] = r << 4;
    arg0[0xD] = (q << 4) + 0x20;
    tab4 = D_80165EB4;
    d = n / 8;
    e = tab4 + (n - d * 8) * 0x10;
    __asm__ __volatile__("" ::: "memory");
    f = D_80165EB6 + d;
    *(s16 *) (arg0 + 0xE) = func_80023A54(e, f, n);
    *(s16 *) (arg0 + 0x10) = 0x10;
    *(s16 *) (arg0 + 0x12) = 0x10;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FBD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FC38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FCBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FCC8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FD20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FD34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FD84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FE60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FF70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8012FFE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130020);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130074);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130078);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801300A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013013C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013014C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013018C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130268);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801303B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130478);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801304CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801305D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801305D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801305E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130628);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013068C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130718);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801307D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801307D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130874);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801308C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801309E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130B98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130C00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130C18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130D18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130D94);

extern s32 func_80137B98();
extern void func_8012DD44();
extern void func_80137F64();

void func_80130ED4(void *arg0, s32 *arg1) {
    register s32 s0v asm("s0") = (s32) arg1;
    register s32 s1v asm("s1") = (s32) arg0;
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    if (func_80137B98() != 0) {
        v0v = D_801697D0;
        if ((v0v & 0x1000) != 0) {
            v0v = *arg1;
            if (v0v == 0) {
                v0v = *(s16 *) ((u8 *) arg0 + 0x1E);
            } else {
                v0v -= 1;
            }
            *arg1 = v0v;
            func_8012DD44();
        }
        v0v = D_801697D0;
        if ((v0v & 0x4000) != 0) {
            v0v = *(s16 *) ((u8 *) arg0 + 0x1E);
            v1v = *arg1;
            __asm__ volatile(".set\tnoreorder\n\tbne %1, %2, 1f\n\taddiu %0, %1, 1\n\tj func_80137F64\n\tsw $0, 0($16)\n\t.set\treorder\n1:"
                             : "=r"(v0v)
                             : "r"(v1v), "r"(v0v)
                             : "memory");
            *arg1 = v0v;
            MEMORY_BARRIER();
            func_8012DD44();
        }
    }
    __asm__ volatile(".set .L80130F20, func_80130ED4 + 0x4C");
}

DEAD_TAIL_LW(2, D_801697D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130F8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80130FA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131024);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013109C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131174);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801311A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801311F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131360);

extern s32 func_8014CC5C();
extern s32 D_80166028;

void func_801313C8(void *arg0) {
    if (func_8014CC5C() != 0) {
        *(s16 *) ((u8 *) arg0 + 0xE) = 0x7D3C;
    } else if (D_80166028 == 1) {
        *(s16 *) ((u8 *) arg0 + 0xE) = 0x7D3C;
    } else {
        *(s16 *) ((u8 *) arg0 + 0xE) = 0x7C3C;
    }
}

void func_80131414(void *arg0) {
    if (func_8014CC5C() != 0) {
        *(s16 *) ((u8 *) arg0 + 0xE) = 0x7C7C;
    } else if (D_80166028 == 1) {
        *(s16 *) ((u8 *) arg0 + 0xE) = 0x7C7C;
    } else {
        *(s16 *) ((u8 *) arg0 + 0xE) = 0x7CBC;
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131460);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131488);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801314B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801314D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131540);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131580);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013158C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013160C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131874);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013190C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131A88);

void func_80131ADC(void *arg0) {
    *(s16 *) ((u8 *) arg0 + 0x1C) = 0;
    *(s16 *) ((u8 *) arg0 + 0x26) = 0;
    func_8014BF54((u8 *) arg0 + 0x20, &D_80165ECC, 8);
}

extern void func_80142BD0();

void func_80131B10(s32 arg0) {
    func_8014A5E8(arg0 + 0x54);
    func_8014A5E8(arg0 + 0x2C);
    func_8014A5E8(arg0 + 0x40);
    func_8014A5E8(arg0 + 0xC);
    func_8014A5E8(arg0 + 0x18);
    func_8014A5E8(arg0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131B64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131BA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131D4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131DF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131E10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131E30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131E98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131E9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131ED8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80131FF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801320A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801320CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013232C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801324A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013252C);

extern void func_801390BC();
extern void func_80139BEC();

void func_8013257C(void) {
    func_801390BC();
    func_80142BD0(0xFA);
    func_80139BEC();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801325AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801326E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132750);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132754);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013275C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132824);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013285C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132888);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132898);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801328AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801328C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801328FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013290C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132914);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132BC4);

extern s32 D_8016D9A8;

s32 func_80132BDC(void) {
    return D_8016D9A8;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132BEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132BF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132E50);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132E74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80132F9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133048);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133088);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801330E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133130);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133150);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133158);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801332C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133324);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133474);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801334A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801334A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133538);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133568);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133588);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133754);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013394C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133950);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133974);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133B24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133B94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133C98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133CDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133D60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133E3C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133E40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80133ED0);

extern s16 D_80168EF4;

void func_80133EDC(s16 arg0) {
    D_80168EF4 = arg0;
}

struct Func80133EEC_Obj {
    u8 pad[4];
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 padA;
    s16 unkC;
    s16 unkE;
    s16 pad10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 pad18;
    s16 pad1A;
    s16 unk1C;
};

extern s32 func_80132824(s16);
extern void func_8013018C(s16 *, s16 *, s32);

void func_80133EEC(struct Func80133EEC_Obj *arg0, s16 *arg1, s16 *arg2, s32 *arg3, s32 arg4) {
    s16 temp_a0;
    s32 temp_a2;
    s32 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    temp_a2 = func_80132824(arg0->unk1C);
    *arg3 = 0;
    func_8013018C(arg1, arg2, temp_a2);
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
    arg0->unk8 = (s16) (0x102 - ((s32) ((u16) *arg1 << 0x10) >> 0x11));
    temp_v0_2 = (u16) *arg1;
    arg0->unk14 = temp_v0_2;
    arg0->unk4 = temp_v0_2;
    arg0->unkC = temp_v0_2;
    temp_v0_3 = (u16) *arg2;
    arg0->unk16 = temp_v0_3;
    arg0->unk6 = temp_v0_3;
    arg0->unkE = temp_v0_3;
}

DEAD_TAIL_LHU(3, D_80168EF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134014);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801340AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134180);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134224);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134248);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013424C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134280);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801342CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134308);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801343BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801343D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801343E0);

extern s32 func_8014CBC0();
extern s32 func_8014CBF4();
extern s32 D_80165FBC;

void func_801344FC(void) {
    extern s32 func_80138094(s32);
    extern void func_80137C10(s32, s32);
    extern void func_80137F84(s32);
    s32 s0v;
    s32 v0;

    s0v = func_8014CBC0();
    SCHED_BARRIER();
    v0 = 1;
    D_80165FBC = v0;
    func_8014CA80();
    if (func_80138094(&D_801697D0) == 0) {
        func_80137C10(s0v, 0);
        func_80137F84(s0v);
        TAIL_JUMP(D_8013B51C);
    }
    func_8014CA80();
    D_80165FBC = 0;
    if (func_8014CBF4() != 0) {
        goto end;
    }
    func_8014C958();
end:;
}

extern void func_8014A018(s32, s32, s32, s32);
extern s32 *D_80165F9C;

s32 func_80134590(s32 arg0) {
    s32 temp_s0;
    s32 temp_s2;
    register s32 temp_v0 asm("v0");

    temp_s2 = *D_80165F9C;
    if (arg0 == 0x22) {
        temp_s0 = func_8013B590(0x24) & 1;
        temp_v0 = func_8013B590(0x23) & 7;
        temp_s0 <<= 0xF;
        temp_v0 <<= 0xC;
        func_8013B644(0x22, temp_s0 | temp_v0);
    }
    func_8014A018(0xBE, 0, 0, 0);
    func_8014A018(0xB1, 0, arg0, 0);
    temp_v0 = *D_80165F9C;
    *D_80165F9C = temp_s2;
    return temp_v0;
}

void func_80134644(s32 arg0, s32 arg1) {
    s32 temp_s2;
    s32 var_s1;

    temp_s2 = *D_80165F9C;
    var_s1 = arg1;
    if (arg0 == 0x2C) {
        if (var_s1 > 0x05F5E0FF) {
            var_s1 = 0x05F5E0FF;
        }
    }
    func_8014A018(0xBE, arg0, 0, 0);
    func_8014A018(0xB0, arg0, var_s1, 0);
    *D_80165F9C = temp_s2;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801346E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801346F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801348A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134940);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134954);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134960);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134A40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134A68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134A74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134B70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134BD8);

extern void func_80044600();

void func_80134BF4(void) {
    func_80044600();
}

DEAD_TAIL_LW(2, D_80166004);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134C1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134C20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134CAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134CC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134D18);

extern void func_801CAFD4();
extern s32 D_80166044;

void func_80134D6C(void) {
    D_80166044 = 0;
    func_801CAFD4();
}

extern void func_8013BC14();
extern void func_801CA664();

void func_80134D94(void) {
    __asm__ volatile(".set\tnoreorder\n\t.L80134D9C:\n\tjal func_80149D48\n\tli $4,0x36\n\t.set\treorder" ::: "ra", "memory");
    func_8013BC14(6);
    func_801CA664();
}

__asm__(".set push\n.set noreorder\njr $31\nnop\n.set pop\n");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134DCC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80134E1C);

extern void func_8012DCF8();
extern void func_801C1A3C();

void func_80134F2C(void) {
    func_8012DCF8();
    func_8013BC14(1);
    func_801C1A3C(0);
}

void func_80134F5C(void) {
    func_8012DCF8();
    func_8013BC14(1);
    func_801C1A3C(1);
}

void func_80134F8C(void) {
    func_8012DCF8();
    func_8013BC14(1);
    func_801C1A3C(2);
}

extern void func_80138ED8();
extern u16 D_8016604A;
extern void func_80149D48();

void func_80134FBC(void) {
    func_80149D48(0x42);
    if (func_8008E17C() != 0) {
        goto B2;
    }
    if (D_8016604A == 0) {
        goto B3;
    }
B2:
    func_8014CA80();
    __asm__ volatile("j func_8013BFCC");
B3:
    func_80142BD0(0xfe);
    D_80166044 = 0;
    func_80138ED8();
}

__asm__(".globl .L80135000\n.L80135000 = func_80134FBC + 0x44");

__asm__(".globl .L80135010\n.L80135010 = func_80134FBC + 0x54");

extern void func_8012DD0C();
extern void func_8013BBEC();
extern s32 func_8013D634();
extern s16 D_8014D08A;
extern s32 D_8016600C;
extern s32 D_8016602C;
extern s16 D_80166048;

void func_80135028(void) {
    extern void func_8014C858();
    extern void func_8014CA38();
    extern s32 func_8014CC94();
    s32 var_s0;
    s32 var_s1;
    s32 var_v0;
    volatile s32 pad[2];

    D_8016604A = 4;
    do {
        func_8014CA80();
    } while (func_8014CC94(6) != 0);
    D_8016600C = 2;
    D_8016602C = 0;
    do {
        func_8014C858(1);
    } while (D_8016600C != 0);
    var_s0 = 2;
    func_8013BBEC();
    do {
        func_8014CA38(var_s0, 0, 0, 1);
        var_s0 += 1;
    } while (var_s0 < 0xF);
    var_s0 = 0;
    var_s1 = 0xFF;
    do {
        D_8016603C = var_s1 - var_s0;
        var_s0 += 8;
        func_8014CA80();
    } while (var_s0 < 0x100);
    var_v0 = var_s1 - var_s0;
    func_8012DD0C();
    var_v0 = var_s1 - var_s0;
    D_80166048 = 0;
    D_8016603C = 0;
    D_8016604A = 0;
    func_8013D634(2, D_8014D08A, 0xFF);
    func_8014C958();
}

extern s32 D_80174038;
extern s8 D_8013C028[];
extern void func_8013DA28();

void func_80135130(void) {
    extern void func_8014CA38(s32, s32, s32, s32);
    extern void func_8013BC14(s32);
    extern void func_8013BB70(s32);
    extern void func_8014C858(s32);
    extern void func_8014C8A0(s32, s32);
    s32 s0v;
    s32 t;

    s0v = 0;
loop:
    D_8016603C = s0v;
    func_8014CA80();
    s0v = s0v + 0x10;
    t = s0v < 0x100;
    if (t != 0) {
        goto loop;
    }
    D_8016603C = 0xFF;
    D_80166048 = 1;
    func_8014CA38(8, 0, 0, 1);
    func_8014CA38(0xA, 0, 0, 1);
    func_8014CA38(0xB, 0, 0, 1);
    func_8014CA38(0xC, 0, 0, 1);
    func_8014CA38(0xD, 0, 0, 1);
    func_8013DA28();
    func_8013BC14(2);
    func_8013BB70(0x20000);
    func_8013BC14(0xF);
    func_8014C858(2);
    D_8016602C = 1;
    func_8014C8A0(0xD, (s32) D_8013C028);
    func_8014C958();
}

extern void func_8014C8A0();
extern void func_8014C9D0();
extern s32 D_8013C130;

void func_80135234(void) {
    func_8012DCF8();
    func_8014C8A0(D_80174038 - 1, &D_8013C130);
    func_8014C9D0(D_80174038 - 1);
    func_8014C958();
}

__asm__(".globl .L80135288\n.L80135288 = func_80135284 + 0x4");

void func_80135284(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    if (func_80149CBC(0x15) != 0) {
        if (func_80149CBC(0x31) == 0) {
            func_8012DD1C();
        }
    }
    func_8013BB70(0x20000);
    func_8013BC14(3);
    func_801DF050();
}

__asm__(".globl func_801352BC\nfunc_801352BC = func_80135284 + 0x38");

extern void func_8012DD1C();
extern void func_8013BB70();
extern void func_8014C858();
extern s32 func_8014CC94();

void func_801352DC(void) {
    if (func_8014CC94(3) != 0) {
        func_8014C958();
    }
    if (func_8014CC94(1) != 0) {
        func_8014C958();
    }
    func_8012DCF8();
    func_8012DD1C();
    func_8013BB70(0x20000);
    func_8013BC14(7);
    func_8014C858(2);
    D_8016600C = 3;
    do {
        D_801697D0 = 0;
        func_8014CA80();
    } while (D_8016600C != 0);
    D_801697D0 = 0;
    func_8013BBEC();
    func_8014C858(2);
    func_8012DD0C();
    func_8014C958();
}

extern u8 D_8016986C[];
extern void *D_80173CB8;
extern void func_8014C924();
extern void func_8014C940();
extern s16 D_80166A34;
extern u8 D_80166B10[];
extern s32 D_80165F80;
extern u16 D_80165EE4[];
extern s32 D_8016D9C4;

void func_801353A4(void) {
    struct Obj {
        u8 pad[0x38];
        u16 unk38;
    };
    extern void func_8013BB70();
    extern void func_8013BC14();
    extern void func_8014C858();
    extern void func_8014CA38();
    s32 temp_s1;
    s32 var_s0;
    s32 var_a1;
    s32 var_v1;
    u16 *var_a0_2;
    u16 temp_v0;

    func_8012DCF8();
    temp_s1 = D_80165F80;
    func_8013D634(0, 0xFF, 0xFF);
    D_80166048 = 1;
    func_8013DA28();
    func_8013BC14(9);
    func_8013BB70(0x20000);
    func_8013BC14(0xA);
    func_8014C940(8);
    func_8014C940(7);
    D_8016600C = 4;
    do {
        D_801697D0 = 0;
        func_8014CA80();
    } while (D_8016600C != 0);
    D_80173CB8 = D_80166B10;
    D_80166A34 = -3;
    D_80165FBC = 1;
    D_801697D0 |= 0x20;
    var_s0 = 9;
    if (D_8016D9C4 == 0) {
        func_8014C924(8);
        func_8014C924(7);
    }
    do {
        func_8014CA38(var_s0, 0, 0, 1);
        var_s0 += 1;
    } while (var_s0 < 0xF);
    func_8014C858(4);
    var_v1 = 0;
    if (D_8016D9C4 != 0) {
        var_a1 = 8;
        var_a0_2 = D_80165EE4;
        do {
            temp_v0 = (*(struct Obj **) (D_8016986C + ((var_a1 - var_v1) << 10)))->unk38;
            var_v1 += 1;
            *var_a0_2 = temp_v0;
            var_a0_2 += 1;
        } while (var_v1 < 2);
    }
    func_8013BBEC();
    D_80166048 = 0;
    func_8013D634(temp_s1, 0xFF, 0xFF);
    D_80165FBC = 0;
    D_801697D0 = 0;
    func_8012DD0C();
    func_8014C958();
}

extern s32 D_80165F84;
extern void func_8014088C();
extern void func_8008DEA0();
extern void func_801C3D84();
extern void func_8008DEC8();

void func_8013556C(void) {
    extern s32 func_80180AFC();
    extern void func_8013BC14();
    extern void func_8014CA38();
    extern void func_8014C9D0();
    extern void func_8013CF58(s32);
    s16 *s0;

    s0 = &D_8014D08A;
    if (((u8 *) func_80180AFC(*s0))[0x182] != 0) {
        func_8013D634(0, 0xFF, 0xFF);
        func_8012DCF8();
        D_80166048 = 1;
        func_8013BC14(0xB);
        func_8014CA38(8, 0, 0, 1);
        func_8014C9D0(8);
        func_8013DA28();
        func_8014088C();
        func_8008DEA0();
        func_801C3D84(*s0);
        D_80166048 = 0;
        D_80165FBC = 0;
        D_801697D0 = 0;
        func_8013CF58(D_80165F84);
        func_8013D634(3, *s0, *s0);
        func_8012DD0C();
        func_8008DEC8();
        func_8014C958();
    }
}

extern void func_8013BC14(s32);
extern void func_8014CA38(s32, s32, s32, s32);
extern void func_8014C9D0(s32);
extern void func_801C438C();

void func_80135668(void) {
    func_8013D634(0, 0xFF, 0xFF);
    func_8012DCF8();
    D_80166048 = 1;
    func_8013BC14(0xB);
    func_8014CA38(8, 0, 0, 1);
    func_8014C9D0(8);
    func_8013DA28();
    func_8014CA80();
    func_8014CA80();
    func_801C438C();
    D_80166048 = 0;
    D_80165FBC = 0;
    D_801697D0 = 0;
    func_8012DD0C();
    func_8014C958();
    __asm__ volatile(".set .L801356C4, func_80135668 + 0x5C");
    __asm__ volatile(".set .L801356D8, func_80135668 + 0x70");
}

extern void func_801C05D4();

void func_80135710(void) {
    func_80149D48(0x3D);
    func_8013BC14(0xC);
    func_801C05D4();
}

__asm__(".set push\n.set noreorder\njr $31\nnop\n.set pop\n");

extern s32 D_80044954;
extern s32 D_80165EBC;
extern s32 D_80165EC4;

void func_80135748(s32 arg0) {
    extern void func_8012F04C();
    s32 temp_s0;

    temp_s0 = func_8012EEB0(0x2000);
    D_80173CA8 = (s32) &D_80044954;
    func_8014CEB4(arg0 * 4 + 0x164B, 0x2000, temp_s0);
    func_800248FC(&D_80165EBC, temp_s0);
    func_800248FC(&D_80165EC4, temp_s0 + 0x1800);
    func_8012F04C(temp_s0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801357C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801357C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135880);

extern void func_8014BF54(u16 *, s32 *, s32);
extern void func_8012F04C(s32);
extern void func_80044694();
extern void func_800446C8();

void func_801358A8(s32 arg0) {
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

    s2 = func_8012EEB0(0x2000);
    s1 = (s32) &func_80044694;
    s0 = arg0 * 4;
    do {
        func_8014CA80();
        D_80173CA8 = s1;
    } while (func_8014CEB4(s0 + 0x164B, 0x2000, s2) != 0);
    s0 = (s32) &func_800446C8;
    do {
        func_8014CA80();
        D_80173CA8 = s0;
    } while (func_8014CEB4() != 0);
    s3 = s2 + 0x1800;
    func_8014BF54(&locals.sp10, &D_80165EBC, 8);
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
    func_800248FC(&D_80165EC4, s3);
    func_8012F04C(s2);
    func_8014CA80();
}

extern u8 D_8004A6BC[];
extern s32 *D_80173CA4;

void func_801359C0(s32 arg0) {
    extern s32 D_80173F8C;
    s32 s1;
    s32 s0;
    s32 v0;
    s32 *v1;
    s1 = (s32) func_80044694;
    s0 = arg0 * 4;
    do {
        func_8014CA80();
        D_80173CA8 = s1;
    } while (func_8014CEB4(s0 + 0xE7B, 0x2000, D_8004A6BC) != 0);
    s0 = (s32) func_800446C8;
    do {
        func_8014CA80();
        D_80173CA8 = s0;
    } while (func_8014CEB4() != 0);
    v1 = D_80173CA4;
    v0 = *v1;
    if (v0 != 0xF2F2F2F2) {
        D_80173F8C = v0 + (s32) v1;
        *v1 = 0xF2F2F2F2;
    }
}

extern s32 D_8016D95C;

void func_80135A70(s32 a0) {
    extern void func_8014BF54();
    s32 s1;
    s32 s0;

    s1 = a0;
    s0 = (s32) &D_8016D95C;
    func_8014BF54(s0, s1, 0x20);
    func_8014BF54(s0 + 0x20, s1 + 0x20, 0x20);
}

extern s32 D_8014E5D4[];
extern void func_8013CA70(s32 *);
extern void func_8014A51C(void);

void func_80135AC4(void) {
    func_8013CA70(D_8014E5D4);
    func_8014A51C();
}

void func_80135AF4(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135AFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135B04);

extern s32 D_8016903C;
extern s32 D_80166004;
extern s32 D_80010008;
extern u8 D_80168F78[];
extern u8 D_80168EF8[];
extern u8 D_80168F38[];

void func_80135BE4(void) {
    s32 v1;
    s32 v0;
    s32 a0v;
    s32 a1v;
    s32 a2v;
    s32 off;

    if (v1 == 0) {
        goto L_C64;
    }
    v0 = D_8016903C;
    if (v0 != 0) {
        goto L_C64;
    }
    D_80173CA8 = (s32) &func_80044694;
    off = v1 << 2;
    v1 = *(s32 *) (D_80168F78 + off);
    a2v = D_80010008;
    a0v = *(s32 *) (D_80168EF8 + off);
    a1v = *(s32 *) (D_80168F38 + off);
    v0 = func_8014CEB4(a0v, a1v, v1 + a2v);
    if (v0 != 0) {
        goto end;
    }
    D_8016903C = 1;
    TAIL_JUMP_NOP(func_8013CCBC);
L_C64:
    v0 = D_80166004;
    if (v0 == 0) {
        goto end;
    }
    v0 = D_8016903C;
    if (v0 == 0) {
        goto end;
    }
    D_80173CA8 = (s32) &func_800446C8;
    v0 = func_8014CEB4();
    if (v0 != 0) {
        goto end;
    }
    D_8016903C = 0;
    D_80166004 = 0;
end:;
}

extern void func_8013F8B4();

void func_80135CCC(void) {
    func_8013F8B4();
}

__asm__(".set push\n.set noreorder\njr $31\nnop\n.set pop\n");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135CF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135D0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135D18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135E68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135ED0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135ED4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135F08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135F58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80135FD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136050);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801360AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801361A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801361F0);

extern void func_8008E304();

void func_801361F8(void) {
    func_8014CA80();
    func_8008E304();
    func_8014CA80();
    func_8014C958();
}

extern u8 D_80043708[];

void func_80136230(void) {
    extern s32 func_8001DBA8();
    u8 *p = D_80043708;
    do {
        func_8001DBA8(0);
        D_80173CA8 = (s32) p;
    } while (func_8014CEB4() != 0);
}

extern void func_80043F00();
extern void func_8013D230();
extern s32 D_800435C4;
extern void func_80043A90();
extern s32 D_800473AC;

void func_80136278(s32 arg0, s32 arg1) {
    s32 s0v = arg0;
    s32 s1v = arg1;

    func_80043F00();
    if (s0v != 0) {
        D_80173CA8 = (s32) &D_800435C4;
        func_8014CEB4(s0v, 1);
        func_8013D230();
    }
    if (s1v != 0) {
        D_80173CA8 = (s32) &D_800435C4;
        func_8014CEB4(s1v, 2);
        func_8013D230();
    }
    if (s0v != 0) {
        D_80173CA8 = (s32) &func_80043A90;
        func_8014CEB4(1, 0x7F, 0);
    }
    __asm__ volatile(".set .L801362CC, func_80136278 + 0x54");
}

extern s32 func_8012DC84();
extern void func_8013D278();
extern s32 func_8013D394();
extern s32 func_8013D464(s32, s32 *, s32, s32);
extern s32 func_8013D4C8();
extern void func_8013EFAC();
extern void func_8013F168();
extern s32 func_8014CEB4_call() __asm__("func_8014CEB4");
extern void func_801C3078();
extern s32 func_801C34B4_call() __asm__("func_801C34B4");
extern void func_801C7FE4();
extern void func_801C8004();
extern void func_801C9488();
extern void func_801C9EC0();
extern s32 D_8013D1F8;
extern s16 D_80165FD4;
extern s16 D_80165FD6;
extern u16 D_80165FDA;
extern s32 D_80166060;
extern s32 D_80166064;
extern s32 D_8016D99C;
extern s32 D_801C3F44;

s32 func_80136320(void) {
    register s32 temp_s0 asm("s0");
    register s32 a0v asm("$4");
    register s32 a1v asm("$5");
    register s32 a2v asm("$6");
    register s32 a3v asm("$7");
    register s32 t0v asm("$8");
    register s32 v0v asm("$2");
    register s32 v1v asm("$3");

    D_80166044 = 0;
    func_8013EFAC();
    func_8013F168();
    func_8013F8B4();
    a0v = 0x990;
    if (D_80165FDA == 2) {
        D_80165FDA = 3;
        __asm__ volatile(".set\tnoreorder\n\tj func_8013D394\n\tnop\n\t.set\treorder" ::: "memory");
    }
normal:
    D_80173CA8 = (s32) &D_80044954;
    func_8014CEB4_call(a0v, 0x20000, D_80010008);
    temp_s0 = func_801C34B4_call();
    KEEP(temp_s0);
    if (D_80165FDA != 3) {
        func_801C7FE4();
        func_801C8004();
    }
    D_80166060 = 0;
    D_80166064 = 0;
    if (func_8012DC84() == 0) {
        goto normal_mask;
    }
    a2v = 0xFFFE7FFF;
    a0v = 0xFFE7FFFF;
    t0v = 0xE7FFFFFF;
    a3v = 0xFE7FFFFF;
    v0v = 0xFF;
    a1v = (s32) &D_800473AC;
    D_8016603C = v0v;
    v0v = *(s32 *) a1v;
    v1v = -8;
    v0v &= v1v;
    v1v = -0x1C1;
    v0v &= v1v;
    v0v |= 0x40;
    v0v &= a2v;
    v0v &= a0v;
    v1v = 0x80000;
    v0v |= v1v;
    v0v &= t0v;
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800473AC)\n\tlw $4,%%lo(D_800473AC)($4)\n\t.set\treorder" : "=r"(a0v) : : "memory");
    v0v &= a3v;
    D_8016D99C = a0v;
    KEEP(a2v);
    KEEP(a0v);
    KEEP(t0v);
    KEEP(a3v);
    KEEP(v0v);
    KEEP(a1v);
    KEEP(v1v);
    __asm__ volatile(".set\tnoreorder\n\tj func_8013D464\n\tsw $2,0($5)\n\t.set\treorder" ::: "memory");
normal_mask:
    D_8016603C = 0;
    func_801C3078();
    __asm__ volatile(".set\tnoreorder\n\tbeqz $16,.L80136320_normal_tail\n\tori $4,$zero,0x2A\n\t.set\treorder" : "=r"(a0v) : : "memory");
    func_8014C8A0(6, &D_8013D1F8);
    __asm__ volatile(".set\tnoreorder\n\tj func_8013D4C8\n\tori $2,$zero,1\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".L80136320_normal_tail:");
    D_80165FD4 = 0;
    D_80165FD6 = 0;
    func_8013D278(a0v, 0);
    func_801C9488();
    func_801C9EC0();
    func_8014C8A0(6, &D_801C3F44);
    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801364DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136580);

extern void func_801334A4();
extern u8 D_80169220[];
extern s16 D_8014D042;
extern s16 D_8014D09A;
extern s16 D_8014D066;
extern s32 D_8013D704;

void func_80136634(s32 a0, s32 a1, s32 a2) {
    extern s32 func_8014CC94(s32);
    extern void func_8014C8A0(s32, s32);
    extern void func_8014CA38(s32, s32, s32, s32);
    s32 s0v;
    s32 s1v;
    s32 s2v;
    s32 t;
    s32 t2;

    s2v = a0;
    s0v = a1;
    s1v = a2;
    t = (u16) D_80166048;
    if (t == 1) {
        goto end;
    }
    func_801334A4();
    D_80166060 = D_80169220[s2v];
    t2 = 0xFF;
    if (s0v != t2) {
        D_8014D08A = s0v;
        D_8014D042 = s0v;
    }
    if (s1v != t2) {
        D_8014D09A = s1v;
        D_8014D066 = s1v;
    }
    if (func_8014CC94(2) == 0) {
        func_8014C8A0(2, (s32) &D_8013D704);
    }
    func_8014CA38(2, s2v, 0, 0);
end:;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136704);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801367A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013685C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801368AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136920);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136954);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801369D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801369DC);

extern s32 D_80165F88;
extern void func_8008DEE8(void);

void func_80136A00(s32 arg0) {
    D_80165F88 = arg0;
    func_8008DEE8();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136A28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136A48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136A90);

void func_80136AE4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    register u8 *s3r asm("s3");
    register s32 s5r asm("s5");
    register s32 s4r asm("s4");
    register s32 s2r asm("s2");
    register s32 s1r asm("s1");
    register s32 s0r asm("s0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 v0 asm("v0");
    s3r = arg0;
    s5r = arg2;
    s4r = arg3;
    v0 = arg1 * 8;
    s2r = v0 + arg1;
    s1r = 1;
    s0r = 0;
loop1:
    a0v = (s32) s3r;
    a1v = s2r + s0r;
    a2v = s1r & 0xFF;
    func_8013DA88(a0v, a1v, s4r & a2v);
    s0r = s0r + 1;
    v0 = s0r < 5;
    s1r = s1r * 2;
    if (v0 != 0) {
        goto loop1;
    }
    s1r = 1;
    s0r = 0;
loop2:
    a0v = (s32) s3r;
    a1v = s0r + 5;
    a1v = s2r + a1v;
    a2v = s1r & 0xFF;
    func_8013DA88(a0v, a1v, s5r & a2v);
    s0r = s0r + 1;
    v0 = s0r < 4;
    s1r = s1r * 2;
    if (v0 != 0) {
        goto loop2;
    }
}

__asm__(".globl func_80136B10\nfunc_80136B10 = func_80136AE4 + 0x2C");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136B9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136BD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136CB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136D08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136F10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136FB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80136FDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013738C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137488);

extern s32 func_8014CCB8(s32, s32, s32);

s32 func_80137548(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_8014CCB8(arg1 - arg0, arg2 << 0xC, arg3) + (arg0 << 0xC);
}

extern u8 D_8012D8C0[];
extern s16 D_80165FF4;

void func_80137584(void) {
    func_800235AC(D_8012D8C0);
    func_8014CA80();
    D_80165FF4 = 1;
}

extern s32 func_8008C664();

void func_801375C0(u8 *arg0) {
    register u8 *s1 asm("s1") = arg0;
    register s32 s0 asm("s0");
    u16 b3[3];

    s0 = func_80133158((s16) func_80146078(s1));
    if (s0 == 0x7D0) {
        return;
    }
    b3[0] = s1[2];
    b3[2] = s1[3];
    b3[1] = s1[4];
    func_8008C664(s0, (s32) b3, 0x100 - (s1[7] << 8), 3, (s16) func_80146078(s1 + 5));
}

extern void func_8008CC50(s32);
extern void func_8008CC80(s32);
extern void func_8013E6B0();

void func_8013765C(void *arg0) {
    register s32 a0 asm("a0");

    s32 v0;
    s32 s0 = (s32) arg0;
    v0 = func_80146078();
    v0 <<= 16;
    s0 = *(u8 *) ((u8 *) s0 + 2);
    v0 = func_80133158(v0 >> 16);
    a0 = v0;
    v0 = 0x7D0;
    if (a0 != v0) {
        if (s0 == 1) {
            func_8008CC50(a0);
            TAIL_JUMP(func_8013E6B0);
        }
        func_8008CC80(a0);
    }
}

extern void func_8008CD24(s32);

void func_801376C4(void) {
    s32 temp_v0;

    temp_v0 = func_80133158((s16) func_80146078());
    if (temp_v0 != 0x7D0) {
        func_8008CD24(temp_v0);
    }
}

extern void *func_8008CA48(s32);
extern void func_8008C9C4(s32, s16 *);
extern s32 func_8008CDD0(s32);
extern void func_8008C7CC(s32, u8, s32);

void func_80137708(u8 *arg0) {
    s16 b[3];
    s32 temp_v0;
    register u16 *p asm("v0");
    register u16 v1 asm("v1");
    register s32 s0 asm("s0");
    register s32 a0 asm("a0");
    register u8 s1 asm("s1");
    register u8 *s2 asm("s2") = arg0;

    temp_v0 = func_80133158((s16) func_80146078());
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

void func_801377D0(void) {
    s32 temp_v0;

    temp_v0 = func_80133158();
    if (temp_v0 != 0x7D0) {
        do {
            func_8014CA80();
        } while (func_8008CEFC(temp_v0) != 0);
    }
}

extern void func_801C34B4();

void func_8013781C(void) {
    if (func_8013B590(0x1FC) == 0) {
        D_80165FDA = 2;
        func_8013BC14(0xD);
        func_8014CA80();
        func_801C34B4();
        func_801C7FE4();
        func_801C8004();
    }
}

extern u8 D_8008DDCC[];
extern u8 D_8008DDEC[];

void func_80137874(void) {
    D_80173CA8 = (s32) D_8008DDCC;
    func_8014CEB4();
    do {
        func_8014CA80();
        D_80173CA8 = (s32) D_8008DDEC;
    } while (func_8014CEB4() != 0);
}

extern void func_8013E874();

void func_801378D4(void) {
    func_80149D48(0x41);
    func_8013E874();
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137904);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137AB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137B98);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137BB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137C10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137D80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137DAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137DD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137E64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137ED4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137EE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137F1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137F64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80137F84);

extern void func_8013EFF4();
extern void func_8013CAC4(s32);
extern void func_8012E190();
extern void func_8013F080();
extern void func_8013F0C0();
extern void func_8013B6E4();

void func_80137FAC(void) {
    s32 a0v;

    func_8013EFF4();
    a0v = 0;
    func_8013CAC4(a0v);
    func_8012E190();
    func_8013F080();
    func_8013F0C0();
    func_8013B6E4();
}

__asm__(".set\tpush\n.set\tnoreorder\n"

        "\tlui $2,0x8017\n"
        "\taddiu $2,$2,-26516\n"
        "\tlui $1,0x8016\n"
        "\tsw $2,24472($1)\n"
        "\tlui $2,0x8015\n"
        "\taddiu $2,$2,-6636\n"
        "\tlui $1,0x8017\n"
        "\tsw $2,15512($1)\n"
        "\tlui $2,0x8015\n"
        "\taddiu $2,$2,-10796\n"
        "\tlui $1,0x8017\n"
        "\tsw $2,16220($1)\n"
        "\tlui $2,0x8005\n"
        "\taddiu $2,$2,-22852\n"
        "\tlui $1,0x8017\n"
        "\tsw $2,15524($1)\n"
        "\tlui $2,0x8005\n"
        "\taddiu $2,$2,30492\n"
        "\tlui $1,0x8016\n"
        "\tsw $2,24476($1)\n"
        "\tlui $2,0x8016\n"
        "\taddiu $2,$2,27408\n"
        "\tlui $1,0x8017\n"
        "\tsw $2,15544($1)\n"
        "\tli $2,-1\n"
        "\tlui $1,0x8017\n"
        "\tsw $2,16224($1)\n"
        "\tlui $1,0x8016\n"
        "\tsh $zero,24654($1)\n"
        "\tlui $1,0x8017\n"
        "\tsh $zero,-9792($1)\n"
        "\tlui $1,0x8017\n"
        "\tsh $zero,15488($1)\n"
        "\tjr $31\n"
        "\tnop\n"
        "\t.set\treorder\n"
        "\t.set\tpop\n");

extern void func_8014A464();
extern void func_8012E9C0();
extern void func_8012EE3C();
extern void func_8014C994();

void func_80138080(void) {
    func_8014A464();
    __asm__ volatile(".set\tnoreorder\n\tjal func_8012E320\n\t.globl func_80138094\nfunc_80138094:\n\tnop\n\t.set\treorder" ::: "ra", "memory");
    func_8012E9C0();
    func_8012EE3C();
    func_8014C994();
}

extern char D_80173C84[];
extern char D_80174010[];
extern char D_80173F6C[];
extern char D_80174018[];
extern s32 func_800E78C0();

void func_801380C0(void) {
    s32 s0v;
    s32 t;

    ((u16 *) D_80174010)[0] = 0;
    ((u16 *) D_80174010)[1] = 0;
    ((u16 *) D_80174010)[2] = 0;
    ((s32 *) D_80173C84)[0] = 0x1000;
    ((s32 *) D_80173C84)[1] = 0x1000;
    ((s32 *) D_80173C84)[2] = 0x1000;
    t = s0v;
    s0v = func_800E78C0(0x62, t, t, 0);
    func_8014BF54(D_80173F6C, s0v, 0x20);
    t = s0v;
    func_8014BF54(D_80174018, func_800E78C0(0x61, t, t, 0), 0x20);
}

__asm__(".globl .L80138134\n.L80138134 = func_801380C0 + 0x74");

__asm__(".globl .L80138150\n.L80138150 = func_801380C0 + 0x90");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138168);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138174);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013820C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138364);

extern s32 func_80143A9C();
extern void func_8008EFB4();
extern s16 D_80165FDC;
extern s32 D_80166054;
extern u8 D_80143B80[];

void func_801383FC(void) {
    extern s32 func_8013B590(s32);
    extern void func_8014C8A0();
    s32 v0;

    func_8013F168();
    v0 = 1;
    D_80165FDA = v0;
    v0 = func_8013B590(0x1FD);
    if (v0 != 0) {
        SCHED_BARRIER();
        func_80143A9C();
        func_8013F0C0();
        D_80165FDC = 0;
        D_80166054 = 0;
    }
    v0 = func_8013B590(0x27);
    if (v0 == 0) {
        return;
    }
    D_80165FDC = 0;
    D_80166054 = 0;
    func_8008EFB4(2, 0, 0, 0, 2);
    func_8014C8A0(1, (s32) D_80143B80);
}

void func_801384A0(void) {
}

void func_801384A8(void) {
    s32 v0;
    func_8013F168();
    v0 = func_8014CC94(1);
    if (v0 == 0) {
        func_80143A9C();
        func_8013F0C0();
        D_80166054 = 0;
        D_80165FDC = 0;
    }
}

extern void func_8014CA1C();

void func_801384F8(void) {
    extern void func_80142D58();

    func_80142D58();
    func_8014CA1C(6);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138520);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138530);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138554);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138568);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138570);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013863C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138668);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013871C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013876C);

extern u8 D_8014D46C;
extern u8 D_8014D46D;

void func_80138900(s32 arg0) {
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 a3v asm("a3");

    s0v = arg0;
    a2v = func_80180AFC(arg0);
    KEEP(a2v);
    a3v = 0xFF;
    v1v = (s32) &D_8014D46C;
    v0v = s0v << 4;
    a0v = v0v + s0v;
    v1v = a0v + v1v;
    a1v = v1v + 0x11;
loop:
    v0v = ((u8 *) a2v)[0x1B8];
    if (v0v == 0) {
        *(u8 *) v1v = 0;
        *(u8 *) ((u8 *) &D_8014D46D + a0v) = a3v;
    }
    v1v = v1v + 1;
    v0v = v1v < a1v;
    if (v0v != 0) {
        goto loop;
    }
}

__asm__(".globl func_8013890C\nfunc_8013890C = func_80138900 + 0xC");

__asm__(".set\tpush\n.set\tnoreorder\n"

        "\tlui $2,%hi(D_80169828)\n"
        "\taddiu $2,$2,%lo(D_80169828)\n"
        "\tjr $31\n"
        "\tnop\n"
        "\t.set\treorder\n"
        "\t.set\tpop\n");

void func_80138988(void) {
    func_80149D48(0x42);
    func_8014C858(2);
    D_80165EE4[0] = 7;
    func_8014C958();
}

extern s32 D_80165FB4;

void func_801389C4(void) {
    extern void func_8014C858();
    s32 v0;

    v0 = 1;
    D_80165FB4 = v0;
    func_80149D48(0x42);
    func_8014C858(0x10);
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138A00);

void func_80138A38(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 v0;
    s32 v1;
    s32 unused[2];

    v1 = 0;
    if (arg2 > 0) {
        do {
            v0 = arg1[0];
            arg1 += 1;
            v1 += 1;
            *(u16 *) arg0 = v0;
            arg0 += 2;
        } while (v1 < arg2);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138A6C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138A74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138AA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138ADC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138B10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138BEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138BF0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138C38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138D5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138ED8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80138F9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801390BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013916C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139238);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139348);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013934C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801393B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801393B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013948C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801394C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801394CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139508);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801395AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013972C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139888);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013988C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801398FC);

void func_80139900() {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139908);

void func_801399A4(s32 a0) {
    extern void func_80137C10();
    D_80165FBC = 1;
    D_801697D0 = 0x20;
    func_80137C10(a0, 0);
    D_80165FBC = 0;
    D_801697D0 = 0;
}

extern void func_801409A4();
extern s16 D_80166A58;
extern s16 D_80166A5A;

void func_801399EC(void) {
    s32 temp_v0;

    temp_v0 = func_8014CBC0();
    D_80166A58 = -2;
    D_80166A5A = -2;
    func_801409A4(temp_v0);
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139A30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139A70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139AB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139B04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139B08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139BB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139BDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139BE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139BE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139BEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139C4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139CD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139EDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80139FE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A128);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A2C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A33C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A354);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A43C);

extern s16 D_801692D0[];
extern u16 D_80165FF6;
extern s32 D_80169CB8;
extern s16 D_801692C0[];
extern u8 D_8013BF8C[];
extern s32 *D_80173C70;
extern u16 D_80166AC0;
extern s32 D_8016607C;
extern void func_8014CA58(s32, s32, s32, s32, s32);

void func_8013A464(void) {
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 mv asm("a0");
    register s32 a1v asm("a1");
    s32 a0v;
    s32 tv;
    s32 hv;

    D_8016607C = 1;
    func_8014A51C();
    mv = 0x18000;
    v1v = D_80174038;
    v0v = D_800473AC;
    v1v = v1v << 10;
    v0v = v0v & mv;
    s1v = *(s32 *) (D_8016986C + v1v);
    if (v0v != 0) {
        v0v = s1v << 2;
        v0v = v0v + s1v;
        v0v = v0v << 2;
        s1v = *(s16 *) ((u8 *) D_801692D0 + v0v);
    }
    func_8014C9D0(8);
    v0v = D_80165FF6;
    if (v0v != 0) {
        goto L_A528;
    }
    s0v = 0x44;
    if (func_8014CC94(1) == 0) {
        goto L_A528;
    }
    v0v = D_80169CB8;
    if (v0v == s0v) {
        func_8014C958();
    }
    func_8014CA80();
    TAIL_JUMP_NOP(.L801414EC);
L_A528:
    func_8012DD94();
    v0v = s1v << 2;
    v0v = v0v + s1v;
    v0v = v0v << 2;
    s0v = v0v + (s32) D_801692C0;
    v1v = *(s16 *) (s0v + 4);
    a0v = *(s16 *) (s0v + 0);
    SCHED_BARRIER();
    a1v = D_80173CB8;
    v0v = v1v << 4;
    v0v = v0v - v1v;
    v0v = v0v << 2;
    v1v = *(u16 *) (s0v + 2);
    v0v = v0v + a1v;
    *(u16 *) (v0v + 0x1C) = v1v;
    D_80166AC0 = *(u16 *) (s0v + 6);
    v1v = *(s16 *) (s0v + 4);
    D_80165F84 = a0v;
    v0v = v1v << 4;
    v0v = v0v - v1v;
    v0v = v0v << 2;
    v1v = *(u16 *) (s0v + 8);
    v0v = v0v + a1v;
    *(u16 *) (v0v + 0x20) = v1v;
    v0v = 0x1F;
    if (s1v != v0v) {
        v0v = 8;
    } else {
        func_8014C8A0(8, D_8013BF8C);
        func_8014CA38(8, 0, D_80173C70, 0);
        func_8014C958();
        v0v = 8;
    }
    if (s1v == v0v) {
        goto L_A5F0;
    }
    func_80142BD0(s1v);
L_A5F0:
    a0v = *(s32 *) (s0v + 0xC);
    func_8014C8A0(8, a0v);
    v0v = *(s16 *) (s0v + 4);
    a1v = v0v << 4;
    a1v = a1v - v0v;
    a1v = a1v << 2;
    hv = D_80173CB8;
    func_8014CA58(8, a1v + hv, 0, 0, 0);
    D_8016607C = 0;
    func_8014C958();
}

extern void func_8013F76C();
extern void func_8014CA38();
extern s32 D_80141464;

void func_8013A654(s32 arg0) {
    func_8013F76C();
    func_8014C8A0(4, &D_80141464);
    func_8014CA38(4, arg0, 0, 0);
}

extern s32 func_8012DF40();
extern s16 D_80166AF0;
extern void func_801416E8();

void func_8013A6A0(void) {
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");
    s32 v1;
    u8 *p;

    s0 = func_8014CBC0();
    p = (u8 *) func_8012DF40();
    v1 = *(s16 *) ((u8 *) D_80173CB8 + 0x74);
    v0 = 3;
    if (v1 != v0) {
        v0 = 4;
        goto rest;
    }
    __asm__ volatile(".set\tnoreorder\n\tj func_801416E8\n\tori %0,$zero,0x10\n\t.set\treorder" : "=r"(v0));
rest:
    if (v1 == v0) {
        p[0x1B8] = 0x11;
    }
    D_80166AF0 = -3;
    func_801409A4(s0);
    func_8014C958();
}

extern u8 D_8014D314;

void func_8013A71C(s32 arg0, s32 arg1) {
    s32 s0;
    s32 v0;
    s0 = arg0;
    v0 = func_80180AFC(arg1, arg1);
    *(u8 *) (v0 + 0x1B9) = s0;
    *(u8 *) (v0 + 0x1B8) = D_8014D314;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A75C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A7CC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A8B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A938);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013A9B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013AA40);

extern s32 D_80180530;
extern s32 *D_80174044;
extern void func_800449F8();

s32 func_8013AA8C(void) {
    extern s32 func_80180AFC();
    s32 *pe;
    s32 *pl;
    u32 v1;
    s32 tmp;

    tmp = func_80180AFC();
    D_80173CA8 = (s32) &D_80180530;
    pe = (s32 *) func_8014CEB4(tmp);
    v1 = (u32) (pe[0] + 1);
    D_80174044 = pe;
    if (v1 < 2) {
        func_800449F8(0x11, 7);
    }
    pl = D_80174044;
    if (pl[0] != 4) {
        return -1;
    }
    return ((u8 *) pl)[0x52];
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013AB0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013ABD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013ABD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013AEDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013AEEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B0F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B1B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B1D4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B280);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B3C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B464);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B4D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B508);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B51C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B590);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B59C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B5B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B644);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B670);

void func_8013B68C(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B694);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B6E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B898);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013B95C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BA68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BB30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BB44);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BB64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BB70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BB80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BB90);

extern s32 func_80173C74;
extern u16 D_8004E5D0[];

s32 func_8013BBA4(void) {
    return (D_8004E5D0[func_80173C74] & 0xF300) >> 8;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BBD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BBEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BC14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BC24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BC40);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BCBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BCE8);

void func_8013BD24(void) {
}

extern s32 D_8016D9B4;
extern void func_80142C24();

void func_8013BD2C(void *arg0) {
    s32 v0;

    v0 = *(s32 *) arg0;
    D_8016D9B4 = v0;
    func_80142C24();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BD58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BD68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013BFCC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013C2DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013C310);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013C390);

void func_8013C3A4(void) {
}

extern void func_8012DF98();
extern void func_8012E65C();
extern s32 D_80173F44;

void func_8013C3AC(s32 arg0, s32 arg1) {
    func_8012DF98(arg1);
    D_80173F44 = arg0;
    func_8012E65C();
}

extern s16 D_8016605C;

void func_8013C3E8(void) {
    if (D_8016605C == 1) {
        D_8016605C += 1;
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013C418);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013C56C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013C8A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013C9C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013C9C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CA70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CA9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CAC4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CAFC);

extern void func_80143BD8();
extern void func_80145F78();

void func_8013CB80(void) {
    func_80145F78();
    func_80143BD8();
}

void func_8013CBA8(void) {
    func_80145F78();
    func_80143BD8();
    __asm__ volatile(".set\tnoreorder");
}

__asm__(".L8013CBCC:\n\tnop\n.set\treorder");

__asm__(".set push\n.set noreorder\njr $31\nnop\n.set pop\n");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CBD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CBDC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CCBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CCEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CD38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CF38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013CF58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D0AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D188);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D19C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D1E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D230);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D234);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D278);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D27C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D320);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D394);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D464);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D4C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D4DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D578);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D5F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D610);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D634);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D728);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D8A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013D8DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DA00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DA28);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DA70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DA88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DADC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DAE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DC00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DD14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DDD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DE54);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DE58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DE74);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DE90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DEBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013DFB0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E090);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E2B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E430);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E434);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E458);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E4EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E4F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E514);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E548);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E54C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E584);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E65C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E6B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E6C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E708);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E7D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E81C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013E874);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013EC88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013ED80);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013EE18);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013EF1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013EF64);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013EF78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013EFAC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013EFB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013EFF4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F004);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F080);

void func_8013F094(s32 arg0, s32 arg1) {
    u8 hi;

    hi = arg1 >> 8;
    *(u8 *) arg0 = arg1;
    *(u8 *) (arg0 + 1) = hi;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F0A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F0AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F0C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F0D4);

extern u16 D_80165EE0;

s32 func_8013F0E4(void) {
    s32 *p;
    s32 v;

    p = &D_80165F9C[D_80165EE0];
    v = *p & -2;
    *p = v;
    return v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F110);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F168);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F1C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F20C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F388);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F3A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F3AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F3FC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F4A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F4F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F520);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F644);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F668);

extern void func_800934D0();
extern u16 D_80169700[];

void func_8013F6B4(void) {
    extern void func_8014C858();
    u8 *temp_v0;
    s8 *temp_s0;

    func_80149D48(6);
    temp_v0 = (u8 *) func_8014CBC0();
    temp_s0 = (s8 *) temp_v0;
    func_800934D0(temp_v0[0], temp_v0[4], temp_s0[1], temp_s0[2], temp_s0[3]);
    func_8014C858(D_80169700[temp_v0[4]]);
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F72C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F76C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F78C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F7B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F7DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F878);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F8B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F8D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F900);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F940);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013F978);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013FA00);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013FA08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013FA38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013FE4C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8013FE9C);

extern void func_80146940();

void func_8013FEE4(void) {
    func_80149D48(0xB);
    func_80146940(func_8014CBC0(), 0);
    func_8014C958();
}

extern void func_80146940(s32, s32);

void func_8013FF20(void) {
    func_80149D48(0xB);
    func_80146940(func_8014CBC0(), 1);
    func_8014C958();
}

extern s32 D_801698B8;
extern s32 D_801698BC;
extern void D_80146F90();

void func_8013FF5C(void) {
    register s32 r asm("s2");
    register s32 eleven asm("s3");
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");

    r = func_80133158();
    if (r == 0x7D0) {
        return;
    }
    eleven = 0xB;
    s0 = 0;
    s1 = 0;
loop:
    if ((func_8014CC94(s0) == 0) ||
        (*(s32 *) ((u8 *) &D_801698B8 + s1) != eleven) ||
        (*(s32 *) ((u8 *) &D_801698BC + s1) != r)) {
        s0 += 1;
        s1 += 0x400;
        if (s0 < 0x10) {
            goto loop;
        }
    }
    if (s0 == 0x10) {
        goto done;
    }
    func_8014CA80();
    s0 = 0;
    USE(s0);
    __asm__ volatile(".set\tnoreorder\n\tj D_80146F90\n\taddu %0,$0,$0\n\t.set\treorder" : "=r"(s1));
done:
}

void func_8014001C(s32 arg0, s32 arg1) {
    func_8014BF54(arg0, arg1, 0x20);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014003C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140040);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140048);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801401C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140318);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140340);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140360);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140484);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801404A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140584);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140614);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140644);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140780);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801407D0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014088C);

void func_80140918(void) {
    volatile s32 pad[12];
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140928);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140980);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140988);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140994);

void func_801409A4(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801409AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140B04);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140B20);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140B34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140BB0);

extern s32 D_8008E2C8;

void func_80140BD0(s32 a0, s32 a1) {
    extern s32 func_8008CDD0();
    extern s32 func_8012DA0C(s32, s32);
    extern s32 func_8008D26C(s32, s32, s32, s32, s32);
    extern void func_8014C858(s32);
    extern void func_8017FD80(s32);
    s32 s0v;
    s32 s1v;
    s32 s2v;
    s32 t1;
    s32 t2;
    s32 t3;

    s2v = a1;
    s0v = func_80133158();
    t1 = 0x7D0;
    if (s0v == t1) {
        goto end;
    }
    t2 = 0x6A;
    D_80165FB4 = t2;
    t3 = (s32) &D_8008E2C8;
    D_80173CA8 = t3;
    func_8014CEB4(s0v);
    s1v = func_8008CDD0(s0v);
    func_8012DA0C(s0v, 0x1B);
    func_8008D26C(s0v, 2, 0x1F, 0x1F, 0x1F);
    func_8014C858(0x3C);
    func_8008D26C(s0v, 2, -0x1F, -0x1F, -0x1F);
    func_8014C858(0x3C);
    if (s2v != 0) {
        func_8017FD80(s1v);
    }
end:;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140CA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140CBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140CD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140CE0);

void func_80140CF0(void) {
    s32 sp18;
    s32 temp_v0;
    u8 *p;
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_8008CBB4(var_s0) != 0) {
            temp_v0 = func_8008CDD0(var_s0);
            if (temp_v0 != -1) {
                p = (u8 *) func_80180C90(*(u8 *) (func_80180AFC(temp_v0) + 0x161), &sp18);
                if ((*(u8 *) (p + 0x1BA) & 0x30) && (sp18 != -2)) {
                    func_8008D26C(var_s0, 2, -0x1F, -0x1F, 0);
                }
            }
        }
        __asm__ volatile(".L80140D74:");
        var_s0 += 1;
    } while (var_s0 < 0x15);
}

extern s32 func_8008D26C();

void func_80140D98(s32 arg0) {
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

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140E60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80140E94);

extern s32 func_8008CC14();
extern s32 func_8008CBD8();
extern void func_8012DB00();
extern u8 D_8016D9D8[];

void func_80140FAC(u8 *arg0) {
    extern void func_8012DA0C();
    register s32 s0v asm("s0") = (s32) arg0;
    register s32 s1v asm("s1");
    register u8 s2v asm("s2");
    register s32 s3v asm("s3");
    register s32 a0v asm("a0");
    u8 *p;

    s1v = func_80146078();
    s2v = ((u8 *) s0v)[2];
    s3v = func_80146078(((u8 *) s0v) + 3);
    a0v = (s16) s1v;
    a0v = func_80133158(a0v);
    s1v = a0v;
    if (((u8 *) s0v)[4] != 0) {
        goto nonzero;
    }
    a0v <<= 16;
    func_8008CC14(a0v >> 16);
    __asm__ volatile(".set\tnoreorder\n\tj D_80148024\n\tsll %0,%1,16\n\t.set\treorder" ::"r"(s0v), "r"(s1v));
nonzero:
    a0v <<= 16;
    func_8008CBD8(a0v >> 16);
    s0v = (s16) s1v;
    p = D_8016D9D8 + s0v * 7;
    p[0] = s2v;
    p[6] = 0;
    p[4] = 0;
    func_8012DB00(s0v, s2v);
    func_8012DA0C(s0v, (s16) s3v);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141084);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801410EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141128);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141160);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801411AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801411B4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014124C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014125C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141284);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801412A4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801412A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141300);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014133C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801413F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801413F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141444);

extern void func_80068E80();

void func_80141488(s32 arg0, s32 arg1) {
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
    v0v = (s32) &func_80068E80;
    s0v = 0;
    s4v = 0x80;
    D_80173CA8 = (s32 *) v0v;
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
        func_8014CEB4(a0v, a1v, a2v);
    }
    s0v++;
    if (s0v < 0x28) {
        goto loop;
    }
    __asm__ volatile(".set .L801414EC, func_80141488 + 0x64");
}

extern s32 D_80173C78;

static void func_8014153C(void) {
    s32 v0v;
    s32 v1v = 0;

loop:
    v0v = D_80173C78;
    v0v += v1v;
    *(u8 *) (v0v + 0x39C) = 0;
    v0v = D_80173C78;
    v0v += v1v;
    v1v++;
    *(u8 *) (v0v + 0x3B1) = 0;
    if (v1v < 0x15) {
        goto loop;
    }
}

DEAD_TAIL_LW(2, D_80173C78);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141588);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141654);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801416E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014171C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014175C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801417C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141884);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801418A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141910);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014198C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141990);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801419B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141A60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141A68);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141A8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141B0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141CA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141CE8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141D90);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141D94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141E08);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141E30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80141E88);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142010);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142014);

extern s32 func_8012DCAC();
extern void func_8018E07C();

void func_80142100(s32 a0, s32 a1, s32 a2, s32 a3) {
    extern s32 func_80180AFC();
    register s32 s0v asm("s0");
    register s32 s1v asm("s1");
    register s32 s2v asm("s2");
    register s32 s3v asm("s3");
    register s32 v0 asm("v0");
    register s32 a0v asm("$4");
    register s32 a1v asm("$5");
    s32 v1;

    s0v = a1;
    s2v = a2;
    s3v = a3;
    s1v = func_8012DCAC();
    v0 = 0x7D0;
    if (s1v == v0) {
        goto end;
    }
    a1v = func_80180AFC(s1v);
    v1 = 0;
    do {
        v0 = a1v + v1;
        v1 = v1 + 1;
        *(u8 *) (v0 + 0x1A7) = 0;
        *(u8 *) (v0 + 0x1AC) = 0;
    } while (v1 < 5);
    if (s0v < 0) {
        v0 = s0v + 7;
    } else {
        v0 = s0v;
    }
    a0v = v0 >> 3;
    v0 = s0v - (a0v << 3);
    v1 = 1;
    v1 = v1 << v0;
    if (s2v != 0) {
        v0 = a1v + a0v;
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j D_8014919C\n\t"
                         "sb %0,0x1A7(%1)\n\t"
                         ".set\treorder" : : "r"(v1), "r"(v0));
    }
    v0 = a1v + a0v;
    *(u8 *) (v0 + 0x1AC) = v1;
    v0 = (s32) func_8018E07C;
    D_80173CA8 = v0;
    MEMORY_BARRIER();
    func_8014CEB4(s1v, s3v);
end:;
}

struct Func801421D8_Arg {
    u8 pad0[2];
    u8 unk2;
};

struct Func801421D8_Item {
    u8 pad0[0x161];
    u8 unk161;
};

struct Func801421D8_Obj {
    u8 pad0[0x24];
    u8 unk24;
    u8 pad25;
    u8 unk26;
    u8 pad27;
    u16 unk28;
    u16 unk2A;
    u8 pad2C[0xD];
    u8 unk39;
};

extern s32 func_80147928(s16 *, s32 *);
extern s32 func_801479AC(s16 *, s32 *, s32 *);

void func_801421D8(struct Func801421D8_Arg *arg0) {
    extern s32 func_80147928(s16 *, s32 *);
    extern s32 func_801479AC(s16 *, s32 *, s32 *);
    extern s32 func_8008CDD0();
    extern s32 func_80180AFC();
    extern void func_8012DF68(s32 *, s32, u16);
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s16 sp10;
    s16 temp_s0;
    s32 temp_v0;
    struct Func801421D8_Obj *temp_s0_2;

    temp_s0 = func_80146078((u8 *) arg0 + 3);
    sp10 = func_80146078(arg0);
    if (func_80147928(&sp10, &sp14) != 0) {
        sp18 = 0;
        do {
            if (func_801479AC(&sp10, &sp18, &sp14) != 0) {
                temp_v0 = func_8008CDD0((u16) sp10);
                if (temp_v0 != -1) {
                    temp_s0_2 = (struct Func801421D8_Obj *) func_80180C90(((struct Func801421D8_Item *) func_80180AFC(temp_v0))->unk161, &sp1C);
                    if (sp1C >= 0) {
                        if (arg0->unk2 == 0) {
                            sp20 = temp_s0_2->unk28 + temp_s0;
                            func_8012DF68(&sp20, 0, temp_s0_2->unk2A);
                            temp_s0_2->unk28 = (u16) sp20;
                        }
                        if (arg0->unk2 == 2) {
                            sp20 = temp_s0_2->unk39 + temp_s0;
                            func_8012DF68(&sp20, 0, 0x64);
                            temp_s0_2->unk39 = (u8) sp20;
                        }
                        if (arg0->unk2 == 3) {
                            sp20 = temp_s0_2->unk24 + temp_s0;
                            func_8012DF68(&sp20, 0, 0x64);
                            temp_s0_2->unk24 = (u8) sp20;
                        }
                        if (arg0->unk2 == 4) {
                            sp20 = temp_s0_2->unk26 + temp_s0;
                            func_8012DF68(&sp20, 0, 0x64);
                            temp_s0_2->unk26 = (u8) sp20;
                        }
                    }
                }
                if (sp14 == 0) {
                    break;
                }
            }
            sp18 += 1;
        } while (sp18 < 0x15);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142398);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801423C4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801423EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014243C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014248C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142490);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142494);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801424C8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801424D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142508);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142518);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014252C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014259C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801425A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801425B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801425CC);

extern s32 func_800933C4(u8, u8, u16, s8, s32, s32);

void func_801425E0(void *arg0) {
    u8 *s0v = (u8 *) arg0;
    s32 a0v;
    s32 a1v;
    s32 a2v;
    s32 a3v;
    s32 v0v;
    s32 sp20;
    s32 sp1C;
    s16 sp18;

    sp18 = (s16) func_80146078();
    if (func_80147928(&sp18, &sp1C) == 0) {
        goto end;
    }
    s0v += 2;
    sp20 = 0;
loop:
    a0v = (s32) &sp18;
    a1v = (s32) &sp20;
    a2v = (s32) &sp1C;
    if (func_801479AC(&sp18, &sp20, &sp1C) != 0) {
        func_800933C4(*(u8 *) (s0v + 0), *(u8 *) (s0v + 4), (u16) sp18, *(s8 *) (s0v + 1), *(s8 *) (s0v + 2), *(s8 *) (s0v + 3));
        if (sp1C == 0) {
            goto end;
        }
    }
    sp20 += 1;
    if (sp20 < 0x15) {
        goto loop;
    }
end:
    return;
}

__asm__(".set .L80142674, func_801425E0 + 0x94");

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014268C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142694);

extern s32 func_8008C0AC(s32);
extern s32 func_8012DF0C();

s32 func_80142734(void) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = func_80133158();
    temp_s0 = (s32) ((func_8012DF0C() + 0x200) & 0xF00) >> 8;
    return (u32) (((temp_s0 + func_8008C0AC(temp_s1)) & 0xF) - 7) < 6U;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014278C);

extern u8 D_8016D9DC[];

void func_801428FC(s32 arg0) {
    register s32 a0v asm("a0");
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    a0v = arg0;
    if (a0v != -1) {
        goto nonminus1;
    }
    s0v = 0x15;
    MEMORY_BARRIER();
loop2:
    func_8014CA80(a0v);
    a0v = 0;
    v1v = 0;
loop3:
    v0v = D_8016D9DC[v1v];
    if (v0v == 0) {
        a0v++;
        v1v += 7;
        if (a0v < 0x15) {
            goto loop3;
        }
    }
    if (a0v == s0v) {
        goto end;
    }
    __asm__ volatile("j D_80149914");
nonminus1:
    v1v = func_80133158();
    v0v = 0x7D0;
    if (v1v == v0v) {
        goto end;
    }
    v0v = v1v << 3;
    s0v = v0v - v1v;
loop4:
    func_8014CA80();
    v0v = D_8016D9DC[s0v];
    if (v0v != 0) {
        goto loop4;
    }
end:
    return;
}

extern void func_800440F4(s32);
extern void func_80044018(s32);
extern void func_80044038(s32);
extern void func_8004408C(s32, s32);
extern void func_80149A54();

void func_801429AC(void) {
    struct Func801429AC_Obj {
        u8 unk0;
        u8 unk1;
        u8 unk2;
        u8 unk3;
    };
    struct Func801429AC_Obj *temp_v0;
    s32 temp_s0;
    u8 temp_s2;
    s32 var_a1;
    u8 flag;

    func_80149D48(0x35);
    temp_v0 = (struct Func801429AC_Obj *) func_8014CBC0();
    flag = temp_v0->unk3;
    USE(flag);
    temp_s2 = temp_v0->unk0;
    temp_s0 = temp_s2 + 0x10000;
    if (flag != 0) {
        func_800440F4(temp_s0);
        func_80044018(temp_s0);
        TAIL_JUMP(D_80149A10);
    }
    func_800440F4(temp_s0);
    func_80044038(temp_s0);
    var_a1 = temp_v0->unk1;
    if (var_a1 == 0) {
        var_a1 = 1;
    }
    func_8004408C(temp_s2 | 0x10000, var_a1);
    func_80149A54();
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142A54);

void func_80142B30() {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142B38);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142B5C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142B94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142BA4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142BD0);

void func_80142BE4(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142BEC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142C24);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142C34);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142C48);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142CA8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142CBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142D1C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142D2C);

void func_80142D58(s32 arg0) {
    s32 v0;

    *(s32 *) ((u8 *) &D_801698B8 + v0) = arg0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80142D6C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143018);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801430EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143150);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143154);

s32 func_801432EC(s32 arg0) {
    s32 s0v;
    s32 v0v;
    s32 v1v;

    if (arg0 < 0x80) {
        v1v = (s32) D_80165F9C;
        v0v = arg0 << 2;
        __asm__ volatile(".set\tnoreorder\n\tj D_8014A384\n\taddu %0, %1, %2\n\t.set\treorder"
                         : "=r"(s0v)
                         : "r"(v0v), "r"(v1v)
                         : "memory");
    }
    __asm__ volatile(".set .L80143310, func_801432EC + 0x24");
    if (arg0 < 0x360) {
        v0v = arg0 - 0x80;
        if (v0v < 0) {
            v0v = arg0 - 0x61;
        }
        v0v >>= 5;
        v0v <<= 2;
        v1v = (s32) D_80165F9C;
        v0v += 0x200;
        __asm__ volatile(".set\tnoreorder\n\tj D_8014A384\n\taddu %0, %1, %2\n\t.set\treorder"
                         : "=r"(s0v)
                         : "r"(v0v), "r"(v1v)
                         : "memory");
    }
    if (arg0 < 0x400) {
        v0v = arg0 - 0x360;
        if (v0v < 0) {
            v0v = arg0 - 0x359;
        }
        v0v >>= 3;
        v0v <<= 2;
        v1v = (s32) D_80165F9C;
        v0v += 0x25C;
        __asm__ volatile(".set\tnoreorder\n\tj D_8014A384\n\taddu %0, %1, %2\n\t.set\treorder"
                         : "=r"(s0v)
                         : "r"(v0v), "r"(v1v)
                         : "memory");
    }
    func_8014C958();
end:
    __asm__ volatile(".set .L80143390, func_801432EC + 0xA4");
    return s0v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014339C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801433E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801433F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143418);

extern s32 func_8001DBA8(s32);
extern s32 D_80173C7C;

void func_80143464(void) {
    D_80173C7C = func_8001DBA8(-1);
}

u32 func_8014348C(void) {
    register u32 a0 asm("a0");
    register u32 v0 asm("v0");
    register u32 v1 asm("v1");
    a0 = (u32) D_80173C7C;
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
    D_80173C7C = v0;
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801434D8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801435A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801435E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014362C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801436B0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801436E4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014372C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143790);

void func_801437A8(s32 arg0, u16 *arg1) {
    s32 r;

    r = func_8002398C(0, 0, (s32) (s16) (arg1[0] & 0xFFC0),
                      (s32) (s16) (arg1[1] & 0xFF00));
    func_800254CC((u8 *) arg0, 0, 0, r & 0xFFFF, &D_80165ECC);
}

static s32 func_8014381C(void) {
    return 0;
}

static void func_80143824(void) {
}

static void func_8014382C(void) {
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143834);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801438F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801439C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143A7C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143A9C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143B58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143BD0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143BD8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143C30);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143C84);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143CBC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143D0C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143D10);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80143EC0);

extern void func_8014BAE4();
extern s32 D_80173F5C;
extern u8 D_80169790[];
extern u8 D_801697A0[];

void func_80144264(s32 arg0, void *arg1) {
    s32 a0v = D_80173F5C;
    u16 x = ((u16 *) arg1)[0];
    u16 y = ((u16 *) arg1)[1];

    ((u16 *) arg1)[0] = x - 2;
    ((u16 *) arg1)[1] = y + 2;
    func_8014BAE4(a0v, arg0, (s32) D_801697A0, arg1);
    ((u16 *) arg1)[1] = ((u16 *) arg1)[1] + 4;
    func_8014BAE4(D_80173F5C, arg0, (s32) D_80169790, arg1);
}

extern s32 D_8014B394;

void func_801442F0(s32 a0, s32 a1, s32 a2) {
    D_80173CA8 = (s32) &D_8014B394;
    func_8014CEB4(a0, a1, a2, 0);
}

void func_80144320(s32 a0, s32 a1, s32 a2) {
    D_80173CA8 = (s32) &D_8014B394;
    func_8014CEB4(a0, a1, a2, 1);
}

void func_80144350(s32 a0, s32 a1, s32 a2) {
    D_80173CA8 = (s32) &D_8014B394;
    func_8014CEB4(0, a0, a1, a2);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80144394);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80145014);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014504C);

extern void func_8014C18C();

void func_80145164(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_8014C18C(a0, a1, a2, a3, a4, 0);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014518C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801454A8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_8014557C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80145624);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801456F0);

void func_80145768(void) {
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
        __asm__(".L801457D8:");
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

void func_80145858(s32 arg0) {
    volatile s32 pad[2];
    s32 i = 0;
    if (arg0 > 0) {
        do {
            func_8014CA80();
            i++;
        } while (i < arg0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801458A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801458BC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801458E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80145944);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80145968);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_80145974);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_3", func_801459D0);
