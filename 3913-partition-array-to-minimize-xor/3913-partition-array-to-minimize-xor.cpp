class Solution {
public:
    int dp[250][250];
    int func(int ind,int cuts,vector<int>& pref){
        if(ind==0 && cuts>0){
            return 1e9;
        }
        if(cuts==0){
            return pref[ind];
        }
        if(dp[ind][cuts]!=-1)   return dp[ind][cuts];
        int mini = 1e9;
        for(int i=0;i<ind;i++){
            mini = min(mini,max(pref[ind]^pref[i],func(i,cuts-1,pref)));
        }
        return dp[ind][cuts] = mini;
    }
    int minXor(vector<int>& nums, int k) {
        //func(int ind,int cuts) - minimum xor of arr[0...ind] having cuts = cuts
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        vector<int> pref(n,0);
        for(int i=0;i<n;i++){
            pref[i] = nums[i];
            if(i)   pref[i] = (pref[i]^pref[i-1]);
        }
        return func(n-1,k-1,pref);
    }
};