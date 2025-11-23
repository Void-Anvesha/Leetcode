class Solution {
bool check(int start,vector<vector<int>>& graph,vector<int>&color,int n){
      queue<int>q;
       q.push(start);
       color[start]=0;

       while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it:graph[node]){
            //If the adjacent node is yet not colored
            //you will give the opposite collor of the node
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            //Is the color of adjacent node same as of my color
            else{
                if(color[it]==color[node])return false;
            }
        }
       }
       return true;
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
     int n=graph.size();
     vector<int>color(n,-1);

     for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(check(i,graph,color,n)==false)return false;
        }
     }
     return true;
    }
};