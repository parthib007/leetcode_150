class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // take the initial price as minimum buying price
        int minPrice = prices[0];
        int ans = INT_MIN;
        for(int price : prices){
            int currProfit = price - minPrice; // assume that you sell at current price, calculate the profit
            ans = max(ans, currProfit); // take max
            minPrice = min(minPrice, price); // update the buying price -> take min
        }
        return ans;
    }
};
