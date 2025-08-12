class Solution {
public:
    vector<pair<int,int>> vis;
    int minsum(int ind,int op1,int op2,int k,vector<int>& nums,vector<vector<vector<int>>>& dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][op1][op2]!=-1){
            return dp[ind][op1][op2];
        }
        int opt1 = 1e9, opt2 = 1e9;
        if(op1){
            opt1 = (nums[ind]+1)/2 + minsum(ind+1,op1-1,op2,k,nums,dp);
        }
        if(op2 && nums[ind]>=k){
            opt2 = (nums[ind]-k + minsum(ind+1,op1,op2-1,k,nums,dp));
        }
        int opt3 = 1e9;
        if(op1 && op2){
            int num = (nums[ind]+1)/2;
            if(num>=k){     
                num-=k;
                opt3 = num + minsum(ind+1,op1-1,op2-1,k,nums,dp);
            }
        }
        int opt4 = 1e9;
        if(op1 && op2 && nums[ind]>=k){
            int num = nums[ind]-k;
            num = (num+1)/2;
            opt4 = num + minsum(ind+1,op1-1,op2-1,k,nums,dp);
        }
        return dp[ind][op1][op2] = min(nums[ind]+minsum(ind+1,op1,op2,k,nums,dp),min(opt1,min(opt2,min(opt3,opt4))));
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vis.resize(n,{0,0});
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return minsum(0,op1,op2,k,nums,dp);
    }
};