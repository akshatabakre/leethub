class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int n = nums.size();
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int j=n-1;
        while(j>i && nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};