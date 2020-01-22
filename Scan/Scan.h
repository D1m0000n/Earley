#pragma once
#ifndef EARLEY_SCAN_H
#define EARLEY_SCAN_H

#include "Grammar.h"

class Scan {
public:
    void Scan_(std::vector<std::unordered_map<int, std::unordered_set<Info>>> &D, int j, char w);

private:
    bool IsTerminal(int a);
};


#endif //EARLEY_SCAN_H
