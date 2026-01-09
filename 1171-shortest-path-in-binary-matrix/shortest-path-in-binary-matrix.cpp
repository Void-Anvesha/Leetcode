class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //If src or destcell is blocked
        if(grid[0][0] == 1 || grid[n-1][m-1] ==1)return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dist(n , vector<int>(m , 1e9));
        dist[0][0] = 1;
        
        int dr[] = {-1 ,-1 , -1 , 0 , 1 , 1 , 1 ,0 };
        int dc[] = {-1 , 0 , 1 , 1 , 1 , 0 , -1 , -1};
      
        while(!q.empty()){
            auto it =q.front();
            q.pop();

    
            int r = it.first;
            int c = it.second;
             
            if(r== n-1 && c== m-1)return dist[r][c];
           for(int i=0; i<8; i++){
            int nrow = r + dr[i];
            int ncol = c+ dc[i];

            if(nrow>=0 && nrow < n && ncol>=0 && ncol<m && 
             grid[nrow][ncol]==0 && dist[r][c]+ 1 <dist[nrow][ncol] ){
                dist[nrow][ncol] = dist[r][c]+1;
                q.push({nrow , ncol});
             }
           }
        }

     return -1;
    }
};