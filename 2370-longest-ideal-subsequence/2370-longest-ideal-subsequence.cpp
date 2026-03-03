class Solution {
public:
    int k;
    vector<vector<int>> dp;
    int solve(int ind,int prev,string&s){
        if(ind==s.length()){
            return 0;
        }
        if(prev!=-1 && dp[ind][prev]!=-1){
            return dp[ind][prev];
        }
        int take = 0, nottake = solve(ind+1,prev,s);
        if(prev==-1 || abs((s[ind]-'a')-prev)<=k){
            take = 1 + solve(ind+1,s[ind]-'a',s);
        }
        if(prev!=-1)    dp[ind][prev] = max(take,nottake);
        return max(take,nottake);
    }
    int longestIdealString(string s, int k) {
        this->k = k;
        dp.assign(s.length(),vector<int>(26,-1));
        return solve(0,-1,s);
    }
};