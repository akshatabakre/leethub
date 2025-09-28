class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string&s,string&t,int n1,int n2){
        if(j==n2){
            return (n1-i);
        }
        if(i==n1){
            return (n2-j);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j] = solve(i+1,j+1,s,t,n1,n2);
        }
        return dp[i][j] = 1 + min(solve(i+1,j+1,s,t,n1,n2),min(solve(i+1,j,s,t,n1,n2),solve(i,j+1,s,t,n1,n2)));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        dp.resize(n1,vector<int>(n2,-1));
        return solve(0,0,word1,word2,n1,n2);
    }
};