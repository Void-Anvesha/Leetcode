class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int k=0;k<=31;k++){
            int temp=(1<<k);
            int cntZeros=0,cntOnes=0;

            for(int num:nums){
                //To find out the kth bit of each number
                  if((num&temp)==0)cntZeros++;
                  else cntOnes++;
            }
            if(cntOnes%3==1){
                res=(res|temp);
            }
        }
        return res;
    }
};