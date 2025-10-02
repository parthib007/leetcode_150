class Solution {
public:
    bool isPalindrome(string s) {
        // isalnum -> returns true if the character is alphabet or numeric
        int left = 0, right = s.length() - 1;
        while(left<right){
            // skip from both left and right if not alphanumeric
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            // case-insensitive
            if(tolower(s[left])!=tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
