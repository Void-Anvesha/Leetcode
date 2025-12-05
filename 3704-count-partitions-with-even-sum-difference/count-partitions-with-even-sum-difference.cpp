class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        int ans=0;
        int left=0;
        int right=sum;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right-=nums[i];
            if((right-left)%2==0)ans++;
        }
        return ans;
    }
};