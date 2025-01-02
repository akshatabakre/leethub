class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), hash(n);
        for(int i=0;i<n;i++){
            hash[i] = i;
        }
        sort(nums.begin(),nums.end());
        int last = 0,ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<=1+dp[j]){
                        dp[i] = 1 + dp[j];
                        hash[i] = j;
                    }
                }
            }
            if(ans<dp[i]){
                ans = dp[i];
                last = i;
            }
        }
        vector<int> res;
        if(last==n){
            return res;
        }
        res.push_back(nums[last]);
        while(hash[last]!=last){
            res.push_back(nums[hash[last]]);
            last = hash[last];
        }
        return res;
    }
};