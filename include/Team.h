#pragma once
#include <string>
#include <iostream>
#include "Champ.h"
#include <vector>
#include "Log.h"
int askteamcapacity(){
    int team_capacity;
    std::cout << "Input your desired team Capacity: " << std::endl;
    std::cin >> team_capacity;
    return team_capacity;
};
std::vector<ChampState> CreateTeam(){
    std::vector<ChampState> team;
    int x = askteamcapacity();
    team.reserve(x);
    int n = 0;
    while (n < x){
        std::string champname;
        int star;
        std::cout<<"Input the name of the desired champion"<<std::endl;
        std::cin>>champname;
        std::cout<<"Input the star level of the desired champion (0, 1 or 2)"<<std::endl;
        std::cin>>star;
        ChampState Champion = CreateChampion(champname,star);
        int q;
        int r;
        std::cout<<"Input the q coordinate of the desired champion"<<std::endl;
        std::cin>>q;
        std::cout<<"Input the r coordinate of the desired champion"<<std::endl;
        std::cin>>r;
        Champion.pos = GridPos(q,r);
        team.push_back(Champion);
        n += 1;
    };
    Log("Created Team with the following champions:");
    for (int i = 0; i<x; i++){
        std::string name = team[i].def.name;
        Log(name);
    }
    return team;
};