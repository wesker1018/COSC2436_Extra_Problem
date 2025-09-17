#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    // Returns true if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEnd;
    }

    // Returns true if there is any word in the trie that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};

// ---------------- Driver Code ----------------
int main() {
    Trie trie;

    trie.insert("apple");
    cout << boolalpha;
    cout << "search(\"apple\"): " << trie.search("apple") << endl;   // true
    cout << "search(\"app\"): " << trie.search("app") << endl;       // false
    cout << "startsWith(\"app\"): " << trie.startsWith("app") << endl; // true
    trie.insert("app");
    cout << "search(\"app\"): " << trie.search("app") << endl;       // true

    return 0;
}
