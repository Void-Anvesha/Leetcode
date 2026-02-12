class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i =0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')st.push(s[i]);
            else{
                //Empty
                if(st.empty())return false;
                
                char top = st.top();
                //No match
                if(s[i] == ')' && top != '(' ||
                   s[i] == '}' && top != '{' ||
                   s[i] == ']' && top != '[') return false;

                   //Found
                   st.pop();
            }
        }
        return st.empty();
    }
};