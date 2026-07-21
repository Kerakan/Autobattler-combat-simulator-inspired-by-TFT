#pragma once
#include <iostream>
#include <algorithm>
#include "TraitStatSystem.h"
#include "Traits.h"
#include "Team.h"
#include <chrono>
#include "AttacksAbilitiesDeathHandling.h"
#include "Draw.h"
#include "Log.h"
void run_combat(std::vector<ChampState>& Team1, std::vector<ChampState>& Team2) {
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Autobattler");
    ToggleBorderlessWindowed();
    MaximizeWindow();
    int Width = GetScreenWidth();
    int Height = GetScreenHeight();
    SetTargetFPS(120);
    EnableCursor();
    bool someone_died = false;
    float Shadow_Fighters_last = 0.0f;
    float Shadow_Fighters_interval=1.0f;
    std::vector<TraitDef*> TraitsInTeam1;
    std::vector<TraitDef*> TraitsInTeam2;
    //sum how many of each trait there is
    for (ChampState& champion: Team1){
        for(Trait trait: champion.def.ChampTraits){
            TraitDef* t = TRAIT_POOL.at(trait);
            if (std::find(TraitsInTeam1.begin(),TraitsInTeam1.end(),t)==TraitsInTeam1.end()){
                TraitsInTeam1.push_back(t);
            }
            t->numchampsT1++;
        }
    }
    //Now we apply the effects
    for (ChampState& champion: Team1){
        for(Trait trait: champion.def.ChampTraits){
            TraitDef* t = TRAIT_POOL.at(trait);
            if (t->name != "Celestials" and t->name != "ShadowFighters") ApplyTraitEffects(*t,champion,1);
            else if(t->name == "Celestials") ApplyCelestialsTraitEffects(champion,1);
        }
    }
    Log("Team 1 traits activated");
    for (ChampState& champion: Team2){
        for(Trait trait: champion.def.ChampTraits){
            TraitDef* t = TRAIT_POOL.at(trait);
            if (std::find(TraitsInTeam2.begin(),TraitsInTeam2.end(),t)==TraitsInTeam2.end()){
                TraitsInTeam2.push_back(t);
            }
            t->numchampsT2++;
        }
    }
    //Now we apply the effects
    for (ChampState& champion: Team2){
        for(Trait trait: champion.def.ChampTraits){
            TraitDef* t = TRAIT_POOL.at(trait);
            if (t->name != "Celestials" and t->name != "ShadowFighters") ApplyTraitEffects(*t,champion,2);
            else if(t->name == "Celestials") ApplyCelestialsTraitEffects(champion,2);
            }
        }
    Log("Team 2 traits activated");
    //Define max hp for each champion
    for (ChampState& c: Team1) c.hp_max = c.hp_current;
    for (ChampState& c: Team2) c.hp_max = c.hp_current;
    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawInterfaceBackGround(Width,Height);
        DrawTraits(1,Team1,TraitsInTeam1);
        DrawTraits(0,Team2,TraitsInTeam2);
        DrawStartButton(Width,Height);
        DrawConsoleLog(Width,Height);
        DrawDamage();
        DrawGrid(Width,Height);
        if (combat_started){
            auto now = std::chrono::steady_clock::now();
            float seconds_in_combat = std::chrono::duration<float>(now - combat_start).count();
            if(IsKeyDown(KEY_A)) Accelerate(Team1, Team2);
            if(IsKeyDown(KEY_D)) Decelerate(Team1, Team2);
            //Apply ShadowFighter per second
            if(seconds_in_combat-Shadow_Fighters_last >= Shadow_Fighters_interval){
                for (ChampState& champion: Team1){
                    if (TRAIT_POOL.at(Trait::Shadow_Fighters)->numchampsT1 >= TRAIT_POOL.at(Trait::Shadow_Fighters)->thresholds[0]){
                        if (std::find(champion.def.ChampTraits.begin(), champion.def.ChampTraits.end(), Trait::Shadow_Fighters) != champion.def.ChampTraits.end()){
                            ApplyShadowFighterTraitEffects(champion,1);
                        }
                    }
                }
                for (ChampState& champion: Team2){
                    if (TRAIT_POOL.at(Trait::Shadow_Fighters)->numchampsT2 >= TRAIT_POOL.at(Trait::Shadow_Fighters)->thresholds[0]){
                        if (std::find(champion.def.ChampTraits.begin(), champion.def.ChampTraits.end(), Trait::Shadow_Fighters) != champion.def.ChampTraits.end()){
                            ApplyShadowFighterTraitEffects(champion,2);
                        }
                    }
                }
                Shadow_Fighters_last = seconds_in_combat;
            }
            //Start Team1 attacks
            DrawSecondsInCombat(Width, Height, int(seconds_in_combat));
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
                    autoattack(champion, Team1, Team2);
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
                    autoattack(champion, Team2, Team1);
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
        }
        else{
            DrawChampions(Team1);
            DrawChampions(Team2);
        }
        EndDrawing();
    }
    CloseWindow();
}