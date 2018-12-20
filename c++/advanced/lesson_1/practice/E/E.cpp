#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

size_t max(size_t a, size_t b) {
    return a >= b ? a : b;
}

int main() {

    size_t max_weigth = 0;
    size_t number_of_things = 0;
    std::vector<int> things;

    std::ifstream in("input.txt");

    in >> max_weigth >> number_of_things;

    for(size_t i = 0; i < number_of_things; ++i) {
        size_t cash = 0;
        in >> cash;
        things.push_back(cash);
    }

    in.close();

    std::vector<std::vector<size_t>> answers(number_of_things + 1, std::vector<size_t>(max_weigth + 1));

    for(size_t thing = 1; thing < number_of_things + 1; ++thing) {
        for(size_t weigth = 1; weigth < max_weigth + 1; ++weigth) {
            answers[thing][weigth] = answers[thing - 1][weigth];
            int new_weight = things[thing - 1];
            if(weigth >= new_weight) {
                answers[thing][weigth] = max(answers[thing - 1][weigth], answers[thing - 1][weigth - new_weight] + new_weight);
            }
        }
    }

    std::ofstream out("output.txt");

    out << answers[number_of_things][max_weigth];

    out.close();

    return 0;
}
