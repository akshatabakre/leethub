class Solution {
public:
    bool isValid(int r,int c,int n){
        return (r>=0 && c>=0 && r<n && c<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[] = {0,1,1,1,0,-1,-1,-1};
        int dy[] = {1,1,0,-1,-1,-1,0,1};
        int n = grid.size();
        vector<vector<int>> D(n,vector<int>(n,1e9));
        if(!grid[0][0])     D[0][0] = 0;
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        if(!grid[0][0])     pq.push({0,{0,0}});
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();
            for(int i=0;i<8;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isValid(nx,ny,n) && !grid[nx][ny] && 1+d<D[nx][ny]){
                    D[nx][ny] = 1 + d;
                    pq.push({1+d,{nx,ny}});
                }
            }
        }
        if(D[n-1][n-1]==1e9)    return -1;
        return D[n-1][n-1]+1;
    }
};