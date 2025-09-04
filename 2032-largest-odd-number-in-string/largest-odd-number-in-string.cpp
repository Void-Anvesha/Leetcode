class Solution {
public:
    string largestOddNumber(string num) {
        string largest="";
        string curr="";
     
        for(char c:num)
        {
         curr+=c;
         int digit=c-'0';

         if(digit%2!=0)
         {
            if(curr.size()>largest.size() || curr.size()==largest.size() && 
                 curr>largest) largest=curr;
         }
        }
        return largest;
    }
};