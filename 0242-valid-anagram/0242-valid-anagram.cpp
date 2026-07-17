class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, they can't be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        // Store character frequencies
        unordered_map<char, int> mp;

        // Increase frequency for characters in s
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        // Decrease frequency for characters in t
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]--;
        }

        // If any character's frequency is not 0,
        // the strings are not anagrams
        for (auto x : mp) {
            if (x.second != 0) {
                return false;
            }
        }

        // All frequencies became 0
        return true;
    }
};