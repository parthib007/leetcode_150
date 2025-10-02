class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 1; // first child gets 1 candy
        int i = 1;
        while(i<n){
            // if all have same ratings
            if(ratings[i]==ratings[i-1]){
                ans++;
                i++;
                continue;
            }
            // increasing slope (building peak)
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                ans += peak;
                i++;
            }
            // decreasing slop (building valley)
            int valley = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                ans += valley;
                valley++;
                i++;
            }
            // extra candy if valley is more than peak
            if(valley > peak)
                ans += valley-peak;
        }
        return ans;
    }
};
