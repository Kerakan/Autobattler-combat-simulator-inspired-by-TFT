#pragma once
#include "Champ.h"
#include <unordered_map>
#include <ctime>
#include "Combat.h"
#include "Log.h"
struct TraitActivation{
    std::string name;
    std::vector<int> treshold;
    int numchampsT1 = 0;
    int numchampsT2 = 0;
    std::vector<float> hp_modifier;
    std::vector<float> ad_modifier;
    std::vector<float> ap_modifier;
    float lifesteal;
    std::vector<float> execute = {0,0};
    bool is_active = false;
};
TraitActivation Lovers{
    .name = "Lovers",
    .treshold = {2,2},
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0,
};
TraitActivation Bruiser{
    .name = "Bruiser",
    .treshold = {2,3},
    .hp_modifier = {1.05, 1.10},
    .ad_modifier = {1.1, 1.2},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Assassin{
    //define it as 2 tresholds so as to have it fulfill the conditions on the void function ApplyTraitEffect
    .name = "Assasin",
    .treshold = {2,2},
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 20.0
};
TraitActivation Sniper{
    .name = "Sniper",
    .treshold = {2,3},
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.15, 1.25},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Guardian{
    .name = "Guardian",
    .treshold = {2,3},
    .hp_modifier = {1.15, 1.25},
    .ad_modifier = {1.00, 1.00},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Mage{
    .name = "Mage",
    .treshold = {2,3},
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.15, 1.25},
    .lifesteal = 0.0
};
TraitActivation Celestials{
    .name = "Celestials",
    .treshold = {2,3,4,5},
    .hp_modifier = {1.0},
    .ad_modifier = {1.0},
    .ap_modifier = {1.0},
    .lifesteal = 0.0
};
TraitActivation Shadow_Fighters{
    //Will check on it later since it scales with time passed since combat start.
    .name = "ShadowFighters",
    .treshold = {3,5},
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Dark_Knights{
    .name = "DarkKnights",
    .treshold = {3,5},
    .hp_modifier = {1.0, 1.0, 1.0},
    .ad_modifier = {1.0, 1.0, 1.0},
    .ap_modifier = {1.0, 1.0, 1.0},
    .lifesteal = 0.0,
    .execute = {5,10}
};
TraitActivation Titan{
    .name = "Titan",
    .treshold = {1,1},
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Star_Forger{
    .name = "Star_Forger",
    .treshold = {1,1},
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
void ApplyTraitEffects(TraitActivation& trait, ChampState& Champion, int TeamNumber){
    if (TeamNumber == 1){
        if (trait.numchampsT1 >= trait.treshold[1]){
            Champion.ad_current = Champion.ad_current * trait.ad_modifier[1];
            Champion.ap_current = Champion.ap_current * trait.ap_modifier[1];
            Champion.hp_current = Champion.hp_current * trait.hp_modifier[1];
            Champion.lifesteal = trait.lifesteal;
            trait.is_active = true;
            Champion.execute = trait.execute[1];
            Log("Applied trait " + trait.name + " with treshold " + std::to_string(trait.treshold[1]) + " to champion " + Champion.def.name);
        }
        else if (trait.numchampsT1 >= trait.treshold[0]){
            Champion.ad_current = Champion.ad_current * trait.ad_modifier[0];
            Champion.ap_current = Champion.ap_current * trait.ap_modifier[0];
            Champion.hp_current = Champion.hp_current * trait.hp_modifier[0];
            Champion.lifesteal = trait.lifesteal;
            trait.is_active = true;
            Champion.execute = trait.execute[0];
            Log("Applied trait " + trait.name + " with treshold " + std::to_string(trait.treshold[0]) + " to champion " + Champion.def.name);
        }
        else{
            Log("Requirements not met to apply trait " + trait.name + " to champion " + Champion.def.name);
        }
    }
    if (TeamNumber == 2){
        if (trait.numchampsT2 >= trait.treshold[1]){
            Champion.ad_current = Champion.ad_current * trait.ad_modifier[1];
            Champion.ap_current = Champion.ap_current * trait.ap_modifier[1];
            Champion.hp_current = Champion.hp_current * trait.hp_modifier[1];
            Champion.lifesteal = trait.lifesteal;
            trait.is_active = true;
            Champion.execute = trait.execute[1];
            Log("Applied trait " + trait.name + " with treshold " + std::to_string(trait.treshold[1]) + " to champion " + Champion.def.name);
        }
        else if (trait.numchampsT2 >= trait.treshold[0]){
            Champion.ad_current = Champion.ad_current * trait.ad_modifier[0];
            Champion.ap_current = Champion.ap_current * trait.ap_modifier[0];
            Champion.hp_current = Champion.hp_current * trait.hp_modifier[0];
            Champion.lifesteal = trait.lifesteal;
            trait.is_active = true;
            Champion.execute = trait.execute[0];
            Log("Applied trait " + trait.name + " with treshold " + std::to_string(trait.treshold[0]) + " to champion " + Champion.def.name);
        }
    }
};
void ApplyCelestialsTraitEffects(ChampState& Champion, int TeamNumber){
    if (TeamNumber==1){
        int n = Celestials.numchampsT1;
        Celestials.ad_modifier = {1.0f + 0.04f*n};
        Celestials.ap_modifier = {1.0f + 0.04f*n};
        Celestials.hp_modifier = {1.0f + 0.04f*n};
        Champion.ad_current = Champion.ad_current * Celestials.ad_modifier[0];
        Champion.ap_current = Champion.ap_current * Celestials.ap_modifier[0];
        Champion.hp_current = Champion.hp_current * Celestials.hp_modifier[0];
        Log("Applied trait Celestial with treshold " + std::to_string(n) + " to champion " + Champion.def.name);
    }
    else if (TeamNumber==2){
        int n = Celestials.numchampsT2;
        Celestials.ad_modifier = {1.0f + 0.04f*n};
        Celestials.ap_modifier = {1.0f + 0.04f*n};
        Celestials.hp_modifier = {1.0f + 0.04f*n};
        Champion.ad_current = Champion.ad_current * Celestials.ad_modifier[0];
        Champion.ap_current = Champion.ap_current * Celestials.ap_modifier[0];
        Champion.hp_current = Champion.hp_current * Celestials.hp_modifier[0];
        Log("Applied trait Celestial with treshold " + std::to_string(n) + " to champion " + Champion.def.name);
    }
};
void ApplyShadowFighterTraitEffects(ChampState& Champion, int TeamNumber){
    if (TeamNumber == 1){
        if (Shadow_Fighters.numchampsT1 >= Shadow_Fighters.treshold[1]){
            Shadow_Fighters.ad_modifier = {1.0f + 0.015f};
            Shadow_Fighters.ap_modifier = {1.0f + 0.015f};
            Shadow_Fighters.hp_modifier = {1.0f + 0.015f};
            Champion.ad_current = Champion.ad_current * Shadow_Fighters.ad_modifier[0];
            Champion.ap_current = Champion.ap_current * Shadow_Fighters.ap_modifier[0];
            Champion.hp_max = Champion.hp_max * Shadow_Fighters.hp_modifier[0];
            Champion.hp_current = Champion.hp_current * Shadow_Fighters.hp_modifier[0];
        }
        else if(Shadow_Fighters.numchampsT1 >= Shadow_Fighters.treshold[0]){
            Shadow_Fighters.ad_modifier = {1.0f + 0.01f};
            Shadow_Fighters.ap_modifier = {1.0f + 0.01f};
            Shadow_Fighters.hp_modifier = {1.0f + 0.01f};
            Champion.ad_current = Champion.ad_current * Shadow_Fighters.ad_modifier[0];
            Champion.ap_current = Champion.ap_current * Shadow_Fighters.ap_modifier[0];
            Champion.hp_max = Champion.hp_max * Shadow_Fighters.hp_modifier[1];
            Champion.hp_current = Champion.hp_current * Shadow_Fighters.hp_modifier[0];
        }
    }
    if (TeamNumber == 2){
        if (Shadow_Fighters.numchampsT2 >= Shadow_Fighters.treshold[1]){
            Shadow_Fighters.ad_modifier = {1.0f + 0.015f};
            Shadow_Fighters.ap_modifier = {1.0f + 0.015f};
            Shadow_Fighters.hp_modifier = {1.0f + 0.015f};
            Champion.ad_current = Champion.ad_current * Shadow_Fighters.ad_modifier[0];
            Champion.ap_current = Champion.ap_current * Shadow_Fighters.ap_modifier[0];
            Champion.hp_max = Champion.hp_max * Shadow_Fighters.hp_modifier[0];
            Champion.hp_current = Champion.hp_current * Shadow_Fighters.hp_modifier[0];
        }
        else if(Shadow_Fighters.numchampsT2 >= Shadow_Fighters.treshold[0]){
            Shadow_Fighters.ad_modifier = {1.0f + 0.01f};
            Shadow_Fighters.ap_modifier = {1.0f + 0.01f};
            Shadow_Fighters.hp_modifier = {1.0f + 0.01f};
            Champion.ad_current = Champion.ad_current * Shadow_Fighters.ad_modifier[0];
            Champion.ap_current = Champion.ap_current * Shadow_Fighters.ap_modifier[0];
            Champion.hp_max = Champion.hp_max * Shadow_Fighters.hp_modifier[1];
            Champion.hp_current = Champion.hp_current * Shadow_Fighters.hp_modifier[0];
        }
    }
}
const std::unordered_map<Trait, TraitActivation*> TRAIT_POOL = {
    {Trait::Titan,           &Titan},
    {Trait::Star_Forger,     &Star_Forger},
    {Trait::Lovers,          &Lovers},
    {Trait::Bruiser,         &Bruiser},
    {Trait::Assassin,        &Assassin},
    {Trait::Sniper,          &Sniper},
    {Trait::Guardian,        &Guardian},
    {Trait::Mage,            &Mage},
    {Trait::Celestials,      &Celestials},
    {Trait::Shadow_Fighters, &Shadow_Fighters},
    {Trait::Dark_Knights,    &Dark_Knights},
};