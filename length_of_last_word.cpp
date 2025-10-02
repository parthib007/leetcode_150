class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.length() - 1; // start from the end
        while(i >=0 && s[i]==' ')
            i--; // decrease pointer until we found a non-white space character
        while(i >=0 && s[i]!=' '){
            ans++; // increase the length of the word
            i--;   // till we find a space
        }
        return ans;
    }
};
