#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    string word;
    TrieNode() : word("") {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        TrieNode* root = buildTrie(words);

        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

private:
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx]) node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = w; // mark end of word
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear(); // avoid duplicates
        }

        board[i][j] = '#'; // mark visited
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size()) {
                dfs(board, x, y, node, result);
            }
        }
        board[i][j] = c; // backtrack
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<vector<char>> board1 = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words1 = {"oath","pea","eat","rain"};
    auto res1 = sol.findWords(board1, words1);
    cout << "Example 1 Output: ";
    for (auto &w : res1) cout << w << " ";
    cout << endl;

    vector<vector<char>> board2 = {
        {'a','b'},
        {'c','d'}
    };
    vector<string> words2 = {"abcb"};
    auto res2 = sol.findWords(board2, words2);
    cout << "Example 2 Output: ";
    for (auto &w : res2) cout << w << " ";
    cout << endl;

    return 0;
}
