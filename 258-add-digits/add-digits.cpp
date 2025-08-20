class Solution {
public:
    int addDigits(int num) {
        //If num%9==0 then sum=9
        //Ex: 18%9==0 sum=9
        if(num==0) return 0;
        return (num%9==0)?9:num%9;
    }
};