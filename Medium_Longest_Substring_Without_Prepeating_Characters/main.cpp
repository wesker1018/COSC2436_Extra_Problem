#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex; // store last index of each char
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // If character was seen before and is inside the current window
            if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= left) {
                left = lastIndex[c] + 1; // move left pointer
            }

            lastIndex[c] = right; // update last index of current char
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "abcabcbb";
    cout << "Output 1: " << sol.lengthOfLongestSubstring(s1) << endl;

    // Example 2
    string s2 = "bbbbb";
    cout << "Output 2: " << sol.lengthOfLongestSubstring(s2) << endl;

    // Example 3
    string s3 = "pwwkew";
    cout << "Output 3: " << sol.lengthOfLongestSubstring(s3) << endl;

    return 0;
}
