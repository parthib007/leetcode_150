class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(), greater<int>());
        int n = citations.size();
        int ans = 0;
        // ith citation -> i+1 times appearing
        // [6,5,3,1,0] -> 6 citation 1 time | 5 citation 2 times | 3 citation 3 times | 1 citation 4 times
        for(int i=0;i<n;i++){
            if(citations[i]>= i+1)
                ans = i+1;
        }
        return ans;
    }
};
