#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& token : tokens) {
            if (isOperator(token)) {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(applyOp(b, a, token));
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }

private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int applyOp(int b, int a, const string& op) {
        if (op == "+") return b + a;
        if (op == "-") return b - a;
        if (op == "*") return b * a;
        if (op == "/") return b / a; // integer division, truncates toward 0
        return 0; // shouldn't happen
    }
};

// Driver code
int main() {
    Solution sol;

    vector<string> tokens1 = {"2","1","+","3","*"};
    cout << "Example 1: " << sol.evalRPN(tokens1) << endl; // 9

    vector<string> tokens2 = {"4","13","5","/","+"};
    cout << "Example 2: " << sol.evalRPN(tokens2) << endl; // 6

    vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "Example 3: " << sol.evalRPN(tokens3) << endl; // 22

    return 0;
}
