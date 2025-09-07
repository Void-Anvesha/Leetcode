class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //<char,idx>
        map<char,int>mp;
        int l=0,r=0;
        int n=s.length();
        int maxLen=0;
        for(int r=0;r<n;r++)
        {
            char c=s[r];
           //If char is seen & is inside curr window
            if(mp.find(c)!=mp.end() && mp[c]>=l)
            {
                l=mp[c]+1;
            }
            mp[c]=r;
            maxLen=max(maxLen,r-l+1);
        }
       
        return maxLen;
        
    }
};