#pragma once
#ifndef EARLEY_COMPLETE_H
#define EARLEY_COMPLETE_H

#include "Grammar.h"

class Complete {
public:
    void Complete_(std::vector<std::unordered_map<int, std::unordered_set<Info>>> &D, int j);
};


#endif //EARLEY_COMPLETE_H
