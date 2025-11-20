class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //{{r,c},t}
        //t: time at which the fresh orange has been rotten
        queue<pair<pair<int,int>,int>>q;
        int fresh_oranges=0;
        int max_time=0;

        //Count the no of fresh oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({{i,j},0});
                else if(grid[i][j]==1)fresh_oranges++;
            }
        }
         //If there is no fresh orange to be rottened
        if(fresh_oranges==0)return 0; 

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};


        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();

            max_time=max(max_time,t);
            for(int i=0;i<4;i++ ){
                    int nrow=r+drow[i];
                    int ncol=c+dcol[i];
                    //Check the neighbours:
                    //If they are fresh mark them as rotten
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                        //Mark as rotten
                        grid[nrow][ncol]=2;
                        q.push({{nrow,ncol},t+1});
                        fresh_oranges--;
                    }
                }
        }
        // If fresh_oranges is 0, all were rotted, return max_time.
        // Otherwise, some fresh oranges were unreachable (blocked by empty cells or grid edges), return -1
        if(fresh_oranges==0)return max_time;
        else return -1;

    }
};