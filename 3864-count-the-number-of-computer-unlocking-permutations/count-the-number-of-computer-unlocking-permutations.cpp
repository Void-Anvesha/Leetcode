class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const long long MOD=1'000'000'007;
        long long ans=1;
        int n=complexity.size();

        for(int i=1;i<n;i++){
            //We can't decrypt the password
            if(complexity[i]<=complexity[0])return 0;
            else ans=(ans*1LL*(i))%MOD;
        }
        return (int)(ans%MOD);
    }
};