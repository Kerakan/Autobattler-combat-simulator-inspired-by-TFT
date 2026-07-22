#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Log.h"
void Log(std::string text){
    LogTxts.push_back(text);
    std::cout<<text<<std::endl;
}