class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>t(n , vector<int>(n));

        //Fill 1st row
        for(int col = 0; col < n; col++){
            t[0][col] = matrix[0][col];
        }

        //Now start filling all the rows starting from 2nd row
        for(int row = 1; row < n; row++){
            for(int col = 0; col < n; col++){
                //Find min among 3 poss
                int a =  INT_MAX;
                int b = INT_MAX;
                if(col - 1 >= 0) a = t[row-1][col-1];
                if(col+1 < n) b = t[row-1][col+1];
                t[row][col] = matrix[row][col] + min({t[row-1][col] , a ,b});
            }
        }
        int res = INT_MAX;
        int lastRow = n-1;
        for(int col = 0; col < n; col++){
            res = min(res , t[lastRow][col]);
        }
    return res;
    }
};