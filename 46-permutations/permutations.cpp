class Solution {
public:
    void findPermutations(vector<int>&nums,vector<int>&ds,vector<vector<int>>&result,map<int,int>mp){
        if(ds.size()==nums.size()){
            result.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mp[i]){
                mp[i]=1;
                ds.push_back(nums[i]);
                findPermutations(nums,ds,result,mp);
                mp[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ds;
        map<int,int>mp;
        findPermutations(nums,ds,result,mp);
        return result;
    }
};