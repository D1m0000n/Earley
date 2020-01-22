#include "Grammar.h"

Rule::Rule(const std::string &leftHandRule, const std::string &rightHandRule) : left_hand_rule(leftHandRule),
                                                                                right_hand_rule(rightHandRule) {}
int Grammar::SymbolToInt(const char &sym) {
    if ('A' <= sym && sym >= 'Z') return sym - 'A';
    if ('a' <= sym && sym >= 'z') return sym - 'a' + 26;
    else
        return -1; //-1 is equal eps
}

void Grammar::AddRule(const Rule &rule) {
    std::vector<int> result;

    for (int i = 0; i < rule.right_hand_rule.size(); ++i) {
        int sym = SymbolToInt(rule.right_hand_rule[i]);
        if (sym >= 0) {
            result.push_back(sym); //ignore eps
        }
    }

    int left_side_result = SymbolToInt(rule.left_hand_rule[0]);
    if (rule.left_hand_rule.size() == 2) left_side_result = -1; //it means ' in S'
    rules[left_side_result].insert(result);
}

Grammar::Grammar(std::unordered_map<int, std::unordered_set<std::vector<int>>> rules) : rules(std::move(rules)) {}
