class Solution {
public:
    int maxlen(int ind,int pind,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][pind+1]!=-1){
            return dp[ind][pind+1];
        }
        int len = maxlen(ind+1,pind,nums,dp);
        if(pind==-1 || nums[pind]<nums[ind]){
            len = max(len,1+maxlen(ind+1,ind,nums,dp));
        }
        return dp[ind][pind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return maxlen(0,-1,nums,dp);
    }
};