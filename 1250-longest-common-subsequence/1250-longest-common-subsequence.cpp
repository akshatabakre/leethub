class Solution {
public:
    // int lcs(int ind1,int ind2,string text1,string text2,vector<vector<int>>& dp){
    //     if(ind1<0||ind2<0){
    //         return 0;
    //     }
    //     if(dp[ind1][ind2]!=-1){
    //         return dp[ind1][ind2];
    //     }
    //     if(text1[ind1]==text2[ind2]){
    //         return dp[ind1][ind2] = 1+lcs(ind1-1,ind2-1,text1,text2,dp);
    //     }
    //     return dp[ind1][ind2] = max(lcs(ind1-1,ind2,text1,text2,dp),lcs(ind1,ind2-1,text1,text2,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        // vector<vector<int>> dp(n,vector<int>(m,0));
        // return lcs(n-1,m-1,text1,text2,dp);
        vector<int> prev(m,0),curr(m,0);
        for(int i1=0;i1<n;i1++){
            for(int i2=0;i2<m;i2++){
                if(text1[i1]==text2[i2]){
                    curr[i2] = 1;
                    if(i1>0 && i2>0){
                        curr[i2]+=prev[i2-1];
                    }
                }else{
                    int v1=0,v2=0;
                    if(i1>0){
                        v1=prev[i2];
                    }
                    if(i2>0){
                        v2=curr[i2-1];
                    }
                    curr[i2] = max(v1,v2);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};