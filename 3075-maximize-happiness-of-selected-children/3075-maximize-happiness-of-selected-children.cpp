class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        #define int long long
        sort(happiness.rbegin(),happiness.rend());
        int ans = 0;
        for(int i=0;i<k;i++){
            ans+=max(happiness[i]-i,0LL);
        }
        return ans;
        #undef int
    }
};