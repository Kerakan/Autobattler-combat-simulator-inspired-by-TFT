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
void MoveCloser(ChampState &champ, ChampState &target, std::vector<ChampState> &AllyTeam, std::vector<ChampState> &EnemyTeam){
    GridPos champpos = champ.pos;
    GridPos targetpos = target.pos;
    std::vector<GridPos> possible_moves = {};
    for (GridPos move: neighbours(champ.pos)){
        if (std::find(GridTeam1.begin(),GridTeam1.end(),move)!=GridTeam1.end() or std::find(GridTeam2.begin(),GridTeam2.end(),move)!=GridTeam2.end()){
            possible_moves.push_back(move);
        }
    }
    for (GridPos move: possible_moves){
        if (distance(move, targetpos) < distance(champpos, targetpos)){
            bool is_occupied = false;
            for (ChampState &champ : AllyTeam) {
                if (champ.pos.q == move.q && champ.pos.r == move.r) {
                    is_occupied = true;
                }
            }
            for (ChampState &champ : EnemyTeam) {
                if (champ.pos.q == move.q && champ.pos.r == move.r) {
                    is_occupied = true;
                }
            }
            if (is_occupied) continue;
            champ.pos = move;
            break;
        }
    }
};
void FindClosestEnemy(ChampState &Champ, std::vector<ChampState> &AllyTeam, std::vector<ChampState> &EnemyTeam){
    GridPos champpos = Champ.pos;
    Champ.enemytarget = &EnemyTeam[0];
    int closest_distance = 1000;
    if (Champ.def.name == "Asura"){
        float lowest_hp =EnemyTeam[0].hp_current;
        ChampState* target = Champ.enemytarget;
        for (ChampState &Enemy: EnemyTeam){
            if (Enemy.hp_current < lowest_hp){
                lowest_hp = Enemy.hp_current;
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
            Log("Champion " + Champ.def.name + " found enemy " + Champ.enemytarget->def.name);
        }
        else{
            while(closest_distance>Champ.range){
                Log("Champion " + Champ.def.name + " is moving closer to enemy " + Champ.enemytarget->def.name);
                MoveCloser(Champ, *Champ.enemytarget, AllyTeam, EnemyTeam);
                //if (Champ.enemytarget->enemytarget == &Champ){
               //     std::cout<<"Champion "<<Champ.enemytarget->def.name<<" is moving closer to enemy "<< Champ.def.name<<std::endl;
                //    MoveCloser(*Champ.enemytarget, Champ, EnemyTeam, AllyTeam);
               // }
                closest_distance = distance(Champ.pos, Champ.enemytarget->pos);
            }
            Log("Champion " + Champ.def.name + " found enemy " + Champ.enemytarget->def.name);
        }
    }   
}