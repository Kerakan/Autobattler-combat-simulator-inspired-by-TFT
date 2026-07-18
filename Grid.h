#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
struct GridPos{
        int q;
        int r;
        int s = -q - r;
        GridPos(int q, int r): q(q), r(r){}
        bool operator==(const GridPos&) const = default;
};
int distance (GridPos a, GridPos b){
    return (abs(a.q - b.q) + abs(a.r - b.r) + abs(a.s - b.s)) / 2;
};
std::vector<GridPos> Trajectory(GridPos a, GridPos b){
    int q1; int q2; int r1; int r2; int s1; int s2;
    q1 = a.q; r1 = a.r; s1 = a.s;
    q2 = b.q; r2 = b.r; s2 = b.s;
    int d = distance(a,b);
    std::vector<GridPos> HexesInTraj;
    for (int i = 0; i<=d+3; i++){
        float t = float(i)/d;
        float qfloat = q1 + (q2-q1)*t;
        float rfloat = r1 + (r2-r1)*t;
        float sfloat = s1 + (s2-s1)*t;
        int q = std::round(qfloat);
        int r = std::round(rfloat);
        int s = std::round(sfloat);
        float diffq = abs(q-qfloat);
        float diffr = abs(r-rfloat);
        float diffs = abs(s-sfloat);
        float maxdiff = std::max({diffq, diffr, diffs});
        int qfinal;
        int rfinal;
        if (maxdiff == diffq){
            qfinal = -r - s;
            rfinal = r;
        }
        else if (maxdiff == diffr){
            qfinal = q;
            rfinal = -q - s;
        }
        else if (maxdiff == diffs){
            qfinal = q;
            rfinal = r;
        }
        if (std::find(HexesInTraj.begin(),HexesInTraj.end(),GridPos(qfinal,rfinal))==HexesInTraj.end()) HexesInTraj.push_back(GridPos(qfinal,rfinal));
    }
    return HexesInTraj;
}
std::vector<GridPos> GridTeam2 = {GridPos(0,-3),GridPos(1,-3),GridPos(2,-3),GridPos(3,-3),GridPos(-1,-2),GridPos(0,-2),GridPos(1,-2),GridPos(2,-2), GridPos(3,-2),GridPos(-1,-1),GridPos(0,-1),GridPos(1,-1),GridPos(2,-1)};
std::vector<GridPos> GridTeam1 = {GridPos(-2,0),GridPos(-1,0),GridPos(0,0),GridPos(1,0),GridPos(-3,1),GridPos(-2,1),GridPos(-1,1),GridPos(0,1),GridPos(1,1),GridPos(-3,2),GridPos(-2,2),GridPos(-1,2),GridPos(0,2)};