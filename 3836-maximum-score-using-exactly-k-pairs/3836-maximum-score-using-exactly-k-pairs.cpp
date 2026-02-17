class Solution {
public:
    int n,m;
    vector<int> nums1,nums2;
    vector<vector<vector<long long>>> dp;
    long long func(int i,int j,int k){
        if(k==0){
            return 0;
        }
        if(i>=n||j>=m){
            return -1e18;
        }
        if(dp[i][j][k]!=LLONG_MIN){
            return dp[i][j][k];
        }
        return dp[i][j][k] = max(func(i+1,j+1,k-1)+(long long)(nums1[i]*1LL*nums2[j]),max(func(i+1,j,k),func(i,j+1,k)));
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        this->n = nums1.size();
        this->m = nums2.size();
        dp.assign(n,vector<vector<long long>>(m,vector<long long>(k+1,LLONG_MIN)));
        return func(0,0,k);
    }
};