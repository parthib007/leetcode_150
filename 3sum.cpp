class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i] > 0) break; // not possible
            // skip duplicates for the first number
            if(i > 0 && nums[i] == nums[i-1])   continue;
            // apply two pointer for the remaining array
            int l = i+1, r = nums.size()-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    // skip duplicates of l and r
                    while(l<r && nums[l]==nums[l+1])    l++;
                    while(l<r && nums[r]==nums[r-1])    r--;
                    l++;
                    r--;
                } else if(sum<0)
                    l++; // need higher sum
                else r--;
            }
        }
        return ans;
    }
};
