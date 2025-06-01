#define ll long long
class Solution {
public:
ll MOD = 1e9 + 7;
    ll countPaths(int n, vector<vector<int>>& roads) {

        //declaration and initializations
        //adj -> node,adjnode,dist
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto edge:roads){
            //bi
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        //vectors - distance and ways
        vector<ll> distance(n,LONG_MAX), ways(n,0);
        distance[0] = 0;
        ways[0] = 1;

        //dijkstra
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;//minheap
        pq.push({0,0});//distance,node
        while(!pq.empty()){
            auto up = pq.top();
            pq.pop();
            ll dist = up.first, node = up.second;
            for(auto it:adj[node]){
                ll adjnode = it.first, newdist = dist + it.second;
                if(newdist < distance[adjnode]){
                    distance[adjnode] = newdist;
                    pq.push({newdist,adjnode});
                    ways[adjnode] = ways[node];
                }else if(newdist == distance[adjnode]){
                    ways[adjnode] = (ways[node] + ways[adjnode])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};