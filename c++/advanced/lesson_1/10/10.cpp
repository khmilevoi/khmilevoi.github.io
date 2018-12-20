#include <iostream>
#include <vector>
#include <iterator>
#include <limits>
#include <algorithm>

const int _INFINITY = std::numeric_limits<int>::max() / 2;

std::vector<int> find_of_sequence(std::vector<int> list) {

    int size_of_list = list.size();

    std::vector<int> ends_of_sequences(size_of_list + 1, _INFINITY);
    ends_of_sequences[0] = - _INFINITY;

    std::vector<int> positions(size_of_list + 1);
    positions[0] = -1;

    std::vector<int> previouse(size_of_list);

    int length = 0;

    auto max = [](int a, int b) -> int { return a > b ? a : b; };

    for(int element_of_list = 0; element_of_list < size_of_list; ++element_of_list) {

        std::vector<int>::iterator left_search = std::upper_bound(ends_of_sequences.begin(), ends_of_sequences.end(), list[element_of_list]);

        int element_of_end_sequence = std::distance(ends_of_sequences.begin(), left_search);

        if(
            ends_of_sequences[element_of_end_sequence - 1] < list[element_of_list] &&
            list[element_of_list] < ends_of_sequences[element_of_end_sequence]
        ) {

            ends_of_sequences[element_of_end_sequence] = list[element_of_list];
            positions[element_of_end_sequence] = element_of_list;
            previouse[element_of_list] = positions[element_of_end_sequence - 1];
            length = max(length, element_of_end_sequence);
        }
    }

    std::vector<int> answer;

    int element = positions[length];
    while(element != -1) {

        answer.push_back(list[element]);
        element = previouse[element];
    }

    std::reverse(answer.begin(), answer.end());

    return answer;
}

int main() {

    std::ios_base::sync_with_stdio(false);

    std::vector<int> sequence = {1, 5, 3, 4, 8, 2, 7, 6};

    sequence = find_of_sequence(sequence);

    for(auto i : sequence) {
        std::cout << i << ' ';
    }

    return 0;
}