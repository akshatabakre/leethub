class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = -grid[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int ind = upper_bound(grid[i].begin(),grid[i].end(),0) - grid[i].begin();
            ans += (m-ind);
        }
        return ans;
    }
};