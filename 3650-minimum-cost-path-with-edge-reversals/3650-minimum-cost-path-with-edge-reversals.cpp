class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }
        vector<int> dist(n,1e9);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top[1], cost = top[0];
            for(auto it:adj[node]){
                int adjnode = it[0], w = it[1];
                if(dist[adjnode]>cost+w){
                    dist[adjnode] = cost + w;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        if(dist[n-1]==1e9){
            return -1;
        }
        return dist[n-1];
    }
};