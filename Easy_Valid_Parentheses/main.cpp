#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;

    cout << boolalpha; // print true/false instead of 1/0
    cout << "Example 1: " << sol.isValid("()") << endl;        // true
    cout << "Example 2: " << sol.isValid("()[]{}") << endl;    // true
    cout << "Example 3: " << sol.isValid("(]") << endl;        // false
    cout << "Example 4: " << sol.isValid("([])") << endl;      // true
    cout << "Example 5: " << sol.isValid("([)]") << endl;      // false

    return 0;
}
