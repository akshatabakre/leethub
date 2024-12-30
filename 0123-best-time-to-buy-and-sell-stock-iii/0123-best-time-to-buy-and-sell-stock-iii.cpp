class Solution {
public:
    // int solve(int ind,int transaction,vector<int>& prices,vector<vector<int>>& dp){
    //     if(ind == prices.size() || transaction==4){
    //         return 0;
    //     }
    //     if(dp[ind][transaction]!=-1){
    //         return dp[ind][transaction];
    //     }
    //     if(transaction%2==0){
    //         return dp[ind][transaction] = max(-prices[ind]+solve(ind+1,transaction+1,prices,dp),solve(ind+1,transaction,prices,dp));
    //     }else{
    //         return dp[ind][transaction] = max(prices[ind]+solve(ind+1,transaction+1,prices,dp),solve(ind+1,transaction,prices,dp));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(5,0));
        // return solve(0,0,prices,dp);
        vector<int> v(5,0),c(5,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int t=0;t<4;t++){
                if(t%2==0){
                    c[t] = max(v[t+1]-prices[ind],v[t]);
                }else{
                    c[t] = max(v[t+1]+prices[ind],v[t]);
                }
            }
            v=c;
        }
        return v[0];
    }
};