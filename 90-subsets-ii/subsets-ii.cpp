class Solution {
public:

void findSubset(int idx,vector<int>&nums,vector<int>&ds,vector<vector<int>>&result){
result.push_back(ds);
for(int i=idx;i<nums.size();i++){
    if(i!=idx && nums[i]==nums[i-1])continue;
    ds.push_back(nums[i]);
    findSubset(i+1,nums,ds,result);
    ds.pop_back();
}

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //sorting so that duplicates are together
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>ds;
        findSubset(0,nums,ds,result);
        return result;
    }
};