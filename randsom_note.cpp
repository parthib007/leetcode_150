class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // construct a hashmap to store frequency of magazine characters
        map<char,int> mpp;
        for(char c : magazine)
            mpp[c]++;
        for(char c : ransomNote){
            if(mpp[c]==0)
                return false; // not possible
            // keep decreasing the frequency one-by-one
            mpp[c]--;
        }
        return true;
    }
};
