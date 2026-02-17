class Solution {
public:
    string s;
    vector<vector<int>> dp;
    int func(int l,int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        if(s[l]==s[r]){
            return dp[l][r] = func(l+1,r-1);
        }
        return dp[l][r] = 1 + min(func(l+1,r),func(l,r-1));
    }
    int almostPalindromic(string s) {
        int n = s.length();
        this->s = s;
        dp.assign(n,vector<int>(n,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(func(i,j)<=1){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};