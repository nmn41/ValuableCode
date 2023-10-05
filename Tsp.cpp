#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int tsp(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> cities;
    for (int i = 0; i < n; ++i) {
        if (i != start) {
            cities.push_back(i);
        }
    }

    int min_cost = INF;
    do {
        int current_cost = 0;
        int current_city = start;
        for (int i = 0; i < n - 1; ++i) {
            int next_city = cities[i];
            current_cost += graph[current_city][next_city];
            current_city = next_city;
        }
        current_cost += graph[current_city][start];

        min_cost = min(min_cost, current_cost);

    } while (next_permutation(cities.begin(), cities.end()));

    return min_cost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int start_city;
    cout << "Enter the starting city (0 to " << n - 1 << "): ";
    cin >> start_city;

    int min_cost = tsp(graph, start_city);

    cout << "Minimum cost for TSP starting from city " << start_city << ": " << min_cost << endl;

    return 0;
}
