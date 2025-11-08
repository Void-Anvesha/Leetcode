class Solution {
private:

void dfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
    vis[node]=1;
    int n=isConnected.size();
    for(int i=0;i<n;i++){
        if(isConnected[node][i] && !vis[i])
              dfs(i,isConnected,vis);
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int provinces=0;

        for(int i=0;i<n;i++){

            if(!vis[i]){
                dfs(i,isConnected,vis);
                provinces++;
            }
        }
        return provinces;

    }
};