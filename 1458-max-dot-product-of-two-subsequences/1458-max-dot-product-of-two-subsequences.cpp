class Solution {
public:
    vector<int> nums1,nums2;
    vector<vector<int>> dp;
    int solve(int i,int j){
        if(i>=nums1.size() || j>=nums2.size()){
            return -1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = max(nums1[i]*nums2[j] + max(0,solve(i+1,j+1)),max(solve(i,j+1),solve(i+1,j)));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        int n = nums1.size(), m = nums2.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0);
    }
};