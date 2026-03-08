class Solution {
public:
    vector<int> prices;
    vector<vector<vector<int>>> dp;
    int profit(int ind,int k,int bought){
        if(k<=0){
            return 0;
        }
        if(ind>=prices.size()){
            if(bought){
                return -1e9;
            }
            return 0;
        }
        if(dp[ind][k][bought]!=-1)  return dp[ind][k][bought];
        if(bought){
            return dp[ind][k][bought] = max(prices[ind]+profit(ind+1,k-1,false),profit(ind+1,k,bought));
        }
        return dp[ind][k][bought] = max(-prices[ind]+profit(ind+1,k,true),profit(ind+1,k,bought));
    }
    int maxProfit(int k, vector<int>& prices) {
        this->prices = prices;
        dp.resize(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return profit(0,k,false);
    }
};