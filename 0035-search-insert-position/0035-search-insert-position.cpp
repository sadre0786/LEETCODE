class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Initialize the search boundaries
        int low = 0;
        int high = nums.size() - 1;

        // Continue searching while the search space is valid
        while (low <= high) {

            // Calculate the middle index safely to avoid integer overflow
            int mid = low + (high - low) / 2;

            // Target found, return its index
            if (nums[mid] == target) {
                return mid;
            }

            // Target lies in the right half
            else if (nums[mid] < target) {
                low = mid + 1;
            }

            // Target lies in the left half
            else {
                high = mid - 1;
            }
        }

        // Target not found, 'low' represents the correct insertion position
        return low;
    }
};