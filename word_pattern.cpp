class Solution {
public:
    vector<string> split(string s, char limit){
        vector<string> ans;
        stringstream ss(s);
        string temp;
        while(getline(ss, temp, limit))
            ans.push_back(temp);
        return ans;
    }
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        // create two maps: pattern -> word & word -> pattern
        map<char,string> pat;
        map<string,char> word;
        vector<string> words = split(s, ' '); // split s into words separated by space
        if(words.size()!=n) return false; 
        for(int i=0;i<n;i++){
            char c = pattern[i];
            string str = words[i];
            // if c is not there in the map, then add it
            if(pat.find(c)==pat.end())
                pat[c] = str;
            // do the same for s
            if(word.find(str)==word.end())
                word[str] = c;
            // check if they are mapped to same values or not
            if(pat[c]!=str || word[str]!=c)
                return false;
        }
        return true;
    }
};
