#include "common.h"

extern s32 D_80085CC0;
extern s32 D_8008E548;
extern s32 D_8008E574;
extern s32 D_8008FBC0;
extern s32 D_8008FBC4;
extern void func_80068638();
extern void func_80067E68(s32);
extern void func_80067E90(s32);

void func_80068D9C(s16 *arg0) {
    s32 *p;
    D_80085CC0 = 2;
    MEMORY_BARRIER();
    func_80067E68(arg0[1]);
    p = &D_8008E574;
    *p += 4;
}

void func_80068DE0(s16 *arg0) {
    s32 *p;
    D_80085CC0 = 2;
    MEMORY_BARRIER();
    func_80067E90(arg0[1]);
    p = &D_8008E574;
    *p += 4;
}

INCLUDE_ASM("rom/extracted/blobs/open/nonmatchings/open_2", func_80068E24);

void func_80068F34(s16 *arg0) {
    register s32 a0v asm("a0");
    register s32 a1v asm("a1");
    register s32 a2v asm("a2");
    register s32 v0v asm("v0");
    register s32 v1v asm("v1");

    a2v = (s32) &D_8008E548;
    a1v = *(s32 *) a2v;
    v0v = a1v & 4;
    KEEP(v0v);
    __asm__ volatile(".word 0x1040000a\n.word 0x30a20020\n.word 0x10400003\n.word 0x38a20002");
    __asm__ volatile(".word 0x0801bff5\n.word 0xacc20000");
path_f68:
    v0v = D_8008E574;
    KEEP(v0v);
    v1v = a1v ^ 4;
    KEEP(v1v);
    __asm__ volatile(".word 0x0801bfe4\n.word 0xacc30000");
path_f7c:
    v0v = a1v & 0x38;
    KEEP(v0v);
    __asm__ volatile(".word 0x10400009\n.word 0x2402ffc5");
    v0v = D_8008E574;
    v0v += 4;
    D_8008E574 = v0v;
    __asm__ volatile(".word 0x0801bff5\n.word 0x00000000");
path_fa8:
    v0v = a1v & v0v;
    v0v |= 0x24;
    v1v = arg0[1];
    KEEP(v1v);
    a0v = 0;
    D_8008FBC4 = 0;
    *(s32 *) a2v = v0v;
    D_8008FBC0 = v1v;
    MEMORY_BARRIER();
    a1v = 1;
    func_80068638(a0v, a1v);
}

void func_80068FE4(s16 *arg0) {
    s32 *p = &D_8008E574;
    func_80068638(0x7A, arg0[1] * 4);
    *p += 4;
}

void func_80069020(s16 *arg0) {
    s32 *p = &D_8008E574;
    func_80068638(0, arg0[1] * 4);
    *p += 4;
}
