class Solution {
public:
    vector<vector<int>> dp;
    int solve(int ind,int sum,vector<int>&nums){
        if(sum==0){
            return 0;
        }
        if(ind==nums.size()){
            return -1e9;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int nottake = solve(ind+1,sum,nums);
        int take = -1e9;
        if(nums[ind]<=sum){
            take = 1 + solve(ind+1,sum-nums[ind],nums);
        }
        return dp[ind][sum] = max(take,nottake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n,vector<int>(target+1,-1));
        int ans = solve(0,target,nums);
        return max(-1,ans);
    }
};