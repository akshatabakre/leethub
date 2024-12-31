class Solution {
public:
    // int maxlen(int ind,int pind,vector<int>& nums,vector<vector<int>>& dp){
    //     if(ind==nums.size()){
    //         return 0;
    //     }
    //     if(dp[ind][pind+1]!=-1){
    //         return dp[ind][pind+1];
    //     }
    //     int len = maxlen(ind+1,pind,nums,dp);
    //     if(pind==-1 || nums[pind]<nums[ind]){
    //         len = max(len,1+maxlen(ind+1,ind,nums,dp));
    //     }
    //     return dp[ind][pind+1] = len;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // return maxlen(0,-1,nums,dp);
        for(int ind = n-1;ind>=0;ind--){
            for(int pind = ind-1;pind>=-1;pind--){
                int len = dp[ind+1][pind+1];
                if(pind==-1||nums[ind]>nums[pind]){
                    len = max(len,1 + dp[ind+1][ind+1]);
                }
                dp[ind][pind+1] = len;
            }
        }
        return dp[0][0];
    }
};