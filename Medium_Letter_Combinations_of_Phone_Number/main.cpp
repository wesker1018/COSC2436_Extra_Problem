#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",    "",    "abc",  "def",
            "ghi", "jkl", "mno",  "pqrs",
            "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        backtrack(digits, 0, current, result, mapping);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current, 
                   vector<string>& result, const vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char c : mapping[digit]) {
            current.push_back(c);
            backtrack(digits, index + 1, current, result, mapping);
            current.pop_back();
        }
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    string digits1 = "23";
    auto res1 = sol.letterCombinations(digits1);
    cout << "Example 1: ";
    for (auto &s : res1) cout << s << " ";
    cout << endl;

    string digits2 = "";
    auto res2 = sol.letterCombinations(digits2);
    cout << "Example 2: ";
    for (auto &s : res2) cout << s << " ";
    cout << endl;

    string digits3 = "2";
    auto res3 = sol.letterCombinations(digits3);
    cout << "Example 3: ";
    for (auto &s : res3) cout << s << " ";
    cout << endl;

    return 0;
}
