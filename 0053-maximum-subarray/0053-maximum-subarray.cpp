class Solution {
public:
    //KADANE'S ALGORITHM
    int maxSubArray(vector<int>& nums) {
        int mxsm = -1e9;
        int n = nums.size();
        int sm = 0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            mxsm = max(mxsm,sm);
            sm = max(0,sm);
        }
        return mxsm;
    }
};