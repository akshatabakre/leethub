class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyat = prices[0],profit = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<=buyat){
                buyat = prices[i];
            }else{
                profit+=prices[i]-buyat;
                buyat = prices[i];
            }
        }
        return profit;
    }
};