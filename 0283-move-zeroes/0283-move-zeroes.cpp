class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        //i tracks non zero values, j tracks index
        while(i<nums.size()){
            if(nums[i]==0){
                i++;
            }else{
                nums[j++] = nums[i];
                i++;
            }
        }
        while(j<nums.size()){
            nums[j++] = 0;
        }
    }
};