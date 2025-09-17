#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // sentinel
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<int> heights1 = {2,1,5,6,2,3};
    cout << "Example 1: " << sol.largestRectangleArea(heights1) << endl; // Expected 10

    vector<int> heights2 = {2,4};
    cout << "Example 2: " << sol.largestRectangleArea(heights2) << endl; // Expected 4

    return 0;
}
