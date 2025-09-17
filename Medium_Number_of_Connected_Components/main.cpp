#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    int count;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        count = n;
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto &edge : edges) {
            uf.unite(edge[0], edge[1]);
        }
        return uf.getCount();
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    int n1 = 5;
    vector<vector<int>> edges1 = {{0,1},{1,2},{3,4}};
    cout << "Example 1: " << sol.countComponents(n1, edges1) << endl; // Expected 2

    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{3,4}};
    cout << "Example 2: " << sol.countComponents(n2, edges2) << endl; // Expected 1

    return 0;
}
