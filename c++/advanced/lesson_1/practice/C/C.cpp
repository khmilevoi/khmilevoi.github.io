#include <vector>
#include <limits>
#include <fstream>

int main() {

    int amount_of_peoples = 0;

    std::ifstream in("input.txt");

    in >> amount_of_peoples;

    std::vector<std::vector<int>> time_for_peoples(amount_of_peoples);

    for(int i = 0; i < amount_of_peoples; ++i) {
        for(int j = 0; j < 3; ++j) {
            int cash = 0;
            in >> cash;
            time_for_peoples[i].push_back(cash);
        }
    }

    in.close();

    auto min = [](int a, int b) -> int { return a < b ? a : b; };

    std::vector<int> distances(amount_of_peoples + 1, std::numeric_limits<int>::max());
    distances[0] = 0;
   
    for(int i = 0; i < amount_of_peoples + 1; ++i) {
        for(int j = 0; j < 3; ++j) {
            int vertex = i + j + 1;
            if(vertex > amount_of_peoples) {
                break;
            }
            int weight = time_for_peoples[i][j];
            distances[vertex] = min(distances[vertex], distances[i] + weight);
        }
    }

    std::ofstream out("output.txt");

    out << distances[amount_of_peoples];

    out.close();

    return 0;
}