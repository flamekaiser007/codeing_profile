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

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        // Build BST using the entire array
        return build(nums, 0, nums.size() - 1);
    }

private:

    // Builds BST from nums[left...right]
    TreeNode* build(vector<int>& nums, int left, int right) {

        // No elements left
        if (left > right)
            return nullptr;

        // Choose middle element as root
        int mid = left + (right - left) / 2;

        // Create root node
        TreeNode* root = new TreeNode(nums[mid]);

        // Build left subtree
        root->left = build(nums, left, mid - 1);

        // Build right subtree
        root->right = build(nums, mid + 1, right);

        // Return root
        return root;
    }
};