#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();

                // place value depending on direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight;  // flip direction
        }
        return result;
    }
};

// Helper: build tree from level-order array
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front(); q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Driver code
int main() {
    Solution sol;

    // Example 1
    vector<string> nodes1 = {"3","9","20","null","null","15","7"};
    TreeNode* root1 = buildTree(nodes1);
    auto res1 = sol.zigzagLevelOrder(root1);
    cout << "Output 1: ";
    for (auto &level : res1) {
        cout << "[";
        for (int x : level) cout << x << " ";
        cout << "]";
    }
    cout << endl;

    // Example 2
    vector<string> nodes2 = {"1"};
    TreeNode* root2 = buildTree(nodes2);
    auto res2 = sol.zigzagLevelOrder(root2);
    cout << "Output 2: ";
    for (auto &level : res2) {
        cout << "[";
        for (int x : level) cout << x << " ";
        cout << "]";
    }
    cout << endl;

    // Example 3
    vector<string> nodes3 = {};
    TreeNode* root3 = buildTree(nodes3);
    auto res3 = sol.zigzagLevelOrder(root3);
    cout << "Output 3: ";
    for (auto &level : res3) {
        cout << "[";
        for (int x : level) cout << x << " ";
        cout << "]";
    }
    cout << endl;

    return 0;
}
