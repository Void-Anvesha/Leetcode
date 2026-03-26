class Solution {
public:
   typedef long long ll;
   ll total = 0;
    bool checkHorCuts(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll>st;
        ll top = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                top += grid[i][j];
                st.insert(grid[i][j]);
            }
            ll bottom = total - top;
            ll diff = top- bottom;
           
            if(diff == 0)return true;
        //To ensure connectivity
        //These arre the corner cases
            if(diff == grid[0][0])return true;
            if(diff == grid[0][n-1])return true;
            if(diff == grid[i][0])return true;
            if(i > 0 && n >1  && st.count(diff))return true;
        }
    return false;

    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total += grid[i][j];
            }
        }
    //Horizontal cut
    if(checkHorCuts(grid)) return true;

    reverse(grid.begin() , grid.end());

    if(checkHorCuts(grid)) return true;

    //Original grid
    reverse(grid.begin() , grid.end());

    //Vertical cut checking but by using horizontal cut
    //Transpose of grid & then do checkHorCuts
    vector<vector<int>>transposeGrid(n , vector<int>(m));//n*m

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            transposeGrid[j][i] = grid[i][j];
        }
    }

    if(checkHorCuts(transposeGrid)) return true;

    reverse(transposeGrid.begin() , transposeGrid.end());

    if(checkHorCuts(transposeGrid)) return true;
    

   return false;

    }
};