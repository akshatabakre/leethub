class Solution {
public:
    map<int,bool> safe;
    vector<vector<int>> graph;
    vector<int> vis, pathvis;
    bool dfs(int node){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto adjnode:graph[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode)){
                    return true;
                }
            }else{
                if(pathvis[adjnode]){
                    return true;
                }
            }
        }
        pathvis[node] = 0;
        safe[node] = 1;//*
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        this->graph = graph;
        vis.resize(n,0);
        pathvis.resize(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);//*
            }
        }
        vector<int> safenodes;
        for(auto it:safe){
            safenodes.push_back(it.first);
        }
        return safenodes;
    }
};