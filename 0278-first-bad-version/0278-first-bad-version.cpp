// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        // Initialize the search boundaries
        // Versions are numbered from 1 to n
        int low = 1;
        int high = n;

        // Store the first bad version found so far
        int ans = -1;

        // Continue searching while the search space is valid
        while (low <= high) {

            // Calculate the middle version safely
            int mid = low + (high - low) / 2;

            // If the current version is bad
            if (isBadVersion(mid)) {

                // Store it as a possible answer
                ans = mid;

                // Continue searching on the left
                // to find an earlier bad version
                high = mid - 1;
            }

            // Current version is good,
            // so the first bad version must be on the right
            else {
                low = mid + 1;
            }
        }

        // Return the first bad version
        return ans;
    }
};