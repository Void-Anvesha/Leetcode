class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";

        for(int i=0;i<strs[0].size();i++)
        {
            char currChar=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                //Mismatch
                if(i==strs[j].size() || currChar!=strs[j][i])
                 return strs[0].substr(0,i);
            }
        }
        //1st string is the common prefix
        return strs[0];
    }
};