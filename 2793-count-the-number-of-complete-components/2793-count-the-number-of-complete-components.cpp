class Solution {
public:
    bool completebsf(int node,vector<vector<int>>& adj,vector<int>& vis){
        queue<int> q;
        vis[node] = 1;
        int nodes = 1;
        for(int i:adj[node]){
            vis[i] = 1;
            q.push(i);
            nodes++;
        }
        cout<<node<<" "<<nodes<<endl;
        bool comp = true;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int n = 1;
            for(int i:adj[x]){
                if(!vis[i]){
                    vis[i] = 1;
                    comp = false;
                    q.push(i);
                }
                n++;
            }
            if(n!=nodes) comp = false;
        }
        return comp;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(completebsf(i,adj,vis)){
                    count++;
                }
            }
        }
        return count;
    }
};