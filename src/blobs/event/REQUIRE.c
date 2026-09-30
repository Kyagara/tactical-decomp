#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80060024);

extern void func_8014BF54();
extern u8 D_801CB690[];

void func_800601F4(EventCoord28 *arg0) {
    *(u16 *) &arg0->at_1C = 0;
    *(u16 *) &arg0->pad_26[0] = 0;
    func_8014BF54((u8 *) &arg0->at_20, D_801CB690, 8);
}

void func_80060228(u16 *arg0, u32 arg1) {
    arg0[0] = (arg1 & 0x3F) << 4;
    arg0[1] = (arg1 & 0xFFFF) >> 6;
    arg0[2] = 0x10;
    arg0[3] = 1;
}

extern void func_80136BD0();
extern void func_801C52C4();

void func_80060254(s32 arg0, s32 arg1) {
    if (!(arg0 & 0x300)) {
        func_80136BD0(arg1, arg0);
    }
    if (arg0 & 0x100) {
        func_801C52C4(arg1, arg0 & 0xFF);
    }
}

void func_800602AC(u8 *arg0, s32 arg1) {
    s32 t0;
    s32 t1;
    s32 u0;
    s32 u1;

    if (arg0[0xC] != arg0[0x14]) {
        MEMORY_BARRIER();
        t0 = arg0[0xC] + arg1;
        t1 = arg0[0x1C] + arg1;
        arg0[0xC] = t0;
        TAIL_JUMP_SB_1C(func_801BF2F4, t1, arg0, t0);
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

void func_80060310(u8 *arg0, s32 arg1) {
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
        TAIL_JUMP_SB_24(func_801BF36C, s24, arg0, s14);
    }
    delta_15 = ((u8 *) &r->f14)[1] - arg1;
    delta_25 = r->f24[1] - arg1;
    ((u8 *) &r->f14)[1] = delta_15;
    r->f24[1] = delta_25;
    MEMORY_BARRIER();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80060374);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_8006079C);

void func_800617AC(void) {
}

extern void func_80023C68(void *, s32);
extern void func_80023DD0(void *);
extern void func_80023DE4(void *);
extern void func_8014A6E4(void *, s32);

void func_800617B4(u8 *arg0) {
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

extern void func_8014C958();
extern void func_8014CA80();

void func_800619D4(void) {
    func_8014CA80();
    func_8014C958();
}

void func_800619FC(void) {
    func_8014CA80();
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80061A24);

extern s32 D_80166028;
extern void func_80023C90(void *, s32);
extern void func_801C1304();

void func_800621B0(u8 *arg0, u8 *arg1) {
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
    TAIL_JUMP(func_801C1304);
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

void func_8006232C(s32 arg0, u8 *arg1) {
    if (*(s32 *) (arg1 + 0x10) == 1 || D_80166028 == 1) {
        func_8012F454();
        TAIL_JUMP(func_801C1370);
    }
    func_8012F3CC();
}

extern void func_801C1430(s16);
extern void func_801C1438(s16);
extern void func_801C1580(s32, s32, s32, void *);

void func_80062380(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    register s32 s5 asm("$21");
    register u8 *s3 asm("$19");
    register u8 *s1 asm("$17");
    register s32 s4 asm("$20");
    register s32 s2 asm("$18");
    register u8 *s0 asm("$16");
    register s32 v0 asm("$2");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    s32 pad[2];

    s5 = arg0;
    KEEP_WITH_NOVOL(s5, arg0);
    s3 = arg1;
    KEEP_WITH_NOVOL(s3, arg1);
    s1 = arg2;
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
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1430\n\tnegu $4,$4\n\t.set\treorder" : : "r"(a0), "r"(v0) : "memory");
        }
        if (a0 > 0) {
            v0 = 0xCCCCCCCC;
            *(volatile u32 *) (s1 + 0xC) = v0;
            v0 = *(u16 *) s0;
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1438\n\tori $2,$2,0x400\n\t.set\treorder" : : "r"(v0) : "memory");
        }
        *(u32 *) (s1 + 0xC) = 0;
        v0 = *(u16 *) s0;
        v0 |= 0x800;
        *(u16 *) s0 = (u16) v0;
        MEMORY_BARRIER();
        a1 = *(s16 *) s0;
        s0 += 0xC;
        MEMORY_BARRIER();
        s3 += 0xC;
        s2++;
        a2 = s5;
        a3 = (s32) s1;
        func_801C1580(a0, a1, a2, a3);
        *(u32 *) (s1 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

extern void func_801C1534(s16, s32);

void func_8006248C(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
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
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1534\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        if (a0 > 0) {
            a1 |= 0x400;
            v0 = 0xBBBBBBBB;
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1534\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        *(volatile u32 *) (s0 + 0xC) = 0;
        MEMORY_BARRIER();
        a1 &= 0xFFF0;
        a1 |= 0x804;
        a2 = s5;
        func_801C1580(a0, a1, a2, s0);
        s1 += 0xC;
        s3 += 0xC;
        s2++;
        *(u32 *) (s0 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80062580);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80062884);

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
extern s32 D_80165F8C;
extern s32 D_80165FA8;
extern s32 *D_801D208C;

void func_80062DE8(void) {
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

    D_801D208C = func_8014A578(0);
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
    a0 = D_801D208C;
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
        TAIL_JUMP_MEM(func_801C1E98);
    }
    func_8014CA80();
    func_8014C958();
}

extern void func_8014C8A0();
extern void func_8014CA58(s32, s32, s32, s32, s32);
extern void func_8014C9D0(s32);
extern s32 D_801308C0;
extern s32 D_80165F98;
extern s32 D_80174038;

void func_80062FD8(void) {
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
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
    D_801D208C = ptr;
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

void func_800630D0(void) {
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
        __asm__ volatile(".set\tnoreorder\n\tj func_801C2138\n\taddiu %0,%0,0x1\n\t.set\treorder" : "=r"(s1));
    }
    func_8014CA80();
    func_8014C958();
}

extern void func_80136B10(u8 *);

void func_80063244(u8 *arg0) {
    u8 buf[24];

    func_80136B10(buf);
    *(u16 *) arg0 = buf[0xC];
    *(u16 *) (arg0 + 2) = buf[0xD];
    *(u16 *) (arg0 + 4) = 0x10;
    *(u16 *) (arg0 + 6) = 0x10;
    *(u16 *) (arg0 + 8) = *(u16 *) (buf + 0xE);
    *(u16 *) (arg0 + 0xA) = func_8002398C(0, 0, 0x380, 0x120);
}

void func_800632AC(void) {
}

s32 func_800632B4(s32 arg0) {
    arg0 <<= 10;
    return *(s32 *) (arg0 + D_80165F98 + 0x48);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_800632D0);

void func_800637A4(u8 *arg0) {
    register s32 i asm("v0");
    u8 c;
    c = 0xFE;
    for (i = 0xF; i >= 0; i--) {
        *arg0 = c;
        arg0++;
    }
}

void func_800637C4(u8 *arg0, s16 *arg1) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");

    v0 = arg0[0x22];
    arg1[1] = 0;
    arg1[0] = v0;
    v0 = arg0[0x1BA];
    if ((v0 & 0x30) != 0) {
        v0 = 1;
        arg1[1] = v0;
    }
    v0 = arg0[0x1BA];
    if ((v0 & 0x38) == 0) {
        v0 = 2;
        arg1[1] = v0;
    }
    v0 = arg0[0x1B8];
    if (v0 != 0) {
        v0 = 3;
        arg1[1] = v0;
    }
    v0 = arg0[0x21];
    arg1[4] = v0;
    v0 = *(u16 *) (arg0 + 0x2A);
    arg1[8] = v0;
    if (v0 != 0) {
        goto l3838;
    }
    arg1[8] = v0 + 1;
l3838:
    v0 = *(u16 *) (arg0 + 0x28);
    arg1[7] = 0;
    arg1[6] = v0;
    v0 = *(u16 *) (arg0 + 0x2E);
    arg1[11] = v0;
    if (v0 != 0) {
        goto l385c;
    }
    arg1[11] = v0 + 1;
l385c:
    v0 = *(u16 *) (arg0 + 0x2C);
    v1 = 0x64;
    arg1[10] = 0;
    arg1[14] = v1;
    arg1[9] = v0;
    v0 = arg0[0x39];
    arg1[5] = 0;
    arg1[2] = 0;
    arg1[3] = 0;
    arg1[12] = v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80063888);

void func_80063DCC(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
    register u8 *s0 asm("s0");
    register u8 *s1 asm("s1");
    register u8 *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 s4 asm("s4");
    register u8 *s5 asm("s5");
    register s32 s6 asm("s6");
    register s32 s7 asm("s7");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    register s32 t0 asm("t0");
    s1 = arg0;
    a0 = (s32) arg4;
    s2 = arg2;
    s0 = arg3;
    v0 = *(s16 *) (arg3 + 8);
    a2 = *(s16 *) arg4;
    v1 = v0 * a2;
    if (v1 < 0) {
        v1 += 0xFFF;
    }
    t0 = (s32) arg1;
    s5 = arg5;
    s6 = v1 >> 12;
    v0 = *(s16 *) (arg3 + 0xA);
    a1 = *(s16 *) (arg4 + 2);
    a0 = v0 * a1;
    if (a0 < 0) {
        a0 += 0xFFF;
    }
    s7 = a0 >> 12;
    v0 = *(s16 *) (arg3 + 4);
    v1 = v0 * a2;
    if (v1 < 0) {
        v1 += 0xFFF;
    }
    s3 = v1 >> 12;
    v0 = *(s16 *) (arg3 + 6);
    v0 = v0 * a1;
    if (v0 < 0) {
        v0 += 0xFFF;
    }
    s4 = v0 >> 12;
    if (s3 < 0) {
        s3 = -s3;
    }
    if (s4 < 0) {
        s4 = -s4;
    }
    a0 = 0;
    a1 = 0;
    a2 = *(s16 *) arg1;
    a3 = *(u16 *) (arg1 + 2) & 0xF00;
    v0 = func_8002398C(a0, a1, a2, a3);
    *(s16 *) (arg0 + 0x16) = v0;
    arg0[0xC] = *(u8 *) arg3;
    arg0[0xD] = *(u8 *) (arg3 + 2);
    arg0[0x14] = (s8) (*(u8 *) arg3 + *(u8 *) (arg3 + 4));
    arg0[0x15] = *(u8 *) (arg3 + 2);
    arg0[0x1C] = *(u8 *) arg3;
    arg0[0x1D] = (s8) (*(u8 *) (arg3 + 2) + *(u8 *) (arg3 + 6));
    arg0[0x24] = (s8) (*(u8 *) arg3 + *(u8 *) (arg3 + 4));
    arg0[0x25] = (s8) (*(u8 *) (arg3 + 2) + *(u8 *) (arg3 + 6));
    v0 = *(u16 *) arg2;
    v0 += s6;
    v0 += *(u16 *) (arg5 + 8);
    *(u16 *) (arg0 + 8) = v0;
    v0 = *(u16 *) (arg2 + 2);
    v0 += s7;
    v0 += *(u16 *) (arg5 + 0xA);
    *(u16 *) (arg0 + 0xA) = v0;
    v0 = *(u16 *) arg2;
    v0 += s6;
    v0 += *(u16 *) (arg5 + 8);
    v0 += s3;
    *(u16 *) (arg0 + 0x10) = v0;
    v0 = *(u16 *) (arg2 + 2);
    v0 += s7;
    v0 += *(u16 *) (arg5 + 0xA);
    *(u16 *) (arg0 + 0x12) = v0;
    v0 = *(u16 *) arg2;
    v0 += s6;
    v0 += *(u16 *) (arg5 + 8);
    *(u16 *) (arg0 + 0x18) = v0;
    v0 = *(u16 *) (arg2 + 2);
    v0 += s7;
    v0 += *(u16 *) (arg5 + 0xA);
    v0 += s4;
    *(u16 *) (arg0 + 0x1A) = v0;
    v0 = *(u16 *) arg2;
    v0 += s6;
    v0 += *(u16 *) (arg5 + 8);
    v0 += s3;
    *(u16 *) (arg0 + 0x20) = v0;
    v0 = *(u16 *) (arg2 + 2);
    v0 += s7;
    v0 += *(u16 *) (arg5 + 0xA);
    v0 += s4;
    *(u16 *) (arg0 + 0x22) = v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80064010);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_800642CC);

void func_8006445C(u8 *arg0, u16 *arg1, u16 *arg2, u8 *arg3, s16 *arg4, u16 *arg5) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    register s32 t0 asm("$8");
    register s32 t1 asm("$9");
    register s32 t2 asm("$10");
    register u16 *t3 asm("$11");
    register u8 *s0 asm("$16");
    register u8 *s1 asm("$17");
    register s32 s2 asm("$18");
    register s32 s3 asm("$19");
    register s32 s4 asm("$20");
    register s32 s5 asm("$21");
    register u16 *s6 asm("$22");
    register u16 *s7 asm("$23");

    s1 = arg0;
    s0 = arg3;
    v1 = (s32) arg4;
    a0 = ((s16 *) v1)[0];
    s2 = ((s16 *) s0)[4] * a0;
    s5 = ((s16 *) s0)[5] * ((s16 *) v1)[1];
    s3 = ((s16 *) s0)[2] * a0;
    s4 = ((s16 *) s0)[3] * ((s16 *) v1)[1];
    t3 = arg1;
    KEEP_NOVOL(t3);
    s6 = arg2;
    KEEP_NOVOL(s6);
    a3 = 0;
    t0 = 0;
    t1 = 0;
    t2 = 0;
    s7 = arg5;

    v0 = s2;
    if (s2 < 0) {
        v0 = s2 + 0xFFF;
    }
    a2 = v0 >> 0xC;
    v0 = s2 - (a2 << 0xC);
    if (v0 >= 0x800) {
        a3 = 1;
    }

    v0 = s5;
    if (s5 < 0) {
        v0 = s5 + 0xFFF;
    }
    a1 = v0 >> 0xC;
    v0 = s5 - (a1 << 0xC);
    if (v0 >= 0x800) {
        t0 = 1;
    }

    v0 = s3;
    if (s3 < 0) {
        v0 = s3 + 0xFFF;
    }
    a0 = v0 >> 0xC;
    v0 = s3 - (a0 << 0xC);
    if (v0 >= 0x800) {
        t1 = 1;
    }

    v0 = s4;
    if (s4 < 0) {
        v0 = s4 + 0xFFF;
    }
    v1 = v0 >> 0xC;
    v0 = s4 - (v1 << 0xC);
    if (v0 >= 0x800) {
        t2 = 1;
    }

    s2 = a2 + a3;
    s5 = a1 + t0;
    s3 = a0 + t1;
    s4 = v1 + t2;
    if (s3 < 0) {
        s3 = -s3;
    }
    if (s4 < 0) {
        s4 = -s4;
    }

    *(s16 *) (s1 + 0x16) = func_8002398C(1, 0, (s16) t3[0], t3[1] & 0xF00);
    s1[0xC] = s0[0];
    s1[0xD] = s0[2];
    s1[0x14] = s0[0] + s0[4];
    s1[0x15] = s0[2];
    s1[0x1C] = s0[0];
    s1[0x1D] = s0[2] + s0[6];
    s1[0x24] = s0[0] + s0[4];
    s1[0x25] = s0[2] + s0[6];
    v0 = s6[0];
    v0 = v0 + s2;
    v0 = v0 + s7[4];
    *(s16 *) (s1 + 8) = v0;
    v0 = s6[1];
    v0 = v0 + s5;
    v0 = v0 + s7[5];
    *(s16 *) (s1 + 0xA) = v0;
    v0 = s6[0];
    v0 = v0 + s2;
    v0 = v0 + s7[4];
    v0 = v0 + s3;
    *(s16 *) (s1 + 0x10) = v0;
    v0 = s6[1];
    v0 = v0 + s5;
    v0 = v0 + s7[5];
    *(s16 *) (s1 + 0x12) = v0;
    v0 = s6[0];
    v0 = v0 + s2;
    v0 = v0 + s7[4];
    *(s16 *) (s1 + 0x18) = v0;
    v0 = s6[1];
    v0 = v0 + s5;
    v0 = v0 + s7[5];
    v0 = v0 + s4;
    *(s16 *) (s1 + 0x1A) = v0;
    v0 = s6[0];
    v0 = v0 + s2;
    v0 = v0 + s7[4];
    v0 = v0 + s3;
    *(s16 *) (s1 + 0x20) = v0;
    v0 = s6[1];
    v0 = v0 + s5;
    v0 = v0 + s7[5];
    v0 = v0 + s4;
    *(s16 *) (s1 + 0x22) = v0;
}

extern void func_80023D1C(void *);
extern s32 func_80023A54(s32, s32);
extern void func_80023D08(void *);
extern void func_801C345C(void *, void *, void *, void *, EventDrawArgs);
extern u8 D_801D082C[];
extern u8 D_801D0988[];
extern u8 D_801D098A[];
extern u8 D_801D09FD;
extern u8 D_801D00B8[];

void func_8006472C(u8 *arg0, u8 *arg1) {
    register EventCoord28 *s0 asm("s0");
    u8 *p2;
    s16 buf[5];
    EventDrawArgs *args;
    s32 s3;
    register s32 s4 asm("s4");
    register s32 s5 asm("s5");
    s32 s6;
    s32 s7;
    register s32 a2 asm("a2");
    register u8 *table asm("a3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 c0 asm("a0");
    register s32 c1 asm("a1");

    s0 = (EventCoord28 *) arg1;
    s4 = 0;
    v0 = D_801D09FD;
    if (v0 <= 0) {
        goto end;
    }
    s6 = 0xFFFFFF;
    s7 = 0xFF000000;
    s5 = 0;
    s3 = 0;
    p2 = arg1 + 6;
loop:
    func_80023D1C(s0);
    *(u16 *) (p2 + 8) = func_80023A54(0, 0x1FD);
    p2[-2] = *(volatile u8 *) (arg0 + 4);
    p2[-1] = *(volatile u8 *) (arg0 + 4);
    p2[0] = *(volatile u8 *) (arg0 + 4);
    func_80023C68(s0, 1);
    func_80023C90(s0, 0);
    a2 = *(s16 *) (D_801D0988 + s3);
    v0 = *(s16 *) (arg0 + 0xC);
    a2 = a2 * v0;
    v1 = *(s16 *) (D_801D098A + s3);
    v0 = *(s16 *) (arg0 + 0xE);
    v1 = v1 * v0;
    v0 = a2;
    if (a2 < 0) {
        v0 = a2 + 0xFFF;
    }
    v0 >>= 12;
    v0 <<= 12;
    v0 = a2 - v0;
    if (!(v0 < 0x800)) {
        a2++;
    }
    v0 = v1;
    if (v1 < 0) {
        v0 = v1 + 0xFFF;
    }
    v0 >>= 12;
    v0 <<= 12;
    v0 = v1 - v0;
    if (!(v0 < 0x800)) {
        v1++;
    }
    v0 = a2;
    if (a2 < 0) {
        v0 = a2 + 0xFFF;
    }
    a2 = v0 >> 12;
    v0 = v1;
    if (v1 < 0) {
        v0 = v1 + 0xFFF;
    }
    v1 = v0 >> 12;
    c0 = (s32) s0;
    c1 = (s32) D_801D00B8;
    buf[0] = a2;
    buf[1] = v1;
    args = (EventDrawArgs *) ((u8 *) buf - 8);
    v0 = (s32) buf;
    args->coords = (s16 *) v0;
    MEMORY_BARRIER();
    v0 = (s32) (arg0 + 0x18);
    args->extra = (u8 *) v0;
    table = D_801D082C;
    a2 = (s32) D_801CB690 + ((s32) table - (s32) table);
    func_801C345C((u8 *) c0, (u8 *) c1, (u8 *) a2, table + s5, *args);
    s5 += 0xC;
    if (*(s32 *) (arg0 + 8) != 0) {
        p2 += 0x28;
        v0 = *(u32 *) arg0;
        v1 = s0->packed;
        v0 = *(u32 *) v0;
        v1 &= s7;
        v0 &= s6;
        v1 |= v0;
        s0->packed = v1;
        v1 = *(u32 *) arg0;
        v0 = *(u32 *) v1;
        c0 = (s32) s0 & s6;
        s0++;
        v0 &= s7;
        v0 |= c0;
        *(u32 *) v1 = v0;
    }
    s4++;
    if (s4 < D_801D09FD) {
        s3 += 4;
        goto loop;
    }
end:
    func_80023D08(s0);
    s0->at_04 = 8;
    s0->at_05 = 8;
    s0->at_06 = 8;
    func_80023C68(s0, 1);
    func_80023C90(s0, 0);
    {
        register s32 cm asm("a0");
        register s32 am asm("a1");
        register s32 ev asm("v0");

        cm = 0xFFFFFF;
        s0->at_08 = 0;
        s0->at_0A = 0;
        ev = 0xFF;
        am = 0xFF000000;
        s0->at_10 = ev;
        s0->at_12 = 0;
        s0->at_18 = 0;
        s0->at_1A = ev;
        s0->at_20 = ev;
        s0->at_22 = ev;
        v0 = *(u32 *) arg0;
        v1 = s0->packed;
        v0 = *(u32 *) v0;
        v1 &= am;
        v0 &= cm;
        v1 |= v0;
        s0->packed = v1;
        v1 = *(u32 *) arg0;
        v0 = *(u32 *) v1;
        cm = (s32) s0 & cm;
        v0 &= am;
        v0 |= cm;
        *(u32 *) v1 = v0;
    }
}

extern void func_8014C858();
extern void func_801CA644();

void func_800649E0(void) {
    func_8014C858(0x10);
    func_801CA644();
}

extern u16 D_801D0ADC[];
extern u8 D_801D0AE2[];
extern void func_8013B644(s32, s32);

void func_80064A08(s32 arg0, s32 arg1) {
    register s32 i asm("s0");
    register s32 count asm("a0");
    register s32 off asm("a1");
    register u16 *base asm("s1");
    register u16 *p asm("v1");

    i = 0;
    base = D_801D0ADC;
outer:
    count = 0;
    off = i << 3;
    p = base;
inner:
    if (arg0 == *p) {
        goto check;
    }
    count++;
    p++;
    if (count < 3) {
        goto inner;
    }
check:
    if (count != 3) {
        func_8013B644(*(u16 *) (D_801D0AE2 + off), arg1);
    }
    base += 4;
next:
    i++;
    count = 0;
    if (i < 0xB) {
        goto outer;
    }
}

extern s32 func_800444DC();
extern void func_80044600();
extern s32 func_8014CEB4();
extern s32 D_80173CA8;
extern s32 D_80010010;
extern s32 D_80044694;
extern s32 D_800446C8;
extern s32 D_801D0068;
extern s32 D_801D0070;

void func_80064AB0(s32 arg0) {
    s32 temp_v0;

    do {
        func_8014CA80();
        temp_v0 = func_800444DC(D_80010010, 0x8000);
    } while (temp_v0 != D_80010010);
    do {
        func_8014CA80();
        D_80173CA8 = &D_80044694;
    } while (func_8014CEB4((arg0 * 0xD) + 0x16C0, 0x6800, temp_v0) != 0);
    do {
        func_8014CA80();
        D_80173CA8 = &D_800446C8;
    } while (func_8014CEB4() != 0);
    func_800248FC(&D_801D0068, temp_v0);
    func_800248FC(&D_801D0070, temp_v0 + 0x6400);
    func_8014CA80();
    func_80044600(temp_v0);
}

void func_80064BA4(s32 arg0) {
    s32 *temp_v0;
    s32 s0;
    s32 s1;
    s32 unused[2];

    s1 = arg0;
    s0 = 0;
    if (s1 <= 0) {
        return;
    }
    do {
        func_8014CA80();
        temp_v0 = func_8014A578(0);
        D_801D208C = temp_v0;
        if (*temp_v0 & 0x20) {
            break;
        }
        s0 += 1;
    } while (s0 < s1);
}

extern u8 D_801D0078;
extern u8 D_801D0079;
extern u8 D_801D007A;

struct func_80064C10_stack {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 pad0;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 pad1;
    s32 sp30;
    s32 sp34;
    s32 sp38;
};

void func_80064C10(s32 arg0, s32 arg1, s32 arg2) {
    struct func_80064C10_stack stack;
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");

    s0 = 0;
    s1 = 0x88888889;
    s2 = (s32) &stack.sp10;
    stack.sp30 = arg0 << 3;
    stack.sp34 = arg1 << 3;
    stack.sp10 = D_801D0078;
    stack.sp14 = D_801D0079;
    stack.sp18 = D_801D007A;
    *(volatile s32 *) &stack.sp38 = arg2 << 3;
    goto init_index;
init_index:
    do {
        a2 = 0;
        a1 = s2;
        do {
            v0 = *(s32 *) ((u8 *) a1 + 0x20);
            a0 = *(s32 *) a1;
            v0 -= a0;
            v0 = ((v0 * s0) / 30) + a0;
            *(s32 *) ((u8 *) a1 + 0x10) = v0;
            v0 = *(u8 *) ((u8 *) a1 + 0x10);
            *((u8 *) &D_801D0078 + a2) = (u8) v0;
            a2++;
            a1 += 4;
        } while (a2 < 3);
        s0++;
        func_8014CA80(a0, a1, a2);
        a2 = 0;
    } while (s0 < 0x1F);
}

extern void func_8001DBA8();
extern s32 D_80043708;

void func_80064D08(void) {
    do {
        func_8001DBA8(0);
        D_80173CA8 = &D_80043708;
    } while (func_8014CEB4() != 0);
}

extern void func_80043F00();
extern void func_801C3D08();
extern s32 D_800435C4;
extern s32 D_80043A90;

void func_80064D50(s32 arg0, s32 arg1) {
    func_80043F00();
    if (arg0 != 0) {
        D_80173CA8 = &D_800435C4;
        func_8014CEB4(arg0, 1);
        func_801C3D08();
    }
    if (arg1 != 0) {
        D_80173CA8 = &D_800435C4;
        func_8014CEB4(arg1, 2);
        func_801C3D08();
    }
    if (arg0 != 0) {
        D_80173CA8 = &D_80043A90;
        func_8014CEB4(1, 0x7F, 0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80064DF8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80064FA4);

extern s32 D_801D008C;
extern s32 D_801D00A0;
extern s32 D_801D00B4;
extern s8 D_801D07D4;
extern s8 D_801D07D5;

void func_800653B0(s32 arg0) {
    D_801D008C = arg0;
    D_801D00A0 = arg0;
    D_801D00B4 = arg0;
    D_801D07D4 = arg0;
    D_801D07D5 = arg0;
}

void func_800653E0(void) {
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_800653E8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80065740);

extern s32 func_8013B590();
extern s32 func_80149BEC(s32);
extern void func_8014C9D0();
extern void func_8014CA38();
extern void func_801C3C10();
extern s32 func_801C3FA4();
extern s32 D_80165EF4;
extern void *D_80173F90;
extern void *D_80173F94;
extern void *D_80173F98;
extern void *D_80173FA4;
extern s32 D_801C9FAC;
extern s32 D_801CBE74;
extern s32 D_801CBE78;
extern s32 D_801CBE7C;
extern s32 D_801CBE80;
extern s32 D_801CBEF0;
extern s32 D_801D0B34;
extern u8 D_801D71F8[];
extern u8 D_801D72C0[];
extern s32 D_801D7388[];

void func_80065AB4(void) {
    register s32 s0 asm("s0");
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    volatile s32 pad[2];

    if (func_8013B590(0x1FE) != 0) {
        func_8014C958();
    }
    v0 = func_801C3FA4();
    if (v0 == 0) {
        func_8014C958();
    }
    s1 = 0;
    a1 = (s32) &D_801CBEF0;
    v0 = D_801CBE74;
    v1 = D_801CBE78;
    v0 += a1;
    D_80173F90 = (void *) v0;
    v0 = D_801CBE7C;
    v1 += a1;
    D_80173F94 = (void *) v1;
    v1 = D_801CBE80;
    v0 += a1;
    v1 += a1;
    D_80173F98 = (void *) v0;
    D_80173FA4 = (void *) v1;
    s3 = func_80149BEC(0x10);
    func_8014C8A0(s3, (void *) &D_801C9FAC);
    a0 = s3;
    a1 = 5;
    a2 = 0;
    a3 = 0;
    func_8014CA38(s3, 5, 0, 0);
    a0 = 0xD;
    a1 = 0xD;
    a2 = 2;
    func_801C3C10(0xD, 0xD, 2);
    v0 = D_801D0B34;
    if (v0 > 0) {
        s2 = (s32) &D_801D7388;
        do {
            s0 = func_80149BEC(0x10);
            a0 = s0;
            a1 = (s32) &D_801308C0;
            USE(a1);
            v0 = *(volatile s32 *) s2;
            D_80165EF4 = v0;
            s2 += 4;
            func_8014C8A0(s0, (void *) &D_801308C0);
            a0 = s0;
            v0 = s1 << 2;
            a2 = *(s32 *) (D_801D72C0 + v0);
            a3 = *(s32 *) (D_801D71F8 + v0);
            func_8014CA38(s0, 0x1B, a2, a3);
            func_8014C9D0(s0);
            s1++;
        } while (s1 < D_801D0B34);
    }
    a0 = s3;
    a1 = 0;
    a2 = 0;
    a3 = 2;
    func_8014CA38(s3, 0, 0, 2);
    func_8014C9D0(s3);
    func_801C3C10(6, 5, 2);
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80065C78);

extern void func_801C3BA4();
extern s32 D_80136128;

void func_80065EC4(void) {
    s32 temp_v0;

    temp_v0 = func_80149BEC(0x10);
    func_8014C8A0(temp_v0, &D_80136128);
    func_8014CA38(temp_v0, 0, 0, 0);
    func_801C3BA4(0x3C);
    func_8014CA38(temp_v0, 0, 0, 1);
    func_8014C9D0(temp_v0);
    func_8014C958();
}

extern s16 D_801D71F0;
extern void func_8014CA38(s32, s32, s32, s32);

void func_80065F40(void) {
    register s32 neg asm("s1");
    register s32 one asm("s0");

    if (*(s32 *) (D_80165F98 + 0x1448) != 0) {
        neg = -1;
        one = 1;
loop:
        if (D_801D71F0 == neg) {
            goto done;
        }
        if (D_801D71F0 == one) {
            goto done;
        }
        if (D_801D71F0 == 0) {
            goto done;
        }
        func_8014CA80();
        if (*(s32 *) (D_80165F98 + 0x1448) != 0) {
            goto loop;
        }
    }
done:
    func_8014CA80();
    *(s32 *) (D_80165F98 + 0x1C4C) = 3;
    func_8014CA38(7, 0, 0, 2);
    func_8014C9D0(7);
    func_8014C9D0(5);
}

void func_8006600C(void) {
    s32 *temp_v0;

    do {
        func_8014CA80();
        temp_v0 = func_8014A578(0);
        D_801D208C = temp_v0;
    } while (!(*temp_v0 & 0x20));
}

extern void func_80133F78(s32 *, s32 *, s32 *);
extern void func_8013BC14(s32);
extern void func_801C507C();
extern s32 D_800459D0;
extern s32 D_8016600C;
extern s32 D_801BF000;
extern s16 D_80165F74;
extern s32 D_801CB31C;
extern s32 D_801CB364;
extern s32 D_801CB384;

void func_80066050(void) {
    s32 *temp_v0_2;
    s32 temp_v0;

    func_80133F78(&D_801CB31C, &D_801CB364, &D_801CB384);
loop_1:
    __asm__ volatile("" ::: "a1");
    temp_v0 = func_800444DC(D_80010010, 0x1F000);
    if (temp_v0 != D_80010010) {
        func_8014CA80();
        if (D_800459D0 == 0) {
            goto loop_1;
        }
        func_800235AC(&D_801BF000);
        __asm__ volatile(".set\tnoreorder\n\tj func_801C507C\n\tlui $a1, 0x1\n\t.set\treorder");
    }
    func_8013BC14(7);
    func_8014C858(2);
    D_8016600C = 3;
    do {
        temp_v0_2 = func_8014A578(0);
        D_801D208C = temp_v0_2;
        *temp_v0_2 = 0;
        func_8014CA80();
    } while (D_8016600C != 0);
    *D_801D208C = 0;
    func_80044600(temp_v0);
    func_8014C858(2);
    D_80165F74 = 0;
    func_8014C958();
}

extern s32 D_801C5050;

void func_80066158(void) {
    func_8014C8A0(6, &D_801C5050);
    func_8014C9D0(6);
    func_8014C958();
}

extern s32 func_8012EEB0(s32);
extern void func_8014C924(s32);
extern void func_8014C940(s32);
extern s32 func_8014CC28();
extern void func_801C3010(void *);
extern void func_801C32CC(void *);
extern s32 D_801D0B38;
extern s8 D_801D07CB;
extern u8 D_8004C6C8[];
extern u8 D_801D7450[];

void func_80066190(void) {
    register s32 s1 asm("s1");
    register s32 s2 asm("s2");
    register u8 *s3 asm("s3");
    register u8 *s4 asm("s4");
    register s32 v0 asm("v0");
    register s32 a0 asm("a0");
    s32 temp_s0;

    s1 = 0;
    s4 = D_8004C6C8;
    s3 = D_801D7450;
    func_8014C940(D_801D0B38);
    s2 = func_8012EEB0(0x400);
    func_8014BF54(s2, (D_801D0B38 << 10) + D_80165F98, 0x400);
    v0 = 2;
    D_801D07CB = v0;
    for (;;) {
        temp_s0 = s1 & 1;
        a0 = temp_s0 * 0x820;
        a0 += (s32) s4;
        func_801C32CC((void *) a0);
        a0 = temp_s0 * 0x4B0;
        a0 += (s32) s3;
        func_801C3010((void *) a0);
        func_8014CA80();
        if (func_8014CC28() == 0) {
            s1 += 1;
            continue;
        }
        break;
    }
    func_8014BF54((D_801D0B38 << 10) + D_80165F98, s2, 0x400);
    func_8012F04C(s2);
    func_8014C924(D_801D0B38);
    func_8014CA80();
    func_8014C958();
}

void func_800662C4(u8 *arg0, s32 arg1) {
    register s32 q asm("v0");
    register s32 r asm("a2");
    register s32 z asm("v1");
    register s8 y asm("a3");

    q = arg1 / 7;
    r = arg1 - q * 7;
    r <<= 5;
    KEEP_NOVOL(r);
    z = q * 3;
    z <<= 4;
    q = z + 0x28;
    y = r + 0x1F;
    z += 0x58;
    arg0[0xC] = r;
    arg0[0x1C] = r;
    arg0[0x14] = y;
    arg0[0x24] = y;
    arg0[0xD] = q;
    arg0[0x15] = q;
    arg0[0x1D] = z;
    arg0[0x25] = z;
    *(u16 *) (arg0 + 0x16) = func_8002398C(0, 0, 0x100, 0);
    *(u16 *) (arg0 + 0xE) = func_80023A54(((arg1 % 3) * 0x10) + 0x100, arg1 / 3);
}

extern void func_801C53D8();
extern void func_801C5410();

void func_800663AC(s32 arg0, s32 arg1, s32 arg2) {
    register s32 r0 asm("s0");
    register s32 r1 asm("s1");
    register s32 r2 asm("s2");
    register s32 *r3 asm("s3");

    r0 = arg0;
    r1 = arg1;
    r2 = arg2;
    r3 = &D_80044694;
    __asm__ volatile("" : "=r"(r0), "=r"(r1), "=r"(r2), "=r"(r3) : "0"(r0), "1"(r1), "2"(r2), "3"(r3));
    D_80173CA8 = r3;
    MEMORY_BARRIER();
    if (func_8014CEB4(r0, r1, r2) != 0) {
        func_8014CA80();
        TAIL_JUMP(func_801C53D8);
    }
    USE(r3);
    r0 = &D_800446C8;
    D_80173CA8 = r0;
    if (func_8014CEB4() != 0) {
        func_8014CA80();
        TAIL_JUMP(func_801C5410);
    }
    USE2(r1, r2);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80066458);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_800668D0);

extern u8 *func_80059AF0(s32);
extern u8 D_800596E0[];

s32 func_80066DD0(void) {
    register s32 index asm("a0");
    register s32 base asm("a1");
    register s32 limit asm("a2");
    s32 item_type;

    base = ((u8 * (*) ()) func_80059AF0)();
    index = 0;
    limit = 0xFF;
    do {
        item_type = *(u8 *) (base + index + 0xE);
        if ((item_type != 0) && (item_type != limit)) {
            D_800596E0[item_type]++;
        }
        index++;
    } while (index < 7);
    return 0;
}

extern u8 *func_80180AFC();
extern s32 func_8005E288(u8, s32);
extern u8 *func_8005A884(u8);
extern s32 func_8013B590(s32);

s32 func_80066E48(void) {
    register s32 i asm("s2");
    register s32 s0p asm("s0");
    register s32 v0p asm("v0");
    s32 result;
    u8 item_type;
    register u8 *p asm("s1");
    u8 *base;

    result = 0;
    base = func_80180AFC();
    i = 0;
loop_80066E48:
    MEMORY_BARRIER();
    p = base + i;
    item_type = p[0x1A];
    if (item_type == 0) {
        goto end_80066E48;
    }
    if (item_type == 0xFF) {
        goto end_80066E48;
    }
    if (func_8005E288(item_type, 1) < 0x64) {
        goto end_80066E48;
    }
    p[0x1A] = 0;
    s0p = *(u16 *) (func_8005A884(item_type) + 8);
    KEEP(s0p);
    if (s0p >= 0) {
        v0p = s0p;
    } else {
        v0p = s0p + 3;
    }
    s0p = v0p >> 2;
    func_8013B644(0x2C, func_8013B590(0x2C) + s0p);
    MEMORY_BARRIER();
    result = 1;
end_80066E48:
    i++;
    if (i < 7) {
        goto loop_80066E48;
    }
    return result;
}

extern s32 func_801C5FC8();

s32 func_80066F10(void) {
    register s32 s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 s2 asm("$18");
    register s32 s3 asm("$19");
    register s32 s4 asm("$20");
    register s32 v0 asm("$2");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    s3 = 0;
    s4 = (s32) func_80180AFC();
    USE(s4);
    s2 = 0;
    __asm__ volatile("addu $17,$20,$18" : "=r"(s1) : "r"(s4), "r"(s2));
loop:
    s0 = *(u8 *) (s1 + 0x1A);
    if (s0 == 0) {
        goto end;
    }
    if ((v0 = 0xFF, a0 = s0, s0 == v0)) {
        goto end;
    }
    a1 = 1;
    v0 = func_8005E288(a0, a1);
    if ((a0 = s0, v0 < 0x64)) {
        goto increment;
    }
    *(u8 *) (s1 + 0x1A) = 0;
    v0 = (s32) func_8005A884(a0);
    s0 = *(u16 *) (v0 + 8);
    if (s0 < 0) {
        v0 = s0 + 3;
    } else {
        v0 = s0;
    }
    s0 = v0 >> 2;
    a0 = 0x2C;
    v0 = func_8013B590(a0);
    a0 = 0x2C;
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,0x2c\n\tjal func_8013B644\n\taddu $5,$2,$16\n\t.set\treorder");
    s3 = 1;
tail:
    __asm__ volatile(".set\tnoreorder\n\tj func_801C5FC8\n\tori $19,$zero,1\n\t.set\treorder" : "=r"(s3));
increment:
    v0 = D_800596E0[s0] + 1;
    D_800596E0[s0] = v0;
end:
    s2++;
    s1 = s4 + s2;
    if (s2 < 7) {
        goto loop;
    }
    return s3;
}

extern s32 func_80059D5C(s32, u8 *);

s32 func_80067000(void) {
    s32 i;
    u8 *p;

    if (func_80180AFC()[6] & 1) {
        return 2;
    }
    i = 0;
    do {
        p = func_80059AF0(i);
        if (p[1] != 0xFF && p[0] != 0 && p[0] < 4) {
            break;
        }
        i++;
    } while (i < 0x14);
    return ~func_80059D5C(0, p + 3) != 0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_800670A0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80067988);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80068170);

s32 func_8006835C(s32 arg0, s32 arg1) {
    s32 v;
    s32 w;
    v = 0xD0;
    if (arg1 < 5) {
        return v;
    }
    w = 0x9C;
    if (arg0 & 1) {
        w = 0x104;
    }
    return w;
}

s32 func_80068384(s32 arg0, s32 arg1) {
    register s32 h asm("v1");
    register s32 x asm("v0");

    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (arg1 < 5) {
        goto mult;
    }
    h = arg0 / 2;
    x = h * 4;
    __asm__ volatile(".set\tnoreorder\n\t"
                     "j func_801C73AC\n\t"
                     "addu $2,$2,$3\n\t"
                     ".set\treorder\n\t" ::"r"(x),
                     "r"(h));
mult:
    __asm__(".set\treorder\n\t");
    return arg0 * 0x14 + 0x78;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_800683B8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80068B78);

void func_80069B94(u8 *arg0, s32 arg1, u8 *arg2) {
    s32 t0;
    s32 t1;
    s32 t2;

    t0 = (s32) arg0[0x4] * arg1 / 128;
    t1 = (s32) arg0[0x5] * arg1 / 128;
    t2 = (s32) arg0[0x6] * arg1 / 128;
    arg2[0x4] = t0;
    arg2[0x5] = t1;
    arg2[0x6] = t2;

    t0 = (s32) arg0[0x8] * arg1 / 128;
    t1 = (s32) arg0[0x9] * arg1 / 128;
    t2 = (s32) arg0[0xA] * arg1 / 128;
    arg2[0x10] = t0;
    arg2[0x11] = t1;
    arg2[0x12] = t2;

    t0 = (s32) arg0[0xC] * arg1 / 128;
    t1 = (s32) arg0[0xD] * arg1 / 128;
    t2 = (s32) arg0[0xE] * arg1 / 128;
    arg2[0x1C] = t0;
    arg2[0x1D] = t1;
    arg2[0x1E] = t2;

    t0 = (s32) arg0[0x10] * arg1 / 128;
    t1 = (s32) arg0[0x11] * arg1 / 128;
    t2 = (s32) arg0[0x12] * arg1 / 128;
    arg2[0x28] = t0;
    arg2[0x29] = t1;
    arg2[0x2A] = t2;
}

extern s32 func_800245BC();
extern void func_80023D44();
extern void func_80023C90();
extern void func_80023C68();
extern u8 D_8004CD48[];
extern u16 D_801D0072[];

void func_80069D38(s32 arg0, s32 arg1) {
    register s32 keep0 asm("s5") = arg0;
    register s32 keep1 asm("s6") = arg1;
    s32 i = 0;
    s32 one = 1;
    u16 *tab = D_801D0072;
    s32 off = 0;
    EventRecord34 *p;
    s32 v1t;
    s32 v0t;
    do {
        p = (EventRecord34 *) (D_8004C6C8 + off);
        func_80023D44(p);
        func_80023C90(p, 0);
        func_80023C68(p, 1);
        p->f0C[0] = 0;
        p->f0C[1] = 0;
        p->f18[0] = one;
        p->f18[1] = 0;
        p->f24[0] = 0;
        p->f24[1] = one;
        p->f30[0] = one;
        p->f30[1] = one;
        p->f08 = 0;
        p->f0A = 0;
        p->f14 = 0;
        p->f16 = 0;
        p->f20 = 0;
        p->f22 = 0;
        p->f2C = 0;
        p->f2E = 0;
        if (func_800245BC() != one) {
            func_800245BC();
        }
        off += 0x34;
        p->f1A = 6;
        i++;
        v1t = tab[0] + keep1;
        v1t <<= 6;
        v0t = (((s16 *) tab)[-1] + keep0) >> 4;
        v0t &= 0x3F;
        v1t |= v0t;
        p->f0E = v1t;
    } while (i < 0x20);
}

void func_80069E5C(s32 arg0, s32 arg1) {
    register s32 keep0 asm("s5") = arg0;
    register s32 keep1 asm("s6") = arg1;
    s32 i = 0;
    s32 one = 1;
    u16 *tab = D_801D0072;
    s32 off = 0;
    EventRecord34 *p;
    s32 v1t;
    s32 v0t;
    do {
        p = (EventRecord34 *) (D_8004CD48 + off);
        func_80023D44(p);
        func_80023C90(p, 0);
        func_80023C68(p, 1);
        p->f0C[0] = 0;
        p->f0C[1] = 0;
        p->f18[0] = one;
        p->f18[1] = 0;
        p->f24[0] = 0;
        p->f24[1] = one;
        p->f30[0] = one;
        p->f30[1] = one;
        p->f08 = 0;
        p->f0A = 0;
        p->f14 = 0;
        p->f16 = 0;
        p->f20 = 0;
        p->f22 = 0;
        p->f2C = 0;
        p->f2E = 0;
        if (func_800245BC() != one) {
            func_800245BC();
        }
        off += 0x34;
        p->f1A = 6;
        i++;
        v1t = tab[0] + keep1;
        v1t <<= 6;
        v0t = (((s16 *) tab)[-1] + keep0) >> 4;
        v0t &= 0x3F;
        v1t |= v0t;
        p->f0E = v1t;
    } while (i < 0x8);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_80069F80);

void func_8006AFA4(void) {
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_8006AFAC);

void func_8006B644(void) {
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_8006B664);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/REQUIRE", func_8006BFD4);

extern void func_80149D48(s32);
extern void func_8014C8A0(s32, s32 *);
extern void func_801CB190();
extern s32 D_80165FB4;
extern s32 D_801DFE10;

void func_8006C15C(void) {
    s32 temp_v0;

    func_80149D48(0x40);
    D_80165FB4 = 1;
    D_801D07D4 = 1;
    D_801D07D5 = 1;
    MEMORY_BARRIER();
    if (func_800444DC(D_80010010, 0x10000) != D_80010010) {
        func_8014CA80();
        TAIL_JUMP(func_801CB190);
    }
    func_8013BC14(3);
    temp_v0 = func_80149BEC(0x10);
    func_8014C8A0(temp_v0, &D_801DFE10);
    func_8014C9D0(temp_v0);
    D_801D07D4 = 0;
    D_801D07D5 = 0;
    func_8014C958();
}

extern u8 *D_80173FAC;
extern void func_801CB29C(u8 *);
extern u8 *func_80180AFC(s32);

void func_8006C21C(void) {
    register u8 *var_s0 asm("s0");
    register s32 var_s1 asm("s1");
    register s32 mask asm("s2");
    register s32 limit asm("s3");
    register s32 var_v1 asm("v1");
    register u8 *base asm("a0");
    u8 *var_v0;
    u8 temp_v0_2;

    var_s0 = D_80173FAC;
    var_s1 = 0;
    mask = 0xFE;
    limit = 0xF;
loop_1:
    base = func_80180AFC(var_s1);
    var_v1 = 0;
loop_2:
    var_v0 = base + var_v1;
    temp_v0_2 = var_v0[0x12C];
    *var_s0 = temp_v0_2;
    if ((temp_v0_2 & 0xFE) == mask) {
        __asm__ volatile(".set\tnoreorder\n\tj func_801CB29C\n\taddiu %0, %0, 1\n\t.set\treorder"
                         : "=r"(var_s0) : "0"(var_s0));
    }
    var_s0++;
    if (var_v1 == limit) {
        *var_s0 = mask;
        var_s0 += 1;
    }
    var_v1 += 1;
    var_v0 = base + var_v1;
    if (var_v1 >= 0x10) {
        var_s1 += 1;
        if (var_s1 < 0x15) {
            goto loop_1;
        }
        return;
    }
    goto loop_2;
}
