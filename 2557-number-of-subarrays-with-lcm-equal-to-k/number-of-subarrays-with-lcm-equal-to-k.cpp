class Solution {
public:
int lcm(int a,int b)
{
    return(a/(gcd(a,b)))*b;
}
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt=0; 
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(k%nums[i]!=0) continue;
            int curr_lcm=nums[i];
            for(int j=i;j<n;j++)
            {
                curr_lcm=lcm(curr_lcm,nums[j]);
                if(curr_lcm==k) cnt++;
                else if(curr_lcm>k) break;
            }

        }
        return cnt;
    }
};