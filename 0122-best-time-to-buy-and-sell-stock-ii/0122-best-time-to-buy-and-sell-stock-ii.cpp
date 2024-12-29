class Solution {
public:
    // int maxprofit(int ind,int canbuy,vector<int>& prices,vector<vector<int>>& dp){
    //     if(ind==prices.size()){
    //         return 0;
    //     }
    //     if(dp[ind][canbuy]!=-1){
    //         return dp[ind][canbuy];
    //     }
    //     if(canbuy){
    //         return dp[ind][canbuy] = max(-prices[ind]+maxprofit(ind+1,0,prices,dp),maxprofit(ind+1,1,prices,dp));
    //     }else{
    //         return dp[ind][canbuy] = max(prices[ind]+maxprofit(ind+1,1,prices,dp),maxprofit(ind+1,0,prices,dp));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return maxprofit(0,1,prices,dp);
        // dp[n][0]=0,dp[n][1]=0;
        int v1 = 0, v2 = 0;
        for(int ind=n-1;ind>=0;ind--){
            int a = v1, b = v2;
            v1 = max(prices[ind]+b,a);
            v2 = max(-prices[ind]+a,b);
        }
        return v2;
    }
};