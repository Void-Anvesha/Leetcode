class Solution {
public:
   int expandAroundCentre(string &s,int left,int right)
   {
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    //-1 because after checking they have already moved 1 step outward 
    //abacde: aba 
    //left:-1 right:3
    return right-left-1;
   }
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        int start=0;
        int maxLen=1;
        for(int i=0;i<s.size();i++)
        {
            int odd=expandAroundCentre(s,i,i);
            int even=expandAroundCentre(s,i,i+1);
            int len=max(odd,even);
            if(len>maxLen){
                maxLen=len;
                start=i-(len-1)/2;
            }
        }
        return s.substr(start,maxLen);
    }
};