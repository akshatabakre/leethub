class Solution {
public:
long long dp[100100][3][3];
    long long solve(int i,int col1,int col2,vector<vector<int>>& cost,int n){
        #define int long long
        if(i>n-i-1){
            return 0LL;
        }
        if((col1!=-1 && col2!=-1) && dp[i][col1][col2]!=-1){
            return dp[i][col1][col2];
        }
        int mini = 1e18;
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(x==y || x==col1 || y==col2)    continue;
                mini = min(cost[i][x]+cost[n-i-1][y]+solve(i+1,x,y,cost,n),mini);
            }
        }
        if(col1==-1 && col2==-1){
            return mini;
        }
        return dp[i][col1][col2] = mini;
        #undef int
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,-1,cost,n);
    }
};