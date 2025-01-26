class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if((sum-2*nums[i])%2==0)    ans++;
        }
        return ans;
    }
};