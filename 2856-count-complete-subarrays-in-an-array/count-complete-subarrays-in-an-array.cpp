class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        //Store Unique el
        unordered_set<int>st(nums.begin() , nums.end());
        int totalUnique = st.size();
        int i=0 ,  j=0;
        int cnt =0;
       unordered_map<int,int>freq;
        while(j < n){
          freq[nums[j]]++;

          while(freq.size() == totalUnique){
            cnt+= (n - j);
            freq[nums[i]]--;
            if(freq[nums[i]] == 0)freq.erase(nums[i]);
            i++;
          }
          j++;
        }
       return cnt;
    }
};