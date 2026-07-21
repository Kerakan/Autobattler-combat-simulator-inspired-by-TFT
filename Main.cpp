#pragma once
#include <iostream>
#include "Champ.h"
#include "Team.h"
#include "Traits.h"
#include "Combat.h"
#include "Draw.h"
int main(){
	LoadTraits();
	LoadChampions();
	std::vector<ChampState> TeamA = CreateTeam();
	std::vector<ChampState> TeamB = CreateTeam();	
	run_combat(TeamA, TeamB);
	return 0;
}