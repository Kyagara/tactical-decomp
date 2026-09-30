#include "common.h"

extern void func_800248FC();
extern s32 func_8002398C();

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_8006000C);

extern void func_8014BF54();
extern u8 D_801CA3F4[];

void func_800601D4(u8 *arg0) {
    *(u16 *) (arg0 + 0x1C) = 0;
    *(u16 *) (arg0 + 0x26) = 0;
    func_8014BF54(arg0 + 0x20, D_801CA3F4, 8);
}

void func_80060208(u8 *arg0, u32 arg1) {
    u32 v = arg1 & 0x3F;

    v <<= 4;
    arg1 &= 0xFFFF;
    arg1 >>= 6;
    *(u16 *) arg0 = v;
    *(u16 *) (arg0 + 4) = 0x10;
    *(u16 *) (arg0 + 2) = arg1;
    *(u16 *) (arg0 + 6) = 1;
}

extern void func_80136BD0();
extern void func_801C8C08();

void func_80060234(s32 arg0, s32 arg1) {
    if (!(arg0 & 0x300)) {
        func_80136BD0(arg1, arg0);
    }
    if (arg0 & 0x200) {
        func_801C8C08(arg1, arg0 & 0xFF);
    }
}

void func_8006028C(u8 *arg0, s32 arg1) {
    s32 t0;
    s32 t1;
    s32 u0;
    s32 u1;

    if (arg0[0xC] != arg0[0x14]) {
        MEMORY_BARRIER();
        t0 = arg0[0xC] + arg1;
        t1 = arg0[0x1C] + arg1;
        arg0[0xC] = t0;
        TAIL_JUMP_SB_1C(func_801BF2D4, t1, arg0, t0);
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

void func_800602F0(u8 *arg0, s32 arg1) {
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
        TAIL_JUMP_SB_24(func_801BF34C, s24, arg0, s14);
    }
    m15 = arg0[0x15] - arg1;
    m25 = arg0[0x25] - arg1;
    arg0[0x15] = m15;
    arg0[0x25] = m25;
    MEMORY_BARRIER();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80060354);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_8006077C);

void func_8006187C(void) {
}

extern void func_80023C68(void *, s32);
extern void func_80023DD0(void *);
extern void func_80023DE4(void *);
extern void func_8014A6E4(void *, s32);

void func_80061884(u8 *arg0) {
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

void func_80061AA4(void) {
    func_8014CA80();
    func_8014C958();
}

void func_80061ACC(void) {
    func_8014CA80();
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80061AF4);

extern void func_80023C90(void *, s32);
extern void func_801C13D4();
extern s32 D_80166028;

void func_80062280(u8 *arg0, u8 *arg1) {
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
    TAIL_JUMP(func_801C13D4);
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

void func_800623FC(s32 arg0, u8 *arg1) {
    if (*(s32 *) (arg1 + 0x10) == 1 || D_80166028 == 1) {
        func_8012F454();
        TAIL_JUMP(func_801C1440);
    }
    func_8012F3CC();
}

extern void func_801C1500(s16);
extern void func_801C1508(s16);
extern void func_801C1650(s32, s32, s32, void *);

void func_80062450(s32 arg0, u8 *arg1, void *arg2, s32 arg3) {
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
            __asm__ volatile("\t.set\tnoreorder\n\tlhu $2,0($16)\n\tj func_801C1500\n\tnegu $4,$4\n\t.set\treorder" : : "r"(a0) : "memory");
        }
        if (a0 > 0) {
            v0 = 0xCCCCCCCC;
            *(volatile u32 *) (s1 + 0xC) = v0;
            __asm__ volatile("\t.set\tnoreorder\n\tlhu $2,0($16)\n\tj func_801C1508\n\tori $2,$2,0x400\n\t.set\treorder" ::: "memory");
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
        func_801C1650(a0, a1, a2, s1);
        *(u32 *) (s1 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

extern void func_801C1604(s16, s32);

void func_8006255C(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
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
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1604\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        if (a0 > 0) {
            a1 |= 0x400;
            v0 = 0xBBBBBBBB;
            __asm__ volatile("\t.set\tnoreorder\n\tj func_801C1604\n\tsw %2,0xC(%3)\n\t.set\treorder" : : "r"(a0), "r"(a1), "r"(v0), "r"(s0) : "memory");
        }
        *(volatile u32 *) (s0 + 0xC) = 0;
        MEMORY_BARRIER();
        a1 &= 0xFFF0;
        a1 |= 0x804;
        a2 = s5;
        func_801C1650(a0, a1, a2, s0);
        s1 += 0xC;
        s3 += 0xC;
        s2++;
        *(u32 *) (s0 + 0xC) = 0;
    } while (s2 < s4);
normal:
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80062650);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80062954);

extern void func_80136B10(u8 *);

void func_80062EB8(u8 *arg0) {
    u8 buf[24];

    func_80136B10(buf);
    *(u16 *) arg0 = buf[0xC];
    *(u16 *) (arg0 + 2) = buf[0xD];
    *(u16 *) (arg0 + 4) = 0x10;
    *(u16 *) (arg0 + 6) = 0x10;
    *(u16 *) (arg0 + 8) = *(u16 *) (buf + 0xE);
    *(u16 *) (arg0 + 0xA) = func_8002398C(0, 0, 0x380, 0x120);
}

void func_80062F20(void) {
}

extern s32 D_80165F98;

s32 func_80062F28(s32 arg0) {
    arg0 <<= 10;
    return *(s32 *) (arg0 + D_80165F98 + 0x48);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80062F44);

void func_80063418(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_8006365C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80063940);

void func_80063ADC(u8 *arg0, u8 *arg1, u16 *arg2, u8 *arg3, s16 *arg4, u16 *arg5) {
    register u8 *s1 asm("s1");
    register u8 *s0 asm("s0");
    register s32 s2 asm("s2");
    register s32 s3 asm("s3");
    register s32 s4 asm("s4");
    register s32 s5 asm("s5");
    register u16 *s6 asm("s6");
    register u16 *s7 asm("s7");
    register u8 *t3 asm("t3");
    s32 a0t;
    s32 v1t;
    register s32 f1 asm("a3");
    register s32 f2 asm("t0");
    register s32 f3 asm("t1");
    register s32 f4 asm("t2");
    s32 v0;
    int new_var;
    s32 a2t;
    s32 a1t;
    int new_var2;
    s32 a0t2;
    s32 v1t2;

    s1 = arg0;
    s0 = arg3;
    asm volatile("" : "=r"(s1), "=r"(s0) : "0"(s1), "1"(s0));
    a0t = arg4[0];
    s3 = (*((s16 *) (s0 + 8))) * a0t;
    v1t = arg4[1];
    s5 = (*((s16 *) (s0 + 0xA))) * v1t;
    s2 = (*((s16 *) (s0 + 4))) * a0t;
    s4 = (*((s16 *) (s0 + 6))) * v1t;
    t3 = arg1;
    s6 = arg2;
    __asm__("" : : "r"(t3), "r"(s6));
    f1 = 0;
    f2 = 0;
    f3 = 0;
    f4 = 0;
    s7 = *((u16 *volatile *) (&arg5));

    v0 = s3;
    if (s3 < 0) {
        v0 = s3 + 0xFFF;
    }
    a2t = v0 >> 12;
    v0 = s3 - (a2t << 12);
    if (v0 >= 0x800) {
        f1 = 1;
    }
    v0 = s5;
    if (s5 < 0) {
        v0 = s5 + 0xFFF;
    }
    a1t = v0 >> 12;
    v0 = s5 - (a1t << 12);
    if (v0 >= 0x800) {
        f2 = 1;
    }
    v0 = s2;
    if (s2 < 0) {
        v0 = s2 + 0xFFF;
    }
    a0t2 = v0 >> 12;
    v0 = s2 - (a0t2 << 12);
    if (v0 >= 0x800) {
        f3 = 1;
    }
    v0 = s4;
    if (s4 < 0) {
        v0 = s4 + 0xFFF;
    }
    v1t2 = v0 >> 12;
    v0 = s4 - ((v1t2 << 3) << 9);
    if (v0 >= 0x800) {
        f4 = 1;
    }
    s3 = a2t + f1;
    s5 = a1t + f2;
    s2 = a0t2 + f3;
    s4 = v1t2 + f4;
    if (s2 < 0) {
        s2 = -s2;
    }
    if (s4 < 0) {
        s4 = -s4;
    }
    *((u16 *) (s1 + 0x16)) = func_8002398C(1, 0, *((s16 *) t3), (*((u16 *) (t3 + 2))) & 0xF00);
    *(s1 + 0xC) = *s0;
    *(s1 + 0xD) = *(s0 + 2);
    *(s1 + 0x14) = (*s0) + (*(s0 + 4));
    *(s1 + 0x15) = *(s0 + 2);
    *(s1 + 0x1C) = *s0;
    *(s1 + 0x1D) = (*(s0 + 2)) + (*(s0 + 6));
    *(s1 + 0x24) = (*s0) + (*(s0 + 4));
    *(s1 + 0x25) = (*(s0 + 2)) + (*(s0 + 6));
    f1 = s3;
    *((u16 *) (s1 + 8)) = ((f1 + (*(s6 + 0))) + (*(s7 + 4))) + 0x100;
    v1t = s3;
    f2 = s5;
    *((u16 *) (s1 + 0xA)) = ((f2 + (*(s6 + 1))) + (*(s7 + 5))) + 0x78;
    *((u16 *) (s1 + 0x10)) = ((v1t + (*(s6 + 0))) + (*(s7 + 4))) + (s2 + 0x100);
    a0t = s3;
    v0 = s5;
    *((u16 *) (s1 + 0x12)) = ((v0 + (*(s6 + 1))) + (*(s7 + 5))) + 0x78;
    *((u16 *) (s1 + 0x18)) = ((a0t + (*(s6 + 0))) + (*(s7 + 4))) + 0x100;
    f3 = s5;
    *((u16 *) (s1 + 0x1A)) = ((f3 + (*(s6 + 1))) + (*(s7 + 5))) + (s4 + 0x78);
    *((u16 *) (s1 + 0x20)) = (new_var = ((*(s6 + 0)) + s3) + (*(s7 + 4))) + (s2 + 0x100);
    new_var2 = (*(s6 + 1)) + s5;
    *((u16 *) (s1 + 0x22)) = (new_var2 + (*(s7 + 5))) + (s4 + 0x78);
    asm volatile("" : : "r"(s2), "r"(s4), "r"(s3), "r"(s5));
}

extern void func_80023D1C(void *);
extern s32 func_80023A54(s32, s32);
extern void func_80023D08(void *);
extern void func_801C2ADC(void *, void *, void *, void *, EventDrawArgs);
extern u8 D_801CF648[];
extern u8 D_801CF7A4[];
extern u8 D_801CF7A6[];
extern u8 D_801CF819;
extern u8 D_801CD0B4[];

void func_80063DBC(u8 *arg0, u8 *arg1) {
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
    v0 = D_801CF819;
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
    a2 = *(s16 *) (D_801CF7A4 + s3);
    v0 = *(s16 *) (arg0 + 0xC);
    a2 = a2 * v0;
    v1 = *(s16 *) (D_801CF7A6 + s3);
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
    c1 = (s32) D_801CD0B4;
    buf[0] = a2;
    buf[1] = v1;
    args = (EventDrawArgs *) ((u8 *) buf - 8);
    v0 = (s32) buf;
    args->coords = (s16 *) v0;
    MEMORY_BARRIER();
    v0 = (s32) (arg0 + 0x18);
    args->extra = (u8 *) v0;
    table = D_801CF648;
    a2 = (s32) D_801CA3F4 + ((s32) table - (s32) table);
    func_801C2ADC((u8 *) c0, (u8 *) c1, (u8 *) a2, table + s5, *args);
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
    if (s4 < D_801CF819) {
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

void func_80064070(void) {
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80064078);

s16 func_800643A8(u8 *arg0) {
    return (s16) ((arg0[1] << 8) | arg0[0]);
}

extern s32 D_80173CA8;
extern void func_8001DBA8();
extern s32 func_8014CEB4();
extern s32 D_80043708;

void func_800643C4(void) {
    do {
        func_8001DBA8(0);
        D_80173CA8 = &D_80043708;
    } while (func_8014CEB4() != 0);
}

extern void func_80043F00();
extern void func_801C33C4();
extern s32 D_800435C4;
extern s32 D_80043A90;

void func_8006440C(s32 arg0, s32 arg1) {
    func_80043F00();
    if (arg0 != 0) {
        D_80173CA8 = &D_800435C4;
        func_8014CEB4(arg0, 1);
        func_801C33C4();
    }
    if (arg1 != 0) {
        D_80173CA8 = &D_800435C4;
        func_8014CEB4(arg1, 2);
        func_801C33C4();
    }
    if (arg0 != 0) {
        D_80173CA8 = &D_80043A90;
        func_8014CEB4(1, 0x7F, 0);
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_800644B4);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80064B00);

extern u8 D_801CD25C[];
extern u8 D_801DCC64[];
extern u8 D_801DCC00[];
extern s32 D_801DCC7C;

void func_80064CA8(void) {
    register s32 i asm("$5");
    register u8 *row asm("$4");
    register u8 *p asm("$3");
    register u8 *e asm("$6");
    register s32 b asm("$2");
    register s32 lim asm("$2");
    register s32 ff asm("$7");

    func_8014BF54(D_801DCC64, D_801CD25C, 0x14);
    i = 0;
    __asm__ volatile("ori %0,$zero,0xFF" : "=r"(ff));
    row = D_801DCC00;
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    for (;;) {
        __asm__ volatile("lw %0,D_801DCC7C" : "=r"(lim));
        if (i == lim) {
            goto cont;
        }
        ASM_NOP();
        p = row;
        e = row + 0x19;
        for (;;) {
            b = *(u8 *) p;
            if (b == ff) {
                goto next;
            }
            p++;
            D_801DCC64[b] = 0;
next:
            if ((s32) p < (s32) e) {
                continue;
            }
            ASM_NOP();
            break;
        }
cont:
        i++;
        row += 0x19;
        if (i < 4) {
            continue;
        }
        break;
    }
    __asm__(".set\treorder\n\t");
    return;
}

extern u8 D_801DCBE4[];

s32 func_80064D3C(s32 arg0) {
    register s32 r asm("$2");
    register s32 i asm("a3");
    register u8 *row asm("a1");
    register u8 *p asm("$3");
    register u8 *e asm("a2");

    r = 0;
    i = 0;
    row = D_801DCBE4;
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    for (;;) {
        p = row;
        e = row + 5;
        for (;;) {
            r = *p;
            if (r == arg0) {
                goto out;
            }
            __asm__ volatile(".set\tnoreorder\n\tori $2,$zero,1\n\t.set\treorder");
            p++;
            if ((s32) p < (s32) e) {
                continue;
            }
            break;
        }
        i++;
        if (i < 5) {
            row += 5;
            continue;
        }
        break;
    }
    r = 0;
out:
    __asm__(".set\treorder\n\t");
    return r;
}

void func_80064D8C(void) {
    func_8014CA80();
    TAIL_JUMP(func_801C3D94);
}

s32 func_80064DB4(s32 arg0) {
    register s32 r asm("$2");
    register s32 i asm("a3");
    register u8 *row asm("a1");
    register u8 *p asm("$3");
    register u8 *e asm("a2");

    r = 0;
    i = 0;
    row = D_801DCBE4;
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    for (;;) {
        p = row;
        e = row + 5;
        for (;;) {
            r = *p;
            if (r == arg0) {
                goto out;
            }
            __asm__ volatile(".set\tnoreorder\n\tori $2,$zero,1\n\t.set\treorder");
            p++;
            if ((s32) p < (s32) e) {
                continue;
            }
            break;
        }
        i++;
        if (i < 5) {
            row += 5;
            continue;
        }
        break;
    }
    r = 0;
out:
    __asm__(".set\treorder\n\t");
    return r;
}

void func_80064E04(s32 arg0) {
    register u8 m asm("t0");
    s32 i;
    u8 *row;
    u8 *p;
    u8 *e;

    i = 0;
    m = 0xFF;
    row = D_801DCBE4;
    for (;;) {
        p = row;
        e = row + 5;
        for (;;) {
            if (*p == arg0) {
                __asm__ volatile(".set\tnoreorder\n\t"
                                 "j func_801C3E54\n\t"
                                 "sb %0,0(%1)\n\t"
                                 ".set\treorder\n\t" ::"r"(m),
                                 "r"(p));
            }
            p++;
            if ((s32) p < (s32) e) {
                continue;
            }
            break;
        }
        i++;
        if (i < 5) {
            row += 5;
            continue;
        }
        break;
    }
}

void func_80064E5C(s32 arg0, s32 arg1, s32 arg2) {
    register s32 i asm("$9");
    register u8 *row asm("$3");
    register u8 *p asm("$4");
    register u8 *e asm("$7");
    register u8 *t0 asm("$8");
    register u8 b asm("$5");
    register u8 c asm("$2");
    s32 v;
    register s32 w asm("$2");

    i = 0;
    row = D_801DCBE4;
    w = (s32) row + arg1 * 5;
    t0 = (u8 *) (w + arg0);
    for (;;) {
        p = row;
        e = row + 5;
        for (;;) {
            b = *p;
            if (b == arg2) {
                c = *t0;
                *p = c;
                __asm__ volatile(".set\tnoreorder\n\t"
                                 "j func_801C3EC4\n\t"
                                 "sb %0,0(%1)\n\t"
                                 ".set\treorder\n\t" ::"r"(b),
                                 "r"(t0));
            }
            p++;
            v = (s32) p < (s32) e;
            if (v != 0) {
                continue;
            }
            break;
        }
        i++;
        if (i < 5) {
            row += 5;
            continue;
        }
        break;
    }
}

void func_80064ECC(void) {
    register u8 m asm("a2");
    register s32 i asm("a0");
    register u8 *p asm("a1");
    register s32 v asm("v0");
    register s8 *q asm("v1");

    i = 0;
    m = 0xFF;
    p = D_801DCBE4;
    for (;;) {
        v = 4;
        q = p + 4;
        for (;;) {
            *q = m;
            v--;
            q--;
            if (v >= 0) {
                continue;
            }
            break;
        }
        i++;
        p += 5;
        if (i < 5) {
            continue;
        }
        break;
    }
    i = 0;
    m = 0xFF;
    p = D_801DCC00;
    for (;;) {
        v = 0x18;
        q = p + 0x18;
        for (;;) {
            *q = m;
            v--;
            q--;
            if (v >= 0) {
                continue;
            }
            break;
        }
        i++;
        p += 0x19;
        if (i < 4) {
            continue;
        }
        break;
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80064F44);

extern s32 D_801D5B04;
extern u8 D_801DCAC4[];
extern u8 D_801DCAAC[];

s32 func_80066A50(void) {
    register s32 v asm("$2");

    __asm__ volatile("lui $2,%hi(D_801D5B04)\n\t"
                     "lw $2,%lo(D_801D5B04)($2)\n\t"
                     "nop\n\t");
    __asm__(".set noreorder\n\t.set\tnoreorder\n\t");
    if (v != 0) {
        __asm__ volatile("ori $2,$zero,1");
        v = (s32) D_801DCAC4;
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801C5A84\n\t"
                         "nop\n\t"
                         ".set\treorder\n\t" ::"r"(v));
    }
    D_801D5B04 = v;
    __asm__(".set\treorder\n\t");
    return (s32) D_801DCAAC;
}

s32 func_80066A8C(void) {
    return 0;
}

extern s32 *func_8014A578(s32);
extern void func_8014C8A0();
extern s32 func_8014CA1C(s32);
extern s32 D_80165FB4;
extern s32 D_801C60E0;
extern s32 D_801C61E4;
extern s8 D_801CF5F0;
extern s8 D_801CF5F1;

void func_80066A94(void) {
    s32 *temp_v0;

    temp_v0 = func_8014A578(0);
    if ((*temp_v0 & 4) && (func_8014CA1C(4) == 0)) {
        D_801CF5F0 = 7;
        D_80165FB4 = 6;
        func_8014C8A0(4, &D_801C61E4);
    }
    if ((*temp_v0 & 8) && (func_8014CA1C(4) == 0)) {
        D_801CF5F1 = 7;
        D_80165FB4 = 6;
        func_8014C8A0(4, &D_801C60E0);
    }
}

extern void func_801C3CA8();
extern void func_801C5B68(u8 *);
extern void func_801C5BE0(s32, s32);
extern s32 D_801CD064;
extern s32 D_801CD210;

void func_80066B50(void) {
    u8 *base;
    register u8 *addr asm("v0");
    s32 index;

    func_801C3CA8();
    base = D_801DCC64;
    USE_NOVOL(base);
    if (D_801CD064 >= 0x14) {
        D_801CD064 = 0;
    }
    index = D_801CD064;
    addr = base + index;
    if (*addr == 0) {
        D_801CD064 += 1;
        TAIL_JUMP(func_801C5B68);
    }
    D_801CD210 = 0;
    func_801C5BE0(1, D_801CD064);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80066BE0);

extern void func_801C5BE0();
extern s32 func_801C3D3C();
extern volatile s32 D_801CD064;
extern s32 D_801CD068;
extern s32 D_801CD21C;
extern s32 D_801CD220;
extern s32 D_801CD230;
extern s32 D_801CD244;

void func_800670E0(void) {
    s32 head;
    s32 tmp;
    u8 *v1;

    func_801C3CA8();
    head = D_801CD068;
    if (head != -1) {
        D_801CD064 = head;
        D_801CD068 = -1;
        TAIL_JUMP(func_801C6170);
    }
    v1 = D_801DCC64;
    do {
        tmp = D_801CD064 + 1;
        D_801CD064 = tmp;
        if (tmp >= 0x14) {
            D_801CD064 = 0;
        }
    } while (*(volatile u8 *) (D_801CD064 + (s32) v1) == 0);
    func_801C5BE0(1, D_801CD064);
    D_801CD21C = 1;
    D_801CD210 = 0;
    D_801CD230 = 1;
    D_801CD244 = 1;
    D_801CD220 = func_801C3D3C(D_801CD064);
    func_8014CA80();
    func_8014C958();
}

void func_800671DC(void) {
}

void func_800671E4(void) {
    register s32 c asm("a0");
    s32 head;
    s32 tmp;
    u8 *v1;

    func_801C3CA8();
    head = D_801CD068;
    c = 0x13;
    if (head != -1) {
        D_801CD064 = head;
        D_801CD068 = -1;
        TAIL_JUMP(func_801C6270);
    }
    v1 = D_801DCC64;
    do {
        tmp = D_801CD064 - 1;
        D_801CD064 = tmp;
        if (tmp < 0) {
            D_801CD064 = c;
        }
    } while (*(volatile u8 *) (D_801CD064 + (s32) v1) == 0);
    func_801C5BE0(1, D_801CD064);
    D_801CD21C = 2;
    D_801CD210 = 0;
    D_801CD230 = 1;
    D_801CD244 = 1;
    D_801CD220 = func_801C3D3C(D_801CD064);
    func_8014CA80();
    func_8014C958();
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_800672E0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_8006751C);

extern u8 D_801DCBC8[];

void func_800676DC(s32 arg0, s32 arg1, u8 arg2) {
    u8 *p;
    u8 *q;
    p = D_801DCBC8;
    q = p + arg1 * 5;
    q[arg0] = arg2;
}

u8 func_800676FC(s32 arg0, s32 arg1) {
    u8 *p;
    u8 *q;
    p = D_801DCBC8;
    q = p + arg1 * 5;
    return q[arg0];
}

extern s32 D_801CD24C;
extern s32 D_801CD254;

void func_80067720(s32 arg0, s32 arg1) {
    D_801CD24C = arg0;
    D_801CD254 = arg1;
}

extern s32 D_801CD06C;

void func_80067738(s32 arg0) {
    D_801CD06C = arg0;
}

extern void func_8014CA38();
extern void func_801C7288();
extern s32 D_801C67CC;
extern s32 D_801CD070;
extern s32 D_801CD074;
extern s32 D_801CD078;
extern s32 D_801CD07C;
extern s32 D_801CD080;
extern s32 D_801DB650;

void func_80067748(void) {
    D_801CD080 = 1;
    D_801CD070 = 5;
    D_801CD074 = 0;
    D_801CD078 = 0;
    D_801CD07C = 0;
    D_801CD06C = 0;
    func_801C7288(&D_801DB650);
    func_8014C8A0(0xF, &D_801C67CC);
    func_8014CA38(0xF, 0, 0, 0);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_800677CC);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80068288);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_8006855C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80068720);

extern void func_8012E198(void *);
extern u8 D_801DB832[];
extern u8 D_801DB844[];
extern u8 D_801DB85A[];

void func_80068944(void) {
    register u8 *var_s0 asm("s0");
    register s32 var_s1 asm("s1");
    register u8 *var_s2 asm("s2");
    register s32 var_s3 asm("s3");
    register u8 *base_v0 asm("v0");

    var_s3 = 0;
    var_s1 = 0x28;
    base_v0 = D_801DB844;
    var_s0 = base_v0 + 0x28;
    var_s2 = base_v0;
    do {
        func_8012E198(var_s2);
        func_8012E198(var_s0);
        *(u16 *) (D_801DB832 + var_s1) = func_8002398C(0, 0, 0x140, 0);
        *(u16 *) (D_801DB85A + var_s1) = func_8002398C(0, 2, 0x3C0, 0x100);
        func_80023C68(var_s0, 1);
        var_s1 += 0x50;
        var_s0 += 0x50;
        var_s3 += 2;
        var_s2 += 0x50;
    } while (var_s3 < 0xA);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80068A08);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80068BEC);

extern void func_801C8598();

void func_80068FE4(void) {
    func_801C8598();
}

extern void func_801C80D0();

void func_80069004(void) {
    func_801C80D0();
}

extern s32 D_80044694;
extern s32 D_800446C8;
extern void func_801C8050();
extern void func_801C8088();

void func_80069024(s32 arg0, s32 arg1, s32 arg2) {
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
        TAIL_JUMP(func_801C8050);
    }
    USE(r3);
    r0 = &D_800446C8;
    D_80173CA8 = r0;
    if (func_8014CEB4() != 0) {
        func_8014CA80();
        TAIL_JUMP(func_801C8088);
    }
    USE2(r1, r2);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_800690D0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80069598);

void func_80069C08(u8 *arg0, s32 arg1) {
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_80069CF0);

extern s32 D_80173F8C[];

void func_8006A444(s32 *arg0) {
    s32 i;
    s32 *d;
    s32 base;
    i = 0;
    base = (s32) arg0 + 0x80;
    d = D_80173F8C;
    while (i < 0x20) {
        if (i != 0) {
            d[0] = base + arg0[0];
        }
        arg0++;
        i++;
        d++;
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_8006A488);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/ATTACK", func_8006A92C);

extern s32 func_8014CC28();
extern void func_801C992C(void *, s32, s32, s32);
extern s32 D_801CD054;
extern u8 D_801DDA64[];

void func_8006AD68(void) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s2;

    var_s2 = func_8014CC28();
    var_s0 = 0;
    if (var_s2 == 0) {
        var_s2 = 1;
    }
    var_s1 = 8;
    do {
        var_s0 ^= 1;
        func_801C992C((var_s0 * 0xD0) + D_801DDA64, var_s1, 0x80, 0);
        var_s1 += var_s2;
        func_8014CA80();
    } while (var_s1 < 0xF8);
    var_s1_2 = 0;
    do {
        var_s0 ^= 1;
        func_801C992C((var_s0 * 0xD0) + D_801DDA64, 0xF8, 0x80, 0);
        var_s1_2 += var_s2;
        func_8014CA80();
    } while (var_s1_2 < 0x6E);
    var_s1_3 = 8;
    do {
        var_s0 ^= 1;
        func_801C992C((var_s0 * 0xD0) + D_801DDA64, var_s1_3, 0x80, 1);
        if (var_s1_3 >= 0x81) {
            D_801CD054 = 1;
        }
        var_s1_3 += var_s2;
        func_8014CA80();
    } while (var_s1_3 < 0xF9);
    func_8014C958();
}

extern s32 func_8012EEB0();
extern void func_8012F04C();
extern s32 func_8013B590();
extern s32 D_80044954;
extern s32 D_801D5FC0;
extern s32 D_801D5FC8;
extern s32 D_801D5FF0;

void func_8006AEC0(void) {
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;
    s32 temp_d;
    temp_s1 = func_8012EEB0(0x2800);
    temp_v0 = func_8013B590(0x33);
    temp_v1 = temp_v0 - 1;
    var_a1 = temp_v1;
    if (temp_v1 < 0) {
        var_a1 = temp_v0 + 2;
    }
    temp_s0 = var_a1 >> 2;
    temp_d = temp_s0;
    temp_d = temp_v1 - (temp_d * 4);
    if (temp_v1 != 0xFF) {
        D_80173CA8 = &D_80044954;
        func_8014CEB4((temp_s0 * 5) + 0xDAC, 0x2800, temp_s1);
    }
    func_800248FC(&D_801D5FC0, temp_s1 + (temp_d * 0xA00));
    func_800248FC(&D_801D5FC8, &D_801D5FF0);
    func_8012F04C(temp_s1);
}
