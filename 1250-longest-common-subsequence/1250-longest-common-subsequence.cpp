class Solution {
public:
    int n1,n2;
    string s1,s2;
    vector<vector<int>> dp;
    int lcs(int i,int j){
        if(i>=n1 || j>=n2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + lcs(i+1,j+1);
        }
        return dp[i][j] = max(lcs(i,j+1),lcs(i+1,j));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.length();
        n2 = text2.length();
        s1 = text1;
        s2 = text2;
        dp.resize(n1,vector<int>(n2,-1));
        return lcs(0,0);
    }
};