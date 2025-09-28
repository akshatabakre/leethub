class Solution {
public:
    int solve(int i,int j,string& s1,string&s2,int n1,int n2,vector<vector<int>>&dp){
        if(i>=n1 || j>=n2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + solve(i+1,j+1,s1,s2,n1,n2,dp);
        }
        return dp[i][j] = max(solve(i+1,j,s1,s2,n1,n2,dp),solve(i,j+1,s1,s2,n1,n2,dp));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int lcs = solve(0,0,word1,word2,n1,n2,dp);
        return (n1+n2-2*lcs);
    }
};