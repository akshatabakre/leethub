class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        //discussion comments
        int n = nums.size();
        for(int i=0;i+1<n;i++){
            if(i+3<n && nums[i]==nums[i+3]){
                return nums[i];
            }
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
            if(i+2<n && nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        return -1;
    }
};