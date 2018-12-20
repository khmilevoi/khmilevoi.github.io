#include <iostream>
#include <limits>
#include <vector>

void depth_firts_search(size_t vertex, std::vector<size_t> &list, std::vector<bool> &visited, std::vector<std::vector<std::vector<size_t>>> graph) {

    visited[vertex] = true;

    for(size_t i = 0; i < graph[vertex].size(); ++i) {
        size_t child = graph[vertex][i][0];
        if(visited[child] == false) {
            depth_firts_search(child, list, visited, graph);
        }
    }

    list.push_back(vertex);
}

std::vector<size_t> topological_sort(std::vector<std::vector<std::vector<size_t>>> graph) {

    std::vector<size_t> list;
    std::vector<bool> visited(graph.size());

    for(size_t i = 0; i < graph.size(); ++i) {
        if(visited[i] == false) {
            depth_firts_search(i, list, visited, graph);
        }
    }

    std::reverse(list.begin(), list.end());
    return list;
}

size_t min_distance(size_t start, size_t end, std::vector<std::vector<std::vector<size_t>>> graph) {

    std::vector<size_t> distances(graph.size(), std::numeric_limits<size_t>::max() / 2);
    distances[start] = 0;

    std::vector<size_t> topologicaly_sorted = topological_sort(graph);

    auto min = [](size_t a, size_t b) -> size_t { return a < b ? a : b; };

    for(size_t i = 0; i < graph.size(); ++i) {
        size_t vertex_1 = topologicaly_sorted[i];
        for(size_t j = 0; j < graph[vertex_1].size(); ++j) {
            size_t vertex_2 = graph[vertex_1][j][0];
            size_t weigth = graph[vertex_1][j][1];
            distances[vertex_2] = min(distances[vertex_2], distances[vertex_1] + weigth);
        }
    }

    return distances[end];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const size_t NUMBER_OF_VERTEX = 8;
    std::vector<std::vector<std::vector<size_t>>> graph = {
        
    };

    for(size_t i = 0; i < NUMBER_OF_VERTEX; ++i) {
        std::cout << "Answer: " << min_distance(0, i, graph) << ";\n";    
    }

    return 0;
}