#ifndef FFT_EFFECT_H
#define FFT_EFFECT_H

/* Shared by the EFFECT family units (E259/E338/E454/E464, ...). */

typedef struct {
    u16 v0;
    u16 v1;
    u16 v2;
} U16x3;

typedef char U16x3_size_check[sizeof(U16x3) == 6 ? 1 : -1];

typedef struct {
    u8 pad00[0x4C];
    s16 kind;
    u8 pad4E[0x5A];
    s16 range_start;
    s16 range_end;
    u8 padAC[0x18];
} EffectMeta;

typedef char EffectMeta_size_check[sizeof(EffectMeta) == 0xC4 ? 1 : -1];

typedef struct {
    u8 pad00[2];
    s16 field02;
    u8 pad04[0x1C];
    s16 field20;
    u8 state;
    u8 pad23[0xC1];
    s32 handle;
} EffectSlot;

typedef char EffectSlot_size_check[sizeof(EffectSlot) == 0xE8 ? 1 : -1];

#endif
