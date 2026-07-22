#pragma once
#include <iostream>
#include "Champ.h"
#include "Team.h"
#include "Traits.h"
#include "Combat.h"
#include "Draw.h"
int main(){
	LoadTraits();
	LoadChampions();
	std::vector<ChampState> TeamA = CreateTeam();
	std::vector<ChampState> TeamB = CreateTeam();
	ApplyTraits(TeamA,TeamB);
	InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Autobattler");
    ToggleBorderlessWindowed();
	MaximizeWindow();
	int Width = GetScreenWidth();
    int Height = GetScreenHeight();
    SetTargetFPS(120);
    EnableCursor();
	while (!WindowShouldClose()){
		float dt = GetFrameTime();	
		run_combat(TeamA, TeamB, dt);
		BeginDrawing();	
		DrawCombat(TeamA, TeamB, Width, Height);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}