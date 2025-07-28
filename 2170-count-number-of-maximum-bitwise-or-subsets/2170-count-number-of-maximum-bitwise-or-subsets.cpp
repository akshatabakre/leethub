class Solution {
public:
    int count(int ind,int OR,vector<int>& nums,int& maxOR,vector<vector<int>> &dp){
        if(ind==nums.size()){
            return (OR==maxOR);
        }
        if(dp[ind][OR]!=-1){
            return dp[ind][OR];
        }
        return dp[ind][OR] = count(ind+1,(OR|nums[ind]),nums,maxOR,dp) + count(ind+1,OR,nums,maxOR,dp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        //max OR -> OR of all elements
        //find number of subsets with OR = maxOR
        int maxOR = 0;
        for(int i:nums){
            maxOR = (maxOR | i);
        }
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(maxOR+1,-1));
        return count(0,0,nums,maxOR,dp);
    }
};