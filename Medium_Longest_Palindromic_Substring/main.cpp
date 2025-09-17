#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expandAroundCenter(s, i, i, start, maxLen);
            // Even length palindrome
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    string s1 = "babad";
    cout << "Example 1: " << sol.longestPalindrome(s1) << endl; // "bab" or "aba"

    string s2 = "cbbd";
    cout << "Example 2: " << sol.longestPalindrome(s2) << endl; // "bb"

    return 0;
}
