class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffmin(n);
        int mini = nums[n-1];
        suffmin[n-1] = mini;
        for(int i=n-2;i>=0;i--){
            suffmin[i] = min(nums[i],suffmin[i+1]);
        }
        int maxi = nums[0];
        int sc = maxi-suffmin[0];
        if(sc<=k){
            return 0;
        }
        for(int i=1;i<n;i++){
            maxi = max(maxi,nums[i]);
            if(maxi-suffmin[i]<=k){
                return i;
            }
        }
        return -1;
    }
};