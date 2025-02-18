class Solution {
public:
    int solve(int ind,int amount,vector<int>& coins,vector<vector<int>>& memo){
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[0];
            }
            return 1e9;
        }
        if(memo[ind][amount]!=-1)   return memo[ind][amount];
        int take = 1e9, nottake = 0;
        if(amount>=coins[ind]){
            take = 1 + solve(ind,amount-coins[ind],coins,memo);
        }
        nottake = solve(ind-1,amount,coins,memo);
        return memo[ind][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)   return 0;
        vector<vector<int>> memo(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(coins.size()-1,amount,coins,memo);
        if (ans>=1e9)   return -1;
        return ans;
    }
};