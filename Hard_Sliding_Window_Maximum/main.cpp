#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller values at the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // First valid window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<int> nums1 = {1,3,-1,-3,5,3,6,7};
    int k1 = 3;
    auto res1 = sol.maxSlidingWindow(nums1, k1);
    cout << "Example 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {1};
    int k2 = 1;
    auto res2 = sol.maxSlidingWindow(nums2, k2);
    cout << "Example 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}
