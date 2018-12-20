#include <iostream>
#include <vector>

int paths_counting(const int vertex, std::vector<int> &paths, const std::vector<std::vector<int>> &graph) {

    if(paths[vertex] != -1) {
        return paths[vertex];
    }

    int result = 0;

    for(int index = 0; index < graph[vertex].size(); ++index) {

        int child = graph[vertex][index];
        result += paths_counting(child, paths, graph);
    }

    paths[vertex] = result;

    return result;
}

int amount_of_paths(int start, int end, std::vector<std::vector<int>> graph) {

    std::vector<int> paths(graph.size(), -1);
    paths[start] = 1;

    return paths_counting(end, paths, graph);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::vector<std::vector<int>> graph = {
        {},
        {0, 0},
        {1, 1},
        {2, 2}
    };

    for (size_t i = 0; i < graph.size(); ++i)
    {
        std::cout << amount_of_paths(0, i, graph) << '\n';
    }

    return 0;
}