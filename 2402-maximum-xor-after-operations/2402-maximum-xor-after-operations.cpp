class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x = x|nums[i];
        }
        return x;
    }
};