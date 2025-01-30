class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), l = 0, ml = 0;
        for(int i=0;i<n;i++){
            if(nums[i]){
                l++;
            }else{
                ml = max(l,ml);
                l = 0;
            }
        }
        ml = max(l,ml);
        return ml;
    }
};