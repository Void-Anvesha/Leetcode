class Solution {
private:

void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int &nodes,int &degreeSum){
vis[node]=1;
nodes++;
degreeSum+=adj[node].size();

for(auto &it:adj[node]){
    if(!vis[it])dfs(it,adj,vis,nodes,degreeSum);
}
}
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int v=edge[0];
            int u=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            int nodes=0,degreeSum=0;
            dfs(i,adj,vis,nodes,degreeSum);
            //Complete connected means 
            //Alll nodes are connecting to each other
            if(degreeSum==(nodes*(nodes-1)))ans++;
        }
        return ans;
    }
};