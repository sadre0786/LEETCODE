class Solution {
public:

    // Find the first occurrence of the target
    int firstOccurrence(vector<int> &nums, int target) {

        // Initialize the search boundaries
        int low = 0;
        int high = nums.size() - 1;

        // Store the index of the first occurrence
        int ans = -1;

        // Continue searching while the search space is valid
        while (low <= high) {

            // Calculate the middle index safely
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {

                // Store the current index as a possible answer
                ans = mid;

                // Continue searching on the left
                // to find an earlier occurrence
                high = mid - 1;
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

        // Return the first occurrence if found
        return ans;
    }

    // Find the last occurrence of the target
    int lastOccurrence(vector<int> &nums, int target) {

        // Initialize the search boundaries
        int low = 0;
        int high = nums.size() - 1;

        // Store the index of the last occurrence
        int ans = -1;

        // Continue searching while the search space is valid
        while (low <= high) {

            // Calculate the middle index safely
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {

                // Store the current index as a possible answer
                ans = mid;

                // Continue searching on the right
                // to find a later occurrence
                low = mid + 1;
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

        // Return the last occurrence if found
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        // Find the first occurrence
        int first = firstOccurrence(nums, target);

        // Find the last occurrence
        int last = lastOccurrence(nums, target);

        // Return both positions
        return {first, last};
    }
};