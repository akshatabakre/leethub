class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int len = n + m - dp[n][m];
        int i = n, j = m;
        string scs = "";
        int index = len-1;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                scs+=s1[i-1];
                i--;    j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                scs+=s1[i-1];
                i--;
            }else{
                scs+=s2[j-1];
                j--;
            }
        }
        while(i>0){
            scs+=s1[i-1];
            i--;
        }
        while(j>0){
            scs+=s2[j-1];
            j--;
        }
        reverse(scs.begin(),scs.end());
        return scs;
    }
};