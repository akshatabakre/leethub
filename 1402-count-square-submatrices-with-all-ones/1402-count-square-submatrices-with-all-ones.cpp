class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    dp[i][j] = 1;
                    if(i>0 && j>0){
                        dp[i][j] += min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};