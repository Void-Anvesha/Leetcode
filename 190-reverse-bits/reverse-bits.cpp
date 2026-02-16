class Solution {
public:
    int reverseBits(int n) {
        int rev = 0;
        for(int i = 0; i <= 31; i++){
            rev <<= 1;
            //Get the LSB ( n & 1)
            rev |= (n &1);
            //Right shift to overcome the prev LSB
            n>>=1;
        }
        return rev;
    }
};