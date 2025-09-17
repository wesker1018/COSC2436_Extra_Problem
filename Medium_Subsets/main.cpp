#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // add current subset
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back(); // backtrack
        }
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3};
    auto res1 = sol.subsets(nums1);
    cout << "Example 1:" << endl;
    for (auto &subset : res1) {
        cout << "[";
        for (int x : subset) cout << x << " ";
        cout << "]" << endl;
    }

    vector<int> nums2 = {0};
    auto res2 = sol.subsets(nums2);
    cout << "Example 2:" << endl;
    for (auto &subset : res2) {
        cout << "[";
        for (int x : subset) cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}
