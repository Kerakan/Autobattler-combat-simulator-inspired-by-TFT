#pragma once
#include "Champ.h"
#include <unordered_map>
#include <ctime>
#include "Combat.h"
struct TraitActivation{
    std::string name;
    std::vector<int> treshold;
    int numchamps;
    std::vector<float> hp_modifier;
    std::vector<float> ad_modifier;
    std::vector<float> ap_modifier;
    float lifesteal;
};
TraitActivation Bruiser{
    .name = "Bruiser",
    .treshold = {2,3},
    .numchamps = 0,
    .hp_modifier = {1.05, 1.10},
    .ad_modifier = {1.1, 1.2},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Assassin{
    //define it as 2 tresholds so as to have it fulfill the conditions on the void function ApplyTraitEffect
    .name = "Assasin",
    .treshold = {2,2},
    .numchamps = 0,
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 20.0
};
TraitActivation Sniper{
    .name = "Sniper",
    .treshold = {2,3},
    .numchamps = 0,
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.15, 1.25},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Guardian{
    .name = "Guardian",
    .treshold = {2,3},
    .numchamps = 0,
    .hp_modifier = {1.15, 1.25},
    .ad_modifier = {1.00, 1.00},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Mage{
    .name = "Mage",
    .treshold = {2,3},
    .numchamps = 0,
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.15, 1.25},
    .lifesteal = 0.0
};
TraitActivation Celestials{
    .name = "Celestials",
    .treshold = {2,3,4,5},
    .numchamps = 0,
    .hp_modifier = {1.0},
    .ad_modifier = {1.0},
    .ap_modifier = {1.0},
    .lifesteal = 0.0
};
TraitActivation Shadow_Fighters{
    //Will check on it later since it scales with time passed since combat start.
    .name = "ShadowFighters",
    .treshold = {3,5},
    .numchamps = 0,
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Dark_Knights{
    //Will check on it later since it executes enemies aat certain tresholds.
    .name = "DarkKnights",
    .treshold = {3,4,5},
    .numchamps = 0,
    .hp_modifier = {1.0, 1.0, 1.0},
    .ad_modifier = {1.0, 1.0, 1.0},
    .ap_modifier = {1.0, 1.0, 1.0},
    .lifesteal = 0.0
};
void ApplyTraitEffects(TraitActivation& trait, ChampState& Champion){
    if (trait.numchamps >= trait.treshold[1]){
        Champion.ad_current = Champion.def.ad[Champion.star] * trait.ad_modifier[1];
        Champion.ap_current = Champion.def.ap[Champion.star] * trait.ap_modifier[1];
        Champion.hp_current = Champion.def.hp[Champion.star] * trait.hp_modifier[1];
        Champion.lifesteal = trait.lifesteal;
        std::cout<< "Applied trait " + trait.name +" with treshold " + std::to_string(trait.treshold[1])<<std::endl;
    }
    else if (trait.numchamps >= trait.treshold[0]){
        Champion.ad_current = Champion.def.ad[Champion.star] * trait.ad_modifier[0];
        Champion.ap_current = Champion.def.ap[Champion.star] * trait.ap_modifier[0];
        Champion.hp_current = Champion.def.hp[Champion.star] * trait.hp_modifier[0];
        Champion.lifesteal = trait.lifesteal;
        std::cout<< "Applied trait " + trait.name +" with treshold " + std::to_string(trait.treshold[0])<<std::endl;
    }
    else{
        std::cout<< "Requirements not met to apply trait " + trait.name <<std::endl;
    }
};
void ApplyCelestialsTraitEffects(ChampState& Champion){
    int n = Celestials.numchamps;
    Celestials.ad_modifier = {1.0f + 0.04f*n};
    Celestials.ap_modifier = {1.0f + 0.04f*n};
    Celestials.hp_modifier = {1.0f + 0.04f*n};
    Champion.ad_current = Champion.def.ad[Champion.star] * Celestials.ad_modifier[0];
    Champion.ap_current = Champion.def.ap[Champion.star] * Celestials.ap_modifier[0];
    Champion.hp_current = Champion.def.hp[Champion.star] * Celestials.hp_modifier[0];
    std::cout<< "Applied trait Celestial with treshold " + std::to_string(n)<<std::endl;
};
void ApplyShadowFighterTraitEffects(ChampState& Champion, int seconds){
    int n = seconds;
    Shadow_Fighters.ad_modifier = {1.0f + 0.04f*n};
    Shadow_Fighters.ap_modifier = {1.0f + 0.04f*n};
    Shadow_Fighters.hp_modifier = {1.0f + 0.04f*n};
    Champion.ad_current = Champion.def.ad[Champion.star] * Shadow_Fighters.ad_modifier[0];
    Champion.ap_current = Champion.def.ap[Champion.star] * Shadow_Fighters.ap_modifier[0];
    Champion.hp_current = Champion.def.hp[Champion.star] * Shadow_Fighters.hp_modifier[0];
}
const std::unordered_map<Trait, TraitActivation*> TRAIT_POOL = {
    {Trait::Bruiser,         &Bruiser},
    {Trait::Assassin,        &Assassin},
    {Trait::Sniper,          &Sniper},
    {Trait::Guardian,        &Guardian},
    {Trait::Mage,            &Mage},
    {Trait::Celestials,      &Celestials},
    {Trait::Shadow_Fighters, &Shadow_Fighters},
    {Trait::Dark_Knights,    &Dark_Knights},
};
