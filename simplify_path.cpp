class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string temp;
        // divide the string in path by the delimiter / and store it in temp string
        while(getline(ss,temp, '/')){
            if(temp=="" || temp==".")   continue; // current directory
            if(temp==".."){
                // go back to previous dir, unless we are at root
                if(!st.empty())
                    st.pop();
            }
            else st.push(temp);
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};
