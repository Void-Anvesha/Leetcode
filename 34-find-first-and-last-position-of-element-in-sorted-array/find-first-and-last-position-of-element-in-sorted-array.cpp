class Solution {
public:

int lowerBound(vector<int> &nums,int target,int n)
{
    int low=0;
    int high=n-1;
    int lb=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>=target)
        {
            lb=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return lb;
}

int upperBound(vector<int> &nums,int target,int n)
{
    int low=0;
    int high=n-1;
    int ub=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>target)
        {
            ub=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ub;
}
    vector<int> searchRange(vector<int>& nums, int target) {
     int n=nums.size();
      int lb=lowerBound(nums,target,n);
      if(lb==n || nums[lb]!=target) return {-1,-1};
      int ub=upperBound(nums,target,n);
      return {lb,ub-1};
    }
};