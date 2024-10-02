class Solution {
public:
    int minElement(vector<int>& nums) {
        int minds = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int ds = 0;
            while(nums[i]>0){
                ds+=(nums[i]%10);
                nums[i]/=10;
            }
            minds = min(ds,minds);
        }
        return minds;
        
    }
};