#ifndef EARLEY_GRAMMAR_H
#define EARLEY_GRAMMAR_H
#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Rule{
public:
    std::string left_hand_rule;
    std::string right_hand_rule;

    Rule(const std::string& leftHandRule, const std::string &rightHandRule);
};

class Grammar {
public:
    Grammar(std::unordered_map<int, std::unordered_set<std::vector<int>>> rules);

    void AddRule(const Rule &rule);

    std::unordered_map<int, std::unordered_set< std::vector<int>> > rules;

private:
    static int SymbolToInt(const char &sym);
};

class Info {
public:
    std::vector<int> rule;
    int point_position;
    int index;

    Info() = default;
};



#endif //EARLEY_GRAMMAR_H
