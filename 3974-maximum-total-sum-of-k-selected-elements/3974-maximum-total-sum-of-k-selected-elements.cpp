class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        #define int long long
        sort(nums.rbegin(),nums.rend());
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<k;i++){
            if(mul>0){
                sum += (1LL*mul*nums[i]);
                mul--;
            }else{
                sum+=nums[i];
            }
        }
        return sum;
        #undef int
    }
};