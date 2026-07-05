#pragma once
#include <iostream>
#include "TraitStatSystem.h"
#include "Team.h"
#include <chrono>
#include "AttacksAbilitiesDeathHandling.h"
void run_combat(std::vector<ChampState>& Team1, std::vector<ChampState>& Team2) {
    bool someone_died = false;
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
        //Start Team1 attacks
        for (ChampState& champion: Team1){
            if (champion.enemytarget == nullptr){
                std::cout<<"Team 2 is:"<<std::endl;
                for (ChampState& champ: Team2){
                    std::cout<<champ.def.name<<std::endl;
                }
                FindClosestEnemy(champion, Team2);
            }
            if (champion.hp_current <= 0 or champion.enemytarget->hp_current <= 0){
                someone_died = true;
                continue;
            }
            if (seconds_in_combat-champion.lastautoattacktime >= 1.0f/champion.attackspeed_current){
                champion.lastautoattacktime = seconds_in_combat;
                autoattack(champion);
            }   
            if (champion.mana_current >= champion.def.mana_max and champion.def.mana_max > 0){
                    Ability(champion, Team1, Team2);
                    champion.mana_current = 0;
                }
        }
        //Remove the Dead if there are any
        if (someone_died){
            Team2 = RemoveDead(Team2);
            for (ChampState& champion: Team1){
                    champion.enemytarget = nullptr;
            }
            someone_died = false;
        } 
        //If the enemy team is empty, team 1 wins
        if (Team2.empty()) {
            std::cout << "Team 1 wins!\n";
            break;
        }
        //Repeat the same as before but for the other team
        for (ChampState& champion: Team2){
            if (champion.enemytarget == nullptr){
                std::cout<<"Team 1 is:"<<std::endl;
                for (ChampState& champ: Team1){
                    std::cout<<champ.def.name<<std::endl;
                }
                FindClosestEnemy(champion, Team1);
            }
            if (champion.hp_current <= 0 or champion.enemytarget->hp_current <= 0){
                someone_died = true;
                continue;
            } 
            if (seconds_in_combat-champion.lastautoattacktime >= 1.0f/champion.attackspeed_current){
                champion.lastautoattacktime = seconds_in_combat;
                autoattack(champion);
            }
            if (champion.mana_current >= champion.def.mana_max){
                    Ability(champion, Team2, Team1);
                    champion.mana_current = 0;
                }       
        }
        if (someone_died){
            Team1 = RemoveDead(Team1);
            for (ChampState& champion: Team2){
                    champion.enemytarget = nullptr;
            }
            someone_died = false;
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
