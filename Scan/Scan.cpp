#include "Scan.h"

void Scan::Scan_(std::vector<std::unordered_map<int, std::unordered_set<Info>>> &D, int j, char w) {
    if (j == 0) return;

    std::unordered_map<int, std::unordered_set<Info>> &D_j_1 = D[j - 1];
    std::unordered_map<int, std::unordered_set<Info>> &D_j = D[j];

    for (auto & i : D_j_1) {
        for (auto k = i.second.begin(); k != i.second.end(); k++) {
            Info tmp_info = *k;
            if (tmp_info.point_position < tmp_info.rule.size()) {
                if (IsTerminal(tmp_info.rule[tmp_info.point_position]) &&
                    (tmp_info.rule[tmp_info.point_position] - 26) == static_cast<int>(w - 'a')) {
                    D_j[i.first].insert({tmp_info.rule, tmp_info.point_position + 1, tmp_info.index});
                }
            }
        }
    }
}

bool Scan::IsTerminal(int a) {
    return 26 <= a && a < 26 * 2;
}
