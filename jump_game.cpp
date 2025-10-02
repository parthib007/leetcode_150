class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0; // current pos
        int reach = 0; // maximum reach
        while(i<nums.size() && i<=reach){
            reach = max(reach, nums[i] + i);
            i++;
        }
        return i==nums.size(); // if ends at last position
    }
};
