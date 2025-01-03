#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ll sum1 = nums[0], sum2 = 0, n = nums.size();
        for(int i=1;i<n;i++){
            sum2+=nums[i];
        }
        int ans = 0;
        if(sum1>=sum2){
            ans++;
        }
        for(int i=1;i<n-1;i++){
            sum1+=(2*nums[i]);
            if(sum1>=sum2){
                ans++;
            }
        }
        return ans;
    }
};