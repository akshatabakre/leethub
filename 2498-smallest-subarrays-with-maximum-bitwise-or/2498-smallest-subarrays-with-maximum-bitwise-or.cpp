class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> setBitInd(32,0);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int num = nums[i];
            for(int j=0;j<32;j++){
                if(num & (1<<j)){
                    setBitInd[j] = i;
                }
            }
            int x = 0;
            for(int j=0;j<32;j++){
                x = max(setBitInd[j],x);
            }
            ans[i] = max(x-i+1,1);
        }
        return ans;
    }
};