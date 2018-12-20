#include <iostream>
#include <vector>

int get_max_value(std::vector<int> list) {

    std::vector<std::vector<int>> result(list.size(), std::vector<int>(list.size()));
    for(size_t i = 0; i < result.size(); ++i) {
        result[i][i] = list[i];
    }


    auto max = [](int a, int b) -> int { return a > b ? a : b; };

    for(int i = result.size() - 2; i >= 0; --i) {
        for(size_t j = i + 1; j < result.size(); ++j) {
            for(size_t k = i; k < j; ++k) {
                result[i][j] = __max(result[i][j], result[i][k] * result[k + 1][j]);
                result[i][j] = __max(result[i][j], result[i][k] + result[k + 1][j]);
            }
        }
    }

    return result[0][result.size() - 1];
}

int main() {

    std::vector<int> sequence = {1, 50, 51, 50, 1};

    std::cout << get_max_value(sequence);

    return 0;
}