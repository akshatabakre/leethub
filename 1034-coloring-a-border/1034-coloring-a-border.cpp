class Solution {
public:
    vector<vector<int>> mark;
    vector<vector<int>> vis,grid;
    int n,m,row,col;
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {-1,1,0,0};

    bool valid(int x,int y){
        return (x>=0 && x<n && y>=0 && y<m && grid[x][y]==grid[row][col]);
    }
    void dfs(int x,int y){
        vis[x][y] = 1;
        bool flag = false;
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(!valid(nx,ny)){
                flag = true;
            }else{
                if(!vis[nx][ny])
                    dfs(nx,ny);
            }
        }
        if(flag){
            mark[x][y] = 1;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        this->grid = grid;
        this->row = row;
        this->col = col;
        mark.resize(n,vector<int>(m,0));
        vis.resize(n,vector<int>(m,0));
        dfs(row,col);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mark[i][j]){
                    ans[i][j] = color;
                }else{
                    ans[i][j] = grid[i][j];
                }
            }
        }
        return ans;
    }
};