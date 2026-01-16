class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> dp;
    int subsetsum(int ind,int target){
        if(target==0){
            return 1;
        }
        if(ind==n){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int take = 0, nottake = subsetsum(ind+1,target);
        if(nums[ind]<=target){
            take = subsetsum(ind+1,target-nums[ind]);
        }
        return dp[ind][target] = (take||nottake);
    }
    bool canPartition(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        int target = 0;
        for(int i:nums){
            target+=i;
        }
        if(target%2){
            return false;
        }
        target/=2;
        dp.resize(n,vector<int>(target+1,-1));
        cout<<subsetsum(0,target);
        return subsetsum(0,target);
    }
};