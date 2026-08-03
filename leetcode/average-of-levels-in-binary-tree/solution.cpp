class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        // Stores the average of each level
        vector<double> result;

        // If the tree is empty, return an empty vector
        if (!root)
            return result;

        // Queue for BFS (Level Order Traversal)
        queue<TreeNode*> q;

        // Start traversal from the root
        q.push(root);

        // Continue until all levels are processed
        while (!q.empty()) {

            // Number of nodes in the current level
            int size = q.size();

            // Stores the sum of the current level
            double sum = 0;

            // Traverse all nodes of the current level
            for (int i = 0; i < size; i++) {

                // Get the front node
                TreeNode* curr = q.front();

                // Remove it from the queue
                q.pop();

                // Add its value to the level sum
                sum += curr->val;

                // Push left child for the next level
                if (curr->left)
                    q.push(curr->left);

                // Push right child for the next level
                if (curr->right)
                    q.push(curr->right);
            }

            // Calculate and store the average of this level
            result.push_back(sum / size);
        }

        // Return averages of all levels
        return result;
    }
};