#ifndef FFT_SOUND_H
#define FFT_SOUND_H

/* Per-voice 0x20 envelope record; SeqVoice.env[4] starts at +0xE0. */
typedef struct {
    u32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u8 unk1C;
    u8 unk1D;
    u16 unk1E;
} SeqVoiceEnv;

typedef struct {
    u16 channelFlags;
    u16 midFlags;
    u16 unk04;
    u16 unk06;
    s32 unk08;
    u8 unk0C[0xC];
    s32 smdListPtr; /* +0x18 SMD instruction list pointer */
    u8 unk1C;
    u8 unk1D;
    u16 unk1E;
    u8 unk20[8];
    u16 loopCount; /* +0x28 incremented per end-bar */
    u8 unk2A[2];
    u8 currentInstrument;
    u8 voiceId;
    u16 unk2E;
    s32 wavesetPtr;
    s32 usedChannels;
    u16 unk38;
    u16 unk3A;
    u16 unk3C;
    u16 unk3E;
    u8 unk40[8];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 adpcmRepeatAddr;
    s32 attackMode;
    s32 sustainMode;
    s32 releaseMode;
    u16 attackShiftStep;
    u16 decayShift;
    u16 sustainFlags;
    u16 releaseFlags;
    u16 sustainLevel;
    u8 unk6E[8];
    u8 unk76;
    u8 unk77;
    s32 unk78;
    u16 unk7C;
    u16 octave;
    u8 unk80[4];
    u16 unk84;
    u8 unk86[4];
    s16 unk8A;
    u8 unk8C[6];
    u16 volumeBalance; /* +0x92 set/shifted by Balance/ShiftBalance */
    u16 echo;
    u16 unk96;
    s32 volumeLeft;
    u8 unk9C[4];
    s32 volumeDelta; /* +0xA0 gradual volume change (FermataRamp) */
    u8 unkA4[0x3C];
    SeqVoiceEnv env[4];
} SeqVoice;

typedef char SeqVoice_size_check[sizeof(SeqVoice) == 0x160 ? 1 : -1];

typedef struct SeqSong {
    struct SeqSong *next;
    void *unk04;
    void *parent;
    u8 unk0C[4];
    u16 flags;
    u16 unk12;
    u8 voiceCount;
    u8 unk15;
    u8 trackCount;
    u8 unk17;
    u16 soundfontId;
    u16 noiseClock;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E[2];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u16 unk30;
    u16 currentMeasure;
    u16 currentBeat;
    u16 framesUntilNextBeat;
    u16 tsTop;
    u16 tsTopFrames;
    u16 tsBottom;
    u16 unk3E;
    u8 unk40[4];
    s32 reverbMode;
    s16 volumeDepth;
    u8 unk4A[2];
    s32 reverbDelay;
    s32 reverbFeedback;
    u16 unk54;
    u8 unk56[2];
    s32 ownedChannels;
    s32 unk5C;
    s32 modifiedChannels;
    s32 unk64;
    s32 lfoVoiceFlags;
    s32 noiseVoiceFlags;
    s32 reverbVoiceFlags;
    s32 unk74;
    s32 modifiedTempo;
    s32 rawTempo;
    s32 unk80;
    u16 unk84;
    u8 unk86[2];
    s32 tempoScalar;
    u8 unk8C[4];
    u16 unk90;
    u8 unk92[2];
    s32 customVolume0;
    s32 unk98;
    s16 unk9C;
    s16 unk9E;
    s32 customVolume1;
    s32 unkA4;
    s16 unkA8;
    s16 unkAA;
    s32 customVolume2;
    s32 unkB0;
    s16 unkB4;
    s16 unkB6;
    SeqVoice voices[8];
} SeqSong;

typedef char SeqSong_size_check[sizeof(SeqSong) == 0xBB8 ? 1 : -1];

typedef struct {
    s32 unk00;
    u16 unk04;
    u16 unk06;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 unk0B;
    u8 unk0C;
    u8 unk0D;
    u8 unk0E;
    u8 unk0F;
} InstrumentEntry;

#endif
