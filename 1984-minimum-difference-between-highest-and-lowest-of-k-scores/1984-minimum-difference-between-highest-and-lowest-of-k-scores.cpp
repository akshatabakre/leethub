class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1e9;
        sort(nums.begin(),nums.end());
        for(int i=0;i+k-1<n;i++){
            ans = min(ans,nums[i+k-1]-nums[i]);
        }
        return ans;
    }
};