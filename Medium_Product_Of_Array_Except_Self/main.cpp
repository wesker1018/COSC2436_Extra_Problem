#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // First pass: prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;   // product of all elements before i
            prefix *= nums[i];
        }

        // Second pass: suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;  // multiply with product of all elements after i
            suffix *= nums[i];
        }

        return answer;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,2,3,4};
    vector<int> ans1 = sol.productExceptSelf(nums1);
    cout << "Output 1: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<int> nums2 = {-1,1,0,-3,3};
    vector<int> ans2 = sol.productExceptSelf(nums2);
    cout << "Output 2: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}
