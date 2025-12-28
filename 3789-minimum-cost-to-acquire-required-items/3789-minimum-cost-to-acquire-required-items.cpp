class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int ans = min(need1,need2)*min(costBoth,cost1+cost2);
        ans += min(costBoth,cost1)*max(0,need1-min(need1,need2));
        ans += min(costBoth,cost2)*max(0,need2-min(need1,need2));
        return ans;
    }
};