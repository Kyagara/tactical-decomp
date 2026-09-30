#include "common.h"

extern void SetDrawMode();
extern void SPUDataTransferController();
extern u8 *func_80016DC0();
void SPUSetReverbVoice(s32 arg0, s32 arg1);
void SPUSetPitchLFOVoice(s32 arg0, s32 arg1);
void ETCMemclr2(int *arg0, int arg1);
void func_80021FC4(void *arg0);
void func_80021FB4(void *arg0);
void func_8001442C(void *arg0, void *arg1, s32 arg2);
void SUZUKIInitializeMusHeader();
void func_80013788(SeqSong *arg0);
void SUZUKISetMus(s32 *arg0);
void SetVolBalance(s32 arg0, s16 *arg1, s32 arg2);
void SPUSetNoiseVoice(s32 arg0, s32 arg1);
extern s32 BuildFileHeader(u8 *, s32, s32, s32, s32);
extern s32 func_80016BF8(s32, s16, s16);
extern s32 func_800176E4(SeqVoiceEnv *);
extern s32 func_80017744(SeqVoiceEnv *);
void SUZUKIDeallocateMUSChannels(SeqSong *arg0);
void TurnOffAllMUS(void);
s32 func_80013544(SeqSong *arg0);
void SUZUKISetNoteflags2AllChannels(s32 arg0, SeqSong *arg1);
void func_800133A0(SeqSong *arg0);
void func_800133D4(SeqSong *arg0);
void func_80013480(SeqSong *arg0);
void SUZUKIRemoveMUSFromQueueForwards();
void func_800144D0(s32 *arg0, s32 arg1);
void SetInstrument(s32 arg0, SeqVoice *arg1);
void InitSoundType(s32 arg0);
void PutSoundType(s16 arg0);
void SUZUKIToggleCDAudioReverb(int arg0, int arg1);
void CommitVolumeChange(void);
void SPUDataCallback();
void func_80022034(void);
void func_80022044(void);
void CdStSetMask();
void SUZUKITransferMusicData(SeqSong *arg0);

INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010000);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_80010A24);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_80010A30);

void func_80010AD0(void) {
    __asm__("lui $t0, %hi(func_80028AE4)\n"
            "lw $t0, %lo(func_80028AE4)($t0)\n"
            "addiu $sp, $sp, -0x10\n"
            "sw $s0, 0x4($sp)\n"
            "sw $s1, 0x8($sp)\n"
            "sw $ra, 0xC($sp)\n"
            "bnez $t0, 2f\n"
            "ori $t0, $zero, 0x1\n"
            "lui $at, %hi(func_80028AE4)\n"
            "sw $t0, %lo(func_80028AE4)($at)\n"
            "lui $s0, %hi(D_80010000)\n"
            "addiu $s0, $s0, %lo(D_80010000)\n"
            "lui $s1, 0x0\n"
            "addiu $s1, $s1, 0x0\n"
            "beqz $s1, 2f\n"
            "nop\n"
            "1:\n"
            "lw $t0, 0x0($s0)\n"
            "addiu $s0, $s0, 0x4\n"
            "jalr $t0\n"
            "addiu $s1, $s1, -0x1\n"
            "bnez $s1, 1b\n"
            "nop\n"
            "2:\n"
            "lw $ra, 0xC($sp)\n"
            "lw $s1, 0x8($sp)\n"
            "lw $s0, 0x4($sp)\n"
            "addiu $sp, $sp, 0x10");
}

void SetProgramRunning(void) {
    __asm__("lui $t0, %hi(func_80028AE4)\n"
            "lw $t0, %lo(func_80028AE4)($t0)\n"
            "addiu $sp, $sp, -0x10\n"
            "sw $s0, 0x4($sp)\n"
            "sw $s1, 0x8($sp)\n"
            "sw $ra, 0xC($sp)\n"
            "beqz $t0, 2f\n"
            "nop\n"
            "lui $s0, %hi(D_80010000)\n"
            "addiu $s0, $s0, %lo(D_80010000)\n"
            "lui $s1, 0x0\n"
            "addiu $s1, $s1, 0x0\n"
            "beqz $s1, 2f\n"
            "nop\n"
            "1:\n"
            "lw $t0, 0x0($s0)\n"
            "addiu $s0, $s0, 0x4\n"
            "jalr $t0\n"
            "addiu $s1, $s1, -0x1\n"
            "bnez $s1, 1b\n"
            "nop\n"
            "2:\n"
            "lw $ra, 0xC($sp)\n"
            "lw $s1, 0x8($sp)\n"
            "lw $s0, 0x4($sp)\n"
            "addiu $sp, $sp, 0x10");
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", D_80010BA8);

void PutStackPointer(void *arg0) {
    register void *t0 asm("t0");

    t0 = arg0;
    __asm__ volatile("sw $sp, 0(%0)" : : "r"(t0));
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_80011BC0);

void BuildFileHeaderNNL(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    BuildFileHeader(arg0, arg1, arg2, arg3, -1);
}

extern s32 D_80028B08;
extern DrawEnv D_8004EA14[2];
extern MixerState D_8004EACC[2];
extern s16 D_8004EA1C;
extern s16 D_8004EA1E;
extern s16 D_8004EA78;
extern s16 D_8004EA7A;
extern s8 D_8004EA87;
extern s8 D_8004EA88;
extern s8 D_8004EA2B;
extern s8 D_8004EA2C;
extern s32 func_8001EFBC(s32, void *);

typedef struct {
    s32 unk00;
    s32 busy;
    s32 unk08;
    s32 unk0C;
    s32 sectors;
    s32 lba;
    s32 unk18;
    s32 unk1C;
    s32 dest;
} FileReq;

s32 BuildFileHeader(u8 *arg0, s32 lba, s32 sectors, s32 dest, s32 mode) {
    s16 data[4];
    u8 *temp_s1;
    u8 *temp_s2;
    FileReq *req = (FileReq *) arg0;

    if (req->busy != 0) {
        return 1;
    }
    if (mode != 1) {
        D_80028B08 = mode;
    }
    if (mode == 0) {
        DrawSync(0);
        BuildNowLoading(1, 0, 0);
        data[2] = 0x100;
        data[0] = 0;
        data[1] = 0;
        data[3] = 0x1E0;
        SetDrawMode(data, 0, 0, 0);
        func_800246D4(0);
        temp_s1 = (u8 *) &D_8004EA14[0];
        func_80022DE0(temp_s1, 0, 0, 0x100, 0xF0);
        temp_s2 = (u8 *) &D_8004EACC[0];
        func_80022EB0(temp_s2, 0, 0xF0, 0x100, 0xF0);
        temp_s1 += 0x5C;
        func_80022DE0(temp_s1, 0, 0xF0, 0x100, 0xF0);
        temp_s2 += 0x14;
        func_80022EB0(temp_s2, 0, 0, 0x100, 0xF0);
        D_8004EA7A = 0xF0;
        D_8004EA78 = 0;
        D_8004EA1E = 0;
        D_8004EA1C = 0;
        D_8004EA87 = 1;
        D_8004EA88 = 1;
        D_8004EA2B = 1;
        D_8004EA2C = 1;
        GetGraphType(temp_s1);
        func_80024E84(temp_s2);
    }
    req->unk00 = 0;
    req->unk18 = 0;
    req->unk08 = 0;
    req->busy = 1;
    req->lba = lba;
    func_8001EFBC(lba, arg0 + 0x1C);
    req->sectors = sectors;
    req->dest = dest;
    return 0;
}

extern int func_8001EDEC(s32, s32, s32);
extern s32 func_8001DBA8(s32);
extern void _CdFlush(void);
extern void AccumulateChannelsToPause(s32);
extern void PauseNeededChannels(SeqSong *, s32, s32);
extern void SUZUKICalcMUSVolChange(SeqSong *, s32, s32);

void ResetPauseCDROM(s32 *arg0) {
    int ret;
    arg0[1] = 0;
    _CdFlush();
    do {
        ret = func_8001EDEC(9, 0, 0);
    } while (ret == 0);
    func_8001DBA8(3);
}

void ResetCDSubsystems(void) {
    CdDataCallback(0);
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_80011E38);

int SetPriority(void *, int);
int _que(void *);
int NowLoadingIntoOTAG(void *);
extern int D_80032A68;

typedef struct {
    u32 magic;
    u32 ctor;
    u32 unk08;
    u32 heap;
    u32 unk10;
} MainDataHeader;

extern MainDataHeader D_80028AF4;
extern void (*D_80028B0C[])(void);
extern u8 D_80028D0C[];
extern u8 D_80028D8C[];
extern u8 D_80028E70[];
extern u8 D_80028F54[];

void DrawNowLoadingMessage(void) {
    s32 temp_s0;

    temp_s0 = D_80028B08;
    if (temp_s0 != -1) {
        temp_s0 = temp_s0 + 1;
        D_80028B08 = temp_s0;
        if (temp_s0 >= 0x40) {
            temp_s0 &= 1;
            GetGraphType(&D_8004EA14[temp_s0]);
            func_80024E84(&D_8004EACC[temp_s0]);
            SetPriority((char *) &D_80032A68 + (temp_s0 * 8), 2);
            NowLoadingIntoOTAG((char *) &D_80032A68 + (temp_s0 * 8));
            _que((char *) &D_80032A68 + (temp_s0 * 8));
            DrawSync(1);
            D_80028B08 &= 0x41;
        }
    }
}

extern s32 FindSpaceForSMDToMUS(s32);

void *SUZUKIPutPlaySMD(void *arg0) {
    SeqSong *s0;

    s0 = (SeqSong *) FindSpaceForSMDToMUS(((SeqSong *) arg0)->voiceCount * 352 + 0xB8);
    s0->parent = arg0;
    SUZUKITransferMusicData(s0);
    func_800138AC(s0);
    s0->unk5C = 0;
    SUZUKISetMus((s32 *) s0);
    return s0;
}

void SUZUKIUnloadMUS(void *arg0) {
    register u8 *s0 asm("s0") = arg0;

    if (*(s16 *) &((SeqSong *) s0)->flags & 0x8000) {
        SUZUKIDeallocateMUSChannels(arg0);
    }
    if (SUZUKIRemoveMUSFromQueue(s0) == 0) {
        SUZUKIRemoveMUSFromQueueForwards((void **) s0);
        func_80014358(s0);
    }
}

void func_800121CC(void) {
}

void func_800121D4(void) {
}

extern void *SUZUKIRootCounter2EvCB;
extern void SUZUKIForceChannelFunc(SeqSong *, s32);

void SUZUKIResetMUS(void *arg0, s32 arg1, s32 arg2) {
    SeqSong *s0;
    s32 s1;
    s32 s2;

    s0 = arg0;
    s1 = arg1;
    s2 = arg2;
    if (s0 == 0) {
        return;
    }
    s0->flags &= 0x7FFF;
    func_80021FC4(SUZUKIRootCounter2EvCB);
    SUZUKITransferMusicData(s0);
    func_800138AC(s0);
    s0->customVolume0 = 0;
    SUZUKICalcMUSVolChange(s0, (s16) s1, (s16) s2);
    SUZUKIForceChannelFunc(s0, 0x7000);
    s0->flags |= 0x8000;
    func_80021FB4(SUZUKIRootCounter2EvCB);
}

void SUZUKIForceRecalculateReverb(void *arg0, s32 arg1, s32 arg2) {
    SeqSong *s0;
    s32 s1;
    s32 s2;

    s0 = arg0;
    s1 = arg1;
    s2 = arg2;
    if (s0 == 0) {
        return;
    }
    func_80021FC4(SUZUKIRootCounter2EvCB);
    s0->customVolume0 = 0;
    SUZUKICalcMUSVolChange(s0, (s16) s1, (s16) s2);
    SUZUKISetSPUReverbMode(s0->reverbMode, s0->volumeDepth, s0->reverbDelay, s0->reverbFeedback);
    SUZUKIForceChannelFunc(s0, 0x71FF);
    func_80013544(s0);
    s0->flags = (s0->flags & 0xFEFF) | 0x8000;
    func_80021FB4(SUZUKIRootCounter2EvCB);
}

s32 SUZUKIGetActiveChannels(SeqSong *);
extern s32 D_80032A08;

void SUZUKIDeallocateMUSChannels(SeqSong *arg0) {
    if (arg0 != NULL) {
        arg0->flags = arg0->flags & 0x7FFF;
        D_80032A08 |= SUZUKIGetActiveChannels(arg0);
    }
}

void func_8001237C(SeqSong *arg0) {
    if (arg0 != NULL) {
        arg0->flags = arg0->flags & 0x7FFF;
        arg0->flags |= 0x100;
        D_80032A08 |= SUZUKIGetActiveChannels(arg0);
    }
}

extern s32 D_80032A50;

void func_800123CC(void) {
    SeqSong *s0;
    u16 v1;
    s32 v0;

    s0 = (SeqSong *) D_80032A50;
    if (s0 == 0) {
        return;
    }
    do {
        v1 = s0->flags;
        if (v1 & 1) {
            v0 = v1 & 0x7FFF;
            s0->flags = v0;
            D_80032A08 |= SUZUKIGetActiveChannels(s0);
        }
        s0 = s0->next;
    } while (s0 != 0);
}

void func_80012444(SeqSong *arg0, u8 *arg1) {
    u8 *voice = (u8 *) arg0->voices;
    u16 *offsets = (u16 *) (arg1 + 0x22);
    u8 *field = (u8 *) arg0->voices + 0x20;
    s32 remaining = arg0->trackCount;
    s32 count = arg1[0x14];
    s32 addr;
    u16 off;

    do {
        ((SeqVoice *) voice)->channelFlags |= 0x4000;
        if (count != 0) {
            addr = 0;
            off = *offsets;
            if (off != 0) {
                addr = (s32) arg1 + off;
            }
            *(u32 *) field = addr;
            count -= 1;
            offsets += 1;
        } else {
            *(u32 *) field = 0;
        }
        field += 0x160;
        remaining -= 1;
        voice += 0x160;
    } while (remaining != 0);
}

void func_800124AC(void) {
}

void func_800124B4(void) {
}

void func_800124BC(void) {
}

void func_800124C4(void) {
}

extern void func_80013B20();
extern s32 SUZUKIGetAvailableVoiceForSFX(s32, s32);
extern u16 SUZUKISpuInstructionFlags;
extern u16 D_80032A28;
extern u16 SUZUKISfxOverMusic;

void SUZUKIToggleMusicPlaying(s32 arg0) {
    u16 v;
    if (arg0 != 0) {
        v = SUZUKISpuInstructionFlags | 0x1000;
    } else {
        TurnOffAllMUS();
        v = SUZUKISpuInstructionFlags & 0xEFFF;
    }
    SUZUKISpuInstructionFlags = v;
}

void SUZUKIPlaySound1(s32 arg0) {
    if (SUZUKISpuInstructionFlags & 0x1000) {
        SUZUKISfxOverMusic = 2;
        func_80013B20(-0x7FFA, arg0, 0x6000, 0x4000);
    }
}

void SUZUKIPlaySound2(s32 arg0) {
    if (SUZUKISpuInstructionFlags & 0x1000) {
        SUZUKISfxOverMusic = 2;
        func_80013B20(0x6004, arg0, 0x6000, 0x4000);
    }
}

void SUZUKIPlaySoundFindChannel(s32 arg0) {
    s32 temp_v0;

    if (SUZUKISpuInstructionFlags & 0x1000) {
        temp_v0 = SUZUKIGetAvailableVoiceForSFX(arg0, 2);
        SUZUKISfxOverMusic = 2;
        func_80013B20((s16) (temp_v0 | 0x2000), arg0, 0x6000, 0x4000);
    }
}

void SUZUKIPlaySoundInChannel(s32 arg0, u32 arg1) {
    u32 a = arg1 & 0xFFFE;
    if (SUZUKISpuInstructionFlags & 0x1000) {
        SUZUKISfxOverMusic = 2;
        func_80013B20((s16) (a | 0x2000), arg0, 0x6000, 0x4000);
    }
}

void SUZUKIPlaySoundWithSettingsFindChannel(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    if (SUZUKISpuInstructionFlags & 0x1000) {
        temp_v0 = SUZUKIGetAvailableVoiceForSFX(arg0, 2);
        SUZUKISfxOverMusic = 2;
        func_80013B20((s16) (temp_v0 | 0x2000), arg0, (s16) (arg1 << 8), (s16) (arg2 << 8));
    }
}

void SUZUKIPlaySoundWithSettingsInChannel(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 a = arg1 & 0xFFFE;
    if (SUZUKISpuInstructionFlags & 0x1000) {
        SUZUKISfxOverMusic = 2;
        func_80013B20((s16) (a | 0x2000), arg0, (s16) (arg2 << 8), (s16) (arg3 << 8));
    }
}

void SUZUKIPlay2Sound(s32 arg0, s32 arg1) {
    s32 v1;
    s32 s0;

    v1 = arg0;
    s0 = arg1;
    if (SUZUKISpuInstructionFlags & 0x1000) {
        SUZUKISfxOverMusic = 2;
        func_80013B20(0x2000, v1, 0x6000, 0x4000);
        func_80013B20(0x2002, s0, 0x6000, 0x4000);
    }
}

void SUZUKIPlay4Sound(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v1;
    s32 s0;
    s32 s1;
    s32 s2;

    v1 = arg0;
    s0 = arg1;
    s1 = arg2;
    s2 = arg3;
    if (SUZUKISpuInstructionFlags & 0x1000) {
        SUZUKISfxOverMusic = 2;
        func_80013B20(0x2000, v1, 0x6000, 0x4000);
        func_80013B20(0x2002, s0, 0x6000, 0x4000);
        func_80013B20(0x2004, s1, 0x6000, 0x4000);
        func_80013B20(0x2006, s2, 0x6000, 0x4000);
    }
}

extern SeqSong *SUZUKICurrentMusPointer;
extern s32 D_80032A0C;
extern s32 D_80032A18;
extern s32 D_80032A20;

void TurnOffAllMUS(void) {
    SeqVoice *v1;
    SeqSong *s0;
    s32 s1 = 0;
    int a0;

    s0 = SUZUKICurrentMusPointer;
    v1 = s0->voices;
    a0 = 8;
    do {
        a0--;
        if ((v1->channelFlags & 1) != 0) {
            v1->channelFlags = 0;
            s1 |= v1->usedChannels;
        }
        v1 += 1;
    } while (a0 != 0);
    func_80021FC4(SUZUKIRootCounter2EvCB);
    s0->ownedChannels = 0;
    s0->modifiedChannels = 0;
    s0->lfoVoiceFlags = 0;
    s0->noiseVoiceFlags = 0;
    s0->reverbVoiceFlags = 0;
    D_80032A0C = 0;
    D_80032A20 |= s1;
    func_80021FB4(SUZUKIRootCounter2EvCB);
}

void TurnOnMUSAfterSoundEffect(void *arg0) {
    s16 tag = *((s16 *) ((char *) arg0 + 0xA));
    SeqVoice *p = SUZUKICurrentMusPointer->voices;
    int i = 8;

    do {
        if ((p->channelFlags & 1) != 0) {
            s32 a = p->unk08;
            if ((a >> 16) == tag) {
                AccumulateChannelsToPause(a);
            }
        }
        i--;
        p += 1;
    } while (i != 0);
}

void AccumulateChannelsToPause(s32 arg0) {
    s32 t2 = arg0;
    s32 t1 = 1;
    s32 a2 = 0;
    s32 a1 = 0;
    SeqSong *a0 = SUZUKICurrentMusPointer;
    s32 t0 = 8;
    SeqVoice *p = a0->voices;
    s32 v0;

    do {
        if ((p->channelFlags & 1) != 0) {
            if (p->unk08 == t2) {
                v0 = p->usedChannels;
                a1 |= t1;
                p->channelFlags = 0;
                a2 |= v0;
            }
        }
        t1 <<= 1;
        p += 1;
        t0 -= 1;
    } while (t0 != 0);
    if (a1 != 0) {
        PauseNeededChannels(a0, a1, a2);
    }
}

void func_80012A20(s32 arg0) {
    s32 t0 = 1 << arg0;
    s32 a2 = 0;
    s32 a1 = 0;
    s32 a3 = 2;
    SeqSong *t1 = SUZUKICurrentMusPointer;
    SeqVoice *v1 = &t1->voices[arg0];
    s32 v0;

    do {
        if ((v1->channelFlags & 1) != 0) {
            v0 = v1->usedChannels;
            a1 |= t0;
            v1->channelFlags = 0;
            a2 |= v0;
        }
        t0 <<= 1;
        a3 -= 1;
        v1 += 1;
    } while (a3 != 0);
    if (a1 != 0) {
        PauseNeededChannels(t1, a1, a2);
    }
}

void PauseNeededChannels(SeqSong *arg0, s32 arg1, s32 arg2) {
    SeqSong *aa = arg0;
    register s32 a2v asm("s2") = arg2;
    register s32 n1v asm("s0") = ~arg1;
    s32 n2;
    s32 t;

    func_80021FC4(SUZUKIRootCounter2EvCB);
    n2 = ~a2v;
    aa->modifiedChannels &= n2;
    n1v &= aa->ownedChannels;
    aa->ownedChannels = n1v;
    a2v |= D_80032A20;
    D_80032A20 = a2v;
    D_80032A0C &= n2;
    aa->lfoVoiceFlags &= n2;
    aa->noiseVoiceFlags &= n2;
    t = n2 & aa->reverbVoiceFlags;
    aa->reverbVoiceFlags = t;
    ((void (*)(void *, s32)) func_80021FB4)(SUZUKIRootCounter2EvCB, t);
}

void SUZUKISetSFXEcho(s32 arg0, s32 value) {
    s32 key = arg0;
    s32 remaining = 8;
    register SeqSong *song asm("a0") = SUZUKICurrentMusPointer;
    register SeqVoice *voice asm("a2") = song->voices;
    register u8 *cur asm("v1");
    u16 on;
    s32 level;
    register SeqVoice *voice2 asm("a3");
    u8 *cur2;
    s32 bit;
    s32 mix;
    s32 hits;
    s32 left;
    s32 val;

    if ((value << 16) != 0) {
        value <<= 8;
        level = 0x100;
        cur = (u8 *) song + 0xBA;
        do {
            on = voice->channelFlags & 1;
            voice += 1;
            if ((on != 0) && (*(volatile s32 *) (cur + 6) == key)) {
                *(volatile u16 *) (cur + 0x92) = value;
                *(volatile u16 *) cur = level;
            }
            remaining--;
            cur += 0x160;
        } while (remaining != 0);
    } else {
        voice2 = voice;
        bit = 1;
        mix = 0;
        hits = 0;
        left = 8;
        cur2 = (u8 *) song + 0xEC;
        do {
            if (((voice2->channelFlags & 1) != 0) && (*(s32 *) (cur2 - 0x2C) == key)) {
                val = *(s32 *) cur2;
                hits |= bit;
                voice2->channelFlags = 0;
                mix |= val;
            }
            bit <<= 1;
            cur2 += 0x160;
            voice2 += 1;
            left -= 1;
        } while (left != 0);
        if (hits != 0) {
            PauseNeededChannels(song, hits, mix);
        }
    }
}

void func_80012C58(s32 key, s32 value) {
    SeqSong *song = SUZUKICurrentMusPointer;
    SeqVoice *voice = song->voices;
    u8 *cur = (u8 *) &voice->midFlags;
    s32 remaining = 8;
    u16 active;

    value <<= 8;
    do {
        active = voice->channelFlags & 1;
        voice += 1;
        if ((active != 0) && (*(volatile s32 *) (cur + 6) == key)) {
            *(volatile u16 *) (cur + 0x90) = value;
            *(volatile u16 *) cur = 0x100;
        }
        remaining--;
        cur += 0x160;
    } while (remaining != 0);
}

s32 GetUsedChannels(s32 key) {
    s32 remaining = 8;
    s32 bit = 1;
    SeqVoice *voice = SUZUKICurrentMusPointer->voices;
    s32 mask = 0;
    s32 active;

    if (key == -1) {
        do {
            active = voice->channelFlags & 1;
            if (active != 0) {
                mask |= bit;
            }
            voice += 1;
            remaining -= 1;
            bit <<= 1;
        } while (remaining != 0);
    } else {
        do {
            active = voice->channelFlags & 1;
            if (active != 0) {
                if (voice->unk08 == key) {
                    mask |= bit;
                }
            }
            voice += 1;
            remaining -= 1;
            bit <<= 1;
        } while (remaining != 0);
    }
    return mask;
}

extern u32 D_80032A10;
extern u32 D_80032A14;

s32 SUZUKIGetAvailableVoiceForSFX(s32 arg0, s32 arg1) {
    s32 t1;
    s32 t2;
    u32 a3;
    s32 t0;
    u8 *a2p;
    s32 a0v;
    u32 t4;
    u32 t3;
    s32 t5;
    register u8 *bsong asm("v1");
    u8 *v1p;
    s32 v0t;
    u32 v1w;
    u8 bytev;

    bsong = *(u8 **) &SUZUKICurrentMusPointer;
    t1 = 0;
    t2 = 0;
    a3 = 1;
    t0 = 8;
    a2p = bsong + 0xB8;
    v1p = bsong + 0xEC;
    do {
        t0 -= 1;
        if ((*(u16 *) a2p & 1) != 0) {
            if (*(u32 *) (v1p - 0x2C) == (u32) arg0) {
                v0t = *(s32 *) v1p;
                t2 |= a3;
                *(u16 *) a2p = 0;
                t1 |= v0t;
            }
        }
        a3 *= 2;
        v1p += 0x160;
        a2p += 0x160;
    } while (t0 != 0);
    v0t = 6;
    a0v = v0t - arg1;
    v0t = 0x20;
    v0t -= arg1;
    v1w = 0xFFFFFFFFu;
    t4 = v1w >> v0t;
    a3 = t4 << a0v;
    D_80032A10 = t2;
    D_80032A14 = t1;
    v0t = a0v << 1;
    v0t += a0v;
    v0t <<= 2;
    v0t -= a0v;
    v0t <<= 5;
    bsong = *(u8 **) &SUZUKICurrentMusPointer;
    t3 = 0xFFFFFFFFu;
    v0t += 0xB8;
    a2p = bsong + v0t;
    v1w = *(u32 *) (bsong + 0x58);
    v0t = ~t2;
    t0 = v0t & v1w;
    if ((t0 & a3) != 0) {
        v0t = arg1 << 1;
        v0t += arg1;
        v0t <<= 2;
        v0t -= arg1;
        t1 = v0t << 5;
        do {
            v1w = *(u32 *) (a2p + 0x10);
            a3 >>= arg1;
            if (v1w < t3) {
                bytev = *(u8 *) (a2p + 0xD);
                if (bytev < 0x21u) {
                    t3 = v1w;
                    t5 = a0v;
                }
            }
            if ((a3 < t4) != 0) {
                a0v = t5;
                break;
            } else {
                a2p -= t1;
                a0v -= arg1;
            }
        } while ((t0 & a3) != 0);
    }
    return a0v;
}

u32 SUZUKIGetMusicPlaying(SeqSong *arg0) {
    return arg0->flags >> 0xF;
}

typedef struct {
    char pad78[0x78];
    s32 unk78;
    char pad7C[0x2];
    s16 unk7E;
    char pad80[0x8];
    s32 unk88;
    s32 unk8C;
    s16 unk90;
    s16 unk92;
} func_80012E88Unk;

void func_80012E88(func_80012E88Unk *arg0, s16 arg1, s16 arg2) {
    s16 var_a0;
    s32 temp_v0;

    var_a0 = arg1;
    if ((arg1 << 0x10) == 0) {
        var_a0 = 0x100;
    }
    arg0->unk92 = var_a0;
    if (arg2 == 0) {
        arg0->unk88 = (s32) (var_a0 << 0x10);
        arg0->unk90 = 0;
        arg0->unk78 = (s32) (arg0->unk7E * var_a0);
        return;
    }
    temp_v0 = (var_a0 << 0x10) - arg0->unk88;
    if (temp_v0 != 0) {
        arg0->unk90 = arg2;
        arg0->unk8C = (s32) (temp_v0 / arg2);
    }
}

void SUZUKICalcMUSVolChange(SeqSong *arg0, s32 arg1, s32 arg2) {
    s32 new_var;
    s32 temp;
    s32 v1t = arg1;
    s32 s1 = v1t;
    void *d;

    arg0->unk9E = v1t << 8;
    new_var = v1t;
    if ((s16) arg2 == 0) {
        s32 t = s1 << 0x18;
        arg0->customVolume0 = t;
        arg0->unk9C = 0;
        SUZUKISetNoteflags2AllChannels(0x100, arg0);
    } else {
        temp = (new_var << 0x10) - (arg0->customVolume0 >> 8);
        if (temp == 0) {
            return;
        }
        temp = temp / (s16) arg2;
        arg0->unk9C = arg2;
        arg0->unk98 = temp << 8;
    }
    if ((arg0->flags & 0x100) == 0) {
        return;
    }
    if ((new_var << 16) == 0) {
        return;
    }
    func_80021FC4(SUZUKIRootCounter2EvCB);
    s1 = 0x48;
    SUZUKISetSPUReverbMode(arg0->reverbMode, arg0->volumeDepth, arg0->reverbDelay, arg0->reverbFeedback);
    SUZUKIForceChannelFunc(arg0, 0x71FF);
    func_80013544(arg0);
    d = SUZUKIRootCounter2EvCB;
    arg0->flags = (arg0->flags & 0xFEFF) | 0x8000;
    func_80021FB4(d);
}

void func_80013014(SeqSong *arg0, s32 arg1, s16 arg2) {
    s32 temp;

    arg0->unkAA = arg1 << 8;
    if (arg2 == 0) {
        arg0->customVolume1 = arg1 << 0x18;
        arg0->unkA8 = 0;
        SUZUKISetNoteflags2AllChannels(0x200, arg0);
        return;
    }
    temp = (arg1 << 0x10) - (arg0->customVolume1 >> 8);
    if (temp != 0) {
        arg0->unkA8 = arg2;
        arg0->unkA4 = (temp / arg2) << 8;
    }
}

void func_80013094(SeqSong *arg0, s32 arg1, s16 arg2) {
    s32 t;
    s16 a0c;

    arg0->unkB6 = arg1 << 8;
    a0c = arg2;
    if (arg2 == 0) {
        arg0->customVolume2 = arg1 << 0x18;
        arg0->unkB4 = 0;
        SUZUKISetNoteflags2AllChannels(0x100, arg0);
        return;
    }
    t = (arg1 << 0x10) - (arg0->customVolume2 >> 8);
    if (t != 0) {
        arg0->unkB4 = a0c;
        arg0->unkB0 = (t / arg2) << 8;
    }
}

void func_80013114(SeqSong *arg0, u32 arg1) {
    u16 *a2;
    u16 *a3;
    u16 t1;
    short t2;
    s32 t0;
    u16 v;
    int new_var;

    t2 = 0;
    if (arg0 == 0) {
        return;
    }
    t1 = 0;
    a2 = (u16 *) arg0->voices;
    t0 = arg0->trackCount;
    new_var = 0x100;
    a3 = (u16 *) &arg0->voices->usedChannels;
    arg0->unk5C = arg1;
    do {
        if ((*a2) != 0) {
            if (arg1 & 1) {
                v = *a2;
                if ((v & 0x20) == 0) {
                    *a2 = v | 0x20;
                    t2 = (*a3) | t2;
                }
            } else {
                v = *a2;
                if (v & 0x20) {
                    *a2 = v & (~0x20);
                    if (((*((u32 *) a2)) & 0x110) == new_var) {
                        t1 = t1 | (*a3);
                    }
                }
            }
        }
        a3 += 0xB0;
        a2 += 0xB0;
        t0 -= 1;
        arg1 >>= 1;
    } while (t0 != 0);
    arg0->modifiedChannels |= t1 & 0xFFFF;
    arg0->unk64 |= t2 & 0xFFFF;
}

void func_800131F0(SeqSong *arg0, u8 arg1) {
    arg0->unk1D = arg1;
}

void func_800131F8(u8 *arg0, u8 *arg1) {
    u32 v;
    u32 q1;
    u32 q2;

    v = *(u32 *) (arg0 + 0x28) >> 8;
    q1 = v / 240;
    *(u32 *) arg1 = *(u32 *) (arg0 + 0x24);
    *(u16 *) (arg1 + 4) = v - q1 * 240;
    q2 = q1 / 60;
    *(u16 *) (arg1 + 6) = q1 - q2 * 60;
    *(u16 *) (arg1 + 8) = q2;
}

u8 *func_80013260(u8 *arg0) {
    u16 *a2v = (u16 *) (arg0 + 0xB8);
    u32 cnt = arg0[0x16];
    u8 *a3v = arg0 + 0x30;
    register u32 min asm("a1") = 0xFFFF;
    u32 step = 0xFFFF;
    u8 *pv = arg0 + 0xE0;
    u16 v;

    do {
        v = *a2v;
        a2v += 0xB0;
        if (v != 0 && (u32) * (volatile u16 *) pv < min) {
            min = *(volatile u16 *) pv;
        }
        cnt += step;
        pv += 0x160;
    } while ((cnt & 0xFFFF) != 0);
    cnt = min & 0xFFFF;
    if (cnt == 0xFFFF) {
        min = 0;
    }
    *(u16 *) a3v = min;
    return a3v;
}

void *func_800132D0(s32 arg0) {
    SeqSong *v0;
    u8 *v1;

    v0 = (SeqSong *) D_80032A50;
    if (arg0 == 0) {
        goto post;
    }
    if (v0 == 0) {
        return 0;
    }
loop:
    if ((s32) v0 == arg0) {
        goto post;
    }
    v0 = v0->next;
    if (v0 != 0) {
        goto loop;
    }
post:
    if (v0 == 0) {
        return 0;
    }
    v1 = (u8 *) v0->parent;
    return (void *) (*(u16 *) (v1 + 0x1E) + (u32) v1);
}

void func_80013328(SeqSong *arg0, s32 arg1) {
    if (arg1 == 1) {
        goto c1;
    }
    if (arg1 >= 2) {
        goto ge2;
    }
    if (arg1 == 0) {
        goto c0;
    }
    goto end;
ge2:
    if (arg1 == 2) {
        goto c2;
    }
    goto end;
c0:
    func_800133A0(arg0);
    goto end;
c1:
    func_800133D4(arg0);
    goto end;
c2:
    func_80013480(arg0);
end:;
}

void func_800133A0(SeqSong *arg0) {
    u16 temp_v1;

    temp_v1 = arg0->flags;
    if (temp_v1 & 0x10) {
        arg0->flags = (u16) (temp_v1 & 0xFFEF);
        SUZUKIRemoveMUSFromQueueForwards();
    }
}

void func_800133D4(SeqSong *arg0) {
    s32 slot;
    s32 *p;
    void *a;

    func_80021FC4(SUZUKIRootCounter2EvCB);
    arg0->flags |= 0x10;
    slot = arg0->trackCount * 0x160 + 0xB8;
    if (arg0->unk04 == 0) {
        arg0->unk04 = (void *) FindSpaceForSMDToMUS(slot);
    }
    p = arg0->unk04;
    func_8001442C(p, arg0, slot);
    a = SUZUKIRootCounter2EvCB;
    p[0] = 0;
    p[1] = 0;
    arg0->unk2C = 0;
    func_80021FB4(a);
}

extern void func_80013FC0(SeqSong *, s32);

void func_80013480(SeqSong *arg0) {
    SeqSong *s1 = arg0;
    SeqSong *a0;
    s32 a1;
    s32 s0;

    if (s1->unk04 == 0) {
        return;
    }
    if ((s1->flags & 0x10) == 0) {
        return;
    }
    func_80021FC4(SUZUKIRootCounter2EvCB);
    D_80032A08 |= SUZUKIGetActiveChannels(s1);
    a1 = (s32) s1->unk04;
    s0 = s1->unk24;
    func_80013FC0(s1, a1);
    s1->unk2C = s0;
    SUZUKIForceChannelFunc(s1, 0x71FF);
    a0 = s1;
    a0->unk64 = 0;
    a0->modifiedChannels = 0;
    func_80013544(a0);
    func_80021FB4(SUZUKIRootCounter2EvCB);
}

void func_8001353C(SeqSong *arg0, u16 arg1) {
    arg0->unk54 = arg1;
}

s32 func_80013544(SeqSong *arg0) {
    s32 a2 = arg0->trackCount;
    u8 *a1 = (u8 *) arg0->voices;
    s32 a3 = 0;
    s32 t0 = 0x101;
    u8 *a0 = (u8 *) arg0->voices + 2;

    do {
        if ((*(u32 *) a1 & 0x101) == t0) {
            if ((((SeqVoice *) a1)->channelFlags & 0x30) == 0) {
                a3 |= *(s32 *) (a0 + 0x32);
                *(u16 *) a0 |= 1;
            }
        }
        a0 += 0x160;
        a2 -= 1;
        a1 += 0x160;
    } while (a2 != 0);
    return a3;
}

s32 func_800135A8(SeqSong *arg0) {
    s32 v1 = arg0->trackCount;
    u8 *a0 = (u8 *) arg0->voices;
    s32 a1 = 0;
    s32 a2 = 0x101;

    do {
        if ((*(u32 *) a0 & 0x101) == a2) {
            if ((((SeqVoice *) a0)->channelFlags & 0x30) == 0) {
                a1 |= ((SeqVoice *) a0)->usedChannels;
            }
        }
        v1 -= 1;
        a0 += 0x160;
    } while (v1 != 0);
    return a1;
}

s32 SUZUKIGetActiveChannels(SeqSong *arg0) {
    s32 var_a1;
    s32 var_v1;
    SeqVoice *var_a0;
    SeqSong *song = arg0;

    var_v1 = song->trackCount;
    var_a0 = song->voices;
    var_a1 = 0;
    do {
        var_v1 -= 1;
        if (var_a0->channelFlags != 0) {
            var_a1 |= var_a0->usedChannels;
        }
        var_a0 += 1;
    } while (var_v1 != 0);
    return var_a1;
}

__asm__(".word 0x03E00008\n\t.word 0x00000000");

void *func_8001363C(void) {
    SeqSong *buf = (SeqSong *) FindSpaceForSMDToMUS(0xBB8);
    u16 *a3;
    register u8 *v1 asm("v1");
    s32 a0;
    s32 a1;
    s32 a2;
    s32 one;

    func_80013788(buf);
    a3 = (u16 *) buf->voices;
    a0 = 0x10;
    a2 = 8;
    a1 = 0;
    one = 1;
    v1 = (u8 *) &buf->voices->usedChannels;
    for (; a2 != 0; a2--) {
        ((SeqVoice *) a3)->channelFlags = 0;
        *(s8 *) (v1 - 0x28) = (s8) a1;
        a1++;
        *(s8 *) (v1 - 0x7) = (s8) a0;
        *(s32 *) v1 = one << a0;
        v1 += 0x160;
        a3 += 0xB0;
        a0++;
    }
    SUZUKISetMus((s32 *) buf);
    return buf;
}

void SUZUKITransferMusicData(SeqSong *arg0) {
    u8 *s0 = (u8 *) arg0;
    u8 *v1;
    s32 a3;

    v1 = (u8 *) arg0->parent;
    arg0->flags |= 1;
    arg0->unk12 = *(u16 *) (v1 + 0x10);
    arg0->voiceCount = *(u8 *) (v1 + 0x12);
    arg0->unk15 = *(u8 *) (v1 + 0x13);
    arg0->trackCount = *(u8 *) (v1 + 0x14);
    arg0->unk17 = *(u8 *) (v1 + 0x15);
    arg0->soundfontId = *(u16 *) (v1 + 0x16);
    arg0->noiseClock = *(u16 *) (v1 + 0x18);
    arg0->reverbMode = *(s8 *) (v1 + 0x1A);
    arg0->volumeDepth = *(u8 *) (v1 + 0x1B) << 8;
    arg0->reverbDelay = *(u8 *) (v1 + 0x1C);
    a3 = *(u8 *) (v1 + 0x1D);
    arg0->reverbFeedback = a3;
    SUZUKISetSPUReverbMode(arg0->reverbMode, arg0->volumeDepth, arg0->reverbDelay, a3);
    SUZUKIInitializeMusHeader(s0);
}

void func_80013788(SeqSong *arg0) {
    SeqSong *p = arg0;

    p->flags = 2;
    p->unk12 = 0x7FFF;
    p->voiceCount = 1;
    p->unk15 = 1;
    p->trackCount = 8;
    p->unk17 = 0;
    p->soundfontId = 0;
    p->noiseClock = 0x7F;
    SUZUKIInitializeMusHeader();
}

void SUZUKIInitializeMusHeader(SeqSong *arg0) {
    SeqSong *p = arg0;

    SUZUKIRemoveMUSFromQueueForwards();
    p->unk1C = 0;
    p->unk1D = 0;
    p->unk30 = 0;
    p->currentMeasure = 1;
    p->currentBeat = 0;
    p->framesUntilNextBeat = 1;
    p->unk28 = 0;
    p->unk24 = 0;
    p->unk20 = 0;
    p->ownedChannels = 0;
    p->modifiedChannels = 0;
    p->unk64 = 0;
    p->lfoVoiceFlags = 0;
    p->noiseVoiceFlags = 0;
    p->reverbVoiceFlags = 0;
    p->customVolume1 = 0;
    p->customVolume2 = 0;
    p->unk90 = 0;
    p->unk9C = 0;
    p->unkA8 = 0;
    p->unkB4 = 0;
    p->unk80 = 0;
    p->unk84 = 0;
    p->tsTop = 4;
    p->tsBottom = 4;
    p->unk3E = 4;
    p->tempoScalar = 0x01000000;
    p->customVolume0 = 0x7F000000;
    p->rawTempo = 0x660000;
    p->modifiedTempo = 0x6600;
    p->unk74 = 0x10000;
    p->tsTopFrames = 0x30 / p->unk15;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_800138AC);

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_80013B20);

void SUZUKIRemoveMUSFromQueueForwards(void **arg0) {
    void **var_a0;
    void **temp_s0;
    register void **keep asm("s0") = arg0;

    var_a0 = keep[1];
    if (var_a0 != NULL) {
        keep[1] = NULL;
        do {
            temp_s0 = var_a0[1];
            func_80014358(var_a0);
            var_a0 = temp_s0;
        } while (temp_s0 != NULL);
    }
}

void func_80013FC0(SeqSong *arg0, int arg1) {
    u8 *p = (u8 *) arg0;
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = *(s32 *) (p + 0);
    temp_s2 = *(s32 *) (p + 4);
    func_8001442C(arg0, (void *) arg1, (arg0->trackCount * 0x160) + 0xB8);
    *(s32 *) (p + 0) = temp_s1;
    *(s32 *) (p + 4) = temp_s2;
}

extern void *D_800329F8;
extern void *D_800329FC;
extern s32 D_80032A38;
extern s32 D_80032A64;

void SUZUKISetMus(s32 *arg0) {
    s32 temp;
    void *a;

    func_80021FC4(SUZUKIRootCounter2EvCB);
    a = SUZUKIRootCounter2EvCB;
    temp = D_80032A50;
    D_80032A50 = (s32) arg0;
    *arg0 = temp;
    func_80021FB4(a);
}

s32 SUZUKIRemoveMUSFromQueue(SeqSong *arg0) {
    SeqSong *s1;
    SeqSong *s0;
    SeqSong *v0;
    s16 temp;
    s16 v1copy;

    v0 = (SeqSong *) D_80032A50;
    s0 = arg0;
    s1 = 0;
    if (v0 == 0) {
        return -1;
    }
loop:
    if (v0 == s0) {
        goto check;
    }
    s1 = v0;
    KEEP_NOVOL(s1);
    v0 = s1->next;
    if (v0 != 0) {
        goto loop;
    }
check:
    if (v0 == 0) {
        return -1;
    }
    temp = *(s16 *) &s0->flags;
    v1copy = temp;
    if ((temp & 0x8000) != 0 && s0 != 0) {
        s0->flags = v1copy & 0x7FFF;
        D_80032A08 |= SUZUKIGetActiveChannels(s0);
    }
    if (s1 != 0) {
        s1->next = s0->next;
    } else {
        KEEP_NOVOL(s0);
        D_80032A50 = (s32) s0->next;
    }
    return 0;
}

void func_80014148(s32 arg0, u8 *arg1) {
    u16 *v1 = (u16 *) (arg1 + 0xB8);
    u32 a1 = arg1[0x16];
    do {
        a1 -= 1;
        if (*v1 != 0) {
            *v1 = arg0 | *v1;
        }
        v1 = (u16 *) ((u8 *) v1 + 0x160);
    } while (a1 != 0);
}

extern u32 D_80032A44;

void func_80014180(u8 *arg0, s32 arg1) {
    InstrumentEntry *ie;
    arg1 = ((arg1 << 16) >> 12) + 0x30;
    ie = (InstrumentEntry *) (arg1 + D_80032A44);
    *(u32 *) (arg0 + 0x1C) = ie->unk00;
    *(u32 *) (arg0 + 0x24) = ie->unk0D;
    *(u32 *) (arg0 + 0x28) = ie->unk0E;
    *(u32 *) (arg0 + 0x2C) = ie->unk0F;
    *(u16 *) (arg0 + 0x30) = ie->unk08;
    *(u16 *) (arg0 + 0x32) = ie->unk09;
    *(u16 *) (arg0 + 0x34) = ie->unk0A;
    *(u16 *) (arg0 + 0x36) = ie->unk0B;
    *(u16 *) (arg0 + 0x38) = ie->unk0C;
}

s32 func_80014204(void) {
    return 0;
}

s32 func_8001420C(u8 *arg0) {
    u32 *a1 = (u32 *) (arg0 + 8);
    s32 sum = 0;
    u32 n = ((u32) (*(u32 *) (arg0 + 8)) - 8) >> 2;
    s32 v0;
    do {
        v0 = *a1;
        a1 += 1;
        n -= 1;
        sum += v0;
    } while (n != 0);
    return sum;
}

void SetGlobalMusicVariables(void *arg0, s32 arg1) {
    u8 *p = arg0;
    s32 size = arg1 & ~0xF;

    __asm__("sw %0, %%gp_rel(D_80032A64)($gp)" : : "r"(p + size) : "memory");
    *(u16 *) (p + 0) = 0x8000;
    {
        s32 tail;
        __asm__ volatile("addiu %0, %1, 0x10" : "=r"(tail) : "r"(p));
        __asm__("sw %0, %%gp_rel(D_800329F8)($gp)" : : "r"(p) : "memory");
        __asm__("sw %0, %%gp_rel(D_80032A38)($gp)" : : "r"(size) : "memory");
        __asm__("sw %0, %%gp_rel(D_800329FC)($gp)" : : "r"(p) : "memory");
        *(u16 *) (p + 2) = 0;
        *(s32 *) (p + 4) = 0;
        *(s32 *) (p + 8) = tail;
        *(s32 *) (p + 0xC) = 0;
    }
}

s32 FindSpaceForSMDToMUS(s32 arg0) {
    u8 *head;
    u8 *temp_v1;
    s32 t;
    s32 mask;
    u32 size;
    s32 temp_s0;
    u8 *temp_v0;

    t = arg0 + 0xF;
    mask = -0x10;
    __asm__("lw %0, %%gp_rel(D_800329FC)($gp)" : "=r"(head) : "r"(mask));
    t &= mask;
    size = t + 0x10;
    if (*(s32 *) (head + 0xC) != 0) {
loop_1:
        temp_v1 = *(u8 **) (head + 0xC);
        if ((u32) (temp_v1 - *(u8 **) (head + 8)) < size) {
            head = temp_v1;
            if (*(s32 *) (temp_v1 + 0xC) == 0) {
                goto block_3;
            }
            goto loop_1;
        }
        goto block_4;
    }
block_3: {
    register u32 end asm("v1");
    register u8 *n8 asm("v0");
    __asm__ volatile("lw %0, %%gp_rel(D_80032A64)($gp)" : "=r"(end));
    n8 = *(u8 **) (head + 8);
    if ((u32) (end - (u32) n8) >= size) {
block_4:
        temp_v0 = (u8 *) ((*(s32 *) (head + 8) + 0xF) & ~0xF);
        temp_s0 = (s32) temp_v0 + 0x10;
        *(s32 *) (temp_v0 + 8) = temp_s0 + arg0;
        *(s32 *) (temp_v0 + 0xC) = 0;
        *(s32 *) (temp_v0 + 4) = 0;
        *(u16 *) (temp_v0 + 0) = 2;
        *(u16 *) (temp_v0 + 2) = 0;
        *(s32 *) (temp_v0 + 0xC) = *(s32 *) (head + 0xC);
        *(s32 *) (head + 0xC) = (s32) temp_v0;
        func_800144D0((s32 *) temp_s0, arg0);
        return temp_s0;
    }
}
    return 0;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_80014358);

void func_8001442C(void *arg0, void *arg1, s32 arg2) {
    u32 *t2 = arg0;
    u32 *t0 = arg1;
    register u32 *t3 asm("t3");
    register u32 *t1 asm("t1");
    s32 a3;
    u32 v1;
    u32 a0;
    u32 a1;
    u32 v0;

    a3 = arg2 >> 4;
    if (a3 != 0) {
        t3 = t2 + 3;
        t1 = t0 + 3;
        do {
            v1 = t1[-2];
            a0 = t1[-1];
            a1 = t1[0];
            t1 += 4;
            v0 = *t0;
            t0 += 4;
            a3--;
            *t2 = v0;
            t3[-2] = v1;
            t3[-1] = a0;
            t3[0] = a1;
            t3 += 4;
            t2 += 4;
        } while (a3 != 0);
    }
    a3 = (arg2 >> 2) & 3;
    if (a3 != 0) {
        do {
            *t2 = *t0;
            t0++;
            a3--;
            t2++;
        } while (a3 != 0);
    }
    a3 = arg2 & 3;
    if (a3 != 0) {
        do {
            *(u8 *) t2 = *(u8 *) t0;
            t0 = (u32 *) ((u8 *) t0 + 1);
            a3--;
            t2 = (u32 *) ((u8 *) t2 + 1);
        } while (a3 != 0);
    }
}

void func_800144D0(s32 *arg0, s32 arg1) {
    int v0;
    s32 *p = arg0;
    register s32 *v1 asm("v1");
    v0 = arg1 >> 4;
    if (v0 != 0) {
        v1 = p + 1;
        do {
            v1[2] = 0;
            v1[1] = 0;
            v1[0] = 0;
            v1 += 4;
            *p = 0;
            p += 4;
        } while (--v0 != 0);
    }
    v0 = (arg1 >> 2) & 3;
    if (v0 != 0) {
        do {
            *p = 0;
            v0--;
            p++;
        } while (v0 != 0);
    }
    v0 = arg1 & 3;
    if (v0 != 0) {
        do {
            *(u8 *) p = 0;
            v0--;
            p = (s32 *) ((u8 *) p + 1);
        } while (v0 != 0);
    }
}

void func_80014544(void) {
}

void func_80019518(void);

s32 SpuMallocWithExtraSteps(s32 arg0) {
    func_80019518();
}

extern void SpuFree();

s32 SpuFreeWithExtraSteps(void) {
    SpuFree();
    return 0;
}

extern u16 D_80032A4C;
extern void func_8001B428();
extern void func_8001B4B0();
extern void func_8001B628();
extern void func_8001B6A4();
extern void func_8001B720();
extern void func_8001B938();
extern void func_8001B79C();
extern void func_8001B9D4();
extern void func_8001BAB8();
extern void func_8001B8B0();

void CalculateMusicVoiceChannelSettings(void) {
    s32 sp18;
    register u8 *s0 asm("s0");
    u8 *s7;
    u8 *s6;
    s16 h;
    s32 fp;
    u16 s1;
    s32 s2;
    s32 s3;
    s32 s4;
    s32 s5;

    s6 = (u8 *) D_80032A50;
    if (s6 == 0) {
        return;
    }
    do {
        h = *(s16 *) (s6 + 0x10);
        if (((h & 0xC000) != 0) && ((h & 0x20) == 0)) {
            *(s16 *) (s6 + 0x10) = h & 0xBFFF;
            fp = *(u8 *) (s6 + 0x16);
            s7 = s6 + 0xB8;
            if ((h & 2) != 0) {
                sp18 = -1;
            } else {
                sp18 = ~(D_80032A0C | D_80032A20);
            }
            s0 = s7 + 4;
            do {
                if (((*(u16 *) s7 & 1) != 0) && ((sp18 & *(s32 *) (s0 + 0x30)) != 0)) {
                    s1 = *(u16 *) s0;
                    if (s1 != 0) {
                        s2 = *(u8 *) (s0 + 0x29);
                        if ((s1 & 2) != 0) {
                            func_8001B4B0(s2, *(s16 *) (s0 + 0x38), *(s16 *) (s0 + 0x3A), *(s16 *) (s0 + 0x3C), *(s16 *) (s0 + 0x3E));
                            s1 &= 0xFFFE;
                        }
                        if ((s1 & 1) != 0) {
                            func_8001B428(s2, *(s16 *) (s0 + 0x38), *(s16 *) (s0 + 0x3A));
                        }
                        if ((s1 & 4) != 0) {
                            func_8001B628(s2, *(u16 *) (s0 + 0x44));
                        }
                        if ((s1 & 8) != 0) {
                            func_8001B6A4(s2, *(s32 *) (s0 + 0x4C));
                            func_8001B720(s2, *(s32 *) (s0 + 0x50));
                        }
                        if ((s1 & 0x10) != 0) {
                            func_8001B938(s2, *(u16 *) (s0 + 0x60), *(s32 *) (s0 + 0x54));
                        }
                        if ((s1 & 0x20) != 0) {
                            func_8001B79C(s2, *(u16 *) (s0 + 0x62));
                        }
                        if ((s1 & 0x40) != 0) {
                            func_8001B9D4(s2, *(u16 *) (s0 + 0x64), *(s32 *) (s0 + 0x58));
                        }
                        if ((s1 & 0x80) != 0) {
                            func_8001BAB8(s2, *(u16 *) (s0 + 0x66), *(s32 *) (s0 + 0x5C));
                        }
                        if ((s1 & 0x100) != 0) {
                            func_8001B8B0(s2, *(u16 *) (s0 + 0x68));
                        }
                        if ((s1 & 4) != 0) {
                            D_80032A4C |= 1;
                        }
                        if ((s1 & 0x10) != 0) {
                            D_80032A4C |= 2;
                        }
                        if ((s1 & 0x40) != 0) {
                            D_80032A4C |= 4;
                        }
                        *(u16 *) s0 = 0;
                    }
                }
                s0 += 0x160;
                fp -= 1;
                s7 += 0x160;
            } while (fp != 0);
        }
        s6 = *(u8 **) s6;
    } while (s6 != 0);
}

extern void func_8001ACF0(s32, s32);

void func_80014818(void) {
    s32 acc;
    s32 mask;
    register s32 h2 asm("v1");
    register s32 f asm("v0");
    s32 r1;
    s32 q0;
    SeqSong *a0;
    s32 h;
    s32 unused[2];

    a0 = (SeqSong *) D_80032A50;
    acc = 0;
    q0 = D_80032A0C;
    r1 = D_80032A20;
    q0 |= r1;
    mask = ~q0;
    if (a0 != NULL) {
        do {
            h = *(s16 *) &a0->flags;
            h2 = h;
            if (h < 0) {
                f = h2 & 2;
                if (f != 0)
                    acc |= a0->modifiedChannels;
                else
                    acc |= mask & a0->modifiedChannels;
                a0->modifiedChannels = 0;
            }
            a0 = a0->next;
        } while (a0 != NULL);
    }
    if (acc != 0)
        func_8001ACF0(1U, acc);
}

extern void SpuSetVoiceRRAttr(s32, s32, s32);

void func_800148B4(void) {
    s32 s0;
    s32 s1;
    register s32 s2 asm("s2");
    s32 s3;
    SeqSong *a1b;
    s32 a2b;
    s32 h;
    s32 unused[2];
    register s32 h2 asm("v1");
    register s32 r1 asm("v1");
    register s32 r0a asm("a0");
    register s32 f asm("v0");
    s32 q0;

    q0 = D_80032A0C;
    r0a = D_80032A20;
    a1b = (SeqSong *) D_80032A50;
    r1 = D_80032A08;
    q0 |= r0a;
    a2b = ~q0;
    r1 = a2b & r1;
    s1 = r1 | r0a;
    if (a1b == NULL)
        goto bitloop;
loop2:
    h = *(s16 *) &a1b->flags;
    h2 = h;
    if (h < 0) {
        f = h2 & 2;
        if (f != 0)
            s1 |= a1b->unk64;
        else
            s1 |= a2b & a1b->unk64;
        a1b->unk64 = 0;
    }
    a1b = a1b->next;
    if (a1b != NULL)
        goto loop2;
bitloop:
    f = D_80032A08;
    r1 = D_80032A20;
    f = a2b & f;
    s2 = f | r1;
    if (s2 == 0)
        goto done;
    s0 = 0x17U;
    s3 = 1U;
    do {
        if ((s2 & (s3 << s0)) != 0)
            SpuSetVoiceRRAttr(s0, 6U, 3U);
        s0 -= 1;
    } while (s0 >= 0);
    D_80032A20 = 0;
    D_80032A08 = 0;
done:
    if (s1 != 0)
        func_8001ACF0(0, s1);
}

extern void CalculateMusicVoiceChannelSettings(void);
extern void CalculateMusicSPitchLFOVoices(void);
extern void CalculateMusicSNoiseVoices(void);
extern void CalculateMusicSReverbVoices3(void);
extern void func_80014F18();
extern void func_8001B094(void *);
extern void func_80013480(SeqSong *);
extern void func_80015138(void *, void *, s32);
extern void func_80015324();
extern void func_8001749C(void *, void *, s32);
extern void func_80017118();
extern u32 D_80032A2C;
extern int SUZUKISpuCommonAttr;
extern short D_80037048;
extern short D_8003704A;
extern short D_80037058;
extern short D_80037064;

s32 SUZUKIRootCounter2Func(void) {
    s32 cur;
    s32 count;
    register s32 keys asm("s1");
    s32 voices;
    s32 bits;
    s32 bit;
    SeqSong *song;
    s32 keyOn;
    s32 keyMask;
    s32 vol;
    u8 *walk;
    s32 invPend;
    s32 flags;
    register s32 flags2 asm("v1");
    register s32 acc asm("v1");
    s32 phase;
    s32 rate;
    s32 span;
    register s32 act asm("a0");
    register s32 flag asm("v0");
    register s32 tick asm("v0");
    u32 limit;
    u16 rep;
    u16 beat;
    u8 *ptr;
    s32 parity;
    s32 unused[4];

    s32 pend;
    CalculateMusicVoiceChannelSettings();
    cur = D_80032A4C;
    flag = cur & 1;
    if (flag != 0)
        CalculateMusicSPitchLFOVoices();
    flag = cur & 2;
    if (flag != 0)
        CalculateMusicSNoiseVoices();
    flag = cur & 4;
    if (flag != 0)
        CalculateMusicSReverbVoices3();
    song = (SeqSong *) D_80032A50;
    keyOn = 0;
    D_80032A4C = 0;
    pend = D_80032A0C;
    acc = D_80032A20;
    pend |= acc;
    keyMask = ~pend;
    if (song != NULL) {
        do {
            flags = *(s16 *) &song->flags;
            flags2 = flags;
            if (flags < 0) {
                flag = flags2 & 2;
                if (flag != 0)
                    keyOn |= song->modifiedChannels;
                else
                    keyOn |= keyMask & song->modifiedChannels;
                song->modifiedChannels = 0;
            }
            song = song->next;
        } while (song != NULL);
    }
    if (keyOn != 0)
        func_8001ACF0(1, keyOn);
    parity = D_80032A2C & 1;
    D_80032A2C += 1;
    if (parity == 0)
        goto mainwalk;
    cur = (s32) &D_80037058;
    KEEP(cur);
    if (*(s16 *) cur != 0) {
        func_80014F18((void *) (cur - 8));
        ptr = (u8 *) (cur - 0x34);
        vol = *(s16 *) (cur - 6);
        D_80037048 = vol;
        SetVolBalance(vol, (s16 *) ptr, 0);
        SUZUKISpuCommonAttr |= 3;
    }
    if (D_80037064 != 0) {
        func_80014F18((void *) (cur + 4));
        ptr = (u8 *) (cur - 0x28);
        vol = *(s16 *) (cur + 6);
        D_8003704A = vol;
        SetVolBalance(vol, (s16 *) ptr, 0);
        SUZUKISpuCommonAttr |= 0xC0;
    }
    vol = cur - 0x38;
    flag = *(s32 *) (cur - 0x38);
    if (flag != 0) {
        func_8001B094((void *) vol);
        *(s32 *) (cur - 0x38) = 0;
    }
mainwalk:
    cur = D_80032A50;
    if (cur == 0)
        goto tail;
    do {
        flags = *(s16 *) (cur + 0x10);
        if (flags < 0) {
            limit = *(u32 *) (cur + 0x2C);
            if (limit != 0 && *(u32 *) (cur + 0x24) >= limit)
                func_80013480((SeqSong *) cur);
            if (*(s16 *) (cur + 0x90) != 0) {
                func_80014F18((void *) (cur + 0x88));
                *(s32 *) (cur + 0x78) = (s32) (*(s16 *) (cur + 0x7E) * *(s16 *) (cur + 0x8A));
            }
            if (*(s16 *) (cur + 0x9C) != 0) {
                func_80014F18((void *) (cur + 0x94));
                SUZUKISetNoteflags2AllChannels(0x100, (SeqSong *) cur);
            }
            if (*(s16 *) (cur + 0xA8) != 0) {
                func_80014F18((void *) (cur + 0xA0));
                SUZUKISetNoteflags2AllChannels(0x200, (SeqSong *) cur);
            }
            if (*(s16 *) (cur + 0xB4) != 0) {
                func_80014F18((void *) (cur + 0xAC));
                SUZUKISetNoteflags2AllChannels(0x100, (SeqSong *) cur);
            }
            tick = *(s32 *) (cur + 0x20);
            phase = *(s16 *) (cur + 0x8A);
            rate = *(s32 *) (cur + 0x28);
            span = *(s32 *) (cur + 0x78);
            tick += 1;
            *(s32 *) (cur + 0x20) = tick;
            flag = *(s32 *) (cur + 0x74);
            phase += rate;
            *(s32 *) (cur + 0x28) = phase;
            flag -= span;
            *(s32 *) (cur + 0x74) = flag;
            if (flag < 0) {
                voices = cur + 0xB8;
inner:
                rep = *(u16 *) (cur + 0x36) - 1;
                *(u16 *) (cur + 0x36) = rep;
                *(s32 *) (cur + 0x74) = *(s32 *) (cur + 0x74) + 0x10000;
                if ((rep & 0xFFFF) == 0) {
                    *(u16 *) (cur + 0x36) = *(u16 *) (cur + 0x3A);
                    beat = *(u16 *) (cur + 0x34) + 1;
                    *(u16 *) (cur + 0x34) = beat;
                    if (*(u16 *) (cur + 0x38) < (u32) (beat & 0xFFFF)) {
                        *(u16 *) (cur + 0x34) = 1;
                        *(u16 *) (cur + 0x32) = *(u16 *) (cur + 0x32) + 1;
                    }
                }
                count = *(u8 *) (cur + 0x16);
                if (count != 0) {
                    func_80015138((void *) cur, (void *) voices, count);
                    func_80015324((void *) cur, (void *) voices, count);
                    func_8001749C((void *) cur, (void *) voices, count);
                    func_80017118((void *) cur, (void *) voices, count);
                }
                if (*(s32 *) (cur + 0x58) != 0) {
                    *(u32 *) (cur + 0x24) = *(u32 *) (cur + 0x24) + 1;
                    if (*(s32 *) (cur + 0x94) == 0) {
                        SUZUKIDeallocateMUSChannels((SeqSong *) cur);
                        *(s16 *) (cur + 0x10) = *(s16 *) (cur + 0x10) | 0x4100;
                    }
                    if (*(u16 *) (cur + 0x32) == *(u16 *) (cur + 0x54))
                        SUZUKIDeallocateMUSChannels((SeqSong *) cur);
                    goto test74;
                } else {
                    *(s16 *) (cur + 0x10) = *(s16 *) (cur + 0x10) & 0x7FFF;
                    goto nextnode;
                }
test74:
                SCHED_BARRIER();
                if (*(s32 *) (cur + 0x74) < 0)
                    goto inner;
nextnode:;
            }
        }
        cur = *(s32 *) cur;
    } while (cur != 0);
tail:
    pend = D_80032A0C;
    act = D_80032A20;
    walk = (u8 *) D_80032A50;
    acc = D_80032A08;
    pend |= act;
    invPend = ~pend;
    acc = invPend & acc;
    keys = acc | act;
    if (walk == NULL)
        goto bitloop;
loop2:
    flags = *(s16 *) (walk + 0x10);
    flags2 = flags;
    if (flags < 0) {
        flag = flags2 & 2;
        if (flag != 0)
            keys |= *(s32 *) (walk + 0x64);
        else
            keys |= invPend & *(s32 *) (walk + 0x64);
        *(s32 *) (walk + 0x64) = 0;
    }
    walk = *(u8 **) walk;
    if (walk != NULL)
        goto loop2;
bitloop:
    flag = D_80032A08;
    acc = D_80032A20;
    flag = invPend & flag;
    bits = flag | acc;
    if (bits == 0)
        goto done;
    cur = 0x17;
    bit = 1;
    do {
        if ((bits & (bit << cur)) != 0)
            SpuSetVoiceRRAttr(cur, 6, 3);
        cur -= 1;
    } while (cur >= 0);
    D_80032A20 = 0;
    D_80032A08 = 0;
done:
    if (keys != 0)
        func_8001ACF0(0, keys);
    return 0;
}

struct func_80014F18_struct {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    s16 unkA;
};

void func_80014F18(struct func_80014F18_struct *arg0) {
    u16 temp_v0;

    temp_v0 = arg0->unk8 - 1;
    arg0->unk8 = temp_v0;
    if ((temp_v0 << 0x10) != 0) {
        arg0->unk0 += arg0->unk4;
    } else {
        arg0->unk0 = arg0->unkA << 0x10;
    }
}

void CalculateMusicSPitchLFOVoices(void) {
    SeqSong *song;
    s32 t;
    s32 a1 = 0;
    s32 s0 = 0;

    song = (SeqSong *) D_80032A50;
    if (song != NULL) {
        do {
            t = *(s16 *) &song->flags;
            if (t < 0) {
                if (t & 1) {
                    s0 |= song->lfoVoiceFlags;
                } else {
                    a1 |= song->lfoVoiceFlags;
                }
            }
            song = song->next;
        } while (song != NULL);
    }
    s0 = (s0 & ~D_80032A0C) | a1;
    SPUSetPitchLFOVoice(1, s0);
    SPUSetPitchLFOVoice(0, ~s0);
}

void CalculateMusicSNoiseVoices(void) {
    SeqSong *song;
    s32 t;
    s32 a1 = 0;
    s32 s0 = 0;

    song = (SeqSong *) D_80032A50;
    if (song != NULL) {
        do {
            t = *(s16 *) &song->flags;
            if (t < 0) {
                if (t & 1) {
                    s0 |= song->noiseVoiceFlags;
                } else {
                    a1 |= song->noiseVoiceFlags;
                }
            }
            song = song->next;
        } while (song != NULL);
    }
    s0 = (s0 & ~D_80032A0C) | a1;
    SPUSetNoiseVoice(1, s0);
    SPUSetNoiseVoice(0, ~s0);
}

void CalculateMusicSReverbVoices3(void) {
    SeqSong *song;
    s32 t;
    s32 a1 = 0;
    s32 s0 = 0;

    song = (SeqSong *) D_80032A50;
    if (song != NULL) {
        do {
            t = *(s16 *) &song->flags;
            if (t < 0) {
                if (t & 1) {
                    s0 |= song->reverbVoiceFlags;
                } else {
                    a1 |= song->reverbVoiceFlags;
                }
            }
            song = song->next;
        } while (song != NULL);
    }
    s0 = (s0 & ~D_80032A0C) | a1;
    SPUSetReverbVoice(1, s0);
    SPUSetReverbVoice(0, ~s0);
}

void func_80015138(void *arg0, void *arg1, s32 arg2) {
    u32 a3;
    u16 t1;
    u16 t0;
    register u8 *a0 asm("a0");
    s32 t;
    u16 v02;
    u32 cFFFF;
    s32 t65;
    a3 = *(u16 *) (arg0 + 0x84);
    if (a3 != 0) {
        s32 x;
        register s32 y asm("v1");
        a3 -= 1;
        if ((a3 & 0xFFFF) != 0) {
            x = *(s32 *) (arg0 + 0x7C);
            y = *(s32 *) (arg0 + 0x80);
            t = x + y;
        } else {
            t = *(u16 *) (arg0 + 0x86) << 16;
        }
        *(s32 *) (arg0 + 0x7C) = t;
        *(u16 *) (arg0 + 0x84) = a3;
        *(s32 *) (arg0 + 0x78) = (s32) (*(s16 *) (arg0 + 0x7E) * *(s16 *) (arg0 + 0x8A));
    }
    cFFFF = 0xFFFF;
    a0 = arg1 + 6;
    do {
        t1 = *(u16 *) arg1;
        if (t1 != 0) {
            t0 = *(u16 *) (a0 - 4);
            a3 = *(u16 *) a0;
            if (*(s16 *) (a0 + 0x6E) != 0) {
                *(u16 *) (a0 + 0x82) = 0;
                *(u16 *) (a0 + 0x84) = 0;
                *(u16 *) (a0 + 0x86) = 0;
                if (a3 & 8) {
                    u16 nv = *(u16 *) (a0 + 0xA2) + cFFFF;
                    *(u16 *) (a0 + 0xA2) = nv;
                    t0 |= 0x100;
                    if ((nv & 0xFFFF) == 0) {
                        a3 &= 0xFFF7;
                    }
                    *(s32 *) (a0 + 0x92) = *(s32 *) (a0 + 0x92) + *(s32 *) (a0 + 0x9A);
                }
                if (a3 & 1) {
                    t0 |= 0x200;
                    if ((a3 & 2) == 0) {
                        u16 nv = *(u16 *) (a0 + 0xA0) + cFFFF;
                        *(u16 *) (a0 + 0xA0) = nv;
                        if ((nv & 0xFFFF) == 0) {
                            a3 &= 0xFFFE;
                        }
                    }
                    *(s32 *) (a0 + 0x7A) = *(s32 *) (a0 + 0x7A) + *(s32 *) (a0 + 0x96);
                }
                if (a3 & 0x10) {
                    u16 nv = *(u16 *) (a0 + 0xA4) + cFFFF;
                    *(u16 *) (a0 + 0xA4) = nv;
                    t0 |= 0x100;
                    if ((nv & 0xFFFF) == 0) {
                        a3 &= 0xFFEF;
                    }
                    *(u16 *) (a0 + 0x8C) = *(u16 *) (a0 + 0x8C) + *(u16 *) (a0 + 0x9E);
                }
                t65 = *(u16 *) (a0 + 0x6E) - 1;
                *(u16 *) (a0 + 0x6E) = t65;
                if ((s16) t65 == 1) {
                    if (t1 & 0x1000) {
                        *(u16 *) (a0 + 0x64) = 6;
                        *(u16 *) (a0 - 2) = *(u16 *) (a0 - 2) | 0x80;
                    }
                }
                v02 = t1 & 0x600;
                if (v02 == 0) {
                    u16 nv = *(u16 *) (a0 + 0x72) + cFFFF;
                    *(u16 *) (a0 + 0x72) = nv;
                    if ((nv & 0xFFFF) == 0) {
                        t0 |= 2;
                        *(u16 *) arg1 = *(u16 *) arg1 | 0x400;
                    }
                }
            }
            *(u16 *) (a0 - 4) = t0;
            *(u16 *) a0 = a3;
        }
        a0 += 0x160;
        t = arg2 - 1;
        arg2 = t;
        t <<= 16;
        arg1 += 0x160;
    } while (t != 0);
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_80015324);

void func_80015864(void) {
}

s32 SMDNoInstruction(s32 arg0) {
    return arg0;
}

u8 *Rest(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u16 tmp;
    register u16 v1 asm("v1");

    tmp = *arg0;
    v1 = arg2->midFlags;
    *(u16 *) &arg2->unk6E[6] = tmp;
    tmp = arg2->channelFlags;
    v1 |= 0x2;
    arg2->midFlags = v1;
    tmp |= 0x400;
    arg2->channelFlags = tmp;
    return arg0 + 1;
}

u8 *Fermata(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 *ret;

    tmp = *arg0;
    arg2->channelFlags |= 0x100;
    ret = arg0 + 1;
    *(u16 *) &arg2->unk6E[6] = tmp;
    return ret;
}

u8 *SMDNoInstruction2(u8 *arg0) {
    return arg0;
}

u8 *func_800158C0(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 x;
    u8 y;
    x = arg0[0];
    y = arg1[0x1D];
    arg0 += 1;
    if (x == y) {
        *(u32 *) &arg2[0x1C] = (u32) arg0;
        arg2[0x2B] = arg2[0x7E];
    }
    return arg0;
}

s32 SMDNoInstruction3(s32 arg0) {
    return arg0 + 3;
}

s32 SMDNoInstruction4(s32 arg0) {
    return arg0;
}

s32 EndBarLoop(s32 arg0, SeqSong *arg1, SeqVoice *arg2) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a3 = arg0;
    u16 x4;

    temp_v0 = *(s32 *) ((u8 *) arg2 + 0x1C);
    if (temp_v0 != 0) {
        var_a3 = temp_v0;
        *(u16 *) ((u8 *) arg2 + 0x28) = *(u16 *) ((u8 *) arg2 + 0x28) + 1;
        *(u16 *) ((u8 *) arg2 + 0x7E) = *(u8 *) ((u8 *) arg2 + 0x2B);
    } else {
        *(u16 *) ((u8 *) arg2 + 0x2) = *(u16 *) ((u8 *) arg2 + 0x2) & 0xFFFC;
        if (arg1->flags & 2) {
            D_80032A20 |= arg2->usedChannels;
            temp_a0 = ~arg2->usedChannels;
            arg1->lfoVoiceFlags = temp_a0 & arg1->lfoVoiceFlags;
            arg1->noiseVoiceFlags = temp_a0 & arg1->noiseVoiceFlags;
            arg1->reverbVoiceFlags = temp_a0 & arg1->reverbVoiceFlags;
            x4 = *(u16 *) ((u8 *) arg2 + 0x4);
            D_80032A0C &= temp_a0;
            *(u16 *) ((u8 *) arg2 + 0x4) = x4 | 0x54;
        } else {
            D_80032A08 |= arg2->usedChannels;
        }
        *(u16 *) ((u8 *) arg2 + 0x0) = 0;
        var_a3 -= 1;
    }
    return var_a3;
}

s32 func_800159DC(s32 arg0, s32 arg1, u8 *arg2) {
    *(u32 *) &arg2[0x1C] = (u32) arg0;
    arg2[0x2B] = arg2[0x7E];
    return arg0;
}

u8 *Octave(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->octave = *arg0 * 12;
    return arg0 + 1;
}

s32 RaiseOctave(s32 arg0, s32 arg1, SeqVoice *arg2) {
    arg2->octave += 0xC;
    return arg0;
}

s32 LowerOctave(s32 arg0, s32 arg1, SeqVoice *arg2) {
    arg2->octave -= 0xC;
    return arg0;
}

u8 *TimeSignature(u8 *arg0, SeqVoice *arg1) {
    s32 a2 = arg0[1];
    s32 v1 = a2 * arg1->unk0C[9];
    s32 v0 = 0xC0 / v1;
    s32 t = arg0[0];

    arg1->unk3A = v0;
    v0 = arg1->unk3A;
    arg1->unk3C = a2;
    arg1->unk38 = t;
    arg1->unk3E = t;
    *(u16 *) ((u8 *) &arg1->usedChannels + 2) = v0;
    return arg0 + 2;
}

u8 *func_80015A88(u8 *arg0, SeqVoice *arg1) {
    arg1->unk1C = arg0[0];
    return arg0 + 1;
}

u8 *func_80015A9C(u8 *arg0, SeqVoice *arg1) {
    arg1->unk1C += arg0[0];
    return arg0 + 1;
}

u8 *Repeat(u8 *arg0, s32 arg1, u8 *arg2) {
    int new_var;
    u8 *next;
    u16 i;
    u8 *e;
    u8 b;
    ((u16 *) arg2)[0x56] += 1;
    next = arg0;
    arg0++;
    arg0--;
    i = ((volatile u16 *) arg2)[0x56];
    b = next[0];
    next = next + 1;
    new_var = ((i * 3) << 2) + 0xB0;
    e = arg2 + new_var;
    e[0] = b + 0xFF;
    *(u32 *) &e[4] = (u32) next;
    e[2] = arg2[0x7E];
    return next;
}

s32 Coda(s32 a0, s32 a1, u8 *a2) {
    u16 count = *(u16 *) (a2 + 0xAC);
    u32 idx = count * 12 + 0xB0;
    u8 *slot = a2 + idx;
    u8 n = slot[0] - 1;
    slot[0] = n;
    if (n != 0xFF) {
        *(u32 *) (slot + 8) = a0;
        slot[3] = *(u8 *) (a2 + 0x7E);
        a0 = *(u32 *) (slot + 4);
        *(u16 *) (a2 + 0x7E) = slot[2];
    } else {
        *(u16 *) (a2 + 0xAC) = *(u16 *) (a2 + 0xAC) - 1;
    }
    return a0;
}

s32 ToCoda(s32 arg0, s32 arg1, u8 *arg2) {
    u16 count = *(u16 *) (arg2 + 0xAC);
    u32 idx = count * 12 + 0xB0;
    u8 *slot = arg2 + idx;
    if (slot[0] == 0) {
        arg0 = *(s32 *) (slot + 8);
        *(u16 *) (arg2 + 0x7E) = slot[3];
        *(u16 *) (arg2 + 0xAC) = *(u16 *) (arg2 + 0xAC) - 1;
    }
    return arg0;
}

u8 *SMDSoundEffect(u8 *arg0) {
    SUZUKIPlaySoundWithSettingsFindChannel(arg0[0] | (arg0[1] << 8), arg0[2], 0x40);
    return arg0 + 3;
}

u8 *func_80015BFC(u8 *arg0) {
    AccumulateChannelsToPause(arg0[0] | (arg0[1] << 8));
    return arg0 + 2;
}

extern void *D_80032A00;

u8 *PlayVFXSMD(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *node = D_80032A00;
    s32 id = *(s16 *) (arg2 + 0xA);
    u8 idx = arg0[2];
    s32 key = arg0[0] | (arg0[1] << 8);

    if (id != 0) {
loop_1:
        if (*(u16 *) (node + 0xA) != id) {
            node = *(u8 **) (node + 0x10);
            if (node == NULL) {
                return arg0;
            }
            goto loop_1;
        }
        goto compute;
    }
compute:
    arg0 = node + *(u16 *) (node + (idx + ((key << 16) >> 15)) * 2 + 0x14);
    return arg0 + 3;
}

u8 *Tempo(u8 *arg0, SeqVoice *arg1) {
    s32 tmp;
    s16 v;
    int new_var;
    s32 p;

    if (p) {
        tmp = arg0[0];
    } else {
        tmp = arg0[0];
    }
    v = arg1->unk8A;
    p = (tmp & 0xFF) * v;
    new_var = tmp & 0xFF;
    *(s32 *) &arg1->unk7C = new_var << 16;
    arg1->unk78 = p;
    return arg0 + 1;
}

u8 *Accelerando(s8 *arg0, u8 *arg1) {
    s32 pad;
    (void) &pad;
    *(s32 *) (arg1 + 0x7C) = (s32) ((*arg0 << 0x10) + *(s32 *) (arg1 + 0x7C));
    *(s32 *) (arg1 + 0x78) = 0;
    return arg0 + 1;
}

u8 *func_80015D04(u8 *arg0, u8 *arg1) {
    u8 v0;
    u8 a3;
    s32 t;
    register s32 a2t asm("a2");
    register s32 q asm("v0");
    v0 = arg0[1];
    a3 = arg0[0];
    *(u16 *) (arg1 + 0x86) = v0;
    t = (v0 << 0x10) - *(s32 *) (arg1 + 0x7C);
    a2t = a3;
    if ((a2t != 0) && (t != 0)) {
        *(s16 *) (arg1 + 0x84) = (s16) a3;
        q = t / a2t;
        *(s32 *) (arg1 + 0x80) = q;
    }
    return arg0 + 2;
}

u8 *func_80015D44(u8 *arg0, u8 *arg1) {
    u8 b = *arg0;
    arg0 += 1;
    *(s32 *) (arg1 + 0x94) = b << 0x18;
    SUZUKISetNoteflags2AllChannels(0x100, (SeqSong *) arg1);
    return arg0;
}

u8 *func_80015D84(u8 *arg0, u8 *arg1) {
    u8 *p;
    u8 b0;
    u8 b1;
    s32 t0;
    s32 v0;
    short new_var;
    p = arg0;
    b0 = p[0];
    b1 = p[1];
    t0 = b0 << 5;
    new_var = b0 << 5;
    v0 = (b1 << 0x18) - *(s32 *) (arg1 + 0x94);
    t0 = new_var;
    if ((t0 != 0) && (v0 != 0)) {
        *(s16 *) (arg1 + 0x9C) = (s16) new_var;
        *(s16 *) (arg1 + 0x9E) = (s16) (b1 << 8);
        *(s32 *) (arg1 + 0x98) = v0 / t0;
    }
    return p + 2;
}

u8 *func_80015DD0(u8 *arg0, s32 arg1, u8 *arg2) {
    *(u16 *) (arg2 + 0x7A) = *arg0;
    return arg0 + 1;
}

u8 *func_80015DE4(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *a1c = arg0;
    u8 v0;
    v0 = *a1c;
    *(arg2 + 0x2D) = v0;
    a1c += 1;
    if (v0 < 0x19U) {
        *(s32 *) (arg2 + 0x34) = 1 << *(arg2 + 0x2D);
        *(u16 *) (arg2 + 4) |= 0x1FF;
    } else {
        *(s32 *) (arg2 + 0x34) = 0;
        *(u16 *) (arg2 + 4) = 0;
    }
    return a1c;
}

u8 *Instrument(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 *s0 = arg0;
    u8 b;
    KEEP_NOVOL(s0);
    b = s0[0];
    s0++;
    SetInstrument(b, arg2);
    KEEP_NOVOL(s0);
    return s0;
}

u8 *func_80015E68(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 v1 = arg0[0];
    arg0++;
    if (v1) {
        arg2->unk76 = v1 + arg2->unk76;
    } else {
        arg2->unk76 = 0;
    }
    return arg0;
}

s32 SMDNoInstruction5(s32 arg0) {
    return arg0;
}

u8 *SMDNoInstruction6(u8 *arg0) {
    return arg0;
}

u8 *func_80015EA8(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u16 t;
    t = arg2->channelFlags;
    t |= 0x800;
    arg2->channelFlags = t;
    return arg0;
}

u8 *func_80015EC0(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u16 t;
    t = arg2->channelFlags;
    t &= ~0x800;
    arg2->channelFlags = t;
    return arg0;
}

u8 *SMDEnableLFO(u8 *arg0, SeqVoice *arg1, SeqVoice *arg2) {
    if (arg2->voiceId & 1) {
        *(s32 *) &arg1->sustainFlags |= arg2->usedChannels;
        arg2->unk04 |= 4;
    }
    return arg0;
}

s32 SMDDisableLFO(s32 arg0, SeqVoice *arg1, SeqVoice *arg2) {
    s32 r1;
    s32 r2;
    u16 tmp;

    r1 = arg2->usedChannels;
    r2 = *(s32 *) &arg1->sustainFlags;
    *(s32 *) &arg1->sustainFlags = ~r1 & r2;
    tmp = arg2->unk04;
    arg2->unk04 = tmp | 4;
    return arg0;
}

u8 *SMDEnableNoise(u8 *arg0, SeqVoice *arg1, SeqVoice *arg2) {
    register u8 *s1 asm("s1") = arg0;
    arg1->unk1E = (u16) *s1;
    func_80019D88(arg1->unk1E);
    *(s32 *) &arg1->sustainLevel |= arg2->usedChannels;
    __asm__("addiu %0, %0, 1" : "=r"(s1) : "0"(s1));
    arg2->unk04 |= 0x10;
    return s1;
}

u8 *SMDIncreaseNoise(u8 *arg0, SeqVoice *arg1, SeqVoice *arg2) {
    register u8 *s1 asm("s1") = arg0;
    arg1->unk1E = (s1[0] + arg1->unk1E) & 0x3F;
    func_80019D88(arg1->unk1E);
    *(s32 *) &arg1->sustainLevel |= arg2->usedChannels;
    __asm__("addiu %0, %0, 1" : "=r"(s1) : "0"(s1));
    arg2->unk04 |= 0x10;
    return s1;
}

s32 SMDTurnOnNoise(s32 arg0, SeqVoice *arg1, SeqVoice *arg2) {
    s32 r1;
    s32 r2;
    u16 tmp;

    r1 = *(s32 *) &arg1->sustainLevel;
    r2 = arg2->usedChannels;
    *(s32 *) &arg1->sustainLevel = r1 | r2;
    tmp = arg2->unk04;
    arg2->unk04 = tmp | 0x10;
    return arg0;
}

s32 SMDDisableNoise(s32 arg0, SeqVoice *arg1, SeqVoice *arg2) {
    s32 r1;
    s32 r2;
    u16 tmp;

    r1 = arg2->usedChannels;
    r2 = *(s32 *) &arg1->sustainLevel;
    *(s32 *) &arg1->sustainLevel = ~r1 & r2;
    tmp = arg2->unk04;
    arg2->unk04 = tmp | 0x10;
    return arg0;
}

u8 *Acoustics(u8 *arg0, SeqVoice *arg1) {
    register s32 a2 asm("a2");
    register s32 a3 asm("a3");
    u8 c = arg0[0];
    *(u16 *) &arg1->unk48 = c << 8;
    a2 = *(s8 *) (arg0 + 1);
    arg1->unk4C = a2;
    a3 = *(s8 *) (arg0 + 2);
    arg1->unk50 = a3;
    SUZUKISetSPUReverbMode(0xA, (c << 24) >> 16);
    return arg0 + 3;
}

s32 EnableReverb(s32 arg0, SeqVoice *arg1, SeqVoice *arg2) {
    s32 r1;
    s32 r2;
    u16 tmp;

    r1 = *(s32 *) &arg1->unk6E[2];
    r2 = arg2->usedChannels;
    *(s32 *) &arg1->unk6E[2] = r1 | r2;
    tmp = arg2->unk04;
    arg2->unk04 = tmp | 0x40;
    return arg0;
}

s32 DisableReverb(s32 arg0, SeqVoice *arg1, SeqVoice *arg2) {
    s32 r1;
    s32 r2;
    u16 tmp;

    r1 = arg2->usedChannels;
    r2 = *(s32 *) &arg1->unk6E[2];
    *(s32 *) &arg1->unk6E[2] = ~r1 & r2;
    tmp = arg2->unk04;
    arg2->unk04 = tmp | 0x40;
    return arg0;
}

extern void SetInstrument(s32, SeqVoice *);

u8 *Naturale(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 *s0;

    s0 = arg0;
    SetInstrument(arg2->currentInstrument, arg2);
    return s0;
}

u8 *EnvelopeShape(u8 *arg0, s32 arg1, s32 *arg2) {
    arg2[0x58 >> 2] = *(u8 *) arg0;
    arg2[0x5C >> 2] = *(u8 *) (arg0 + 1);
    arg2[0x60 >> 2] = *(u8 *) (arg0 + 2);
    ((u16 *) arg2)[2] |= 0x1F0;
    return arg0 + 3;
}

u8 *AttackTime(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 *ret;

    tmp = *arg0;
    arg2->unk04 |= 0x10;
    ret = arg0 + 1;
    arg2->attackShiftStep = tmp;
    return ret;
}

u8 *DecayTime(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 *ret;

    tmp = *arg0;
    arg2->unk04 |= 0x20;
    ret = arg0 + 1;
    arg2->decayShift = tmp;
    return ret;
}

u8 *Sustain(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp = *arg0;
    arg2->unk04 |= 0x40;
    arg2->sustainFlags = tmp;
    return arg0 + 1;
}

u8 *Release(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u16 tmp;
    u8 *ret;

    tmp = *arg0;
    arg2->unk04 |= 0x80;
    ret = arg0 + 1;
    arg2->unk2E = tmp;
    arg2->releaseFlags = tmp;
    return ret;
}

u8 *SustainLevel(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp = *arg0;
    arg2->unk04 |= 0x100;
    arg2->sustainLevel = tmp;
    return arg0 + 1;
}

u8 *EnvelopeTail(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u16 t;
    u8 tmp2;
    u16 new_var;
    new_var = arg2->unk04;
    tmp = arg0[0];
    arg2->decayShift = tmp;
    t = new_var;
    tmp2 = arg0[1];
    t |= 0x120;
    arg2->unk04 = t;
    arg2->sustainLevel = tmp2;
    return arg0 + 2;
}

u8 *AttackMode(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 *ret;

    tmp = *arg0;
    arg2->unk04 |= 0x10;
    ret = arg0 + 1;
    arg2->attackMode = tmp;
    return ret;
}

u8 *SustainMode(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp = *arg0;
    arg2->unk04 |= 0x40;
    arg2->sustainMode = tmp;
    return arg0 + 1;
}

u8 *ReleaseMode(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 *ret;

    tmp = *arg0;
    arg2->unk04 |= 0x80;
    ret = arg0 + 1;
    arg2->releaseMode = tmp;
    return ret;
}

u8 *func_800162B4(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u16 v;
    u16 t;

    tmp = *arg0;
    v = ((s32) (tmp << 24)) >> 19;
    t = arg2->midFlags;
    t |= 0x200;
    *(u16 *) arg2->unk86 = v;
    arg2->midFlags = t;
    return arg0 + 1;
}

u8 *func_800162D8(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u16 cur;
    u16 t;
    u16 new_var;

    tmp = arg0[0];
    new_var = *(u16 *) arg2->unk86;
    t = arg2->midFlags;
    cur = new_var;
    cur = cur + (((s32) (tmp << 24)) >> 19);
    *(u16 *) arg2->unk86 = cur;
    arg2->midFlags = t | 0x200;
    return arg0 + 1;
}

u8 *func_80016304(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u16 cur;
    u16 t;
    u16 new_var;

    tmp = arg0[0];
    new_var = *(u16 *) arg2->unk86;
    t = arg2->midFlags;
    cur = new_var;
    cur = cur + (((s32) (tmp << 24)) >> 21);
    *(u16 *) arg2->unk86 = cur;
    arg2->midFlags = t | 0x200;
    return arg0 + 1;
}

u8 *func_80016330(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    s32 tmp2;
    int new_var;
    SeqVoice *new_var3;
    u16 t;
    s32 v;
    u16 cur;
    u16 new_var2;

    new_var3 = arg2;
    t = new_var3->midFlags;
    tmp = arg0[0];
    tmp2 = arg0[1];
    new_var2 = t;
    v = 16;
    v = ((s32) (tmp << 24)) >> v;
    cur = *(u16 *) new_var3->unk86;
    tmp2 = tmp2 + v;
    cur = (*(u16 *) arg2->unk86 = cur + tmp2);
    arg2->midFlags = new_var2 | 0x200;
    new_var = 2;
    return arg0 + new_var;
}

u8 *func_80016364(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s32 a1;
    s32 v0;
    s8 b1;
    s32 a3;

    b1 = arg0[1];
    a3 = arg0[0];
    v0 = b1 << 24;
    a1 = a3 & 0xFFFF;
    if ((a1 != 0) && (v0 != 0)) {
        *(u16 *) &arg2->unkA4[2] = (u16) a3;
        arg2->unk06 |= 1;
        *(s32 *) arg2->unk9C = v0 / a1;
    } else {
        arg2->unk06 &= ~1;
    }
    return arg0 + 2;
}

u8 *func_800163BC(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->unk06 ^= 2;
    return arg0;
}

u8 *func_800163D4(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->unk06 &= ~1;
    return arg0;
}

u8 *func_800163EC(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u16 v;

    tmp = *arg0++;
    *(u16 *) &arg2->unk8C[4] = tmp;
    if (tmp != 0) {
        v = arg2->unk06 | 4;
    } else {
        v = arg2->unk06 & ~4;
    }
    arg2->unk06 = v;
    return arg0;
}

u8 *PitchShift(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s32 b0;
    s16 tmp;
    u8 v1;

    b0 = *(s8 *) &arg0[1];
    tmp = arg0[0];
    if (b0 == 0) {
        return arg0 + 3;
    }
    if (tmp != 0) {
        if (b0 < 0) {
            b0 = b0 * (-b0);
        } else {
            b0 *= b0;
        }
        arg2->env[0].unk0C = func_80016BF8(b0 << 14, tmp, 3);
        arg2->env[0].unk12 = tmp;
        v1 = arg0[2];
        arg2->env[0].unk1A = 0x100;
        arg2->env[0].unk00 = (u32) func_80017744;
        arg2->env[0].unk1D = 3;
        arg2->env[0].unk1C = 0;
        arg2->env[0].unk1E = 3;
        arg2->env[0].unk16 = v1;
        func_80016DC0((u16 *) &arg2->env[0]);
    }
    return arg0 + 3;
}

u8 *func_800164D4(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s32 b0;
    s16 tmp;
    u32 *new_var;
    u16 v1;
    s16 s0v;

    b0 = *(s8 *) &arg0[1];
    tmp = arg0[0];
    v1 = arg0[2];
    if (b0 == 0) {
        return arg0 + 3;
    }
    if (tmp != 0) {
        if (b0 < 0) {
            b0 = b0 * (-b0);
        } else {
            b0 *= b0;
        }
        s0v = v1 & 0x10;
        v1 &= 0xF;
        s0v = s0v == 0;
        new_var = (u32 *) &arg2->env[0];
        s0v <<= 1;
        arg2->env[0].unk0C = func_80016BF8(b0 << 14, tmp, v1);
        arg2->env[0].unk12 = tmp;
        arg2->env[0].unk1A = 0x100;
        arg2->env[0].unk16 = 0;
        *new_var = ((s32 *) D_80028F54)[v1];
        arg2->env[0].unk1D = v1;
        arg2->env[0].unk1C = 0;
        arg2->env[0].unk1E = s0v + 1;
        func_80016DC0((u16 *) &arg2->env[0]);
    }
    return arg0 + 3;
}

u8 *func_800165AC(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 v1;
    s32 v0;

    tmp = *arg0;
    v1 = (tmp + 1) & 0xFF;
    arg0++;
    if (v1 != 0) {
        v0 = 0x100 / v1;
        arg2->env[0].unk1A = v0;
        arg2->env[0].unk18 = v0;
    }
    return arg0;
}

u8 *func_800165E4(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->env[0].unk1E |= 1;
    return arg0;
}

u8 *func_800165FC(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->env[0].unk1E &= ~1;
    return arg0;
}

u8 *Dynamic(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u16 t;
    u16 t2;
    if (t2) {
        tmp = arg0[0];
        t = arg2->unk06;
        arg2->volumeLeft = tmp << 24;
    } else {
        tmp = arg0[0];
        t = arg2->unk06;
        arg2->volumeLeft = tmp << 24;
    }
    t2 = arg2->midFlags;
    t &= ~8;
    arg2->unk06 = t;
    t2 |= 0x100;
    arg2->midFlags = t2;
    return arg0 + 1;
}

u8 *Crescendo(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s8 tmp;
    u16 t;
    u16 t2;
    s32 w;
    s32 res;
    s32 mask;
    if (t2) {
        tmp = arg0[0];
        w = arg2->volumeLeft;
        res = (tmp << 24) + w;
        mask = 0x7FFFFFFF;
        res &= mask;
        arg2->volumeLeft = res;
    } else {
        tmp = arg0[0];
        w = arg2->volumeLeft;
        res = (tmp << 24) + w;
        mask = 0x7FFFFFFF;
        res &= mask;
        arg2->volumeLeft = res;
    }
    t = arg2->midFlags;
    t2 = arg2->unk06;
    t |= 0x100;
    t2 &= ~8;
    arg2->midFlags = t;
    arg2->unk06 = t2;
    return arg0 + 1;
}

u8 *FermataRamp(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s32 a1;
    s32 v0;
    s8 b1;
    s32 a3;
    s32 w;

    b1 = arg0[1];
    w = arg2->volumeLeft;
    a3 = arg0[0];
    v0 = (b1 << 24) - w;
    a1 = a3 & 0xFFFF;
    if ((a1 != 0) && (v0 != 0)) {
        *(u16 *) &arg2->unkA4[4] = (u16) a3;
        arg2->unk06 |= 8;
        *(s32 *) &arg2->volumeDelta = v0 / a1;
    }
    return arg0 + 2;
}

u8 *func_800166C8(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s8 b0;
    s32 tmp;
    register s32 a1v asm("a1");
    u8 v1;

    b0 = arg0[1];
    tmp = arg0[0];
    if (b0 != 0) {
        a1v = tmp;
        if (a1v != 0) {
            arg2->env[1].unk0C = func_80016BF8((-b0) << 24, a1v, 2);
            arg2->env[1].unk12 = tmp;
            v1 = arg0[2];
            arg2->env[1].unk1A = 0x100;
            arg2->env[1].unk00 = (u32) func_800176E4;
            arg2->env[1].unk1D = 2;
            arg2->env[1].unk1C = 1;
            arg2->env[1].unk1E = 3;
            arg2->env[1].unk16 = v1;
            func_80016DC0((u16 *) &arg2->env[1]);
        }
    }
    return arg0 + 3;
}

u8 *func_8001676C(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s8 b0;
    s32 tmp;
    register s32 a1v asm("a1");
    SeqVoice *s1d;
    u32 *new_var;
    u16 v1;
    s16 s0v;

    b0 = arg0[1];
    tmp = arg0[0];
    v1 = arg0[2];
    s1d = arg2;
    if (b0 != 0) {
        a1v = tmp;
        if (a1v != 0) {
            s0v = v1 & 0x10;
            v1 &= 0xF;
            s0v = s0v == 0;
            new_var = (u32 *) &s1d->env[1];
            s0v <<= 1;
            s1d->env[1].unk0C = func_80016BF8((-b0) << 24, a1v, v1);
            s1d->env[1].unk12 = tmp;
            s1d->env[1].unk1A = 0x100;
            s1d->env[1].unk16 = 0;
            *new_var = ((s32 *) D_80028F54)[v1];
            s1d->env[1].unk1D = v1;
            s1d->env[1].unk1C = 1;
            s1d->env[1].unk1E = s0v + 1;
            func_80016DC0((u16 *) &s1d->env[1]);
        }
    }
    return arg0 + 3;
}

u8 *func_80016834(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 v1;
    s32 v0;

    tmp = *arg0;
    v1 = (tmp + 1) & 0xFF;
    arg0++;
    if (v1 != 0) {
        v0 = 0x100 / v1;
        arg2->env[1].unk1A = v0;
        arg2->env[1].unk18 = v0;
    }
    return arg0;
}

u8 *func_8001686C(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->env[1].unk1E |= 1;
    return arg0;
}

u8 *func_80016884(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->env[1].unk1E &= ~1;
    return arg0;
}

u8 *Balance(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u16 tmp;
    u8 *ret;
    u16 shifted;

    shifted = (u16) (*arg0 << 8);
    tmp = arg2->midFlags;
    *(u16 *) &arg2->volumeBalance = shifted;
    ret = arg0 + 1;
    tmp |= 0x100;
    arg2->midFlags = tmp;
    return ret;
}

u8 *ShiftBalance(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u16 cur;
    u16 t;
    u16 new_var;

    tmp = arg0[0];
    new_var = *(u16 *) &arg2->volumeBalance;
    cur = new_var + (((s32) (tmp << 24)) >> 16);
    cur &= 0x7FFF;
    t = arg2->midFlags;
    *(u16 *) &arg2->volumeBalance = cur;
    arg2->midFlags = t | 0x100;
    return arg0 + 1;
}

u8 *func_800168EC(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s32 a1;
    s32 v0;
    s8 b1;
    s32 a3;
    u16 cur;

    cur = *(u16 *) &arg2->volumeBalance;
    b1 = arg0[1];
    a3 = arg0[0];
    v0 = b1 - (((s32) (cur << 16)) >> 24);
    a1 = a3 & 0xFFFF;
    if ((a1 != 0) && (v0 != 0)) {
        *(u16 *) &arg2->unkA4[6] = (u16) a3;
        arg2->unk06 |= 0x10;
        *(u16 *) &arg2->unkA4[0] = (v0 << 8) / a1;
    }
    return arg0 + 2;
}

u8 *func_8001693C(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 v1;
    s32 v0;

    tmp = *arg0;
    v1 = (tmp + 1) & 0xFF;
    arg0++;
    if (v1 != 0) {
        v0 = 0x100 / v1;
        arg2->env[2].unk1A = v0;
        arg2->env[2].unk18 = v0;
    }
    return arg0;
}

u8 *func_80016974(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    s8 b0;
    s32 tmp;
    register s32 a1v asm("a1");
    u8 v1;

    b0 = arg0[1];
    tmp = arg0[0];
    if (b0 != 0) {
        a1v = tmp;
        if (a1v != 0) {
            arg2->env[2].unk0C = func_80016BF8(b0 << 24, a1v, 3);
            arg2->env[2].unk12 = tmp;
            v1 = arg0[2];
            arg2->env[2].unk1A = 0x100;
            arg2->env[2].unk00 = (u32) func_80017744;
            arg2->env[2].unk1D = 3;
            arg2->env[2].unk1C = 2;
            arg2->env[2].unk1E = 3;
            arg2->env[2].unk16 = v1;
            func_80016DC0((u16 *) &arg2->env[2]);
        }
    }
    return arg0 + 3;
}

u8 *func_80016A14(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    register s32 b0 asm("a0");
    s32 b0t;
    s16 tmp;
    u32 *new_var;
    u16 v1;
    s16 s0v;
    SeqVoice *s1d;

    b0t = *(s8 *) &arg0[1];
    b0 = b0t;
    tmp = arg0[0];
    v1 = arg0[2];
    s1d = arg2;
    if (b0 == 0) {
        return arg0 + 3;
    }
    if (tmp != 0) {
        s0v = v1 & 0x10;
        v1 &= 0xF;
        s0v = s0v == 0;
        new_var = (u32 *) &s1d->env[2];
        s0v <<= 1;
        s1d->env[2].unk0C = func_80016BF8(b0 << 24, tmp, v1);
        s1d->env[2].unk12 = tmp;
        s1d->env[2].unk1A = 0x100;
        s1d->env[2].unk16 = 0;
        *new_var = ((s32 *) D_80028F54)[v1];
        s1d->env[2].unk1D = v1;
        s1d->env[2].unk1C = 2;
        s1d->env[2].unk1E = s0v + 1;
        func_80016DC0((u16 *) &s1d->env[2]);
    }
    return arg0 + 3;
}

u8 *func_80016AD8(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->env[2].unk1E |= 1;
    return arg0;
}

u8 *func_80016AF0(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    arg2->env[2].unk1E &= ~1;
    return arg0;
}

u8 *func_80016B08(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp0;
    s32 tmp1;
    u8 x;
    u16 ae;
    u8 *a2p;
    u8 *ret;
    s32 v0w;

    tmp0 = arg0[0];
    *(u16 *) &arg2->unkA4[0xA] = tmp0;
    ae = *(volatile u16 *) &arg2->unkA4[0xA];
    tmp1 = arg0[1];
    a2p = (u8 *) &arg2->env[ae];
    a2p[0x1D] = tmp1 & 0xF;
    x = *(volatile u8 *) (a2p + 0x1D);
    v0w = ((s32 *) D_80028F54)[x];
    tmp1 = tmp1 & 0x10;
    *(u32 *) a2p = v0w;
    if (tmp1 == 0) {
        *(u16 *) (a2p + 0x1E) = 2;
    } else {
        *(u16 *) (a2p + 0x1E) = 0;
    }
    tmp1 = arg0[2];
    *(u16 *) (a2p + 0x1A) = 0x100;
    ret = arg0 + 3;
    *(u16 *) (a2p + 0x16) = 0;
    a2p[0x1C] = tmp1;
    return ret;
}

u8 *func_80016B80(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 tmp;
    u8 a0v;
    s8 b0;
    u16 ae;
    u8 *s0;

    tmp = arg0[0];
    ae = *(u16 *) &arg2->unkA4[0xA];
    a0v = arg0[2];
    s0 = (u8 *) &arg2->env[ae];
    b0 = arg0[1];
    *(s32 *) (s0 + 0x0C) = func_80016BF8((b0 << 24) | (a0v << 16), tmp, s0[0x1D]);
    *(u16 *) (s0 + 0x12) = tmp;
    return arg0 + 3;
}

s32 func_80016BF8(s32 arg0, s16 arg1, s16 arg2) {
    if (arg0 != 0) {
        if (arg1 != 0) {
            if (arg2 >= 2) {
                switch (arg2) {
                case 2:
                case 3:
                    arg0 = arg0 / arg1;
                    break;
                case 4:
                    if (arg1 != 1) {
                        arg0 = arg0 / (arg1 - 1);
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
    return arg0;
}

u8 *func_80016C70(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 t1;
    u8 t0;
    u16 ae;
    s32 v0;
    u8 *b;
    t1 = arg0[1];
    ae = *(u16 *) &arg2->unkA4[0xA];
    t1 = (t1 + 1) & 0xFF;
    b = (u8 *) &arg2->env[ae];
    if (t1 != 0) {
        v0 = 0x100 / t1;
        t0 = arg0[0];
        *(u16 *) (b + 0x16) = t0;
        *(u16 *) (b + 0x1A) = v0;
        *(u16 *) (b + 0x18) = v0;
    }
    return arg0 + 2;
}

u8 *func_80016CB8(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 *s3;
    s32 s2;
    u8 s1;
    s32 m;
    u8 *s0;
    u16 v0;
    s3 = (u8 *) arg2 + 0xE0;
    s2 = 4;
    s1 = *arg0;
    arg0 += 1;
    m = -2;
    s0 = (u8 *) arg2 + 0xFE;
    do {
        if (s1 & 1) {
            func_80016DC0(s3);
            v0 = *(u16 *) s0 | 1;
        } else {
            v0 = *(u16 *) s0 & m;
        }
        *(u16 *) s0 = v0;
        s1 = s1 >> 1;
        s0 += 0x20;
        s2 -= 1;
        s3 += 0x20;
    } while (s2 != 0);
    return arg0;
}

u8 *func_80016D64(u8 *arg0, s32 arg1, SeqVoice *arg2) {
    u8 t;
    u8 *s0;
    t = *arg0;
    s0 = (u8 *) &arg2->env[t];
    func_80016DC0(s0);
    *(u16 *) (s0 + 0x1E) |= 1;
    arg0 += 1;
    KEEP(arg0);
    return arg0;
}

u8 *func_80016DC0(u16 *arg0, s32 arg1, u8 *arg2) {
    register u16 b asm("a1") = ((SeqSong *) arg0)->noiseClock;
    ((SeqSong *) arg0)->flags = 1;
    ((SeqSong *) arg0)->unk04 = 0;
    *(u16 *) &((SeqSong *) arg0)->unk1E &= 0xFFF3;
    *(u16 *) &((SeqSong *) arg0)->voiceCount = *(u16 *) &((SeqSong *) arg0)->trackCount;
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "jr $ra\n\t"
        "sh %0, 0x18($a0)\n\t"
        ".set\treorder" : : "r"(b));
    *(u16 *) (arg2 + ((u8) arg0[0] << 5) + 0xFE) &= 0xFFFE;
    return (u8 *) arg0 + 1;
}

typedef struct {
    char pad78[0x78];
    s32 unk78;
    char pad7E[0x2];
    s16 unk7E;
    char pad88[0x8];
    s32 unk88;
} ScaleTempoTrack;

void *ScaleTempo(u8 *arg0, ScaleTempoTrack *arg1) {
    u8 *ret = arg0 + 1;
    u8 temp_a2;

    temp_a2 = *arg0;
    if (temp_a2 != 0) {
        arg1->unk88 = (s32) (temp_a2 << 0x18);
        arg1->unk78 = (s32) (arg1->unk7E * (temp_a2 << 8));
    }
    return ret;
}

u8 *SelectSoundFont(u8 *arg0, u8 *arg1, u8 *arg2) {
    s32 b;
    s32 ae;
    void *v1;
    b = *(u8 *) arg0;
    arg0 += 1;
    v1 = (void *) D_80032A44;
    *(u16 *) (arg1 + 0x18) = b;
    if (v1 != 0) {
        ae = b;
loop_1:
        if (*(u16 *) (v1 + 0x20) != ae) {
            v1 = *(void **) (v1 + 0x2C);
            if (v1 != 0) {
                goto loop_1;
            }
        }
    }
    if (v1 == 0) {
        v1 = (void *) D_80032A44;
    }
    *(void **) (arg2 + 0x30) = v1;
    return arg0;
}

void func_8001AEF4(s32, s16 *, u16 *);

s32 func_80016EA4(s32 arg0, SeqSong *arg1, SeqVoice *arg2) {
    s32 sp10;
    s16 sp14;
    s32 temp_a0;
    s32 var_v0 = arg0;
    register SeqSong *s0v asm("s0") = arg1;
    SeqVoice *s1v = arg2;
    u16 x4;

    func_8001AEF4(s1v->voiceId, (s16 *) &sp10, (u16 *) &sp14);
    if (sp14 == 0) {
        *(u16 *) ((u8 *) s1v + 0x2) = *(u16 *) ((u8 *) s1v + 0x2) & 0xFFFC;
        if (s0v->flags & 2) {
            D_80032A20 |= s1v->usedChannels;
            temp_a0 = ~s1v->usedChannels;
            s0v->lfoVoiceFlags = temp_a0 & s0v->lfoVoiceFlags;
            s0v->noiseVoiceFlags = temp_a0 & s0v->noiseVoiceFlags;
            s0v->reverbVoiceFlags = temp_a0 & s0v->reverbVoiceFlags;
            x4 = *(u16 *) ((u8 *) s1v + 0x4);
            D_80032A0C &= temp_a0;
            *(u16 *) ((u8 *) s1v + 0x4) = x4 | 0x54;
        } else {
            D_80032A08 |= s1v->usedChannels;
        }
        *(u16 *) ((u8 *) s1v + 0x0) = 0;
        var_v0 -= 1;
    }
    return var_v0;
}

void SetInstrument(s32 arg0, SeqVoice *arg1) {
    u8 *instr;
    InstrumentEntry *ie;
    s32 base;
    s32 sh;
    u16 flags;
    u8 b;

    sh = arg0;
    arg1->currentInstrument = sh;
    sh = (sh << 0x10) >> 0xC;
    base = arg1->wavesetPtr;
    instr = (u8 *) (sh + 0x30);
    ie = (InstrumentEntry *) (base + (u32) instr);
    arg1->unk50 = ie->unk00 + *(s32 *) (base + 0x28);
    flags = arg1->channelFlags;
    arg1->adpcmRepeatAddr = ie->unk04 + ie->unk00;
    arg1->attackMode = ie->unk0D;
    arg1->sustainMode = ie->unk0E;
    arg1->releaseMode = ie->unk0F;
    arg1->attackShiftStep = ie->unk08;
    arg1->decayShift = ie->unk09;
    arg1->sustainFlags = ie->unk0A;
    b = ie->unk0B;
    arg1->unk2E = b;
    arg1->releaseFlags = b;
    arg1->sustainLevel = ie->unk0C;
    arg1->unk84 = ie->unk06;
    if (flags & 0xC) {
        arg1->midFlags |= 0x300;
        arg1->unk04 |= 0x1FF;
    } else {
        arg1->channelFlags = flags | 0x8000;
    }
}

void SUZUKISetNoteflags2AllChannels(s32 arg0, SeqSong *arg1) {
    u8 *a;
    u8 *b;
    int count;

    a = (u8 *) arg1->voices;
    count = arg1->trackCount;
    b = (u8 *) arg1->voices + 2;
    do {
        if (((SeqVoice *) a)->channelFlags != 0) {
            *(u16 *) b = arg0 | *(u16 *) b;
        }
        a += 0x160;
        b += 0x160;
        count--;
    } while (count != 0);
}

void SUZUKIForceChannelFunc(SeqSong *arg0, s32 arg1) {
    u8 *a;
    u8 *b;
    int count;

    a = (u8 *) arg0->voices;
    count = arg0->trackCount;
    b = (u8 *) arg0->voices + 4;
    do {
        if (((SeqVoice *) a)->channelFlags != 0) {
            *(u16 *) b |= arg1;
        }
        a += 0x160;
        b += 0x160;
        count--;
    } while (count != 0);
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main", func_80017118);

extern u8 D_80028FE8[];
extern u8 D_80029060[];
extern u16 D_800290D8[];

s16 func_80017424(s32 arg0) {
    s32 idx = (u32) (arg0 & 0x7FFF) >> 8;
    s32 v0 = D_80029060[idx];
    s32 v1 = D_80028FE8[idx];
    s32 shift = 6 - v1;
    s32 a0 = D_800290D8[(arg0 & 0xFF) + (v0 << 8)];
    if (shift >= 0) {
        a0 = (s16) a0 >> shift;
    } else {
        a0 = (s16) a0 << -shift;
    }
    return (s16) a0;
}

void func_8001749C(void *arg0, void *arg1, s32 arg2) {
    s32 (*fp)(u8 *, u8 *);
    s32 s5 = arg2;
    u8 *s4 = (u8 *) arg1;
    register u8 *s0 asm("s0");
    register s32 s3 asm("s3");
    u8 *s2;
    register u8 *s1 asm("s1");
    register u8 *a1v asm("a1") = (u8 *) arg1;
    s32 a0r;
    s16 temp;
    u8 mode;
    u16 sum;
    u16 flg;
    s32 v0t;
    s32 pad[2];

    (void) pad;
    s0 = s4 + 2;
    do {
        if (*(u16 *) s4 != 0) {
            s3 = 4;
            s2 = s4 + 0xE0;
            s1 = s4 + 0xFC;
            do {
                if ((*(u16 *) (s1 + 2) & 1) != 0) {
                    if (*(u16 *) (s1 - 8) != 0) {
                        *(u16 *) (s1 - 8) = *(u16 *) (s1 - 8) - 1;
                        goto inc;
                    }
                    fp = *(s32(**)(u8 *, u8 *)) s2;
                    a0r = (*fp)(s2, a1v);
                    temp = *(s16 *) (s1 - 4);
                    a1v = (u8 *) (s32) temp;
                    if (temp < 0x100) {
                        *(u16 *) (s1 - 4) = (u16) ((s32) a1v + *(u16 *) (s1 - 2));
                        a0r = (a0r >> 8) * temp;
                    }
                    mode = *(s1 + 0);
                    a0r >>= 16;
                    switch (mode) {
                    case 0:
                        sum = *(u16 *) (s0 + 0x86) + a0r;
                        flg = *(u16 *) s0 | 0x200;
                        *(u16 *) (s0 + 0x86) = sum;
                        break;
                    case 1:
                        sum = *(u16 *) (s0 + 0x88) + a0r;
                        flg = *(u16 *) s0 | 0x100;
                        *(u16 *) (s0 + 0x88) = sum;
                        break;
                    case 2:
                        sum = *(u16 *) (s0 + 0x8A) + a0r;
                        flg = *(u16 *) s0 | 0x100;
                        *(u16 *) (s0 + 0x8A) = sum;
                        break;
                    default:
                        s1 += 0x20;
                        goto tail;
                    }
                    *(u16 *) s0 = flg;
                }
inc:
                s1 += 0x20;
tail:
                s3 -= 1;
                s2 += 0x20;
            } while (s3 != 0);
        }
        s0 += 0x160;
        v0t = s5 - 1;
        s5 = v0t;
        v0t <<= 16;
        s4 += 0x160;
    } while (v0t != 0);
}

void func_80017634(SeqVoiceEnv *arg0) {
    arg0->unk1E &= 0xFFFE;
}

s32 func_80017648(SeqVoiceEnv *arg0) {
    s32 var_a1;
    u16 temp_v0;

    temp_v0 = arg0->unk10 - 1;
    arg0->unk10 = temp_v0;
    var_a1 = 0;
    if (!(temp_v0 & 0xFFFF)) {
        arg0->unk10 = arg0->unk12;
        if (arg0->unk04 == 0) {
            var_a1 = arg0->unk0C;
        }
        arg0->unk04 = var_a1;
    }
    return arg0->unk04;
}

s32 func_80017690(SeqVoiceEnv *arg0) {
    s32 var_a1;
    u16 temp_v0;

    temp_v0 = arg0->unk10 - 1;
    arg0->unk10 = temp_v0;
    if (!(temp_v0 & 0xFFFF)) {
        var_a1 = arg0->unk0C;
        arg0->unk10 = arg0->unk12;
        if (arg0->unk1E & 8) {
            var_a1 = -var_a1;
        }
        arg0->unk04 = var_a1;
        arg0->unk1E ^= 8;
    }
    return arg0->unk04;
}

s32 func_800176E4(SeqVoiceEnv *arg0) {
    u16 temp_v0;
    s32 var_a1;

    temp_v0 = arg0->unk10 - 1;
    arg0->unk10 = temp_v0;
    if ((temp_v0 & 0xFFFF) == 0) {
        var_a1 = arg0->unk0C;
        arg0->unk10 = arg0->unk12;
        if (arg0->unk1E & 8) {
            var_a1 = -var_a1;
        }
        arg0->unk08 = var_a1;
        arg0->unk1E ^= 8;
    }
    arg0->unk04 = arg0->unk04 + arg0->unk08;
    return arg0->unk04;
}

s32 func_80017744(SeqVoiceEnv *arg0) {
    u16 temp_v0;
    u16 flags;
    u16 var_v1;
    s32 temp_a2;

    temp_v0 = arg0->unk10 - 1;
    flags = arg0->unk1E;
    arg0->unk10 = temp_v0;
    if ((temp_v0 & 0xFFFF) == 0) {
        arg0->unk10 = arg0->unk12;
        var_v1 = *(volatile u16 *) &arg0->unk10;
        if (flags & 4) {
            var_v1 *= 2;
        }
        temp_a2 = arg0->unk0C;
        arg0->unk10 = var_v1;
        arg0->unk08 = temp_a2;
        if (flags & 8) {
            arg0->unk08 = -temp_a2;
        }
        flags = (flags | 4) ^ 8;
        arg0->unk1E = flags;
    }
    arg0->unk04 = arg0->unk04 + arg0->unk08;
    return arg0->unk04;
}

s32 func_800177C0(SeqVoiceEnv *arg0) {
    u16 temp_v0;

    temp_v0 = arg0->unk10 - 1;
    arg0->unk10 = temp_v0;
    if (!(temp_v0 & 0xFFFF)) {
        arg0->unk04 = 0;
        arg0->unk10 = arg0->unk12;
    } else {
        arg0->unk04 = arg0->unk04 + arg0->unk0C;
    }
    return arg0->unk04;
}

s32 func_8001780C(SeqVoiceEnv *arg0) {
    u16 temp_v0;

    func_800178F4();
    temp_v0 = arg0->unk10 - 1;
    arg0->unk10 = temp_v0;
    if (!(temp_v0 & 0xFFFF)) {
        arg0->unk10 = (u16) arg0->unk12;
        arg0->unk04 = (s32) (((s32) arg0->unk0C >> 0xF) * func_800178F4());
    }
    return arg0->unk04;
}

s32 func_80017878(SeqVoiceEnv *arg0) {
    s32 temp_a0;
    s32 temp_v1;
    u16 temp_v0;

    temp_v0 = arg0->unk10 - 1;
    arg0->unk10 = temp_v0;
    if (!(temp_v0 & 0xFFFF)) {
        arg0->unk10 = (u16) arg0->unk12;
        temp_v1 = func_800178F4();
        temp_a0 = arg0->unk0C;
        arg0->unk04 = (s32) (((temp_a0 >> 0xE) * temp_v1) - temp_a0);
    }
    return arg0->unk04;
}

void func_800178E4(s32 arg0) {
    D_80032A18 = arg0;
}

s32 func_800178F4(void) {
    s32 v0;
    s32 v1;

    v0 = D_80032A18;
    v1 = v0 << 17;
    v0 ^= v1;
    v1 = v0 >> 15;
    v0 ^= v1;
    D_80032A18 = v0;
    return v0 & 0x7FFF;
}

extern u16 D_80032A1C[];
extern u32 D_80032A34;
extern u32 SUZUKISpuIrqEvCB;
extern u16 D_80032A58[];
extern u16 D_80037028;
extern u16 D_8003702A;
extern u32 D_8003700C;
extern u32 D_800370BC[];
extern u32 D_800408E0[];
extern void SPUSetTransferCallback(s32 *);
extern void SUZUKISPUCallbackFunc(void);
extern s32 Return0(void);
extern void SUZUKIChangeVolumeBalanceHandler(s16, s16);
extern void CalculateChangeInVolume(s16, s16);

void SUZUKISPUInitialiser(s32 arg0) {
    if ((s16) SUZUKISpuInstructionFlags >= 0) {
        SUZUKISpuInstructionFlags = arg0 | 0x8000;
        func_800194C4(6, &D_800408E0[0]);
        SetGlobalMusicVariables(&D_800370BC[0], 0x8000);
        func_80014544();
        D_80032A18 = 0x12345678;
        D_80032A50 = 0;
        SUZUKICurrentMusPointer = 0;
        D_80032A00 = 0;
        D_80032A44 = 0;
        D_80032A0C = 0;
        D_80032A10 = 0;
        D_80032A14 = 0;
        D_80032A08 = 0;
        D_80032A20 = 0;
        D_80032A1C[0] = 0;
        D_80032A58[0] = 0;
        SUZUKICurrentMusPointer = func_8001363C();
        D_80037028 = 0;
        D_8003702A = 0;
        SUZUKISpuCommonAttr = 0xC;
        func_80022034();
        SUZUKIRootCounter2EvCB = (void *) func_80021F74(0xF2000002, 2, 0x1000, &SUZUKIRootCounter2Func);
        SUZUKISpuIrqEvCB = func_80021F74(0xF0000009, 0x1000, 0x1000, &Return0);
        D_80032A2C = 0;
        D_80032A34 = 0;
        func_80022114(0xF2000002, 0x44E8, 0x1000);
        func_800221EC(0xF2000002);
        func_80021FB4(SUZUKIRootCounter2EvCB);
        SPUSetTransferCallback((s32 *) &SUZUKISPUCallbackFunc);
        SUZUKISpuInstructionFlags = (u16) SUZUKISpuInstructionFlags | 1;
        func_80022044();
        InitSoundType(1);
        D_8003700C = -1;
        SUZUKISetSPUReverbMode(4, 0, 0, 0);
        SUZUKIToggleCDAudioReverb(0, 1);
        SUZUKIChangeVolumeBalanceHandler(0x3FFF, 0);
        CalculateChangeInVolume(0x6400, 0);
        if ((u16) SUZUKISpuInstructionFlags & 0x2000) {
            PutSoundType(0xC0);
        }
        SUZUKIToggleMusicPlaying(1);
        D_80032A28 = 0;
    }
}

extern void func_80021F84(s32);
extern void func_8001B828(s32, s32);

void SetAllVoicesReleaseShiftTo6(void) {
    s32 s0;

    if (*(s16 *) &SUZUKISpuInstructionFlags != 0) {
        s0 = 0;
        func_80022034();
        func_80021F84((s32) SUZUKIRootCounter2EvCB);
        func_80021F84(SUZUKISpuIrqEvCB);
        SUZUKISpuInstructionFlags = 0;
        func_80022044();
        do {
            func_8001B828(s0, 6);
            s0++;
        } while (s0 < 0x18);
        func_8001ACF0(0, 0xFFFFFF);
        SUZUKISetSPUReverbMode(0, 0, 0, 0);
        D_80032A28 = 0;
    }
}

void EnableRootCounter2EvCB(void) {
    if (!(SUZUKISpuInstructionFlags & 1)) {
        SUZUKISpuInstructionFlags |= 1;
        func_80021FB4(SUZUKIRootCounter2EvCB);
    }
}

void DisableRootCounter2EvCB(void) {
    if (SUZUKISpuInstructionFlags & 1) {
        func_80021FC4(SUZUKIRootCounter2EvCB);
        SUZUKISpuInstructionFlags &= 0xFFFE;
    }
}

extern s16 WaitForSPUTransfer(s32);
extern s32 SpuMallocWithExtraSteps(s32);

void *PutWAVESETWDInSPU(void *arg0) {
    u8 *s0 = arg0;
    u8 *new_var;
    s32 s1;
    u8 *s2;
    u32 *a1;
    s32 v0;

    s1 = SpuMallocWithExtraSteps(*(s32 *) (s0 + 0x14));
    new_var = s0 + 0x10;
    SPUDataTransferController(s1, s0 + *(s32 *) (s0 + 0x18), *(s32 *) (s0 + 0x14), 0x11);
    s2 = (u8 *) FindSpaceForSMDToMUS(*(s32 *) new_var);
    func_8001442C(s2, s0, *(s32 *) new_var);
    v0 = D_80032A44;
    a1 = (u32 *) (&D_80032A44);
    *(s32 *) (s2 + 0x28) = s1;
    if (v0 != 0) {
        u8 *v0;
        do {
            v0 = *(u8 **) a1;
            a1 = (u32 *) (v0 + 0x2C);
        } while (*(s32 *) (v0 + 0x2C) != 0);
    }
    *(u8 **) a1 = s2;
    *(s32 *) (s2 + 0x2C) = 0;
    WaitForSPUTransfer(0x10);
    return s2;
}

extern void func_80017DA4(void *);

static void func_80017D4C(void) {
    u8 *s0;
    u8 *a0;

    s0 = (u8 *) D_80032A44;
    if (s0 != 0) {
        u16 v0;
        a0 = s0;
        do {
            v0 = *(u16 *) (a0 + 0x20);
            s0 = *(u8 **) (s0 + 0x2C);
            if (v0 >= 0x20) {
                func_80017DA4(a0);
            }
            a0 = s0;
        } while (s0 != 0);
    }
}

void func_80017DA4(void *arg0) {
    void *ss = 0;
    void *v0;

    v0 = (void *) D_80032A44;
    if (v0 != 0) {
loop_1:
        if (v0 != arg0) {
            ss = v0;
            v0 = *(void **) (ss + 0x2C);
            if (v0 != 0) {
                goto loop_1;
            }
        }
        if (v0 != 0) {
            ((s32 (*)(s32)) SpuFreeWithExtraSteps)(*(s32 *) (arg0 + 0x28));
            if (ss != 0) {
                *(void **) (ss + 0x2C) = *(void **) (arg0 + 0x2C);
            } else {
                D_80032A44 = (u32) * (void **) (arg0 + 0x2C);
            }
            func_80014358(arg0);
        }
    }
}

void *func_80017E38(s16 arg0) {
    void *v1;
    s32 ae;

    v1 = (void *) D_80032A44;
    if (v1 != 0) {
        ae = arg0;
loop_1:
        if (*(u16 *) (v1 + 0x20) != (s16) ae) {
            v1 = *(void **) (v1 + 0x2C);
            if (v1 != 0) {
                goto loop_1;
            }
        }
    }
    return v1;
}

void SUZUKIAppendVFXSMD(void *arg0) {
    void **a1 = &D_80032A00;
    if (D_80032A00 != NULL) {
        do {
            void *v0 = *a1;
            a1 = v0 + 0x10;
        } while (*(s32 *) a1 != 0);
    }
    *a1 = arg0;
    ((s32 *) arg0)[4] = 0;
}

void SUZUKIPopVFXSMD(void *arg0) {
    register void *ss asm("s0") = 0;
    void *new_var;
    void *v0;

    v0 = D_80032A00;
    new_var = arg0;
    if (v0 != 0) {
loop_1:
        if (v0 != arg0) {
            ss = v0;
            v0 = *(void **) (ss + 0x10);
            if (v0 != 0) {
                goto loop_1;
            }
        }
        if (v0 != 0) {
            TurnOnMUSAfterSoundEffect(new_var);
            if (ss != 0) {
                *(void **) (ss + 0x10) = *(void **) (arg0 + 0x10);
            } else {
                D_80032A00 = *(void **) (arg0 + 0x10);
            }
        }
    }
}

void func_80017F44(void) {
    func_800123CC();
    TurnOffAllMUS();
}

extern int SUZUKIGlobalReverb;
extern u16 D_8003704E;

void InitSoundType(s32 arg0) {
    u16 v1;
    u16 nv;
    s32 *s0;
    s32 *s1;

    v1 = SUZUKISpuInstructionFlags & 0xF8FF;
    SUZUKISpuInstructionFlags = v1;
    if (arg0 == 1) {
        goto C1;
    }
    if (arg0 < 2) {
        goto DEF;
    }
    if (arg0 == 2) {
        goto C2;
    }
    if (arg0 == 3) {
        goto C3;
    }
    goto DEF;
C1:
    nv = v1 | 0x100;
    goto ST;
C2:
    nv = v1 | 0x300;
    goto ST;
C3:
    nv = v1 | 0x500;
ST:
    SUZUKISpuInstructionFlags = nv;
DEF:
    CommitVolumeChange();
    s0 = &SUZUKIGlobalReverb;
    func_8001A014(s0);
    s1 = (s32 *) D_80032A50;
    *s0 = 0;
    if (s1 != 0) {
        do {
            SUZUKISetNoteflags2AllChannels(0x100, (SeqSong *) s1);
            s1 = (s32 *) *s1;
        } while (s1 != 0);
    }
    if ((SUZUKISpuInstructionFlags & 0x2000) != 0) {
        PutSoundType((s16) D_8003704E);
    }
}

s32 GetSoundType(void) {
    u16 h;
    s32 r;
    h = SUZUKISpuInstructionFlags;
    if ((h & 0x700) != 0) {
        if ((h & 0x600) != 0)
            r = 2;
        else
            r = 1;
    } else
        r = 0;
    return r;
}

extern u8 SUZUKICdlATV;
extern u8 D_80032A3D;
extern u8 D_80032A3E;
extern u8 D_80032A3F;
s32 _CdMix(void *arg0);

void PutSoundType(s16 arg0) {
    s16 r0;
    s32 r1;

    D_8003704E = arg0;
    if (SUZUKISpuInstructionFlags & 0x700) {
        r1 = 0;
        r0 = arg0;
    } else {
        r1 = (arg0 * 0xA0) / 255;
        r0 = r1;
    }
    SUZUKICdlATV = D_80032A3E = (s8) r0;
    D_80032A3D = D_80032A3F = (s8) r1;
    _CdMix(&SUZUKICdlATV);
}

extern void SPUGetReverbModeParam(void *);
extern u32 D_80037014;
extern u32 D_80037018;
extern s16 D_8003704C;

s32 SUZUKISetSPUReverbMode(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 sp10[5];
    u32 *s1;
    s32 *s0;
    u32 v0;

    SPUGetReverbModeParam(sp10);
    if (arg0 < 0) {
        if (sp10[1] == D_8003700C) {
            return;
        }
        arg0 = D_8003700C;
    }
    D_8003704C = arg1;
    __asm__("la %0, D_80037014" : "=r"(s1));
    *s1 = arg2;
    D_80037018 = arg3;
    if (arg0 < 10) {
        if ((sp10[1] != arg0) || (arg0 == 0)) {
            func_80019E38(0);
            D_8003700C = arg0 | 0x100;
            v0 = s1[-3] | 1;
            s1[-3] = v0;
            func_8001A014(s1 - 3);
            s1[-3] = 0;
            func_80019E38(1);
        }
        CommitVolumeChange();
        s0 = &SUZUKIGlobalReverb;
        func_8001AA44(s0);
        *s0 = 0;
    }
}

extern int D_80037050;
extern int D_80037054;
extern short D_8003705A;

void SUZUKIChangeVolumeBalanceHandler(s16 arg0, s16 arg1) {
    s32 temp;
    s16 *base = &D_8003705A;

    *base = arg0;
    if (arg1 == 0) {
        D_80037050 = arg0 << 0x10;
        D_80037058 = 0;
        D_80037048 = arg0;
        SetVolBalance(arg0, (s16 *) ((u8 *) base - 0x36), 0);
        SUZUKISpuCommonAttr |= 3;
    } else {
        temp = ((s32) (arg0 << 0x10) >> 8) - (D_80037050 >> 8);
        if (temp != 0) {
            D_80037058 = arg1;
            D_80037054 = (temp / arg1) << 8;
        }
    }
}

extern int D_8003705C;
extern int D_80037060;
extern short D_80037066;

void CalculateChangeInVolume(s16 arg0, s16 arg1) {
    s32 temp;
    s16 *base = &D_80037066;

    *base = arg0;
    if (arg1 == 0) {
        D_8003705C = arg0 << 0x10;
        D_80037064 = 0;
        D_8003704A = arg0;
        SetVolBalance(arg0, (s16 *) ((u8 *) base - 0x36), 0);
        SUZUKISpuCommonAttr |= 0xC0;
    } else {
        temp = ((s32) (arg0 << 0x10) >> 8) - (D_8003705C >> 8);
        if (temp != 0) {
            D_80037064 = arg1;
            D_80037060 = (temp / arg1) << 8;
        }
    }
}

extern int D_80037034;
extern int D_80037038;
void func_8001B094(void *arg);

void SUZUKIToggleCDAudioReverb(int arg0, int arg1) {
    int *p = &D_80037034;
    int *q = p - 5;
    p[0] = arg0;
    *q |= 0x300;
    D_80037038 = arg1;
    func_8001B094(q);
}

extern s16 D_80037010[2];

void CommitVolumeChange(void) {
    short *base = &D_80037048;
    SetVolBalance(*base, (s16 *) ((u8 *) base - 0x24), 0);
    SetVolBalance(D_8003704A, (s16 *) ((u8 *) base - 0x18), 0);
    SetVolBalance(D_8003704C, &D_80037010[0], 1);
    SUZUKISpuCommonAttr |= 0xC3;
    SUZUKIGlobalReverb |= 6;
}

void SetVolBalance(s32 a0, s16 *a1, s32 a2) {
    u16 v1 = SUZUKISpuInstructionFlags;
    a1[1] = a0;
    a1[0] = a0;
    if (v1 & 0x600) {
        a2 &= 0xFF;
        if (!(v1 & 0x200)) {
            if ((a2 ^ 1) != 0) {
                a1[0] = -a0;
            } else {
                a1[1] = -a0;
            }
        } else {
            if (a2 != 0) {
                a1[0] = -a0;
            } else {
                a1[1] = -a0;
            }
        }
    }
}

void func_800184E0(s32 a0) {
    D_80032A28 = a0;
}

void SUZUKISPUCallbackFunc(void) {
    SUZUKISpuInstructionFlags &= 0xFF8F;
}

s32 Return0(void) {
    return 0;
}

extern void SPUSetTransferMode(s32);
extern void func_8001AFC4(s32);
extern void func_8001AF64(s32, s32);
extern void func_80019DD8(s32, s32);
extern s16 func_8001AC7C(s32, s32);
extern u16 D_80032A40[];

void SPUDataTransferController(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_a0;
    s32 var_a1;
    s32 temp_s0;
    u16 temp_v0;

    WaitForSPUTransfer(0x10);
    SUZUKISpuInstructionFlags |= 0x10;
    SPUSetTransferMode(0);
    func_8001AFC4(arg0);
    temp_s0 = arg3 & 0xF;
    switch (temp_s0) {
    case 1:
        SUZUKISpuInstructionFlags |= 0x30;
        func_8001AF64(arg1, arg2);
        return;
    case 2:
        SUZUKISpuInstructionFlags |= 0x50;
        func_80019DD8(arg1, arg2);
        return;
    case 3:
        var_a0 = arg1;
        temp_v0 = SUZUKISpuInstructionFlags;
        var_a1 = 0;
        goto block_6;
    case 4:
        var_a0 = arg1;
        temp_v0 = SUZUKISpuInstructionFlags;
        var_a1 = 5;
block_6:
        SUZUKISpuInstructionFlags = temp_v0 | 0x50;
        D_80032A40[0] = func_8001AC7C(var_a0, var_a1);
        return;
    case 5:
        return;
    default:
        return;
    }
}

void func_80018654(void) {
}

extern s32 D_80032A04;
extern u16 D_80032A30;
extern vu16 SUZUKISpuInstructionFlags;

INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010044);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010054);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010064);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010078);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001008C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010108);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001014C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010168);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010184);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800101A0);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800101B0);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800101C8);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001030C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001031C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010338);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010344);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010360);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010374);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010380);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010394);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001039C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800103A8);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800103B0);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800103C0);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800103FC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010408);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010414);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010420);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010438);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010450);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010464);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001047C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010490);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010558);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800105F4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010784);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800107A0);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800107B4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800107C8);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800107D4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800107E8);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800107EC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800107F8);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001081C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001084C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010860);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010894);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800108AC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800108E0);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800108F8);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010904);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010910);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010920);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010934);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001095C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010974);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_8001098C);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109A4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109AC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109B4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109BC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109C4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109C8);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109CC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109D4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109DC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109E4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109EC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109F4);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_800109FC);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010A00);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010A04);
INCLUDE_RODATA("rom/extracted/asm/nonmatchings/main", D_80010A0C);
