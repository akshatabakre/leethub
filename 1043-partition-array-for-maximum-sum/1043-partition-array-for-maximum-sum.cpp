class Solution {
public:
    int n,k;
    vector<int> arr;
    int dp[501];
    int solve(int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi = 0;
        int maxsum = 0;
        for(int j=i;j<min(n,i+k);j++){
            maxi = max(arr[j],maxi);
            maxsum = max(maxsum,(j-i+1)*maxi + solve(j+1));
        }
        return dp[i] = maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->arr = arr;
        this->n = arr.size();
        this->k = k;
        memset(dp,-1,sizeof(dp));
        return solve(0);
    }
};