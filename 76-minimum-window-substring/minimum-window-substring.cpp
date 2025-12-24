class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        
        if(t.length() > n)return "";
       
       unordered_map<char,int>mp;
       //storing char of 't' in map
       for(char& ch : t ){
           mp[ch]++;
       }

       int reqdCnt=t.length();
       int i=0 , j=0;
       int min_window_size=INT_MAX;
       int start_i=0;

       while(j < n){
         char ch=s[j];

         //char reqd 
         if(mp[ch]>0)reqdCnt--;

         mp[ch]--;

         while(reqdCnt==0){
           //start shrinking the window
           int currwindowSize= j - i + 1;
           if(min_window_size > currwindowSize){
              min_window_size= currwindowSize;
              start_i=i;
           }
           mp[s[i]]++;

           if(mp[s[i]] > 0)reqdCnt++;
           i++;
         }
         j++;


       }
       return min_window_size == INT_MAX ? "" : s.substr(start_i,min_window_size);
    }
};