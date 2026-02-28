class Solution {
public:
    int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long res = 0;
        for(int num = 1; num <= n; num++){

            //To know tthe no of digits in a number
            int digits = log2(num) + 1;
            res = ((res << digits) % M + num) % M;
        }
        return (int)res;
    }
};