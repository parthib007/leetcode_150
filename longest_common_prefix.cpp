class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end()); // sort lexicographically
        string first = strs[0];
        string last = strs[n-1];
        // find common substring between the first and extreme
        string ans = "";
        for(int i=0;i<min(first.length(),last.length());i++){
            if(first[i]==last[i])
                ans += first[i];
            else break; // break at the first mismatch
        } 
        return ans;
    }
};
