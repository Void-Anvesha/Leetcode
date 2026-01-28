class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool>row(m , false);
        vector<bool>col(n, false);
        //Find out the 'r' or 'c' which willl be impacted(marked zeros)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
       //Now mark 'r' & 'c' of the impacted ones as 0's
       for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(row[i] || col[j]) matrix[i][j] = 0;
        }
       }
    
    }
};