#pragma once
#include "Champ.h"
#include <unordered_map>
//Shadow Fighters
ChampDef Akira{
    .name = "Akira",
    .cost = 2,
    .range = 1,
    .mana_max = 40,//Will throw an ability that deals both magic and attack damage that damages the 3 nearest champions.
    .hp = {500, 900, 1600},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad = {75, 115, 175},
    .ap = {50, 75, 125},
    .attackspeed = {0.6,0.75,1.00},
    .ChampTraits = {Trait::Assassin, Trait::Shadow_Fighters}
};
ChampDef Totom{
    .name = "Totom",
    .cost = 3,
    .range = 1,
    .mana_max = 15, // No mana, he just autoattacks so as a bruiser he gets more life and more ad. Every third attack he gets a shield for 10% of his remaining health.
    .hp = {1050, 2000, 3200},
    .armor = {40, 80, 140},
    .magicres = {40, 80, 140},
    .ad = {80, 150, 200},
    .ap = {0, 0, 0},
    .attackspeed = {0.6,0.75,1.00},
    .ChampTraits = {Trait::Bruiser, Trait::Shadow_Fighters}
};
ChampDef Asura{
    .name = "Asura",
    .cost = 1,
    .range = 3,
    .mana_max = 0, // She will automatically target the the enemy with lowest hp dealing 10% more dmg to them.
    .hp = {450, 800, 1300},
    .armor = {15, 30, 60},
    .magicres = {15, 30, 60},
    .ad = {50, 75, 120},
    .ap = {0, 0, 0},
    .attackspeed = {1,1.2,1.5},
    .ChampTraits = {Trait::Sniper, Trait::Shadow_Fighters}
};
ChampDef Dante{
    .name = "Dante",
    .cost = 2,
    .range = 3,
    .mana_max= 50,// Nukes the enemy he is autoattacking dealing High AP damage.
    .hp = {500, 900, 1500},
    .armor = {20, 40, 75},
    .magicres={20,40,75},
    .ad = {20, 35, 60},
    .ap = {75, 115, 175},
    .attackspeed = {0.7,0.9,1.15},
    .ChampTraits={Trait::Mage, Trait::Shadow_Fighters}
};
ChampDef Takeshi{
    .name = "Takeshi",
    .cost = 1,
    .range = 1,
    .mana_max = 50, //Empowers and uses an attack dealing 10/15/25 more ad.
    .hp = {600, 1100, 1600},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad= {50, 75, 120},
    .ap = {0,0,0},
    .attackspeed = {0.7,0.9,1.15},
    .ChampTraits={Trait::Bruiser, Trait::Shadow_Fighters}

};
//Celestials
ChampDef Draco{
    .name = "Draco",
    .cost = 2,
    .range = 1,
    .mana_max = 60,// His ability will shield him and any ally in a touching hexagon for 30% of his max hp and will heal them for 10% of his current hp instantly.
    .hp = {700, 1400, 2100},
    .armor = {35, 70, 120},
    .magicres = {35, 70, 120},
    .ad = {20, 35, 60},
    .ap = {0,0,0},
    .attackspeed = {0.6,0.75,1.00},
    .ChampTraits = {Trait::Celestials, Trait::Guardian, Trait::Lovers}
};
ChampDef Lyra{
    .name = "Lyra",
    .cost = 3,
    .range = 3,
    .mana_max = 50, // Her ability will throw 2 piercing shots all the way to the back of the board dealing proportional damage based on her ad and the distance to the enemies.
    .hp = {600, 1200, 1900},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad = {100, 150, 250},
    .ap = {0, 0, 0},
    .attackspeed = {0.9,1.2,1.5},
    .ChampTraits = {Trait::Celestials, Trait::Sniper, Trait::Lovers}
};
ChampDef Orion{
    .name ="Orion",
    .cost = 1,
    .range = 2,
    .mana_max = 40, // throws a high ad shot to the enemy he is already attacking(non piercing).
    .hp ={450,800,1300},
    .armor = {15,30,60},
    .magicres = {15,30,60},
    .ad = {50,75,120},
    .ap = {0,0,0},
    .attackspeed = {1,1.2,1.5},
    .ChampTraits = {Trait::Celestials, Trait::Sniper}
};
ChampDef Andromeda{
    .name = "Andromeda",
    .cost = 2,
    .range = 1,
    .mana_max = 50, // Uses an empowered attack dealing 25% more damage.
    .hp = {650, 1250, 1900},
    .armor = {30, 60, 100},
    .magicres = {30, 60, 100},
    .ad = {75, 115, 160},
    .ap = {0, 0, 0},
    .attackspeed = {0.6, 0.75, 1.00},
    .ChampTraits = {Trait::Celestials, Trait::Bruiser}
};
ChampDef Delphinus{
    .name = "Delphinus",
    .cost = 1,
    .range = 1,
    .mana_max = 80, //High mana cost but will heal all allies for 30% of their remaining hp.
    .hp = {450, 700, 1100},
    .armor = {15, 30, 60},
    .magicres = {15, 30, 60},
    .ad = {20,35,65},
    .ap = {0, 0, 0},
    .attackspeed = {0.6, 0.75, 1.00},
    .ChampTraits = {Trait::Celestials, Trait::Mage}
};
//Dark Knights
ChampDef Hades{
    .name = "Hades",
    .cost = 3,
    .range = 3,
    .mana_max = 50, // Ability like Lyra's but his will deal ap damage instead of ad damage.
    .hp = {600, 1200, 1900},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad = {80, 130, 200},
    .ap = {50, 100, 175},
    .attackspeed = {0.9, 1.1, 1.4},
    .ChampTraits = {Trait::Dark_Knights, Trait::Sniper}
};
ChampDef Thanatos{
    .name = "Thanatos",
    .cost = 2,
    .range = 2,
    .mana_max = 40, // Does a higher damage attack
    .hp = {450, 800, 1500},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad = {50, 75, 120},
    .ap = {0, 0, 0},
    .attackspeed = {0.8, 0.9, 1.15},
    .ChampTraits = {Trait::Dark_Knights, Trait::Assassin}
};
ChampDef Vesper{
    .name = "Vesper",
    .cost = 1,
    .range = 1,
    .mana_max = 50, // Shields herself for 15% max health
    .hp = {650, 1300, 1800},
    .armor = {30, 60, 100},
    .magicres = {30, 60, 100},
    .ad = {20, 35, 60},
    .ap = {0, 0, 0},
    .attackspeed = {0.6, 0.75, 1.00},
    .ChampTraits = {Trait::Dark_Knights, Trait::Guardian}
};
ChampDef Cassian{
    .name = "Cassian",
    .cost = 2,
    .range = 1,
    .mana_max = 50, //Heals herself for 20% missing health and shields for 10% max health.
    .hp = {700, 1400, 2100},
    .armor = {35, 70, 120},
    .magicres = {35, 70, 120},
    .ad = {20, 35, 60},
    .ap = {0, 0, 0},
    .attackspeed = {0.6, 0.75, 1.00},
    .ChampTraits = {Trait::Dark_Knights, Trait::Guardian}
};
ChampDef Sable{
    .name = "Sable",
    .cost = 1,
    .range = 1,
    .mana_max = 30, // Heals for a percentage of the damage dealt on the next attack.
    .hp = {600, 1100, 1600},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad= {50, 75, 120},
    .ap = {0,0,0},
    .attackspeed = {0.7,0.9,1.15},
    .ChampTraits={Trait::Bruiser, Trait::Dark_Knights}
};
//Non Faction Trait Champions
ChampDef Goliath{
    .name = "Goliath",
    .cost = 3,
    .range = 1,
    .mana_max = 50, //becomes invulnerable for 2 seconds
    .hp = {1200, 2400, 3500},
    .armor = {50, 100, 175},
    .magicres = {50, 100, 175},
    .ad = {20, 35, 60},
    .ap = {0, 0, 0},
    .attackspeed = {0.6, 0.75, 1.00},
    .ChampTraits = {Trait::Titan, Trait::Guardian}
};
ChampDef Solarix{
    .name = "Solarix",
    .cost = 3,
    .range = 3,
    .mana_max = 100, //Throws a star from the sky dealing REALLY High AP damage to all enemies.
    .hp = {600, 1200, 1900},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad = {20, 35, 60},
    .ap = {100, 250, 400},
    .attackspeed = {0.6, 0.75, 1.00},
    .ChampTraits = {Trait::Star_Forger, Trait::Mage}
};

const std::unordered_map<std::string, const ChampDef*> CHAMP_POOL = {
    {"Akira",     &Akira},
    {"Totom",     &Totom},
    {"Asura",     &Asura},
    {"Dante",     &Dante},
    {"Takeshi",   &Takeshi},
    {"Draco",     &Draco},
    {"Lyra",      &Lyra},
    {"Orion",     &Orion},
    {"Andromeda", &Andromeda},
    {"Delphinus", &Delphinus},
    {"Hades",     &Hades},
    {"Thanatos",  &Thanatos},
    {"Vesper",    &Vesper},
    {"Cassian",   &Cassian},
    {"Sable",     &Sable},
    {"Goliath",   &Goliath},
    {"Solarix",   &Solarix}
};
ChampState CreateChampion(std::string name, int star){
    return ChampState(*CHAMP_POOL.at(name),star);
}
