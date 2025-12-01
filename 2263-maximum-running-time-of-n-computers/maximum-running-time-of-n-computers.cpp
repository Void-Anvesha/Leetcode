class Solution {
public:
    bool possible(vector<int>& batteries,long long mid,int n){

        long long total_min=n*mid;

        long long sum=0;

        for(auto b:batteries){
            sum+=min((long long)b,mid);

            if(sum>=total_min)return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=0;

        long long sum_total_min=0;
        for(auto min:batteries) sum_total_min+=min;

       long long r=sum_total_min/n;
       long long res=0;
        while(l<=r){
         
         long long mid=l+(r-l)/2;
         if(possible(batteries,mid,n)){
            res=mid;
            l=mid+1;
         }

         else r=mid-1;
        }
        return res;
    }
};