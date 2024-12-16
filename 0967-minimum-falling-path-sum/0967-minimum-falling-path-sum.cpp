class Solution {
public:
    int f(int i,int j,vector<vector<int>>& a,int n,vector<vector<int>>&dp){
        if(j<0 || j>=n){
            return 1e6;
        }
        if(i==0){
            return dp[i][j] = a[0][j];
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        int ld = a[i][j] + f(i-1,j-1,a,n,dp);
        int up = a[i][j] + f(i-1,j,a,n,dp);
        int rd = a[i][j] + f(i-1,j+1,a,n,dp);
        int ur = min(up,rd);
        return dp[i][j] = min(ld,ur);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans = 1e6;
        vector<vector<int>> dp(n,vector<int> (n,0));
        // for(int i=0;i<n;i++){
        //     ans = min(ans,f(n-1,i,matrix,n,dp));
        // }
        // return ans;
        //base case
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int ld = 1e6,rd = 1e6, up;
                if(j>0)
                    ld = matrix[i][j] + dp[i-1][j-1];
                up = matrix[i][j] + dp[i-1][j];
                if(j<n-1)
                    rd = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(up,min(ld,rd));
            }
        }
        int ans = 1e6;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};