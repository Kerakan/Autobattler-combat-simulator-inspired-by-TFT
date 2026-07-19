#pragma once
#include <iostream>
#include <vector>
#include <string>
std::vector <std::string> LogTxts;
void Log(std::string text){
    LogTxts.push_back(text);
    std::cout<<text<<std::endl;
}
struct TimedText{
    std::string text;
    int q;
    int r;
    float defined_until;
    TimedText(std::string text, int q, int r, float defined_at)
    : text(text), q(q), r(r), defined_until(defined_at + 0.5f) {}
};
std::vector<TimedText> TimedTexts;