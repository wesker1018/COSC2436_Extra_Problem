#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = INT_MAX / 2; // avoid overflow
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int x = 1; x <= amount; x++) {
            for (int c : coins) {
                if (x - c >= 0) {
                    dp[x] = min(dp[x], dp[x - c] + 1);
                }
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<int> coins1 = {1,2,5};
    int amount1 = 11;
    cout << "Example 1: " << sol.coinChange(coins1, amount1) << endl; // Expected 3

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Example 2: " << sol.coinChange(coins2, amount2) << endl; // Expected -1

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Example 3: " << sol.coinChange(coins3, amount3) << endl; // Expected 0

    return 0;
}
