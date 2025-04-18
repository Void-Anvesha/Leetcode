class Solution {
public:

bool Possible(vector<int> &arr,int day,int m,int k)
{
	int cnt=0;
	int no_of_bouquets=0;
	int n=arr.size();
	for(int i=0; i<n;i++)
	{
		if(arr[i]<=day){
		cnt++;}
		else{
			no_of_bouquets+=cnt/k;
			cnt=0;
		}
	}
	no_of_bouquets+=cnt/k;
	if(no_of_bouquets>=m) return true;
	else return false;
}
    int minDays(vector<int>& arr, int m, int k) {
    int n=arr.size();
    int val=(long long)k*(long long)m;
	if (val>n) return -1;
	int mini=INT_MAX;
	int maxi=INT_MIN;
    int ans=-1;
	for(int i=0;i<n;i++)
	{
		mini=min(mini,arr[i]);
		maxi=max(maxi,arr[i]);
	}
	int low=mini;
	int high=maxi;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(Possible(arr,mid,m,k)){
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