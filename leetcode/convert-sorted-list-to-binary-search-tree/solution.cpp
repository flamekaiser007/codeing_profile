/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode* sortedListToBST(ListNode* head) {

        // Stores linked list values
        vector<int> nums;

        // Convert linked list into vector
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        // Build BST from vector
        return build(nums, 0, nums.size() - 1);
    }

private:

    // Builds BST from nums[left...right]
    TreeNode* build(vector<int>& nums, int left, int right) {

        // No elements left
        if (left > right)
            return nullptr;

        // Middle element becomes root
        int mid = left + (right - left) / 2;

        // Create current node
        TreeNode* root = new TreeNode(nums[mid]);

        // Build left subtree
        root->left = build(nums, left, mid - 1);

        // Build right subtree
        root->right = build(nums, mid + 1, right);

        // Return subtree root
        return root;
    }
};