#define ll long long
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> ans(k,0);
        vector<ll> freq(k,0);
        for(int i=0;i<n;i++){
            vector<ll> newfreq(k,0);
            newfreq[nums[i]%k]++;//starting with nums[i]
            for(int j=0;j<k;j++){
                ll count = freq[j];
                ll newmod = (1LL*j*nums[i])%k;
                newfreq[newmod]+=count;
            }
            for(int j=0;j<k;j++){
                ans[j]+=newfreq[j];
            }
            freq = newfreq;
        }
        return ans;
    }
};