class Solution {
public:
    int maxprofit(int ind,int canbuy,vector<int>& prices,vector<vector<int>>& dp){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][canbuy]!=-1){
            return dp[ind][canbuy];
        }
        if(canbuy){
            return dp[ind][canbuy] = max(-prices[ind]+maxprofit(ind+1,0,prices,dp),maxprofit(ind+1,1,prices,dp));
        }else{
            return dp[ind][canbuy] = max(prices[ind]+maxprofit(ind+1,1,prices,dp),maxprofit(ind+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxprofit(0,1,prices,dp);
    }
};