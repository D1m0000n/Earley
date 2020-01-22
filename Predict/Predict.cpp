#include "Predict.h"

void Predict::Predict_(std::vector<std::unordered_map<int, std::unordered_set<Info>>> &D, int j,
                       std::unordered_map<int, std::unordered_set<std::vector<int>>> &rules) {
    std::unordered_map<int, std::unordered_set<Info>> &D_j = D[j];

    for (auto i = D_j.begin(); i != D_j.end(); ++i) {
        for (auto tmp_info : i->second) {
            if (tmp_info.point_position < tmp_info.rule.size()) {
                if (NonTerminal(tmp_info.rule[tmp_info.point_position])) {

                    for (auto & rule : rules) {
                        if (rule.first == tmp_info.rule[tmp_info.point_position]) {
                            for (auto p = rule.second.begin(); p != rule.second.end(); p++) {

                                D_j[rule.first].insert({*p, 0, j});
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Predict::NonTerminal(int a) {
    return -1 <= a && a < 26;
}
