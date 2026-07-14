#include "Champ.h"
struct ItemDef{
    std::string name;
    float ad_modifier;
    float ap_modifier;
    float hp_modifier;
    float armor_modifier;
    float magicres_modifier;
    float attackspeed_modifier;
    float lifesteal;
};
ItemDef AttackItem{
    .name = "AttackItem",
    .ad_modifier = 75,
    .ap_modifier = 0,
    .hp_modifier = 0,
    .armor_modifier = 0,
    .magicres_modifier = 0,
    .attackspeed_modifier = 1.1,
};
ItemDef AttackSpeedItem{
    .name = "AttackSpeedItem",
    .ad_modifier = 25,
    .ap_modifier = 0,
    .hp_modifier = 0,
    .armor_modifier = 0,
    .magicres_modifier = 0,
    .attackspeed_modifier = 1.5,
};
ItemDef HealthItem{
    .name = "HealthItem",
    .ad_modifier = 0,
    .ap_modifier = 0,
    .hp_modifier = 500,
    .armor_modifier = 20,
    .magicres_modifier = 20,
    .attackspeed_modifier = 1.0,
};
ItemDef ArmorItem{
    .name = "ArmorItem",
    .ad_modifier = 0,
    .ap_modifier = 0,
    .hp_modifier = 150,
    .armor_modifier = 50,
    .magicres_modifier = 50,
    .attackspeed_modifier = 1.0,
};
ItemDef AbilityPowerItem{
    .name = "AbilityPowerItem",
    .ad_modifier = 0,
    .ap_modifier = 90,
    .hp_modifier = 0,
    .armor_modifier = 0,
    .magicres_modifier = 0,
    .attackspeed_modifier = 1.0,
};
ItemDef lifestealItem{
    .name = "LifestealItem",
    .ad_modifier = 0,
    .ap_modifier = 0,
    .hp_modifier = 0,
    .armor_modifier = 0,
    .magicres_modifier = 0,
    .attackspeed_modifier = 1.0,
    .lifesteal = 20.0
};
void ApplyItemEffects(ItemDef& item, ChampState& Champion){
    Champion.ad_current += item.ad_modifier;
    Champion.ap_current += item.ap_modifier;
    Champion.hp_current += item.hp_modifier;
    Champion.armor_current += item.armor_modifier;
    Champion.magicres_current += item.magicres_modifier;
    Champion.attackspeed_current *= item.attackspeed_modifier;
    Champion.lifesteal += item.lifesteal;
}