class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=(nums.size())/2;

        for(int i=0 ;i<nums.size(); i++)
        {
            mpp[nums[i]]++;
            
        }
        int num=0;
        for(auto it:mpp)
        {
            if(it.second>n)
            {
                 num=it.first;
                return num;
            }
        }
        return -1;
    
    }
};