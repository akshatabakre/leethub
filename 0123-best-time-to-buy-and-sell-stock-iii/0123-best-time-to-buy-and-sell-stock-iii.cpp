class Solution {
public:
    // int akshata(int ind,int canbuy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
    //     if(cap==0){
    //         return 0;
    //     }
    //     if(ind==prices.size()){
    //         return 0;
    //     }
    //     if(dp[ind][canbuy][cap]!=-1){
    //         return dp[ind][canbuy][cap];
    //     }
    //     if(canbuy){
    //         return dp[ind][canbuy][cap] = max(-prices[ind]+akshata(ind+1,0,cap,prices,dp),akshata(ind+1,1,cap,prices,dp));
    //     }else{
    //         return dp[ind][canbuy][cap] = max(prices[ind]+akshata(ind+1,1,cap-1,prices,dp),akshata(ind+1,0,cap,prices,dp));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return akshata(0,1,2,prices,dp);
        //base cases -> for cap==0, dp = 0 && for ind==n, dp=0
        //space optimization -> to a 2D DP
        vector<vector<int>> v(2,vector<int>(3,0)),c(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=1;cap<3;cap++){
                    if(buy){
                        c[buy][cap] = max(-prices[ind]+v[0][cap],v[1][cap]);
                    }else{
                        c[buy][cap] = max(prices[ind]+v[1][cap-1],v[0][cap]);
                    }
                }
                v=c;
            }
        }
        return v[1][2];
    }
};