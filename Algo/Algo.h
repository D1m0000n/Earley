#pragma once
#ifndef EARLEY_ALGO_H
#define EARLEY_ALGO_H

#include <iostream>
#include "Scan.h"
#include "Predict.h"
#include "Complete.h"

class Algo {
public:
    bool Earley();

    Algo() = default;

private:
    Grammar _Grammar;
    Scan _Scan;
    Predict _Predict;
    Complete _Complete;
    std::string word;
    std::vector<std::unordered_map<int, std::unordered_set<Info>>> D;

    void _init();
};

#endif //EARLEY_ALGO_H
