#include "common.h"

extern s16 D_80193CB2;

s32 func_8012D92C(void) {
    register s32 v1v asm("v1");
    register s32 v0v asm("v0");
    v1v = D_80193CB2;
    KEEP_NOVOL(v1v);
    v0v = v1v;
    __asm__("j .Lfe\n\t.Lfe:");
    return v0v;
}

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012D964);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012DAE0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012DCD4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012DDC8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012DE98);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012DF80);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012DFE4);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012E0B8);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012E674);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012E720);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012E7A0);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012EA44);

INCLUDE_ASM("rom/extracted/blobs/world/nonmatchings/world_4", func_8012EB08);
