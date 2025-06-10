class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& obs,vector<vector<int>>& dp){
        if(obs[i][j]){
            return dp[i][j] = 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        int up = 0, left = 0;
        if(i>0){
            up = solve(i-1,j,obs,dp);
        }
        if(j>0){
            left = solve(i,j-1,obs,dp);
        }
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size(), n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obs,dp);
    }
};