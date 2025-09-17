
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Optimized solution using hash map (O(n))
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // key: number, value: index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // the number we need
            if (mp.find(complement) != mp.end()) {
                // if complement already exists, return indices
                return {mp[complement], i};
            }
            // store current number with its index
            mp[nums[i]] = i;
        }
        return {}; // will never reach here because the problem guarantees a solution
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    cout << "Answer: [" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
