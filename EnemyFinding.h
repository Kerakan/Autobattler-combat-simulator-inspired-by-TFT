#pragma once
#include <iostream>
#include <vector>
#include "Champ.h"
#include "Grid.h"
std::vector<GridPos> neighbours(GridPos pos){
    std::vector<GridPos> result;
    result.push_back(GridPos(pos.q + 1, pos.r));
    result.push_back(GridPos(pos.q - 1, pos.r));
    result.push_back(GridPos(pos.q, pos.r + 1));
    result.push_back(GridPos(pos.q, pos.r - 1));
    result.push_back(GridPos(pos.q + 1, pos.r - 1));
    result.push_back(GridPos(pos.q - 1, pos.r + 1));
    return result;
};
void MoveCloser(ChampState &champ, ChampState &target){
    GridPos champpos = champ.pos;
    GridPos targetpos = target.pos;
    std::vector<GridPos> possible_moves = neighbours(champpos);
    for (GridPos move: possible_moves){
        if (distance(move, targetpos) < distance(champpos, targetpos)){
            champ.pos = move;
            break;
        }
    }
};
void FindClosestEnemy(ChampState &Champ, std::vector<ChampState> &EnemyTeam){
    GridPos champpos = Champ.pos;
    Champ.enemytarget = &EnemyTeam[0];
    int closest_distance = 1000;
    for (ChampState &Enemy: EnemyTeam){
        GridPos enemypos = Enemy.pos;
        int dis = distance(champpos,enemypos);
        if (dis < closest_distance){
            closest_distance = dis;
            Champ.enemytarget = &Enemy;
        }
    }
}