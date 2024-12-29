class Solution {
public:
    int akshata(int ind,int canbuy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(cap==0){
            return 0;
        }
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][canbuy][cap]!=-1){
            return dp[ind][canbuy][cap];
        }
        if(canbuy){
            return dp[ind][canbuy][cap] = max(-prices[ind]+akshata(ind+1,0,cap,prices,dp),akshata(ind+1,1,cap,prices,dp));
        }else{
            return dp[ind][canbuy][cap] = max(prices[ind]+akshata(ind+1,1,cap-1,prices,dp),akshata(ind+1,0,cap,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return akshata(0,1,2,prices,dp);
    }
};