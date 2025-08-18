class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n),meretak(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            meretak[it[1]].push_back({it[0],it[2]});
        }
        // dist,node
        vector<int> dist(n,1e9);
        dist[0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,
            greater<vector<int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int w = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();
            for(auto it:adj[node]){
                //direct edges
                int adjnode = it[0], wei = it[1];
                if(dist[adjnode]>w+wei){
                    dist[adjnode] = w+wei;
                    pq.push({dist[adjnode],adjnode});
                }
            }
            for(auto it:meretak[node]){
                int adjnode = it[0], wei = it[1];
                if(dist[adjnode]>w+(2*wei)){
                    dist[adjnode] = w+(2*wei);
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