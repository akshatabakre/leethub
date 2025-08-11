class Solution {
public:
    int MOD = 1e9 + 7;
    long long zeroFilledSubarray(vector<int>& nums) {
        #define int long long
        long long ans = 0;
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]){
                ans += (cnt*(cnt+1)/2);
                cnt = 0;
            }else{
                cnt++;
            }
        }
        ans += (cnt*(cnt+1)/2);
        return ans;
        #undef int
    }
};