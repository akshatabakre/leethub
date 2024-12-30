class Solution {
public:
    // int solve(int ind, int tr,int& maxtr,vector<int>& pr,vector<vector<int>>& dp){
    //     if(ind==pr.size()||tr==maxtr){
    //         return 0;
    //     }
    //     if(dp[ind][tr]!=-1){
    //         return dp[ind][tr];
    //     }
    //     if(tr%2==0){
    //         return dp[ind][tr] = max(-pr[ind]+solve(ind+1,tr+1,maxtr,pr,dp),solve(ind+1,tr,maxtr,pr,dp));
    //     }
    //     return dp[ind][tr] = max(pr[ind]+solve(ind+1,tr+1,maxtr,pr,dp),solve(ind+1,tr,maxtr,pr,dp));
    // }
    int maxProfit(int k, vector<int>& prices) {
        int maxtr = 2*k, n = prices.size();;
        // vector<vector<int>> dp(n+1,vector<int>(maxtr+1,0));
        // return solve(0,0,maxtr,prices,dp);
        vector<int> v(maxtr+1,0),cur(maxtr+1,0);
        for(int i=n-1;i>=0;i--){
            for(int t=maxtr-1;t>=0;t--){
                if(t%2==0){
                    cur[t] = max(-prices[i]+v[t+1],v[t]);
                }else{
                    cur[t] = max(prices[i]+v[t+1],v[t]);
                }
            }
            v=cur;
        }
        return v[0];
    }
};