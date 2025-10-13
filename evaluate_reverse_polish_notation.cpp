class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // stack to store intermediate ans
        stack<int> st;
        for(string tok : tokens){
            // check if it's a number and push it to stack
            // it can be multi-digit or first digit is a number
            if(tok.length()>1 || isdigit(tok[0])){
                st.push(stoi(tok));
            } else {
                // applying the operands and pushing it to stack
                // left and right position matters for subtraction and division
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                if(tok[0]=='+')
                    st.push(left+right);
                else if(tok[0]=='-')
                    st.push(left-right);
                else if(tok[0]=='*')
                    st.push(left*right);
                else    st.push(left/right);
            }
        }
        return st.top();
    }
};
