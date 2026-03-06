class Solution {
public:
    bool f(int idx , int target , vector<int>& nums , vector<vector<int>>&dp){

        if(target == 0)return true;
        if(idx == 0) return (nums[0] == target);
        
        if(dp[idx][target] != -1)return dp[idx][target];
        bool notTake = f(idx-1 , target , nums , dp);
        bool take = (target >= nums[idx]) ? f(idx-1 , target-nums[idx] , nums ,dp) :
                    false;

        return dp[idx][target] = take | notTake;


    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) total += nums[i];
        //we can't find equal subset for odd numbers
        if(total % 2 == 1)return false;
        int target = total/2;
        
        vector<vector<int>>dp(n , vector<int>(target+1 , -1));
        return f(n-1 , target , nums , dp );
    }
};