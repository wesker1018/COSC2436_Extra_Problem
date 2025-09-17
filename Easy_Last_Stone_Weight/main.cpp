#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max-heap
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int y = pq.top(); pq.pop();  // largest
            int x = pq.top(); pq.pop();  // 2nd largest

            if (y != x) {
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

// Driver code for testing
int main() {
    Solution sol;

    vector<int> stones1 = {2,7,4,1,8,1};
    cout << "Output 1: " << sol.lastStoneWeight(stones1) << endl;  // Expected 1

    vector<int> stones2 = {1};
    cout << "Output 2: " << sol.lastStoneWeight(stones2) << endl;  // Expected 1

    return 0;
}
