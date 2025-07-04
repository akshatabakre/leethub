class Solution {
public:
    // int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
    //     if(i>j){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int maxc = 0;
    //     for(int ind=i;ind<=j;ind++){
    //         int coins = nums[i-1]*nums[ind]*nums[j+1] + f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp);
    //         maxc = max(coins,maxc);
    //     }
    //     return dp[i][j] = maxc;
    // }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        // return f(1,n,nums,dp);
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxi = 0;
                for(int ind=i;ind<=j;ind++){
                    int coins = dp[i][ind-1]+dp[ind+1][j] + nums[i-1]*nums[ind]*nums[j+1];
                    maxi = max(coins,maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};