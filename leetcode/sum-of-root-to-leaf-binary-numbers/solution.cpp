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

    // val stores the decimal value of the binary number formed so far
    int sumRootToLeaf(TreeNode* root, int val = 0) {

        // Empty subtree contributes 0
        if (!root)
            return 0;

        // Append current bit to the binary number
        val = val * 2 + root->val;

        // If current node is a leaf, return the completed number
        return root->left == root->right
               ? val
               : sumRootToLeaf(root->left, val) +
                 sumRootToLeaf(root->right, val);
    }
};