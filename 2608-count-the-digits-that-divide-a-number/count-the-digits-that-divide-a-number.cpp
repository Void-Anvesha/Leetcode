class Solution {
public:
    int countDigits(int num) {
        int temp=num;
        int cnt=0;
        while(num>0)
        {
            int mod=num%10;
            if(temp%mod==0) cnt++;
            num/=10;
        }
        return cnt;
    }
};