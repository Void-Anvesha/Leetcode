class Solution {
public:
   int maxEl(vector<vector<int>> &g,int n ,int m, int mid)
{
    int maxi=INT_MIN;
    int row;
    for(int i=0;i<n;i++)
    {
       if(g[i][mid]>maxi){
           maxi=g[i][mid];
           row=i;
       }
    }
    return row;
}
    vector<int> findPeakGrid(vector<vector<int>>& g) {
    int n=g.size();
    int m=g[0].size();
    int low=0;
    int high=m-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int row=maxEl(g,n,m,mid);
        int left=mid-1>=0?g[row][mid-1]:-1;
        int right=mid+1<m?g[row][mid+1]:-1;
        if(g[row][mid]>left && g[row][mid]>right) return {row,mid};
        else if(g[row][mid]<left) high=mid-1;
        else low=mid+1;
    }
    return{-1,-1};
        
    }
};