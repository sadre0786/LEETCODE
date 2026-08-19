class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        // Continue until low and high point to the same element
        while (low < high) {

            // Calculate middle index safely
            int mid = low + (high - low) / 2;

            // We are going uphill,
            // so a peak must exist on the right side
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }

            // We are going downhill,
            // so a peak exists at mid or on the left side
            else {
                high = mid;
            }
        }

        // low == high, so this index is a peak
        return low;
    }
};