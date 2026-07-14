#pragma once
#include <iostream>
#include <algorithm>
#include "TraitStatSystem.h"
#include "Team.h"
#include <chrono>
#include "AttacksAbilitiesDeathHandling.h"
#include "Draw.h"
void run_combat(std::vector<ChampState>& Team1, std::vector<ChampState>& Team2) {
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Autobattler");
    ToggleBorderlessWindowed();
    MaximizeWindow();
    int Width = GetScreenWidth();
    int Height = GetScreenHeight();
    SetTargetFPS(120);
    EnableCursor();
    bool someone_died = false;
    auto combat_start = std::chrono::steady_clock::now();
    float Shadow_Fighters_last = 0.0f;
    float Shadow_Fighters_interval=1.0f;
    int sf_count_t1 = 0;
    int sf_count_t2 = 0;
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
            if (t->name != "Celestials" and t->name != "ShadowFighters") ApplyTraitEffects(*t,champion);
            else if(t->name == "Celestials") ApplyCelestialsTraitEffects(champion);
            if (t->name == "ShadowFighters") sf_count_t1 ++;
        }
    }
    //Reset the trait champion count 
    for (ChampState& champion: Team1){
        for(Trait trait: champion.def.ChampTraits){
            TraitActivation* t = TRAIT_POOL.at(trait);
            t->numchamps= 0;
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
            if (t->name != "Celestials" and t->name != "ShadowFighters") ApplyTraitEffects(*t,champion);
            else if(t->name == "Celestials") ApplyCelestialsTraitEffects(champion);
            if (t->name == "ShadowFighters") sf_count_t2 ++;
            }
        }
    //Reset Numchamp count
    for (ChampState& champion: Team2){
        for(Trait trait: champion.def.ChampTraits){
            TraitActivation* t = TRAIT_POOL.at(trait);
            t->numchamps = 0;
        }
    }
    std::cout<<"Team 2 traits activated"<<std::endl;
    //Define max hp for each champion
    for (ChampState& c: Team1) c.hp_max = c.hp_current;
    for (ChampState& c: Team2) c.hp_max = c.hp_current;
    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawInterfaceBackGround();
        DrawStartButton(Width,Height);
        DrawConsoleLog(Width,Height);
        DrawGrid(Width,Height);
        auto now = std::chrono::steady_clock::now();
        float seconds_in_combat = std::chrono::duration<float>(now - combat_start).count();
        //Apply ShadowFighter per second
        if(seconds_in_combat-Shadow_Fighters_last >= Shadow_Fighters_interval){
            TRAIT_POOL.at(Trait::Shadow_Fighters)->numchamps = sf_count_t1;
            for (ChampState& champion: Team1){
                if (TRAIT_POOL.at(Trait::Shadow_Fighters)->numchamps >= TRAIT_POOL.at(Trait::Shadow_Fighters)->treshold[0]){
                    if (std::find(champion.def.ChampTraits.begin(), champion.def.ChampTraits.end(), Trait::Shadow_Fighters) != champion.def.ChampTraits.end()){
                        ApplyShadowFighterTraitEffects(champion);
                    }
                }
            }
            TRAIT_POOL.at(Trait::Shadow_Fighters)->numchamps = sf_count_t2;
            for (ChampState& champion: Team2){
                if (TRAIT_POOL.at(Trait::Shadow_Fighters)->numchamps >= TRAIT_POOL.at(Trait::Shadow_Fighters)->treshold[0]){
                    if (std::find(champion.def.ChampTraits.begin(), champion.def.ChampTraits.end(), Trait::Shadow_Fighters) != champion.def.ChampTraits.end()){
                        ApplyShadowFighterTraitEffects(champion);
                    }
                }
            }
            Shadow_Fighters_last = seconds_in_combat;
        }
        //Start Team1 attacks
        DrawChampions(Team1);
        for (ChampState& champion: Team1){
            if (champion.enemytarget == nullptr or champion.def.name == "Asura"){
                FindClosestEnemy(champion, Team1, Team2);
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
        DrawChampions(Team2);
        for (ChampState& champion: Team2){
            if (champion.enemytarget == nullptr or champion.def.name == "Asura"){
                FindClosestEnemy(champion, Team2, Team1);
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
        EndDrawing();
    }
    CloseWindow();
}