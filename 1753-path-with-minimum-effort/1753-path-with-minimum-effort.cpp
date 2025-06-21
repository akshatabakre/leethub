class Solution {
public:
    bool isValid(int r,int c,int rows,int cols){
        return (r>=0 && c>=0 && r<rows && c<cols);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> minEffort(rows,vector<int>(cols,1e9));
        minEffort[0][0] = 0;
        priority_queue<
        pair<int,pair<int,int>>,//effort,x,y
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({0,{0,0}});
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        while(!pq.empty()){
            int eff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(isValid(nr,nc,rows,cols)){
                    int newEff = abs(heights[r][c]-heights[nr][nc]);
                    if(max(eff,newEff) < minEffort[nr][nc]){
                        minEffort[nr][nc] = max(eff,newEff);
                        pq.push({minEffort[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return minEffort[rows-1][cols-1];
    }
};