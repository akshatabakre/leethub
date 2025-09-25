class Solution {
public:
    int len;
    string s;
    vector<string> wordDict;
    int n;
    vector<int> dp;
    bool solve(int ind){
        if(ind>=len){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        bool ans = false;
        for(int i=0;i<n;i++){
            if(s[ind]==wordDict[i][0] && ind+wordDict[i].length()<=len){
                if(s.substr(ind,wordDict[i].length())==wordDict[i]){
                    ans = (ans | solve(ind+wordDict[i].length()));
                }
            }
        }
        return dp[ind] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = wordDict.size();
        len = s.length();
        this->s = s;
        this->wordDict = wordDict;
        dp.resize(len,-1);
        return solve(0);
    }
};