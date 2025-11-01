class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result(n+1);

        //Base Case
        if(n==0) return result;
        //Binary of 0 has 0 no of bits set as 1
        result[0]=0;

        for(int i=1;i<=n;i++){
            if(i%2==1){
                //Suppose 3: 11 & 3/2 is 1+1=2 
                result[i]=result[i/2]+1;
            }
            else{
                result[i]=result[i/2];
            }
        }
        return result;


    }
};