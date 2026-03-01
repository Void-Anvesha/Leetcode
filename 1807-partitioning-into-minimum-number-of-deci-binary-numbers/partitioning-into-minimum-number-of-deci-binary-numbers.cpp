class Solution {
public:
    int minPartitions(string n) {
        //If you find the max digit in a no
        //You get the no of steps to get that numbers -> n
        int maxDigit = 0;
        for(char digit : n){
          int no = digit - '0';
          maxDigit = max(maxDigit , no);
        }
        return maxDigit;
    }
};