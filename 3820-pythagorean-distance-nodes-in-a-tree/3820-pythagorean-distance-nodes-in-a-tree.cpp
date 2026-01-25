class Solution {
public:
    vector<vector<int>> adj;
    int n;
    vector<long long> bfs(int node){
        #define int long long
        vector<int> ans(n,-1);
        queue<vector<int>> q;
        q.push({node,0});
        ans[node] = 0;
        while(!q.empty()){
            int curr = q.front()[0];
            int dist = q.front()[1];
            q.pop();
            for(int adjnode:adj[curr]){
                if(ans[adjnode]==-1){
                    ans[adjnode] = dist+1;
                    q.push({adjnode,dist+1});
                }
            }
        }
        return ans;
        #undef int
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        #define int long long
        this->n = n;
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dx = bfs(x);
        vector<int> dy = bfs(y);
        vector<int> dz = bfs(z);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int a = dx[i], b = dy[i], c = dz[i];
            vector<int> v = {a,b,c};
            sort(v.begin(),v.end());
            if(v[0]*v[0] + v[1]*v[1] == v[2]*v[2]){
                ans++;
            }
        }
        return ans;
        #undef int
    }
};