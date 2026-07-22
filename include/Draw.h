#pragma once
#include "raylib.h"
#include "Champ.h"
#include "Traits.h"
void DrawDamage();
void DrawInterfaceBackGround(int width, int height);
void DrawSecondsInCombat(int width, int height, int seconds);
void DrawStartButton(int width, int height);
void DrawHexagon(Vector2 center,Color color);
void DrawGrid(int width, int height);
void DrawHealthBar(int Cx, int Cy, int rad,ChampState& champion);
void DrawChampions(std::vector<ChampState>& Team);
void DrawTraitsSkeleton();
void DrawTraits(int position, std::vector<ChampState> &Team, std::vector<TraitDef*> TraitsInTeam);
void DrawConsoleLog(int width, int height);
void Accelerate(std::vector<ChampState>& Team1, std::vector<ChampState>& Team2);
void DrawCombat(std::vector<ChampState>& Team1, std::vector<ChampState>& Team2, int Width, int Height);