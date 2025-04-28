class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
    int maxOnes=-1;
    int ind=-1;
   int rows = matrix.size();
   int cols = matrix[0].size();

    for(int i=0; i<rows;i++)
    {
        int cntRow=0;
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j]==1)
            {
                cntRow++;
            }
        }
        if(cntRow>maxOnes)
        {
            maxOnes=cntRow;
            ind=i;
        }
    }
    return {ind,maxOnes};
    }
};