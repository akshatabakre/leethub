class Solution {
public:
    bool isValid(int r,int c,int m,int n){
        return (r>=0 && c>=0 && r<m && c<n);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        deque<pair<int,int>> dq;//r,c
        dq.push_back({0,0});
        dist[0][0] = 0;
        //i -> direction
        int dr[] = {0,0,0,1,-1};
        int dc[] = {0,1,-1,0,0};
        while(!dq.empty()){
            auto it = dq.front();
            int r = it.first, c = it.second;
            dq.pop_front();
            for(int i=1;i<=4;i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(isValid(nr,nc,m,n)){
                    if(grid[r][c]==i && dist[nr][nc] > dist[r][c]){
                        dist[nr][nc] = dist[r][c];
                        dq.push_front({nr,nc});
                    }else if(dist[nr][nc] > 1 + dist[r][c]){
                        dist[nr][nc] = dist[r][c] + 1;
                        dq.push_back({nr,nc});
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {for(int j=0;j<n;j++)
        {cout<<dist[i][j]<<" ";}    cout<<endl; }
        if(dist[m-1][n-1]==1e9)     return -1;
        return dist[m-1][n-1];
    }
};