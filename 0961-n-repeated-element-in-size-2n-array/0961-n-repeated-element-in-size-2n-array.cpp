class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        map<int,int> f;
        for(int i:nums){
            f[i]++;
            if(f[i]>=n){
                return i;
            }
        }
        return nums[2*n-1];
    }
};