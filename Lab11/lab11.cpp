#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

struct CompareWeight {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    }
};

std::vector<Edge> primMST(const std::vector<std::vector<int>>& adjacencyMatrix, int startNode) {
    int numNodes = adjacencyMatrix.size();
    std::vector<bool> visited(numNodes, false);
    std::vector<Edge> minimumSpanningTree;

    // Priority queue to store the edges with their weights
    std::priority_queue<Edge, std::vector<Edge>, CompareWeight> pq;

    visited[startNode] = true;

    // Add all edges from the startNode to the priority queue
    for (int j = 0; j < numNodes; ++j) {
        if (adjacencyMatrix[startNode][j] != 0) {
            pq.push(Edge(startNode, j, adjacencyMatrix[startNode][j]));
        }
    }

    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        int src = currentEdge.src;
        int dest = currentEdge.dest;
        int weight = currentEdge.weight;

        if (visited[dest])
            continue;

        visited[dest] = true;
        minimumSpanningTree.push_back(currentEdge);

        // Add all edges from the newly visited node to the priority queue
        for (int j = 0; j < numNodes; ++j) {
            if (adjacencyMatrix[dest][j] != 0 && !visited[j]) {
                pq.push(Edge(dest, j, adjacencyMatrix[dest][j]));
            }
        }
    }

    return minimumSpanningTree;
}

int main() {
    std::vector<std::vector<int>> adjacencyMatrix = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {2, 0, 5, 0, 4, 0}
    };

    int startNode = 0;

    std::vector<Edge> minimumSpanningTree = primMST(adjacencyMatrix, startNode);

    // Print the minimum spanning tree
    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : minimumSpanningTree) {
        std::cout << edge.src << " -- " << edge.dest << " (Weight: " << edge.weight << ")" << std::endl;
    }

    return 0;
}
