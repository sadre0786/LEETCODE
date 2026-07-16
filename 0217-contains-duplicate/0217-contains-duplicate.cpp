class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //store the frequency of each number
        unordered_map<int,int>freq;  
        
       //traverse every element in the array
        for(int i=0; i<nums.size(); i++){
            // increase the frequency for the current number 
            freq[nums[i]]++;

           // If frequency becomes greater than 1,
            // we found a duplicate
            if(freq[nums[i]]>1){
                return true;
            }
        }
        

        // No duplicate found
        return false;
    }
};