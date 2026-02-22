class Solution {
public:
    int binaryGap(int n) {
        int curr = 0;
        int prev = -1;
        int res = 0;

        while(n > 0){
        //If the rightmost bit is 1
            if((n & 1) == 1){
                //If (prev = -1) don't update
                //Because this is the 1st time we have seen 1
                res = (prev != -1) ? max(res , curr - prev) : res;
                prev = curr;
            }
            curr++;
            n >>= 1;
        }
        return res;
    }
};