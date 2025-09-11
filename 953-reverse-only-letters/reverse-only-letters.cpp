class Solution {
public:
   bool isAlphabet(char c)
   {
    return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
   }
    string reverseOnlyLetters(string s) {
       int l=0;
       int r=s.length()-1;
       while(l<=r){
       if(!isAlphabet(s[l]))l++;
       else if(!isAlphabet(s[r]))r--;
       else{ 
        swap(s[l],s[r]);
        l++;
        r--;
       }
       }
       return s;
    }
};