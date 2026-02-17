#define ll long long
class Solution {
public:
    ll dp[101][101][101];
    ll solve(int i,int j,vector<int>& nums1, vector<int>& nums2,int k){
        if((i>=nums1.size() || j>=nums2.size()) && k==0){
            return 0;
        }
        if(i>=nums1.size() || j>=nums2.size()){
            return -1e18;
        }
        if(k<0){
            return -1e18;
        }
        if(dp[i][j][k]!=LLONG_MIN){
            return dp[i][j][k];
        }
        ll ans=-1e18;
        ans=max(ans,(1LL*nums1[i]*nums2[j])+solve(i+1,j+1,nums1,nums2,k-1));
        ans=max(ans,solve(i+1,j,nums1,nums2,k));
        ans=max(ans,solve(i,j+1,nums1,nums2,k));
        return dp[i][j][k]=ans;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                for(int k=0;k<101;k++){
                    dp[i][j][k]=LLONG_MIN;
                }
            }
        }
        return solve(0,0,nums1,nums2,k);    
        
    }
};
