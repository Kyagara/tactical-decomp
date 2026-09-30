#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();
extern void func_801BFA18();
extern void func_801BF754();
extern void func_801C6788();
extern void func_801C78DC(s32);
extern void func_801C9604();
extern void func_801CA804(GpuRect *, GpuRect *);
extern void func_801CA834(GpuRect *, GpuRect *);
extern s16 *D_80173F5C;
extern s16 D_801CE1E8;
extern s32 D_801E9308;

void func_80060004(void) {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 s4;
    s32 s5;
    s32 s6;
    s32 v0;
    s32 a0;
    s32 a1;
    GpuRect rect;
    GpuRect out;
    GpuRect tail;
    u8 pad[0x10];

    s4 = (s16 *) 0x100;
    s0 = (s16 *) 0x40;
    a0 = (s32) &rect;
    a1 = (s32) D_80173F5C;
    v0 = 0x30;
    rect.x = 0x100;
    rect.y = 0;
    rect.w = 0x40;
    rect.h = 0x30;
    func_801CA804(&rect, (GpuRect *) D_80173F5C);
    rect.x = 0x100;
    rect.y = 0xFA;
    rect.w = 0x40;
    rect.h = 4;
    func_801CA804(&rect, (GpuRect *) &D_801CE1E8);
    s3 = (s16 *) &out;
    s6 = (s16 *) 0x3C0;
    v0 = 0x1F0;
    s2 = (s16 *) 0x10;
    s0 = (s16 *) 1;
    rect.x = 0x3C0;
    rect.y = 0x1F0;
    rect.w = 0x10;
    rect.h = 1;
    func_801CA834(&rect, &out);
    tail.x = 0;
    rect.x = 0x120;
    rect.y = 0xFE;
    rect.w = 0x10;
    rect.h = 1;
    func_801CA804(&rect, &out);
    s4 = (s16 *) 0xC;
    s5 = (s32) &tail;
    rect.x = 0x100;
    rect.y = 0xFE;
    rect.w = 0xC;
    rect.h = 1;
    func_801CA804(&rect, &tail);
    rect.x = 0x3C0;
    rect.y = 0x1F4;
    rect.w = 0x10;
    rect.h = 1;
    func_801CA834(&rect, &out);
    tail.x = 0;
    rect.x = 0x130;
    rect.y = 0xFE;
    rect.w = 0x10;
    rect.h = 1;
    func_801CA804(&rect, &out);
    rect.x = 0x110;
    rect.y = 0xFE;
    rect.w = 0xC;
    rect.h = 1;
    func_801CA804(&rect, &tail);
    func_801C9604();
    D_801E9308 = 0;
    func_801BF754();
    func_801C6788();
    func_801C78DC(0);
    func_801C78DC(1);
    func_801C78DC(2);
    func_801C78DC(3);
    func_801C78DC(4);
    func_801BFA18();
}

extern void func_801BF004();
extern void func_801BF3C8(s32);
extern void func_801BF42C(s32);
extern void func_801BF4AC(s32);
extern void func_801BF604();
extern void func_801C6CA0(s32);
extern void func_801CDA80(void *, void *, s32, s32, s32, s32, s32, s32,
                          s32, s32, void *, s32, s32, s32, s32, s32, void *,
                          s32, s32, s32, s32, s32, s32, void *, void *, void *);

extern void *D_80173FF8;
extern u8 D_801CE0E0[];
extern s32 D_801CE180;
extern u8 D_801D87EC[];
extern u8 D_801E04EC[];
extern u8 D_801E08AC[];
extern u8 D_801E099C[];
extern u8 D_801E0B9C[];
extern u8 D_801E0D74[];
extern u8 D_801E1044[];
extern u8 D_801E1184[];
extern s16 D_801E9068;
extern s16 D_801E906C;
extern s16 D_801E9070;
extern s16 D_801E9074;
extern s16 D_801E908C;
extern s16 D_801E9090;
extern s16 D_801E9094;
extern s16 D_801E9098;
extern s16 D_801E909C;
extern s16 D_801E90A0;
extern s16 D_801E90A4;
extern s16 D_801E90A8;
extern s16 D_801E90B0;
extern s16 D_801E90B4;
extern s16 D_801E90C0;
extern s16 D_801E90E4;
extern s16 D_801E90FC;
extern u16 D_801E9100;
extern s16 D_801E9104;
extern s16 D_801E9224;
extern s16 D_801E9228;
extern s16 D_801E9230;
extern s16 D_801E924C;
extern s16 D_801E92D4;
extern s16 D_801E92F8;

void func_800601D8(s32 arg0) {
    D_801E9100 = 0x40;
    D_801E90B4 = 0x190;
    D_801E9090 = 0xA;
    D_801E9228 = 0xA;
    D_801E9230 = 0x14;
    D_801E9104 = 6;
    D_801E9224 = 0x1E;
    D_801E9068 = 0;
    D_801E90A8 = 0;
    D_801E9070 = 0;
    D_801E906C = 0;
    D_801E90B0 = 0;
    D_801E9074 = 0;
    D_801E90C0 = 0;
    D_801E9098 = 0;
    D_801E90A0 = 0;
    D_801E9094 = 0;
    D_801E909C = 0;
    D_801E90A4 = 0;
    D_801E924C = 0;
    D_801E92D4 = 0;
    D_801E92F8 = 0;
    D_801E908C = 0;
    D_801E90E4 = 0;
    D_801E90FC = 0;
    func_801CDA80(D_801E0B9C, D_801E099C, 0, 0, 0, D_801D87EC,
                  0, 0, 0, 0, D_801E1044, 0, 0, 0, 0, 0, D_801E1184,
                  0, 0, 0, 0, 0, 0, D_801E04EC, D_801E08AC, D_801E0D74);
    func_801C6CA0(arg0);
    func_801BF004();
    D_801CE180 = arg0;
    D_80173FF8 = D_801CE0E0;
    func_801BF604();
    func_801BF3C8(1);
    func_801BF42C(1);
    func_801BF4AC(1);
}

extern s32 func_8014CA1C();
extern void func_8014C8A0();
extern void func_8014CA38();
extern void func_801C8EF4();
extern u8 D_801C0318[];
extern u8 D_801CE178[];

void func_800603C8(s32 arg0) {
    if (arg0 == 0) {
        goto L_then;
    }
    if (func_8014CA1C(0xD) != 0) {
        goto L_epi;
    }
    func_8014C8A0(0xD, D_801C0318);
    func_8014CA38(0xD, D_801CE178, 0, 0);
    TAIL_JUMP(func_801BF41C);
L_then:
    func_801C8EF4(0xD);
L_epi:;
}

extern u8 D_801C1744[];
extern u8 D_801CE18C[];
extern void func_801BF4AC();
extern void func_801BF498();

void func_8006042C(s32 arg0) {
    if (arg0 == 0) {
        goto L_then;
    }
    if (func_8014CA1C(0xA) != 0) {
        goto L_mid;
    }
    func_8014C8A0(0xA, D_801C1744);
    func_8014CA38(0xA, D_801CE18C, 0, 0);
L_mid:
    func_801BF4AC(arg0);
    TAIL_JUMP(func_801BF498);
L_then:
    func_801C8EF4(0xA);
    func_801C8EF4(0xC);
L_epi:;
}

extern u8 D_801C31C4[];
extern u8 D_801CE1A0[];

void func_800604AC(s32 arg0) {
    if (arg0 == 0) {
        goto L_then;
    }
    if (func_8014CA1C(0xC) != 0) {
        goto L_epi;
    }
    func_8014C8A0(0xC, D_801C31C4);
    func_8014CA38(0xC, D_801CE1A0, 0, 0);
    TAIL_JUMP(func_801BF500);
L_then:
    func_801C8EF4(0xC);
L_epi:;
}

extern u8 D_801CE1B4[];
extern s32 D_801CE414;
extern s32 D_801CE1B0;
extern void func_801BF56C();

void func_80060510(s32 arg0) {
    s32 local = arg0;

    if (local == 0) {
        goto L_then;
    }
    if (func_8014CA1C(0xB) != 0) {
        goto L_epi;
    }
    func_8014C8A0(0xB, D_801C31C4);
    func_8014CA38(0xB, D_801CE1B4, 0, 0);
    TAIL_JUMP(func_801BF56C);
L_then:
    func_801C8EF4(0xB);
L_epi:
    D_801CE414 = local;
    D_801CE1B0 = local;
}

extern s32 D_801CE184;
extern s32 D_801CE1AC;
extern s32 D_801CE1C0;
extern s32 D_801CE198;

void func_80060590(void) {
    D_801CE184 = 1;
    D_801CE1AC = 1;
    D_801CE1C0 = 1;
    D_801CE198 = 1;
}

extern void func_801BF510();
extern s32 D_801CE19C;
extern s32 D_801CE1C4;

void func_800605BC(void) {
    func_801C8EF4(0xD);
    func_801C8EF4(0xA);
    func_801C8EF4(0xC);
    func_801BF510(0);
    D_801CE1C4 = 0;
    D_801CE19C = 0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80060604);

extern u8 D_801E90F2[];

void func_80060754(s16 arg0) {
    s32 i;
    s16 *p;
    arg0 = -1;
    i = 3;
    p = (s16 *) D_801E90F2;
    for (; i >= 0; i--) {
        *p = arg0;
        p--;
    }
}

extern void func_801C8DAC();
extern void func_80043FF8();
extern s8 D_801CE1C9;
extern s16 D_801CFBB8;
extern s32 D_80166028;

void func_8006077C(s32 arg0, s32 arg1) {
    func_801C8DAC(1, 0x2B, arg0, 0);
    D_801CE1C9 = 1;
    func_80043FF8(arg1);
    D_801CFBB8 = 1;
    D_80166028 = 1;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_800607E0);

extern void func_800222FC();
extern u8 D_801E12C4[];

void func_80060A18(void) {
    func_800222FC(D_801E12C4, 0, 0x1E);
}

extern u16 D_801E12C4_w[] asm("D_801E12C4");
extern u16 D_801E12C6[];
extern s16 D_801E12C8[];

void func_80060A44(s32 arg0) {
    func_800222FC(&D_801E12C4[arg0 * 6], 0, 6);
}

void func_80060A80(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_801E12C4_w[arg0 * 3] = arg1;
    D_801E12C6[arg0 * 3] = arg2;
    D_801E12C8[arg0 * 3] = *(u16 *) (arg1 * 2 + arg3) & 0x3FF;
}

extern void func_801BFBBC(s32);

void func_80060ACC(s32 arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    s32 i;
    s32 f;
    s32 v;
    s32 n;
    s32 m;
    s32 key;
    s32 unused[2];

    *arg1 = (s16) D_801E12C4_w[arg0 * 3];
    f = 0;
    KEEP(f);
    *arg2 = (s16) D_801E12C6[arg0 * 3];
    key = D_801E12C8[arg0 * 3];
    v = *arg1;
    i = 0;
    if (v > 0) {
        m = -1;
        n = v;
        do {
            if (arg3[i] == m) {
                f = 1;
            }
            i++;
        } while (i < n);
    }
    i = 0;
    if (key == arg3[*arg1] && f == 0) {
        return;
    }
    if (arg3[0] == -1) {
        goto L2;
    }
    for (;;) {
        if ((arg3[i] & 0x3FF) == key) {
            __asm__(".set\tnoreorder\n\tj func_801BFBBC\n\tsh %0,0(%1)\n\t.set\treorder" : : "r"(i), "r"(arg1) : "memory");
        }
        i++;
        if (arg3[i] == -1) {
            break;
        }
    }
L2:
    *arg1 = 0;
    *arg2 = 0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80060BC8);

extern void func_8014BF54();
extern u8 D_801CE7F8[];

void func_80060D98(EventCoord28 *arg0) {
    *(u16 *) &arg0->at_1C = 0;
    *(u16 *) &arg0->pad_26[0] = 0;
    func_8014BF54((u8 *) &arg0->at_20, D_801CE7F8, 8);
}

void func_80060DCC(u16 *arg0, u32 arg1) {
    arg0[0] = (arg1 & 0x3F) << 4;
    arg0[1] = (arg1 & 0xFFFF) >> 6;
    arg0[2] = 0x10;
    arg0[3] = 1;
}

extern void func_80136BD0();

void func_80060DF8(s32 arg0, s32 arg1) {
    if (!(arg0 & 0x300)) {
        func_80136BD0(arg1, arg0);
    }
}

void func_80060E28(u8 *arg0, s32 arg1) {
    s32 t0;
    s32 t1;
    s32 u0;
    s32 u1;

    if (arg0[0xC] != arg0[0x14]) {
        MEMORY_BARRIER();
        t0 = arg0[0xC] + arg1;
        t1 = arg0[0x1C] + arg1;
        arg0[0xC] = t0;
        TAIL_JUMP_SB_1C(func_801BFE70, t1, arg0, t0);
    }
    t0 = arg0[0xD] + arg1;
    t1 = arg0[0x1D] + arg1;
    arg0[0xD] = t0;
    arg0[0x1D] = t1;
    MEMORY_BARRIER();
    u0 = *(u16 *) (arg0 + 0x10) - arg1;
    u1 = *(u16 *) (arg0 + 0x20) - arg1;
    *(u16 *) (arg0 + 0x10) = u0;
    *(u16 *) (arg0 + 0x20) = u1;
}

void func_80060E8C(u8 *arg0, s32 arg1) {
    EventRecord34 *r = (EventRecord34 *) arg0;
    u8 c = r->f0C[0];
    s32 t8 = r->f08 + arg1;
    s32 t18;
    s32 s14;
    s32 s24;
    s32 delta_15;
    s32 delta_25;

    r->f08 = t8;
    t18 = *(u16 *) r->f18 + arg1;
    *(u16 *) r->f18 = t18;
    if (c != *(u8 *) &r->f14) {
        MEMORY_BARRIER();
        s14 = *(u8 *) &r->f14 - arg1;
        s24 = r->f24[0] - arg1;
        *(u8 *) &r->f14 = s14;
        TAIL_JUMP_SB_24(func_801BFEE8, s24, arg0, s14);
    }
    delta_15 = ((u8 *) &r->f14)[1] - arg1;
    delta_25 = r->f24[1] - arg1;
    ((u8 *) &r->f14)[1] = delta_15;
    r->f24[1] = delta_25;
    MEMORY_BARRIER();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80060EF0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80061318);

void func_8006251C(void) {
}

extern void func_80023C68(void *, s32);
extern void func_80023DD0(void *);
extern void func_80023DE4(void *);
extern void func_8014A6E4(void *, s32);

void func_80062524(u8 *arg0) {
    register u8 *s0 asm("s0");
    register s32 s1 asm("s1");
    register EventInitBlock *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");

    s2 = (EventInitBlock *) arg0;
    s0 = (u8 *) &s2->first;
    func_80023DD0(s0);
    s1 = (s32) (u8 *) &s2->second;
    func_80023DD0((void *) s1);
    func_80023C68(s0, 1);
    func_80023C68((void *) s1, 1);
    s3 = 0;
    s1 = 0x224;
    s2->first.at_04 = 0x30;
    s2->first.at_05 = 0x30;
    s2->first.at_06 = 0x30;
    s2->second.at_04 = 0x30;
    s2->second.at_05 = 0x30;
    s2->second.at_06 = 0x30;
    s2->first.at_08 = 0x12;
    s2->first.at_0A = 1;
    s2->first.at_0C = 0x10;
    s2->first.at_0E = 0x5A;
    s2->second.at_08 = 0x7C;
    s2->second.at_0A = 1;
    s2->second.at_0C = 0x10;
    s2->second.at_0E = 0x5A;
    do {
        s0 = (u8 *) s2 + s1;
        func_80023DE4(s0);
        func_80023C68(s0, 1);
        s3 += 1;
        s1 += 0x10;
    } while (s3 < 8);
    a0 = (s32) s2;
    a1 = 0;
    a2 = 1;
    v1 = 0x10;
    v0 = 0x20;
    s2->entries[1].at_04 = v0;
    s2->entries[1].at_05 = v0;
    s2->entries[1].at_06 = v0;
    s2->entries[2].at_04 = v0;
    s2->entries[2].at_05 = v0;
    s2->entries[2].at_06 = v0;
    s2->entries[5].at_04 = v0;
    s2->entries[5].at_05 = v0;
    s2->entries[5].at_06 = v0;
    s2->entries[6].at_04 = v0;
    s2->entries[6].at_05 = v0;
    s2->entries[6].at_06 = v0;
    v0 = 0x10;
    a2 = 1;
    USE(a2);
    s2->entries[0].at_04 = v1;
    s2->entries[0].at_05 = v1;
    s2->entries[0].at_06 = v1;
    s2->entries[3].at_04 = v1;
    s2->entries[3].at_05 = v1;
    s2->entries[3].at_06 = v1;
    s2->entries[4].at_04 = v1;
    s2->entries[4].at_05 = v1;
    s2->entries[4].at_06 = v1;
    s2->entries[7].at_04 = v1;
    s2->entries[7].at_05 = v1;
    s2->entries[7].at_06 = v1;
    v1 = 0x5A;
    s2->entries[0].at_08 = v0;
    s2->entries[0].at_0C = v0;
    v0 = 0x11;
    s2->entries[1].at_08 = v0;
    s2->entries[1].at_0C = v0;
    MEMORY_BARRIER();
    v0 = 0x22;
    *(volatile u16 *) &s2->entries[0].at_0A = a2;
    *(volatile u16 *) &s2->entries[0].at_0E = v1;
    *(volatile u16 *) &s2->entries[1].at_0A = a2;
    *(volatile u16 *) &s2->entries[1].at_0E = v1;
    *(volatile u16 *) &s2->entries[2].at_08 = v0;
    *(volatile u16 *) &s2->entries[2].at_0A = a2;
    *(volatile u16 *) &s2->entries[2].at_0C = v0;
    v0 = 0x23;
    *(volatile u16 *) &s2->entries[3].at_08 = v0;
    *(volatile u16 *) &s2->entries[3].at_0C = v0;
    v0 = 0x7A;
    *(volatile u16 *) &s2->entries[4].at_08 = v0;
    *(volatile u16 *) &s2->entries[4].at_0C = v0;
    v0 = 0x7B;
    *(volatile u16 *) &s2->entries[5].at_08 = v0;
    *(volatile u16 *) &s2->entries[5].at_0C = v0;
    v0 = 0x8C;
    *(volatile u16 *) &s2->entries[6].at_08 = v0;
    *(volatile u16 *) &s2->entries[6].at_0C = v0;
    v0 = 0x8D;
    *(volatile u16 *) &s2->entries[2].at_0E = v1;
    *(volatile u16 *) &s2->entries[3].at_0A = a2;
    *(volatile u16 *) &s2->entries[3].at_0E = v1;
    *(volatile u16 *) &s2->entries[4].at_0A = a2;
    *(volatile u16 *) &s2->entries[4].at_0E = v1;
    *(volatile u16 *) &s2->entries[5].at_0A = a2;
    *(volatile u16 *) &s2->entries[5].at_0E = v1;
    *(volatile u16 *) &s2->entries[6].at_0A = a2;
    *(volatile u16 *) &s2->entries[6].at_0E = v1;
    *(volatile u16 *) &s2->entries[7].at_08 = v0;
    *(volatile u16 *) &s2->entries[7].at_0A = a2;
    *(volatile u16 *) &s2->entries[7].at_0C = v0;
    s2->entries[7].at_0E = v1;
    func_8014A6E4((u8 *) s2, 0);
    func_8014A6E4((u8 *) s2 + 0xC, 2);
    func_8014A6E4((u8 *) s2 + 0x18, 4);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80062744);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80062D90);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80063364);

extern void func_80023C90(void *, s32);
extern void func_801C2C44();

void func_80063AF0(u8 *arg0, u8 *arg1) {
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
    if (v0 != 1 && D_80166028 != 1) {
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
    TAIL_JUMP(func_801C2C44);
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
}

extern void func_8012F454();
extern void func_8012F3CC();

void func_80063C6C(s32 arg0, u8 *arg1) {
    if (*(s32 *) (arg1 + 0x10) == 1 || D_80166028 == 1) {
        func_8012F454();
        TAIL_JUMP(func_801C2CB0);
    }
    func_8012F3CC();
}

extern void func_801C2D70(s16);
extern void func_801C2D78(s16);
extern void func_801C2EC0(s32, s32, s32, void *);

void func_80063CC0(s32 arg0, u8 *arg1, void *arg2, s32 arg3) {
    register s32 s5 asm("$21");
    register u8 *s3 asm("$19");
    register u8 *s1 asm("$17");
    register u8 *s0 asm("$16");
    register s32 s4 asm("$20");
    register s32 s2 asm("$18");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    s32 pad[2];

    s5 = arg0;
    KEEP_WITH_NOVOL(s5, arg0);
    s3 = arg1;
    KEEP_WITH_NOVOL(s3, arg1);
    s1 = (u8 *) arg2;
    KEEP_WITH_NOVOL(s1, arg2);
    s4 = arg3;
    KEEP_WITH_NOVOL(s4, arg3);
    s2 = 0;
    KEEP_WITH_NOVOL(s2, s2);
    if (s4 <= 0) {
        goto normal;
    }
    s0 = arg1 + 8;
    do {
        v0 = *(s32 *) (s0 - 4);
        MEMORY_BARRIER();
        a0 = *(s16 *) v0;
        v0 = *(u16 *) s3;
        *(u16 *) s1 = (u16) v0;
        v0 = *(u16 *) (s0 - 6);
        *(u16 *) (s1 + 2) = (u16) v0;
        v0 = *(u16 *) s0;
        MEMORY_BARRIER();
        v0 &= 0xF3FF;
        *(u16 *) s0 = (u16) v0;
        if (a0 < 0) {
            v0 = 0x88888888;
            *(volatile u32 *) (s1 + 0xC) = v0;
            v0 = *(u16 *) s0;
            __asm__ volatile("\t.set\tnoreorder\n\tlhu $2,0($16)\n\tj func_801C2D70\n\tnegu $4,$4\n\t.set\treorder" : : "r"(a0) : "memory");
        }
        if (a0 > 0) {
            v0 = 0xCCCCCCCC;
            *(volatile u32 *) (s1 + 0xC) = v0;
            __asm__ volatile("\t.set\tnoreorder\n\tlhu $2,0($16)\n\tj func_801C2D78\n\tori $2,$2,0x400\n\t.set\treorder" ::: "memory");
        }
        *(volatile u32 *) (s1 + 0xC) = 0;
        MEMORY_BARRIER();
        v0 = *(u16 *) s0;
        __asm__ volatile("nop\n\tori $2,$2,0x800" ::: "memory");
        *(u16 *) s0 = (u16) v0;
        MEMORY_BARRIER();
        __asm__ volatile("lh $5,0($16)" : "=r"(a1) : : "memory");
        s0 += 0xC;
        __asm__ volatile("addiu $19,$19,12\n\taddiu $18,$18,1" ::: "memory");
        a2 = s5;
        func_801C2EC0(a0, a1, a2, s1);
        *(u32 *) (s1 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

extern void func_801C2E74(s16, s32);

void func_80063DCC(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    register s32 s5 asm("$21");
    register u8 *s3 asm("$19");
    register u8 *s0 asm("$16");
    register s32 s4 asm("$20");
    register s32 s2 asm("$18");
    register u8 *s1 asm("$17");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    s32 pad[2];

    s5 = arg0;
    KEEP_WITH_NOVOL(s5, arg0);
    s3 = arg1;
    KEEP_WITH_NOVOL(s3, arg1);
    s0 = arg2;
    KEEP_WITH_NOVOL(s0, arg2);
    s4 = arg3;
    KEEP_WITH_NOVOL(s4, arg3);
    s2 = 0;
    KEEP_WITH_NOVOL(s2, s2);
    if (s4 <= 0) {
        goto normal;
    }
    s1 = arg1 + 8;
    do {
        v0 = *(s32 *) (s1 - 4);
        MEMORY_BARRIER();
        a0 = *(s16 *) v0;
        v0 = *(u16 *) s3;
        *(u16 *) s0 = (u16) v0;
        v0 = *(u16 *) (s1 - 6);
        *(u16 *) (s0 + 2) = (u16) v0;
        a1 = *(s16 *) s1;
        a1 &= 0xF3FF;
        if (a0 < 0) {
            a0 = -a0;
            a1 |= 0x800;
            v0 = 0x77777777;
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C2E74\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        if (a0 > 0) {
            a1 |= 0x400;
            v0 = 0xBBBBBBBB;
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C2E74\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        *(volatile u32 *) (s0 + 0xC) = 0;
        MEMORY_BARRIER();
        a1 &= 0xFFF0;
        a1 |= 0x804;
        a2 = s5;
        func_801C2EC0(a0, a1, a2, s0);
        s1 += 0xC;
        s3 += 0xC;
        s2++;
        *(u32 *) (s0 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80063EC0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_800641C4);

extern s32 *func_8014A578(s32);
extern u8 *func_8014CBC0();
extern void func_8012F04C(s32);
extern void func_80137C10(void *, s32);
extern void func_80137ED4(void *, s32 *);
extern void func_80137F84(void *);
extern s32 func_80138094(s32);
extern void func_80138174(void *, void *, void *);
extern void func_80138460(void *);
extern void func_80138570(void *, void *, s32, s32);
extern void func_80138B10(void *);
extern void func_8014A6CC(s32, s32);
extern void func_8014B2F0(s16, s32, s32 *);
extern void func_8014BF54(s32, s32, s32);
extern s32 func_8014C4A8(s16, s16, void *, s32);
extern void func_8014C958();
extern void func_8014CA80();
extern void func_801C37EC();
extern s32 D_80165F8C;
extern s32 D_80165FA8;
extern s32 *D_801E17D4;

void func_8006473C(void) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    u8 *fp;
    register u8 *s0 asm("$16");
    register volatile u8 *s1 asm("s1");
    register s32 s2 asm("$18");
    register s32 s3 asm("$19");
    register u32 s4 asm("$20");
    register s16 *s5 asm("$21");
    register s32 s6 asm("$22");
    register s32 s7 asm("$23");
    struct {
        s32 sp10[2];
        u8 sp18[0x7C];
        u8 sp94[0x7C];
        s32 sp110;
    } stack;

    D_801E17D4 = func_8014A578(0);
    s0 = func_8014CBC0();
    s1 = stack.sp18;
    v0 = *(u16 *) (s0 + 0xA);
    v1 = *(s16 *) (s0 + 0x38);
    *(u16 *) (s0 + 0xA) = v0 & 0xFFFE;
    stack.sp110 = v1;
    if (v1 == -1) {
        stack.sp110 = 0;
    }
    func_80138174(stack.sp10, s0, s1);
    func_8014BF54((s32) &stack.sp94, (s32) &stack.sp18, 0x7C);
    s4 = 0;
    s2 = 0;
    KEEP(s2);
    s7 = 1;
    KEEP(s7);
    s6 = (s32) &D_80165FA8;
    MEMORY_BARRIER();
    fp = s1;
    KEEP(fp);
    s5 = *(s16 **) (s0 + 0x30);
    *(volatile s16 *) s5 = 1;
    MEMORY_BARRIER();
    v0 = *s5;
    if (v0 != s7) {
        goto flag_skip;
    }
    v1 = s2 & 1;
    *s5 = 0;
    a0 = *(s16 *) (s0 + 4);
    a1 = *(s16 *) (s0 + 6);
    a2 = (s32) stack.sp10;
    a3 = 1;
    USE(a3);
    s3 = func_8014C4A8(a0, a1, (void *) a2, a3);
    s4 = 0x00000001;
    *(s32 *) s6 = *(s16 *) (s0 + 4);
    a0 = 8;
    a1 = 9;
    v1 = *(s16 *) (s0 + 4);
    func_8014A6CC(a0, a1);
    a0 = *(s16 *) (s0 + 0x1C);
    D_80165F8C = 0;
    a1 = s3;
    a2 = s6 - 8;
    func_8014B2F0(a0, a1, (s32 *) a2);
    func_800248FC((void *) stack.sp10, s3);
flag_skip:
    v1 = s2 & 1;
    v0 = v1 << 5;
    v0 -= v1;
    v0 <<= 2;
    s1 = (u8 *) fp + v0;
    func_8014CA80();
    USE(fp);
    if (s4 != s7) {
        goto call_done;
    }
    MEMORY_BARRIER();
    a0 = s3;
    func_8012F04C(a0);
    s4 = 0;
    USE(s4);
call_done:
    v0 = *(u16 *) &stack.sp110;
    a0 = D_801E17D4;
    *(s16 *) (s0 + 0x38) = v0;
    v0 = func_80138094(a0);
    if (v0 == 0) {
        a0 = (s32) s0;
        func_80137ED4((void *) a0, &stack.sp110);
        a1 = *(s32 *) &stack.sp110;
        a0 = (s32) s0;
        func_80137C10((void *) a0, a1);
        a0 = (s32) s0;
        func_80137F84((void *) a0);
        a0 = (s32) s1;
        func_80138460((void *) a0);
        a0 = (s32) s0;
        a1 = (s32) s1;
        a2 = s2;
        a3 = *(s32 *) &stack.sp110;
        USE(a2);
        func_80138570((void *) a0, (void *) a1, a2, a3);
        s2 += 1;
        USE(s2);
        a0 = (s32) s1;
        func_80138B10((void *) a0);
        TAIL_JUMP_MEM(func_801C37EC);
    }
    func_8014CA80();
    func_8014C958();
}

extern s32 D_80174038;
extern s32 D_80165F98;
extern s32 D_801308C0;
extern void func_8014C8A0(s32, void *);
extern void func_8014CA58(s32, u16, u16, s32, s32);
extern void func_8014C9D0(s32);

void func_8006492C(void) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    register s32 s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 s2 asm("$18");
    register s32 s3 asm("$19");
    s32 *ptr;
    u16 t1;
    u16 t2;

    v0 = D_80174038;
    v1 = D_80165F98;
    v0 <<= 10;
    v0 += v1;
    s0 = *(s32 *) v0;
    v0 = *(s32 *) (s0 + 0x30);
    v0 = *(s32 *) v0;
    ((void (*)(void)) v0)();
    ptr = func_8014A578(0);
    a0 = s0;
    s3 = *(volatile u16 *) (a0 + 0x1C);
    v1 = *(volatile s32 *) (a0 + 0x30);
    s2 = *(u16 *) (a0 + 0x2C);
    D_801E17D4 = ptr;
    s1 = *(u16 *) (v1 + 6);
    t1 = s1;
    s0 = *(u16 *) (v1 + 4);
    t2 = s0;
    a1 = 0;
    *ptr = 0x20;
    func_80137C10((void *) a0, a1);
    func_8014C8A0(t1, (void *) &D_801308C0);
    func_8014CA58(t1, s2, s3, t2, t2);
    func_8014C9D0(D_80174038 - 1);
    func_8014C9D0(t1);
    func_8014C958();
}

void func_80064A24(void) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    register u8 *s0 asm("$16");
    register s32 s1 asm("s1");
    register u8 *s2 asm("$18");
    register s32 s3 asm("$19");
    register s32 s4 asm("$20");
    register s32 s5 asm("$21");
    register s32 s6 asm("$22");
    struct {
        s32 sp10[2];
        u8 sp18[0x7C];
        u8 sp94[0x7C];
        s32 sp110;
    } stack;

    stack.sp110 = 0;
    s2 = (u8 *) func_8014CBC0();
    s0 = stack.sp18;
    a0 = (s32) stack.sp10;
    KEEP(a0);
    a1 = (s32) s2;
    a2 = s0;
    func_80138174((void *) a0, (void *) a1, (void *) a2);
    a0 = (s32) &stack.sp94;
    a1 = s0;
    a2 = 0x7C;
    func_8014BF54((void *) a0, (void *) a1, a2);
    s4 = 1;
    KEEP(s4);
    s1 = 0;
    KEEP(s1);
    s5 = (s32) &D_80165FA8;
    KEEP(s5);
    s6 = s0;
    KEEP(s6);
    if (s1 % 7 == 0) {
        s4 = 1;
        a0 = *(s16 *) (s2 + 4);
        a1 = *(s16 *) (s2 + 6);
        a2 = (s32) stack.sp10;
        a3 = 1;
        s3 = func_8014C4A8(a0, a1, (void *) a2, a3);
        a0 = 8;
        a1 = 9;
        func_8014A6CC(a0, a1);
        *(s32 *) s5 = *(s16 *) (s2 + 4);
        a0 = *(s16 *) (s2 + 0x1C);
        a1 = s3;
        a2 = s5 - 8;
        func_8014B2F0(a0, a1, (s32 *) a2);
        a0 = (s32) stack.sp10;
        KEEP(a0);
        a1 = s3;
        func_800248FC((void *) a0, a1);
    }
    func_8014CA80();
    if (s4 == 1) {
        a0 = s3;
        func_8012F04C(a0);
        s4 = 0;
        KEEP(s4);
    }
    a0 = (s32) &stack.sp110;
    if (func_80138094(a0) == 0) {
        v1 = s1 & 1;
        v0 = v1 << 5;
        v0 -= v1;
        v0 <<= 2;
        s0 = (u8 *) s6 + v0;
        a0 = s0;
        func_80138460((void *) a0);
        a0 = s0;
        func_80138B10((void *) a0);
        __asm__ volatile(".set\tnoreorder\n\tj func_801C3A8C\n\taddiu %0,%0,0x1\n\t.set\treorder" : "=r"(s1));
    }
    func_8014CA80();
    func_8014C958();
}

extern void func_80136B10(u8 *);

void func_80064B98(u8 *arg0) {
    u8 buf[24];

    func_80136B10(buf);
    *(u16 *) arg0 = buf[0xC];
    *(u16 *) (arg0 + 2) = buf[0xD];
    *(u16 *) (arg0 + 4) = 0x10;
    *(u16 *) (arg0 + 6) = 0x10;
    *(u16 *) (arg0 + 8) = *(u16 *) (buf + 0xE);
    *(u16 *) (arg0 + 0xA) = func_8002398C(0, 0, 0x380, 0x120);
}

void func_80064C00(void) {
}

s32 func_80064C08(s32 arg0) {
    arg0 <<= 10;
    return *(s32 *) (arg0 + D_80165F98 + 0x48);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80064C24);

extern void func_8014C858();

void func_800650FC(void) {
    func_8014C858(1);
    TAIL_JUMP(func_801C4104);
}

extern s32 func_801C81CC();
extern s32 func_801C8188();
extern u8 D_801E9108[];

s32 func_80065124(s32 arg0) {
    u8 *base = D_801E9108;
    u16 *p = (u16 *) (base + (arg0 << 1));
    s32 v = func_801C81CC(*p & 0x3FF);
    s32 a = v;

    if (*p & 0x4000) {
        a = v | 0x40000000;
    }
    return a;
}

s32 func_80065180(s32 arg0) {
    u8 *base = D_801E9108;
    u16 *p = (u16 *) (base + (arg0 << 1));
    s32 v = func_801C8188(*p & 0x3FF);
    s32 a = v;

    if (*p & 0x4000) {
        a = v | 0x40000000;
    }
    return a;
}

extern s32 func_801C8860(s32);
extern void func_801C8884(s32, u8 *);
extern u8 D_801E8CC4[];
extern u16 D_801E8CCC;
extern u16 D_801E8CCE;
extern u16 D_801E90D0;
extern u16 D_801D86BA;

u8 *func_800651DC(s32 arg0) {
    func_801C8884(func_801C8860(*(s16 *) (D_801E9108 + arg0 * 2)), D_801E8CC4);
    D_801E8CCC = D_801E90D0;
    D_801E8CCE = D_801D86BA;
    return D_801E8CC4;
}

extern void func_801C3B98();
extern u8 D_801E8CD0[];

u8 *func_8006524C(s32 arg0) {
    func_801C3B98(D_801E8CD0, D_801E9108[arg0 * 2]);
    return D_801E8CD0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80065290);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80065490);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80065A10);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80065DCC);

extern s16 D_801CE432;

s32 func_80065F38(void) {
    return D_801CE432;
}

extern s16 D_801CE438;

s32 func_80065F48(void) {
    return D_801CE438;
}

s32 func_80065F58(void) {
    s32 v;
    v = D_801CE432;
    if (v == 0) {
        return 0x20000000;
    }
    return v;
}

s32 func_80065F78(void) {
    s32 v;
    v = D_801CE438;
    if (v == 0) {
        return 0x20000000;
    }
    return v;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80065F98);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006626C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006661C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80066920);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80066A68);

typedef struct {
    s16 f0;
    s16 f2;
    u8 pad_10[0x10];
} EventRecord14;

extern void func_801C9F30(s16 *, s32, s32, s32, s32);
extern void func_801CAA68(void *, s32);
extern s32 func_801CD558();
extern s32 D_801CF8F0;
extern EventRecord14 D_801CF96C[];
extern s16 D_801CF9D0;
extern s16 D_801CF9D2;
extern u8 D_801CF9E4[];

void func_80066DD0(s32 arg0, s32 arg1) {
    register EventRecord14 *s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 s2 asm("$18");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");

    s1 = arg1;
    KEEP_NOVOL(s1);
    a0 = (s32) &D_801CF8F0;
    s2 = D_801CF9E4[s1];
    func_801CAA68((void *) a0, 0);
    s0 = (EventRecord14 *) s1;
    s0 = (EventRecord14 *) ((s32) s0 << 2);
    s0 = (EventRecord14 *) ((s32) s0 + s1);
    s0 = (EventRecord14 *) ((s32) s0 << 2);
    s0 = (EventRecord14 *) ((s32) s0 + (s32) D_801CF96C);
    v0 = 0x40;
    v1 = (unsigned) s1 < 1;
    v0 -= v1;
    s0->f2 = v0;
    s0->f0 = s2;
    func_801C9F30((s16 *) s0, func_801CD558(), 0, 0, 0xE);
    a0 = (s32) &D_801CF9D0;
    v0 = 3;
    if (s1 == v0) {
        v1 = s2 + 7;
    } else {
        v1 = s2 + 9;
    }
    a1 = 0;
    KEEP_NOVOL(a1);
    a2 = 0;
    KEEP_NOVOL(a2);
    a3 = 0;
    KEEP_NOVOL(a3);
    v0 = 0x4A;
    *(s16 *) a0 = v1;
    D_801CF9D2 = v0;
    v0 = 0xF;
    func_801C9F30((s16 *) a0, a1, a2, a3, v0);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80066EAC);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_800671D4);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80067598);

extern u8 D_800596E0[];
extern u8 D_801E8EA8[];
extern void func_800222DC();
extern u8 *func_80059AF0();

void func_80067788(void) {
    s32 s0v;
    s32 s1v;
    s32 a0;
    s32 a1;
    s32 v0;
    u32 v1;

    func_800222DC(D_800596E0, D_801E8EA8, 0x100);
    s0v = 0;
    s1v = 0xFF;
    do {
        a0 = s0v;
        a1 = (s32) func_80059AF0(s0v);
        v0 = *(u8 *) (a1 + 1);
        if (v0 != s1v) {
            a0 = 0;
            v0 = a1 + a0;
            for (;;) {
                v0 = a1 + a0;
                v1 = *(u8 *) (v0 + 0xE);
                if (v1 != 0) {
                    if (v1 < 0xFE) {
                        D_801E8EA8[v1] = D_801E8EA8[v1] + 1;
                    }
                }
                a0 = a0 + 1;
                if (a0 >= 7) {
                    break;
                }
            }
        }
        s0v = s0v + 1;
    } while (s0v < 0x14);
}

s32 func_8006784C(s32 arg0, s32 arg1) {
    s32 v;
    arg0 &= 0x3FF;
    v = 0;
    if (arg0 == 0) {
        return v;
    }
    v = D_800596E0[arg0] + arg1;
    if (v < 0) {
        v = 0;
    }
    D_800596E0[arg0] = v;
    return v;
}

extern u8 D_80063AB9[];

s32 func_8006788C(s16 *arg0, s32 arg1) {
    s32 r;
    s32 a;
    s32 v1;
    s32 t;
    s32 b;
    s32 lim;

    r = 0;
    a = *(s16 *) ((u8 *) arg0 + 0);
    ASM_NOP();
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (a == 0) {
        goto second;
    }
    __asm__ volatile("addu $3,$zero,$zero");
    t = *(s16 *) ((u8 *) arg0 + 2);
    t = -(t == 0);
    __asm__ volatile("j func_801C68CC\n\t"
                     "and $3,%0,%1\n\t" ::"r"(a),
                     "r"(t));
second:
    b = *(s16 *) ((u8 *) arg0 + 2);
    if (b == 0) {
        goto third;
    }
    ASM_NOP();
    v1 = b;
third:
    if (v1 == 0) {
        goto end;
    }
    ASM_NOP();
    lim = 0x7A;
    if (v1 >= lim) {
        goto end;
    }
    ASM_NOP();
    t = v1 * 8;
    v1 = D_80063AB9[t];
    t = v1 & 1;
    if (t != 0) {
        goto ok;
    }
    ASM_NOP();
    if (arg1 == 0) {
        goto end;
    }
    ASM_NOP();
    t = v1 & 4;
    if (t == 0) {
        goto end;
    }
    ASM_NOP();
ok:
    r = 1;
end:
    __asm__(".set\treorder\n\t");
    return r;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80067920);

extern void *func_80180AFC();
extern void func_801C6920(void *, void *);
extern u8 D_801E8DB4[];
extern u16 D_801E8DAC;
extern u16 D_801E8DB0;
extern s16 D_801E8DBA;
extern s16 D_801E8DD2;
extern s32 *D_801E92E4_ptr asm("D_801E92E4");
extern s32 *D_801E92E8_ptr asm("D_801E92E8");

void func_80067CA0(s16 arg0) {
    register s16 s3 asm("$19");
    register s32 s2 asm("$18");
    register s32 s1 asm("$17");
    register s32 s0 asm("$16");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    u8 *p;
    s32 a1;

    s3 = arg0;
    p = (u8 *) func_80180AFC();
    a1 = (s32) &D_801E8DB4;
    func_801C6920(p, (void *) a1);
    s2 = 0;
    v0 = *(u16 *) (p + 0x28);
    v1 = *(u16 *) (p + 0x2C);
    s1 = 0;
    D_801E8DAC = v0;
    D_801E8DB0 = v1;
    do {
        s0 = (s32) func_80180AFC(s1);
        if ((s0 != 0) && (*(u8 *) (s0 + 1) != 0xFF) &&
            ((*(u8 *) (s0 + 6) & 4) ||
             (!(*(u8 *) (s0 + 0x58) & 0x40) && !(*(u8 *) (s0 + 0x59) & 1)))) {
            s2 += 1;
        }
        s1 += 1;
    } while (s1 < 0x15);
    v0 = (s32) &D_801E8DBA;
    v1 = v0 - 6;
    *(s16 *) v0 = s2;
    v0 += 0x74;
    D_801E8DD2 = s3;
    D_801E92E4_ptr = (s32 *) v1;
    D_801E92E8_ptr = (s32 *) v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80067DB4);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006800C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_800680F8);

extern u8 *D_801CFB44[];

void func_800686CC(s32 arg0, s16 *arg1) {
    u8 *p;
    s32 g;
    s32 v;
    s32 sent;
    u8 *q;
    s32 h;

    p = D_801CFB44[arg0];
    g = *(u8 *) p;
    MEMORY_BARRIER();
    v = -1;
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if ((s8) g == v) {
        goto out;
    }
    h = (s8) g;
    *arg1 = h;
    sent = -1;
    q = p;
    for (;;) {
        q++;
        g = *(u8 *) q;
        MEMORY_BARRIER();
        arg1++;
        h = (s8) g;
        *arg1 = h;
        if (h != sent) {
            continue;
        }
        break;
    }
out:
    __asm__(".set\treorder\n\t");
    return;
}

void func_80068724(s32 arg0, s16 *arg1) {
    u8 *p;
    s16 *r;
    s32 g;
    s32 v;
    s32 sent;
    u8 *q;
    s32 h;

    r = arg1;
    p = D_801CFB44[arg0];
    __asm__ volatile("lbu %0,0(%1)" : "=r"(g) : "r"(r));
    MEMORY_BARRIER();
    v = -1;
    *p = g;
    MEMORY_BARRIER();
    h = (s8) g;
    if (h == v) {
        goto out;
    }
    sent = -1;
    q = p;
    r++;
    for (;;) {
        __asm__ volatile("lbu %0,0(%1)" : "=r"(g) : "r"(r));
        MEMORY_BARRIER();
        q++;
        *q = g;
        h = (s8) g;
        r++;
        if (h != sent) {
            continue;
        }
        break;
    }
    __asm__ volatile("addiu $5,$5,-2");
out:
    return;
}

extern u8 *D_801CFB5C[];

void func_80068784(s32 arg0, s16 *arg1) {
    register s32 sent asm("$7");
    register s32 vsent asm("$3");
    register u8 *var_v1 asm("$3");
    register u8 *end asm("$3");
    register s32 var_a2 asm("$6");
    register s32 idx asm("$4");
    register u8 *temp_a0 asm("$4");
    s16 *var_a1;
    s16 g;
    u8 temp_v0;

    idx = arg0 << 2;
    __asm__ volatile("addiu %0,$zero,-1" : "=r"(vsent) : "r"(idx));
    var_a1 = arg1;
    g = *var_a1;
    temp_a0 = *(u8 **) ((u8 *) D_801CFB5C + idx);
    var_a2 = 0;
    if (g != vsent) {
        __asm__ volatile("addiu %0,$zero,-1" : "=r"(sent) : "r"(idx));
        var_v1 = temp_a0;
        do {
            temp_v0 = *var_a1;
            var_a1++;
            var_a2 += 1;
            *var_v1 = temp_v0;
            var_v1 += 1;
        } while (*var_a1 != sent);
    }
    __asm__ volatile("addu $3,%0,%1" : : "r"(temp_a0), "r"(var_a2));
    *end = 0xFF;
}

extern void func_801C7894();

s32 func_800687DC(s32 arg0, s16 *arg1) {
    s16 buf[140];
    s32 pad[2];
    register u8 *p asm("$11");
    register u8 *sc asm("$3");
    register u8 *q asm("$8");
    register s32 len asm("$9");
    register s32 n asm("$16");
    register s32 i asm("$6");
    register s16 *dst asm("$7");
    register s32 m1 asm("$13");
    register s32 m2 asm("$10");
    register s32 lim asm("$4");
    register s16 *base asm("$12");
    register s16 *ap asm("$4");
    register s32 v0 asm("$2");

    p = (u8 *) D_801CFB5C[arg0];
    len = 0;
    if (*p != 0xFF) {
        lim = 0xFF;
        sc = p;
        while (*sc != lim) {
            len++;
            sc++;
        }
    }
    __asm__ volatile(".set\tnoreorder\n\t"
                     "addu $6,$zero,$zero\n\t"
                     "blez $9,1f\n\t"
                     "addu $16,$zero,$zero\n\t"
                     "addiu $13,$zero,-1\n\t"
                     "addiu $12,$sp,16\n\t"
                     ".set\treorder");
LOOP: {
    v0 = *(s16 *) arg1;
    if (v0 == m1) {
        goto NEXT;
    }
    q = p + i;
    m2 = -1;
    ap = arg1;
    v0 = n << 1;
    dst = (s16 *) ((s32) v0 + (s32) base);
    for (;;) {
        if (*q == (u8) *ap) {
            v0 = *(u16 *) ap;
            n++;
            __asm__ volatile(".set\tnoreorder\n\t"
                             "j func_801C7894\n\t"
                             "sh %0,0(%1)\n\t"
                             ".set\treorder" ::"r"(v0),
                             "r"(dst) : "memory");
        }
        ap++;
        if (*ap == m2) {
            break;
        }
    }
}
NEXT:
    i = i + 1;
    if (i < len) {
        goto LOOP;
    }
    __asm__ volatile("1:");
    buf[n] = -1;
    i = n + 1;
    func_800222DC(buf, arg1, i << 1);
    return n;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_800688DC);

s32 func_80068980(s32 arg0, s32 arg1) {
    register s32 v asm("$2");
    register s32 z asm("$2");
    register s32 b asm("$3");
    u8 *p;

    p = D_801CFB5C[arg1];
    b = *p;
    MEMORY_BARRIER();
    z = 0xFF;
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (b == z) {
        goto out;
    }
    __asm__ volatile("addu $2,$zero,$zero");
    for (;;) {
        v = *p;
        MEMORY_BARRIER();
        if (v == arg0) {
            goto out;
        }
        __asm__ volatile("ori $2,$zero,1");
        p++;
        v = *p;
        if (v != 0xFF) {
            continue;
        }
        break;
    }
    __asm__ volatile("addu $2,$zero,$zero");
out:
    __asm__(".set\treorder\n\t");
    return v;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_800689D4);

void func_80068AB4(void) {
}

void func_80068ABC(u8 *arg0, u8 *arg1) {
    *(u16 *) (arg0 + 0xE) = 0;
    *(u16 *) (arg0 + 0x14) = 0;
    *(u16 *) (arg1 + 0x0) = 0;
    *(u16 *) (arg1 + 0x2) = 0;
    *(u16 *) (arg1 + 0x4) = 0;
    *(u16 *) (arg1 + 0x6) = 0;
    *(u16 *) (arg1 + 0x8) = 0;
    *(u16 *) (arg1 + 0xC) = 0;
    *(u16 *) (arg1 + 0xA) = 0;
    *(u16 *) (arg1 + 0x12) = 0;
    *(u16 *) (arg1 + 0x14) = 0;
    *(u16 *) (arg1 + 0x16) = 0;
    *(u16 *) (arg1 + 0x18) = 0;
    *(u16 *) (arg1 + 0x1C) = 0;
    *(u16 *) (arg1 + 0x1E) = 0;
    *(u16 *) (arg1 + 0x20) = 0;
    *(u16 *) (arg1 + 0x22) = 0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80068B04);

extern void func_801C7DE8(s32, s32, s32, s32);
extern void func_801C7B04(s32, u16 *, u16 *, s32);

void func_80068D2C(s32 arg0, u16 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    u16 sp[0x28];
    u16 c[0x20];
    u16 d[0x20];
    s32 v0;
    s32 v1;

    func_801C7B04((s16) arg2, &sp[0], &c[0], arg4);
    func_801C7B04((s16) arg3, &sp[0x14], &d[0], arg4);
    v0 = sp[0x1B];
    v1 = sp[7];
    v0 = v0 - v1;
    arg1[7] = v0;
    v0 = sp[0x1E];
    v1 = sp[0xA];
    v0 = v0 - v1;
    arg1[0xA] = v0;
    func_801C7DE8(arg0, (s32) &c[0], (s32) &d[0], 1);
}

void func_80068DE8(s16 *arg0, s16 *arg1, u16 *arg2, s32 arg3) {
    s32 v0v;
    s32 v1v;

    v0v = arg1[0];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[0] - v1v;
    arg0[0] = (s16) v0v;
    v0v = arg1[1];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[1] - v1v;
    arg0[1] = (s16) v0v;
    v0v = arg1[2];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[2] - v1v;
    arg0[2] = (s16) v0v;
    v0v = arg1[3];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[3] - v1v;
    arg0[3] = (s16) v0v;
    v0v = arg1[4];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[4] - v1v;
    arg0[4] = (s16) v0v;
    v0v = arg1[5];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[5] - v1v;
    arg0[5] = (s16) v0v;
    v0v = arg1[6];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[6] - v1v;
    arg0[6] = (s16) v0v;
    v0v = arg1[9];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[9] - v1v;
    arg0[9] = (s16) v0v;
    v0v = arg1[10];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[10] - v1v;
    arg0[10] = (s16) v0v;
    v0v = arg1[11];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[11] - v1v;
    arg0[11] = (s16) v0v;
    v0v = arg1[12];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[12] - v1v;
    arg0[12] = (s16) v0v;
    v0v = arg1[14];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[14] - v1v;
    arg0[14] = (s16) v0v;
    v0v = arg1[15];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[15] - v1v;
    arg0[15] = (s16) v0v;
    v0v = arg1[16];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[16] - v1v;
    arg0[16] = (s16) v0v;
    v0v = arg1[17];
    v1v = arg3 * v0v;
    v0v = (s32) arg2[17] - v1v;
    arg0[17] = (s16) v0v;
}

extern void func_801C7ABC(s32, s32);
extern void func_801C7D2C(s32, s32, s32, s32, s32);

void func_80068F90(s32 arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    register s32 s4 asm("$20");
    register s32 s2 asm("$18");
    register s32 s1 asm("$17");
    register s32 s0 asm("$16");
    register s32 s5 asm("$21");
    register s32 s3 asm("$19");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    u16 buf18[0x14];
    u16 buf40[0x40];

    s4 = arg0;
    KEEP_WITH_NOVOL(s4, arg0);
    s2 = (s32) arg1;
    KEEP_WITH_NOVOL(s2, arg1);
    s1 = (s32) arg2;
    KEEP_WITH_NOVOL(s1, arg2);
    s0 = (s32) arg3;
    KEEP_WITH_NOVOL(s0, arg3);
    func_801C7ABC(s2, s4);
    s3 = 0;
    s5 = (s32) buf40;
    do {
        a0 = s5;
        a1 = (s32) buf18;
        USE(a1);
        a2 = *(u16 *) s1;
        a3 = *(u16 *) s0;
        SCHED_BARRIER();
        s0 += 2;
        SCHED_BARRIER();
        a2 &= 0x3FF;
        a3 &= 0x3FF;
        func_801C7D2C(a0, a1, a2, a3, s3);
        func_801C7DE8(s4, s4, s5, -1);
        v0 = *(u16 *) (s2 + 0xE);
        v1 = *(u16 *) ((u8 *) buf18 + 0x0E);
        v0 += v1;
        *(u16 *) (s2 + 0xE) = v0;
        v0 = *(u16 *) (s2 + 0x14);
        v1 = *(u16 *) ((u8 *) buf18 + 0x14);
        SCHED_BARRIER();
        s3 += 1;
        v0 += v1;
        *(u16 *) (s2 + 0x14) = v0;
        s1 += 2;
    } while (s3 < 5);
}

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
} W69068Rec24;

void func_80069068(void *arg0, u16 *arg1) {
    u16 sp[0x54];
    W69068Rec24 *s0 = (W69068Rec24 *) arg0;
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
        func_801C7B04(*(u16 *) s2 & 0x3FF, &sp[0], &sp[0x14], s1);
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

extern s32 func_801C684C();

s32 func_80069188(s32 arg0) {
    s32 k = arg0 & 0x3FF;
    s32 v = func_801C684C(k, 0);

    return D_801E8EA8[k] - v;
}

s32 func_800691CC(s32 arg0) {
    return D_801E8EA8[arg0 & 0x3FF];
}

extern s32 D_801E92E4[];
extern s32 func_801C83D0();
extern void func_801C6DB4();

s32 func_800691E4(s16 arg0, s16 arg1, s32 arg2) {
    s16 *row;
    s16 *p;
    s32 r;
    s16 m;
    s32 k;

    m = arg2 & 0x3FF;
    r = func_801C83D0(arg0, arg1, m);
    if (r < 0) {
        return r;
    }
    if (arg0 != 1) {
        s32 br;
        br = *(s32 *) ((u8 *) D_801E92E4 + arg0 * 4);
        p = (s16 *) (arg1 * 2 + (u32) br);
        func_801C684C(p[0x2A], 1);
    }
    if (arg1 < 2) {
        if (r != 1) {
            k = arg1 == 0;
            if (arg0 != 1) {
                s32 br;
                br = *(s32 *) ((u8 *) D_801E92E4 + arg0 * 4);
                p = (s16 *) (k * 2 + (u32) br);
                func_801C684C(p[0x2A], 1);
            }
            {
                s32 br;
                br = *(s32 *) ((u8 *) D_801E92E4 + arg0 * 4);
                p = (s16 *) (k * 2 + (u32) br);
                p[0x2A] = 0;
            }
        }
    }
    row = (s16 *) (*(s32 *) ((u8 *) D_801E92E4 + arg0 * 4));
    p = (s16 *) (arg1 * 2 + (u32) row);
    p[0x2A] = m;
    if (arg0 != 1) {
        func_801C6DB4();
    }
    return 1;
}

extern void func_801C83B8();
extern s32 func_801C88BC(s32);
extern void func_801CDF50(s32);
extern s32 func_801CDF88(s32);

s32 func_80069338(s32 arg0, s32 arg1) {
    s32 v0;
    s32 v1;
    s32 a0;
    s32 s0;
    s32 s1;

    s1 = arg0;
    s0 = arg1 & 0x3FF;
    if (s0 == 0) {
        __asm__ volatile(".set\tnoreorder\n\tj func_801C83B8\n\tori $2,$zero,1\n\t.set\treorder");
    }
    a0 = s0;
    v0 = func_801C88BC(a0);
    __asm__ volatile("ori $3,$zero,5");
    __asm__ volatile(".set\tnoreorder\n\tbne $2,$3,.L80069338_cont\n\tsll $2,$17,16\n\t.set\treorder");
    __asm__ volatile(".set\tnoreorder\n\tj func_801C83B8\n\taddiu $2,$zero,-1\n\t.set\treorder");
    __asm__ volatile(".L80069338_cont:");
    v0 >>= 14;
    MEMORY_BARRIER();
    a0 = *(s32 *) ((u8 *) D_801E92E4 + v0);
    func_801CDF50(a0 + 0x70);
    v0 = func_801C8860(s0);
    v0 = func_801CDF88(v0);
    v0 = func_801CDF88(1);
    USE(s1);
    v1 = 1;
    if (v0 == 0) {
        v1 = -1;
    }
    return v1;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_800693D0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_800695CC);

extern u8 D_80062EBD[];

u8 func_80069860(s32 arg0) {
    return D_80062EBD[(arg0 & 0x3FF) * 12];
}

extern u8 D_801CFB70[];
extern u8 D_801CFB71[];

void func_80069884(s32 arg0, s16 *arg1) {
    arg1[0] = D_801CFB70[arg0 * 2];
    arg1[1] = D_801CFB71[arg0 * 2];
    arg1[2] = 0xC;
    arg1[3] = 0xC;
}

extern void func_801C8914();

s32 func_800698BC(s32 arg0) {
    s32 v0;
    s32 v1;

    arg0 = arg0 & 0x3FF;
    v1 = 0;
    if (arg0 >= 0x7A) {
        v1 = 5;
        if (arg0 >= 0x80) {
            v1 = 1;
            if (arg0 >= 0x90) {
                v1 = 2;
                if (arg0 >= 0xAC) {
                    if (arg0 < 0xD0) {
                        __asm__ volatile(".set\tnoreorder\n\t"
                                         "j func_801C8914\n\t"
                                         "ori $3,$zero,3\n\t"
                                         ".set\treorder");
                    }
                    SCHED_BARRIER();
                    v1 = 5;
                    if (arg0 < 0xF0) {
                        v1 = 4;
                    }
                }
            }
        }
    }
    return v1;
}

extern s32 D_801E92E8[];

void func_8006991C(void) {
    func_800222DC(*(s32 *) D_801E92E4, *(s32 *) D_801E92E8, 0x7A);
}

s32 func_8006994C(s32 arg0) {
    return ((u8 *) *(s32 *) ((u8 *) D_801E92E4 + (s16) arg0 * 4))[0x76] & 1;
}

s32 func_80069970(s32 arg0) {
    return ((u8 *) *(s32 *) ((u8 *) D_801E92E4 + (s16) arg0 * 4))[0x76] & 2;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80069994);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80069AC8);

s32 func_80069B1C(s32 arg0) {
    return arg0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_80069B24);

void func_80069DAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_8014CA1C() == 0) {
        func_8014C8A0(arg0, &D_801308C0);
        func_8014CA38(arg0, arg1, arg2, arg3);
    }
}

extern u8 *func_801C8AC8(s32, s32, s32);

void func_80069E24(s32 arg0, u8 *arg1, s16 *arg2, s32 arg3) {
    s16 *var_s1;
    u8 *var_a0;
    u8 *var_s0;

    var_s0 = arg1;
    if (*arg2 != -1) {
        var_s1 = arg2;
        do {
            var_a0 = func_801C8AC8(arg0, *(u16 *) var_s1 & 0x7FF, 1);
            while (*var_a0 != 0xFE) {
                *var_s0 = *var_a0;
                var_a0 += 1;
                var_s0 += 1;
            }
            var_s1 += 1;
            if (arg3 != 0) {
                *var_s0 = 0xF8;
                var_s0 += 1;
            }
        } while (*var_s1 != -1);
    }
    if (arg3 != 0) {
        var_s0 -= 1;
    }
    *var_s0 = 0xFE;
}

void func_80069EF4(s32 arg0) {
    func_8014CA38(arg0, 0, 0, 1);
}

struct func_80069F1C_fields {
    s16 f828;
    s16 f82a;
    u16 f82c;
    s16 f82e;
    u16 f830;
    u16 f832;
    u16 f834;
    s16 f836;
    u16 f838;
    s16 f83a;
};

extern void func_801C8B24();

void func_80069F1C(s32 arg0, s16 *arg1, void *arg2, s32 arg3) {
    s32 lowpad[6];
    u8 sp28[0x800];
    struct func_80069F1C_fields f;
    s32 pad[4];
    register u8 *s0v asm("$16");
    register s32 s1v asm("$17");
    register s32 s2v asm("$18");
    register s32 s3v asm("$19");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a3v asm("$7");

    f.f828 = 0;
    f.f82a = 0;
    v0 = ((u16 *) arg2)[2];
    f.f82e = 0x10;
    f.f82c = (u16) v0;
    f.f830 = ((u16 *) arg2)[0];
    v0 = ((u16 *) arg2)[1];
    __asm__ volatile("move %0,%1" : "=r"(s0v) : "r"(arg1));
    f.f832 = (u16) v0;
    v0 = ((u16 *) arg2)[2];
    __asm__ volatile("move %0,%1" : "=r"(s3v) : "r"(arg3));
    f.f836 = 0x10;
    f.f834 = (u16) v0;
    v1 = *(s16 *) s0v;
    a3v = *(u16 *) s0v;
    v0 = -1;
    if (v1 != v0) {
        s2v = arg0;
        s1v = -1;
        __asm__ volatile("addiu $4,$29,0x28" : : : "a0", "memory");
        __asm__ volatile(".L80069F1C_loop:");
        do {
            __asm__ volatile("move $5,$zero" : : : "a1", "memory");
            __asm__ volatile("ori $6,$zero,0x800" : : : "a2", "memory");
            f.f838 = a3v;
            f.f83a = (s16) s1v;
            ((void (*)(void)) func_800222FC)();
            __asm__ volatile("addiu $4,$29,0x28" : : : "a0", "memory");
            __asm__ volatile("addiu $5,$29,0x828" : : : "a1", "memory");
            __asm__ volatile("ori $6,$zero,0xA" : : : "a2", "memory");
            v0 = (s32) &f.f838;
            *(s32 *) ((u8 *) &f.f828 - 0x814) = v0;
            v0 = 0x64;
            *(s32 *) ((u8 *) &f.f828 - 0x810) = v0;
            v0 = 0xEB;
            __asm__ volatile("ori $7,$zero,0x64" : : : "a3", "memory");
            *(s32 *) ((u8 *) &f.f828 - 0x818) = s2v;
            *(s32 *) ((u8 *) &f.f828 - 0x80C) = v0;
            *(s32 *) ((u8 *) &f.f828 - 0x808) = s3v;
            ((void (*)(void)) func_801C8B24)();
            func_801CA804((GpuRect *) &f.f830, (GpuRect *) &sp28[0]);
            v0 = *(u16 *) &f.f832;
            s0v = s0v + 2;
            v0 = v0 + 0x10;
            f.f832 = (u16) v0;
            v0 = *(s16 *) s0v;
            a3v = *(u16 *) s0v;
            __asm__ volatile(".set\tnoreorder\n\tbne $2,$17,.L80069F1C_loop\n\taddiu $4,$29,0x28\n\t.set\treorder" : : "r"(v0), "r"(a3v), "r"(s1v) : "memory");
        } while (0);
    }
}

extern s32 D_801CFBD4;

void func_8006A024(void) {
    func_801C8EF4();
    D_801CFBD4 = 0;
}

extern void *D_80173CB8;
extern s32 func_801C90D0();

s32 func_8006A04C(s32 arg0, void *arg1) {
    register s32 s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");

    v0 = D_801CFBD4;
    s0 = arg0;
    s1 = (s32) arg1;
    if (v0 != 0) {
        goto already;
    }
    v0 = func_8014CA1C();
    if (v0 != 0) {
        v0 = 1;
        goto done;
    }
    a1 = *(s32 *) (s1 + 0x28);
    D_80173CB8 = arg1;
    func_8014C8A0(s0, a1);
    a0 = s0;
    a1 = (s32) D_80173CB8;
    a2 = 0;
    a3 = 0;
    func_8014CA38(a0, a1, a2, a3);
    v1 = 1;
    D_801CFBD4 = v1;
    __asm__ volatile(".set\tnoreorder\n\tj func_801C90D0\n\tori $2,$zero,1\n\t.set\treorder" ::: "memory");
already:
    v0 = func_8014CA1C(s0);
    D_801CFBD4 = v0;
done:
    return v0;
}

extern void func_80134020();
extern void func_80133FE8();
extern u8 D_801CFBD8[];

void func_8006A0E8(s32 arg0) {
    if (D_801E9308 > 0) {
        func_80134020();
        func_80133FE8(&D_801CFBD8);
        func_8014C8A0(1, &D_801308C0);
        func_8014CA38(1, arg0 + 0x38, D_801E9308, 0);
        D_80166028 = 1;
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006A164);

extern s16 D_801D86AC;

void func_8006A4A4(s16 arg0) {
    D_801D86AC = arg0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006A4B4);

extern u8 D_801E8FF2[];

void func_8006A604(void) {
    s32 i;
    s16 *p;
    i = 3;
    p = (s16 *) D_801E8FF2;
    for (; i >= 0; i--) {
        *p = 0;
        p--;
    }
}

extern u16 D_801E8FEC[];

s16 func_8006A628(s32 arg0, s16 arg1) {
    D_801E8FEC[arg0 & 0xFF] = arg1;
    return arg1;
}

s16 func_8006A648(s32 arg0, s16 arg1) {
    D_801E8FEC[arg0 & 0xFF] = arg1;
    return arg1;
}

extern void func_801C96E8(s16 *, s32);

s32 func_8006A668(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v0;
    s32 v1;
    s32 a0;
    s32 a2;
    s32 a3;

    __asm__ volatile(".set\tnoreorder\n\taddiu $29,$29,-0x10\n\tandi $2,$6,0x1000\n\tbeqz $2,.L8006A668_second\n\tmove $7,$4\n\tandi $2,$5,0xFF\n\tlui $3,%%hi(D_801E8FEC)\n\taddiu $3,$3,%%lo(D_801E8FEC)\n\tsll $2,$2,1\n\taddu $6,$2,$3\n\tlh $2,0($6)\n\tnop\n\tbnez $2,.L8006A668_nonzero\n\tmove $3,$2\n\tj func_801C96E8\n\taddiu $2,$4,-1\n\t.L8006A668_nonzero:\n\tj func_801C96E8\n\taddiu $2,$3,-1\n\t.L8006A668_second:\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tandi $2,$6,0x4000\n\tbeqz $2,.L8006A668_final\n\tandi $2,$5,0xFF\n\tlui $3,%%hi(D_801E8FEC)\n\taddiu $3,$3,%%lo(D_801E8FEC)\n\tsll $2,$2,1\n\taddu $6,$2,$3\n\tlh $3,0($6)\n\tandi $2,$7,0xFFFF\n\taddiu $2,$2,-1\n\tmove $4,$3\n\tslt $3,$3,$2\n\tbne $3,$zero,.L8006A668_store\n\taddiu $2,$4,1\n\tmove $2,$zero\n\t.L8006A668_store:\n\tsh $2,0($6)\n\t.L8006A668_final:\n\tandi $2,$5,0xFF\n\tsll $2,$2,1\n\tlui $1,%%hi(D_801E8FEC)\n\taddu $1,$1,$2\n\tlh $2,%%lo(D_801E8FEC)($1)\n\taddiu $29,$29,0x10\n\t.set\treorder" : "=r"(v0)::"memory");
    return v0;
}

extern s16 func_801C9668(s32, s32);
extern s8 D_801CE1C8;

void func_8006A70C(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 t;
    u16 s;

    t = arg1 & 0xFF;
    s = D_801E8FEC[t];
    if ((s16) s != func_801C9668(arg0 & 0xFFFF, t)) {
        D_801CE1C8 = arg3;
    }
}

extern void func_801C97F4(s16 *, s32);

s32 func_8006A774(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v0;
    s32 v1;
    s32 a0;
    s32 a2;
    s32 a3;

    __asm__ volatile(".set\tnoreorder\n\taddiu $29,$29,-0x10\n\tandi $2,$6,0x8000\n\tbeqz $2,.L8006A774_second\n\tmove $7,$4\n\tandi $2,$5,0xFF\n\tlui $3,%%hi(D_801E8FEC)\n\taddiu $3,$3,%%lo(D_801E8FEC)\n\tsll $2,$2,1\n\taddu $6,$2,$3\n\tlh $2,0($6)\n\tnop\n\tbnez $2,.L8006A774_nonzero\n\tmove $3,$2\n\tj func_801C97F4\n\taddiu $2,$4,-1\n\t.L8006A774_nonzero:\n\tj func_801C97F4\n\taddiu $2,$3,-1\n\t.L8006A774_second:\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tandi $2,$6,0x2000\n\tbeqz $2,.L8006A774_final\n\tandi $2,$5,0xFF\n\tlui $3,%%hi(D_801E8FEC)\n\taddiu $3,$3,%%lo(D_801E8FEC)\n\tsll $2,$2,1\n\taddu $6,$2,$3\n\tlh $3,0($6)\n\tandi $2,$7,0xFFFF\n\taddiu $2,$2,-1\n\tmove $4,$3\n\tslt $3,$3,$2\n\tbne $3,$zero,.L8006A774_store\n\taddiu $2,$4,1\n\tmove $2,$zero\n\t.L8006A774_store:\n\tsh $2,0($6)\n\t.L8006A774_final:\n\tandi $2,$5,0xFF\n\tsll $2,$2,1\n\tlui $1,%%hi(D_801E8FEC)\n\taddu $1,$1,$2\n\tlh $2,%%lo(D_801E8FEC)($1)\n\taddiu $29,$29,0x10\n\t.set\treorder" : "=r"(v0)::"memory");
    return v0;
}

extern s16 func_801C9774();
extern s16 D_801E9064;
extern s32 D_801E92F0;
extern s32 D_801E9240;

void func_8006A818(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 t;
    u16 s;

    t = arg1 & 0xFF;
    s = D_801E8FEC[t];
    if ((s16) s != func_801C9774(arg0 & 0xFFFF, t)) {
        D_801CE1C8 = arg3;
    }
}

void func_8006A880(void) {
    D_801E9064 = 0;
    D_801E92F0 = 0;
    D_801E9240 = 0;
}

extern void func_80023C68();
extern u16 D_801E9234;
extern s32 *D_801E923C;

void func_8006A8A0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u16 n;
    u8 *p;
    s32 *b1;
    register s32 *b2 asm("a2");
    register s32 mlo asm("a0");
    s32 i;

    n = D_801E9234;
    D_801E9234 = n + 1;
    b1 = *(s32 **) ((u8 *) &D_801E9234 + 8);
    p = *(u8 **) ((u8 *) b1 + 0x3C) + n * 0x10;
    p[4] = arg1[0];
    p[5] = arg1[1];
    p[6] = arg1[2];
    func_80023C68(p, arg2 & 0xFF);
    b2 = D_801E923C;
    i = arg3 * 4;
    mlo = 0xFFFFFF;
    *(s16 *) (p + 8) = *(u16 *) arg0 + 0x80;
    *(u16 *) (p + 10) = *(u16 *) (arg0 + 2);
    *(u16 *) (p + 12) = *(u16 *) (arg0 + 4);
    *(u16 *) (p + 14) = *(u16 *) (arg0 + 6);
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & 0xFF000000) | ((s32) p & mlo);
}

extern u16 D_801E90AC;

void func_8006A9A0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u16 n;
    u8 *p;
    s32 *b1;
    register s32 *b2 asm("a2");
    register s32 mlo asm("a0");
    s32 i;

    n = D_801E90AC;
    D_801E90AC = n + 1;
    b1 = D_801E923C;
    p = *(u8 **) ((u8 *) b1 + 0x24) + n * 0x10;
    p[4] = arg1[0];
    p[5] = arg1[1];
    p[6] = arg1[2];
    func_80023C68(p, arg2 & 0xFF);
    mlo = 0xFFFFFF;
    *(s16 *) (p + 8) = *(u16 *) arg0 + 0x80;
    *(u16 *) (p + 10) = *(u16 *) (arg0 + 2);
    b2 = D_801E923C;
    i = arg3 * 4;
    *(u16 *) (p + 12) = *(u16 *) (arg0 + 4) + 0x80;
    *(u16 *) (p + 14) = *(u16 *) (arg0 + 6);
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & 0xFF000000) | ((s32) p & mlo);
}

extern void func_801C9B78(void);
extern s16 D_801E90DC;

void func_8006AAA4(u8 *arg0, void *arg1, s32 arg2, u16 arg3, u16 arg4, s32 arg5, s32 arg6) {
    register u8 *s0 asm("$16");
    register u8 *s1 asm("$17");
    register u8 *s2 asm("$18");
    register s32 s3 asm("$19");
    register s32 s4 asm("$20");
    register s32 s5 asm("$21");
    s32 s6;
    register s32 s7 asm("$23");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    struct {
        volatile s32 sp10;
        s32 pad;
        u16 sp18;
    } stack;

    s3 = arg6;
    s2 = arg0;
    s4 = (s32) arg1;
    KEEP(s4);
    stack.sp10 = arg2;
    s3 -= 1;
    stack.sp18 = arg3;
    v0 = arg5;
    if (s3 >= 0) {
        s6 = v0 << 2;
        s5 = 0xFFFFFF;
        s7 = 0xFF000000;
        s1 = arg0 + 3;
        do {
            a0 = (u16) D_801E90DC;
            v1 = (s32) D_801E923C;
            v0 = a0 + 1;
            D_801E90DC = v0;
            v0 = a0;
            v0 <<= 2;
            v0 += a0;
            v0 <<= 3;
            v1 = *(s32 *) ((u8 *) v1 + 0x10);
            s0 = (u8 *) v0 + v1;
            if (s4 == 0) {
                goto copy;
            }
            KEEP(s0);
            func_80023C90(s0, 0);
            v0 = *(u8 *) s4;
            s0[4] = v0;
            v0 = *(u8 *) (s4 + 1);
            s0[5] = v0;
            v0 = *(u8 *) (s4 + 2);
            __asm__ volatile(".set\tnoreorder\n\tj func_801C9B78\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
copy:
            func_80023C90(s0, 1);
            a1 = stack.sp10;
            func_80023C68(s0, a1);
            v0 = *(u8 *) s2;
            v0 += 0x80;
            *(u16 *) (s0 + 8) = v0;
            v0 = *(u8 *) (s1 - 2);
            *(u16 *) (s0 + 0xA) = v0;
            v0 = *(u8 *) s2;
            v1 = *(u8 *) (s1 - 1);
            v0 += 0x80;
            v1 += v0;
            *(u16 *) (s0 + 0x10) = v1;
            v0 = *(u8 *) (s1 - 2);
            *(u16 *) (s0 + 0x12) = v0;
            v0 = *(u8 *) s2;
            v0 += 0x80;
            *(u16 *) (s0 + 0x18) = v0;
            v0 = *(u8 *) (s1 - 2);
            v1 = *(u8 *) s1;
            v0 += v1;
            *(u16 *) (s0 + 0x1A) = v0;
            v0 = *(u8 *) s2;
            v1 = *(u8 *) (s1 - 1);
            v0 += 0x80;
            v1 += v0;
            *(u16 *) (s0 + 0x20) = v1;
            v0 = *(u8 *) (s1 - 2);
            v1 = *(u8 *) s1;
            v0 += v1;
            *(u16 *) (s0 + 0x22) = v0;
            v0 = *(u8 *) (s1 + 1);
            s0[0xC] = v0;
            v0 = *(u8 *) (s1 + 2);
            s0[0xD] = v0;
            v0 = *(u8 *) (s1 + 1);
            v1 = *(u8 *) (s1 - 1);
            v0 += v1;
            s0[0x14] = v0;
            v0 = *(u8 *) (s1 + 2);
            s0[0x15] = v0;
            v0 = *(u8 *) (s1 + 1);
            s0[0x1C] = v0;
            v0 = *(u8 *) (s1 + 2);
            v1 = *(u8 *) s1;
            v0 += v1;
            s0[0x1D] = v0;
            v0 = *(u8 *) (s1 + 1);
            v1 = *(u8 *) (s1 - 1);
            v0 += v1;
            s0[0x24] = v0;
            v0 = *(u8 *) (s1 + 2);
            v1 = *(u8 *) s1;
            s3 -= 1;
            *(u16 *) (s0 + 0xE) = arg4;
            v0 += v1;
            s0[0x25] = v0;
            a0 = (s32) D_801E923C;
            s2 += 6;
            {
                register u16 t0 asm("$8");

                t0 = *(volatile u16 *) &stack.sp18;
                *(u16 *) (s0 + 0x16) = t0;
            }
            v0 = *(s32 *) a0;
            v1 = *(s32 *) s0;
            v0 = s6 + v0;
            v0 = *(s32 *) v0;
            v1 &= s7;
            v0 &= s5;
            v1 |= v0;
            *(s32 *) s0 = v1;
            a0 = *(s32 *) a0;
            s1 += 6;
            a0 = s6 + a0;
            v1 = *(s32 *) a0;
            v0 = (s32) s0 & s5;
            v1 &= s7;
            v1 |= v0;
            *(s32 *) a0 = v1;
        } while (s3 >= 0);
    }
}

extern void func_801C9DD0(void);

void func_8006AD1C(void *arg0, s32 arg1, s32 arg2, void *arg3,

                   s32 arg4, u16 arg5, u16 arg6, s32 arg7) {
    u8 *s0;
    u8 *s1;
    register s32 s3 asm("$19");
    register s32 s4 asm("$20");
    register s32 s2 asm("$18");
    register s32 s5 asm("$21");
    register s32 s6 asm("$22");
    register s32 s7 asm("$23");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");

    s7 = arg7;
    KEEP_NOVOL(s7);
    s1 = (u8 *) arg0;
    s6 = arg5;
    KEEP_NOVOL(s6);
    a0 = (u16) D_801E90DC;
    D_801E90DC = a0 + 1;
    s5 = arg6;
    s3 = arg1;
    s4 = arg2;
    __asm__("move %0,%1" : "=r"(s2) : "r"(arg3));
    s0 = (u8 *) &((EventCoord28 *) *(EventCoord28 **) ((u8 *) D_801E923C + 0x10))[a0];
    if (s2 == 0) {
        goto copy;
    }
    {
        func_80023C90(s0, 0);
        v0 = *(u8 *) s2;
        s0[4] = v0;
        v0 = *((u8 *) s2 + 1);
        s0[5] = v0;
        v0 = *((u8 *) s2 + 2);
        __asm__ volatile(".set\tnoreorder\n\tj func_801C9DD0\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
    }
copy:
    func_80023C90(s0, 1);
    a1 = arg4;
    func_80023C68(s0, a1);
    *(u16 *) (s0 + 8) = *(u16 *) s1 + 0x80;
    *(u16 *) (s0 + 0xA) = *(u16 *) (s1 + 2);
    v0 = *(u16 *) (s1 + 4);
    v1 = *(u16 *) s1;
    v0 += 0x80;
    v1 += v0;
    *(u16 *) (s0 + 0x10) = v1;
    *(u16 *) (s0 + 0x12) = *(u16 *) (s1 + 2);
    *(u16 *) (s0 + 0x18) = *(u16 *) s1 + 0x80;
    *(u16 *) (s0 + 0x1A) = *(u16 *) (s1 + 2) + *(u16 *) (s1 + 6);
    v0 = *(u16 *) (s1 + 4);
    v1 = *(u16 *) s1;
    v0 += 0x80;
    v1 += v0;
    *(u16 *) (s0 + 0x20) = v1;
    __asm__ volatile(".set\tnoreorder\n\tlhu $2,0x2($17)\n\tlhu $3,0x6($17)\n\tsb $19,0xC($16)\n\tsb $20,0xD($16)\n\taddu $2,$2,$3\n\tsh $2,0x22($16)\n\tlbu $2,0x4($17)\n\tsb $20,0x15($16)\n\tsb $19,0x1C($16)\n\taddu $2,$19,$2\n\tsb $2,0x14($16)\n\t.set\treorder" ::: "$2", "$3", "memory");
    v0 = s1[6];
    __asm__ volatile("lui %0,0xff" : "=r"(a1));
    s0[0x1D] = s4 + v0;
    v0 = s1[4];
    a1 |= 0xffff;
    s0[0x24] = s3 + v0;
    v0 = s1[6];
    a0 = s7 << 2;
    *(u16 *) (s0 + 0xE) = s5;
    *(volatile u8 *) (s0 + 0x25) = s4 + v0;
    MEMORY_BARRIER();
    *(u16 *) (s0 + 0x16) = s6;
    a3 = (s32) D_801E923C;
    a2 = 0xFF000000;
    v0 = *(s32 *) a3;
    v1 = *(s32 *) s0;
    v0 = a0 + v0;
    v0 = *(s32 *) v0;
    v1 &= a2;
    v0 &= a1;
    v1 |= v0;
    *(s32 *) s0 = v1;
    v0 = *(s32 *) a3;
    a0 += v0;
    v0 = *(s32 *) a0;
    a1 = (s32) s0 & a1;
    v0 &= a2;
    v0 |= a1;
    *(s32 *) a0 = v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006AF30);

extern void func_801CA3E0(void);

void func_8006B344(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 *s0;
    u8 *s1;
    u8 *s2;
    s32 s3;
    s32 s4;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");

    s1 = (u8 *) arg0;
    s2 = (u8 *) arg1;
    s3 = arg2;
    s4 = arg3;
    a0 = (u16) D_801E90DC;
    D_801E90DC = a0 + 1;
    v1 = (s32) D_801E923C;
    s0 = (u8 *) &((EventCoord28 *) *(EventCoord28 **) ((u8 *) v1 + 0x10))[a0];
    if (s2 == 0) {
        goto copy;
    }
    {
        func_80023C90(s0, 0);
        v0 = s2[0];
        s0[4] = v0;
        v0 = s2[1];
        s0[5] = v0;
        v0 = s2[2];
        __asm__ volatile(".set\tnoreorder\n\tj func_801CA3E0\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
    }
copy:
    func_80023C90(s0, 1);
    func_80023C68(s0, s3);
    *(u16 *) (s0 + 8) = *(u16 *) s1 + 0x80;
    *(u16 *) (s0 + 0xA) = *(u16 *) (s1 + 2);
    *(u16 *) (s0 + 0x10) = *(u16 *) (s1 + 4) + 0x80;
    *(u16 *) (s0 + 0x12) = *(u16 *) (s1 + 6);
    *(u16 *) (s0 + 0x18) = *(u16 *) (s1 + 8) + 0x80;
    *(u16 *) (s0 + 0x1A) = *(u16 *) (s1 + 0xA);
    *(u16 *) (s0 + 0x20) = *(u16 *) (s1 + 0xC) + 0x80;
    *(u16 *) (s0 + 0x22) = *(u16 *) (s1 + 0xE);
    s0[0xC] = s1[0x10];
    s0[0xD] = s1[0x12];
    s0[0x14] = s1[0x14];
    s0[0x15] = s1[0x16];
    s0[0x1C] = s1[0x18];
    s0[0x1D] = s1[0x1A];
    v0 = s1[0x1C];
    __asm__ volatile("lui %0,0xff" : "=r"(a1));
    s0[0x24] = v0;
    v0 = s1[0x1E];
    a1 |= 0xffff;
    s0[0x25] = v0;
    v0 = *(u16 *) (s1 + 0x20);
    a0 = s4 << 2;
    *(u16 *) (s0 + 0xE) = v0;
    v0 = *(u16 *) (s1 + 0x22);
    a3 = (s32) D_801E923C;
    a2 = 0xFF000000;
    *(u16 *) (s0 + 0x16) = v0;
    v0 = *(s32 *) a3;
    v1 = *(s32 *) s0;
    v0 = a0 + v0;
    v0 = *(s32 *) v0;
    v1 &= a2;
    v0 &= a1;
    v1 |= v0;
    *(s32 *) s0 = v1;
    v0 = *(s32 *) a3;
    a0 += v0;
    v0 = *(s32 *) a0;
    a1 = (s32) s0 & a1;
    v0 &= a2;
    v0 |= a1;
    *(s32 *) a0 = v0;
}

extern void func_80023EA0(void *);
extern u16 D_801E9238;

void func_8006B540(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0;
    s32 s1;
    u8 *s2;
    s32 s3;
    s32 s4;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 *a2 asm("a2");

    v1 = *(u16 *) &D_801E9238;
    s2 = arg0;
    s3 = arg1;
    s4 = arg2;
    s1 = arg3;
    v0 = v1 + 1;
    s0 = v1 << 1;
    D_801E9238 = v0;
    v0 = (s32) D_801E923C;
    s0 += v1;
    s0 <<= 3;
    v0 = *(s32 *) ((u8 *) v0 + 0x58);
    s0 += v0;
    func_80023EA0((void *) s0);
    v0 = *(u16 *) s2;
    a2 = D_801E923C;
    a0 = 0xFFFFFF;
    *(u16 *) (s0 + 0xC) = v0;
    v0 = *(u16 *) (s2 + 2);
    a0 = 0xFFFFFF;
    *(u16 *) (s0 + 0x10) = s3;
    *(u16 *) (s0 + 0x12) = s4;
    *(u16 *) (s0 + 0xE) = v0;
    v0 = *(u16 *) (s2 + 4);
    s1 <<= 2;
    *(u16 *) (s0 + 0x14) = v0;
    v0 = *(u16 *) (s2 + 6);
    a1 = 0xFF000000;
    *(u16 *) (s0 + 0x16) = v0;
    v0 = *a2;
    v1 = *(s32 *) s0;
    v0 = s1 + v0;
    v0 = *(s32 *) v0;
    v1 &= a1;
    v0 &= a0;
    v1 |= v0;
    *(s32 *) s0 = v1;
    v0 = *a2;
    s1 += v0;
    v0 = *(s32 *) s1;
    s0 &= a0;
    v0 &= a1;
    v0 |= s0;
    *(s32 *) s1 = v0;
}

extern void func_800253DC();
extern u16 D_801E90E8;
extern u16 D_801E9220;

void func_8006B648(void *arg0, s32 arg1) {
    u16 limit;
    register s32 i asm("s1");
    register s32 j asm("a0");
    u16 n;
    s32 *p;
    s32 *b1;
    register void *src asm("a2");
    register s32 *b3 asm("a3");
    register s32 mlo asm("a1");

    limit = D_801E90E8;
    src = arg0;
    __asm__("move %0, %1" : "=&r"(i) : "r"(arg1), "r"(src));
    if (limit < 0x64) {
        *(u16 *) ((u8 *) src + 2) += 0xF0;
    }
    n = D_801E9220;
    D_801E9220 = n + 1;
    b1 = D_801E923C;
    p = (s32 *) (*(u8 **) ((u8 *) b1 + 0x5C) + n * 0xC);
    func_800253DC(p, src, src);
    b3 = D_801E923C;
    mlo = 0xFFFFFF;
    j = i * 4;
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (j + *b3) & mlo);
    *(s32 *) (j + *b3) = (*(s32 *) (j + *b3) & 0xFF000000) | ((s32) p & mlo);
}

extern s32 func_800254CC(s32 *, s32, s32, s32, s32);
extern u16 D_801E922C;

void func_8006B72C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register u16 n asm("v1");
    s32 *p;
    register s32 *b1 asm("v0");
    register s32 *b2 asm("a2");
    register s32 *b3 asm("a3");
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
    b1 = D_801E923C;
    n = D_801E922C;
    p = (s32 *) (*(u8 **) ((u8 *) b1 + 0x60) + n * 0xC);
    D_801E922C = n + 1;
    func_800254CC(p, r0, r1, r2, arg3);
    b2 = D_801E923C;
    b3 = D_801E923C;
    mlo = 0xFFFFFF;
    i <<= 2;
    mhi = 0xFF000000;
    *(s32 *) p = (*(s32 *) p & mhi) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & mhi) | ((s32) p & mlo);
}

void func_8006B804(void) {
    func_800248FC();
    do {
    } while (func_800246D4(1) != 0);
}

extern void func_80024960();
extern s32 func_800246D4();

void func_8006B834(void) {
    func_80024960();
    do {
    } while (func_800246D4(1) != 0);
}

void func_8006B864(s32 arg0, s32 arg1, s32 arg2) {
    func_800249C4(arg0, (s16) arg1, (s16) arg2);
    while (func_800246D4(1) != 0) {
    }
}

extern s32 D_801E9024;
extern s32 D_801E9028;
extern s16 D_801E9350;
extern u16 D_801E90F8;
extern s16 D_801E9248;
extern s16 D_801E8FFC;
extern s16 D_801E9010;
extern s16 D_801D86B0;
extern u8 D_801E8FF8[];
extern u8 D_801E8FF9[];
extern u8 D_801E8FFA[];
extern u8 D_801E901C;
extern s8 D_801D8764;
extern s8 D_801E9048;

void func_8006B8A0(s32 arg0, s32 arg1, s32 arg2) {
    register s32 v1 asm("$3");

    s32 v0;
    D_801E9024 = arg0;
    D_801E9028 = arg2;
    v0 = -1;
    if (arg0 != 0) {
        v1 = *(s16 *) arg0;
        D_801E9350 = 0;
        if (v1 != v0) {
            arg2 = -1;
            do {
                v0 = (u16) D_801E9350;
                v0 = v0 + 1;
                __asm__ volatile("sll %0,%1,16\n\tsra %0,%0,15" : "=r"(v1) : "r"(v0));
                v1 = v1 + arg0;
                v1 = *(s16 *) v1;
                D_801E9350 = v0;
            } while (v1 != arg2);
        }
    }
    D_801E90F8 = (s16) arg1;
    v0 = 0x80;
    if (arg1 == 0) {
        D_801E9248 = 0;
    }
    D_801E8FF8[0] = (u8) v0;
    D_801E8FF9[0] = (u8) v0;
    D_801E8FFA[0] = (u8) v0;
    v0 = 1;
    D_801E8FFC = 0;
    D_801E9010 = 0;
    D_801D86B0 = 0;
    D_801E901C = (u8) v0;
    D_801D8764 = 0;
    D_801E9048 = 0;
}

extern void func_801CA8A0();

void func_8006B96C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 k = arg2;

    func_801CA8A0(arg0, arg1, arg3, arg3);
    D_801E9248 = k;
}

extern void func_801CA96C();
extern void func_801CC628();

void func_8006B9A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 k = arg4;

    func_801CA96C(arg0, arg1, arg2, arg3);
    func_801CC628(k);
}

extern s16 D_801E9014;
extern s32 D_801E9000;
extern s32 D_801D8700[];

typedef void (*func_8006B9D4_fn)(void);

void func_8006B9D4(u8 *arg0, s32 arg1) {
    register s32 s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");

    D_801E8FFC = 0;
    D_801E9014 = 0;
    D_801E9000 = arg1;
    D_801E9048 = 0;
    v1 = *(u8 *) a0;
    v0 = 0x19;
    if (v1 == v0) {
        s0 = 0x19;
        goto done;
    }
    s0 = 0x19;
    s1 = (s32) D_801D8700;
    MEMORY_BARRIER();
    v0 = *(volatile u8 *) a0;
    do {
        v0 <<= 2;
        v0 += s1;
        v0 = *(s32 *) v0;
        ((func_8006B9D4_fn) v0)();
        a0 = v0;
        v0 = *(volatile u8 *) a0;
    } while (v0 != s0);
done:;
}

extern void func_801CD2F0(s32);
extern void func_801CA9D4(s32, s32);

void func_8006BA68(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;

    var_s0 = arg1;
    if (arg2 != 0) {
        var_s0 = 0;
    }
    func_801CD2F0(arg2);
    func_801CA9D4(arg0, var_s0);
}

typedef void *(*func_8006BF84_fn)(s32, void *);

extern func_8006BF84_fn D_801E930C[];
extern s32 D_801D86B4;
extern u8 *func_801CAB30(func_8006BF84_fn);
extern u8 *func_801CABB0(void);

typedef s32 (*func_8006BAB8_fn)(s32, s32);

typedef u8 *(*func_8006BAB8_table_fn)(u8 *);

u8 *func_8006BAB8(u8 *arg0) {
    register u8 *s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 s2 asm("$18");
    register s32 s3 asm("$19");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    func_8006BAB8_table_fn temp_fn;
    u8 *p;

    s0 = arg0;
    v0 = s0[3];
    s1 = s0[4];
    v1 = D_801E9010;
    v0 <<= 2;
    a1 = *(s32 *) ((u8 *) D_801E930C + v0);
    if (v1 == 0) {
        v1 = s0[5];
        __asm__ volatile("j func_801CAB30" : : "r"(s0), "r"(a1), "r"(v1) : "a0", "a1", "v1");
    }
    v0 = D_801E9248;
    v1 = D_801D86B4;
    a0 = D_801D86B0;
    v1 = v0 + v1;
    if (a0 < 0) {
        v1--;
    }
    v0 = s0[1];
    p = s0 + v0;
    s0 = p;
    if (((func_8006BAB8_fn) a1)(v1, a1) == 0) {
        s1--;
        v0 = -1;
        if (s1 == v0) {
            return s0;
        }
        v1 = -1;
        do {
            v0 = s0[1];
            s1--;
            s0 += v0;
        } while (s1 != v1);
        __asm__ volatile("\t.set\tnoreorder\n\tj func_801CABB0\n\taddu $2,$16,$zero\n\t.set\treorder" : : : "v0", "memory");
    }
    s1--;
    if (s1 != v0) {
        s3 = (s32) D_801D8700;
        s2 = -1;
        do {
            v0 = s0[0];
            __asm__ volatile("addu %0,$16,$zero" : "=r"(a0) : : "memory");
            v0 <<= 2;
            v0 += s3;
            v0 = *(s32 *) v0;
            temp_fn = (func_8006BAB8_table_fn) v0;
            temp_fn((u8 *) a0);
            s1--;
            s0 = (u8 *) v0;
        } while (s1 != s2);
    }
    return s0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006BBD0);

extern s16 D_801E9008;
extern void func_801C98A0(s16 *, void *, s32, s32);
extern void *func_801CADBC(u8);

void *func_8006BD5C(void *arg0) {
    s16 buf[4];
    register s32 s0 asm("$16");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");

    v0 = D_801E9010;
    s0 = (s32) arg0;
    if (v0 != 0) {
        goto main;
    }
    a0 = *(u8 *) (s0 + 3);
    __asm__ volatile("j func_801CADBC" : : "r"(a0) : "a0", "memory");
main:
    a1 = D_801E9008;
    v0 = D_801D86B4;
    v0 = a1 * v0;
    a0 = *(u8 *) (s0 + 3);
    v1 = D_801D86B0;
    v0 += a0;
    a0 = v0 + v1;
    if (v1 < 0) {
        a0 -= a1;
    }
    v0 = *(u8 *) (s0 + 2);
    __asm__ volatile("lui $6,%%hi(D_801E9014)\n\tlbu $6,%%lo(D_801E9014)($6)" ::: "a2", "memory");
    a3 = D_801E8FFC;
    KEEP_NOVOL(a3);
    buf[1] = a0;
    buf[0] = v0;
    v0 = *(u8 *) (s0 + 4);
    a0 = (s32) &buf[0];
    buf[2] = v0;
    v0 = *(u8 *) (s0 + 5);
    a1 = s0 + 6;
    buf[3] = v0;
    func_801C98A0(&buf[0], (void *) a1, a2, a3);
    v0 = *(u8 *) (s0 + 1);
    v0 = s0 + v0;
    return (void *) v0;
}

extern void *func_801CAE74(u8);
extern void func_801C9D1C(s16 *, u8, u8, void *, s32, s32, s32, s32);
extern s16 D_801E902C;
extern s16 D_801E9030;

u8 *func_8006BE14(u8 *arg0) {
    s16 buf[4];
    register void *var_t0 asm("t0");
    s32 v0;
    s32 var_a0;
    register s32 a0 asm("a0");

    if (D_801E9010 == 0) {
        a0 = arg0[4];
        __asm__ volatile("j func_801CAE74" : : "r"(a0) : "a0");
    }
    {
        register s32 v0 asm("v0");
        register s32 v1 asm("v1");
        register s32 a1 asm("a1");

        a1 = D_801E9008;
        v0 = D_801D86B4;
        var_a0 = a1 * v0;
        a0 = arg0[4];
        v1 = D_801D86B0;
        var_a0 += a0;
        a0 = var_a0 - v1;
        if (v1 < 0) {
            a0 -= a1;
        }
    }
    v0 = arg0[3];
    buf[1] = a0;
    buf[0] = v0;
    buf[2] = arg0[5];
    var_t0 = D_801E8FF8;
    buf[3] = arg0[6];
    if (arg0[0] == 4) {
        var_t0 = 0;
    }
    {
        register s32 call_a0 asm("a0");
        register s32 call_a3 asm("a3");
        register s32 call_a1 asm("a1");
        register s32 call_a2 asm("a2");
        register s32 call_v0 asm("v0");
        register s32 call_v1 asm("v1");

        call_a0 = D_801E8FFC;
        call_a3 = D_801E9014;
        call_a1 = arg0[7];
        call_a2 = arg0[8];
        call_v0 = (u16) D_801E902C;
        call_v1 = (u16) D_801E9030;
        func_801C9D1C(&buf[0], call_a1, call_a2, var_t0, call_a3, call_v0, call_v1, call_a0);
    }
    return arg0 + arg0[1];
}

extern void func_801C99A0(s16 *, u8 *, u8, s16);

u8 *func_8006BF14(u8 *arg0) {
    s16 buf[4];

    buf[0] = arg0[2];
    buf[1] = arg0[3];
    buf[2] = arg0[4];
    buf[3] = arg0[5];
    func_801C99A0(buf, arg0 + 6, *(u8 *) &D_801E9014, D_801E8FFC);
    return arg0 + arg0[1];
}

extern u8 *func_801CAFEC(func_8006BF84_fn);
extern void func_801CAE14(u8 *);
extern u8 D_801D8773[];
extern u8 D_801D8774;
extern u8 D_801D8775;
extern u8 D_801D8776;
extern u8 D_801D8777;
extern u8 D_801D8778;

u8 *func_8006BF84(u8 *arg0) {
    register s32 s0 asm("$16");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");

    s0 = (s32) arg0;
    v0 = *(u8 *) (s0 + 2);
    v1 = D_801E9010;
    v0 <<= 2;
    a1 = *(s32 *) ((s32) D_801E930C + v0);
    if (v1 == 0) {
        v0 = *(u8 *) (s0 + 3);
        __asm__ volatile("j func_801CAFEC" : : "r"(v0), "r"(a1) : "v0", "a1", "memory");
    }
    v0 = D_801E9248;
    v1 = D_801D86B4;
    a0 = D_801D86B0;
    v0 += v1;
    if (a0 < 0) {
        v0 -= 1;
    }
    a0 = v0;
    ((func_8006BF84_fn) a1)(a0, (void *) a1);
    v1 = v0;
    if (v1 == 0) {
        goto done;
    }
    a0 = (s32) &D_801D8773[0];
    v0 = *(u8 *) (s0 + 4);
    *(u8 *) a0 = v0;
    v0 = *(u8 *) (s0 + 5);
    D_801D8774 = v0;
    v0 = ((u8 *) v1)[4];
    D_801D8775 = v0;
    v0 = ((u8 *) v1)[6];
    D_801D8776 = v0;
    v0 = ((u8 *) v1)[0];
    D_801D8777 = v0;
    v0 = ((u8 *) v1)[2];
    D_801D8778 = v0;
    v0 = *(u16 *) ((u8 *) v1 + 8);
    __asm__ volatile("lhu $3,0xa($3)\n\tlui $at,%%hi(D_801E9030)\n\tsh %0,%%lo(D_801E9030)($at)\n\tlui $at,%%hi(D_801E902C)\n\tsh $3,%%lo(D_801E902C)($at)" ::"r"(v0) : "v1", "at", "memory");
    func_801CAE14((u8 *) (a0 - 3));
done:
    v0 = *(u8 *) (s0 + 1);
    v0 = s0 + v0;
    return (u8 *) v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006C08C);

extern void func_801CA648();
extern void func_801CB08C(void *);
extern void func_801CB7E4();
extern s16 D_801D8784[];

void func_8006C6D4(void *arg0) {
    register s32 s0 asm("$16");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    s16 sp[4];
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_a2;
    s32 temp_a2_2;

    s0 = (s32) arg0;
    v1 = D_801D8764;
    v0 = v1 < 4;
    if (v0 == 0) {
        goto false_body;
    }
    v0 = v1 < 3;
    if (v0 != 0) {
        D_801E9000 = 0;
    }
    v0 = v1 << 1;
    a0 = *(s16 *) ((u8 *) D_801D8784 + v0);
    v0 = *(u8 *) (s0 + 5);
    MEMORY_BARRIER();
    temp_a1 = (v0 * a0) / 100;
    sp[2] = temp_a1;
    temp_a2 = (*(u8 *) (s0 + 6) * a0) / 100;
    sp[3] = temp_a2;
    temp_a2_2 = ((s32) temp_a2 << 16) >> 17;
    sp[0] = (s16) (*(u8 *) (s0 + 3) + (*(u8 *) (s0 + 5) >> 1)) -
        (s16) (((s32) temp_a1 << 16) >> 17);
    v0 = *(u8 *) (s0 + 6);
    v1 = *(u8 *) (s0 + 4);
    v0 >>= 1;
    v1 += v0;
    v1 -= temp_a2_2;
    sp[1] = v1;
    func_801CA648(&sp[0], D_801E8FFC - 1, temp_a2_2);
    D_801E9048 = 1;
    TAIL_JUMP_NOP(func_801CB7E4);
false_body:
    D_801E9048 = 0;
    a0 = s0;
    func_801CB08C((void *) a0);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006C800);

extern s32 func_80023A54(s32, s32);

u8 *func_8006CB30(u8 *arg0) {
    D_801E9030 = func_80023A54(arg0[3] * 0x10, arg0[4] | (arg0[2] << 8));
    return arg0 + arg0[1];
}

extern u8 D_801E9040[];
extern void *func_801CBBC4();

u8 *func_8006CB84(u8 *arg0) {
    register u8 v0 asm("v0");
    register u8 a0 asm("a0");
    register u8 a1 asm("a1");

    if (D_801E9040[0] == 0) {
        goto call_80023a54;
    }
    a0 = arg0[6];
    a1 = arg0[5];
    v0 = arg0[7];
    __asm__ volatile(".set\tnoreorder\n\tj func_801CBBC4\n\tsll %0, %0, 4\n\t.set\treorder" ::"r"(a0), "r"(a1), "r"(v0) : "a0", "memory");
call_80023a54:
    D_801E9030 = func_80023A54(arg0[3] << 4, arg0[4] | (arg0[2] << 8));
    return arg0 + arg0[1];
}

u8 *func_8006CBF8(u8 *arg0) {
    u8 t;

    t = arg0[2];
    D_801E902C = func_8002398C(arg0[4], t >> 4, arg0[3] * 0x10, t << 8);
    return arg0 + arg0[1];
}

u8 *func_8006CC4C(u8 *arg0) {
    D_801E9014 = arg0[3];
    return arg0 + arg0[1];
}

u8 *func_8006CC64(u8 *arg0) {
    s32 r;
    r = func_8002398C(0, arg0[2], 0x100, 0);
    func_801CA72C(0, 0, r & 0xFFFF, 0, D_801E8FFC);
    return arg0 + arg0[1];
}

u8 *func_8006CCC8(u8 *arg0) {
    if (D_801E9040[0] == 0) {
        goto second;
    }
    D_801E8FF8[0] = arg0[5];
    D_801E8FF9[0] = arg0[6];
    __asm__ volatile("lbu $2,7(%0)\n\t"
                     ".set\tnoreorder\n\t"
                     "j func_801CBD1C\n\t"
                     "nop\n\t"
                     ".set\treorder\n\t" ::"r"(arg0));
second:
    D_801E8FF8[0] = arg0[2];
    D_801E8FF9[0] = arg0[3];
    D_801E8FFA[0] = arg0[4];
    return arg0 + arg0[1];
}

u8 *func_8006CD30(u8 *arg0) {
    D_801E8FFC = arg0[3];
    return arg0 + arg0[1];
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006CD48);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006D17C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006D328);

u8 *func_8006D5BC(u8 *arg0) {
    register s32 x asm("$2");
    register s32 y asm("$3");
    register s32 z asm("$5");
    register s32 b asm("$3");
    register s32 c asm("$2");
    register s32 d asm("$3");

    b = arg0[0];
    x = 1;
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (b != x) {
        goto second;
    }
    __asm__ volatile("ori $2,$zero,2\n\t"
                     "lbu $2,4(%0)\n\t" ::"r"(arg0));
    __asm__ volatile("j func_801CC5FC\n\t"
                     "addiu $3,$2,1\n\t"
                     ".set\treorder\n\t" ::"r"(c));
second:
    __asm__(".set\tnoreorder\n\t");
    if (b != x) {
        goto third;
    }
    ASM_NOP();
    c = arg0[4];
    d = arg0[5];
    c = c + d;
    __asm__ volatile("j func_801CC5FC\n\t"
                     "addiu $3,$2,1\n\t"
                     ".set\treorder\n\t" ::"r"(c));
third:
    __asm__(".set\tnoreorder\n\t");
    __asm__ volatile("ori %0,$zero,1\n\taddiu %0,%0,-1" : "=r"(y));
    x = -1;
    if (y == x) {
        goto end;
    }
    ASM_NOP();
    z = -1;
    for (;;) {
        c = arg0[1];
        y--;
        arg0 += c;
        if (y != z) {
            continue;
        }
        break;
    }
end:
    __asm__(".set\treorder\n\t");
    return arg0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006D628);

void func_8006D8C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_801CA8A0();
    func_801CC628(arg3);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006D8F8);

void func_8006E2B4(u8 *arg0) {
    D_801E8FF8[0] = arg0[0];
    D_801E8FF8[1] = arg0[1];
    D_801E8FF8[2] = arg0[2];
}

void func_8006E2E0(s16 arg0) {
    D_801E8FFC = arg0;
}

extern u16 D_801D86E2[];
extern u16 D_801D86C0[];
extern u16 D_801D86BE[];
extern u16 D_801D86C6[];
extern u16 D_801D86CE[];
extern u16 D_801D86D0[];
extern u16 D_801D86E0[];
extern u16 D_801D86C2[];
extern u16 D_801D86BC[];
extern u16 D_801D86C4[];
extern u16 D_801D86CA[];
extern u16 D_801D86CC[];
extern u16 D_801E92D0;
extern u16 D_801E90F4;
extern u16 D_801E9088;
extern u16 D_801E92DC;
extern u16 D_801E92FC;

void func_8006E2F0(s32 arg0) {
    register s32 m asm("$2");
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;

    D_801E9040[0] = arg0;
    if (arg0 == 0) {
        goto b0;
    }
    {
        m = 0x60;
        __asm__ volatile("lhu $3,D_801D86E2");
        __asm__ volatile("lhu $4,D_801D86C0");
        __asm__ volatile("lhu $5,D_801D86BE");
        __asm__ volatile("lhu $6,D_801D86C6");
        __asm__ volatile("lhu $7,D_801D86CE");
        __asm__ volatile("lhu $8,D_801D86D0");
        D_801E8FF8[0] = m;
        D_801E8FF9[0] = m;
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801CD38C\n\t"
                         "ori $2,$zero,0x80\n\t"
                         ".set\treorder\n\t");
    }
b0:
    a = D_801D86E0[0];
    b = D_801D86C2[0];
    c = D_801D86BC[0];
    d = D_801D86C4[0];
    e = D_801D86CA[0];
    f = D_801D86CC[0];
    m = 0x80;
    D_801E8FF8[0] = m;
    D_801E8FF9[0] = m;
    D_801E8FFA[0] = m;
    D_801E92D0 = a;
    D_801E90F4 = b;
    D_801E90D0 = c;
    D_801E9088 = d;
    D_801E92DC = e;
    D_801E92FC = f;
}

extern s16 D_801D876A;

u8 *func_8006E3CC(u8 *arg0) {
    register s32 a1 asm("a1");

    u8 *a0;
    u8 *s0;
    s0 = arg0;
    if (D_801E9048 != 0) {
        a1 = D_801E8FFC;
        a0 = (u8 *) &D_801D876A;
        *(s16 *) a0 = 0;
        func_801CA648(a0 - 2, a1 + 1);
        D_801E9048 = 0;
    }
    return s0 + s0[1];
}

u8 *func_8006E430(u8 *arg0) {
    s16 buf[4];

    if (D_801E9048 == 0) {
        buf[0] = arg0[2];
        buf[1] = arg0[3];
        buf[2] = arg0[4];
        buf[3] = arg0[5];
        func_801CA648(buf, D_801E8FFC - 1);
    }
    return arg0 + arg0[1];
}

u8 *func_8006E4A4(u8 *arg0) {
    register s32 v asm("a1");
    if (D_801E9048 == 0) {
        v = D_801E8FFC;
        *(s16 *) ((u8 *) &D_801D8764 + 6) = 0;
        func_801CA648((s16 *) ((u8 *) &D_801D8764 + 4), v + 1);
    }
    return arg0 + arg0[1];
}

void func_8006E500(s8 arg0) {
    D_801D8764 = arg0;
}

s32 func_8006E510(void) {
    return D_801D8764;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006E520);

s32 func_8006E538(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s32 unused[2];
    v0 = v1 + 1;
    D_801D8764 = v0;
    __asm__ volatile(".L8006E548:");
    v0 = arg0 + 1;
    return v0;
}

u8 *func_8006E558(void) {
    return D_801E8FF8;
}

extern void func_801CD624(s16);

void func_8006E568(s32 arg0, u8 *arg1) {
    register s32 s1 asm("s1");
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register u8 *p1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a0 asm("a0");
    s32 unused[8];

    s1 = D_801E9248;
    v0 = D_801E90F8;
    s0 = v0 - s1;
    p1 = arg1;
    a2 = s1;
    if (arg0 == -1) {
        v0 = p1[6];
        v0 = a2 - v0;
        D_801E9248 = v0;
        if ((s16) v0 < 0) {
            D_801E9248 = 0;
            TAIL_JUMP_MEM(func_801CD624);
        } else {
            goto block_7;
        }
    }
    if (arg0 == 1) {
        v0 = p1[6];
        v1 = D_801E9350;
        v0 += a2;
        a2 = v1;
        D_801E9248 = v0;
        v0 = (s16) v0;
        v0 += 1;
        a0 = p1[6];
        v1 -= v0;
        if (v1 < a0) {
            v0 = *(volatile u8 *) &p1[6];
            v0 = a2 - v0;
            D_801E9248 = v0;
        }
    }
block_7:
    D_801E90F8 = (u16) D_801E9248;
    func_801CC628(p1);
    v0 = s0 + (u16) D_801E9248;
    D_801E90F8 = v0;
    if ((s16) v0 >= D_801E9350) {
        D_801E90F8 = D_801E9350 - 1;
    }
    if (s1 != (s16) (u16) D_801E9248) {
        D_801CE1C8 = 3;
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006E6A8);

extern void func_80024A88(s32, s32);
extern void func_80024E4C(void *);
extern s16 D_801E9078;
extern s16 D_801E907C;
extern s16 D_801E9080;
extern s16 D_801E9084;
extern s16 D_801E90B8;
extern s16 D_801E90BC;
extern s16 D_801E90C4;
extern s16 D_801E90C8;
extern s16 D_801E90CC;
extern s16 D_801E90D4;
extern s16 D_801E90D8;
extern s16 D_801E90E0;
extern s16 D_801E9244;
extern s16 D_801E92D8;
extern s16 D_801E92E0;
extern s32 *D_801E92EC;
extern s16 D_801E92F4;
extern s16 D_801E9300;
extern s16 D_801E9304;

void func_8006E7C4(s32 arg0) {
    u8 sp10[0x60];
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");

    s0 = arg0;
    D_801E9078 = 0;
    D_801E90D4 = 0;
    D_801E9080 = 0;
    D_801E90DC = 0;
    D_801E907C = 0;
    D_801E90D8 = 0;
    D_801E9084 = 0;
    D_801E90E0 = 0;
    D_801E90AC = 0;
    D_801E90BC = 0;
    D_801E90C8 = 0;
    D_801E90B8 = 0;
    D_801E90C4 = 0;
    D_801E90CC = 0;
    D_801E9234 = 0;
    D_801E92D8 = 0;
    D_801E92E0 = 0;
    D_801E9300 = 0;
    D_801E9244 = 0;
    D_801E92F4 = 0;
    D_801E9304 = 0;
    D_801E9238 = 0;
    D_801E9220 = 0;
    D_801E922C = 0;
    func_80024E4C(sp10);
    v0 = *(u16 *) (sp10 + 2);
    D_801E90E8 = v0;
    a1 = (s32) D_801E92EC;
    v1 = (s32) D_801E923C;
    a0 = s0 << 2;
    if (v1 == a1) {
        a1 += 0xEC;
    }
    v0 = *(s32 *) a1;
    D_801E923C = (s32 *) a1;
    a0 += v0;
    a1 = D_801E9100 - s0;
    func_80024A88(a0, a1);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006E8F8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/EQUIP", func_8006EA80);

extern s8 D_801D87C8_h asm("D_801D87C8");

s32 func_8006EF30(void) {
    s32 v;
    v = D_801D87C8_h;
    if (v == 0) {
        return 1;
    }
    return v;
}

extern u8 D_801D87CC;
extern s32 D_801E905C;

void func_8006EF50(s32 arg0) {
    D_801D87CC = 1;
    D_801E905C = arg0;
}

extern u8 D_801D87CD;
extern s32 D_801E9060;

void func_8006EF6C(s32 arg0) {
    D_801D87CD = 1;
    D_801E9060 = arg0;
}

extern s32 D_801D87D0;

s32 func_8006EF88(s32 arg0) {
    s32 acc;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 n;
    s32 a1;
    u8 *p;
    s32 v;

    if (arg0 == 0) {
        return 0;
    }
    __asm__(".set push\n.set noreorder\n"
            "lui $2,%hi(D_801D87CC)\n"
            "lbu $2,%lo(D_801D87CC)($2)\n"
            "nop\n"
            "beqz $2,1f\n"
            "move $7,$0\n"
            "ori $2,$0,7\n"
            "lui $1,%hi(D_801D87D0)\n"
            "sw $2,%lo(D_801D87D0)($1)\n"
            "lui $1,%hi(D_801D87CC)\n"
            "sb $0,%lo(D_801D87CC)($1)\n"
            "1:\n"
            ".set pop\n");
    arg0--;
    if (arg0 == -1) {
        return acc;
    }
    t2 = 1;
    t1 = 7;
    t0 = -1;
    for (;;) {
        p = (u8 *) D_801E905C;
        n = D_801D87D0;
        v = *p;
        a1 = n - 1;
        D_801D87D0 = a1;
        if ((v >> n) & 1) {
            acc |= t2 << arg0;
        }
        arg0--;
        if (a1 < 0) {
            D_801D87D0 = t1;
            D_801E905C = (s32) (p + 1);
        }
        if (arg0 != t0) {
            continue;
        }
        break;
    }
    return acc;
}

extern s32 D_801D87D4;

s32 func_8006F034(s32 arg0) {
    s32 acc;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 n;
    s32 a1;
    u8 *p;
    s32 v;

    if (arg0 == 0) {
        return 0;
    }
    __asm__(".set push\n.set noreorder\n"
            "lui $2,%hi(D_801D87CD)\n"
            "lbu $2,%lo(D_801D87CD)($2)\n"
            "nop\n"
            "beqz $2,1f\n"
            "move $7,$0\n"
            "ori $2,$0,7\n"
            "lui $1,%hi(D_801D87D4)\n"
            "sw $2,%lo(D_801D87D4)($1)\n"
            "lui $1,%hi(D_801D87CD)\n"
            "sb $0,%lo(D_801D87CD)($1)\n"
            "1:\n"
            ".set pop\n");
    arg0--;
    if (arg0 == -1) {
        return acc;
    }
    t2 = 1;
    t1 = 7;
    t0 = -1;
    for (;;) {
        p = (u8 *) D_801E9060;
        n = D_801D87D4;
        v = *p;
        a1 = n - 1;
        D_801D87D4 = a1;
        if ((v >> n) & 1) {
            acc |= t2 << arg0;
        }
        arg0--;
        if (a1 < 0) {
            D_801D87D4 = t1;
            D_801E9060 = (s32) (p + 1);
        }
        if (arg0 != t0) {
            continue;
        }
        break;
    }
    return acc;
}
