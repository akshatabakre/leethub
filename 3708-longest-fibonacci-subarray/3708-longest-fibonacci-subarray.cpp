class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 1;
        int ans = 0;
        while(l<n){
            while(r+1<n && nums[r+1]==nums[r-1]+nums[r]){
                r++;
            }
            ans = max(r-l+1,ans);
            if(r-l<=1){
                l++;
                r = l+1;
            }else{
                l++;
            }
        }
        return ans;
    }
};