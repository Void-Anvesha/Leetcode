class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long ans=0;

        int minPos = -1;
        int maxPos = -1;
        //Idx at which nums[i] > maxK
        int culpritIdx =-1;

        for(int i=0; i<nums.size(); i++){

            if(nums[i]<minK || nums[i]> maxK) culpritIdx = i;

            if(nums[i] == minK) minPos=i;

            if(nums[i] == maxK) maxPos=i;

            int smaller = min( minPos , maxPos);
            int temp = smaller - culpritIdx;
            ans+= (temp>0) ? temp : 0;
        }
        return ans;

    }
};