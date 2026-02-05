class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;

        for(int i = 0; i < n; i++){

            int steps = (i + nums[i] % n + n)%n;
            res.push_back (nums[steps]);
        
        }
        return res;
    }
};