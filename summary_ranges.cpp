class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n==0)    return ans;
        for(int i=0;i<n; ){
            int start = i;
            // extend the window until consecutive elements
            while(i+1<n && nums[i+1]==nums[i]+1)
                i++;
            // single number
            if(start==i)
                ans.push_back(to_string(nums[start]));
            // multi element
            else ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            i++;
        }
        return ans;
    }
};
