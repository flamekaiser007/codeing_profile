class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;
        // explanation: binary search range starts from index 0 to last valid index

        while (low <= high) {
            // explanation: search continues while range is valid

            int mid = (low + high) / 2;
            // explanation: compute middle index of current range

            if (nums[mid] == target)
                return mid;
            // explanation: target found → return its index

            else if (target < nums[mid])
                high = mid - 1;
            // explanation: target lies in left half → move high pointer left

            else
                low = mid + 1;
            // explanation: target lies in right half → move low pointer right
        }

        return low;
        // explanation: target not found → low is the correct insertion position
    }
};