#pragma once
#include "raylib.h"
#include "Grid.h"
#include "Champ.h"
#include <cmath>
void DrawInterfaceBackGround(){
    ClearBackground(BLACK);
};
void DrawStartButton(int width, int height){
    DrawRectangleLines((width/2)-150, height-150, 300, 150, WHITE);
    DrawRectangle((width/2)-149, height-149, 298, 148, BLUE);
    DrawText("START",(width/2)-85,(height-100),50,WHITE);
    Vector2 MousePos = GetMousePosition();
    Rectangle btnBounds = {(width/2)-150, height-150, 300, 150};
    if (CheckCollisionPointRec(MousePos,btnBounds)){
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            DrawText("COMBAT STARTED",(width/2)-85,(height/2)-100,50,WHITE);
        }
    }
}
void DrawHexagon(Vector2 center,Color color){
    DrawPolyLines(center,6,75,90,color);
}
void DrawGrid(int width, int height){
    //Draw the board converting axial coordinates to pixels:
    for (GridPos H : GridTeam2){
        int q = H.q;
        int r = H.r;
        Vector2 c={750 + 75 * (q * sqrt(3) + r * sqrt(3)/2), 537.5 + r * 112.5};
        DrawHexagon(c,YELLOW);
    }
    for (GridPos H : GridTeam1){
        int q = H.q;
        int r = H.r;
        Vector2 c={750 + 75 * (q * sqrt(3) + r * sqrt(3)/2), 537.5 + r * 112.5};
        DrawHexagon(c,RED);
    }
}
void DrawHealthBar(int Cx, int Cy, int rad,ChampState& champion){
    //Draw the outline of the hp bar
    float w = 2 * rad;
    float l = rad *(1.0f/4);
    DrawRectangleLines(Cx-rad,Cy+rad, w, l, WHITE);
    float hp_mult = std::max(champion.hp_current/champion.hp_max,0.0f);
    //DrawHealth
    DrawRectangle(Cx-rad+1,Cy+rad+1,  (w - 2)*hp_mult, l - 2, GREEN);
    //DrawShield
    float shield_mult = std::max(champion.current_shield/champion.hp_max,0.0f);
    DrawRectangle(Cx-rad+1+(w - 2)*hp_mult,Cy+rad+1,  (w - 2)*hp_mult*shield_mult, l - 2, WHITE);
}
void DrawChampions(std::vector<ChampState>& Team){
    for (ChampState& Champ: Team){
        std::string name = Champ.def.name;
        int q = Champ.pos.q;
        int r = Champ.pos.r;
        Vector2 c= {750 + 75 * (q * sqrt(3) + r * sqrt(3)/2), 537.5 + r * 112.5};
        DrawCircleLinesV(c, 50, WHITE);
        DrawText(name.c_str(), 750 + 75 * (q * sqrt(3) + r * sqrt(3)/2) - 25, 537.5 + r * 112.5 - 12.5, 20, WHITE);
        DrawHealthBar(c.x , c.y, 50, Champ);
    }
}
void DrawTraitsSkeleton(){
    DrawText("Team 2 Traits", 100, 100, 25, YELLOW);
    DrawLine(50,500,150,500, WHITE);
    DrawText("Team 1 Traits", 100, 550, 25, RED);
}
void DrawTraits(int position, std::vector<ChampState> &Team, std::vector<TraitActivation*> TraitsInTeam){
    DrawTraitsSkeleton();
    int i = 1;
    for (TraitActivation* trait: TraitsInTeam){
        if (trait->name != "Celestials"){
            if (position == 1){
                std::string text = trait->name+ " " + std::to_string(trait->numchampsT1);
                if (trait->numchampsT1 >= trait->treshold[1]){
                    DrawText(text.c_str(), 100, 550 + 75*i, 20, GOLD);
                    i++;
                }
                else if (trait->numchampsT1 >= trait->treshold[0]){
                    DrawText(text.c_str(), 100, 550 + 75*i, 20, LIGHTGRAY);
                    i++;
                }
            }
            else if (position == 0){
                std::string text = trait->name+ " " + std::to_string(trait->numchampsT2);
                if (trait->numchampsT2 >= trait->treshold[1]){
                    DrawText(text.c_str(), 100, 100 + 75*i, 20, GOLD);
                    i++;
                }
                else if (trait->numchampsT2 >= trait->treshold[0]){
                    DrawText(text.c_str(), 100, 100 + 75*i, 20, LIGHTGRAY);
                    i++;
                }
            }
        }
        else{
            if (position == 1){
                std::string text = trait->name+ " " + std::to_string(trait->numchampsT1);
                if (trait->numchampsT1 >= trait->treshold[0]){
                    DrawText(text.c_str(), 100, 550 + 75*i, 20, SKYBLUE);
                    i++;
                }
            }
            else if (position == 0){
                std::string text = trait->name+ " " + std::to_string(trait->numchampsT2);
                if (trait->numchampsT2 >= trait->treshold[1]){
                    DrawText(text.c_str(), 100, 100 + 75*i, 20, SKYBLUE);
                    i++;
                }
            }
        }
    }
}
void DrawConsoleLog(int width, int height){
    DrawRectangleLines((width-600), height, 600, -400, WHITE);
}