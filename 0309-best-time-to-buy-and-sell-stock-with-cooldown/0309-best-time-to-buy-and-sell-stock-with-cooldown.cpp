class Solution {
public:
    // int solve(int i,int b,vector<int>& pr,vector<vector<int>>& dp){
    //     if(i>=pr.size()){
    //         return 0;
    //     }
    //     if(dp[i][b]!=-1){
    //         return dp[i][b];
    //     }
    //     if(b){
    //         return dp[i][b] = max(-pr[i]+solve(i+1,0,pr,dp),solve(i+1,1,pr,dp));
    //     }
    //     return dp[i][b] = max(pr[i]+solve(i+2,1,pr,dp),solve(i+1,0,pr,dp));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        // return solve(0,1,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                if(b==1){
                    dp[i][b] = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][b] = max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};