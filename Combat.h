#pragma once
#include <ctime>
#include <iostream>
#include "TraitStatSystem.h"
#include "Team.h"
void run_combat(std::vector<ChampState> Team1, std::vector<ChampState> Team2) {
    int combat_start_time = time(0);
    //sum how many of each trait there is
    for (ChampState& champion: Team1){
        for(Trait trait:champion.def.ChampTraits){
            TraitActivation* t = TRAIT_POOL.at(trait);
            t->numchamps++;
        }
    }
    //Now we apply the effects
    for (ChampState& champion: Team1){
        for(Trait trait:champion.def.ChampTraits){
            TraitActivation* t = TRAIT_POOL.at(trait);
            if (t->name != "Celestials" and t->name != "DarkKnights" and t->name != "ShadowFighters")
            ApplyTraitEffects(*t,champion);
        }
    }
    std::cout<<"Team 1 traits activated"<<std::endl;
    while (true) {
        int seconds_in_combat = int(time(0) - combat_start_time);
        if (seconds_in_combat > 15) {
            std::cout << "DRAW\n";
            break;
        }

    }
}