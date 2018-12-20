#include <iostream>
#include <vector>

std::vector<std::vector<int>> warshall(std::vector<std::vector<int>> adjacent_matrix) {
    for(size_t i = 0; i < adjacent_matrix.size(); ++i) {
        for(size_t j = 0; j < adjacent_matrix.size(); ++j) {
            for(size_t k = 0; k < adjacent_matrix.size(); ++k) {
                adjacent_matrix[j][k] = adjacent_matrix[j][k] | (adjacent_matrix[j][i] & adjacent_matrix[i][k]);
            }
        }
    }
    return adjacent_matrix;
}

int main() {

    std::vector<std::vector<int>> adjacent_matrix {
        {{0}, {1}, {0}, {0}},
        {{0}, {0}, {0}, {1}},
        {{0}, {0}, {0}, {0}},
        {{1}, {0}, {1}, {0}}
    };

    for(auto i : adjacent_matrix) {
        for(auto j : i) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    adjacent_matrix = warshall(adjacent_matrix);

    for(auto i : adjacent_matrix) {
        for(auto j : i) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}