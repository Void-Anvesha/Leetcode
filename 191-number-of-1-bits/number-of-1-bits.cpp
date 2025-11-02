class Solution {
public:
    int hammingWeight(int n) {
        //Built-in function to count the no of set bits
        return __builtin_popcount(n);
    }
};