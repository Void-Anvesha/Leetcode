class Solution {
public:
    int f(vector<int>& nums,int k)
    {
        if(k<0)return 0;
        int l=0,r=0;
        int sum=0,cnt=0;
        while(r<nums.size()){
            sum+=(nums[r]%2);
            //shrint the array from left
            while(sum>k){
              sum-=(nums[l]%2);
              l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};