class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp1;  //creating map
        
        //store magazine freq
        for(int i=0; i<magazine.size(); i++){
            mp1[magazine[i]]++;
        }

        // traverse and decerese freq
        for(int i=0; i<ransomNote.size(); i++){

            //if element is not available return false
            if(mp1[ransomNote[i]]==0){
                return false;
            }
            mp1[ransomNote[i]]--;
        }

        //after finishing successfuly loop return true

        return true;

        

        
    }
};