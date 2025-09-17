#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

// ----------------- Clone Graph Solution (DFS) -----------------
class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (visited.count(node)) {
            return visited[node];
        }

        Node* clone = new Node(node->val);
        visited[node] = clone;

        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

// ----------------- Helper Functions -----------------

// Build graph from adjacency list
Node* buildGraph(const vector<vector<int>>& adjList) {
    if (adjList.empty()) return nullptr;

    vector<Node*> nodes(adjList.size() + 1, nullptr);
    for (int i = 1; i <= adjList.size(); i++) {
        nodes[i] = new Node(i);
    }
    for (int i = 1; i <= adjList.size(); i++) {
        for (int neighbor : adjList[i-1]) {
            nodes[i]->neighbors.push_back(nodes[neighbor]);
        }
    }
    return nodes[1]; // return node with val = 1
}

// Convert graph back to adjacency list
vector<vector<int>> graphToAdjList(Node* node) {
    if (!node) return {};

    unordered_map<Node*, bool> visited;
    vector<vector<int>> adjList;

    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        vector<int> neighbors;

        for (auto neighbor : curr->neighbors) {
            neighbors.push_back(neighbor->val);
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }

        if (curr->val > adjList.size()) adjList.resize(curr->val);
        adjList[curr->val - 1] = neighbors;
    }

    return adjList;
}

// ----------------- Driver Code -----------------
int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> adj1 = {{2,4},{1,3},{2,4},{1,3}};
    Node* graph1 = buildGraph(adj1);
    Node* clone1 = sol.cloneGraph(graph1);
    auto res1 = graphToAdjList(clone1);
    cout << "Example 1 Output: ";
    for (auto &row : res1) {
        cout << "[";
        for (int x : row) cout << x << " ";
        cout << "]";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> adj2 = {{}};
    Node* graph2 = buildGraph(adj2);
    Node* clone2 = sol.cloneGraph(graph2);
    auto res2 = graphToAdjList(clone2);
    cout << "Example 2 Output: ";
    for (auto &row : res2) {
        cout << "[";
        for (int x : row) cout << x << " ";
        cout << "]";
    }
    cout << endl;

    // Example 3
    vector<vector<int>> adj3 = {};
    Node* graph3 = buildGraph(adj3);
    Node* clone3 = sol.cloneGraph(graph3);
    auto res3 = graphToAdjList(clone3);
    cout << "Example 3 Output: ";
    for (auto &row : res3) {
        cout << "[";
        for (int x : row) cout << x << " ";
        cout << "]";
    }
    cout << endl;

    return 0;
}
