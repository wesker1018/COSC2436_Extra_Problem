#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false; // already connected

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);

        vector<int> result;
        for (auto &edge : edges) {
            if (!uf.unite(edge[0], edge[1])) {
                result = edge; // this edge causes a cycle
            }
        }
        return result;
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{1,2},{1,3},{2,3}};
    auto res1 = sol.findRedundantConnection(edges1);
    cout << "Example 1: [" << res1[0] << "," << res1[1] << "]" << endl; // [2,3]

    vector<vector<int>> edges2 = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    auto res2 = sol.findRedundantConnection(edges2);
    cout << "Example 2: [" << res2[0] << "," << res2[1] << "]" << endl; // [1,4]

    return 0;
}
