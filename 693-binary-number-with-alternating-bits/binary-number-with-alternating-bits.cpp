class Solution {
public:
    bool hasAlternatingBits(int n) {
        //Ex : 5
        int currBit = n % 2; //1
        n /= 2; //2

        while(n > 0){

            if(currBit == n % 2)return false;

            currBit = n % 2;
            n /= 2;
        }
        return true;
    }
};