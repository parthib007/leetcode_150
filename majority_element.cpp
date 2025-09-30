//boyer-moore algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(int num : nums){
            // if cnt is 0, then reset the candidate to present num and cnt to 1
            if(count==0){
                candidate = num;
                count = 1;
            } else if(num==candidate){
                count++; // increment the cnt is num is equal to present candidate
            } else count--; //decrement otherwise
        }
        return candidate;
    }
};
