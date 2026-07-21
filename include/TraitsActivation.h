#pragma once
#include "Champ.h"
#include <unordered_map>
#include <ctime>
#include "Log.h"
#include "Traits.h"
void ApplyTraitEffects(Trait& trait, ChampState& Champion, int TeamNumber){
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
        int n = TRAIT_STORAGE.at("Celestials").numchampsT1;
        TRAIT_STORAGE.at("Celestials").ad_modifier = {1.0f + 0.04f*n};
        TRAIT_STORAGE.at("Celestials").ap_modifier = {1.0f + 0.04f*n};
        TRAIT_STORAGE.at("Celestials").hp_modifier = {1.0f + 0.04f*n};
        Champion.ad_current = Champion.ad_current * TRAIT_STORAGE.at("Celestials").ad_modifier[0];
        Champion.ap_current = Champion.ap_current * TRAIT_STORAGE.at("Celestials").ap_modifier[0];
        Champion.hp_current = Champion.hp_current * TRAIT_STORAGE.at("Celestials").hp_modifier[0];
        Log("Applied trait Celestial with treshold " + std::to_string(n) + " to champion " + Champion.def.name);
    }
    else if (TeamNumber==2){
        int n = TRAIT_STORAGE.at("Celestials").numchampsT2;
        TRAIT_STORAGE.at("Celestials").ad_modifier = {1.0f + 0.04f*n};
        TRAIT_STORAGE.at("Celestials").ap_modifier = {1.0f + 0.04f*n};
        TRAIT_STORAGE.at("Celestials").hp_modifier = {1.0f + 0.04f*n};
        Champion.ad_current = Champion.ad_current * TRAIT_STORAGE.at("Celestials").ad_modifier[0];
        Champion.ap_current = Champion.ap_current * TRAIT_STORAGE.at("Celestials").ap_modifier[0];
        Champion.hp_current = Champion.hp_current * TRAIT_STORAGE.at("Celestials").hp_modifier[0];
        Log("Applied trait Celestial with treshold " + std::to_string(n) + " to champion " + Champion.def.name);
    }
};
void ApplyShadowFighterTraitEffects(ChampState& Champion, int TeamNumber){
    if (TeamNumber == 1){
        if (TRAIT_STORAGE.at("ShadowFighters").numchampsT1 >= TRAIT_STORAGE.at("ShadowFighters").treshold[1]){
            TRAIT_STORAGE.at("ShadowFighters").ad_modifier = {1.0f + 0.015f};
            TRAIT_STORAGE.at("ShadowFighters").ap_modifier = {1.0f + 0.015f};
            TRAIT_STORAGE.at("ShadowFighters").hp_modifier = {1.0f + 0.015f};
            Champion.ad_current = Champion.ad_current * TRAIT_STORAGE.at("ShadowFighters").ad_modifier[0];
            Champion.ap_current = Champion.ap_current * TRAIT_STORAGE.at("ShadowFighters").ap_modifier[0];
            Champion.hp_max = Champion.hp_max * TRAIT_STORAGE.at("ShadowFighters").hp_modifier[0];
            Champion.hp_current = Champion.hp_current * TRAIT_STORAGE.at("ShadowFighters").hp_modifier[0];
        }
        else if(TRAIT_STORAGE.at("ShadowFighters").numchampsT1 >= TRAIT_STORAGE.at("ShadowFighters").treshold[0]){
            TRAIT_STORAGE.at("ShadowFighters").ad_modifier = {1.0f + 0.01f};
            TRAIT_STORAGE.at("ShadowFighters").ap_modifier = {1.0f + 0.01f};
            TRAIT_STORAGE.at("ShadowFighters").hp_modifier = {1.0f + 0.01f};
            Champion.ad_current = Champion.ad_current * TRAIT_STORAGE.at("ShadowFighters").ad_modifier[0];
            Champion.ap_current = Champion.ap_current * TRAIT_STORAGE.at("ShadowFighters").ap_modifier[0];
            Champion.hp_max = Champion.hp_max * TRAIT_STORAGE.at("ShadowFighters").hp_modifier[0];
            Champion.hp_current = Champion.hp_current * TRAIT_STORAGE.at("ShadowFighters").hp_modifier[0];
        }
    }
    if (TeamNumber == 2){
        if (TRAIT_STORAGE.at("ShadowFighters").numchampsT2 >= TRAIT_STORAGE.at("ShadowFighters").treshold[1]){
            TRAIT_STORAGE.at("ShadowFighters").ad_modifier = {1.0f + 0.015f};
            TRAIT_STORAGE.at("ShadowFighters").ap_modifier = {1.0f + 0.015f};
            TRAIT_STORAGE.at("ShadowFighters").hp_modifier = {1.0f + 0.015f};
            Champion.ad_current = Champion.ad_current * TRAIT_STORAGE.at("ShadowFighters").ad_modifier[0];
            Champion.ap_current = Champion.ap_current * TRAIT_STORAGE.at("ShadowFighters").ap_modifier[0];
            Champion.hp_max = Champion.hp_max * TRAIT_STORAGE.at("ShadowFighters").hp_modifier[0];
            Champion.hp_current = Champion.hp_current * TRAIT_STORAGE.at("ShadowFighters").hp_modifier[0];
        }
        else if(TRAIT_STORAGE.at("ShadowFighters").numchampsT2 >= TRAIT_STORAGE.at("ShadowFighters").treshold[0]){
            TRAIT_STORAGE.at("ShadowFighters").ad_modifier = {1.0f + 0.01f};
            TRAIT_STORAGE.at("ShadowFighters").ap_modifier = {1.0f + 0.01f};
            TRAIT_STORAGE.at("ShadowFighters").hp_modifier = {1.0f + 0.01f};
            Champion.ad_current = Champion.ad_current * TRAIT_STORAGE.at("ShadowFighters").ad_modifier[0];
            Champion.ap_current = Champion.ap_current * TRAIT_STORAGE.at("ShadowFighters").ap_modifier[0];
            Champion.hp_max = Champion.hp_max * TRAIT_STORAGE.at("ShadowFighters").hp_modifier[1];
            Champion.hp_current = Champion.hp_current * TRAIT_STORAGE.at("ShadowFighters").hp_modifier[0];
        }
    }
}