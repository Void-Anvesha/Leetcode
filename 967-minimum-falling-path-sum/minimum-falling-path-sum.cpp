class Solution {
public:
    int n;
    int t[101][101];
    int solve(vector<vector<int>>& matrix , int row , int col){
        if(row == n-1)return matrix[row][col];

        if(t[row][col] != INT_MAX)return t[row][col]; 
        int sum = matrix[row][col];
        int minSum = INT_MAX;

    if(row+1 < n && col > 0) minSum = min(minSum , sum + solve(matrix , row+1 , col-1));
    if(row+1 < n) minSum = min(minSum , sum + solve(matrix , row+1 , col));
    if(row+1 < n && col+1 < n)minSum = min(minSum , sum + solve(matrix , row+1 , col+1));

    return t[row][col] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        int row = 0;
        int minSum = INT_MAX;
        for(int i = 0; i < 101; i++){
            for(int  j = 0; j < 101; j++){
                t[i][j] = INT_MAX;
            }
        }
        for(int col = 0; col < n; col++){
          minSum = min(minSum , solve(matrix , row , col));
        }
    return minSum;
    }
};