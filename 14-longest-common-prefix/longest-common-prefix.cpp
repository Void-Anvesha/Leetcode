class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";

        //For traversing all the characters of the 1st string
        for(int i=0;i<strs[0].length();i++)
        {
            char ch=strs[0][i];
            bool match=true;

            //For comparing ch with remaining strings
            for(int j=1;j<strs.size();j++)
            {
                //Not Match
                if(strs[j].size()<i || ch!=strs[j][i]){
                    match=false;
                    break;
                }    
            }
            if(match==false)break;
            else ans.push_back(ch);


        }
        return ans;
    }
};