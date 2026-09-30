#include "common.h"

extern void func_800248FC();

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80060004);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80060198);

extern void func_800222FC();
extern u8 D_801FA530[];

void func_80060478(void) {
    func_800222FC(D_801FA530, 0, 0x1E);
}

void func_800604A4(s32 arg0) {
    func_800222FC(&D_801FA530[arg0 * 6], 0, 6);
}

extern u8 A0[] asm("D_801FA530");
extern u8 A2[] asm("D_801FA532");
extern u8 A4[] asm("D_801FA534");

void func_800604E0(s32 arg0, s32 arg1, s16 arg2, u8 *arg3) {
    *(s16 *) &A0[arg0 * 6] = arg1;
    *(s16 *) &A2[arg0 * 6] = arg2;
    *(s16 *) &A4[arg0 * 6] = *(u16 *) (arg3 + arg1 * 2) & 0x3FF;
}

extern u8 D_801FA532[];
extern u8 D_801FA534[];

void func_8006052C(s32 arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 t0v asm("$8");

    *(s16 *) arg1 = ((s16 *) D_801FA530)[arg0 * 3];
    *(s16 *) arg2 = ((s16 *) D_801FA532)[arg0 * 3];
    t0v = ((s16 *) D_801FA534)[arg0 * 3];
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
                         "j func_801DF5D4\n\t"
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

extern volatile s32 D_801FA5B0;
extern s32 func_801E0390();
extern s16 D_801FA550[];
extern s32 D_801FA7F8;

s32 func_800605DC(s32 arg0) {
    s32 lookup;
    register s32 extracted_value;
    s32 packed_nibbles;

    lookup = func_801E0390(D_801FA550[arg0]);
    packed_nibbles = *(u8 *) ((u8 *) D_801FA7F8 + (lookup >> 1) + 0x44);
    D_801FA5B0 = packed_nibbles;
    if (lookup & 1) {
        extracted_value = packed_nibbles & 0xF;
    } else {
        extracted_value = packed_nibbles >> 4;
    }
    D_801FA5B0 = extracted_value;
    return D_801FA5B0;
}

extern u32 D_801FA5B4;
extern u32 D_801FA5B8;

void func_80060648(s32 arg0) {
    s32 v;

    v = func_801E0390(D_801FA550[arg0]);
    v <<= 1;
    D_801FA5B4 = *(u16 *) (v + D_801FA7F8 + 0x4E);
}

void func_80060694(s32 arg0) {
    s32 v;

    v = func_801E0390(D_801FA550[arg0]);
    v <<= 1;
    D_801FA5B8 = *(u16 *) (v + D_801FA7F8 + 0x76);
}

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_800606E0\nfunc_800606E0:\n\taddiu $29,$29,-24\n\tsll $4,$4,1\n\tsw $31,16($29)\n\tlui $1,%hi(D_801FA550)\n\taddu $1,$1,$4\n\tlh $4,%lo(D_801FA550)($1)\n\t.word 0x0c0780e4\n\tnop\n\tlui $2,%hi(D_801FA5B0)\n\tlw $2,%lo(D_801FA5B0)($2)\n\tnop\n\tandi $3,$2,0xF\n\tslti $2,$3,8\n\tbnez $2,1f\n\tnop\n\tlui $2,%hi(D_801FA5BC)\n\tlw $2,%lo(D_801FA5BC)($2)\n\tlui $3,0x2000\n\t.word 0x08077dd0\n\tor $2,$2,$3\n1:\n\tsll $2,$3,1\n\tlui $1,%hi(D_80066184)\n\taddu $1,$1,$2\n\tlhu $2,%lo(D_80066184)($1)\n\tlui $1,%hi(D_801FA5BC)\n\tsw $2,%lo(D_801FA5BC)($1)\n\tlui $2,%hi(D_801FA5BC)\n\tlw $2,%lo(D_801FA5BC)($2)\n\tlw $31,16($29)\n\taddiu $29,$29,24\n\tjr $31\n\tnop\n\t.set at\n");

extern s32 func_801E03BC();
extern s32 D_801FA5C0;

void func_80060760(s32 arg0) {
    s16 buf[24];

    D_801FA5C0 = func_801E03BC(0, D_801FA550[arg0], 0xF, buf, 2) == 0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_800607AC);

u32 func_80060964(void) {
    return D_801FA5B4;
}

extern s32 D_801FA5B0;

s32 func_80060974(void) {
    return D_801FA5B0;
}

extern u32 D_801FA5BC;

u32 func_80060984(void) {
    return D_801FA5BC;
}

u32 func_80060994(void) {
    return D_801FA5B8;
}

s32 func_800609A4(void) {
    return D_801FA5C0;
}

extern u16 D_801FA57C[];
extern u8 *D_801F0050;
extern s32 D_801FA5C4;
extern s32 func_8005A72C(s32, void *, void *);

s32 func_800609B4(s32 arg0) {
    u16 *p;
    s32 base;
    void *y;
    void *x;
    u16 t;
    s32 ret;
    s32 r;

    base = (s32) D_801FA57C;
    p = (u16 *) ((u8 *) base + arg0 * 2);
    x = (void *) &D_801F0050;
    t = *p;
    __asm__ volatile("lui %0,%%hi(D_801F0050)\n\t"
                     "addiu %0,%0,%%lo(D_801F0050)\n\t" : "=r"(y));
    ret = func_8005A72C(t & 0x3FF, x, y);
    D_801FA5C4 = ret;
    r = 0;
    if (ret != 0) {
        t = *p;
        r = (t >> 14) == 0;
    }
    return r;
}

s32 func_80060A24(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (D_801FA5C4 != 0) {
        var_v1 = (D_801FA57C[arg0] >> 0xE) != 0;
    }
    return var_v1;
}

s32 func_80060A5C(void) {
    return !D_801FA5C4;
}

extern u16 D_8005EBF0[][4];

u32 func_80060A6C(s32 arg0) {
    s32 t;
    u32 r;

    __asm__ volatile("lui $at,%%hi(D_801FA57C)\n\t"
                     "addu $at,$at,%1\n\t"
                     "lh %0,%%lo(D_801FA57C)($at)\n\t"
                     : "=r"(t)
                     : "r"(arg0 << 1));
    r = 0x20000000;
    if (!(t & 0x2000)) {
        r = D_801F0050[0xD];
    }
    if ((t >> 14) != 0) {
        r |= 0x40000000;
    }
    return r;
}

u32 func_80060AB8(s32 arg0) {
    u32 r;
    s32 t;
    u32 v;

    __asm__ volatile("lui $at,%%hi(D_801FA57C)\n\t"
                     "addu $at,$at,%1\n\t"
                     "lh %0,%%lo(D_801FA57C)($at)\n\t"
                     : "=r"(t)
                     : "r"(arg0 << 1));
    r = 0x20000000;
    if (!(t & 0x2000)) {
        r = D_801F0050[0xC];
        v = (s32) 100 / (s32) r;
        r = v + (((s32) 100 % (s32) r) != 0);
    }
    if ((t >> 14) != 0) {
        r |= 0x40000000;
    }
    return r;
}

u32 func_80060B1C(s32 arg0) {
    s32 t;
    u32 r;

    __asm__ volatile("lui $at,%%hi(D_801FA57C)\n\t"
                     "addu $at,$at,%1\n\t"
                     "lh %0,%%lo(D_801FA57C)($at)\n\t"
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

s32 func_80060B6C(s32 arg0) {
    return ((D_801FA57C[arg0] >> 14) ^ 1) & 1;
}

extern s16 D_801E5232;

s32 func_80060B90(void) {
    return !D_801E5232;
}

s32 func_80060BA0(void) {
    return !(D_801E5232 ^ 1);
}

s32 func_80060BB8(void) {
    return !(D_801E5232 ^ 2);
}

s32 func_80060BD0(void) {
    return !(D_801E5232 ^ 3);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80060BE8);

s32 func_80060FA0(s32 arg0) {
    s32 v;
    v = arg0 - 0x3C;
    v = (u32) v < 0xE;
    if ((u32) (arg0 - 0x90) < 0xB) {
        v = 1;
    }
    return v;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80060FC0);

extern s32 func_80180AFC();
extern void func_801DFFC0(s32, s32);
extern s32 D_801FA5C8;

void func_80061128(void) {
    register s32 s0 asm("$16");
    register s32 a0 asm("$4");
    s32 temp;

    temp = func_80180AFC();
    a0 = temp;
    s0 = (s32) &D_801FA5C8;
    func_801DFFC0(a0, s0);
    D_801FA7F8 = s0;
}

__asm__(".text\n\t.set noat\n\t.set noreorder\n\tsll $4,$4,16\n\tsra $4,$4,14\n\tlui $1,%hi(D_801FA7F8)\n\taddu $1,$1,$4\n\tlw $4,%lo(D_801FA7F8)($1)\n\tnop\n\tlbu $3,7($4)\n\tori $2,$zero,0x82\n\t.word 0x14620004\n\tnop\n\tlh $3,0($4)\n\t.word 0x0807806b\n\tnop\n1:\n\tsltiu $2,$3,0x80\n\tbnez $2,2f\n\tnop\n\tori $3,$zero,0x4A\n2:\n\t.word 0x03e00008\n\taddu $2,$3,$zero\n\t.set at\n");

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_800611B4);

extern u8 *func_8005A8A4();

s32 func_80061314(s32 arg0) {
    s32 i = 0;

    do {
        if (*func_8005A8A4(i) == arg0) {
            return i;
        }
        i++;
    } while (i < 0xA0);
    return -1;
}

s32 func_8006136C(void) {
    return *func_8005A8A4();
}

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_80061390\nfunc_80061390:\n\taddiu $2,$4,-0x4A\n\tandi $2,$2,0xFFFF\n\tsltiu $2,$2,0x14\n\tbeqz $2,1f\n\tnop\n\t.word 0x080780ec\n\t.word 0x2482ffb6\n1:\n\taddu $2,$zero,$zero\n\tsll $2,$2,16\n\t.word 0x03e00008\n\t.word 0x00021403\n\t.set at\n");

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_800613BC);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_8006160C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80061740);

s32 func_80061794(s32 arg0) {
    return arg0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_8006179C);

struct func_80061A24_fields {
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

extern void func_801E079C();
extern void func_801E1FF0();

void func_80061A24(s32 arg0, s16 *arg1, void *arg2, s32 arg3) {
    s32 lowpad[6];
    u8 sp28[0x800];
    struct func_80061A24_fields f;
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
        __asm__ volatile(".L80061A24_loop:");
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
            ((void (*)(void)) func_801E079C)();
            func_801E1FF0(&f.f830, (void *) &sp28[0]);
            v0 = *(u16 *) &f.f832;
            s0v = s0v + 2;
            v0 = v0 + 0x10;
            f.f832 = (u16) v0;
            v0 = *(s16 *) s0v;
            a3v = *(u16 *) s0v;
            __asm__ volatile(".set\tnoreorder\n\tbne $2,$17,.L80061A24_loop\n\taddiu $4,$29,0x28\n\t.set\treorder" : : "r"(v0), "r"(a3v), "r"(s1v) : "memory");
        } while (0);
    }
}

extern void func_80134020();
extern void func_80133FE8();
extern void func_8014C8A0();
extern void func_8014CA38();
extern u8 D_801E5508[];
extern u8 D_801308C0[];
extern s32 D_801FA818;
extern s32 D_80166028;

void func_80061B2C(s32 arg0) {
    if (D_801FA818 > 0) {
        func_80134020();
        func_80133FE8(&D_801E5508);
        func_8014C8A0(1, &D_801308C0);
        func_8014CA38(1, arg0 + 0x38, D_801FA818, 0);
        D_80166028 = 1;
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80061BA8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80061EE8);

extern u8 D_801FA6BA[];

void func_80062050(void) {
    s32 i;
    s16 *p;
    i = 7;
    p = (s16 *) D_801FA6BA;
    for (; i >= 0; i--) {
        *p = 0;
        p--;
    }
}

extern u8 D_801FA6AC[];
extern void func_801E1100();
extern void func_801E10FC();

s32 func_80062074(s32 arg0, s32 arg1, s32 arg2) {
    register s32 a3 asm("$7");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register u8 *q1 asm("$3");
    register s32 lim asm("$2");
    s32 idx;

    a3 = arg0;
    if (arg2 & 0x8000) {
        idx = arg1 & 0xFF;
        q1 = D_801FA6AC;
        q1 = q1 + (idx << 1);
        __asm__ volatile("lhu %0,0(%1)\n\tnop" : "=r"(v0) : "r"(q1));
        __asm__ volatile(".set\tnoreorder\n\t.set noreorder\n\t");
        if (v0 != 0) {
            __asm__ volatile("addiu $2,$4,-1");
            __asm__ volatile("lhu %0,0(%1)\n\tnop" : "=r"(v0) : "r"(q1));
            v0 = v0 - 1;
        }
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801E1100\n\t"
                         "sh %0,0(%1)\n\t"
                         ".set\treorder" ::"r"(v0),
                         "r"(q1) : "memory");
    }
    if (arg2 & 0x2000) {
        idx = arg1 & 0xFF;
        v1 = (s32) D_801FA6AC;
        v0 = idx << 1;
        arg0 = v0 + v1;
        v1 = *(u16 *) arg0;
        lim = (a3 & 0xFFFF) - 1;
        v1 = v1 < lim;
        if (v1 != 0) {
            __asm__ volatile("lhu %0,0(%1)" : "=r"(v0) : "r"(arg0));
            __asm__ volatile(".set\tnoreorder\n\t"
                             "j func_801E10FC\n\t"
                             "addiu %0,%0,1\n\t"
                             ".set\treorder" ::"r"(v0) : "memory");
        }
        __asm__ volatile("addu $2,$zero,$zero");
        *(u16 *) arg0 = v0;
    }
    return *(u16 *) (D_801FA6AC + ((arg1 & 0xFF) << 1));
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_8006211C);

extern void func_80023C68(void *, s32);
extern void func_80023C90(void *, s32);
extern void func_801CD93C();
extern void func_801E1430();
extern s16 D_801FA798;
extern s32 *D_801FA7D0;

void func_8006235C(u8 *arg0, u8 *arg1, s32 arg2, u16 arg3, u16 arg4, s32 arg5, s32 arg6) {
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
            a0 = (u16) D_801FA798;
            v1 = (s32) D_801FA7D0;
            v0 = a0 + 1;
            D_801FA798 = v0;
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
            __asm__ volatile(".set\tnoreorder\n\tj func_801E1430\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
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
            a0 = (s32) D_801FA7D0;
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

extern void func_801E1688();

void func_800625D4(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4, u16 arg5, u16 arg6, s32 arg7) {
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
    a0 = (u16) D_801FA798;
    D_801FA798 = a0 + 1;
    s5 = arg6;
    s3 = arg1;
    s4 = arg2;
    __asm__("move %0,%1" : "=r"(s2) : "r"(arg3));
    s0 = (u8 *) &((EventCoord28 *) *(EventCoord28 **) ((u8 *) D_801FA7D0 + 0x10))[a0];
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
        __asm__ volatile(".set\tnoreorder\n\tj func_801E1688\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
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
    v0 = *(u16 *) (s1 + 2);
    v1 = *(u16 *) (s1 + 6);
    SCHED_BARRIER();
    s0[0xC] = s3;
    s0[0xD] = s4;
    *(u16 *) (s0 + 0x22) = v0 + v1;
    v0 = *(u8 *) (s1 + 4);
    SCHED_BARRIER();
    s0[0x15] = s4;
    s0[0x1C] = s3;
    s0[0x14] = s3 + v0;
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
    a3 = (s32) D_801FA7D0;
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_800627E8);

extern void func_801E1CA4();

void func_80062C08(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
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
    a0 = (u16) D_801FA798;
    D_801FA798 = a0 + 1;
    v1 = (s32) D_801FA7D0;
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
        __asm__ volatile(".set\tnoreorder\n\tj func_801E1CA4\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
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
    a3 = (s32) D_801FA7D0;
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
extern s16 D_801FA7CC;

void func_80062E04(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
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

    v1 = *(u16 *) &D_801FA7CC;
    s2 = arg0;
    s3 = arg1;
    s4 = arg2;
    s1 = arg3;
    v0 = v1 + 1;
    s0 = v1 << 1;
    D_801FA7CC = v0;
    v0 = (s32) D_801FA7D0;
    s0 += v1;
    s0 <<= 3;
    v0 = *(s32 *) ((u8 *) v0 + 0x58);
    s0 += v0;
    func_80023EA0((void *) s0);
    v0 = *(u16 *) s2;
    a2 = D_801FA7D0;
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
extern u16 D_801FA7A4;
extern s16 D_801FA7BC;

void func_80062F0C(void *arg0, s32 arg1) {
    u16 limit;
    register s32 i asm("s1");
    register s32 j asm("a0");
    u16 n;
    s32 *p;
    s32 *b1;
    register void *src asm("a2");
    register s32 *b3 asm("a3");
    register s32 mlo asm("a1");

    limit = D_801FA7A4;
    src = arg0;
    __asm__("move %0, %1" : "=&r"(i) : "r"(arg1), "r"(src));
    if (limit < 0x64) {
        *(u16 *) ((u8 *) src + 2) += 0xF0;
    }
    n = D_801FA7BC;
    D_801FA7BC = n + 1;
    b1 = D_801FA7D0;
    p = (s32 *) (*(u8 **) ((u8 *) b1 + 0x5C) + n * 0xC);
    func_800253DC(p, src, src);
    b3 = D_801FA7D0;
    mlo = 0xFFFFFF;
    j = i * 4;
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (j + *b3) & mlo);
    *(s32 *) (j + *b3) = (*(s32 *) (j + *b3) & 0xFF000000) | ((s32) p & mlo);
}

extern s32 func_800246D4();

void func_80062FF0(void) {
    func_800248FC();
    do {
    } while (func_800246D4(1) != 0);
}

void func_80063020(void) {
    func_80024960();
    while (func_800246D4(1) != 0) {
    }
}

extern s32 D_801FA6EC;
extern u16 D_801FA6C0[];
extern u8 D_801FA6C1[];
extern u8 D_801FA6C2[];
extern s32 D_801FA6F0;
extern s16 D_801FA71C;
extern u16 D_801FA7AC;
extern s16 D_801FA7DC;
extern s16 D_801FA6C4;
extern s16 D_801FA6D8;
extern s16 D_801EFF68;
extern u8 D_801FA6E4;
extern s8 D_801EFFFC;

void func_80063050(s32 arg0, s32 arg1, s32 arg2) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");

    D_801FA6EC = arg0;
    D_801FA6F0 = arg2;
    v0 = -1;
    if (arg0 != 0) {
        v1 = *(s16 *) arg0;
        D_801FA71C = 0;
        if (v1 != v0) {
            arg2 = -1;
            do {
                v0 = (u16) D_801FA71C;
                v0 = v0 + 1;
                __asm__ volatile("sll %0,%1,16\n\tsra %0,%0,15" : "=r"(v1) : "r"(v0));
                v1 = v1 + arg0;
                v1 = *(s16 *) v1;
                D_801FA71C = v0;
            } while (v1 != arg2);
        }
    }
    D_801FA7AC = (s16) arg1;
    v0 = 0x80;
    if (arg1 == 0) {
        D_801FA7DC = 0;
    }
    *(s8 *) D_801FA6C0 = (s8) v0;
    D_801FA6C1[0] = (u8) v0;
    D_801FA6C2[0] = (u8) v0;
    v0 = 1;
    D_801FA6C4 = 0;
    D_801FA6D8 = 0;
    D_801EFF68 = 0;
    D_801FA6E4 = (u8) v0;
    D_801EFFFC = 0;
}

extern void func_801E2050();

void func_80063114(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 k = arg2;

    func_801E2050(arg0, arg1, arg3, arg3);
    D_801FA7DC = k;
}

extern void func_801E2114();
extern void func_801E3698();

void func_80063148(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 k = arg4;

    func_801E2114(arg0, arg1, arg2, arg3);
    func_801E3698(k);
}

extern s8 D_801FA70C;
extern s16 D_801FA6DC;
extern s32 D_801FA6C8;
extern u32 D_801EFF9C[];

typedef u8 *(*func_8006317C_fn)(u8 *);

void func_8006317C(volatile u8 *arg0, s32 arg1) {
    s32 pad[2];
    register s32 s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");

    D_801FA70C = 0;
    D_801FA6C4 = 0;
    D_801FA6DC = 0;
    D_801FA6C8 = arg1;
    v1 = arg0[0];
    v0 = 0x16;
    if (v1 != v0) {
        s1 = (s32) D_801EFF9C;
        s0 = 0x16;
        a0 = (s32) arg0;
        v0 = *(u8 *) a0;
        do {
            v0 <<= 2;
            v0 += s1;
            v0 = *(s32 *) v0;
            ((func_8006317C_fn) v0)((u8 *) a0);
            a0 = v0;
            v0 = *(u8 *) a0;
        } while (v0 != s0);
    }
    v0 = D_801EFFFC;
    v1 = v0;
    v0 = (v0 < 10);
    if (v0 != 0) {
        v0 = v1 + 1;
        D_801EFFFC = v0;
    }
    return;
}

extern void func_801E4338();
extern void func_801E217C();

void func_80063238(s32 arg0, s32 arg1, s32 arg2) {
    s32 k0 = arg0;
    s32 k1 = arg1;

    func_801E4338(arg2);
    func_801E217C(k0, k1);
}

extern s32 D_801EFF6C;
extern s32 D_801FA81C[];
extern u8 *func_801E22F4(u8 *, s32);
extern u8 *func_801E2374(void);

typedef s32 (*func_8006327C_fn)(s32, s32);

typedef u8 *(*func_8006327C_table_fn)(u8 *);

u8 *func_8006327C(u8 *arg0) {
    register u8 *s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 s2 asm("$18");
    register s32 s3 asm("$19");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    func_8006327C_table_fn temp_fn;
    u8 *p;

    s0 = arg0;
    v0 = s0[3];
    s1 = s0[4];
    v1 = D_801FA6D8;
    v0 <<= 2;
    a1 = *(s32 *) ((u8 *) D_801FA81C + v0);
    if (v1 == 0) {
        v1 = s0[5];
        __asm__ volatile("j func_801E22F4" : : "r"(s0), "r"(a1), "r"(v1) : "a0", "a1", "v1");
    }
    v0 = D_801FA7DC;
    v1 = D_801EFF6C;
    a0 = D_801EFF68;
    v1 = v0 + v1;
    if (a0 < 0) {
        v1--;
    }
    v0 = s0[1];
    p = s0 + v0;
    s0 = p;
    if (((func_8006327C_fn) a1)(v1, a1) == 0) {
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
        __asm__ volatile("\t.set\tnoreorder\n\tj func_801E2374\n\taddu $2,$16,$zero\n\t.set\treorder" : : : "v0", "memory");
    }
    s1--;
    if (s1 != v0) {
        s3 = (s32) D_801EFF9C;
        s2 = -1;
        do {
            v0 = s0[0];
            __asm__ volatile("addu %0,$16,$zero" : "=r"(a0) : : "memory");
            v0 <<= 2;
            v0 += s3;
            v0 = *(s32 *) v0;
            temp_fn = (func_8006327C_table_fn) v0;
            temp_fn((u8 *) a0);
            s1--;
            s0 = (u8 *) v0;
        } while (s1 != s2);
    }
    return s0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80063394);

u8 *func_80063520(u8 *arg0) {
    D_801FA6DC = arg0[3];
    return arg0 + arg0[1];
}

extern s32 func_801E2598();
extern s16 D_801FA6D0;
extern u16 D_801FA6F4;
extern s16 D_801FA6F8;
extern void func_801E15D4(s16 *, u8, u8, void *, s32, s32, s32, s32);

u8 *func_80063538(u8 *arg0) {
    s16 buf[4];
    register void *var_t0 asm("t0");
    s32 v0;
    s32 var_a0;
    register s32 a0 asm("a0");

    if (D_801FA6D8 == 0) {
        a0 = arg0[4];
        __asm__ volatile("j func_801E2598" : : "r"(a0) : "a0");
    }
    {
        register s32 v0 asm("v0");
        register s32 v1 asm("v1");
        register s32 a1 asm("a1");

        a1 = D_801FA6D0;
        v0 = D_801EFF6C;
        var_a0 = a1 * v0;
        a0 = arg0[4];
        v1 = D_801EFF68;
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
    var_t0 = D_801FA6C0;
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

        call_a0 = D_801FA6C4;
        call_a3 = D_801FA6DC;
        call_a1 = arg0[7];
        call_a2 = arg0[8];
        call_v0 = D_801FA6F4;
        call_v1 = *(u16 *) &D_801FA6F8;
        func_801E15D4(&buf[0], call_a1, call_a2, var_t0, call_a3, call_v0, call_v1, call_a0);
    }
    return arg0 + arg0[1];
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80063638);

extern void func_801E1F0C();
extern void func_801E2638(void *);
extern void func_801E2CC4();
extern s16 D_801F0008[];

void func_80063BE8(u8 *arg0) {
    register u8 *s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a1 asm("a1");
    register s32 a2 asm("a2");
    s16 buf[4];

    s0 = arg0;
    if (D_801EFFFC < 8) {
        if (D_801EFFFC < 3) {
            D_801FA6C8 = 0;
        }
        v1 = D_801F0008[D_801EFFFC];
        buf[2] = 0x100;
        v0 = s0[6];
        v1 = v0 * v1;
        a1 = D_801FA6C4;
        buf[0] = 0;
        v0 = v1 / 100;
        buf[3] = v0;
        v0 <<= 16;
        v0 >>= 17;
        v1 = s0[6];
        v1 >>= 1;
        a2 = s0[4];
        a2 += v1;
        a2 -= v0;
        buf[1] = a2;
        func_801E1F0C(&buf[0], a1, a2);
        D_801FA70C = 1;
        D_801FA6C4 = (u16) D_801FA6C4 + 1;
        TAIL_JUMP(func_801E2CC4);
    }
    D_801FA70C = 0;
    func_801E2638(s0);
    v1 = (u16) D_801FA6C4;
    D_801FA6C4 = (u16) v1 + 1;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80063CF8);

extern s32 func_80023A54(s32, s32);

u8 *func_80063F90(u8 *arg0) {
    D_801FA6F8 = func_80023A54(arg0[3] * 0x10, arg0[4] | (arg0[2] << 8));
    return arg0 + arg0[1];
}

extern u8 D_801FA708[];
extern void *func_801E3024();

u8 *func_80063FE4(u8 *arg0) {
    register u8 v0 asm("v0");
    register u8 a0 asm("a0");
    register u8 a1 asm("a1");

    if (D_801FA708[0] == 0) {
        goto call_80023a54;
    }
    a0 = arg0[6];
    a1 = arg0[5];
    v0 = arg0[7];
    __asm__ volatile(".set\tnoreorder\n\tj func_801E3024\n\tsll %0, %0, 4\n\t.set\treorder" ::"r"(a0), "r"(a1), "r"(v0) : "a0", "memory");
call_80023a54:
    D_801FA6F8 = func_80023A54(arg0[3] << 4, arg0[4] | (arg0[2] << 8));
    return arg0 + arg0[1];
}

extern s32 func_8002398C();

u8 *func_80064058(u8 *arg0) {
    u8 *local = arg0;

    D_801FA6F4 = func_8002398C(local[4], local[2] >> 4, local[3] << 4, local[2] << 8);
    return local + local[1];
}

u8 *func_800640AC(u8 *arg0) {
    if (D_801FA70C == 0) {
        D_801FA6C4 = arg0[3];
    }
    return arg0 + arg0[1];
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_800640D8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80064398);

u8 *func_8006462C(u8 *arg0) {
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
    __asm__ volatile("j func_801E366C\n\t"
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
    __asm__ volatile("j func_801E366C\n\t"
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80064698);

void func_80064938(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_801E2050();
    func_801E3698(arg3);
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_80064968);

extern u16 D_801EFF98[];
extern u16 D_801EFF78[];
extern u16 D_801EFF76[];
extern u16 D_801EFF7E[];
extern u16 D_801EFF86[];
extern u16 D_801EFF88[];
extern u16 D_801EFF9A[];
extern u16 D_801EFF7A[];
extern u16 D_801EFF74[];
extern u16 D_801EFF7C[];
extern u16 D_801EFF82[];
extern u16 D_801EFF84[];
extern u16 D_801FA7E4;
extern u16 D_801FA7A8;
extern u16 D_801FA78C;
extern u16 D_801FA744;
extern u16 D_801FA7F0;
extern u16 D_801FA80C;

void func_80065338(s32 arg0) {
    register s32 m asm("$2");
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;

    D_801FA708[0] = arg0;
    if (arg0 == 0) {
        goto b0;
    }
    {
        m = 0x60;
        __asm__ volatile("lhu $3,D_801EFF98");
        __asm__ volatile("lhu $4,D_801EFF78");
        __asm__ volatile("lhu $5,D_801EFF76");
        __asm__ volatile("lhu $6,D_801EFF7E");
        __asm__ volatile("lhu $7,D_801EFF86");
        __asm__ volatile("lhu $8,D_801EFF88");
        *(u8 *) D_801FA6C0 = m;
        *(u8 *) D_801FA6C1 = m;
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801E43D4\n\t"
                         "ori $2,$zero,0x80\n\t"
                         ".set\treorder\n\t");
    }
b0:
    a = D_801EFF9A[0];
    b = D_801EFF7A[0];
    c = D_801EFF74[0];
    d = D_801EFF7C[0];
    e = D_801EFF82[0];
    f = D_801EFF84[0];
    m = 0x80;
    *(u8 *) D_801FA6C0 = m;
    *(u8 *) D_801FA6C1 = m;
    *(u8 *) D_801FA6C2 = m;
    D_801FA7E4 = a;
    D_801FA7A8 = b;
    D_801FA78C = c;
    D_801FA744 = d;
    D_801FA7F0 = e;
    D_801FA80C = f;
}

extern s16 D_801EFFF6;

u8 *func_80065414(u8 *arg0) {
    s16 *p;
    u16 t;

    if (D_801FA70C != 0) {
        t = (u16) D_801FA6C4;
        p = &D_801EFFF6;
        *p = 0;
        t += 1;
        D_801FA6C4 = t;
        func_801E1F0C(p - 1, (s16) t);
        D_801FA70C = 0;
        D_801FA6C4 += 1;
    }
    return arg0 + arg0[1];
}

u8 *func_8006549C(u8 *arg0) {
    s16 buf[4];

    if (D_801FA70C == 0) {
        buf[0] = arg0[2];
        buf[1] = arg0[3];
        buf[2] = arg0[4];
        buf[3] = arg0[5];
        func_801E1F0C(buf, D_801FA6C4 - 1);
    }
    return arg0 + arg0[1];
}

u8 *func_80065510(u8 *arg0) {
    u8 *p0;
    s32 v;
    s16 *p;

    p0 = arg0;
    if (D_801FA70C == 0) {
        v = D_801FA6C4;
        __asm__("" : "=r"(v) : "0"(v));
        p = &D_801EFFF6;
        *p = 0;
        func_801E1F0C((s8 *) p - 2, v + 1);
    }
    return p0 + p0[1];
}

void func_8006556C(s32 arg0) {
    D_801EFFFC = arg0;
}

s32 func_8006557C(void) {
    return D_801EFFFC;
}

extern void func_801E4648(s16);
extern s8 D_801E5028;

void func_8006558C(s32 arg0, u8 *arg1) {
    register s32 s1 asm("s1");
    register s32 s0 asm("s0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register u8 *p1 asm("a1");
    register s32 a2 asm("a2");
    s32 unused[8];

    s1 = D_801FA7DC;
    v0 = D_801FA7AC;
    s0 = v0 - s1;
    p1 = arg1;
    a2 = s1;
    if (arg0 == -1) {
        v0 = p1[6];
        v0 = a2 - v0;
        D_801FA7DC = v0;
        if ((s16) v0 < 0) {
            D_801FA7DC = 0;
            TAIL_JUMP_MEM(func_801E4648);
        } else {
            goto block_7;
        }
    }
    if (arg0 == 1) {
        v0 = p1[6];
        v1 = D_801FA71C;
        v0 += a2;
        a2 = v1;
        D_801FA7DC = v0;
        v0 = (s16) v0;
        v0 += 1;
        v1 -= v0;
        if (v1 < p1[6]) {
            v0 = *(volatile u8 *) &p1[6];
            v0 = a2 - v0;
            D_801FA7DC = v0;
        }
    }
block_7:
    D_801FA7AC = (u16) D_801FA7DC;
    func_801E3698(p1);
    v0 = s0 + (u16) D_801FA7DC;
    D_801FA7AC = v0;
    if ((s16) v0 >= D_801FA71C) {
        D_801FA7AC = D_801FA71C - 1;
    }
    if (s1 != (s16) (u16) D_801FA7DC) {
        D_801E5028 = 3;
    }
}

extern s8 D_801F0040_g asm("D_801F0040");
extern u8 D_801F003C[];
extern u8 D_800473A1[];
extern u8 D_800473A3[];
extern s32 func_8001DB58();

s32 func_800656CC(void) {
    register s32 r asm("$16");
    register s32 v0 asm("$2");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 d0 asm("$2");
    register s32 d1 asm("$3");

    r = 0;
    a0 = func_8001DB58(0);
    v0 = a0 & 0x1000;
    if (v0 != 0) {
        v0 = a0 & 0x80;
        if (v0 != 0) {
            __asm__ volatile("lui %0,%%hi(D_801F003C+2)\n\t"
                             "lhu %0,%%lo(D_801F003C+2)(%0)"
                             : "=&r"(v0));
            __asm__ volatile(".set\tnoreorder\n\t"
                             "j func_801E472C\n\t"
                             "addiu %0,$zero,-1\n\t"
                             ".set\treorder" : "=r"(r)::"memory");
        }
    }
    v0 = a0 & 0x4000;
    if (v0 == 0) {
        goto L40;
    }
    v0 = a0 & 0x80;
    if (v0 == 0) {
        goto L40;
    }
    __asm__ volatile("lui %0,%%hi(D_801F003C+2)\n\t"
                     "lhu %0,%%lo(D_801F003C+2)(%0)"
                     : "=&r"(v0));
    r = 1;
    v0 = v0 + 1;
    *(u16 *) (D_801F003C + 2) = (u16) v0;
    __asm__ volatile(".set\tnoreorder\n\tj func_801E4748\n\tnop\n\t.set\treorder" ::: "memory");
L40:
    __asm__ volatile("lui $at,%%hi(D_801F003C+2)\n\t"
                     "sh $zero,%%lo(D_801F003C+2)($at)" ::: "memory");
    a0 = D_801F0040_g;
    d0 = D_800473A1[0];
    d0 = d0 / a0;
    a1 = *(u16 *) (D_801F003C + 2);
    __asm__ volatile("lui %0,%%hi(D_800473A3)\n\t"
                     "lbu %0,%%lo(D_800473A3)(%0)\n\t"
                     "slt %1,%2,%3"
                     : "=&r"(d1), "=&r"(a2) : "r"(a1), "r"(d0));
    d1 = d1 / a0;
    __asm__ volatile(".set\tnoreorder\n\t"
                     "bnez   %4,1f\n\t"
                     "sltiu  %0,%2,2\n\t"
                     "div    $0,%2,%3\n\t"
                     "mfhi   %0\n\t"
                     "nop\n\t"
                     "bnez   %0,2f\n\t"
                     "sltiu  %0,%2,2\n\t"
                     "1:\n\t"
                     "bnez   %0,3f\n\t"
                     "nop\n\t"
                     "beqz   %4,4f\n\t"
                     "addu   %0,%1,$0\n\t"
                     "2:\n\t"
                     "addu   %1,$0,$0\n\t"
                     "3:\n\t"
                     "addu   %0,%1,$0\n\t"
                     "4:\n\t"
                     ".set\treorder"
                     : "=r"(v0), "=r"(r) : "r"(a1), "r"(d1), "r"(a2), "1"(r));
    return v0;
}

extern int func_80024A88(void *, int);
extern void func_80024E4C(void *);
extern s16 D_801FA734;
extern s16 D_801FA738;
extern s16 D_801FA73C;
extern s16 D_801FA740;
extern s16 D_801FA768;
extern s16 D_801FA774;
extern s16 D_801FA778;
extern s16 D_801FA780;
extern s16 D_801FA784;
extern s16 D_801FA788;
extern s16 D_801FA790;
extern s16 D_801FA794;
extern s16 D_801FA79C;
extern u16 D_801FA7B4;
extern s16 D_801FA7C8;
extern s16 D_801FA7D8;
extern s16 D_801FA7EC;
extern s16 D_801FA7F4;
extern s32 *D_801FA7FC;
extern s16 D_801FA804;
extern s16 D_801FA810;
extern s16 D_801FA814;

void func_800657C8(s32 arg0) {
    u16 buf[48];
    u8 *var_a1;
    register s32 v asm("v0");
    register s32 t asm("a0");

    D_801FA734 = 0;
    D_801FA790 = 0;
    D_801FA73C = 0;
    D_801FA798 = 0;
    D_801FA738 = 0;
    D_801FA794 = 0;
    D_801FA740 = 0;
    D_801FA79C = 0;
    D_801FA768 = 0;
    D_801FA778 = 0;
    D_801FA784 = 0;
    D_801FA774 = 0;
    D_801FA780 = 0;
    D_801FA788 = 0;
    D_801FA7C8 = 0;
    D_801FA7EC = 0;
    D_801FA7F4 = 0;
    D_801FA810 = 0;
    D_801FA7D8 = 0;
    D_801FA804 = 0;
    D_801FA814 = 0;
    D_801FA7CC = 0;
    D_801FA7BC = 0;
    func_80024E4C(buf);
    var_a1 = (u8 *) D_801FA7FC;
    D_801FA7A4 = buf[1];
    if (D_801FA7D0 == (s32 *) var_a1) {
        var_a1 += 0xF4;
    }
    t = arg0 * 4;
    v = *(s32 *) var_a1;
    D_801FA7D0 = (s32 *) var_a1;
    func_80024A88(t + v, D_801FA7B4 - arg0);
}

extern void func_80023D1C(void *);
extern void func_80023DD0(void *);
extern u16 D_801FA770;
extern u16 D_801FA7C0;
extern u16 D_801FA7C4;

void func_800658F4(void *arg0) {
    register u8 *var_s2;
    register s32 var_s0;
    register s32 var_s1 asm("s1");
    register s32 v0 asm("v0");
    register s32 index asm("a0");
    s32 unused[6];

    var_s2 = (u8 *) arg0;
    var_s0 = 0;
    v0 = D_801FA770;
    if (v0 <= 0) {
        goto skip1;
    }
    var_s1 = 0;
    do {
        func_80023D1C((void *) (var_s1 + *(s32 *) (var_s2 + 0x10)));
        var_s0 += 1;
        func_80023C90((void *) (var_s1 + *(s32 *) (var_s2 + 0x10)), 0);
        var_s1 += 0x28;
    } while (var_s0 < (s32) D_801FA770);
skip1:
    var_s0 = 0;
    v0 = D_801FA7C0;
    if (v0 <= 0) {
        goto skip2;
    }
    do {
        index = var_s0 << 4;
        func_80023DD0((void *) (index + *(s32 *) (var_s2 + 0x3C)));
        var_s0 += 1;
    } while (var_s0 < (s32) D_801FA7C0);
skip2:
    v0 = D_801FA7C4;
    if (v0 <= 0) {
        goto end;
    }
    var_s0 = 0;
    var_s1 = 0;
    do {
        var_s0 += 1;
        func_80023EA0((void *) (var_s1 + *(s32 *) (var_s2 + 0x58)));
        var_s1 += 0x18;
    } while (var_s0 < (s32) D_801FA7C4);
end:;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/JOBSTTS", func_800659F0);

extern s8 D_801F0040_h asm("D_801F0040");

s32 func_80065E78(void) {
    s32 v;
    v = D_801F0040_h;
    if (v == 0) {
        return 1;
    }
    return v;
}

extern u8 D_801F0044;
extern s32 D_801FA714;

void func_80065E98(s32 arg0) {
    D_801F0044 = 1;
    D_801FA714 = arg0;
}

extern u8 D_801F0045;
extern s32 D_801FA718;

void func_80065EB4(s32 arg0) {
    D_801F0045 = 1;
    D_801FA718 = arg0;
}

extern s32 D_801F0048;

s32 func_80065ED0(s32 arg0) {
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
            "lui $2,%hi(D_801F0044)\n"
            "lbu $2,%lo(D_801F0044)($2)\n"
            "nop\n"
            "beqz $2,1f\n"
            "move $7,$0\n"
            "ori $2,$0,7\n"
            "lui $1,%hi(D_801F0048)\n"
            "sw $2,%lo(D_801F0048)($1)\n"
            "lui $1,%hi(D_801F0044)\n"
            "sb $0,%lo(D_801F0044)($1)\n"
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
        p = (u8 *) D_801FA714;
        n = D_801F0048;
        v = *p;
        a1 = n - 1;
        D_801F0048 = a1;
        if ((v >> n) & 1) {
            acc |= t2 << arg0;
        }
        arg0--;
        if (a1 < 0) {
            D_801F0048 = t1;
            D_801FA714 = (s32) (p + 1);
        }
        if (arg0 != t0) {
            continue;
        }
        break;
    }
    return acc;
}

extern s32 D_801F004C;

s32 func_80065F7C(s32 arg0) {
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
            "lui $2,%hi(D_801F0045)\n"
            "lbu $2,%lo(D_801F0045)($2)\n"
            "nop\n"
            "beqz $2,1f\n"
            "move $7,$0\n"
            "ori $2,$0,7\n"
            "lui $1,%hi(D_801F004C)\n"
            "sw $2,%lo(D_801F004C)($1)\n"
            "lui $1,%hi(D_801F0045)\n"
            "sb $0,%lo(D_801F0045)($1)\n"
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
        p = (u8 *) D_801FA718;
        n = D_801F004C;
        v = *p;
        a1 = n - 1;
        D_801F004C = a1;
        if ((v >> n) & 1) {
            acc |= t2 << arg0;
        }
        arg0--;
        if (a1 < 0) {
            D_801F004C = t1;
            D_801FA718 = (s32) (p + 1);
        }
        if (arg0 != t0) {
            continue;
        }
        break;
    }
    return acc;
}
