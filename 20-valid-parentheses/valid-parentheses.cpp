class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            st.push(str[i]);  }
            else{ //For closing
                if(st.empty()) return false; //stack is empty & you're trying to match
                if((st.top()=='(' && str[i]==')') ||
                 (st.top()=='{' && str[i]=='}') ||
                  (st.top()=='[' && str[i]==']'))
                {
                    st.pop();
                }
                else{ //No match
                    return false;
                }}
        }
        //If the stack is empty then all the brackets are matched
        return st.empty();
    }
};