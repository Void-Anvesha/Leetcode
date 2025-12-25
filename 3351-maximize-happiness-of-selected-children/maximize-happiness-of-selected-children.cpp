class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        //Give gifts to the happiest children first
        sort(happiness.rbegin() , happiness.rend());

        long long TotalmaxiHappiness=0;
        for(int i=0; i<k; i++){
          int currHappiness= happiness[i] - i;
          if(currHappiness < 0)break;
          TotalmaxiHappiness+= currHappiness;
        }
        return TotalmaxiHappiness;
    }
};