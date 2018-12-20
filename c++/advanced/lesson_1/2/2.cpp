#include <iostream>
#include <vector>

int bin(size_t n, size_t m) {

    std::vector<std::vector<int>> cash(n + 1, std::vector<int>(n + 1, 1));
    for(size_t i = 1; i < n + 1; ++i) {
        for(size_t j = 1; j < i; ++j) {
            cash[i][j] = cash[i - 1][j - 1] + cash[i - 1][j];
        }
    }

    for(auto i : cash) {
        for(auto j : i) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }

    return cash[n][m];
}

int main() {
    std::cout << bin(4, 3);
    return 0;
}