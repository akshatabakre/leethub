class Solution {
public:
    bool isvalid(int nx,int ny,int row,int col){
        return (nx>=0 && ny>=0 && nx<row && ny<col);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> dist(row,vector<int>(col,1e9));
        dist[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        //x,y,d
        pq.push({0,0,0});
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        while(!pq.empty()){
            int x = pq.top()[0], y = pq.top()[1], d = pq.top()[2];
            pq.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isvalid(nx,ny,row,col) && dist[nx][ny]>max(d,abs(heights[x][y]-heights[nx][ny]))){
                    dist[nx][ny] = max(d,abs(heights[x][y]-heights[nx][ny]));
                    pq.push({nx,ny,dist[nx][ny]});
                }
            }
        }
        return dist[row-1][col-1];
    }
};