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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // This will store the final zigzag traversal
        vector<vector<int>> result;

        // If tree is empty, return empty result
        if (root == nullptr) 
            return result;

        // Stack to store nodes of current level
        stack<TreeNode*> currLevel;

        // Stack to store nodes of next level
        stack<TreeNode*> nextLevel;

        // Direction flag: true → left to right, false → right to left
        bool leftToRight = true;

        // Push root node as first level
        currLevel.push(root);

        // Vector to store values of one level
        vector<int> level;

        // Loop until all levels are processed
        while (!currLevel.empty()) {

            // Take top node from current level stack
            TreeNode* temp = currLevel.top();

            // Remove it from stack
            currLevel.pop();

            // Check if node is valid
            if (temp != nullptr) {

                // Store node value in current level vector
                level.push_back(temp->val);

                // If traversal is left to right
                if (leftToRight) {

                    // Push left child first
                    if (temp->left)
                        nextLevel.push(temp->left);

                    // Push right child next
                    if (temp->right)
                        nextLevel.push(temp->right);
                }
                // If traversal is right to left
                else {

                    // Push right child first
                    if (temp->right)
                        nextLevel.push(temp->right);

                    // Push left child next
                    if (temp->left)
                        nextLevel.push(temp->left);
                }
            }

            // If current level stack becomes empty
            if (currLevel.empty()) {

                // Store completed level into result
                result.push_back(level);

                // Clear level vector for next level
                level.clear();

                // Change direction for next level
                leftToRight = !leftToRight;

                // Move to next level by swapping stacks
                swap(currLevel, nextLevel);
            }
        }

        // Return final zigzag traversal
        return result;
    }