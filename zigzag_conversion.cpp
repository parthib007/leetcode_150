class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)  return s;
        vector<string> ds(numRows);
        int currRow = 0; // indicates which row we are currently on ds
        int dir = -1; // flips for top and bottom
        for(char c : s){
            ds[currRow] += c;
            if(currRow == 0 || currRow == numRows-1)
                dir = -dir;
            currRow += dir; // update the current row based on the direction
        }
        string ans = "";
        for(auto ch : ds){
            ans += ch;
        }
        return ans;
    }
};
