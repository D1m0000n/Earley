#ifndef EARLEY_PREDICT_H
#define EARLEY_PREDICT_H
#pragma once

#include "Grammar.h"

class Predict {
public:
    void
    Predict_(std::vector<std::unordered_map<int, std::unordered_set<Info>>> &D, int j,
             std::unordered_map<int, std::unordered_set<std::vector<int>>> &rules);

private:
    bool NonTerminal(int a);
};


#endif //EARLEY_PREDICT_H
