#pragma once
#include <iostream>
#include <vector>
#include <string>
std::vector <std::string> LogTxts;
void Log(std::string text){
    LogTxts.push_back(text);
    std::cout<<text<<std::endl;
}