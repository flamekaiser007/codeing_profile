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
    bool isSymmetric(TreeNode* root) {

        // Empty tree is symmetric
        return root == nullptr ||

               // Compare left and right subtrees
               isSymmetricHelp(root->left, root->right);
    }

    // Checks whether two subtrees are mirror images
    bool isSymmetricHelp(TreeNode* left, TreeNode* right) {

        // If either node is null,
        // return true only if both are null
        if (left == nullptr || right == nullptr)
            return left == right;

        // Values must be equal
        if (left->val != right->val)
            return false;

        // Compare outer pair and inner pair recursively
        return isSymmetricHelp(left->left, right->right) &&
               isSymmetricHelp(left->right, right->left);
    }
};