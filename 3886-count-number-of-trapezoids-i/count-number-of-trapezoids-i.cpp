class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD=1000000007;

        //Count how many points lie on each y-value
        unordered_map<long long,long long>countOnY;
        for(auto &p:points){
            long long y=p[1];
            countOnY[y]++;
        }

        // (how many ways to pick 2 points on that horizontal line)
        vector<long long>ways;
        for(auto & entry:countOnY){
            long long cnt=entry.second;
            //Combination
            long long c2=(cnt>=2?(cnt*(cnt-1)/2):0);
            ways.push_back(c2 % MOD);
        }

        //Compute total trapezoids
        long long ans=0;
        long long sum=0;

        for(long long temp:ways){
            ans=(ans+ sum*temp)%MOD;
            sum=(sum+temp)%MOD;
        }

        return (int)ans;

    }
};