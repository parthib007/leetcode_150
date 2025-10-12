class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // key : code for indivitual anagram
        // val : list of string that follows it
        map<string, vector<string>> mpp;
        for(string s : strs){
            string temp = s;
            sort(temp.begin(),temp.end()); // this sorted is unique for each anagram
            mpp[temp].emplace_back(s); // this will create the list of string in-place
        }
        for(auto [key , val] : mpp){
            ans.push_back(val);
        }
        return ans;
    }
};
