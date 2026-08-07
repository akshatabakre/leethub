class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        int q = queries.size();
        for(int i=0;i<q;i++){
            int x1 = queries[i][0], y1 = queries[i][1];
            int x2 = queries[i][2], y2 = queries[i][3];
            for(int r=x1;r<=x2;r++){
                grid[r][y1]++;
                if(y2+1<n){
                    grid[r][y2+1]--;
                }
            }
        }
        for(int r=0;r<n;r++){
            for(int c=1;c<n;c++){
                grid[r][c] += grid[r][c-1];
            }
        }
        return grid;
    }
};