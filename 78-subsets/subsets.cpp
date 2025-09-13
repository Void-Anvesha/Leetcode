class Solution {
public:
   void findSubset(int idx,vector<int>&nums,vector<int>&ds,vector<vector<int>>&result,int n){
    if(idx==n){
        result.push_back(ds);
        return;
    }
    //Pick el
    ds.push_back(nums[idx]);
    findSubset(idx+1,nums,ds,result,n);
    //Not pick
    ds.pop_back();
    findSubset(idx+1,nums,ds,result,n);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ds;
        findSubset(0,nums,ds,result,nums.size());
        return result;
    }
};