class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = k;
        long long cnt = 0; 
        long long MOD = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            if(nums[i] <= res) {
                res -= nums[i];
            } else {
                long long x = (nums[i] - res + k - 1) / k; 
                res += (x * k);
                res -= nums[i];
                cnt += x;
            }
        }
        
        long long ans;
        if (cnt % 2 == 0) {
            ans = ((cnt / 2) % MOD) * ((cnt + 1) % MOD) % MOD;
        } else {
            ans = (cnt % MOD) * (((cnt + 1) / 2) % MOD) % MOD;
        }
        
        return ans;
    }
};