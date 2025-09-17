#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // use sorted string as key
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &p : mp) {
            result.push_back(p.second);
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<string> strs1 = {"eat","tea","tan","ate","nat","bat"};
    auto res1 = sol.groupAnagrams(strs1);
    cout << "Example 1: ";
    for (auto &group : res1) {
        cout << "[";
        for (auto &w : group) cout << w << " ";
        cout << "]";
    }
    cout << endl;

    vector<string> strs2 = {""};
    auto res2 = sol.groupAnagrams(strs2);
    cout << "Example 2: ";
    for (auto &group : res2) {
        cout << "[";
        for (auto &w : group) cout << w << " ";
        cout << "]";
    }
    cout << endl;

    vector<string> strs3 = {"a"};
    auto res3 = sol.groupAnagrams(strs3);
    cout << "Example 3: ";
    for (auto &group : res3) {
        cout << "[";
        for (auto &w : group) cout << w << " ";
        cout << "]";
    }
    cout << endl;

    return 0;
}
