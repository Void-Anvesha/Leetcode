class Solution {
public:

   void findCombination(int idx,vector<int>& candidates,int target,
       vector<vector<int>>&result, vector<int>&ds){
        if(idx==candidates.size()){
            if(target==0){
                result.push_back(ds);
            }
            return;
        }
    //Choose curr candidate if it's <= target
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            findCombination(idx,candidates,target-candidates[idx],result,ds);
            //Remove all the idx before it & pick only the curr idx
            ds.pop_back();
        }
        findCombination(idx+1,candidates,target,result,ds);
       }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ds;
        findCombination(0,candidates,target,result,ds);
        return result;
    }
};