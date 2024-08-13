class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int x = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            x = x|nums[i];
        }
        return x;
    }
};