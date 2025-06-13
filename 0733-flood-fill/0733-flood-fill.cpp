class Solution {
public:
    bool isValid(int a,int b,int m,int n){
        return (a>=0 && b>=0 && a<m && b<n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int prevcol = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        while(!q.empty()){
            auto it = q.front();
            int x = it.first, y = it.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isValid(nx,ny,m,n) && !vis[nx][ny] && image[nx][ny]==prevcol){
                    vis[nx][ny] = 1;
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};