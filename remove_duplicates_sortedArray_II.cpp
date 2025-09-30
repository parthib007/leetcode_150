class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 0; //pointer to track the valid elements
        for(int num : nums){
            // allow if and only if
            // 1. index is less than 2
            // 2. it is different from the previous-to-previous element
            if(ind<2 || num!=nums[ind-2])
                nums[ind++] = num;
        }
        return ind;
    }
};
