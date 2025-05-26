class Solution {
public:
    int countways(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==0){
            if(nums[ind]==0 && target==0)    return 2;//either take 0 or not take 0
            if(target==0 || target==nums[ind])  return 1;//either nottake, or take
            return 0;//no other way possible
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = countways(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target){
            take = countways(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target] = take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(), sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum<target || sum+target<0)  return 0;
        if((sum+target)%2==1)   return 0;
        // vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        vector<vector<int>> dp(n,vector<int> (sum+1,0));
        int t = (sum+target)/2;
        // return countways(n-1,t,nums,dp);
        //ind==0 if(nums[ind]==0) for all t = 0, ans = 2
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int i=0;i<n;i++){
            dp[i][nums[i]] = 1;
        }
        if(nums[0]==0){
            dp[0][0] = 2;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take+nottake;
            }
        }
        return dp[n-1][t];
    }
};