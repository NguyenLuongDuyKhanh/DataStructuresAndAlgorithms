#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Graph represented as an adjacency list
class Graph {
    unordered_map<int, vector<int>> adj;

public:
    // Add edge (for undirected graph)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Omit this for directed graph
    }

    // DFS helper to find path
    bool dfs(int current, int destination, unordered_set<int>& visited, vector<int>& path) {
        visited.insert(current);
        path.push_back(current);

        if (current == destination)
            return true;

        for (int neighbor : adj[current]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, destination, visited, path))
                    return true;
            }
        }

        path.pop_back(); // Backtrack
        return false;
    }

    // Main function to find path
    vector<int> findPath(int source, int destination) {
        unordered_set<int> visited;
        vector<int> path;

        if (dfs(source, destination, visited, path))
            return path;
        else
            return {}; // Empty vector indicates no path
    }
};

// Driver code
int main() {
    Graph g;

    // Add edges
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 4);
    g.addEdge(4, 6);

    int source = 1, destination = 4;

    vector<int> path = g.findPath(source, destination);

    if (!path.empty()) {
        cout << "Path from " << source << " to " << destination << ": ";
        for (int node : path)
            cout << node << " ";
        cout << endl;
    } else {
        cout << "No path found from " << source << " to " << destination << endl;
    }

    return 0;
}