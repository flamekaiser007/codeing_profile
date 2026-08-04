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

    // val stores the value that every node should have.
    // Default value -1 means "not initialized yet".
    bool isUnivalTree(TreeNode* root, int val = -1) {

        // Empty subtree is always valid
        if (!root)
            return true;

        // First call: initialize val with root's value
        if (val < 0)
            val = root->val;

        // Current node must match val,
        // and both subtrees must also be uni-valued
        return root->val == val &&
               isUnivalTree(root->left, val) &&
               isUnivalTree(root->right, val);
    }
};