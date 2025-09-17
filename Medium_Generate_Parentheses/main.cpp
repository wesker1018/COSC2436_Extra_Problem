#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int open, int close, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back();
        }
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    int n1 = 3;
    auto res1 = sol.generateParenthesis(n1);
    cout << "Example 1: ";
    for (auto &s : res1) cout << s << " ";
    cout << endl;

    int n2 = 1;
    auto res2 = sol.generateParenthesis(n2);
    cout << "Example 2: ";
    for (auto &s : res2) cout << s << " ";
    cout << endl;

    return 0;
}
