#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c : t) {
            count[c - 'a']--;
        }
        for (int x : count) {
            if (x != 0) return false;
        }
        return true;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "anagram", t1 = "nagaram";
    cout << "Example 1: " 
         << (sol.isAnagram(s1, t1) ? "true" : "false") << endl; // Expected true

    string s2 = "rat", t2 = "car";
    cout << "Example 2: " 
         << (sol.isAnagram(s2, t2) ? "true" : "false") << endl; // Expected false

    return 0;
}
