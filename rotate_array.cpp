class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n; // handle cases where k is larger than size of array
        // rotate whole array -> [1,100,3,99] = [99 3 100 1]
        // rotate first k elements -> [3 99 100 1]
        // rotate remaining elements -> [3 99 1 100]
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
