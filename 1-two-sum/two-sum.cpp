class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        //Vector for storing indices
        vector<pair<int,int>>numsWithIndex;

        for(int i=0;i<n;i++){
           numsWithIndex.push_back({nums[i],i});
        }

        sort(numsWithIndex.begin(),numsWithIndex.end());

        int l=0;
        int r=n-1;
        while(l<r){
            int sum=numsWithIndex[l].first+numsWithIndex[r].first;
            if(sum==target) return {numsWithIndex[l].second,numsWithIndex[r].second};
            else if(sum<target)l++;
            else r--;
        }
        return {};
    }
};