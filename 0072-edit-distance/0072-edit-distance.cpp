class Solution {
public:
    // int minsteps(int i,int j,string& s,string& t,vector<vector<int>>& dp){
    //     if(j<0){
    //         return i+1;
    //     }
    //     if(i<0){
    //         return j+1;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i]==t[j]){
    //         return dp[i][j] = minsteps(i-1,j-1,s,t,dp);
    //     }
    //     return dp[i][j] = 1+min(minsteps(i-1,j-1,s,t,dp),min(minsteps(i-1,j,s,t,dp),minsteps(i,j-1,s,t,dp)));
    // }
    int minDistance(string word1, string word2) {
        int n = word1.length(),m=word2.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return minsteps(n-1,m-1,word1,word2,dp);
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> v(m+1,0),c(m+1,0);
        for(int j=0;j<=m;j++){
            v[j] = j;
        }
        // for(int i=0;i<=n;i++){
        //     dp[i][0] = i;
        // }
        for(int i=1;i<=n;i++){
            c[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    c[j] = v[j-1];
                }else{
                    c[j] = 1+min(v[j-1],min(v[j],c[j-1]));
                }
            }
            v=c;
        }
        return v[m];
    }
};