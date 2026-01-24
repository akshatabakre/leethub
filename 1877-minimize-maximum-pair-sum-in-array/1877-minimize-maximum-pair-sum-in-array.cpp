class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            maxsum = max(nums[i]+nums[n-i-1],maxsum);
        }
        return maxsum;
    }
};