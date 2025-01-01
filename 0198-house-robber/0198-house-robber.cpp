class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int inc = nums[ind]+solve(ind+2,nums,dp);
        int exc = solve(ind+1,nums,dp);
        return dp[ind] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};