class Solution {
public:
    int f(int ind,int prevind,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prevind]!=-1)    return dp[ind][prevind];
        int nottake = 0 + f(ind+1,prevind,nums,dp);
        int take = 0;
        if(prevind==0){
            take = 1 + f(ind+1,ind+1,nums,dp);
        } else if(nums[ind]>nums[prevind-1]){
            take = 1 + f(ind+1,ind+1,nums,dp);
        }
        // if(prevind==-1){
        //     return max(take,nottake);
        // }
        return dp[ind][prevind] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,0,nums,dp);
    }
};