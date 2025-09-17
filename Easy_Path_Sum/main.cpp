#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;  // empty tree
        // check leaf
        if (!root->left && !root->right) {
            return (targetSum == root->val);
        }
        // recurse left or right
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

// Helper function: build tree from level-order vector
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // left child
        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        // right child
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
    vector<string> nodes1 = {"5","4","8","11","null","13","4","7","2","null","null","null","1"};
    TreeNode* root1 = buildTree(nodes1);
    cout << "Output 1: " << (sol.hasPathSum(root1, 22) ? "true" : "false") << endl;  // Expected true

    // Example 2
    vector<string> nodes2 = {"1","2","3"};
    TreeNode* root2 = buildTree(nodes2);
    cout << "Output 2: " << (sol.hasPathSum(root2, 5) ? "true" : "false") << endl;  // Expected false

    // Example 3
    vector<string> nodes3 = {};
    TreeNode* root3 = buildTree(nodes3);
    cout << "Output 3: " << (sol.hasPathSum(root3, 0) ? "true" : "false") << endl;  // Expected false

    return 0;
}
