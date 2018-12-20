#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

enum direction {
    left,
    top,
    diag,
    swap
};

std::vector<int> Films(std::vector<int> first_friend, std::vector<int> second_friend, std::vector<int> third_friend) {

    size_t size_of_first = first_friend.size();
    size_t size_of_second = second_friend.size();
    size_t size_of_third = third_friend.size();

    std::vector<std::vector<std::vector<int>>> search_of_sequence(
        size_of_first + 1,
        std::vector<std::vector<int>>(
            size_of_second + 1,
            std::vector<int>(size_of_third + 1)));

    std::vector<std::vector<std::vector<direction>>> sequence_of_directions(
        size_of_first + 1,
        std::vector<std::vector<direction>>(
            size_of_second + 1,
            std::vector<direction>(size_of_third + 1)));

    for (size_t i = 1; i < size_of_first + 1; ++i) {
        for (size_t j = 1; j < size_of_second + 1; ++j) {
            for (size_t k = 1; k < size_of_third + 1; ++k) {

                if (first_friend[i - 1] == second_friend[j - 1] &&
                    first_friend[i - 1] == third_friend[k - 1]) {

                    search_of_sequence[i][j][k] = search_of_sequence[i - 1][j - 1][k - 1] + 1;
                    sequence_of_directions[i][j][k] = diag;
                }
                else {

                    if (search_of_sequence[i - 1][j][k] >= search_of_sequence[i][j - 1][k] &&
                        search_of_sequence[i - 1][j][k] >= search_of_sequence[i][j][k - 1]) {

                        search_of_sequence[i][j][k] = search_of_sequence[i - 1][j][k];
                        sequence_of_directions[i][j][k] = top;
                    }
                    else if (search_of_sequence[i][j - 1][k] >= search_of_sequence[i - 1][j][k] &&
                             search_of_sequence[i][j - 1][k] >= search_of_sequence[i][j][k - 1]) {

                        search_of_sequence[i][j][k] = search_of_sequence[i][j - 1][k];
                        sequence_of_directions[i][j][k] = left;
                    }
                    else if (search_of_sequence[i][j][k - 1] >= search_of_sequence[i][j - 1][k] &&
                             search_of_sequence[i][j][k - 1] >= search_of_sequence[i - 1][j][k]) {

                        search_of_sequence[i][j][k] = search_of_sequence[i][j][k - 1];
                        sequence_of_directions[i][j][k] = swap;
                    }
                }
            }
        }
    }

    std::vector<int> answer;

    int i = size_of_first;
    int j = size_of_second;
    int k = size_of_third;

    while (true) {
        if (i == 0 || j == 0 || k == 0) {
            break;
        }
        if (sequence_of_directions[i][j][k] == diag) {
            answer.push_back(first_friend[i - 1]);
            i -= 1;
            j -= 1;
            k -= 1;
        }
        else if (sequence_of_directions[i][j][k] == top) {
            i -= 1;
        }
        else if (sequence_of_directions[i][j][k] == left) {
            j -= 1;
        } else {
            k -= 1;
        }
    }

    std::reverse(answer.begin(), answer.end());

    return answer;
}

int main() {

    std::vector<int> number_of_films;

    std::ifstream in("input.txt");

    for (size_t i = 0; i < 3; ++i) {
        int cash = 0;
        in >> cash;
        number_of_films.push_back(cash);
    }

    std::vector<std::vector<int>> list_of_films(3);

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < number_of_films[i]; ++j) {
            int cash;
            in >> cash;
            list_of_films[i].push_back(cash);
        }
    }

    in.close();

    std::vector<int> answer = Films(list_of_films[0], list_of_films[1], list_of_films[2]);

    std::ofstream out("output.txt");

    out << std::to_string(answer.size()) << '\n';

    for (auto i : answer) {
        out << std::to_string(i) << ' ';
    }

    return 0;
}
