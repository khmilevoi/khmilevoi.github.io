#include <fstream>
#include <iostream>
#include <vector>

using std::vector;

void path_counting(
    const long long int vertex, 
    vector<vector<vector<long long int>>> &visited, 
    vector<long long int> &weights,
    long long int current_weight,
    const long long int max_weight,
    const vector<vector<vector<long long int>>> &graph
) {

    if(current_weight > max_weight) {
        return;
    }

    if(vertex == 0) {

        weights.push_back(current_weight);
        return;
    } 

    long long int child = 0;

    for(long long int index = 0; index < graph[vertex].size(); ++index) {
        
        child = graph[vertex][index][0];    

        if(visited[vertex][child][0] == false || visited[vertex][child][1] == false) {

            if(visited[vertex][child][0] == false) {
                visited[vertex][child][0] = true;
            } else {
                visited[vertex][child][1] = true;
            }
            path_counting(child, visited, weights, current_weight + graph[vertex][index][1], max_weight, graph);
        }        
    }

    for(long long int row = 0; row < vertex + 1; ++row) {
        for(long long int col = 0; col < vertex + 1; ++col) {
            visited[row][col][0] = 0;
            visited[row ][col][1] = 0;
        }
    }

}

vector<long long int> amount_of_paths(const long long int max_weight, const vector<vector<vector<long long int>>> &graph) {

    vector<long long int> weights;
    vector<vector<vector<long long int>>> visited(graph.size(), vector<vector<long long int>>(graph.size(), vector<long long int>(2)));

    path_counting(graph.size() - 1, visited, weights, 0, max_weight, graph);

    return weights;
}

int main() {

    std::ifstream in("input.txt");

    long long int amount_of_things = 0;

    in >> amount_of_things;

    vector<long long int> weight_of_things;

    for (long long int thing = 0; thing < amount_of_things; ++thing) {
        long long int cash = 0;
        in >> cash;
        weight_of_things.push_back(cash);
    }

    long long int max_weight = 0;

    in >> max_weight;

    in.close();

    vector<vector<vector<long long int>>> graph(amount_of_things + 1);

    for (long long int vertex = 1; vertex < amount_of_things + 1; ++vertex) {
        graph[vertex] = {{vertex - 1, weight_of_things[vertex - 1]}, {vertex - 1, 0}};
    }

    vector<long long int> answer = amount_of_paths(max_weight, graph);

    std::cout << answer.size();

    return 0;
}
