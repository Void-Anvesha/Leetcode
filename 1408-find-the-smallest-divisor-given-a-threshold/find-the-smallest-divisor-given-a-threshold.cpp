class Solution {
public:

int divisor(vector<int>&arr,int div)
{
	int n=arr.size();
	int sum=0;
	for(int i=0; i<n; i++)
	{
		sum+=ceil((double)arr[i]/div);
		

	}
	return sum;
}
    int smallestDivisor(vector<int>& arr, int limit) {
    int n=arr.size();
	int maxi=INT_MIN;
	for(int i=0;i<n;i++)
	{
	   maxi=max(maxi,arr[i]);
	}
	int low=1;
	int high=maxi;
	int ans=-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(divisor(arr,mid)<=limit)
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