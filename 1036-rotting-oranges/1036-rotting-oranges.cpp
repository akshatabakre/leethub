class Solution {
public:
    bool isvalid(int a,int b,int n,int m){
        return (a>=0 && b>=0 && a<n && b<m);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int timer = 0;
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        while(!q.empty()){
                auto curr = q.front();
                int x = curr.first.first, y = curr.first.second;
                int t = curr.second;
                q.pop();
                timer = max(t,timer);
                for(int i=0;i<4;i++){
                    int nx = x+dx[i], ny = y + dy[i];
                    if(isvalid(nx,ny,n,m) && !vis[nx][ny] && grid[nx][ny]==1){
                        q.push({{nx,ny},t+1});
                        vis[nx][ny] = 1;
                    }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return timer;
    }
};