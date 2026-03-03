class Solution {
public:
    //KADANE'S ALGORITHM
    int maxSubArray(vector<int>& nums) {
        int mxsm = -1e9;
        int n = nums.size();
        int sm = 0;
        int s = -1, e = -1;
        int start = 0;
        for(int i=0;i<n;i++){
            if(sm==0)   start = i;
            sm+=nums[i];
            if(mxsm<sm){
                mxsm = sm;
                s = start;
                e = i;
            }
            if(sm<0){
                sm = 0;
            }
        }
        cout<<s<<" "<<e<<endl;
        return mxsm;
    }
};