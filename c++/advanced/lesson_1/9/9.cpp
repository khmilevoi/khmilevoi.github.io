#include <iostream>
#include <vector>
#include <limits>

const int INFINITE = std::numeric_limits<int>::max() / 2;

int get_min_reliable_distance(
    int start,
    int end,
    int amount_of_vertex,
    std::vector<std::vector<int>> graph
) {

    std::vector<std::vector<int>> distances(graph.size(), std::vector<int>(amount_of_vertex + 1, INFINITE));
    distances[start][0] = 0;

    auto min = [](int a, int b) -> int { return a < b ? a : b; };

    for(int vertex_1 = 0; vertex_1 < graph.size(); ++vertex_1) {
        for(int amount = 0; amount < amount_of_vertex; ++amount) {
            for(int child = 0; child < graph[vertex_1].size(); ++child) {
                int vertex_2 = graph[vertex_1][child];
                distances[vertex_2][amount + 1] = min(distances[vertex_2][amount + 1], distances[vertex_1][amount] + 1);
            }
        }
    }

    return distances[end][amount_of_vertex];
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::vector<std::vector<int>> graph = {
        {1, 2, 3},
        {3},
        {3},
        {}
    };

    int beg = 0;

    for(int i = 0; i < graph.size(); ++i) {
        for(int j = 0; j < 3; ++j) {
            std::cout << (get_min_reliable_distance(beg, i, j, graph) == INFINITE ? 0 : get_min_reliable_distance(beg, i, j, graph)) << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}