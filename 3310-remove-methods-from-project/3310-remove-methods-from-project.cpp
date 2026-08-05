class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> mark(n,0),vis(n,0);
        vector<vector<int>> adj(n);
        for(auto it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = 1;
            mark[node] = 1;
            for(int i:adj[node]){
                if(!vis[i])
                    q.push(i);
            }
        }

        vis.assign(n,0);

        bool returnall = false;
        for(int i=0;i<n;i++){
            if(!mark[i]){
                cout<<i<<" ";
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    vis[node] = 1;
                    if(mark[node]){
                        returnall = true;
                    }
                    for(int j:adj[node]){
                        if(!vis[j]){
                            q.push(j);
                        }
                    }
                }

            }
        }
        vector<int> ans;
        if(returnall){
            for(int i=0;i<n;i++)    ans.push_back(i);
            return ans;
        }
        for(int i=0;i<n;i++){
            if(!mark[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};