class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        #define int long long
        map<char,int> charcost;
        int n = s.length();
        int t = 0;
        for(int i=0;i<n;i++){
            charcost[s[i]]+=cost[i];
            t+=cost[i];
        }
        int ans = 1e18;
        for(auto it:charcost){
            ans = min(ans,t-it.second);
        }
        return ans;
        #undef int
    }

};