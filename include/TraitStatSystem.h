#pragma once
#include "Champ.h"
#include "Traits.h"
#include <unordered_map>
#include <ctime>
#include "Combat.h"
#include "Log.h"
void ApplyTraitEffects(TraitDef& trait, ChampState& Champion, int TeamNumber){
    if (TeamNumber == 1){
        if (trait.numchampsT1 >= trait.thresholds[1]){
            Champion.ad_current = Champion.ad_current * trait.ad_modifier[1];
            Champion.ap_current = Champion.ap_current * trait.ap_modifier[1];
            Champion.hp_current = Champion.hp_current * trait.hp_modifier[1];
            Champion.lifesteal = trait.lifesteal;
            trait.is_active = true;
            Champion.execute = trait.execute[1];
            Log("Applied trait " + trait.name + " with thresholds " + std::to_string(trait.thresholds[1]) + " to champion " + Champion.def.name);
        }
        else if (trait.numchampsT1 >= trait.thresholds[0]){
            Champion.ad_current = Champion.ad_current * trait.ad_modifier[0];
            Champion.ap_current = Champion.ap_current * trait.ap_modifier[0];
            Champion.hp_current = Champion.hp_current * trait.hp_modifier[0];
            Champion.lifesteal = trait.lifesteal;
            trait.is_active = true;
            Champion.execute = trait.execute[0];
            Log("Applied trait " + trait.name + " with thresholds " + std::to_string(trait.thresholds[0]) + " to champion " + Champion.def.name);
        }
        else{
            Log("Requirements not met to apply trait " + trait.name + " to champion " + Champion.def.name);
        }
    }
    if (TeamNumber == 2){
        if (trait.numchampsT2 >= trait.thresholds[1]){
            Champion.ad_current = Champion.ad_current * trait.ad_modifier[1];
            Champion.ap_current = Champion.ap_current * trait.ap_modifier[1];
            Champion.hp_current = Champion.hp_current * trait.hp_modifier[1];
            Champion.lifesteal = trait.lifesteal;
            trait.is_active = true;
            Champion.execute = trait.execute[1];
            Log("Applied trait " + trait.name + " with thresholds " + std::to_string(trait.thresholds[1]) + " to champion " + Champion.def.name);
        }
        else if (trait.numchampsT2 >= trait.thresholds[0]){
            Champion.ad_current = Champion.ad_current * trait.ad_modifier[0];
            Champion.ap_current = Champion.ap_current * trait.ap_modifier[0];
            Champion.hp_current = Champion.hp_current * trait.hp_modifier[0];
            Champion.lifesteal = trait.lifesteal;
            trait.is_active = true;
            Champion.execute = trait.execute[0];
            Log("Applied trait " + trait.name + " with thresholds " + std::to_string(trait.thresholds[0]) + " to champion " + Champion.def.name);
        }
    }
};
void ApplyCelestialsTraitEffects(ChampState& Champion, int TeamNumber){
    if (TeamNumber==1){
        int n = TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->numchampsT1;
        TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->ad_modifier = {1.0f + 0.04f*n};
        TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->ap_modifier = {1.0f + 0.04f*n};
        TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->hp_modifier = {1.0f + 0.04f*n};
        Champion.ad_current = Champion.ad_current * TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->ad_modifier[0];
        Champion.ap_current = Champion.ap_current * TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->ap_modifier[0];
        Champion.hp_current = Champion.hp_current * TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->hp_modifier[0];
        Log("Applied trait Celestial with thresholds " + std::to_string(n) + " to champion " + Champion.def.name);
    }
    else if (TeamNumber==2){
        int n = TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->numchampsT2;
        TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->ad_modifier = {1.0f + 0.04f*n};
        TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->ap_modifier = {1.0f + 0.04f*n};
        TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->hp_modifier = {1.0f + 0.04f*n};
        Champion.ad_current = Champion.ad_current * TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->ad_modifier[0];
        Champion.ap_current = Champion.ap_current * TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->ap_modifier[0];
        Champion.hp_current = Champion.hp_current * TRAIT_POOL[TRAIT_TRANSFORM.at("Celestials")]->hp_modifier[0];
        Log("Applied trait Celestial with thresholds " + std::to_string(n) + " to champion " + Champion.def.name);
    }
};
void ApplyShadowFighterTraitEffects(ChampState& Champion, int TeamNumber){
    if (TeamNumber == 1){
        if (TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->numchampsT1 >= TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->thresholds[1]){
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ad_modifier = {1.0f + 0.015f};
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ap_modifier = {1.0f + 0.015f};
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier = {1.0f + 0.015f};
            Champion.ad_current = Champion.ad_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ad_modifier[0];
            Champion.ap_current = Champion.ap_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ap_modifier[0];
            Champion.hp_max = Champion.hp_max * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier[0];
            Champion.hp_current = Champion.hp_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier[0];
        }
        else if(TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->numchampsT1 >= TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->thresholds[0]){
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ad_modifier = {1.0f + 0.01f};
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ap_modifier = {1.0f + 0.01f};
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier = {1.0f + 0.01f};
            Champion.ad_current = Champion.ad_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ad_modifier[0];
            Champion.ap_current = Champion.ap_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ap_modifier[0];
            Champion.hp_max = Champion.hp_max * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier[0];
            Champion.hp_current = Champion.hp_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier[0];
        }
    }
    if (TeamNumber == 2){
        if (TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->numchampsT2 >= TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->thresholds[1]){
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ad_modifier = {1.0f + 0.015f};
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ap_modifier = {1.0f + 0.015f};
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier = {1.0f + 0.015f};
            Champion.ad_current = Champion.ad_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ad_modifier[0];
            Champion.ap_current = Champion.ap_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ap_modifier[0];
            Champion.hp_max = Champion.hp_max * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier[0];
            Champion.hp_current = Champion.hp_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier[0];
        }
        else if (TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->numchampsT2 >= TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->thresholds[0]){
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ad_modifier = {1.0f + 0.01f};
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ap_modifier = {1.0f + 0.01f};
            TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier = {1.0f + 0.01f};
            Champion.ad_current = Champion.ad_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ad_modifier[0];
            Champion.ap_current = Champion.ap_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->ap_modifier[0];
            Champion.hp_max = Champion.hp_max * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier[0];
            Champion.hp_current = Champion.hp_current * TRAIT_POOL[TRAIT_TRANSFORM.at("ShadowFighters")]->hp_modifier[0];
        }
    }
}