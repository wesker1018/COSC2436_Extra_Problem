#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int prev2 = nums[0];                  // dp[i-2]
        int prev1 = max(nums[0], nums[1]);    // dp[i-1]
        int curr = prev1;

        for (int i = 2; i < n; i++) {
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,1};
    cout << "Example 1: " << sol.rob(nums1) << endl; // Expected 4

    vector<int> nums2 = {2,7,9,3,1};
    cout << "Example 2: " << sol.rob(nums2) << endl; // Expected 12

    return 0;
}
