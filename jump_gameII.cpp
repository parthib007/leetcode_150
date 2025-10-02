class Solution {
public:
    int jump(vector<int>& nums) {
        // let dp[i] = min jumps to reach position i
        int n = nums.size();
        if(n<=1)    return 0;
        vector<int> dp(n , INT_MAX);
        dp[0] = 0; // 0 steps to reach base index
        for(int i=0;i<n-1;i++){
            if(dp[i]==INT_MAX)  continue; // if unreachable then skip it
            int maxJump = min(i+nums[i] , n-1); 
            // from current position we can jump from i+1 to i+nums[i] -> so try all possibilities (loop)
            for(int j=i+1;j<=maxJump;j++){
                dp[j] = min(dp[j], 1+dp[i]);
            }
        }
        return dp[n-1];
    }
};
