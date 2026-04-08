class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        const int INF = 1e9;
        vector<vector<vector<int>>> dp(3, vector<vector<int>>(k+1, vector<int>(2, INF)));
        for(int i = 0; i <= n+1; i++)
            for(int fs = 0; fs <= 1; fs++)
                dp[i%3][0][fs] = 0;
        for(int i = n-1; i >= 0; i--){
            for(int x = 1; x <= k; x++){
                for(int fs = 0; fs <= 1; fs++){
                    int ans = INF;
                    if(i == n-1){
                        if(fs == 0){
                            int maxi = nums[i-1];
                            maxi = max(maxi, nums[0]);
                            if(nums[i] > maxi){
                                if(dp[(i+2)%3][x-1][fs] < INF)
                                    ans = min(ans, dp[(i+2)%3][x-1][fs]);
                            }
                            else{
                                if(dp[(i+2)%3][x-1][fs] < INF)
                                    ans = min(ans, maxi+1-nums[i] + dp[(i+2)%3][x-1][fs]);
                            }
                        }
                        ans = min(ans, dp[(i+1)%3][x][fs]);
                    }
                    else if(i == 0){
                        int maxi = nums[i+1];
                        maxi = max(maxi, nums[n-1]);
                        if(nums[i] > maxi){
                            if(dp[(i+2)%3][x-1][1] < INF)
                                ans = min(ans, dp[(i+2)%3][x-1][1]);
                        }
                        else{
                            if(dp[(i+2)%3][x-1][1] < INF)
                                ans = min(ans, maxi+1-nums[i] + dp[(i+2)%3][x-1][1]);
                        }
                        ans = min(ans, dp[(i+1)%3][x][0]);
                    }
                    else{
                        int maxi = nums[i-1];
                        maxi = max(maxi, nums[i+1]);
                        if(nums[i] > maxi){
                            if(dp[(i+2)%3][x-1][fs] < INF)
                                ans = min(ans, dp[(i+2)%3][x-1][fs]);
                        }
                        else{
                            if(dp[(i+2)%3][x-1][fs] < INF)
                                ans = min(ans, maxi+1-nums[i] + dp[(i+2)%3][x-1][fs]);
                        }
                        ans = min(ans, dp[(i+1)%3][x][fs]);
                    }
                    dp[i%3][x][fs] = ans;
                }
            }
        }
        int ans = dp[0][k][0];
        if(ans >= INF) return -1;
        return ans;
    }
};