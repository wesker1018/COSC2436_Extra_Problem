#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
        
        int cost = 0;
        while (minHeap.size() > 1) {
            int first = minHeap.top(); minHeap.pop();
            int second = minHeap.top(); minHeap.pop();
            int newStick = first + second;
            cost += newStick;
            minHeap.push(newStick);
        }
        return cost;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> ropes1 = {2,4,3};
    cout << "Example 1: " << sol.connectSticks(ropes1) << endl; // Expected 14

    vector<int> ropes2 = {1,8,3,5};
    cout << "Example 2: " << sol.connectSticks(ropes2) << endl; // Expected 30

    vector<int> ropes3 = {5};
    cout << "Example 3: " << sol.connectSticks(ropes3) << endl; // Expected 0 (only one rope)

    return 0;
}
