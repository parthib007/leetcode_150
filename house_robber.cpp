class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0]; // when at 0th house, take that money
        dp[1] = max(dp[0], nums[1]); // when at 1st house, we have option of taking either previous one or this
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]); // constraint given
        }
        return dp[n-1];
    }
};
