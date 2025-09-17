#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;  // empty tree
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
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

    // Example 1: [3,9,20,null,null,15,7]
    vector<string> nodes1 = {"3","9","20","null","null","15","7"};
    TreeNode* root1 = buildTree(nodes1);
    cout << "Output 1: " << sol.maxDepth(root1) << endl;  // Expected 3

    // Example 2: [1,null,2]
    vector<string> nodes2 = {"1","null","2"};
    TreeNode* root2 = buildTree(nodes2);
    cout << "Output 2: " << sol.maxDepth(root2) << endl;  // Expected 2

    return 0;
}
