class Solution {
public:

    bool topo(vector<vector<int>>&adj,set<int>&s){
        vector<int> indegree(61,0);
        for(auto i:s){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=1;i<=60;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int col = q.front();
            q.pop();

            cnt++;

            for(int i:adj[col]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        return (cnt==60);
    }

    bool isPrintable(vector<vector<int>>& targetGrid) {
        int n = targetGrid.size(), m = targetGrid[0].size();
        vector<vector<int>> adj(61);

        set<int> s;

        for(int c=1;c<=60;c++){
            int minx = 1e9, miny = 1e9, maxx = -1, maxy = -1;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(targetGrid[i][j]==c){
                        s.insert(c);
                        minx = min(minx,i);
                        miny = min(miny,j);
                        maxx = max(i,maxx);
                        maxy = max(j,maxy);
                    }
                }
            }

            for(int i=minx;i<=maxx;i++){
                for(int j=miny;j<=maxy;j++){
                    if(targetGrid[i][j]!=c){
                        adj[c].push_back(targetGrid[i][j]);
                    }
                }
            }
        }
        
        
        return topo(adj,s);
    }
};