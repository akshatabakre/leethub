class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)  sum+=nums[i];
        if(sum%2==1)    return false;
        else{
            int n = nums.size();
            int k = sum/2;
            vector<vector<bool>> dp(n,vector<bool> (k + 1,false));
            // return f(n-1,k,nums,dp);
            //base case
            //for index
            if(nums[0]<=k)
                dp[0][nums[0]] = true;
            //for target
            for(int i=0;i<n;i++)    dp[i][0] = true;
            for(int ind = 1;ind<n;ind++){
                for(int target = 1;target<=k;target++){
                    bool nottake = dp[ind-1][target],take = false;
                    if(target>=nums[ind]){
                        take = dp[ind-1][target-nums[ind]];
                    }
                    dp[ind][target] = take||nottake;
                }
            }
            return dp[n-1][k];
        }
    }
};