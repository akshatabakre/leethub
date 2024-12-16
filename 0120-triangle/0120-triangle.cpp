class Solution {
public:
    // int f(int i,int j,vector<vector<int>>& t,int n,vector<vector<int>>& dp){
    //     if(i==n-1){
    //         return t[n-1][j];
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int d = f(i+1,j,t,n,dp);
    //     int dg = f(i+1,j+1,t,n,dp);
    //     return dp[i][j] = t[i][j] + min(d,dg);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        // return f(0,0,triangle,n,dp);

        //tabulation
        //base case implementation
        // for(int i=0;i<n;i++){
        //     dp[n-1][i] = triangle[n-1][i];
        // }
        // for(int i=n-2;i>=0;i--){//row
        //     for(int j=0;j<=i;j++){
        //         dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
        //     }
        // }
        // return dp[0][0];

        //space optimization
        vector<int> v(n);
        //base case implementation
        for(int i=0;i<n;i++)
            v[i] = triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            vector<int> temp(n);
            for(int j=0;j<=i;j++){
                temp[j] = triangle[i][j] + min(v[j],v[j+1]);
            }
            v = temp;
        }
        return v[0];
    }
};