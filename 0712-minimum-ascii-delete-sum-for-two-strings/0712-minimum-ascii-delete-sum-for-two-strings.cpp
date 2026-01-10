class Solution {
public:
    string s1,s2;
    vector<vector<int>> dp;
    int solve(int i,int j){
        if(i>=s1.length() || j>=s2.length()){
            int ans = 0;
            for(int ii=i;ii<s1.length();ii++){
                ans+=(int)s1[ii];
            }
            for(int jj=j;jj<s2.length();jj++){
                ans+=(int)s2[jj];
            }
            return ans;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = solve(i+1,j+1);
        }
        return dp[i][j] = min((int)s1[i]+solve(i+1,j),(int)s2[j]+solve(i,j+1));
    }
    int minimumDeleteSum(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        int n = s1.length(), m = s2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(0,0);
    }
};