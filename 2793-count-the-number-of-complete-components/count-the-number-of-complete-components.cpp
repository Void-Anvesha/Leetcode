class Solution {
private:
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int &nodes,int &degreeSum){
    vis[node]=1;
    nodes++;
    degreeSum+=adj[node].size();
    for(auto& neighbor:adj[node]){
        if(!vis[neighbor]){
          dfs(neighbor,adj,vis,nodes,degreeSum);
        }
    }
}
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //Adjacency list
        vector<vector<int>>adj(n);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes=0,degreeSum=0;
                dfs(i,adj,vis,nodes,degreeSum);
                if(degreeSum==(nodes*(nodes-1)))ans++;
            }
        }
        return ans;
    }
};