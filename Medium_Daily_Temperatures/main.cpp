#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // store indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                answer[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        return answer;
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {73,74,75,71,69,72,76,73};
    vector<int> res1 = sol.dailyTemperatures(t1);
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> t2 = {30,40,50,60};
    vector<int> res2 = sol.dailyTemperatures(t2);
    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    vector<int> t3 = {30,60,90};
    vector<int> res3 = sol.dailyTemperatures(t3);
    cout << "Output 3: ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;
}
