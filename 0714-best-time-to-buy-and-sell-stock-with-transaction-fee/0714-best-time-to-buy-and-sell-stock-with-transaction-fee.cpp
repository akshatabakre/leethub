class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int v1 = 0, v2 = 0;
        for(int ind=n-1;ind>=0;ind--){
            int a = v1, b = v2;
            v1 = max(prices[ind]+b-fee,a);
            v2 = max(-prices[ind]+a,b);
        }
        return v2;
    }
};