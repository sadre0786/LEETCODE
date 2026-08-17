class Solution {
public:

    // Check whether all packages can be shipped
    // within the given number of days using this capacity
    bool canShip(vector<int>& weights, int capacity, int days) {

        // Start with the first shipping day
        int daysUsed = 1;

        // Weight currently loaded on the ship
        int currentWeight = 0;

        // Process packages in their given order
        for (int weight : weights) {

            // If adding this package exceeds the capacity,
            // we need to use a new day
            if (currentWeight + weight > capacity) {

                daysUsed++;

                // Start the new day with the current package
                currentWeight = weight;
            }
            else {

                // Add the package to the current day's shipment
                currentWeight += weight;
            }
        }

        // Check whether we can finish within the allowed days
        return daysUsed <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {

        // Minimum possible capacity is the heaviest package
        int low = *max_element(weights.begin(), weights.end());

        // Maximum possible capacity is the total weight
        // which means shipping everything in one day
        int high = accumulate(weights.begin(), weights.end(), 0);

        // Store the minimum valid capacity
        int ans = high;

        // Binary Search on the answer
        while (low <= high) {

            // Calculate the middle capacity safely
            int mid = low + (high - low) / 2;

            // Check whether this capacity is sufficient
            if (canShip(weights, mid, days)) {

                // This capacity works, so store it
                ans = mid;

                // Try to find an even smaller capacity
                high = mid - 1;
            }
            else {

                // Capacity is too small,
                // so we need to increase it
                low = mid + 1;
            }
        }

        // Return the minimum capacity that works
        return ans;
    }
};