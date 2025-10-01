class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        // first store leftproducts of each index i
        int leftProd = 1;
        for(int i=0;i<n;i++){
            ans[i] = leftProd;
            leftProd *= nums[i];
        }
        // now store the rightproducts of each index i
        int rightProd = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] *= rightProd;
            rightProd *= nums[i];
        }
        return ans;
    }
};
