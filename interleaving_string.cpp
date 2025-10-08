class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // dp[i][j] = whether s3[0..i+j-1] is made from s1[0..i-1] and s2[0..j-1]
        int m = s1.length(), n = s2.length();
        if(s3.length()!=m+n)    return false;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
        dp[0][0] = 1;
        // for the first row, word made only from s2
        for(int j=1;j<=n;j++){
            dp[0][j] = s3[j-1]==s2[j-1] && dp[0][j-1];
        }
        // similarly for first col, word made only from s1
        for(int i=1;i<=m;i++){
            dp[i][0] = s3[i-1]==s1[i-1] && dp[i-1][0];
        }
        // fill the rest of the table
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]  = (s1[i-1]==s3[i+j-1] && dp[i-1][j]) || (s2[j-1]==s3[i+j-1] && dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
