#pragma once
#include <ctime>
#include <iostream>
#include "TraitStatSystem.h"
#include "Team.h"
#include "AttacksAbilitiesDeathHandling.h"
void run_combat(std::vector<ChampState> Team1, std::vector<ChampState> Team2) {
    int combat_start_time = time(0);
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
        int seconds_in_combat = int(time(0) - combat_start_time);
        std::cout<<"Starting Team1 attacks"<<std::endl;
        for (ChampState& champion: Team1){
            if (champion.enemytarget ==nullptr){
                FindClosestEnemy(champion, Team2);
            }
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
        if (Team2.empty()) {
            std::cout << "Team 1 wins!\n";
            break;
        }
        std::cout<<"Starting Team2 attacks"<<std::endl;
        for (ChampState& champion: Team2){
            if (champion.enemytarget == nullptr){
                FindClosestEnemy(champion, Team1);
            }
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
        if (Team1.empty()) {
            std::cout << "Team 2 wins!\n";
            break;
        }
        if (seconds_in_combat > 15) {
            std::cout << "DRAW\n";
            break;
        }

    }
}
