class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        while(l<r){
            int width = r - l; // 8-0 = 8
            int minHeight = min(height[l], height[r]);
            int currArea = minHeight * width;
            ans = max(ans, currArea);
            // move the pointer with lower height
            if(height[l] < height[r])
                l++;
            else r--;
        }
        return ans;
    }
};
