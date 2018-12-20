#include <vector>
#include <algorithm>
#include <fstream>

int main() {

    size_t amount_of_numbers = 0;
    std::vector<int> numbers;

    std::ifstream in("input.txt");

    in >> amount_of_numbers;

    for(size_t i = 0; i < amount_of_numbers; ++i) {
        int cash = 0;
        in >> cash;
        numbers.push_back(cash);
    }

    in.close();

    std::vector<size_t> answers(amount_of_numbers, 1);

    for(size_t i = 0; i < amount_of_numbers; ++i) {
        for(size_t j = 0; j < i; ++j) {
            if(numbers[i] % numbers[j] == 0) {
                if(answers[j] + 1 > answers[i]) {
                    answers[i] = answers[j] + 1;
                }
            }
        }
    }
    
    std::ofstream out("output.txt");

    out << *std::max_element(answers.begin(), answers.end());

    out.close();
}