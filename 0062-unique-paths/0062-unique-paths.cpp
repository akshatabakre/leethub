class Solution {
public:
int m,n;
vector<vector<int>>dp;
    int ways(int i,int j){
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = ways(i+1,j)+ways(i,j+1);
    }
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        dp.resize(m,vector<int>(n,-1));
        return ways(0,0);
    }
};