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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;              // both null
        if (!t1 || !t2) return false;             // one null, one not
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&   // left vs right
               isMirror(t1->right, t2->left);     // right vs left
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

    // Example 1: [1,2,2,3,4,4,3]
    vector<string> nodes1 = {"1","2","2","3","4","4","3"};
    TreeNode* root1 = buildTree(nodes1);
    cout << "Output 1: " << (sol.isSymmetric(root1) ? "true" : "false") << endl;

    // Example 2: [1,2,2,null,3,null,3]
    vector<string> nodes2 = {"1","2","2","null","3","null","3"};
    TreeNode* root2 = buildTree(nodes2);
    cout << "Output 2: " << (sol.isSymmetric(root2) ? "true" : "false") << endl;

    return 0;
}
