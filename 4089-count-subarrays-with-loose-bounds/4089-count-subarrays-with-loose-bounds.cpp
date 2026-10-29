class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0, ans = 0, n = (long long)nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                count++;
            }else{
                ans += count*(count+1)/2;
                count = 0;
            }
        }
        ans += count*(count+1)/2;
        return ans;
    }
};