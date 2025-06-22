class Solution {
public:
    int ways(int amt,vector<int>& coins){
        int n = coins.size();
        if(n==0)        return 0;
        vector<vector<int>> dp(n,vector<int>(amt+1,0));
        for(int a=1;a<=amt;a++){
            if(a%coins[0]==0){
                dp[0][a] = 1;
            }
        }
        for(int i=0;i<n;i++)    dp[i][0] = 1;
        for(int i=1;i<n;i++){
            for(int a=1;a<=amt;a++){
                int nottake = dp[i-1][a];
                int take = 0;
                if(a>=coins[i]){
                    take = dp[i][a-coins[i]];
                }
                dp[i][a] = nottake + take;
            }
        }
        return dp[n-1][amt];
    }
    vector<int> findCoins(vector<int>& numWays) {
        if (numWays.empty()) return {};
        vector<int> coins;
        if(numWays[0]==1){
            coins.push_back(1);
        }else if(numWays[0]>1){
            return {};
        }
        int n = numWays.size();
        for(int i=1;i<n;i++){
            int w = ways(i+1,coins);
            cout<<i+1<<" "<<w<<endl;
            if(w==numWays[i]){
                continue;
            }else if(w+1==numWays[i]){
                coins.push_back(i+1);
            }else{
                return {};
            }
        }
        return coins;
    }
};