class Solution {
public:
    int bestClosingTime(string customers) {
        int n= customers.size();

        vector<int>prefix_N (n + 1 , 0);
        prefix_N[0] = 0;

        vector<int>suffixY(n + 1 , 0);
        suffixY[n] =0;

        for(int i=1; i<=n; i++){

            if(customers[i-1] == 'N'){
                prefix_N[i] = prefix_N[i-1] + 1;
            }
            else{
                prefix_N[i] = prefix_N[i-1];
            }
        }


        //Suffix
        for(int i=n-1; i>=0; i--){

            if(customers[i] == 'Y'){
                suffixY[i]=suffixY[i+1] + 1;
            }
            else{
                suffixY[i] = suffixY[i+1];
            }
        }


        int minPenalty=INT_MAX;
        int minHour=INT_MAX;

        for(int i=0; i<=n; i++){

            int currPenalty=prefix_N[i] + suffixY[i];
            if(currPenalty < minPenalty){
                minPenalty = currPenalty;
                minHour = i;
            }
        }
        return minHour;
    }
};