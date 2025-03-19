class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int maxtime = 0;
        while(!q.empty()){
            int x = q.front().first.first, y = q.front().first.second, t = q.front().second;
            maxtime = max(t,maxtime);
            q.pop();
            for(int i=-1;i<=1;i++){
                if(x+i>=0 && x+i<m){
                    if(!vis[x+i][y] && grid[x+i][y]==1){
                        vis[x+i][y] = 1;
                        q.push({{x+i,y},t+1});
                        grid[x+i][y] = 2;
                    }
                }
                if(y+i>=0 && y+i<n){
                    if(!vis[x][y+i] && grid[x][y+i]==1){
                        vis[x][y+i] = 1;
                        q.push({{x,y+i},t+1});
                        grid[x][y+i] = 2;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maxtime;
    }
};