class Solution {
public:
    bool isHappy(int n) {

        // Store previously seen numbers to detect a cycle
        unordered_set<int> seen;

        // Continue until the number becomes 1
        while (n != 1) {

            // If the number is already seen,
            // we are stuck in a cycle
            if (seen.find(n) != seen.end()) {
                return false;
            }

            // Mark the current number as visited
            seen.insert(n);

            // Store the sum of the squares of the digits
            int sum = 0;

            // Calculate the sum of the squares of all digits
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }

            // Use the new sum as the next number
            n = sum;
        }

        // Reached 1, so the number is happy
        return true;
    }
};