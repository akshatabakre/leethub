class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> DistFromK(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge:times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        priority_queue<
        pair<int,int>,  vector<pair<int,int>>,   greater<pair<int,int>>
        > pq;
        DistFromK[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto neigh:adj[node]){
                int adjnode = neigh.first;
                int wei = neigh.second;
                if(dist + wei < DistFromK[adjnode]){
                    DistFromK[adjnode] = dist + wei;
                    pq.push({dist+wei,adjnode});
                }
            }
        }
        int maxi = -1e9;
        for(int i=1;i<=n;i++){
            int dist = DistFromK[i];
            maxi = max(dist,maxi);
        }
        if(maxi==1e9)   return -1;
        return maxi;
    }
};