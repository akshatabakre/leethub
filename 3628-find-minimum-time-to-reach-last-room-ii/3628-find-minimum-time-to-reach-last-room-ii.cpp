class Solution {
public:
    bool isValid(int nx,int ny,int n,int m){
        return (nx>=0 && ny>=0 && nx<n && ny<m);
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // {timer,x,y,1}->{0,0,0,1}
        priority_queue<vector<int>,
                vector<vector<int>>,
                greater<vector<int>>> pq;
        pq.push({0,0,0,1});
        int n = moveTime.size(),m = moveTime[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        dist[0][0] = 0;
        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            int t = pq.top()[0];
            int step = pq.top()[3];
            pq.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(!isValid(nx,ny,n,m)){
                    continue;
                }
                int timer = max(t,moveTime[nx][ny]);
                if(dist[nx][ny]>step+timer){
                    dist[nx][ny] = step + timer;
                    pq.push({dist[nx][ny],nx,ny,(3^step)});
                }
            }
        }
        return dist[n-1][m-1];
    }
};