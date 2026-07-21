#pragma once
#include <unordered_map>
#include <ctime>
#include "Log.h"
#include <fstream>
#include "json.hpp"
struct Trait{
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
    bool operator==(const Trait& other) const{
        return name == other.name;
    }
};
inline std::unordered_map<std::string, Trait> TRAIT_STORAGE;
void LoadTraits(){
    std::ifstream f("data/Traits.json");
    nlohmann::json data = nlohmann::json::parse(f);
    for (auto& t: data){
        Trait trait;
        trait.name = t["name"];
        trait.treshold = t["thresholds"].get<std::vector<int>>();
        trait.hp_modifier = t["hp_modifier"].get<std::vector<float>>();
        trait.ad_modifier = t["ad_modifier"].get<std::vector<float>>();
        trait.ap_modifier = t["ap_modifier"].get<std::vector<float>>();
        trait.lifesteal   = t["lifesteal"];
        trait.execute     = t["execute"].get<std::vector<float>>();

        TRAIT_STORAGE[trait.name] = trait;
    }
}