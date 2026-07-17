class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Store only unique common elements
        unordered_set<int> st;

        // Store the final answer
        vector<int> ans;

        // Compare every element of nums1 with every element of nums2
        for (int i = 0; i < nums1.size(); i++) {

            for (int j = 0; j < nums2.size(); j++) {

                // If a common element is found,
                // insert it into the set (duplicates are ignored)
                if (nums1[i] == nums2[j]) {
                    st.insert(nums1[i]);
                }
            }
        }

        // Copy all unique common elements from the set to the answer vector
        for (auto x : st) {
            ans.push_back(x);
        }

        // Return the intersection of both arrays
        return ans;
    }
};