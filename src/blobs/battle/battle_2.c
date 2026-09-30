#include "common.h"

extern void func_8001D578();

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E02A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E02A8);

extern u8 D_800F5AF4[];
extern s32 D_800F5B08[];
extern u8 D_800F5B14[];
extern s32 D_800F5B28[];
extern u8 D_800F79C4[];
extern s32 D_800F79D8[];
extern s32 D_800F7A18[];

void func_800E067C(u8 *arg0, u8 *arg1) {
    u8 *t0;
    s32 t1v;
    u8 *t2;
    u8 *t3;
    u8 *t4;
    u8 *a0v;
    u8 *a2v;
    u8 *a3v;
    s32 v0v;
    s32 v1v;
    volatile s32 pad[2];

    t1v = 0;
    t4 = D_800F79C4;
    t3 = arg0;
    a0v = arg0;
    t2 = D_800F5AF4;
    do {
        v1v = 0;
        t0 = t4;
        a3v = t2;
        a2v = t3;
        do {
            v0v = *(u16 *) a2v;
            a2v += 2;
            v1v += 1;
            *(u16 *) a3v = (u16) v0v;
            *(u16 *) t0 = (u16) v0v;
            t0 += 2;
            a3v += 2;
        } while (v1v < 3);

        v1v = *(s32 *) (a0v + 0x14);
        a0v += 4;
        t4 += 6;
        t3 += 6;
        v0v = t1v << 2;
        t1v += 1;
        *(s32 *) ((u8 *) D_800F5B08 + v0v) = v1v;
        *(s32 *) ((u8 *) D_800F79D8 + v0v) = v1v;
        v1v = (s32) D_800F79D8;
        t2 += 6;
    } while (t1v < 3);

    t1v = 0;
    t3 = (u8 *) D_800F79D8 + 0x2C;
    t2 = arg1;
    t0 = D_800F5B14;
    do {
        v1v = 0;
        a3v = t3;
        a2v = t0;
        a0v = t2;
        do {
            v0v = *(u16 *) a0v;
            a0v += 2;
            v1v += 1;
            *(u16 *) a2v = (u16) v0v;
            *(u16 *) a3v = (u16) v0v;
            a3v += 2;
            a2v += 2;
        } while (v1v < 3);

        v1v = *(s32 *) (arg1 + 0x14);
        arg1 += 4;
        t3 += 6;
        t2 += 6;
        v0v = t1v << 2;
        t1v += 1;
        *(s32 *) ((u8 *) D_800F5B28 + v0v) = v1v;
        *(s32 *) ((u8 *) D_800F7A18 + v0v) = v1v;
        v1v = (s32) D_800F7A18;
        t0 += 6;
    } while (t1v < 3);

    a0v = D_800F5AF4;
    func_8001D108(a0v, arg1, a2v, a3v);
}

extern s32 func_8001D168();
extern u8 D_800F6674;
extern s32 D_800F5B40;
extern s32 D_800F5B44;
extern s32 D_800F5B48;

s32 func_800E07B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    register s32 s0v asm("s0");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");

    v0v = 9;
    if (arg0 == v0v) {
        goto c9;
    }
    v0v = arg0 < 9;
    if (v0v != 0) {
        v0v = s0v;
        goto end;
    }
    v0v = 0xA;
    if (arg0 == v0v) {
        goto cA;
    }
    v0v = 0xB;
    if (arg0 == v0v) {
        goto cB;
    }
    v0v = 0xC;
    if (arg0 == v0v) {
        goto cC;
    }
    v0v = s0v;
    __asm__ volatile(".set\tnoreorder\n\tj func_800E78AC\n\tnop\n\t.set\treorder" ::"r"(v0v));
c9:
    v1v = D_800F6674;
    a0v = arg1;
    v0v = 1;
    if (v1v != v0v) {
        goto l818;
    }
    __asm__ volatile(".set\tnoreorder\n\tj func_800E78AC\n\taddu $2,$zero,$zero\n\t.set\treorder" : "=r"(v0v));
l818:
    a1v = arg2;
    a2v = arg3;
    s0v = (s32) &D_800F5B40;
    *(s32 *) s0v = a0v;
    D_800F5B44 = a1v;
    D_800F5B48 = a2v;
    func_8001D168(a0v, a1v, a2v);
    __asm__ volatile(".set\tnoreorder\n\tj func_800E78AC\n\taddu %0,%1,$zero\n\t.set\treorder" : "=r"(v0v) : "r"(s0v));
cA:
    s0v = (s32) &D_800F5B40;
    __asm__ volatile(".set\tnoreorder\n\tj func_800E78AC\n\taddu %0,%1,$zero\n\t.set\treorder" : "=r"(v0v) : "r"(s0v));
cB:
    a0v = 0;
    a1v = 0;
    a2v = 0;
    func_8001D168(a0v, a1v, a2v);
    v0v = 1;
    D_800F6674 = v0v;
    __asm__ volatile(".set\tnoreorder\n\tj func_800E78AC\n\taddu %0,%1,$zero\n\t.set\treorder" : "=r"(v0v) : "r"(s0v));
cC:
    a0v = D_800F5B40;
    a1v = D_800F5B44;
    a2v = D_800F5B48;
    func_8001D168(a0v, a1v, a2v);
    D_800F6674 = 0;
    SCHED_BARRIER();
    v0v = s0v;
end:
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E08C0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E1190);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E140C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E4E70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E4E8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E4EA0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E503C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E5718);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E6AB4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E7104);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E72A0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E7438);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E7670);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E767C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E77B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E78AC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E78C0);

extern u8 D_800F5C0C[];
extern void func_8001CF48();
extern void func_8001CF78();
extern void func_8001D0A8();
extern void func_8001D138();
extern void func_8001D658();
extern u8 D_800F5B34;
extern u8 D_800F5B9C;
extern u8 D_800FBDD4;

void func_800E795C(u8 *arg0, u8 *arg1, void *arg2, void *arg3) {
    typedef struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
    } Vec4;
    typedef struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
        s32 unk10;
        s32 unk14;
        s32 unk18;
        s32 unk1C;
    } Vec8;
    typedef struct {
        char c[8];
    } W;
    extern Vec4 D_800F5C2C;
    extern Vec8 D_800F6D94;
    extern Vec8 D_800FBE60;
    s32 sp10;
    Vec4 *v3;
    Vec8 *v8;
    W *w;
    Vec8 *p0;
    u8 *p1;

    p0 = (Vec8 *) arg0;
    p1 = arg1;
    v3 = (Vec4 *) arg3;
    v8 = &D_800F6D94;
    D_800F5C2C = *v3;
    w = (W *) D_800F5C0C;
    *w = *(W *) arg1;
    func_8001D658(arg1, arg0);
    func_8001CF48(arg0, arg2);
    func_8001CF78(arg0, &D_800F5C2C);
    func_8001D658(arg1, &D_800F6D94);
    func_8001D0A8(arg0);
    func_8001D138(arg0);
    func_8001D578(&D_800F5B9C, (u8 *) &D_800F6D94 + 0x14, &sp10);
    func_8001CF78(&D_800F6D94, &D_800F5C2C);
    *p0 = *(Vec8 *) v8;
    D_800FBE60 = *(Vec8 *) v8;
    func_8001D658(&D_800F5B34, &D_800FBDD4);
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E7AF8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E7ECC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E7F60);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E8120);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E816C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E8190);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E8194);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E81E0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E82E8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E83F8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E840C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E8670);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E86F0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E885C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E94DC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E9578);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E95EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E9660);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E9BE0);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E9C58);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E9CFC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E9D70);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800E9DE4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EA204);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EA378);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EA51C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EB294);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EB6BC);

#define BATTLE_B_CHAIN(n, cur, nxt)                         \
    __asm__ volatile(".set\tnoreorder\n\t"                  \
                     "bne %1,%0," #n "f\n\t"                \
                     "ori %0,$zero," #nxt "\n\t"            \
                     "j D_800F35F8\n\t"                     \
                     "ori $4,$zero," #cur "\n\t" #n ":\n\t" \
                     ".set\treorder\n\t"                    \
                     : "=r"(v0) : "r"(v1))

extern char D_800E6B94[];
extern char D_800E6B9C[];
extern s32 D_800FBDF4;
extern s16 func_800F2618();
extern void func_800F26BC();
extern s32 func_8013B590();

s32 func_800EC4C4(s32 arg0, u8 *arg1) {
    typedef struct {
        u8 c[8];
    } T8;
    typedef struct {
        s32 a;
        s32 b;
        s32 c;
        s32 d;
    } T16;
    T8 l8;
    T16 l16;
    u8 *s1;
    register u8 *a3 asm("a3");
    s32 s0;
    register s32 a0 asm("a0");
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    a3 = arg1;
    KEEP(a3);
    l8 = *(T8 *) D_800E6B94;
    l16 = *(T16 *) D_800E6B9C;
    if (arg0 != 2) {
        return 0;
    }
    s1 = a3;
    v1 = s1[5];
    __asm__ volatile(".set\tnoreorder\n\t"
                     "ori %0,$zero,0x85\n\t"
                     "bne %1,%0,1f\n\t"
                     "ori %0,$zero,0x86\n\t"
                     "j D_800F35F8\n\t"
                     "ori $4,$zero,0x85\n\t"
                     "1:\n\t"
                     ".set\treorder\n\t" : "=r"(v0) : "r"(v1));
    BATTLE_B_CHAIN(2, 0x86, 0x88);
    BATTLE_B_CHAIN(3, 0x88, 0x89);
    BATTLE_B_CHAIN(4, 0x89, 0x8A);
    BATTLE_B_CHAIN(5, 0x8A, 0x8B);
    __asm__ volatile(".set\tnoreorder\n\t"
                     "beq %1,%0,lb8b\n\t"
                     "ori $4,$zero,0x8B\n\t"
                     ".set\treorder\n\t" ::"r"(v0),
                     "r"(v1));
    v0 = func_8013B590(s1[0]);
    __asm__ volatile("ori %0,$zero,0x23" : "=r"(a0));
    s0 = v0 & 0xFFF;
    v0 = func_8013B590(a0);
    __asm__ volatile("ori %0,$zero,0x24" : "=r"(a0));
    v0 &= 7;
    v0 <<= 12;
    s0 |= v0;
    v0 = func_8013B590(a0);
    s0 |= (v0 & 1) << 15;
    s0 <<= 16;
    if ((func_800F2618(s1[4], s1[2], s0 >> 16) << 16) != 0) {
        __asm__ volatile(".set\tnoreorder\n\tlbu $4,0x5($17)\n\t.set\treorder");
        __asm__ volatile(".set\tnoreorder\n\t"
                         "lb8b:\n\t"
                         "jal func_800F26BC\n\t"
                         "addu $5,$17,$zero\n\t"
                         ".set\treorder\n\t");
    }
join:
    v0 = s1[8];
    v1 = D_800FBDF4;
    v0 = v0 + v1;
    D_800FBDF4 = v0;
    return 0;
}

extern void func_80183F60(void *);
extern s32 func_800222EC(u32, s32);
extern s32 func_80044694(s32, s32, void *);
extern u8 D_800F5E74[];
extern u8 D_800F5C74[];
extern void *D_80121FFC;
extern u8 D_80124604[];

s32 func_800EC638(s32 arg0) {
    u32 s0;
    u32 s1;
    s32 temp_a0;
    s32 var_v0;

    s0 = arg0 & 0xFFFF;
    func_80183F60((void *) &D_800F5E74[s0 * 0x10]);
    s1 = (u32) D_80124604;
    var_v0 = func_800222EC(s1, 0xBB8);
    s0 <<= 2;
    temp_a0 = *(s32 *) &D_800F5C74[s0];
    if (temp_a0 != 0) {
        if (func_80044694(temp_a0, 0x1000, D_80121FFC) != 0) {
            goto return_zero;
        }
        return s1;
    }
    return var_v0;
return_zero:
    return 0;
}

s32 func_800EC6C4(s32 arg0, u8 *arg1, s32 arg2) {
    register s32 v0v asm("v0");
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 s0v asm("s0");
    volatile s32 pad[4];

    USE(&pad[0]);
    v0v = arg1[0xD];
    if (v0v == 0) {
        return 0;
    }
    s0v = arg2;
    a0v = *(s32 *) (arg1 + 2);
    a1v = *(s32 *) (arg1 + 6);
    __asm__ volatile(".set\tnoreorder\n\tjal func_80044694\n\taddu $6,$16,$zero\n\t.set\treorder"
                     : "=r"(v0v) : "r"(a0v), "r"(a1v), "r"(s0v) : "ra");
    if (v0v == 0) {
        v0v = s0v;
        __asm__ volatile(".set\tnoreorder\n\tj D_800F3704\n\taddu $2,%0,$zero\n\t.set\treorder" : : "r"(s0v));
    }
    return 0;
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EC718);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EC720);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800ECD94);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800ECF8C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800ED524);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800ED71C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EDAD4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EDB14);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EDDB8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE0B8);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE0EC);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE0F4);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE104);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE144);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE438);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE578);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE95C);

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EE974);

extern s32 func_800F5A64();
extern s32 func_80091248();
extern s32 D_800F6CCC[];

s32 func_800EE984(void) {
    extern s8 D_800F5C70;
    s32 *s0;
    s32 s1;

    func_800F5A64();
    s1 = 0;
    s0 = D_800F6CCC;
    do {
        if (*s0 != 0) {
            func_80091248(*s0);
            *s0 = 0;
        }
        s0++;
        s1++;
    } while (s1 < 0x20);
    D_800F5C70 = 0;
    return 0;
}

extern s32 D_800F5C64;
extern void func_80044038();

void func_800EE9F0(void) {
    extern u8 D_800F5C70;
    register s32 a0v asm("$4");
    s32 v0;

    a0v = D_800F5C64;
    v0 = 1;
    D_800F5C70 = v0;
    if (a0v != 0) {
        func_80044038();
    }
}

INCLUDE_ASM("rom/extracted/blobs/battle/nonmatchings/battle_2", func_800EEA2C);

extern void func_800440F4();
extern s32 D_800F5C68;
extern s32 D_800F5C6C;

s32 func_800EEA6C(s32 arg0) {
    s32 ret;

    if (arg0 != 0) {
        func_800440F4(arg0);
        D_800F5C64 = 0;
    }
    if (D_800F5C68 != 0) {
        func_800440F4(D_800F5C68);
        D_800F5C68 = 0;
    }
    if (D_800F5C6C != 0) {
        func_800440F4(D_800F5C6C);
        D_800F5C6C = 0;
    }
    return ret;
}
