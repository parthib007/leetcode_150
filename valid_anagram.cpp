class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return 0;
        // create a hashmap to store the frequency of characters
        map<char,int> mpp;
        for(char c : s)
            mpp[c]++;
        for(char c : t){
            mpp[c]--;
            // if value goes below 0 then not possible
            if(mpp[c] < 0)  return 0;
        }
        return 1;
    }
};
