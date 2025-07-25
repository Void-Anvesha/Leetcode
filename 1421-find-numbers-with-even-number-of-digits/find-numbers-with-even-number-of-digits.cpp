class Solution {
public:
int cnt=0;
 void  countEvenDigits(vector<int>&nums,int n)
   {  int temp=0;
   
       while(n>0)
       {
            n/=10;
            temp++;
       }

       if(temp%2==0) cnt++;
   }

    int findNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        { 
            int num=nums[i];
            countEvenDigits(nums,num);
        }
        return cnt;
    }
};