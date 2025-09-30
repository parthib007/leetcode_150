class Solution {
public:
    int f(char c, vector<pair<int,char>>& valueSymbol){
        for(auto p : valueSymbol){
            if(p.second == c)   return p.first;
        }
        return 0;
    }
    int romanToInt(string s) {
        vector<pair<int,char>> valueSymbol = {
            {1,'I'}, {5,'V'}, {10,'X'}, {50,'L'},
            {100,'C'}, {500, 'D'}, {1000,'M'}
        };
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int currVal = f(s[i],valueSymbol);
            int sign = (i+1<s.length() && currVal<f(s[i+1],valueSymbol)) ? -1:1;
            ans += (sign*currVal);
        }
        return ans;
    }
};
