class Solution {
public:

    // Check if Koko can finish all bananas
    // with the given eating speed
    bool canFinish(vector<int>& piles, int speed, int h) {

        // Store total hours required
        long long int hours = 0;

        // Calculate hours needed for each pile
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;
        }

        // Return true if Koko can finish within h hours
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        // Search space:
        // Minimum speed = 1
        // Maximum speed = largest pile
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        // Store the minimum valid speed
        int ans = high;

        // Binary Search on the answer
        while (low <= high) {

            // Calculate the middle speed safely
            int mid = low + (high - low) / 2;

            // If Koko can finish at this speed,
            // try finding a smaller valid speed
            if (canFinish(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            }

            // Otherwise, increase the speed
            else {
                low = mid + 1;
            }
        }

        // Return the minimum possible speed
        return ans;
    }
};