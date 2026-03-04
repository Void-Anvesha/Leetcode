class Solution {
public:
    int numSpecial(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int>rowCnt(m,0);
        vector<int>colCnt(n,0);
        //Count no of 1's in rows & cols
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){

                if(matrix[row][col] == 1){
                    rowCnt[row]++;
                    colCnt[col]++;
                }
            }
        }

        //Find special pos
        int res = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == 0)continue;
                if(matrix[row][col] == 1 && rowCnt[row] == 1 && colCnt[col] == 1)res++;
            }
        }
        return res;
    }
};