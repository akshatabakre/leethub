class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool eq = true;
        for(int i:nums){
            if(i!=nums[0]){
                eq= false;
                break;
            }
        }
        if(eq){
            return 0;
        }
        return 1;
    }
};