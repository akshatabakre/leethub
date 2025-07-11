class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        //entering time, node
        vector<vector<vector<int>>> adj(n);
        for(auto ed:edges){
            adj[ed[0]].push_back({ed[1],ed[2],ed[3]});//node,start time,endtime
        }
        vector<int> dist(n,1e9);
        dist[0] = 0;
        int ans = 1e9;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;//time,node
        q.push({0,0});
        while(!q.empty()){
            int ti = q.top()[0];
            int node = q.top()[1];
            q.pop();
            for(auto ad:adj[node]){
                if(ti<=ad[2] && dist[ad[0]]>max(ti,ad[1])+1){
                    dist[ad[0]] = max(ti,ad[1])+1;
                    q.push({max(ti,ad[1])+1,ad[0]});
                }
            }
        }
        if(dist[n-1]==1e9){
            return -1;
        }
        return dist[n-1];
    }
};