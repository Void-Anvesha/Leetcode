class Solution {
private:
   void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,
        int delRow[],int delCol[]){
         vis[row][col]=1;

         int n=grid.size();
         int m=grid[0].size();

         for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];

            if(nRow>=0 && nRow<n &&nCol>=0 && nCol<m && grid[nRow][nCol]==1 && 
            vis[nRow][nCol]==0) dfs(nRow,nCol,grid,vis,delRow,delCol);
         }
        }
public:

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));\
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        

        //Check for the 1st row & last col
        for(int i=0;i<m;i++){

            //Check for 1st row
            if(grid[0][i]==1 && vis[0][i]==0)dfs(0,i,grid,vis,delRow,delCol);

            //Check for last row
            if(grid[n-1][i]==1 && vis[n-1][i]==0)dfs(n-1,i,grid,vis,delRow,delCol);
        }

        //Check for 1st & last col
        for(int i=0;i<n;i++){

            //Check for 1st row
            if(grid[i][0]==1 && vis[i][0]==0)dfs(i,0,grid,vis,delRow,delCol);

            //Checl for last col
            if(grid[i][m-1]==1 && vis[i][m-1]==0)dfs(i,m-1,grid,vis,delRow,delCol);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)cnt++;
            }
        }
        return cnt;
    }
};