class Solution {
public:
    bool func(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        if(j<0 && i<0){
            return true;
        }
        if(j<0 && i>=0){
            return false;
        }
        if(i<0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = func(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j] = func(i,j-1,s,p,dp)||func(i-1,j,s,p,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return func(n-1,m-1,s,p,dp);
        // vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        vector<bool> v(m+1),curr(m+1);
        v[0] = true;
        // for(int i=1;i<=n;i++){
        //     dp[i][0] = false;
        // }
        for(int j=1;j<=m;j++){
            bool allstars = true;
            for(int k=0;k<j;k++){
                if(p[k]!='*'){
                    allstars = false;
                    break;
                }
            }
            v[j] = allstars;
        }
        for(int i=1;i<=n;i++){
            curr[0] = false;
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j] = v[j-1];
                }else if(p[j-1]=='*'){
                    curr[j] = v[j]||curr[j-1];
                }else{
                    curr[j] = false;
                }
            }
            v=curr;
        }
        return v[m];
    }
};