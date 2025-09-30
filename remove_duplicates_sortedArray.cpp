class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 0; //pointer to track the valid elements
        for(int num : nums){
            if(ind==0 || num!=nums[ind-1]){
                nums[ind++] = num; //keep the element only if it's the first element or not equal to previous element
            }
        }
        return ind;
    }
};
