class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0,w=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                r++;
            }else if(nums[i]==1){
                w++;
            }
        }
        int j = 0;
        while(r--){
            nums[j++] = 0;
        }
        while(w--){
            nums[j++] = 1;
        }
        while(j!=nums.size()){
            nums[j++] = 2;
        }
    }
};