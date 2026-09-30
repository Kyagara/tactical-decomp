#ifndef FFT_BATTLE_H
#define FFT_BATTLE_H

typedef struct {
    u8 sprite;
    u8 partyId;
    u8 job;
    u8 palette;
    u8 gender;
    u8 birthday;
    u8 zodiac;
    u8 secondarySkillset;
    u16 reaction;
    u16 support;
    u16 movement;
    u8 head;
    u8 body;
    u8 accessory;
    u8 rhWeapon;
    u8 rhShield;
    u8 lhWeapon;
    u8 lhShield;
    u8 exp;
    u8 level;
    u8 brave;
    u8 faith;
    u8 rawHp[3];
    u8 rawMp[3];
    u8 rawSp[3];
    u8 rawPa[3];
    u8 rawMa[3];
    u8 unlocked[3];
    u8 learned[57];
    u8 jobLevels[10];
    u16 jobJp[20];
    u16 jobJpTotal[20];
    u8 name[16];
    u16 nameId;
    u8 battle[48];
} Unit;

typedef struct {
    u8 skillset;
    u8 innate[8];
    u8 equip[4];
    u8 hpGrowth;
    u8 hpMult;
    u8 mpGrowth;
    u8 mpMult;
    u8 spGrowth;
    u8 spMult;
    u8 paGrowth;
    u8 paMult;
    u8 maGrowth;
    u8 maMult;
    u8 move;
    u8 jump;
    u8 cev;
    u8 innateStatus[5];
    u8 immunity[5];
    u8 startingStatus[5];
    u8 absorb;
    u8 nullify;
    u8 halve;
    u8 weak;
    u8 monsterPortrait;
    u8 monsterPalette;
    u8 monsterGraphic;
} Job;

typedef struct {
    u8 palette;
    u8 sprite;
    u8 reqLevel;
    u8 typeFlags;
    u8 secondId;
    u8 itemType;
    u8 unk06;
    u8 attributes;
    u16 price;
    u8 shop;
    u8 unk0B;
} Item;

typedef struct {
    u16 jpCost;
    u8 learnChance;
    u8 learnFlags;
    u8 aiFlags[4];
} Ability1;

typedef struct {
    u8 range;
    u8 aoe;
    u8 vertical;
    u8 flags[4];
    u8 element;
    u8 formula;
    u8 x;
    u8 y;
    u8 status;
    u8 ct;
    u8 mp;
} Ability2;

typedef struct {
    u8 flags[3];
    u8 abilities[16];
    u8 rsm[6];
} Skillset;

typedef struct {
    u8 flags[1];
    u8 abilities[4];
} MonsterSkillset;

struct BaseData {
    u8 hp;
    u8 mp;
    u8 sp;
    u8 pa;
    u8 ma;
    u8 helmet;
    u8 armor;
    u8 accessory;
    u8 rhWeapon;
    u8 rhShield;
    u8 lhWeapon;
    u8 lhShield;
};

typedef struct {
    u8 hp;
    u8 mp;
    u8 sp;
    u8 pa;
    u8 ma;
} BaseRawRandom;

typedef struct {
    u8 status[5];
} StatusCheck;

typedef struct {
    u8 unk00;
    u8 unk01;
    u8 order;
    u8 ct;
    u8 checks1;
    u8 checks2;
    u8 cancels1;
    u8 cancels2;
    u8 cancels3;
    u8 cancels4;
    u8 cancels5;
    u8 nostack1;
    u8 nostack2;
    u8 nostack3;
    u8 nostack4;
    u8 nostack5;
} StatusEffect;

typedef struct {
    u8 range;
    u8 flags;
    u8 formula;
    u8 unk03;
    u8 power;
    u8 evade;
    u8 element;
    u8 status;
} WeaponSecondary;

typedef struct {
    u8 pev;
    u8 mev;
} ShieldSecondary;

typedef struct {
    u8 hpBonus;
    u8 mpBonus;
} HelmArmorSecondary;

typedef struct {
    u8 pev;
    u8 mev;
} AccessorySecondary;

typedef struct {
    u8 formula;
    u8 z;
    u8 statusId;
} ItemSecondary;

typedef struct {
    u8 type;
    u8 status[5];
} InflictStatuses;

typedef struct {
    u8 range;
    u8 vertical;
} JumpAbility;

typedef struct {
    u8 ct;
    u8 power;
} ChargeAbility;

typedef struct {
    u8 req[10];
} JobUnlockRow;

typedef struct {
    u8 sprite;
    u8 gender;
    u8 nameId;
    u8 level;
    u8 birthMonth;
    u8 birthDay;
    u8 brave;
    u8 faith;
    u8 jobUnlock;
    u8 jobLevel;
    u8 job;
    u8 secondary;
    u16 reaction;
    u16 support;
    u16 movement;
    u8 helmet;
    u8 armor;
    u8 accessory;
    u8 rhEquip;
    u8 lhEquip;
    u8 palette;
    u8 flags;
    u8 x;
    u8 y;
    u8 facing;
    u8 exp;
    u8 primarySkillset;
    u8 warTrophy;
    u8 bonusMoney;
    u8 unk20;
    u8 ai[7];
} ENTDEntry;

typedef char ENTDEntry_size_check[sizeof(ENTDEntry) == 0x28 ? 1 : -1];

typedef struct {
    u8 sprite;
    u8 unitId;
    u8 partyId;
    u8 job;
    u8 palette;
    u8 entdFlags;
    u8 gender;
    u8 deathCounter;
    u8 birthday;
    u8 zodiac;
    u16 innate[4];
    u8 primarySkillset;
    u8 secondarySkillset;
    u16 reaction;
    u16 support;
    u16 movement;
    u8 head;
    u8 body;
    u8 accessory;
    u8 rhWeapon;
    u8 rhShield;
    u8 lhWeapon;
    u8 lhShield;
    u8 exp;
    u8 level;
    u8 origBrave;
    u8 brave;
    u8 origFaith;
    u8 faith;
    u8 turnFlag;
    u16 hp;
    u16 maxHp;
    u16 mp;
    u16 maxMp;
    u8 origPa;
    u8 origMa;
    u8 origSp;
    u8 bonusPa;
    u8 bonusMa;
    u8 bonusSp;
    u8 pa;
    u8 ma;
    u8 sp;
    u8 ct;
    u8 move;
    u8 jump;
    u8 wp1;
    u8 wp2;
    u8 weva1;
    u8 weva2;
    u8 accPev;
    u8 rhShieldPev;
    u8 lhShieldPev;
    u8 cev;
    u8 accMev;
    u8 rhShieldMev;
    u8 lhShieldMev;
    u8 x;
    u8 y;
    u8 mapFlags;
    u8 equip[4];
    u8 innateStatus[5];
    u8 immunity[5];
    u8 curStatus[5];
    u8 statusCt[16];
    u8 absorb;
    u8 nullify;
    u8 halve;
    u8 weak;
    u8 strengthen;
    u8 rawHp[3];
    u8 rawMp[3];
    u8 rawSp[3];
    u8 rawPa[3];
    u8 rawMa[3];
    u8 growth[10];
    u8 reactions[4];
    u8 supports[4];
    u8 movements[3];
    u8 unlocked[3];
    u8 learned[57];
    u8 jobLevels[10];
    u16 jobJp[20];
    u16 jobJpTotal[20];
    u8 unitName[16];
    u8 jobName[16];
    u8 primaryName[8];
    u8 secondaryName[8];
    u8 unk15C;
    u8 abilityCt;
    u8 graphic;
    u8 portrait;
    u8 pal;
    u8 entdId;
    u8 specialSkillset;
    u8 warTrophy;
    u8 bonusMoney;
    u8 aiX;
    u8 aiY;
    u8 aiFlags;
    u8 targetId;
    u8 entd69;
    u8 entd6A;
    u8 entd6B;
    u16 nameId;
    u8 attackerId;
    u8 lastSkillset;
    u16 lastAbility;
    u16 calcType;
    u16 calcMult;
    u16 usedItem;
    u8 actionFlag;
    u8 targetId2;
    u8 targetX;
    u8 tileFlags;
    u8 targetLevel;
    u8 unk17D;
    u8 targetY;
    u8 unk17F;
    u8 unk180;
    u8 unk181;
    u8 mountInfo;
    u8 existsFlag;
    u8 equipFlags;
    u8 unk185;
    u8 charTurn;
    u8 moveTaken;
    u8 actionTaken;
    u8 waterFlags;
    u8 unitId2;
    u8 abilityCt2;
    u8 curAction[52];
} BattleUnit;

typedef char BattleUnit_size_check[sizeof(BattleUnit) == 0x1C0 ? 1 : -1];

/* 0x10-byte menu-init entry; ten sit at +0x204 of the 0x2A4 event block. */
typedef struct {
    u8 at_00[4];
    u8 at_04;
    u8 at_05;
    u8 at_06;
    u8 at_07;
    u16 at_08;
    u16 at_0A;
    u16 at_0C;
    u16 at_0E;
} EventEntry16;

typedef char EventEntry16_size_check[sizeof(EventEntry16) == 0x10 ? 1 : -1];

/* 0x2A4 event menu-init block: 0x204 prefix plus ten EventEntry16 rows. */
typedef struct {
    u8 prefix[0x204];
    EventEntry16 first;
    EventEntry16 second;
    EventEntry16 entries[8];
} EventInitBlock;

typedef char EventInitBlock_size_check[sizeof(EventInitBlock) == 0x2A4 ? 1 : -1];

/* 0x28-byte event coordinate/display record, walked with a 0x28 stride. */
typedef struct {
    u32 packed;
    u8 at_04;
    u8 at_05;
    u8 at_06;
    u8 pad_07;
    u16 at_08;
    u16 at_0A;
    u8 at_0C;
    u8 at_0D;
    u16 at_0E;
    u16 at_10;
    u16 at_12;
    u8 at_14;
    u8 at_15;
    u16 at_16;
    u16 at_18;
    u16 at_1A;
    u8 at_1C;
    u8 at_1D;
    u16 at_1E;
    u16 at_20;
    u16 at_22;
    u8 at_24;
    u8 at_25;
    u8 pad_26[2];
} EventCoord28;

typedef char EventCoord28_size_check[sizeof(EventCoord28) == 0x28 ? 1 : -1];

/* 0x34-stride event row record; every gap is an explicit array. */
typedef struct {
    u8 unknown_00[8];
    u16 f08;
    u16 f0A;
    u8 f0C[2];
    u16 f0E;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u8 f18[2];
    u16 f1A;
    u8 unknown_1C[4];
    u16 f20;
    u16 f22;
    u8 f24[2];
    u8 unknown_26[6];
    u16 f2C;
    u16 f2E;
    u8 f30[2];
    u8 pad32[2];
} EventRecord34;

typedef char EventRecord34_size_check[sizeof(EventRecord34) == 0x34 ? 1 : -1];

/* 8-byte world file-record header shared with the event card stream helpers. */
struct WorldFileRec {
    s32 f00;
    s16 f04;
};

typedef char WorldFileRec_size_check[sizeof(struct WorldFileRec) == 8 ? 1 : -1];

/* curAction byte offsets (Data locations 0x018C base + index). */
#define CURACTION_INFLICT 47 /* +0x2F Inflicted Status List 1-5 */

/* Current action data: 0x34 bytes at BattleUnit+0x018C. */
typedef struct {
    u8 hitFlag;
    u8 critFlag;
    u8 evadeType;
    u8 breakItem;
    u16 hpDamage;
    u16 hpRecovery;
    u16 mpDamage;
    u16 mpRecovery;
    u16 gil;
    u16 reaction;
    u8 special1;
    u8 special2;
    u8 spChange;
    u8 ctChange;
    u8 paChange;
    u8 maChange;
    u8 braveChange;
    u8 faithChange;
    u8 statusChange;
    u8 removeEquip;
    u8 unk1A;
    u8 inflict[5];
    u8 remove[5];
    u8 attackType;
    u8 lastAttackSelf;
    u8 unk28;
    u8 stolenExp;
    u8 stolenJp;
    u8 hitPct;
    u8 unk2C;
    u8 mainTarget;
    u8 entdFlags;
    u8 inflictedList[5];
} CurrentAction;

typedef char CurrentAction_size_check[sizeof(CurrentAction) == 0x34 ? 1 : -1];

#define FFT_BASE_DATA_ADDR 0x8005E90C
#define FFT_ABILITY_DATA1_ADDR 0x8005EBF0
#define FFT_ABILITY_DATA2_ADDR 0x8005FBF0
#define FFT_JOB_DATA_ADDR 0x800610B8
#define FFT_ITEM_DATA_ADDR 0x80062EB8
#define FFT_SKILLSETS_ADDR 0x80064A94
#define FFT_STATUS_EFFECTS_ADDR 0x80065DE4
#define FFT_STATUS_CHECKS_ADDR 0x800662D0

typedef struct {
    u16 level[8];
} JpReqLevels;

typedef struct {
    u8 abilities[64];
} GeomancyTable;

#endif
