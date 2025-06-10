class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //index i in dp - i-1 in string
        int len = dp[n][m];
        int i=n,j=m;
        string str = "";
        for(int i=0;i<len;i++){
            str+='$';
        }
        int index = len-1;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                str[index] = text1[i-1];
                index--;
                i--;    j--;
            }else if(text1[i-1]>text2[j-1]){
                i--;
            }else{
                j--;
            }
        }
        cout<<str;
        return len;
    }
};