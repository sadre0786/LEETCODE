class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Store mapping from characters of s to characters of t
        unordered_map<char, char> mp1;

        // Store reverse mapping from characters of t to characters of s
        // This prevents multiple characters from mapping to the same character
        unordered_map<char, char> mp2;

        // Traverse both strings simultaneously
        for (int i = 0; i < s.size(); i++) {

            // If the current character of s is already mapped,
            // it must map to the current character of t
            if (mp1.find(s[i]) != mp1.end()) {
                if (mp1[s[i]] != t[i]) {
                    return false;
                }
            }

            // If the current character of t is already mapped,
            // it must map back to the current character of s
            if (mp2.find(t[i]) != mp2.end()) {
                if (mp2[t[i]] != s[i]) {
                    return false;
                }
            }

            // Create the mapping in both directions
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        // All mappings are valid
        return true;
    }
};