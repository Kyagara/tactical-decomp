#ifndef FFT_GPU_H
#define FFT_GPU_H

typedef struct {
    void *vec[16];
} GpuDispatch;

typedef struct {
    u8 tag[3];
    u8 code;
    u8 pad[3];
    u8 len;
} GpuPacket;

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} GpuRect;

typedef struct {
    GpuRect disp;
    GpuRect screen;
    u8 isinter;
    u8 isrgb24;
    u8 pad0;
    u8 pad1;
} DispEnv;

typedef struct {
    GpuRect clip;
    s16 ofs[2];
    GpuRect tw;
    u16 tpage;
    u8 dtd;
    u8 dfe;
    u8 isbg;
    u8 r0;
    u8 g0;
    u8 b0;
    s32 unk1C;
    u8 unk20[0x3C];
} DrawEnv;

typedef char DrawEnv_size_check[sizeof(DrawEnv) == 0x5C ? 1 : -1];

/* 0x14-byte mixer-state element of the two-screen DrawEnv block. */
typedef struct {
    u8 unk00[0x14];
} MixerState;

typedef char MixerState_size_check[sizeof(MixerState) == 0x14 ? 1 : -1];

/* 8-byte draw-argument pair passed by value to the event draw callbacks. */
typedef struct {
    s16 *coords;
    u8 *extra;
} EventDrawArgs;

typedef char EventDrawArgs_size_check[sizeof(EventDrawArgs) == 8 ? 1 : -1];

/* TIM texwindow source (GetTw): byte offsets corroborated by widths
 * (u8@0, u8@2, s16@4, s16@6). Offset names only. */

typedef struct {
    u8 unk00;
    u8 pad01;
    u8 unk02;
    u8 pad03;
    s16 unk04;
    s16 unk06;
} TimPos;

typedef char TimPos_size_check[sizeof(TimPos) == 8 ? 1 : -1];

#endif
