#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {3,2,1,5,6,4};
    cout << "Example 1: " << sol.findKthLargest(nums1, 2) << endl; // Expected 5

    vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    cout << "Example 2: " << sol.findKthLargest(nums2, 4) << endl; // Expected 4

    return 0;
}
