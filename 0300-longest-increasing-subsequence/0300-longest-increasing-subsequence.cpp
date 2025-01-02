class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        for(int i=0;i<n;i++)    hash[i] = i;
        int lastin = n;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    // dp[i] = max(dp[i],1+dp[j]);
                    if(dp[i]<1+dp[j]){
                        dp[i] = 1+dp[j];
                        hash[i] = j;
                    }
                }
            }
            // ans = max(ans,dp[i]);
            if(dp[i]>ans){
                ans = dp[i];
                lastin = i;
            }
        }
        cout<<lastin<<endl;
        vector<int> v;
        v.push_back(nums[lastin]);
        while(hash[lastin]!=lastin){
            v.push_back(nums[hash[lastin]]);
            lastin = hash[lastin];
        }
        // for(int i=0;i<hash.size();i++){
        //     cout<<hash[i]<<" ";
        // }
        return v.size();
    }
};