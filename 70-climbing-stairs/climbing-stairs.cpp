class Solution {
public:
vector<int>dp;
    int climbStairs(int n) {
       if (dp.empty())              // initialize only once
            dp.resize(n + 1, -1);
        if(n == 0 || n == 1)return 1;
        if(dp[n] != -1)return dp[n];
        int left = climbStairs(n-1);
        int right = climbStairs(n-2);

        return dp[n] = left+right;

    }
};