class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(auto &c:s)freq[c]++;

        bool isOdd=false;
        int ans=0;
        for(auto& [c,fr]:freq){
           if(fr%2==0)ans+=fr;
           else{
            ans+=fr-1;
            isOdd=true;
           }
        }
        if(isOdd)ans+=1;
        return ans;
    }
};