class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp;
    int maxlen(int ind,int prev){
        if(ind==nums.size()){
            return 0;
        }
        if(prev!=-1 && dp[ind][prev]!=-1){
            return dp[ind][prev];
        }
        int take = 0, nottake = maxlen(ind+1,prev);
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1 + maxlen(ind+1,ind);
        }
        if(prev==-1){
            return max(nottake,take);
        }
        return dp[ind][prev] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        dp.resize(n,vector<int>(n,-1));
        return maxlen(0,-1);
    }
};