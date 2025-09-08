class Solution {
public:
     int f(vector<int>&nums,int goal)
   {
        if(goal<0)return 0;
        int l=0,r=0;
        int sum=0;
        int cnt=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
   }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //f(nums,k):finds subarray lesser than equal to k
        //f(nums,k-1):finds subarray lesser thena equal to k
        //subtracting them gives #subarray with sum==k
        return f(nums,goal)-f(nums,goal-1);
    }
};