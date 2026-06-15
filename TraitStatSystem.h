#pragma once
#include "Champ.h"
#include <ctime>
struct TraitActivation{
    std::vector<int> treshold;
    int numchamps;
    std::vector<float> hp_modifier;
    std::vector<float> ad_modifier;
    std::vector<float> ap_modifier;
    float lifesteal;
};
TraitActivation Bruiser{
    .treshold = {2,3},
    .numchamps = 0,
    .hp_modifier = {1.05, 1.10},
    .ad_modifier = {1.1, 1.2},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Assassin{
    //define it as 2 tresholds so as to have it fulfill the conditions on the void function ApplyTraitEffect
    .treshold = {2,2},
    .numchamps = 0,
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 20.0
};
TraitActivation Sniper{
    .treshold = {2,3},
    .numchamps = 0,
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.15, 1.25},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Guardian{
    .treshold = {2,3},
    .numchamps = 0,
    .hp_modifier = {1.15, 1.25},
    .ad_modifier = {1.00, 1.00},
    .ap_modifier = {1.0, 1.0},
    .lifesteal = 0.0
};
TraitActivation Mage{
    .treshold = {2,3},
    .numchamps = 0,
    .hp_modifier = {1.0, 1.0},
    .ad_modifier = {1.0, 1.0},
    .ap_modifier = {1.15, 1.25},
    .lifesteal = 0.0
};
void ApplyTraitEffects(TraitActivation& trait, ChampState& Champion){
    if (trait.numchamps >= trait.treshold[1]){
        
    }
    if (trait.numchamps >= trait.treshold[0]){

    }
};
//Imoportant Traits will activate separetely
void ApplyCelestialsTraitEffects(){
};
