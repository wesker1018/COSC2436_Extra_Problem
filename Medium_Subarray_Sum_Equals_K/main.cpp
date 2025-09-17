#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSumCount;
        prefixSumCount[0] = 1;  // base case: sum=0 seen once

        int prefix = 0, count = 0;
        for (int n : nums) {
            prefix += n;
            if (prefixSumCount.count(prefix - k)) {
                count += prefixSumCount[prefix - k];
            }
            prefixSumCount[prefix]++;
        }
        return count;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {1,1,1};
    cout << "Example 1: " << sol.subarraySum(nums1, 2) << endl; // Expected 2

    vector<int> nums2 = {1,2,3};
    cout << "Example 2: " << sol.subarraySum(nums2, 3) << endl; // Expected 2

    return 0;
}
