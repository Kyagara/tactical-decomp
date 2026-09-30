#include "common.h"

extern void func_8001DD8C(void);
extern void func_8007371C(s32);

void func_8006C48C(s32 arg0) {
    if (arg0 == 0) {
        func_8001DD8C();
    }
    func_8007371C(arg0);
}

extern s32 D_8007407C[];
extern s32 D_800740BC[];
extern s32 D_80074100[];

s32 *func_8006C4C4(s32 *arg0) {
    s32 i;
    s32 *dst = arg0;
    s32 *src = D_8007407C;

    for (i = 15; i != -1; i--) {
        *dst++ = *src++;
    }
    dst = arg0 + 16;
    src = D_800740BC;
    for (i = 15; i != -1; i--) {
        *dst++ = *src++;
    }
    dst = arg0 + 32;
    src = D_80074100;
    for (i = 31; i != -1; i--) {
        *dst++ = *src++;
    }
    return arg0;
}

extern s32 D_80074078[];
extern s32 D_800740FC[];
extern void func_80073818(void *, s32);

s32 *func_8006C550(s32 *arg0) {
    s32 i;
    s32 *src = arg0;
    s32 *dst = D_8007407C;

    for (i = 15; i != -1; i--) {
        *dst++ = *src++;
    }
    dst = D_800740BC;
    src = arg0 + 16;
    for (i = 15; i != -1; i--) {
        *dst++ = *src++;
    }
    func_80073818(D_80074078, 0x20);
    func_80073818(D_800740FC, 0x20);
    return arg0;
}

u16 func_8006C5EC(u16 *arg0) {
    return *arg0;
}

void func_8006C5F8(s32 *a0, s32 a1) {
    if ((a1 & 1) != 0) {
        s32 rv0;
        register s32 rv1 asm("v1");
        __asm__ volatile(
            ".set\tnoreorder\n\tlui $3,0xf7ff\n\tlw $2,0($4)\n\t.set\treorder"
            : "=r"(rv0), "=r"(rv1));
        rv1 |= 0xFFFF;
        __asm__ volatile(
            ".set\tnoreorder\n\tj 0x80073628\n\tand $2,$2,$3\n\t.set\treorder" ::"r"(rv0), "r"(rv1));
    }
    *a0 |= 0x8000000;
    if ((a1 & 2) != 0) {
        register s32 rv1 asm("v1");
        s32 rv0;
        rv1 = 0x2000000;
        rv0 = *(volatile s32 *) a0;
        __asm__ volatile(
            ".set\tnoreorder\n\tj 0x80073654\n\tor $2,$2,$3\n\t.set\treorder" ::"r"(rv0), "r"(rv1));
    }
    {
        s32 t = *(volatile s32 *) a0;
        s32 m = 0xFDFF0000;
        m |= 0xFFFF;
        t &= m;
        *a0 = t;
    }
    func_80073818(a0, *(u16 *) a0);
}

extern void func_800738AC(void);

void func_8006C674(void) {
    func_800738AC();
}

extern void func_8007393C(void);

void func_8006C694(void) {
    func_8007393C();
}

extern void func_800739D4(void);

void func_8006C6B4(void) {
    func_800739D4();
}

extern void func_8001DDEC(s32, s32);

void func_8006C6D4(s32 arg0) {
    func_8001DDEC(0, arg0);
}

void func_8006C6F8(s32 arg0) {
    func_8001DDEC(1, arg0);
}

extern s32 *D_800741B4;
extern s32 *D_80074188;
extern s32 *D_80074194;
extern u8 D_80067044[];
extern void func_8002232C(u8 *);

void func_8006C71C(s32 arg0) {
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    a1v = arg0;
    if (a1v == 0) {
        goto zero;
    }
    v0v = 1;
    if (a1v == v0v) {
        goto one;
    }
    v0v = 0x80000000;
    KEEP(v0v);
    __asm__ volatile(".word 0x0801cdfe\n.word 0x00000000");
zero:
    v1v = (s32) D_800741B4;
    v0v = 0x80000000;
    *(s32 *) v1v = v0v;
    __asm__(".globl func_8006C750\nfunc_8006C750:");
    v0v = (s32) D_80074188;
    a0v = (s32) D_80074078;
    *(s32 *) v0v = 0;
    v0v = (s32) D_80074194;
    a1v = 0x20;
    *(s32 *) v0v = 0;
    v1v = (s32) D_800741B4;
    v0v = 0x60000000;
    *(s32 *) v1v = v0v;
    MEMORY_BARRIER();
    func_80073818(D_80074078, 0x20);
    func_80073818(D_800740FC, 0x20);
    __asm__ volatile(".word 0x0801ce02\n.word 0x00000000");
one:
    v1v = (s32) D_800741B4;
    *(s32 *) v1v = v0v;
    v0v = (s32) D_80074188;
    *(s32 *) v0v = 0;
    v0v = (s32) D_80074194;
    *(s32 *) v0v = 0;
    v0v = (s32) D_80074194;
    v1v = (s32) D_800741B4;
    v0v = *(volatile s32 *) v0v;
    v0v = 0x60000000;
    *(s32 *) v1v = v0v;
    __asm__ volatile(".word 0x0801ce02\n.word 0x00000000");
    func_8002232C(D_80067044);
}

extern s32 *D_80074180;
extern s32 *D_80074184;
extern s32 *D_800741B0;
extern s32 *D_800741B8;

void func_8006C818(s32 *arg0, u32 arg1) {
    func_8007393C();
    *D_800741B8 |= 0x88;
    *D_80074180 = arg0 + 1;
    *D_80074184 = ((arg1 >> 5) << 16) | 0x20;
    *D_800741B0 = *arg0;
    *D_80074188 = 0x1000201;
}

extern void func_800739D4();
extern s32 *D_8007418C;
extern s32 *D_80074190;

void func_8006C8AC(s32 arg0, u32 arg1) {
    func_800739D4();
    *D_800741B8 |= 0x88;
    *D_80074194 = 0;
    *D_8007418C = arg0;
    *D_80074190 = ((arg1 >> 5) << 0x10) | 0x20;
    *D_80074194 = 0x01000200;
}

extern s32 D_80067060;
extern void func_80073A6C(s32 *);

s32 func_8006C93C(void) {
    volatile s32 counter;
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    v1v = (s32) D_800741B4;
    counter = 0x100000;
    v0v = *(volatile s32 *) v1v;
    v1v = 0x20000000;
    v0v &= v1v;
    KEEP(v0v);
    __asm__ volatile(".word 0x10400018\n.word 0x00001021");
    a0v = -1;
    __asm__(".globl func_8006C96C\nfunc_8006C96C:");
loop:
    v0v = counter;
    v0v = v0v - 1;
    counter = v0v;
    v0v = counter;
    if (v0v != a0v) {
        goto check;
    }
    func_80073A6C(&D_80067060);
    __asm__ volatile(".word 0x0801ce71\n.word 0x2402ffff");
check:
    v0v = (s32) D_800741B4;
    v0v = *(s32 *) v0v;
    v0v &= v1v;
    __asm__ volatile(".word 0x1440ffeb\n.word 0x00001021");
end:
    return v0v;
}

extern u8 func_80067068[];

s32 func_8006C9D4(void) {
    volatile s32 counter;
    register s32 a0v asm("a0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    v1v = (s32) D_80074194;
    counter = 0x100000;
    v0v = *(volatile s32 *) v1v;
    v1v = 0x1000000;
    v0v &= v1v;
    KEEP(v0v);
    __asm__ volatile(".word 0x10400018\n.word 0x00001021");
    a0v = -1;
    __asm__(".globl func_8006CA04\nfunc_8006CA04:");
loop:
    v0v = counter;
    v0v = v0v - 1;
    counter = v0v;
    v0v = counter;
    if (v0v != a0v) {
        goto check;
    }
    __asm__(".globl func_8006CA2C\nfunc_8006CA2C:");
    func_80073A6C((s32 *) (func_80067068 + 8));
    __asm__ volatile(".word 0x0801ce97\n.word 0x2402ffff");
check:
    v0v = (s32) D_80074194;
    v0v = *(volatile s32 *) v0v;
    v0v &= v1v;
    __asm__ volatile(".word 0x1440ffeb\n.word 0x00001021");
end:
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open_4", func_8006CA6C);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open_4", func_8006CBF8);

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open_4", func_8006CDB4);
