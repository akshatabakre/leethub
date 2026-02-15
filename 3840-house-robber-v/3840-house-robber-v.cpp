class Solution {
public:
    vector<long long> dp;
    long long solve(int ind,vector<int>&nums,vector<int>&colors){
        #define int long long
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans = 0;
        //take
        if(ind+1<nums.size() && colors[ind+1]!=colors[ind]){
            ans = max(nums[ind]+solve(ind+1,nums,colors),ans);
        }else{
            ans = max(nums[ind]+solve(ind+2,nums,colors),ans);
        }
        //dont take
        ans = max(ans,solve(ind+1,nums,colors));
        return dp[ind]=ans;
        #undef int
    }
    long long rob(vector<int>& nums, vector<int>& colors){
        int n = nums.size();
        dp.assign(n,-1);
        return solve(0,nums,colors);
    }
};