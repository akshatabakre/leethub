class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        #define int long long
        //store mini of path and sum of path
        //on reaching n-1, if sum<=k, store maximum of mini of every path
        //adjacent node should be online
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);//node,adjnode,cost
        // unordered_map<int,unordered_set<long long>> vis;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // vector<int> maxscore(n,-1);
        int ans = -1;
        priority_queue<pair<int,pair<int,long long>>> pq;//score,{node,sum}
        if(online[0])
            pq.push({1e9,{0,0}});
        while(!pq.empty()){
            int score = pq.top().first;
            int node = pq.top().second.first;
            int sum = pq.top().second.second;
            pq.pop();
            if(node==n-1){
                ans = max(score,ans);
                break;
            }
            for(auto it:adj[node]){
                int adjnode = it.first;
                int cost = it.second;
                if(online[adjnode] && sum+cost<=k){
                    pq.push({min(score,cost),{adjnode,sum+cost}});
                }
            }
        }
        return ans;
        #undef int
    }
};