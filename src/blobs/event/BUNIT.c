#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006020C);

extern void func_8014BF54();
extern u8 D_801CEC70[];

void func_800603D4(u8 *arg0) {
    *(u16 *) (arg0 + 0x1C) = 0;
    *(u16 *) (arg0 + 0x26) = 0;
    func_8014BF54(arg0 + 0x20, D_801CEC70, 8);
}

void func_80060408(u16 *arg0, u32 arg1) {
    arg0[0] = (arg1 & 0x3F) << 4;
    arg0[1] = (arg1 & 0xFFFF) >> 6;
    arg0[2] = 0x10;
    arg0[3] = 1;
}

extern void func_80136BD0();

void func_80060434(s32 arg0, s32 arg1) {
    if (!(arg0 & 0x300)) {
        func_80136BD0(arg1, arg0);
    }
}

void func_80060464(u8 *arg0, s32 arg1) {
    s32 t0;
    s32 t1;
    s32 u0;
    s32 u1;

    if (arg0[0xC] != arg0[0x14]) {
        MEMORY_BARRIER();
        t0 = arg0[0xC] + arg1;
        t1 = arg0[0x1C] + arg1;
        arg0[0xC] = t0;
        TAIL_JUMP_SB_1C(func_801BF4AC, t1, arg0, t0);
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

void func_800604C8(u8 *arg0, s32 arg1) {
    u8 c = arg0[0xC];
    s32 t8 = *(u16 *) (arg0 + 8) + arg1;
    s32 t18;
    s32 s14;
    s32 s24;
    s32 m15;
    s32 m25;

    *(u16 *) (arg0 + 8) = t8;
    t18 = *(u16 *) (arg0 + 0x18) + arg1;
    *(u16 *) (arg0 + 0x18) = t18;
    if (c != arg0[0x14]) {
        MEMORY_BARRIER();
        s14 = arg0[0x14] - arg1;
        s24 = arg0[0x24] - arg1;
        arg0[0x14] = s14;
        TAIL_JUMP_SB_24(func_801BF524, s24, arg0, s14);
    }
    m15 = arg0[0x15] - arg1;
    m25 = arg0[0x25] - arg1;
    arg0[0x15] = m15;
    arg0[0x25] = m25;
    MEMORY_BARRIER();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006052C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80060954);

void func_80061ADC(void) {
}

extern void func_80023DD0(void *);
extern void func_80023DE4(void *);
extern void func_80023C68(void *, s32);
extern void func_8014A6E4();

void func_80061AE4(u8 *arg0) {
    register u8 *s0 asm("s0");
    register s32 s1 asm("s1");
    register EventInitBlock *s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a2 asm("a2");
    register s32 a0 asm("a0");
    register s32 a1 asm("a1");

    s2 = (EventInitBlock *) arg0;
    s0 = (u8 *) &s2->first;
    func_80023DD0(s0);
    s1 = (s32) (u8 *) &s2->second;
    func_80023DD0((u8 *) s1);
    func_80023C68(s0, 1);
    func_80023C68((u8 *) s1, 1);
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
    a0 = s2;
    a1 = 0;
    asm volatile("" : "=r"(a0), "=r"(a1) : "0"(a0), "1"(a1));
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
    v0 = 0x22;
    s2->entries[0].at_0A = a2;
    s2->entries[0].at_0E = v1;
    s2->entries[1].at_0A = a2;
    s2->entries[1].at_0E = v1;
    s2->entries[2].at_08 = v0;
    s2->entries[2].at_0A = a2;
    s2->entries[2].at_0C = v0;
    v0 = 0x23;
    s2->entries[3].at_08 = v0;
    s2->entries[3].at_0C = v0;
    v0 = 0x7A;
    s2->entries[4].at_08 = v0;
    s2->entries[4].at_0C = v0;
    v0 = 0x7B;
    s2->entries[5].at_08 = v0;
    s2->entries[5].at_0C = v0;
    v0 = 0x8C;
    s2->entries[6].at_08 = v0;
    s2->entries[6].at_0C = v0;
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
    func_8014A6E4((u8 *) a0, a1, a2);
    a0 = (s32) ((u8 *) s2 + 0xC);
    a1 = 2;
    func_8014A6E4((u8 *) a0, a1);
    a0 = (s32) ((u8 *) s2 + 0x18);
    a1 = 4;
    func_8014A6E4((u8 *) a0, a1);
}

extern void func_8014CA80();
extern void func_8014C958();

void func_80061D04(void) {
    func_8014CA80();
    func_8014C958();
}

void func_80061D2C(void) {
    func_8014CA80();
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80061D54);

extern void func_80023C90(void *, s32);
extern void func_801C1628();
extern s32 D_80166028;

void func_800624D4(u8 *arg0, u8 *arg1) {
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
    TAIL_JUMP(func_801C1628);
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

void func_80062650(s32 arg0, u8 *arg1) {
    if (*(s32 *) (arg1 + 0x10) == 1 || D_80166028 == 1) {
        func_8012F454();
        TAIL_JUMP(func_801C1694);
    }
    func_8012F3CC();
}

extern void func_801C1754(s16, s32);
extern void func_801C175C(s16, s32);
extern void func_801C18A4(s32, s32, s32, void *);

void func_800626A4(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
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
            __asm__ volatile("\t.set\tnoreorder\n\tlhu $2,0($16)\n\tj func_801C1754\n\tnegu $4,$4\n\t.set\treorder" : : "r"(a0) : "memory");
        }
        if (a0 > 0) {
            v0 = 0xCCCCCCCC;
            *(volatile u32 *) (s1 + 0xC) = v0;
            __asm__ volatile("\t.set\tnoreorder\n\tlhu $2,0($16)\n\tj func_801C175C\n\tori $2,$2,0x400\n\t.set\treorder" ::: "memory");
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
        func_801C18A4(a0, a1, a2, s1);
        *(u32 *) (s1 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

extern void func_801C1858(s16, s32);

void func_800627B0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
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
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1858\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        if (a0 > 0) {
            a1 |= 0x400;
            v0 = 0xBBBBBBBB;
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1858\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        *(volatile u32 *) (s0 + 0xC) = 0;
        MEMORY_BARRIER();
        a1 &= 0xFFF0;
        a1 |= 0x804;
        a2 = s5;
        func_801C18A4(a0, a1, a2, s0);
        s1 += 0xC;
        s3 += 0xC;
        s2++;
        *(u32 *) (s0 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_800628A4);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80062BA8);

extern void func_8012F04C(s32);
extern void func_80137C10(void *, s32);
extern void func_80137ED4(void *, s32 *);
extern void func_80137F84(void *);
extern s32 func_80138094(s32);
extern void func_80138174(void *, void *, void *);
extern void func_80138460(void *);
extern void func_80138570(void *, void *, s32, s32);
extern void func_80138B10(void *);
extern s32 *func_8014A578(s32);
extern void func_8014A6CC(s32, s32);
extern void func_8014B2F0(s16, s32, s32 *);
extern s32 func_8014C4A8(s16, s16, void *, s32);
extern u8 *func_8014CBC0();
extern s32 D_80165F8C;
extern s32 D_80165FA8;
extern s32 *D_801E3C40;

void func_80063100(void) {
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

    D_801E3C40 = func_8014A578(0);
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
    a0 = D_801E3C40;
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
        TAIL_JUMP(func_801C21B0);
    }
    func_8014CA80();
    func_8014C958();
}

extern s32 D_80174038;
extern s32 D_80165F98;
extern s32 D_801308C0;
extern void func_8014C9D0(s32);
extern void func_8014CA58(s32, s32, s32, s32, s32);
extern void func_8014C8A0(s32, void *);

void func_800632F0(void) {
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
    D_801E3C40 = ptr;
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
    return;
}

void func_800633E8(void) {
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
        __asm__ volatile(".set\tnoreorder\n\tj func_801C2450\n\taddiu %0,%0,0x1\n\t.set\treorder" : "=r"(s1));
    }
    func_8014CA80();
    func_8014C958();
}

extern void func_80136B10(u8 *);

void func_8006355C(u8 *arg0) {
    u8 buf[24];

    func_80136B10(buf);
    *(u16 *) arg0 = buf[0xC];
    *(u16 *) (arg0 + 2) = buf[0xD];
    *(u16 *) (arg0 + 4) = 0x10;
    *(u16 *) (arg0 + 6) = 0x10;
    *(u16 *) (arg0 + 8) = *(u16 *) (buf + 0xE);
    *(u16 *) (arg0 + 0xA) = func_8002398C(0, 0, 0x380, 0x120);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_800635C4);

s32 func_80063948(s32 arg0) {
    return *(s32 *) (((arg0 << 0xA) + D_80165F98) + 0x48);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80063964);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80063E38);

extern s32 func_8014CA1C();
extern s32 func_801C66E0();
extern s32 D_801CF4C0;
extern u8 D_801CF50D;
extern u16 D_801ECA0C;
extern s32 D_801ECAD0;
extern s32 D_801ECB50;

void func_800640A8(void) {
    register s32 v0 asm("$2");

    v0 = 0xA;
    if (func_8014CA1C(7) != 0) {
        v0 = 0xA;
        goto set;
    }
    v0 = 0xA;
    v0 = D_801CF4C0;
    v0 &= 0x60;
    if (v0 != 0) {
        v0 = 0xA;
        goto set;
    }
    v0 = 0xA;
    if (func_801C66E0() != 0) {
        v0 = 0xA;
        goto set;
    }
    v0 = D_801CF50D;
    if (v0 == 0) {
        goto end;
    }
    v0 = v0 - 1;
set:
    D_801CF50D = v0;
    if (D_801CF50D != 0) {
        D_801ECA0C = 0;
        D_801ECB50 = 0;
        D_801ECAD0 = 0;
    }
end:;
}

__asm__(".text\n\t.set noat\n\t.set noreorder\n\tlui $2,%hi(D_801CF50D)\n\tlbu $2,%lo(D_801CF50D)($2)\n\tjr $31\n\tnop\n\t.set at\n");

s32 func_8001DB58();
s32 func_801C3140();

s32 func_80064150(void) {
    s32 v;

    v = func_8001DB58(0);
    if (func_801C3140() != 0) {
        v = 0;
    }
    return v;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80064190);

extern s16 D_801EB152;
extern s16 D_801EB150;

void func_800645F0(void) {
    D_801EB150 = -1;
    D_801EB152 = -1;
}

extern s32 func_8014CA1C(s32);

s32 func_8006460C(void) {
    s32 s0 = 0;

    if (func_8014CA1C(0xF) != 0) {
        goto set1;
    }
    if (D_80166028 != 0) {
        goto set1;
    }
    if (func_8014CA1C(5) == 0) {
        goto out;
    }
set1:
    s0 = 1;
out:
    return s0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006466C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80064A68);

extern void func_800222DC(s32, void *, s32);
extern s32 D_801ECAF8[];
extern u8 D_801CE8FC[];
extern u8 D_801CE944[];
extern u8 D_801CE964[];
extern s16 D_801CF450;
extern u16 D_801CF452;
extern s32 D_801CF4C4;
extern s32 D_801CF4D8;
extern s32 D_801CF4EC;
extern s32 D_801CF500;

void func_80064E18(void) {
    u16 first;
    s32 p;
    volatile s32 unused;

    first = D_801CF450;
    p = *(s32 *) ((u8 *) D_801ECAF8 + (((s32) (first << 16)) >> 14));
    D_801CF452 = first;
    func_800222DC(p, D_801CE8FC, 0x22);
    func_800222DC(*(s32 *) ((u8 *) D_801ECAF8 + ((s32) (s16) D_801CF450 * 4)) + 0x22, D_801CE944, 0xE);
    func_800222DC(*(s32 *) ((u8 *) D_801ECAF8 + ((s32) (s16) D_801CF450 * 4)) + 0x30, D_801CE964, 0x40);
    D_801CF4C4 = 1;
    D_801CF4D8 = 1;
    D_801CF4EC = 1;
    D_801CF500 = 1;
}

extern void func_8014C8A0();
extern void func_8014CA38();
extern void func_801CBA14();
extern u8 D_801BF954[];
extern u8 D_801CF4B8[];

void func_80064EE0(s32 arg0) {
    if (arg0 == 0) {
        goto L_then;
    }
    if (func_8014CA1C(8) != 0) {
        goto L_epi;
    }
    func_8014C8A0(8, D_801BF954);
    func_8014CA38(8, D_801CF4B8, 0, 0);
    TAIL_JUMP(func_801C3F34);
L_then:
    func_801CBA14(8);
L_epi:;
}

extern u8 D_801CF4CC[];

void func_80064F44(s32 arg0) {
    if (arg0 == 0) {
        goto L_then;
    }
    if (func_8014CA1C(7) != 0) {
        goto L_epi;
    }
    func_8014C8A0(7, D_801BF954);
    func_8014CA38(7, D_801CF4CC, 0, 0);
    TAIL_JUMP(func_801C3F98);
L_then:
    func_801CBA14(7);
L_epi:;
}

extern u8 D_801C0D54[];
extern u8 D_801CF4E0[];
extern u8 D_801C1BA8[];
extern u8 D_801CF4F4[];
extern void func_801CBA14(s32);

void func_80064FA8(s32 arg0) {
    s32 v;

    if (arg0 != 0) {
        v = D_801CF4C0;
        if (v & 0x60) {
            goto out;
        }
        v = func_8014CA1C(9);
        if (v != 0) {
            goto out;
        }
        func_8014C8A0(9, D_801C0D54);
        func_8014CA38(9, D_801CF4E0, 0, 0);
        func_8014C8A0(0xC, D_801C1BA8);
        func_8014CA38(0xC, D_801CF4F4, 0, 0);
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801C4044\n\t"
                         "nop\n\t"
                         ".set\treorder\n\t");
    }
    func_801CBA14(9);
    func_801CBA14(0xC);
out:
    return;
}

extern u8 D_801CF557[];
extern s16 D_801EB204;

s32 func_80065054(s32 arg0) {
    register s32 idx asm("$2");
    register s32 f asm("$3");
    register s16 a1r asm("$5");
    register s32 p asm("$2");
    register s32 k asm("$2");
    u8 *q;

    f = D_801CF557[0];
    ASM_NOP();
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (f != 0) {
        goto second;
    }
    __asm__ volatile("sll $2,$4,2");
    q = *(u8 **) ((u8 *) D_801ECAF8 + idx);
    __asm__ volatile("lh %0,12(%1)" : "=r"(a1r) : "r"(q));
    __asm__ volatile("j func_801C40D0\n\t"
                     "nop\n\t" ::"r"(a1r));
second:
    __asm__ volatile("ori %0,$zero,1" : "=r"(k));
    if (f != k) {
        goto third;
    }
    __asm__ volatile("sll $2,$4,2");
    q = *(u8 **) ((u8 *) D_801ECAF8 + idx);
    __asm__ volatile("lh %0,18(%1)" : "=r"(a1r) : "r"(q));
    __asm__ volatile("j func_801C40D0\n\t"
                     "nop\n\t" ::"r"(a1r));
third:
    __asm__ volatile("ori %0,$zero,2" : "=r"(k));
    if (f != k) {
        goto store;
    }
    ASM_NOP();
    __asm__ volatile("sll $2,$4,2");
    q = *(u8 **) ((u8 *) D_801ECAF8 + idx);
    __asm__ volatile("lh %0,24(%1)" : "=r"(a1r) : "r"(q));
store:
    D_801EB204 = a1r;
    __asm__(".set\treorder\n\t");
    return a1r;
}

s32 func_800650E4(s32 arg0) {
    return ((s16 *) D_801ECAF8[arg0])[0];
}

s32 func_80065104(s32 arg0) {
    return ((s16 *) D_801ECAF8[arg0])[4];
}

s32 func_80065124(s32 arg0) {
    return ((s16 *) D_801ECAF8[arg0])[19];
}

s32 func_80065144(s32 arg0) {
    return ((s16 *) D_801ECAF8[arg0])[20];
}

extern s16 D_801EB208;

s32 func_80065164(s32 arg0) {
    register s32 idx asm("$2");
    register s32 f asm("$3");
    register s16 a1r asm("$5");
    register s32 p asm("$2");
    register s32 k asm("$2");
    u8 *q;

    f = D_801CF557[0];
    ASM_NOP();
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (f != 0) {
        goto second;
    }
    __asm__ volatile("sll $2,$4,2");
    q = *(u8 **) ((u8 *) D_801ECAF8 + idx);
    __asm__ volatile("lh %0,16(%1)" : "=r"(a1r) : "r"(q));
    __asm__ volatile("j func_801C41CC\n\t"
                     "nop\n\t" ::"r"(a1r));
second:
    __asm__ volatile("ori %0,$zero,1" : "=r"(k));
    if (f != k) {
        goto third;
    }
    __asm__ volatile("sll $2,$4,2");
    q = *(u8 **) ((u8 *) D_801ECAF8 + idx);
    __asm__ volatile("lh %0,22(%1)" : "=r"(a1r) : "r"(q));
    __asm__ volatile("j func_801C41CC\n\t"
                     "nop\n\t" ::"r"(a1r));
third:
    k = 2;
    if (f != k) {
        goto store;
    }
    ASM_NOP();
    a1r = 100;
store:
    D_801EB208 = a1r;
    __asm__(".set\treorder\n\t");
    return a1r;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_800651E0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_800652A0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_800653B4);

extern void func_801C845C();
extern void func_801C8408(s32);
extern u8 func_801C41E0(s8);
extern void func_801C4738();
extern void func_801C5A78();
extern u8 D_801C4054[];
extern u8 D_801C40E4[];
extern u8 D_801C4104[];
extern u8 D_801C4124[];
extern u8 D_801C4144[];
extern u8 D_801C4164[];
extern s32 D_801ECB70;
extern s32 D_801ECB74;
extern s32 D_801ECB80;
extern s32 D_801ECB84;
extern s32 D_801ECB88;
extern s32 D_801ECB8C;
extern s32 D_801CF4BC;
extern u8 D_801CF508;
extern u8 D_801CF509;
extern s8 D_801CF50B;

void func_80065670(void) {
    u8 temp;

    func_801C845C(0, 0, 0);
    D_801ECB70 = &D_801C4054;
    D_801ECB74 = &D_801C4164;
    D_801ECB80 = &D_801C40E4;
    D_801ECB84 = &D_801C4104;
    D_801ECB88 = &D_801C4124;
    D_801ECB8C = &D_801C4144;
    func_801C8408(0);
    temp = func_801C41E0(D_801CF50B);
    D_801CF508 = temp;
    D_801CF509 = temp;
    if (D_801CF508 != 0) {
        D_801CF4BC = 0x90;
        TAIL_JUMP(func_801C4738);
    }
    D_801CF4BC = 0;
    func_801C5A78();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80065750);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_800667C0);

extern s32 func_8001BE1C(s32);

s32 func_80066808(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v0;
    s32 v1;
    s32 a0;
    s32 s0;
    s32 s1;

    s0 = arg2;
    s1 = arg3;
    __asm__ volatile("mflo %0" : "=r"(v0));
    a0 = v0 + v1;
    a0 <<= 12;
    v0 = func_8001BE1C(a0) >> 12;
    v1 = s0 - v0;
    v0 = v1 < s1;
    if (v0 != 0) {
        v1 = s1;
    }
    v0 = v1;
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80066864);

extern u8 D_801EB20C[];
extern s16 D_801CF87E;
extern s16 D_801CF892;

void func_80066A78(void) {
    s32 fill = -1;
    s32 i = 0x1C;

    do {
        *(s16 *) (D_801EB20C + i) = fill;
        i -= 4;
    } while (i >= 0);
    D_801CF87E = func_8002398C(0, 2, 0x3C0, 0x100);
    D_801CF892 = func_8002398C(0, 1, 0x3C0, 0x100);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80066AE4);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80066E78);

extern void func_801C62F4();
extern s8 func_801C7148(s16);
extern u8 D_801EB154;
extern u8 D_801EB1F0[];

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_80067274\nfunc_80067274:\n\tlui $2,%hi(D_801EB154)\n\tlbu $2,%lo(D_801EB154)($2)\n\t.set at\n");

void func_80067274_body(void) {
    register u8 *s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 *s2 asm("$18");
    register s32 s3 asm("$19");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    s32 dummy;

    (void) &dummy;
    FORCE_REG_NOVOL(v0);
    s3 = 0;
    KEEP_NOVOL(s3);
    s1 = 0;
    if (v0 <= 0) {
        goto end;
    }
    s0 = D_801EB1F0;
    s2 = D_801ECAF8;
loop:
    v1 = *s2;
    __asm__ volatile(
        ".set\tnoreorder\n"
        "lbu $2,0x73($3)\n"
        "nop\n"
        "andi $2,$2,0x40\n"
        "bnez $2,1f\n"
        "ori $2,$zero,0xffc0\n"
        "sb $19,0($16)\n"
        "j func_801C62F4\n"
        "addiu $19,$19,1\n"
        "1:\n"
        "lbu $4,0x73($3)\n"
        "nop\n"
        ".set\treorder\n"
        : "=r"(v0), "=r"(a0)
        : "r"(v1), "r"(s0), "r"(s3)
        : "memory");
    a0 += v0;
    a0 <<= 16;
    a0 >>= 16;
    *s0 = func_801C7148(a0);
    s0 += 1;
    v0 = D_801EB154;
    __asm__ volatile("addiu %0,%0,1" : "=r"(s1) : "0"(s1));
    v0 = s1 < v0;
    if (v0) {
        s2 += 1;
        goto loop;
    }
end:;
}

extern u8 D_801EB1DC[];

s32 func_80067330(void) {
    register s32 i asm("a0");
    register s32 n asm("v1");
    s32 *pp;
    s32 dummy;
    s32 t;

    (void) &dummy;
    i = 0;
    n = 0;
    t = D_801EB154;
    if (t <= 0) {
        goto end;
    }
    pp = D_801ECAF8;
    do {
        if ((((u8 *) (*pp))[0x73] & 0x40) == 0) {
            D_801EB1DC[n] = i;
            n += 1;
        }
        pp += 1;
        i += 1;
    } while (i < D_801EB154);
end:
    return n;
}

extern void func_801C35F0();
extern s32 func_801CBB44(s32, void *);
extern void func_801C6274();
extern void func_801C6330();
extern void func_801C6F48(s32);
extern void func_801C70C4(s32, void *);
extern void func_801C7104(s32, void *);
extern void func_801CB944(void *, void *, s16 *, s32);
extern s32 D_801CF454;
extern u8 D_801CF458[];
extern s16 D_801CF900;
extern u8 D_801CF904[];
extern s16 D_801CF93C;
extern u8 D_801CF940;
extern s16 D_801EB134[];
extern u8 D_801EB158[];
extern s32 D_801ECB6C;

s32 func_800673A8(void) {
    register u16 *s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s32 a0;
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    s16 sp10[0xC];
    u8 pad[0x8];

    if (D_801CF940 == 0) {
        D_801CF93C = 0;
        a0 = 1;
        KEEP(a0);
        func_801C70C4(a0, D_801EB134);
        s0 = D_801EB134;
        a0 = 0;
        v1 = (s32) sp10;
        do {
            v0 = *s0;
            s0 += 1;
            a0 += 1;
            v0 += 1;
            *(s16 *) v1 = v0;
            v1 += 2;
        } while (a0 < 0xB);
        sp10[0xB] = -1;
        func_801CB944(D_801CF458, D_801EB158, sp10, 1);
        D_801CF940 = 1;
    }
    if (func_801CBB44(0xF, D_801CF904) == 0) {
        D_801CF940 = 0;
        v0 = -1;
        D_801CF454 = v0;
    }
    v0 = D_801CF93C;
    a2 = (s32) D_801EB134;
    v0 <<= 1;
    v0 = *(s16 *) (a2 + v0);
    v1 = D_801EB152;
    v0 += 0x1002;
    D_801ECB6C = v0;
    v0 = -1;
    if (v1 == v0) {
        goto skip_reverse;
    }
    a0 = v1;
    v0 = a0 << 1;
    a0 -= 1;
    v0 += a2;
    a3 = *(s16 *) v0;
    if (a0 >= 0) {
        v0 = a0 << 1;
        v1 = a2 + 2;
        a1 = v0 + v1;
        v1 = v0 + a2;
        do {
            v0 = *(u16 *) v1;
            v1 -= 2;
            a0 -= 1;
            *(s16 *) a1 = v0;
            a1 -= 2;
        } while (a0 >= 0);
    }
    s0 = D_801EB134;
    D_801EB134[0] = a3;
    func_801C35F0();
    a0 = 0;
    v1 = (s32) sp10;
    do {
        v0 = *s0;
        s0 += 1;
        a0 += 1;
        v0 += 1;
        *(s16 *) v1 = v0;
        v1 += 2;
    } while (a0 < 0xB);
    sp10[0xB] = -1;
    func_801CB944(D_801CF458, D_801EB158, sp10, 1);
    a1 = (s32) D_801EB134;
    func_801C7104((D_801CF900 = (v0 = 1)), (void *) a1);
    func_801C6F48(1);
    func_801C6330();
    func_801C6274();
skip_reverse:
    return v0;
}

extern void func_800222FC();
extern u8 D_801EB22C[];

void func_8006757C(void) {
    func_800222FC(D_801EB22C, 0, 0x54);
}

void func_800675A8(s32 arg0) {
    func_800222FC(&D_801EB22C[arg0 * 6], 0, 6);
}

extern u8 D_801EB22E[];
extern u8 D_801EB230[];

void func_800675E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(s16 *) &D_801EB22C[arg0 * 6] = arg1;
    *(s16 *) &D_801EB22E[arg0 * 6] = arg2;
    *(s16 *) &D_801EB230[arg0 * 6] = *(u16 *) (arg1 * 2 + arg3) & 0x3FF;
}

void func_80067630(s32 arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 t0v asm("$8");

    *(s16 *) arg1 = ((s16 *) D_801EB22C)[arg0 * 3];
    *(s16 *) arg2 = ((s16 *) D_801EB22E)[arg0 * 3];
    t0v = ((s16 *) D_801EB230)[arg0 * 3];
    v0 = *arg1;
    v0 = ((s16 *) arg3)[v0];
    if (t0v == v0) {
        return;
    }
    v0 = -1;
    arg0 = 0;
    if (*arg3 == v0) {
        goto L676D0;
    }
    v1 = -1;
L676A0:
    if (((u16) *arg3 & 0x3FF) == t0v) {
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801C66D8\n\t"
                         "sh %0,0(%1)\n\t"
                         ".set\treorder" ::"r"(arg0),
                         "r"(arg1) : "memory");
    }
    arg3++;
    v0 = *arg3;
    arg0 = arg0 + 1;
    if (v0 != v1) {
        goto L676A0;
    }
L676D0:
    *(s16 *) arg1 = 0;
    *(s16 *) arg2 = 0;
}

s32 func_800676E0(s32 arg0, s32 arg1) {
    register s32 r asm("$4");
    register s32 t asm("$2");
    register s32 u asm("$3");

    __asm__ volatile("lui %0,%%hi(D_801CF50C)\n\t"
                     "lb %0,%%lo(D_801CF50C)(%0)\n\t" : "=&r"(t));
    ASM_NOP();
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (t != 0) {
        goto out1;
    }
    __asm__ volatile("addu $4,$zero,$zero");
    __asm__(".set\treorder\n\t");
    __asm__ volatile("lui %0,%%hi(D_801CF50B)\n\t"
                     "lb %0,%%lo(D_801CF50B)(%0)\n\t" : "=&r"(u));
    t = -0x3C;
    if (u == t) {
        goto b50;
    }
    if (u >= -0x3B) {
        goto b20;
    }
    t = -0x78;
    if (u == t) {
        goto b30;
    }
    __asm__ volatile(".set\tnoreorder\n\t"
                     "j func_801C6798\n\t"
                     "nop\n\t"
                     ".set\treorder\n\t");
b20:
    if (u == 0) {
        goto b7c;
    }
    __asm__ volatile(".set\tnoreorder\n\t"
                     "j func_801C6798\n\t"
                     "nop\n\t"
                     ".set\treorder\n\t");
b30:
    __asm__ volatile("lui %0,%%hi(D_801CF450)\n\t"
                     "lh %0,%%lo(D_801CF450)(%0)\n\t" : "=&r"(t));
    if (t >= 8) {
        goto out2;
    }
    __asm__ volatile(".set\tnoreorder\n\t"
                     "j func_801C6798\n\t"
                     "ori $4,$zero,1\n\t"
                     ".set\treorder\n\t");
b50:
    __asm__ volatile("lui %0,%%hi(D_801CF450)\n\t"
                     "lh %0,%%lo(D_801CF450)(%0)\n\t" : "=&r"(u));
    if (u >= 0x10) {
        goto out1;
    }
    __asm__ volatile("slti %0,%1,4" : "=r"(t) : "r"(u));
    if (t == 0) {
        goto out2;
    }
    __asm__ volatile(".set\tnoreorder\n\t"
                     "j func_801C6798\n\t"
                     "ori $4,$zero,1\n\t"
                     ".set\treorder\n\t");
b7c:
    __asm__ volatile("lui %0,%%hi(D_801CF450)\n\t"
                     "lh %0,%%lo(D_801CF450)(%0)\n\t" : "=&r"(t));
    if (t < 0xC) {
        goto out2;
    }
out1:
    r = 1;
out2:
    return r;
}

extern u8 D_80063AB9[];

s32 func_800677A0(s16 *arg0, s32 arg1) {
    s32 r;
    s32 a2;
    s32 v1;
    s32 t;
    s32 x;

    __asm__ volatile("addiu $sp,$sp,-0x10");
    r = 0;
    t = *(s16 *) ((u8 *) arg0 + 0);
    __asm__ volatile("addu $6,$zero,$zero");
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (t == 0) {
        goto d0;
    }
    v1 = t;
    __asm__(".set\treorder\n\t");
    t = *(s16 *) ((u8 *) arg0 + 2);
    if (t != 0) {
        goto e4;
    }
    __asm__ volatile(".set\tnoreorder\n\t"
                     "j func_801C67E4\n\t"
                     "andi $6,$3,0x3FF\n\t"
                     ".set\treorder\n\t" ::"r"(v1));
d0:
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    t = *(s16 *) ((u8 *) arg0 + 2);
    if (t == 0) {
        goto e4;
    }
    __asm__ volatile("addu $3,%0,$zero" : : "r"(t));
    __asm__(".set\treorder\n\t");
    a2 = v1 & 0x3FF;
e4:
    if (a2 == 0) {
        goto end;
    }
    if (a2 >= 0x7A) {
        goto end;
    }
    t = a2 * 8;
    v1 = D_80063AB9[t];
    t = v1 & 1;
    if (t != 0) {
        goto ok;
    }
    if (arg1 == 0) {
        goto end;
    }
    t = v1 & 4;
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (t == 0) {
        goto epi;
    }
    __asm__ volatile("addu $2,%0,$zero" ::"r"(r));
    __asm__(".set\treorder\n\t");
ok:
    r = 1;
end:
    __asm__ volatile("addu $2,%0,$zero" ::"r"(r));
epi:
    __asm__ volatile("addiu $sp,$sp,0x10");
    return;
}

s32 func_80067834(s32 arg0) {
    s32 v;
    v = arg0 - 0x3C;
    v = (u32) v < 0xE;
    if ((u32) (arg0 - 0x90) < 0xB) {
        v = 1;
    }
    return v;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80067854);

extern s16 D_801EB280[];
extern u8 D_801EB2B0[];
extern u8 D_801EB2B6[];
extern s16 D_801EB2AC;
extern s32 func_80180AFC();
extern void func_801C6ED4();
extern void func_801C6854();
extern void func_801C6F48();

s32 func_80067E08(s32 arg0, s32 arg1, s32 arg2) {
    register s32 s0v asm("$16");
    register s32 s1v asm("$17");
    register s32 s2v asm("$18");
    register s32 s3v asm("$19");
    register s16 *s4v asm("$20");
    register s32 s5v asm("$21");
    register s32 v0v asm("$2");
    register s32 v1v asm("$3");
    register s32 a0v asm("$4");
    register s32 a1v asm("$5");
    register s32 a2v asm("$6");
    s32 pad[2];

    s5v = arg2;
    s1v = 0;
    s2v = 0;
    s0v = 0;
    s4v = (s16 *) D_801EB280;
    s3v = 0;
    do {
        a0v = func_80180AFC(s0v);
        v0v = 0xFF;
        if (a0v == 0) {
            goto Lend;
        }
        v1v = ((u8 *) a0v)[1];
        if (v1v == v0v) {
            goto Lend;
        }
        v0v = ((u8 *) a0v)[6] & 4;
        if (v0v == 0) {
            goto Lnext;
        }
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801C6ED4\n\t"
                         "addiu $18,$18,1\n\t"
                         ".set\treorder\n\t" ::: "memory");
Lnext:
        v0v = ((u8 *) a0v)[0x58] & 0x40;
        if (v0v != 0) {
            goto Lend;
        }
        v0v = ((u8 *) a0v)[0x59] & 1;
        if (v0v != 0) {
            goto Lend;
        }
        s2v = s2v + 1;
        a1v = (s32) D_801EB2B0 + s3v;
        a2v = s1v;
        func_801C6854(a0v, a1v, a2v);
        *s4v = (s16) s1v;
        s4v = s4v + 1;
        s3v = s3v + 0x10C;
        s1v = s1v + 1;
Lend:
        s0v = s0v + 1;
    } while (s0v < 0x15);
    s0v = 0;
    if (s1v > 0) {
        v1v = 0;
        do {
            *(s16 *) ((u8 *) D_801EB2B6 + v1v) = (s16) s2v;
            s0v = s0v + 1;
            v1v = v1v + 0x10C;
        } while (s0v < s1v);
    }
    D_801EB2AC = (s16) s1v;
    func_801C6F48(s5v);
    return s1v;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80067F48);

extern u8 D_80057B20[];

void func_800680C4(s16 *arg1) {
    register s32 i asm("a0");
    register s16 *p asm("a1");
    register s32 sent asm("v1");
    s16 v;

    i = 0;
    v = D_80057B20[0];
    __asm__ volatile(".set\tnoreorder\n\t"
                     "j func_801C70EC\n\t"
                     "addiu %0,$zero,-1\n\t"
                     ".set\treorder\n\t"
                     : "=r"(sent)
                     : "r"(v));
    for (;;) {
        i++;
        v = (s8) D_80057B20[i];
        p++;
        *p = v;
        if (v != sent) {
            continue;
        }
        break;
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80068104);

s32 func_80068148(s32 arg0) {
    s32 i;
    s16 key;
    s32 cnt;
    cnt = D_801EB2AC;
    key = (s16) arg0;
    i = 0;
    while (i < cnt) {
        if (*(s16 *) (D_801ECAF8[i] + 0x2C) == key) {
            break;
        }
        i++;
    }
    return i;
}

__asm__(".text\n\t.set noat\n\t"

        ".set noreorder\n\t"
        ".set\tnoreorder\n\t"
        ".globl func_800681A8\n"
        "func_800681A8:\n\t"
        "addiu $2,$4,-0x4A\n\t"
        "andi $2,$2,0xFFFF\n\t"
        "sltiu $2,$2,0x14\n\t"
        "beqz $2,1f\n\t"
        "nop\n\t"
        "j func_801C71C8\n\t"
        "addiu $v0,$4,-0x4A\n\t"
        "1:\n\t"
        "addu $v0,$zero,$zero\n\t"
        "sll $v0,$v0,16\n\t"
        "jr $ra\n\t"
        "sra $v0,$v0,16\n\t"
        ".set\treorder\n\t"
        ".set reorder\n\t"
        ".set at\n");

extern u8 *func_8005A8A4();

s32 func_800681D4(s32 arg0) {
    s32 i;
    i = 0;
    do {
        if (*func_8005A8A4(i) == arg0) {
            return i;
        }
        i++;
    } while (i < 0xA0);
    return -1;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006822C);

s32 func_80068260(s32 arg0, s32 arg1) {
    s32 v1;

    FORCE_REG_NOVOL(v1);
    if ((u32) v1 < 0x80) {
        goto done;
    }
    v1 = 0x4A;
done:
    return v1;
}

extern s32 func_8005DC14();

void func_80068278(u8 *arg0, u8 *arg1) {
    u8 *dst = arg1;
    s32 v;

    arg1 = (u8 *) arg0[4];
    arg0 += 0x64;
    v = func_8005DC14(arg0, (s32) arg1 & 0xC0);
    dst[0] = v >> 16;
    dst[1] = v >> 8;
    dst[2] = v;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_800682C0);

s32 func_80068420(void) {
    return *func_8005A8A4();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80068444);

extern void func_800449EC();
extern s32 func_800246D4(s32);
extern void func_8001DBA8(s8);
extern void func_80024A88(s32, s32);
extern void func_80024C38(s32);
extern void func_80024CAC(void *);
extern void func_80024E84(void *);
extern s16 D_801ECA20;
extern s16 D_801ECA24;
extern s16 D_801ECA28;
extern u16 D_801ECA2C;
extern s16 D_801ECA54;
extern s16 D_801ECA60;
extern s16 D_801ECA64;
extern s16 D_801ECA6C;
extern s16 D_801ECA70;
extern s16 D_801ECA74;
extern s16 D_801ECA7C;
extern s16 D_801ECA80;
extern s16 D_801ECA84;
extern s16 D_801ECA88;
extern u16 D_801ECA90;
extern u16 D_801ECAA0;
extern u16 D_801ECAB0;
extern u16 D_801ECABC;
extern u16 D_801ECAC4;
extern s16 D_801ECAC8;
extern s16 D_801ECAD8;
extern s16 D_801ECAEC;
extern s16 D_801ECAF4;
extern s8 D_801CF950;
extern s32 *D_801ECACC;
extern s32 *D_801ECB4C;
extern s16 D_801ECB54;
extern s16 D_801ECB60;
extern s16 D_801ECB64;

void func_800686CC(s32 arg0, s32 arg1) {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 v0;
    s32 v1;
    s32 a0;
    s32 a1;
    u8 stack[0x60];

    s1 = arg0;
    s0 = arg1;
    v0 = (s32) D_801ECACC;
    s2 = *(s32 *) v0;
    func_800449EC();
    D_801ECA20 = 0;
    D_801ECA7C = 0;
    D_801ECA28 = 0;
    D_801ECA84 = 0;
    D_801ECA24 = 0;
    D_801ECA80 = 0;
    D_801ECA2C = 0;
    D_801ECA88 = 0;
    D_801ECA54 = 0;
    D_801ECA64 = 0;
    D_801ECA70 = 0;
    D_801ECA60 = 0;
    D_801ECA6C = 0;
    D_801ECA74 = 0;
    D_801ECAC4 = 0;
    D_801ECAEC = 0;
    D_801ECAF4 = 0;
    D_801ECB60 = 0;
    D_801ECAD8 = 0;
    D_801ECB54 = 0;
    D_801ECB64 = 0;
    D_801ECAC8 = 0;
    D_801ECAB0 = 0;
    D_801ECABC = 0;
    do {
    } while (func_800246D4(1) != 0);
    func_8001DBA8(D_801CF950);
    v1 = (s32) D_801ECB4C;
    v0 = (s32) D_801ECACC;
    if (v0 == v1) {
        v1 += 0xEC;
    }
    D_801ECACC = (s32 *) v1;
    func_80024E84((void *) (v1 + 0xC0));
    func_80024CAC((void *) ((u8 *) D_801ECACC + 0x64));
    v0 = *(u16 *) ((u8 *) D_801ECACC + 0x66);
    D_801ECA90 = v0;
    if (s0 != -1) {
        v1 = s1 << 2;
        func_80024C38(s2 + (s0 << 2));
    }
    v1 = s1 << 2;
    a1 = D_801ECAA0 - s1;
    a0 = *(s32 *) D_801ECACC + v1;
    func_80024A88(a0, a1);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80068888);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80068EA0);

void func_80069408(s32 arg0) {
    D_801CF950 = arg0;
    if (arg0 == 0) {
        arg0 = 1;
    }
    func_8013DA00(arg0);
}

s32 func_8006943C(void) {
    s32 v;
    v = D_801CF950;
    if (v == 0) {
        return 1;
    }
    return v;
}

extern s32 D_801EC8D8;
extern s32 D_801EC8DC;
extern s16 D_801ECBB0;
extern u16 D_801ECA98;
extern s16 D_801ECADC;
extern u8 D_801EC8B0[];
extern u8 D_801EC8B1[];
extern u8 D_801EC8B2[];
extern s16 D_801EC8B4;
extern s16 D_801EC8C8;
extern s16 D_801CF954;
extern s8 D_801EC8D4;
extern s8 D_801CF9FC;
extern s8 D_801EC8FC;
extern s8 D_801CF988;

void func_8006945C(s32 arg0, s32 arg1, s32 arg2) {
    register s32 v1 asm("$3");

    s32 v0;
    D_801EC8D8 = arg0;
    D_801EC8DC = arg2;
    v0 = -1;
    if (arg0 != 0) {
        v1 = *(s16 *) arg0;
        D_801ECBB0 = 0;
        if (v1 != v0) {
            arg2 = -1;
            do {
                v0 = (u16) D_801ECBB0;
                v0 = v0 + 1;
                __asm__ volatile("sll %0,%1,16\n\tsra %0,%0,15" : "=r"(v1) : "r"(v0));
                v1 = v1 + arg0;
                v1 = *(s16 *) v1;
                D_801ECBB0 = v0;
            } while (v1 != arg2);
        }
    }
    D_801ECA98 = arg1;
    v0 = 0x80;
    if (arg1 == 0) {
        D_801ECADC = 0;
    }
    D_801EC8B0[0] = (u8) v0;
    D_801EC8B1[0] = (u8) v0;
    D_801EC8B2[0] = (u8) v0;
    v0 = 1;
    D_801EC8B4 = 0;
    D_801EC8C8 = 0;
    D_801CF954 = 0;
    D_801EC8D4 = (u8) v0;
    D_801CF9FC = 0;
    D_801EC8FC = 0;
    D_801CF988 = 0;
}

void func_80069530(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 k = arg2;

    func_801C845C(arg0, arg1, arg3, arg3);
    D_801ECADC = k;
}

extern u32 D_801CF98C[];
extern s32 D_801EC8B8;
extern s16 D_801EC8CC;

void func_80069564(u8 *arg0, s32 arg1) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register u8 *a0 asm("$4");
    register s32 s0 asm("$16");
    register u32 *s1 asm("$17");

    a0 = arg0;
    D_801EC8B4 = 0;
    D_801EC8CC = 0;
    D_801EC8B8 = arg1;
    D_801EC8FC = 0;
    v1 = a0[0];
    v0 = 0x1C;
    if (v1 != v0) {
        s0 = 0x1C;
        USE_NOVOL(s0);
        s1 = D_801CF98C;
        v0 = *(volatile u8 *) a0;
        do {
            v0 = *(u32 *) (s1 + v0);
            ((void (*)(void)) v0)();
            a0 = (u8 *) v0;
            USE(a0);
            v0 = a0[0];
        } while (v0 != 0x1C);
    }
}

extern void func_801CB058(s32);
extern void func_801C8564(s32, s32);

void func_800695F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;

    var_s0 = arg1;
    if (arg2 != 0) {
        var_s0 = 0;
    }
    func_801CB058(arg2);
    func_801C8564(arg0, var_s0);
}

extern s32 D_801CF958;
extern u8 *func_801C86C0(u8 *, s32, s32);
extern u8 *func_801C8740(void);

typedef s32 (*func_80069648_fn)(s32, s32);

typedef u8 *(*func_80069648_table_fn)(u8 *);

u8 *func_80069648(u8 *arg0) {
    register u8 *s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 s2 asm("$18");
    register s32 s3 asm("$19");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    func_80069648_table_fn temp_fn;
    u8 *p;

    s0 = arg0;
    v0 = s0[3];
    s1 = s0[4];
    v1 = D_801EC8C8;
    v0 <<= 2;
    a1 = *(s32 *) ((u8 *) &D_801ECB70 + v0);
    if (v1 == 0) {
        v1 = s0[5];
        __asm__ volatile("j func_801C86C0" : : "r"(s0), "r"(a1), "r"(v1) : "a0", "a1", "v1");
    }
    v0 = D_801ECADC;
    v1 = D_801CF958;
    a0 = D_801CF954;
    v1 = v0 + v1;
    if (a0 < 0) {
        v1--;
    }
    v0 = s0[1];
    p = s0 + v0;
    s0 = p;
    if (((func_80069648_fn) a1)(v1, a1) == 0) {
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
        __asm__ volatile("\t.set\tnoreorder\n\tj func_801C8740\n\taddu $2,$16,$zero\n\t.set\treorder" : : : "v0", "memory");
    }
    s1--;
    if (s1 != v0) {
        s3 = (s32) D_801CF98C;
        s2 = -1;
        do {
            v0 = s0[0];
            __asm__ volatile("addu %0,$16,$zero" : "=r"(a0) : : "memory");
            v0 <<= 2;
            v0 += s3;
            v0 = *(s32 *) v0;
            temp_fn = (func_80069648_table_fn) v0;
            temp_fn((u8 *) a0);
            s1--;
            s0 = (u8 *) v0;
        } while (s1 != s2);
    }
    return s0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80069760);

extern void *func_801C894C(u8);
extern void func_801CD888(s16 *, u8, u8, void *, s32, s32, s32, s32);
extern s16 D_801EC8C0;
extern u16 D_801EC8E0;
extern u16 D_801EC8E4;

void *func_800698EC(u8 *arg0) {
    s16 buf[4];
    register void *var_t0 asm("t0");
    s32 v0;
    s32 var_a0;
    register s32 a0 asm("a0");

    if (D_801EC8C8 == 0) {
        a0 = arg0[4];
        __asm__ volatile("j func_801C894C" : : "r"(a0) : "a0");
    }
    {
        register s32 v0 asm("v0");
        register s32 v1 asm("v1");
        register s32 a1 asm("a1");

        a1 = D_801EC8C0;
        v0 = D_801CF958;
        var_a0 = a1 * v0;
        a0 = arg0[4];
        v1 = D_801CF954;
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
    var_t0 = D_801EC8B0;
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

        call_a0 = D_801EC8B4;
        call_a3 = D_801EC8CC;
        call_a1 = arg0[7];
        call_a2 = arg0[8];
        call_v0 = D_801EC8E0;
        call_v1 = D_801EC8E4;
        func_801CD888(&buf[0], call_a1, call_a2, var_t0, call_a3, call_v0, call_v1, call_a0);
    }
    return arg0 + arg0[1];
}

extern u8 D_801CFA0B;
extern u8 D_801CFA0C;
extern u8 D_801CFA0D;
extern u8 D_801CFA0E;
extern u8 D_801CFA0F;
extern u8 D_801CFA10;
extern void func_801C88EC(void *);

typedef void *(*func_800699EC_fn)(s32, void *);

void *func_800699EC(void *arg0) {
    register u8 *s0 asm("$16") = (u8 *) arg0;
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");

    v0 = s0[2];
    v1 = D_801EC8C8;
    v0 <<= 2;
    a1 = *(s32 *) ((u8 *) &D_801ECB70 + v0);
    if (v1 == 0) {
        v0 = s0[3];
        __asm__ volatile(".set\tnoreorder\n\tj func_801C8A54\n\tnop\n\t.set\treorder" ::"r"(v0) : "memory");
    }
    v0 = (s16) D_801ECADC;
    v0 += D_801CF958;
    a0 = D_801CF954;
    if (a0 < 0) {
        v0 -= 1;
    }
    a0 = v0;
    ((func_800699EC_fn) a1)(a0, (void *) a1);
    v1 = v0;
    if (v1 == 0) {
        goto done;
    }
    v0 = s0[4];
    a0 = (s32) &D_801CFA0B;
    *(u8 *) a0 = v0;
    v0 = s0[5];
    D_801CFA0C = v0;
    v0 = *((u8 *) v1 + 4);
    D_801CFA0D = v0;
    v0 = *((u8 *) v1 + 6);
    D_801CFA0E = v0;
    v0 = *(u8 *) v1;
    D_801CFA0F = v0;
    v0 = *((u8 *) v1 + 2);
    D_801CFA10 = v0;
    v0 = *(u16 *) (v1 + 8);
    v1 = *(u16 *) (v1 + 10);
    D_801EC8E4 = v0;
    D_801EC8E0 = v1;
    a0 -= 3;
    func_801C88EC((void *) a0);
done:
    v0 = s0[1];
    return s0 + v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_80069AF4);

extern void func_801C8AF4(void *);
extern void func_801C924C(void);
extern void func_801CE40C();
extern s16 D_801CFA1C[];

void func_8006A13C(void *arg0) {
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
    v1 = D_801CF9FC;
    v0 = v1 < 4;
    if (v0 == 0) {
        goto false_body;
    }
    v0 = v1 < 3;
    if (v0 != 0) {
        D_801EC8B8 = 0;
    }
    v0 = v1 << 1;
    a0 = *(s16 *) ((u8 *) D_801CFA1C + v0);
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
    ((void (*)(s16 *, s32, s32)) func_801CE40C)(&sp[0], D_801EC8B4 - 1, temp_a2_2);
    D_801EC8FC = 1;
    __asm__ volatile(".set\tnoreorder\n\tj func_801C924C\n\tnop\n\t.set\treorder" ::: "memory");
false_body:
    D_801EC8FC = 0;
    a0 = s0;
    func_801C8AF4((void *) a0);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006A268);

extern s32 func_80023A54(s32, s32);

u8 *func_8006A500(u8 *arg0) {
    D_801EC8E4 = func_80023A54(arg0[3] * 0x10, arg0[4] | (arg0[2] << 8));
    return arg0 + arg0[1];
}

extern u8 D_801EC8F4[];
extern void *func_801C9594();

u8 *func_8006A554(u8 *arg0) {
    register u8 v0 asm("v0");
    register u8 a0 asm("a0");
    register u8 a1 asm("a1");

    if (D_801EC8F4[0] == 0) {
        goto call_80023a54;
    }
    a0 = arg0[6];
    a1 = arg0[5];
    v0 = arg0[7];
    __asm__ volatile(".set\tnoreorder\n\tj func_801C9594\n\tsll %0, %0, 4\n\t.set\treorder" ::"r"(a0), "r"(a1), "r"(v0) : "a0", "memory");
call_80023a54:
    D_801EC8E4 = func_80023A54(arg0[3] << 4, arg0[4] | (arg0[2] << 8));
    return arg0 + arg0[1];
}

u8 *func_8006A5C8(u8 *arg0) {
    u8 t;

    t = arg0[2];
    D_801EC8E0 = func_8002398C(arg0[4], t >> 4, arg0[3] * 0x10, t << 8);
    return arg0 + arg0[1];
}

u8 *func_8006A61C(u8 *arg0) {
    D_801EC8CC = arg0[3];
    return arg0 + arg0[1];
}

u8 *func_8006A634(u8 *arg0) {
    s32 r;
    r = func_8002398C(0, arg0[2], 0x100, 0);
    func_801CE334(0, 0, r & 0xFFFF, 0, D_801EC8B4);
    return arg0 + arg0[1];
}

u8 *func_8006A698(u8 *arg0) {
    if (D_801EC8F4[0] == 0) {
        goto second;
    }
    D_801EC8B0[0] = arg0[5];
    D_801EC8B1[0] = arg0[6];
    __asm__ volatile("lbu $2,7(%0)\n\t"
                     ".set\tnoreorder\n\t"
                     "j func_801C96EC\n\t"
                     "nop\n\t"
                     ".set\treorder\n\t" ::"r"(arg0));
second:
    D_801EC8B0[0] = arg0[2];
    D_801EC8B1[0] = arg0[3];
    D_801EC8B2[0] = arg0[4];
    return arg0 + arg0[1];
}

u8 *func_8006A700(u8 *arg0) {
    D_801EC8B4 = arg0[3];
    return arg0 + arg0[1];
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006A718);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006AB4C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006ACF4);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006AF80);

u8 *func_8006B2E0(u8 *arg0) {
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
    __asm__ volatile("j func_801CA320\n\t"
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
    __asm__ volatile("j func_801CA320\n\t"
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006B34C);

extern void func_801CA34C();

void func_8006B5EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 k = arg3;

    func_801C845C(arg0, arg1, arg2, k);
    func_801CA34C(k);
}

extern void func_801C8530();

void func_8006B61C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_801C8530();
    func_801CA34C(arg4);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006B650);

void func_8006C014(u8 *arg0) {
    if (arg0 != 0) {
        D_801EC8B0[0] = arg0[0];
        D_801EC8B0[1] = arg0[1];
        D_801EC8B0[2] = arg0[2];
    }
}

void func_8006C048(s16 arg0) {
    D_801EC8B4 = arg0;
}

extern u16 D_801CF984[];
extern u16 D_801CF964[];
extern u16 D_801CF962[];
extern u16 D_801CF96A[];
extern u16 D_801CF972[];
extern u16 D_801CF974[];
extern u16 D_801CF986[];
extern u16 D_801CF966[];
extern u16 D_801CF960[];
extern u16 D_801CF968[];
extern u16 D_801CF96E[];
extern u16 D_801CF970[];
extern u16 D_801ECAE4;
extern u16 D_801ECA94;
extern u16 D_801ECA78;
extern u16 D_801ECA30;
extern u16 D_801ECAF0;
extern u16 D_801ECB5C;

void func_8006C058(s32 arg0) {
    register s32 m asm("$2");
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;

    D_801EC8F4[0] = arg0;
    if (arg0 == 0) {
        goto b0;
    }
    {
        m = 0x60;
        __asm__ volatile("lhu $3,D_801CF984");
        __asm__ volatile("lhu $4,D_801CF964");
        __asm__ volatile("lhu $5,D_801CF962");
        __asm__ volatile("lhu $6,D_801CF96A");
        __asm__ volatile("lhu $7,D_801CF972");
        __asm__ volatile("lhu $8,D_801CF974");
        D_801EC8B0[0] = m;
        D_801EC8B1[0] = m;
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801CB0F4\n\t"
                         "ori $2,$zero,0x80\n\t"
                         ".set\treorder\n\t");
    }
b0:
    a = D_801CF986[0];
    b = D_801CF966[0];
    c = D_801CF960[0];
    d = D_801CF968[0];
    e = D_801CF96E[0];
    f = D_801CF970[0];
    m = 0x80;
    D_801EC8B0[0] = m;
    D_801EC8B1[0] = m;
    D_801EC8B2[0] = m;
    D_801ECAE4 = a;
    D_801ECA94 = b;
    D_801ECA78 = c;
    D_801ECA30 = d;
    D_801ECAF0 = e;
    D_801ECB5C = f;
}

extern s16 D_801CFA02[];

u8 *func_8006C134(u8 *arg0) {
    if (D_801EC8FC != 0) {
        D_801CFA02[0] = 0;
        func_801CE40C((u8 *) D_801CFA02 - 2, D_801EC8B4 + 1);
        D_801EC8FC = 0;
    }
    return arg0 + arg0[1];
}

u8 *func_8006C198(u8 *arg0) {
    s16 buf[4];

    if (D_801EC8FC == 0) {
        buf[0] = arg0[2];
        buf[1] = arg0[3];
        buf[2] = arg0[4];
        buf[3] = arg0[5];
        func_801CE40C(buf, D_801EC8B4 - 1);
    }
    return arg0 + arg0[1];
}

u8 *func_8006C20C(u8 *arg0) {
    register s32 v asm("a1");
    if (D_801EC8FC == 0) {
        v = D_801EC8B4;
        *(s16 *) ((u8 *) &D_801CF9FC + 6) = 0;
        func_801CE40C((s16 *) ((u8 *) &D_801CF9FC + 4), v + 1);
    }
    return arg0 + arg0[1];
}

void func_8006C268(s8 arg0) {
    D_801CF9FC = arg0;
}

s32 func_8006C278(void) {
    return D_801CF9FC;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006C288);

s32 func_8006C2A0(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    s32 unused[2];
    v0 = v1 + 1;
    D_801CF9FC = v0;
    __asm__ volatile(".L8006C2B0:");
    v0 = arg0 + 1;
    return v0;
}

u8 *func_8006C2C0(void) {
    return D_801EC8B0;
}

extern void func_801CB38C(s16);
extern s8 D_801ECAAC;

void func_8006C2D0(s32 arg0, u8 *arg1) {
    register s32 s1 asm("s1");
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register u8 *p1 asm("a1");
    register s32 a2 asm("a2");
    s32 unused[8];

    s1 = D_801ECADC;
    v0 = D_801ECA98;
    s0 = v0 - s1;
    p1 = arg1;
    a2 = s1;
    if (arg0 == -1) {
        v0 = p1[6];
        v0 = a2 - v0;
        D_801ECADC = v0;
        if ((s16) v0 < 0) {
            D_801ECADC = 0;
            TAIL_JUMP_MEM(func_801CB38C);
        } else {
            goto block_7;
        }
    }
    if (arg0 == 1) {
        v0 = p1[6];
        v1 = D_801ECBB0;
        v0 += a2;
        a2 = v1;
        D_801ECADC = v0;
        v0 = (s16) v0;
        v0 += 1;
        v1 -= v0;
        if (v1 < p1[6]) {
            v0 = *(volatile u8 *) &p1[6];
            v0 = a2 - v0;
            D_801ECADC = v0;
        }
    }
block_7:
    D_801ECA98 = (u16) D_801ECADC;
    func_801CA34C(p1);
    v0 = s0 + (u16) D_801ECADC;
    D_801ECA98 = v0;
    if ((s16) v0 >= D_801ECBB0) {
        D_801ECA98 = D_801ECBB0 - 1;
    }
    if (s1 != (s16) (u16) D_801ECADC) {
        D_801ECAAC = 3;
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006C410);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006C52C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006C660);

s32 func_8006C6B4(s32 arg0) {
    return arg0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006C6BC);

extern u8 *func_801CB660(s32, s32, s32);

void func_8006C944(s32 arg0, u8 *arg1, s16 *arg2, s32 arg3) {
    s16 *var_s1;
    u8 *var_a0;
    u8 *var_s0;

    var_s0 = arg1;
    if (*arg2 != -1) {
        var_s1 = arg2;
        do {
            var_a0 = func_801CB660(arg0, *(u16 *) var_s1 & 0x7FF, 1);
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

void func_8006CA14(s32 arg0) {
    func_8014CA38(arg0, 0, 0, 1);
}

struct func_8006CA3C_fields {
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

extern void func_801CB6BC();
extern void func_801CE82C();

void func_8006CA3C(s32 arg0, s16 *arg1, void *arg2, s32 arg3) {
    s32 lowpad[6];
    u8 sp28[0x800];
    struct func_8006CA3C_fields f;
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
        __asm__ volatile(".L8006CA3C_loop:");
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
            v0 = 0xE7;
            __asm__ volatile("ori $7,$zero,0x64" : : : "a3", "memory");
            *(s32 *) ((u8 *) &f.f828 - 0x818) = s2v;
            *(s32 *) ((u8 *) &f.f828 - 0x80C) = v0;
            *(s32 *) ((u8 *) &f.f828 - 0x808) = s3v;
            ((void (*)(void)) func_801CB6BC)();
            func_801CE82C(&f.f830, (void *) &sp28[0]);
            v0 = *(u16 *) &f.f832;
            s0v = s0v + 2;
            v0 = v0 + 0x10;
            f.f832 = (u16) v0;
            v0 = *(s16 *) s0v;
            a3v = *(u16 *) s0v;
            __asm__ volatile(".set\tnoreorder\n\tbne $2,$17,.L8006CA3C_loop\n\taddiu $4,$29,0x28\n\t.set\treorder" : : "r"(v0), "r"(a3v), "r"(s1v) : "memory");
        } while (0);
    }
}

extern void *D_80173CB8;
extern u8 D_801CFDF4;

u8 func_8006CB44(s32 arg0, void *arg1) {
    u8 var_v0;
    s32 value;

    if (D_801CFDF4 == 0) {
        if (func_8014CA1C(arg0) != 0) {
            var_v0 = 1;
            return var_v0;
        }
        value = *(s32 *) ((u8 *) arg1 + 0x28);
        D_80173CB8 = arg1;
        func_8014C8A0(arg0, value);
        func_8014CA38(arg0, D_80173CB8, 0, 0);
        D_801CFDF4 = 1;
    }
    D_801CFDF4 = func_8014CA1C(arg0);
    return D_801CFDF4;
}

extern void func_80133FE8();
extern void func_80134020();
extern void func_801CBC6C();
extern u8 D_801CFDF8[];
extern s32 D_801ECB68;

void func_8006CBE0(s32 arg0) {
    s32 t = D_801ECB6C;

    if (0x1FFFF < t) {
        D_801ECB68 = t;
        TAIL_JUMP(func_801CBC6C);
    }
    if (t > 0) {
        func_80134020();
        func_80133FE8(&D_801CFDF8);
        func_8014C8A0(1, &D_801308C0);
        func_8014CA38(1, arg0 + 0x38, D_801ECB6C, 0);
        D_80166028 = 1;
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006CC80);

extern u8 D_801E3460;
extern s32 D_801EC908;

void func_8006CFC4(s32 arg0) {
    D_801E3460 = 1;
    D_801EC908 = arg0;
}

extern s32 D_801E3464;

s32 func_8006CFE0(s32 arg0) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0v asm("$4");
    register s32 a1v asm("$5");
    register s32 a2v asm("$6");
    register s32 a3v asm("$7");
    register s32 t0v asm("$8");
    register s32 t1v asm("$9");
    register s32 t2v asm("$10");

    v0 = 0;
    if (arg0 == 0) {
        goto END;
    }
    __asm__ volatile("lui %0,%%hi(D_801E3460)\n\t"
                     "lbu %0,%%lo(D_801E3460)(%0)\n\tnop" : "=&r"(v0));
    __asm__ volatile(".set\tnoreorder\n\t"
                     "beqz %0,1f\n\t"
                     "andi $4,$4,0x1f\n\t"
                     "ori $2,$zero,7\n\t"
                     "lui $1,%%hi(D_801E3464)\n\t"
                     "sw $2,%%lo(D_801E3464)($1)\n\t"
                     "lui $1,%%hi(D_801E3460)\n\t"
                     "sb $zero,%%lo(D_801E3460)($1)\n\t"
                     "1:\n\t"
                     ".set\treorder" ::"r"(v0));
    arg0 = arg0 - 1;
    __asm__ volatile(".set\tnoreorder\n\t"
                     "addiu $2,$zero,-1\n\t"
                     "beq $4,$2,1f\n\t"
                     "addu $7,$zero,$zero\n\t"
                     "ori $10,$zero,1\n\t"
                     "ori $9,$zero,7\n\t"
                     "addiu $8,$zero,-1\n\t"
                     ".set\treorder");
L02C:
    __asm__ volatile("lui %0,%%hi(D_801EC908)\n\t"
                     "lw %0,%%lo(D_801EC908)(%0)" : "=&r"(a2v));
    __asm__ volatile("lui %0,%%hi(D_801E3464)\n\t"
                     "lw %0,%%lo(D_801E3464)(%0)" : "=&r"(v1));
    v0 = *(u8 *) a2v;
    a1v = v1 - 1;
    D_801E3464 = a1v;
    v0 = v0 >> v1;
    v0 = v0 & 1;
    if (v0 != 0) {
        v0 = t2v << arg0;
        a3v = a3v | v0;
    }
    __asm__ volatile(".set\tnoreorder\n\t"
                     "bgez $5,2f\n\t"
                     "addiu $4,$4,-1\n\t"
                     "addiu $2,$6,1\n\t"
                     "lui $1,%hi(D_801E3464)\n\t"
                     "sw $9,%lo(D_801E3464)($1)\n\t"
                     "lui $1,%hi(D_801EC908)\n\t"
                     "sw $2,%lo(D_801EC908)($1)\n\t"
                     "2:\n\t"
                     ".set\treorder");
    if (arg0 != t0v) {
        goto L02C;
    }
    __asm__ volatile("1:");
    v0 = a3v;
END:
    return v0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006D090);

extern void func_801CC090();
extern void func_801CC7E8();
extern s32 func_801CE5F8();

#define P3 "D_801E3468 + 3"

void func_8006D418(void) {
    s32 s0r;
    s32 v0;
    s32 v1;

    func_801CC090();
    s0r = func_8014CA1C(1);
    if (s0r != 0) {
        goto L450;
    }
    v0 = D_801ECB68;
    if (v0 == 0) {
        goto L498;
    }
L450:
    func_801CC7E8();
    if (s0r == 0) {
        goto L488;
    }
    __asm__ volatile("lui %0,%%hi(" P3 ")\n\t"
                     "lbu %0,%%lo(" P3 ")(%0)\n\t" : "=&r"(v0));
    v1 = 1;
    if (v0 != 0) {
        v1 = 2;
    }
    __asm__ volatile("lui $at,%%hi(" P3 ")\n\t"
                     "sb %0,%%lo(" P3 ")($at)\n\t" ::"r"(v1));
    __asm__ volatile(".set\tnoreorder\n\tj func_801CC4CC\n\tnop\n\t.set\treorder\n\t");
L488:
    __asm__ volatile("lui $at,%%hi(" P3 ")\n\t"
                     "sb $zero,%%lo(" P3 ")($at)\n\t" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tj func_801CC4CC\n\tnop\n\t.set\treorder\n\t");
L498:
    __asm__ volatile("lui %0,%%hi(" P3 ")\n\t"
                     "lbu %0,%%lo(" P3 ")(%0)\n\t" : "=&r"(v0));
    if (v0 != 0) {
        goto L4BC;
    }
    v0 = func_801CE5F8();
    if (v0 == 0) {
        goto L4CC;
    }
L4BC:
    __asm__ volatile("lui $at,%%hi(" P3 ")\n\t"
                     "sb $zero,%%lo(" P3 ")($at)\n\t" ::: "memory");
    func_801CC7E8();
L4CC:
    v0 = 1;
    if (s0r == 0) {
        __asm__ volatile("lui $at,%%hi(D_80166028)\n\t"
                         "sw $zero,%%lo(D_80166028)($at)\n\t" ::: "memory");
    }
    __asm__ volatile("lui %0,%%hi(" P3 ")\n\t"
                     "lbu %0,%%lo(" P3 ")(%0)\n\t" : "=&r"(v1));
    ASM_NOP();
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (v1 != v0) {
        goto L4F8;
    }
    __asm__ volatile("ori $2,$zero,0x12");
    __asm__(".set\treorder\n\t");
    __asm__ volatile("lui $at,%%hi(D_801ECAAC)\n\t"
                     "sb $2,%%lo(D_801ECAAC)($at)\n\t" ::: "memory");
L4F8:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006D50C);

extern u8 D_801EC96E[];

void func_8006D698(void) {
    s32 i;
    s16 *p;
    i = 0xF;
    p = (s16 *) D_801EC96E;
    for (; i >= 0; i--) {
        *p = 0;
        p--;
    }
}

extern s16 D_801EC950_h[] asm("D_801EC950");

s16 func_8006D6BC(s32 arg0, s16 arg1) {
    D_801EC950_h[arg0 & 0xFF] = arg1;
    return arg1;
}

s32 func_8006D6DC(s32 arg0, s32 arg1, s32 arg2, s32 unused) {
    s32 v;
    register s32 a3c asm("$7");
    register s32 tb asm("$3");
    s32 ix;
    volatile s32 pad[4];

    a3c = arg0;

    if (arg2 & 0x8000) {
        register s32 v8 asm("$2");
        register s32 w8 asm("$3");
        ix = arg1 & 0xFF;
        tb = (u32) D_801EC950_h;
        KEEP(tb);
        arg2 = ix * 2 + tb;
        v8 = *(s16 *) arg2;
        w8 = v8;
        if (v8 != 0) {
            goto L1;
        }
        __asm__ volatile("\t.set\tnoreorder\n\tj func_801CC75C\n\taddiu $2,%0,-1\n\t.set\treorder" : : "r"(arg0) : "v0", "memory");
L1:
        __asm__ volatile("\t.set\tnoreorder\n\tj func_801CC75C\n\taddiu $2,%0,-1\n\t.set\treorder" : : "r"(w8) : "v0", "memory");
    }
    if (arg2 & 0x2000) {
        register s32 u2 asm("$4");
        register s32 x asm("$2");
        s32 c;
        ix = arg1 & 0xFF;
        tb = (u32) D_801EC950_h;
        KEEP(tb);
        arg2 = ix * 2 + tb;
        v = *(s16 *) arg2;
        x = (a3c & 0xFFFF) - 1;
        u2 = v;
        KEEP(u2);
        c = v < x;
        x = u2 + 1;
        if (!c) {
            x = 0;
        }
        *(s16 *) arg2 = x;
    }
    return D_801EC950_h[arg1 & 0xFF];
}

extern s16 func_801CC6DC(s32, s32);
extern u16 D_801EC950[];

void func_8006D780(s32 arg0, s32 arg1, s32 unused, s8 arg3) {
    s32 temp_a1;
    u16 temp_s0;

    temp_a1 = arg1 & 0xFF;
    temp_s0 = D_801EC950[temp_a1];
    if ((s16) temp_s0 != func_801CC6DC(arg0 & 0xFFFF, temp_a1)) {
        D_801ECAAC = arg3;
    }
}

void func_8006D7E8(void) {
    D_801ECA0C = 0;
    D_801ECB50 = 0;
    D_801ECAD0 = 0;
}

extern s16 D_801EC984[];
extern s32 D_801EC9E4;

s32 func_8006D808(s32 arg0) {
    s32 r;
    s32 c;
    s32 cond;

    r = func_801C71A8(D_801EC984[arg0]);
    c = *(u8 *) (D_801ECAF8[D_801CF450] + (r >> 1) + 0xB1);
    cond = r & 1;
    D_801EC9E4 = c;
    MEMORY_BARRIER();
    if (cond == 0) {
        D_801EC9E4 = ((s32) c) >> 4;
    } else {
        D_801EC9E4 = c & 0xF;
    }
    MEMORY_BARRIER();
    return D_801EC9E4;
}

extern s32 func_801C71A8(s32);
extern s32 D_801EC9E8;

void func_8006D888(s32 arg0) {
    s32 r = func_801C71A8(D_801EC984[arg0]);

    D_801EC9E8 = *(u16 *) (D_801ECAF8[D_801CF450] + (r * 2) + 0xBC);
}

extern s32 D_801EC9EC;

void func_8006D8E8(s32 arg0) {
    s32 r = func_801C71A8(D_801EC984[arg0]);

    D_801EC9EC = *(u16 *) (D_801ECAF8[D_801CF450] + (r * 2) + 0xE4);
}

extern s32 D_801EC9F0;
extern JpReqLevels D_80066184;

s32 func_8006D948(s32 arg0) {
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    u16 *p;

    func_801C71A8(D_801EC984[arg0]);
    v0 = D_801EC9E4;
    v1 = v0 & 0xF;
    if (v1 < 8) {
        goto assign;
    }
    v0 = D_801EC9F0;
    {
        register s32 v1 asm("v1");

        v1 = 0x20000000;
        __asm__ volatile(".set\tnoreorder\n\tj func_801CC9A8\n\tor %0, %0, %1\n\t.set\treorder" ::"r"(v0), "r"(v1) : "memory");
    }
assign: {
    register s32 off asm("v0");

    MEMORY_BARRIER();
    off = v1 << 1;
    p = (u16 *) ((u8 *) &D_80066184 + off);
    D_801EC9F0 = *p;
    MEMORY_BARRIER();
    return D_801EC9F0;
}
}

extern s32 func_801C7444();
extern s32 D_801EC9F4;

void func_8006D9C8(s32 arg0) {
    D_801EC9F4 = func_801C7444(D_801CF450, D_801EC984[arg0], 0xF, 0, 3) == 0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006DA18);

s32 func_8006DC2C(void) {
    return D_801EC9E8;
}

s32 func_8006DC3C(void) {
    return D_801EC9E4;
}

s32 func_8006DC4C(void) {
    return D_801EC9F0;
}

s32 func_8006DC5C(void) {
    return D_801EC9EC;
}

s32 func_8006DC6C(void) {
    return D_801EC9F4;
}

extern u16 D_801EC9B0[];
extern u8 D_801ECA00[];
extern u8 *D_801EC9FC;
extern s32 D_801EC9F8;
extern s32 func_8005A72C(s32, void *, void *);

s32 func_8006DC7C(s32 arg0) {
    u16 *p;
    s32 base;
    u16 t;
    s32 ret;
    s32 r;

    base = (s32) D_801EC9B0;
    p = (u16 *) ((u8 *) base + arg0 * 2);
    t = *p;
    ret = func_8005A72C(t & 0x3FF, D_801ECA00, (void *) &D_801EC9FC);
    D_801EC9F8 = ret;
    r = 0;
    if (ret != 0) {
        t = *p;
        r = (t >> 14) == 0;
    }
    return r;
}

s32 func_8006DCEC(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (D_801EC9F8 != 0) {
        var_v1 = (D_801EC9B0[arg0] >> 0xE) != 0;
    }
    return var_v1;
}

s32 func_8006DD24(void) {
    return !D_801EC9F8;
}

extern u16 D_8005EBF0[][4];

u32 func_8006DD34(s32 arg0) {
    s32 t;
    u32 r;

    __asm__ volatile("lui $at,%%hi(D_801EC9B0)\n\t"
                     "addu $at,$at,%1\n\t"
                     "lh %0,%%lo(D_801EC9B0)($at)\n\t"
                     : "=r"(t)
                     : "r"(arg0 << 1));
    r = 0x20000000;
    if (!(t & 0x2000)) {
        r = D_801EC9FC[0xD];
    }
    if ((t >> 14) != 0) {
        r |= 0x40000000;
    }
    return r;
}

u32 func_8006DD80(s32 arg0) {
    u32 r;
    s32 t;
    u32 v;

    __asm__ volatile("lui $at,%%hi(D_801EC9B0)\n\t"
                     "addu $at,$at,%1\n\t"
                     "lh %0,%%lo(D_801EC9B0)($at)\n\t"
                     : "=r"(t)
                     : "r"(arg0 << 1));
    r = 0x20000000;
    if (!(t & 0x2000)) {
        r = D_801EC9FC[0xC];
        v = (s32) 100 / (s32) r;
        r = v + (((s32) 100 % (s32) r) != 0);
    }
    if ((t >> 14) != 0) {
        r |= 0x40000000;
    }
    return r;
}

u32 func_8006DDE4(s32 arg0) {
    s32 t;
    u32 r;

    __asm__ volatile("lui $at,%%hi(D_801EC9B0)\n\t"
                     "addu $at,$at,%1\n\t"
                     "lh %0,%%lo(D_801EC9B0)($at)\n\t"
                     : "=r"(t)
                     : "r"(arg0 << 1));
    r = 0x20000000;
    if (!(t & 0x2000)) {
        r = D_8005EBF0[t & 0x3FF][0];
    }
    if ((t >> 14) != 0) {
        r |= 0x40000000;
    }
    return r;
}

extern s16 D_801E346C;

s32 func_8006DE34(void) {
    return !D_801E346C;
}

s32 func_8006DE44(void) {
    return !(D_801E346C ^ 1);
}

s32 func_8006DE5C(void) {
    return !(D_801E346C ^ 2);
}

s32 func_8006DE74(void) {
    return !(D_801E346C ^ 3);
}

s32 func_8006DE8C(s32 arg0) {
    return ((D_801EC9B0[arg0] >> 14) ^ 1) & 1;
}

extern s8 D_801E3739;
extern s8 D_801EC974;
extern void func_801C657C();
extern void func_801CC6BC(s32, s32);
extern void func_801CCA18();
extern void func_801CCF2C();
extern s8 func_801CCF74();

void func_8006DEB0(void) {
    s32 v0;
    s32 v1;

    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801E3739)\n\tlb $2,%%lo(D_801E3739)($2)\n\taddiu $29,$29,-0x18\n\tsw $31,0x14($29)\n\tbnez $2,.L8006DEB0_common\n\tsw $16,0x10($29)\n\tori $16,$zero,1\n\tmove $4,$zero\n\tlui $1,%%hi(D_801E3739)\n\tsb $16,%%lo(D_801E3739)($1)\n\tlui $1,%%hi(D_801EC974)\n\tsb $zero,%%lo(D_801EC974)($1)\n\tjal func_801CC6BC\n\tmove $5,$zero\n\tjal func_801C657C\n\tnop\n\tlui $1,%%hi(D_801ECAAC)\n\tsb $16,%%lo(D_801ECAAC)($1)\n\t.L8006DEB0_common:\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tlui $3,%%hi(D_801EC974)\n\tlb $3,%%lo(D_801EC974)($3)\n\tnop\n\tbne $3,$zero,.L8006DEB0_state\n\tori $2,$zero,1\n\tjal func_801CCA18\n\tnop\n\tj func_801CCF2C\n\tnop\n\t.L8006DEB0_state:\n\t.set\treorder" : "=r"(v1)::"memory");
    __asm__ volatile(".set\tnoreorder\n\tbne $3,$2,.L8006DEB0_after_state\n\tnop\n\tjal func_801CCF74\n\tnop\n\tlui $1,%%hi(D_801EC974)\n\tsb $2,%%lo(D_801EC974)($1)\n\t.L8006DEB0_after_state:\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile(".set\tnoreorder\n\tlui $3,%%hi(D_801EC974)\n\tlb $3,%%lo(D_801EC974)($3)\n\t.set\treorder" : "=r"(v1)::"memory");
    v0 = -1;
    if (v1 == v0) {
        __asm__ volatile(".set\tnoreorder\n\tlui $1,%%hi(D_801CF454)\n\tsw $3,%%lo(D_801CF454)($1)\n\tjal func_801CC7E8\n\tnop\n\tlui $1,%%hi(D_801E3739)\n\tsb $zero,%%lo(D_801E3739)($1)\n\t.set\treorder" ::: "memory");
    }
    __asm__ volatile(".set\tnoreorder\n\tlw $31,0x14($29)\n\tlw $16,0x10($29)\n\taddiu $29,$29,0x18\n\t.set\treorder" ::: "memory");
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006DF74);

extern void func_80023C68();

void func_8006E344(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u16 n;
    EventEntry16 *p;
    s32 *b1;
    register s32 *b2 asm("a2");
    register s32 mlo asm("a0");
    s32 i;

    n = D_801ECAC4;
    D_801ECAC4 = n + 1;
    b1 = *(s32 **) ((u8 *) &D_801ECAC4 + 8);
    p = (EventEntry16 *) (*(u8 **) ((u8 *) b1 + 0x3C) + n * 0x10);
    p->at_04 = arg1[0];
    p->at_05 = arg1[1];
    p->at_06 = arg1[2];
    func_80023C68(p, arg2 & 0xFF);
    b2 = D_801ECACC;
    i = arg3 * 4;
    mlo = 0xFFFFFF;
    *(s16 *) &p->at_08 = *(u16 *) arg0 + 0x80;
    p->at_0A = *(u16 *) (arg0 + 2);
    p->at_0C = *(u16 *) (arg0 + 4);
    p->at_0E = *(u16 *) (arg0 + 6);
    *(s32 *) p->at_00 = (*(s32 *) p->at_00 & 0xFF000000) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & 0xFF000000) | ((s32) p & mlo);
}

void func_8006E444(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u16 n;
    u8 *p;
    s32 *b1;
    register s32 *b2 asm("a2");
    register s32 mlo asm("a0");
    s32 i;

    n = D_801ECA2C;
    D_801ECA2C = n + 1;
    b1 = D_801ECACC;
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
    b2 = D_801ECACC;
    mlo = 0xFFFFFF;
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & 0xFF000000) | ((s32) p & mlo);
}

extern void func_801CD6E4();
extern void func_801CD93C();

void func_8006E610(u8 *arg0, u8 *arg1, s32 arg2, u16 arg3, u16 arg4, s32 arg5, s32 arg6) {
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
    s4 = arg1;
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
            a0 = (u16) D_801ECA84;
            v1 = (s32) D_801ECACC;
            v0 = a0 + 1;
            D_801ECA84 = v0;
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
            __asm__ volatile(".set\tnoreorder\n\tj func_801CD6E4\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
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
            a0 = (s32) D_801ECACC;
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

void func_8006E888(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4, u16 arg5, u16 arg6, s32 arg7) {
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
    s1 = arg0;
    s6 = arg5;
    KEEP_NOVOL(s6);
    a0 = (u16) D_801ECA84;
    D_801ECA84 = a0 + 1;
    s5 = arg6;
    s3 = arg1;
    s4 = arg2;
    __asm__("move %0,%1" : "=r"(s2) : "r"(arg3));
    s0 = (u8 *) &((EventCoord28 *) *(EventCoord28 **) ((u8 *) D_801ECACC + 0x10))[a0];
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
        __asm__ volatile(".set\tnoreorder\n\tj func_801CD93C\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
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
    a3 = (s32) D_801ECACC;
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006EA9C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006ED24);

extern void func_801CE1D4();

void func_8006F138(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
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

    s1 = arg0;
    s2 = arg1;
    s3 = arg2;
    s4 = arg3;
    a0 = (u16) D_801ECA84;
    D_801ECA84 = a0 + 1;
    v1 = (s32) D_801ECACC;
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
        __asm__ volatile(".set\tnoreorder\n\tj func_801CE1D4\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
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
    a3 = (s32) D_801ECACC;
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

extern s32 func_800254CC(s32 *, s32, s32, s32, s32);

void func_8006F334(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register u16 n asm("v1");
    s32 *p;
    register s32 *b1 asm("v0");
    register s32 *b2 asm("a2");
    register s32 *b3 asm("a3");
    register s32 i asm("s1");
    register s32 arg0_mask asm("a0");
    register s32 arg0_msb_mask asm("a1");
    register s32 arg0_copy asm("t0");
    register s32 arg1_copy asm("t1");
    register s32 arg2_copy asm("t2");

    arg0_copy = arg0;
    arg1_copy = arg1;
    arg2_copy = arg2;
    __asm__("" : "=r"(arg0_copy), "=r"(arg1_copy), "=r"(arg2_copy) : "0"(arg0_copy), "1"(arg1_copy), "2"(arg2_copy));
    i = arg4;
    b1 = D_801ECACC;
    n = D_801ECABC;
    p = (s32 *) (*(u8 **) ((u8 *) b1 + 0x60) + n * 0xC);
    D_801ECABC = n + 1;
    func_800254CC(p, arg0_copy, arg1_copy, arg2_copy, arg3);
    b2 = D_801ECACC;
    b3 = D_801ECACC;
    arg0_mask = 0xFFFFFF;
    i <<= 2;
    arg0_msb_mask = 0xFF000000;
    *(s32 *) p = (*(s32 *) p & arg0_msb_mask) | (*(s32 *) (i + *b2) & arg0_mask);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & arg0_msb_mask) | ((s32) p & arg0_mask);
}

extern void func_800253DC();

void func_8006F40C(void *arg0, s32 arg1) {
    u16 limit;
    register s32 i asm("s1");
    register s32 j asm("a0");
    u16 n;
    s32 *p;
    s32 *b1;
    register void *src asm("a2");
    register s32 *b3 asm("a3");
    register s32 mlo asm("a1");

    limit = D_801ECA90;
    src = arg0;
    __asm__("move %0, %1" : "=&r"(i) : "r"(arg1), "r"(src));
    if (limit < 0x64) {
        *(u16 *) ((u8 *) src + 2) += 0xF0;
    }
    n = D_801ECAB0;
    D_801ECAB0 = n + 1;
    b1 = D_801ECACC;
    p = (s32 *) (*(u8 **) ((u8 *) b1 + 0x5C) + n * 0xC);
    func_800253DC(p, src, src);
    b3 = D_801ECACC;
    mlo = 0xFFFFFF;
    j = i * 4;
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (j + *b3) & mlo);
    *(s32 *) (j + *b3) = (*(s32 *) (j + *b3) & 0xFF000000) | ((s32) p & mlo);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/BUNIT", func_8006F4F0);

extern u8 D_801E3740;
extern u8 D_801E3741;

s32 func_8006F5F8(void) {
    return D_801E3740 + (D_801E3741 << 1);
}

extern u16 D_801ECA08;

void func_8006F614(void) {
    D_801E3740 = 1;
    D_801ECA08 = 0xF0;
}

void func_8006F634(void) {
    D_801E3741 = 1;
    D_801ECA08 = 0;
}

extern s32 func_801C843C();
extern void func_801CE334(s32, s32, s32, s32, s32);
extern void func_801CD344(void *, void *, s32, s32);
extern u8 D_801E3744[];
extern u8 D_801ECA04;
extern u8 D_801ECA05;
extern u8 D_801ECA06;

s32 func_8006F650(void) {
    s32 temp_a0;
    s32 temp_a3;
    s32 var_s0;
    u8 *p;
    u8 temp_v1;
    u16 temp_v0;

    var_s0 = 1;
    temp_a0 = func_801C843C();
    if (D_801E3740 != 0) {
        temp_v0 = D_801ECA08 - (temp_a0 * 8);
        D_801ECA08 = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            D_801E3740 = 0;
            var_s0 = 0;
        }
        func_801CE334(0, 0, func_8002398C(0, 2, 0x100, 0) & 0xFFFF, 0, D_801ECAA0 - 2);
        temp_v1 = (u8) D_801ECA08;
        p = &D_801ECA04;
        D_801ECA06 = temp_v1;
        D_801ECA05 = temp_v1;
        temp_a3 = D_801ECAA0 - 1;
        *p = temp_v1;
        func_801CD344(D_801E3744, p, 1, temp_a3);
    }
    return var_s0;
}

s32 func_8006F734(void) {
    s32 temp_a0;
    s32 temp_a3;
    s32 var_s0;
    u8 *p;
    s32 unused[4];
    u8 temp_v1;
    u16 temp_v0;

    var_s0 = 1;
    temp_a0 = func_801C843C();
    if (D_801E3741 != 0) {
        temp_v0 = D_801ECA08 + (temp_a0 * 8);
        D_801ECA08 = temp_v0;
        if ((s16) temp_v0 >= 0x100) {
            var_s0 = 0;
            D_801E3741 = 0;
            D_801ECA08 = 0xFF;
        }
        func_801CE334(0, 0, func_8002398C(0, 2, 0x100, 0) & 0xFFFF, 0, D_801ECAA0 - 2);
        temp_v1 = (u8) D_801ECA08;
        p = &D_801ECA04;
        D_801ECA06 = temp_v1;
        D_801ECA05 = temp_v1;
        temp_a3 = D_801ECAA0 - 1;
        *p = temp_v1;
        func_801CD344(D_801E3744, p, 1, temp_a3);
    }
    return var_s0;
}

extern void func_80024960();
extern s32 func_800246D4();

void func_8006F82C(void) {
    func_800248FC();
    do {
    } while (func_800246D4(1) != 0);
}

void func_8006F85C(void) {
    func_80024960();
    do {
    } while (func_800246D4(1) != 0);
}

extern void func_800249C4();

void func_8006F88C(s32 arg0, s16 arg1, s16 arg2) {
    func_800249C4(arg0, arg1, arg2);
    do {
    } while (func_800246D4(1) != 0);
}
