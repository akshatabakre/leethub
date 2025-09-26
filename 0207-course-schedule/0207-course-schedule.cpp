class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int adjnode:adj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode]==0){
                    q.push(adjnode);
                }
            }
        }
        return (topo.size()==n);
    }
};