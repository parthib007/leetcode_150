class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        // push words into stack
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                word += s[i];
            } else if(!word.empty()){
                // end of word, encountered a space
                st.push(word);
                word = "";
            }
        }
        // take the last word
        if(!word.empty()){
            st.push(word);
        }
        // pop the stack
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty())
                ans += " ";
        }
        return ans;
    }
};
