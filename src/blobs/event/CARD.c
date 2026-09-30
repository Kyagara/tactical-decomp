#include "common.h"

extern u8 *D_801D9294_ptr asm("D_801D9294");
extern void func_800248FC();
extern s32 func_8002398C();

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_80060170\nfunc_80060170:\n\taddiu $29,$29,-8\n\tsw $30,0($29)\n\taddu $30,$29,$zero\n\taddiu $2,$zero,-1\n\tlui $1,%hi(D_801C9580)\n\tsh $2,%lo(D_801C9580)($1)\n\taddiu $2,$zero,-1\n\tlui $1,%hi(D_801C9582)\n\tsh $2,%lo(D_801C9582)($1)\n\taddu $29,$30,$zero\n\tlw $30,0($29)\n\taddiu $29,$29,8\n\tjr $31\n\tnop\n\t.set at\n");

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_800601A8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_800603B8);

extern u8 D_801C960C;
extern s16 D_801C957C;
extern s8 D_801C9570;
extern s16 D_801C9608;
extern s16 D_801C9582;
extern u8 D_801C9594;
extern s8 D_801CC80C;
extern void func_801BF9F8(void);
extern void func_801BFA64(void);
extern s32 func_801C7238(s32, void *);

void func_80060970(void) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[6];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x14($sp)\n\tsw $30,0x10($sp)\n\taddu %0,$29,$zero\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[5]));
    if (D_801C960C != 0) {
        goto loaded;
    }
    v0 = D_801C957C;
    v1 = v0 < 0x28;
    if (v1 == 0) {
        goto reset;
    }
    v0 = (u16) D_801C957C;
    ASM_NOP();
    __asm__ volatile("addiu $3,$2,1\n\tmove $2,$3" ::: "memory");
    D_801C957C = (s16) v0;
    TAIL_JUMP(func_801BF9F8);
reset:
    __asm__ volatile("ori $2,$zero,1" ::: "memory");
    D_801C960C = (u8) v0;
    D_801C9570 = 0;
    D_801C9608 = 0;
    __asm__ volatile("addiu $2,$zero,-1" ::: "memory");
    D_801C9582 = (s16) v0;
    TAIL_JUMP(func_801BFA64);
loaded:
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,6\n\tlui $5,%%hi(D_801C9594)\n\taddiu $5,$5,%%lo(D_801C9594)\n\tjal func_801C7238\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    D_801C960C = (u8) v0;
    v0 = D_801C960C;
    if (v0 != 0) {
        goto finish;
    }
    v0 = D_801C9582;
    if (v0 == 0) {
        goto set_one;
    }
    __asm__ volatile("ori $2,$zero,0xA" ::: "memory");
    D_801CC80C = (s8) v0;
    TAIL_JUMP(func_801BFA64);
set_one:
    v0 = 1;
    D_801CC80C = (s8) v0;
finish:
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x14($29)\n\tlw $30,0x10($29)\n\t.set\treorder" ::: "memory");
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80060A7C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80060BD8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80060DE0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_800611AC);

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_800619B4\nfunc_800619B4:\n\taddiu $29,$29,-24\n\tsw $31,20($29)\n\tsw $30,16($29)\n\taddu $30,$29,$zero\n\tori $2,$zero,0x18\n\tlui $1,%hi(D_801C9574)\n\tsh $2,%lo(D_801C9574)($1)\n\tlui $1,%hi(D_801C9572)\n\tsh $zero,%lo(D_801C9572)($1)\n\tlui $1,%hi(D_801C9578)\n\tsh $zero,%lo(D_801C9578)($1)\n\tlui $1,%hi(D_801C9576)\n\tsh $zero,%lo(D_801C9576)($1)\n\tlui $1,%hi(D_801C9570)\n\tsb $zero,%lo(D_801C9570)($1)\n\tlui $1,%hi(D_801C957C)\n\tsh $zero,%lo(D_801C957C)($1)\n\tlui $2,%hi(D_801CA968)\n\taddiu $2,$2,%lo(D_801CA968)\n\tlui $1,%hi(D_801CC808)\n\tsw $2,%lo(D_801CC808)($1)\n\tlui $4,%hi(D_801CC808)\n\tlw $4,%lo(D_801CC808)($4)\n\tori $5,$zero,0xff\n\tori $6,$zero,0x1e80\n\t.word 0x0c0088bf\n\tnop\n\taddu $29,$30,$zero\n\tlw $31,20($29)\n\tlw $30,16($29)\n\taddiu $29,$29,24\n\tjr $31\n\tnop\n\t.set at\n");

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80061A38);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80061C58);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80062820);

extern void func_801C1E18();
extern void func_801C70AC(void *, void *, s16 *, s32);
extern s16 D_801C9908;
extern s32 D_801D8398[];

void func_80062D28(s32 arg0) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    register s32 a3 asm("$7");
    struct {
        s32 pad[4];
        volatile s16 f10;
        volatile s16 f12;
        volatile s16 f14;
        volatile s16 f16;
        s32 tail[2];
    } locals;

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu $30,$29,$zero\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(locals.pad[0]), "m"(locals.f16));
    *(volatile s32 *) (fp + 0x20) = arg0;
    v0 = *(volatile s32 *) (fp + 0x20);
    __asm__ volatile("slti $3,$2,6" : "=r"(v1) : "r"(v0));
    if (v1 != 0) {
        __asm__ volatile("ori $2,$zero,0x100\n\tsh $2,0x10($30)" ::: "memory");
        v0 = *(volatile s32 *) (fp + 0x20);
        __asm__ volatile("addu $3,$2,$zero\n\tsll $2,$3,5\n\taddu $3,$2,$zero\n\taddiu $2,$3,0x30" : "=r"(v0) : "0"(v0) : "v1", "memory");
        *(volatile s16 *) (fp + 0x12) = (s16) v0;
        __asm__ volatile("li $2,0x32\n\tsh $2,0x14($30)\n\tli $2,0x20\n\tsh $2,0x16($30)" ::: "memory");
        TAIL_JUMP(func_801C1E18);
    }
    v0 = *(volatile s32 *) (fp + 0x20);
    __asm__ volatile(".set\tnoreorder\n\tslti $3,$2,0xB\n\tbeqz $3,.L80062D28_third\n\tnop\n\t.set\treorder");
    __asm__ volatile("li $2,0x1c0\n\tsh $2,0x10($30)" ::: "memory");
    v1 = *(volatile s32 *) (fp + 0x20);
    __asm__ volatile("nop" ::: "memory");
    __asm__ volatile("addiu $2,$3,-6\n\taddu $3,$2,$zero\n\tsll $2,$3,5\n\taddu $3,$2,$zero\n\taddiu $2,$3,0x40" : "=r"(v1), "=r"(v0) : "0"(v1) : "memory");
    *(volatile s16 *) (fp + 0x12) = (s16) v0;
    __asm__ volatile("li $2,0x32\n\tsh $2,0x14($30)\n\tli $2,0x20\n\tsh $2,0x16($30)" ::: "memory");
    TAIL_JUMP(func_801C1E18);
    __asm__ volatile(".L80062D28_third:");
    __asm__ volatile("li $2,0x180\n\tsh $2,0x10($30)" ::: "memory");
    v1 = *(volatile s32 *) (fp + 0x20);
    __asm__ volatile("nop" ::: "memory");
    __asm__ volatile("addiu $2,$3,-0xB\n\taddu $3,$2,$zero\n\tsll $2,$3,5\n\taddu $3,$2,$zero\n\taddiu $2,$3,0x60" : "=r"(v1), "=r"(v0) : "0"(v1) : "memory");
    *(volatile s16 *) (fp + 0x12) = (s16) v0;
    __asm__ volatile("li $2,0x32\n\tsh $2,0x14($30)\n\tli $2,0x20\n\tsh $2,0x16($30)" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tlw $2,0x20($30)\n\tnop\n\tmove $4,$2\n\tsll $3,$4,2\n\taddu $3,$3,$2\n\tsll $2,$3,4\n\tlui $3,%%hi(D_801D8398)\n\taddiu $3,$3,%%lo(D_801D8398)\n\taddu $2,$2,$3\n\tmove $4,$2\n\tlui $5,%%hi(D_801C9908)\n\taddiu $5,$5,%%lo(D_801C9908)\n\taddiu $6,$30,0x10\n\tmove $7,$zero\n\tjal func_801C70AC\n\tnop\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80062E70);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80062FC8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80063D08);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80063EA8);

void func_800644C8(u8 *arg0, u16 *arg1, u16 *arg2, u8 *arg3, s16 *arg4, u16 *arg5) {
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
extern void func_80023C68(void *, s32);
extern void func_80023C90(void *, s32);
extern void func_80023D08(void *);
extern void func_801C34C8(void *, void *, void *, void *, EventDrawArgs);
extern u8 D_801CA861;
extern u8 D_801CA7EC[];
extern u8 D_801CA7EE[];
extern u8 D_801CA680[];
extern u8 D_801CA688[];
extern u8 D_801CA690[];

void func_80064798(u8 *arg0, u8 *arg1) {
    register EventCoord28 *s0 asm("s0");
    register u8 *s2 asm("s2");
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
    v0 = D_801CA861;
    if (v0 <= 0) {
        goto end;
    }
    s6 = 0xFFFFFF;
    s7 = 0xFF000000;
    s5 = 0;
    s3 = 0;
    s2 = arg1 + 6;
loop:
    func_80023D1C(s0);
    *(u16 *) (s2 + 8) = func_80023A54(0, 0x1FD);
    s2[-2] = *(volatile u8 *) (arg0 + 4);
    s2[-1] = *(volatile u8 *) (arg0 + 4);
    s2[0] = *(volatile u8 *) (arg0 + 4);
    func_80023C68(s0, 1);
    func_80023C90(s0, 0);
    a2 = *(s16 *) (D_801CA7EC + s3);
    v0 = *(s16 *) (arg0 + 0xC);
    a2 = a2 * v0;
    v1 = *(s16 *) (D_801CA7EE + s3);
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
    c1 = (s32) D_801CA680;
    buf[0] = a2;
    buf[1] = v1;
    args = (EventDrawArgs *) ((u8 *) buf - 8);
    v0 = (s32) buf;
    args->coords = (s16 *) v0;
    MEMORY_BARRIER();
    v0 = (s32) (arg0 + 0x18);
    args->extra = (u8 *) v0;
    table = D_801CA690;
    a2 = (s32) D_801CA688 + ((s32) table - (s32) table);
    func_801C34C8((u8 *) c0, (u8 *) c1, (u8 *) a2, table + s5, *args);
    s5 += 0xC;
    if (*(s32 *) (arg0 + 8) != 0) {
        s2 += 0x28;
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
    if (s4 < D_801CA861) {
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80064A4C);

extern s32 D_801D91D4;

void func_80064DCC(s32 arg0) {
    D_801D91D4 = arg0;
}

extern s32 D_80166030;
extern s32 D_80165F88;
extern s32 D_801CA864[];
extern s16 D_801CA870;
extern s16 D_801CA872;
extern s16 D_801CA884;
extern s16 D_801CA886;
extern s32 D_801D8874[];
extern s32 func_8014CBC0();
extern s32 func_8014CA80();
extern s32 func_8014CC28();
extern void func_8014C958();
extern void func_801C3798(s32 *, s32);
extern void func_801C3E18();
extern void func_801C3E50();

void func_80064DDC(void) {
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 s0 asm("$16");
    register s32 s1 asm("$17");
    volatile s32 pad[2];
    v0 = D_80166030;
    if (v0 != 0) {
        D_801CA884 = 0;
        __asm__ volatile(".set\tnoreorder\n\tj func_801C3E18\n\tori $2,$zero,8\n\t.set\treorder");
    }
    D_801CA884 = 0x100;
    D_801CA886 = 0x80;
    v0 = func_8014CBC0();
    if (v0 == 0) {
        v0 = 0x2000;
    } else {
        v0 = 0x1000;
    }
    __asm__ volatile(".set\tnoreorder\n\tlui $1,%%hi(D_801CA870)\n\tsh %2,%%lo(D_801CA870)($1)\n\tlui $1,%%hi(D_801CA872)\n\tsh %2,%%lo(D_801CA872)($1)\n\tmove $17,$zero\n\tlui $16,%%hi(D_801CA864)\n\taddiu $16,$16,%%lo(D_801CA864)\n\t.set\treorder" : "=r"(s0), "=r"(s1) : "r"(v0) : "memory");
    do {
        v1 = D_801D91D4;
        v0 = *(s16 *) (s0 + 0xC);
        *(s32 *) s0 = v1;
        v1 = v0;
        __asm__ volatile(".set\tnoreorder\n\tslti $2,$2,0x1001\n\tbnez $2,.L80064DDC_common\n\tori $2,$zero,0x80\n\t.set\treorder" : "=r"(v0) : "0"(v0) : "memory");
        v0 = D_80165F88;
        a0 = *(u16 *) (s0 + 0xE);
        v0 <<= 8;
        v1 -= v0;
        a0 -= v0;
        *(s16 *) (s0 + 0xC) = (s16) v1;
        *(s16 *) (s0 + 0xE) = (s16) a0;
        __asm__ volatile("ori $2,$zero,0x80" : "=r"(v0));
        __asm__ volatile(".L80064DDC_common:");
        __asm__ volatile("sw $2,4($16)" ::: "memory");
        v1 = s1 & 1;
        v0 = v1 << 2;
        __asm__ volatile("addu $2,$2,$3" : "=r"(v0) : "r"(v0), "r"(v1));
        a1 = v0 << 4;
        a1 -= v0;
        a1 <<= 4;
        v0 = (s32) D_801D8874;
        a0 = s0;
        func_801C3798((s32 *) s0, a1 + v0);
        func_8014CA80();
        if (func_8014CC28() != 0) {
            break;
        }
        s1 += 1;
    } while (1);
    func_8014C958();
    TAIL_JUMP(func_801C3E50);
}

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_80064F04\nfunc_80064F04:\n\taddiu $29,$29,-8\n\tsw $30,0($29)\n\taddu $30,$29,$zero\n\tsw $4,8($30)\n\tlbu $2,8($30)\n\tlui $1,%hi(D_801CA88C)\n\tsb $2,%lo(D_801CA88C)($1)\n\taddu $29,$30,$zero\n\tlw $30,0($29)\n\taddiu $29,$29,8\n\tjr $31\n\tnop\n\t.set at\n");

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_80064F34\nfunc_80064F34:\n\taddiu $29,$29,-8\n\tsw $30,0($29)\n\taddu $30,$29,$zero\n\tlui $3,%hi(D_801CA88C)\n\tlbu $3,%lo(D_801CA88C)($3)\n\tnop\n\taddu $2,$3,$zero\n\t.word 0x08070fd6\n\tnop\n\taddu $29,$30,$zero\n\tlw $30,0($29)\n\taddiu $29,$29,8\n\tjr $31\n\tnop\n\t.set at\n");

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_80064F6C\nfunc_80064F6C:\n\taddiu $29,$29,-24\n\tsw $31,20($29)\n\tsw $30,16($29)\n\taddu $30,$29,$zero\n\t.word 0x0c071051\n\tnop\n\t.word 0x0c0710d3\n\tnop\n\taddu $29,$30,$zero\n\tlw $31,20($29)\n\tlw $30,16($29)\n\taddiu $29,$29,24\n\tjr $31\n\tnop\n\t.set at\n");

void func_80064FA4(void) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[8];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\taddiu $2,$zero,-1\n\tsw $2,0x10(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[7]));
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800596C0)\n\tlw $4,%%lo(D_800596C0)($4)\n\tjal func_80021FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("ori $3,$zero,1" ::: "memory");
    if (v0 != v1) {
        goto second;
    }
    *(volatile s32 *) (fp + 0x10) = 0;
    TAIL_JUMP(func_801C4060);
second:
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800596C4)\n\tlw $4,%%lo(D_800596C4)($4)\n\tjal func_80021FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("ori $3,$zero,1" ::: "memory");
    if (v0 != v1) {
        goto third;
    }
    __asm__ volatile("ori $2,$zero,1" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    TAIL_JUMP(func_801C4060);
third:
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800596C8)\n\tlw $4,%%lo(D_800596C8)($4)\n\tjal func_80021FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("ori $3,$zero,1" ::: "memory");
    if (v0 != v1) {
        goto fourth;
    }
    __asm__ volatile("ori $2,$zero,2" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    TAIL_JUMP(func_801C4060);
fourth:
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800596CC)\n\tlw $4,%%lo(D_800596CC)($4)\n\tjal func_80021FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("ori $3,$zero,1" ::: "memory");
    if (v0 != v1) {
        goto finish;
    }
    __asm__ volatile("ori $2,$zero,3" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v0;
finish:
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 == -1) {
        goto tail;
    }
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C4144\n\tnop\n\t.set\treorder" ::: "memory");
tail:
    v0 = *(volatile s32 *) (fp + 0x10);
    TAIL_JUMP(func_801C4084);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

extern void func_801C40C0();
extern void func_801C40B0();
extern void func_801C412C();
extern s32 func_801C3FA4();

void func_8006509C(void) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    struct {
        s32 pad[4];
        volatile s32 result;
        volatile s32 flag;
        s32 tail[2];
    } locals;

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\tnop\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(locals.pad[0]), "m"(locals.pad[1]));
    TAIL_JUMP(func_801C40C0);
    TAIL_JUMP(func_801C412C);
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\tmove $4,$2\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tjal func_80028770\n\tnop\n\t.set\treorder" : "=r"(v0) : "r"(a0) : "memory");
    v1 = v0 & 1;
    *(volatile s32 *) (fp + 0x14) = v1;
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C3FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 < 0) {
        goto negative;
    }
    v0 = *(volatile s32 *) (fp + 0x10);
    TAIL_JUMP(func_801C412C);
negative:
    v0 = *(volatile s32 *) (fp + 0x14);
    if (v0 == 0) {
        goto flag_zero;
    }
    __asm__ volatile(".set\tnoreorder\n\tori $2,$zero,2\n\tj func_801C412C\n\tnop\n\t.set\treorder" ::: "memory");
flag_zero:
    TAIL_JUMP(func_801C40B0);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_80065144\nfunc_80065144:\n\taddiu $29,$29,-24\n\tsw $31,20($29)\n\tsw $30,16($29)\n\taddu $30,$29,$zero\n\tlui $4,%hi(D_800596C0)\n\tlw $4,%lo(D_800596C0)($4)\n\t.word 0x0c0087e9\n\tnop\n\tlui $4,%hi(D_800596C4)\n\tlw $4,%lo(D_800596C4)($4)\n\t.word 0x0c0087e9\n\tnop\n\tlui $4,%hi(D_800596C8)\n\tlw $4,%lo(D_800596C8)($4)\n\t.word 0x0c0087e9\n\tnop\n\tlui $4,%hi(D_800596CC)\n\tlw $4,%lo(D_800596CC)($4)\n\t.word 0x0c0087e9\n\tnop\n\taddu $29,$30,$zero\n\tlw $31,20($29)\n\tlw $30,16($29)\n\taddiu $29,$29,24\n\tjr $31\n\tnop\n\t.set at\n");

void func_800651AC(void) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[8];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\taddiu $2,$zero,-1\n\tsw $2,0x10(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[7]));
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800596D0)\n\tlw $4,%%lo(D_800596D0)($4)\n\tjal func_80021FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("ori $3,$zero,1" ::: "memory");
    if (v0 != v1) {
        goto second;
    }
    *(volatile s32 *) (fp + 0x10) = 0;
    TAIL_JUMP(func_801C4268);
second:
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800596D4)\n\tlw $4,%%lo(D_800596D4)($4)\n\tjal func_80021FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("ori $3,$zero,1" ::: "memory");
    if (v0 != v1) {
        goto third;
    }
    __asm__ volatile("ori $2,$zero,1" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    TAIL_JUMP(func_801C4268);
third:
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800596D8)\n\tlw $4,%%lo(D_800596D8)($4)\n\tjal func_80021FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("ori $3,$zero,1" ::: "memory");
    if (v0 != v1) {
        goto fourth;
    }
    __asm__ volatile("ori $2,$zero,2" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    TAIL_JUMP(func_801C4268);
fourth:
    __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_800596DC)\n\tlw $4,%%lo(D_800596DC)($4)\n\tjal func_80021FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("ori $3,$zero,1" ::: "memory");
    if (v0 != v1) {
        goto finish;
    }
    __asm__ volatile("ori $2,$zero,3" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v0;
finish:
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 == -1) {
        goto tail;
    }
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C434C\n\tnop\n\t.set\treorder" ::: "memory");
tail:
    v0 = *(volatile s32 *) (fp + 0x10);
    TAIL_JUMP(func_801C428C);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

extern volatile u8 D_801CA88C;
extern s32 func_80028770(s32);
extern s32 func_801C41AC(void);
extern void func_801C42B8(void);
extern void func_801C42C8(void);
extern void func_801C4334(void);

void func_800652A4(void) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    struct {
        s32 pad[4];
        volatile s32 result;
        volatile s32 flag;
        s32 tail[2];
    } locals;

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\tnop\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(locals.pad[0]), "m"(locals.pad[1]));
    TAIL_JUMP(func_801C42C8);
    TAIL_JUMP(func_801C4334);
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\tmove $4,$2\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tjal func_80028770\n\tnop\n\t.set\treorder" : "=r"(v0) : "r"(a0) : "memory");
    v1 = v0 & 1;
    *(volatile s32 *) (fp + 0x14) = v1;
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C41AC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 < 0) {
        goto negative;
    }
    v0 = *(volatile s32 *) (fp + 0x10);
    TAIL_JUMP(func_801C4334);
negative:
    v0 = *(volatile s32 *) (fp + 0x14);
    if (v0 == 0) {
        goto flag_zero;
    }
    __asm__ volatile(".set\tnoreorder\n\tori $2,$zero,2\n\tj func_801C4334\n\tnop\n\t.set\treorder" ::: "memory");
flag_zero:
    TAIL_JUMP(func_801C42B8);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

__asm__(".text\n\t.set noat\n\t.set noreorder\n\t.globl func_8006534C\nfunc_8006534C:\n\taddiu $29,$29,-24\n\tsw $31,20($29)\n\tsw $30,16($29)\n\taddu $30,$29,$zero\n\tlui $4,%hi(D_800596D0)\n\tlw $4,%lo(D_800596D0)($4)\n\t.word 0x0c0087e9\n\tnop\n\tlui $4,%hi(D_800596D4)\n\tlw $4,%lo(D_800596D4)($4)\n\t.word 0x0c0087e9\n\tnop\n\tlui $4,%hi(D_800596D8)\n\tlw $4,%lo(D_800596D8)($4)\n\t.word 0x0c0087e9\n\tnop\n\tlui $4,%hi(D_800596DC)\n\tlw $4,%lo(D_800596DC)($4)\n\t.word 0x0c0087e9\n\tnop\n\taddu $29,$30,$zero\n\tlw $31,20($29)\n\tlw $30,16($29)\n\taddiu $29,$29,24\n\tjr $31\n\tnop\n\t.set at\n");

void func_800653B4(s32 arg0, s32 arg1) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[8];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\tsw $4,0x20(%0)\n\tsw $5,0x24(%0)\n\tsw $zero,0x10(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[7]));
    v0 = *(volatile s32 *) (fp + 0x10);
    v1 = *(volatile s32 *) (fp + 0x24);
    if (v0 < v1) {
        goto body;
    }
    TAIL_JUMP(func_801C4458);
body:
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x20($30)\n\tjal func_80028740\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    v1 = 1;
    if (v0 != v1) {
        goto alternate;
    }
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C409C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v0 = *(volatile s32 *) (fp + 0x14);
    if (v0 != 0) {
        goto nonzero;
    }
    TAIL_JUMP(func_801C4458);
nonzero:
    TAIL_JUMP(func_801C443C);
alternate:
    __asm__ volatile("ori $2,$zero,2" ::: "memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v1 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\tmove $3,$2" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v1;
    TAIL_JUMP(func_801C43D0);
    v0 = *(volatile s32 *) (fp + 0x14);
    TAIL_JUMP(func_801C4464);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

void func_8006547C(s32 arg0, s32 arg1) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[8];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\tsw $4,0x20(%0)\n\tsw $5,0x24(%0)\n\tsw $zero,0x10(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[7]));
    v0 = *(volatile s32 *) (fp + 0x10);
    v1 = *(volatile s32 *) (fp + 0x24);
    if (v0 < v1) {
        goto body;
    }
    TAIL_JUMP(func_801C452C);
body:
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x20($30)\n\tjal func_80028750\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    v1 = 1;
    if (v0 != v1) {
        goto alternate;
    }
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C409C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v0 = *(volatile s32 *) (fp + 0x14);
    if (v0 != 0) {
        goto nonzero;
    }
    TAIL_JUMP(func_801C452C);
nonzero:
    TAIL_JUMP(func_801C4504);
alternate:
    __asm__ volatile("ori $2,$zero,2" ::: "memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,2\n\tjal func_8001DBA8\n\tnop\n\t.set\treorder" ::: "memory");
    v1 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\tmove $3,$2" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v1;
    TAIL_JUMP(func_801C4498);
    v0 = *(volatile s32 *) (fp + 0x14);
    TAIL_JUMP(func_801C4538);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

void func_80065550(s32 arg0, s32 arg1) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[8];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\tsw $4,0x20(%0)\n\tsw $5,0x24(%0)\n\tsw $zero,0x10(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[7]));
    v0 = *(volatile s32 *) (fp + 0x10);
    v1 = *(volatile s32 *) (fp + 0x24);
    if (v0 < v1) {
        goto body;
    }
    TAIL_JUMP(func_801C4630);
body:
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x20($30)\n\tjal func_80028780\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    v1 = 1;
    if (v0 != v1) {
        goto alternate;
    }
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C42A4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v0 = *(volatile s32 *) (fp + 0x14);
    v1 = v0 < 3;
    if (v1 != 0) {
        goto check;
    }
    __asm__ volatile("ori $2,$zero,1" ::: "memory");
    *(volatile s32 *) (fp + 0x14) = v0;
check:
    v0 = *(volatile s32 *) (fp + 0x14);
    if (v0 != 0) {
        goto call477;
    }
    TAIL_JUMP(func_801C4630);
call477:
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,1\n\tjal func_801C477C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 != 0) {
        goto positive;
    }
    __asm__ volatile("sw $zero,0x14($30)" ::: "memory");
    TAIL_JUMP(func_801C4630);
positive:
    TAIL_JUMP(func_801C4614);
alternate:
    __asm__ volatile("ori $2,$zero,2" ::: "memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v1 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\tmove $3,$2" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v1;
    TAIL_JUMP(func_801C456C);
    v0 = *(volatile s32 *) (fp + 0x14);
    TAIL_JUMP(func_801C463C);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

extern u8 D_801CA88D;
extern void func_80028740(s32);
extern s32 func_801C43B4(s32, s32);
extern void func_801C4764();

void func_80065654(void) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    s32 pad[8];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[7]));
    v0 = D_801CA88D;
    if (v0 != 0) {
        goto initialized;
    }
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\tsll $3,$2,4\n\tmove $4,$3\n\tjal func_80028740\n\tnop\n\t.set\treorder" ::: "memory");
    v0 = 1;
    D_801CA88D = (u8) v0;
initialized:
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\tmove $4,$2\n\tjal func_80028770\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    v1 = v0 & 1;
    *(volatile s32 *) (fp + 0x10) = v1;
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C3FA4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 == 0) {
        goto check_result;
    }
    v0 = *(volatile s32 *) (fp + 0x14);
    v1 = -1;
    if (v0 != v1) {
        goto check_result;
    }
    MEMORY_BARRIER();
    v0 = 2;
    *(volatile s32 *) (fp + 0x14) = v0;
check_result:
    v0 = *(volatile s32 *) (fp + 0x14);
    if (v0 < 0) {
        goto after_clear;
    }
    D_801CA88D = 0;
after_clear:
    v0 = *(volatile s32 *) (fp + 0x14);
    if (v0 <= 0) {
        goto final;
    }
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\tsll $3,$2,4\n\tmove $4,$3\n\tori $5,$zero,2\n\tjal func_801C43B4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x14) = v0;
final:
    v0 = *(volatile s32 *) (fp + 0x14);
    v1 = 1;
    if (v0 != v1) {
        goto tail;
    }
    MEMORY_BARRIER();
    v0 = 2;
    *(volatile s32 *) (fp + 0x14) = v0;
tail:
    v0 = *(volatile s32 *) (fp + 0x14);
    TAIL_JUMP(func_801C4764);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

extern s32 func_801C4654(void);
extern void func_801C47B4(void);
extern void func_801C47E0(void);
extern void func_801C4794(void);
extern void func_801C4814(void);
extern void func_801C4820(void);

void func_8006577C(s32 arg0) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[8];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\tsw $4,0x20(%0)\n\tsw $zero,0x14(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[7]));
    v0 = *(volatile s32 *) (fp + 0x14);
    v1 = *(volatile s32 *) (fp + 0x20);
    if (v0 < v1) {
        goto body;
    }
    TAIL_JUMP(func_801C4814);
body:
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C4654\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    v0 = *(volatile s32 *) (fp + 0x10);
    v1 = -1;
    if (v0 == v1) {
        goto minus_one;
    }
    TAIL_JUMP(func_801C47E0);
minus_one:
    TAIL_JUMP(func_801C47B4);
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 == 0) {
        TAIL_JUMP(func_801C4814);
    }
    v1 = *(volatile s32 *) (fp + 0x14);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\tmove $3,$2" ::: "memory");
    *(volatile s32 *) (fp + 0x14) = v1;
    TAIL_JUMP(func_801C4794);
    v0 = *(volatile s32 *) (fp + 0x10);
    TAIL_JUMP(func_801C4820);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

extern u8 D_801CA88C;
extern s8 D_801BF144[];
extern s8 D_801BF14C[];
extern s8 D_801BF154[];
extern s8 D_801BF168[];
extern void func_800220B4(s32 *, s32);
extern s32 func_800220C4(s32);
extern void func_800222AC(s32 *, s32 *);
extern void func_800222CC(s32 *, s32 *);
extern void func_801C489C();
extern void func_801C48E4();
extern void func_801C490C();
extern void func_801C4960();
extern void func_801C496C();

void func_80065838(s32 arg0, s32 arg1) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[40];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x9C($sp)\n\tsw $30,0x98($sp)\n\taddu %0,$29,$zero\n\tsw $4,0xA0(%0)\n\tsw $5,0xA4(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[39]));
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 == 0) {
        __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlui $5,%%hi(D_801BF144)\n\taddiu $5,$5,%%lo(D_801BF144)\n\tjal func_800222CC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
        TAIL_JUMP(func_801C489C);
    }
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlui $5,%%hi(D_801BF14C)\n\taddiu $5,$5,%%lo(D_801BF14C)\n\tjal func_800222CC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    v0 = *(volatile s32 *) (fp + 0xA4);
    if (v0 == 0) {
        __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlui $5,%%hi(D_801BF154)\n\taddiu $5,$5,%%lo(D_801BF154)\n\tjal func_800222AC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
        TAIL_JUMP(func_801C48E4);
    }
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlui $5,%%hi(D_801BF168)\n\taddiu $5,$5,%%lo(D_801BF168)\n\tjal func_800222AC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x10) = 0;
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlw $5,0xA0($30)\n\tjal func_800220B4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    v1 = *(volatile s32 *) (fp + 0xA0);
    __asm__ volatile(".set\tnoreorder\n\tbne %0,%1,.L80065838_mismatch\n\tnop\n\t.set\treorder" : : "r"(v0), "r"(v1) : "memory");
    v1 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\taddu $3,$2,$zero\n\tsw $3,0x10($30)" ::: "memory");
    v1 = *(volatile s32 *) (fp + 0xA0);
    __asm__ volatile("nop\n\taddiu $2,$3,0x28\n\taddu $3,$2,$zero\n\tsw $3,0xA0($30)" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0xA0($30)\n\tjal func_800220C4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    v1 = *(volatile s32 *) (fp + 0xA0);
    if (v0 != v1) {
        TAIL_JUMP(func_801C4960);
    }
    TAIL_JUMP(func_801C490C);
    __asm__ volatile(".L80065838_mismatch:");
    v0 = *(volatile s32 *) (fp + 0x10);
    TAIL_JUMP(func_801C496C);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x9C($29)\n\tlw $30,0x98($29)\n\t.set\treorder" ::: "memory");
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80065984);

void func_80065AB8(void) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[8];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x1C($sp)\n\tsw $30,0x18($sp)\n\taddu %0,$29,$zero\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[7]));
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,10\n\tjal func_801C477C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    v0 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("ori $3,$zero,3" ::: "memory");
    if (v0 != v1) {
        goto after_first;
    }
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\tsll $3,$2,4\n\tmove $4,$3\n\tori $5,$zero,10\n\tjal func_801C4550\n\tnop\n\tsw $2,0x10($30)\n\t.set\treorder" : "=r"(v0)::"memory");
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 == 0) {
        goto after_first;
    }
    __asm__ volatile("ori $2,$zero,2" ::: "memory");
    TAIL_JUMP(func_801C4B9C);
after_first:
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 != 0) {
        goto check_three;
    }
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\tsll $3,$2,4\n\tmove $4,$3\n\tori $5,$zero,0x1e\n\tjal func_801C447C\n\tnop\n\tsw $2,0x10($30)\n\t.set\treorder" : "=r"(v0)::"memory");
check_three:
    v0 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("ori $3,$zero,3" ::: "memory");
    if (v0 != v1) {
        goto final;
    }
    __asm__ volatile("ori $2,$zero,3" ::: "memory");
    TAIL_JUMP(func_801C4B9C);
final:
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 == 0) {
        goto tail;
    }
    __asm__ volatile("ori $2,$zero,2" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v0;
tail:
    v0 = *(volatile s32 *) (fp + 0x10);
    TAIL_JUMP(func_801C4B9C);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x1C($29)\n\tlw $30,0x18($29)\n\t.set\treorder" ::: "memory");
    return;
}

void func_80065BB4(void) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    s32 pad[10];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x24($sp)\n\tsw $30,0x20($sp)\n\taddu %0,$29,$zero\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[9]));
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,10\n\tjal func_801C477C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 <= 0) {
        goto check;
    }
    __asm__ volatile("move $2,$zero" ::: "memory");
    TAIL_JUMP(func_801C4C84);
check:
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA88C)\n\tlbu $2,%%lo(D_801CA88C)($2)\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 != 0) {
        goto nonzero;
    }
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlui $5,%%hi(D_801BF144)\n\taddiu $5,$5,%%lo(D_801BF144)\n\tjal func_800222CC\n\tnop\n\tj func_801C4C3C\n\tnop\n\t.set\treorder" ::: "memory");
nonzero:
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlui $5,%%hi(D_801BF14C)\n\taddiu $5,$5,%%lo(D_801BF14C)\n\tjal func_800222CC\n\tnop\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tjal func_800220A4\n\tnop\n\tsw $2,0x10($30)\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tjal func_800220A4\n\tnop\n\tsw $2,0x10($30)\n\t.set\treorder" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tjal func_800220A4\n\tnop\n\tsw $2,0x10($30)\n\t.set\treorder" ::: "memory");
    v0 = *(volatile s32 *) (fp + 0x10);
    TAIL_JUMP(func_801C4C84);
done:
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x24($29)\n\tlw $30,0x20($29)\n\t.set\treorder" ::: "memory");
    return;
}

extern s32 D_801CA888;
extern s32 func_80022054(s32 *, s32);
extern s32 func_801C3F34();
extern s32 func_801C477C(s32);
extern s32 func_801C4E1C(s32);
extern void func_801C4D44();
extern void func_801C4D58();
extern void func_801C4DF4();
extern void func_801C4E04();

void func_80065C9C(s32 arg0, s32 arg1) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[40];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x9C($sp)\n\tsw $30,0x98($sp)\n\taddu %0,$29,$zero\n\tsw $4,0xA0(%0)\n\tsw $5,0xA4(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[39]));
    *(volatile s32 *) (fp + 0x10) = 0;
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA888)\n\tlw $2,%%lo(D_801CA888)($2)\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 >= 0) {
        __asm__ volatile(".set\tnoreorder\n\tlui $4,%%hi(D_801CA888)\n\tlw $4,%%lo(D_801CA888)($4)\n\tjal func_801C4E1C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
        *(volatile s32 *) (fp + 0x14) = v0;
        v0 = *(volatile s32 *) (fp + 0x14);
        if (v0 == 0) {
            __asm__ volatile(".set\tnoreorder\n\taddiu $2,$zero,-2\n\tj func_801C4E04\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
        }
    }
    __asm__ volatile(".set\tnoreorder\n\tjal func_801C3F34\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 == 0) {
        __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlui $5,%%hi(D_801BF144)\n\taddiu $5,$5,%%lo(D_801BF144)\n\tjal func_800222CC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
        TAIL_JUMP(func_801C4D44);
    }
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlui $5,%%hi(D_801BF14C)\n\taddiu $5,$5,%%lo(D_801BF14C)\n\tjal func_800222CC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlw $5,0xA0($30)\n\tjal func_800222AC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    v0 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("slti $3,$2,0x28" : "=r"(v1) : "r"(v0));
    if (v1 == 0) {
        TAIL_JUMP(func_801C4DF4);
    }
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,0xA\n\tjal func_801C477C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v0 = *(volatile s32 *) (fp + 0x14);
    if (v0 != 0) {
        __asm__ volatile(".set\tnoreorder\n\taddiu $2,$zero,-2\n\tj func_801C4E04\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    }
    __asm__ volatile(".set\tnoreorder\n\taddiu $2,$30,0x18\n\tmove $4,$2\n\tlw $5,0xA4($30)\n\tjal func_80022054\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile(".set\tnoreorder\n\tlui $1,%%hi(D_801CA888)\n\tsw %0,%%lo(D_801CA888)($1)\n\t.set\treorder" : : "r"(v0) : "memory");
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA888)\n\tlw $2,%%lo(D_801CA888)($2)\n\t.set\treorder" : "=r"(v0)::"memory");
    v1 = -1;
    if (v0 != v1) {
        TAIL_JUMP(func_801C4DF4);
    }
    v1 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\taddu $3,$2,$zero\n\tsw $3,0x10($30)" ::: "memory");
    TAIL_JUMP(func_801C4D58);
    __asm__ volatile(".L80065C9C_final:");
    __asm__ volatile(".set\tnoreorder\n\tlui $2,%%hi(D_801CA888)\n\tlw $2,%%lo(D_801CA888)($2)\n\t.set\treorder" : "=r"(v0)::"memory");
    TAIL_JUMP(func_801C4E04);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x9C($29)\n\tlw $30,0x98($29)\n\t.set\treorder" ::: "memory");
    return;
}

void func_80065E1C(s32 arg0) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[10];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x24($sp)\n\tsw $30,0x20($sp)\n\taddu %0,$29,$zero\n\tsw $4,0x28(%0)\n\tsw $zero,0x10(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[9]));
    v0 = *(volatile s32 *) (fp + 0x10);
    v1 = v0 < 10;
    if (v1 != 0) {
        goto body;
    }
    TAIL_JUMP(func_801C4EBC);
body:
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,10\n\tjal func_801C477C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    __asm__ volatile("xori $3,$2,0\n\tsltiu $2,$3,1" ::: "memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tjal func_80022094\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x18) = v0;
    v0 = *(volatile s32 *) (fp + 0x18);
    v1 = *(volatile s32 *) (fp + 0x28);
    if (v0 != v1) {
        goto different;
    }
    TAIL_JUMP(func_801C4EBC);
    TAIL_JUMP(func_801C4EA0);
different:
    *(volatile s32 *) (fp + 0x14) = 0;
    v1 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\tmove $3,$2" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v1;
    TAIL_JUMP(func_801C4E34);
    v0 = -1;
    D_801CA888 = v0;
    v0 = *(volatile s32 *) (fp + 0x14);
    TAIL_JUMP(func_801C4ED4);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x24($29)\n\tlw $30,0x20($29)\n\t.set\treorder" ::: "memory");
    return;
}

void func_80065EEC(s32 arg0, s32 arg1, s32 arg2) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    s32 pad[10];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x24($sp)\n\tsw $30,0x20($sp)\n\taddu %0,$29,$zero\n\tsw $4,0x28(%0)\n\tsw $5,0x2C(%0)\n\tsw $6,0x30(%0)\n\tsw $zero,0x10(%0)\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[9]));
    v0 = *(volatile s32 *) (fp + 0x10);
    v1 = v0 < 10;
    if (v1 != 0) {
        goto body;
    }
    TAIL_JUMP(func_801C4F94);
body:
    __asm__ volatile(".set\tnoreorder\n\tori $4,$zero,10\n\tjal func_801C477C\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 == 0) {
        goto second;
    }
    __asm__ volatile("addiu $2,$zero,-1" ::: "memory");
    TAIL_JUMP(func_801C4FA0);
second:
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tlw $5,0x2C($30)\n\tlw $6,0x30($30)\n\tjal func_80022064\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x18) = v0;
    v0 = *(volatile s32 *) (fp + 0x18);
    v1 = -1;
    if (v0 == v1) {
        goto increment;
    }
    TAIL_JUMP(func_801C4F94);
increment:
    v1 = *(volatile s32 *) (fp + 0x10);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\tmove $3,$2" ::: "memory");
    *(volatile s32 *) (fp + 0x10) = v1;
    TAIL_JUMP(func_801C4F0C);
    v0 = *(volatile s32 *) (fp + 0x18);
    TAIL_JUMP(func_801C4FA0);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x24($29)\n\tlw $30,0x20($29)\n\t.set\treorder" ::: "memory");
    return;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80065FB8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80066264);

extern s32 func_80022074(s32, s32, s32);
extern s32 func_800220E4(s32);
extern s32 func_801C4EEC(s32, s32, s32);
extern void func_801C53F8();
extern void func_801C5488();
extern void func_801C54B0();

void func_80066378(s32 arg0, s32 arg1, s32 arg2) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    s32 pad[10];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x24($sp)\n\tsw $30,0x20($sp)\n\taddu %0,$29,$zero\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[9]));
    __asm__ volatile("sw $4,0x28($30)\n\tsw $5,0x2C($30)\n\tsw $6,0x30($30)" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tmove $5,$zero\n\tli $6,1\n\tjal func_801C4EEC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x1C) = v0;
    v0 = *(volatile s32 *) (fp + 0x1C);
    if (v0 < 0) {
        __asm__ volatile(".set\tnoreorder\n\taddiu $2,$zero,-1\n\tj func_801C54B0\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    }
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tjal func_800220E4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 != 0) {
        __asm__ volatile(".set\tnoreorder\n\taddiu $2,$zero,-1\n\tj func_801C54B0\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    }
    *(volatile s32 *) (fp + 0x18) = 0;
    v0 = *(volatile s32 *) (fp + 0x18);
    __asm__ volatile("slti $3,$2,0xA" : "=r"(v1) : "r"(v0));
    if (v1 == 0) {
        TAIL_JUMP_NOP(func_801C5488);
    }
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tlw $5,0x2C($30)\n\tlw $6,0x30($30)\n\tjal func_80022074\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v0 = *(volatile s32 *) (fp + 0x14);
    v1 = *(volatile s32 *) (fp + 0x30);
    if (v0 == v1) {
        TAIL_JUMP_NOP(func_801C5488);
    }
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tlw $5,0x1C($30)\n\tmove $6,$zero\n\tjal func_801C4EEC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 < 0) {
        TAIL_JUMP_NOP(func_801C5488);
    }
    v1 = *(volatile s32 *) (fp + 0x18);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\taddu $3,$2,$zero\n\tsw $3,0x18($30)" ::: "memory");
    TAIL_JUMP_NOP(func_801C53F8);
    v0 = *(volatile s32 *) (fp + 0x14);
    v1 = *(volatile s32 *) (fp + 0x30);
    __asm__ volatile(".set\tnoreorder\n\tbeq %0,%1,.L80066378_final\n\tnop\n\t.set\treorder" : : "r"(v0), "r"(v1) : "memory");
    __asm__ volatile("addiu $2,$zero,-1\n\tsw $2,0x14($30)" ::: "memory");
    __asm__ volatile(".L80066378_final:");
    v0 = *(volatile s32 *) (fp + 0x14);
    TAIL_JUMP_NOP(func_801C54B0);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x24($29)\n\tlw $30,0x20($29)\n\t.set\treorder" ::: "memory");
    return;
}

extern s32 func_80022084(s32, s32, s32);
extern void func_801C5548();
extern void func_801C55D8();
extern void func_801C5600();

void func_800664C8(s32 arg0, s32 arg1, s32 arg2) {
    register s32 fp asm("$30");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");
    register s32 a2 asm("$6");
    s32 pad[10];

    __asm__ volatile(".set\tnoreorder\n\tsw $31,0x24($sp)\n\tsw $30,0x20($sp)\n\taddu %0,$29,$zero\n\t.set\treorder" : "=r"(fp)::"memory");
    __asm__ volatile("" : : "m"(pad[0]), "m"(pad[9]));
    __asm__ volatile("sw $4,0x28($30)\n\tsw $5,0x2C($30)\n\tsw $6,0x30($30)" ::: "memory");
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tmove $5,$zero\n\tli $6,1\n\tjal func_801C4EEC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x1C) = v0;
    v0 = *(volatile s32 *) (fp + 0x1C);
    if (v0 < 0) {
        __asm__ volatile(".set\tnoreorder\n\taddiu $2,$zero,-1\n\tj func_801C5600\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    }
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tjal func_800220E4\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x10) = v0;
    v0 = *(volatile s32 *) (fp + 0x10);
    if (v0 != 0) {
        __asm__ volatile(".set\tnoreorder\n\taddiu $2,$zero,-1\n\tj func_801C5600\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    }
    *(volatile s32 *) (fp + 0x18) = 0;
    v0 = *(volatile s32 *) (fp + 0x18);
    __asm__ volatile("slti $3,$2,0xA" : "=r"(v1) : "r"(v0));
    if (v1 == 0) {
        TAIL_JUMP_NOP(func_801C55D8);
    }
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tlw $5,0x2C($30)\n\tlw $6,0x30($30)\n\tjal func_80022084\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    *(volatile s32 *) (fp + 0x14) = v0;
    v0 = *(volatile s32 *) (fp + 0x14);
    v1 = *(volatile s32 *) (fp + 0x30);
    if (v0 == v1) {
        TAIL_JUMP_NOP(func_801C55D8);
    }
    __asm__ volatile(".set\tnoreorder\n\tlw $4,0x28($30)\n\tlw $5,0x1C($30)\n\tmove $6,$zero\n\tjal func_801C4EEC\n\tnop\n\t.set\treorder" : "=r"(v0)::"memory");
    if (v0 < 0) {
        TAIL_JUMP_NOP(func_801C55D8);
    }
    v1 = *(volatile s32 *) (fp + 0x18);
    __asm__ volatile("nop\n\taddiu $2,$3,1\n\taddu $3,$2,$zero\n\tsw $3,0x18($30)" ::: "memory");
    TAIL_JUMP_NOP(func_801C5548);
    v0 = *(volatile s32 *) (fp + 0x14);
    v1 = *(volatile s32 *) (fp + 0x30);
    __asm__ volatile(".set\tnoreorder\n\tbeq %0,%1,.L800664C8_final\n\tnop\n\t.set\treorder" : : "r"(v0), "r"(v1) : "memory");
    __asm__ volatile("addiu $2,$zero,-1\n\tsw $2,0x14($30)" ::: "memory");
    __asm__ volatile(".L800664C8_final:");
    v0 = *(volatile s32 *) (fp + 0x14);
    TAIL_JUMP_NOP(func_801C5600);
    __asm__ volatile(".set\tnoreorder\n\taddu $29,$30,$zero\n\tlw $31,0x24($29)\n\tlw $30,0x20($29)\n\t.set\treorder" ::: "memory");
    return;
}

extern s8 D_801CA890;
extern s16 D_801D9278;
extern s16 D_801D927C;
extern u16 D_801D9288;
extern u16 D_801D9290;
extern u8 D_801D9294[];
extern s32 D_801D92A8;
extern void func_800449EC();
extern s32 func_800246D4(s32);
extern void func_8001DBA8(s8 *);
extern void func_80024A88(s8 *, u16 *);
extern void func_80024C38(s8 *);
extern void func_80024CAC(s8 *);
extern void func_80024E84(s8 *);

void func_80066618(s32 arg0, s32 arg1) {
    register s32 s0 asm("$16");
    register s32 s1 asm("$17");
    register s32 s2 asm("$18");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a0 asm("$4");
    register s32 a1 asm("$5");

    v0 = (s32) D_801D9294_ptr;
    s1 = arg0;
    s2 = *(s32 *) v0;
    s0 = arg1;
    func_800449EC();
    D_801D9278 = 0;
    D_801D9290 = 0;
    do {
    } while (func_800246D4(1) != 0);
    a0 = D_801CA890;
    func_8001DBA8((s8 *) a0);
    v1 = D_801D92A8;
    v0 = (s32) D_801D9294_ptr;
    if (v0 == v1) {
        v1 += 0xF4;
    }
    D_801D9294_ptr = (u8 *) v1;
    a0 = v1 + 0xBC;
    func_80024E84((s8 *) a0);
    a0 = (s32) D_801D9294_ptr + 0x60;
    func_80024CAC((s8 *) a0);
    v0 = (s32) D_801D9294_ptr;
    v0 = *(u16 *) (v0 + 0x62);
    D_801D927C = v0;
    v0 = -1;
    if (s0 != v0) {
        v1 = s1 << 2;
        a0 = s0 << 2;
        a0 = s2 + a0;
        func_80024C38((s8 *) a0);
    }
    v1 = s1 << 2;
    v0 = (s32) D_801D9294_ptr;
    a1 = D_801D9288;
    a0 = *(s32 *) v0;
    a1 -= s1;
    a0 = v1 + a0;
    func_80024A88((s8 *) a0, (u16 *) a1);
}

extern void func_80023DD0(void *);
extern u16 D_801D9270;
extern u16 D_801D928C;

void func_80066724(register s32 s2) {
    s32 s0;
    s32 s1;
    s32 v0;
    s32 a0;
    s32 a1;
    s32 pad[4];

    v0 = D_801D9270;
    s0 = 0;
    if (v0 > 0) {
        s1 = 0;
        do {
            a0 = *(s32 *) (s2 + 0x10) + s1;
            func_80023D1C((void *) a0);
            s0++;
            a0 = *(s32 *) (s2 + 0x10) + s1;
            a1 = 0;
            func_80023C90((void *) a0, a1);
            s1 += 0x28;
            v0 = D_801D9270;
        } while (s0 < (s32) v0);
    }
    v0 = D_801D928C;
    if (v0 > 0) {
        s0 = 0;
        do {
            v0 = *(s32 *) (s2 + 0x3C);
            a0 = s0 << 4;
            a0 += v0;
            func_80023DD0((void *) a0);
            s0++;
            v0 = D_801D928C;
        } while (s0 < (s32) v0);
    }
}

extern void func_80022DE0(s32, s32, s32, s32, s32);
extern void func_80022EB0(s32, s32, s32, s32, s32);
extern void func_801C5618(s32, s32);
extern void func_801C5724(void *, s32);

void func_800667E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15, s32 arg16) {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 temp_const;
    s32 s4;
    s32 s5;
    s32 s6;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");
    register s32 a0 asm("a0");
    register s32 temp_lo asm("a1");

    s1 = 0;
    temp_const = 0xF0;
    s2 = 0;
    s0 = 0;
    s4 = arg1;
    s6 = arg5;
    s5 = arg16;

    D_801D92A8 = arg0;
    *(s32 *) D_801D9294 = arg0;
    do {
        v1 = D_801D9288 * s1;
        temp_lo = D_801D9270 * s1;
        v0 = D_801D928C * s1;
        a0 = D_801D92A8;
        a0 = s0 + a0;
        *(s32 *) a0 = arg1 + (v1 << 2);
        *(s32 *) (a0 + 0x10) = arg5 + (temp_lo * 0x28);
        *(s32 *) (a0 + 0x3C) = arg16 + (v0 << 4);
        func_801C5724((void *) a0, temp_lo);
        a0 = D_801D92A8;
        a0 = s0 + a0;
        func_80022DE0(a0 + 0x60, 0, s2, 0x100, temp_const);
        a0 = D_801D92A8;
        a0 = s0 + a0;
        func_80022EB0(a0 + 0xBC, 0, -(s1 == 0) & 0xF0, 0x100, temp_const);
        v0 = D_801D92A8;
        v0 = s0 + v0;
        *(u8 *) (v0 + 0x78) = 0;
        v0 = D_801D92A8;
        v0 = s0 + v0;
        *(u8 *) (v0 + 0x79) = 0;
        v0 = D_801D92A8;
        v0 = s0 + v0;
        s2 += 0xF0;
        *(u8 *) (v0 + 0x7A) = 0;
        v0 = D_801D92A8;
        v0 = s0 + v0;
        s1 += 1;
        *(u8 *) (v0 + 0x7B) = 0;
        v1 = D_801D92A8;
        v1 = s0 + v1;
        *(s16 *) (v1 + 0x68) = -0x80;
        s0 += 0xF4;
    } while (s1 < 2);
    func_801C5618(0, -1);
    func_801C5618(0, -1);
}

extern void func_8013DA00();

void func_800669B0(s32 arg0) {
    D_801CA890 = arg0;
    if (arg0 == 0) {
        arg0 = 1;
    }
    func_8013DA00(arg0);
}

s32 func_800669E4(void) {
    s32 r = 1;
    s32 v = D_801CA890;

    if (v == 0) {
    } else {
        r = v;
    }
    return r;
}

extern void func_801C7D04(s16 *, u8, u8, void *, s32, s32, s32, s32);
extern u8 D_801D91D8[];
extern s16 D_801D91DC;
extern s16 D_801D91E0;
extern u16 D_801D91F0;
extern u16 D_801D91F4;

void *func_80066A04(u8 *arg0) {
    s16 buf[4];
    u8 *p;
    u8 v0;
    u8 v1;

    v0 = arg0[3];
    v1 = arg0[4];
    buf[0] = v0;
    buf[1] = v1;
    buf[2] = arg0[5];
    buf[3] = arg0[6];
    p = D_801D91D8;
    if (arg0[0] == 4) {
        p = 0;
    }
    func_801C7D04(buf, arg0[7], arg0[8], p, D_801D91E0, D_801D91F0, D_801D91F4, D_801D91DC);
    return arg0 + arg0[1];
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80066AB8);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_800671E0);

u8 *func_80067510(u8 *arg0) {
    u8 *local = arg0;

    D_801D91F0 = func_8002398C(local[4], 0, local[3] << 4, local[2] << 8);
    return local + local[1];
}

u8 *func_80067564(u8 *arg0) {
    D_801D91DC = arg0[3];
    return arg0 + arg0[1];
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_8006757C);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_8006770C);

void func_80067998(u8 *arg0) {
    D_801D91D8[0] = arg0[0];
    D_801D91D8[1] = arg0[1];
    D_801D91D8[2] = arg0[2];
}

void func_800679C4(s16 arg0) {
    D_801D91DC = arg0;
}

extern u8 D_801D91F8[];
extern u8 D_801D91D9[];
extern u8 D_801D91DA[];
extern u16 D_801CA8C4[];
extern u16 D_801CA8A4[];
extern u16 D_801CA8A2[];
extern u16 D_801CA8AA[];
extern u16 D_801CA8B2[];
extern u16 D_801CA8B4[];
extern u16 D_801CA8C6[];
extern u16 D_801CA8A6[];
extern u16 D_801CA8A0[];
extern u16 D_801CA8A8[];
extern u16 D_801CA8AE[];
extern u16 D_801CA8B0[];
extern u16 D_801D92A0;
extern u16 D_801D9280;
extern u16 D_801D9274;
extern u16 D_801D926C;
extern u16 D_801D92A4;
extern u16 D_801D92B0;

void func_800679D4(s32 arg0) {
    register s32 m asm("$2");
    register s32 r3 asm("$3");
    register s32 r4 asm("$4");
    register s32 r5 asm("$5");
    register s32 r6 asm("$6");
    register s32 r7 asm("$7");
    register s32 r8 asm("$8");
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;

    D_801D91F8[0] = arg0;
    if (arg0 == 0) {
        goto b0;
    }
    {
        m = 0x60;
        r3 = D_801CA8C4[0];
        r4 = D_801CA8A4[0];
        r5 = D_801CA8A2[0];
        r6 = D_801CA8AA[0];
        r7 = D_801CA8B2[0];
        r8 = D_801CA8B4[0];
        D_801D91D8[0] = m;
        D_801D91D9[0] = m;
        __asm__ volatile(".set\tnoreorder\n\t"
                         "j func_801C6A70\n\t"
                         "ori $2,$zero,0x80\n\t"
                         ".set\treorder\n\t" ::"r"(r3),
                         "r"(r4),
                         "r"(r5),
                         "r"(r6),
                         "r"(r7),
                         "r"(r8) : "memory");
    }
b0:
    a = D_801CA8C6[0];
    b = D_801CA8A6[0];
    c = D_801CA8A0[0];
    d = D_801CA8A8[0];
    e = D_801CA8AE[0];
    f = D_801CA8B0[0];
    m = 0x80;
    D_801D91D8[0] = m;
    D_801D91D9[0] = m;
    D_801D91DA[0] = m;
    D_801D92A0 = a;
    D_801D9280 = b;
    D_801D9274 = c;
    D_801D926C = d;
    D_801D92A4 = e;
    D_801D92B0 = f;
}

s32 func_80067AB0(void) {
    return (s32) D_801D91D8;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80067AC0);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80067BF4);

s32 func_80067C48(s32 arg0) {
    return arg0;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80067C50);

extern void func_8014C8A0();
extern s32 func_8014CA1C();
extern void func_8014CA38();
extern s32 D_801308C0;

void func_80067ED8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_8014CA1C() == 0) {
        func_8014C8A0(arg0, &D_801308C0);
        func_8014CA38(arg0, arg1, arg2, arg3);
    }
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80067F50);

void func_80068030(s32 arg0) {
    func_8014CA38(arg0, 0, 0, 1);
}

extern s32 func_801C7094(u8 *, s32);

s32 func_80068058(u8 *arg0) {
    s32 n;

    n = 0;
    if (*arg0 != 0xFE) {
        for (;;) {
            if ((u8) (*arg0 + 0x30) < 0x10) {
                __asm__ volatile(".set\tnoreorder\n\t"
                                 "j func_801C7094\n\t"
                                 "addiu $4,$4,2\n\t" ::"r"(n),
                                 "r"(arg0));
            }
            arg0++;
            n++;
            if (*arg0 == 0xFE) {
                break;
            }
        }
    }
    return n;
}

extern void func_800222FC();
extern void func_801C6C50();
extern void func_801C861C(u16 *, void *);

struct func_800680AC_fields {
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

void func_800680AC(s32 arg0, s16 *arg1, void *arg2, s32 arg3) {
    s32 lowpad[6];
    u8 sp28[0x800];
    struct func_800680AC_fields f;
    s32 pad[4];
    register u8 *s0v asm("$16");
    register s32 s1v asm("$17");
    register s32 s2v asm("$18");
    register s32 s3v asm("$19");
    register s32 v0 asm("$2");
    register s32 v1 asm("$3");
    register s32 a3v asm("$7");
    register s32 a0v asm("$4");

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
        __asm__ volatile(".L800680AC_loop:");
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
            ((void (*)(void)) func_801C6C50)();
            func_801C861C(&f.f830, (void *) &sp28[0]);
            v0 = *(u16 *) &f.f832;
            s0v = s0v + 2;
            v0 = v0 + 0x10;
            f.f832 = (u16) v0;
            v0 = *(s16 *) s0v;
            a3v = *(u16 *) s0v;
            __asm__ volatile(".set\tnoreorder\n\tbne $2,$17,.L800680AC_loop\n\taddiu $4,$29,0x28\n\t.set\treorder" : : "r"(v0), "r"(a3v), "r"(s1v) : "memory");
        } while (0);
    }
}

extern void func_801C7030();
extern s32 D_801CA93C;

void func_800681B4(void) {
    func_801C7030();
    D_801CA93C = 0;
}

extern void func_801C3A4C(s32 *, s32, s32);
extern void func_801C71EC(void);

void func_800681DC(s32 arg0) {
    s32 sp10;
    s32 s0v;

    __asm__("move %0, %1" : "=r"(s0v) : "r"(arg0));
    if (func_8014CA1C(s0v) != 0) {
        func_801C7030(s0v);
        func_801C3A4C(&sp10, 0, 0);
        TAIL_JUMP(func_801C71EC);
    }
    D_801CA93C = 0;
}

extern void func_8014C8A0(s32, s32);
extern void func_8014CA38(s32, void *, s32, s32);
extern s32 func_801C72BC();
extern void *D_80173CB8;

s32 func_80068238(s32 arg0, void *arg1) {
    register s32 s0v asm("s0") = arg0;
    register void *s1v asm("s1") = arg1;
    register s32 a1v asm("a1");
    register s32 onev asm("v1");
    register s32 result asm("v0");

    if (D_801CA93C != 0) {
        goto nonzero;
    }
    result = func_8014CA1C();
    if (result != 0) {
        return 1;
    }
    result = 1;
    a1v = *(s32 *) ((u8 *) s1v + 0x28);
    D_80173CB8 = s1v;
    func_8014C8A0(s0v, a1v);
    func_8014CA38(s0v, D_80173CB8, 0, 0);
    onev = 1;
    D_801CA93C = onev;
    __asm__ volatile(".set\tnoreorder\n\tj func_801C72BC\n\tori $2,$0,1\n\t.set\treorder");
nonzero:
    result = func_8014CA1C(s0v);
    D_801CA93C = result;
end:
    return result;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_800682D4);

extern u8 D_801CA940;
extern s32 D_801D9210;

void func_80068384(s32 arg0) {
    D_801CA940 = 1;
    D_801D9210 = arg0;
}

extern u8 D_801CA941;
extern s32 D_801D9214;

void func_800683A0(s32 arg0) {
    D_801CA941 = 1;
    D_801D9214 = arg0;
}

extern s32 D_801CA944;

s32 func_800683BC(s32 arg0) {
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
            "lui $2,%hi(D_801CA940)\n"
            "lbu $2,%lo(D_801CA940)($2)\n"
            "nop\n"
            "beqz $2,1f\n"
            "move $7,$0\n"
            "ori $2,$0,7\n"
            "lui $1,%hi(D_801CA944)\n"
            "sw $2,%lo(D_801CA944)($1)\n"
            "lui $1,%hi(D_801CA940)\n"
            "sb $0,%lo(D_801CA940)($1)\n"
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
        p = (u8 *) D_801D9210;
        n = D_801CA944;
        v = *p;
        a1 = n - 1;
        D_801CA944 = a1;
        if ((v >> n) & 1) {
            acc |= t2 << arg0;
        }
        arg0--;
        if (a1 < 0) {
            D_801CA944 = t1;
            D_801D9210 = (s32) (p + 1);
        }
        if (arg0 != t0) {
            continue;
        }
        break;
    }
    return acc;
}

extern s32 D_801CA948;
extern u8 *D_801D9210_b asm("D_801D9210");

void func_80068468(s32 arg0) {
    s32 temp_a1;
    s32 temp_v1;

    if (D_801CA940 != 0) {
        D_801CA948 = 7;
        D_801CA940 = 0;
    }
    temp_v1 = D_801CA948;
    D_801CA948 = temp_v1 - 1;
    temp_a1 = 1 << temp_v1;
    *D_801D9210_b &= ~temp_a1;
    if (arg0 & 0xFF) {
        *D_801D9210_b = temp_a1 | *D_801D9210_b;
    }
    if (D_801CA948 < 0) {
        D_801CA948 = 7;
        D_801D9210_b += 1;
    }
}

extern s32 D_801CA94C;

s32 func_80068524(s32 arg0) {
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
            "lui $2,%hi(D_801CA941)\n"
            "lbu $2,%lo(D_801CA941)($2)\n"
            "nop\n"
            "beqz $2,1f\n"
            "move $7,$0\n"
            "ori $2,$0,7\n"
            "lui $1,%hi(D_801CA94C)\n"
            "sw $2,%lo(D_801CA94C)($1)\n"
            "lui $1,%hi(D_801CA941)\n"
            "sb $0,%lo(D_801CA941)($1)\n"
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
        p = (u8 *) D_801D9214;
        n = D_801CA94C;
        v = *p;
        a1 = n - 1;
        D_801CA94C = a1;
        if ((v >> n) & 1) {
            acc |= t2 << arg0;
        }
        arg0--;
        if (a1 < 0) {
            D_801CA94C = t1;
            D_801D9214 = (s32) (p + 1);
        }
        if (arg0 != t0) {
            continue;
        }
        break;
    }
    return acc;
}

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_800685D0);

extern void func_801C75D0();
extern s32 func_801C83E8();
extern s16 D_801D9268;
extern s32 D_801D9298;
extern s32 D_801D92AC;

void func_80068924(void) {
    func_801C75D0();
    if (func_801C83E8() != 0) {
        D_801D9268 = 0;
        D_801D9298 = 0;
        D_801D92AC = 0;
    }
}

void func_8006896C(void) {
    D_801D9268 = 0;
    D_801D92AC = 0;
    D_801D9298 = 0;
}

extern void func_80023C68();

void func_8006898C(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u16 n;
    u8 *p;
    s32 *b1;
    register s32 *b2 asm("a2");
    register s32 mlo asm("a0");
    s32 i;

    n = D_801D9290;
    D_801D9290 = n + 1;
    b1 = *(s32 **) ((u8 *) &D_801D9290 + 4);
    p = *(u8 **) ((u8 *) b1 + 0x3C) + n * 0x10;
    p[4] = arg1[0];
    p[5] = arg1[1];
    p[6] = arg1[2];
    func_80023C68(p, arg2 & 0xFF);
    b2 = *(s32 **) D_801D9294;
    i = arg3 * 4;
    mlo = 0xFFFFFF;
    *(s16 *) (p + 8) = *(u16 *) arg0 + 0x80;
    *(u16 *) (p + 10) = *(u16 *) (arg0 + 2);
    *(u16 *) (p + 12) = *(u16 *) (arg0 + 4);
    *(u16 *) (p + 14) = *(u16 *) (arg0 + 6);
    *(s32 *) p = (*(s32 *) p & 0xFF000000) | (*(s32 *) (i + *b2) & mlo);
    *(s32 *) (i + *b2) = (*(s32 *) (i + *b2) & 0xFF000000) | ((s32) p & mlo);
}

extern void func_801C7B60();
extern void func_801CD93C();

void func_80068A8C(u8 *arg0, u8 *arg1, s32 arg2, u16 arg3, u16 arg4, s32 arg5, s32 arg6) {
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
            a0 = (u16) D_801D9278;
            v1 = (s32) D_801D9294_ptr;
            v0 = a0 + 1;
            D_801D9278 = v0;
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
            __asm__ volatile(".set\tnoreorder\n\tj func_801C7B60\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
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
            a0 = (s32) D_801D9294_ptr;
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

extern void func_801C7DB8();

void func_80068D04(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4, u16 arg5, u16 arg6, s32 arg7) {
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
    a0 = (u16) D_801D9278;
    D_801D9278 = a0 + 1;
    s5 = arg6;
    s3 = arg1;
    s4 = arg2;
    __asm__("move %0,%1" : "=r"(s2) : "r"(arg3));
    s0 = (u8 *) &((EventCoord28 *) *(EventCoord28 **) ((u8 *) D_801D9294_ptr + 0x10))[a0];
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
        __asm__ volatile(".set\tnoreorder\n\tj func_801C7DB8\n\tsb %0,0x6(%1)\n\t.set\treorder" ::"r"(v0), "r"(s0) : "memory");
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
    s0[0xC] = s3;
    s0[0xD] = s4;
    *(u16 *) (s0 + 0x22) = v0 + v1;
    v0 = *(u8 *) (s1 + 4);
    s0[0x15] = s4;
    s0[0x1C] = s3;
    s0[0x14] = s3 + v0;
    v0 = s1[6];
    a1 = 0xFF0000;
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
    a3 = (s32) D_801D9294_ptr;
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

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_80068F18);

INCLUDE_ASM("rom/extracted/blobs/event/nonmatchings/CARD", func_8006932C);

extern u8 D_801CA954;
extern u8 D_801CA955;

s32 func_800693E8(void) {
    return D_801CA954 + (D_801CA955 << 1);
}

extern u16 D_801D9264;

void func_80069404(void) {
    D_801CA954 = 1;
    D_801D9264 = 0xF0;
}

void func_80069424(void) {
    D_801CA955 = 1;
    D_801D9264 = 0;
}

extern s32 func_801C59E4();
extern void func_801C832C(s32, s32, s32, s32, s32);
extern void func_801C798C(void *, void *, s32, s32);
extern u8 D_801CA958[];
extern u8 D_801D9260[];
extern u8 D_801D9261;
extern u8 D_801D9262;

s32 func_80069440(void) {
    s32 temp_a0;
    s32 temp_a3;
    s32 var_s0;
    u8 *p;
    u8 temp_v1;
    u16 temp_v0;

    var_s0 = 1;
    temp_a0 = func_801C59E4();
    if (D_801CA954 != 0) {
        temp_v0 = D_801D9264 - (temp_a0 * 8);
        D_801D9264 = temp_v0;
        if ((s16) temp_v0 <= 0) {
            D_801CA954 = 0;
            var_s0 = 0;
        }
        func_801C832C(0, 0, func_8002398C(0, 2, 0x100, 0) & 0xFFFF, 0, D_801D9288 - 2);
        temp_v1 = (u8) D_801D9264;
        p = &D_801D9260[0];
        D_801D9262 = temp_v1;
        D_801D9261 = temp_v1;
        temp_a3 = D_801D9288 - 1;
        *p = temp_v1;
        func_801C798C(D_801CA958, p, 1, temp_a3);
    }
    return var_s0;
}

s32 func_80069524(void) {
    s32 temp_a0;
    s32 temp_a3;
    s32 var_s0;
    u8 *p;
    s32 unused[4];
    u8 temp_v1;
    u16 temp_v0;

    var_s0 = 1;
    temp_a0 = func_801C59E4();
    if (D_801CA955 != 0) {
        temp_v0 = D_801D9264 + (temp_a0 * 8);
        D_801D9264 = temp_v0;
        if ((s16) temp_v0 >= 0x100) {
            var_s0 = 0;
            D_801CA955 = 0;
            D_801D9264 = 0xFF;
        }
        func_801C832C(0, 0, func_8002398C(0, 2, 0x100, 0) & 0xFFFF, 0, D_801D9288 - 2);
        temp_v1 = (u8) D_801D9264;
        p = &D_801D9260[0];
        D_801D9262 = temp_v1;
        D_801D9261 = temp_v1;
        temp_a3 = D_801D9288 - 1;
        *p = temp_v1;
        func_801C798C(D_801CA958, p, 1, temp_a3);
    }
    return var_s0;
}

void func_8006961C(void) {
    func_800248FC();
    do {
    } while (func_800246D4(1) != 0);
}

extern void func_80024960();

void func_8006964C(void) {
    func_80024960();
    do {
    } while (func_800246D4(1) != 0);
}
