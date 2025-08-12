class Solution {
public:
    int MOD = 1e9 + 7;
    int ways(int num,int sum,int x,int n,vector<vector<int>>& dp){
        if(sum>n){
            return 0;
        }
        if(pow(num,x)>n){
            if(sum==n){
                return 1;
            }
            return 0;
        }
        if(dp[num][sum]!=-1){
            return dp[num][sum];
        }
        return dp[num][sum] = (ways(num+1,sum+pow(num,x),x,n,dp) + ways(num+1,sum,x,n,dp))%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return ways(1,0,x,n,dp)%MOD;
    }
};