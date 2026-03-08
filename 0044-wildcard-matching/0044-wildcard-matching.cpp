class Solution {
public:
    string s,p;
    int n,m;
    vector<vector<int>> dp;
    bool match(int i,int j){
        if(j>=m){
            return (i>=n);
        }
        if(i>=n){
            while(j<m && p[j]=='*'){
                j++;
            }
            return (j>=m);
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = match(i+1,j+1);
        }
        if(p[j]=='*'){
            return dp[i][j] = (match(i+1,j)||match(i,j+1));
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        this->n = s.length();
        this->m = p.length();
        dp.resize(n,vector<int>(m,-1));
        return match(0,0);
    }
};