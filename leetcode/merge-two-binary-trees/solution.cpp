/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        // If both nodes are null, return null
        if (!root1 && !root2)
            return nullptr;

        // If first tree is null, use second tree
        if (!root1)
            return root2;

        // If second tree is null, use first tree
        if (!root2)
            return root1;

        // Merge current node values
        root1->val += root2->val;

        // Recursively merge left subtrees
        root1->left = mergeTrees(root1->left, root2->left);

        // Recursively merge right subtrees
        root1->right = mergeTrees(root1->right, root2->right);

        // Return merged tree
        return root1;
    }
};