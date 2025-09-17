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
private:
    int diameter;
    
    int depth(TreeNode* node) {
        if (!node) return 0;
        int left = depth(node->left);
        int right = depth(node->right);
        diameter = max(diameter, left + right);  // update max diameter
        return max(left, right) + 1;             // return height
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        depth(root);
        return diameter;
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

    // Example 1: [1,2,3,4,5]
    vector<string> nodes1 = {"1","2","3","4","5"};
    TreeNode* root1 = buildTree(nodes1);
    cout << "Output 1: " << sol.diameterOfBinaryTree(root1) << endl; // Expected 3

    // Example 2: [1,2]
    vector<string> nodes2 = {"1","2"};
    TreeNode* root2 = buildTree(nodes2);
    cout << "Output 2: " << sol.diameterOfBinaryTree(root2) << endl; // Expected 1

    return 0;
}
