class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=0,n2=0;
        int i=num1.size()-1;
        int j=num2.size()-1;
        string res="";
        int carry=0;

//Even if i&j becomes 0 then too the resultant will have the carry
       while(i>=0 || j>=0 || carry){
         n1=(i>=0)?num1[i--]-'0':0;
         n2=(j>=0)?num2[j--]-'0':0;
         int sum=n1+n2+carry;
         res+=(sum%10)+'0';
         carry=sum/10;
    }
      reverse(res.begin(),res.end());
       return res;

    }
};