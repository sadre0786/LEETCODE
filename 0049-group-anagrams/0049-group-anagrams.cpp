class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Map sorted word -> list of all its anagrams
        unordered_map<string, vector<string>> mp;

        // Store the final grouped anagrams
        vector<vector<string>> ans;

        // Traverse every word in the input
        for (const string &str : strs) {

            // Create a copy of the current word
            string key = str;

            // Sort the characters to generate a common key
            // All anagrams will produce the same sorted string
            sort(key.begin(), key.end());

            // Group the original word using its sorted representation
            mp[key].push_back(str);
        }

        // Collect all anagram groups from the hash map
        for (const auto &x : mp) {
            ans.push_back(x.second);
        }

        // Return all grouped anagrams
        return ans;
    }
};