#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        
        // Count frequency of tasks
        for (char t : tasks) {
            freq[t]++;
            maxFreq = max(maxFreq, freq[t]);
        }
        
        // Count how many tasks have maxFreq
        int countMax = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) countMax++;
        }
        
        int partCount = maxFreq - 1;
        int partLength = n + 1;
        int minTime = partCount * partLength + countMax;
        
        return max((int)tasks.size(), minTime);
    }
};

// Driver code
int main() {
    Solution sol;

    vector<char> tasks1 = {'A','A','A','B','B','B'};
    cout << "Example 1: " << sol.leastInterval(tasks1, 2) << endl; // Expected 8

    vector<char> tasks2 = {'A','C','A','B','D','B'};
    cout << "Example 2: " << sol.leastInterval(tasks2, 1) << endl; // Expected 6

    vector<char> tasks3 = {'A','A','A','B','B','B'};
    cout << "Example 3: " << sol.leastInterval(tasks3, 3) << endl; // Expected 10

    return 0;
}
