class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        //do BFS
        while(!q.empty()){
            int r = q.front().first.first, c = q.front().first.second, t = q.front().second;
            q.pop();
            //check for 4 directions
            if(r-1>=0 && r-1<m){
                if(!vis[r-1][c]){
                    vis[r-1][c] = 1;
                    ans[r-1][c] = t+1;
                    q.push({{r-1,c},t+1});
                }
            }
            if(r+1>=0 && r+1<m){
                if(!vis[r+1][c]){
                    vis[r+1][c] = 1;
                    ans[r+1][c] = t+1;
                    q.push({{r+1,c},t+1});
                }
            }
            if(c-1>=0 && c-1<n){
                if(!vis[r][c-1]){
                    vis[r][c-1] = 1;
                    ans[r][c-1] = t+1;
                    q.push({{r,c-1},t+1});
                }
            }
            if(c+1>=0 && c+1<n){
                if(!vis[r][c+1]){
                    vis[r][c+1] = 1;
                    ans[r][c+1] = t+1;
                    q.push({{r,c+1},t+1});
                }
            }
        }
        return ans;
    }
};