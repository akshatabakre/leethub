class Solution {
public:
vector<vector<int>> dp;
    vector<vector<int>> triangle;
    int r;
    int solve(int row,int col){
        if(row==r){
            return 0;
        }
        if(dp[row][col]!=1e9){
            return dp[row][col];
        }
        return dp[row][col] = triangle[row][col]+min(solve(row+1,col),solve(row+1,col+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        this->r = triangle.size();
        this->triangle = triangle;
        dp.resize(r,vector<int>(r,1e9));
        return solve(0,0);
    }
};