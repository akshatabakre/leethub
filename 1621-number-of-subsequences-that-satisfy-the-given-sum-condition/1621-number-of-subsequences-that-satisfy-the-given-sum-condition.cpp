#define ll long long
int MOD = 1e9 + 7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int l = 0, r = n-1;
        vector<ll> pow2(n+1,1);
        for(int i=1;i<=n;i++){
            pow2[i] = (pow2[i-1]*2LL)%MOD;
        }
        sort(nums.begin(),nums.end());
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans = (ans+pow2[r-l])%MOD;
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};