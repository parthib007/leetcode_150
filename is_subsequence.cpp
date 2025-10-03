class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int l = 0, r = 0; // l -> s || r -> t
        while(l<n && r<m){
            if(s[l]==t[r])
                l++; // if s matches with t, then increment it's pointer only
            r++; // keep incrementing t's pointer nevertheless
        }
        return (l == n); // at the end s pointer should reach the end
    }
};
