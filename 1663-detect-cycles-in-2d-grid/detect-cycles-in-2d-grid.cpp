class Solution {
private:

bool dfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int row,int col,char ch,int pRow,int pCol){
    int n=grid.size();
    int m=grid[0].size();

    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};

    vis[row][col]=1;

    for(int i=0;i<4;i++){
        int nRow=row+delRow[i];
        int nCol=col+delCol[i];

        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==ch){
            if(!vis[nRow][nCol]){
                if(dfs(grid,vis,nRow,nCol,ch,row,col))return true;
            }
            else if(nRow!=pRow || nCol!=pCol)return true;
        }
    }
    return false;
}
public:
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(grid,vis,i,j,grid[i][j],-1,-1))return true;
                }
            }
        }
        return false;
    }
};