#include "Complete.h"

void Complete::Complete_(std::vector<std::unordered_map<int, std::unordered_set<Info>>> &D, int j) {
    std::unordered_map<int, std::unordered_set<Info>> &D_j = D[j];

    for (auto &i : D_j) {
        for (auto &tmp_info : i.second) {
            if (tmp_info.rule.size() == tmp_info.point_position) {
                std::unordered_map<int, std::unordered_set<Info>> &D_i = D[tmp_info.index];

                for (auto &rule : D_i) {
                    for (auto &right_side : rule.second) {
                        if (right_side.rule.size() > right_side.point_position &&
                            i.first == right_side.rule[right_side.point_position]) {
                            D_j[rule.first].insert({right_side.rule, right_side.point_position + 1, j});
                        }
                    }
                }
            }
        }
    }
}
