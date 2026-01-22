class Solution {
public:
    int minPairSum(vector<int>&nums){
        int miniSum = INT_MAX;
        int idx = 0;
        for(int i=0; i<nums.size()-1; i++){
            int sum = nums[i] + nums[i+1];
            if(sum < miniSum){
                miniSum = sum;
                idx = i;
            }
        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
       int op = 0;

       while(!is_sorted(nums.begin() , nums.end())){
        //Find the index with min pair Sum
        int index = minPairSum(nums);

        nums[index] = nums[index] + nums[index + 1];
        nums.erase(nums.begin() + index +1);
        op++;
       }
       return op;
    }
};