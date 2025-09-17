#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());  // ensure lexicographic order
        unordered_set<string> built;
        string result = "";

        for (string &w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                built.insert(w);
                if (w.size() > result.size() || (w.size() == result.size() && w < result)) {
                    result = w;
                }
            }
        }
        return result;
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<string> words1 = {"w","wo","wor","worl","world"};
    cout << "Example 1: " << sol.longestWord(words1) << endl; // Expected "world"

    vector<string> words2 = {"a","banana","app","appl","ap","apply","apple"};
    cout << "Example 2: " << sol.longestWord(words2) << endl; // Expected "apple"

    return 0;
}
