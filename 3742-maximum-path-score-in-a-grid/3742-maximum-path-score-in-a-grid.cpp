class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,int k){
        if(i>=grid.size() || j>=grid[0].size()){
            
            return -1e9;
        }
        int c = 0;
        if(grid[i][j]){
            c = 1;
        }
        k-=c;
        if(k<0){
            return -1e9;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            // if(k==0){
            //     if(grid[i][j]){
            //         return -1e9;
            //     }
            //     return 0;
            // }
            return grid[grid.size()-1][grid[0].size()-1];
            // return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        // int c = 0;
        // if(grid[i][j]){
        //     c = 1;
        // }
        return dp[i][j][k] = grid[i][j] + max(solve(i+1,j,k),solve(i,j+1,k));
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        int m = grid.size(), n = grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans = solve(0,0,k);
        if(ans<0){
            return -1;
        }
        return ans;
    }
};
