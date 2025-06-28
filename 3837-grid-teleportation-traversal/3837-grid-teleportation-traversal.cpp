class Solution {
public:
    bool isValid(int r,int c,int m,int n,vector<string>& mat){
        return (r>=0 && r<m && c>=0 && c<n && mat[r][c]!='#');
    }
    int minMoves(vector<string>& matrix) {
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;//dist,coord
        int m = matrix.size(), n = matrix[0].size();


        vector<vector<pair<int,int>>> alphacoords(26);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]>='A' && matrix[i][j]<='Z'){
                    alphacoords[matrix[i][j]-'A'].push_back({i,j});
                }
            }
        }

        vector<vector<int>> distance(m,vector<int>(n,1e9));
        distance[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x==m-1 && y==n-1){
                return dist;
            }

            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isValid(nx,ny,m,n,matrix)){
                    if(1+dist<distance[nx][ny]){
                        distance[nx][ny] = 1 + dist;
                        pq.push({1+dist,{nx,ny}});
                    }
                }
            }
            if(matrix[x][y]>='A' && matrix[x][y]<='Z'){
                if(!alphacoords[matrix[x][y]-'A'].empty()){
                    for(auto it:alphacoords[matrix[x][y]-'A']){
                        pq.push({dist,it});
                    }
                    alphacoords[matrix[x][y]-'A'].clear();
                }
            }
        }
        return -1;
    }
};