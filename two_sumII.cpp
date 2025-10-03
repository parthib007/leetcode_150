class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // since array is sorted we can apply binary search directly
        int l = 0, r = numbers.size()-1;
        while(l<r){
            int sum = numbers[l] + numbers[r];
            if(sum == target)
                return {l+1, r+1}; // 1-based indexing
            if(sum < target)
                l++;
            else r--;
        }
        return {-1,-1};
    }
};
