class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                x = i;
                break;
            }
        }
        if(x==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int y = -1;
        for(int i=n-1;i>x;i--){
            if(nums[x]<nums[i]){
                y = i;
                break;
            }
        }
        swap(nums[x],nums[y]);
        sort(nums.begin()+x+1,nums.end());
        return;
    }
};