class Solution {
public:
    int n;
    string s;
    int pal[2001][2001], dp[2001];
    int checkpal(int i,int j){
        if(i>j){
            return 1;
        }
        if(pal[i][j]!=-1){
            return pal[i][j];
        }
        if(s[i]!=s[j]){
            return pal[i][j] = 0;
        }
        return pal[i][j] = checkpal(i+1,j-1);
    }
    int solve(int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mincuts = 1e9;
        for(int j=i;j<n;j++){
            if(checkpal(i,j)){
                mincuts = min(mincuts,1+solve(j+1));
            }

        }
        return dp[i] = mincuts;
    }
    int minCut(string s) {
        this->n = s.length();
        this->s = s;
        memset(dp,-1,sizeof(dp));
        memset(pal,-1,sizeof(pal));
        return solve(0)-1;
    }
};