class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;

        int i=0;
        int n=s.length();
        //Skip whitespaces
        while(i<s.length() && s[i]==' ') 
        {
            i++;
        }
         if(i==n)return 0;
        
        int sign=1;
        

        if(i<n && s[i]=='-') 
        {
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+') i++;

        int MAX=INT_MAX;
        int MIN=INT_MIN;

        long long ans=0;
        while(i<s.length())
        {
            if(s[i]==' '|| !isdigit(s[i])) break;

            ans=ans*10+s[i]-'0';
            if(sign==-1 && -ans<MIN) return MIN;
            if(sign==1 && ans>MAX) return MAX;
            i++;
        }
        return ans*sign;

    }
};