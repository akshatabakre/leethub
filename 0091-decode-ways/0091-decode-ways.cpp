class Solution {
public:
    string s;
    int n;
    vector<int> dp;
    int ways(int ind){
        if(ind==n){
            return 1;
        }
        if(ind>n || s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        if(s[ind]=='1'){
            return dp[ind] = ways(ind+1)+ways(ind+2);
        }
        if(s[ind]=='2' &&ind+1<n && s[ind+1]>='0' && s[ind+1]<='6'){
            return dp[ind] = ways(ind+1)+ways(ind+2);
        }
        return dp[ind] = ways(ind+1);
    }
    int numDecodings(string s) {
        this->s = s;
        n = s.length();
        dp.resize(n,-1);
        return ways(0);
    }
};