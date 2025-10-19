class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1),v(n,1);
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                lis[i]+=lis[i+1];
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                v[i]+=v[i-1];
            }
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            ans = max(ans,min(v[i-1],lis[i]));
        }
        return ans;
    }
};