class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=1;

        int l=0;
        for(int r=1; r<n; r++){
            if(prices[r-1]-prices[r]==1){
                ans+=(r-l+1);
            }else{
                l=r;
                ans+=1;
            }
        }
        return ans;
    }
};