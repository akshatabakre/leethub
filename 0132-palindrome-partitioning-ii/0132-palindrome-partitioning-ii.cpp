class Solution {
public:
    bool isp(string& s){
        if(s.length()==1)   return true;
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    // int solve(int i,string& s,vector<int>& dp){
    //     if(i==s.length()){
    //         return 0;
    //     }
    //     if(dp[i]!=-1)   return dp[i];
    //     int mincost = 1e9;
    //     string temp = "";
    //     for(int j=i;j<s.length();j++){
    //         temp+=s[j];
    //         if(isp(temp)){
    //             mincost = min(1+solve(j+1,s,dp),mincost);
    //         }
    //     }
    //     return dp[i] = mincost;
    // }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        // return solve(0,s,dp)-1;
        for(int i=n-1;i>=0;i--){
            int mini = 1e9;
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isp(temp)){
                    int cost = 1 + dp[j+1];
                    mini = min(cost,mini);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};