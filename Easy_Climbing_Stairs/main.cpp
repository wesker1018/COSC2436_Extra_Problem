#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev1 = 1, prev2 = 2, curr = 0;
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};

// Driver code
int main() {
    Solution sol;
    cout << "Example 1: " << sol.climbStairs(2) << endl; // Expected 2
    cout << "Example 2: " << sol.climbStairs(3) << endl; // Expected 3
    cout << "Example 3: " << sol.climbStairs(5) << endl; // Expected 8
    return 0;
}
