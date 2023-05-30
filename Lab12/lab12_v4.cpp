#include <iostream>
#include <climits>

#define V 6 // Number of vertices

int minDistance(int distances[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int source) {
    int distances[V]; // Store the shortest distance from source to each city
    bool visited[V]; // Track visited cities

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance from source to itself is always 0
    distances[source] = 0;

    // Find the shortest path for all cities
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distances, visited);

        // Mark the selected city as visited
        visited[u] = true;

        // Update distances of the adjacent cities of the selected city
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances from the source to each city
    std::cout << "Shortest distances from source city " << source << ":\n";
    for (int i = 0; i < V; i++) {
        if (i==source){
            continue;
        }
        std::cout << "City " << i << ": " << distances[i] << "\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source = 5; // Choose the source city

    dijkstra(graph, source);

    return 0;
}