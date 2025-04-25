class Solution {
public:
 int maxSubarray(vector<int> &arr, int temp)
{
	int cnt=1;
	int sum=0;
	for(int i=0;i<arr.size();i++)
	{
		if(sum+arr[i]<=temp)
		{
			sum+=arr[i];
		}
		else{
			cnt++;
			sum=arr[i];
		}
	}
	return cnt;
}
int splitArray(vector<int> &arr, int k) {
	// Write your code here.
	int n=arr.size();
	int maxi=INT_MIN;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		maxi=max(maxi,arr[i]);
		sum+=arr[i];
	}
	int low=maxi;
	int high=sum;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		int maxSum=maxSubarray(arr,mid);
		if(maxSum<=k)
		{
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return low;
}
};