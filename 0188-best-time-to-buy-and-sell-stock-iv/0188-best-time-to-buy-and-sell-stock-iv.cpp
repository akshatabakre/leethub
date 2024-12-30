class Solution {
public:
    int solve(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(ind==prices.size()||cap==0){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        if(buy){
            return dp[ind][buy][cap] = max(-prices[ind]+solve(ind+1,0,cap,prices,dp),solve(ind+1,1,cap,prices,dp));
        }
        return dp[ind][buy][cap] = max(prices[ind]+solve(ind+1,1,cap-1,prices,dp),solve(ind+1,0,cap,prices,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // return solve(0,1,k,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<2;b++){
                for(int c=1;c<k+1;c++){
                    if(b==1){
                        dp[i][b][c] = max(-prices[i]+dp[i+1][0][c],dp[i+1][1][c]);
                    }else{
                        dp[i][b][c] = max(prices[i]+dp[i+1][1][c-1],dp[i+1][0][c]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};