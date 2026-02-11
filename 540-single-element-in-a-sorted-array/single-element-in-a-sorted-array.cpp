class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int l = 1 , r = n-2;
        if(n == 1)return nums[0];
        if(nums[0] != nums[l])return nums[0];
        if(nums[r] != nums[n-1])return nums[n-1];

        while( l <= r){
            int mid = l + (r - l)/2;

            if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1]))return nums[mid];
            //Left half
            else if( (mid%2 == 1 && nums[mid] == nums[mid-1]) || (mid%2 == 0 && nums[mid]== nums[mid+1])){
                l = mid+1;
            }
            //Right half
            else r = mid-1;

        }
        return -1;
    }
};