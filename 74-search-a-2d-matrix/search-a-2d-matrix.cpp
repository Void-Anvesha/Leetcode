class Solution {
public:

bool bs(vector<int> & mat,int target)
{
    int n=mat.size();
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mat[mid]==target)return true;
        else if(mat[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int row=mat.size();
    int col=mat[0].size();
    for(int i=0;i<row;i++)
    {
     if (mat[i][0]<=target && target<=mat[i][col-1]){
         return bs(mat[i],target);
     }
    }
    return false;
    }
};