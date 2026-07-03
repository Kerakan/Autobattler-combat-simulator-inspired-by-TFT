#include "Champ.h"
#include "EnemyFinding.h"
#include <functional>
#include "Grid.h"
void autoattack(ChampState &champ){
    if (champ.enemytarget == nullptr){
        std::cout<<"No enemy target found for "<<champ.def.name<<std::endl;
        return;
    }
    float damage = champ.ad_current*(100/(100+champ.enemytarget->armor_current));
    std::cout<<"Champion "<<champ.def.name<<" attacks with AD: "<<champ.ad_current<< " to "<<champ.enemytarget->def.name<<" dealing "<<damage<<std::endl;
    if (champ.enemytarget->current_shield >0){
        if (champ.enemytarget->current_shield >= damage){
            champ.enemytarget->current_shield -= damage;
            damage = 0;
        }
        else{
            champ.enemytarget->current_shield = 0;
            damage -= champ.enemytarget->current_shield;
        }
    }
    champ.enemytarget->hp_current -= damage;
    champ.mana_current += 5;
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
using AbilityFunction = std::function<void(ChampState&, std::vector<ChampState>&, std::vector<ChampState>&)>;
void akira_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    //Find 3 closest enemies,
    std::vector<ChampState> targets;
    for (ChampState& enemy: EnemyTeam){
        if (targets.size() < 3){
            targets.push_back(enemy);
        }
        else{
            int max_distance = 0;
            int max_index = 0;
            for (int i = 0; i<targets.size(); i++){
                int dis = distance(champ.pos, targets[i].pos);
                if (dis > max_distance){
                    max_distance = dis;
                    max_index = i;
                }
            }
            if (distance(champ.pos, enemy.pos) < max_distance){
                targets[max_index] = enemy;
            }
        }
    }
    //attacks now
    for (ChampState& target: targets){
        float damage = champ.ap_current*(100/(50+target.magicres_current));
        if (target.current_shield >0){
            if (target.current_shield >= damage){
                target.current_shield -= damage;
                damage = 0;
            }
            else{
                target.current_shield = 0;
                damage -= target.current_shield;
            }
        }
        target.hp_current -= damage;
        std::cout<<"Champion "<<champ.def.name<<" uses ability on "<<target.def.name<<" dealing "<<damage<< " damage"<<std::endl;
    }
}
void totom_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    champ.current_shield += 0.1f*champ.hp_current;
    std::cout<<"Champion "<<champ.def.name<<" uses ability gaining a shield of "<<champ.current_shield<<std::endl;
}
void asura_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    //Yet to be programmed
}
void dante_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    float damage = champ.ap_current*(100/(35+champ.enemytarget->magicres_current));
    champ.enemytarget->hp_current -= damage;
    if (champ.enemytarget->current_shield >0){
        if (champ.enemytarget->current_shield >= damage){
            champ.enemytarget->current_shield -= damage;
            damage = 0;
        }
        else{
            champ.enemytarget->current_shield = 0;
            damage -= champ.enemytarget->current_shield;
        }
    }
    champ.enemytarget->hp_current -= damage;
    std::cout<<"Champion "<<champ.def.name<<" uses ability on "<<champ.enemytarget->def.name<<" dealing "<<damage<< " damage"<<std::endl;
}
void takeshi_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    if (champ.star==0){
        champ.ad_current += 10;
    }
    else if (champ.star==1){
        champ.ad_current += 15;
    }
    else if (champ.star==2){
        champ.ad_current += 25;
    }
    float extra_ad = champ.ad_current-champ.def.ad[champ.star];
    std::cout<<"Champion "<<champ.def.name<<" uses ability getting "<<extra_ad<<" more ad"<<std::endl;
    autoattack(champ);
    champ.ad_current -= extra_ad;
}
void draco_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    for (ChampState& ally: AllyTeam){
        if (distance(champ.pos, ally.pos) <=1){
            ally.current_shield += 0.3f*champ.def.hp[champ.star];
            ally.hp_current += 0.1f*champ.hp_current;
            std::cout<<"Champion "<<champ.def.name<<" uses ability on "<<ally.def.name<<"gaining a shield of "<<ally.current_shield<<" and healing "<<0.1f*champ.hp_current<<std::endl;
        }
    }
}
void lyra_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    //Yet to be programmed
}
void orion_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    if (champ.star==0){
        champ.ad_current += 15;
    }
    else if (champ.star==1){
        champ.ad_current += 25;
    }
    else if (champ.star==2){
        champ.ad_current += 40;
    }
    float extra_ad = champ.ad_current-champ.def.ad[champ.star];
    std::cout<<"Champion "<<champ.def.name<<" uses ability"<<"getting "<<extra_ad<<" more ad"<<std::endl;
    autoattack(champ);
    champ.ad_current -= extra_ad;
}
void andromeda_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    float x = champ.ad_current;
    champ.ad_current *= 1.25f;
    std::cout<<"Champion "<<champ.def.name<<" uses ability"<<"getting "<<0.25f*champ.ad_current<<" more ad"<<std::endl;
    autoattack(champ);
    champ.ad_current = x;
}
void delphinus_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    for (ChampState& ally: AllyTeam){
        float missing_health = ally.def.hp[ally.star]-ally.hp_current;
        ally.hp_current += 0.3f*missing_health;
    }
}
void hades_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    //Yet to be programmed
}
void thanatos_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){

}
void vesper_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){

}
void cassian_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){

}
void sable_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){

}
void goliath_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){

}
void solarix_ability(ChampState& champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){

}
const std::unordered_map<std::string, AbilityFunction> ABILITY_MAP = {
    {"Akira",     akira_ability},
    {"Totom",     totom_ability},
    {"Asura",     asura_ability},
    {"Dante",     dante_ability},
    {"Takeshi",   takeshi_ability},
    {"Draco",     draco_ability},
    {"Lyra",      lyra_ability},
    {"Orion",     orion_ability},
    {"Andromeda", andromeda_ability},
    {"Delphinus", delphinus_ability},
    {"Hades",     hades_ability},
    {"Thanatos",  thanatos_ability},
    {"Vesper",    vesper_ability},
    {"Cassian",   cassian_ability},
    {"Sable",     sable_ability},
    {"Goliath",   goliath_ability},
    {"Solarix",   solarix_ability},
};
void Ability(ChampState &champ, std::vector<ChampState>& AllyTeam, std::vector<ChampState>& EnemyTeam){
    std::cout<<"Champion "<<champ.def.name<<" is using their ability"<<std::endl;
    AbilityFunction ability = ABILITY_MAP.at(champ.def.name);
    ability(champ, AllyTeam, EnemyTeam);
}
