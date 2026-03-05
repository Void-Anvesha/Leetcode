class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        //even Idx -> 0 && oddIdx ->1
        //010101
        int cntStartWith0 = 0;
        //evenIdx -> 1 && oddIdx -> 0
        //101010
        int cntStartWith1= 0;

        for(int i = 0; i < n; i++){
            //Expected char if char starting with '0'
            char expected0 = (i % 2 == 0) ? '0' : '1';
            if(s[i] != expected0) cntStartWith0++;

            //Expected char if char startinh with '1'
            char expected1 = (i % 2 == 0) ? '1' : '0';
            if(s[i] != expected1) cntStartWith1++;
        }
        return min(cntStartWith0 , cntStartWith1);
    }
};