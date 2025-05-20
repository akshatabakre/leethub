class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //using bfs (kahns algo/topological sort)
        //step 1 - reverse edges
        int n = graph.size();
        vector<int> indegree(n,0),safe;
        vector<vector<int>> reverse(n);
        for(int i=0;i<graph.size();i++){
            for(int j:graph[i]){
                reverse[j].push_back(i);
                indegree[i]++;
            }
        }
        //step 2 - topo sort on reverse
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(int i:reverse[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};