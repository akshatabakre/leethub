class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        vector<int> dup(n);
        dup = nums;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                nums[i] = nums[i+1];
                dup[i+1] = dup[i];
                break;
            }
        }
        bool b1 = true, b2 = true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])   b1 = false;
            if(dup[i]>dup[i+1])     b2 = false;
            if(!b1 && !b2){
                break;
            }
        }
        return b1||b2;
    }
};