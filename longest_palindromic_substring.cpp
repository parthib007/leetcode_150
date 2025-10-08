class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j] = whether substring i..j is palindrome or not
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        int ans = 1, start = 0;
        // all 1 characters are palindrome in itself
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        // length 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
                    start = i;
                    ans = 2;
            }
        }
        // rest of the lengths : len is for the length and i is for the starting index
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    if(len > ans){
                        start = i;
                        ans = len;
                    }
                }
            }
        }
        return s.substr(start,ans);
    }
};
