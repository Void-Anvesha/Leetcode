class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n= customers.size();

        int minHour=0;
        int penalty=count(customers.begin() , customers.end() , 'Y');
        
        int minPenalty=penalty;
        for(int i=0; i<n; i++){

            if(customers[i] == 'Y'){
                penalty--;
            }else{
                penalty++;
            }
            if(penalty < minPenalty){
                minPenalty=penalty;
                minHour= i+1;
            }
        }
        return minHour;

    }
};