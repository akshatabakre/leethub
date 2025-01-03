class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totsum=0,n=nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=0;i<n;i++){
            totsum+=nums[i];
            if(i!=0){
                prefix[i] = prefix[i-1] + nums[i];
            }
        }
        int valid = 0;
        for(int i=0;i<n-1;i++){
            if(2*prefix[i]>=totsum){
                valid++;
            }
        }
        return valid;
    }
};