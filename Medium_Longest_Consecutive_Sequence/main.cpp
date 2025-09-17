#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (!s.count(num - 1)) { // start of a sequence
                int curr = num;
                int length = 1;

                while (s.count(curr + 1)) {
                    curr++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {100,4,200,1,3,2};
    cout << "Example 1: " << sol.longestConsecutive(nums1) << endl; // 4

    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    cout << "Example 2: " << sol.longestConsecutive(nums2) << endl; // 9

    vector<int> nums3 = {1,0,1,2};
    cout << "Example 3: " << sol.longestConsecutive(nums3) << endl; // 3

    return 0;
}
