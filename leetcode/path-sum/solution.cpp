class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        // If the tree is empty, no path exists.
        if (!root)
            return false;

        // If this is a leaf node, check whether the remaining target
        // equals the value of this node.
        if (!root->left && !root->right)
            return targetSum == root->val;

        // Recursively check the left subtree with the updated target.
        bool left_sum = hasPathSum(root->left, targetSum - root->val);

        // Recursively check the right subtree with the updated target.
        bool right_sum = hasPathSum(root->right, targetSum - root->val);

        // Return true if either subtree contains a valid path.
        return left_sum || right_sum;
    }
};