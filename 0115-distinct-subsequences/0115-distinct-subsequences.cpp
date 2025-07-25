class Solution {
public:
    int mod = 1e9 + 7;
    // int func(int i,int j,string& s,string& t,vector<vector<int>>& dp){
    //     if(j<0){
    //         return 1;
    //     }
    //     if(i<0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i]==t[j]){
    //         return dp[i][j] = func(i-1,j-1,s,t,dp) + func(i-1,j,s,t,dp);
    //     }
    //     return dp[i][j] = func(i-1,j,s,t,dp);
    // }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        //MEMOIZATION
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return func(n-1,m-1,s,t,dp);
        //TABULATION
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<n;i++)    dp[i][0] = 1;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
        //         }else{
        //             dp[i][j] = dp[i-1][j]%mod;
        //         }
        //     }
        // }
        // return dp[n][m];
        // SPACE OPTIMIZATION
        vector<int> v(m+1,0);
        v[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    v[j]=(v[j]+v[j-1])%mod;
                }
            }
        }
        return v[m];
    }
};