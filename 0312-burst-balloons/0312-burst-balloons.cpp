class Solution {
public:
    vector<int>nums;
    vector<vector<int>> dp;
    int coins(int l,int r){
        if(l+1==r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int maxi = 0;
        for(int i=l+1;i<r;i++){
            maxi = max(nums[l]*nums[r]*nums[i]+coins(l,i)+coins(i,r),maxi);
        }
        return dp[l][r] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        this->nums = nums;
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return coins(0,nums.size()-1);
    }
};