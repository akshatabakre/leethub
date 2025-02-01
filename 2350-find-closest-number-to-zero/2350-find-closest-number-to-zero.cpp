class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int neg = -1e9, pos = 1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos = min(pos,nums[i]);
            }else{
                neg = max(neg,nums[i]);
            }
        }
        if(abs(neg)<pos){
            return neg;
        }
        return pos;
    }
};