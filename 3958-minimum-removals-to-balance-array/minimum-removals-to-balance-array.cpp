class Solution {
public:
   // ( max <= k*min )
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int i = 0 , j = 0;
        int longest = 0;

        while(j < n){

            int minEl = nums[i];
            int maxEl = nums[j];

            if(maxEl <= (long long)k*minEl){
                longest = max(longest , j - i +1);
                j++;
            }else{
                while(maxEl > (long long)k*nums[i] && i < j){
                    i++;
                }
            }

        }
        return n - longest;
    }
};