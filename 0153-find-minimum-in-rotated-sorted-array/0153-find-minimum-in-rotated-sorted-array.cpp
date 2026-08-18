class Solution {
public:
    int findMin(vector<int>& nums) {

        // Initialize the search boundaries
        int low = 0;
        int high = nums.size() - 1;

        // Continue until low and high point to the same element
        while (low < high) {

            // Calculate the middle index safely
            int mid = low + (high - low) / 2;

            // If nums[mid] is greater than nums[high],
            // the minimum must be on the right side of mid
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }

            // Otherwise, the minimum is at mid or somewhere
            // on the left side
            else {
                high = mid;
            }
        }

        // When low == high, both point to the minimum element
        return nums[low];
    }
};