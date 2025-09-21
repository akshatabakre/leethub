class Solution {
public:
    int md = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        #define int long long
        vector<int> dp(n+1,0);
        dp[1] = 1;
        int cnt = 0;
        for(int i=2;i<=n;i++){
            if(i-delay>0){
                cnt = (cnt+dp[i-delay])%md;
            }
            if(i-forget>0){
                cnt=(cnt-dp[i-forget]+md)%md;
            }
            dp[i] = cnt;
        }
        int ans = 0;
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+dp[i])%md;
        }
        return ans;
        #undef int
    }
};