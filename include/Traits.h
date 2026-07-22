#pragma once
#include <unordered_map>
#include <string>
enum class Trait {Guardian, Mage, Sniper, Bruiser, Assassin, Shadow_Fighters, Dark_Knights, Celestials, Lovers, Star_Forger, Titan};
struct TraitDef{ 
    std::string name;
    std::vector<int> thresholds;
    int numchampsT1 = 0;
    int numchampsT2 = 0;
    std::vector<float> hp_modifier;
    std::vector<float> ad_modifier;
    std::vector<float> ap_modifier;
    float lifesteal;
    std::vector<float> execute = {0,0};
    bool is_active = false;
};
const std::unordered_map<std::string, Trait> TRAIT_TRANSFORM = {
    {"Titan", Trait::Titan},
    {"StarForger", Trait::Star_Forger},
    {"Lovers", Trait::Lovers},
    {"Bruiser", Trait::Bruiser},
    {"Assassin", Trait::Assassin},
    {"Sniper", Trait::Sniper},
    {"Guardian", Trait::Guardian},
    {"Mage", Trait::Mage},
    {"Celestials", Trait::Celestials},
    {"ShadowFighters", Trait::Shadow_Fighters},
    {"DarkKnights", Trait::Dark_Knights},
};
inline std::unordered_map<Trait, TraitDef*> TRAIT_POOL;
void LoadTraits();