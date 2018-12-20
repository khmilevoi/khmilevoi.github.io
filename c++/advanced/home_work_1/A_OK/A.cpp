#include <vector>
#include <fstream>
#include <limits>

std::vector<int> min_distance(const std::vector<std::vector<int>> &graph) {

    std::vector<int> distances(graph.size(), std::numeric_limits<int>::max() / 2);

    std::vector<int> incoming_vertices(graph.size());

    distances[0] = 0;
    
    for (int row = 0; row < graph.size(); ++row) {

        int vertex_first = row;

        for (int column = 0; column < graph[vertex_first].size(); ++column) {

            int vertex_second = graph[vertex_first][column];

            if (distances[vertex_second] > distances[vertex_first] + 1) {

                distances[vertex_second] = distances[vertex_first] + 1;
                incoming_vertices[vertex_second] = vertex_first;
            }
        }
    }

    std::vector<int> sequence_of_step;

    int counter = incoming_vertices.size() - 1;

    while (counter > 0) {

        sequence_of_step.push_back(counter + 1);
        counter = incoming_vertices[counter];
    }

    sequence_of_step.push_back(1);

    return sequence_of_step;
}

int main() {

    int year = 0;

    std::ifstream in("input.txt");

    in >> year;

    in.close();

    std::vector<std::vector<int>> graph(year);

    for (int vertex = 1; vertex <= year; ++vertex) {

        if (vertex < year) {
            graph[vertex - 1].push_back(vertex);
        }

        if (vertex * 2 - 1 < year) {
            graph[vertex - 1].push_back(vertex * 2 - 1);
        }

        if (vertex * 3 - 1 < year) {
            graph[vertex - 1].push_back(vertex * 3 - 1);
        }
    }

    std::vector<int> answer = min_distance(graph);

    std::ofstream out("output.txt");

    out << answer.size() - 1 << '\n';

    for (int number = answer.size() - 1; number >= 0; --number) {
        out << answer[number] << ' ';
    }

    out.close();

    return 0;
}
