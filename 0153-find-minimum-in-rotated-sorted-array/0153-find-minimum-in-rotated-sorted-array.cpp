class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int minValue = high;

        while(low<=high){
            int mid = low + (high - low) / 2;

            if(nums[low]<=nums[mid]){
                if(nums[low]<=nums[minValue]){
                    minValue = low;
                }
                low = mid+1;
            }else{
                high = mid;
            }
        }

        return nums[minValue];
    }
};