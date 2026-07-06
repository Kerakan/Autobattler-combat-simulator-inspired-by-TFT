#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "Grid.h"
enum class Trait {Guardian, Mage, Sniper, Bruiser, Assassin, Shadow_Fighters, Dark_Knights, Celestials, Lovers, Star_Forger, Titan};
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
    std::vector <Trait> ChampTraits;
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