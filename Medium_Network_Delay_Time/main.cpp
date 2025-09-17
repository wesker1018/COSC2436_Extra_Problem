#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for (auto &t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};

// ----------------- Driver Code -----------------
int main() {
    Solution sol;

    vector<vector<int>> times1 = {{2,1,1},{2,3,1},{3,4,1}};
    cout << "Example 1: " << sol.networkDelayTime(times1, 4, 2) << endl; // Expected 2

    vector<vector<int>> times2 = {{1,2,1}};
    cout << "Example 2: " << sol.networkDelayTime(times2, 2, 1) << endl; // Expected 1

    vector<vector<int>> times3 = {{1,2,1}};
    cout << "Example 3: " << sol.networkDelayTime(times3, 2, 2) << endl; // Expected -1

    return 0;
}
