class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        // use set for O(1) lookup
        set<int> st(nums.begin(),nums.end());
        int ans = 1;
        for(int num : st){
            // check for num-1 in the set. If present then num is not the start so skip it
            if(st.find(num-1)==st.end()){
                int curr = num;
                int len = 1;
                // loop for consecutive numbers in the set
                while(st.find(curr + 1) != st.end()){
                    curr++;
                    len++;
                }
                // update the length
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
