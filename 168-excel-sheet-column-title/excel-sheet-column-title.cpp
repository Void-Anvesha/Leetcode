class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
       while(columnNumber>0)
       {
          columnNumber--;
          int mod=columnNumber%26;
          res=(char)(mod+'A')+res;
          columnNumber/=26;
       }
       return res;
    }
};