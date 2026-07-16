class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;      // 'i' points to the last position of the unique elements block
        int j = 1;      // 'j' scans ahead to find the next unique element
        int temp;

        while (j < nums.size()) {
            // If current element (nums[j]) is different from the last unique one (nums[i]),
            // it means we found a new unique element
            if (nums[i] < nums[j]) {
                i++;              // move 'i' forward to the next slot for a unique element
                
                // swap nums[i] and nums[j] to place the unique element right after the last unique block
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;

                j++;              // move scanner forward
            } else {
                // nums[j] is a duplicate (equal to nums[i], since array is sorted), skip it
                j++;
            }
        }

        // i+1 is the count of unique elements (since i is 0-indexed)
        return i + 1;
    }
};