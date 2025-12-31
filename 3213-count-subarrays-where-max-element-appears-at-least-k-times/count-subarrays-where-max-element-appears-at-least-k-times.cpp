class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n =nums.size();

        int maxE = *max_element(nums.begin() , nums.end());

        int i=0, j=0;
        long long res=0;
        int cntMax=0;

        while(j < n){
            if(nums[j] == maxE)cntMax++;

            while(cntMax >= k){
                if(nums[i] == maxE)cntMax--;
                res+=n - j;
                i++;
            }
            j++;
        }
        return res;
        
    }
};