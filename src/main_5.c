#include "common.h"

extern void *jtbl_80059818[];
extern s32 D_80132824(s32);
extern s32 func_800E6EDC(s32);
extern u8 D_801908CC[];
extern void EquippableItemSetting();
extern void CalculateActualStats();
extern void TransferJobSDataToUnitSData();
extern void InitializeUnitSBattleData();
extern Unit PartyData[20];
void EquipmentMoveJumpXNameStoringGeneration(void *arg0);
s32 CalculateUnlockedJobs(u8 *arg0, u8 arg1);
void Store3ByteData(u8 *arg0, u32 arg1);
void InitializeUnitSJobLevels(u16 *arg0, u8 *arg1);
void InitializeSomeUnitData(BattleUnit *arg0);
extern u8 D_80059414[];
extern u8 D_80065DE8[];
extern u8 D_80065DE9[];
extern u16 D_800661CE[];
extern StatusCheck StatusChecks[];
extern void DataNullifying(u8 *, s32);

void InitializeStatusCheckData(void) {
    s32 i;
    s32 off;
    s32 a0;
    s32 v0;
    s32 bit;
    u8 a1;
    u8 a2;

    DataNullifying(D_80059414, 0x80);
    DataNullifying((u8 *) StatusChecks, 0x37);
    i = 0;
    off = 0;
    do {
        a1 = D_80065DE8[off];
        a2 = D_80065DE9[off];
        v0 = i;
        if (i < 0) {
            v0 = i + 7;
        }
        a0 = v0 >> 3;
        bit = 0x80 >> (i & 7);
        if (a1 & 1) {
            StatusChecks[0].status[a0] = bit | StatusChecks[0].status[a0];
        }
        if (a1 & 2) {
            StatusChecks[1].status[a0] = bit | StatusChecks[1].status[a0];
        }
        if (a1 & 4) {
            StatusChecks[2].status[a0] = bit | StatusChecks[2].status[a0];
        }
        if (a1 & 0x80) {
            StatusChecks[3].status[a0] = bit | StatusChecks[3].status[a0];
        }
        if (a2 & 0x80) {
            StatusChecks[4].status[a0] = bit | StatusChecks[4].status[a0];
        }
        if (a2 & 1) {
            StatusChecks[5].status[a0] = bit | StatusChecks[5].status[a0];
        }
        if (a2 & 2) {
            StatusChecks[6].status[a0] = bit | StatusChecks[6].status[a0];
        }
        if (a2 & 4) {
            StatusChecks[7].status[a0] = bit | StatusChecks[7].status[a0];
        }
        if (a2 & 8) {
            StatusChecks[8].status[a0] = bit | StatusChecks[8].status[a0];
        }
        if (a2 & 0x10) {
            StatusChecks[9].status[a0] = bit | StatusChecks[9].status[a0];
        }
        off += 0x10;
        i += 1;
    } while (i < 0x28);
    StatusChecks[10].status[0] = 0x60;
    StatusChecks[10].status[1] = 0x85;
    StatusChecks[10].status[2] = 0x0E;
    StatusChecks[10].status[4] = 0x20;
}

void Unused(void) {
}

void ClearParty(void) {
    s32 i = 19;

    do {
        PartyData[i].partyId = 0xFF;
        i -= 1;
    } while (i >= 0);
}

Unit *GetPartyDataPointer(s32 arg0) {
    if (arg0 >= 0x14) {
        return 0;
    }
    return &PartyData[arg0];
}

extern ENTDEntry *D_80066238;
extern s32 UnitBattleInitialization(BattleUnit *, ENTDEntry *, s32, s32);
extern s32 SaveUnitToParty(u8 *, s32);

s32 UnitInitialization(u8 *entdBase, s32 index, s32 slotArg, s32 mode) {
    u8 buf[0x1C0];
    u8 *tmp;
    ENTDEntry *entd;

    tmp = buf;
    entd = (ENTDEntry *) (entdBase + index * 0x28);
    D_80066238 = entd;
    if (entd->sprite == 0) {
        return -2;
    }
    {
        u8 *tmp = buf;
        ((BattleUnit *) buf)->unitId2 = 0xFF;
        ((BattleUnit *) buf)->unitId = 0x20;
        ((BattleUnit *) buf)->existsFlag = 1;
        ((BattleUnit *) buf)->partyId = 0xFF;
        UnitBattleInitialization((BattleUnit *) tmp, entd, mode, 0);
        return SaveUnitToParty(tmp, slotArg);
    }
}

extern s32 FindFreePartyIndex();
extern void RemoveUnitFromParty(u32);
extern void StoreXByteIntoY(u8 *, u8 *, s32);

s32 SaveUnitToParty(u8 *src, s32 checkSave) {
    u8 palette;
    u8 *unit;
    s32 slot;
    register u8 *p asm("s2");
    s32 save;
    u8 sprite;
    s32 from;
    s32 party;
    u32 partyId;
    u16 birth;

    p = src;
    save = p[6] & 1;
    if ((p[0] >= 0x80) || (checkSave == 0)) {
        save = 0;
    }
    party = p[2];
    partyId = party & 0xFF;
    if ((save & 0xFF) != 0) {
        goto A;
    }
    if (((u32) (party - 0x10)) >= 4U) {
        goto A;
    }
    RemoveUnitFromParty(party);
    from = 0;
CALL1: {
    register s32 found asm("a0") = FindFreePartyIndex(from, &palette);
    slot = found;
    if (found == (-1))
        goto RETN;
    goto L2;
}
    goto L2;
A:
    if (partyId >= 0x15U) {
        from = save;
        goto CALL1;
    }

    FindFreePartyIndex(0, &palette);
    slot = partyId;
L2:
    unit = (u8 *) GetPartyDataPointer(slot);

    sprite = p[0];
    unit[1] = slot;
    unit[0] = sprite;
    unit[2] = p[3];
    if (slot >= 0x10) {
        unit[3] = p[4];
        unit[4] = p[6] & 0xFB;
    } else {
        unit[3] = palette;
        unit[4] = p[6] & 0xFA;
    }
    birth = ((*((volatile u16 *) (&p[8]))) & 0x1FF) | ((*((volatile u16 *) (&p[8]))) & 0xF000);
    unit[5] = birth;
    unit[6] = birth >> 8;
    StoreXByteIntoY(p + 0x13, unit + 7, 0x10);
    unit[0x17] = p[0x23];
    unit[0x18] = p[0x25];
    StoreXByteIntoY(p + 0x72, unit + 0x19, 0xF);
    StoreXByteIntoY(p + 0x96, unit + 0x28, 0xA6);
    unit[0xCE] = p[0x16C];
    unit[0xCF] = (*((u16 *) (&p[0x16C]))) >> 8;
    unit[0xD0] = 0;
    unit[0xD2] = 0;
    return 0;
RETN:
    return -1;
}

s32 FindFreePartyIndex(s32 arg0, u8 *arg1) {
    Unit *arr[0x14];
    s32 i;
    s32 count;
    s32 idx;
    Unit **p;

    *arg1 = 0;
    i = 0;
    p = arr;
    do {
        *p = GetPartyDataPointer(i);
        i++;
        p++;
    } while (i < 0x14);

    if (arg0 != 0) {
        idx = 0x10;
        count = 0x14;
    } else {
        idx = 0;
        count = 0x10;
    }
    i = idx;
    for (; i < count; i++) {
        if (arr[i]->partyId == 0xFF) {
            return i;
        }
    }
    return -1;
}

s32 CreateMonsterEgg(s32 job, s32 birthday, s32 eggType) {
    s32 temp_v0;
    unsigned int new_var;
    s32 var_s0;
    Unit *u;

    temp_v0 = GeneratePartyUnitInEmptySlot(3);
    var_s0 = birthday;
    if (temp_v0 != -1) {
        u = GetPartyDataPointer(temp_v0);
        u->job = job;
        u->battle[2] = eggType;
        u->gender = u->gender | 4;
        if ((u32) (var_s0 & 0xFFFF) >= 0x16EU) {
            if (var_s0 || eggType) {
                var_s0 = 1;
            } else {
                var_s0 = 1;
            }
        }
        new_var = CalculateZodiacSymbol(var_s0 & 0xFFFF) * 0x10;
        u->birthday = var_s0;
        u->zodiac = (((u32) (var_s0 & 0x100)) >> 8) + new_var;
        return temp_v0;
    }
    return -1;
}

s32 GeneratePartyUnitInEmptySlot(s32 arg0) {
    Unit *arr[0x14];
    s32 i;
    s32 zero;
    Unit **p;

    zero = 0;
    i = 0;
    p = arr;
    do {
        *p = GetPartyDataPointer(i);
        i++;
        p++;
    } while (i < 0x14);

    for (i = 0; i < 0x10; i++) {
        if (arr[i]->partyId == 0xFF) {
            arr[i]->partyId = i;
            arr[i]->palette = zero;
            func_80059FFC(arr[i], arg0);
            return i;
        }
    }
    return -1;
}

s32 FindUnitSPartyDataLocation(s32 arg0) {
    s32 a1;
    s32 a2;
    Unit *v1;
    u8 v0;

    a1 = 0;
    a2 = 0xFF;
    v1 = PartyData;
    do {
        v0 = v1->partyId;
        if (v0 == a2) {
            goto cont;
        }
        v0 = v1->sprite;
        if (v0 == arg0) {
            return a1;
        }
        v0 = a1;
cont:
        a1 += 1;
        v1 += 1;
    } while (a1 < 0x14);
    return -1;
}

void RemoveUnitFromParty(u32 arg0) {
    PartyData[arg0].partyId = 0xFF;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_5", func_80059FFC);

extern void GenerateUnitSBaseRawStats();

void GenerateUnitSBaseRawStatsPrep(Unit *arg0) {
    GenerateUnitSBaseRawStats(arg0->rawHp);
}

void PrepForGeneratingBaseRawStats(BattleUnit *arg0) {
    s32 a1;
    u8 v1 = arg0->gender;
    if (v1 & 0x80) {
        a1 = 0;
    } else {
        a1 = 3;
        if (v1 & 0x40) {
            a1 = 1;
        }
    }
    GenerateUnitSBaseRawStats(arg0->rawHp, a1);
}

extern u8 BaseData[];
extern u8 BaseRawRandomMod[];

void GenerateUnitSBaseRawStats(u8 *arg0, s32 arg1) {
    register s32 a1v asm("s4") = arg1;
    s32 i;
    u8 *b2base;
    register u8 *out asm("s1");
    u8 *p1base;
    u8 *p1v;
    s32 b;
    s32 r;
    s32 x;
    s32 a1c;

    s32 off;
    i = 0;
    b2base = BaseRawRandomMod;
    out = arg0;
    p1base = BaseData;
    a1c = a1v;
    off = a1c * 12;
    p1base = off + p1base;
    p1v = p1base;
    do {
        b = (*p1v) << 14;
        r = func_8002230C() * (*(b2base + (a1v * 5) + i));
        p1v += 1;
        i += 1;
        x = b + (r / 2);
        out[0] = x;
        out[1] = ((u32) x) >> 8;
        out[2] = x >> 16;
        out += 3;
    } while (i < 5);
}

void StoreXByteIntoY(u8 *, u8 *, s32);
extern Job *D_80066194;

void TransferJobSGrowthsMultsToUnit(BattleUnit *arg0) {
    StoreXByteIntoY(&D_80066194[arg0->job].hpGrowth, arg0->growth, 0xA);
}

extern Skillset Skillsets[];
extern MonsterSkillset D_80065854[];

s32 GetAbilityIDFromSkillset(s32 arg0, s32 arg1) {
    u8 *p;
    s32 a2;

    if (arg0 < 0xB0) {
        if (arg1 < 0x16) {
            u8 *pb = (u8 *) Skillsets;
            s32 sh;
            s32 l;
            a2 = arg1;
            p = pb + arg0 * sizeof(Skillset);
            if (arg1 < 0) {
                a2 = arg1 + 7;
            }
            sh = ((Skillset *) p)->flags[a2 >> 3] << (arg1 - (a2 >> 3) * 8 + 1);
            l = ((Skillset *) p)->abilities[arg1];
            return l | (sh & 0x100);
        }
    } else if (arg0 < 0xE0 && arg1 < 0x4) {
        u8 *pb = (u8 *) D_80065854;
        s32 sh;
        s32 l;
        a2 = arg1;
        p = pb + arg0 * sizeof(MonsterSkillset);
        if (arg1 < 0) {
            a2 = arg1 + 7;
        }
        sh = ((MonsterSkillset *) p)->flags[a2 >> 3] << (arg1 - (a2 >> 3) * 8 + 1);
        l = ((MonsterSkillset *) p)->abilities[arg1];
        return l | (sh & 0x100);
    }
    return 0;
}

extern u16 D_80066204[];

s16 *StoreSkillsetSAbilities(s32 arg0, s32 arg1) {
    s16 *p;
    s32 new_var;
    s32 f;
    s32 i;
    s32 n;
    s32 a;
    u32 v;
    s32 b;
    a = arg0;
    new_var = arg1;
    if (a >= 0x100) {
        a = 0;
    }
    n = 0;
    i = 0;
    p = D_80066204;
    do {
        f = GetAbilityIDFromSkillset(a, i);
        v = (u32) (f & 0xFFFF);
        if (v < 0x1A6U) {
            b = new_var & 1;
        } else if (v < 0x1C6U) {
            b = new_var & 2;
        } else if (v < 0x1E7U) {
            b = new_var & 8;
        } else {
            b = new_var & 4;
        }
        n += 1;
        if (b == 0) {
            f = 0;
        }
        *p = f;
        i += 1;
        p += 1;
    } while (i < 0x18);
    while (n < 0x18) {
        D_80066204[n] = 0;
        n += 1;
    }
    return D_80066204;
}

extern Ability1 AbilityData1[];
extern Ability2 AbilityData2[];
extern u16 D_80060D18[];
extern u8 D_80060EA0[];
extern u8 D_80060EA2[];
extern u8 D_80060EB6[];

s32 CalculateAbilityPointersAndType(s32 arg0, void **arg1, void **arg2) {
    arg0 &= 0x1FF;
    *arg1 = &AbilityData1[arg0];
    if (arg0 < 0x170) {
        *arg2 = &AbilityData2[arg0];
        return 0;
    }
    if (arg0 < 0x17E) {
        *arg2 = (void *) &D_80060EA0[arg0];
        return 1;
    }
    if (arg0 < 0x18A) {
        *arg2 = (void *) &D_80060EA2[arg0];
        return 2;
    }
    if (arg0 < 0x196) {
        *arg2 = (void *) &D_80060D18[arg0];
        return 3;
    }
    if (arg0 < 0x19E) {
        *arg2 = (void *) &D_80060D18[arg0];
        return 4;
    }
    if (arg0 < 0x1A6) {
        *arg2 = (void *) &D_80060EB6[arg0];
        return 5;
    }
    if (arg0 < 0x1C6) {
        *arg2 = (void *) &D_80060EB6[arg0];
        return 6;
    }
    if (arg0 < 0x1E6) {
        *arg2 = (void *) &D_80060EB6[arg0];
        return 7;
    }
    *arg2 = (void *) &D_80060EB6[arg0];
    return 8;
}

extern Item ItemData[];
extern Job JobData[160];

Item *GetItemDataPointer(u32 arg0) {
    return &ItemData[arg0 & 0xFF];
}

void *GetJobDataPointer(s32 arg0) {
    if (arg0 < 0xA0) {
        return &JobData[arg0];
    }
    return 0;
}

void EnableUnitSRSMFlags(BattleUnit *);
extern s32 D_80066200;

s32 InitializeUnitSJobData(BattleUnit *arg0, s32 arg1, s32 arg2) {
    Unit *u;

    D_80066200 = arg2;
    u = GetPartyDataPointer(arg1);
    if (u == 0) {
        return -1;
    }
    if (u->partyId == 0xFF) {
        return -1;
    }
    InitializeUnitSJobLevels(u->jobJpTotal, u->jobLevels);
    Store3ByteData(u->unlocked, CalculateUnlockedJobs(u->jobLevels, u->gender));
    InitializeSomeUnitData(arg0);
    arg0->partyId = arg1;
    InitializeUnitSBattleData(arg0, u);
    TransferJobSDataToUnitSData(arg0);
    EnableUnitSRSMFlags(arg0);
    CalculateActualStats(arg0, 0);
    EquippableItemSetting(arg0);
    EquipmentMoveJumpXNameStoringGeneration(arg0);
    return 0;
}

s32 UnitBattleInitialization(BattleUnit *arg0, ENTDEntry *arg1, s32 arg2, s32 arg3) {
    BattleUnit *s0 = arg0;
    ENTDEntry *s1 = arg1;
    s32 s2 = arg3;

    D_80066200 = arg2;
    if (s2 != 0x82) {
        InitializeSomeUnitData(arg0);
        if (func_8005AC1C(s0, s1) != 0) {
            return -1;
        }
    }
    if (s2 == 0) {
        if ((s1->gender & 8) != 0) {
            return 0;
        }
        if (s1->sprite < 4) {
            if (s1->birthMonth == 0) {
                return 0;
            }
        }
    }
    CalculateUnitJobsAndSkillsetsFromENTD(s0, s1);
    func_8005BA70(s0, s1);
    EnableUnitSRSMFlags(s0);
    PrepForGeneratingBaseRawStats(s0);
    TransferJobSGrowthsMultsToUnit(s0);
    if (s0->partyId == 0xFF) {
        s0->partyId = 0xFE;
    }
    CalculateActualStats(s0, 0);
    if (s0->partyId == 0xFE) {
        s0->partyId = 0xFF;
    }
    EquippableItemSetting(s0);
    if (s2 != 0x82) {
        if (s0->partyId >= 0x14) {
            func_8005BDF0(s0, s1);
        }
    }
    EquipmentMoveJumpXNameStoringGeneration(s0);
    StoreRamzaSNameBirthdayZodiac(s0);
    return 0;
}

void EquipmentStatSetting(BattleUnit *);
void EquipmentAttributeSetting();
void MoveJumpXCalculation(BattleUnit *, s32);
void StoreGenerateCharacterNames();

void EquipmentMoveJumpXNameStoringGeneration(void *arg0) {
    EquipmentStatSetting(arg0);
    EquipmentAttributeSetting(arg0, 1);
    MoveJumpXCalculation(arg0, 0);
    StoreGenerateCharacterNames(arg0);
}

void StoreRamzaSNameBirthdayZodiac(BattleUnit *arg0) {
    s32 i;
    register Unit *unit asm("a0");

    i = 0;
    if ((s32) arg0->sprite < 4) {
        do {
            GetPartyDataPointer(i);
            __asm__ volatile("move %0, $2" : "=r"(unit));
            if (unit->partyId != 0xFF) {
                i++;
                if ((s32) unit->sprite < 4) {
                    u8 *dst;
                    s32 len;
                    s32 sum;

                    __asm__ volatile("addiu %0, $17, 300" : "=r"(dst));
                    __asm__ volatile("ori %0, $zero, 16" : "=r"(len));
                    {
                        u32 u6;
                        __asm__ volatile(
                            "lbu %0, 6($4)\n\t"
                            "lbu %1, 5($4)\n\t"
                            "sll %0, %0, 8\n\t"
                            "addu %1, %1, %0"
                            : "=r"(u6), "=r"(sum)
                            :);
                    }
                    {
                        register s32 val asm("v0");
                        val = *(volatile u16 *) &arg0->birthday;
                        sum &= 0x1FF;
                        val &= 0xFE00;
                        val |= sum;
                        *(u16 *) &arg0->birthday = val;
                        val = (val & 0xFFF) | ((unit->zodiac >> 4) << 12);
                        *(u16 *) &arg0->birthday = val;
                        StoreXByteIntoY(&unit->name[0], dst, len);
                        return;
                    }
                }
            } else {
                i++;
            }
        } while (i < 0x14);
    }
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_5", func_8005AC1C);

s32 InitializeUnitSJobData(BattleUnit *, s32, s32);

s32 PrepForInitializingUnitSJobData(BattleUnit *arg0, ENTDEntry *arg1) {
    s32 r;

    r = FindUnitSPartyDataLocation(arg1->sprite);
    if (r == -1) {
        return -1;
    }
    InitializeUnitSJobData(arg0, r, D_80066200);
    arg0->gender &= 0xEE;
    arg0->gender |= arg1->gender & 0x11;
    arg0->entdFlags = arg1->flags;
    arg0->curAction[46] = arg1->flags;
    return 0;
}

void InitializeUnitSBattleData(BattleUnit *arg0, Unit *arg1) {
    BattleUnit *s1 = arg0;
    Unit *s0 = arg1;
    u8 v1;
    u8 tmp;
    u16 low;
    u16 high;
    u16 t0;
    s32 i;
    u8 *b;

    USE2(s1, s0);
    {
        u32 a;
        u8 b;
        __asm__ volatile("lbu %0, 0(%1)\n\tnop" : "=r"(a) : "r"(s0));
        v1 = 8;
        if (a < 4U) {
            v1 = 0xB;
        }
        s1->entdFlags = v1;
        s1->curAction[46] = v1;
        __asm__ volatile("lbu %0, 0(%1)\n\tnop" : "=r"(b) : "r"(s0));
        __asm__ volatile("sb %0, 0(%1)" : : "r"(b), "r"(s1));
    }
    s1->partyId = s0->partyId;
    s1->job = s0->job;
    v1 = s0->palette;
    if (s0->partyId < 0x10U) {
        v1 = 0;
    }
    s1->palette = v1;
    s1->gender = s0->gender;
    low = (((u8 *) &s0->birthday)[0] + (((u8 *) &s0->birthday)[1] << 8)) & 0x1FF;
    high = *(u16 *) &s1->birthday & 0xFE00;
    t0 = high | low;
    *(u16 *) &s1->birthday = t0;
    *(u16 *) &s1->birthday = (t0 & 0xFFF) | (((s0->zodiac >> 4) << 12));
    s1->secondarySkillset = s0->secondarySkillset;
    b = (u8 *) &s0->reaction;
    *(u16 *) &s1->reaction = b[0] + (b[1] << 8);
    b = (u8 *) &s0->support;
    *(u16 *) &s1->support = b[0] + (b[1] << 8);
    b = (u8 *) &s0->movement;
    *(u16 *) &s1->movement = b[0] + (b[1] << 8);
    StoreXByteIntoY((u8 *) &s0->head, (u8 *) &s1->head, 7);
    s1->exp = s0->exp;
    s1->level = s0->level;
    tmp = s0->brave;
    s1->brave = tmp;
    s1->origBrave = tmp;
    tmp = s0->faith;
    s1->faith = tmp;
    s1->origFaith = tmp;
    StoreXByteIntoY((u8 *) &s0->rawHp, (u8 *) &s1->rawHp, 0xF);
    i = 0;
    do {
        s1->unlocked[i] = s0->unlocked[i];
        i += 1;
    } while (i < 3);
    StoreXByteIntoY((u8 *) &s0->learned, (u8 *) &s1->learned, 0x39);
    StoreXByteIntoY((u8 *) &s0->jobLevels, (u8 *) &s1->jobLevels, 0xA);
    StoreXByteIntoY((u8 *) &s0->jobJp, (u8 *) &s1->jobJp, 0x50);
    StoreXByteIntoY((u8 *) &s0->name, (u8 *) &s1->unitName, 0x10);
    b = (u8 *) &s0->nameId;
    *(u16 *) &s1->nameId = b[0] + (b[1] << 8);
    DataNullifying((u8 *) &s1->aiX, 7);
}

extern u8 D_800660BA[];
extern int GetRandomUnlockedJob(BattleUnit *unit);

void CalculateUnitJobsAndSkillsetsFromENTD(u8 *arg0, u8 *arg1) {
    u8 *s0;
    u8 *s1;
    s32 a1;
    s32 t2;
    s32 a2;
    u32 a3;
    s32 t1;
    u8 *t0;
    s32 a0;
    s32 v0;
    s32 v1;
    s32 w1;
    s32 cFE;
    u8 *a3p;
    u8 *tab;
    u8 *tcall;

    s0 = arg0;
    s1 = arg1;
    tcall = s0 + 0xD2;
    __asm__ volatile("" ::"r"(s1));
    DataNullifying(tcall, 0xA);
    a1 = 0;
    if (s1 == 0) {
        TransferJobSDataToUnitSData(s0);
        s0[0x13] = 0;
        s0[6] = 0x20;
        Store3ByteData(s0 + 0x96, 0);
        return;
    }
    t2 = s1[1];
    if ((t2 & 0x20) == 0) {
        a2 = s1[8];
        a3 = a2 & 0xFF;
        if (a3 < 0x14) {
            v1 = s1[9] & 0xF;
            a0 = v1;
            if ((a2 & 1) == 0) {
                a0 = v1 << 4;
            }
            *(s0 + (a3 >> 1) + 0xD2) = a0;
            a2 = 0;
            t1 = a3;
            tab = D_800660BA;
            t0 = tab + a3 * 10;
            do {
                if (t1 != 0) {
                    a0 = *t0;
                } else if (a2 != 0) {
                    a0 = 0x11;
                } else {
                    a0 = 1;
                }
                a3p = s0 + a2;
                v1 = a0 | a3p[0xD2];
                a0 = v1;
                if ((v1 & 0xF) == 0) {
                    a0 = v1 | 1;
                }
                t0 += 1;
                if ((a0 & 0xF0) == 0) {
                    a0 |= 0x10;
                }
                a3p[0xD2] = a0;
                a2 += 1;
            } while (a2 < 0xA);
            if ((t2 & 0x40) != 0) {
                s0[0xDA] &= 0xF0;
            }
            if ((t2 & 0x80) != 0) {
                s0[0xDB] &= 0xF;
            }
            a1 = CalculateUnlockedJobs(s0 + 0xD2, t2);
        }
    }
    Store3ByteData(s0 + 0x96, a1);
    s0[3] = s1[0xA];
    TransferJobSDataToUnitSData(s0);
    a2 = s1[0x1D];
    v1 = a2 & 0xFF;
    if ((v1 != 0xFF) && (v1 != 0)) {
        s0[0x12] = a2;
        s0[0x189] = 0xFF;
    }
    a2 = s1[0xB];
    w1 = a2 & 0xFF;
    cFE = 0xFE;
    __asm__ volatile("" ::"r"(w1), "r"(cFE));
    v1 = w1;
    if (v1 == cFE) {
        if ((s0[6] & 0x20) != 0) {
            s0[0x13] = 0;
        } else {
            v0 = GetRandomUnlockedJob((BattleUnit *) s0);
            a0 = v0;
            v1 = a0 & 0xFF;
            if (v1 != 0) {
                v1 = D_80066194[v1].skillset;
            } else {
                KEEP(a0);
                v1 = a0 & 0xFF;
            }
            if (v1 == s0[0x12]) {
                v1 = 0;
            }
            s0[0x13] = v1;
        }
    } else {
        s0[0x13] = a2;
    }
}

s32 func_8002230C();

int GetRandomUnlockedJob(BattleUnit *unit) {
    s32 mask = 0x800000;
    s32 packed = (unit->unlocked[0] << 0x10) + (unit->unlocked[1] << 8) + unit->unlocked[2];
    s32 count = 0;
    s32 i = 0;
    u8 jobs[19];
    u8 *p = jobs;
    u8 ch;

    do {
        if (packed & mask) {
            ch = i + 0x4A;
            if (i == 0) {
                ch = unit->sprite;
                if (ch >= 0x80) {
                    ch = 0x4A;
                }
            }
            *p = ch;
            p += 1;
            count += 1;
        }
        i += 1;
        mask = mask / 2;
    } while (i < 0x13);

    if (count != 0) {
        s32 temp_lo = func_8002230C() * count;
        u32 idx = (u32) temp_lo >> 0xF;
        if (temp_lo < 0) {
            idx = (u32) (temp_lo + 0x7FFF) >> 0xF;
        }
        return jobs[idx & 0xFF];
    }
    return 0;
}

void TransferJobSDataToUnitSData(BattleUnit *arg0) {
    BattleUnit *s0 = arg0;
    Job *job;
    u8 v1;
    u8 j3;
    u16 t48;
    s32 a3;
    s32 a2;
    s32 a1;
    u8 *a0;

    USE(s0);
    v1 = s0->sprite;
    if (v1 < 0x4AU) {
        s0->specialSkillset = D_80066194[v1].skillset;
    } else {
        s0->specialSkillset = 0;
    }
    j3 = s0->job;
    job = &D_80066194[j3];
    s0->primarySkillset = job->skillset;
    StoreXByteIntoY((u8 *) job->innate, (u8 *) &s0->innate[0], 8);
    StoreXByteIntoY((u8 *) job->equip, s0->equip, 4);
    StoreXByteIntoY((u8 *) &job->hpGrowth, s0->growth, 0xA);
    s0->move = job->move;
    s0->jump = job->jump & 0x7F;
    if (job->jump & 0x80) {
        t48 = *(u16 *) &s0->y | 0x4000;
    } else {
        t48 = *(u16 *) &s0->y & 0xBFFF;
    }
    __asm__ volatile("sh %0, 72(%1)" : : "r"(t48), "r"(s0));
    StoreXByteIntoY((u8 *) job->innateStatus, (u8 *) &s0->innateStatus, 0xF);
    a3 = s0->entdFlags & 4;
    a2 = s0->gender & 9;
    if (a3 != 0) {
        a1 = 0;
        if (a2 != 0) {
            a0 = &s0->immunity[0];
            do {
                if (a3 != 0) {
                    *a0 |= ((u8 *) &StatusChecks)[0x19 + a1];
                }
                if (a2 != 0) {
                    *a0 |= ((u8 *) &StatusChecks)[0x1E + a1];
                }
                a1 += 1;
                a0 += 1;
            } while (a1 < 5);
        }
    }
    StoreXByteIntoY((u8 *) &job->absorb, (u8 *) &s0->absorb, 4);
    s0->strengthen = 0;
    s0->portrait = job->monsterPortrait;
    s0->pal = job->monsterPalette;
    s0->graphic = job->monsterGraphic;
}

extern void RSMFlagSetting(BattleUnit *, u32);

void EnableUnitSRSMFlags(BattleUnit *arg0) {
    s32 i;

    DataNullifying(arg0->reactions, 0xB);
    i = 0;
    do {
        RSMFlagSetting(arg0, arg0->innate[i]);
        i++;
    } while (i < 4);
    RSMFlagSetting(arg0, arg0->reaction);
    RSMFlagSetting(arg0, arg0->support);
    RSMFlagSetting(arg0, arg0->movement);
}

void RSMFlagSetting(BattleUnit *arg0, u32 arg1) {
    u32 sub;
    u32 orig;
    u8 *temp_a0;

    sub = arg1 - 0x1A6;
    orig = arg1;
    arg1 = sub & 0xFFFF;
    if (arg1 < 0x58) {
        sub = orig & 0xFFFF;
        if (sub < 0x1C6) {
            arg0->reaction = orig;
        }
        temp_a0 = arg0->reactions;
        temp_a0 += arg1 >> 3;
        *temp_a0 |= 0x80 >> (arg1 & 7);
    }
}

void CalculateActualStats(BattleUnit *arg0, s32 arg1) {
    BattleUnit *unit;
    s32 limit;
    u32 cap;
    register s32 odd asm("t5");
    s32 i;
    u8 *stat;
    u8 *growth;
    s32 level;
    s32 lowLevel;
    register u32 value asm("a0");
    u32 divisor;
    s32 k;
    s32 lastLevel;
    register u32 result asm("v0");
    s32 small;
    u32 high;

    unit = arg0;
    USE_NOVOL(unit);
    limit = 0x64;
    cap = 0x3E7;
    USE_NOVOL(cap);
    if (unit->gender & 4) {
        limit = 0xA;
        cap = 0xFFFF;
    }
    odd = arg1 & 1;
    i = 0;
    growth = unit->growth;
    level = unit->level;
    stat = unit->rawHp;
    lowLevel = level < 2;
    do {
        result = stat[1];
        value = stat[0];
        high = stat[2];
        __asm__("" : "=r"(value) : "0"(value), "r"(result), "r"(high));
        result <<= 8;
        value += result;
        high <<= 16;
        value += high;
        if (arg1 == 0 && unit->partyId == 0xFE) {
            divisor = growth[0];
            result = divisor;
            if (!divisor) {
                result = 1;
            }
            divisor = result;
            k = 2;
            lastLevel = level;
            if (!lowLevel) {
                do {
                    value += value / (divisor + k - 1);
                    k += 1;
                } while (lastLevel >= k);
            }
        }
        if (0xFFFFFF < value) {
            value = 0xFFFFFF;
        }
        divisor = 0x64;
        stat[1] = value >> 8;
        stat[0] = value;
        stat[2] = value >> 16;
        small = i < 2;
        result = growth[1];
        if (small) {
            divisor = limit;
        }
        result = (value * result) / divisor;
        value = result >> 14;
        if (value == 0) {
            value = 1;
        }
        if (small && cap < value) {
            value = cap;
        }
        if (i == 2 && value >= 0x33) {
            value = 0x32;
        }
        if (i >= 3 && value >= 0x64) {
            value = 0x63;
        }
        if ((u32) i >= 5) {
            goto next;
        }
        goto *jtbl_80059818[i];
case0:
        unit->maxHp = value;
        if (arg1 == 0) {
            unit->hp = value;
        }
        goto next;
case1:
        unit->maxMp = value;
        if (arg1 == 0) {
            unit->mp = value;
        }
        goto next;
case2:
        if (!odd) {
            unit->origSp = value;
        }
        goto next;
case3:
        if (!odd) {
            unit->origPa = value;
        }
        goto next;
case4:
        if (!odd) {
            unit->origMa = value;
        }
next:
        growth += 2;
        i += 1;
        stat += 3;
    } while (i < 5);
    __asm__ volatile("" ::"X"(&&case0), "X"(&&case1), "X"(&&case2), "X"(&&case3), "X"(&&case4));
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_5", func_8005BA70);

void MonsterEquipmentStoring(BattleUnit *arg0, ENTDEntry *arg1) {
    u8 v0;
    register u8 v1 asm("v1");

    v0 = arg1->rhEquip;
    v1 = 0xFF;
    arg0->rhShield = v1;
    arg0->rhWeapon = v0;
    v0 = arg1->lhEquip;
    arg0->lhShield = v1;
    arg0->lhWeapon = v0;
    v0 = arg1->helmet;
    arg0->head = v0;
    v0 = arg1->armor;
    arg0->body = v0;
    v0 = arg1->accessory;
    arg0->accessory = v0;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_5", func_8005BDF0);

void EquippableItemSetting(BattleUnit *arg0) {
    u8 t1;
    s32 m;
    t1 = arg0->supports[0];
    if (t1 & 0x80) {
        arg0->equip[2] = arg0->equip[2] | 9;
    }
    m = t1 & 0x40;
    if (m != 0) {
        arg0->equip[2] = arg0->equip[2] | 0x10;
    }
    m = t1 & 0x20;
    if (m != 0) {
        arg0->equip[0] = arg0->equip[0] | 0x10;
    }
    m = t1 & 0x10;
    if (m != 0) {
        arg0->equip[0] = arg0->equip[0] | 4;
    }
    m = t1 & 8;
    if (m != 0) {
        arg0->equip[1] = arg0->equip[1] | 0x10;
    }
    m = t1 & 4;
    if (m != 0) {
        arg0->equip[1] = arg0->equip[1] | 1;
    }
    m = t1 & 2;
    if (m != 0) {
        arg0->equip[0] = arg0->equip[0] | 2;
    }
    m = t1 & 1;
    if (m != 0) {
        arg0->equip[1] = arg0->equip[1] | 0x20;
    }
    t1 = arg0->gender;
    if (t1 & 0x40) {
        arg0->equip[2] = arg0->equip[2] | 0x42;
        arg0->equip[3] = arg0->equip[3] | 1;
    }
}

extern u8 D_80062EBB[];
extern u8 D_80062EBC[];
extern u8 D_80063F58[];
extern u8 D_80063EB8[];
extern u8 D_80063AB8[];

void EquipmentStatSetting(BattleUnit *arg0) {
    register BattleUnit *p asm("s0") = arg0;
    u8 *b62E8;
    s32 v;
    s32 tA;
    s32 tB;
    s32 idx1;
    s32 idx2;
    s32 idx3;
    s32 idx45;
    u8 *q;
    u8 *ptr;
    u8 *ptr1;
    u8 u;
    DataNullifying(&p->wp1, 0xB);
    v = p->job;
    p->cev = D_80066194[v].cev;
    if ((p->gender & 0x20) == 0) {
        b62E8 = (u8 *) ItemData;
        idx1 = p->accessory * 0xC;
        if (D_80062EBB[idx1] & 8) {
            u = D_80062EBC[idx1];
            ptr1 = (u * 2) + D_80063F58;
            p->accPev = ((AccessorySecondary *) ptr1)->pev;
            p->accMev = ((AccessorySecondary *) ptr1)->mev;
        }
        idx2 = p->rhShield * 0xC;
        q = idx2 + b62E8;
        if (((Item *) q)->typeFlags & 0x40) {
            u = D_80062EBC[idx2];
            ptr = D_80063EB8 + (u * 2);
            p->rhShieldPev = ((ShieldSecondary *) ptr)->pev;
            p->rhShieldMev = ((ShieldSecondary *) ptr)->mev;
        }
        idx3 = p->lhShield * 0xC;
        q = idx3 + b62E8;
        if (((Item *) q)->typeFlags & 0x40) {
            u = D_80062EBC[idx3];
            ptr = D_80063EB8 + (u * 2);
            p->lhShieldPev = ((ShieldSecondary *) ptr)->pev;
            p->lhShieldMev = ((ShieldSecondary *) ptr)->mev;
        }
        tA = p->rhWeapon;
        idx45 = tA * 0xC;
        q = idx45 + b62E8;
        if (((Item *) q)->typeFlags & 0x80) {
            ptr = (tA * 8) + D_80063AB8;
            p->wp1 = ((WeaponSecondary *) ptr)->power;
            p->weva1 = ((WeaponSecondary *) ptr)->evade;
        }
        tB = p->lhWeapon;
        idx45 = tB * 0xC;
        q = idx45 + b62E8;
        if (((Item *) q)->typeFlags & 0x80) {
            ptr = (tB * 8) + D_80063AB8;
            p->wp2 = ((WeaponSecondary *) ptr)->power;
            p->weva2 = ((WeaponSecondary *) ptr)->evade;
        }
    }
}

extern u8 D_80062EBD[];
extern u8 D_80063ED8[];
extern u8 D_80063ED9[];
extern u8 D_800642C4[];

void EquipmentAttributeSetting(u8 *arg0, s32 arg1) {
    register s32 s0 asm("s0") = arg1;
    u8 *s2 = arg0 + 0x33;
    u8 *a0;
    s32 t2;
    u8 *v0;
    u8 a1;
    u32 v1;
    u8 *t1;
    u8 *a3;
    u8 *t0;
    register u8 *pa2 asm("a2");
    s32 a12;
    s32 a12b;
    DataNullifying(s2, 3);
    CalculateActualStats(arg0, s0 + 1);
    s0 = 0x3E7;
    *(u8 *) (arg0 + 0x184) = 0;
    if ((*(u8 *) (arg0 + 6) & 0x20) == 0) {
        a0 = s2;
        t2 = 0;
        do {
            v0 = arg0 + t2;
            a1 = v0[0x1A];
            {
                u32 v0c = 0x20;
                v1 = a1 & 0xFF;
                if (v1 != v0c) {
                    goto chk80;
                }
                *(u8 *) (arg0 + 0x184) = *(u8 *) (arg0 + 0x184) | 4;
chk80:
                v0c = (v1 < 0x80);
                if (v0c == 0) {
                    goto skipEBD;
                }
                {
                    u32 idx = (v1 * 3) << 2;
                    u32 ev;
                    ev = D_80062EBD[idx];
                    ev -= 3;
                    if (ev < 2U) {
                        v1 = a1 & 0xFF;
                        *(u8 *) (arg0 + 0x184) = *(u8 *) (arg0 + 0x184) | 8;
                    }
                }
skipEBD:
                v1 = a1 & 0xFF;
            }
            if (v1 != 0xFF) {
                u8 *a2;
                u8 *t1;
                u8 *a3;
                u8 *t0;
                u32 idx2;
                a2 = a0;
                idx2 = (v1 * 3) << 2;
                t1 = ((u8 *) ItemData) + idx2;
                {
                    u32 uu = *(u8 *) (t1 + 7);
                    a3 = (uu * 0x19) + D_800642C4;
                }
                {
                    u8 *pa1 = a3;
                    s32 vsum;
                    pa2 = a0;
                    do {
                        register s32 cb1 asm("v0");
                        s32 cb2;
                        cb1 = *(u8 *) pa1;
                        cb2 = *pa2;
                        vsum = cb1 + cb2;
                        pa1 += 1;
                        if ((u32) vsum >= 0x100U) {
                            vsum = 0xFF;
                        }
                        *pa2 = vsum;
                        pa2 += 1;
                    } while ((s32) pa2 < (s32) (a2 + 3));
                }
                {
                    u32 v34 = *(u8 *) (a3 + 3) + *(u8 *) (arg0 + 0x3A);
                    if (v34 >= 0xFEU) {
                        v34 = 0xFD;
                    }
                    *(u8 *) (arg0 + 0x3A) = v34;
                }
                {
                    u32 v35 = *(u8 *) (a3 + 4) + *(u8 *) (arg0 + 0x3B);
                    if (v35 >= 8U) {
                        v35 = 7;
                    }
                    *(u8 *) (arg0 + 0x3B) = v35;
                    a12 = 0;
                    {
                        pa2 = arg0 + 0x4E;
                        do {
                            *pa2 = *(u8 *) (a3 + a12 + 5) | *pa2;
                            pa2 += 1;
                            a12 += 1;
                        } while (a12 < 0xF);
                    }
                }
                {
                    a12b = 0;
                    pa2 = arg0 + 0x6D;
                    do {
                        *pa2 = *(u8 *) (a3 + a12b + 0x14) | *pa2;
                        pa2 += 1;
                        a12b += 1;
                    } while (a12b < 5);
                }
                if (*(u8 *) (t1 + 3) & 0x30) {
                    register u32 v2a asm("v1");
                    register u32 idx4 asm("a1");
                    u32 v2e;
                    __asm__ volatile(
                        ".set\tnoreorder\n\t"
                        "lbu $2,4(%0)\n\t"
                        "lhu $3,0x2A(%1)\n\t"
                        "sll $5,$2,0x1\n\t"
                        ".set\treorder"
                        : : "r"(t1), "r"(arg0) : "$2", "$3", "$5");
                    v2a += D_80063ED8[idx4];
                    if (v2a > (u32) s0) {
                        v2a = s0;
                    }
                    *(u16 *) (arg0 + 0x2A) = v2a;
                    v2e = *(u16 *) (arg0 + 0x2E) + D_80063ED9[idx4];
                    if (v2e > (u32) s0) {
                        v2e = s0;
                    }
                    *(u16 *) (arg0 + 0x2E) = v2e;
                }
            }
            t2 += 1;
            v0 = arg0 + t2;
        } while (t2 < 7);
    }
    if (*(u16 *) (arg0 + 0x28) > *(u16 *) (arg0 + 0x2A)) {
        *(u16 *) (arg0 + 0x28) = *(u16 *) (arg0 + 0x2A);
    }
    if (*(u16 *) (arg0 + 0x2C) > *(u16 *) (arg0 + 0x2E)) {
        *(u16 *) (arg0 + 0x2C) = *(u16 *) (arg0 + 0x2E);
    }
    {
        u8 *pa1 = arg0 + 0x30;
        __asm__("addiu $6,%0,0x32" : : "r"(arg0) : "memory");
        {
            {
                u8 *pa0 = arg0 + 0x33;
                register u8 *pa2b asm("a2");
                s32 ix = 0;
                do {
                    u16 vsum = (u16) (*(u8 *) (pa1 + ix) + *(u8 *) (pa1 + ix + 3));
                    if ((s32) (pa1 + ix) < (s32) pa2b) {
                        if ((u32) vsum >= 0x64U) {
                            vsum = 0x63;
                        }
                    } else if (vsum >= 0x33U) {
                        vsum = 0x32;
                    }
                    *(u8 *) (pa1 + ix + 6) = vsum;
                    ix += 1;
                } while (ix < 3);
            }
        }
    }
}

void MoveJumpXCalculation(BattleUnit *arg0, s32 arg1) {
    s32 t1;
    s32 t2;
    s32 t3;

    if (arg1 == 0) {
        arg0->hp = arg0->maxHp;
        arg0->mp = arg0->maxMp;
    }
    t1 = arg0->move;
    t2 = arg0->movements[0];
    t3 = arg0->jump;
    if (t2 & 0x80) {
        t1 += 1;
    }
    if (t2 & 0x40) {
        t1 += 2;
    }
    if (t2 & 0x20) {
        t1 += 3;
    }
    if (t2 & 0x10) {
        t3 += 1;
    }
    if (t2 & 0x8) {
        t3 += 2;
    }
    if (t2 & 0x4) {
        t3 += 3;
    }
    if ((u32) (t1 & 0xFFFF) >= 0xFDU) {
        t1 = 0xFC;
    }
    if ((u32) (t3 & 0xFFFF) >= 8U) {
        t3 = 7;
    }
    arg0->move = t1;
    arg0->jump = t3;
}

void StoreGenerateCharacterNames(void *arg0, s32 arg1, s32 arg2) {
    u8 *unit;
    s32 tbl7;
    s32 elemsk;
    s32 ofs;
    register s32 base asm("s1");
    s32 found;
    s32 (*fn)(s32);
    Unit local;
    s32 a0;
    register s32 a1 asm("a1");
    s32 a2;
    u8 *b;
    register u8 *p1 asm("a1");
    register u8 *p2 asm("v1");
    s32 id0;
    s32 ff;
    s32 v0;
    s32 v1;

    unit = (u8 *) arg0;
    fn = D_80132824;
    if (D_80066200 != 0) {
        fn = func_800E6EDC;
    }
    a0 = unit[2];
    if (a0 == 0xFF) {
        id0 = unit[0x16C];
        base = 0x4000;
        if (id0 == 0xFF) {
            v1 = unit[6];
            a0 = v1 & 0xE0;
            if (v1 & 0x80) {
                base = 0x4100;
                ofs = 0x100;
            } else if (v1 & 0x40) {
                base = 0x4200;
                ofs = 0x200;
            } else {
                base = 0x4300;
                ofs = 0x300;
            }
            tbl7 = PartyData;
            ff = 0xFF;
            elemsk = a0 & 0xFF;
            do {
                found = 1;
                v0 = func_8002230C() * 0xFF;
                if (v0 < 0) {
                    v0 += 0x7FFF;
                }
                id0 = ofs + (v0 >> 15);
                a0 = id0 & 0xFFFF;
                a2 = 0;
                p1 = (u8 *) tbl7;
                for (; a2 < 0x14; a2++) {
                    b = p1 + 0xCE;
                    if (p1[1] != ff) {
                        if (elemsk == (p1[4] & 0xE0)) {
                            if ((b[0] | (b[1] << 8)) == a0) {
                                found = 0;
                                break;
                            }
                        }
                    }
                    p1 += 0x100;
                }
                a2 = 0;
                a1 = id0 & 0xFFFF;
                p2 = D_801908CC;
                for (; a2 < 0x15; a2++) {
                    if (elemsk == (p2[6] & 0xE0)) {
                        if (*(u16 *) (p2 + 0x16C) == a1) {
                            found = 0;
                            break;
                        }
                    }
                    p2 += 0x1C0;
                }
            } while (found == 0);
            *(u16 *) (unit + 0x16C) = id0;
        }
        a0 = id0 & 0xFF;
        v0 = fn(base + a0);
    } else {
        v0 = (s32) GetPartyDataPointer(a0) + 0xBE;
    }
    a0 = v0;
    StoreXIntoY(a0, unit + 0x12C, 0x10);
    v0 = fn(unit[3] | 0x3000);
    a0 = v0;
    StoreXIntoY(a0, unit + 0x13C, 0x10);
    v0 = fn(unit[0x12] | 0x1000);
    a0 = v0;
    StoreXIntoY(a0, unit + 0x14C, 8);
    v0 = fn(unit[0x13] | 0x1000);
    a0 = v0;
    StoreXIntoY(a0, unit + 0x154, 8);
    DataNullifying(unit + 0x1A7, 0xA);
}

extern u8 D_80066308;

s32 CalculateHighestPartyLevel(void) {
    u8 level = 0;
    s32 idx = 0;
    volatile Unit *p;

    do {
        p = GetPartyDataPointer(idx);
        idx++;
        if (p->partyId != 0xFF && (u32) level < p->level) {
            level = p->level;
        }
    } while (idx < 0x14);
    if ((u32) level >= 0x64) {
        level = 0x63;
    }
    D_80066308 = level;
    return level;
}

void StoreXIntoY(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < arg2; i++) {
        *arg1++ = *arg0++;
    }
}

extern u8 D_80063AB9[];

u8 CalculateRandomEquipment(u8 *unit, u8 category, u8 flags, u8 itemType) {
    u8 items[128];
    s32 first;
    s32 end;
    s32 i;
    u8 count;
    u32 best;
    u32 level;
    Item *item;
    u32 type;
    u32 required;
    register u32 bits asm("a0");
    s32 test;
    register u8 *secondary asm("v0");
    s32 product;
    u32 index;

    switch (category) {
    case 0x80:
        first = 1;
        end = 0x80;
        break;
    case 0x40:
        first = 0x80;
        end = 0x90;
        break;
    case 0x20:
        first = 0x90;
        end = 0xAC;
        break;
    case 0x10:
        first = 0xAC;
        end = 0xD0;
        break;
    case 8:
        first = 0xD0;
        end = 0xF0;
        break;
    default:
        first = 0;
        end = 0x100;
        break;
    }
    count = 0;
    i = first;
    level = unit[0x22];
    best = 0;
    for (; i < end; i++) {
        item = &ItemData[i];
        type = item->typeFlags;
        test = type & 2;
        if (!test) {
            type = item->itemType;
            if (itemType == 0xFF || type == itemType) {
                type &= 0xFF;
                bits = (unit + (type >> 3))[0x4A];
                bits &= 0x80 >> (type & 7);
                if (bits) {
                    if (flags == 0 || (secondary = D_80063AB9, flags & secondary[item->secondId * 8])) {
                        required = item->reqLevel;
                        KEEP_NOVOL(required);
                        bits = required & 0xFF;
                        if (level >= bits) {
                            test = best < bits;
                            if (test) {
                                best = required;
                                count = 0;
                            }
                            items[count++] = i;
                        }
                    }
                }
            }
        }
    }
    if (count != 0) {
        product = func_8002230C() * count;
        index = (u32) product >> 15;
        if (product < 0) {
            index = (u32) (product + 0x7FFF) >> 15;
        }
        return items[(u8) index];
    }
    return 0xFE;
}

INCLUDE_ASM("rom/extracted/asm/nonmatchings/main_5", func_8005CE74);

u16 CalculateUnitSRSM(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    u16 arr[480];
    u16 filt[4];
    u8 b3D8[8];
    register u8 b3dtmp asm("t3");
    s32 a2v;
    s32 a3v;
    s32 a0v;
    s32 s0;
    s32 s1;
    s32 s2v;
    s32 s3;
    s32 s4;
    s32 s5;
    s32 s7v;
    u8 *fpv;
    s32 t1v;
    s32 v1v;
    u16 *vp;
    u16 *ap;
    u16 v0v;
    s32 r;
    s32 tmp;
    u32 mk;
    arg1 &= 0xFFFF;
    if (arg1 < 0x1FEU) {
        return arg1;
    }
    if ((arg0[6] & 0x20) != 0) {
        return 0;
    }
    s3 = 0;
    ap = (u16 *) arg0;
    vp = arr;
    do {
        v0v = ap[5];
        ap += 1;
        s3 += 1;
        vp[0x1E0] = v0v;
        vp += 1;
    } while (s3 < 4);
    s4 = 0;
    a3v = 1;
    a2v = arg0[0x13];
    s3 = 0;
    fpv = arg0;
    do {
        s2v = 0;
        s5 = 1;
        if (s3 == 0x13) {
            if (a3v == 0) {
                goto next_outer;
            }
            s2v = a2v;
            if (s2v == 0) {
                goto next_outer;
            }
            s5 = 0;
        } else {
            t1v = s3 + 0x4A;
            if (s3 == 0) {
                v1v = arg0[0];
                if ((u32) ((v1v - 0x80) & 0xFF) >= 2U) {
                    t1v = v1v;
                }
                v1v = arg3[0x1D];
                MEMORY_BARRIER();
                if ((v1v != 0) && (v1v != 0xFF)) {
                    s2v = arg3[0x1D];
                }
            }
        }
        if (s2v == 0) {
            v1v = t1v & 0xFF;
            if (v1v == 0) {
                goto next_outer;
            }
            s2v = D_80066194[v1v].skillset;
        }
        if (s2v == a2v) {
            a3v = 0;
        }
        SCHED_BARRIER();
        s0 = 0x10;
        if (s5 != 0) {
            b3dtmp = fpv[0x9B];
            b3D8[0] = b3dtmp;
        }
        s7v = b3D8[0];
        do {
            if ((s5 == 0) || ((s7v & (0x80 >> (s0 % 8))) != 0)) {
                s1 = 0;
                a0v = GetAbilityIDFromSkillset(s2v & 0xFF, s0);
                r = a0v & 0xFFFF;
                if ((r != 0x1A9) && (r != filt[0]) && (r != filt[1]) && (r != filt[2]) && (r != filt[3])) {
                    if ((arg2 & 2) != 0) {
                        mk = (a0v - 0x1A6) & 0xFFFF;
                        s1 = ((u32) mk < 0x20U);
                    }
                    if ((arg2 & 4) != 0) {
                        if (((u32) ((a0v - 0x1C6) & 0xFFFF) < 0x20U) != 0) {
                            s1 = 1;
                        }
                    }
                    if ((arg2 & 8) != 0) {
                        if (((u32) (a0v & 0xFFFF) >= 0x1E6U) != 0) {
                            s1 = 1;
                        }
                    }
                    if (s1 != 0) {
                        arr[s4] = a0v;
                        s4 += 1;
                    }
                }
            }
            s0 += 1;
        } while (s0 < 0x16);
next_outer:
        s3 += 1;
        fpv += 3;
    } while (s3 < 0x14);
    if (s4 == 0) {
        return 0;
    }
    tmp = func_8002230C() * s4;
    if (tmp < 0) {
        tmp += 0x7FFF;
    }
    return arr[tmp >> 15];
}

s32 FindSkillsetSJobID(u8 arg0) {
    u8 i;

    i = 0;
    while (i < 0x9F) {
        if (D_80066194[i].skillset == arg0) {
            return i;
        }
        i++;
    }
}

void NullifyCTInitializeDeathCounter(BattleUnit *, s32);
void FloatCurrentStatusesStatusImmunitiesStatusCT(BattleUnit *);
s32 StatusCTSetting(BattleUnit *, s32, s32);

void StatusInitialization(BattleUnit *arg0) {
    s32 i = 0;
    do {
        arg0->curAction[CURACTION_INFLICT + i] = arg0->curStatus[i] & ~arg0->innateStatus[i];
        i += 1;
    } while (i < 5);
    NullifyCTInitializeDeathCounter(arg0, i);
    FloatCurrentStatusesStatusImmunitiesStatusCT(arg0);
}

void NullifyCTInitializeDeathCounter(BattleUnit *arg0, s32 arg1) {
    DataNullifying(arg0->statusCt, 0x10);
    if (arg0->entdFlags & 4) {
        arg0->deathCounter = 0xFF;
    } else if (arg0->gender & 9) {
        arg0->deathCounter = 0xFF;
    } else {
        arg0->deathCounter = 3;
    }
}

void FloatCurrentStatusesStatusImmunitiesStatusCT(BattleUnit *arg0) {
    u8 *s1 = (u8 *) arg0;
    u8 new_var;
    s32 s0 = 0;
    s32 s2;
    u8 *a1;
    if ((s1[0x95] & 8) != 0) {
        s1[0x50] |= 0x40;
    }
    do {
        a1 = s1 + s0;
        s0 += 1;
        new_var = (unsigned char) a1[0x4E];
        a1[0x53] = a1[0x53] & (~new_var);
        a1[0x58] = a1[0x4E] | a1[0x1BB];
    } while (new_var = s0 < 5);
    s0 = 0x18;
    s2 = 0x80;
    do {
        s32 v0;
        s32 v1;
        s32 d;
        s32 b;
        d = s0 / 8;
        b = s0 & (7 & 0xFFFF);
        v0 = (s1 + d)[0x1BB];
        v1 = s2 >> b;
        {
            s32 t1 = s0;
            if ((v0 & v1) != 0) {
                if ((s1 + s0)[0x45] == 0) {
                    if (s2) {
                        StatusCTSetting((BattleUnit *) s1, t1, 0);
                    } else {
                        StatusCTSetting((BattleUnit *) s1, t1, 0);
                    }
                }
            }
        }
        s0 += 1;
    } while (s0 < 0x28);
}

extern void StatusSettingCheckingEquipRSMStats(s32, s32, s32);

void StatusSettingCheckingEquipRSMStatsPrep(s32 arg0) {
    StatusSettingCheckingEquipRSMStats(arg0, 1, 0);
}

void StatusSettingCheckingEquipRSMStatsPrep2(s32 arg0) {
    StatusSettingCheckingEquipRSMStats(arg0, 0, 0);
}

void StatusSettingCheckingEquipRSMStatsPrep3(s32 arg0) {
    StatusSettingCheckingEquipRSMStats(arg0, 0, 1);
}

void StatusSettingCheckingEquipRSMStats(s32 arg0, s32 arg1, s32 arg2) {
    s32 s2;
    s32 s1;
    s32 s3;
    s32 s4;
    register s32 s0 asm("s0");
    s32 s2c;
    u8 buf[13];
    u8 *p0;
    u8 *p1;
    s32 p2;
    s32 p3;
    s32 i0;
    s32 i1;
    register s32 v0 asm("v0");
    register s32 v1 asm("v1");

    s1 = arg0;
    s2 = arg1;
    s3 = arg2;
    s4 = *(u8 *) (s1 + 0x18A);
    StoreCurrentStatuses((u8 *) s1);
    s0 = 0;
    p1 = buf;
    p0 = buf + 8;
    while (s0 < 5) {
        v1 = s1 + s0;
        *p0 = *(u8 *) (v1 + 0x58);
        *p1 = *(u8 *) (v1 + 0x1BB);
        p0++;
        p1++;
        s0++;
    }
    v0 = *(u8 *) (s1 + 3);
    s0 = v0 * 3 * 16 + (s32) D_80066194;
    v0 = *(u8 *) (s0 + 0x17);
    *(u8 *) (s1 + 0x3A) = v0;
    v0 = *(u8 *) (s0 + 0x18) & 0x7F;
    *(u8 *) (s1 + 0x3B) = v0;
    StoreXIntoY((u8 *) (s0 + 9), (u8 *) (s1 + 0x4A), 4);
    StoreXIntoY((u8 *) (s0 + 0x1A), (u8 *) (s1 + 0x4E), 0xF);
    StoreXIntoY((u8 *) (s0 + 0x29), (u8 *) (s1 + 0x6D), 4);
    *(u8 *) (s1 + 0x71) = 0;
    EnableUnitSRSMFlags((BattleUnit *) s1);
    MoveJumpXCalculation((BattleUnit *) s1, 1);
    EquipmentStatSetting((BattleUnit *) s1);
    EquipmentAttributeSetting((void *) s1, 0);
    EquippableItemSetting(s1);
    p2 = (s32) buf;
    v1 = s1;
    p3 = (s32) (buf + 5);
    do {
        if (s3 != 0) {
            *(u8 *) (v1 + 0x1BB) = *(u8 *) (v1 + 0x58);
        } else {
            *(u8 *) (v1 + 0x1BB) = *(u8 *) p2;
        }
        p2++;
        v1++;
    } while (p2 < p3);
    s0 = *(u8 *) (s1 + 2);
    *(u8 *) (s1 + 2) = 0xFF;
    FloatCurrentStatusesStatusImmunitiesStatusCT((BattleUnit *) s1);
    *(u8 *) (s1 + 2) = s0;
    StoreCurrentStatuses((u8 *) s1);
    if (s2 != 0) {
        return;
    }
    {
        v0 = *(u16 *) (s1 + 0x2A);
        v0 = (u16) (v0 / 5u);
        v1 = *(u16 *) (s1 + 0x28);
        if ((u32) v0 >= (u32) v1) {
            v0 = *(u8 *) (s1 + 0x1BD) | 1;
            goto l_1bd;
        }
        v0 = *(u8 *) (s1 + 0x1BD) & 0xFE;
l_1bd:
        *(u8 *) (s1 + 0x1BD) = v0;
        StoreCurrentStatuses((u8 *) s1);
        s0 = 0;
        s2c = 1;
        for (s0 = 0; s0 < 0x28; s0++) {
            v0 = s0;
            if (s0 < 0) {
                v0 = s0 + 7;
            }
            v0 = v0 >> 3;
            v1 = 128 >> (s0 & 7);
            p0 = buf + v0 + 8;
            p1 = (u8 *) (s1 + v0 + 0x58);
            i0 = *p0 & v1;
            i1 = *p1 & v1;
            if (s3 != 0 || i0 != i1) {
                if (i1 != 0) {
                    if (s3 != 0) {
                        StatusCTSetting((BattleUnit *) s1, s0, 0);
                    }
                    func_8018E9BC(s2c, 1, s4);
                } else {
                    func_8018E9BC(s2c, 0, s4);
                }
            }
            s2c++;
        }
    }
}

extern void LevelUpSection(void *, s32);

s32 CheckUnitLeveledUp(void *arg0) {
    register Unit *p asm("s0") = (Unit *) arg0;
    u8 temp_s1;

    __asm__ volatile("" : : : "a0");
    if (p->rawSp[2] >= 0x64) {
        temp_s1 = p->rawPa[0];
        if (temp_s1 < 0x63) {
            LevelUpSection(p, 0);
            p->rawSp[2] = 0;
            p->rawPa[0] = temp_s1 + 1;
            return 1;
        }
        p->rawSp[2] = 0x63;
        return 0;
    }
    return 0;
}

s32 LevelUnitToSpecificLevel(Unit *arg0, s32 arg1) {
    u8 *t0;
    u8 a0b;
    u8 v1b;
    s32 a2;
    u8 *t5;
    u8 *t6;
    s32 t3;
    s32 t1;
    u32 t4;
    volatile u8 *a1;
    u8 *a3;
    u8 *t2;
    u32 b0;
    u32 b1;
    u32 v0b;
    s32 v0;
    u32 new_var;
    u32 s0;
    u32 denom;
    u32 quot;

    t0 = (u8 *) arg0;
    v1b = arg0->job;
    a0b = arg0->level;
    a2 = a0b + arg1;
    t6 = &arg0->rawHp[0];
    t5 = (u8 *) &D_80066194[arg0->job].hpGrowth;
    if ((u32) a2 >= 0x64U) {
        a2 = 0x63;
    }
    t3 = a2 - a0b;
    if (t3 <= 0) {
        return a2;
    }
    t4 = 0xFFFFFF;
    for (t1 = 0; t1 < t3; t1++) {
        a1 = t6;
        a3 = t5;
        t2 = a1 + 0xF;
        do {
            b1 = a1[1];
            a2 = arg0->level;
            b0 = a1[0];
            v0 = b1;
            new_var = b1 << 8;
            v0 = new_var;
            v0b = *a3;
            s0 = (b0 + v0) + (a1[2] << 16);
            if (v0b == 0) {
                denom = a2 + 1;
            } else {
                denom = a2 + v0b;
            }
            quot = s0 / denom;
            s0 += quot;
            a3 += 2;
            if (s0 > 0xFFFFFFU) {
                s0 = 0xFFFFFF;
            }
            a1[1] = s0 >> 8;
            a1[0] = s0;
            a1[2] = s0 >> 16;
            a1 += 3;
        } while ((s32) a1 < (s32) t2);
        arg0->level = arg0->level + 1;
    }
    return arg0->level;
}

void LevelUpSection(void *arg0, s32 arg1) {
    u8 *a0 = (u8 *) arg0;
    u8 *s5;
    volatile u8 *s2;
    u8 *s4;
    u32 s7;
    u32 s0;
    u32 new_var;
    u32 s1d;
    s32 v0;
    u32 v0b;
    u32 vv;
    u32 b0;
    u32 b1;
    s32 aq;

    s7 = a0[0x22];
    s5 = a0 + 0x72;
    aq = arg1;
    s2 = s5;
    s4 = a0 + 0x81;
    do {
        b1 = s2[1];
        b0 = s2[0];
        v0 = b1;
        new_var = b1 << 8;
        v0 = new_var;
        v0b = *s4;
        s0 = (b0 + v0) + (s2[2] << 16);
        vv = v0b;
        s1d = v0b;
        if (s1d == 0) {
            vv = 1;
        }
        s1d = vv + s7;
        func_8002230C(v0);
        if (aq != 0) {
            s0 = s0 - s0 / s1d;
        } else {
            s0 = s0 + s0 / s1d;
        }
        s4 += 2;
        if (0xFFFFFF < s0) {
            s0 = 0xFFFFFF;
        }
        s2[1] = s0 >> 8;
        s2[0] = s0;
        s2[2] = s0 >> 16;
        s2 += 3;
    } while ((s32) s2 < (s32) (s5 + 0xF));
    StatusSettingCheckingEquipRSMStatsPrep2((s32) a0);
    if (*(u16 *) (a0 + 0x28) > *(u16 *) (a0 + 0x2A)) {
        *(u16 *) (a0 + 0x28) = *(u16 *) (a0 + 0x2A);
    }
    if (*(u16 *) (a0 + 0x2C) > *(u16 *) (a0 + 0x2E)) {
        *(u16 *) (a0 + 0x2C) = *(u16 *) (a0 + 0x2E);
    }
}

extern u8 D_80065DE7[];

s32 StatusCTSetting(BattleUnit *arg0, s32 arg1, s32 arg2) {
    register s32 t0 asm("t0");
    register s32 r asm("a0");
    s32 v0;

    if (arg1 == 2) {
        if (arg0->entdFlags & 4)
            v0 = 0xFF;
        else {
            v0 = arg0->gender & 9;
            if (v0)
                v0 = 0xFF;
            else
                v0 = 3;
        }
        arg0->deathCounter = v0;
    }
    r = arg1 - 0x18;
    if ((u32) r >= 0x10U)
        return 0;
    t0 = r;
    if (arg2 != 0) {
        register u8 *qa asm("v0") = (u8 *) arg0 + t0;

        *(qa + 0x5D) = 0;
        SCHED_BARRIER();
        return 0;
    }
    if (t0 == 0xF) {
        if (((u8 *) arg0)[0x6C] != 0) {
            v0 = -1;
            return v0;
        }
    }
    v0 = 0;
    r = D_80065DE7[arg1 * 16];
    {
        register u8 *qt asm("v1") = (u8 *) arg0 + t0;

        *(qt + 0x5D) = r;
    }
    return v0;
}

extern JobUnlockRow D_800660C4[];

s32 CalculateUnlockedJobs(u8 *arg0, u8 arg1) {
    u8 buf[18];
    s32 i;
    s32 j;
    s32 mismatch;
    s32 mask;
    u32 acc;
    JobUnlockRow *row;

    for (i = 0; i < 10; i++) {
        buf[i] = arg0[i];
    }
    if ((arg1 & 0x40) != 0) {
        buf[8] |= 0xF;
    }
    if (arg1 & 0x80) {
        buf[9] |= 0xF0;
    }
    if ((arg1 & 0x20) != 0) {
        return 0;
    }
    mask = 0x800000;
    acc = 0x800000;
    i = 0;
    row = D_800660C4;
    while (i < 0x13) {
        mask /= 2;
        mismatch = 0;
        for (j = 0; j < 10; j++) {
            if (((row->req[j] & 0xF0) > (buf[j] & 0xF0)) ||
                ((row->req[j] & 0xF) > (buf[j] & 0xF))) {
                mismatch = 1;
                break;
            }
        }
        if (mismatch == 0) {
            acc |= mask;
        }
        row += 1;
        i++;
    }
    if ((arg1 & 0x80) != 0) {
        acc &= 0x00FFFFD0;
    }
    if ((arg1 & 0x40) != 0) {
        acc &= 0x00FFFFB0;
    }
    mismatch = acc;
    return mismatch;
}

s32 PropositionJPGain(u32 arg0, s32 arg1) {
    register s32 s2 asm("s2") = arg1;
    Unit *s1;
    register s32 s0 asm("s0");
    s32 job;
    u8 *a1;
    s32 v1;
    s32 v0;
    u8 old;
    s32 newb;
    u8 *new_var;
    u8 new96;
    s32 s0c;
    s32 lvl;
    register s32 lvlE asm("a1");
    register s32 mt asm("v0");
    if (s2 < 0) {
        return -1;
    }
    if (arg0 >= 0x14) {
        return -1;
    }
    s1 = GetPartyDataPointer(arg0);
    if (s1->partyId == 0xFF) {
        return -1;
    }
    if (s1->gender & 0x20) {
        return -1;
    }
    s0 = 0;
    job = s1->job;
    if (((u32) (((unsigned short) job) - 0x4A)) < 0x14) {
        SCHED_BARRIER();
        s0 = job - 0x4A;
    }
    a1 = ((u8 *) s1) + (s0 * 2);
    v1 = (a1[0x6E] + (a1[0x6F] << 8)) + s2;
    if (v1 >= 0x2710) {
        v1 = 0x270F;
    }
    a1[0x6E] = v1;
    if (v1 < 0) {
        v0 = v1 + 0xFF;
    } else {
        v0 = v1;
    }
    new96 = a1[0x96];
    a1[0x6F] = v0 >> 8;
    v1 = (new96 + (a1[0x97] << 8)) + s2;
    if (v1 >= 0x2710) {
        v1 = 0x270F;
    }
    a1[0x96] = v1;
    if (v1 < 0) {
        v0 = v1 + 0xFF;
    } else {
        v0 = v1;
    }
    a1[0x97] = v0 >> 8;
    lvl = CalculateJobLevel(v1 & 0xFFFF);
    s0c = s0;

    s0c = s0;
    {
        s32 idx = s0c / 2;
        new_var = ((u8 *) s1) + idx;
        new_var = &new_var[0x64];
        old = *new_var;
    }
    s1++;
    s1--;
    lvlE = lvl;

    if (s0c & 1) {
        mt = old & 0xF0;
        newb = lvl + mt;
    } else {
        newb = old & 0xF;
        mt = lvlE & 0xFF;
        mt <<= 4;
        newb |= mt;
    }
    (((u8 *) s1) + (s0c / 2))[0x64] = newb;
    ;
    Store3ByteData(s1->unlocked, CalculateUnlockedJobs(s1->jobLevels, s1->gender));
    return 0;
}

void Store3ByteData(u8 *arg0, u32 arg1) {
    *arg0++ = (u8) (arg1 >> 16);
    *arg0++ = (u8) (arg1 >> 8);
    *arg0 = (u8) arg1;
}

extern JpReqLevels D_80066184;

s32 CalculateJobLevel(s32 arg0) {
    register s32 var_a1 asm("a1");
    s32 var_a2;
    u16 *var_v1;

    var_a2 = 0;
    var_a1 = 0;
    arg0 &= 0xFFFF;
    var_v1 = D_80066184.level;
    do {
        if ((u32) arg0 >= *var_v1) {
            var_a2 += 1;
        }
        var_v1 += 1;
        var_a1 += 1;
    } while (var_a1 < 8);
    return var_a2;
}

void InitializeUnitSJobLevels(u16 *arg0, u8 *arg1) {
    s32 var_s3;
    u8 *var_s2;
    u16 *var_s1;
    s32 temp_v0;
    s32 var_s0;
    u16 temp_a0;

    var_s3 = 0;
    var_s2 = arg1;
    var_s1 = arg0;
    do {
        var_s3 += 1;
        temp_v0 = CalculateJobLevel(*var_s1);
        temp_a0 = var_s1[1];
        var_s1 += 2;
        var_s0 = temp_v0 << 4;
        *var_s2 = var_s0 | CalculateJobLevel(temp_a0);
        var_s2 += 1;
    } while (var_s3 < 0xA);
}

void InitializeSomeUnitData(BattleUnit *arg0) {
    arg0->curAction[44] = 0;
    arg0->curAction[45] = 0;
    arg0->ct = 0;
    arg0->charTurn = 0;
    arg0->waterFlags = 0;
    arg0->abilityCt = 0xFF;
    arg0->mountInfo = 0;
    arg0->unk15C = 0;
}

void StatusInitialization(BattleUnit *);

void MinimumSPCappingWarTrophyNullingStatusInitialization(BattleUnit *arg0, s32 arg1) {
    if (arg0->sp == 0)
        arg0->sp = 1;
    if (arg1 != 0) {
        arg0->warTrophy = 0;
        arg0->bonusMoney = 0;
    }
    StatusInitialization(arg0);
}

u8 GetAbilitySRange(u32 arg0) {
    arg0 &= 0xFFFF;
    if (arg0 >= 0x170) {
        return 0;
    }
    return AbilityData2[arg0].range;
}

u8 GetAbilitySAoE(u32 arg0) {
    arg0 &= 0xFFFF;
    if (arg0 >= 0x170) {
        return 0;
    }
    return AbilityData2[arg0].aoe;
}

s32 GetUnitSPortraitPalette(BattleUnit *, u8 *);

s32 CalculateUnitSPalettePortrait(BattleUnit *arg0, u8 *arg1) {
    s32 v0 = GetUnitSPortraitPalette(arg0, arg1);
    arg0->portrait = v0;
    v0 &= 0xFF;
    arg0->pal = *arg1;
    return v0;
}

s32 PassFailRoll(s32 arg0, s32 arg1) {
    return ((s32) (func_8002230C(arg0) * arg0) / 32768) >= arg1;
}

s32 GetUnitSPortraitPalette(BattleUnit *arg0, u8 *arg1) {
    u8 a2;
    u8 v1;
    int new_var;
    arg1[0] = 0;
    a2 = arg0->job;
    v1 = arg0->sprite & 0xFF;
    if ((u32) (a2 - 0x5C) < 2U) {
        a2 -= 1;
    }
    new_var = 0xFE;
    if (v1 < 0x80U) {
        return v1;
    }
    if (v1 == 0x80) {
        v1 = ((a2 & 0xFF) * 2) - 0x34;
        return v1 & new_var;
    }
    if (v1 == 0x81) {
        v1 = ((a2 & 0xFF) * 2) - 0x33;
        return v1 & 0xFF;
    }
    if (v1 == 0x82) {
        arg1[0] = arg0->pal;
        return arg0->portrait;
    } else {
        v1 = a2 + 0x28;
        return v1 & 0xFF;
    }
}

s32 DoesUnitHaveStatusInSet(BattleUnit *arg0, s32 arg1) {
    s32 i = 0;
    u8 *q = (u8 *) &StatusChecks;

    q += arg1 * 5;
    for (; i < 5; i++) {
        if (arg0->curStatus[i] & q[i]) {
            return 1;
        }
    }
    return 0;
}

s32 GetKnownAbilities(BattleUnit *arg0, s32 arg1) {
    s32 base = arg1 * 3;
    return (arg0->learned[base] << 16) + (arg0->learned[base + 1] << 8) | arg0->learned[base + 2];
}

void CopyByteData(u8 *arg0, u8 *arg1) {
    u32 i = 0;

    do {
        *arg1++ = *arg0++;
        i++;
    } while (i < 0x14);
}

void StoreXByteIntoY(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < arg2; i++) {
        *arg1++ = *arg0++;
    }
}

extern u8 ItemQuantities[];

s32 GetTotalEquipmentQuantity(s32 arg0, s32 arg1) {
    Unit *GetPartyDataPointer(s32);
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 s4;
    s32 s5;
    u8 *s6;
    s32 v1;
    u8 *a2;
    register u8 *a1 asm("a1");
    u8 *a0;
    register s32 a3 asm("a3");
    register u8 t0 asm("t0");
    register s32 tmp asm("v0");

    s5 = arg0;
    s3 = arg1;
    tmp = s5 & 0xFF;
    s0 = 0;
    s4 = 0xFF;
    s6 = D_801908CC;
    s1 = ItemQuantities[tmp];
    s2 = tmp;
    for (; s0 < 0x14; s0++) {
        a2 = (u8 *) GetPartyDataPointer(s0);
        t0 = a2[1];
        if ((t0 != s4) && !(a2[4] & 0x20)) {
            if (s3 != 0) {
                a3 = 0;
                v1 = 0;
                a1 = s6;
                for (; v1 < 0x15; v1++, a1 += 0x1C0) {
                    a0 = a1;
                    if ((a0[0x183] != s4) && !(a0[6] & 0x20) && (a0[2] == t0)) {
                        a3 = 1;
                        break;
                    }
                }
                if (a3 == 0) {
                    goto countem;
                }
            } else {
countem:
                for (v1 = 0; v1 < 7; v1++) {
                    if (*(a2 + v1 + 0xE) == s2) {
                        s1 += 1;
                    }
                }
            }
        }
    }
    if (s3 != 0) {
        s0 = 0;
        a3 = 0xFF;
        a2 = (u8 *) 0x5D;
        a0 = (u8 *) (s5 & 0xFF);
        a1 = D_801908CC;
        for (; s0 < 0x15; s0++, a1 += 0x1C0) {
            if ((a1[0x183] != a3) && !(a1[6] & 0x20) && !(a1[0x1BA] & 0x30) && (a1[3] != (s32) a2)) {
                for (v1 = 0; v1 < 7; v1++) {
                    if (*(a1 + v1 + 0x1A) == (s32) a0) {
                        s1 += 1;
                    }
                }
            }
        }
    }
    return s1;
}

void InitializeUnitSXYFacingBattleRewards(BattleUnit *arg0, ENTDEntry *arg1) {
    u16 v0, v1;

    arg0->x = arg1->x;
    arg0->y = arg1->y;
    v1 = *(u16 *) &arg1->y & 0x8000;
    v0 = *(u16 *) &arg0->y & 0x7FFF;
    *(u16 *) &arg0->y = v0 | v1;
    v1 = *(u16 *) &arg1->y & 0x300;
    v0 = *(u16 *) &arg0->y & 0xF0FF;
    *(u16 *) &arg0->y = v0 | v1;
    v1 = *(u16 *) &arg1->y & 0x3000;
    v0 = *(u16 *) &arg0->y & 0xCFFF;
    *(u16 *) &arg0->y = v0 | v1;
    arg0->warTrophy = arg1->warTrophy;
    arg0->bonusMoney = arg1->bonusMoney;
}

extern u8 D_80065DE6[];

s32 FindActionHighestOrderStatusEffect(u8 *arg0) {
    s32 t2;
    register s32 a2 asm("a2");
    s32 a1;
    register s32 a3 asm("a3");
    register u8 *t0 asm("t0");
    s32 t1;
    s32 v0;
    register s32 mask asm("v0");
    s32 mask2;
    s32 av;
    s32 c80;
    t2 = -1;
    a2 = 0;
    a1 = 0;
    c80 = 0x80;
    t0 = D_80065DE6;
    a3 = 0;
    do {
        v0 = a1;
        if (a1 < 0) {
            v0 = a1 + 7;
        }
        if (t2) {
            t1 = v0 >> 3;
            mask = c80 >> (a1 & 7);
            mask2 = mask;
        } else {
            t1 = v0 >> 3;
            mask = c80 >> (a1 & 7);
            mask2 = mask;
        }
        if ((arg0 + t1)[0x20] & mask) {
            if (t2 < t0[0]) {
                t2 = t0[0];
                a2 = a1 + 0x81;
                if (D_80065DE9[a3] & 8) {
                    a2 = a1 + 0x181;
                }
            }
        }
        av = mask2 & (&arg0[t1])[0x1B];
        if (av) {
            if (t2 < t0[0]) {
                t2 = t0[0];
                a2 = a1 + 1;
                if (D_80065DE9[a3] & 8) {
                    a2 = a1 + 0x101;
                }
            }
        }
        t0 += 0x10;
        a1 += 1;
        a3 += 0x10;
    } while (a1 < 0x28);
    return a2;
}

extern u16 D_800661E8[];

s32 CalculateZodiacSymbol(s32 arg0) {
    s32 c = 0;
    register s32 i asm("a2") = 0;
    u32 a = arg0 & 0xFFFF;
    u16 *t = D_800661E8;
    s32 x;
    s32 q;

    do {
        c += a >= *t;
        t += 1;
        i += 1;
    } while (i < 12);
    x = c + 9;
    q = x / 12;
    c = q;
    return (x - c * 12) & 0xFFFF;
}

void DataNullifying(u8 *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        *arg0++ = 0;
    }
}

extern s32 func_8013B590(s32);
extern void func_8013B644(s32, s32);

void IncreaseCasualtiesInjuredCounters(BattleUnit *arg0) {
    s32 x;
    s32 y;

    if (arg0->curAction[46] & 0x30) {
        x = 0x61;
    } else {
        x = 0x62;
    }
    y = func_8013B590(x);
    if (y < 0x270F) {
        y++;
    }
    func_8013B644(x, y);
}

void InflictedStatusChanges(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    register s32 v1 asm("v1");
    u8 t0;

    v1 = arg2;
    if (arg3 == 1)
        goto L1;
    if (arg3 < 2) {
        if (arg3 == 0)
            goto L0;
    } else {
        if (arg3 == 2)
            goto L2;
    }
    goto Lmerge;
L0:
    t0 = ((BattleUnit *) (arg0 + arg1))->curAction[47] | (u8) arg2;
    goto Lmerge;
L1:
    t0 = ((BattleUnit *) (arg0 + arg1))->curAction[47] & (u8) ~arg2;
    goto Lmerge;
L2:
    t0 = (u8) v1;
Lmerge:
    ((BattleUnit *) (arg0 + arg1))->curAction[47] = t0;
    ((BattleUnit *) (arg0 + arg1))->curStatus[0] = t0 | ((BattleUnit *) (arg0 + arg1))->innateStatus[0];
}

void StoreCurrentStatuses(u8 *arg0) {
    u8 *a2;
    s32 a1;
    u8 *v1;
    u8 v0;
    u8 a0_reg;

    a2 = arg0;
    a1 = 0;
    do {
        v1 = a2 + a1;
        v0 = ((BattleUnit *) v1)->innateStatus[0];
        a1 += 1;
        a0_reg = ((BattleUnit *) v1)->curAction[47];
        v0 = v0 | a0_reg;
        ((BattleUnit *) v1)->curStatus[0] = v0;
    } while (a1 < 5);
}

s32 TransferLastAbilityUsedCT(BattleUnit *arg0) {
    s16 val = *(s16 *) &arg0->lastAbility;
    s32 result = AbilityData2[val].ct & 0x7F;
    arg0->abilityCt2 = result;
    return result;
}

extern void *jtbl_80059830[];
extern void func_8018E9BC(s32, s32, s32);

void EnableDisableActingStatuses(u8 *arg0, s32 arg1) {
    void InflictedStatusChanges(s32, s32, s32, s32);
    u8 *s2;
    u32 s3;
    u32 s4;
    u8 v1;
    u32 s1;
    s32 s0;
    u32 s2tv;
    u32 v0t;

    s2 = arg0;
    s4 = s2[0x58];
    s3 = s2[0x18A];
    v1 = arg1 & 0xFF;
    if (v1 == 0xFF) {
        v1 = (s4 & 1) << 3;
    }
    if (v1 >= 9U) {
        goto join;
    }
    goto *jtbl_80059830[v1];
case0:
    s1 = 0;
    s2[0x15D] = 0xFF;
    goto join;
case5:
    s1 = 8;
    goto join;
case6:
    s1 = 4;
    goto join;
case7:
    s1 = 2;
    s2[0x15D] = 0xFF;
    goto join;
case8:
    TransferLastAbilityUsedCT((BattleUnit *) s2);
    s1 = 1;
    s2[0x15D] = s2[0x18B];
join:
    s0 = s1 ^ 0xF;
    InflictedStatusChanges((s32) s2, 0, s1 & 0xFF, 0);
    InflictedStatusChanges((s32) s2, 0, s0 & 0xFF, 1);
    s1 = 8;
    s0 = 5;
    v0t = s2[0x58];
    s2tv = s4 ^ v0t;
    __asm__("addu %0,%1,$0" : "=r"(s2) : "r"(s2tv));
    do {
        if ((s32) s2 & s1) {
            if (s4 & s1) {
                func_8018E9BC(s0, 0, s3);
            } else {
                func_8018E9BC(s0, 1, s3);
            }
        }
        s0 += 1;
        s1 >>= 1;
    } while (s0 < 9);
    __asm__ volatile("" ::"X"(&&case0), "X"(&&case5), "X"(&&case6), "X"(&&case7), "X"(&&case8));
}

extern void MallocExceptionHandler(u32, s32);

void BATTLELoadExceptionHandler(s32 arg0) {
    MallocExceptionHandler(3, arg0);
}
