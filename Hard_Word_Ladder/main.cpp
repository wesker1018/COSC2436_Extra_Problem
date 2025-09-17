#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();

            if (word == endWord) return length;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.count(temp)) {
                        q.push({temp, length + 1});
                        dict.erase(temp); // mark visited
                    }
                }
            }
        }
        return 0;
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    string begin1 = "hit", end1 = "cog";
    vector<string> words1 = {"hot","dot","dog","lot","log","cog"};
    cout << "Example 1: " << sol.ladderLength(begin1, end1, words1) << endl; // Expected 5

    string begin2 = "hit", end2 = "cog";
    vector<string> words2 = {"hot","dot","dog","lot","log"};
    cout << "Example 2: " << sol.ladderLength(begin2, end2, words2) << endl; // Expected 0

    return 0;
}
