class Solution {
public:
    bool isValid(int nx,int ny,int n){
        return (nx>=0 && ny>=0 && nx<n && ny<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> minTime(n,vector<int>(n,1e9));
        minTime[0][0] = grid[0][0];
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({grid[0][0],{0,0}});
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!pq.empty()){
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isValid(nx,ny,n) && max(t,grid[nx][ny]) < minTime[nx][ny]){
                    minTime[nx][ny] = max(t,grid[nx][ny]);
                    pq.push({minTime[nx][ny],{nx,ny}});
                }
            }
        }
        return minTime[n-1][n-1];
    }
};