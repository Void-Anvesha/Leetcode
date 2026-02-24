class Solution {
public:
//Tabulation Method(Bottom-Up)
    int climbStairs(int n) {
        int prev2 = 1 , prev1 = 1;
        if(n == 0 || n == 1)return 1;

        for(int i =2; i <= n; i++){
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};