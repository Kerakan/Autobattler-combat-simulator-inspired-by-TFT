#pragma once
#include "Champ.h"
#include "Traits.h"
#include <vector>
inline std::vector<TraitDef*> TraitsInTeam1;
inline std::vector<TraitDef*> TraitsInTeam2;
inline bool someone_died = false;
inline float Shadow_Fighters_last = 0.0f;
inline float Shadow_Fighters_interval=1.0f;
inline float seconds_in_combat = 0.0f;
inline bool combat_started = false;
void ApplyTraits(std::vector<ChampState>& Team1, std::vector<ChampState>& Team2);
void run_combat(std::vector<ChampState>& Team1, std::vector<ChampState>& Team2, float DeltaTime);