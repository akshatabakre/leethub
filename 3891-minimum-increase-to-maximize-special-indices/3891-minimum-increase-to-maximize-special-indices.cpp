class Solution {
public:
    vector<int> nums;
    long long n;
    vector<vector<long long>> dp;
    long long solve(long long ind,int ch){
        if(ind>=n-1){
            return 0;
        }
        if(dp[ind][ch]!=-1){
            return dp[ind][ch];
        }

        long long maxi = max(nums[ind-1],nums[ind+1]);

        if(ch>0){
            long long ch1 = max(0LL,maxi+1-nums[ind]) + solve(ind+2,ch);
            long long ch2 = solve(ind+1,ch-1);
            return dp[ind][ch] = min(ch1,ch2);
        }else{
            return dp[ind][ch] = max(0LL,maxi+1-nums[ind]) + solve(ind+2,ch);
        }
    }
    long long minIncrease(vector<int>& nums) {
        this->nums = nums;
         n = nums.size();
        dp = vector<vector<long long>>(n,vector<long long>(2, -1));
        if(n%2==0){
            return solve(1,1);
        }
        return solve(1,0);
    }
};