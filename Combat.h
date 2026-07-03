#pragma once
#include <iostream>
#include "TraitStatSystem.h"
#include "Team.h"
#include <chrono>
#include "AttacksAbilitiesDeathHandling.h"
void run_combat(std::vector<ChampState> Team1, std::vector<ChampState> Team2) {
    auto combat_start = std::chrono::steady_clock::now();
    //sum how many of each trait there is
    for (ChampState& champion: Team1){
        for(Trait trait: champion.def.ChampTraits){
            TraitActivation* t = TRAIT_POOL.at(trait);
            t->numchamps++;
        }
    }
    //Now we apply the effects
    for (ChampState& champion: Team1){
        for(Trait trait: champion.def.ChampTraits){
            TraitActivation* t = TRAIT_POOL.at(trait);
            if (t->name != "Celestials" and t->name != "DarkKnights" and t->name != "ShadowFighters")
            ApplyTraitEffects(*t,champion);
        }
    }
    std::cout<<"Team 1 traits activated"<<std::endl;
    for (ChampState& champion: Team2){
        for(Trait trait: champion.def.ChampTraits){
            TraitActivation* t = TRAIT_POOL.at(trait);
            t->numchamps++;
        }
    }
    //Now we apply the effects
    for (ChampState& champion: Team2){
        for(Trait trait: champion.def.ChampTraits){
            TraitActivation* t = TRAIT_POOL.at(trait);
            if (t->name != "Celestials" and t->name != "DarkKnights" and t->name != "ShadowFighters")
            ApplyTraitEffects(*t,champion);
        }
    }
    std::cout<<"Team 2 traits activated"<<std::endl;
    while (true) {
        auto now = std::chrono::steady_clock::now();
        float seconds_in_combat = std::chrono::duration<float>(now - combat_start).count();
        for (ChampState& champion: Team1){
            if (champion.enemytarget ==nullptr){
                FindClosestEnemy(champion, Team2);
            }
            if (seconds_in_combat-champion.lastautoattacktime >= 1.0f/champion.attackspeed_current){
                champion.lastautoattacktime = seconds_in_combat;
                autoattack(champion);
                if (champion.enemytarget->hp_current <= 0){
                    std::cout<<"Champion "<<champion.enemytarget->def.name<<" is dead"<<std::endl;
                    for (ChampState& champ: Team2){
                        if (champ.enemytarget == champion.enemytarget){
                            champ.enemytarget = nullptr;
                        }
                    }
                    RemoveDead(Team2);
                }
            }
            if (champion.mana_current >= champion.def.mana_max){
                    Ability(champion, Team1, Team2);
                    champion.mana_current = 0;
                }
        }
        if (Team2.empty()) {
            std::cout << "Team 1 wins!\n";
            break;
        }
        for (ChampState& champion: Team2){
            if (champion.enemytarget == nullptr){
                FindClosestEnemy(champion, Team1);
            }
            if (seconds_in_combat-champion.lastautoattacktime >= 1.0f/champion.attackspeed_current){
                champion.lastautoattacktime = seconds_in_combat;
                autoattack(champion);
                if (champion.enemytarget->hp_current <= 0){
                    std::cout<<"Champion "<<champion.enemytarget->def.name<<" is dead"<<std::endl;
                    for (ChampState& champ: Team1){
                        if (champ.enemytarget == champion.enemytarget){
                            champ.enemytarget = nullptr;
                        }
                    }
                        RemoveDead(Team1);
                }
            }
            if (champion.mana_current >= champion.def.mana_max){
                    Ability(champion, Team2, Team1);
                    champion.mana_current = 0;
                }       
        }
        if (Team1.empty()) {
            std::cout << "Team 2 wins!\n";
            break;
        }
        if (seconds_in_combat > 30) {
            std::cout << "DRAW\n";
            break;
        }

    }
}
