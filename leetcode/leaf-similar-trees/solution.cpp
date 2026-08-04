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

    // Stores all leaf nodes in left-to-right order
    void dfs(TreeNode* root, vector<int>& leaves) {

        // Empty tree
        if (!root)
            return;

        // If current node is a leaf, store its value
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }

        // Traverse left subtree
        dfs(root->left, leaves);

        // Traverse right subtree
        dfs(root->right, leaves);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        // Stores leaf sequence of first tree
        vector<int> leaves1;

        // Stores leaf sequence of second tree
        vector<int> leaves2;

        // Collect leaves from first tree
        dfs(root1, leaves1);

        // Collect leaves from second tree
        dfs(root2, leaves2);

        // If number of leaves is different
        if (leaves1.size() != leaves2.size())
            return false;

        // Compare leaf values one by one
        for (int i = 0; i < leaves1.size(); i++) {

            // Leaf values differ
            if (leaves1[i] != leaves2[i])
                return false;
        }

        // Both leaf sequences are identical
        return true;
    }
};