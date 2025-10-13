class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0, sign = 1; // 1 -> positive -1 -> negative
        for(int i=0;i<s.length();i++){
            char c = s[i];
            // check if it's a number
            if(isdigit(c)){
                // it could be a multi-digit number
                int num = 0;
                while(isdigit(s[i]) && i<s.length()){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i--; //move back i for the outer loop
                ans += sign*num;
            }
            if(c=='+')  sign = 1;
            if(c=='-')  sign = -1;
            if(c=='('){
                // push the ans and sign ans reset them as well
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            if(c==')'){
                // take out the sign and sum and add them to previous ans
                int curr_sign = st.top();
                st.pop();
                int curr_sum = st.top();
                st.pop();
                ans = (ans*curr_sign) + curr_sum;
            }
        }
        return ans;
    }
};
