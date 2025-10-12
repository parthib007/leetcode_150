class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map to store num and its index
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            int left = target - curr;
            // check whether it is present in the map or not
            if(mpp.find(left)!=mpp.end())
                return {mpp[left], i};
            // add curr to the map;
            mpp[curr] = i;
        }
        return {};
    }
};
