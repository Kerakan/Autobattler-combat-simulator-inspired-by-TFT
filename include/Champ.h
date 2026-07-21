#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "Grid.h"
#include "Traits.h"
struct ChampDef{
    std::string name;
    int cost;
    int range;
    int mana_max;
    std::array <float,3> hp;
    std::array <float,3> armor;
    std::array <float,3> magicres;
    std::array <float,3> ad;
    std::array <float,3> ap;
    std::array <float,3> attackspeed;
    std::vector <std::string> ChampTraits;
};
struct ChampState{
    const ChampDef& def;
    GridPos pos = GridPos(0,0);
    ChampState* enemytarget=nullptr;
    float lastautoattacktime = 0.0f;
    int star;
    int range;
    float hp_current;
    int mana_current;
    float armor_current;
    float magicres_current;
    float ad_current;
    float ap_current;
    float attackspeed_current;
    float current_shield = 0;
    float lifesteal = 0;
    float execute = 0;
    float hp_max = 0;
    float is_invulnerable_until = 0.0f;
    ChampState(const ChampDef& d, int s): def(d), star(s){
        range = def.range;
        hp_current = def.hp[star];
        mana_current = 0;
        armor_current = def.armor[star];
        magicres_current = def.magicres[star];
        ad_current = def.ad[star];
        ap_current = def.ap[star];
        attackspeed_current = def.attackspeed[star];
    }
    ChampState operator=(const ChampState& other){
        return ChampState(other.def, other.star);
    }
};
inline std::unordered_map<std::string, ChampDef> CHAMP_STORAGE;
inline std::unordered_map<std::string, const ChampDef*> CHAMP_POOL;
void LoadChampions(){
    std::ifstream f("data/ChampionPool.json");
    nlohmann::json cdata = nlohmann::json::parse(f);
    for (auto& c: cdata){
        ChampDef def;
        def.name     = c["name"];
        def.cost     = c["cost"];
        def.range    = c["range"];
        def.mana_max = c["mana_max"];
        def.hp       = {c["hp"][0], c["hp"][1], c["hp"][2]};
        def.armor    = {c["armor"][0], c["armor"][1], c["armor"][2]};
        def.magicres = {c["magicres"][0], c["magicres"][1], c["magicres"][2]};
        def.ad       = {c["ad"][0], c["ad"][1], c["ad"][2]};
        def.ap       = {c["ap"][0], c["ap"][1], c["ap"][2]};
        def.attackspeed = {c["attackspeed"][0], c["attackspeed"][1], c["attackspeed"][2]};
        def.ChampTraits = c["traits"].get<std::vector<std::string>>();
        CHAMP_STORAGE[def.name] = def;
    }
    for (auto& [name, def] : CHAMP_STORAGE) {
        CHAMP_POOL[name] = &def;
    }
}
ChampState CreateChampion(const std::string& name, int star) {
    return ChampState(*CHAMP_POOL.at(name), star);
}