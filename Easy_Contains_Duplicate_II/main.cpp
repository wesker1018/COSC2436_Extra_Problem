#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.count(nums[i])) {
                if (i - lastIndex[nums[i]] <= k) {
                    return true;
                }
            }
            lastIndex[nums[i]] = i;  // update last index
        }
        return false;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,1};
    cout << "Example 1: " << (sol.containsNearbyDuplicate(nums1, 3) ? "true" : "false") << endl; // true

    vector<int> nums2 = {1,0,1,1};
    cout << "Example 2: " << (sol.containsNearbyDuplicate(nums2, 1) ? "true" : "false") << endl; // true

    vector<int> nums3 = {1,2,3,1,2,3};
    cout << "Example 3: " << (sol.containsNearbyDuplicate(nums3, 2) ? "true" : "false") << endl; // false

    return 0;
}
