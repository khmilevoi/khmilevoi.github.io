#include <fstream>
#include <vector>
#include <limits>

int main() {

    std::ifstream in("input.txt");

    int number_of_deputies = 0;

    in >> number_of_deputies;

    int number_of_stations = 0;

    in >> number_of_stations;

    std::vector<int> houses_of_deputies;

    for (int deputy = 0; deputy < number_of_deputies; ++deputy) {

        int cash = 0;
        in >> cash;
        houses_of_deputies.push_back(cash);
    }

    in.close();

    std::vector<std::vector<int>> answer(number_of_deputies, std::vector<int>(number_of_stations));

    std::vector<int> distances_to_end(number_of_deputies);

    for (int row = 0; row < number_of_deputies - 1; ++row) {

        for (int col = row + 1; col < number_of_deputies; ++col) {

            distances_to_end[row] += houses_of_deputies[col] - houses_of_deputies[row];
        }
    }

    std::vector<std::vector<int>> previouse_distance(
        number_of_deputies, 
        std::vector<int>(number_of_stations, std::numeric_limits<int>::max() / 2)
    );

    for (int index = 0; index < number_of_deputies; ++index) {

        int sum = 0;

        for (int element = 0; element < index; ++element) {

            sum += houses_of_deputies[index] - houses_of_deputies[element];
        }

        previouse_distance[index][0] = sum;
    }

    int distance = std::numeric_limits<int>::max() / 2;

    if (number_of_stations == 1) {

        int res = 0;

        for (int index = 0; index < number_of_deputies; ++index) {

            if (distance > previouse_distance[index][0] + distances_to_end[index]) {

                distance = previouse_distance[index][0] + distances_to_end[index];
                res = index;
            }
        }

        std::ofstream out("output.txt");

        out << distance << '\n';
        out << houses_of_deputies[res];

        out.close();
        return 0;
    }

    int last = 0;

    for (int row = 1; row < number_of_deputies; ++row) {

        for (int col = 1; col < number_of_stations; ++col) {

            int min = std::numeric_limits<int>::max() / 2;
            int cash = 0;

            for (int index = 0; index < row; ++index) {

                auto _min = [](int left, int right) { 

                    return left < right ? left : right; 
                };

                int sum = 0;

                for (int element = index; element < row + 1; ++element) {

                    sum += _min(
                        houses_of_deputies[element] - houses_of_deputies[index], 
                        houses_of_deputies[row] - houses_of_deputies[element]
                    );
                }

                cash = previouse_distance[index][col - 1] + sum;

                if (min > cash) {

                    min = cash;
                    answer[row][col] = index;
                }
            }

            previouse_distance[row][col] = min;
            cash = min + distances_to_end[row];

            if (distance > cash) {
                last = row;
                distance = cash;
            }
        }
    }

    int cash_last = last;
    int cash_number = number_of_stations;

    std::vector<int> result;

    result.push_back(houses_of_deputies[last]);

    for (int counter = 0; counter < number_of_deputies; ++counter) {

        if (cash_number == 1) {

            break;
        }

        int element = answer[cash_last][cash_number - 1];

        result.push_back(houses_of_deputies[element]);

        cash_last = element;
        --cash_number;
    }

    std::ofstream out("output.txt");

    out << distance << '\n';

    for (int index = 0; index < result.size(); ++index) {
        out << result[result.size() - index - 1] << ' ';
    }

    out.close();

    return 0;
}
