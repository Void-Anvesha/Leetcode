class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();

        //Case 1 : ('F' -> 'T')

        int res=0;
        int i=0, j=0;
        int cntF=0;

        while(j < n){

            if(answerKey[j]=='F'){
                cntF++;
            }
            while(cntF > k){
                if(answerKey[i]=='F')cntF--;
                i++;
            }
            res= max(res, j-i+1);
            j++;
        }

        //Case 2: ('T' -> 'F')
        i=0 , j=0;
        int cntT=0;
          while(j < n){
            if(answerKey[j]=='T'){
                cntT++;
            }
            while(cntT > k){
                if(answerKey[i]=='T')cntT--;
                i++;
            }
            res= max(res, j-i+1);
            j++;
        }
        return res;
    }
};