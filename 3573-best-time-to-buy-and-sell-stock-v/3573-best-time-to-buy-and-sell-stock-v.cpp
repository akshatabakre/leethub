class Solution {
public:
    long long  dp[1001][3][1001]; 
    long long solve(int i,int status,int k,vector<int>& prices){
        if(i>=prices.size()){
            return 0;
        }
        if (i == prices.size() - 1) {
            if (status == 1) return prices[i];
            if (status == 0) return -prices[i];
            return 0;
        }
        if(k==0){
            return 0;
        }
        if (dp[i][status][k] != -1) return dp[i][status][k];
        if(status==2){
            return dp[i][status][k]=max({solve(i+1,status,k,prices),prices[i]+solve(i+1,0,k,prices),-prices[i]+solve(i+1,1,k,prices)});
        }
        if(status==0){
            return dp[i][status][k]=max(-prices[i]+solve(i+1,2,k-1,prices),solve(i+1,status,k,prices));
        }
        if(status==1){
            return dp[i][status][k]=max(prices[i]+solve(i+1,2,k-1,prices),solve(i+1,status,k,prices));

        }
        return 0;
    }
    long long maximumProfit(vector<int>& prices, int k) {
         memset(dp, -1, sizeof(dp));
        return solve(0,2,k,prices);
        
    }
};