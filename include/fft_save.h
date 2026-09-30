#ifndef FFT_SAVE_H
#define FFT_SAVE_H

typedef struct {
    u32 ms;
    u32 seconds;
    u32 minutes;
    u32 hours;
} Clock;

typedef struct {
    u32 customized;
    u32 def;
} Options;

/* Shop page orders: u8 item-ID lists, 0xFF-terminated. */
typedef struct {
    u8 weapon[0x8C];
    u8 helmet[0x20];
    u8 armor[0x28];
    u8 accessory[0x24];
} ShopPageOrders;

/* Save-screen rows: 0x18 bytes x 15 files @0x80057D84. */
typedef struct {
    u8 fileId;
    u8 name[0x15];
    u8 text[2];
    u8 ramzaJob;
    u8 ramzaLevel;
    u8 month;
    u8 day;
    u8 location;
    u8 unk17;
} SaveScreenRow;

/* Save times: 3 bytes x 15 files @0x800597E0. */
typedef struct {
    u8 hours;
    u8 minutes;
    u8 seconds;
} SaveTime;

#define FFT_OPT_MAX_EQUIP_JOB 0x20000000
#define FFT_OPT_TARGET_FLASH 0x08000000
#define FFT_OPT_SHOW_EXPJP 0x02000000
#define FFT_OPT_SHOW_UNEQUIP 0x00800000
#define FFT_OPT_SOUND_WIDE 0x00400000
#define FFT_OPT_SOUND_STEREO 0x00200000
#define FFT_OPT_SHOW_EFFECT_MSG 0x00080000
#define FFT_OPT_SHOW_ABILITY_NAME 0x00020000
#define FFT_OPT_NAV_MSG 0x00008000

#define FFT_LOC_IGROS 0x02
#define FFT_LOC_GARILAND 0x06
#define FFT_LOC_DORTER 0x09
#define FFT_LOC_ZEAKDEN 0x0F
#define FFT_LOC_THIEVESFORT 0x11
#define FFT_LOC_ORBONNE 0x12
#define FFT_LOC_MANDALIA 0x18
#define FFT_LOC_FOVOHAM 0x19
#define FFT_LOC_SWEEGY 0x1A
#define FFT_LOC_ZEKLAUS 0x1C
#define FFT_LOC_LENALIA 0x1D

#define FFT_CLOCK_ADDR 0x800459B8
#define FFT_OPTIONS_ADDR 0x800473AC
#define FFT_TIME_PLAYED_ADDR 0x80057718
#define FFT_EVENT_ID_ADDR 0x800577B8
#define FFT_GIL_ADDR 0x800577CC
#define FFT_MONTH_ADDR 0x800577D4
#define FFT_DAY_ADDR 0x800577D8
#define FFT_LOCATION_ADDR 0x800577E0
#define FFT_ENTD_ID_ADDR 0x800577E4
#define FFT_MAP_ID_ADDR 0x800577E8
#define FFT_TEAMS_ADDR 0x800577EC
#define FFT_FORMATION_ADDR 0x800577F0
#define FFT_INJURED_ADDR 0x800578A0
#define FFT_CASUALTIES_ADDR 0x800578A4
#define FFT_STORYLINE_ADDR 0x800578D4
#define FFT_SHOP_AVAIL_ADDR 0x800578D8
#define FFT_PARTY_ADDR 0x80057F74
#define FFT_PARTY_COUNT 20
#define FFT_SAVE_SCREEN_ADDR 0x80057D84
#define FFT_SAVE_SCREEN_COUNT 15
#define FFT_ITEM_PAGE_ORDER_ADDR 0x80057C54
#define FFT_ITEM_QTY_ADDR 0x800596E0
#define FFT_POACHED_QTY_ADDR 0x80059494
#define FFT_SAVE_TIMES_ADDR 0x800597E0
#define FFT_LEVELUP_PTRS_ADDR 0x80059818
#define FFT_ACTION_STATUS_PTRS_ADDR 0x80059830

#endif
