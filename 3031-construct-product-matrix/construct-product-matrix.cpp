class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>ans(m , vector<int>(n));//prod matrix
        vector<vector<int>>suffix(m , vector<int>(n));//suffix matrix

        long long suff = 1;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >=  0; j--){
                suffix[i][j] = suff;
                suff = (suff *grid[i][j]) % MOD;
            }
        }
        long long prefix  = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = (prefix * suffix[i][j]) %MOD;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }
    return ans;
        
    }
};