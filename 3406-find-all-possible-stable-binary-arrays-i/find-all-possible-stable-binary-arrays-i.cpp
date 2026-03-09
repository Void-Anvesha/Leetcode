class Solution {
public:
    int M = 1e9 + 7;
    //{zerosLeft, onesleft , lastWasOne}
    int t[201][201][2];

    int solve(int zerosLeft , int onesLeft , bool lastWasOne , int limit){

        //Base case{Used all 0's & 1's}
        if(zerosLeft == 0 && onesLeft == 0)return 1;
        
        if(t[zerosLeft][onesLeft][lastWasOne] != -1)return t[zerosLeft][onesLeft][lastWasOne];
        int res = 0;
        //Explore 0s
        if(lastWasOne == true){
            for(int len = 1; len <= min(zerosLeft , limit); len++){
                res = (res + solve(zerosLeft - len , onesLeft , false , limit))%M;
            }
        }else{
            for(int len = 1; len <= min(onesLeft , limit); len++){
                res = (res + solve(zerosLeft , onesLeft- len, true , limit )) % M;
            }
        }
    return t[zerosLeft][onesLeft][lastWasOne] = res;

    }
    int numberOfStableArrays(int zero, int one, int limit) {
         memset(t , -1 , sizeof(t));
         int startWithOne = solve(zero , one , false , limit);
         int startWithZero = solve(zero , one , true , limit);

         return (startWithOne + startWithZero) % M;
    }
};