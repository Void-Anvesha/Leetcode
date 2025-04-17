class Solution {
public:
int findMax(vector<int> &v, int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,v[i]);
    }
    return maxi;
}

int totalHrs(vector<int> &v, int hourly,int n )
{
    long long total_time=0;
    for(int i=0;i<n;i++)
    {
       total_time+=ceil((double)v[i]/(double)hourly);
       if (total_time > INT_MAX) return INT_MAX;
    }
    return total_time;
}

int minEatingSpeed(vector<int> v, int h) {
    // Write Your Code Here
    int n=v.size();
    int low=1;
    int high=findMax(v,n);
    while(low<=high)
    {
       int mid=low+(high-low)/2;
       long long totalTime=totalHrs(v,mid,n);
       if(totalTime<=h){
           high=mid-1;
       }
       else{
           low=mid+1;
       }
    }
    return low;
}
};