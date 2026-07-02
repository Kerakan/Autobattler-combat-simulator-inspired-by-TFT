#include "Champ.h"
#include "EnemyFinding.h"
void autoattack(ChampState &champ){
    if (champ.enemytarget == nullptr){
        std::cout<<"No enemy target found for "<<champ.def.name<<std::endl;
        return;
    }
    float damage = champ.ad_current*(100/(100+champ.enemytarget->armor_current));
    std::cout<<"Champion "<<champ.def.name<<" attacks with AD: "<<champ.ad_current<< " to "<<champ.enemytarget->def.name<<" dealing "<<damage<<std::endl;
    champ.enemytarget->hp_current -= damage;
}
void RemoveDead(std::vector<ChampState> &team){
    std::vector<ChampState> aux = {};
    for (ChampState& champ: team){
        if (champ.hp_current > 0){
            aux.push_back(champ);
        }
        if (champ.hp_current <= 0){
            std::cout<<"Removing dead champion: "<< champ.def.name<<std::endl;
        }
    }
        team=aux;
}