#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums); // found one permutation
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);        // choose
            backtrack(nums, start + 1, result); // explore
            swap(nums[start], nums[i]);        // unchoose (backtrack)
        }
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3};
    auto res1 = sol.permute(nums1);
    cout << "Example 1:" << endl;
    for (auto &perm : res1) {
        cout << "[";
        for (int x : perm) cout << x << " ";
        cout << "]" << endl;
    }

    vector<int> nums2 = {0,1};
    auto res2 = sol.permute(nums2);
    cout << "Example 2:" << endl;
    for (auto &perm : res2) {
        cout << "[";
        for (int x : perm) cout << x << " ";
        cout << "]" << endl;
    }

    vector<int> nums3 = {1};
    auto res3 = sol.permute(nums3);
    cout << "Example 3:" << endl;
    for (auto &perm : res3) {
        cout << "[";
        for (int x : perm) cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}
