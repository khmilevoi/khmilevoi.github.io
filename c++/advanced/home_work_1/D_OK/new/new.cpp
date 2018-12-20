#include <iostream>

#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

const int _INFINITY = std::numeric_limits<int>::max() / 2;

int main() {

    std::ifstream in("../input.txt");

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

    std::vector<std::vector<std::vector<int>>> graph(number_of_deputies);

    for(int deputy = 0; deputy < number_of_deputies; ++deputy) {

        for(int index = 0; index < deputy; ++index) {

            if(deputy != index) {

                int distance = 0;

                for(int inner_index = index; inner_index < deputy; ++inner_index) {

                    distance += houses_of_deputies[deputy] - houses_of_deputies[inner_index];
                }

                graph[deputy].push_back({index, distance});
            }
        }
    }

    for(auto i : graph) {
        for(auto j : i) {
            for(auto k : j) {

                std::cout << k << ' ';
            }
            std::cout << "  ";
        }
        std::cout << '\n';
    }

    // def get_min_reliable_distance(u: int, v: int, k: int) -> int:
    // # k -- максимально допустимая длина надёжного пути
    
    // # список кратчайших расстояний:
    // dist = [[float('inf')] * (k + 1) for _ in range(n)]
    // dist[u][0] = 0

    // for t in range(k):
    //     for v1 in range(n):
    //         for j in range(len(graph[v1])):
    //             v2, w = graph[v1][j]
    //             dist[v2][t + 1] = min(dist[v2][t + 1], dist[v1][t] + w)
    // return dist[v][k]
   
    std::vector<std::vector<int>> distances(number_of_deputies, std::vector<int>(number_of_stations + 1, _INFINITY));
    distances[0][0] = 0;

    for(int row = 0; row < number_of_deputies; ++row) {
        for(int col = 0; col < number_of_stations; ++col) {
            for(int index = 0; index < graph[row].size(); ++index) {

                int vertex = graph[row][index][0];
                int weigth = graph[row][index][1];
                distances[vertex][col + 1] = std::min(distances[vertex][col + 1], distances[row][col] + weigth);
            }
        }
    }

    for(auto i : distances) {
        for(auto j : i) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }

    // std::cout << distances[number_of_stations + 6][number_of_deputies - 1] << '\n';

    return 0;
}