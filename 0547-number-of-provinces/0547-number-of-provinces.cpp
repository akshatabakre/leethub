class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>& vis){
        for(int i=0;i<isConnected[node].size();i++){
            if(isConnected[node][i] && !vis[i]){
                vis[i] = 1;
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};