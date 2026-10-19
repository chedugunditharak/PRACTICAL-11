#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Define a large value to represent infinity (unconnected edges)
const int INF = 1e9;

// Function to execute the Floyd-Warshall Algorithm
void floydWarshall(int V, vector<vector<int>>& graph) {
    // Initialize the distance matrix with the input graph configuration
    vector<vector<int>> dist = graph;

    // Core of the algorithm: 3 nested loops
    // The outermost loop must be the intermediate vertex 'k'
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Check for negative weight cycles
    // A negative value on the diagonal indicates a negative cycle
    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            cout << "Warning: Negative weight cycle detected!\n";
            return;
        }
    }

    // Print the final shortest distance matrix
    cout << "Enrollment No:92460118181\n";
    cout << "Shortest distance matrix between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << "\n";
    
    }
}

int main() {
    // Example: A graph with 4 vertices
    int V = 4;

    /* Example Graph Weights:
       0 -> 1 (weight 3)
       0 -> 3 (weight 7)
       1 -> 0 (weight 8)
       1 -> 2 (weight 2)
       2 -> 0 (weight 5)
       2 -> 3 (weight 1)
       3 -> 0 (weight 2)
    */
    vector<vector<int>> graph = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    floydWarshall(V, graph);

    return 0;
}

