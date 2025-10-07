class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // use a set to find the word in O(1) complexity
        set<string> st(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n+1,0);
        // dp[i] = can s, upto the ith character, be segmented using wordDict
        dp[0] = 1;
        // for every i, check if before word segmentation is true and is there in the wordDict
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && st.count(s.substr(j,i-j))){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
