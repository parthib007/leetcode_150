class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if(m>n) return -1; //early termination
        for(int i=0;i<=n-m;i++){
            int j = 0; // pointer for needle
            while(j<m && haystack[i+j]==needle[j])
                j++;
            // if pointer reached the end
            if(j==m)
                return i;
        }
        return -1;
    }
};
