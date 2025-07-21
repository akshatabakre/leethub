class Solution {
public:
    int rec(int ind,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size()-1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int minjumps = 1e9;
        for(int i=1;i<=nums[ind];i++){
            minjumps = min(1+rec(ind+i,nums,dp),minjumps);
        }
        return dp[ind] = minjumps;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return rec(0,nums,dp);
    }
};