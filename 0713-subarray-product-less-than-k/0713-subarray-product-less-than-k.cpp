class Solution {
public:
    int MOD = 1e9 + 7;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        #define int long long
        int n = nums.size();
        int l = 0, r = -1;
        int prod= 1;
        int ans = 0;
        while(l<n){
            while(r+1<n && prod*nums[r+1]<k){
                r++;
                prod = (prod*nums[r])%MOD;
            }
            if(prod<k)
            ans+=(r-l+1);
            // cout<<l<<" "<<ans<<endl;
            if(prod!=1)
            prod/=nums[l];
            l++;
            if(r<l){
                r = l-1;
            }
        }
        return ans;
        #undef int
    }
};