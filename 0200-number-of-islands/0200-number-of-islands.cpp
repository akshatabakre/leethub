class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& vis,int n,int m){
        vis[x][y] = 1;
        if(x>=1){
            if(grid[x-1][y]=='1' && !vis[x-1][y]){
                dfs(x-1,y,grid,vis,n,m);
            }
        }
        if(x<n-1){
            if(grid[x+1][y]=='1' && !vis[x+1][y]){
                dfs(x+1,y,grid,vis,n,m);
            }
        }
        if(y>=1){
            if(grid[x][y-1]=='1' && !vis[x][y-1]){
                dfs(x,y-1,grid,vis,n,m);
            }
        }
        if(y<m-1){
            if(grid[x][y+1]=='1' && !vis[x][y+1]){
                dfs(x,y+1,grid,vis,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int islands = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    islands++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return islands;
    }
};