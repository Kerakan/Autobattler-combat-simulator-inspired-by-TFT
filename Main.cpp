#pragma once
#include <iostream>
#include "Champ.h"
#include "Team.h"
#include "Combat.h"
int main(){
	std::vector<ChampState> Team1 = CreateTeam();
	std::vector<ChampState> Team2 = CreateTeam();
	run_combat(Team1, Team2);
	return 0;
}