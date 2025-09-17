#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; // must have exactly n-1 edges

        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        dfs(0, graph, visited);

        // check if all nodes are visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }

private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }
};

// Driver code
int main() {
    Solution sol;

    int n1 = 5;
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{1,4}};
    cout << "Example 1: " << (sol.validTree(n1, edges1) ? "true" : "false") << endl; // true

    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << "Example 2: " << (sol.validTree(n2, edges2) ? "true" : "false") << endl; // false

    return 0;
}
