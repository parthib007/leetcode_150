class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e8));
        // dp[i][j] = min. no. of coins to make j with [1..i] coins
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                dp[i][j] = dp[i-1][j]; // not-take
                // take
                if(j >= coins[i-1]){
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j-coins[i-1]]);
                }
            }
        }
        return dp[n][amount]>=1e8 ? -1 : dp[n][amount];
    }
};
