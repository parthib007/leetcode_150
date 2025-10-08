class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1); // each indivitual is itself longest 
        int ans = 1;
        // for each i, we check whether it is increasing from the back, till i
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], 1+dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;

    }
};
