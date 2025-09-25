class Solution {
public:
vector<vector<int>> vis;
vector<vector<int>> grid;
vector<int> dx, dy;
int m,n;
    bool isvalid(int a,int b){
        return (a>=0 && b>=0 && a<m && b<n);
    }
    void dfs(int x,int y){
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isvalid(nx,ny) && !vis[nx][ny] && grid[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // if(grid.empty() || grid[0].empty()) return 0;
        this->m = grid.size(), this->n = grid[0].size();
        dx = {0,-1,0,1};
        dy = {-1,0,1,0};
        this->grid = grid;
        vis.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]){
                dfs(i,0);
            }
            if(grid[i][n-1]){
                dfs(i,n-1);
            }
        }
        for(int j=1;j<n-1;j++){
            if(grid[0][j])  dfs(0,j);
            if(grid[m-1][j])    dfs(m-1,j);
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};