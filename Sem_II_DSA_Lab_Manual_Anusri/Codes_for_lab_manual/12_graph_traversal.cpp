#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int> > adj; // Adjacency list representation of graph

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list
    }

    // Depth First Search traversal starting from a given vertex
    void DFS(int start) {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Create a stack for DFS
        stack<int> stack;

        // Push the current source node
        stack.push(start);

        while (!stack.empty()) {
            // Pop a vertex from stack and print it
            int current = stack.top();
            stack.pop();

            // Stack may contain same vertex twice. So, we need to print the popped item only if it is not visited.
            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true; // Mark the current node as visited

                // Get all adjacent vertices of the popped vertex and push the adjacent vertices to the stack if not already visited
                for (auto it = adj[current].begin(); it != adj[current].end(); ++it) {
                    if (!visited[*it]) {
                        stack.push(*it);
                    }
                }
            }
        }
    }

    // Breadth First Search traversal starting from a given vertex
    void BFS(int start) {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            int current = queue.front();
            cout << current << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex current. If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for (auto it = adj[current].begin(); it != adj[current].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }
    }
};

int main() {
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Search (DFS) starting from vertex 2: ";
    g.DFS(2);
    cout << endl;

    cout << "Breadth First Search (BFS) starting from vertex 2: ";
    g.BFS(2);
    cout << endl;

    return 0;
}
