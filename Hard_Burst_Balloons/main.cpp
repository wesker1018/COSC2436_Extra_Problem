#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // add virtual balloons
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; i++) balloons[i + 1] = nums[i];
        n += 2;

        // dp[i][j] = max coins from (i, j)
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length of interval
        for (int len = 2; len < n; len++) {
            for (int left = 0; left + len < n; left++) {
                int right = left + len;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right],
                        balloons[left] * balloons[i] * balloons[right] 
                        + dp[left][i] + dp[i][right]);
                }
            }
        }

        return dp[0][n-1];
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<int> nums1 = {3,1,5,8};
    cout << "Example 1: " << sol.maxCoins(nums1) << endl; // Expected 167

    vector<int> nums2 = {1,5};
    cout << "Example 2: " << sol.maxCoins(nums2) << endl; // Expected 10

    return 0;
}
