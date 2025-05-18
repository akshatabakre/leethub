class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            topo.push_back(x);
            q.pop();
            for(int i:adj[x]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(topo.size()!=n){
            return {};
        }
        return topo;
    }
};