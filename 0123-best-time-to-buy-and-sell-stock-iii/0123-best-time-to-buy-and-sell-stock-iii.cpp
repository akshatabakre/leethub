class Solution {
public:
    int solve(int ind,int transaction,vector<int>& prices,vector<vector<int>>& dp){
        if(ind == prices.size() || transaction==4){
            return 0;
        }
        if(dp[ind][transaction]!=-1){
            return dp[ind][transaction];
        }
        if(transaction%2==0){
            return dp[ind][transaction] = max(-prices[ind]+solve(ind+1,transaction+1,prices,dp),solve(ind+1,transaction,prices,dp));
        }else{
            return dp[ind][transaction] = max(prices[ind]+solve(ind+1,transaction+1,prices,dp),solve(ind+1,transaction,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(0,0,prices,dp);
    }
};