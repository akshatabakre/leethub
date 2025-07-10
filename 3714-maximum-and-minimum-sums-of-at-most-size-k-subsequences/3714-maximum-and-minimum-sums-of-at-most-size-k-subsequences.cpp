class Solution {
public:
    int MOD = 1e9 + 7;

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<vector<int>> nCr(n+1, vector<int>(k+1));
        nCr[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            nCr[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
            }
        }
        for (int i = 0; i < n; i++) {
            int left = i, right = n-i-1;
            ans = (ans + 2LL*nums[i])%MOD;
            for(int j=1;j<k;j++){
                if(left>=j){
                    ans = (ans + 1LL*nums[i]*nCr[left][j])%MOD;
                }
                if(right>=j){
                    ans = (ans + 1LL*nums[i]*nCr[right][j])%MOD;
                }
            }
        }

        return ans;
    }
};
