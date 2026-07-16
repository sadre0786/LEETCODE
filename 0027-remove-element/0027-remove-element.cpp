class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;      // 'i' points to the position where the next non-'val' element should go
        int j = 0;      // 'j' scans through the array looking for elements != val
        int temp;

        while (j < nums.size()) {
            if (nums[i] == val && nums[j] != val) {
                // nums[i] holds an unwanted value, and nums[j] holds a valid value
                // swap them so the valid value moves into position i
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j++;
            } else if (nums[i] != val) {
                // nums[i] is already a valid value, so both pointers move forward together
                i++;
                j++;
            } else if (nums[i] == val && nums[j] == val) {
                // both are unwanted values, only move j forward to search for a valid one
                j++;
            }
        }

        // i represents the count of elements not equal to val
        return i;
    }
};