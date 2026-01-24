class Solution {
public:
    int minPairSum(vector<int>& nums) {
      int n = nums.size();
      //Start finding the pairs from (start,end)
      sort(nums.begin() , nums.end());
      int i=0 , j= n-1;
      
      int maxPairSum = 0;
      while(i < j){
         int sum = nums[i] + nums[j];
         maxPairSum = max(maxPairSum , sum);
         i++;
         j--;
      }
    return maxPairSum;
    }
};