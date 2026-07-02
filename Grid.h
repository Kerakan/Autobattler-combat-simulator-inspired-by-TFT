#pragma once
#include <iostream>
#include <vector>
struct GridPos{
        int q;
        int r;
        int s = -q - r;
        GridPos(int q, int r): q(q), r(r){}
};
int distance (GridPos a, GridPos b){
    return (abs(a.q - b.q) + abs(a.r - b.r) + abs(a.s - b.s)) / 2;
};