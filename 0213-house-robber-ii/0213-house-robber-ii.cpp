class Solution {
public:
     int solve(vector<int>& nums,int index,vector<vector<int>>& dp,int  flag){
        if(index>=nums.size()){
            return 0;
        }
        if(index==nums.size()-1 && flag==0){
            return nums[index];
        }
        if(index==nums.size()-1 && flag==1){
            return 0;
        }
        if(dp[index][flag]!=-1){
            return dp[index][flag];
        }
        if(index==0){
            flag=1;
        }
        int include=solve(nums,index+2,dp,flag)+nums[index];
        if(index==0){
            flag=0;
        }
        int exclude=solve(nums,index+1,dp,flag);
        dp[index][flag]=max(include,exclude);
        return dp[index][flag];
    }
    int rob(vector<int>& nums) {
        bool flag=false;
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        int ans=solve(nums,0,dp,flag);
        return ans;
    }
};