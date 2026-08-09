class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        double ans = 0.00000;
        int i=0, j=0;
        for(int i=0;i<prices.size();i++){
            int d = 0;
            if(j<discounts.size()){
                d = discounts[j];
                j++;
            }
            ans += (prices[i]*(100-d))/100.00000;
        }
        return ans;
    }
};