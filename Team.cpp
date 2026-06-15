#pragma once
#include <string>
#include <iostream>
#include "Champ.h"
#include <vector>
#include "ChampionPool.h"
int askteamcapacity(){
    int team_capacity;
    std::cout << "Input your desired team Capacity: ";
    std::cin >> team_capacity;
    return team_capacity;
};
std::vector<ChampState> CreateTeam(){
    std::vector<ChampState> team;
    int x = askteamcapacity();
    int n = 0;
    while (n < x){
        std::string champname;
        std::cout<<"Input the name of the desired champion";
        std::cin>>champname;
        ChampState Champion = CreateChampion(champname,0);
        team.push_back(Champion);
    };
    return team;
};
std::vector<ChampState> team = CreateTeam();