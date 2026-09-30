#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80060008);

extern void func_8014BF54();
extern u8 D_801C5650[];

void func_800601D0(EventCoord28 *arg0) {
    *(u16 *) &arg0->at_1C = 0;
    *(u16 *) &arg0->pad_26[0] = 0;
    func_8014BF54((u8 *) &arg0->at_20, D_801C5650, 8);
}

void func_80060204(u16 *arg0, u32 arg1) {
    arg0[0] = (arg1 & 0x3F) << 4;
    arg0[1] = (arg1 & 0xFFFF) >> 6;
    arg0[2] = 0x10;
    arg0[3] = 1;
}

extern void func_80136BD0();

void func_80060230(s32 arg0, s32 arg1) {
    if (!(arg0 & 0x300)) {
        func_80136BD0(arg1, arg0);
    }
}

void func_80060260(u8 *arg0, s32 arg1) {
    s32 t0;
    s32 t1;
    s32 u0;
    s32 u1;

    if (arg0[0xC] != arg0[0x14]) {
        MEMORY_BARRIER();
        t0 = arg0[0xC] + arg1;
        t1 = arg0[0x1C] + arg1;
        arg0[0xC] = t0;
        TAIL_JUMP_SB_1C(func_801BF2A8, t1, arg0, t0);
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

void func_800602C4(u8 *arg0, s32 arg1) {
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
        TAIL_JUMP_SB_24(func_801BF320, s24, arg0, s14);
    }
    delta_15 = ((u8 *) &r->f14)[1] - arg1;
    delta_25 = r->f24[1] - arg1;
    ((u8 *) &r->f14)[1] = delta_15;
    r->f24[1] = delta_25;
    MEMORY_BARRIER();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80060328);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80060750);

void func_8006190C(void) {
}

extern void func_80023C68(void *, s32);
extern void func_80023DD0(void *);
extern void func_80023DE4(void *);
extern void func_8014A6E4(void *, s32);

void func_80061914(u8 *arg0) {
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

void func_80061B34(void) {
    func_8014CA80();
    func_8014C958();
}

void func_80061B5C(void) {
    func_8014CA80();
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80061B84);

extern void func_80023C90(void *, s32);
extern void func_801C1464();
extern s32 D_80166028;

void func_80062310(u8 *arg0, u8 *arg1) {
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
    TAIL_JUMP(func_801C1464);
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

void func_8006248C(s32 arg0, u8 *arg1) {
    if (*(s32 *) (arg1 + 0x10) == 1 || D_80166028 == 1) {
        func_8012F454();
        TAIL_JUMP(func_801C14D0);
    }
    func_8012F3CC();
}

extern void func_801C1590(s16);
extern void func_801C1598(s16);
extern void func_801C16E0(s32, s32, s32, void *);

void func_800624E0(s32 arg0, u8 *arg1, void *arg2, s32 arg3) {
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
            __asm__ volatile("\t.set\tnoreorder\n\tlhu $2,0($16)\n\tj func_801C1590\n\tnegu $4,$4\n\t.set\treorder" : : "r"(a0) : "memory");
        }
        if (a0 > 0) {
            v0 = 0xCCCCCCCC;
            *(volatile u32 *) (s1 + 0xC) = v0;
            __asm__ volatile("\t.set\tnoreorder\n\tlhu $2,0($16)\n\tj func_801C1598\n\tori $2,$2,0x400\n\t.set\treorder" ::: "memory");
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
        func_801C16E0(a0, a1, a2, s1);
        *(u32 *) (s1 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

extern void func_801C1694(s16, s32);

void func_800625EC(s32 arg0, u8 *arg1, void *arg2, s32 arg3) {
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
    s0 = (u8 *) arg2;
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
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1694\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        if (a0 > 0) {
            a1 |= 0x400;
            v0 = 0xBBBBBBBB;
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1694\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        *(volatile u32 *) (s0 + 0xC) = 0;
        MEMORY_BARRIER();
        a1 &= 0xFFF0;
        a1 |= 0x804;
        a2 = s5;
        func_801C16E0(a0, a1, a2, s0);
        s1 += 0xC;
        s3 += 0xC;
        s2++;
        *(u32 *) (s0 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_800626E0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_800629E4);

extern s32 func_8014A578(s32);
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
extern void func_8014BF54(void *, void *, s32);
extern s32 func_8014C4A8(s16, s16, void *, s32);
extern s32 D_80165F8C;
extern s32 D_80165FA8;
extern s32 D_801C6DEC;

void func_80062F48(void) {
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

    D_801C6DEC = func_8014A578(0);
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
    func_8014BF54(&stack.sp94, &stack.sp18, 0x7C);
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
    a0 = D_801C6DEC;
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
        TAIL_JUMP_MEM(func_801C1FF8);
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

void func_80063138(void) {
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
    D_801C6DEC = ptr;
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

void func_80063230(void) {
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
        __asm__ volatile(".set\tnoreorder\n\tj func_801C2298\n\taddiu %0,%0,0x1\n\t.set\treorder" : "=r"(s1));
    }
    func_8014CA80();
    func_8014C958();
}

extern void func_80136B10(u8 *);

void func_800633A4(u8 *arg0) {
    u8 buf[24];

    func_80136B10(buf);
    *(u16 *) arg0 = buf[0xC];
    *(u16 *) (arg0 + 2) = buf[0xD];
    *(u16 *) (arg0 + 4) = 0x10;
    *(u16 *) (arg0 + 6) = 0x10;
    *(u16 *) (arg0 + 8) = *(u16 *) (buf + 0xE);
    *(u16 *) (arg0 + 0xA) = func_8002398C(0, 0, 0x380, 0x120);
}

void func_8006340C(void) {
}

s32 func_80063414(s32 arg0) {
    arg0 <<= 10;
    return *(s32 *) (arg0 + D_80165F98 + 0x48);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80063430);

void func_80063904(u8 *arg0) {
    u8 val;
    s32 i;
    u8 *p;
    val = 0xFE;
    p = arg0;
    for (i = 0xF; i >= 0; i--) {
        *p = val;
        p++;
    }
}

extern s32 func_8008CBB4(s32);
extern s32 func_8008CDD0(s32);
extern s16 func_8014CEB4(void *);
extern void *func_80180AFC(s32);
extern void func_80180C90(u8, s32 *);
extern volatile s32 D_80173CA8;
extern s32 D_801834BC;

void func_80063924(u8 *arg0, u16 *arg1) {
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80063AF0);

void func_80064034(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80064278);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80064534);

void func_800646C4(u8 *arg0, u16 *arg1, u16 *arg2, u8 *arg3, s16 *arg4, u16 *arg5) {
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
extern void func_801C36C4(void *, void *, void *, void *, EventDrawArgs);
extern u8 D_801C66D4[];
extern u8 D_801C6830[];
extern u8 D_801C6832[];
extern u8 D_801C68A5;
extern u8 D_801CE2DC[];

void func_80064994(u8 *arg0, u8 *arg1) {
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
    v0 = D_801C68A5;
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
    a2 = *(s16 *) (D_801C6830 + s3);
    v0 = *(s16 *) (arg0 + 0xC);
    a2 = a2 * v0;
    v1 = *(s16 *) (D_801C6832 + s3);
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
    c1 = (s32) D_801CE2DC;
    buf[0] = a2;
    buf[1] = v1;
    args = (EventDrawArgs *) ((u8 *) buf - 8);
    v0 = (s32) buf;
    args->coords = (s16 *) v0;
    MEMORY_BARRIER();
    v0 = (s32) (arg0 + 0x18);
    args->extra = (u8 *) v0;
    table = D_801C66D4;
    a2 = (s32) D_801C5650 + ((s32) table - (s32) table);
    func_801C36C4((u8 *) c0, (u8 *) c1, (u8 *) a2, table + s5, *args);
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
    if (s4 < D_801C68A5) {
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

extern void *func_80180AFC();
extern s16 D_801C52E8[];
extern s16 D_801C52EC;
extern s16 D_801C52F2;
extern s16 D_801C52F8;
extern u8 D_801C52DC;
extern u8 D_801C52E4;
extern u8 D_801C5328;
extern u8 D_801C532A;
extern s16 D_801C532C;
extern u8 D_801C5344;
extern u8 D_801C5346;
extern u8 D_801C5348;

void func_80064C48(void) {
    register u8 *a0 asm("a0");
    register s32 a2 asm("$6");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a1 asm("a1");
    s32 unused[6];

    a0 = (u8 *) ((void *(*) ()) func_80180AFC)();
    KEEP(a0);
    a2 = (s32) D_801C52E8;
    KEEP(a2);
    v0 = D_801C52EC;
    v1 = *(s16 *) (a2 + 0);
    a1 = v0;
    v0 = v0 < v1;
    if (v0 == 0) {
        goto skip0;
    }
    *(s16 *) (a2 + 0) = a1;
skip0:
    v0 = D_801C52F2;
    v1 = *(s16 *) (a2 + 6);
    a1 = v0;
    v0 = v0 < v1;
    if (v0 == 0) {
        goto skip1;
    }
    *(s16 *) (a2 + 6) = a1;
skip1:
    v0 = D_801C52F8;
    v1 = *(s16 *) (a2 + 12);
    a1 = v0;
    v0 = v0 < v1;
    if (v0 == 0) {
        goto skip2;
    }
    *(s16 *) (a2 + 12) = a1;
skip2:
    v0 = *(u16 *) (a2 + 0);
    *(u16 *) (a0 + 0x28) = v0;
    v0 = *(u16 *) (a2 + 6);
    *(u16 *) (a0 + 0x2C) = v0;
    v0 = *(u8 *) (a2 + 12);
    *(u8 *) (a0 + 0x39) = v0;
    v0 = D_801C52DC;
    *(u8 *) (a0 + 0x22) = v0;
    v0 = D_801C52E4;
    *(u8 *) (a0 + 0x21) = v0;
    v0 = D_801C5328;
    *(u8 *) (a0 + 0x24) = v0;
    v0 = D_801C532A;
    *(u8 *) (a0 + 0x26) = v0;
    v1 = D_801C532C;
    v0 = *(u16 *) (a0 + 8);
    v1 <<= 12;
    v0 &= 0xFFF;
    v0 |= v1;
    *(u16 *) (a0 + 8) = v0;
    v0 = D_801C5344;
    *(u8 *) (a0 + 0x3A) = v0;
    v0 = D_801C5346;
    *(u8 *) (a0 + 0x38) = v0;
    v0 = D_801C5348;
    *(u8 *) (a0 + 0x3B) = v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_80064D84);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/DEBUGCHR", func_8006538C);
