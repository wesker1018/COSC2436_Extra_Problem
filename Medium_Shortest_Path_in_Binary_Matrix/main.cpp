#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<pair<int,int>> directions = {
            {1,0},{-1,0},{0,1},{0,-1},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1; // mark as visited with distance 1

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int dist = grid[x][y];

            if (x == n-1 && y == n-1) return dist;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = dist + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};

// ----------------- Driver Code -----------------
int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{0,1},{1,0}};
    cout << "Example 1: " << sol.shortestPathBinaryMatrix(grid1) << endl; // Expected 2

    vector<vector<int>> grid2 = {{0,0,0},{1,1,0},{1,1,0}};
    cout << "Example 2: " << sol.shortestPathBinaryMatrix(grid2) << endl; // Expected 4

    vector<vector<int>> grid3 = {{1,0,0},{1,1,0},{1,1,0}};
    cout << "Example 3: " << sol.shortestPathBinaryMatrix(grid3) << endl; // Expected -1

    return 0;
}
