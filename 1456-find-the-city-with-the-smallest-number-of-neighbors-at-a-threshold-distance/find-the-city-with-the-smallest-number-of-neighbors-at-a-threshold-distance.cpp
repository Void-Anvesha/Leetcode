class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //{u -> {v , wt}}
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;

    int cityNo , minCityCnt =INT_MAX;
   //Apply Djikstra's on each node
    for(int i=0; i<n; i++){
       vector<int>dist(n , 1e9);
       pq.push({0 , i});
       dist[i] = 0;

       while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it.first;
            int wt = it.second;
            if(dis + wt < dist[adjNode]){
                dist[adjNode] = dis+wt;
                pq.push({dist[adjNode] , adjNode});
            }
        }
       }
       int cnt =0;
       for(int city=0; city<n; city++){
        if(dist[city] <= distanceThreshold)cnt++;
       }
       if(cnt <= minCityCnt){
        minCityCnt = cnt;
        cityNo = i;
       }
    }
    return cityNo;
    }
};