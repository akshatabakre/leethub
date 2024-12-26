class Solution {
public:
    int countways(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==0){
            if(nums[ind]==0 && target==0)    return 2;
            if(target==0 || target==nums[ind])  return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = countways(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target){
            // cout<<"now target = "<<target-nums[ind]<<endl;
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
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        int t = (sum+target)/2;
        return countways(n-1,t,nums,dp);
    }
};