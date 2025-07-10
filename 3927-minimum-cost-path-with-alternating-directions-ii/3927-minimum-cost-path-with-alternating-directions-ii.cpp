class Solution {
public:
    long long solve(int i,int j,int m,int n,vector<vector<int>>& waitCost,vector<vector<long long>>& dp){
        #define int long long
        if(i==m-1 && j==n-1){
            return (i+1)*(j+1);
        }
        if(i>=m || j>=n){
            return 1e18;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int cost = (i+1)*(j+1);
        if(i || j){
            cost += waitCost[i][j];
        }
        cost += min(solve(i+1,j,m,n,waitCost,dp),solve(i,j+1,m,n,waitCost,dp));
        return dp[i][j] = cost;
        #undef int
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        #define int long long
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,waitCost,dp);
        #undef int
    }
};