class Solution {
public:

    int search(vector<int>& nums, int target) {

        // Initialize the search boundaries
        int low = 0;
        int high = nums.size() - 1;

        // Continue searching while the search space is valid
        while (low <= high) {

            // Calculate the middle index safely
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {

                // Check if the target lies inside the left sorted half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }

                // Otherwise, search in the right half
                else {
                    low = mid + 1;
                }
            }

            // Otherwise, the right half must be sorted
            else {

                // Check if the target lies inside the right sorted half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }

                // Otherwise, search in the left half
                else {
                    high = mid - 1;
                }
            }
        }

        // Target does not exist in the array
        return -1;
    }
};