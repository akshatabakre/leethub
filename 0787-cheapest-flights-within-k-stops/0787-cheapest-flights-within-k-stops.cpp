class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vector<pair<int,int>> paths[n];//adjnode,cost
        vector<vector<pair<int,int>>> paths(n);
        for(auto i:flights){
            paths[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;//stops,node,cost
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first, node = it.second.first, cost = it.second.second;
            if(stops>k){
                break;//means the destination might already have been updated till now
            }
            for(auto i:paths[node]){
                int adjnode = i.first, c = i.second;
                if(cost + c < dist[adjnode] && stops<=k){//*
                    dist[adjnode] = cost + c;//updating destination here
                    q.push({stops+1,{adjnode,cost+c}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};