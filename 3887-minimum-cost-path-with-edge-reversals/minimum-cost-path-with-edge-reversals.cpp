class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int , int>>>adj(n);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v , wt});
            //Reversed edge
            adj[v].push_back({u , 2*wt});
        }

        //Priority Queue ( Min Heap)
        priority_queue<pair<int , int> , vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0 , 0});

        //Dist vector
        vector<int>dist(n , 1e9 );
        dist[0] = 0;

        while(!pq.empty()){
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(currDist > dist[node])continue;

            if(node == n-1) return dist[n-1];
            for(auto& it : adj[node]){
                int v = it.first;
                int wt = it.second;

                if(currDist + wt < dist[v]){
                    dist[v] = currDist + wt;
                    pq.push({dist[v] , v});
                }
            }

        }
        return -1;
    }
};