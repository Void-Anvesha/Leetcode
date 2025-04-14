class Solution {
public:
int search(vector<int> &nums, int target,int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)return mid;
         //Left sorted
         else if(nums[mid]>=nums[low])
         {
             if(nums[low]<=target && target<=nums[mid])
             {
                high=mid-1;
             }
             else{
                low=mid+1;
             }
         }
         //Right sorted
         else{
            if(nums[mid]<=target && target<=nums[high])
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
         }

    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        return search(nums,target,nums.size());
    }
};