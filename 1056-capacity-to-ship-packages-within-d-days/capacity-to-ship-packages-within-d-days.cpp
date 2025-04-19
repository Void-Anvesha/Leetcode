class Solution {
public:
int days(vector<int> &weights, int cap,int n)
{
    int day=1;
    int loadCap=0;
    for(int i=0;i<n;i++)
    {
        if(loadCap+weights[i]>cap){
            day++;
            loadCap=weights[i];
        }
        else{
            loadCap+=weights[i];
        }
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int d) {
    int n=weights.size();
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n; i++)
    {
        sum+=weights[i];
        maxi=max(maxi,weights[i]);
    }
    int low=maxi;
    int high=sum;
    int ans=-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int daysReq=days(weights,mid,n);
        if(daysReq<=d)
        {
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    }
};