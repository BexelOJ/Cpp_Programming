#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

struct Vertex {
    int id;
    int weight;  // Weight of the vertex
    vector<Edge> edges;  // List of edges from this vertex
};

int main() {
    // Create a graph with 4 vertices, and some edges between them.
    vector<Vertex> graph(4);
    
    // Set the vertex weights
    graph[0].weight = 10;
    graph[1].weight = 5;
    graph[2].weight = 3;
    graph[3].weight = 7;

    // Add edges (destination, weight)
    graph[0].edges.push_back({1, 2});
    graph[0].edges.push_back({2, 1});
    graph[1].edges.push_back({3, 3});
    graph[2].edges.push_back({3, 1});

    // Print the vertex weights
    for (int i = 0; i < graph.size(); i++) {
        cout << "Vertex " << i << " has weight: " << graph[i].weight << endl;
    }

    // Example of using vertex weights in an algorithm
    // Let's assume you want to add vertex weights to a modified Dijkstra or MST algorithm
}

