class Solution {
public:
    int pivotInteger(int n) {
        //Base Case
        if(n==1)return 1;
        int lSum=1,rSum=n;
        int l=1,r=n;
        int ans=-1;
        while(l<r){
            if(lSum<rSum){
                l++;
                lSum+=l;
            }
            else{
                r--;
                rSum+=r;
            }
            
           if(lSum==rSum && (l+1==r-1))return l+1;
        }
        return -1;
    }
};