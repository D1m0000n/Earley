#include "Algo.h"

bool Algo::Earley() {
    _init();

    for (int j = 0; j < word.size(); j++) {
        _Scan.Scan_(D, j, word[j]);

        int current_size = 0;
        int new_size = -1;

        while (current_size != new_size) {
            current_size = new_size;

            _Complete.Complete_(D, j);
            _Predict.Predict_(D, j, _Grammar.rules);

            new_size = 0;
            for (auto &i : D[j]) {
                new_size += i.second.size();
            }
        }

        return D[word.size()][-1].find({std::vector<int>{static_cast<int>('S' - 'A')}, 1, 0}) !=
               D[word.size()][-1].end();
    }

}

void Algo::_init() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) { //initialization
        std::string left_side;
        std::string right_side;
        std::cin >> left_side >> right_side;
        _Grammar.AddRule({left_side, right_side});
    }
    std::cin >> word;
    D.resize(word.size() + 1);
    //-1 is @S'@
    D[0][-1].insert({std::vector<int>{static_cast<int>('S' - 'A')}, 0, 0});
}
