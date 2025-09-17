#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        // bucket: index = frequency, value = list of numbers
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &p : freq) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int n : bucket[i]) {
                result.push_back(n);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {1,1,1,2,2,3};
    auto res1 = sol.topKFrequent(nums1, 2);
    cout << "Example 1: ";
    for (int n : res1) cout << n << " ";
    cout << endl; // Expected [1,2]

    vector<int> nums2 = {1};
    auto res2 = sol.topKFrequent(nums2, 1);
    cout << "Example 2: ";
    for (int n : res2) cout << n << " ";
    cout << endl; // Expected [1]

    vector<int> nums3 = {1,2,1,2,1,2,3,1,3,2};
    auto res3 = sol.topKFrequent(nums3, 2);
    cout << "Example 3: ";
    for (int n : res3) cout << n << " ";
    cout << endl; // Expected [1,2]

    return 0;
}
