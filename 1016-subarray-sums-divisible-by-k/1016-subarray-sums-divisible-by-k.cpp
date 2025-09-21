class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> f;
        f[0]++;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            nums[i] = ((sum%k)+k)%k;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += f[nums[i]];
            f[nums[i]]++;
        }
        return ans;
    }
};