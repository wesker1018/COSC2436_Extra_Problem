#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        // max heap: pair<frequency, char>
        priority_queue<pair<int,char>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }
        
        string result = "";
        pair<int,char> prev = {0, '#'}; // previous char to avoid adjacency
        
        while (!pq.empty()) {
            auto [count, ch] = pq.top(); pq.pop();
            result.push_back(ch);
            
            if (prev.first > 0) pq.push(prev); // push back previous if still remains
            
            count--;
            prev = {count, ch};
        }
        
        // Check if valid
        for (int i = 1; i < result.size(); i++) {
            if (result[i] == result[i-1]) return "";
        }
        
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "aab";
    cout << "Example 1: " << sol.reorganizeString(s1) << endl; // "aba"

    string s2 = "aaab";
    cout << "Example 2: " << sol.reorganizeString(s2) << endl; // ""

    return 0;
}
