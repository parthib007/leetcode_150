class Solution {
public:
    string minWindow(string s, string t) {
        // create two hash map of s & t
        map<char, int> hashT, hashS;
        for(char c : t)
            hashT[c]++;
        int len = hashT.size();
        int l=0, r=0, ans = INT_MAX, start=0, cnt=0;
        while(r<s.length()){
            hashS[s[r]]++;
            // keep increasing the cnt till we get dissimilar char
            if(hashT.count(s[r]) && hashT[s[r]]==hashS[s[r]])   cnt++;
            // contract window
            while(cnt == len){
                if(ans > r-l+1){
                    ans = min(ans, r-l+1);
                    start = l;
                }
                hashS[s[l]]--;
                if(hashT.count(s[l]) && hashT[s[l]] > hashS[s[l]])    cnt--;
                l++;
            }
            r++;
        }
        return ans==INT_MAX ? "" : s.substr(start, ans);
    }
};
