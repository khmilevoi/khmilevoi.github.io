#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

const int _INFINITY = std::numeric_limits<int>::max();

std::vector<int> find_of_sequence(const std::vector<int> &list) {

    std::vector<int> rev_list = list;
    std::reverse(rev_list.begin(), rev_list.end());

    int size_of_list = rev_list.size();

    std::vector<int> ends_of_sequences(size_of_list + 1, _INFINITY);
    ends_of_sequences[0] = - _INFINITY;

    std::vector<int> positions(size_of_list + 1);
    positions[0] = -1;

    std::vector<int> previouse(size_of_list);

    auto max = [](int left, int right) { 

        return left < right ? right : left; 
    };

    int length = 0;

    for (int element_of_list = 0; element_of_list < size_of_list; ++element_of_list) {


        std::vector<int>::iterator beg = ends_of_sequences.begin();

        std::vector<int>::iterator end = ends_of_sequences.end();

        std::vector<int>::iterator left_search = std::lower_bound(beg, end, rev_list[element_of_list]);

        int end_of_sequence = std::distance(beg, left_search);

        if (
            ends_of_sequences[end_of_sequence - 1] < rev_list[element_of_list] &&
            rev_list[element_of_list] < ends_of_sequences[end_of_sequence]
        ) {

            ends_of_sequences[end_of_sequence] = rev_list[element_of_list];
            positions[end_of_sequence] = element_of_list;
            previouse[element_of_list] = positions[end_of_sequence - 1];
            length = max(length, end_of_sequence);
        }
    }

    std::vector<int> answer;

    int element = positions[length];

    while (element != -1) {

        answer.push_back(size_of_list - element);
        element = previouse[element];
    }

    return answer;
}

int main() {

    std::ifstream in("input.txt");

    int amount_of_people = 0;

    in >> amount_of_people;

    std::vector<int> people;

    for (int human = 0; human < amount_of_people; ++human) {

        int cash = 0;
        in >> cash;
        people.push_back(cash);
    }

    in.close();

    std::vector<int> answer = find_of_sequence(people);

    std::ofstream out("output.txt");

    out << answer.size() << '\n';

    for (auto i : answer) {

        out << i << '\n';
    }

    out.close();

    return 0;
}
