class Solution {
public:
    bool isMagicGrid(vector<vector<int>>& grid , int r ,int c){
        //Uniqueness : 1 to 9 & distinct
        unordered_set<int>st;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9 || st.count(num))return false;
                else st.insert(num);
            }
        }

        //Check sums
        int RSum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        //Check RowSum & colSum
        for(int i=0; i<3; i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != RSum)return false;
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != RSum) return false;
        }

        //Check diagonal elements
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != RSum)return false;

        //Check antidiagonal elements
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != RSum)return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int cnt=0;

        for(int i=0; i<=rows-3; i++){
            for(int j=0; j<=cols-3; j++){
                if(isMagicGrid(grid , i , j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};