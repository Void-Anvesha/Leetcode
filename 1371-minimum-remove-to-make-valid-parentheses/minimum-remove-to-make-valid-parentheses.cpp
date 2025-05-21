class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; //To store the indices of unmatched '('
        unordered_set<int> remove; //Stores the indices of paranthesis that has to be removed

        for(int i=0; i<s.size();i++)
        {
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty())
                {
                    st.pop();
                }
                else{
                    remove.insert(i);
                }

            }

        }

        //Handling unmatched leftover '(' 
        while(!st.empty())
        {
            remove.insert(st.top());
            st.pop();
        }

        //Now the fiinal string
        string result="";
        for(int i=0;i<s.size();i++)
        {
            if(remove.find(i)==remove.end())
            {
                result+=s[i];
            }
        }
        return result;
    }
};