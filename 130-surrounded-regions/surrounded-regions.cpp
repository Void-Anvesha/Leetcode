class Solution {
private:
 
 void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis,
          int delRow[], int delCol[]){
       vis[row][col]=1;
       int n=board.size();
       int m=board[0].size();

       for(int i=0;i<4;i++){
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 &&
           board[nrow][ncol]=='O') dfs(nrow,ncol,board,vis,delRow,delCol);
       }
 }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
       
       //Check for 1st row & last row
       for(int i=0;i<m;i++){

        //1st row
        if(board[0][i]=='O' && vis[0][i]==0)dfs(0,i,board,vis,delRow,delCol);

        //last row
        if(board[n-1][i]=='O' && vis[n-1][i]==0)dfs(n-1,i,board,vis,delRow,delCol);
       }

       //Check for 1st & last col
       for(int j=0;j<n;j++){

        //1st Col
        if(board[j][0]=='O' && vis[j][0]==0)dfs(j,0,board,vis,delRow,delCol);

        //last col
        if(board[j][m-1]=='O' && vis[j][m-1]==0)dfs(j,m-1,board,vis,delRow,delCol);
       }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0)board[i][j]='X';
            }
        }
    }
};