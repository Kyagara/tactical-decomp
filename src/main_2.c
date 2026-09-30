#include "common.h"
#include "psx_gte.h"

extern s32 func_8001EFBC(s32, void *);
extern int func_8001EDEC(s32, s32, s32);
extern s32 func_8001DBA8(s32);
extern void _CdFlush(void);
extern void (*D_80028B0C[])(void);
extern vu16 SUZUKISpuInstructionFlags;
extern void SpuFree();
extern void func_8001B4B0();
extern void func_8001ACF0(s32, s32);
extern void SpuSetVoiceRRAttr(s32, s32, s32);
extern void func_8001B094(void *);
extern void SPUSetTransferCallback(s32 *);
extern void func_80021F84(s32);
extern s16 WaitForSPUTransfer(s32);
extern void SPUGetReverbModeParam(void *);
extern void SPUSetTransferMode(s32);
extern s32 D_80032A04;
extern u16 D_80032A30;

s16 WaitForSPUTransfer(s32 arg0) {
    if (arg0 & 0x10) {
        while (SUZUKISpuInstructionFlags & 0x10) {
        }
    }
    if (SUZUKISpuInstructionFlags & 0x10) {
        return *(s16 *) ((s32) D_80032A30 * 0x10 + D_80032A04);
    }
    return 0;
}

void func_800186BC(void) {
}

extern void _spu_zerobuf(s32);

void SPUSsUtReverbOff(void) {
    _spu_zerobuf(0);
}

extern s32 D_8002A8E4;
extern s32 D_8002A8E8;
extern s32 D_8002A8EC;
extern s16 D_8002A93A;
extern s16 D_8002BA4C[];
extern s32 D_8002AD3C;
extern s32 D_8002ADAC;
extern int D_8002A8F4;
extern u16 D_8002A8F8;
extern u16 D_8002A8FA;
extern int D_8002A8FC;
extern int D_8002A900;
extern s32 *D_8002ADA8;
extern s32 D_8002ADA4;
extern s32 D_8002ADA0;
extern s32 D_8002A8E0;
extern s32 D_8002AD60;
extern s32 D_8002A8DC;
extern s32 D_8002A908;
extern s32 D_8002A904;
void func_80018858(s32 arg0);
void _spu_keystat(s32 arg0);
void _spu_tsa(u32 arg0, u32 arg1, u32 arg2);
void ETCResetCallback(void);

void _spu_zerobuf(s32 arg0) {
    s16 *var_v0;
    int new_var;
    s32 var_v1;

    ETCResetCallback();
    func_80018858(arg0);
    new_var = 0xC000;
    if (arg0 == 0) {
        var_v1 = 0x17;
        var_v0 = &D_8002A93A;
        do {
            *var_v0 = new_var;
            var_v1 -= 1;
            var_v0 -= 1;
        } while (var_v1 >= 0);
    }
    _spu_keystat(new_var);
    D_8002A8E4 = 0;
    D_8002A8E8 = 0;
    D_8002A8F4 = 0;
    D_8002A8F8 = 0;
    D_8002A8FA = 0;
    D_8002A8FC = 0;
    D_8002A900 = 0;
    D_8002A8EC = D_8002ADAC;
    _spu_tsa(0xD1, D_8002ADAC, 0);
    D_8002ADA0 = 0;
    D_8002ADA4 = 0;
    D_8002ADA8 = 0;
    D_8002A8E0 = 0;
    D_8002AD60 = 0;
    D_8002A8DC = 0;
    D_8002A908 = 0;
    D_8002A904 = 0;
    D_8002AD3C = 0;
}

extern s32 D_8002AD40;
extern s32 func_80018CB8;
extern s32 D_8002A8D8;

void _spu_keystat(s32 arg0) {
    s32 temp_v0;

    if (D_8002AD40 == 0) {
        D_8002AD40 = 1;
        func_80022034();
        SPUDataCallback(&func_80018CB8);
        temp_v0 = func_80021F74(0xF0000009, 0x20, 0x2000, 0);
        D_8002A8D8 = temp_v0;
        func_80021FB4((void *) temp_v0);
        func_80022044();
    }
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80018858);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80018AEC);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80018CB8);

extern u16 *D_8002AD44;
extern volatile u32 *D_8002AD48;
extern s32 *D_8002AD4C;
extern s32 *D_8002AD50;
extern s32 D_8002AD94;
void _spu_FiDMA(void);
void SPUDMASetTimingOverride2(void);

void _spu_inTransfer(s32 arg0, s16 arg1, s32 arg2) {
    ((volatile u16 *) D_8002AD44)[0xD3] = arg1;
    _spu_FiDMA();
    _spu_FiDMA();
    ((volatile u16 *) D_8002AD44)[0xD5] = (u16) (((volatile u16 *) D_8002AD44)[0xD5] | 0x30);
    _spu_FiDMA();
    _spu_FiDMA();
    SPUDMASetTimingOverride2();
    *D_8002AD48 = arg0;
    *D_8002AD4C = (arg2 << 0x10) | 0x10;
    D_8002AD94 = 1;
    *D_8002AD50 = 0x01000200;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80018E44);

extern u16 D_8002AD5C;
extern u32 D_8002AD6C;
void func_80018E44();
void func_80018AEC(s32 arg0, s32 arg1);

s32 _spu_write(s32 arg0, s32 arg1) {
    if (D_8002AD60 == 0) {
        register u32 shift asm("a1") = D_8002AD5C << D_8002AD6C;

        func_80018E44(2, shift);
        func_80018E44(1, shift);
        func_80018E44(3, arg0, arg1);
    } else {
        func_80018AEC(arg0, arg1);
    }
    return arg1;
}

s32 _spu_mem_mode(s32 arg0, s32 arg1) {
    register u32 shift asm("a1") = D_8002AD5C << D_8002AD6C;

    func_80018E44(2, shift);
    func_80018E44(0, shift);
    func_80018E44(3, arg0, arg1);
    return arg1;
}

void _spu_tsa(u32 arg0, u32 arg1, u32 arg2) {
    if (arg2 == 0) {
        ((volatile u16 *) D_8002AD44)[arg0] = (u16) arg1;
    } else {
        ((volatile u16 *) D_8002AD44)[arg0] = (u16) (arg1 >> D_8002AD6C);
    }
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001920C);

s32 _spu_mem_mode_plus(s32 arg0, s32 arg1) {
    u16 v;
    v = *(u16 *) ((arg0 << 1) + (u32) D_8002AD44);
    if (arg1 == -1)
        return v;
    return v << D_8002AD6C;
}

extern u32 *volatile D_8002AD54;

void _spu_transferCallback(s32 arg0) {
    volatile u32 *p;
    register u32 x asm("v1");
    u32 k;

    p = (volatile u32 *) D_8002AD54;
    x = 0xFFF8FFFFu;
    *p &= x;
    if (arg0 != 0) {
        volatile u32 *q;
        q = (volatile u32 *) D_8002AD54;
        k = 0x30000u;
        x = *q;
        x |= k;
        *q = x;
    } else {
        volatile u32 *r;
        r = (volatile u32 *) D_8002AD54;
        k = 0x50000u;
        x = *r;
        x |= k;
        *r = x;
    }
}

extern volatile s32 *D_8002AD58;

void SPUDMASetTimingOverride0(void) {
    *D_8002AD58 = (*D_8002AD58 & 0xF0FFFFFF) | 0x20000000;
}

void SPUDMASetTimingOverride2(void) {
    *D_8002AD58 = (*D_8002AD58 & 0xF0FFFFFF) | 0x22000000;
}

void _spu_FiDMA(void) {
    volatile s32 b;
    volatile s32 a;

    a = 0xD;
    b = 0;
    while (b < 0xF0) {
        a = a * 3;
        b++;
    }
}

void SPUDataCallback(s32 arg0) {
    func_8001DDEC(4, arg0);
}

void SPUSsUtReverbOn(void) {
    _spu_zerobuf(1);
}

extern s32 *D_8002AD7C;
extern u32 D_8002AD80;

void SpuQuit(void) {
    register s32 a0val asm("a0");

    if (D_8002AD40 == 1) {
        D_8002AD40 = 0;
        func_80022034();
        a0val = 0;
        MEMORY_BARRIER();
        D_8002AD7C = 0;
        D_8002AD80 = 0;
        SPUDataCallback(a0val);
        func_80021F84(D_8002A8D8);
        func_80021FC4((void *) D_8002A8D8);
        func_80022044();
    }
}

typedef struct {
    u32 tag;
    u32 data;
} SpuAlocEntry;

s32 SpuInitMalloc(s32 arg0, s32 *arg1) {
    s32 keep = arg0;

    if (keep <= 0) {
        return 0;
    }

    {
        register s32 count asm("a0") = D_8002AD6C;
        register s32 hi asm("v1");

        hi = 0x40001010;
        arg1[0] = hi;
        hi = 0x10000;
        D_8002ADA8 = arg1;
        D_8002ADA4 = 0;
        D_8002ADA0 = keep;
        arg1[1] = (hi << count) - 0x1010;
    }
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80019518);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_800197E0);

void SpuFree(u32 addr) {
    SpuAlocEntry *e;
    u32 mark;
    u32 busy;
    s32 n;
    register u32 tag asm("v1");
    s32 m;
    s32 i;
    char pad[8];

    n = D_8002ADA0;
    i = 0;
    if (n > 0) {
        busy = 0x40000000;
        mark = addr | 0x80000000;
        m = n;
        e = (SpuAlocEntry *) D_8002ADA8;
        while (1) {
            tag = e->tag;
            if (tag & busy)
                break;
            i++;
            if (tag == addr) {
                e->tag = mark;
                break;
            }
            e++;
            if (i >= m)
                break;
        }
    }
    func_800197E0();
}

void SPUSetNoiseVoice(s32 arg0, s32 arg1) {
    SPUSetAnyVoice(arg0, arg1, 0xCA, 0xCB);
}

extern volatile s32 D_8002A908;
extern u32 D_80036EF8[];

s32 SPUSetAnyVoice(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 t2;

    if (D_8002AD3C & 1) {
        t2 = ((((volatile u16 *) D_80036EF8)[arg3] & 0xFF) << 16) |
            ((volatile u16 *) D_80036EF8)[arg2];
    } else {
        t2 = ((((volatile u16 *) D_8002AD44)[arg3] & 0xFF) << 16) |
            ((volatile u16 *) D_8002AD44)[arg2];
    }
    if (arg0 != 0) {
        if (arg0 == 1) {
            if (D_8002AD3C & 1) {
                ((volatile u16 *) D_80036EF8)[arg2] |= arg1;
                ((volatile u16 *) D_80036EF8)[arg3] |= (arg1 >> 16) & 0xFF;
                D_8002A908 |= arg0 << ((arg2 - 0xC6) >> 1);
            } else {
                ((volatile u16 *) D_8002AD44)[arg2] |= arg1;
                ((volatile u16 *) D_8002AD44)[arg3] |= (arg1 >> 16) & 0xFF;
            }
            t2 |= arg1 & 0xFFFFFF;
        }
    } else {
        if (D_8002AD3C & 1) {
            ((volatile u16 *) D_80036EF8)[arg2] &= ~arg1;
            ((volatile u16 *) D_80036EF8)[arg3] &= ~((arg1 >> 16) & 0xFF);
            D_8002A908 |= 1 << ((arg2 - 0xC6) >> 1);
        } else {
            ((volatile u16 *) D_8002AD44)[arg2] &= ~arg1;
            ((volatile u16 *) D_8002AD44)[arg3] &= ~((arg1 >> 16) & 0xFF);
        }
        t2 &= ~(arg1 & 0xFFFFFF);
    }
    return t2 & 0xFFFFFF;
}

s32 SpuSetNoiseClock(s32 arg0) {
    s32 noise;

    if (arg0 < 0) {
        noise = 0;
    } else {
        noise = arg0;
        if (noise >= 0x40) {
            noise = 0x3F;
        }
    }
    ((volatile u16 *) D_8002AD44)[0xD5] =
        (((volatile u16 *) D_8002AD44)[0xD5] & 0xC0FF) | ((noise & 0x3F) << 8);
    return noise;
}

extern s32 D_8002AD78;

u32 SpuRead(u32 arg0, u32 arg1) {
    u32 var_s0 = arg1;
    if (arg1 > 0x7EFF0U) {
        var_s0 = 0x7EFF0;
    }
    _spu_mem_mode(arg0, var_s0);
    if (D_8002AD7C == 0) {
        D_8002AD78 = 0;
    }
    return var_s0;
}

s32 SpuSetReverb(s32 arg0) {
    register u16 *p asm("v0");
    u16 v;

    switch (arg0) {
    case 0:
        D_8002A8E4 = 0;
        p = D_8002AD44;
        v = ((volatile u16 *) p)[0xD5] & ~0x80;
        ((volatile u16 *) p)[0xD5] = v;
        break;
    case 1:
        if ((D_8002A8E8 != arg0) && (_SpuIsInAllocateArea(D_8002A8EC) != 0)) {
            D_8002A8E4 = 0;
            p = D_8002AD44;
            v = ((volatile u16 *) p)[0xD5] & ~0x80;
            ((volatile u16 *) p)[0xD5] = v;
        } else {
            D_8002A8E4 = arg0;
            p = D_8002AD44;
            v = ((volatile u16 *) p)[0xD5] | 0x80;
            ((volatile u16 *) p)[0xD5] = v;
        }
        break;
    }
    return D_8002A8E4;
}

typedef struct {
    u32 addr;
    u32 size;
} SpuMemList;

s32 _SpuIsInAllocateArea_(u32 arg0) {
    u32 i;
    SpuMemList *memList;

    memList = (SpuMemList *) D_8002ADA8;
    if (memList == NULL) {
        return 0;
    }
    for (i = 0;; i++) {
        if (memList[i].addr & 0x80000000) {
            continue;
        }
        if (memList[i].addr & 0x40000000) {
            break;
        }
        if (arg0 <= (memList[i].addr & 0x0FFFFFFF)) {
            return 1;
        }
        if (arg0 < (memList[i].addr & 0x0FFFFFFF) + memList[i].size) {
            return 1;
        }
    }
    return 0;
};

s32 _SpuIsInAllocateArea(u32 arg0) {
    u32 i;
    SpuMemList *memList;

    arg0 <<= D_8002AD6C;
    memList = (SpuMemList *) D_8002ADA8;
    if (memList == NULL) {
        return 0;
    }
    for (i = 0;; i++) {
        if (memList[i].addr & 0x80000000) {
            continue;
        }
        if (memList[i].addr & 0x40000000) {
            break;
        }
        if (arg0 <= (memList[i].addr & 0x0FFFFFFF)) {
            return 1;
        }
        if (arg0 < (memList[i].addr & 0x0FFFFFFF) + memList[i].size) {
            return 1;
        }
    }
    return 0;
};

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001A014);

void SPUSetReverbAttr(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a1 = *(s32 *) arg0;
    temp_a2 = temp_a1 == 0;
    if ((temp_a2 != 0) || (temp_a1 & 1)) {
        ((u16 *) D_8002AD44)[0xE0] = *(u16 *) ((u8 *) arg0 + 4);
    }
    if ((temp_a2 != 0) || (temp_a1 & 2)) {
        ((u16 *) D_8002AD44)[0xE1] = *(u16 *) ((u8 *) arg0 + 6);
    }
    if ((temp_a2 != 0) || (temp_a1 & 4)) {
        ((u16 *) D_8002AD44)[0xE2] = *(u16 *) ((u8 *) arg0 + 8);
    }
    if ((temp_a2 != 0) || (temp_a1 & 8)) {
        ((u16 *) D_8002AD44)[0xE3] = *(u16 *) ((u8 *) arg0 + 0xA);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10)) {
        ((u16 *) D_8002AD44)[0xE4] = *(u16 *) ((u8 *) arg0 + 0xC);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20)) {
        ((u16 *) D_8002AD44)[0xE5] = *(u16 *) ((u8 *) arg0 + 0xE);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40)) {
        ((u16 *) D_8002AD44)[0xE6] = *(u16 *) ((u8 *) arg0 + 0x10);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x80)) {
        ((u16 *) D_8002AD44)[0xE7] = *(u16 *) ((u8 *) arg0 + 0x12);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x100)) {
        ((u16 *) D_8002AD44)[0xE8] = *(u16 *) ((u8 *) arg0 + 0x14);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x200)) {
        ((u16 *) D_8002AD44)[0xE9] = *(u16 *) ((u8 *) arg0 + 0x16);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x400)) {
        ((u16 *) D_8002AD44)[0xEA] = *(u16 *) ((u8 *) arg0 + 0x18);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x800)) {
        ((u16 *) D_8002AD44)[0xEB] = *(u16 *) ((u8 *) arg0 + 0x1A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x1000)) {
        ((u16 *) D_8002AD44)[0xEC] = *(u16 *) ((u8 *) arg0 + 0x1C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x2000)) {
        ((u16 *) D_8002AD44)[0xED] = *(u16 *) ((u8 *) arg0 + 0x1E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x4000)) {
        ((u16 *) D_8002AD44)[0xEE] = *(u16 *) ((u8 *) arg0 + 0x20);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x8000)) {
        ((u16 *) D_8002AD44)[0xEF] = *(u16 *) ((u8 *) arg0 + 0x22);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10000)) {
        ((u16 *) D_8002AD44)[0xF0] = *(u16 *) ((u8 *) arg0 + 0x24);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20000)) {
        ((u16 *) D_8002AD44)[0xF1] = *(u16 *) ((u8 *) arg0 + 0x26);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40000)) {
        ((u16 *) D_8002AD44)[0xF2] = *(u16 *) ((u8 *) arg0 + 0x28);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x80000)) {
        ((u16 *) D_8002AD44)[0xF3] = *(u16 *) ((u8 *) arg0 + 0x2A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x100000)) {
        ((u16 *) D_8002AD44)[0xF4] = *(u16 *) ((u8 *) arg0 + 0x2C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x200000)) {
        ((u16 *) D_8002AD44)[0xF5] = *(u16 *) ((u8 *) arg0 + 0x2E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x400000)) {
        ((u16 *) D_8002AD44)[0xF6] = *(u16 *) ((u8 *) arg0 + 0x30);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x800000)) {
        ((u16 *) D_8002AD44)[0xF7] = *(u16 *) ((u8 *) arg0 + 0x32);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x1000000)) {
        ((u16 *) D_8002AD44)[0xF8] = *(u16 *) ((u8 *) arg0 + 0x34);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x2000000)) {
        ((u16 *) D_8002AD44)[0xF9] = *(u16 *) ((u8 *) arg0 + 0x36);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x4000000)) {
        ((u16 *) D_8002AD44)[0xFA] = *(u16 *) ((u8 *) arg0 + 0x38);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x8000000)) {
        ((u16 *) D_8002AD44)[0xFB] = *(u16 *) ((u8 *) arg0 + 0x3A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10000000)) {
        ((u16 *) D_8002AD44)[0xFC] = *(u16 *) ((u8 *) arg0 + 0x3C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20000000)) {
        ((u16 *) D_8002AD44)[0xFD] = *(u16 *) ((u8 *) arg0 + 0x3E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40000000)) {
        ((u16 *) D_8002AD44)[0xFE] = *(u16 *) ((u8 *) arg0 + 0x40);
    }
    if ((temp_a2 != 0) || (temp_a1 < 0)) {
        ((u16 *) D_8002AD44)[0xFF] = *(u16 *) ((u8 *) arg0 + 0x42);
    }
}

void SPUGetReverbModeParam(void *arg0) {
    *(s32 *) ((u8 *) arg0 + 0x4) = D_8002A8F4;
    *(s32 *) ((u8 *) arg0 + 0xC) = D_8002A8FC;
    *(s32 *) ((u8 *) arg0 + 0x10) = D_8002A900;
    *(u16 *) ((u8 *) arg0 + 0x8) = D_8002A8F8;
    *(u16 *) ((u8 *) arg0 + 0xA) = D_8002A8FA;
}

s32 SpuSetReverbDepth(void *arg0) {
    s32 flags = *(s32 *) arg0;
    s32 iszero = flags == 0;

    if (iszero || (flags & 2)) {
        D_8002AD44[0xC2] = *(u16 *) ((u8 *) arg0 + 8);
        D_8002A8F8 = *(u16 *) ((u8 *) arg0 + 8);
    }
    if (iszero || (flags & 4)) {
        D_8002AD44[0xC3] = *(u16 *) ((u8 *) arg0 + 0xA);
        D_8002A8FA = *(u16 *) ((u8 *) arg0 + 0xA);
    }
    return 0;
}

void SPUSetReverbVoice(s32 arg0, s32 arg1) {
    SPUSetAnyVoice(arg0, arg1, 0xCC, 0xCD);
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001AAE0);

extern void _spu_inTransfer();

long SpuReadDecodedData(s32 arg0, s32 arg1) {
    s32 spu_a;
    s32 spu_b;
    s32 new_var;

    switch (arg1) {
    case 5:
        spu_a = 0;
        spu_b = 0x20;
        break;
    case 6:
        arg0 += 0x800;
        spu_a = 0x100;
        spu_b = 0x20;
        break;
    default:
        spu_a = 0;
        spu_b = 0x40;
        break;
    }
    new_var = 0;
    _spu_inTransfer(arg0, spu_a, spu_b);
    return (D_8002AD44[0xD7] & 0x800) != new_var;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001ACF0);

void func_8001AEF4(s32 arg0, s16 *arg1, u16 *arg2) {
    u16 temp_a3;

    temp_a3 = *(u16 *) (((arg0 << 4) | 0xC) + (u32) D_8002AD44);
    *arg2 = temp_a3;
    if ((1 << arg0) & D_8002A8DC) {
        if ((s16) temp_a3 > 0) {
            *arg1 = 1;
        } else {
            *arg1 = 3;
        }
    } else {
        if ((s16) temp_a3 > 0) {
            *arg1 = 2;
        } else {
            *arg1 = 0;
        }
    }
}

u32 SpuRead_8001AF64(u32 arg0, u32 arg1) {
    u32 addr = arg1;

    if (addr > 0x7EFF0U) {
        addr = 0x7EFF0;
    }
    _spu_write(arg0, addr);
    if (D_8002AD7C == 0) {
        D_8002AD78 = 0;
    }
    return addr;
}

u16 func_8001920C();

u16 SpuSetTransferStartAddr(u32 arg0) {
    if (0x7EFE8 < (u32) (arg0 - 0x1010))
        return 0;
    D_8002AD5C = func_8001920C(-1, arg0);
    return D_8002AD5C;
}

void SPUSetTransferMode(s32 arg0) {
    s32 var_v0;

    switch (arg0) {
    case 0:
        var_v0 = 0;
        break;
    case 1:
        var_v0 = 1;
        break;
    default:
        var_v0 = 0;
        break;
    }
    D_8002A8E0 = arg0;
    D_8002AD60 = var_v0;
}

void SPUSetTransferCallback(s32 *arg0) {
    if (arg0 == D_8002AD7C) {
        return;
    }
    D_8002AD7C = arg0;
}

void SPUSetPitchLFOVoice(s32 arg0, s32 arg1) {
    SPUSetAnyVoice(arg0, arg1, 0xC8, 0xC9);
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001B094);

void SpuSetVoiceVolume(s32 voice, short volL, short volR) {
    volatile s32 sp0;
    volatile s32 sp4;

    volL &= 0x7FFF;
    volR &= 0x7FFF;
    ((volatile u16 *) D_8002AD44)[voice * 8 + 0] = volL;
    ((volatile u16 *) D_8002AD44)[voice * 8 + 1] = volR;
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001B4B0);

void SpuSetVoicePitch(s32 voice, u16 pitch) {
    volatile s32 sp0;
    volatile s32 sp4;

    ((volatile u16 *) D_8002AD44)[voice * 8 + 2] = pitch;
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

void SpuSetVoiceStartAddr(s32 voice) {
    volatile s32 sp0;
    volatile s32 sp4;

    func_8001920C((voice * 8) | 3);
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

void SpuSetVoiceLoopStartAddr(s32 voice) {
    volatile s32 sp0;
    volatile s32 sp4;

    func_8001920C((voice * 8) | 7);
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

void SpuSetVoiceDR(s32 voice, s32 rate) {
    volatile s32 sp0;
    volatile s32 sp4;

    ((volatile u16 *) D_8002AD44)[voice * 8 + 4] =
        (((volatile u16 *) D_8002AD44)[voice * 8 + 4] & 0xFF0F) | ((u16) rate << 4);
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

void SpuSetVoiceRR(s32 voice, s32 rate) {
    volatile s32 sp0;
    volatile s32 sp4;

    ((volatile u16 *) D_8002AD44)[voice * 8 + 5] =
        (((volatile u16 *) D_8002AD44)[voice * 8 + 5] & 0xFFC0) | rate;
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

void SpuSetVoiceSL(s32 voice, s32 rate) {
    volatile s32 sp0;
    volatile s32 sp4;

    ((volatile u16 *) D_8002AD44)[voice * 8 + 4] =
        (((volatile u16 *) D_8002AD44)[voice * 8 + 4] & 0xFFF0) | rate;
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

void SpuSetVoiceARAttr(s32 voice, s32 arg1, s32 arg2) {
    volatile s32 sp0;
    volatile s32 sp4;
    s32 bit;

    ((volatile u16 *) D_8002AD44)[voice * 8 + 4] =
        (((volatile u16 *) D_8002AD44)[voice * 8 + 4] & 0xFF) |
        ((bit = (arg2 == 5) << 7, (arg1 | bit)) << 8);
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

void SpuSetVoiceSRAttr(s32 voice, s32 arg1, s32 arg2) {
    volatile s32 sp0;
    volatile s32 sp4;
    volatile u16 *p;
    s32 a3 = 0x100;
    register s32 off asm("v1") = voice * 8;

    switch (arg2) {
    case 1:
        a3 = 0;
        break;
    case 5:
        a3 = 0x200;
        break;
    case 7:
        a3 = 0x300;
        break;
    }
    p = D_8002AD44 + off;
    p[5] = (p[5] & 0x3F) | ((arg1 | a3) << 6);
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

void SpuSetVoiceRRAttr(s32 voice, s32 arg1, s32 arg2) {
    volatile s32 sp0;
    volatile s32 sp4;
    volatile u16 *p;
    register s32 off asm("v1");
    s32 a3 = 0;
    s32 addr;

    if (arg2 != 3) {
        a3 = (arg2 == 7) << 5;
    }
    off = voice * 16;
    addr = ((s32) D_8002AD44) + off;
    p = (volatile u16 *) addr;
    addr = arg1 | a3;
    p[5] = (p[5] & 0xFFC0) | addr;
    sp4 = 1;
    sp0 = 0;
    while (sp0 < 2) {
        sp4 *= 13;
        sp0++;
    }
}

s32 rsin(s32 arg0) {
    if (arg0 < 0) {
        arg0 = -arg0;
        return -GTESin1(arg0 & 0xFFF);
    }
    return GTESin1(arg0 & 0xFFF);
}

extern s16 D_8002A0A4[];
extern s16 D_8002B0A4[];

s32 GTESin1(s32 arg0) {
    if (arg0 < 0x801) {
        if (arg0 < 0x401) {
            return D_8002B0A4[arg0];
        }
        return D_8002B0A4[0x800 - arg0];
    }
    if (arg0 < 0xC01) {
        return -D_8002A0A4[arg0];
    }
    return -D_8002B0A4[0x1000 - arg0];
}

extern s16 D_8002A8A4[];
extern s16 D_800298A4[];

s32 GTERcos(s32 arg0) {
    s32 a;
    if (arg0 < 0) {
        arg0 = -arg0;
    }
    a = arg0 & 0xFFF;
    if (a < 0x801) {
        if (a < 0x401) {
            return D_8002B0A4[0x400 - a];
        }
        return -D_8002A8A4[a];
    }
    if (a < 0xC01) {
        return -D_8002B0A4[0xC00 - a];
    }
    return D_800298A4[a];
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001BCC8);

extern s32 GTELzc(s32);
extern s32 func_8001BCC8(s32);

s32 csqrt_1(s32 x) {
    s32 t, s0, y;
    if (x == 0) {
        return 0;
    }
    t = 8 - GTELzc(x);
    if (t >= 0) {
        s0 = t >> 1;
        y = x >> (s0 << 1);
    } else {
        s0 = (t >> 1) + 1;
        y = x << (-(s0 << 1));
    }
    s0 -= 6;
    if (s0 >= 0) {
        return func_8001BCC8(y) << s0;
    } else {
        return func_8001BCC8(y) >> -s0;
    }
}

/* COP2/GTE library - kept as asm stub */
INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_8001BEB8);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001BF38);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_8001BFB4);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001BFBC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001BFC0);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001BFC4);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001BFC8);

s32 ReturnMinus1(void) {
    return -1;
}

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C054);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C094);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C0C4);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C180);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001C264);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C268);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001C2FC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001C300);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001C304);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C308);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C468);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C574);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C658);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C740);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C850);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C9B0);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001C9E0);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CB04);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CB40);

/* COP2/GTE library - kept as asm stub */
INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_8001CBA4);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CC44);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CC8C);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CCD4);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001CD1C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001CD20);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001CD24);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CD28);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001CE34);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CE38);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001CF44);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CF48);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001CF6C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001CF70);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001CF74);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001CF78);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D09C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D0A0);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D0A4);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D0A8);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D0D8);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D108);

void GTESetTransMatrix(s32 *arg0) {
    register s32 a asm("t0");
    register s32 b asm("t1");
    register s32 c asm("t2");

    a = arg0[5];
    b = arg0[6];
    c = arg0[7];
    gte_ctc2(a, 5);
    gte_ctc2(b, 6);
    gte_ctc2(c, 7);
}

s32 GTEReadGeomScreen(void) {
    s32 ret;

    gte_cfc2(ret, 26);
    return ret;
}

void GTESetBackColor(s32 arg0, s32 arg1, s32 arg2) {
    ASM_NOP();
    arg0 <<= 4;
    arg1 <<= 4;
    arg2 <<= 4;
    gte_ctc2(arg0, 13);
    gte_ctc2(arg1, 14);
    gte_ctc2(arg2, 15);
}

void GTESetFarColor(s32 arg0, s32 arg1, s32 arg2) {
    arg0 <<= 4;
    arg1 <<= 4;
    arg2 <<= 4;
    gte_ctc2(arg0, 21);
    gte_ctc2(arg1, 22);
    gte_ctc2(arg2, 23);
}

void StoreScreenOffsetsToGTE(s32 arg0, s32 arg1) {
    arg0 <<= 16;
    arg1 <<= 16;
    gte_ctc2(arg0, 24);
    gte_ctc2(arg1, 25);
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", D_8001D1C0);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D1C4);

void func_8001D1C8(s32 arg0) {
    gte_ctc2(arg0, 26);
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", D_8001D1D4);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D1D8);

void DpqColorLight(s32 *arg0, s32 *arg1, s32 arg2, s32 *arg3) {
    gte_ldlvl(arg0);
    gte_ldrgb(arg1);
    gte_lddp(arg2);
    ASM_NOP();
    gte_dpcl_b();
    gte_strgb(arg3);
}

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D228);

void Interpolate(s32 *arg0, s32 arg1, s32 *arg2) {
    gte_ldlvl(arg0);
    gte_lddp(arg1);
    ASM_NOP();
    gte_intpl_b();
    gte_strgb(arg2);
}

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D288);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D2B0);

s32 SMP11AverageSZ3(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret;

    gte_ldsz3(arg0, arg1, arg2);
    ASM_NOP();
    gte_avsz3_b();
    gte_mfc2(ret, 7);
    return ret;
}

s32 SMP12AverageSZ4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 ret;

    gte_ldsz4(arg0, arg1, arg2, arg3);
    ASM_NOP();
    gte_avsz4_b();
    gte_mfc2(ret, 7);
    return ret;
}

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D31C);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D374);

s32 GTELzc(s32 arg0) {
    s32 ret;

    gte_ldlzc(arg0);
    ASM_NOP2();
    gte_mfc2(ret, 31);
    return ret;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", D_8001D3E4);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D3E8);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D418);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D450);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D488);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D4B8);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D4E8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", D_8001D514);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D518);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D56C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D570);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D574);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D578);

s32 GTENormalClip(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret;

    ASM_NOP2();
    gte_ldsxy3(arg0, arg1, arg2);
    gte_nclip();
    gte_mfc2(ret, 24);
    return ret;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", D_8001D5CC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D5D0);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D5D4);

/* COP2/GTE library - kept as asm stub */
INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D5D8);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", D_8001D650);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001D654);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D658);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", D_8001D8E4);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001D8E8);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001DA68);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_8001DAD0);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_8001DB04);

extern s32 D_80032A78;
extern s32 D_800370B0;
extern void func_80021FE4(s32, s32 *);
extern void func_800220F4(s32);

void PadIdentifier(s32 arg0) {
    D_800370B0 = arg0;
    D_80032A78 = -1;
    ETCResetCallback();
    func_80021FE4(0x20000001, &D_80032A78);
    func_800220F4(0);
}

extern void func_80021FF4(void);
extern void func_80021FD4(void);

s32 ETCPadRead(void) {
    func_80021FF4();
    return ~D_80032A78;
}

void ETCPadStop(void) {
    func_80021FD4();
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001DBA8);

extern char D_80010108[];
extern volatile int D_800317B8;
extern s32 func_8002228C();
extern void func_80022104(s32, s32);

void VSync(s32 arg0, s32 arg1) {
    volatile s32 sp10;
    s32 temp_a1;

    temp_a1 = arg1 << 0xF;
    sp10 = temp_a1;
    if (D_800317B8 < arg0) {
        do {
            sp10 -= 1;
            if (sp10 == -1) {
                func_8002228C(D_80010108, temp_a1);
                func_800220F4(0);
                func_80022104(3, 0);
                return;
            }
        } while (D_800317B8 < arg0);
    }
}

typedef void (*Callback)(void);
extern u32 D_80031764[];
extern void *D_80031784;
extern int D_80031798[8];
extern int *D_800317BC;
extern volatile u32 *D_800317C0;
extern Callback D_800317C4[8];
extern int D_800317E8;
void startIntrVSync(void);
void ETCSetIntrVsync(int idx, int fn);

void ETCResetCallback(void) {
    void (**t)(void) = D_80031784;
    t[3]();
}

void ETCInterruptCallback(void) {
    void (**t)(void) = D_80031784;
    t[2]();
}

void ETCDMACallback(void) {
    void (**t)(void) = D_80031784;
    t[1]();
}

void SetIntrMask(s32 arg0) {
    void (**t)(s32, s32) = D_80031784;
    t[5](0, arg0);
}

void ETCVsyncCallbacks(void) {
    void (**t)(void) = D_80031784;
    t[5]();
}

void ETCStopCallback(void) {
    void (**t)(void) = D_80031784;
    t[4]();
}

void ETCRestartCallback(void) {
    void (**t)(void) = D_80031784;
    t[6]();
}

extern vu32 GpuControlPointer;
extern vu32 HorizontalRetraceCounterPointer;
extern u32 D_800306F4;
extern u16 D_800306FC;
extern u16 D_800306FE;
extern u16 *D_8003178C;

u16 ETCCheckCallback(void) {
    return D_800306FE;
}

u16 ETCGetIntrMask(void) {
    return *D_8003178C;
}

u16 ETCSetIntrMask(u16 arg0) {
    volatile u16 *p = D_8003178C;
    u16 tmp = *p;
    *p = arg0;
    return tmp;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001DF24);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001E000);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001E1E8);

extern u16 D_8003072E;
extern u32 D_80030730[];
extern u32 D_80031788;
extern u32 D_80031790;
extern void func_80022014(void);

u16 *ETCStopIntr(void) {
    u16 *s0 = &D_800306FC;
    u16 *p;
    u32 *new_var3;
    u32 new_var4;
    u32 q;
    u16 *pa;
    u16 v;
    u32 w;
    u16 *r;
    u16 *new_var;
    u32 *new_var2;
    if (0 != (*s0)) {
        func_80022034();
        p = D_8003178C;
        q = D_80031790;
        new_var3 = (u32 *) q;
        new_var2 = new_var3;
        D_8003072E = *p;
        new_var = p;
        D_80030730[0] = *new_var2;
        pa = (u16 *) D_80031788;
        *p = 0;
        v = *((volatile u16 *) new_var);
        *pa = v;
        q = (new_var4 = D_80031790);
        w = (*((u32 *) q)) & 0x77777777;
        *((volatile u32 *) q) = w;
        func_80022014();
        r = s0;
        *r = 0;
        return r;
    }
    if (D_8003178C) {
        return 0;
    } else {
        return 0;
    }
}

extern void func_80022024(void *);

u16 *ETCRestartIntr(void) {
    u8 *s0 = (u8 *) &D_800306FC;

    if (*(u16 *) s0 != 0) {
        return 0;
    }
    func_80022024(s0 + 0x38);
    *(u16 *) s0 = 1;
    *D_8003178C = D_8003072E;
    *(volatile u32 *) D_80031790 = D_80030730[0];
    func_80022044();
    return (u16 *) s0;
}

void ETCMemclr(int *arg0, int arg1) {
    int *p = arg0;
    while (arg1-- != 0) {
        *p++ = 0;
    }
}

void *Vcount(void) {
    *D_800317BC = 0x107;
    D_800317B8 = 0;
    ETCMemclr2(D_80031798, 8);
    ((void (*)(s32, void *)) ETCInterruptCallback)(0, startIntrVSync);
    return (void *) ETCSetIntrVsync;
}

void startIntrVSync(void) {
    int i;

    D_800317B8++;
    for (i = 0; i < 8; i++) {
        if (D_80031798[i])
            ((void (*)(void)) D_80031798[i])();
    }
}

void ETCSetIntrVsync(int idx, int fn) {
    int *base;
    int *p;

    base = D_80031798;
    p = base + idx;
    if (fn != *p)
        *p = fn;
}

void ETCMemclr2(int *arg0, int arg1) {
    int *p = arg0;
    while (arg1-- != 0) {
        *p++ = 0;
    }
}

extern s32 *D_800317E4;
extern void ETCMemclr3(s32 *, s32);
extern void func_8002232C();
extern char D_80010184[];
extern char D_800101A0[];
void ETCTrapIntrDMA(void);
Callback ETCSetIntrDMA(s32 index, Callback callback);

void *startIntrDMA(void) {
    ETCMemclr3((s32 *) D_800317C4, 8);
    *D_800317C0 = 0;
    ((void (*)(s32, void *)) ETCInterruptCallback)(3, ETCTrapIntrDMA);
    return ETCSetIntrDMA;
}

void ETCTrapIntrDMA(void) {
    u32 mask;
    s32 i;

    i = 0;
    while ((mask = (*D_800317C0 >> 24) & 0x7F) != 0) {
        for (i = 0; mask != 0 && i < 7; i++, mask >>= 1) {
            if (mask & 1) {
                *D_800317C0 &= 0xFFFFFF | (1 << (i + 24));
                if (D_800317C4[i] != NULL) {
                    D_800317C4[i]();
                }
            }
        }
    }
    if ((*D_800317C0 & 0xFF000000) == 0x80000000 ||
        (*D_800317C0 & 0x8000) != 0) {
        func_8002232C(D_80010184, *D_800317C0);
        for (i = 0; i < 7; i++) {
            func_8002232C(D_800101A0, i, D_800317E4[i * 4]);
        }
    }
}

Callback ETCSetIntrDMA(s32 index, Callback callback) {
    Callback prev = D_800317C4[index];
    if (callback != prev) {
        if (callback != NULL) {
            D_800317C4[index] = callback;
            *D_800317C0 =
                (*D_800317C0 & 0xFFFFFF) | 0x800000 | (1 << (index + 16));
        } else {
            D_800317C4[index] = NULL;
            *D_800317C0 =
                ((*D_800317C0 & 0xFFFFFF) | 0x800000) & ~(1 << (index + 16));
        }
    }
    return prev;
}

void ETCMemclr3(s32 *arg0, s32 arg1) {
    s32 *var_a0;
    int var_v0;

    var_a0 = arg0;
    var_v0 = arg1;
    while (var_v0--) {
        *var_a0 = 0;
        var_a0 += 1;
    }
}

int ETCSetVideoMode(int arg0) {
    int prev;

    prev = D_800317E8;
    D_800317E8 = arg0;
    return prev;
}

s32 ETCGetVideoMode(void) {
    return D_800317E8;
}

extern s32 D_800408DC;
extern volatile s32 D_80040918;
void CdStClearRing(void);

void ETCStSetRing(s32 arg0, s32 arg1) {
    D_800408DC = arg0;
    D_80040918 = arg1;
    CdStClearRing();
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001E8C4);

void func_80021F64(s32, s32);

void CdDefCbsync(void) {
    func_80021F64(0xF0000003, 0x20);
}

void CdDefCbready(void) {
    func_80021F64(0xF0000003, 0x40);
}

void CdDefCbread(void) {
    func_80021F64(0xF0000003, 0x40);
}

extern u8 D_8003188C;

u8 CdStatus(void) {
    return D_8003188C;
}

extern u8 D_8003189C;

u8 CdMode(void) {
    return D_8003189C;
}

extern u8 D_8003189D;

u8 CdLastCom(void) {
    return D_8003189D;
}

extern s32 D_80031898;

s32 *CdLastPos(void) {
    return &D_80031898;
}

extern s32 func_800202F8();
extern void CdInitintr(void);

s32 CdDataCallback(s32 arg0) {
    s32 r;
    if (arg0 == 2) {
        CdInitintr();
        return 1;
    }
    if (func_800202F8() != 0) {
        return 0;
    }
    if (arg0 != 1) {
        return 1;
    }
    r = CdInitvol();
    if (r != 0) {
        r = 0;
    } else {
        r = 1;
    }
    return r;
}

extern void CdFlush(void);

void _CdFlush(void) {
    CdFlush();
}

extern volatile s32 D_80031888;

void _CdSetDebug(s32 arg0) {
    D_80031888;
    D_80031888 = arg0;
}

extern s32 D_800318A0[];
extern s32 D_800101C8;

s32 CdComstr(u32 arg0) {
    arg0 &= 0xFF;
    if (arg0 >= 0x1C) {
        return (s32) &D_800101C8;
    }
    return D_800318A0[arg0];
}

extern s32 D_80031920[];

s32 CdIntstr(u32 arg0) {
    arg0 &= 0xFF;
    if (arg0 >= 7) {
        return (s32) &D_800101C8;
    }
    return D_80031920[arg0];
}

s32 CdSync();

void _CdSync(void) {
    CdSync();
}

void _CdReady(void) {
    CdReady();
}

extern s32 D_8003187C;

s32 CdSyncCallback(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8003187C;
    D_8003187C = arg0;
    return temp_v0;
}

extern s32 D_80031880;

s32 _CdReadyCallback(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80031880;
    D_80031880 = arg0;
    return temp_v0;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001EB88);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001ECC0);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001EDEC);

s32 _CdMix(void *arg0) {
    CdVol();
    return 1;
}

s32 CdGetSector(void) {
    return func_80020650() == 0;
}

void _CdDataCallback(s32 arg0) {
    func_8001DDEC(3, arg0);
}

void CdDataSync(void) {
    CdDatasync();
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_8001EFBC);

s32 CdMix(void *arg0) {
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_v1;

    temp_v1 = ((u8 *) arg0)[0];
    temp_a2 = ((u8 *) arg0)[1];
    temp_a1 = ((u8 *) arg0)[2];
    return (((((((temp_v1 >> 4) * 0xA) + (temp_v1 & 0xF)) * 0x3C) + (((temp_a2 >> 4) * 0xA) + (temp_a2 & 0xF))) * 0x4B) + (((temp_a1 >> 4) * 0xA) + (temp_a1 & 0xF))) - 0x96;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_8001F140);

extern char D_8001030C[];
extern char D_8001031C[];
extern char D_80010394[];
extern u8 *D_80031B40;
extern volatile u8 D_80031B58;
extern u8 D_80032A7C[];
extern u8 D_80032A84[];
extern u32 D_80032A94;
extern u32 D_80032A98;
extern u32 D_80032A9C;
extern s32 func_8001F140(void);

s32 CdSync(s32 arg0, s32 arg1) {
    volatile u8 *s2;
    register volatile u8 *s4 asm("s4");
    s32 *s3;
    s32 s0v;
    register s32 s1v asm("s1");
    s32 temp_v1;
    s32 var_v0;
    u32 *new_var;
    s32 s0t;
    s32 var_v0_2;
    s32 temp_a2;
    u8 *var_a0;
    u8 *var_a1;
    s32 var_v1;
    u8 temp_u8;

    D_80032A94 = func_8001DBA8(-1) + 0x3C0;
    s3 = D_80031920;
    s2 = &D_80031B58;
    s4 = s2 + 1;
    D_80032A98 = 0;
    do {
        D_80032A9C = (u32) &D_80010394;
loop_1:
        if (((s32) D_80032A94 < func_8001DBA8(-1)) ||
            (temp_v1 = D_80032A98, D_80032A98 = temp_v1 + 1, temp_v1 > 0x3C0000)) {
            new_var = &D_80032A9C;
            func_8002228C(&D_8001030C);
            func_8002232C(&D_8001031C, (void *) *new_var, D_800318A0[D_8003189D], s3[s2[0]], s3[s2[1]]);
            CdFlush();
            var_v0_2 = -1;
        } else {
            var_v0_2 = 0;
        }
    } while (0);
    if (var_v0_2 == 0) {
        if (((s32 (*)(void)) ETCCheckCallback)() == 0) {
            goto disp;
        }
        temp_u8 = *D_80031B40;
        s1v = temp_u8 & 3;
loop_8:
        s0v = func_8001F140();
        s0t = s0v;
        if (s0t == 0) {
            goto out;
        }
        if (s0t & 4) {
            if (D_80031880 != 0) {
                ((void (*)(u8, void *)) D_80031880)(s4[0], D_80032A84);
            }
        }
        if ((s0t & 2) == 0) {
            goto loop_8;
        }
        if (D_8003187C == 0) {
            goto loop_8;
        }
        ((void (*)(u8, void *)) D_8003187C)(s2[0], D_80032A7C);
        goto loop_8;
out:
        *D_80031B40 = s1v;
disp:
        temp_a2 = s2[0] & 0xFF;
        if ((temp_a2 == 2) || (temp_a2 == 5)) {
            s2[0] = 2;
            var_a1 = (u8 *) arg1;
            var_a0 = D_80032A7C;
            var_v1 = 7;
            if (arg1 != 0) {
                do {
                    temp_u8 = *var_a0;
                    var_a0 += 1;
                    var_v1 -= 1;
                    *var_a1 = temp_u8;
                    var_a1 += 1;
                } while (var_v1 != -1);
            }
            return temp_a2;
        }
        if (arg0 == 0) {
            goto loop_1;
        }
        var_v0 = 0;
    } else {
        var_v0 = -1;
    }
    return var_v0;
}

extern char D_8001039C[];
extern u8 D_80032A8C[];

s32 CdReady(s32 arg0, u8 *arg1) {
    s32 poll;
    s32 old;
    s32 status;
    s32 result;
    s32 count;
    u8 saved;
    s16 sentinel;
    u8 *src;
    register u8 *dst asm("a1");
    u8 *state;
    u8 *done;
    u8 *ready;
    s32 *names;
    s32 raw;

    D_80032A94 = func_8001DBA8(-1) + 0x3C0;
    D_80032A98 = 0;
    D_80032A9C = D_8001039C;
    names = D_80031920;
    state = (u8 *) (&D_80031B58);
    ready = state + 1;
    done = state + 2;
    do {
        if (((s32) D_80032A94 < func_8001DBA8(-1)) || ((s32) D_80032A98++ > 0x3C0000)) {
            func_8002228C(D_8001030C);
            {
                s32 first;
                register s32 second asm("v0");
                register char *message asm("a1");
                register s32 value asm("v1");
                s32 tableIndex;

                first = state[0];
                second = state[1];
                message = (char *) D_80032A9C;
                asm volatile("" : "=r"(first), "=r"(second), "=r"(message) : "0"(first), "1"(second),
                                                                             "2"(message));
                value = names[second];
                func_8002232C(D_8001031C, message, D_800318A0[tableIndex = D_8003189D], names[first], value);
            }
            CdFlush();
            status = -1;
        } else {
            status = 0;
        }
        if (status != 0) {
            return -1;
        }
        if (((s32 (*)()) ETCCheckCallback)() != 0) {
            saved = (*D_80031B40) & 3;
            while ((poll = func_8001F140()) != 0) {
                if ((poll & 4) && (D_80031880 != 0)) {
                    ((void (*)()) D_80031880)(*ready, D_80032A84);
                }
                if ((poll & 2) && (D_8003187C != 0)) {
                    ((void (*)()) D_8003187C)(*state, D_80032A7C);
                }
            }
            *D_80031B40 = saved;
        }
        raw = *done;
        asm volatile("" : "=r"(raw) : "0"(raw));
        result = raw & 0xFF;
        if (result != 0) {
            *done = 0;
            src = D_80032A8C;
            dst = arg1;
            if (arg1 != 0) {
                count = 7;
                sentinel = -1;
                do {
                    *(dst++) = *(src++);
                    count--;
                } while (count != sentinel);
                return result;
            }
            goto copy_return;
        }
        raw = done[-1];
        asm volatile("" : "=r"(raw) : "0"(raw));
        result = raw & 0xFF;
        if (result != 0) {
            done[-1] = 0;
            asm volatile("" : : : "memory");
            dst = arg1;
            src = D_80032A84;
            count = 7;
            if (dst != 0) {
                sentinel = -1;
                do {
                    *(dst++) = *(src++);
                    count--;
                } while (count != sentinel);
            }
copy_return:
            asm volatile("");
            return result;
        }
    } while (arg0 == 0);
    return 0;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_8001FC04);

extern u8 *D_80031B44;
extern u8 *D_80031B48;
extern u8 *D_80031B4C;

s32 CdVol(u8 *arg0) {
    *D_80031B40 = 2;
    *D_80031B48 = arg0[0];
    *D_80031B4C = arg0[1];
    *D_80031B40 = 3;
    *D_80031B44 = arg0[2];
    *D_80031B48 = arg0[3];
    *D_80031B4C = 0x20;
    return 0;
}

extern volatile u8 D_80031B5A;
extern s32 *D_80031B50;

void CdFlush(void) {
    *D_80031B40 = 1;
    while ((*D_80031B4C & 7) != 0) {
        *D_80031B40 = 1;
        *D_80031B4C = 7;
        *D_80031B48 = 7;
    }
    D_80031B5A = 0;
    ((volatile u8 *) &D_80031B5A)[-1] = *(&D_80031B5A);
    D_80031B58 = 2;
    *D_80031B40 = 0;
    *D_80031B4C = 0;
    *(volatile s32 *) D_80031B50 = 0x1325;
}

extern u16 *D_80031B54;

s32 CdInitvol(void) {
    u8 buf[4];
    u16 *p = D_80031B54;

    if (p[0xDC] == 0 && p[0xDD] == 0) {
        p[0xC0] = 0x3FFF;
        p[0xC1] = 0x3FFF;
    }
    p = D_80031B54;
    p[0xD8] = 0x3FFF;
    p[0xD9] = 0x3FFF;
    p[0xD5] = 0xC001;
    buf[2] = 0x80;
    buf[0] = 0x80;
    buf[3] = 0;
    buf[1] = 0;
    *D_80031B40 = 2;
    *D_80031B48 = buf[0];
    *D_80031B4C = buf[1];
    *D_80031B40 = 3;
    *D_80031B44 = buf[2];
    *D_80031B48 = buf[3];
    *D_80031B4C = 0x20;
    return 0;
}

extern s32 D_80031890;
void CdCallback(void);

void CdInitintr(void) {
    D_80031880 = 0;
    D_8003187C = 0;
    D_80031890 = 0;
    *(u32 *) 0x8003188C = 0;
    ETCResetCallback();
    ((void (*)(s32, void *)) ETCInterruptCallback)(2, CdCallback);
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_800202F8);

extern char D_80010414[];
extern u32 D_80031B84;

s32 CdDatasync(s32 arg0) {
    s32 s2v = arg0;
    register volatile u8 *s1 asm("s1");
    s32 *s3;
    register s32 *s0 asm("s0");
    s32 temp_v1;
    s32 var_v0;
    u32 *new_var;
    s32 var_v0_2;

    D_80032A94 = func_8001DBA8(-1) + 0x3C0;
    s3 = D_800318A0;
    s1 = &D_80031B58;
    s0 = D_80031920;
    D_80032A98 = 0;
    D_80032A9C = (u32) &D_80010414;
loop_1:
    if (((s32) D_80032A94 < func_8001DBA8(-1)) || (temp_v1 = D_80032A98, D_80032A98 = temp_v1 + 1, temp_v1 > 0x3C0000)) {
        new_var = &D_80032A9C;
        func_8002228C(&D_8001030C);
        func_8002232C(&D_8001031C, (void *) *new_var, s3[D_8003189D], s0[s1[0]], s0[s1[1]]);
        CdFlush();
        var_v0_2 = -1;
    } else {
        var_v0_2 = 0;
    }
    if (var_v0_2 == 0) {
        if ((*(s32 *) D_80031B84 & 0x01000000) == 0) {
            var_v0 = 0;
        } else {
            if (s2v == 0) {
                goto loop_1;
            }
            var_v0 = 1;
        }
    } else {
        var_v0 = -1;
    }
    return var_v0;
}

extern u32 D_80031B74;
extern u32 D_80031B78;
extern u32 D_80031B7C;
extern u32 D_80031B80;

s32 func_80020650(s32 arg0, s32 arg1) {
    *D_80031B40 = 0;
    *D_80031B4C = 0x80;
    *(s32 *) D_80031B74 = 0x20943;
    *(s32 *) D_80031B50 = 0x1323;
    *(s32 *) D_80031B78 |= 0x8000;
    *(s32 *) D_80031B7C = arg0;
    *(s32 *) D_80031B80 = arg1 | 0x10000;
    do {
    } while ((*(volatile u8 *) D_80031B40 & 0x40) == 0);
    *(s32 *) D_80031B84 = 0x11000000;
    if (*(s32 *) D_80031B84 & 0x01000000) {
        do {
        } while (*(volatile s32 *) D_80031B84 & 0x01000000);
    }
    *(s32 *) D_80031B50 = 0x1325;
    return 0;
}

extern s32 D_80031B24;

void CdSetTestParmnum(s32 arg0) {
    D_80031B24 = arg0;
}

extern u8 D_80031B59;

void CdCallback(void) {
    u8 save;
    s32 v;
    u8 *p59;

    save = *D_80031B40 & 3;
    p59 = &D_80031B59;
loop:
    v = func_8001F140();
    if (v != 0) {
        if (v & 4) {
            if (D_80031880 != 0) {
                ((void (*)(u8, void *)) D_80031880)(*p59, D_80032A84);
            }
        }
        if ((v & 2) != 0) {
            s32 f2 = D_8003187C;
            if (f2 != 0) {
                ((void (*)(u8, void *)) f2)(*(volatile u8 *) &D_80031B58, D_80032A7C);
            }
        }
        goto loop;
    }
    *D_80031B40 = save;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80020840);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80020A64);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80020C3C);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80020D44);

extern s32 D_80031B88;

s32 _CdReadCallback(s32 arg0) {
    s32 ret = D_80031B88;
    D_80031B88 = arg0;
    return ret;
}

extern s32 D_80037070;
void func_8001EB88(s32 arg0, void *arg1, s32 arg2);
void func_80020F94(void);
void CdStCdInterrupt2(void);

void StMode(s32 arg0) {
    u8 buf;

    buf = arg0;
    func_8001EB88(0xE, &buf, 0);
    if (arg0 & 0x100) {
        if (arg0 & 0x20) {
            D_80037070 = 0;
        } else {
            D_80037070 = 1;
        }
        _CdDataCallback((s32) func_80020F94);
        _CdReadyCallback((s32) CdStCdInterrupt2);
    }
    func_8001EB88(0x1B, 0, 0);
}

void func_800212EC(void);

void CdStCdInterrupt2(void) {
    func_800212EC();
}

extern s32 D_800408C4;
extern s32 D_800408C0;
extern s32 D_800408BC;
extern s32 D_800370B4;
extern s32 D_8003707C;
extern u16 D_80037068;
extern s32 SUZUKIUnknown3701C;
extern unsigned char Stframe_no_800211C8();

void CdStClearRing(void) {
    register s32 a1 asm("a1") = D_80040918;
    D_800408C4 = 0;
    D_800408C0 = 0;
    D_800408BC = 0;
    D_800370B4 = 0;
    Stframe_no_800211C8(0);
    D_8003707C = 0;
    D_80037068 = 0;
    SUZUKIUnknown3701C = 0;
}

extern volatile s8 *D_80031BC8;
extern volatile s8 *D_80031BD4;

void Stframe_no(void) {
    func_80022034();
    _CdDataCallback(0);
    _CdReadyCallback(0);
    *D_80031BC8 = 0;
    *D_80031BD4 = 0;
    func_80022044();
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80020F94);

extern s32 CdMix(void *);
extern char D_80032AA0[];
extern s32 D_80032AA4;

s32 StFinalSector(void *arg0) {
    s32 v = D_80037070;
    if (v != 0) {
        return -1;
    } else {
        s32 a = CdMix(&D_80032AA0) + 1;
        func_8001EFBC(a, arg0);
        return D_80032AA4;
    }
}

extern u32 D_8003706C;
extern u32 D_80037074;
extern u32 D_80037078;
extern u32 D_800370A4;
extern u32 D_800370AC;
extern u32 D_800408CC;

void Stframe_no_80021084(s32 arg0, s32 unused1, s32 unused2, s32 arg3, s32 arg4) {
    CdStSetMask(1);
    D_800408CC = 0;
    D_80037074 = arg3;
    D_8003706C = arg0 & 1;
    D_800370AC = 0;
    D_800370A4 = 0;
    D_80037068 = 0;
    SUZUKIUnknown3701C = 0;
    D_80037078 = arg4;
}

s32 Stframe_no_8002110C(s32 arg0) {
    s32 idx;
    s32 x;
    s32 entry;
    s32 i;
    s32 t;

    x = (arg0 - ((D_80040918 << 5) + D_800408DC)) >> 2;
    idx = x / 504;
    entry = (idx << 5) + D_800408DC;
    t = *(u16 *) (entry + 6);

    if (*(s16 *) entry != 4) {
        return 1;
    }
    for (i = 0; i < (s16) t; i++) {
        *(s16 *) (((i + idx) << 5) + D_800408DC) = 0;
    }
    D_800408C4 = i + idx;
    return 0;
}

unsigned char Stframe_no_800211C8(s32 arg0, u32 arg1) {
    s32 temp_v0;
    u32 var_a2;
    s32 unused[2];

    var_a2 = 0;
    if (arg1 != 0) {
        do {
            temp_v0 = var_a2 + arg0;
            var_a2 += 1;
            *(s32 *) ((temp_v0 << 5) + D_800408DC) = 0;
        } while (var_a2 < arg1);
    }
}

extern s32 D_800408D0;

s32 Stframe_no_80021208(s32 *arg0, s32 *arg1) {
    s32 *entry;

    entry = (s32 *) ((D_800408C4 << 5) + D_800408DC);
    if ((*(volatile u16 *) entry & 0xFFFF) == 1) {
        D_800408C4 = 0;
        if (D_800408D0 != 0) {
            *(s16 *) entry = 0;
        }
        entry = (s32 *) ((D_800408C4 << 5) + D_800408DC);
    }
    if ((*(volatile u16 *) entry & 0xFFFF) != 2) {
        return 1;
    }
    *(s16 *) entry = 4;
    *arg0 = ((D_80040918 << 5) + D_800408DC) + D_800408C4 * 2016;
    *arg1 = (s32) entry;
    return 0;
}

extern s32 D_800370A8;
extern s32 D_800408D4;

void CdStSetMask(s32 arg0, s32 arg1, s32 arg2) {
    D_800408D4 = arg0;
    D_800370A8 = arg1;
    D_800408D0 = arg2;
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_800212EC);

void StFinalSector_80021C5C(s32 *arg0, s32 *arg1, u32 arg2) {
    u32 i;

    for (i = 0; i < arg2; i++) {
        arg0[i] = arg1[i];
    }
}

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80021C90);

INCLUDE_PSYQ("rom/extracted/asm/nonmatchings/main_2", func_80021E4C);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_80021F14);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_80021F20);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_80021F24);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_80021F30);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", func_80021F34);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_2", pad_80021F40);

/* main_data 0x80028AF4-0x80040934 bulk 187 D_* per-constant (98% auto) - vram order, not top - filtered no dup */
extern u32 D_8002A93C[];
extern u32 D_8002AD64;
extern u32 D_8002AD68;
extern u32 D_8002AD70;
extern u32 D_8002AD74;
extern u32 D_8002AD84[];
extern u32 D_8002AD98;
extern u32 D_8002AD9C;
extern u8 D_8002ADFC[];
extern u16 D_8002FEE8[];
extern u32 D_800306F8;
extern u32 D_80030700[];
extern u16 D_8003072C;
extern u32 D_80030738[];
extern u32 D_80031794;
extern u32 D_800317FC[];
extern u32 D_80031894;
extern u32 D_80031940[];
extern u32 D_800319C0[];
extern u32 D_80031A40[];
extern u32 D_80031AC0[];
extern u32 D_80031B5C[];
extern u32 D_80031B8C;
extern u32 D_80031B90;
extern u32 D_80031B94;
extern u32 D_80031B98;
extern u32 D_80031B9C;
extern u32 D_80031BA0;
extern u32 D_80031BA4;
extern u32 D_80031BA8;
extern u32 D_80031BAC;
extern u32 D_80031BB0;
extern u32 D_80031BB4[];
extern u32 D_80031C38[];
extern u32 D_80031C40;
extern u32 D_80031C44;
extern u32 D_80031C48;
extern u32 D_80031C4C;
extern u32 D_80031C50;
extern u32 D_80031C54;
extern u32 D_80031C58[];
extern u32 D_80031C68[];
extern u32 D_80031C80[];
extern u32 D_80031C98;
extern u32 D_80031C9C;
extern u32 D_80031CA0[];
extern u32 D_80031CB0[];
extern u32 D_80031CBC[];
extern u32 D_80031CCC[];
extern u32 D_80031CD8;
extern u32 D_80031CDC;
extern u32 D_80031CE0;
extern u32 D_80031CE4;
extern u32 D_80031CE8[];
extern u32 D_80031E3C;
extern u32 D_80031E40;
extern u32 D_80031E44[];
extern u32 D_80032844;
extern u32 D_80032848;
extern u32 D_8003284C[];
extern u32 D_8003288C;
extern u32 D_80032890;
extern u8 D_80032894;
extern u8 D_80032895;
extern u8 D_80032896;
extern u8 D_80032897;
extern u16 D_80032898;
extern u16 D_8003289A;
extern u32 D_8003289C;
extern u32 D_800328A0;
extern u32 D_800328A4[];
extern u16 D_80032900;
extern u16 D_80032902;
extern u16 D_80032904;
extern u16 D_80032906;
extern u16 D_80032908;
extern u16 D_8003290A;
extern u16 D_8003290C;
extern u16 D_8003290E;
extern u32 D_80032910;
extern u16 D_80032914[];
extern u16 D_80032928[];
extern u32 D_80032944;
extern u32 D_80032948;
extern u32 D_8003294C;
extern u32 D_80032950[];
extern u32 D_80032964;
extern u32 D_80032968;
extern u32 D_8003296C;
extern u32 D_80032970;
extern u32 D_80032974;
extern u32 D_80032978;
extern u32 D_8003297C;
extern u32 D_80032980;
extern u32 D_80032984;
extern u32 D_80032988;
extern u32 D_8003298C;
extern u32 D_80032990[];
extern u32 D_80032998;
extern u32 D_8003299C;
extern u32 D_800329A0;
extern u32 D_800329A4;
extern u32 D_800329A8;
extern u32 D_800329AC;
extern u32 D_800329B0[];
extern u32 D_800329BC;
extern u32 D_800329C0[];
extern u32 D_800329D0[];
extern u32 D_800329E0[];
extern u32 D_80032AA8;
extern u32 D_80032AAC[];
extern u32 D_80032EAC[];
extern u16 D_80036EAC[];
extern u16 D_80036EB0[];
extern u32 D_80036EB4;
extern u32 D_80036EB8;
extern u32 D_80036EBC;
extern u32 D_80036EC0;
extern u32 D_80036EC4;
extern u32 D_80036EC8;
extern u32 D_80036ECC;
extern u32 D_80036ED0;
extern u32 D_80036ED4;
extern u32 D_80036ED8;
extern u32 D_80036EDC;
extern u32 D_80036EE0[];
extern u8 D_80036EF4[];
extern u32 D_80036FF4;
extern u32 D_80036FF8;
extern u32 D_80036FFC;
extern u32 D_80037000;
extern u32 D_80037004;
extern u16 D_80037080;
extern u16 D_80037082;
extern u32 D_80037084[];
extern u32 D_800370B8;
extern u32 D_8003F0BC;
extern u32 D_8003F0C0;
extern u32 D_8003F0C4;
extern u32 D_8003F0C8[];
extern u32 D_800408D8;
extern u32 D_8004091C[];
extern u32 D_80040924[];
extern u32 D_8004092C[];
