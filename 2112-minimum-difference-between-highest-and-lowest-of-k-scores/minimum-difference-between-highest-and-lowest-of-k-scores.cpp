class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;

        sort(nums.begin() , nums.end());
        int i=0 , j = k-1;
        int minScore = INT_MAX;
        
       while(j < n){
        int minEl = nums[i];
        int maxEl = nums[j];

        minScore = min(minScore , maxEl - minEl);

        i++;
        j++;
       }
     return minScore;
    }
};