class Solution {
public:
//using recursion
    // int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
    //     if(i==0 && j==0){
    //         return grid[0][0];
    //     }
    //     if(i<0 || j<0){
    //         return INT_MAX;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int up = f(i-1,j,grid,dp);
    //     int left = f(i,j-1,grid,dp);
    //     return dp[i][j] = grid[i][j] + min(up,left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // dp[0][0] = grid[0][0];
        // return f(m-1,n-1,grid,dp);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0){
        //             dp[i][j] = grid[0][0];
        //             continue;
        //         }
        //         int up = INT_MAX, left = INT_MAX;
        //         if(i>0){
        //             up = dp[i-1][j];
        //         }
        //         if(j>0){
        //             left = dp[i][j-1];
        //         }
        //         dp[i][j] = grid[i][j] + min(up,left);
        //     }
        // }
        // return dp[m-1][n-1];

        //space optimization
        vector<int> v(n);
        //base case initialization
        v[0] = grid[0][0];
        for(int i=1;i<n;i++){
            v[i] = v[i-1] + grid[0][i];
        }
        for(int i=1;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int up = v[j],left = INT_MAX;
                if(j>0){
                    left = temp[j-1];
                }
                temp[j] = grid[i][j] + min(up,left);
            }
            v = temp;
        }
        return v[n-1];
    }
};