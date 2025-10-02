class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // peak-valley approach
        int n = prices.size(), i = 0;
        int ans = 0;
        while(i<n-1){
            // find local minima (for buying)
            while(i < n-1 && prices[i+1] <= prices[i])
                i++;
            int valley = prices[i];
            // find local maxima (for selling)
            while(i < n-1 && prices[i+1] >= prices[i])
                i++;
            int peak = prices[i];
            ans += peak-valley;
        }
        return ans;
    }
};
