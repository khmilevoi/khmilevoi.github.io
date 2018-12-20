#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

const double PI = 3.14;
const double RAD_TO_DEG = 180 / PI;
const double RADIUS = 1;

int main() {

    std::ifstream in("input.txt");

    int number_of_angles = 0;

    in >> number_of_angles;

    int numer_of_coordinates = 0;

    in >> numer_of_coordinates;

    std::vector<std::vector<double>> angles;

    for(int angle = 0; angle < number_of_angles; ++angle) {

        double cash = 0;
        in >> cash;
        angles.push_back({cash, (double)angle + 1});
    }

    in.close();

    std::cout << number_of_angles << ' ' << numer_of_coordinates << '\n';

    std::sort(
        angles.begin(), 
        angles.end(), 
        [](std::vector<double> left, std::vector<double> right) {

            return left[0] < right[0];
        }
    );

    for(auto angle : angles) {

        for(auto num : angle) {

            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    std::vector<std::vector<double>> squares(numer_of_coordinates, std::vector<double>(number_of_angles));

    for(int row = 0; row < numer_of_coordinates; ++row) {
        for(int col = 0; col < number_of_angles; ++col) {

            
        }
    }

    return 0;
}