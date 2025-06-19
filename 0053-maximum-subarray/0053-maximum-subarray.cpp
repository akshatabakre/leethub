class Solution {
public:
    //KADANE'S ALGORITHM
    int maxSubArray(vector<int>& nums) {
        int maxsum = -1e9, sum = 0, n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxsum = max(sum,maxsum);
            sum = max(0,sum);
        }
        return maxsum;
    }
};