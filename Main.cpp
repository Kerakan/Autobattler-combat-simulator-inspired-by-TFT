#pragma once
#include <iostream>
#include "Champ.h"
#include "Team.h"
#include "Combat.h"
#include "Traits.h"
#include "Draw.h"
int main(){
	LoadTraits();
	std::cout << "Traits loaded: " << TRAIT_STORAGE.size() << std::endl;
	LoadChampions();
	std::cout << "Champions loaded: " << CHAMP_POOL.size() << std::endl;
	std::vector<ChampState> TeamA = CreateTeam();
	std::vector<ChampState> TeamB = CreateTeam();	
	run_combat(TeamA, TeamB);
	return 0;
}