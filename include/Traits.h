#pragma once
#include <unordered_map>
#include <string>
#include "json.hpp"
#include <fstream>
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
inline void LoadTraits() {
    std::ifstream f("data/Traits.json");
    nlohmann::json data = nlohmann::json::parse(f);
    for (auto& t : data) {
        TraitDef* trait = new TraitDef();
        trait->name        = t["name"];
        trait->thresholds  = t["thresholds"].get<std::vector<int>>();
        trait->hp_modifier = t["hp_modifier"].get<std::vector<float>>();
        trait->ad_modifier = t["ad_modifier"].get<std::vector<float>>();
        trait->ap_modifier = t["ap_modifier"].get<std::vector<float>>();
        trait->lifesteal   = t["lifesteal"];
        trait->execute     = t["execute"].get<std::vector<float>>();

        TRAIT_POOL[TRAIT_TRANSFORM.at(trait->name)] = trait;
    }
}
