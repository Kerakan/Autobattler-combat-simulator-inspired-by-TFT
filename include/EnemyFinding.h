#pragma once
#include <iostream>
#include <vector>
#include "Champ.h"
#include "Grid.h"
std::vector<GridPos> neighbours(GridPos pos);
void MoveCloser(ChampState &champ, ChampState &target, std::vector<ChampState> &AllyTeam, std::vector<ChampState> &EnemyTeam);
void FindClosestEnemy(ChampState &Champ, std::vector<ChampState> &AllyTeam, std::vector<ChampState> &EnemyTeam);