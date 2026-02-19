class Solution {
public:
    int countBinarySubstrings(string s) {
       int res = 0;

       int prevCnt = 0;
       int currCnt = 1;

       for(int i = 1; i < s.length(); i++ ){
        
           if(s[i] == s[i-1]){
            currCnt++;
           }
           else{
            res += min(currCnt , prevCnt);
            prevCnt = currCnt;
            currCnt = 1;
           }
       } 
       return res + min(prevCnt , currCnt);
    }
};