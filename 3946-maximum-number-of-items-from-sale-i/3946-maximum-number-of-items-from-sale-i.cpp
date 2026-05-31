class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int b,vector<vector<int>>&items,vector<int>&free){
        if(i==items.size()){
            return 0;
        }
        if(dp[i][b]!=-1){
            return dp[i][b];
        }
        int ans = 0;
        ans = solve(i+1,b,items,free);
        if(b>=items[i][1]){
            ans = max(ans,1+solve(i,b-items[i][1],items,free));
            if(free[i]>=1){
                ans = max(ans,1+free[i]+solve(i+1,b-items[i][1],items,free));
            }
        }
        return dp[i][b] = ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free(n,0);
        dp.resize(n,vector<int>(budget+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)    continue;
                if(items[j][0]%items[i][0]==0){
                    free[i]++;
                }
            }
        }
        return solve(0,budget,items,free);
    }
};