#ifndef MODULE_TORTUGA_TOMES_H
#define MODULE_TORTUGA_TOMES_H

#include "ScriptMgr.h"
#include "Player.h"

#include <unordered_map>

enum TortugaTomesConstants
{
    ATTR_ITEM = 248000,
    ATTR_SPELL = 18282,
    ATTR_QUEST = 248000,
    TALENT_QUEST = 248001,

    ATTR_SETTING_PROMPT = 1,

    ATTR_GOSSIP_ALLOCATE = 1,
    ATTR_GOSSIP_ALLOCATE_RETURN = 2,
    ATTR_GOSSIP_ALLOCATE_RESET = 3,
    ATTR_GOSSIP_SETTINGS = 4,
    ATTR_GOSSIP_SETTINGS_PROMPT = 5,
    ATTR_GOSSIP_SETTINGS_RETURN = 6,

    ATTR_NPC_TEXT_HAS_ATTRIBUTES = 248001,
    ATTR_NPC_TEXT_GENERIC = 248000,
    ATTR_NPC_TEXT_DISABLED = 248002,

    ATTR_SPELL_STAMINA = 7477,
    ATTR_SPELL_AGILITY = 7471,
    ATTR_SPELL_INTELLECT = 7468,
    ATTR_SPELL_STRENGTH = 7464,
    ATTR_SPELL_SPIRIT = 7474,
    ATTR_SPELL_SPELL_POWER = 9392
};

struct TomeAttributes
{
    uint32 Unallocated;

    uint32 Stamina;
    uint32 Strength;
    uint32 Agility;
    uint32 Intellect;
    uint32 Spirit;
    uint32 SpellPower;

    uint32 Settings;
};

std::unordered_map<uint64, TomeAttributes> tomeAttributesMap;

void AddAttributePoint(Player* /*player*/);
void AddTalentPoint(Player* /*player*/);
TomeAttributes* GetTomeAttributes(Player* /*player*/);
void ClearTomeAttributes();
void LoadTomeAttributes();
TomeAttributes* LoadTomeAttributesForPlayer(Player* /*player*/);
void SaveTomeAttributes();
void SaveTomeAttributesForPlayer(Player* /*player*/);
void ApplyAttributes(Player* /*player*/, TomeAttributes* /*attributes*/);
void DisableAttributes(Player* /*player*/);
bool TryAddAttribute(TomeAttributes* /*attributes*/, uint32 /*attribute*/);
void ResetAttributes(TomeAttributes* /*attributes*/);
bool HasAttributesToSpend(Player* /*player*/);
bool HasAttributes(Player* /*player*/);
bool IsAttributeAtMax(uint32 /*attribute*/, uint32 /*value*/);
uint32 GetAttributesToSpend(Player* /*player*/);
uint32 GetTotalAttributes(Player* /*player*/);
uint32 GetTotalAttributes(TomeAttributes* /*attributes*/);
uint32 GetResetCost();
bool HasSetting(Player* /*player*/, uint32 /*setting*/);
void ToggleSetting(Player* /*player*/, uint32 /*setting*/);
void SendAllocateMenu(Player* /*player*/, Creature* /*creature*/);
void SendSettingsMenu(Player* /*player*/, Creature* /*creature*/);

class TortugaTomesPlayerScript : public PlayerScript
{
public:
    TortugaTomesPlayerScript() : PlayerScript("TortugaTomesPlayerScript") { }

    virtual void OnPlayerLogin(Player* /*player*/) override;
    virtual void OnPlayerLogout(Player* /*player*/) override;
    virtual void OnPlayerCompleteQuest(Player* /*player*/, Quest const* /*quest*/) override;
    virtual void OnPlayerLeaveCombat(Player* /*player*/) override;

    uint32 GetRandomAttributeForClass(Player* /*player*/);
    std::string GetAttributeName(uint32 /*attribute*/);
};

class TortugaTomesUnitScript : public UnitScript
{
public:
    TortugaTomesUnitScript() : UnitScript("TortugaTomesUnitScript") { }

    void OnDamage(Unit* /*attacker*/, Unit* /*victim*/, uint32& /*damage*/);
};

class TortugaTomesCreatureScript : public CreatureScript
{
public:
    TortugaTomesCreatureScript() : CreatureScript("TortugaTomesCreatureScript") { }

    virtual bool OnGossipHello(Player* /*player*/, Creature* /*creature*/) override;
    virtual bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override;

    void HandleAttributeAllocation(Player* /*player*/, uint32 /*attribute*/, bool /*reset*/);
};

class TortugaTomesWorldScript : public WorldScript
{
public:
    TortugaTomesWorldScript() : WorldScript("TortugaTomesWorldScript") { }

    virtual void OnAfterConfigLoad(bool /*reload*/) override;
    virtual void OnShutdownInitiate(ShutdownExitCode /*code*/, ShutdownMask /*mask*/) override;
};

#endif // MODULE_TORTUGA_TOMES_H
