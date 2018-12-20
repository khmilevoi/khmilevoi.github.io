#include <iostream>
#include <vector>


std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
std::vector<int> results(prices.size(), -1);

int cut(size_t number_of_cuts) {
    results[0] = 0;
    size_t result = 0;

    auto max = [](size_t a, size_t b) -> int { return a > b ? a : b; };

    for(size_t i = 1; i < number_of_cuts + 1; ++i) {
        result = 0;
        for(size_t j = 1; j < i + 1; ++j) {
            result = max(result, prices[j - 1] + results[i - j]);
        }
        results[i] = result;
    }

    return results[number_of_cuts];
}

int main() {

    int number = 0;

    while(std::cin >> number && number != -1) {
        std::cout << cut(number) << '\n';
    }

    return 0;
}