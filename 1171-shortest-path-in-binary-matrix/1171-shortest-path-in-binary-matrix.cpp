class Solution {
public:
    bool isvalid(int nx,int ny,int n){
        return (nx>=0 && ny>=0 && nx<n && ny<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        int dx[] = {-1,-1,-1,0,0,1,1,1}, dy[] = {-1,0,1,-1,1,-1,0,1};
        queue<vector<int>> q;//x,y,d
        if(grid[0][0]==0){
            q.push({0,0,1});
            dist[0][0] = 1;
        }
        while(!q.empty()){
            int x = q.front()[0], y = q.front()[1], d = q.front()[2];
            q.pop();
            for(int i=0;i<8;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isvalid(nx,ny,n) && grid[nx][ny]==0 && dist[nx][ny]>1+d){
                    dist[nx][ny] = 1 + d;
                    q.push({nx,ny,d+1});
                }
            }
        }
        if(dist[n-1][n-1]==1e9){
            return -1;
        }
        return dist[n-1][n-1];
    }
};