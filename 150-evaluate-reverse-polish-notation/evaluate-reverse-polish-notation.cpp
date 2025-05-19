class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens)
        {
            if(s=="+" || s=="*" || s=="-" || s=="/")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int result;

                if(s=="+") result=a+b;
                else if(s=="-") result=b-a;
                else if(s=="*") result=b*a;
                else result=b/a;

                st.push(result);
            }
            else{
                st.push(stoi(s)); //c++ function to convert string to integer
            }

        }
        return st.top();
    }
};