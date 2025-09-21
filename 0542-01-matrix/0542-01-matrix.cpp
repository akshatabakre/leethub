class Solution {
public:
    bool isvalid(int a,int b,int m,int n){
        return (a>=0 && b>=0 && a<m && b<n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<vector<int>> q;//x,y,d
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it[0], y = it[1], d = it[2];
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isvalid(nx,ny,m,n) && !vis[nx][ny]){
                    q.push({nx,ny,d+1});
                    ans[nx][ny] = d+1;
                    vis[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};