class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        // we first create a hashmap of word present in words (required map)
        int len = words[0].length();
        int n = words.size();
        int totalLen = len * n;
        map<string, int> req;
        for(auto word : words)
            req[word]++;
        // we now go through s only at those locations that are multiple of len
        // if len = 3 then we check only at 0,3,6,9,... || 1,4,7,10.... || 2,5,8,11....
        for(int i=0;i<len;i++){
            // initiate window here to create the current map of string
            int l = i, r = i;
            map<string, int> curr;
            while(r + len <= s.length()){
                string word = s.substr(r,len);
                r += len; // move right pointer by full word length
                if(req.count(word)){
                    curr[word]++;
                    // contract window if exceeds
                    while(curr[word] > req[word]){
                        string leftword = s.substr(l,len);
                        curr[leftword]--;
                        l += len;
                    }
                    // check if present
                    if(r-l == totalLen)
                        ans.push_back(l);
                } else {
                    curr.clear();
                    l = r;
                }
            }
        }
        return ans;
    }
};
