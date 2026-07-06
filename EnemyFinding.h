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
    if (Champ.def.name == "Asura"){
        float lowest_hp =EnemyTeam[0].def.hp[EnemyTeam[0].star];
        ChampState* target = Champ.enemytarget;
        for (ChampState &Enemy: EnemyTeam){
            if (Enemy.def.hp[Enemy.star] < lowest_hp){
                lowest_hp = Enemy.def.hp[Enemy.star];
                Champ.enemytarget = &Enemy;
            }
        }
    }
    else{    
        for (ChampState &Enemy: EnemyTeam){
            GridPos enemypos = Enemy.pos;
            int dis = distance(champpos,enemypos);
            if (dis < closest_distance){
                closest_distance = dis;
                Champ.enemytarget = &Enemy;
            }
        }
        if (closest_distance<=Champ.range){
            std::cout<<"Champion "<<Champ.def.name<<" found enemy "<< Champ.enemytarget->def.name<<std::endl;
        }
        else{
            while(closest_distance>Champ.range){
                std::cout<<"Champion "<<Champ.def.name<<" is moving closer to enemy "<< Champ.enemytarget->def.name<<std::endl;
                MoveCloser(Champ, *Champ.enemytarget);
                if (Champ.enemytarget->enemytarget == &Champ){
                    std::cout<<"Champion "<<Champ.enemytarget->def.name<<" is moving closer to enemy "<< Champ.def.name<<std::endl;
                    MoveCloser(*Champ.enemytarget, Champ);
                }
                closest_distance = distance(Champ.pos, Champ.enemytarget->pos);
            }
            std::cout<<"Champion "<<Champ.def.name<<" found enemy "<< Champ.enemytarget->def.name<<std::endl;
        }
    }   
}