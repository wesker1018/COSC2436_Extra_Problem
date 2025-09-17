#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    unordered_map<int, int> inorderIndex;  // value -> index
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        // Pick current root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int idx = inorderIndex[rootVal];

        // Build right subtree first, then left
        root->right = build(inorder, postorder, idx + 1, right);
        root->left  = build(inorder, postorder, left, idx - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;

        // Build hashmap for inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};

// Helper: Print tree in preorder for checking
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution sol;

    // Example 1
    vector<int> inorder1 = {9,3,15,20,7};
    vector<int> postorder1 = {9,15,7,20,3};
    TreeNode* root1 = sol.buildTree(inorder1, postorder1);
    cout << "Preorder of Example 1 tree: ";
    printPreorder(root1);  // Expected: 3 9 20 15 7
    cout << endl;

    // Example 2
    vector<int> inorder2 = {-1};
    vector<int> postorder2 = {-1};
    TreeNode* root2 = sol.buildTree(inorder2, postorder2);
    cout << "Preorder of Example 2 tree: ";
    printPreorder(root2);  // Expected: -1
    cout << endl;

    return 0;
}
