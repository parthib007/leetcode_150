class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mpp; // stores the element and index position
        for(int i=0;i<nums.size();i++){
            // check if it exists and distance is at max k
            if(mpp.count(nums[i]) && i-mpp[nums[i]]<=k)
                return 1;
            mpp[nums[i]] = i;
        }
        return 0;
    }
};
