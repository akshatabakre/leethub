class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        #define int long long
        int n = prices.size();
        vector<int> p(n),q(n);
        p[0] = strategy[0]*prices[0];
        q[0] = prices[0];
        for(int i=1;i<n;i++){
            p[i] = p[i-1] + (strategy[i]*prices[i]);
            q[i] = q[i-1] + prices[i];
        }
        int ans = p[n-1];
        for(int i=0;i<=n-k;i++){
            int x = 0;
            if(i)
                x += p[i-1];
            // for(int j=i+(k/2);j<i+k;j++){
            //     x+=prices[j];
            // }
            x += q[i+k-1]-q[i+(k/2)-1];
            if(k-1<n-1)
            x += p[n-1]-p[i+k-1];
            ans = max(x,ans);
        }
        return ans;
        #undef int
    }
};