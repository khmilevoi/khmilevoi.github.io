#include <iostream>
#include <limits>
#include <vector>

std::vector<std::vector<int>> floid(std::vector<std::vector<int>> adjacent_matrix) {
    for(size_t i = 0; i < adjacent_matrix.size(); ++i) {
        for(size_t j = 0; j < adjacent_matrix.size(); ++j) {
            for(size_t k = 0; k < adjacent_matrix.size(); ++k) {
                adjacent_matrix[j][k] = __min(adjacent_matrix[j][k], adjacent_matrix[j][i] + adjacent_matrix[i][k]);
            }
        }
    }
    return adjacent_matrix;
}

int main() {

    std::vector<std::vector<int>> adjacent_matrix {
        {{0}, {1}, {10}, {10}, {10}},
        {{10}, {0}, {1}, {10}, {10}},
        {{10}, {10}, {0}, {1}, {10}},
        {{10}, {10}, {10}, {0}, {1}},
        {{10}, {10}, {10}, {10}, {0}}
    };

    for(auto i : adjacent_matrix) {
        for(auto j : i) {
            if(j != 10) {
                std::cout << j << ' ';
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    adjacent_matrix = floid(adjacent_matrix);

    for(auto i : adjacent_matrix) {
        for(auto j : i) {
            if(j != 10) {
                std::cout << j << ' ';
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << '\n';
    }

    return 0;
}