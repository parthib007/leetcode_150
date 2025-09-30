class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ind = 0; //pointer to track position of valid elements
        for(int num : nums){
            if(num!=val){
                nums[ind++] = num; //place the element at the index and increment the pointer
            }
        }
        return ind;
    }
};
