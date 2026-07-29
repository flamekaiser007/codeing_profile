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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // Stores the maximum path sum found so far.
        maxPathDown(root, maxi);
        return maxi;
    }

private:
    int maxPathDown(TreeNode* node, int& maxi) {
        // Base case: an empty node contributes 0 to the path sum.
        if (node == nullptr)
            return 0;

        // Compute the maximum contribution from the left subtree.
        // Ignore negative sums by taking max with 0.
        int left = max(0, maxPathDown(node->left, maxi));

        // Compute the maximum contribution from the right subtree.
        // Ignore negative sums by taking max with 0.
        int right = max(0, maxPathDown(node->right, maxi));

        // Update the global maximum path sum.
        // This path passes through the current node and may include both children.
        maxi = max(maxi, left + right + node->val);

        // Return the maximum contribution of the current node to its parent.
        // A parent can only continue through one child.
        return node->val + max(left, right);
    }
};