#include <iostream>
#include <vector>
#include <iterator>
#include <limits>
#include <algorithm>

const int _INFINITY = std::numeric_limits<int>::max() / 2;

std::vector<int> find_of_sequence(const std::vector<int> &list) {

    std::vector<int> reverse_list = list;
    std::reverse(reverse_list.begin(), reverse_list.end());

    int size_of_sequence = reverse_list.size();
    
    std::vector<int> ends_of_sequence(size_of_sequence + 1, _INFINITY);
    ends_of_sequence[0] = - _INFINITY;
    
    std::vector<int> position(size_of_sequence + 1);
    position[0] = -1;

    std::vector<int> previouse(size_of_sequence);

    int length = 0;

    auto max = [](int a, int b) { return a > b ? a : b; };

    for(int element_of_sequence = 0; element_of_sequence < size_of_sequence; ++element_of_sequence) {

        std::vector<int>::iterator left_search = std::upper_bound(ends_of_sequence.begin(), ends_of_sequence.end(), reverse_list[element_of_sequence]);

        int element_of_ends_sequence = std::distance(ends_of_sequence.begin(), left_search);

        if(
            ends_of_sequence[element_of_ends_sequence - 1] < reverse_list[element_of_sequence] && 
            reverse_list[element_of_sequence] < ends_of_sequence[element_of_ends_sequence]
        ) {

            ends_of_sequence[element_of_ends_sequence] = reverse_list[element_of_sequence];
            position[element_of_ends_sequence] = element_of_sequence;
            previouse[element_of_sequence] = position[element_of_ends_sequence - 1];
            length = max(length, element_of_ends_sequence);
        }
    }
    std::vector<int> answer;
    int element = position[length];
    

    while(element != -1) {
        answer.push_back(size_of_sequence - element);
        element = previouse[element];
    }

    return answer;
}

int main() {

    std::ios_base::sync_with_stdio(false);

    std::vector<int> sequence = {1, 2, 4, 3, 5};

    sequence = find_of_sequence(sequence);

    for(auto i : sequence) {
        std::cout << i << ' ';
    }

    return 0;
}