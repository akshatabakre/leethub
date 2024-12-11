class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyat = prices[0], profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[i-1]){
            profit = max(profit,prices[i-1] - buyat);
            if(prices[i]<buyat){
                buyat = prices[i];
            }
            }
        }
        profit = max(profit,prices[prices.size()-1] - buyat);
        return profit;
    }
};