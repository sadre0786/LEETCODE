class Solution {
public:
    int mySqrt(int x) {

        // Initialize search boundaries
        int low = 0;
        int high = x;

        // Store the largest valid square root
        int ans = 0;

        // Continue while the search space is valid
        while (low <= high) {

            // Calculate the middle value safely
            int mid = low + (high - low) / 2;

            // Check if mid² is less than or equal to x
            if (1LL * mid * mid <= x) {

                // mid is a valid answer
                ans = mid;

                // Try to find a larger valid value
                low = mid + 1;
            }

            // mid² is greater than x,
            // so we need a smaller value
            else {
                high = mid - 1;
            }
        }

        // Return the largest valid value
        return ans;
    }
};