class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp; //creating map for store char and freq

        //add frequency in map 
        for(int i=0; i<s.size();i++){
            mp[s[i]]++;
        }

        // subtract freq from the map 
        for(int j=0; j<t.size();j++){
            mp[t[j]]--;
        }
        
        //traverse all map 
        for(auto x : mp){

            //checking every every element freq if zero then it is anagram and return true if not return false
            if(x.second==0){
                return true;
            }else{
                return false;
            }
        }

        return false;
    }
};