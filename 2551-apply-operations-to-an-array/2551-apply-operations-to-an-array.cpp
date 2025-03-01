class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i=0, j=0;
        int n = nums.size();
        while(j<n-1){
            if(nums[j]==nums[j+1]){
                if(nums[j]==0){
                    j+=2;
                    continue;
                }
                nums[i++] = nums[j]*2;
                j+=2;
            }else{
                if(nums[j]==0){
                    j++;
                    continue;
                }
                nums[i++] = nums[j++];
            }
        }
        if(j==n-1){
            nums[i++] = nums[j];
        }
        while(i<n){
            nums[i++] = 0;
        }
        return nums;
    }
};