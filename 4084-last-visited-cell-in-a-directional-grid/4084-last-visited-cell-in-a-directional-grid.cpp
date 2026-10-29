class Solution {
public:
    pair<int,int> coords(int r,int c,vector<vector<char>>& grid){
        if(grid[r][c]=='L'){
            c--;
        }else if(grid[r][c]=='R'){
            c++;
        }else if(grid[r][c]=='U'){
            r--;
        }else{
            r++;
        }
        return {r,c};
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int r = 0, c = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(true){
            vis[r][c] = 1;
            auto it = coords(r,c,grid);
            int nr = it.first;
            int nc = it.second;
            if(nr<0 || nc<0 || nr>=n || nc>=m || vis[nr][nc]){
                break;
            }
            r = nr, c = nc;
        }
        return {r,c};
    }
};