#include "Champ.h"
ChampDef Akira{
    .name = "Akira",
    .cost = 2,
    .range = 1,
    .mana_max = 40,//Will throw an ability that deals both magic and attack damage that damages the 3 nearest champions.
    .hp = {500, 900, 1600},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 80},
    .ad = {75, 115, 175},
    .ap = {50, 75, 125},
    .attackspeed = {0.6,0.75,1.00},
    .ChampTraits = {Trait::Assassin, Trait::Shadow_Fighters}
};
ChampDef Totom{
    .name = "Totom",
    .cost = 3,
    .range = 1,
    .mana_max = 0, // No mana, he just autoattacks so as a bruiser he gets more life and more ad.
    .hp = {1050, 2000, 3500},
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
ChampDef Date{
    .name = "Date",
    .cost = 2,
    .range = 3,
    .mana_max= 50,// Nukes the enemy she is autoattacking dealing High AP damage.
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
    .mana_max = 50, //Empowers its next attack dealing 10/15/25 more ad
    .hp = {600, 1100, 1600},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad= {50, 75, 120},
    .ap = {0,0,0},
    .attackspeed = {0.7,0.9,1.15},
    .ChampTraits={Trait::Bruiser, Trait::Shadow_Fighters}

};
ChampDef Draco{
    .name = "Draco",
    .cost = 2,
    .range = 1,
    .mana_max = 80,// His ability will shield him and any ally in a touching hexagon for 30% of his max hp and will heal them for 10% of his current hp instantly.
    .hp = {700, 1250, 2100},
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
    .mana_max = 60, // Her ability will throw 2 piercing shots all the way to the back of the board dealing proportional damage based on her ad and the distance to the enemies.
    .hp = {600, 1200, 1900},
    .armor = {20, 40, 75},
    .magicres = {20, 40, 75},
    .ad = {100, 150, 250},
    .ap = {0, 0, 0},
    .attackspeed = {0.9,1.2,1.5},
    .ChampTraits = {Trait::Celestials, Trait::Sniper, Trait::Lovers}
};