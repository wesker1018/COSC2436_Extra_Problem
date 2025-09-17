#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int num : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), num);
            if (it == sub.end()) {
                sub.push_back(num);
            } else {
                *it = num; // replace
            }
        }
        return sub.size();
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    cout << "Example 1: " << sol.lengthOfLIS(nums1) << endl; // Expected 4

    vector<int> nums2 = {0,1,0,3,2,3};
    cout << "Example 2: " << sol.lengthOfLIS(nums2) << endl; // Expected 4

    vector<int> nums3 = {7,7,7,7,7,7,7};
    cout << "Example 3: " << sol.lengthOfLIS(nums3) << endl; // Expected 1

    return 0;
}
