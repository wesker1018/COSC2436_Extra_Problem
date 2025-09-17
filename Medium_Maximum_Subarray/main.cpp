#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // extend the current subarray or start new from nums[i]
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Output 1: " << sol.maxSubArray(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1};
    cout << "Output 2: " << sol.maxSubArray(nums2) << endl;

    // Example 3
    vector<int> nums3 = {5,4,-1,7,8};
    cout << "Output 3: " << sol.maxSubArray(nums3) << endl;

    return 0;
}
