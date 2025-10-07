class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        // only 1 way to reach ground and first floor
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
