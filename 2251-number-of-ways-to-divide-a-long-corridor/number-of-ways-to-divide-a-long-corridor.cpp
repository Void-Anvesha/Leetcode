class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD=1000000007;
         int seats=0;
         for(char c:corridor){
            if(c=='S')seats++;
         }
        //No ways if seats are zeror or odd
        if(seats==0 || seats%2 !=0)return 0;

        long long ans=1;
        int seatCnt=0;
        int plantsBetween=0;
        bool countingPlants=false;

        for(char c:corridor){
            if(c=='S'){
                seatCnt++;
            
            //Finished one section of 2 seats
            if(seatCnt==2)countingPlants=true;

            //Starting next Section
            else if(seatCnt==3){

                ans=(ans*(plantsBetween+1))%MOD;
                plantsBetween=0;
                seatCnt=1;
                countingPlants=false;
            }
        }else if(countingPlants)plantsBetween++;

        }
        return ans;
    }
};