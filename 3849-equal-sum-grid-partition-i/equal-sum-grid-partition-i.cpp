class Solution {
public:
   typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //Find totalSum
        ll totalSum = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                totalSum += grid[i][j];
            }
        }

        //Slice horizontally
        ll suffix = totalSum , prefix = 0;
        for(int i = 0; i < m; i++){
             int j = 0;
             while(j < n){
                prefix += grid[i][j];
                suffix -= grid[i][j];
                j++;
             }
             if(prefix == suffix) return true;
        }

        //Slice vertically
        suffix = totalSum , prefix = 0;
        for(int i = 0; i < n; i++){
            int j = 0;
            while(j < m){
                prefix += grid[j][i];
                suffix -= grid[j][i];
                j++;
            }
            if(suffix == prefix)return true;
        }
    return false;
    }
};