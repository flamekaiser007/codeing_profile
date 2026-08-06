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
    int widthOfBinaryTree(TreeNode* root) {

        // Empty tree
        if (!root)
            return 0;

        // Stores maximum width
        int ans = 0;

        // Queue stores {node, index}
        queue<pair<TreeNode*, int>> q;

        // Root starts at index 0
        q.push({root, 0});

        while (!q.empty()) {

            // Number of nodes in current level
            int size = q.size();

            // Minimum index of current level (used for normalization)
            int mmin = q.front().second;

            int first, last;

            // Traverse current level
            for (int i = 0; i < size; i++) {

                // Normalize index to avoid overflow
                int cur_id = q.front().second - mmin;

                // Current node
                TreeNode* node = q.front().first;
                q.pop();

                // Store first index
                if (i == 0)
                    first = cur_id;

                // Store last index
                if (i == size - 1)
                    last = cur_id;

                // Left child gets index 2*i+1
                if (node->left)
                    q.push({node->left, cur_id * 2 + 1});

                // Right child gets index 2*i+2
                if (node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }

            // Width = last index - first index + 1
            ans = max(ans, last - first + 1);
        }

        // Return maximum width
        return ans;
    }
};