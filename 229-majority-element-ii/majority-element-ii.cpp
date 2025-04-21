class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int>ans;
        int n=nums.size()/3;
        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second>n)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};