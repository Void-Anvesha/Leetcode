class Solution {
public:
   // Factor comes in pair for 21 : (3,7) both 3& 7 are factors
    int findSumDivisors(int num){
        int divisors= 0; //count
        int sum=0;

        for(int fact=1; fact*fact <=num; fact++){
            if(num % fact ==0){
                int other = num/fact;

                if(fact == other) {
                    divisors+=1;
                    sum+=fact;
                }else{
                    divisors+=2;
                    sum+=(fact+other);
                }
            }

            if(divisors > 4) return 0;
        }
        return (divisors==4) ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n= nums.size();
        int totalSum=0;
        for(int i=0; i<n; i++){
         totalSum += findSumDivisors(nums[i]);

        }
        return totalSum;

    }
};