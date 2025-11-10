class Solution {
private:
void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
    vis[row][col]=1;

    int m=grid.size();
    int  n=grid[0].size();

    queue<pair<int,int>>q;
    q.push({row,col});

    //BFS Traversal
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        //Traversal in neighbors
        //Direction : {up,right,down,left}
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n
                  && grid[nRow][nCol]=='1' && !vis[nRow][nCol]){
                        vis[nRow][nCol]=1;
                        q.push({nRow,nCol});
                }
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                    
                }
            }
        }
        return cnt;

    }
};